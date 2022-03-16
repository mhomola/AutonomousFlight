/* This file has been generated from  */
/* Version v6.1.0_stable-0-g3508db681 */
/* Please DO NOT EDIT */

#ifndef MODULES_H
#define MODULES_H

#define MODULES_IDLE  0
#define MODULES_RUN   1
#define MODULES_START 2
#define MODULES_STOP  3

#ifndef MODULES_FREQUENCY
#ifdef PERIODIC_FREQUENCY
#define MODULES_FREQUENCY PERIODIC_FREQUENCY
#else
#error "neither MODULES_FREQUENCY or PERIODIC_FREQUENCY are defined"
#endif
#endif

#ifdef MODULES_C
#define EXTERN_MODULES
#else
#define EXTERN_MODULES extern
#endif
#include "std.h"
#include "computer_vision/video_thread.h"
#include "firmwares/rotorcraft/stabilization.h"
#include "stabilization/stabilization_none.h"
#include "core/settings.h"
#include "radio_control/rc_datalink.h"
#include "firmwares/rotorcraft/navigation.h"
#include "./mcu.h"
#include "mcu_periph/gpio.h"
#include "math/pprz_algebra_int.h"
#include "math/pprz_algebra_float.h"
#include "math/pprz_algebra_double.h"
#include "math/pprz_geodetic_int.h"
#include "math/pprz_geodetic_float.h"
#include "math/pprz_geodetic_double.h"
#include "math/pprz_trig_int.h"
#include "math/pprz_orientation_conversion.h"
#include "math/pprz_stat.h"
#include "loggers/file_logger.h"
#include "imu/imu.h"
#include "mcu_periph/i2c.h"
#include "gps/gps.h"
#include "datalink/telemetry.h"
#include "datalink/datalink.h"
#include "datalink/downlink.h"
#include "ahrs/ahrs.h"
#include "actuators/actuators.h"
#include "mcu_periph/adc.h"
#include "../boards/bebop/mt9v117.h"
#include "../boards/bebop/mt9f002.h"
#include "computer_vision/cv_detect_color_object.h"
#include "energy/electrical.h"
#include "gps/gps.h"
#include "guidance/guidance_h.h"
#include "guidance/guidance_v.h"
#include "imu/imu_nps.h"
#include "ins/ins_int.h"
#include "orange_avoider/orange_avoider_guided.h"
#include "stabilization/stabilization_indi_simple.h"
#include "stabilization/stabilization_rate_indi.h"
#include "./state.h"
#include "mcu_periph/udp.h"
#include "computer_vision/video_capture.h"
#include "computer_vision/viewvideo.h"
#include "datalink/pprz_dl.h"
#include "actuators/motor_mixing.h"
#include "./autopilot.h"

#define VIDEO_THREAD_PERIODIC_PERIOD (1.000000f)
#define VIDEO_THREAD_PERIODIC_FREQ (1.000000f)
#define FILE_LOGGER_PERIODIC_PERIOD (0.010000f)
#define FILE_LOGGER_PERIODIC_FREQ (100.000000f)
#define COLOR_OBJECT_DETECTOR_PERIODIC_PERIOD (0.020000f)
#define COLOR_OBJECT_DETECTOR_PERIODIC_FREQ (50.000000f)
#define ELECTRICAL_PERIODIC_PERIOD (0.100000f)
#define ELECTRICAL_PERIODIC_FREQ (10.000000f)
#define GPS_NPS_PERIODIC_CHECK_PERIOD (1.000000f)
#define GPS_NPS_PERIODIC_CHECK_FREQ (1.000000f)
#define ORANGE_AVOIDER_GUIDED_PERIODIC_PERIOD (0.250000f)
#define ORANGE_AVOIDER_GUIDED_PERIODIC_FREQ (4.000000f)
#define AUTOPILOT_PERIODIC_PERIOD (1.f / MODULES_FREQUENCY)
#define AUTOPILOT_PERIODIC_FREQ (MODULES_FREQUENCY)

#define PRESCALER_1 (uint32_t)(MODULES_FREQUENCY * (1.000000f))
#define PRESCALER_2 (uint32_t)(MODULES_FREQUENCY * (0.010000f))
#define PRESCALER_3 (uint32_t)(MODULES_FREQUENCY * (0.020000f))
#define PRESCALER_4 (uint32_t)(MODULES_FREQUENCY * (0.100000f))
#define PRESCALER_5 (uint32_t)(MODULES_FREQUENCY * (0.250000f))
#define PRESCALER_6 (uint32_t)(MODULES_FREQUENCY * (1.f / MODULES_FREQUENCY))

EXTERN_MODULES uint8_t video_thread_video_thread_periodic_status;
EXTERN_MODULES uint8_t logger_file_file_logger_periodic_status;
EXTERN_MODULES uint8_t gps_nps_gps_nps_periodic_check_status;


static inline void modules_mcu_init(void) {
  mcu_init();
}

static inline void modules_core_init(void) {
  settings_init();
  pprz_trig_int_init();
  logger_file_file_logger_periodic_status = MODULES_STOP;
  electrical_init();
  stateInit();
}

static inline void modules_sensors_init(void) {
  imu_init();
  gps_init();
  gps_nps_init();
  gps_nps_gps_nps_periodic_check_status = MODULES_START;
  imu_nps_init();
}

static inline void modules_estimation_init(void) {
  ahrs_init();
  ins_int_init();
}

static inline void modules_radio_control_init(void) {
}

static inline void modules_control_init(void) {
  stabilization_init();
  stabilization_none_init();
  nav_init();
  guidance_h_init();
  guidance_v_init();
  stabilization_indi_init();
  stabilization_rate_init();
  autopilot_init();
}

static inline void modules_actuators_init(void) {
  actuators_init();
  motor_mixing_init();
}

static inline void modules_datalink_init(void) {
  downlink_init();
  pprz_dl_init();
}

static inline void modules_default_init(void) {
  video_thread_init();
  video_thread_video_thread_periodic_status = MODULES_START;
  mt9v117_init(PTR(mt9v117));
  mt9f002_init(PTR(mt9f002));
  color_object_detector_init();
  orange_avoider_guided_init();
  video_capture_init();
  viewvideo_init();
}

static inline void modules_init(void) {
  modules_mcu_init();
  modules_core_init();
  modules_sensors_init();
  modules_estimation_init();
  modules_radio_control_init();
  modules_control_init();
  modules_actuators_init();
  modules_datalink_init();
  modules_default_init();
}

static inline void modules_mcu_periodic_task(void) {

}

static inline void modules_core_periodic_task(void) {
  static uint32_t i2; i2++; if (i2>=PRESCALER_2) i2=0;
  static uint32_t i4; i4++; if (i4>=PRESCALER_4) i4=0;

  if (logger_file_file_logger_periodic_status == MODULES_START) {
    file_logger_start();
    logger_file_file_logger_periodic_status = MODULES_RUN;
  }
  if (logger_file_file_logger_periodic_status == MODULES_STOP) {
    file_logger_stop();
    logger_file_file_logger_periodic_status = MODULES_IDLE;
  }

  if (i2 == (uint32_t)(0.200000f * PRESCALER_2) && logger_file_file_logger_periodic_status == MODULES_RUN) {
    file_logger_periodic();
  }
  if (i4 == (uint32_t)(0.400000f * PRESCALER_4)) {
    electrical_periodic();
  }
}

static inline void modules_sensors_periodic_task(void) {
  static uint32_t i1; i1++; if (i1>=PRESCALER_1) i1=0;

  if (gps_nps_gps_nps_periodic_check_status == MODULES_START) {
    gps_nps_gps_nps_periodic_check_status = MODULES_RUN;
  }
  if (gps_nps_gps_nps_periodic_check_status == MODULES_STOP) {
    gps_nps_gps_nps_periodic_check_status = MODULES_IDLE;
  }

  if (i1 == (uint32_t)(0.500000f * PRESCALER_1) && gps_nps_gps_nps_periodic_check_status == MODULES_RUN) {
    gps_nps_periodic_check();
  }
}

static inline void modules_estimation_periodic_task(void) {

}

static inline void modules_radio_control_periodic_task(void) {

}

static inline void modules_control_periodic_task(void) {
  static uint32_t i6; i6++; if (i6>=PRESCALER_6) i6=0;

  autopilot_periodic();
}

static inline void modules_actuators_periodic_task(void) {

}

static inline void modules_datalink_periodic_task(void) {

}

static inline void modules_default_periodic_task(void) {
  static uint32_t i1; i1++; if (i1>=PRESCALER_1) i1=0;
  static uint32_t i3; i3++; if (i3>=PRESCALER_3) i3=0;
  static uint32_t i5; i5++; if (i5>=PRESCALER_5) i5=0;

  if (video_thread_video_thread_periodic_status == MODULES_START) {
    video_thread_start();
    video_thread_video_thread_periodic_status = MODULES_RUN;
  }
  if (video_thread_video_thread_periodic_status == MODULES_STOP) {
    video_thread_stop();
    video_thread_video_thread_periodic_status = MODULES_IDLE;
  }

  if (i3 == (uint32_t)(0.300000f * PRESCALER_3)) {
    color_object_detector_periodic();
  }
  if (i5 == (uint32_t)(0.600000f * PRESCALER_5)) {
    orange_avoider_guided_periodic();
  }
  if (i1 == (uint32_t)(0.100000f * PRESCALER_1) && video_thread_video_thread_periodic_status == MODULES_RUN) {
    video_thread_periodic();
  }
}

static inline void modules_periodic_task(void) {
  modules_mcu_periodic_task();
  modules_core_periodic_task();
  modules_sensors_periodic_task();
  modules_estimation_periodic_task();
  modules_radio_control_periodic_task();
  modules_control_periodic_task();
  modules_actuators_periodic_task();
  modules_datalink_periodic_task();
  modules_default_periodic_task();
}

static inline void modules_mcu_event_task(void) {
  mcu_event();
}

static inline void modules_core_event_task(void) {
}

static inline void modules_sensors_event_task(void) {
  imu_nps_event();
}

static inline void modules_estimation_event_task(void) {
}

static inline void modules_radio_control_event_task(void) {
}

static inline void modules_control_event_task(void) {
  autopilot_event();
}

static inline void modules_actuators_event_task(void) {
}

static inline void modules_datalink_event_task(void) {
  pprz_dl_event();
}

static inline void modules_default_event_task(void) {
}

static inline void modules_event_task(void) {
  modules_mcu_event_task();
  modules_core_event_task();
  modules_sensors_event_task();
  modules_estimation_event_task();
  modules_radio_control_event_task();
  modules_control_event_task();
  modules_actuators_event_task();
  modules_datalink_event_task();
  modules_default_event_task();
}

#ifdef MODULES_DATALINK_C

#include "pprzlink/messages.h"
#include "generated/airframe.h"
static inline void modules_parse_datalink(uint8_t msg_id __attribute__ ((unused)),
                                          struct link_device *dev __attribute__((unused)),
                                          struct transport_tx *trans __attribute__((unused)),
                                          uint8_t *buf __attribute__((unused))) {
}

#endif // MODULES_DATALINK_C

#endif // MODULES_H
