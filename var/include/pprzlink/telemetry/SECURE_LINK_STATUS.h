/** @file
 *  @brief PPRZLink message header for SECURE_LINK_STATUS in class telemetry
 *
 *  Message for monitoring key exchange status
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SECURE_LINK_STATUS_H_
#define _VAR_MESSAGES_telemetry_SECURE_LINK_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SECURE_LINK_STATUS 255
#define PPRZ_MSG_ID_SECURE_LINK_STATUS 255

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SECURE_LINK_STATUS _send_msg(SECURE_LINK_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SECURE_LINK_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sts_stage 
 * @param _sts_error 
 * @param _counter_err 
 * @param _decrypt_err 
 * @param _encrypt_err 
 */
static inline void pprzlink_msg_v2_send_SECURE_LINK_STATUS(struct pprzlink_msg * msg, uint8_t *_sts_stage, uint8_t *_sts_error, uint32_t *_counter_err, uint32_t *_decrypt_err, uint32_t *_encrypt_err) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SECURE_LINK_STATUS, "SECURE_LINK_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _sts_stage, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _sts_error, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _counter_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _decrypt_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _encrypt_err, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SECURE_LINK_STATUS pprz_msg_send_SECURE_LINK_STATUS
#define DOWNLINK_SEND_SECURE_LINK_STATUS(_trans, _dev, sts_stage, sts_error, counter_err, decrypt_err, encrypt_err) pprz_msg_send_SECURE_LINK_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, sts_stage, sts_error, counter_err, decrypt_err, encrypt_err)
/**
 * Sends a SECURE_LINK_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sts_stage 
 * @param _sts_error 
 * @param _counter_err 
 * @param _decrypt_err 
 * @param _encrypt_err 
 */
static inline void pprz_msg_send_SECURE_LINK_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_sts_stage, uint8_t *_sts_error, uint32_t *_counter_err, uint32_t *_decrypt_err, uint32_t *_encrypt_err) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SECURE_LINK_STATUS(&msg,_sts_stage,_sts_error,_counter_err,_decrypt_err,_encrypt_err);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SECURE_LINK_STATUS(_trans, _dev, sts_stage, sts_error, counter_err, decrypt_err, encrypt_err) {}
static inline void pprz_send_msg_SECURE_LINK_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_sts_stage __attribute__((unused)), uint8_t *_sts_error __attribute__((unused)), uint32_t *_counter_err __attribute__((unused)), uint32_t *_decrypt_err __attribute__((unused)), uint32_t *_encrypt_err __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sts_stage in message SECURE_LINK_STATUS
  *
  * @param _payload : a pointer to the SECURE_LINK_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SECURE_LINK_STATUS_sts_stage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field sts_error in message SECURE_LINK_STATUS
  *
  * @param _payload : a pointer to the SECURE_LINK_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SECURE_LINK_STATUS_sts_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field counter_err in message SECURE_LINK_STATUS
  *
  * @param _payload : a pointer to the SECURE_LINK_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SECURE_LINK_STATUS_counter_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}


/** Getter for field decrypt_err in message SECURE_LINK_STATUS
  *
  * @param _payload : a pointer to the SECURE_LINK_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SECURE_LINK_STATUS_decrypt_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 10);
}


/** Getter for field encrypt_err in message SECURE_LINK_STATUS
  *
  * @param _payload : a pointer to the SECURE_LINK_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SECURE_LINK_STATUS_encrypt_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 14);
}


/* Compatibility macros */
#define DL_SECURE_LINK_STATUS_sts_stage(_payload) pprzlink_get_DL_SECURE_LINK_STATUS_sts_stage(_payload)
#define DL_SECURE_LINK_STATUS_sts_error(_payload) pprzlink_get_DL_SECURE_LINK_STATUS_sts_error(_payload)
#define DL_SECURE_LINK_STATUS_counter_err(_payload) pprzlink_get_DL_SECURE_LINK_STATUS_counter_err(_payload)
#define DL_SECURE_LINK_STATUS_decrypt_err(_payload) pprzlink_get_DL_SECURE_LINK_STATUS_decrypt_err(_payload)
#define DL_SECURE_LINK_STATUS_encrypt_err(_payload) pprzlink_get_DL_SECURE_LINK_STATUS_encrypt_err(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SECURE_LINK_STATUS_H_

