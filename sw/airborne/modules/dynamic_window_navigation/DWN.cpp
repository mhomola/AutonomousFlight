/*"""
This code is an adaptation of the code originally written by author: Atsushi Sakai (@Atsushi_twi), Göktuğ Karakaşlı
The original can be found on https://github.com/AtsushiSakai/PythonRobotics.git

It was ported to c++ by:

Nathaniel Peter Stebbins Dahl
Georg Strunck
Thijs Verkade

"""*/

//#include <iostream>
#include <tuple>
#include <math.h>
#include <eigen3/Eigen/Core> 
using namespace Eigen;
using Eigen::placeholders::last;


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
std::tuple<Vector2f, trajectory_mat>    dwa_control(x_vect& x, const struct Config& config, const Vector2f& goal, const obj_mat& ob);
x_vect                                  motion(x_vect& x, const Vector2f& u, const float dt);
dw_vect                                 calc_dynamic_window(x_vect& x,const struct Config& config);
trajectory_mat                          predict_trajectory(const x_vect& x_init, float v, float y, const struct Config& config);
std::tuple<Vector2f, x_vect>            calc_control_and_trajectory(const x_vect& x, const Vector4f& dw, const struct Config& config, const Vector2f& goal, const obj_mat& ob);
float                                   calc_obstacle_cost(const trajectory_mat& trajectory,const obj_mat& ob, const struct Config& config);
float                                   calc_to_goal_cost(const trajectory_mat& trajectory, const Vector2f& goal);

struct Config{
    //simulation parameter class
    //Tune stuff here
    //Robot parameters
    float max_speed             = 1.0;  // [m/s]
    float min_speed             = -0.5;  // [m/s]
    float max_yaw_rate          = 40.0 * M_PI / 180.0;  // [rad/s]
    float max_accel             = 0.2;  // [m/ss]
    float max_delta_yaw_rate    = 40.0 * M_PI / 180.0;  // [rad/ss]
    float v_resolution          = 0.01;  // [m/s]
    float yaw_rate_resolution   = 0.1 * M_PI / 180.0;  // [rad/s]
    float dt                    = DT;  // [s] Time tick for motion prediction
    float predict_time          = HORIZON;  // [s]
    float to_goal_cost_gain     = 0.15;
    float speed_cost_gain       = 1.0;
    float obstacle_cost_gain    = 1.0;
    float robot_stuck_flag_cons = 0.001;  // constant to prevent robot stucked
    float robot_radius          = 1.0;  // [m] for collision check
};

//arange equivelent function
template<typename T>
VectorXf arange(T start, T stop, T step = 1) {
    VectorXf values;
    for (T value = start; value < stop; value += step)
        values.push_back(value);
    return values;
}

//C++ wrapper function
struct DWN_run{
    float best_v = 0.0;
    float best_yaw = 0.0;
    struct Config config;
    Vector2f goal = Vector2f(2,2);
    obj_mat ob_lst; ob_lst <<   1.0, 1.0,
                                1.5, 1.5; //Just a basic list. Need to properly pass this in 
    Vector2f best_u = Vector2f(0,0);
    x_vect best_trajectory;
    x_vect x_vector;

    void update_dwn(float x, float y, float angle, float goal_x, float goal_y){
        x_vector << x, y, angle, best_u(0), best_u(1);
        goal(0) = goal_x;
        goal(1) = goal_y;
        dw_vect dw_update = calc_dynamic_window(x_vector,config);
        auto [best_u, best_trajectory] = calc_control_and_trajectory(x_vector, dw_update, config, goal, ob_lst);
    }

    float get_speed(){
        return best_u(0);
    }

    float get_yawrate(){
        return best_u(1);
    }
}

//C wrapper conversion function

extern "C" void updt_dwn(float x, float y, float angle, float goal_x, float goal_y) {
    return DWN_run->update_dwn( x, y, angle, goal_x, goal_y);
}
extern "C" float gt_spd(){
    return DWN_run->get_speed();
}
extern "C" float gt_ywrt(){
    return DWN_run->get_yawrate();
}

std::tuple<Vector2f, trajectory_mat> dwa_control(x_vect& x, const struct Config& config, const Vector2f& goal, const obj_mat& ob) {
    //Top level control function
    //call Calculate dynamic window
    //call Calculate control and trajectory
    //return control and traject.
    dw_vect dw  = calc_dynamic_window(x, config);
    return        calc_control_and_trajectory(x, dw, config, goal, ob);
}


// initial state [x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]
//X0 x pos
//X1 y pos
//X2 flight path in rad from horizontal
//X3/U0 velocity
//X4/U1 angular rate
x_vect motion(x_vect& x, const Vector2f& u, const float dt) {

    x(2) += u(1) * dt;
    x(0) += u(0) * cos(x(2)) * dt;
    x(1) += u(0) * sin(x(2)) * dt;
    x(3) = u(0);
    x(4) = u(1);

    return x;
}


dw_vect calc_dynamic_window(x_vect& x,const struct Config& config){
		// calculation dynamic window based on current state x
		// Dynamic window from robot specification
		dw_vect	Vs  = {config.min_speed, config.max_speed, -config.max_yaw_rate, config.max_yaw_rate};

		// Dynamic window from motion model
		dw_vect Vd  = {
				x(3) - config.max_accel * config.dt,
				x(3) + config.max_accel * config.dt,
				x(4) - config.max_delta_yaw_rate * config.dt,
				x(4) + config.max_delta_yaw_rate * config.dt
		};

		// [v_min, v_max, yaw_rate_min, yaw_rate_max]
		dw_vect dw(std::max(Vs(0), Vd(0)), std::min(Vs(1), Vd(1)), std::max(Vs(2), Vd(2)), std::min(Vs(3), Vd(3)));

		return dw;
}

trajectory_mat predict_trajectory(const x_vect& x_init, float v, float y, const struct Config& config){
		// predict trajectory with an input
        x_vect                x;
		trajectory_mat        trajectory;
        trajectory.row(0)   = x_init;
        Vector2f              u(v,y);

        for (int step = 1; step != STEPS; ++step){   
            x                       =  trajectory.row(step - 1);        
            trajectory.row(step)    =  motion(x, u, config.dt);
        }
		return trajectory;
}

std::tuple<Vector2f, x_vect> calc_control_and_trajectory(const x_vect& x, const Vector4f& dw, const struct Config& config, const Vector2f& goal, const obj_mat& ob) {
    //calculation final input with dynamic window

    x_vect  x_init          = x;
    double min_cost         = INFINITY;
    Vector2f best_u(0.0, 0.0);
    x_vect  best_trajectory = x;

    //Can we eliminate this in favor of something not double looped
    auto v_range = arange<float>(dw[0], dw[1], config.v_resolution);
    auto y_range = arange<float>(dw[2], dw[3], config.yaw_rate_resolution);
    //Maybe can do a for each?
    for (auto v_it = v_range.begin(); v_it != v_range.end(); ++v) {
        for (auto y_it = y_range.begin(); y_it != y_range.end(); ++y) {

            auto trajectory     = predict_trajectory(x_init, *v_it, *y_it, config);
            //Calculate the cost
            float to_goal_cost  = config.to_goal_cost_gain  * calc_to_goal_cost(trajectory, goal);
            float speed_cost    = config.speed_cost_gain    * (config.max_speed - trajectory(-1, 3));
            float ob_cost       = config.obstacle_cost_gain * calc_obstacle_cost(trajectory, ob, config);

            float final_cost    = to_goal_cost + speed_cost + ob_cost;

            // Search for minimum trajectory
            if (min_cost >= final_cost) {
                min_cost = final_cost;
                best_u = Vector2f(*v_it, *y_it);
                best_trajectory = trajectory;
                if (abs(best_u[0]) < config.robot_stuck_flag_cons & abs(x[3]) < config.robot_stuck_flag_cons){
                    best_u[1]   = -config.max_delta_yaw_rate;
                }
            }
        }
    }
    return {best_u, best_trajectory};
}

float calc_obstacle_cost(const trajectory_mat& trajectory,const obj_mat& ob, const struct Config& config) {
		//TODO Georg
		//calc obstacle cost inf: collision
		auto dx = trajectory.col(0) - ob.col(0);
		auto dy = trajectory.col(1) - ob.col(1);
		auto r  = sqrt(dx.pow(2)+dy.pow(2));

        if (r <= config.robot_radius){
				return INFINITY;
		}

		float min_r = r.min();
		return (1.0/min_r);		
}

float calc_to_goal_cost(const trajectory_mat& trajectory, const Vector2f& goal){
    //calc to goal cost with angle difference
    auto dx             = goal[0] - trajectory(last,0);
    auto dy             = goal[1] - trajectory(last, 1);
    auto error_angle    = atan2(dy, dx);
    auto cost_angle     = error_angle - trajectory(last, 2);
    float cost          = abs(atan2(sin(cost_angle),cos(cost_angle)));
    return cost;
}

/*int main(){
	float gx=10.0;
	float gy=10.0;
	// initial state [x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]
	x_vect x = {0.0,0.0,M_PI/8.0,0.0,0.0};
	Vector2f goal = {gx,gy};

	trajectory_mat trajectory = x;

    Config config;
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
*/
