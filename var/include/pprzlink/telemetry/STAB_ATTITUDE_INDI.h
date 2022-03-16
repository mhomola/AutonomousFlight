/** @file
 *  @brief PPRZLink message header for STAB_ATTITUDE_INDI in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INDI_H_
#define _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INDI_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STAB_ATTITUDE_INDI 216
#define PPRZ_MSG_ID_STAB_ATTITUDE_INDI 216

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STAB_ATTITUDE_INDI _send_msg(STAB_ATTITUDE_INDI,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STAB_ATTITUDE_INDI message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _angular_accel_p 
 * @param _angular_accel_q 
 * @param _angular_accel_r 
 * @param _angular_accel_ref_p 
 * @param _angular_accel_ref_q 
 * @param _angular_accel_ref_r 
 * @param _g1_p 
 * @param _g1_q 
 * @param _g1_r 
 * @param _g2_r 
 */
static inline void pprzlink_msg_v2_send_STAB_ATTITUDE_INDI(struct pprzlink_msg * msg, float *_angular_accel_p, float *_angular_accel_q, float *_angular_accel_r, float *_angular_accel_ref_p, float *_angular_accel_ref_q, float *_angular_accel_ref_r, float *_g1_p, float *_g1_q, float *_g1_r, float *_g2_r) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STAB_ATTITUDE_INDI, "STAB_ATTITUDE_INDI");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _g1_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _g1_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _g1_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _g2_r, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STAB_ATTITUDE_INDI pprz_msg_send_STAB_ATTITUDE_INDI
#define DOWNLINK_SEND_STAB_ATTITUDE_INDI(_trans, _dev, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, g1_p, g1_q, g1_r, g2_r) pprz_msg_send_STAB_ATTITUDE_INDI(&((_trans).trans_tx), &((_dev).device), AC_ID, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, g1_p, g1_q, g1_r, g2_r)
/**
 * Sends a STAB_ATTITUDE_INDI message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _angular_accel_p 
 * @param _angular_accel_q 
 * @param _angular_accel_r 
 * @param _angular_accel_ref_p 
 * @param _angular_accel_ref_q 
 * @param _angular_accel_ref_r 
 * @param _g1_p 
 * @param _g1_q 
 * @param _g1_r 
 * @param _g2_r 
 */
static inline void pprz_msg_send_STAB_ATTITUDE_INDI(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_angular_accel_p, float *_angular_accel_q, float *_angular_accel_r, float *_angular_accel_ref_p, float *_angular_accel_ref_q, float *_angular_accel_ref_r, float *_g1_p, float *_g1_q, float *_g1_r, float *_g2_r) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STAB_ATTITUDE_INDI(&msg,_angular_accel_p,_angular_accel_q,_angular_accel_r,_angular_accel_ref_p,_angular_accel_ref_q,_angular_accel_ref_r,_g1_p,_g1_q,_g1_r,_g2_r);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STAB_ATTITUDE_INDI(_trans, _dev, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, g1_p, g1_q, g1_r, g2_r) {}
static inline void pprz_send_msg_STAB_ATTITUDE_INDI(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_angular_accel_p __attribute__((unused)), float *_angular_accel_q __attribute__((unused)), float *_angular_accel_r __attribute__((unused)), float *_angular_accel_ref_p __attribute__((unused)), float *_angular_accel_ref_q __attribute__((unused)), float *_angular_accel_ref_r __attribute__((unused)), float *_g1_p __attribute__((unused)), float *_g1_q __attribute__((unused)), float *_g1_r __attribute__((unused)), float *_g2_r __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field angular_accel_p in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field angular_accel_q in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field angular_accel_r in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field angular_accel_ref_p in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field angular_accel_ref_q in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field angular_accel_ref_r in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field g1_p in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field g1_q in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field g1_r in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field g2_r in message STAB_ATTITUDE_INDI
  *
  * @param _payload : a pointer to the STAB_ATTITUDE_INDI message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_INDI_g2_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/* Compatibility macros */
#define DL_STAB_ATTITUDE_INDI_angular_accel_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_p(_payload)
#define DL_STAB_ATTITUDE_INDI_angular_accel_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_q(_payload)
#define DL_STAB_ATTITUDE_INDI_angular_accel_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_r(_payload)
#define DL_STAB_ATTITUDE_INDI_angular_accel_ref_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_p(_payload)
#define DL_STAB_ATTITUDE_INDI_angular_accel_ref_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_q(_payload)
#define DL_STAB_ATTITUDE_INDI_angular_accel_ref_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_angular_accel_ref_r(_payload)
#define DL_STAB_ATTITUDE_INDI_g1_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_p(_payload)
#define DL_STAB_ATTITUDE_INDI_g1_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_q(_payload)
#define DL_STAB_ATTITUDE_INDI_g1_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_g1_r(_payload)
#define DL_STAB_ATTITUDE_INDI_g2_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_INDI_g2_r(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STAB_ATTITUDE_INDI_H_

