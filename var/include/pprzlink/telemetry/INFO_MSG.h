/** @file
 *  @brief PPRZLink message header for INFO_MSG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INFO_MSG_H_
#define _VAR_MESSAGES_telemetry_INFO_MSG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INFO_MSG 215
#define PPRZ_MSG_ID_INFO_MSG 215

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INFO_MSG _send_msg(INFO_MSG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INFO_MSG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_msg,_msg 
 */
static inline void pprzlink_msg_v2_send_INFO_MSG(struct pprzlink_msg * msg, uint8_t nb_msg, char *_msg) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_msg*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_msg*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INFO_MSG, "INFO_MSG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_msg, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _msg, nb_msg*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INFO_MSG pprz_msg_send_INFO_MSG
#define DOWNLINK_SEND_INFO_MSG(_trans, _dev, nb_msg, msg) pprz_msg_send_INFO_MSG(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_msg, msg)
/**
 * Sends a INFO_MSG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_msg,_msg 
 */
static inline void pprz_msg_send_INFO_MSG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_msg, char *_msg) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INFO_MSG(&msg,nb_msg,_msg);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INFO_MSG(_trans, _dev, nb_msg, msg) {}
static inline void pprz_send_msg_INFO_MSG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_msg __attribute__((unused)), char *_msg __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array msg in message INFO_MSG
 *
 * @return msg : 
 */
 static inline uint8_t pprzlink_get_INFO_MSG_msg_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for field msg in message INFO_MSG
  *
  * @param _payload : a pointer to the INFO_MSG message
  * @return 
  */
static inline char * pprzlink_get_DL_INFO_MSG_msg(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 5);
}


/* Compatibility macros */
#define DL_INFO_MSG_msg_length(_payload) pprzlink_get_INFO_MSG_msg_length(_payload)
#define DL_INFO_MSG_msg(_payload) pprzlink_get_DL_INFO_MSG_msg(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INFO_MSG_H_

