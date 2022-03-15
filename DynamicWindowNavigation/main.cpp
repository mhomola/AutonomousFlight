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

float calc_to_goal_cost(trajectory_mat trajectory, Vector2f goal){
    //calc to goal cost with angle difference
    auto dx = goal[0] - trajectory(last,0);
    auto dy = goal[1] - trajectory[last, 1];
    auto error_angle = atan2(dy, dx);
    auto cost_angle = error_angle - trajectory[last, 2];
    float cost = abs(atan2(sin(cost_angle),cos(cost_angle)));

    return cost
}

def main(gx=10.0, gy=10.0, robot_type=RobotType.circle):
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs


