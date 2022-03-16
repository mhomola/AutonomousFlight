/** @file
 *  @brief PPRZLink message header for THROTTLE_CURVE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_THROTTLE_CURVE_H_
#define _VAR_MESSAGES_telemetry_THROTTLE_CURVE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_THROTTLE_CURVE 107
#define PPRZ_MSG_ID_THROTTLE_CURVE 107

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_THROTTLE_CURVE _send_msg(THROTTLE_CURVE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a THROTTLE_CURVE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _curve 
 * @param _throttle 
 * @param _collective 
 * @param _rpm_sp 
 * @param _rpm_meas 
 * @param _rpm_err_sum 
 */
static inline void pprzlink_msg_v2_send_THROTTLE_CURVE(struct pprzlink_msg * msg, uint8_t *_curve, uint16_t *_throttle, int16_t *_collective, uint16_t *_rpm_sp, uint16_t *_rpm_meas, float *_rpm_err_sum) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+2+2+2+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+2+2+2+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_THROTTLE_CURVE, "THROTTLE_CURVE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _curve, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _throttle, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _collective, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_sp, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rpm_meas, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rpm_err_sum, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_THROTTLE_CURVE pprz_msg_send_THROTTLE_CURVE
#define DOWNLINK_SEND_THROTTLE_CURVE(_trans, _dev, curve, throttle, collective, rpm_sp, rpm_meas, rpm_err_sum) pprz_msg_send_THROTTLE_CURVE(&((_trans).trans_tx), &((_dev).device), AC_ID, curve, throttle, collective, rpm_sp, rpm_meas, rpm_err_sum)
/**
 * Sends a THROTTLE_CURVE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _curve 
 * @param _throttle 
 * @param _collective 
 * @param _rpm_sp 
 * @param _rpm_meas 
 * @param _rpm_err_sum 
 */
static inline void pprz_msg_send_THROTTLE_CURVE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_curve, uint16_t *_throttle, int16_t *_collective, uint16_t *_rpm_sp, uint16_t *_rpm_meas, float *_rpm_err_sum) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_THROTTLE_CURVE(&msg,_curve,_throttle,_collective,_rpm_sp,_rpm_meas,_rpm_err_sum);
}


#else // DOWNLINK

#define DOWNLINK_SEND_THROTTLE_CURVE(_trans, _dev, curve, throttle, collective, rpm_sp, rpm_meas, rpm_err_sum) {}
static inline void pprz_send_msg_THROTTLE_CURVE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_curve __attribute__((unused)), uint16_t *_throttle __attribute__((unused)), int16_t *_collective __attribute__((unused)), uint16_t *_rpm_sp __attribute__((unused)), uint16_t *_rpm_meas __attribute__((unused)), float *_rpm_err_sum __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field curve in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_THROTTLE_CURVE_curve(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field throttle in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_THROTTLE_CURVE_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 5);
}


/** Getter for field collective in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline int16_t pprzlink_get_DL_THROTTLE_CURVE_collective(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 7);
}


/** Getter for field rpm_sp in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_THROTTLE_CURVE_rpm_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 9);
}


/** Getter for field rpm_meas in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_THROTTLE_CURVE_rpm_meas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 11);
}


/** Getter for field rpm_err_sum in message THROTTLE_CURVE
  *
  * @param _payload : a pointer to the THROTTLE_CURVE message
  * @return 
  */
static inline float pprzlink_get_DL_THROTTLE_CURVE_rpm_err_sum(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/* Compatibility macros */
#define DL_THROTTLE_CURVE_curve(_payload) pprzlink_get_DL_THROTTLE_CURVE_curve(_payload)
#define DL_THROTTLE_CURVE_throttle(_payload) pprzlink_get_DL_THROTTLE_CURVE_throttle(_payload)
#define DL_THROTTLE_CURVE_collective(_payload) pprzlink_get_DL_THROTTLE_CURVE_collective(_payload)
#define DL_THROTTLE_CURVE_rpm_sp(_payload) pprzlink_get_DL_THROTTLE_CURVE_rpm_sp(_payload)
#define DL_THROTTLE_CURVE_rpm_meas(_payload) pprzlink_get_DL_THROTTLE_CURVE_rpm_meas(_payload)
#define DL_THROTTLE_CURVE_rpm_err_sum(_payload) pprzlink_get_DL_THROTTLE_CURVE_rpm_err_sum(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_THROTTLE_CURVE_H_

