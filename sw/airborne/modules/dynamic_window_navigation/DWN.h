/*
 * Copyright (C) 2016 Freek van Tienen <freek.v.tienen@gmail.com>
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file modules/ins/ins_ekf2.h
 *
 * INS based in the EKF2 of PX4
 *
 */

#ifndef DWN_H
#define DWN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "modules/ahrs/ahrs.h"
#include "modules/ins/ins.h"

// extern struct u_traj   dwa_control(x_vect& x, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob);
// extern x_vect          motion(x_vect& x, const Eigen::Vector2f& u, const float dt);
// extern dw_vect         calc_dynamic_window(x_vect& x,const struct Config& config);
// extern x_vect          predict_trajectory(const x_vect& x_init, float v, float y, const struct Config& config);
// extern struct u_traj   calc_control_and_trajectory(const x_vect& x, const Eigen::Vector4f& dw, const struct Config& config, const Eigen::Vector2f& goal, const obj_mat& ob);
// extern float           calc_obstacle_cost(const x_vect& final_state,const obj_mat& ob, const struct Config& config);
// extern float           calc_to_goal_cost(const x_vect& final_state, const Eigen::Vector2f& goal);
// extern Eigen::Matrix<float, 1, RESOLUTION> linspace(float start, float stop);
// extern std::vector<T> arange(T start, T stop, T step = 1);


#ifdef __cplusplus
}
#endif

#endif /* DWN_H */
