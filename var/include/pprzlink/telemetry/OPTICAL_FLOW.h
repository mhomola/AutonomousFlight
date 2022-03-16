/** @file
 *  @brief PPRZLink message header for OPTICAL_FLOW in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_OPTICAL_FLOW_H_
#define _VAR_MESSAGES_telemetry_OPTICAL_FLOW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_OPTICAL_FLOW 233
#define PPRZ_MSG_ID_OPTICAL_FLOW 233

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_OPTICAL_FLOW _send_msg(OPTICAL_FLOW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a OPTICAL_FLOW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _time_sec 
 * @param _sensor_id 
 * @param _flow_x 
 * @param _flow_y 
 * @param _flow_comp_m_x 
 * @param _flow_comp_m_y 
 * @param _flow_quality 
 * @param _ground_distance 
 * @param _distance_compensated 
 * @param _distance_quality 
 */
static inline void pprzlink_msg_v2_send_OPTICAL_FLOW(struct pprzlink_msg * msg, float *_time_sec, uint8_t *_sensor_id, int32_t *_flow_x, int32_t *_flow_y, float *_flow_comp_m_x, float *_flow_comp_m_y, uint8_t *_flow_quality, float *_ground_distance, float *_distance_compensated, uint8_t *_distance_quality) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+4+4+4+4+1+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+4+4+4+4+1+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_OPTICAL_FLOW, "OPTICAL_FLOW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _time_sec, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _sensor_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _flow_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _flow_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flow_comp_m_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flow_comp_m_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _flow_quality, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ground_distance, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _distance_compensated, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _distance_quality, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_OPTICAL_FLOW pprz_msg_send_OPTICAL_FLOW
#define DOWNLINK_SEND_OPTICAL_FLOW(_trans, _dev, time_sec, sensor_id, flow_x, flow_y, flow_comp_m_x, flow_comp_m_y, flow_quality, ground_distance, distance_compensated, distance_quality) pprz_msg_send_OPTICAL_FLOW(&((_trans).trans_tx), &((_dev).device), AC_ID, time_sec, sensor_id, flow_x, flow_y, flow_comp_m_x, flow_comp_m_y, flow_quality, ground_distance, distance_compensated, distance_quality)
/**
 * Sends a OPTICAL_FLOW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _time_sec 
 * @param _sensor_id 
 * @param _flow_x 
 * @param _flow_y 
 * @param _flow_comp_m_x 
 * @param _flow_comp_m_y 
 * @param _flow_quality 
 * @param _ground_distance 
 * @param _distance_compensated 
 * @param _distance_quality 
 */
static inline void pprz_msg_send_OPTICAL_FLOW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_time_sec, uint8_t *_sensor_id, int32_t *_flow_x, int32_t *_flow_y, float *_flow_comp_m_x, float *_flow_comp_m_y, uint8_t *_flow_quality, float *_ground_distance, float *_distance_compensated, uint8_t *_distance_quality) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_OPTICAL_FLOW(&msg,_time_sec,_sensor_id,_flow_x,_flow_y,_flow_comp_m_x,_flow_comp_m_y,_flow_quality,_ground_distance,_distance_compensated,_distance_quality);
}


#else // DOWNLINK

#define DOWNLINK_SEND_OPTICAL_FLOW(_trans, _dev, time_sec, sensor_id, flow_x, flow_y, flow_comp_m_x, flow_comp_m_y, flow_quality, ground_distance, distance_compensated, distance_quality) {}
static inline void pprz_send_msg_OPTICAL_FLOW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_time_sec __attribute__((unused)), uint8_t *_sensor_id __attribute__((unused)), int32_t *_flow_x __attribute__((unused)), int32_t *_flow_y __attribute__((unused)), float *_flow_comp_m_x __attribute__((unused)), float *_flow_comp_m_y __attribute__((unused)), uint8_t *_flow_quality __attribute__((unused)), float *_ground_distance __attribute__((unused)), float *_distance_compensated __attribute__((unused)), uint8_t *_distance_quality __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field time_sec in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_time_sec(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field sensor_id in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_OPTICAL_FLOW_sensor_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field flow_x in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_OPTICAL_FLOW_flow_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field flow_y in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_OPTICAL_FLOW_flow_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 13);
}


/** Getter for field flow_comp_m_x in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_flow_comp_m_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 17);
}


/** Getter for field flow_comp_m_y in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_flow_comp_m_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 21);
}


/** Getter for field flow_quality in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_OPTICAL_FLOW_flow_quality(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 25);
}


/** Getter for field ground_distance in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_ground_distance(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/** Getter for field distance_compensated in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_distance_compensated(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 30);
}


/** Getter for field distance_quality in message OPTICAL_FLOW
  *
  * @param _payload : a pointer to the OPTICAL_FLOW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_OPTICAL_FLOW_distance_quality(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 34);
}


/* Compatibility macros */
#define DL_OPTICAL_FLOW_time_sec(_payload) pprzlink_get_DL_OPTICAL_FLOW_time_sec(_payload)
#define DL_OPTICAL_FLOW_sensor_id(_payload) pprzlink_get_DL_OPTICAL_FLOW_sensor_id(_payload)
#define DL_OPTICAL_FLOW_flow_x(_payload) pprzlink_get_DL_OPTICAL_FLOW_flow_x(_payload)
#define DL_OPTICAL_FLOW_flow_y(_payload) pprzlink_get_DL_OPTICAL_FLOW_flow_y(_payload)
#define DL_OPTICAL_FLOW_flow_comp_m_x(_payload) pprzlink_get_DL_OPTICAL_FLOW_flow_comp_m_x(_payload)
#define DL_OPTICAL_FLOW_flow_comp_m_y(_payload) pprzlink_get_DL_OPTICAL_FLOW_flow_comp_m_y(_payload)
#define DL_OPTICAL_FLOW_flow_quality(_payload) pprzlink_get_DL_OPTICAL_FLOW_flow_quality(_payload)
#define DL_OPTICAL_FLOW_ground_distance(_payload) pprzlink_get_DL_OPTICAL_FLOW_ground_distance(_payload)
#define DL_OPTICAL_FLOW_distance_compensated(_payload) pprzlink_get_DL_OPTICAL_FLOW_distance_compensated(_payload)
#define DL_OPTICAL_FLOW_distance_quality(_payload) pprzlink_get_DL_OPTICAL_FLOW_distance_quality(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_OPTICAL_FLOW_H_

