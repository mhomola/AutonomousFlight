/** @file
 *  @brief PPRZLink message header built from message_definitions/v1.0/messages.xml
 *  @see http://paparazziuav.org
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PPRZLINK_DEFAULT_VER
#define PPRZLINK_DEFAULT_VER 2
#endif

#ifndef PPRZLINK_ENABLE_FD
#define PPRZLINK_ENABLE_FD FALSE
#endif

// dummy fd to save ROM if this is not used
#if !PPRZLINK_ENABLE_FD
#define _FD 0
#define _FD_ADDR 0
#else
#define _FD_ADDR &_FD
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#if DOWNLINK
#define DL_MSG_telemetry_NB 232
#endif // DOWNLINK

#define DL_telemetry_CLASS_ID 1

#include "telemetry/AUTOPILOT_VERSION.h"
#include "telemetry/ALIVE.h"
#include "telemetry/PONG.h"
#include "telemetry/TAKEOFF.h"
#include "telemetry/ARDRONE_NAVDATA.h"
#include "telemetry/ATTITUDE.h"
#include "telemetry/IR_SENSORS.h"
#include "telemetry/GPS.h"
#include "telemetry/NAVIGATION_REF.h"
#include "telemetry/NAVIGATION.h"
#include "telemetry/PPRZ_MODE.h"
#include "telemetry/ENERGY.h"
#include "telemetry/DEBUG_MCU_LINK.h"
#include "telemetry/CALIBRATION.h"
#include "telemetry/SETTINGS.h"
#include "telemetry/DESIRED.h"
#include "telemetry/GPS_SOL.h"
#include "telemetry/ADC_GENERIC.h"
#include "telemetry/ECU.h"
#include "telemetry/CAM.h"
#include "telemetry/CIRCLE.h"
#include "telemetry/SEGMENT.h"
#include "telemetry/VECTORNAV_INFO.h"
#include "telemetry/HYBRID_GUIDANCE.h"
#include "telemetry/SVINFO.h"
#include "telemetry/DEBUG.h"
#include "telemetry/SURVEY.h"
#include "telemetry/RSSI.h"
#include "telemetry/RANGEFINDER.h"
#include "telemetry/DATALINK_REPORT.h"
#include "telemetry/DL_VALUE.h"
#include "telemetry/MARK.h"
#include "telemetry/SYS_MON.h"
#include "telemetry/MOTOR.h"
#include "telemetry/WP_MOVED.h"
#include "telemetry/MKK.h"
#include "telemetry/GUIDANCE_INDI_HYBRID.h"
#include "telemetry/DRAGSPEED.h"
#include "telemetry/RSSI_COMBINED.h"
#include "telemetry/DCF.h"
#include "telemetry/ALT_KALMAN.h"
#include "telemetry/ESTIMATOR.h"
#include "telemetry/TUNE_ROLL.h"
#include "telemetry/BARO_MS5534A.h"
#include "telemetry/CHIRP.h"
#include "telemetry/BARO_WORDS.h"
#include "telemetry/WP_MOVED_LLA.h"
#include "telemetry/RLFILTER.h"
#include "telemetry/WP_MOVED_ENU.h"
#include "telemetry/WINDTURBINE_STATUS_.h"
#include "telemetry/RC_3CH_.h"
#include "telemetry/MPPT.h"
#include "telemetry/DEBUG_IR_I2C.h"
#include "telemetry/AIRSPEED.h"
#include "telemetry/METEO_STICK.h"
#include "telemetry/BARO_ETS.h"
#include "telemetry/AIRSPEED_ETS.h"
#include "telemetry/VISION_OUTBACK.h"
#include "telemetry/GPS_LLA.h"
#include "telemetry/H_CTL_A.h"
#include "telemetry/CLOUD_SENSOR.h"
#include "telemetry/TURB_PRESSURE_VOLTAGE.h"
#include "telemetry/CAM_POINT.h"
#include "telemetry/DC_INFO.h"
#include "telemetry/AMSYS_BARO.h"
#include "telemetry/AMSYS_AIRSPEED.h"
#include "telemetry/FLIGHT_BENCHMARK.h"
#include "telemetry/MPL3115_BARO.h"
#include "telemetry/AOA.h"
#include "telemetry/XTEND_RSSI.h"
#include "telemetry/GVF.h"
#include "telemetry/SUPERBITRF.h"
#include "telemetry/GX3_INFO.h"
#include "telemetry/UBLOX_INFO.h"
#include "telemetry/GVF_PARAMETRIC.h"
#include "telemetry/SWARM_FISH.h"
#include "telemetry/INV_FILTER.h"
#include "telemetry/MISSION_STATUS.h"
#include "telemetry/JEVOIS.h"
#include "telemetry/GENERIC_COM.h"
#include "telemetry/FORMATION_SLOT_TM.h"
#include "telemetry/FORMATION_STATUS_TM.h"
#include "telemetry/BMP_STATUS.h"
#include "telemetry/MLX_STATUS.h"
#include "telemetry/TMP_STATUS.h"
#include "telemetry/WIND_INFO_RET.h"
#include "telemetry/SCP_STATUS.h"
#include "telemetry/SHT_STATUS.h"
#include "telemetry/VISION_POSITION_ESTIMATE.h"
#include "telemetry/DPICCO_STATUS.h"
#include "telemetry/LOGGER_STATUS.h"
#include "telemetry/MINIMAL_COM.h"
#include "telemetry/MOTOR_BENCH_STATUS.h"
#include "telemetry/HIH_STATUS.h"
#include "telemetry/TEMT_STATUS.h"
#include "telemetry/GP2Y_STATUS.h"
#include "telemetry/SHT_I2C_SERIAL.h"
#include "telemetry/PPM.h"
#include "telemetry/RC.h"
#include "telemetry/COMMANDS.h"
#include "telemetry/FBW_STATUS.h"
#include "telemetry/ADC.h"
#include "telemetry/ACTUATORS.h"
#include "telemetry/BLUEGIGA.h"
#include "telemetry/THROTTLE_CURVE.h"
#include "telemetry/PIKSI_HEARTBEAT.h"
#include "telemetry/MULTIGAZE_METERS.h"
#include "telemetry/DC_SHOT.h"
#include "telemetry/CAMERA_PAYLOAD.h"
#include "telemetry/MOTOR_MIXING.h"
#include "telemetry/MLX_SERIAL.h"
#include "telemetry/PAYLOAD.h"
#include "telemetry/HTM_STATUS.h"
#include "telemetry/BARO_MS5611.h"
#include "telemetry/MS5611_COEFF.h"
#include "telemetry/ATMOSPHERE_CHARGE.h"
#include "telemetry/SOLAR_RADIATION.h"
#include "telemetry/TCAS_TA.h"
#include "telemetry/TCAS_RA.h"
#include "telemetry/TCAS_RESOLVED.h"
#include "telemetry/TCAS_DEBUG.h"
#include "telemetry/POTENTIAL.h"
#include "telemetry/COPILOT_STATUS.h"
#include "telemetry/TEMP_TCOUPLE.h"
#include "telemetry/SHT_I2C_STATUS.h"
#include "telemetry/CAMERA_SNAPSHOT.h"
#include "telemetry/TIMESTAMP.h"
#include "telemetry/STAB_ATTITUDE_FLOAT.h"
#include "telemetry/IMU_GYRO_SCALED.h"
#include "telemetry/IMU_ACCEL_SCALED.h"
#include "telemetry/IMU_MAG_SCALED.h"
#include "telemetry/FILTER.h"
#include "telemetry/RATE_LOOP.h"
#include "telemetry/FILTER_ALIGNER.h"
#include "telemetry/AIRSPEED_MS45XX.h"
#include "telemetry/STAB_ATTITUDE_INT.h"
#include "telemetry/STAB_ATTITUDE_REF_INT.h"
#include "telemetry/STAB_ATTITUDE_REF_FLOAT.h"
#include "telemetry/ROTORCRAFT_CMD.h"
#include "telemetry/GUIDANCE_H_INT.h"
#include "telemetry/VERT_LOOP.h"
#include "telemetry/HOVER_LOOP.h"
#include "telemetry/ROTORCRAFT_FP.h"
#include "telemetry/TEMP_ADC.h"
#include "telemetry/GUIDANCE_H_REF_INT.h"
#include "telemetry/ROTORCRAFT_TUNE_HOVER.h"
#include "telemetry/INS_Z.h"
#include "telemetry/PCAP01_STATUS.h"
#include "telemetry/GEIGER_COUNTER.h"
#include "telemetry/INS_REF.h"
#include "telemetry/GPS_INT.h"
#include "telemetry/AHRS_EULER_INT.h"
#include "telemetry/AHRS_QUAT_INT.h"
#include "telemetry/ROTORCRAFT_NAV_STATUS.h"
#include "telemetry/ROTORCRAFT_RADIO_CONTROL.h"
#include "telemetry/VFF_EXTENDED.h"
#include "telemetry/VFF.h"
#include "telemetry/GEO_MAG.h"
#include "telemetry/HFF.h"
#include "telemetry/HFF_DBG.h"
#include "telemetry/HFF_GPS.h"
#include "telemetry/INS_EKF2.h"
#include "telemetry/ROTORCRAFT_CAM.h"
#include "telemetry/AHRS_REF_QUAT.h"
#include "telemetry/INS_EKF2_EXT.h"
#include "telemetry/AHRS_BIAS.h"
#include "telemetry/AHRS_EULER.h"
#include "telemetry/AHRS_MEASUREMENT_EULER.h"
#include "telemetry/WT.h"
#include "telemetry/CSC_CAN_DEBUG.h"
#include "telemetry/CSC_CAN_MSG.h"
#include "telemetry/AHRS_GYRO_BIAS_INT.h"
#include "telemetry/AEROPROBE.h"
#include "telemetry/FMS_TIME.h"
#include "telemetry/AHRS_LKF.h"
#include "telemetry/NPS_SENSORS_SCALED.h"
#include "telemetry/INS.h"
#include "telemetry/IMU_GYRO.h"
#include "telemetry/IMU_MAG.h"
#include "telemetry/IMU_ACCEL.h"
#include "telemetry/IMU_GYRO_RAW.h"
#include "telemetry/IMU_ACCEL_RAW.h"
#include "telemetry/IMU_MAG_RAW.h"
#include "telemetry/IMU_MAG_SETTINGS.h"
#include "telemetry/IMU_MAG_CURRENT_CALIBRATION.h"
#include "telemetry/UART_ERRORS.h"
#include "telemetry/IMU_GYRO_LP.h"
#include "telemetry/IMU_PRESSURE.h"
#include "telemetry/WINDTUNNEL_MEAS.h"
#include "telemetry/TUNE_VERT.h"
#include "telemetry/MF_DAQ_STATE.h"
#include "telemetry/INFO_MSG.h"
#include "telemetry/STAB_ATTITUDE_INDI.h"
#include "telemetry/ROTORCRAFT_FP_MIN.h"
#include "telemetry/BEBOP_ACTUATORS.h"
#include "telemetry/WEATHER.h"
#include "telemetry/IMU_TURNTABLE.h"
#include "telemetry/BARO_RAW.h"
#include "telemetry/AIR_DATA.h"
#include "telemetry/AMSL.h"
#include "telemetry/DIVERGENCE.h"
#include "telemetry/VIDEO_SYNC.h"
#include "telemetry/PERIODIC_TELEMETRY_ERR.h"
#include "telemetry/TIME.h"
#include "telemetry/OPTIC_FLOW_EST.h"
#include "telemetry/STEREO_IMG.h"
#include "telemetry/ROVER_STATUS.h"
#include "telemetry/ROTORCRAFT_STATUS.h"
#include "telemetry/STATE_FILTER_STATUS.h"
#include "telemetry/OPTICAL_FLOW.h"
#include "telemetry/LIDAR.h"
#include "telemetry/VISUALTARGET.h"
#include "telemetry/SONAR.h"
#include "telemetry/PAYLOAD_FLOAT.h"
#include "telemetry/NPS_POS_LLH.h"
#include "telemetry/KEY_EXCHANGE_UAV.h"
#include "telemetry/NPS_SPEED_POS.h"
#include "telemetry/NPS_RATE_ATTITUDE.h"
#include "telemetry/NPS_GYRO_BIAS.h"
#include "telemetry/OPTICAL_FLOW_HOVER.h"
#include "telemetry/NPS_WIND.h"
#include "telemetry/ESC.h"
#include "telemetry/RTOS_MON.h"
#include "telemetry/PPRZ_DEBUG.h"
#include "telemetry/BATTERY_MONITOR.h"
#include "telemetry/GPS_RXMRTCM.h"
#include "telemetry/INDI_G.h"
#include "telemetry/GPS_RTK.h"
#include "telemetry/GPS_SMALL.h"
#include "telemetry/I2C_ERRORS.h"
#include "telemetry/DCF_THETA.h"
#include "telemetry/SECURE_LINK_STATUS.h"

// Macros for keeping compatibility between versions
// These should not be used directly
#define _inner_send_msg(NAME,PROTO_VERSION) pprzlink_msg_v##PROTO_VERSION##_send_##NAME
#define _send_msg(NAME,PROTO_VERSION) _inner_send_msg(NAME,PROTO_VERSION)

