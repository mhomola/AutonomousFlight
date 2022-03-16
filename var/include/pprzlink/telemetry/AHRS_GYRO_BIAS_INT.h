/** @file
 *  @brief PPRZLink message header for AHRS_GYRO_BIAS_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AHRS_GYRO_BIAS_INT_H_
#define _VAR_MESSAGES_telemetry_AHRS_GYRO_BIAS_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AHRS_GYRO_BIAS_INT 178
#define PPRZ_MSG_ID_AHRS_GYRO_BIAS_INT 178

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AHRS_GYRO_BIAS_INT _send_msg(AHRS_GYRO_BIAS_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AHRS_GYRO_BIAS_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _bp 
 * @param _bq 
 * @param _br 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_AHRS_GYRO_BIAS_INT(struct pprzlink_msg * msg, int32_t *_bp, int32_t *_bq, int32_t *_br, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AHRS_GYRO_BIAS_INT, "AHRS_GYRO_BIAS_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _bp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _bq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _br, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AHRS_GYRO_BIAS_INT pprz_msg_send_AHRS_GYRO_BIAS_INT
#define DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(_trans, _dev, bp, bq, br, comp_id) pprz_msg_send_AHRS_GYRO_BIAS_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, bp, bq, br, comp_id)
/**
 * Sends a AHRS_GYRO_BIAS_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _bp 
 * @param _bq 
 * @param _br 
 * @param _comp_id 
 */
static inline void pprz_msg_send_AHRS_GYRO_BIAS_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_bp, int32_t *_bq, int32_t *_br, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AHRS_GYRO_BIAS_INT(&msg,_bp,_bq,_br,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(_trans, _dev, bp, bq, br, comp_id) {}
static inline void pprz_send_msg_AHRS_GYRO_BIAS_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_bp __attribute__((unused)), int32_t *_bq __attribute__((unused)), int32_t *_br __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field bp in message AHRS_GYRO_BIAS_INT
  *
  * @param _payload : a pointer to the AHRS_GYRO_BIAS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_GYRO_BIAS_INT_bp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field bq in message AHRS_GYRO_BIAS_INT
  *
  * @param _payload : a pointer to the AHRS_GYRO_BIAS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_GYRO_BIAS_INT_bq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field br in message AHRS_GYRO_BIAS_INT
  *
  * @param _payload : a pointer to the AHRS_GYRO_BIAS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_GYRO_BIAS_INT_br(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field comp_id in message AHRS_GYRO_BIAS_INT
  *
  * @param _payload : a pointer to the AHRS_GYRO_BIAS_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_AHRS_GYRO_BIAS_INT_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/* Compatibility macros */
#define DL_AHRS_GYRO_BIAS_INT_bp(_payload) pprzlink_get_DL_AHRS_GYRO_BIAS_INT_bp(_payload)
#define DL_AHRS_GYRO_BIAS_INT_bq(_payload) pprzlink_get_DL_AHRS_GYRO_BIAS_INT_bq(_payload)
#define DL_AHRS_GYRO_BIAS_INT_br(_payload) pprzlink_get_DL_AHRS_GYRO_BIAS_INT_br(_payload)
#define DL_AHRS_GYRO_BIAS_INT_comp_id(_payload) pprzlink_get_DL_AHRS_GYRO_BIAS_INT_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AHRS_GYRO_BIAS_INT_H_

