#include <iostream>
#include <tuple>
#include <math.h>

tuple<vect, vect> dwa_control(vect x, Config config, vect goal, objectlist ob){
    //Top level control function
    //call Calculate dynamic window
    //call Calculate control and trajectory
    //return control and traject.
    //TODO Nathaniel
    //TODO ensure proper variable types.
    //TODO ensure pointers are used etc.
    
    auto dw = calc_dynamic_window(x, config);
    auto [u, trajectory] = calc_control_and_trajectory(x, dw, config, goal, ob);
    return  {u, trajectory};
}

enum RobotType {circle, rectangle};

struct Config{
    //TODO Nathaniel
    //simulation parameter class
    //Tune stoff here

    using enum RobotType;

    Config() {
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
        }
};

def motion(x, u, dt):
    //TODO figure out if this is just simulating the real world. Do we need to implement something here?
    //TODO is this a placeholder and we just use our drone simulation instead. 
    //TODO this could also be a prediction
    //TODO thijs will figure it out
}

uint8_t calc_dynamic_window(x, config){				// add datatype? uint8_t?
		//TODO Georg
		// calculation dynamic window based on current state x

		// Dynamic window from robot specification
		float Vs[] = {
				config.min_speed, config.max_speed,
				-config.max_yaw_rate, config.max_yaw_rate
		};

		// Dynamic window from motion model
		float Vd[] = {
				x[3] - config.max_accel * config.dt,
				x[3] + config.max_accel * config.dt,
				x[4] - config.max_delta_yaw_rate * config.dt,
				x[4] + config.max_delta_yaw_rate * config.dt
		};

		// [v_min, v_max, yaw_rate_min, yaw_rate_max]
		float dw[] = {
				max(Vs[0], Vd[0]), min(Vs[1], Vd[1]),
				max(Vs[2], Vd[2]), min(Vs[3], Vd[3])
		};

		return dw;
}


def predict_trajectory(x_init, v, y, config):
//TODO Georg

def calc_control_and_trajectory(x, dw, config, goal, ob):
//TODO Nathaniel

def calc_obstacle_cost(trajectory, ob, config):
//TODO Georg

def calc_to_goal_cost(trajectory, goal):
//TODO Thijs

def main(gx=10.0, gy=10.0, robot_type=RobotType.circle):
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs
