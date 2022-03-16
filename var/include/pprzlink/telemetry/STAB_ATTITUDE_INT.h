/** @file
 *  @brief PPRZLink message header for STAB_ATTITUDE_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INT_H_
#define _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STAB_ATTITUDE_INT 140
#define PPRZ_MSG_ID_STAB_ATTITUDE_INT 140

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STAB_ATTITUDE_INT _send_msg(STAB_ATTITUDE_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STAB_ATTITUDE_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _est_p 
 * @param _est_q 
 * @param _est_r 
 * @param _est_phi 
 * @param _est_theta 
 * @param _est_psi 
 * @param _sp_phi 
 * @param _sp_theta 
 * @param _sp_psi 
 * @param _sum_err_phi 
 * @param _sum_err_theta 
 * @param _sum_err_psi 
 * @param _delta_a_fb 
 * @param _delta_e_fb 
 * @param _delta_r_fb 
 * @param _delta_a_ff 
 * @param _delta_e_ff 
 * @param _delta_r_ff 
 * @param _delta_a 
 * @param _delta_e 
 * @param _delta_r 
 */
static inline void pprzlink_msg_v2_send_STAB_ATTITUDE_INT(struct pprzlink_msg * msg, int32_t *_est_p, int32_t *_est_q, int32_t *_est_r, int32_t *_est_phi, int32_t *_est_theta, int32_t *_est_psi, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_sum_err_phi, int32_t *_sum_err_theta, int32_t *_sum_err_psi, int32_t *_delta_a_fb, int32_t *_delta_e_fb, int32_t *_delta_r_fb, int32_t *_delta_a_ff, int32_t *_delta_e_ff, int32_t *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STAB_ATTITUDE_INT, "STAB_ATTITUDE_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sum_err_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sum_err_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sum_err_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_a_fb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_e_fb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_r_fb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_a_ff, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_e_ff, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_r_ff, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_a, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_e, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_r, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STAB_ATTITUDE_INT pprz_msg_send_STAB_ATTITUDE_INT
#define DOWNLINK_SEND_STAB_ATTITUDE_INT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, sp_phi, sp_theta, sp_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r) pprz_msg_send_STAB_ATTITUDE_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, est_p, est_q, est_r, est_phi, est_theta, est_psi, sp_phi, sp_theta, sp_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r)
/**
 * Sends a STAB_ATTITUDE_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _est_p 
 * @param _est_q 
 * @param _est_r 
 * @param _est_phi 
 * @param _est_theta 
 * @param _est_psi 
 * @param _sp_phi 
 * @param _sp_theta 
 * @param _sp_psi 
 * @param _sum_err_phi 
 * @param _sum_err_theta 
 * @param _sum_err_psi 
 * @param _delta_a_fb 
 * @param _delta_e_fb 
 * @param _delta_r_fb 
 * @param _delta_a_ff 
 * @param _delta_e_ff 
 * @param _delta_r_ff 
 * @param _delta_a 
 * @param _delta_e 
 * @param _delta_r 
 */
static inline void pprz_msg_send_STAB_ATTITUDE_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_est_p, int32_t *_est_q, int32_t *_est_r, int32_t *_est_phi, int32_t *_est_theta, int32_t *_est_psi, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_sum_err_phi, int32_t *_sum_err_theta, int32_t *_sum_err_psi, int32_t *_delta_a_fb, int32_t *_delta_e_fb, int32_t *_delta_r_fb, int32_t *_delta_a_ff, int32_t *_delta_e_ff, int32_t *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STAB_ATTITUDE_INT(&msg,_est_p,_est_q,_est_r,_est_phi,_est_theta,_est_psi,_sp_phi,_sp_theta,_sp_psi,_sum_err_phi,_sum_err_theta,_sum_err_psi,_delta_a_fb,_delta_e_fb,_delta_r_fb,_delta_a_ff,_delta_e_ff,_delta_r_ff,_delta_a,_delta_e,_delta_r);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STAB_ATTITUDE_INT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, sp_phi, sp_theta, sp_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r) {}
static inline void pprz_send_msg_STAB_ATTITUDE_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_est_p __attribute__((unused)), int32_t *_est_q __attribute__((unused)), int32_t *_est_r __attribute__((unused)), int32_t *_est_phi __attribute__((unused)), int32_t *_est_theta __attribute__((unused)), int32_t *_est_psi __attribute__((unused)), int32_t *_sp_phi __attribute__((unused)), int32_t *_sp_theta __attribute__((unused)), int32_t *_sp_psi __attribute__((unused)), int32_t *_sum_err_phi __attribute__((unused)), int32_t *_sum_err_theta __attribute__((unused)), int32_t *_sum_err_psi __attribute__((unused)), int32_t *_delta_a_fb __attribute__((unused)), int32_t *_delta_e_fb __attribute__((unused)), int32_t *_delta_r_fb __attribute__((unused)), int32_t *_delta_a_ff __attribute__((unused)), int32_t *_delta_e_ff __attribute__((unused)), int32_t *_delta_r_ff __attribute__((unused)), int32_t *_delta_a __attribute__((unused)), int32_t *_delta_e __attribute__((unused)), int32_t *_delta_r __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field est_p in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field est_q in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field est_r in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field est_phi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field est_theta in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field est_psi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_est_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field sp_phi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sp_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field sp_theta in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sp_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field sp_psi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sp_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field sum_err_phi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field sum_err_theta in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field sum_err_psi in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field delta_a_fb in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a_fb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field delta_e_fb in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e_fb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field delta_r_fb in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r_fb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 60);
}


/** Getter for field delta_a_ff in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a_ff(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 64);
}


/** Getter for field delta_e_ff in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e_ff(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 68);
}


/** Getter for field delta_r_ff in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r_ff(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 72);
}


/** Getter for field delta_a in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 76);
}


/** Getter for field delta_e in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 80);
}


/** Getter for field delta_r in message STAB_ATTITUDE_INT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 84);
}


/* Compatibility macros */
#define DL_STAB_ATTITUDE_INT_est_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_p(_payload)
#define DL_STAB_ATTITUDE_INT_est_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_q(_payload)
#define DL_STAB_ATTITUDE_INT_est_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_r(_payload)
#define DL_STAB_ATTITUDE_INT_est_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_phi(_payload)
#define DL_STAB_ATTITUDE_INT_est_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_theta(_payload)
#define DL_STAB_ATTITUDE_INT_est_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_est_psi(_payload)
#define DL_STAB_ATTITUDE_INT_sp_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sp_phi(_payload)
#define DL_STAB_ATTITUDE_INT_sp_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sp_theta(_payload)
#define DL_STAB_ATTITUDE_INT_sp_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sp_psi(_payload)
#define DL_STAB_ATTITUDE_INT_sum_err_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_phi(_payload)
#define DL_STAB_ATTITUDE_INT_sum_err_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_theta(_payload)
#define DL_STAB_ATTITUDE_INT_sum_err_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_sum_err_psi(_payload)
#define DL_STAB_ATTITUDE_INT_delta_a_fb(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a_fb(_payload)
#define DL_STAB_ATTITUDE_INT_delta_e_fb(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e_fb(_payload)
#define DL_STAB_ATTITUDE_INT_delta_r_fb(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r_fb(_payload)
#define DL_STAB_ATTITUDE_INT_delta_a_ff(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a_ff(_payload)
#define DL_STAB_ATTITUDE_INT_delta_e_ff(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e_ff(_payload)
#define DL_STAB_ATTITUDE_INT_delta_r_ff(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r_ff(_payload)
#define DL_STAB_ATTITUDE_INT_delta_a(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_a(_payload)
#define DL_STAB_ATTITUDE_INT_delta_e(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_e(_payload)
#define DL_STAB_ATTITUDE_INT_delta_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INT_delta_r(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INT_H_

