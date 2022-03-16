/** @file
 *  @brief PPRZLink message header for NPS_GYRO_BIAS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_GYRO_BIAS_H_
#define _VAR_MESSAGES_telemetry_NPS_GYRO_BIAS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_GYRO_BIAS 242
#define PPRZ_MSG_ID_NPS_GYRO_BIAS 242

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_GYRO_BIAS _send_msg(NPS_GYRO_BIAS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_GYRO_BIAS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _bp 
 * @param _bq 
 * @param _br 
 */
static inline void pprzlink_msg_v2_send_NPS_GYRO_BIAS(struct pprzlink_msg * msg, float *_bp, float *_bq, float *_br) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_GYRO_BIAS, "NPS_GYRO_BIAS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _br, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_GYRO_BIAS pprz_msg_send_NPS_GYRO_BIAS
#define DOWNLINK_SEND_NPS_GYRO_BIAS(_trans, _dev, bp, bq, br) pprz_msg_send_NPS_GYRO_BIAS(&((_trans).trans_tx), &((_dev).device), AC_ID, bp, bq, br)
/**
 * Sends a NPS_GYRO_BIAS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _bp 
 * @param _bq 
 * @param _br 
 */
static inline void pprz_msg_send_NPS_GYRO_BIAS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_bp, float *_bq, float *_br) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_GYRO_BIAS(&msg,_bp,_bq,_br);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_GYRO_BIAS(_trans, _dev, bp, bq, br) {}
static inline void pprz_send_msg_NPS_GYRO_BIAS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_bp __attribute__((unused)), float *_bq __attribute__((unused)), float *_br __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field bp in message NPS_GYRO_BIAS
  *
  * @param _payload : a pointer to the NPS_GYRO_BIAS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_GYRO_BIAS_bp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field bq in message NPS_GYRO_BIAS
  *
  * @param _payload : a pointer to the NPS_GYRO_BIAS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_GYRO_BIAS_bq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field br in message NPS_GYRO_BIAS
  *
  * @param _payload : a pointer to the NPS_GYRO_BIAS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_GYRO_BIAS_br(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_NPS_GYRO_BIAS_bp(_payload) pprzlink_get_DL_NPS_GYRO_BIAS_bp(_payload)
#define DL_NPS_GYRO_BIAS_bq(_payload) pprzlink_get_DL_NPS_GYRO_BIAS_bq(_payload)
#define DL_NPS_GYRO_BIAS_br(_payload) pprzlink_get_DL_NPS_GYRO_BIAS_br(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_GYRO_BIAS_H_

