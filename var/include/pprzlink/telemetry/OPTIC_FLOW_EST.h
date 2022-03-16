/** @file
 *  @brief PPRZLink message header for OPTIC_FLOW_EST in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_OPTIC_FLOW_EST_H_
#define _VAR_MESSAGES_telemetry_OPTIC_FLOW_EST_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_OPTIC_FLOW_EST 228
#define PPRZ_MSG_ID_OPTIC_FLOW_EST 228

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_OPTIC_FLOW_EST _send_msg(OPTIC_FLOW_EST,PPRZLINK_DEFAULT_VER)

/**
 * Sends a OPTIC_FLOW_EST message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _fps 
 * @param _corner_cnt 
 * @param _tracked_cnt 
 * @param _flow_x 
 * @param _flow_y 
 * @param _flow_der_x 
 * @param _flow_der_y 
 * @param _vel_x 
 * @param _vel_y 
 * @param _vel_z 
 * @param _div_size 
 * @param _surface_roughness 
 * @param _divergence 
 * @param _camera_id 
 */
static inline void pprzlink_msg_v2_send_OPTIC_FLOW_EST(struct pprzlink_msg * msg, float *_fps, uint16_t *_corner_cnt, uint16_t *_tracked_cnt, int16_t *_flow_x, int16_t *_flow_y, int16_t *_flow_der_x, int16_t *_flow_der_y, float *_vel_x, float *_vel_y, float *_vel_z, float *_div_size, float *_surface_roughness, float *_divergence, uint8_t *_camera_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+2+2+2+2+2+2+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+2+2+2+2+2+2+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_OPTIC_FLOW_EST, "OPTIC_FLOW_EST");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fps, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _corner_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _tracked_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _flow_x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _flow_y, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _flow_der_x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _flow_der_y, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vel_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _div_size, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _surface_roughness, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _divergence, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _camera_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_OPTIC_FLOW_EST pprz_msg_send_OPTIC_FLOW_EST
#define DOWNLINK_SEND_OPTIC_FLOW_EST(_trans, _dev, fps, corner_cnt, tracked_cnt, flow_x, flow_y, flow_der_x, flow_der_y, vel_x, vel_y, vel_z, div_size, surface_roughness, divergence, camera_id) pprz_msg_send_OPTIC_FLOW_EST(&((_trans).trans_tx), &((_dev).device), AC_ID, fps, corner_cnt, tracked_cnt, flow_x, flow_y, flow_der_x, flow_der_y, vel_x, vel_y, vel_z, div_size, surface_roughness, divergence, camera_id)
/**
 * Sends a OPTIC_FLOW_EST message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _fps 
 * @param _corner_cnt 
 * @param _tracked_cnt 
 * @param _flow_x 
 * @param _flow_y 
 * @param _flow_der_x 
 * @param _flow_der_y 
 * @param _vel_x 
 * @param _vel_y 
 * @param _vel_z 
 * @param _div_size 
 * @param _surface_roughness 
 * @param _divergence 
 * @param _camera_id 
 */
static inline void pprz_msg_send_OPTIC_FLOW_EST(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_fps, uint16_t *_corner_cnt, uint16_t *_tracked_cnt, int16_t *_flow_x, int16_t *_flow_y, int16_t *_flow_der_x, int16_t *_flow_der_y, float *_vel_x, float *_vel_y, float *_vel_z, float *_div_size, float *_surface_roughness, float *_divergence, uint8_t *_camera_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_OPTIC_FLOW_EST(&msg,_fps,_corner_cnt,_tracked_cnt,_flow_x,_flow_y,_flow_der_x,_flow_der_y,_vel_x,_vel_y,_vel_z,_div_size,_surface_roughness,_divergence,_camera_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_OPTIC_FLOW_EST(_trans, _dev, fps, corner_cnt, tracked_cnt, flow_x, flow_y, flow_der_x, flow_der_y, vel_x, vel_y, vel_z, div_size, surface_roughness, divergence, camera_id) {}
static inline void pprz_send_msg_OPTIC_FLOW_EST(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_fps __attribute__((unused)), uint16_t *_corner_cnt __attribute__((unused)), uint16_t *_tracked_cnt __attribute__((unused)), int16_t *_flow_x __attribute__((unused)), int16_t *_flow_y __attribute__((unused)), int16_t *_flow_der_x __attribute__((unused)), int16_t *_flow_der_y __attribute__((unused)), float *_vel_x __attribute__((unused)), float *_vel_y __attribute__((unused)), float *_vel_z __attribute__((unused)), float *_div_size __attribute__((unused)), float *_surface_roughness __attribute__((unused)), float *_divergence __attribute__((unused)), uint8_t *_camera_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field fps in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_fps(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field corner_cnt in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_OPTIC_FLOW_EST_corner_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field tracked_cnt in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_OPTIC_FLOW_EST_tracked_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field flow_x in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline int16_t pprzlink_get_DL_OPTIC_FLOW_EST_flow_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/** Getter for field flow_y in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline int16_t pprzlink_get_DL_OPTIC_FLOW_EST_flow_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 14);
}


/** Getter for field flow_der_x in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline int16_t pprzlink_get_DL_OPTIC_FLOW_EST_flow_der_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 16);
}


/** Getter for field flow_der_y in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline int16_t pprzlink_get_DL_OPTIC_FLOW_EST_flow_der_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 18);
}


/** Getter for field vel_x in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_vel_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field vel_y in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_vel_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field vel_z in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_vel_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field div_size in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_div_size(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field surface_roughness in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_surface_roughness(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field divergence in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline float pprzlink_get_DL_OPTIC_FLOW_EST_divergence(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field camera_id in message OPTIC_FLOW_EST
  *
  * @param _payload : a pointer to the OPTIC_FLOW_EST message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_OPTIC_FLOW_EST_camera_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 44);
}


/* Compatibility macros */
#define DL_OPTIC_FLOW_EST_fps(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_fps(_payload)
#define DL_OPTIC_FLOW_EST_corner_cnt(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_corner_cnt(_payload)
#define DL_OPTIC_FLOW_EST_tracked_cnt(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_tracked_cnt(_payload)
#define DL_OPTIC_FLOW_EST_flow_x(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_flow_x(_payload)
#define DL_OPTIC_FLOW_EST_flow_y(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_flow_y(_payload)
#define DL_OPTIC_FLOW_EST_flow_der_x(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_flow_der_x(_payload)
#define DL_OPTIC_FLOW_EST_flow_der_y(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_flow_der_y(_payload)
#define DL_OPTIC_FLOW_EST_vel_x(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_vel_x(_payload)
#define DL_OPTIC_FLOW_EST_vel_y(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_vel_y(_payload)
#define DL_OPTIC_FLOW_EST_vel_z(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_vel_z(_payload)
#define DL_OPTIC_FLOW_EST_div_size(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_div_size(_payload)
#define DL_OPTIC_FLOW_EST_surface_roughness(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_surface_roughness(_payload)
#define DL_OPTIC_FLOW_EST_divergence(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_divergence(_payload)
#define DL_OPTIC_FLOW_EST_camera_id(_payload) pprzlink_get_DL_OPTIC_FLOW_EST_camera_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_OPTIC_FLOW_EST_H_

