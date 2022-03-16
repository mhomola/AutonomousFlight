/** @file
 *  @brief PPRZLink message header for H_CTL_A in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_H_CTL_A_H_
#define _VAR_MESSAGES_telemetry_H_CTL_A_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_H_CTL_A 60
#define PPRZ_MSG_ID_H_CTL_A 60

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_H_CTL_A _send_msg(H_CTL_A,PPRZLINK_DEFAULT_VER)

/**
 * Sends a H_CTL_A message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _roll_sum_err 
 * @param _roll_sp 
 * @param _roll_ref 
 * @param _phi 
 * @param _aileron_sp 
 * @param _pitch_sum_err 
 * @param _pitch_sp 
 * @param _pitch_ref 
 * @param _theta 
 * @param _elevator_sp 
 */
static inline void pprzlink_msg_v2_send_H_CTL_A(struct pprzlink_msg * msg, float *_roll_sum_err, float *_roll_sp, float *_roll_ref, float *_phi, int16_t *_aileron_sp, float *_pitch_sum_err, float *_pitch_sp, float *_pitch_ref, float *_theta, int16_t *_elevator_sp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+2+4+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+2+4+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_H_CTL_A, "H_CTL_A");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _roll_sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _roll_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _roll_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _aileron_sp, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitch_sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitch_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitch_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _elevator_sp, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_H_CTL_A pprz_msg_send_H_CTL_A
#define DOWNLINK_SEND_H_CTL_A(_trans, _dev, roll_sum_err, roll_sp, roll_ref, phi, aileron_sp, pitch_sum_err, pitch_sp, pitch_ref, theta, elevator_sp) pprz_msg_send_H_CTL_A(&((_trans).trans_tx), &((_dev).device), AC_ID, roll_sum_err, roll_sp, roll_ref, phi, aileron_sp, pitch_sum_err, pitch_sp, pitch_ref, theta, elevator_sp)
/**
 * Sends a H_CTL_A message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _roll_sum_err 
 * @param _roll_sp 
 * @param _roll_ref 
 * @param _phi 
 * @param _aileron_sp 
 * @param _pitch_sum_err 
 * @param _pitch_sp 
 * @param _pitch_ref 
 * @param _theta 
 * @param _elevator_sp 
 */
static inline void pprz_msg_send_H_CTL_A(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_roll_sum_err, float *_roll_sp, float *_roll_ref, float *_phi, int16_t *_aileron_sp, float *_pitch_sum_err, float *_pitch_sp, float *_pitch_ref, float *_theta, int16_t *_elevator_sp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_H_CTL_A(&msg,_roll_sum_err,_roll_sp,_roll_ref,_phi,_aileron_sp,_pitch_sum_err,_pitch_sp,_pitch_ref,_theta,_elevator_sp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_H_CTL_A(_trans, _dev, roll_sum_err, roll_sp, roll_ref, phi, aileron_sp, pitch_sum_err, pitch_sp, pitch_ref, theta, elevator_sp) {}
static inline void pprz_send_msg_H_CTL_A(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_roll_sum_err __attribute__((unused)), float *_roll_sp __attribute__((unused)), float *_roll_ref __attribute__((unused)), float *_phi __attribute__((unused)), int16_t *_aileron_sp __attribute__((unused)), float *_pitch_sum_err __attribute__((unused)), float *_pitch_sp __attribute__((unused)), float *_pitch_ref __attribute__((unused)), float *_theta __attribute__((unused)), int16_t *_elevator_sp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field roll_sum_err in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_roll_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field roll_sp in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_roll_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field roll_ref in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_roll_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field phi in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field aileron_sp in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline int16_t pprzlink_get_DL_H_CTL_A_aileron_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 20);
}


/** Getter for field pitch_sum_err in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_pitch_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field pitch_sp in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_pitch_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/** Getter for field pitch_ref in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_pitch_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 30);
}


/** Getter for field theta in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline float pprzlink_get_DL_H_CTL_A_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 34);
}


/** Getter for field elevator_sp in message H_CTL_A
  *
  * @param _payload : a pointer to the H_CTL_A message
  * @return 
  */
static inline int16_t pprzlink_get_DL_H_CTL_A_elevator_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 38);
}


/* Compatibility macros */
#define DL_H_CTL_A_roll_sum_err(_payload) pprzlink_get_DL_H_CTL_A_roll_sum_err(_payload)
#define DL_H_CTL_A_roll_sp(_payload) pprzlink_get_DL_H_CTL_A_roll_sp(_payload)
#define DL_H_CTL_A_roll_ref(_payload) pprzlink_get_DL_H_CTL_A_roll_ref(_payload)
#define DL_H_CTL_A_phi(_payload) pprzlink_get_DL_H_CTL_A_phi(_payload)
#define DL_H_CTL_A_aileron_sp(_payload) pprzlink_get_DL_H_CTL_A_aileron_sp(_payload)
#define DL_H_CTL_A_pitch_sum_err(_payload) pprzlink_get_DL_H_CTL_A_pitch_sum_err(_payload)
#define DL_H_CTL_A_pitch_sp(_payload) pprzlink_get_DL_H_CTL_A_pitch_sp(_payload)
#define DL_H_CTL_A_pitch_ref(_payload) pprzlink_get_DL_H_CTL_A_pitch_ref(_payload)
#define DL_H_CTL_A_theta(_payload) pprzlink_get_DL_H_CTL_A_theta(_payload)
#define DL_H_CTL_A_elevator_sp(_payload) pprzlink_get_DL_H_CTL_A_elevator_sp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_H_CTL_A_H_

