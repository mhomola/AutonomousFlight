/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_CMD in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_CMD_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_CMD_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_CMD 143
#define PPRZ_MSG_ID_ROTORCRAFT_CMD 143

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_CMD _send_msg(ROTORCRAFT_CMD,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_CMD message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _cmd_thrust 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_CMD(struct pprzlink_msg * msg, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_CMD, "ROTORCRAFT_CMD");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_roll, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_pitch, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_yaw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_thrust, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_CMD pprz_msg_send_ROTORCRAFT_CMD
#define DOWNLINK_SEND_ROTORCRAFT_CMD(_trans, _dev, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust) pprz_msg_send_ROTORCRAFT_CMD(&((_trans).trans_tx), &((_dev).device), AC_ID, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust)
/**
 * Sends a ROTORCRAFT_CMD message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cmd_roll 
 * @param _cmd_pitch 
 * @param _cmd_yaw 
 * @param _cmd_thrust 
 */
static inline void pprz_msg_send_ROTORCRAFT_CMD(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_CMD(&msg,_cmd_roll,_cmd_pitch,_cmd_yaw,_cmd_thrust);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_CMD(_trans, _dev, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust) {}
static inline void pprz_send_msg_ROTORCRAFT_CMD(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_cmd_roll __attribute__((unused)), int32_t *_cmd_pitch __attribute__((unused)), int32_t *_cmd_yaw __attribute__((unused)), int32_t *_cmd_thrust __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cmd_roll in message ROTORCRAFT_CMD
  *
  * @param _payload : a pointer to the ROTORCRAFT_CMD message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_CMD_cmd_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field cmd_pitch in message ROTORCRAFT_CMD
  *
  * @param _payload : a pointer to the ROTORCRAFT_CMD message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_CMD_cmd_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field cmd_yaw in message ROTORCRAFT_CMD
  *
  * @param _payload : a pointer to the ROTORCRAFT_CMD message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_CMD_cmd_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field cmd_thrust in message ROTORCRAFT_CMD
  *
  * @param _payload : a pointer to the ROTORCRAFT_CMD message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_CMD_cmd_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_CMD_cmd_roll(_payload) pprzlink_get_DL_ROTORCRAFT_CMD_cmd_roll(_payload)
#define DL_ROTORCRAFT_CMD_cmd_pitch(_payload) pprzlink_get_DL_ROTORCRAFT_CMD_cmd_pitch(_payload)
#define DL_ROTORCRAFT_CMD_cmd_yaw(_payload) pprzlink_get_DL_ROTORCRAFT_CMD_cmd_yaw(_payload)
#define DL_ROTORCRAFT_CMD_cmd_thrust(_payload) pprzlink_get_DL_ROTORCRAFT_CMD_cmd_thrust(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_CMD_H_

