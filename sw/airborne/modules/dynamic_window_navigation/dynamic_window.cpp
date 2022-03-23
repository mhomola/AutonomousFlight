/*
 * Copyright (C) Roland Meertens
 *
 * This file is part of paparazzi
 *
 */
/**
 * @file "modules/dynamic_window_navigation/dynamic_window.c"
 * @author Nathaniel Peter Stebbins Dahl
 * Example on how to use the colours detected to avoid orange pole in the cyberzoo
 * This module is an example module for the course AE4317 Autonomous Flight of Micro Air Vehicles at the TU Delft.
 * This module is used in combination with a color filter (cv_detect_color_object) and the navigation mode of the autopilot.
 * The avoidance strategy is to simply count the total number of orange pixels. When above a certain percentage threshold,
 * (given by color_count_frac) we assume that there is an obstacle and we turn.
 *
 * The color filter settings are set using the cv_detect_color_object. This module can run multiple filters simultaneously
 * so you have to define which filter to use with the ORANGE_AVOIDER_VISUAL_DETECTION_ID setting.
 */


//#include "firmwares/rotorcraft/navigation.h"
#include "firmwares/rotorcraft/guidance/guidance_h.h"
#include "generated/airframe.h"
#include "state.h"
#include "modules/core/abi.h"
#include <time.h>
#include <stdio.h>

#include "modules/dynamic_window_navigation/DWN.h"
#include "modules/dynamic_window_navigation/dynamic_window.h"

#define NAV_C // needed to get the nav functions like Inside...
#include "generated/flight_plan.h"



#define ORANGE_AVOIDER_VERBOSE TRUE

#define PRINT(string,...) fprintf(stderr, "[orange_avoider->%s()] " string,__FUNCTION__ , ##__VA_ARGS__)
#if ORANGE_AVOIDER_VERBOSE
#define VERBOSE_PRINT PRINT
#else
#define VERBOSE_PRINT(...)
#endif


enum navigation_state_t {
  NAVIGATING,
};

// define settings

// define and initialise global variables
enum navigation_state_t navigation_state = NAVIGATING;


/*
 * This next section defines an ABI messaging event (http://wiki.paparazziuav.org/wiki/ABI), necessary
 * any time data calculated in another module needs to be accessed. Including the file where this external
 * data is defined is not enough, since modules are executed parallel to each other, at different frequencies,
 * in different threads. The ABI event is triggered every time new data is sent out, and as such the function
 * defined in this file does not need to be explicitly called, only bound in the init function
 */
//We will need this most likely to get data from the vision module
/*
#ifndef ORANGE_AVOIDER_VISUAL_DETECTION_ID
#define ORANGE_AVOIDER_VISUAL_DETECTION_ID ABI_BROADCAST
#endif
static abi_event color_detection_ev;
static void color_detection_cb(uint8_t __attribute__((unused)) sender_id,
                               int16_t __attribute__((unused)) pixel_x, int16_t __attribute__((unused)) pixel_y,
                               int16_t __attribute__((unused)) pixel_width, int16_t __attribute__((unused)) pixel_height,
                               int32_t quality, int16_t __attribute__((unused)) extra)
{
  color_count = quality;
}*/

/*
 * Initialisation function
 */
void dynamic_window_init(void)
{
  // Initialise random values
  srand(time(NULL));
  DWN_wrapper_init();

}

/*
 * Function that calls the navigation software and then commands a speed and yaw rate
 */
void dynamic_window_periodic(void) {
  // Need to be in guided mode (following orange avoider guided here)
  if (guidance_h.mode != GUIDANCE_H_MODE_GUIDED) {
    //navigation_state = SEARCH_FOR_SAFE_HEADING;
    return;
  }
  //Do the computation and return a 
  //TODO implement goal system
  update_dwn( stateGetPositionEnu_i()->x,  stateGetPositionEnu_i()->y,  stateGetNedToBodyEulers_f()->psi,  3.f,  3.f);

  switch (navigation_state){
    case NAVIGATING:
      guidance_h_set_guided_heading_rate(get_yawrate());
      guidance_h_set_guided_body_vel(get_speed(), 0);

      break;
    default:
      break;
  }
  return;
}
