#include <iostream>
#include <tuple>
#include <math.h>
#include <eigen3/Eigen/Dense> 

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

Matrix<float, 1, 4> calc_dynamic_window(Matrix<float, 1, 5> x, struct config){				// is config really a struct?
		//TODO Georg
		// calculation dynamic window based on current state x

		// Dynamic window from robot specification
		Matrix<float, 1, 4> Vs = {config.min_speed, config.max_speed, -config.max_yaw_rate, config.max_yaw_rate};

		// Dynamic window from motion model
		Matrix<float, 1, 4> Vd = {
				x[3] - config.max_accel * config.dt,
				x[3] + config.max_accel * config.dt,
				x[4] - config.max_delta_yaw_rate * config.dt,
				x[4] + config.max_delta_yaw_rate * config.dt
		};

		// [v_min, v_max, yaw_rate_min, yaw_rate_max]
		Matrix<float, 1, 4>  dw = {max(Vs[0], Vd[0]), min(Vs[1], Vd[1]), max(Vs[2], Vd[2]), min(Vs[3], Vd[3])};

		return dw;
}

Matrix<float, 31, 5> predict_trajectory(Matrix<float, 1, 5> x_init, float v, float y, struct config){
		//TODO Georg
		// predict trajectory with an input

		Matrix<float, 1, 5>  x = {x_init};
		Matrix<float, 31, 5>  trajectory= {x};							//starts with just x, but then vstacks them up to 31 times
		float time = 0;
		while (time <= int config.predict_time){
			Matrix<float, 1, 5> x = motion(x, [v, y], float config.dt);
			Matrix<float, 31, 5> trajectory = vstack(trajectory, x) 		//not sure whether vstackworks this way
		    float time += config.dt;
		}
		return trajectory;
}

def calc_control_and_trajectory(x, dw, config, goal, ob):
//TODO Nathaniel

float calc_obstacle_cost(trajectory, ob, config):
//TODO Georg
		//calc obstacle cost inf: collision

		auto ox = ob[:][0];
		auto oy = ob[:][1];
		auto dx = trajectory[:][0] - ox[:][None];
		auto dy = trajectory[:][1] - oy[:][None];
		auto intermediary = dx*dx+dy*dy;
		auto r = sqrt(intermediary);

		if (config.robot_type == RobotType.rectangle){
			auto yaw = trajectory[:][2];
			auto rot [][] = [[cos(yaw), -sin(yaw)], [sin(yaw), cos(yaw)]];
		    auto rot = transpose(rot, [2, 0, 1]);
		    auto local_ob = ob[:][None] - trajectory[:][0:2];
		    auto local_ob = local_ob.reshape(-1, local_ob.shape[-1]);
		    auto local_ob = [local_ob @ x for x in rot];				//fix this
		    auto local_ob = local_ob.reshaped(-1, local_ob.shape[-1]);
		    auto upper_check = local_ob[:][0] <= config.robot_length / 2;
		    auto right_check = local_ob[:][1] <= config.robot_width / 2;
		    auto bottom_check = local_ob[:][0] >= -config.robot_length / 2;
		    auto left_check = local_ob[:][1] >= -config.robot_width / 2;
		    if ((logical_and(logical_and(upper_check, right_check),logical_and(bottom_check, left_check))).any()){
		    	return float("Inf");
		        }
		} else if (config.robot_type == RobotType.circle){
			if ([r <= config.robot_radius].any()){
				return float("Inf");
			}
		}


		min_r = min(r);
		return 1.0 / min_r;		// OK

}

def calc_to_goal_cost(trajectory, goal):
//TODO Thijs

def main(gx=10.0, gy=10.0, robot_type=RobotType.circle):
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs
