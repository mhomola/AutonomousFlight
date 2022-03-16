/** @file
 *  @brief PPRZLink message header for AHRS_BIAS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AHRS_BIAS_H_
#define _VAR_MESSAGES_telemetry_AHRS_BIAS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AHRS_BIAS 171
#define PPRZ_MSG_ID_AHRS_BIAS 171

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AHRS_BIAS _send_msg(AHRS_BIAS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AHRS_BIAS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _accel_x Accelerometer bias x-axis
 * @param _accel_y Accelerometer bias y-axis
 * @param _accel_z Accelerometer bias z-axis
 * @param _gyro_p Gyrometer bias roll rate
 * @param _gyro_q Gyrometer bias pitch rate
 * @param _gyro_r Gyrometer bias yaw rate
 * @param _mag_x Magnetometer x-bias in mGauss
 * @param _mag_y Magnetometer y-bias in mGauss
 * @param _mag_z Magnetometer z-bias in mGauss
 */
static inline void pprzlink_msg_v2_send_AHRS_BIAS(struct pprzlink_msg * msg, float *_accel_x, float *_accel_y, float *_accel_z, float *_gyro_p, float *_gyro_q, float *_gyro_r, float *_mag_x, float *_mag_y, float *_mag_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AHRS_BIAS, "AHRS_BIAS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accel_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accel_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accel_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gyro_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gyro_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gyro_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_z, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AHRS_BIAS pprz_msg_send_AHRS_BIAS
#define DOWNLINK_SEND_AHRS_BIAS(_trans, _dev, accel_x, accel_y, accel_z, gyro_p, gyro_q, gyro_r, mag_x, mag_y, mag_z) pprz_msg_send_AHRS_BIAS(&((_trans).trans_tx), &((_dev).device), AC_ID, accel_x, accel_y, accel_z, gyro_p, gyro_q, gyro_r, mag_x, mag_y, mag_z)
/**
 * Sends a AHRS_BIAS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _accel_x Accelerometer bias x-axis
 * @param _accel_y Accelerometer bias y-axis
 * @param _accel_z Accelerometer bias z-axis
 * @param _gyro_p Gyrometer bias roll rate
 * @param _gyro_q Gyrometer bias pitch rate
 * @param _gyro_r Gyrometer bias yaw rate
 * @param _mag_x Magnetometer x-bias in mGauss
 * @param _mag_y Magnetometer y-bias in mGauss
 * @param _mag_z Magnetometer z-bias in mGauss
 */
static inline void pprz_msg_send_AHRS_BIAS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_accel_x, float *_accel_y, float *_accel_z, float *_gyro_p, float *_gyro_q, float *_gyro_r, float *_mag_x, float *_mag_y, float *_mag_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AHRS_BIAS(&msg,_accel_x,_accel_y,_accel_z,_gyro_p,_gyro_q,_gyro_r,_mag_x,_mag_y,_mag_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AHRS_BIAS(_trans, _dev, accel_x, accel_y, accel_z, gyro_p, gyro_q, gyro_r, mag_x, mag_y, mag_z) {}
static inline void pprz_send_msg_AHRS_BIAS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_accel_x __attribute__((unused)), float *_accel_y __attribute__((unused)), float *_accel_z __attribute__((unused)), float *_gyro_p __attribute__((unused)), float *_gyro_q __attribute__((unused)), float *_gyro_r __attribute__((unused)), float *_mag_x __attribute__((unused)), float *_mag_y __attribute__((unused)), float *_mag_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field accel_x in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Accelerometer bias x-axis
  */
static inline float pprzlink_get_DL_AHRS_BIAS_accel_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field accel_y in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Accelerometer bias y-axis
  */
static inline float pprzlink_get_DL_AHRS_BIAS_accel_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field accel_z in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Accelerometer bias z-axis
  */
static inline float pprzlink_get_DL_AHRS_BIAS_accel_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field gyro_p in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Gyrometer bias roll rate
  */
static inline float pprzlink_get_DL_AHRS_BIAS_gyro_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field gyro_q in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Gyrometer bias pitch rate
  */
static inline float pprzlink_get_DL_AHRS_BIAS_gyro_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field gyro_r in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Gyrometer bias yaw rate
  */
static inline float pprzlink_get_DL_AHRS_BIAS_gyro_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field mag_x in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Magnetometer x-bias in mGauss
  */
static inline float pprzlink_get_DL_AHRS_BIAS_mag_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field mag_y in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Magnetometer y-bias in mGauss
  */
static inline float pprzlink_get_DL_AHRS_BIAS_mag_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field mag_z in message AHRS_BIAS
  *
  * @param _payload : a pointer to the AHRS_BIAS message
  * @return Magnetometer z-bias in mGauss
  */
static inline float pprzlink_get_DL_AHRS_BIAS_mag_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/* Compatibility macros */
#define DL_AHRS_BIAS_accel_x(_payload) pprzlink_get_DL_AHRS_BIAS_accel_x(_payload)
#define DL_AHRS_BIAS_accel_y(_payload) pprzlink_get_DL_AHRS_BIAS_accel_y(_payload)
#define DL_AHRS_BIAS_accel_z(_payload) pprzlink_get_DL_AHRS_BIAS_accel_z(_payload)
#define DL_AHRS_BIAS_gyro_p(_payload) pprzlink_get_DL_AHRS_BIAS_gyro_p(_payload)
#define DL_AHRS_BIAS_gyro_q(_payload) pprzlink_get_DL_AHRS_BIAS_gyro_q(_payload)
#define DL_AHRS_BIAS_gyro_r(_payload) pprzlink_get_DL_AHRS_BIAS_gyro_r(_payload)
#define DL_AHRS_BIAS_mag_x(_payload) pprzlink_get_DL_AHRS_BIAS_mag_x(_payload)
#define DL_AHRS_BIAS_mag_y(_payload) pprzlink_get_DL_AHRS_BIAS_mag_y(_payload)
#define DL_AHRS_BIAS_mag_z(_payload) pprzlink_get_DL_AHRS_BIAS_mag_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AHRS_BIAS_H_

