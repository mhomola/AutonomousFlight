/** @file
 *  @brief PPRZLink message header for ALIVE in class telemetry
 *
 *  alive/heartbeat message containing the MD5sum of the aircraft configuration
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ALIVE_H_
#define _VAR_MESSAGES_telemetry_ALIVE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ALIVE 2
#define PPRZ_MSG_ID_ALIVE 2

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ALIVE _send_msg(ALIVE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ALIVE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_md5sum,_md5sum 
 */
static inline void pprzlink_msg_v2_send_ALIVE(struct pprzlink_msg * msg, uint8_t nb_md5sum, uint8_t *_md5sum) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_md5sum*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_md5sum*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ALIVE, "ALIVE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_md5sum, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _md5sum, nb_md5sum*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ALIVE pprz_msg_send_ALIVE
#define DOWNLINK_SEND_ALIVE(_trans, _dev, nb_md5sum, md5sum) pprz_msg_send_ALIVE(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_md5sum, md5sum)
/**
 * Sends a ALIVE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_md5sum,_md5sum 
 */
static inline void pprz_msg_send_ALIVE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_md5sum, uint8_t *_md5sum) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ALIVE(&msg,nb_md5sum,_md5sum);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ALIVE(_trans, _dev, nb_md5sum, md5sum) {}
static inline void pprz_send_msg_ALIVE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_md5sum __attribute__((unused)), uint8_t *_md5sum __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array md5sum in message ALIVE
 *
 * @return md5sum : 
 */
 static inline uint8_t pprzlink_get_ALIVE_md5sum_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for field md5sum in message ALIVE
  *
  * @param _payload : a pointer to the ALIVE message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_ALIVE_md5sum(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 5);
}


/* Compatibility macros */
#define DL_ALIVE_md5sum_length(_payload) pprzlink_get_ALIVE_md5sum_length(_payload)
#define DL_ALIVE_md5sum(_payload) pprzlink_get_DL_ALIVE_md5sum(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ALIVE_H_

