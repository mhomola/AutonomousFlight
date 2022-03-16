/** @file
 *  @brief PPRZLink message header for KITE_COMMAND in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_KITE_COMMAND_H_
#define _VAR_MESSAGES_datalink_KITE_COMMAND_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_KITE_COMMAND 96
#define PPRZ_MSG_ID_KITE_COMMAND 96

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_KITE_COMMAND _send_msg(KITE_COMMAND,PPRZLINK_DEFAULT_VER)

/**
 * Sends a KITE_COMMAND message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _POWER 
 * @param _TURN 
 */
static inline void pprzlink_msg_v2_send_KITE_COMMAND(struct pprzlink_msg * msg, uint16_t *_POWER, uint16_t *_TURN) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_KITE_COMMAND, "KITE_COMMAND");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _POWER, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _TURN, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_KITE_COMMAND pprz_msg_send_KITE_COMMAND
#define DOWNLINK_SEND_KITE_COMMAND(_trans, _dev, POWER, TURN) pprz_msg_send_KITE_COMMAND(&((_trans).trans_tx), &((_dev).device), AC_ID, POWER, TURN)
/**
 * Sends a KITE_COMMAND message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _POWER 
 * @param _TURN 
 */
static inline void pprz_msg_send_KITE_COMMAND(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_POWER, uint16_t *_TURN) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_KITE_COMMAND(&msg,_POWER,_TURN);
}


#else // DOWNLINK

#define DOWNLINK_SEND_KITE_COMMAND(_trans, _dev, POWER, TURN) {}
static inline void pprz_send_msg_KITE_COMMAND(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_POWER __attribute__((unused)), uint16_t *_TURN __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field POWER in message KITE_COMMAND
  *
  * @param _payload : a pointer to the KITE_COMMAND message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_KITE_COMMAND_POWER(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field TURN in message KITE_COMMAND
  *
  * @param _payload : a pointer to the KITE_COMMAND message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_KITE_COMMAND_TURN(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/* Compatibility macros */
#define DL_KITE_COMMAND_POWER(_payload) pprzlink_get_DL_KITE_COMMAND_POWER(_payload)
#define DL_KITE_COMMAND_TURN(_payload) pprzlink_get_DL_KITE_COMMAND_TURN(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_KITE_COMMAND_H_

