/** @file
 *  @brief PPRZLink message header for PAYLOAD_COMMAND in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_PAYLOAD_COMMAND_H_
#define _VAR_MESSAGES_datalink_PAYLOAD_COMMAND_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_PAYLOAD_COMMAND 97
#define PPRZ_MSG_ID_PAYLOAD_COMMAND 97

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_PAYLOAD_COMMAND _send_msg(PAYLOAD_COMMAND,PPRZLINK_DEFAULT_VER)

/**
 * Sends a PAYLOAD_COMMAND message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param nb_command,_command 
 */
static inline void pprzlink_msg_v2_send_PAYLOAD_COMMAND(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t nb_command, uint8_t *_command) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+nb_command*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+nb_command*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_PAYLOAD_COMMAND, "PAYLOAD_COMMAND");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_command, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _command, nb_command*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_PAYLOAD_COMMAND pprz_msg_send_PAYLOAD_COMMAND
#define DOWNLINK_SEND_PAYLOAD_COMMAND(_trans, _dev, ac_id, nb_command, command) pprz_msg_send_PAYLOAD_COMMAND(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, nb_command, command)
/**
 * Sends a PAYLOAD_COMMAND message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param nb_command,_command 
 */
static inline void pprz_msg_send_PAYLOAD_COMMAND(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t nb_command, uint8_t *_command) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_PAYLOAD_COMMAND(&msg,_ac_id,nb_command,_command);
}


#else // DOWNLINK

#define DOWNLINK_SEND_PAYLOAD_COMMAND(_trans, _dev, ac_id, nb_command, command) {}
static inline void pprz_send_msg_PAYLOAD_COMMAND(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t nb_command __attribute__((unused)), uint8_t *_command __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message PAYLOAD_COMMAND
  *
  * @param _payload : a pointer to the PAYLOAD_COMMAND message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PAYLOAD_COMMAND_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for length of array command in message PAYLOAD_COMMAND
 *
 * @return command : 
 */
 static inline uint8_t pprzlink_get_PAYLOAD_COMMAND_command_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for field command in message PAYLOAD_COMMAND
  *
  * @param _payload : a pointer to the PAYLOAD_COMMAND message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_PAYLOAD_COMMAND_command(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 6);
}


/* Compatibility macros */
#define DL_PAYLOAD_COMMAND_ac_id(_payload) pprzlink_get_DL_PAYLOAD_COMMAND_ac_id(_payload)
#define DL_PAYLOAD_COMMAND_command_length(_payload) pprzlink_get_PAYLOAD_COMMAND_command_length(_payload)
#define DL_PAYLOAD_COMMAND_command(_payload) pprzlink_get_DL_PAYLOAD_COMMAND_command(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_PAYLOAD_COMMAND_H_

