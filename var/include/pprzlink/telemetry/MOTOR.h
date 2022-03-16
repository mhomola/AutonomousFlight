/** @file
 *  @brief PPRZLink message header for MOTOR in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MOTOR_H_
#define _VAR_MESSAGES_telemetry_MOTOR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MOTOR 34
#define PPRZ_MSG_ID_MOTOR 34

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MOTOR _send_msg(MOTOR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MOTOR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _rpm 
 * @param _current 
 */
static inline void pprzlink_msg_v2_send_MOTOR(struct pprzlink_msg * msg, uint16_t *_rpm, float *_current) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MOTOR, "MOTOR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MOTOR pprz_msg_send_MOTOR
#define DOWNLINK_SEND_MOTOR(_trans, _dev, rpm, current) pprz_msg_send_MOTOR(&((_trans).trans_tx), &((_dev).device), AC_ID, rpm, current)
/**
 * Sends a MOTOR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _rpm 
 * @param _current 
 */
static inline void pprz_msg_send_MOTOR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_rpm, float *_current) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MOTOR(&msg,_rpm,_current);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MOTOR(_trans, _dev, rpm, current) {}
static inline void pprz_send_msg_MOTOR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_rpm __attribute__((unused)), float *_current __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field rpm in message MOTOR
  *
  * @param _payload : a pointer to the MOTOR message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MOTOR_rpm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field current in message MOTOR
  *
  * @param _payload : a pointer to the MOTOR message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/* Compatibility macros */
#define DL_MOTOR_rpm(_payload) pprzlink_get_DL_MOTOR_rpm(_payload)
#define DL_MOTOR_current(_payload) pprzlink_get_DL_MOTOR_current(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MOTOR_H_

