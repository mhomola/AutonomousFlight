/** @file
 *  @brief PPRZLink message header for MPPT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MPPT_H_
#define _VAR_MESSAGES_telemetry_MPPT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MPPT 52
#define PPRZ_MSG_ID_MPPT 52

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MPPT _send_msg(MPPT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MPPT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_values,_values 
 */
static inline void pprzlink_msg_v2_send_MPPT(struct pprzlink_msg * msg, uint8_t nb_values, int16_t *_values) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_values*2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_values*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MPPT, "MPPT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_values, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_ARRAY, (void *) _values, nb_values*2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MPPT pprz_msg_send_MPPT
#define DOWNLINK_SEND_MPPT(_trans, _dev, nb_values, values) pprz_msg_send_MPPT(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_values, values)
/**
 * Sends a MPPT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_values,_values 
 */
static inline void pprz_msg_send_MPPT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_values, int16_t *_values) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MPPT(&msg,nb_values,_values);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MPPT(_trans, _dev, nb_values, values) {}
static inline void pprz_send_msg_MPPT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_values __attribute__((unused)), int16_t *_values __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array values in message MPPT
 *
 * @return values : 
 */
 static inline uint8_t pprzlink_get_MPPT_values_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 4);
}

/** Getter for field values in message MPPT
  *
  * @param _payload : a pointer to the MPPT message
  * @return 
  */
static inline int16_t * pprzlink_get_DL_MPPT_values(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t_array(_payload, 5);
}


/* Compatibility macros */
#define DL_MPPT_values_length(_payload) pprzlink_get_MPPT_values_length(_payload)
#define DL_MPPT_values(_payload) pprzlink_get_DL_MPPT_values(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MPPT_H_

