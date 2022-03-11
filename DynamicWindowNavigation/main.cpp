#include <iostream>
#include <tuple>
#include <math.h>
#include <eigen3/Eigen/Dense> 
using namespace Eigen;

//python arange function
#include <vector>

template<typename T>
std::vector<T> arange(T start, T stop, T step = 1) {
    std::vector<T> values;
    for (T value = start; value < stop; value += step)
        values.push_back(value);
    return values;
}

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
		// predict trajectory with an input

/*
 * Horizontally:
 * MatrixXd C(A.rows(), A.cols()+B.cols());
 * C << A, B;
 *
 * Vertically:
 * // eigen uses provided dimensions in declaration to determine
 * // concatenation direction
 * MatrixXd D(A.rows()+B.rows(), A.cols()); // <-- D(A.rows() + B.rows(), ...)
 * D << A, B; // <-- syntax is the same for vertical and horizontal concatenation
 *
 * MatrixXd trajectory_a(trajectory.rows()+x.rows(), trajectory.cols());
 * trajectory_a >> trajectory,
 * x;
 * trajectory = trajectory_a
 */
		float x[] = {x_init};
		float trajectory[] = {x};
		int time = 0;
		while (time <= config.predict_time){
			x = motion(x, [v, y], config.dt);
			auto trajectory = vstack(trajectory, x) 		//not sure whether this is correct,
															//otherwise use above commented out code
		    time += config.dt;
		}
		return trajectory;
}

tuple<Vector2f, Matrix<float, 1, 5>> calc_control_and_trajectory(x, dw, config, goal, ob) {
    //TODO Nathaniel
    //calculation final input with dynamic window

    Matrix<float, 1, 5>  x_init = x;
    double min_cost = INFINITY;
    Vector2f best_u(0.0, 0.0);
    Matrix<float, 1, 5>  best_trajectory = x;

    //Can we eliminate this in favor of something not double looped
    auto v_range = arange<float>(dw[0], dw[1], config.v_resolution);
    auto y_range = arange<float>(dw[2], dw[3], config.yaw_rate_resolution);
    //Maybe can do a for each?
    for (float v = std::begin(v_range); v != std::end(v_range); ++v) {
        for (float y = std::begin(y_range); y != std::end(y_range); ++y) {

            auto trajectory  = predicted_trajectory(x_init, *v, *y, config);
            //Calculate the cost
            float to_goal_cost= config.to_goal_cost_gain  * calc_to_goal_cost(trajectory, goal);
            float speed_cost  = config.speed_cost_gain    * (config.max_speed - trajectory(-1, 3));
            float ob_cost     = config.obstacle_cost_gain * calc_obstacle_cost(trajectory, ob, config);

            float sinal_csot = to_goal_cost + speed_cost + ob_cost;

            // Search for minimum trajectory
            if (min_cost >= final_cost) {
                min_cost = final_cost;
                best_u = Vector2f(*v, *y);
                best_trajectory = trajectory;
                if (abs(best_u[0]) < config.robot_stuck_flag_cons & abs(x[3]) < config.robot_stuck_flag_cons){
                    best_u[1] = -config.max_delta_yaw_rate;
                }
            }
        }
    }
    return {best_u, best_trajectory};
}


def calc_obstacle_cost(trajectory, ob, config):
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
//TODO Georg

/*
 * """
    calc obstacle cost inf: collision
    """
    ox = ob[:, 0]
    oy = ob[:, 1]
    dx = trajectory[:, 0] - ox[:, None]
    dy = trajectory[:, 1] - oy[:, None]
    r = np.hypot(dx, dy)

    if config.robot_type == RobotType.rectangle:
        yaw = trajectory[:, 2]
        rot = np.array([[np.cos(yaw), -np.sin(yaw)], [np.sin(yaw), np.cos(yaw)]])
        rot = np.transpose(rot, [2, 0, 1])
        local_ob = ob[:, None] - trajectory[:, 0:2]
        local_ob = local_ob.reshape(-1, local_ob.shape[-1])
        local_ob = np.array([local_ob @ x for x in rot])
        local_ob = local_ob.reshape(-1, local_ob.shape[-1])
        upper_check = local_ob[:, 0] <= config.robot_length / 2
        right_check = local_ob[:, 1] <= config.robot_width / 2
        bottom_check = local_ob[:, 0] >= -config.robot_length / 2
        left_check = local_ob[:, 1] >= -config.robot_width / 2
        if (np.logical_and(np.logical_and(upper_check, right_check),
                           np.logical_and(bottom_check, left_check))).any():
            return float("Inf")
    elif config.robot_type == RobotType.circle:
        if np.array(r <= config.robot_radius).any():
            return float("Inf")

    min_r = np.min(r)
    return 1.0 / min_r  # OK
 *
 */
float calc_to_goal_cost(vect trajectory, vect goal){
    //calc to goal cost with angle difference
    float dx = goal[0] - trajectory[-1, 0];
    float dy = goal[1] - trajectory[-1, 1];
    float error_angle = atan2(dy, dx);
    float cost_angle = error_angle - trajectory[-1, 2];
    float cost = abs(atan2(sin(cost_angle),cos(cost_angle)));

    return cost
}

def main(gx=10.0, gy=10.0, robot_type=RobotType.circle):
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs
