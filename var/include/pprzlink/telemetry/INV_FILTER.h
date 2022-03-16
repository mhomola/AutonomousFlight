/** @file
 *  @brief PPRZLink message header for INV_FILTER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INV_FILTER_H_
#define _VAR_MESSAGES_telemetry_INV_FILTER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INV_FILTER 78
#define PPRZ_MSG_ID_INV_FILTER 78

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INV_FILTER _send_msg(INV_FILTER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INV_FILTER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _quat 
 * @param _phi_inv 
 * @param _theta_inv 
 * @param _psi_inv 
 * @param _Vx_inv 
 * @param _Vy_inv 
 * @param _Vz_inv 
 * @param _Px_inv 
 * @param _Py_inv 
 * @param _Pz_inv 
 * @param _bias_phi 
 * @param _bias_theta 
 * @param _bias_psi 
 * @param _bias_as 
 * @param _bias_hb 
 * @param _meas_baro 
 * @param _meas_gps 
 */
static inline void pprzlink_msg_v2_send_INV_FILTER(struct pprzlink_msg * msg, float *_quat, float *_phi_inv, float *_theta_inv, float *_psi_inv, float *_Vx_inv, float *_Vy_inv, float *_Vz_inv, float *_Px_inv, float *_Py_inv, float *_Pz_inv, float *_bias_phi, float *_bias_theta, float *_bias_psi, float *_bias_as, float *_bias_hb, float *_meas_baro, float *_meas_gps) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INV_FILTER, "INV_FILTER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _quat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Vx_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Vy_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Vz_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Px_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Py_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pz_inv, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias_as, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias_hb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _meas_baro, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _meas_gps, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INV_FILTER pprz_msg_send_INV_FILTER
#define DOWNLINK_SEND_INV_FILTER(_trans, _dev, quat, phi_inv, theta_inv, psi_inv, Vx_inv, Vy_inv, Vz_inv, Px_inv, Py_inv, Pz_inv, bias_phi, bias_theta, bias_psi, bias_as, bias_hb, meas_baro, meas_gps) pprz_msg_send_INV_FILTER(&((_trans).trans_tx), &((_dev).device), AC_ID, quat, phi_inv, theta_inv, psi_inv, Vx_inv, Vy_inv, Vz_inv, Px_inv, Py_inv, Pz_inv, bias_phi, bias_theta, bias_psi, bias_as, bias_hb, meas_baro, meas_gps)
/**
 * Sends a INV_FILTER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _quat 
 * @param _phi_inv 
 * @param _theta_inv 
 * @param _psi_inv 
 * @param _Vx_inv 
 * @param _Vy_inv 
 * @param _Vz_inv 
 * @param _Px_inv 
 * @param _Py_inv 
 * @param _Pz_inv 
 * @param _bias_phi 
 * @param _bias_theta 
 * @param _bias_psi 
 * @param _bias_as 
 * @param _bias_hb 
 * @param _meas_baro 
 * @param _meas_gps 
 */
static inline void pprz_msg_send_INV_FILTER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_quat, float *_phi_inv, float *_theta_inv, float *_psi_inv, float *_Vx_inv, float *_Vy_inv, float *_Vz_inv, float *_Px_inv, float *_Py_inv, float *_Pz_inv, float *_bias_phi, float *_bias_theta, float *_bias_psi, float *_bias_as, float *_bias_hb, float *_meas_baro, float *_meas_gps) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INV_FILTER(&msg,_quat,_phi_inv,_theta_inv,_psi_inv,_Vx_inv,_Vy_inv,_Vz_inv,_Px_inv,_Py_inv,_Pz_inv,_bias_phi,_bias_theta,_bias_psi,_bias_as,_bias_hb,_meas_baro,_meas_gps);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INV_FILTER(_trans, _dev, quat, phi_inv, theta_inv, psi_inv, Vx_inv, Vy_inv, Vz_inv, Px_inv, Py_inv, Pz_inv, bias_phi, bias_theta, bias_psi, bias_as, bias_hb, meas_baro, meas_gps) {}
static inline void pprz_send_msg_INV_FILTER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_quat __attribute__((unused)), float *_phi_inv __attribute__((unused)), float *_theta_inv __attribute__((unused)), float *_psi_inv __attribute__((unused)), float *_Vx_inv __attribute__((unused)), float *_Vy_inv __attribute__((unused)), float *_Vz_inv __attribute__((unused)), float *_Px_inv __attribute__((unused)), float *_Py_inv __attribute__((unused)), float *_Pz_inv __attribute__((unused)), float *_bias_phi __attribute__((unused)), float *_bias_theta __attribute__((unused)), float *_bias_psi __attribute__((unused)), float *_bias_as __attribute__((unused)), float *_bias_hb __attribute__((unused)), float *_meas_baro __attribute__((unused)), float *_meas_gps __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field quat in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_quat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field phi_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_phi_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field theta_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_theta_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field psi_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_psi_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field Vx_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Vx_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field Vy_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Vy_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field Vz_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Vz_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field Px_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Px_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field Py_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Py_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field Pz_inv in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_Pz_inv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field bias_phi in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_bias_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field bias_theta in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_bias_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field bias_psi in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_bias_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field bias_as in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_bias_as(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field bias_hb in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_bias_hb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field meas_baro in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_meas_baro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/** Getter for field meas_gps in message INV_FILTER
  *
  * @param _payload : a pointer to the INV_FILTER message
  * @return 
  */
static inline float pprzlink_get_DL_INV_FILTER_meas_gps(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/* Compatibility macros */
#define DL_INV_FILTER_quat(_payload) pprzlink_get_DL_INV_FILTER_quat(_payload)
#define DL_INV_FILTER_phi_inv(_payload) pprzlink_get_DL_INV_FILTER_phi_inv(_payload)
#define DL_INV_FILTER_theta_inv(_payload) pprzlink_get_DL_INV_FILTER_theta_inv(_payload)
#define DL_INV_FILTER_psi_inv(_payload) pprzlink_get_DL_INV_FILTER_psi_inv(_payload)
#define DL_INV_FILTER_Vx_inv(_payload) pprzlink_get_DL_INV_FILTER_Vx_inv(_payload)
#define DL_INV_FILTER_Vy_inv(_payload) pprzlink_get_DL_INV_FILTER_Vy_inv(_payload)
#define DL_INV_FILTER_Vz_inv(_payload) pprzlink_get_DL_INV_FILTER_Vz_inv(_payload)
#define DL_INV_FILTER_Px_inv(_payload) pprzlink_get_DL_INV_FILTER_Px_inv(_payload)
#define DL_INV_FILTER_Py_inv(_payload) pprzlink_get_DL_INV_FILTER_Py_inv(_payload)
#define DL_INV_FILTER_Pz_inv(_payload) pprzlink_get_DL_INV_FILTER_Pz_inv(_payload)
#define DL_INV_FILTER_bias_phi(_payload) pprzlink_get_DL_INV_FILTER_bias_phi(_payload)
#define DL_INV_FILTER_bias_theta(_payload) pprzlink_get_DL_INV_FILTER_bias_theta(_payload)
#define DL_INV_FILTER_bias_psi(_payload) pprzlink_get_DL_INV_FILTER_bias_psi(_payload)
#define DL_INV_FILTER_bias_as(_payload) pprzlink_get_DL_INV_FILTER_bias_as(_payload)
#define DL_INV_FILTER_bias_hb(_payload) pprzlink_get_DL_INV_FILTER_bias_hb(_payload)
#define DL_INV_FILTER_meas_baro(_payload) pprzlink_get_DL_INV_FILTER_meas_baro(_payload)
#define DL_INV_FILTER_meas_gps(_payload) pprzlink_get_DL_INV_FILTER_meas_gps(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INV_FILTER_H_

