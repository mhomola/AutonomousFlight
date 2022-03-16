/** @file
 *  @brief PPRZLink message header for ALT_KALMAN in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ALT_KALMAN_H_
#define _VAR_MESSAGES_telemetry_ALT_KALMAN_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ALT_KALMAN 41
#define PPRZ_MSG_ID_ALT_KALMAN 41

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ALT_KALMAN _send_msg(ALT_KALMAN,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ALT_KALMAN message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _p00 
 * @param _p01 
 * @param _p10 
 * @param _p11 
 */
static inline void pprzlink_msg_v2_send_ALT_KALMAN(struct pprzlink_msg * msg, float *_p00, float *_p01, float *_p10, float *_p11) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ALT_KALMAN, "ALT_KALMAN");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p00, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p01, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p10, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p11, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ALT_KALMAN pprz_msg_send_ALT_KALMAN
#define DOWNLINK_SEND_ALT_KALMAN(_trans, _dev, p00, p01, p10, p11) pprz_msg_send_ALT_KALMAN(&((_trans).trans_tx), &((_dev).device), AC_ID, p00, p01, p10, p11)
/**
 * Sends a ALT_KALMAN message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _p00 
 * @param _p01 
 * @param _p10 
 * @param _p11 
 */
static inline void pprz_msg_send_ALT_KALMAN(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_p00, float *_p01, float *_p10, float *_p11) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ALT_KALMAN(&msg,_p00,_p01,_p10,_p11);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ALT_KALMAN(_trans, _dev, p00, p01, p10, p11) {}
static inline void pprz_send_msg_ALT_KALMAN(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_p00 __attribute__((unused)), float *_p01 __attribute__((unused)), float *_p10 __attribute__((unused)), float *_p11 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field p00 in message ALT_KALMAN
  *
  * @param _payload : a pointer to the ALT_KALMAN message
  * @return 
  */
static inline float pprzlink_get_DL_ALT_KALMAN_p00(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field p01 in message ALT_KALMAN
  *
  * @param _payload : a pointer to the ALT_KALMAN message
  * @return 
  */
static inline float pprzlink_get_DL_ALT_KALMAN_p01(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field p10 in message ALT_KALMAN
  *
  * @param _payload : a pointer to the ALT_KALMAN message
  * @return 
  */
static inline float pprzlink_get_DL_ALT_KALMAN_p10(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field p11 in message ALT_KALMAN
  *
  * @param _payload : a pointer to the ALT_KALMAN message
  * @return 
  */
static inline float pprzlink_get_DL_ALT_KALMAN_p11(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_ALT_KALMAN_p00(_payload) pprzlink_get_DL_ALT_KALMAN_p00(_payload)
#define DL_ALT_KALMAN_p01(_payload) pprzlink_get_DL_ALT_KALMAN_p01(_payload)
#define DL_ALT_KALMAN_p10(_payload) pprzlink_get_DL_ALT_KALMAN_p10(_payload)
#define DL_ALT_KALMAN_p11(_payload) pprzlink_get_DL_ALT_KALMAN_p11(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ALT_KALMAN_H_

