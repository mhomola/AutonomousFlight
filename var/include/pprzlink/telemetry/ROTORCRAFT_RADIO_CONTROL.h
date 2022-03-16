/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_RADIO_CONTROL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_RADIO_CONTROL_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_RADIO_CONTROL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_RADIO_CONTROL 160
#define PPRZ_MSG_ID_ROTORCRAFT_RADIO_CONTROL 160

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_RADIO_CONTROL _send_msg(ROTORCRAFT_RADIO_CONTROL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_RADIO_CONTROL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _roll 
 * @param _pitch 
 * @param _yaw 
 * @param _throttle 
 * @param _mode 
 * @param _kill 
 * @param _status 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_RADIO_CONTROL(struct pprzlink_msg * msg, int16_t *_roll, int16_t *_pitch, int16_t *_yaw, int16_t *_throttle, int16_t *_mode, int16_t *_kill, uint8_t *_status) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_RADIO_CONTROL, "ROTORCRAFT_RADIO_CONTROL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _roll, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _pitch, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _yaw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _throttle, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mode, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _kill, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_RADIO_CONTROL pprz_msg_send_ROTORCRAFT_RADIO_CONTROL
#define DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(_trans, _dev, roll, pitch, yaw, throttle, mode, kill, status) pprz_msg_send_ROTORCRAFT_RADIO_CONTROL(&((_trans).trans_tx), &((_dev).device), AC_ID, roll, pitch, yaw, throttle, mode, kill, status)
/**
 * Sends a ROTORCRAFT_RADIO_CONTROL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _roll 
 * @param _pitch 
 * @param _yaw 
 * @param _throttle 
 * @param _mode 
 * @param _kill 
 * @param _status 
 */
static inline void pprz_msg_send_ROTORCRAFT_RADIO_CONTROL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_roll, int16_t *_pitch, int16_t *_yaw, int16_t *_throttle, int16_t *_mode, int16_t *_kill, uint8_t *_status) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_RADIO_CONTROL(&msg,_roll,_pitch,_yaw,_throttle,_mode,_kill,_status);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(_trans, _dev, roll, pitch, yaw, throttle, mode, kill, status) {}
static inline void pprz_send_msg_ROTORCRAFT_RADIO_CONTROL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_roll __attribute__((unused)), int16_t *_pitch __attribute__((unused)), int16_t *_yaw __attribute__((unused)), int16_t *_throttle __attribute__((unused)), int16_t *_mode __attribute__((unused)), int16_t *_kill __attribute__((unused)), uint8_t *_status __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field roll in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field pitch in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field yaw in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field throttle in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/** Getter for field mode in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/** Getter for field kill in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_kill(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 14);
}


/** Getter for field status in message ROTORCRAFT_RADIO_CONTROL
  *
  * @param _payload : a pointer to the ROTORCRAFT_RADIO_CONTROL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_RADIO_CONTROL_roll(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_roll(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_pitch(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_pitch(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_yaw(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_yaw(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_throttle(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_throttle(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_mode(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_mode(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_kill(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_kill(_payload)
#define DL_ROTORCRAFT_RADIO_CONTROL_status(_payload) pprzlink_get_DL_ROTORCRAFT_RADIO_CONTROL_status(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_RADIO_CONTROL_H_

