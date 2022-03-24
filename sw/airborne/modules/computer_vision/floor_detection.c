/*
 * Copyright (C) C. De Wagter
 *
 * This file is part of paparazzi
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
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/computer_vision/cv_opencvdemo.c"
 * @author C. De Wagter
 * A simple module showing what you can do with opencv on the bebop.
 */

#include "modules/computer_vision/cv.h"
#include "modules/computer_vision/floor_detection.h"
#include "modules/computer_vision/floor_detection_funcs.h"


#ifndef FLOOR_DETECTION_FPS
#define FLOOR_DETECTION_FPS 0       ///< Default FPS (zero means run at camera fps)
#endif
PRINT_CONFIG_VAR(FLOOR_DETECTION_FPS)

float output[30] = {-1};

// Function
struct image_t *floor_detection_func(struct image_t *img, uint8_t camera_id);
struct image_t *floor_detection_func(struct image_t *img, uint8_t camera_id)
{

  if (img->type == IMAGE_YUV422) {
    // Call OpenCV (C++ from paparazzi C function)
    objectDetection((char *) img->buf, img->w, img->h, output);
  }

  return NULL;
}

void floor_detection_init(void)
{
  cv_add_to_device(&FLOOR_DETECTION_CAMERA, floor_detection_func, FLOOR_DETECTION_FPS, 0);
}

void floor_detection_periodic(void)

{ 
  // uint8_t id = 1;
  // AbiSendMsgFLOOR_DETECTION(id, output);

}

