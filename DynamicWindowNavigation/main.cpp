#include <tuple>
#include <cmath>

def dwa_control(x, config, goal, ob):
    //TODO Nathaniel
}

auto class Config:
//TODO Nathaniel

tuple<vect> motion(vect x, vect u, float dt){

    x[2] += u[1] * dt;
    x[0] += u[0] * cos(x[2]) * dt;
    x[1] += u[0] * sin(x[2]) * dt;
    x[3] = u[0];
    x[4] = u[1];

    return x;
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

def main(gx=10.0, gy=10.0, robot_type=RobotType.circle):
//DODO just call the functions in the right order (just implement the while loop)
//TODO Thijs
