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
#define DL_MSG_datalink_NB 58
#endif // DOWNLINK

#define DL_datalink_CLASS_ID 2

#include "datalink/ACINFO.h"
#include "datalink/MOVE_WP.h"
#include "datalink/WIND_INFO.h"
#include "datalink/SETTING.h"
#include "datalink/BLOCK.h"
#include "datalink/HITL_UBX.h"
#include "datalink/HITL_INFRARED.h"
#include "datalink/PING.h"
#include "datalink/FORMATION_SLOT.h"
#include "datalink/FORMATION_STATUS.h"
#include "datalink/JOYSTICK_RAW.h"
#include "datalink/COMMANDS_RAW.h"
#include "datalink/DGPS_RAW.h"
#include "datalink/ACINFO_LLA.h"
#include "datalink/DESIRED_SETPOINT.h"
#include "datalink/GET_SETTING.h"
#include "datalink/TCAS_RESOLVE.h"
#include "datalink/MISSION_GOTO_WP.h"
#include "datalink/MISSION_GOTO_WP_LLA.h"
#include "datalink/MISSION_CIRCLE.h"
#include "datalink/MISSION_CIRCLE_LLA.h"
#include "datalink/MISSION_SEGMENT.h"
#include "datalink/MISSION_SEGMENT_LLA.h"
#include "datalink/MISSION_PATH.h"
#include "datalink/MISSION_PATH_LLA.h"
#include "datalink/MISSION_CUSTOM.h"
#include "datalink/MISSION_UPDATE.h"
#include "datalink/GOTO_MISSION.h"
#include "datalink/NEXT_MISSION.h"
#include "datalink/END_MISSION.h"
#include "datalink/COPILOT_STATUS_DL.h"
#include "datalink/CAMERA_PAYLOAD_DL.h"
#include "datalink/CAMERA_SNAPSHOT_DL.h"
#include "datalink/GUIDED_SETPOINT_NED.h"
#include "datalink/WINDTURBINE_STATUS.h"
#include "datalink/RC_3CH.h"
#include "datalink/RC_4CH.h"
#include "datalink/RC_5CH.h"
#include "datalink/REMOTE_GPS_SMALL.h"
#include "datalink/REMOTE_GPS.h"
#include "datalink/REMOTE_GPS_LOCAL.h"
#include "datalink/TARGET_POS.h"
#include "datalink/SMARTPROBE.h"
#include "datalink/KITE_COMMAND.h"
#include "datalink/PAYLOAD_COMMAND.h"
#include "datalink/SET_ACTUATOR.h"
#include "datalink/CSC_SERVO_CMD.h"
#include "datalink/BOOZ2_FMS_COMMAND.h"
#include "datalink/BOOZ_NAV_STICK.h"
#include "datalink/EXTERNAL_FILTER_SOLUTION.h"
#include "datalink/ROTORCRAFT_CAM_STICK.h"
#include "datalink/GPS_INJECT.h"
#include "datalink/EXTERNAL_MAG_RAW.h"
#include "datalink/VIDEO_ROI.h"
#include "datalink/EMERGENCY_CMD.h"
#include "datalink/RTCM_INJECT.h"
#include "datalink/DCF_REG_TABLE.h"
#include "datalink/KEY_EXCHANGE_GCS.h"

// Macros for keeping compatibility between versions
// These should not be used directly
#define _inner_send_msg(NAME,PROTO_VERSION) pprzlink_msg_v##PROTO_VERSION##_send_##NAME
#define _send_msg(NAME,PROTO_VERSION) _inner_send_msg(NAME,PROTO_VERSION)

