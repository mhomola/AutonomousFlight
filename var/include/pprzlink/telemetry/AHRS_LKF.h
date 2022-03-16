/** @file
 *  @brief PPRZLink message header for AHRS_LKF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AHRS_LKF_H_
#define _VAR_MESSAGES_telemetry_AHRS_LKF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AHRS_LKF 193
#define PPRZ_MSG_ID_AHRS_LKF 193

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AHRS_LKF _send_msg(AHRS_LKF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AHRS_LKF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _qi 
 * @param _qx 
 * @param _qy 
 * @param _qz 
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _mx 
 * @param _my 
 * @param _mz 
 */
static inline void pprzlink_msg_v2_send_AHRS_LKF(struct pprzlink_msg * msg, float *_phi, float *_theta, float *_psi, float *_qi, float *_qx, float *_qy, float *_qz, float *_p, float *_q, float *_r, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AHRS_LKF, "AHRS_LKF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _qi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _qx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _qy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _qz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ax, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ay, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _az, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _my, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AHRS_LKF pprz_msg_send_AHRS_LKF
#define DOWNLINK_SEND_AHRS_LKF(_trans, _dev, phi, theta, psi, qi, qx, qy, qz, p, q, r, ax, ay, az, mx, my, mz) pprz_msg_send_AHRS_LKF(&((_trans).trans_tx), &((_dev).device), AC_ID, phi, theta, psi, qi, qx, qy, qz, p, q, r, ax, ay, az, mx, my, mz)
/**
 * Sends a AHRS_LKF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _qi 
 * @param _qx 
 * @param _qy 
 * @param _qz 
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _mx 
 * @param _my 
 * @param _mz 
 */
static inline void pprz_msg_send_AHRS_LKF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_phi, float *_theta, float *_psi, float *_qi, float *_qx, float *_qy, float *_qz, float *_p, float *_q, float *_r, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AHRS_LKF(&msg,_phi,_theta,_psi,_qi,_qx,_qy,_qz,_p,_q,_r,_ax,_ay,_az,_mx,_my,_mz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AHRS_LKF(_trans, _dev, phi, theta, psi, qi, qx, qy, qz, p, q, r, ax, ay, az, mx, my, mz) {}
static inline void pprz_send_msg_AHRS_LKF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_phi __attribute__((unused)), float *_theta __attribute__((unused)), float *_psi __attribute__((unused)), float *_qi __attribute__((unused)), float *_qx __attribute__((unused)), float *_qy __attribute__((unused)), float *_qz __attribute__((unused)), float *_p __attribute__((unused)), float *_q __attribute__((unused)), float *_r __attribute__((unused)), float *_ax __attribute__((unused)), float *_ay __attribute__((unused)), float *_az __attribute__((unused)), float *_mx __attribute__((unused)), float *_my __attribute__((unused)), float *_mz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field phi in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field theta in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field psi in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field qi in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_qi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field qx in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_qx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field qy in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_qy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field qz in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_qz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field p in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field q in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field r in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field ax in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field ay in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field az in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field mx in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_mx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field my in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_my(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field mz in message AHRS_LKF
  *
  * @param _payload : a pointer to the AHRS_LKF message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_LKF_mz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/* Compatibility macros */
#define DL_AHRS_LKF_phi(_payload) pprzlink_get_DL_AHRS_LKF_phi(_payload)
#define DL_AHRS_LKF_theta(_payload) pprzlink_get_DL_AHRS_LKF_theta(_payload)
#define DL_AHRS_LKF_psi(_payload) pprzlink_get_DL_AHRS_LKF_psi(_payload)
#define DL_AHRS_LKF_qi(_payload) pprzlink_get_DL_AHRS_LKF_qi(_payload)
#define DL_AHRS_LKF_qx(_payload) pprzlink_get_DL_AHRS_LKF_qx(_payload)
#define DL_AHRS_LKF_qy(_payload) pprzlink_get_DL_AHRS_LKF_qy(_payload)
#define DL_AHRS_LKF_qz(_payload) pprzlink_get_DL_AHRS_LKF_qz(_payload)
#define DL_AHRS_LKF_p(_payload) pprzlink_get_DL_AHRS_LKF_p(_payload)
#define DL_AHRS_LKF_q(_payload) pprzlink_get_DL_AHRS_LKF_q(_payload)
#define DL_AHRS_LKF_r(_payload) pprzlink_get_DL_AHRS_LKF_r(_payload)
#define DL_AHRS_LKF_ax(_payload) pprzlink_get_DL_AHRS_LKF_ax(_payload)
#define DL_AHRS_LKF_ay(_payload) pprzlink_get_DL_AHRS_LKF_ay(_payload)
#define DL_AHRS_LKF_az(_payload) pprzlink_get_DL_AHRS_LKF_az(_payload)
#define DL_AHRS_LKF_mx(_payload) pprzlink_get_DL_AHRS_LKF_mx(_payload)
#define DL_AHRS_LKF_my(_payload) pprzlink_get_DL_AHRS_LKF_my(_payload)
#define DL_AHRS_LKF_mz(_payload) pprzlink_get_DL_AHRS_LKF_mz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AHRS_LKF_H_

