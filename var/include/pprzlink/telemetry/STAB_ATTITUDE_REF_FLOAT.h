/** @file
 *  @brief PPRZLink message header for STAB_ATTITUDE_REF_FLOAT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STAB_ATTITUDE_REF_FLOAT_H_
#define _VAR_MESSAGES_telemetry_STAB_ATTITUDE_REF_FLOAT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STAB_ATTITUDE_REF_FLOAT 142
#define PPRZ_MSG_ID_STAB_ATTITUDE_REF_FLOAT 142

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STAB_ATTITUDE_REF_FLOAT _send_msg(STAB_ATTITUDE_REF_FLOAT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STAB_ATTITUDE_REF_FLOAT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_phi 
 * @param _sp_theta 
 * @param _sp_psi 
 * @param _ref_phi 
 * @param _ref_theta 
 * @param _ref_psi 
 * @param _ref_p 
 * @param _ref_q 
 * @param _ref_r 
 * @param _ref_pd 
 * @param _ref_qd 
 * @param _ref_rd 
 */
static inline void pprzlink_msg_v2_send_STAB_ATTITUDE_REF_FLOAT(struct pprzlink_msg * msg, float *_sp_phi, float *_sp_theta, float *_sp_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_ref_p, float *_ref_q, float *_ref_r, float *_ref_pd, float *_ref_qd, float *_ref_rd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STAB_ATTITUDE_REF_FLOAT, "STAB_ATTITUDE_REF_FLOAT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_pd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_qd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ref_rd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STAB_ATTITUDE_REF_FLOAT pprz_msg_send_STAB_ATTITUDE_REF_FLOAT
#define DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd) pprz_msg_send_STAB_ATTITUDE_REF_FLOAT(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd)
/**
 * Sends a STAB_ATTITUDE_REF_FLOAT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_phi 
 * @param _sp_theta 
 * @param _sp_psi 
 * @param _ref_phi 
 * @param _ref_theta 
 * @param _ref_psi 
 * @param _ref_p 
 * @param _ref_q 
 * @param _ref_r 
 * @param _ref_pd 
 * @param _ref_qd 
 * @param _ref_rd 
 */
static inline void pprz_msg_send_STAB_ATTITUDE_REF_FLOAT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_sp_phi, float *_sp_theta, float *_sp_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_ref_p, float *_ref_q, float *_ref_r, float *_ref_pd, float *_ref_qd, float *_ref_rd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STAB_ATTITUDE_REF_FLOAT(&msg,_sp_phi,_sp_theta,_sp_psi,_ref_phi,_ref_theta,_ref_psi,_ref_p,_ref_q,_ref_r,_ref_pd,_ref_qd,_ref_rd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd) {}
static inline void pprz_send_msg_STAB_ATTITUDE_REF_FLOAT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_sp_phi __attribute__((unused)), float *_sp_theta __attribute__((unused)), float *_sp_psi __attribute__((unused)), float *_ref_phi __attribute__((unused)), float *_ref_theta __attribute__((unused)), float *_ref_psi __attribute__((unused)), float *_ref_p __attribute__((unused)), float *_ref_q __attribute__((unused)), float *_ref_r __attribute__((unused)), float *_ref_pd __attribute__((unused)), float *_ref_qd __attribute__((unused)), float *_ref_rd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_phi in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field sp_theta in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field sp_psi in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ref_phi in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ref_theta in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ref_psi in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field ref_p in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field ref_q in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field ref_r in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field ref_pd in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_pd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field ref_qd in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_qd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field ref_rd in message STAB_ATTITUDE_REF_FLOAT
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_REF_FLOAT message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_rd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/* Compatibility macros */
#define DL_STAB_ATTITUDE_REF_FLOAT_sp_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_phi(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_sp_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_theta(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_sp_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_sp_psi(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_phi(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_theta(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_psi(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_p(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_q(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_r(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_pd(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_pd(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_qd(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_qd(_payload)
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_rd(_payload) pprzlink_get_DL_STAB_ATTITUDE_REF_FLOAT_ref_rd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STAB_ATTITUDE_REF_FLOAT_H_

