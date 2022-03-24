/*
 * Copyright (C) 2014 Hann Woei Ho
 *               2015 Freek van Tienen <freek.v.tienen@gmail.com>
 *               2016 Kimberly McGuire <k.n.mcguire@tudelft.nl
 *
 * This file is part of Paparazzi.
 *
 * Paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * Paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file modules/computer_vision/opticflow/opticflow_calculator.c
 * @brief Estimate velocity from optic flow.
 *
 */

#include "std.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <state.h>

// Own Header group 11
#include "opticflow_calculator.h"

// Computer Vision
#include "lib/vision/image.h"
#include "lib/vision/lucas_kanade.h"
#include "lib/vision/fast_rosten.h"
#include "lib/vision/act_fast.h"
#include "lib/vision/edge_flow.h"
#include "lib/vision/undistortion.h"
#include "size_divergence.h"
#include "linear_flow_fit.h"
#include "modules/sonar/agl_dist.h"

// to get the definition of front_camera / bottom_camera
#include BOARD_CONFIG

// whether to show the flow and corners:
#define OPTICFLOW_SHOW_CORNERS 1

// How to select interesting features:
#define GRID 0    // grid points (dense flow)
#define EXHAUSTIVE_FAST 1   //corners
#define ACT_FAST 2     //corners


// TODO: these are now adapted, but perhaps later could be a setting:
uint16_t n_time_steps[2] = {10, 10};
uint16_t n_agents[2] = {25, 25};

// What methods are run to determine divergence, lateral flow, etc.
// SIZE_DIV looks at line sizes and only calculates divergence
#define SIZE_DIV 1
// LINEAR_FIT makes a linear optical flow field fit and extracts a lot of information:
// relative velocities in x, y, z (divergence / time to contact), the slope of the surface, and the surface roughness.
#define LINEAR_FIT 1




#ifndef OPTICFLOW_CORNER_METHOD_CAMERA
#define OPTICFLOW_CORNER_METHOD_CAMERA GRID    // Change here the method
#endif

#ifndef ALPHA
#define ALPHA 0.9  // Change here the method: 1. for no averaging 
#endif

#ifndef SUBSAMPLING_FACTOR
#define SUBSAMPLING_FACTOR 10   // >> lower value measns fewer features to track (decrease for better FPS)
#endif

PRINT_CONFIG_VAR(OPTICFLOW_CORNER_METHOD_CAMERA)



#ifndef OPTICFLOW_MAX_TRACK_CORNERS_CAMERA
  #if OPTICFLOW_CORNER_METHOD_CAMERA == 0 
    #define OPTICFLOW_MAX_TRACK_CORNERS_CAMERA 200
  #else 
    #define OPTICFLOW_MAX_TRACK_CORNERS_CAMERA 40
  #endif
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_MAX_TRACK_CORNERS)



#ifndef OPTICFLOW_WINDOW_SIZE_CAMERA
#define OPTICFLOW_WINDOW_SIZE_CAMERA 10
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_WINDOW_SIZE)



#ifndef OPTICFLOW_SEARCH_DISTANCE_CAMERA
#define OPTICFLOW_SEARCH_DISTANCE_CAMERA 20
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_SEARCH_DISTANCE)



#ifndef OPTICFLOW_SUBPIXEL_FACTOR_CAMERA
#define OPTICFLOW_SUBPIXEL_FACTOR_CAMERA 10  // >> not this one
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_SUBPIXEL_FACTOR)



#ifndef OPTICFLOW_RESOLUTION_FACTOR_CAMERA
#define OPTICFLOW_RESOLUTION_FACTOR_CAMERA 100      // >> not this one
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_RESOLUTION_FACTOR)



#ifndef OPTICFLOW_MAX_ITERATIONS_CAMERA
#define OPTICFLOW_MAX_ITERATIONS_CAMERA 10
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_MAX_ITERATIONS)


#ifndef OPTICFLOW_THRESHOLD_VEC_CAMERA
#define OPTICFLOW_THRESHOLD_VEC_CAMERA 20   // >> not this one
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_THRESHOLD_VEC)




#ifndef OPTICFLOW_PYRAMID_LEVEL_CAMERA
#define OPTICFLOW_PYRAMID_LEVEL_CAMERA 3    // >> not this one
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_PYRAMID_LEVEL)



#ifndef OPTICFLOW_FAST9_ADAPTIVE_CAMERA
#define OPTICFLOW_FAST9_ADAPTIVE_CAMERA FALSE
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_FAST9_ADAPTIVE)




#ifndef OPTICFLOW_FAST9_THRESHOLD_CAMERA
  #if OPTICFLOW_CORNER_METHOD_CAMERA == 0 
    #define OPTICFLOW_FAST9_THRESHOLD_CAMERA 100
  #else 
    #define OPTICFLOW_FAST9_THRESHOLD_CAMERA 30
  #endif
#endif

// PRINT_CONFIG_VAR(OPTICFLOW_FAST9_THRESHOLD)




#ifndef OPTICFLOW_FAST9_MIN_DISTANCE_CAMERA
#define OPTICFLOW_FAST9_MIN_DISTANCE_CAMERA 10
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_FAST9_MIN_DISTANCE)



#ifndef OPTICFLOW_FAST9_PADDING_CAMERA
#define OPTICFLOW_FAST9_PADDING_CAMERA 20
#endif
PRINT_CONFIG_VAR(OPTICFLOW_FAST9_PADDING)


// thresholds FAST9 that are currently not set from the GCS:
#define FAST9_LOW_THRESHOLD 5
#define FAST9_HIGH_THRESHOLD 60

// 0 for LK and 1 for EDGE flow 

#ifndef OPTICFLOW_METHOD_CAMERA
#define OPTICFLOW_METHOD_CAMERA 0
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_METHOD_CAMERA)


#if OPTICFLOW_METHOD_CAMERA > 1
#error WARNING: Both Lukas Kanade and EdgeFlow are NOT selected camera2
#endif


#ifndef OPTICFLOW_DEROTATION_CAMERA
#define OPTICFLOW_DEROTATION_CAMERA TRUE
#endif

// PRINT_CONFIG_VAR(OPTICFLOW_DEROTATION_CAMERA)



#ifndef OPTICFLOW_DEROTATION_CORRECTION_FACTOR_X_CAMERA
#define OPTICFLOW_DEROTATION_CORRECTION_FACTOR_X_CAMERA 1.0
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_DEROTATION_CORRECTION_FACTOR_X)


#ifndef OPTICFLOW_DEROTATION_CORRECTION_FACTOR_Y_CAMERA
#define OPTICFLOW_DEROTATION_CORRECTION_FACTOR_Y_CAMERA 1.0
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_DEROTATION_CORRECTION_FACTOR_Y_CAMERA)


#ifndef OPTICFLOW_MEDIAN_FILTER_CAMERA
#define OPTICFLOW_MEDIAN_FILTER_CAMERA FALSE
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_MEDIAN_FILTER)


#ifndef OPTICFLOW_FEATURE_MANAGEMENT_CAMERA
#define OPTICFLOW_FEATURE_MANAGEMENT_CAMERA 0
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_FEATURE_MANAGEMENT_CAMERA)


#ifndef OPTICFLOW_FAST9_REGION_DETECT
#define OPTICFLOW_FAST9_REGION_DETECT_CAMERA 1
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_FAST9_REGION_DETECT)


#ifndef OPTICFLOW_FAST9_NUM_REGIONS_CAMERA
#define OPTICFLOW_FAST9_NUM_REGIONS_CAMERA 9
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_FAST9_NUM_REGIONS)


#ifndef OPTICFLOW_ACTFAST_LONG_STEP_CAMERA
#define OPTICFLOW_ACTFAST_LONG_STEP_CAMERA 10
#endif
PRINT_CONFIG_VAR(OPTICFLOW_ACTFAST_LONG_STEP_CAMERA)


#ifndef OPTICFLOW_ACTFAST_SHORT_STEP_CAMERA
#define OPTICFLOW_ACTFAST_SHORT_STEP_CAMERA 2
#endif
PRINT_CONFIG_VAR(OPTICFLOW_ACTFAST_SHORT_STEP_CAMERA)


#ifndef OPTICFLOW_ACTFAST_GRADIENT_METHOD_CAMERA
#define OPTICFLOW_ACTFAST_GRADIENT_METHOD_CAMERA 1
#endif
// PRINT_CONFIG_VAR(OPTICFLOW_ACTFAST_GRADIENT_METHOD)



#ifndef OPTICFLOW_ACTFAST_MIN_GRADIENT_CAMERA
#define OPTICFLOW_ACTFAST_MIN_GRADIENT_CAMERA 10
#endif


// Defaults for ARdrone

#ifndef OPTICFLOW_BODY_TO_CAM_PHI_CAMERA
#define OPTICFLOW_BODY_TO_CAM_PHI_CAMERA 0
#endif
#ifndef OPTICFLOW_BODY_TO_CAM_THETA_CAMERA
#define OPTICFLOW_BODY_TO_CAM_THETA_CAMERA 0
#endif
#ifndef OPTICFLOW_BODY_TO_CAM_PSI_CAMERA
#define OPTICFLOW_BODY_TO_CAM_PSI_CAMERA -M_PI_2
#endif

// Tracking back flow to make the accepted flow vectors more robust:
// Default is false, as it does take extra processing time


#ifndef OPTICFLOW_TRACK_BACK_CAMERA
#define OPTICFLOW_TRACK_BACK_CAMERA TRUE
#endif


// Whether to draw the flow on the image:
// False by default, since it changes the image and costs time.

// front camera
#ifndef OPTICFLOW_SHOW_FLOW_CAMERA
#define OPTICFLOW_SHOW_FLOW_CAMERA TRUE
#endif



//Include median filter
#include "filters/median_filter.h"
struct MedianFilter3Float vel_filt;
struct FloatRMat body_to_cam[2];

/* Functions only used here */
static uint32_t timeval_diff(struct timeval *starttime, struct timeval *finishtime);
static int cmp_flow(const void *a, const void *b);
static int cmp_array(const void *a, const void *b);
static void manage_flow_features(struct image_t *img, struct opticflow_t *opticflow,
                                 struct opticflow_result_t *result);

static struct flow_t *predict_flow_vectors(struct flow_t *flow_vectors, uint16_t n_points, float phi_diff,
    float theta_diff, float psi_diff, struct opticflow_t *opticflow);
/**
 * Initialize the opticflow calculator
 * @param[out] *opticflow The new optical flow calculator
 */
void opticflow_calc_init(struct opticflow_t opticflow[])
{
  opticflow[0].method = OPTICFLOW_METHOD_CAMERA; //0 = LK_fast9, 1 = Edgeflow
  opticflow[0].window_size = OPTICFLOW_WINDOW_SIZE_CAMERA;
  opticflow[0].alpha = ALPHA;
  opticflow[0].search_distance = OPTICFLOW_SEARCH_DISTANCE_CAMERA;
  opticflow[0].derotation = OPTICFLOW_DEROTATION_CAMERA; //0 = OFF, 1 = ON
  opticflow[0].derotation_correction_factor_x = OPTICFLOW_DEROTATION_CORRECTION_FACTOR_X_CAMERA;
  opticflow[0].derotation_correction_factor_y = OPTICFLOW_DEROTATION_CORRECTION_FACTOR_Y_CAMERA;
  opticflow[0].track_back = OPTICFLOW_TRACK_BACK_CAMERA;
  opticflow[0].show_flow = OPTICFLOW_SHOW_FLOW_CAMERA;
  opticflow[0].max_track_corners = OPTICFLOW_MAX_TRACK_CORNERS_CAMERA;
  opticflow[0].subpixel_factor = OPTICFLOW_SUBPIXEL_FACTOR_CAMERA;
  if (opticflow[0].subpixel_factor == 0) {
    opticflow[0].subpixel_factor = 10;
  }
  opticflow[0].resolution_factor = OPTICFLOW_RESOLUTION_FACTOR_CAMERA;
  opticflow[0].max_iterations = OPTICFLOW_MAX_ITERATIONS_CAMERA;
  opticflow[0].threshold_vec = OPTICFLOW_THRESHOLD_VEC_CAMERA;
  opticflow[0].pyramid_level = OPTICFLOW_PYRAMID_LEVEL_CAMERA;
  opticflow[0].median_filter = OPTICFLOW_MEDIAN_FILTER_CAMERA;
  opticflow[0].feature_management = OPTICFLOW_FEATURE_MANAGEMENT_CAMERA;
  opticflow[0].fast9_region_detect = OPTICFLOW_FAST9_REGION_DETECT_CAMERA;
  opticflow[0].fast9_num_regions = OPTICFLOW_FAST9_NUM_REGIONS_CAMERA;

  opticflow[0].fast9_adaptive = OPTICFLOW_FAST9_ADAPTIVE_CAMERA;
  opticflow[0].fast9_threshold = OPTICFLOW_FAST9_THRESHOLD_CAMERA;
  opticflow[0].fast9_min_distance = OPTICFLOW_FAST9_MIN_DISTANCE_CAMERA;
  opticflow[0].fast9_padding = OPTICFLOW_FAST9_PADDING_CAMERA;
  opticflow[0].fast9_rsize = FAST9_MAX_CORNERS;
  opticflow[0].fast9_ret_corners = calloc(opticflow[0].fast9_rsize, sizeof(struct point_t));

  opticflow[0].corner_method = OPTICFLOW_CORNER_METHOD_CAMERA;
  opticflow[0].actfast_long_step = OPTICFLOW_ACTFAST_LONG_STEP_CAMERA;
  opticflow[0].actfast_short_step = OPTICFLOW_ACTFAST_SHORT_STEP_CAMERA;
  opticflow[0].actfast_min_gradient = OPTICFLOW_ACTFAST_MIN_GRADIENT_CAMERA;
  opticflow[0].actfast_gradient_method = OPTICFLOW_ACTFAST_GRADIENT_METHOD_CAMERA;

  opticflow[0].camera = &OPTICFLOW_CAMERA;
  opticflow[0].id = 1;

  struct FloatEulers euler_cam2 = {OPTICFLOW_BODY_TO_CAM_PHI_CAMERA, OPTICFLOW_BODY_TO_CAM_THETA_CAMERA,
      OPTICFLOW_BODY_TO_CAM_PSI_CAMERA};
  float_rmat_of_eulers(&body_to_cam[1], &euler_cam2);

}
/**
 * Run the optical flow with fast9 and lukaskanade on a new image frame.
 * The magic happens in this function.
 * @param[in] *opticflow The opticalflow structure that keeps track of previous images
 * @param[in] *state The state of the drone
 * @param[in] *img The image frame to calculate the optical flow from
 * @param[out] *result The optical flow result
 * @return Was optical flow successful
 */
bool calc_fast9_lukas_kanade(struct opticflow_t *opticflow, struct image_t *img,
                             struct opticflow_result_t *result)
{
  if (opticflow->just_switched_method) {
    // Create the image buffers
    image_create(&opticflow->img_gray, img->w, img->h, IMAGE_GRAYSCALE);
    image_create(&opticflow->prev_img_gray, img->w, img->h, IMAGE_GRAYSCALE);

    // Set the previous values
    opticflow->got_first_img = false;

    // Init median filters with zeros
    InitMedianFilterVect3Float(vel_filt, MEDIAN_DEFAULT_SIZE);
  }

  // Convert image to grayscale
  image_to_grayscale(img, &opticflow->img_gray);

  if (!opticflow->got_first_img) {
    image_copy(&opticflow->img_gray, &opticflow->prev_img_gray);
    opticflow->got_first_img = true;
    return false;
  }

  // // variables for linear flow fit:
  // float error_threshold;
  // int n_iterations_RANSAC, n_samples_RANSAC, success_fit;
  // struct linear_flow_fit_info fit_info;

  // Update FPS for information
  float cur_yaw_command = 0.0;
  float dt = timeval_diff(&(opticflow->prev_img_gray.ts), &(img->ts));
  if (dt > 1e-5) {
    result->fps = 1000.f / dt;
  } else {
    return false;
  }

  // *************************************************************************************
  // Corner detection
  // *************************************************************************************
  // TODO: 
  // if feature_management is selected and tracked corners drop below a threshold, redetect
  if ((opticflow->feature_management) && (result->corner_cnt < opticflow->max_track_corners / 2)) 
    manage_flow_features(img, opticflow, result);
  else if (!opticflow->feature_management) {
    // needs to be set to 0 because result is now static
    result->corner_cnt = 0;

    if (opticflow->corner_method == EXHAUSTIVE_FAST) {
      // FAST corner detection
      fast9_detect(&opticflow->prev_img_gray, opticflow->fast9_threshold, opticflow->fast9_min_distance,
                   opticflow->fast9_padding, opticflow->fast9_padding, &result->corner_cnt, &opticflow->fast9_rsize,
                   &opticflow->fast9_ret_corners, NULL);

    } else if (opticflow->corner_method == ACT_FAST) {
      // ACT-FAST corner detection:
      act_fast(&opticflow->prev_img_gray, opticflow->fast9_threshold, &result->corner_cnt,
               &opticflow->fast9_ret_corners, n_agents[opticflow->id], n_time_steps[opticflow->id],
               opticflow->actfast_long_step, opticflow->actfast_short_step, opticflow->actfast_min_gradient,
               opticflow->actfast_gradient_method, opticflow->id);

    } else if (opticflow->corner_method == GRID){
      // Manually set a grid of 'corners' to track -- shoudl be much cheaper computationally
      int i,j;
      for(i=1; i < opticflow->prev_img_gray.w; i=i+opticflow->prev_img_gray.w/SUBSAMPLING_FACTOR)
        for(j=1; j < opticflow->prev_img_gray.h; j=j+opticflow->prev_img_gray.h/SUBSAMPLING_FACTOR)
          {
            opticflow->fast9_ret_corners[result->corner_cnt].x = i;
            opticflow->fast9_ret_corners[result->corner_cnt].y = j;
            result->corner_cnt++;  // update corner counter

          }
    }
  }

  // Show corners on the video recording:
  #if OPTICFLOW_SHOW_CORNERS
    image_show_points(img, opticflow->fast9_ret_corners, result->corner_cnt);
  #endif

  if (opticflow->corner_method != GRID)
  {
      // printf("--- %s is using method %d ", opticflow->camera->dev_name,opticflow->corner_method);
    // Adaptive threshold
    // NOTE This one is set to True
    // if (opticflow->fast9_adaptive) {

    //   // This works well for exhaustive FAST, but drives the threshold to the minimum for ACT-FAST:
    //   // Decrease and increase the threshold based on previous values
    //   if (result->corner_cnt < opticflow->max_track_corners / 2) {
    //     // make detections easier:
    //     if (opticflow->fast9_threshold > FAST9_LOW_THRESHOLD) {
    //       opticflow->fast9_threshold--;
    //     }

    //     if (opticflow->corner_method == ACT_FAST && n_agents[opticflow->id] < opticflow->fast9_rsize) {
    //       n_time_steps[opticflow->id]++;
    //       n_agents[opticflow->id]++;
    //     }

    //   } else if (result->corner_cnt > opticflow->max_track_corners * 2) {

    //     if (opticflow->fast9_threshold < FAST9_HIGH_THRESHOLD) {
    //       opticflow->fast9_threshold++;
    //     }

    //     if (opticflow->corner_method == ACT_FAST && n_time_steps[opticflow->id] > 5 && n_agents[opticflow->id] > 10) {
    //       n_time_steps[opticflow->id]--;
    //       n_agents[opticflow->id]--;
    //     }
    //   }
    // }
    // Check if we found some corners to track
    if (result->corner_cnt < 1) {

      result->yaw_command = 0.0;
      result->noise_measurement = 5.0;

      image_switch(&opticflow->img_gray, &opticflow->prev_img_gray);
      return false;
    }
  }

  // *************************************************************************************
  //                                      Corner/Grid-points Tracking
  // *************************************************************************************

  // Execute a Lucas Kanade optical flow
  result->tracked_cnt = result->corner_cnt;
  // printf("%s: Conrers dected: %d\n",opticflow->camera->dev_name,result->corner_cnt);
  // printf("--Max tracked corners: %d \n",opticflow->max_track_corners);
  
  uint8_t keep_bad_points = 0;
  struct flow_t *vectors = opticFlowLK(&opticflow->img_gray, &opticflow->prev_img_gray, opticflow->fast9_ret_corners,
                                       &result->tracked_cnt,
                                       opticflow->window_size / 2, opticflow->subpixel_factor, opticflow->max_iterations,
                                       opticflow->threshold_vec, opticflow->max_track_corners, opticflow->pyramid_level, keep_bad_points);
  


  if (opticflow->track_back) {
    // TODO: Watch out!
    // We track the flow back and give badly back-tracked vectors a high error,
    // but we do not yet remove these vectors, nor use the errors in any other function than showing the flow.

    // initialize corners at the tracked positions:
    for (int i = 0; i < result->tracked_cnt; i++) {
      opticflow->fast9_ret_corners[i].x = (uint32_t)(vectors[i].pos.x + vectors[i].flow_x) / opticflow->subpixel_factor;
      opticflow->fast9_ret_corners[i].y = (uint32_t)(vectors[i].pos.y + vectors[i].flow_y) / opticflow->subpixel_factor;
    }

    // present the images in the opposite order:
    keep_bad_points = 1;
    uint16_t back_track_cnt = result->tracked_cnt;
    struct flow_t *back_vectors = opticFlowLK(&opticflow->prev_img_gray, &opticflow->img_gray, opticflow->fast9_ret_corners,
                                  &back_track_cnt,
                                  opticflow->window_size / 2, opticflow->subpixel_factor, opticflow->max_iterations,
                                  opticflow->threshold_vec, opticflow->max_track_corners, opticflow->pyramid_level, keep_bad_points);

    
    int32_t back_x, back_y, diff_x, diff_y, dist_squared;
    int32_t back_track_threshold = 200;

    for (int i = 0; i < result->tracked_cnt; i++) {
      if (back_vectors[i].error < LARGE_FLOW_ERROR) {
        back_x = (int32_t)(back_vectors[i].pos.x + back_vectors[i].flow_x);
        back_y = (int32_t)(back_vectors[i].pos.y + back_vectors[i].flow_y);
        diff_x = back_x - vectors[i].pos.x;
        diff_y = back_y - vectors[i].pos.y;
        dist_squared = diff_x * diff_x + diff_y * diff_y;
        // printf("Vector %d: x,y = %d, %d, back x, y = %d, %d, back tracking error %d\n", i, vectors[i].pos.x, vectors[i].pos.y, back_x, back_y, dist_squared);
        if (dist_squared > back_track_threshold) {
          vectors[i].error = LARGE_FLOW_ERROR;
        }
      } else {
        vectors[i].error = LARGE_FLOW_ERROR;
      }
    }
    // Free-up back-tracked vectors:
    free(back_vectors);
  }

  if (opticflow->show_flow) {
    uint8_t color[4] = {100, 100, 0, 0};
    uint8_t bad_color[4] = {255, 255, 0, 0};
    image_show_flow_color(img, vectors, result->tracked_cnt, opticflow->subpixel_factor, color, bad_color);
  }

  // Median filter on OF
  qsort(vectors, result->tracked_cnt, sizeof(struct flow_t), cmp_flow);
  if (result->tracked_cnt == 0) {
    // We got no flow
    result->flow_x = 0;
    result->flow_y = 0;
    result->yaw_command = 0.;

    free(vectors);
    image_switch(&opticflow->img_gray, &opticflow->prev_img_gray);
    return false;

  } else if (result->tracked_cnt % 2) {
    // Take the median point
    result->flow_x = vectors[result->tracked_cnt / 2].flow_x;
    result->flow_y = vectors[result->tracked_cnt / 2].flow_y;
  } else {
    // Take the average of the 2 median points (because there are odd number of vectors)
    result->flow_x = (vectors[result->tracked_cnt / 2 - 1].flow_x + vectors[result->tracked_cnt / 2].flow_x) / 2.f;
    result->flow_y = (vectors[result->tracked_cnt / 2 - 1].flow_y + vectors[result->tracked_cnt / 2].flow_y) / 2.f;
  }

  // TODO scale flow to rad/s here

  // ******************************************************************************************
  //                                 Flow De-rotation
  // ******************************************************************************************
  float diff_flow_x = 0.f;
  float diff_flow_y = 0.f;

  if (opticflow->derotation && result->tracked_cnt > 5) {

    float rotation_threshold = M_PI / 180.0f;   // rad/deg
    if (fabs(opticflow->img_gray.eulers.phi - opticflow->prev_img_gray.eulers.phi) > rotation_threshold
        || fabs(opticflow->img_gray.eulers.theta - opticflow->prev_img_gray.eulers.theta) > rotation_threshold) {

      // do not apply the derotation if the rotation rates are too high:
      result->flow_der_x = 0.0f;
      result->flow_der_y = 0.0f;

    } else {
      // NOTE: It does perform the de-rotation
      // determine the roll, pitch, yaw differencces between the images.
      
      float phi_diff = opticflow->img_gray.eulers.phi - opticflow->prev_img_gray.eulers.phi;
      float theta_diff = opticflow->img_gray.eulers.theta - opticflow->prev_img_gray.eulers.theta;
      float psi_diff = opticflow->img_gray.eulers.psi - opticflow->prev_img_gray.eulers.psi;

      if (strcmp(opticflow->camera->dev_name, bottom_camera.dev_name) == 0) {
        // bottom cam: just subtract a scaled version of the roll and pitch difference from the global flow vector:
        diff_flow_x = phi_diff * opticflow->camera->camera_intrinsics.focal_x; // phi_diff works better than (cam_state->rates.p)
        diff_flow_y = theta_diff * opticflow->camera->camera_intrinsics.focal_y;
        result->flow_der_x = result->flow_x - diff_flow_x * opticflow->subpixel_factor *
                             opticflow->derotation_correction_factor_x;
        result->flow_der_y = result->flow_y - diff_flow_y * opticflow->subpixel_factor *
                             opticflow->derotation_correction_factor_y;
      } else {
        // frontal cam, predict individual flow vectors:
        struct flow_t *predicted_flow_vectors = predict_flow_vectors(vectors, result->tracked_cnt, phi_diff, theta_diff,
                                                psi_diff, opticflow);
        // if (opticflow->show_flow) {
        //   uint8_t color[4] = {255, 255, 255, 255};
        //   uint8_t bad_color[4] = {255, 255, 0, 255};
        //   image_show_flow_color(img, predicted_flow_vectors, result->tracked_cnt, opticflow->subpixel_factor, color, bad_color);
        // }

        for (int i = 0; i < result->tracked_cnt; i++) {
          // subtract the flow:
          vectors[i].flow_x -= predicted_flow_vectors[i].flow_x;
          vectors[i].flow_y -= predicted_flow_vectors[i].flow_y;
        }


        // vectors have to be re-sorted after derotation:
        qsort(vectors, result->tracked_cnt, sizeof(struct flow_t), cmp_flow);

        if (result->tracked_cnt % 2) {
          // Take the median point
          result->flow_der_x = vectors[result->tracked_cnt / 2].flow_x;
          result->flow_der_y = vectors[result->tracked_cnt / 2].flow_y;
        } else {
          // Take the average of the 2 median points
          result->flow_der_x = (vectors[result->tracked_cnt / 2 - 1].flow_x + vectors[result->tracked_cnt / 2].flow_x) / 2.f;
          result->flow_der_y = (vectors[result->tracked_cnt / 2 - 1].flow_y + vectors[result->tracked_cnt / 2].flow_y) / 2.f;
        }
      }
    }
  }
  result->camera_id = opticflow->id;
  result->noise_measurement = 0.25;
  // *************************************************************************************
  //                              Calculate yaw Command
  // *************************************************************************************


    if (strcmp(opticflow->camera->dev_name, front_camera.dev_name) == 0)
  { 


    cur_yaw_command = get_heading_command(vectors, result->tracked_cnt, opticflow->prev_img_gray.h, opticflow->subpixel_factor);
    result->yaw_command = opticflow->alpha * cur_yaw_command + (1-opticflow->alpha) * result->yaw_command;

    // yaw_command_group11 = result->yaw_command;

  }

  // *************************************************************************************
  //                              Next Loop Preparation
  // *************************************************************************************
  if (opticflow->feature_management) {
    result->corner_cnt = result->tracked_cnt;
    //get the new positions of the corners and the "residual" subpixel positions
    for (uint16_t i = 0; i < result->tracked_cnt; i++) {
      opticflow->fast9_ret_corners[i].x = (uint32_t)((vectors[i].pos.x + (float)vectors[i].flow_x) /
                                          opticflow->subpixel_factor);
      opticflow->fast9_ret_corners[i].y = (uint32_t)((vectors[i].pos.y + (float)vectors[i].flow_y) /
                                          opticflow->subpixel_factor);
      opticflow->fast9_ret_corners[i].x_sub = (uint16_t)((vectors[i].pos.x + vectors[i].flow_x) % opticflow->subpixel_factor);
      opticflow->fast9_ret_corners[i].y_sub = (uint16_t)((vectors[i].pos.y + vectors[i].flow_y) % opticflow->subpixel_factor);
      opticflow->fast9_ret_corners[i].count = vectors[i].pos.count;
    }
  }
  free(vectors);
  image_switch(&opticflow->img_gray, &opticflow->prev_img_gray);
  return true;
}




/*
 * Predict flow vectors by means of the rotation rates:
 */
static struct flow_t *predict_flow_vectors(struct flow_t *flow_vectors, uint16_t n_points, float phi_diff,
    float theta_diff, float psi_diff, struct opticflow_t *opticflow)
{

  // reserve memory for the predicted flow vectors:
  struct flow_t *predicted_flow_vectors = malloc(sizeof(struct flow_t) * n_points);

  float K[9] = {opticflow->camera->camera_intrinsics.focal_x, 0.0f, opticflow->camera->camera_intrinsics.center_x,
                0.0f, opticflow->camera->camera_intrinsics.focal_y, opticflow->camera->camera_intrinsics.center_y,
                0.0f, 0.0f, 1.0f
               };
  // TODO: make an option to not do distortion / undistortion (Dhane_k = 1)
  float k = opticflow->camera->camera_intrinsics.Dhane_k;

  float A, B, C; // as in Longuet-Higgins

  if (strcmp(opticflow->camera->dev_name, front_camera.dev_name) == 0) {
    // specific for the x,y swapped Bebop 2 images:
    A = -psi_diff;  // why is the yaw with opposite sign
    B = theta_diff;
    C = phi_diff;
  } else {
    A = theta_diff;
    B = phi_diff;
    C = psi_diff;
  }

  float x_n, y_n;
  float x_n_new, y_n_new, x_pix_new, y_pix_new;
  float predicted_flow_x, predicted_flow_y;
  for (uint16_t i = 0; i < n_points; i++) {
    // the from-coordinate is always the same:
    predicted_flow_vectors[i].pos.x = flow_vectors[i].pos.x;
    predicted_flow_vectors[i].pos.y = flow_vectors[i].pos.y;

    bool success = distorted_pixels_to_normalized_coords((float)flow_vectors[i].pos.x / opticflow->subpixel_factor,
                   (float)flow_vectors[i].pos.y / opticflow->subpixel_factor, &x_n, &y_n, k, K);
    if (success) {
      // predict flow as in a linear pinhole camera model:
      predicted_flow_x = A * x_n * y_n - B * x_n * x_n - B + C * y_n;
      predicted_flow_y = -C * x_n + A + A * y_n * y_n - B * x_n * y_n;

      x_n_new = x_n + predicted_flow_x;
      y_n_new = y_n + predicted_flow_y;

      success = normalized_coords_to_distorted_pixels(x_n_new, y_n_new, &x_pix_new, &y_pix_new, k, K);

      if (success) {
        predicted_flow_vectors[i].flow_x = (int16_t)(x_pix_new * opticflow->subpixel_factor - (float)flow_vectors[i].pos.x);
        predicted_flow_vectors[i].flow_y = (int16_t)(y_pix_new * opticflow->subpixel_factor - (float)flow_vectors[i].pos.y);
        predicted_flow_vectors[i].error = 0;
      } else {
        predicted_flow_vectors[i].flow_x = 0;
        predicted_flow_vectors[i].flow_y = 0;
        predicted_flow_vectors[i].error = LARGE_FLOW_ERROR;
      }
    } else {
      predicted_flow_vectors[i].flow_x = 0;
      predicted_flow_vectors[i].flow_y = 0;
      predicted_flow_vectors[i].error = LARGE_FLOW_ERROR;
    }
  }
  return predicted_flow_vectors;
}


/* manage_flow_features - Update list of corners to be tracked by LK
 * Remembers previous points and tries to find new points in less dense
 * areas of the image first.
 *
 */
static void manage_flow_features(struct image_t *img, struct opticflow_t *opticflow, struct opticflow_result_t *result)
{   

  if (opticflow->corner_method != GRID){
    // check if corners have not moved too close together due to flow:
    // NOTE it only makes sense to do this if the GRID method is not used i.e. if the corners can actually move
    int16_t c1 = 0;
    while (c1 < (int16_t)result->corner_cnt - 1) {
      bool exists = false;
      for (int16_t i = c1 + 1; i < result->corner_cnt; i++) {
        if (abs((int16_t)opticflow->fast9_ret_corners[c1].x - (int16_t)opticflow->fast9_ret_corners[i].x) <
            opticflow->fast9_min_distance / 2
            && abs((int16_t)opticflow->fast9_ret_corners[c1].y - (int16_t)opticflow->fast9_ret_corners[i].y) <
            opticflow->fast9_min_distance / 2) {
          // if too close, replace the corner with the last one in the list:
          opticflow->fast9_ret_corners[c1].x = opticflow->fast9_ret_corners[result->corner_cnt - 1].x;
          opticflow->fast9_ret_corners[c1].y = opticflow->fast9_ret_corners[result->corner_cnt - 1].y;
          opticflow->fast9_ret_corners[c1].count = opticflow->fast9_ret_corners[result->corner_cnt - 1].count;
          opticflow->fast9_ret_corners[c1].x_sub = opticflow->fast9_ret_corners[result->corner_cnt - 1].x_sub;
          opticflow->fast9_ret_corners[c1].y_sub = opticflow->fast9_ret_corners[result->corner_cnt - 1].y_sub;

          // decrease the number of corners:
          result->corner_cnt--;
          exists = true;
          // no further checking required for the removed corner
          break;
        }
      }
      // if the corner has been replaced, the new corner in position c1 has to be checked again:
      if (!exists) { c1++; }
    }
  }

  // no need for "per region" re-detection when there are no previous corners
  if ((!opticflow->fast9_region_detect) || (result->corner_cnt == 0)) {
    fast9_detect(&opticflow->prev_img_gray, opticflow->fast9_threshold, opticflow->fast9_min_distance,
                 opticflow->fast9_padding, opticflow->fast9_padding, &result->corner_cnt,
                 &opticflow->fast9_rsize,
                 &opticflow->fast9_ret_corners,
                 NULL);
  } else {
    // allocating memory and initializing the 2d array that holds the number of corners per region and its index (for the sorting)
    uint16_t **region_count = calloc(opticflow->fast9_num_regions, sizeof(uint16_t *));
    for (uint16_t i = 0; i < opticflow->fast9_num_regions; i++) {
      region_count[i] = calloc(2, sizeof(uint16_t));
      region_count[i][0] = 0;
      region_count[i][1] = i;
    }
    uint16_t root_regions = (uint16_t)sqrtf((float)opticflow->fast9_num_regions);
    int region_index;
    for (uint16_t i = 0; i < result->corner_cnt; i++) {
      region_index = (opticflow->fast9_ret_corners[i].x * root_regions / img->w
                      + root_regions * (opticflow->fast9_ret_corners[i].y * root_regions / img->h));
      region_index = (region_index < opticflow->fast9_num_regions) ? region_index : opticflow->fast9_num_regions - 1;
      region_count[region_index][0]++;
    }

    //sorting region_count array according to first column (number of corners).
    qsort(region_count, opticflow->fast9_num_regions, sizeof(region_count[0]), cmp_array);

    uint16_t roi[4];
    // Detecting corners from the region with the less to the one with the most, until a desired total is reached.
    for (uint16_t i = 0; i < opticflow->fast9_num_regions && result->corner_cnt < 2 * opticflow->max_track_corners; i++) {
      // Find the boundaries of the region of interest
      roi[0] = (region_count[i][1] % root_regions) * (img->w / root_regions);
      roi[1] = (region_count[i][1] / root_regions) * (img->h / root_regions);
      roi[2] = roi[0] + (img->w / root_regions);
      roi[3] = roi[1] + (img->h / root_regions);

      struct point_t *new_corners = calloc(opticflow->fast9_rsize, sizeof(struct point_t));
      uint16_t new_count = 0;

      fast9_detect(&opticflow->prev_img_gray, opticflow->fast9_threshold, opticflow->fast9_min_distance,
                   opticflow->fast9_padding, opticflow->fast9_padding, &new_count,
                   &opticflow->fast9_rsize, &new_corners, roi);

      // check that no identified points already exist in list
      for (uint16_t j = 0; j < new_count; j++) {
        bool exists = false;
        for (uint16_t k = 0; k < result->corner_cnt; k++) {
          if (abs((int16_t)new_corners[j].x - (int16_t)opticflow->fast9_ret_corners[k].x) < (int16_t)opticflow->fast9_min_distance
              && abs((int16_t)new_corners[j].y - (int16_t)opticflow->fast9_ret_corners[k].y) < (int16_t)
              opticflow->fast9_min_distance) {
            exists = true;
            break;
          }
        }
        if (!exists) {
          opticflow->fast9_ret_corners[result->corner_cnt].x = new_corners[j].x;
          opticflow->fast9_ret_corners[result->corner_cnt].y = new_corners[j].y;
          opticflow->fast9_ret_corners[result->corner_cnt].count = 0;
          opticflow->fast9_ret_corners[result->corner_cnt].x_sub = 0;
          opticflow->fast9_ret_corners[result->corner_cnt].y_sub = 0;
          result->corner_cnt++;

          if (result->corner_cnt >= opticflow->fast9_rsize) {
            break;
          }
        }
      }

      free(new_corners);
    }
    for (uint16_t i = 0; i < opticflow->fast9_num_regions; i++) {
      free(region_count[i]);
    }
    free(region_count);
  }
}


/**
 * Run the optical flow on a new image frame
 * @param[in] *opticflow The opticalflow structure that keeps track of previous images
 * @param[in] *state The state of the drone
 * @param[in] *img The image frame to calculate the optical flow from
 * @param[out] *result The optical flow result
 */
bool opticflow_calc_frame(struct opticflow_t *opticflow, struct image_t *img,
                          struct opticflow_result_t *result)
{
  bool flow_successful = false;
  // A switch counter that checks in the loop if the current method is similar,
  // to the previous (for reinitializing structs)
  static int8_t switch_counter[2] = {-1, -1};
  if (switch_counter[opticflow->id] != opticflow->method) {
    opticflow->just_switched_method = true;
    switch_counter[opticflow->id] = opticflow->method;
    // Clear the static result
    memset(result, 0, sizeof(struct opticflow_result_t));
  } else {
    opticflow->just_switched_method = false;
  }

  // Switch between methods (0 = fast9/lukas-kanade, 1 = EdgeFlow)
  if (opticflow->method == 0) {
    flow_successful = calc_fast9_lukas_kanade(opticflow, img, result);
  }

  return flow_successful;
}

// ********************************************************************************************
//                                       Utility Functions
// ********************************************************************************************

/**
 * Calculate the difference from start till finish
 * @param[in] *starttime The start time to calculate the difference from
 * @param[in] *finishtime The finish time to calculate the difference from
 * @return The difference in milliseconds
 */
static uint32_t timeval_diff(struct timeval *starttime, struct timeval *finishtime)
{
  uint32_t msec;
  msec = (finishtime->tv_sec - starttime->tv_sec) * 1000;
  msec += (finishtime->tv_usec - starttime->tv_usec) / 1000;
  return msec;
}

/**
 * Compare two flow vectors based on flow distance
 * Used for sorting.
 * @param[in] *a The first flow vector (should be vect flow_t)
 * @param[in] *b The second flow vector (should be vect flow_t)
 * @return Negative if b has more flow than a, 0 if the same and positive if a has more flow than b
 */
static int cmp_flow(const void *a, const void *b)
{
  const struct flow_t *a_p = (const struct flow_t *)a;
  const struct flow_t *b_p = (const struct flow_t *)b;
  return (a_p->flow_x * a_p->flow_x + a_p->flow_y * a_p->flow_y) - (b_p->flow_x * b_p->flow_x + b_p->flow_y *
         b_p->flow_y);
}

/**
 * Compare the rows of an integer (uint16_t) 2D array based on the first column.
 * Used for sorting.
 * @param[in] *a The first row (should be *uint16_t)
 * @param[in] *b The second flow vector (should be *uint16_t)
 * @return Negative if a[0] < b[0],0 if a[0] == b[0] and positive if a[0] > b[0]
 */
static int cmp_array(const void *a, const void *b)
{
  const uint16_t *pa = (const uint16_t *)a;
  const uint16_t *pb = (const uint16_t *)b;
  return pa[0] - pb[0];
}
