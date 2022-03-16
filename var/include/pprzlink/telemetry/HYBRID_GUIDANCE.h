/** @file
 *  @brief PPRZLink message header for HYBRID_GUIDANCE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_HYBRID_GUIDANCE_H_
#define _VAR_MESSAGES_telemetry_HYBRID_GUIDANCE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HYBRID_GUIDANCE 24
#define PPRZ_MSG_ID_HYBRID_GUIDANCE 24

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HYBRID_GUIDANCE _send_msg(HYBRID_GUIDANCE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HYBRID_GUIDANCE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pos_x 
 * @param _pos_y 
 * @param _speed_x 
 * @param _speed_y 
 * @param _wind_x 
 * @param _wind_y 
 * @param _pos_err_x 
 * @param _pos_err_y 
 * @param _speed_sp_x 
 * @param _speed_sp_y 
 * @param _norm_ref_speed 
 * @param _heading_diff 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 */
static inline void pprzlink_msg_v2_send_HYBRID_GUIDANCE(struct pprzlink_msg * msg, int32_t *_pos_x, int32_t *_pos_y, int32_t *_speed_x, int32_t *_speed_y, int32_t *_wind_x, int32_t *_wind_y, int32_t *_pos_err_x, int32_t *_pos_err_y, int32_t *_speed_sp_x, int32_t *_speed_sp_y, int32_t *_norm_ref_speed, int32_t *_heading_diff, int32_t *_phi, int32_t *_theta, int32_t *_psi) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HYBRID_GUIDANCE, "HYBRID_GUIDANCE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pos_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pos_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _speed_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _speed_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _wind_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _wind_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pos_err_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pos_err_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _speed_sp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _speed_sp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _norm_ref_speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _heading_diff, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HYBRID_GUIDANCE pprz_msg_send_HYBRID_GUIDANCE
#define DOWNLINK_SEND_HYBRID_GUIDANCE(_trans, _dev, pos_x, pos_y, speed_x, speed_y, wind_x, wind_y, pos_err_x, pos_err_y, speed_sp_x, speed_sp_y, norm_ref_speed, heading_diff, phi, theta, psi) pprz_msg_send_HYBRID_GUIDANCE(&((_trans).trans_tx), &((_dev).device), AC_ID, pos_x, pos_y, speed_x, speed_y, wind_x, wind_y, pos_err_x, pos_err_y, speed_sp_x, speed_sp_y, norm_ref_speed, heading_diff, phi, theta, psi)
/**
 * Sends a HYBRID_GUIDANCE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pos_x 
 * @param _pos_y 
 * @param _speed_x 
 * @param _speed_y 
 * @param _wind_x 
 * @param _wind_y 
 * @param _pos_err_x 
 * @param _pos_err_y 
 * @param _speed_sp_x 
 * @param _speed_sp_y 
 * @param _norm_ref_speed 
 * @param _heading_diff 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 */
static inline void pprz_msg_send_HYBRID_GUIDANCE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_pos_x, int32_t *_pos_y, int32_t *_speed_x, int32_t *_speed_y, int32_t *_wind_x, int32_t *_wind_y, int32_t *_pos_err_x, int32_t *_pos_err_y, int32_t *_speed_sp_x, int32_t *_speed_sp_y, int32_t *_norm_ref_speed, int32_t *_heading_diff, int32_t *_phi, int32_t *_theta, int32_t *_psi) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HYBRID_GUIDANCE(&msg,_pos_x,_pos_y,_speed_x,_speed_y,_wind_x,_wind_y,_pos_err_x,_pos_err_y,_speed_sp_x,_speed_sp_y,_norm_ref_speed,_heading_diff,_phi,_theta,_psi);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HYBRID_GUIDANCE(_trans, _dev, pos_x, pos_y, speed_x, speed_y, wind_x, wind_y, pos_err_x, pos_err_y, speed_sp_x, speed_sp_y, norm_ref_speed, heading_diff, phi, theta, psi) {}
static inline void pprz_send_msg_HYBRID_GUIDANCE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_pos_x __attribute__((unused)), int32_t *_pos_y __attribute__((unused)), int32_t *_speed_x __attribute__((unused)), int32_t *_speed_y __attribute__((unused)), int32_t *_wind_x __attribute__((unused)), int32_t *_wind_y __attribute__((unused)), int32_t *_pos_err_x __attribute__((unused)), int32_t *_pos_err_y __attribute__((unused)), int32_t *_speed_sp_x __attribute__((unused)), int32_t *_speed_sp_y __attribute__((unused)), int32_t *_norm_ref_speed __attribute__((unused)), int32_t *_heading_diff __attribute__((unused)), int32_t *_phi __attribute__((unused)), int32_t *_theta __attribute__((unused)), int32_t *_psi __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pos_x in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_pos_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field pos_y in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_pos_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field speed_x in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_speed_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field speed_y in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_speed_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field wind_x in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_wind_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field wind_y in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_wind_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field pos_err_x in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_pos_err_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field pos_err_y in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_pos_err_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field speed_sp_x in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_speed_sp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field speed_sp_y in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_speed_sp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field norm_ref_speed in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_norm_ref_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field heading_diff in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_heading_diff(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field phi in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field theta in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field psi in message HYBRID_GUIDANCE
  *
  * @param _payload : a pointer to the HYBRID_GUIDANCE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HYBRID_GUIDANCE_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 60);
}


/* Compatibility macros */
#define DL_HYBRID_GUIDANCE_pos_x(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_pos_x(_payload)
#define DL_HYBRID_GUIDANCE_pos_y(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_pos_y(_payload)
#define DL_HYBRID_GUIDANCE_speed_x(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_speed_x(_payload)
#define DL_HYBRID_GUIDANCE_speed_y(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_speed_y(_payload)
#define DL_HYBRID_GUIDANCE_wind_x(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_wind_x(_payload)
#define DL_HYBRID_GUIDANCE_wind_y(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_wind_y(_payload)
#define DL_HYBRID_GUIDANCE_pos_err_x(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_pos_err_x(_payload)
#define DL_HYBRID_GUIDANCE_pos_err_y(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_pos_err_y(_payload)
#define DL_HYBRID_GUIDANCE_speed_sp_x(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_speed_sp_x(_payload)
#define DL_HYBRID_GUIDANCE_speed_sp_y(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_speed_sp_y(_payload)
#define DL_HYBRID_GUIDANCE_norm_ref_speed(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_norm_ref_speed(_payload)
#define DL_HYBRID_GUIDANCE_heading_diff(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_heading_diff(_payload)
#define DL_HYBRID_GUIDANCE_phi(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_phi(_payload)
#define DL_HYBRID_GUIDANCE_theta(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_theta(_payload)
#define DL_HYBRID_GUIDANCE_psi(_payload) pprzlink_get_DL_HYBRID_GUIDANCE_psi(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_HYBRID_GUIDANCE_H_

