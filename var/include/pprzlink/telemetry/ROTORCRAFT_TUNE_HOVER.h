/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_TUNE_HOVER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_TUNE_HOVER_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_TUNE_HOVER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_TUNE_HOVER 150
#define PPRZ_MSG_ID_ROTORCRAFT_TUNE_HOVER 150

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_TUNE_HOVER _send_msg(ROTORCRAFT_TUNE_HOVER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_TUNE_HOVER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _rc_roll 
 * @param _rc_pitch 
 * @param _rc_yaw 
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _cmd_thrust 
 * @param _body_phi 
 * @param _body_theta 
 * @param _body_psi 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_TUNE_HOVER(struct pprzlink_msg * msg, int16_t *_rc_roll, int16_t *_rc_pitch, int16_t *_rc_yaw, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_TUNE_HOVER, "ROTORCRAFT_TUNE_HOVER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _rc_roll, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _rc_pitch, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _rc_yaw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_roll, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_pitch, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_yaw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_psi, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_TUNE_HOVER pprz_msg_send_ROTORCRAFT_TUNE_HOVER
#define DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(_trans, _dev, rc_roll, rc_pitch, rc_yaw, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust, body_phi, body_theta, body_psi) pprz_msg_send_ROTORCRAFT_TUNE_HOVER(&((_trans).trans_tx), &((_dev).device), AC_ID, rc_roll, rc_pitch, rc_yaw, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust, body_phi, body_theta, body_psi)
/**
 * Sends a ROTORCRAFT_TUNE_HOVER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _rc_roll 
 * @param _rc_pitch 
 * @param _rc_yaw 
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _cmd_thrust 
 * @param _body_phi 
 * @param _body_theta 
 * @param _body_psi 
 */
static inline void pprz_msg_send_ROTORCRAFT_TUNE_HOVER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_rc_roll, int16_t *_rc_pitch, int16_t *_rc_yaw, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_TUNE_HOVER(&msg,_rc_roll,_rc_pitch,_rc_yaw,_cmd_roll,_cmd_pitch,_cmd_yaw,_cmd_thrust,_body_phi,_body_theta,_body_psi);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(_trans, _dev, rc_roll, rc_pitch, rc_yaw, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust, body_phi, body_theta, body_psi) {}
static inline void pprz_send_msg_ROTORCRAFT_TUNE_HOVER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_rc_roll __attribute__((unused)), int16_t *_rc_pitch __attribute__((unused)), int16_t *_rc_yaw __attribute__((unused)), int32_t *_cmd_roll __attribute__((unused)), int32_t *_cmd_pitch __attribute__((unused)), int32_t *_cmd_yaw __attribute__((unused)), int32_t *_cmd_thrust __attribute__((unused)), int32_t *_body_phi __attribute__((unused)), int32_t *_body_theta __attribute__((unused)), int32_t *_body_psi __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field rc_roll in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field rc_pitch in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field rc_yaw in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field cmd_roll in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field cmd_pitch in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field cmd_yaw in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field cmd_thrust in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 22);
}


/** Getter for field body_phi in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 26);
}


/** Getter for field body_theta in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 30);
}


/** Getter for field body_psi in message ROTORCRAFT_TUNE_HOVER
  *
  * @param _payload : a pointer to the ROTORCRAFT_TUNE_HOVER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 34);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_TUNE_HOVER_rc_roll(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_roll(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_rc_pitch(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_pitch(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_rc_yaw(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_rc_yaw(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_roll(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_roll(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_pitch(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_pitch(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_yaw(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_yaw(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_thrust(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_cmd_thrust(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_body_phi(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_phi(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_body_theta(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_theta(_payload)
#define DL_ROTORCRAFT_TUNE_HOVER_body_psi(_payload) pprzlink_get_DL_ROTORCRAFT_TUNE_HOVER_body_psi(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_TUNE_HOVER_H_

