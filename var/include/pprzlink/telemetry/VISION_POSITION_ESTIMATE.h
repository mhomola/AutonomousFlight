/** @file
 *  @brief PPRZLink message header for VISION_POSITION_ESTIMATE in class telemetry
 *
 *  Generic message to send position measurement from computer vision
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VISION_POSITION_ESTIMATE_H_
#define _VAR_MESSAGES_telemetry_VISION_POSITION_ESTIMATE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VISION_POSITION_ESTIMATE 90
#define PPRZ_MSG_ID_VISION_POSITION_ESTIMATE 90

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VISION_POSITION_ESTIMATE _send_msg(VISION_POSITION_ESTIMATE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VISION_POSITION_ESTIMATE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cnt Counter
 * @param _x X
 * @param _y Y
 * @param _z Z
 * @param _quality Detection Quality or Uncertainty
 * @param _extra In case the default message does not suit you
 */
static inline void pprzlink_msg_v2_send_VISION_POSITION_ESTIMATE(struct pprzlink_msg * msg, uint16_t *_cnt, float *_x, float *_y, float *_z, float *_quality, float *_extra) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VISION_POSITION_ESTIMATE, "VISION_POSITION_ESTIMATE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _quality, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _extra, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VISION_POSITION_ESTIMATE pprz_msg_send_VISION_POSITION_ESTIMATE
#define DOWNLINK_SEND_VISION_POSITION_ESTIMATE(_trans, _dev, cnt, x, y, z, quality, extra) pprz_msg_send_VISION_POSITION_ESTIMATE(&((_trans).trans_tx), &((_dev).device), AC_ID, cnt, x, y, z, quality, extra)
/**
 * Sends a VISION_POSITION_ESTIMATE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cnt Counter
 * @param _x X
 * @param _y Y
 * @param _z Z
 * @param _quality Detection Quality or Uncertainty
 * @param _extra In case the default message does not suit you
 */
static inline void pprz_msg_send_VISION_POSITION_ESTIMATE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_cnt, float *_x, float *_y, float *_z, float *_quality, float *_extra) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VISION_POSITION_ESTIMATE(&msg,_cnt,_x,_y,_z,_quality,_extra);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VISION_POSITION_ESTIMATE(_trans, _dev, cnt, x, y, z, quality, extra) {}
static inline void pprz_send_msg_VISION_POSITION_ESTIMATE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_cnt __attribute__((unused)), float *_x __attribute__((unused)), float *_y __attribute__((unused)), float *_z __attribute__((unused)), float *_quality __attribute__((unused)), float *_extra __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cnt in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return Counter
  */
static inline uint16_t pprzlink_get_DL_VISION_POSITION_ESTIMATE_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field x in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return X
  */
static inline float pprzlink_get_DL_VISION_POSITION_ESTIMATE_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field y in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return Y
  */
static inline float pprzlink_get_DL_VISION_POSITION_ESTIMATE_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field z in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return Z
  */
static inline float pprzlink_get_DL_VISION_POSITION_ESTIMATE_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field quality in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return Detection Quality or Uncertainty
  */
static inline float pprzlink_get_DL_VISION_POSITION_ESTIMATE_quality(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field extra in message VISION_POSITION_ESTIMATE
  *
  * @param _payload : a pointer to the VISION_POSITION_ESTIMATE message
  * @return In case the default message does not suit you
  */
static inline float pprzlink_get_DL_VISION_POSITION_ESTIMATE_extra(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/* Compatibility macros */
#define DL_VISION_POSITION_ESTIMATE_cnt(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_cnt(_payload)
#define DL_VISION_POSITION_ESTIMATE_x(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_x(_payload)
#define DL_VISION_POSITION_ESTIMATE_y(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_y(_payload)
#define DL_VISION_POSITION_ESTIMATE_z(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_z(_payload)
#define DL_VISION_POSITION_ESTIMATE_quality(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_quality(_payload)
#define DL_VISION_POSITION_ESTIMATE_extra(_payload) pprzlink_get_DL_VISION_POSITION_ESTIMATE_extra(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VISION_POSITION_ESTIMATE_H_

