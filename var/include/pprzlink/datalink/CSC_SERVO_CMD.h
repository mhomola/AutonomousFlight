/** @file
 *  @brief PPRZLink message header for CSC_SERVO_CMD in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_CSC_SERVO_CMD_H_
#define _VAR_MESSAGES_datalink_CSC_SERVO_CMD_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CSC_SERVO_CMD 101
#define PPRZ_MSG_ID_CSC_SERVO_CMD 101

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CSC_SERVO_CMD _send_msg(CSC_SERVO_CMD,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CSC_SERVO_CMD message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _servo_1 
 * @param _servo_2 
 * @param _servo_3 
 * @param _servo_4 
 */
static inline void pprzlink_msg_v2_send_CSC_SERVO_CMD(struct pprzlink_msg * msg, uint16_t *_servo_1, uint16_t *_servo_2, uint16_t *_servo_3, uint16_t *_servo_4) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CSC_SERVO_CMD, "CSC_SERVO_CMD");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _servo_1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _servo_2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _servo_3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _servo_4, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CSC_SERVO_CMD pprz_msg_send_CSC_SERVO_CMD
#define DOWNLINK_SEND_CSC_SERVO_CMD(_trans, _dev, servo_1, servo_2, servo_3, servo_4) pprz_msg_send_CSC_SERVO_CMD(&((_trans).trans_tx), &((_dev).device), AC_ID, servo_1, servo_2, servo_3, servo_4)
/**
 * Sends a CSC_SERVO_CMD message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _servo_1 
 * @param _servo_2 
 * @param _servo_3 
 * @param _servo_4 
 */
static inline void pprz_msg_send_CSC_SERVO_CMD(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_servo_1, uint16_t *_servo_2, uint16_t *_servo_3, uint16_t *_servo_4) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CSC_SERVO_CMD(&msg,_servo_1,_servo_2,_servo_3,_servo_4);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CSC_SERVO_CMD(_trans, _dev, servo_1, servo_2, servo_3, servo_4) {}
static inline void pprz_send_msg_CSC_SERVO_CMD(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_servo_1 __attribute__((unused)), uint16_t *_servo_2 __attribute__((unused)), uint16_t *_servo_3 __attribute__((unused)), uint16_t *_servo_4 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field servo_1 in message CSC_SERVO_CMD
  *
  * @param _payload : a pointer to the CSC_SERVO_CMD message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_CSC_SERVO_CMD_servo_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field servo_2 in message CSC_SERVO_CMD
  *
  * @param _payload : a pointer to the CSC_SERVO_CMD message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_CSC_SERVO_CMD_servo_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field servo_3 in message CSC_SERVO_CMD
  *
  * @param _payload : a pointer to the CSC_SERVO_CMD message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_CSC_SERVO_CMD_servo_3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field servo_4 in message CSC_SERVO_CMD
  *
  * @param _payload : a pointer to the CSC_SERVO_CMD message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_CSC_SERVO_CMD_servo_4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/* Compatibility macros */
#define DL_CSC_SERVO_CMD_servo_1(_payload) pprzlink_get_DL_CSC_SERVO_CMD_servo_1(_payload)
#define DL_CSC_SERVO_CMD_servo_2(_payload) pprzlink_get_DL_CSC_SERVO_CMD_servo_2(_payload)
#define DL_CSC_SERVO_CMD_servo_3(_payload) pprzlink_get_DL_CSC_SERVO_CMD_servo_3(_payload)
#define DL_CSC_SERVO_CMD_servo_4(_payload) pprzlink_get_DL_CSC_SERVO_CMD_servo_4(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_CSC_SERVO_CMD_H_

