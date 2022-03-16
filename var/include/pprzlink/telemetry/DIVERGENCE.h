/** @file
 *  @brief PPRZLink message header for DIVERGENCE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DIVERGENCE_H_
#define _VAR_MESSAGES_telemetry_DIVERGENCE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DIVERGENCE 224
#define PPRZ_MSG_ID_DIVERGENCE 224

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DIVERGENCE _send_msg(DIVERGENCE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DIVERGENCE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _divergence  vertical velocity / height from optitrack (unit = 1/sec)
 * @param _divergence_vision  vertical velocity / height from vision (unit = 1/sec)
 * @param _normalized_thrust  thrust / max thrust paparazzi (-)
 * @param _cov_div  covariance of divergence and thrust, or past divergence depending on the mode (-)
 * @param _pstate  gain state in adaptive gain control: indicative of height (-) 
 * @param _pused  gain used for control, includes the effect of the p-gain of adaptive control (-) 
 * @param _sonar  measurement from the sonar (mm)
 */
static inline void pprzlink_msg_v2_send_DIVERGENCE(struct pprzlink_msg * msg, float *_divergence, float *_divergence_vision, float *_normalized_thrust, float *_cov_div, float *_pstate, float *_pused, float *_sonar) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DIVERGENCE, "DIVERGENCE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _divergence, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _divergence_vision, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _normalized_thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cov_div, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pstate, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pused, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sonar, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DIVERGENCE pprz_msg_send_DIVERGENCE
#define DOWNLINK_SEND_DIVERGENCE(_trans, _dev, divergence, divergence_vision, normalized_thrust, cov_div, pstate, pused, sonar) pprz_msg_send_DIVERGENCE(&((_trans).trans_tx), &((_dev).device), AC_ID, divergence, divergence_vision, normalized_thrust, cov_div, pstate, pused, sonar)
/**
 * Sends a DIVERGENCE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _divergence  vertical velocity / height from optitrack (unit = 1/sec)
 * @param _divergence_vision  vertical velocity / height from vision (unit = 1/sec)
 * @param _normalized_thrust  thrust / max thrust paparazzi (-)
 * @param _cov_div  covariance of divergence and thrust, or past divergence depending on the mode (-)
 * @param _pstate  gain state in adaptive gain control: indicative of height (-) 
 * @param _pused  gain used for control, includes the effect of the p-gain of adaptive control (-) 
 * @param _sonar  measurement from the sonar (mm)
 */
static inline void pprz_msg_send_DIVERGENCE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_divergence, float *_divergence_vision, float *_normalized_thrust, float *_cov_div, float *_pstate, float *_pused, float *_sonar) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DIVERGENCE(&msg,_divergence,_divergence_vision,_normalized_thrust,_cov_div,_pstate,_pused,_sonar);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DIVERGENCE(_trans, _dev, divergence, divergence_vision, normalized_thrust, cov_div, pstate, pused, sonar) {}
static inline void pprz_send_msg_DIVERGENCE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_divergence __attribute__((unused)), float *_divergence_vision __attribute__((unused)), float *_normalized_thrust __attribute__((unused)), float *_cov_div __attribute__((unused)), float *_pstate __attribute__((unused)), float *_pused __attribute__((unused)), float *_sonar __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field divergence in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  vertical velocity / height from optitrack (unit = 1/sec)
  */
static inline float pprzlink_get_DL_DIVERGENCE_divergence(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field divergence_vision in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  vertical velocity / height from vision (unit = 1/sec)
  */
static inline float pprzlink_get_DL_DIVERGENCE_divergence_vision(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field normalized_thrust in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  thrust / max thrust paparazzi (-)
  */
static inline float pprzlink_get_DL_DIVERGENCE_normalized_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field cov_div in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  covariance of divergence and thrust, or past divergence depending on the mode (-)
  */
static inline float pprzlink_get_DL_DIVERGENCE_cov_div(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field pstate in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  gain state in adaptive gain control: indicative of height (-) 
  */
static inline float pprzlink_get_DL_DIVERGENCE_pstate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field pused in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  gain used for control, includes the effect of the p-gain of adaptive control (-) 
  */
static inline float pprzlink_get_DL_DIVERGENCE_pused(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field sonar in message DIVERGENCE
  *
  * @param _payload : a pointer to the DIVERGENCE message
  * @return  measurement from the sonar (mm)
  */
static inline float pprzlink_get_DL_DIVERGENCE_sonar(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_DIVERGENCE_divergence(_payload) pprzlink_get_DL_DIVERGENCE_divergence(_payload)
#define DL_DIVERGENCE_divergence_vision(_payload) pprzlink_get_DL_DIVERGENCE_divergence_vision(_payload)
#define DL_DIVERGENCE_normalized_thrust(_payload) pprzlink_get_DL_DIVERGENCE_normalized_thrust(_payload)
#define DL_DIVERGENCE_cov_div(_payload) pprzlink_get_DL_DIVERGENCE_cov_div(_payload)
#define DL_DIVERGENCE_pstate(_payload) pprzlink_get_DL_DIVERGENCE_pstate(_payload)
#define DL_DIVERGENCE_pused(_payload) pprzlink_get_DL_DIVERGENCE_pused(_payload)
#define DL_DIVERGENCE_sonar(_payload) pprzlink_get_DL_DIVERGENCE_sonar(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DIVERGENCE_H_

