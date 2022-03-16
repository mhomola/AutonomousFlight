/** @file
 *  @brief PPRZLink message header for MULTIGAZE_METERS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MULTIGAZE_METERS_H_
#define _VAR_MESSAGES_telemetry_MULTIGAZE_METERS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MULTIGAZE_METERS 109
#define PPRZ_MSG_ID_MULTIGAZE_METERS 109

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MULTIGAZE_METERS _send_msg(MULTIGAZE_METERS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MULTIGAZE_METERS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_multigaze_meters,_multigaze_meters 
 */
static inline void pprzlink_msg_v2_send_MULTIGAZE_METERS(struct pprzlink_msg * msg, uint8_t nb_multigaze_meters, float *_multigaze_meters) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_multigaze_meters*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_multigaze_meters*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MULTIGAZE_METERS, "MULTIGAZE_METERS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_multigaze_meters, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _multigaze_meters, nb_multigaze_meters*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MULTIGAZE_METERS pprz_msg_send_MULTIGAZE_METERS
#define DOWNLINK_SEND_MULTIGAZE_METERS(_trans, _dev, nb_multigaze_meters, multigaze_meters) pprz_msg_send_MULTIGAZE_METERS(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_multigaze_meters, multigaze_meters)
/**
 * Sends a MULTIGAZE_METERS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_multigaze_meters,_multigaze_meters 
 */
static inline void pprz_msg_send_MULTIGAZE_METERS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_multigaze_meters, float *_multigaze_meters) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MULTIGAZE_METERS(&msg,nb_multigaze_meters,_multigaze_meters);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MULTIGAZE_METERS(_trans, _dev, nb_multigaze_meters, multigaze_meters) {}
static inline void pprz_send_msg_MULTIGAZE_METERS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_multigaze_meters __attribute__((unused)), float *_multigaze_meters __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array multigaze_meters in message MULTIGAZE_METERS
 *
 * @return multigaze_meters : 
 */
 static inline uint8_t pprzlink_get_MULTIGAZE_METERS_multigaze_meters_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 4);
}

/** Getter for field multigaze_meters in message MULTIGAZE_METERS
  *
  * @param _payload : a pointer to the MULTIGAZE_METERS message
  * @return 
  */
static inline float * pprzlink_get_DL_MULTIGAZE_METERS_multigaze_meters(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 5);
}


/* Compatibility macros */
#define DL_MULTIGAZE_METERS_multigaze_meters_length(_payload) pprzlink_get_MULTIGAZE_METERS_multigaze_meters_length(_payload)
#define DL_MULTIGAZE_METERS_multigaze_meters(_payload) pprzlink_get_DL_MULTIGAZE_METERS_multigaze_meters(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MULTIGAZE_METERS_H_

