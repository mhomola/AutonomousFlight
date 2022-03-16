/** @file
 *  @brief PPRZLink message header for KEY_EXCHANGE_GCS in class datalink
 *
 *  Message for key exchange during crypto initialization
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_KEY_EXCHANGE_GCS_H_
#define _VAR_MESSAGES_datalink_KEY_EXCHANGE_GCS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_KEY_EXCHANGE_GCS 159
#define PPRZ_MSG_ID_KEY_EXCHANGE_GCS 159

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_KEY_EXCHANGE_GCS _send_msg(KEY_EXCHANGE_GCS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a KEY_EXCHANGE_GCS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id ID of the table's aircraft to be updated
 * @param _msg_type 
 * @param nb_msg_data,_msg_data 
 */
static inline void pprzlink_msg_v2_send_KEY_EXCHANGE_GCS(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_msg_type, uint8_t nb_msg_data, uint8_t *_msg_data) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+nb_msg_data*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+nb_msg_data*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_KEY_EXCHANGE_GCS, "KEY_EXCHANGE_GCS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _msg_type, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_msg_data, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _msg_data, nb_msg_data*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_KEY_EXCHANGE_GCS pprz_msg_send_KEY_EXCHANGE_GCS
#define DOWNLINK_SEND_KEY_EXCHANGE_GCS(_trans, _dev, ac_id, msg_type, nb_msg_data, msg_data) pprz_msg_send_KEY_EXCHANGE_GCS(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, msg_type, nb_msg_data, msg_data)
/**
 * Sends a KEY_EXCHANGE_GCS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id ID of the table's aircraft to be updated
 * @param _msg_type 
 * @param nb_msg_data,_msg_data 
 */
static inline void pprz_msg_send_KEY_EXCHANGE_GCS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_msg_type, uint8_t nb_msg_data, uint8_t *_msg_data) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_KEY_EXCHANGE_GCS(&msg,_ac_id,_msg_type,nb_msg_data,_msg_data);
}


#else // DOWNLINK

#define DOWNLINK_SEND_KEY_EXCHANGE_GCS(_trans, _dev, ac_id, msg_type, nb_msg_data, msg_data) {}
static inline void pprz_send_msg_KEY_EXCHANGE_GCS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_msg_type __attribute__((unused)), uint8_t nb_msg_data __attribute__((unused)), uint8_t *_msg_data __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message KEY_EXCHANGE_GCS
  *
  * @param _payload : a pointer to the KEY_EXCHANGE_GCS message
  * @return ID of the table's aircraft to be updated
  */
static inline uint8_t pprzlink_get_DL_KEY_EXCHANGE_GCS_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field msg_type in message KEY_EXCHANGE_GCS
  *
  * @param _payload : a pointer to the KEY_EXCHANGE_GCS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_KEY_EXCHANGE_GCS_msg_type(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for length of array msg_data in message KEY_EXCHANGE_GCS
 *
 * @return msg_data : 
 */
 static inline uint8_t pprzlink_get_KEY_EXCHANGE_GCS_msg_data_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for field msg_data in message KEY_EXCHANGE_GCS
  *
  * @param _payload : a pointer to the KEY_EXCHANGE_GCS message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_KEY_EXCHANGE_GCS_msg_data(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 7);
}


/* Compatibility macros */
#define DL_KEY_EXCHANGE_GCS_ac_id(_payload) pprzlink_get_DL_KEY_EXCHANGE_GCS_ac_id(_payload)
#define DL_KEY_EXCHANGE_GCS_msg_type(_payload) pprzlink_get_DL_KEY_EXCHANGE_GCS_msg_type(_payload)
#define DL_KEY_EXCHANGE_GCS_msg_data_length(_payload) pprzlink_get_KEY_EXCHANGE_GCS_msg_data_length(_payload)
#define DL_KEY_EXCHANGE_GCS_msg_data(_payload) pprzlink_get_DL_KEY_EXCHANGE_GCS_msg_data(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_KEY_EXCHANGE_GCS_H_

