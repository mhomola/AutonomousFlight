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
#define DL_MSG_intermcu_NB 17
#endif // DOWNLINK

#define DL_intermcu_CLASS_ID 5

#include "intermcu/IMCU_COMMANDS.h"
#include "intermcu/IMCU_RADIO_COMMANDS.h"
#include "intermcu/IMCU_SPEKTRUM_SOFT_BIND.h"
#include "intermcu/IMCU_FBW_STATUS.h"
#include "intermcu/IMCU_REMOTE_MAG.h"
#include "intermcu/IMCU_REMOTE_BARO.h"
#include "intermcu/IMCU_REMOTE_AIRSPEED.h"
#include "intermcu/IMCU_REMOTE_GROUND.h"
#include "intermcu/IMCU_REMOTE_GPS.h"
#include "intermcu/STEREOCAM_ARRAY.h"
#include "intermcu/STEREOCAM_VELOCITY.h"
#include "intermcu/STEREOCAM_STATE.h"
#include "intermcu/STEREOCAM_FOLLOW_ME.h"
#include "intermcu/IMCU_DATALINK.h"
#include "intermcu/IMCU_TELEMETRY.h"
#include "intermcu/IMCU_DEBUG.h"
#include "intermcu/IMCU_PAYLOAD.h"

// Macros for keeping compatibility between versions
// These should not be used directly
#define _inner_send_msg(NAME,PROTO_VERSION) pprzlink_msg_v##PROTO_VERSION##_send_##NAME
#define _send_msg(NAME,PROTO_VERSION) _inner_send_msg(NAME,PROTO_VERSION)

