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

#ifndef NEG2THRESHOLD
#define NEG2THRESHOLD 800
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
  uint16_t  i;
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
          flow_l+= local_flow_sq ; 
        }
        else if(vectors[i].pos.y > img_size/2 * subpixel_factor){
          flow_r+= local_flow_sq ; 
        }
      }
    }
    else
        break;  // vectors are in ascending order of their magnitude
  }


  // compute simple yaw/heading change command
  yaw_command = (flow_l - flow_r)/(flow_l + flow_r);

  if (flow_l + flow_r > NEG2THRESHOLD) {
    return flow_l+flow_r;
  } else if (isnan(yaw_command) || (fabs(yaw_command) < YAW_THRESHOLD ) || flow_l < 5.0 || flow_r < 5.0) {
    return 0.0;
  } 

  // fprintf(stderr, " >>>>>>>> Vision --Yaw command: %f by l:%f r%f   \n\n\n", yaw_command,flow_l, flow_r);
  return yaw_command;

}

