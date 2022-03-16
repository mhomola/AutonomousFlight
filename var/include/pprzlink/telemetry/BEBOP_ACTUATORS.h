/** @file
 *  @brief PPRZLink message header for BEBOP_ACTUATORS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_BEBOP_ACTUATORS_H_
#define _VAR_MESSAGES_telemetry_BEBOP_ACTUATORS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BEBOP_ACTUATORS 218
#define PPRZ_MSG_ID_BEBOP_ACTUATORS 218

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BEBOP_ACTUATORS _send_msg(BEBOP_ACTUATORS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BEBOP_ACTUATORS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cmd_thrust 
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _rpm_ref_lf 
 * @param _rpm_ref_rf 
 * @param _rpm_ref_rb 
 * @param _rpm_ref_lb 
 * @param _rpm_obs_lf 
 * @param _rpm_obs_rf 
 * @param _rpm_obs_rb 
 * @param _rpm_obs_lb 
 */
static inline void pprzlink_msg_v2_send_BEBOP_ACTUATORS(struct pprzlink_msg * msg, int32_t *_cmd_thrust, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, uint16_t *_rpm_ref_lf, uint16_t *_rpm_ref_rf, uint16_t *_rpm_ref_rb, uint16_t *_rpm_ref_lb, uint16_t *_rpm_obs_lf, uint16_t *_rpm_obs_rf, uint16_t *_rpm_obs_rb, uint16_t *_rpm_obs_lb) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+2+2+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+2+2+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BEBOP_ACTUATORS, "BEBOP_ACTUATORS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_roll, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_pitch, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_yaw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_ref_lf, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_ref_rf, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_ref_rb, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_ref_lb, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_obs_lf, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_obs_rf, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_obs_rb, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_obs_lb, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BEBOP_ACTUATORS pprz_msg_send_BEBOP_ACTUATORS
#define DOWNLINK_SEND_BEBOP_ACTUATORS(_trans, _dev, cmd_thrust, cmd_roll, cmd_pitch, cmd_yaw, rpm_ref_lf, rpm_ref_rf, rpm_ref_rb, rpm_ref_lb, rpm_obs_lf, rpm_obs_rf, rpm_obs_rb, rpm_obs_lb) pprz_msg_send_BEBOP_ACTUATORS(&((_trans).trans_tx), &((_dev).device), AC_ID, cmd_thrust, cmd_roll, cmd_pitch, cmd_yaw, rpm_ref_lf, rpm_ref_rf, rpm_ref_rb, rpm_ref_lb, rpm_obs_lf, rpm_obs_rf, rpm_obs_rb, rpm_obs_lb)
/**
 * Sends a BEBOP_ACTUATORS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cmd_thrust 
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _rpm_ref_lf 
 * @param _rpm_ref_rf 
 * @param _rpm_ref_rb 
 * @param _rpm_ref_lb 
 * @param _rpm_obs_lf 
 * @param _rpm_obs_rf 
 * @param _rpm_obs_rb 
 * @param _rpm_obs_lb 
 */
static inline void pprz_msg_send_BEBOP_ACTUATORS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_cmd_thrust, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, uint16_t *_rpm_ref_lf, uint16_t *_rpm_ref_rf, uint16_t *_rpm_ref_rb, uint16_t *_rpm_ref_lb, uint16_t *_rpm_obs_lf, uint16_t *_rpm_obs_rf, uint16_t *_rpm_obs_rb, uint16_t *_rpm_obs_lb) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BEBOP_ACTUATORS(&msg,_cmd_thrust,_cmd_roll,_cmd_pitch,_cmd_yaw,_rpm_ref_lf,_rpm_ref_rf,_rpm_ref_rb,_rpm_ref_lb,_rpm_obs_lf,_rpm_obs_rf,_rpm_obs_rb,_rpm_obs_lb);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BEBOP_ACTUATORS(_trans, _dev, cmd_thrust, cmd_roll, cmd_pitch, cmd_yaw, rpm_ref_lf, rpm_ref_rf, rpm_ref_rb, rpm_ref_lb, rpm_obs_lf, rpm_obs_rf, rpm_obs_rb, rpm_obs_lb) {}
static inline void pprz_send_msg_BEBOP_ACTUATORS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_cmd_thrust __attribute__((unused)), int32_t *_cmd_roll __attribute__((unused)), int32_t *_cmd_pitch __attribute__((unused)), int32_t *_cmd_yaw __attribute__((unused)), uint16_t *_rpm_ref_lf __attribute__((unused)), uint16_t *_rpm_ref_rf __attribute__((unused)), uint16_t *_rpm_ref_rb __attribute__((unused)), uint16_t *_rpm_ref_lb __attribute__((unused)), uint16_t *_rpm_obs_lf __attribute__((unused)), uint16_t *_rpm_obs_rf __attribute__((unused)), uint16_t *_rpm_obs_rb __attribute__((unused)), uint16_t *_rpm_obs_lb __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cmd_thrust in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BEBOP_ACTUATORS_cmd_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field cmd_roll in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BEBOP_ACTUATORS_cmd_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field cmd_pitch in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BEBOP_ACTUATORS_cmd_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field cmd_yaw in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BEBOP_ACTUATORS_cmd_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field rpm_ref_lf in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_lf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 20);
}


/** Getter for field rpm_ref_rf in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_rf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field rpm_ref_rb in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_rb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 24);
}


/** Getter for field rpm_ref_lb in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_lb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 26);
}


/** Getter for field rpm_obs_lf in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_lf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 28);
}


/** Getter for field rpm_obs_rf in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_rf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 30);
}


/** Getter for field rpm_obs_rb in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_rb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 32);
}


/** Getter for field rpm_obs_lb in message BEBOP_ACTUATORS
  *
  * @param _payload : a pointer to the BEBOP_ACTUATORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_lb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 34);
}


/* Compatibility macros */
#define DL_BEBOP_ACTUATORS_cmd_thrust(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_cmd_thrust(_payload)
#define DL_BEBOP_ACTUATORS_cmd_roll(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_cmd_roll(_payload)
#define DL_BEBOP_ACTUATORS_cmd_pitch(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_cmd_pitch(_payload)
#define DL_BEBOP_ACTUATORS_cmd_yaw(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_cmd_yaw(_payload)
#define DL_BEBOP_ACTUATORS_rpm_ref_lf(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_lf(_payload)
#define DL_BEBOP_ACTUATORS_rpm_ref_rf(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_rf(_payload)
#define DL_BEBOP_ACTUATORS_rpm_ref_rb(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_rb(_payload)
#define DL_BEBOP_ACTUATORS_rpm_ref_lb(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_ref_lb(_payload)
#define DL_BEBOP_ACTUATORS_rpm_obs_lf(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_lf(_payload)
#define DL_BEBOP_ACTUATORS_rpm_obs_rf(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_rf(_payload)
#define DL_BEBOP_ACTUATORS_rpm_obs_rb(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_rb(_payload)
#define DL_BEBOP_ACTUATORS_rpm_obs_lb(_payload) pprzlink_get_DL_BEBOP_ACTUATORS_rpm_obs_lb(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_BEBOP_ACTUATORS_H_

