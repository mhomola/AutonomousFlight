/** @file
 *  @brief PPRZLink message header for DEBUG_IR_I2C in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DEBUG_IR_I2C_H_
#define _VAR_MESSAGES_telemetry_DEBUG_IR_I2C_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DEBUG_IR_I2C 53
#define PPRZ_MSG_ID_DEBUG_IR_I2C 53

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DEBUG_IR_I2C _send_msg(DEBUG_IR_I2C,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DEBUG_IR_I2C message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ir1 
 * @param _ir2 
 * @param _top 
 */
static inline void pprzlink_msg_v2_send_DEBUG_IR_I2C(struct pprzlink_msg * msg, int16_t *_ir1, int16_t *_ir2, int16_t *_top) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DEBUG_IR_I2C, "DEBUG_IR_I2C");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _ir1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _ir2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _top, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DEBUG_IR_I2C pprz_msg_send_DEBUG_IR_I2C
#define DOWNLINK_SEND_DEBUG_IR_I2C(_trans, _dev, ir1, ir2, top) pprz_msg_send_DEBUG_IR_I2C(&((_trans).trans_tx), &((_dev).device), AC_ID, ir1, ir2, top)
/**
 * Sends a DEBUG_IR_I2C message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ir1 
 * @param _ir2 
 * @param _top 
 */
static inline void pprz_msg_send_DEBUG_IR_I2C(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_ir1, int16_t *_ir2, int16_t *_top) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DEBUG_IR_I2C(&msg,_ir1,_ir2,_top);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DEBUG_IR_I2C(_trans, _dev, ir1, ir2, top) {}
static inline void pprz_send_msg_DEBUG_IR_I2C(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_ir1 __attribute__((unused)), int16_t *_ir2 __attribute__((unused)), int16_t *_top __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ir1 in message DEBUG_IR_I2C
  *
  * @param _payload : a pointer to the DEBUG_IR_I2C message
  * @return 
  */
static inline int16_t pprzlink_get_DL_DEBUG_IR_I2C_ir1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field ir2 in message DEBUG_IR_I2C
  *
  * @param _payload : a pointer to the DEBUG_IR_I2C message
  * @return 
  */
static inline int16_t pprzlink_get_DL_DEBUG_IR_I2C_ir2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field top in message DEBUG_IR_I2C
  *
  * @param _payload : a pointer to the DEBUG_IR_I2C message
  * @return 
  */
static inline int16_t pprzlink_get_DL_DEBUG_IR_I2C_top(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/* Compatibility macros */
#define DL_DEBUG_IR_I2C_ir1(_payload) pprzlink_get_DL_DEBUG_IR_I2C_ir1(_payload)
#define DL_DEBUG_IR_I2C_ir2(_payload) pprzlink_get_DL_DEBUG_IR_I2C_ir2(_payload)
#define DL_DEBUG_IR_I2C_top(_payload) pprzlink_get_DL_DEBUG_IR_I2C_top(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DEBUG_IR_I2C_H_

