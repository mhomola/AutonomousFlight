/** @file
 *  @brief PPRZLink message header for GVF_PARAMETRIC in class telemetry
 *
 *  
      Information about the parametric trajectory followed by the Guidance Vector Field algorithm.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GVF_PARAMETRIC_H_
#define _VAR_MESSAGES_telemetry_GVF_PARAMETRIC_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GVF_PARAMETRIC 75
#define PPRZ_MSG_ID_GVF_PARAMETRIC 75

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GVF_PARAMETRIC _send_msg(GVF_PARAMETRIC,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GVF_PARAMETRIC message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _traj Kind of trajectory
 * @param _s Direction to be followed
 * @param _w Virtual coordinate of the algorithm
 * @param nb_p,_p Parameters describing the trajectory
 * @param nb_phi,_phi Error signals
 */
static inline void pprzlink_msg_v2_send_GVF_PARAMETRIC(struct pprzlink_msg * msg, uint8_t *_traj, int8_t *_s, float *_w, uint8_t nb_p, float *_p, uint8_t nb_phi, float *_phi) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+1+nb_p*4+1+nb_phi*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+1+nb_p*4+1+nb_phi*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GVF_PARAMETRIC, "GVF_PARAMETRIC");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _traj, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _s, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _w, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_p, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _p, nb_p*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_phi, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _phi, nb_phi*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GVF_PARAMETRIC pprz_msg_send_GVF_PARAMETRIC
#define DOWNLINK_SEND_GVF_PARAMETRIC(_trans, _dev, traj, s, w, nb_p, p, nb_phi, phi) pprz_msg_send_GVF_PARAMETRIC(&((_trans).trans_tx), &((_dev).device), AC_ID, traj, s, w, nb_p, p, nb_phi, phi)
/**
 * Sends a GVF_PARAMETRIC message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _traj Kind of trajectory
 * @param _s Direction to be followed
 * @param _w Virtual coordinate of the algorithm
 * @param nb_p,_p Parameters describing the trajectory
 * @param nb_phi,_phi Error signals
 */
static inline void pprz_msg_send_GVF_PARAMETRIC(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_traj, int8_t *_s, float *_w, uint8_t nb_p, float *_p, uint8_t nb_phi, float *_phi) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GVF_PARAMETRIC(&msg,_traj,_s,_w,nb_p,_p,nb_phi,_phi);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GVF_PARAMETRIC(_trans, _dev, traj, s, w, nb_p, p, nb_phi, phi) {}
static inline void pprz_send_msg_GVF_PARAMETRIC(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_traj __attribute__((unused)), int8_t *_s __attribute__((unused)), float *_w __attribute__((unused)), uint8_t nb_p __attribute__((unused)), float *_p __attribute__((unused)), uint8_t nb_phi __attribute__((unused)), float *_phi __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field traj in message GVF_PARAMETRIC
  *
  * @param _payload : a pointer to the GVF_PARAMETRIC message
  * @return Kind of trajectory
  */
static inline uint8_t pprzlink_get_DL_GVF_PARAMETRIC_traj(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field s in message GVF_PARAMETRIC
  *
  * @param _payload : a pointer to the GVF_PARAMETRIC message
  * @return Direction to be followed
  */
static inline int8_t pprzlink_get_DL_GVF_PARAMETRIC_s(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 5);
}


/** Getter for field w in message GVF_PARAMETRIC
  *
  * @param _payload : a pointer to the GVF_PARAMETRIC message
  * @return Virtual coordinate of the algorithm
  */
static inline float pprzlink_get_DL_GVF_PARAMETRIC_w(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}

/** Getter for length of array p in message GVF_PARAMETRIC
 *
 * @return p : Parameters describing the trajectory
 */
 static inline uint8_t pprzlink_get_GVF_PARAMETRIC_p_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 10);
}

/** Getter for field p in message GVF_PARAMETRIC
  *
  * @param _payload : a pointer to the GVF_PARAMETRIC message
  * @return Parameters describing the trajectory
  */
static inline float * pprzlink_get_DL_GVF_PARAMETRIC_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 11);
}

/** Getter for length of array phi in message GVF_PARAMETRIC
 *
 * @return phi : Error signals
 */
 static inline uint8_t pprzlink_get_GVF_PARAMETRIC_phi_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 11);
}

/** Getter for field phi in message GVF_PARAMETRIC
  *
  * @param _payload : a pointer to the GVF_PARAMETRIC message
  * @return Error signals
  */
static inline float * pprzlink_get_DL_GVF_PARAMETRIC_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 12);
}


/* Compatibility macros */
#define DL_GVF_PARAMETRIC_traj(_payload) pprzlink_get_DL_GVF_PARAMETRIC_traj(_payload)
#define DL_GVF_PARAMETRIC_s(_payload) pprzlink_get_DL_GVF_PARAMETRIC_s(_payload)
#define DL_GVF_PARAMETRIC_w(_payload) pprzlink_get_DL_GVF_PARAMETRIC_w(_payload)
#define DL_GVF_PARAMETRIC_p_length(_payload) pprzlink_get_GVF_PARAMETRIC_p_length(_payload)
#define DL_GVF_PARAMETRIC_p(_payload) pprzlink_get_DL_GVF_PARAMETRIC_p(_payload)
#define DL_GVF_PARAMETRIC_phi_length(_payload) pprzlink_get_GVF_PARAMETRIC_phi_length(_payload)
#define DL_GVF_PARAMETRIC_phi(_payload) pprzlink_get_DL_GVF_PARAMETRIC_phi(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GVF_PARAMETRIC_H_

