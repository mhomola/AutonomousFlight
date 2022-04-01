/*"""
This code is an adaptation of the code originally written by author: Atsushi Sakai (@Atsushi_twi), Göktuğ Karakaşlı
The original can be found on https://github.com/AtsushiSakai/PythonRobotics.git

It was ported to c++ by:

Nathaniel Peter Stebbins Dahl
Georg Strunck
Thijs Verkade

"""*/

#include "modules/dynamic_window_navigation/dynamic_window.h"
#include "modules/dynamic_window_navigation/dwn.h"
#include <math.h>
#include <Eigen/Dense> 
#include <vector>
#include <unsupported/Eigen/MatrixFunctions>
//using namespace Eigen;

float get_speed();
float get_yawrate();

//using Eigen::placeholders::last;
//Replaced the call of last with STEPS. not ideal but its not working...

//for simplicity we will just do it manually:
#define DT 0.1
#define HORIZON (int)3

//horizon time/dt = 3/0.1 = 30 + 1 (+1 for the current time)
#define STEPS (int)31
#define MAXOBJECTS (int)3
#define RESOLUTION (int)50

//Declare matrix sizes for clarity and reducing read complexity
typedef Eigen::Matrix<float, 1, 5> x_vect;
typedef Eigen::Matrix<float, 1, 4> dw_vect;
//typedef Eigen::Matrix<float, STEPS, 5> trajectory_mat;
typedef Eigen::Matrix<float, MAXOBJECTS, 2> obj_mat;
typedef Eigen::Array<float, MAXOBJECTS, 1> obj_arr;

//creating custom bit to remove std::tuple requirements
struct u_traj {
  Eigen::Vector2f u;
  x_vect traj;
};

//Functions in this file:
struct u_traj   dwa_control(x_vect& x, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob);
x_vect          motion(x_vect& x, const Eigen::Vector2f& u, const float dt);
dw_vect         calc_dynamic_window(x_vect& x,const struct Config& config);
x_vect          predict_trajectory(const x_vect& x_init, float v, float y, const struct Config& config);
struct u_traj   calc_control_and_trajectory(const x_vect& x, const Eigen::Vector4f& dw, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob);
float           calc_obstacle_cost(const x_vect& final_state,const obj_mat& ob, const struct Config& config);
float           calc_to_goal_cost(const x_vect& final_state, const Eigen::Vector2f& goal);
Eigen::Matrix<float, 1, RESOLUTION> linspace(float start, float stop);
template<typename T>
std::vector<T>  arange(T start, T stop, T step = 1);
Eigen::Vector2f obs_pos(float heading_angle, int floor_pixels, float psi);

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
    // int v_resolution            = RESOLUTION; //Changed usage for better static mem usage
    // int yaw_rate_resolution     = RESOLUTION; //Changed usage for better static mem usage
    float dt                    = DT;  // [s] Time tick for motion prediction
    float predict_time          = HORIZON;  // [s]
    float to_goal_cost_gain     = 0.15;
    float speed_cost_gain       = 1.0;
    float obstacle_cost_gain    = 1.0;
    float robot_stuck_flag_cons = 0.001;  // constant to prevent robot stucked
    float robot_radius          = 1.0;  // [m] for collision check
};

float best_v = 0.0;
float best_yaw = 0.0;
struct Config config;
Eigen::Vector2f goal; 
obj_mat ob_lst; //Just a basic list. Need to properly pass this in 
                            //Error on line 80 due to Dynamic not being understood as a keyword from Eigen

x_vect best_trajectory;
x_vect x_vector;

Eigen::Vector2f best_u;



void update_dwn(float x, float y, float angle, float goal_x, float goal_y){
    x_vector << x, y, angle, best_u(0), best_u(1);
    goal(0) = goal_x;
    goal(1) = goal_y;
    dw_vect dw_update = calc_dynamic_window(x_vector,config);
    auto [best_u, best_trajectory] = calc_control_and_trajectory(x_vector, dw_update, config, goal, ob_lst);
}


//get function used to get the best speed
float get_speed(){
    return best_u(0);
}

//get function used to get the best yaw rate
float get_yawrate(){
    return best_u(1);
}
//C wrapper conversion function

void dwn_wrapper_init();

//init function 
void dwn_wrapper_init() {
    ob_lst <<   1.f, 1.f,
                1.5f, 1.5f,
                2.5f, 2.5f;
    goal        = Eigen::Vector2f(2,2);
    best_u      = Eigen::Vector2f(0,0);
}

/*
void updt_dwn(float x, float y, float angle, float goal_x, float goal_y) {
    return DWN_wrapper.update_dwn( x, y, angle, goal_x, goal_y);
}
float gt_spd(){
    return DWN_wrapper.get_speed();
}
float gt_ywrt(){
    return DWN_wrapper.get_yawrate();
}*/
//This is an implementation of the linspace python linspace function hardcoded to have resolution number of points
Eigen::Matrix<float, 1, RESOLUTION> linspace(float start, float stop) {
    Eigen::Matrix<float, 1, RESOLUTION> values;
    int i = 0;
    for (float value = start; value < stop; value += (stop-start)/RESOLUTION)
        values(i) = value;
        ++i;
    return values;
}

//This is an implementation of the arange function from python. It uses the dynamic memory from std::vector.
template<typename T>
std::vector<T> arange(T start, T stop, T step) {
    std::vector<T> values;
    for (T value = start; value < stop; value += step)
        values.push_back(value);
    return values;
}

struct u_traj dwa_control(x_vect& x, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob) {
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
x_vect motion(x_vect& x, const Eigen::Vector2f& u, const float dt) {
    //integrate forward
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

x_vect predict_trajectory(const x_vect& x_init, float v, float y, const struct Config& config){
		// predict trajectory with an input
        // This function takes a speed and yaw rate (v and y) and then passes them into the motion equation and performs a forward integration
        // The function returns the final coordinates.
        x_vect      x;
		x_vect      trajectory;
        trajectory  = x_init;
        Eigen::Vector2f    u = Eigen::Vector2f(v,y);

        for (int step = 1; step != STEPS; ++step){   
            x           =  trajectory;        
            trajectory  =  motion(x, u, config.dt);
        }
		return trajectory;
}

struct u_traj calc_control_and_trajectory(const x_vect& x, const Eigen::Vector4f& dw, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob) {
    //calculation final input with dynamic window
    //This function calls predict trajecotry and then evaluates the the cost functions
    //returns the best control inputs and then best final location from the search space

    x_vect  x_init          = x;
    double min_cost         = INFINITY;
    Eigen::Vector2f best_u(0.0, 0.0);
    x_vect  best_trajectory = x;

    //Can we eliminate this in favor of something not double looped
    auto v_range = arange<float>(dw(0), dw(1), config.v_resolution);
    auto y_range = arange<float>(dw(2), dw(3), config.yaw_rate_resolution);

    //auto v_range = linspace(dw(0), dw(1));
    //auto y_range = linspace(dw(2), dw(3));
    //Maybe can do a for each?

    //THIS DOESNT WORK ANYMORE as we used to use std::vector but I was unable to import the standard library.
    for (auto v_it = v_range.begin(); v_it != v_range.end(); ++v_it) {
        for (auto y_it = y_range.begin(); y_it != y_range.end(); ++y_it) {

            x_vect final_state  = predict_trajectory(x_init, *v_it, *y_it, config);
            //Calculate the cost
            float to_goal_cost  = config.to_goal_cost_gain  * calc_to_goal_cost(final_state, goal);
            float speed_cost    = config.speed_cost_gain    * (config.max_speed - final_state(3));
            float ob_cost       = config.obstacle_cost_gain * calc_obstacle_cost(final_state, ob, config);

            float final_cost    = to_goal_cost + speed_cost + ob_cost;


            // Search for minimum trajectory
            if (min_cost >= final_cost) {
                min_cost = final_cost;
                best_u = Eigen::Vector2f(*v_it, *y_it);
                best_trajectory = final_state;
                if (abs(best_u[0]) < config.robot_stuck_flag_cons & abs(x[3]) < config.robot_stuck_flag_cons){
                    best_u[1]   = -config.max_delta_yaw_rate;
                }
            }
        }
    }
    return {best_u, best_trajectory};
}



float calc_obstacle_cost(const x_vect& final_state,const obj_mat& ob, const struct Config& config) {
		//calc obstacle cost inf: collision
        //This function calculates the cost due to the the closest object
        obj_arr dx;
        obj_arr dy;

        //find vectors to the objects
        for (int ob_num = 0; ob_num != MAXOBJECTS; ++ob_num){
            dx(ob_num) = ob(ob_num, 0) - final_state(0);
            dy(ob_num) = ob(ob_num, 1) - final_state(1);
        }     
        //Use relative distance to create vector length
        obj_arr r = (dx.pow(2)+dy.pow(2)).sqrt();

        //if you hit an object cost needs to be infinite as this is infeasible option.
        for (int ob_num = 0; ob_num != MAXOBJECTS; ++ob_num){
            if (r(ob_num) <= config.robot_radius){
                    return INFINITY;
            }
        }
        //if not inside obstacle zone return infinite cost; uses last entry of trajectory
        //consider using "trajectory.col(0).back(), trajectory.col(1)).back()", dont know what is faster
        //Need to use external C here to get this function to work
        /*
        else if (!InsideObstacleZone(trajectory(0,STEPS-1), trajectory(1, STEPS-1)){
            return INFINITY;
        }*/
        //DEFine edges of square (four coners)
        //Do some fancy vector math to closest point to any of the square walls
        //TODO add cost to going near wall

        //If feasible return the largest 1/r and use that to determine the cost
		float min_r = r.minCoeff();
		return (1.0/min_r);		
}

float calc_to_goal_cost(const x_vect& final_state, const Eigen::Vector2f& goal){
    //calc to goal cost with angle difference
    //This can be significantly improved with vector math

    float dx            = goal(0) - final_state(0);
    float dy            = goal(1) - final_state(1);
    auto error_angle    = std::atan2(dy, dx);
    auto cost_angle     = error_angle - final_state(2);
    float cost          = std::abs(std::atan2(std::sin(cost_angle),std::cos(cost_angle)));
    return cost;
}

//This is an incomplete helper function to estimate the locations of objects based on the object detection code.
Eigen::Vector2f obs_pos(float heading_angle, int floor_pixels, float psi)
{
  (void)floor_pixels;
  float angle = psi + heading_angle;
  //place object in that direction
  float d = 1.0; //[m] //distance to object
  float object_x = d*cos(angle);
  float object_y = d*sin(angle);
  Eigen::Vector2f object_pos = {object_x, object_y};

  return object_pos;
}