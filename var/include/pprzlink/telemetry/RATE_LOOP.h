/** @file
 *  @brief PPRZLink message header for RATE_LOOP in class telemetry
 *
 *  Rotorcraft rate control loop.
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RATE_LOOP_H_
#define _VAR_MESSAGES_telemetry_RATE_LOOP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RATE_LOOP 136
#define PPRZ_MSG_ID_RATE_LOOP 136

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RATE_LOOP _send_msg(RATE_LOOP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RATE_LOOP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_p rate setpoint
 * @param _sp_q rate setpoint
 * @param _sp_r rate setpoint
 * @param _sumerr_p integrated quaternion error
 * @param _sumerr_q integrated quaternion error
 * @param _sumerr_r integrated quaternion error
 * @param _fb_p feedback command on pitch (pprz scale)
 * @param _fb_q feedback command on roll  (pprz scale)
 * @param _fb_r feedback command on yaw   (pprz scale)
 * @param _delta_t thrust command
 */
static inline void pprzlink_msg_v2_send_RATE_LOOP(struct pprzlink_msg * msg, float *_sp_p, float *_sp_q, float *_sp_r, float *_sumerr_p, float *_sumerr_q, float *_sumerr_r, float *_fb_p, float *_fb_q, float *_fb_r, int32_t *_delta_t) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RATE_LOOP, "RATE_LOOP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sumerr_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sumerr_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sumerr_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fb_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fb_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fb_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_t, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RATE_LOOP pprz_msg_send_RATE_LOOP
#define DOWNLINK_SEND_RATE_LOOP(_trans, _dev, sp_p, sp_q, sp_r, sumerr_p, sumerr_q, sumerr_r, fb_p, fb_q, fb_r, delta_t) pprz_msg_send_RATE_LOOP(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_p, sp_q, sp_r, sumerr_p, sumerr_q, sumerr_r, fb_p, fb_q, fb_r, delta_t)
/**
 * Sends a RATE_LOOP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_p rate setpoint
 * @param _sp_q rate setpoint
 * @param _sp_r rate setpoint
 * @param _sumerr_p integrated quaternion error
 * @param _sumerr_q integrated quaternion error
 * @param _sumerr_r integrated quaternion error
 * @param _fb_p feedback command on pitch (pprz scale)
 * @param _fb_q feedback command on roll  (pprz scale)
 * @param _fb_r feedback command on yaw   (pprz scale)
 * @param _delta_t thrust command
 */
static inline void pprz_msg_send_RATE_LOOP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_sp_p, float *_sp_q, float *_sp_r, float *_sumerr_p, float *_sumerr_q, float *_sumerr_r, float *_fb_p, float *_fb_q, float *_fb_r, int32_t *_delta_t) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RATE_LOOP(&msg,_sp_p,_sp_q,_sp_r,_sumerr_p,_sumerr_q,_sumerr_r,_fb_p,_fb_q,_fb_r,_delta_t);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RATE_LOOP(_trans, _dev, sp_p, sp_q, sp_r, sumerr_p, sumerr_q, sumerr_r, fb_p, fb_q, fb_r, delta_t) {}
static inline void pprz_send_msg_RATE_LOOP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_sp_p __attribute__((unused)), float *_sp_q __attribute__((unused)), float *_sp_r __attribute__((unused)), float *_sumerr_p __attribute__((unused)), float *_sumerr_q __attribute__((unused)), float *_sumerr_r __attribute__((unused)), float *_fb_p __attribute__((unused)), float *_fb_q __attribute__((unused)), float *_fb_r __attribute__((unused)), int32_t *_delta_t __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_p in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return rate setpoint
  */
static inline float pprzlink_get_DL_RATE_LOOP_sp_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field sp_q in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return rate setpoint
  */
static inline float pprzlink_get_DL_RATE_LOOP_sp_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field sp_r in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return rate setpoint
  */
static inline float pprzlink_get_DL_RATE_LOOP_sp_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field sumerr_p in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return integrated quaternion error
  */
static inline float pprzlink_get_DL_RATE_LOOP_sumerr_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field sumerr_q in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return integrated quaternion error
  */
static inline float pprzlink_get_DL_RATE_LOOP_sumerr_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field sumerr_r in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return integrated quaternion error
  */
static inline float pprzlink_get_DL_RATE_LOOP_sumerr_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field fb_p in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return feedback command on pitch (pprz scale)
  */
static inline float pprzlink_get_DL_RATE_LOOP_fb_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field fb_q in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return feedback command on roll  (pprz scale)
  */
static inline float pprzlink_get_DL_RATE_LOOP_fb_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field fb_r in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return feedback command on yaw   (pprz scale)
  */
static inline float pprzlink_get_DL_RATE_LOOP_fb_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field delta_t in message RATE_LOOP
  *
  * @param _payload : a pointer to the RATE_LOOP message
  * @return thrust command
  */
static inline int32_t pprzlink_get_DL_RATE_LOOP_delta_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/* Compatibility macros */
#define DL_RATE_LOOP_sp_p(_payload) pprzlink_get_DL_RATE_LOOP_sp_p(_payload)
#define DL_RATE_LOOP_sp_q(_payload) pprzlink_get_DL_RATE_LOOP_sp_q(_payload)
#define DL_RATE_LOOP_sp_r(_payload) pprzlink_get_DL_RATE_LOOP_sp_r(_payload)
#define DL_RATE_LOOP_sumerr_p(_payload) pprzlink_get_DL_RATE_LOOP_sumerr_p(_payload)
#define DL_RATE_LOOP_sumerr_q(_payload) pprzlink_get_DL_RATE_LOOP_sumerr_q(_payload)
#define DL_RATE_LOOP_sumerr_r(_payload) pprzlink_get_DL_RATE_LOOP_sumerr_r(_payload)
#define DL_RATE_LOOP_fb_p(_payload) pprzlink_get_DL_RATE_LOOP_fb_p(_payload)
#define DL_RATE_LOOP_fb_q(_payload) pprzlink_get_DL_RATE_LOOP_fb_q(_payload)
#define DL_RATE_LOOP_fb_r(_payload) pprzlink_get_DL_RATE_LOOP_fb_r(_payload)
#define DL_RATE_LOOP_delta_t(_payload) pprzlink_get_DL_RATE_LOOP_delta_t(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RATE_LOOP_H_

