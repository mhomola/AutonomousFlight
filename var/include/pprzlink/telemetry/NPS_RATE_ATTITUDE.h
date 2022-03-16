/** @file
 *  @brief PPRZLink message header for NPS_RATE_ATTITUDE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_RATE_ATTITUDE_H_
#define _VAR_MESSAGES_telemetry_NPS_RATE_ATTITUDE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_RATE_ATTITUDE 241
#define PPRZ_MSG_ID_NPS_RATE_ATTITUDE 241

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_RATE_ATTITUDE _send_msg(NPS_RATE_ATTITUDE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_RATE_ATTITUDE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 */
static inline void pprzlink_msg_v2_send_NPS_RATE_ATTITUDE(struct pprzlink_msg * msg, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_RATE_ATTITUDE, "NPS_RATE_ATTITUDE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_RATE_ATTITUDE pprz_msg_send_NPS_RATE_ATTITUDE
#define DOWNLINK_SEND_NPS_RATE_ATTITUDE(_trans, _dev, p, q, r, phi, theta, psi) pprz_msg_send_NPS_RATE_ATTITUDE(&((_trans).trans_tx), &((_dev).device), AC_ID, p, q, r, phi, theta, psi)
/**
 * Sends a NPS_RATE_ATTITUDE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 */
static inline void pprz_msg_send_NPS_RATE_ATTITUDE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_RATE_ATTITUDE(&msg,_p,_q,_r,_phi,_theta,_psi);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_RATE_ATTITUDE(_trans, _dev, p, q, r, phi, theta, psi) {}
static inline void pprz_send_msg_NPS_RATE_ATTITUDE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_p __attribute__((unused)), float *_q __attribute__((unused)), float *_r __attribute__((unused)), float *_phi __attribute__((unused)), float *_theta __attribute__((unused)), float *_psi __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field p in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field q in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field r in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field phi in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field theta in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field psi in message NPS_RATE_ATTITUDE
  *
  * @param _payload : a pointer to the NPS_RATE_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_RATE_ATTITUDE_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/* Compatibility macros */
#define DL_NPS_RATE_ATTITUDE_p(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_p(_payload)
#define DL_NPS_RATE_ATTITUDE_q(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_q(_payload)
#define DL_NPS_RATE_ATTITUDE_r(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_r(_payload)
#define DL_NPS_RATE_ATTITUDE_phi(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_phi(_payload)
#define DL_NPS_RATE_ATTITUDE_theta(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_theta(_payload)
#define DL_NPS_RATE_ATTITUDE_psi(_payload) pprzlink_get_DL_NPS_RATE_ATTITUDE_psi(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_RATE_ATTITUDE_H_

