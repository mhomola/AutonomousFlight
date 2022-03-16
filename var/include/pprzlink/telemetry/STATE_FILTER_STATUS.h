/** @file
 *  @brief PPRZLink message header for STATE_FILTER_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STATE_FILTER_STATUS_H_
#define _VAR_MESSAGES_telemetry_STATE_FILTER_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STATE_FILTER_STATUS 232
#define PPRZ_MSG_ID_STATE_FILTER_STATUS 232

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STATE_FILTER_STATUS _send_msg(STATE_FILTER_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STATE_FILTER_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _id 
 * @param _state_filter_mode 
 * @param _value 
 */
static inline void pprzlink_msg_v2_send_STATE_FILTER_STATUS(struct pprzlink_msg * msg, uint8_t *_id, uint8_t *_state_filter_mode, uint16_t *_value) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STATE_FILTER_STATUS, "STATE_FILTER_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _state_filter_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _value, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STATE_FILTER_STATUS pprz_msg_send_STATE_FILTER_STATUS
#define DOWNLINK_SEND_STATE_FILTER_STATUS(_trans, _dev, id, state_filter_mode, value) pprz_msg_send_STATE_FILTER_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, id, state_filter_mode, value)
/**
 * Sends a STATE_FILTER_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _id 
 * @param _state_filter_mode 
 * @param _value 
 */
static inline void pprz_msg_send_STATE_FILTER_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_id, uint8_t *_state_filter_mode, uint16_t *_value) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STATE_FILTER_STATUS(&msg,_id,_state_filter_mode,_value);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STATE_FILTER_STATUS(_trans, _dev, id, state_filter_mode, value) {}
static inline void pprz_send_msg_STATE_FILTER_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_id __attribute__((unused)), uint8_t *_state_filter_mode __attribute__((unused)), uint16_t *_value __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field id in message STATE_FILTER_STATUS
  *
  * @param _payload : a pointer to the STATE_FILTER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STATE_FILTER_STATUS_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field state_filter_mode in message STATE_FILTER_STATUS
  *
  * @param _payload : a pointer to the STATE_FILTER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STATE_FILTER_STATUS_state_filter_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field value in message STATE_FILTER_STATUS
  *
  * @param _payload : a pointer to the STATE_FILTER_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_STATE_FILTER_STATUS_value(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/* Compatibility macros */
#define DL_STATE_FILTER_STATUS_id(_payload) pprzlink_get_DL_STATE_FILTER_STATUS_id(_payload)
#define DL_STATE_FILTER_STATUS_state_filter_mode(_payload) pprzlink_get_DL_STATE_FILTER_STATUS_state_filter_mode(_payload)
#define DL_STATE_FILTER_STATUS_value(_payload) pprzlink_get_DL_STATE_FILTER_STATUS_value(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STATE_FILTER_STATUS_H_

