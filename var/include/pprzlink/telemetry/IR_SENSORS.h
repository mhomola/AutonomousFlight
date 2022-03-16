/** @file
 *  @brief PPRZLink message header for IR_SENSORS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IR_SENSORS_H_
#define _VAR_MESSAGES_telemetry_IR_SENSORS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IR_SENSORS 7
#define PPRZ_MSG_ID_IR_SENSORS 7

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IR_SENSORS _send_msg(IR_SENSORS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IR_SENSORS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ir1 
 * @param _ir2 
 * @param _longitudinal 
 * @param _lateral 
 * @param _vertical 
 */
static inline void pprzlink_msg_v2_send_IR_SENSORS(struct pprzlink_msg * msg, int16_t *_ir1, int16_t *_ir2, int16_t *_longitudinal, int16_t *_lateral, int16_t *_vertical) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IR_SENSORS, "IR_SENSORS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _ir1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _ir2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _longitudinal, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _lateral, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _vertical, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IR_SENSORS pprz_msg_send_IR_SENSORS
#define DOWNLINK_SEND_IR_SENSORS(_trans, _dev, ir1, ir2, longitudinal, lateral, vertical) pprz_msg_send_IR_SENSORS(&((_trans).trans_tx), &((_dev).device), AC_ID, ir1, ir2, longitudinal, lateral, vertical)
/**
 * Sends a IR_SENSORS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ir1 
 * @param _ir2 
 * @param _longitudinal 
 * @param _lateral 
 * @param _vertical 
 */
static inline void pprz_msg_send_IR_SENSORS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_ir1, int16_t *_ir2, int16_t *_longitudinal, int16_t *_lateral, int16_t *_vertical) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IR_SENSORS(&msg,_ir1,_ir2,_longitudinal,_lateral,_vertical);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IR_SENSORS(_trans, _dev, ir1, ir2, longitudinal, lateral, vertical) {}
static inline void pprz_send_msg_IR_SENSORS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_ir1 __attribute__((unused)), int16_t *_ir2 __attribute__((unused)), int16_t *_longitudinal __attribute__((unused)), int16_t *_lateral __attribute__((unused)), int16_t *_vertical __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ir1 in message IR_SENSORS
  *
  * @param _payload : a pointer to the IR_SENSORS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IR_SENSORS_ir1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field ir2 in message IR_SENSORS
  *
  * @param _payload : a pointer to the IR_SENSORS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IR_SENSORS_ir2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field longitudinal in message IR_SENSORS
  *
  * @param _payload : a pointer to the IR_SENSORS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IR_SENSORS_longitudinal(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field lateral in message IR_SENSORS
  *
  * @param _payload : a pointer to the IR_SENSORS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IR_SENSORS_lateral(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/** Getter for field vertical in message IR_SENSORS
  *
  * @param _payload : a pointer to the IR_SENSORS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IR_SENSORS_vertical(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/* Compatibility macros */
#define DL_IR_SENSORS_ir1(_payload) pprzlink_get_DL_IR_SENSORS_ir1(_payload)
#define DL_IR_SENSORS_ir2(_payload) pprzlink_get_DL_IR_SENSORS_ir2(_payload)
#define DL_IR_SENSORS_longitudinal(_payload) pprzlink_get_DL_IR_SENSORS_longitudinal(_payload)
#define DL_IR_SENSORS_lateral(_payload) pprzlink_get_DL_IR_SENSORS_lateral(_payload)
#define DL_IR_SENSORS_vertical(_payload) pprzlink_get_DL_IR_SENSORS_vertical(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IR_SENSORS_H_

