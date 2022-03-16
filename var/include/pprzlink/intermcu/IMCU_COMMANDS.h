/** @file
 *  @brief PPRZLink message header for IMCU_COMMANDS in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_COMMANDS_H_
#define _VAR_MESSAGES_intermcu_IMCU_COMMANDS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_COMMANDS 1
#define PPRZ_MSG_ID_IMCU_COMMANDS 1

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_COMMANDS _send_msg(IMCU_COMMANDS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_COMMANDS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _status 
 * @param nb_values,_values 
 */
static inline void pprzlink_msg_v2_send_IMCU_COMMANDS(struct pprzlink_msg * msg, uint8_t *_status, uint8_t nb_values, int16_t *_values) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+nb_values*2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+nb_values*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_COMMANDS, "IMCU_COMMANDS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_values, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_ARRAY, (void *) _values, nb_values*2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_COMMANDS pprz_msg_send_IMCU_COMMANDS
#define DOWNLINK_SEND_IMCU_COMMANDS(_trans, _dev, status, nb_values, values) pprz_msg_send_IMCU_COMMANDS(&((_trans).trans_tx), &((_dev).device), AC_ID, status, nb_values, values)
/**
 * Sends a IMCU_COMMANDS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _status 
 * @param nb_values,_values 
 */
static inline void pprz_msg_send_IMCU_COMMANDS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_status, uint8_t nb_values, int16_t *_values) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_COMMANDS(&msg,_status,nb_values,_values);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_COMMANDS(_trans, _dev, status, nb_values, values) {}
static inline void pprz_send_msg_IMCU_COMMANDS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_status __attribute__((unused)), uint8_t nb_values __attribute__((unused)), int16_t *_values __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field status in message IMCU_COMMANDS
  *
  * @param _payload : a pointer to the IMCU_COMMANDS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_COMMANDS_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for length of array values in message IMCU_COMMANDS
 *
 * @return values : 
 */
 static inline uint8_t pprzlink_get_IMCU_COMMANDS_values_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for field values in message IMCU_COMMANDS
  *
  * @param _payload : a pointer to the IMCU_COMMANDS message
  * @return 
  */
static inline int16_t * pprzlink_get_DL_IMCU_COMMANDS_values(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t_array(_payload, 6);
}


/* Compatibility macros */
#define DL_IMCU_COMMANDS_status(_payload) pprzlink_get_DL_IMCU_COMMANDS_status(_payload)
#define DL_IMCU_COMMANDS_values_length(_payload) pprzlink_get_IMCU_COMMANDS_values_length(_payload)
#define DL_IMCU_COMMANDS_values(_payload) pprzlink_get_DL_IMCU_COMMANDS_values(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_COMMANDS_H_

