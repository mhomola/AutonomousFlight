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
#include <eigen3/Eigen/Core> 
using namespace Eigen;

//python arange function
#include <vector>

//for simplicity we will just do it manually:
#define DT 0.1
#define HORIZON 3
//horizon time/dt = 3/0.1 = 30 + 1 (+1 for the current time)
#define STEPS 31

//Declare matrix sizes for clarity and reducing read complexity
typedef Matrix<float, 1, 5> x_vect;
typedef Matrix<float, 1, 4> dw_vect;
typedef Matrix<float, STEPS, 5> trajectory_mat;
typedef Matrix<float, Dynamic, 2> obj_mat;


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
    dw_vect dw = calc_dynamic_window(x, config);
    return  calc_control_and_trajectory(x, dw, config, goal, ob);
}


struct Config{
    //TODO Nathaniel
    //simulation parameter class
    //Tune stoff here


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

    // Also used to check if goal is reached in both types
    float robot_radius = 1.0;  // [m] for collision check

    // if robot_type == RobotType.rectangle
    float robot_width = 0.5;  // [m] for collision check
    float robot_length = 1.2;  // [m] for collision check
    // obstacles [x(m) y(m), ....]
    /*
    self.ob = np.array([[-1, -1],
                        [0, 2],
                        [4.0, 2.0],
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
		dw_vect Vd = {
				x[3] - config.max_accel * config.dt,
				x[3] + config.max_accel * config.dt,
				x[4] - config.max_delta_yaw_rate * config.dt,
				x[4] + config.max_delta_yaw_rate * config.dt
		};

		// [v_min, v_max, yaw_rate_min, yaw_rate_max]
		dw_vect dw(std::max(Vs[0], Vd[0]), std::min(Vs[1], Vd[1]), std::max(Vs[2], Vd[2]), std::min(Vs[3], Vd[3]));

		return dw;
}
float calc_to_goal_cost(trajectory_mat trajectory, Vector2f goal){
    //calc to goal cost with angle difference
    auto dx = goal[0] - trajectory(last,0);
    auto dy = goal[1] - trajectory(last, 1);
    auto error_angle = atan2(dy, dx);
    auto cost_angle = error_angle - trajectory(last, 2);
    float cost = abs(atan2(sin(cost_angle),cos(cost_angle)));
    return cost
}
trajectory_mat predict_trajectory(x_vect x_init, float v, float y, struct Config config){
		//TODO Georg
		// predict trajectory with an input
		trajectory_mat      trajectory;		        //starts with just x, but then vstacks them up to 31 times //We can probably make this dynamic/based on the dt. OPTIMIZE
        trajectory.row(0) = x_init;
        Vector2f            u(v,y);
        //gonna leave this while loop. Needs to be refactored as this isn't the best way to do it.

        for (int step = 1; step != STEPS; ++step){           
            trajectory.row(step) =  motion(trajectory.row(step - 1), u, config.dt);
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
		auto dx = trajectory.col(0) - ob.col(0);
		auto dy = trajectory.col(1) - ob.col(1);
		auto r = sqrt(dx.pow(2)+dy.pow(2));

        if (r <= config.robot_radius){
				return INFINITY;
		}

		float min_r = r.min();
		return (1.0/min_r);		
}


int main(){
	float gx=10.0;
	float gy=10.0;
	RobotType robot_type = circle;
	// initial state [x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]
	x_vect x = {0.0,0.0,M_PI/8.0,0.0,0.0};
	Vector2f goal = {gx,gy};

	config.robot_type = robot_type;
	trajectory_mat trajectory = x;
	obj_mat ob = config.ob;

	while (true){
		[Vector2f u, trajectory_mat predicted_trajectory] = dwa_control(x,config,goal,ob);
		x_vect x = motion(x,u,config.dt);
		trajectory = Eigen::vstack(trajectory,x);

		auto dist_to_goal = sqrt(square((x[0]-goal[0]),2) + square((x[1]-goal[1]),2));

		if (dist_to_goal <= config.robot_radius){
			break;
		}

	}
	return 0;
}

