/*"""
This code is an adaptation of the code originally written by author: Atsushi Sakai (@Atsushi_twi), Göktuğ Karakaşlı
The original can be found on https://github.com/AtsushiSakai/PythonRobotics.git

It was ported to c++ by:

Nathaniel Peter Stebbins Dahl
Georg Strunck
Thijs Verkade

"""*/

#include <iostream>
#include <tuple>
#include <math.h>
#include <eigen3/Eigen/Dense> 
using namespace Eigen;

//python arange function
#include <vector>

//Declare matrix sizes for clarity and reducing read complexity
typedef Matrix<float, 1, 5> x_vect;
typedef Matrix<float, 1, 4> dw_vect;
typedef Matrix<float, 31, 5> trajectory_mat;
typedef Matrix<float, Dynamic, 2> obj_mat;
//typedef x_vect trajectory_vect; //is x always the trajectory?? Yes yes it is. 


//Functions in this file:
std::tuple<Vector2f, trajectory_mat>    dwa_control(x_vect x, Config config, Vector2f goal, Matrix<float, Dynamic,2> ob);
x_vect                                  motion(x_vect x,Vector2f u, float dt);
dw_vect                                 calc_dynamic_window(x_vect x, struct Config config);
trajectory_mat                          predict_trajectory(x_vect x_init, float v, float y, struct Config config);
std::tuple<Vector2f, x_vect>            calc_control_and_trajectory(x_vect x, Vector4f dw,struct Config config, Vector2f goal, obj_mat ob);
float                                   calc_obstacle_cost(trajectory_mat trajectory, obj_mat ob, struct Config config);
float                                   calc_to_goal_cost(trajectory_mat trajectory, Vector2f goal);

template<typename T>
std::vector<T> arange(T start, T stop, T step = 1) {
    std::vector<T> values;
    for (T value = start; value < stop; value += step)
        values.push_back(value);
    return values;
}

std::tuple<Vector2f, trajectory_mat >dwa_control(x_vect x, Config config, Vector2f goal, obj_mat ob) {
    //Top level control function
    //call Calculate dynamic window
    //call Calculate control and trajectory
    //return control and traject.
    //TODO Nathaniel
    //TODO ensure proper variable types.
    //TODO ensure pointers are used etc.
    Vector2f u;
    x_vect trajectory;
    dw_vect dw = calc_dynamic_window(x, config);
    [u, trajectory] = calc_control_and_trajectory(x, dw, config, goal, ob);
    return  {u, trajectory};
}

enum RobotType {circle, rectangle};

struct Config{
    //TODO Nathaniel
    //simulation parameter class
    //Tune stoff here

    using enum RobotType;

    // robot parameterint
    //TODO Tune parameters. Currently all still on default
    //TODO implement pi
    float max_speed = 1.0;  // [m/s]
    float min_speed = -0.5;  // [m/s]
    float max_yaw_rate = 40.0 * M_PI / 180.0;  // [rad/s]
    float max_accel = 0.2;  // [m/ss]
    float max_delta_yaw_rate = 40.0 * M_PI / 180.0;  // [rad/ss]
    float v_resolution = 0.01;  // [m/s]
    float yaw_rate_resolution = 0.1 * M_PI / 180.0;  // [rad/s]
    float dt = 0.1;  // [s] Time tick for motion prediction
    float predict_time = 3.0;  // [s]
    float to_goal_cost_gain = 0.15;
    float speed_cost_gain = 1.0;
    float obstacle_cost_gain = 1.0;
    float robot_stuck_flag_cons = 0.001;  // constant to prevent robot stucked
    RobotType robot_type = circle;

    // if robot_type == RobotType.circle
    // Also used to check if goal is reached in both types
    float robot_radius = 1.0;  // [m] for collision check

    // if robot_type == RobotType.rectangle
    float robot_width = 0.5;  // [m] for collision check
    float robot_length = 1.2;  // [m] for collision check
    // obstacles [x(m) y(m), ....]
    /*
    Currently removed this. We should implement the object list differently then the python script
    self.ob = np.array([[-1, -1],
                        [0, 2],
                        [4.0, 2.0],
                        [5.0, 4.0],
                        [5.0, 5.0],
                        [5.0, 6.0],
                        [5.0, 9.0],
                        [8.0, 9.0],
                        [7.0, 9.0],
                        [8.0, 10.0],
                        [9.0, 11.0],
                        [12.0, 13.0],
                        [12.0, 12.0],
                        [15.0, 15.0],
                        [13.0, 13.0]
                        ]);
    */
};


x_vect motion(x_vect x,Vector2f u, float dt) {
    //TODO figure out if this is just simulating the real world. Do we need to implement something here?
    //TODO is this a placeholder and we just use our drone simulation instead. 
    //TODO this could also be a prediction
    //TODO thijs will figure it out
    return x;
}

dw_vect calc_dynamic_window(x_vect x, struct Config config){				// is config really a struct?
		//TODO Georg
		// calculation dynamic window based on current state x

		// Dynamic window from robot specification
		dw_vect	Vs = {config.min_speed, config.max_speed, -config.max_yaw_rate, config.max_yaw_rate};

		// Dynamic window from motion model
		dw_vect 	Vd = {
				x[3] - config.max_accel * config.dt,
				x[3] + config.max_accel * config.dt,
				x[4] - config.max_delta_yaw_rate * config.dt,
				x[4] + config.max_delta_yaw_rate * config.dt
		};

		// [v_min, v_max, yaw_rate_min, yaw_rate_max]
		dw_vect 	dw(std::max(Vs[0], Vd[0]), std::min(Vs[1], Vd[1]), std::max(Vs[2], Vd[2]), std::min(Vs[3], Vd[3]));

		return dw;
}

trajectory_mat predict_trajectory(x_vect x_init, float v, float y, struct Config config){
		//TODO Georg
		// predict trajectory with an input

		x_vect  	x(x_init);
		trajectory_mat  	trajectory(x);		        //starts with just x, but then vstacks them up to 31 times //We can probably make this dynamic/based on the dt. OPTIMIZE
        Vector2f                u(v,y);
		float time = 0;
        //gonna leave this while loop. Needs to be refactored as this isn't the best way to do it.
		while (time <= config.predict_time){
			x = motion(x, u, config.dt);                    //return next position based on current position, v,y and timestep
			trajectory = Eigen::vstack(trajectory, x); 		//not sure whether vstack works this way
		    time += config.dt;
		}
		return trajectory;
}

std::tuple<Vector2f, x_vect> calc_control_and_trajectory(x_vect x, Vector4f dw,struct Config config, Vector2f goal, obj_mat ob) {
    //TODO Nathaniel
    //calculation final input with dynamic window

    x_vect  x_init = x;
    double min_cost = INFINITY;
    Vector2f best_u(0.0, 0.0);
    x_vect  best_trajectory = x;

    //Can we eliminate this in favor of something not double looped
    auto v_range = arange<float>(dw[0], dw[1], config.v_resolution);
    auto y_range = arange<float>(dw[2], dw[3], config.yaw_rate_resolution);
    //Maybe can do a for each?
    for (auto v_it = v_range.begin(); v_it != v_range.end(); ++v) {
        for (auto y_it = y_range.begin(); y_it != y_range.end(); ++y) {

            auto trajectory  = predict_trajectory(x_init, *v_it, *y_it, config);
            //Calculate the cost
            float to_goal_cost= config.to_goal_cost_gain  * calc_to_goal_cost(trajectory, goal);
            float speed_cost  = config.speed_cost_gain    * (config.max_speed - trajectory(-1, 3));
            float ob_cost     = config.obstacle_cost_gain * calc_obstacle_cost(trajectory, ob, config);

            float final_cost = to_goal_cost + speed_cost + ob_cost;

            // Search for minimum trajectory
            if (min_cost >= final_cost) {
                min_cost = final_cost;
                best_u = Vector2f(*v_it, *y_it);
                best_trajectory = trajectory;
                if (abs(best_u[0]) < config.robot_stuck_flag_cons & abs(x[3]) < config.robot_stuck_flag_cons){
                    best_u[1] = -config.max_delta_yaw_rate;
                }
            }
        }
    }
    return {best_u, best_trajectory};
}

float calc_obstacle_cost(trajectory_mat trajectory, obj_mat ob, struct Config config) {
		//TODO Georg
		//calc obstacle cost inf: collision
        //- Nathaniel haven't touched any of the types. This needs a pretty big refactor.
		Matrix<float, 15, 1> ox = ob[:][0];
		Matrix<float, 15, 1> oy = ob[:][1];
		Matrix<float, 15, 31> dx = trajectory[:][0] - ox[:][None];
		Matrix<float, 15, 31> dy = trajectory[:][1] - oy[:][None];
		Matrix<float, 15, 31> intermediary = dx*dx+dy*dy;
		Matrix<float, 15, 31> r = sqrt(intermediary);

		if (config.robot_type == RobotType.rectangle){
			Matrix<float, 31, 1>  		yaw = trajectory[:][2];
			Matrix<float, 2, 2, 31>  	rot [][] = [[cos(yaw), -sin(yaw)], [sin(yaw), cos(yaw)]];
			Matrix<float, 31, 2, 2>  	rot = transpose(rot, [2, 0, 1]);
			Matrix<float, 15, 31, 2>  	local_ob = ob[:][None] - trajectory[:][0:2];
			Matrix<float, 465, 2>  		local_ob = local_ob.reshape(-1, local_ob.shape[-1]);
			Matrix<float, 31, 465, 2>  	local_ob = [local_ob @ x for x in rot];				//fix this
			Matrix<float, 14415, 2>  	local_ob = local_ob.reshaped(-1, local_ob.shape[-1]);
			Matrix<bool, 14415, 1>  	upper_check = local_ob[:][0] <= config.robot_length / 2;
			Matrix<bool, 14415, 1>  	right_check = local_ob[:][1] <= config.robot_width / 2;
			Matrix<bool, 14415, 1>  	bottom_check = local_ob[:][0] >= -config.robot_length / 2;
			Matrix<bool, 14415, 1>  	left_check = local_ob[:][1] >= -config.robot_width / 2;
			// if upper, right, bottom, left are all the same, return float "Inf"
		    if ((logical_and(logical_and(upper_check, right_check),logical_and(bottom_check, left_check))).any()){
		    	return float("Inf");
		        }
		}
		else if (config.robot_type == RobotType.circle){
			if ([r <= config.robot_radius].any()){
				return float("Inf");
			}
		}

		float min_r = min(r);
		return (1.0/min_r);		// OK
}

float calc_to_goal_cost(trajectory_mat trajectory, Vector2f goal){
//TODO Thijs
    float cost;
    return cost;
}

void main(gx=10.0, gy=10.0, robot_type=RobotType.circle) {}
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs
