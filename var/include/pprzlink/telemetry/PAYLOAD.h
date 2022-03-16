/** @file
 *  @brief PPRZLink message header for PAYLOAD in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_PAYLOAD_H_
#define _VAR_MESSAGES_telemetry_PAYLOAD_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_PAYLOAD 114
#define PPRZ_MSG_ID_PAYLOAD 114

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_PAYLOAD _send_msg(PAYLOAD,PPRZLINK_DEFAULT_VER)

/**
 * Sends a PAYLOAD message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_values,_values 
 */
static inline void pprzlink_msg_v2_send_PAYLOAD(struct pprzlink_msg * msg, uint8_t nb_values, uint8_t *_values) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_values*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_values*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_PAYLOAD, "PAYLOAD");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_values, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _values, nb_values*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_PAYLOAD pprz_msg_send_PAYLOAD
#define DOWNLINK_SEND_PAYLOAD(_trans, _dev, nb_values, values) pprz_msg_send_PAYLOAD(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_values, values)
/**
 * Sends a PAYLOAD message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_values,_values 
 */
static inline void pprz_msg_send_PAYLOAD(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_values, uint8_t *_values) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_PAYLOAD(&msg,nb_values,_values);
}


#else // DOWNLINK

#define DOWNLINK_SEND_PAYLOAD(_trans, _dev, nb_values, values) {}
static inline void pprz_send_msg_PAYLOAD(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_values __attribute__((unused)), uint8_t *_values __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array values in message PAYLOAD
 *
 * @return values : 
 */
 static inline uint8_t pprzlink_get_PAYLOAD_values_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for field values in message PAYLOAD
  *
  * @param _payload : a pointer to the PAYLOAD message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_PAYLOAD_values(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 5);
}


/* Compatibility macros */
#define DL_PAYLOAD_values_length(_payload) pprzlink_get_PAYLOAD_values_length(_payload)
#define DL_PAYLOAD_values(_payload) pprzlink_get_DL_PAYLOAD_values(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_PAYLOAD_H_

