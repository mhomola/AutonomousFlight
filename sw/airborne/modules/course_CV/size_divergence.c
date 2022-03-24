/*
 * Copyright (C) 2015 Guido de Croon <guido.de.croon@gmail.com>
 *
 * From:
 * Characterization of Flow Field Divergence for Vertical Landing Control of MAVs
 * by H.W. Ho and G.C.H.E. de Croon (submitted)
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
 * @file modules/computer_vision/opticflow/size_divergence.c
 * @brief Calculate divergence from flow vectors by looking at line sizes between the points.
 *
 * Uses optical flow vectors as determined with a corner tracker and Lucas Kanade to estimate divergence.
 */

#include "size_divergence.h"
#include <stdlib.h>
#include <stdio.h>



// TODO: Check this threshold of outputting a yaw command
#ifndef THRESHOLD
#define YAW_THRESHOLD 0.05f
#endif

//Ignore noise threshold
#ifndef FLOW_THRESHOLD
#define FLOW_THRESHOLD 5.f
#endif

#ifndef LARGE_FLOW_ERROR
#define LARGE_FLOW_ERROR 1E3
#endif


// 


/**
 * Get the heading command from the difference in optical flow between left and right hemispheres.
 * @param[in] vectors      The optical flow vectors
 * @param[in] count      The number of optical flow vectors 
 * @param[in] img_wdith    Size fo the current frame. 
 * @param[in] subpixel_factor    Pixel to sub-pixel conversion factor
 * @return Yaw rate command.
 */
float get_heading_command(struct flow_t *vectors, int count, int img_size, int subpixel_factor)
{
  uint16_t count_l = 0, count_r = 0, i;
  float flow_l =0.f, flow_r =0.f, yaw_command=0.f, local_flow_sq =0.f;
  float local_threshold = FLOW_THRESHOLD * (float)subpixel_factor;
  
  for(i = 0; i < count; i++)
  { 
    // Calculate the squarred flow:
    local_flow_sq = (float)vectors[i].flow_x * (float)vectors[i].flow_x +\
     (float)vectors[i].flow_y * (float)vectors[i].flow_y;

    //first check that local_flow_sq is not huge
    if (local_flow_sq < local_threshold) {
        if (vectors[i].error < LARGE_FLOW_ERROR)
        // printf("(%d, %d): flow error: %d \n", vectors[i].pos.x, vectors[i].pos.y, vectors[i].error);
      {      
        if (vectors[i].pos.y < img_size/2 * subpixel_factor){
          count_l++; flow_l+= local_flow_sq ; 
        }
        else if(vectors[i].pos.y > img_size/2 * subpixel_factor){
          count_r++; flow_r+= local_flow_sq ; 
        }
      }
    }
    else
        break;  // vectors are in ascending order of their magnitude
  }
  count_l = (float)(count_l);
  count_r = (float)(count_r);

  // compute simple yaw/heading change command
  yaw_command = (flow_l - flow_r)/(flow_l + flow_r);

  if (isnan(yaw_command) || (fabs(yaw_command) < YAW_THRESHOLD ) || flow_l < 5.0 || flow_r < 5.0)
    return 0.0;

  // printf(">>>>>>>>> l:%f r%f   Yaw command: %f \n\n\n",flow_l, flow_r, yaw_command);
  fprintf(stderr, " >>>>>>>> Vision --Yaw command: %f by l:%f r%f   \n\n\n", yaw_command,flow_l, flow_r);
  return yaw_command;

}


/**
//  * Get divergence from optical flow vectors based on line sizes between corners
//  * @param[in] vectors    The optical flow vectors
//  * @param[in] count      The number of optical flow vectors
//  * @param[in] n_samples  The number of line segments that will be taken into account. 0 means all line segments will be considered.
//  * @return divergence
//  */
// float get_size_divergence(struct flow_t *vectors, int count, int n_samples)
// {
//   float distance_1, distance_2;
//   float divs_sum = 0.f;
//   uint32_t used_samples = 0;
//   float dx, dy;
//   int32_t i, j;

//   int32_t max_samples = (count * count - count) / 2;

//   if (count < 2) {
//     return 0.f;
//   } else if (count >= max_samples) {
//     n_samples = 0;
//   }

//   if (n_samples == 0) {
//     // go through all possible lines:
//     for (i = 0; i < count; i++) {
//       for (j = i + 1; j < count; j++) {
//         // distance in previous image:
//         dx = (float)vectors[i].pos.x - (float)vectors[j].pos.x;
//         dy = (float)vectors[i].pos.y - (float)vectors[j].pos.y;
//         distance_1 = sqrtf(dx * dx + dy * dy);

//         if (distance_1 < 1E-5) {
//           continue;
//         }

//         // distance in current image:
//         dx = (float)vectors[i].pos.x + (float)vectors[i].flow_x - (float)vectors[j].pos.x - (float)vectors[j].flow_x;
//         dy = (float)vectors[i].pos.y + (float)vectors[i].flow_y - (float)vectors[j].pos.y - (float)vectors[j].flow_y;
//         distance_2 = sqrtf(dx * dx + dy * dy);

//         divs_sum += (distance_2 - distance_1) / distance_1;
//         used_samples++;
//       }
//     }
//   } else {
//     // take random samples:
//     for (uint16_t sample = 0; sample < n_samples; sample++) {
//       // take two random indices:
//       i = rand() % count;
//       j = rand() % count;
//       // ensure it is not the same index:
//       while (i == j) {
//         j = rand() % count;
//       }

//       // distance in previous image:
//       dx = (float)vectors[i].pos.x - (float)vectors[j].pos.x;
//       dy = (float)vectors[i].pos.y - (float)vectors[j].pos.y;
//       distance_1 = sqrtf(dx * dx + dy * dy);

//       if (distance_1 < 1E-5) {
//         continue;
//       }

//       // distance in current image:
//       dx = (float)vectors[i].pos.x + (float)vectors[i].flow_x - (float)vectors[j].pos.x - (float)vectors[j].flow_x;
//       dy = (float)vectors[i].pos.y + (float)vectors[i].flow_y - (float)vectors[j].pos.y - (float)vectors[j].flow_y;
//       distance_2 = sqrtf(dx * dx + dy * dy);

//       divs_sum += (distance_2 - distance_1) / distance_1;
//       used_samples++;
//     }
//   }

//   if (used_samples < 1){
//     return 0.f;
//   }
//   float out = divs_sum / used_samples;

//   return out;
// }