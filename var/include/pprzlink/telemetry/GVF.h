/** @file
 *  @brief PPRZLink message header for GVF in class telemetry
 *
 *  
      Information about the trajectory followed by the Guidance Vector Field algorithm.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GVF_H_
#define _VAR_MESSAGES_telemetry_GVF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GVF 71
#define PPRZ_MSG_ID_GVF 71

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GVF _send_msg(GVF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GVF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _error Error index e, i.e. 'distance' to the trajectory
 * @param _traj Kind of trajectory
 * @param _s Direction to be followed
 * @param _ke Gain for the vector field convergence
 * @param nb_p,_p Parameters describing the trajectory
 */
static inline void pprzlink_msg_v2_send_GVF(struct pprzlink_msg * msg, float *_error, uint8_t *_traj, int8_t *_s, float *_ke, uint8_t nb_p, float *_p) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+1+4+1+nb_p*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+1+4+1+nb_p*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GVF, "GVF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _error, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _traj, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _s, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ke, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_p, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _p, nb_p*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GVF pprz_msg_send_GVF
#define DOWNLINK_SEND_GVF(_trans, _dev, error, traj, s, ke, nb_p, p) pprz_msg_send_GVF(&((_trans).trans_tx), &((_dev).device), AC_ID, error, traj, s, ke, nb_p, p)
/**
 * Sends a GVF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _error Error index e, i.e. 'distance' to the trajectory
 * @param _traj Kind of trajectory
 * @param _s Direction to be followed
 * @param _ke Gain for the vector field convergence
 * @param nb_p,_p Parameters describing the trajectory
 */
static inline void pprz_msg_send_GVF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_error, uint8_t *_traj, int8_t *_s, float *_ke, uint8_t nb_p, float *_p) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GVF(&msg,_error,_traj,_s,_ke,nb_p,_p);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GVF(_trans, _dev, error, traj, s, ke, nb_p, p) {}
static inline void pprz_send_msg_GVF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_error __attribute__((unused)), uint8_t *_traj __attribute__((unused)), int8_t *_s __attribute__((unused)), float *_ke __attribute__((unused)), uint8_t nb_p __attribute__((unused)), float *_p __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field error in message GVF
  *
  * @param _payload : a pointer to the GVF message
  * @return Error index e, i.e. 'distance' to the trajectory
  */
static inline float pprzlink_get_DL_GVF_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field traj in message GVF
  *
  * @param _payload : a pointer to the GVF message
  * @return Kind of trajectory
  */
static inline uint8_t pprzlink_get_DL_GVF_traj(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field s in message GVF
  *
  * @param _payload : a pointer to the GVF message
  * @return Direction to be followed
  */
static inline int8_t pprzlink_get_DL_GVF_s(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 9);
}


/** Getter for field ke in message GVF
  *
  * @param _payload : a pointer to the GVF message
  * @return Gain for the vector field convergence
  */
static inline float pprzlink_get_DL_GVF_ke(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}

/** Getter for length of array p in message GVF
 *
 * @return p : Parameters describing the trajectory
 */
 static inline uint8_t pprzlink_get_GVF_p_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 14);
}

/** Getter for field p in message GVF
  *
  * @param _payload : a pointer to the GVF message
  * @return Parameters describing the trajectory
  */
static inline float * pprzlink_get_DL_GVF_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 15);
}


/* Compatibility macros */
#define DL_GVF_error(_payload) pprzlink_get_DL_GVF_error(_payload)
#define DL_GVF_traj(_payload) pprzlink_get_DL_GVF_traj(_payload)
#define DL_GVF_s(_payload) pprzlink_get_DL_GVF_s(_payload)
#define DL_GVF_ke(_payload) pprzlink_get_DL_GVF_ke(_payload)
#define DL_GVF_p_length(_payload) pprzlink_get_GVF_p_length(_payload)
#define DL_GVF_p(_payload) pprzlink_get_DL_GVF_p(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GVF_H_

