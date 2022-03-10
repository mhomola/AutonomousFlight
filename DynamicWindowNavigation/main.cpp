#include <cmath>
def dwa_control(x, config, goal, ob):
    //TODO Nathaniel
}

auto class Config:
//TODO Nathaniel

def motion(x, u, dt):
    //TODO figure out if this is just simulating the real world. Do we need to implement something here?
    //TODO is this a placeholder and we just use our drone simulation instead. 
    //TODO this could also be a prediction
    //TODO thijs will figure it out
}

def calc_dynamic_window(x, config):
//TODO Georg

def predict_trajectory(x_init, v, y, config):
//TODO Georg

def calc_control_and_trajectory(x, dw, config, goal, ob):
//TODO Nathaniel

def calc_obstacle_cost(trajectory, ob, config):
//TODO Georg

def calc_to_goal_cost(trajectory, goal):
//TODO Thijs

int main(){
	float gx=10.0;
	float gy=10.0;
	RobotType robot_type = circle;
	// initial state [x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]
	vect x = {0.0,0.0,M_PI/8.0,0.0,0.0};
	vect goal = {gx,gy};

	config.robot_type = robot_type;
	vect trajectory = x;
	ob = config.ob;

	while (true){
		vect [u, predicted_trajectory] = dwa_control(x,config,goal,ob);
		vect x = motion(x,u,config.dt);

		// trajectory = np.vstack((trajectory, x))  NOT SURE HOW TO IMPLEMENT THIS

		//auto trajectory = ;

		auto dist_to_goal = sqrt(square((x[0]-goal[0]),2) + square((x[1]-goal[1]),2));

		if (dist_to_goal <= config.robot_radius){
			break;
		}

	}
	return 0;
}

