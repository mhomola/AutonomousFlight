/** @file
 *  @brief PPRZLink message header for INS_EKF2_EXT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_EKF2_EXT_H_
#define _VAR_MESSAGES_telemetry_INS_EKF2_EXT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS_EKF2_EXT 170
#define PPRZ_MSG_ID_INS_EKF2_EXT 170

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS_EKF2_EXT _send_msg(INS_EKF2_EXT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS_EKF2_EXT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _gps_drift_h Horizontal position drift rate (m/s)
 * @param _gps_drift_v Vertical position drift rate (m/s)
 * @param _gps_drift_h_filt Filtered horizontal velocity (m/s)
 * @param _gps_drift_blocked The GPS drift calculation is blocked
 * @param _gyro_vibe_coning Gyro delta angle coning metric = filtered length of (delta_angle x prev_delta_angle)
 * @param _gyro_vibe_hf Gyro high frequency vibe = filtered length of (delta_angle - prev_delta_angle)
 * @param _accel_vibe_hf Accel high frequency vibe = filtered length of (delta_velocity - prev_delta_velocity)
 */
static inline void pprzlink_msg_v2_send_INS_EKF2_EXT(struct pprzlink_msg * msg, float *_gps_drift_h, float *_gps_drift_v, float *_gps_drift_h_filt, uint8_t *_gps_drift_blocked, float *_gyro_vibe_coning, float *_gyro_vibe_hf, float *_accel_vibe_hf) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS_EKF2_EXT, "INS_EKF2_EXT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gps_drift_h, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gps_drift_v, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gps_drift_h_filt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gps_drift_blocked, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gyro_vibe_coning, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gyro_vibe_hf, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accel_vibe_hf, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS_EKF2_EXT pprz_msg_send_INS_EKF2_EXT
#define DOWNLINK_SEND_INS_EKF2_EXT(_trans, _dev, gps_drift_h, gps_drift_v, gps_drift_h_filt, gps_drift_blocked, gyro_vibe_coning, gyro_vibe_hf, accel_vibe_hf) pprz_msg_send_INS_EKF2_EXT(&((_trans).trans_tx), &((_dev).device), AC_ID, gps_drift_h, gps_drift_v, gps_drift_h_filt, gps_drift_blocked, gyro_vibe_coning, gyro_vibe_hf, accel_vibe_hf)
/**
 * Sends a INS_EKF2_EXT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _gps_drift_h Horizontal position drift rate (m/s)
 * @param _gps_drift_v Vertical position drift rate (m/s)
 * @param _gps_drift_h_filt Filtered horizontal velocity (m/s)
 * @param _gps_drift_blocked The GPS drift calculation is blocked
 * @param _gyro_vibe_coning Gyro delta angle coning metric = filtered length of (delta_angle x prev_delta_angle)
 * @param _gyro_vibe_hf Gyro high frequency vibe = filtered length of (delta_angle - prev_delta_angle)
 * @param _accel_vibe_hf Accel high frequency vibe = filtered length of (delta_velocity - prev_delta_velocity)
 */
static inline void pprz_msg_send_INS_EKF2_EXT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_gps_drift_h, float *_gps_drift_v, float *_gps_drift_h_filt, uint8_t *_gps_drift_blocked, float *_gyro_vibe_coning, float *_gyro_vibe_hf, float *_accel_vibe_hf) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS_EKF2_EXT(&msg,_gps_drift_h,_gps_drift_v,_gps_drift_h_filt,_gps_drift_blocked,_gyro_vibe_coning,_gyro_vibe_hf,_accel_vibe_hf);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS_EKF2_EXT(_trans, _dev, gps_drift_h, gps_drift_v, gps_drift_h_filt, gps_drift_blocked, gyro_vibe_coning, gyro_vibe_hf, accel_vibe_hf) {}
static inline void pprz_send_msg_INS_EKF2_EXT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_gps_drift_h __attribute__((unused)), float *_gps_drift_v __attribute__((unused)), float *_gps_drift_h_filt __attribute__((unused)), uint8_t *_gps_drift_blocked __attribute__((unused)), float *_gyro_vibe_coning __attribute__((unused)), float *_gyro_vibe_hf __attribute__((unused)), float *_accel_vibe_hf __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field gps_drift_h in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Horizontal position drift rate (m/s)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_gps_drift_h(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field gps_drift_v in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Vertical position drift rate (m/s)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_gps_drift_v(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field gps_drift_h_filt in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Filtered horizontal velocity (m/s)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_gps_drift_h_filt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field gps_drift_blocked in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return The GPS drift calculation is blocked
  */
static inline uint8_t pprzlink_get_DL_INS_EKF2_EXT_gps_drift_blocked(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/** Getter for field gyro_vibe_coning in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Gyro delta angle coning metric = filtered length of (delta_angle x prev_delta_angle)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_gyro_vibe_coning(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 17);
}


/** Getter for field gyro_vibe_hf in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Gyro high frequency vibe = filtered length of (delta_angle - prev_delta_angle)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_gyro_vibe_hf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 21);
}


/** Getter for field accel_vibe_hf in message INS_EKF2_EXT
  *
  * @param _payload : a pointer to the INS_EKF2_EXT message
  * @return Accel high frequency vibe = filtered length of (delta_velocity - prev_delta_velocity)
  */
static inline float pprzlink_get_DL_INS_EKF2_EXT_accel_vibe_hf(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 25);
}


/* Compatibility macros */
#define DL_INS_EKF2_EXT_gps_drift_h(_payload) pprzlink_get_DL_INS_EKF2_EXT_gps_drift_h(_payload)
#define DL_INS_EKF2_EXT_gps_drift_v(_payload) pprzlink_get_DL_INS_EKF2_EXT_gps_drift_v(_payload)
#define DL_INS_EKF2_EXT_gps_drift_h_filt(_payload) pprzlink_get_DL_INS_EKF2_EXT_gps_drift_h_filt(_payload)
#define DL_INS_EKF2_EXT_gps_drift_blocked(_payload) pprzlink_get_DL_INS_EKF2_EXT_gps_drift_blocked(_payload)
#define DL_INS_EKF2_EXT_gyro_vibe_coning(_payload) pprzlink_get_DL_INS_EKF2_EXT_gyro_vibe_coning(_payload)
#define DL_INS_EKF2_EXT_gyro_vibe_hf(_payload) pprzlink_get_DL_INS_EKF2_EXT_gyro_vibe_hf(_payload)
#define DL_INS_EKF2_EXT_accel_vibe_hf(_payload) pprzlink_get_DL_INS_EKF2_EXT_accel_vibe_hf(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_EKF2_EXT_H_

