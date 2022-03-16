/** @file
 *  @brief PPRZLink message header for SMARTPROBE in class datalink
 *
 *  
        Data from SmartProbe 5-hole probe sensor for wind and turbulence measurements
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_SMARTPROBE_H_
#define _VAR_MESSAGES_datalink_SMARTPROBE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SMARTPROBE 60
#define PPRZ_MSG_ID_SMARTPROBE 60

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SMARTPROBE _send_msg(SMARTPROBE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SMARTPROBE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _accel internal accelerometer
 * @param _gyro internal gyrometer
 * @param _attitude attitude in normalized quaternion or euler in radians (when last field is lower than -2)
 * @param _tas true airspeed
 * @param _eas equivalent airspeed
 * @param _alpha angle of attack
 * @param _beta angle of sideslip
 * @param _pressure static absolute pressure
 * @param _temperature static temperature
 * @param _rho air density
 * @param _p_diff_C_raw raw differential pressure for central sensor
 * @param _t_diff_C_raw raw temperature for central sensor
 * @param _p_diff_H_raw raw differential pressure for horizontal sensor
 * @param _t_diff_H_raw raw temperature for horizontal sensor
 * @param _p_diff_V_raw raw differential pressure for vertical sensor
 * @param _t_diff_V_raw raw temperature for vertical sensor
 */
static inline void pprzlink_msg_v2_send_SMARTPROBE(struct pprzlink_msg * msg, float *_accel, float *_gyro, float *_attitude, float *_tas, float *_eas, float *_alpha, float *_beta, float *_pressure, float *_temperature, float *_rho, float *_p_diff_C_raw, float *_t_diff_C_raw, float *_p_diff_H_raw, float *_t_diff_H_raw, float *_p_diff_V_raw, float *_t_diff_V_raw) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+3*4+3*4+4*4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+3*4+3*4+4*4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SMARTPROBE, "SMARTPROBE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _accel, 3*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _gyro, 3*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _attitude, 4*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _tas, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _eas, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alpha, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _beta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temperature, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rho, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p_diff_C_raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _t_diff_C_raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p_diff_H_raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _t_diff_H_raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p_diff_V_raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _t_diff_V_raw, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SMARTPROBE pprz_msg_send_SMARTPROBE
#define DOWNLINK_SEND_SMARTPROBE(_trans, _dev, accel, gyro, attitude, tas, eas, alpha, beta, pressure, temperature, rho, p_diff_C_raw, t_diff_C_raw, p_diff_H_raw, t_diff_H_raw, p_diff_V_raw, t_diff_V_raw) pprz_msg_send_SMARTPROBE(&((_trans).trans_tx), &((_dev).device), AC_ID, accel, gyro, attitude, tas, eas, alpha, beta, pressure, temperature, rho, p_diff_C_raw, t_diff_C_raw, p_diff_H_raw, t_diff_H_raw, p_diff_V_raw, t_diff_V_raw)
/**
 * Sends a SMARTPROBE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _accel internal accelerometer
 * @param _gyro internal gyrometer
 * @param _attitude attitude in normalized quaternion or euler in radians (when last field is lower than -2)
 * @param _tas true airspeed
 * @param _eas equivalent airspeed
 * @param _alpha angle of attack
 * @param _beta angle of sideslip
 * @param _pressure static absolute pressure
 * @param _temperature static temperature
 * @param _rho air density
 * @param _p_diff_C_raw raw differential pressure for central sensor
 * @param _t_diff_C_raw raw temperature for central sensor
 * @param _p_diff_H_raw raw differential pressure for horizontal sensor
 * @param _t_diff_H_raw raw temperature for horizontal sensor
 * @param _p_diff_V_raw raw differential pressure for vertical sensor
 * @param _t_diff_V_raw raw temperature for vertical sensor
 */
static inline void pprz_msg_send_SMARTPROBE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_accel, float *_gyro, float *_attitude, float *_tas, float *_eas, float *_alpha, float *_beta, float *_pressure, float *_temperature, float *_rho, float *_p_diff_C_raw, float *_t_diff_C_raw, float *_p_diff_H_raw, float *_t_diff_H_raw, float *_p_diff_V_raw, float *_t_diff_V_raw) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SMARTPROBE(&msg,_accel,_gyro,_attitude,_tas,_eas,_alpha,_beta,_pressure,_temperature,_rho,_p_diff_C_raw,_t_diff_C_raw,_p_diff_H_raw,_t_diff_H_raw,_p_diff_V_raw,_t_diff_V_raw);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SMARTPROBE(_trans, _dev, accel, gyro, attitude, tas, eas, alpha, beta, pressure, temperature, rho, p_diff_C_raw, t_diff_C_raw, p_diff_H_raw, t_diff_H_raw, p_diff_V_raw, t_diff_V_raw) {}
static inline void pprz_send_msg_SMARTPROBE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_accel __attribute__((unused)), float *_gyro __attribute__((unused)), float *_attitude __attribute__((unused)), float *_tas __attribute__((unused)), float *_eas __attribute__((unused)), float *_alpha __attribute__((unused)), float *_beta __attribute__((unused)), float *_pressure __attribute__((unused)), float *_temperature __attribute__((unused)), float *_rho __attribute__((unused)), float *_p_diff_C_raw __attribute__((unused)), float *_t_diff_C_raw __attribute__((unused)), float *_p_diff_H_raw __attribute__((unused)), float *_t_diff_H_raw __attribute__((unused)), float *_p_diff_V_raw __attribute__((unused)), float *_t_diff_V_raw __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array accel in message SMARTPROBE
 *
 * @return accel : internal accelerometer
 */
 static inline uint8_t pprzlink_get_SMARTPROBE_accel_length(void* _payload __attribute__ ((unused))) {
    return 3;
}

/** Getter for field accel in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return internal accelerometer
  */
static inline float * pprzlink_get_DL_SMARTPROBE_accel(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 4);
}

/** Getter for length of array gyro in message SMARTPROBE
 *
 * @return gyro : internal gyrometer
 */
 static inline uint8_t pprzlink_get_SMARTPROBE_gyro_length(void* _payload __attribute__ ((unused))) {
    return 3;
}

/** Getter for field gyro in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return internal gyrometer
  */
static inline float * pprzlink_get_DL_SMARTPROBE_gyro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 16);
}

/** Getter for length of array attitude in message SMARTPROBE
 *
 * @return attitude : attitude in normalized quaternion or euler in radians (when last field is lower than -2)
 */
 static inline uint8_t pprzlink_get_SMARTPROBE_attitude_length(void* _payload __attribute__ ((unused))) {
    return 4;
}

/** Getter for field attitude in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return attitude in normalized quaternion or euler in radians (when last field is lower than -2)
  */
static inline float * pprzlink_get_DL_SMARTPROBE_attitude(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 28);
}


/** Getter for field tas in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return true airspeed
  */
static inline float pprzlink_get_DL_SMARTPROBE_tas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field eas in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return equivalent airspeed
  */
static inline float pprzlink_get_DL_SMARTPROBE_eas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field alpha in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return angle of attack
  */
static inline float pprzlink_get_DL_SMARTPROBE_alpha(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field beta in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return angle of sideslip
  */
static inline float pprzlink_get_DL_SMARTPROBE_beta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field pressure in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return static absolute pressure
  */
static inline float pprzlink_get_DL_SMARTPROBE_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field temperature in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return static temperature
  */
static inline float pprzlink_get_DL_SMARTPROBE_temperature(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/** Getter for field rho in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return air density
  */
static inline float pprzlink_get_DL_SMARTPROBE_rho(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/** Getter for field p_diff_C_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw differential pressure for central sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_p_diff_C_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 72);
}


/** Getter for field t_diff_C_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw temperature for central sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_t_diff_C_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 76);
}


/** Getter for field p_diff_H_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw differential pressure for horizontal sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_p_diff_H_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 80);
}


/** Getter for field t_diff_H_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw temperature for horizontal sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_t_diff_H_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 84);
}


/** Getter for field p_diff_V_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw differential pressure for vertical sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_p_diff_V_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 88);
}


/** Getter for field t_diff_V_raw in message SMARTPROBE
  *
  * @param _payload : a pointer to the SMARTPROBE message
  * @return raw temperature for vertical sensor
  */
static inline float pprzlink_get_DL_SMARTPROBE_t_diff_V_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 92);
}


/* Compatibility macros */
#define DL_SMARTPROBE_accel_length(_payload) pprzlink_get_SMARTPROBE_accel_length(_payload)
#define DL_SMARTPROBE_accel(_payload) pprzlink_get_DL_SMARTPROBE_accel(_payload)
#define DL_SMARTPROBE_gyro_length(_payload) pprzlink_get_SMARTPROBE_gyro_length(_payload)
#define DL_SMARTPROBE_gyro(_payload) pprzlink_get_DL_SMARTPROBE_gyro(_payload)
#define DL_SMARTPROBE_attitude_length(_payload) pprzlink_get_SMARTPROBE_attitude_length(_payload)
#define DL_SMARTPROBE_attitude(_payload) pprzlink_get_DL_SMARTPROBE_attitude(_payload)
#define DL_SMARTPROBE_tas(_payload) pprzlink_get_DL_SMARTPROBE_tas(_payload)
#define DL_SMARTPROBE_eas(_payload) pprzlink_get_DL_SMARTPROBE_eas(_payload)
#define DL_SMARTPROBE_alpha(_payload) pprzlink_get_DL_SMARTPROBE_alpha(_payload)
#define DL_SMARTPROBE_beta(_payload) pprzlink_get_DL_SMARTPROBE_beta(_payload)
#define DL_SMARTPROBE_pressure(_payload) pprzlink_get_DL_SMARTPROBE_pressure(_payload)
#define DL_SMARTPROBE_temperature(_payload) pprzlink_get_DL_SMARTPROBE_temperature(_payload)
#define DL_SMARTPROBE_rho(_payload) pprzlink_get_DL_SMARTPROBE_rho(_payload)
#define DL_SMARTPROBE_p_diff_C_raw(_payload) pprzlink_get_DL_SMARTPROBE_p_diff_C_raw(_payload)
#define DL_SMARTPROBE_t_diff_C_raw(_payload) pprzlink_get_DL_SMARTPROBE_t_diff_C_raw(_payload)
#define DL_SMARTPROBE_p_diff_H_raw(_payload) pprzlink_get_DL_SMARTPROBE_p_diff_H_raw(_payload)
#define DL_SMARTPROBE_t_diff_H_raw(_payload) pprzlink_get_DL_SMARTPROBE_t_diff_H_raw(_payload)
#define DL_SMARTPROBE_p_diff_V_raw(_payload) pprzlink_get_DL_SMARTPROBE_p_diff_V_raw(_payload)
#define DL_SMARTPROBE_t_diff_V_raw(_payload) pprzlink_get_DL_SMARTPROBE_t_diff_V_raw(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_SMARTPROBE_H_

