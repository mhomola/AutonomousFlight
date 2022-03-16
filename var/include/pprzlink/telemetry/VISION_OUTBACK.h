/** @file
 *  @brief PPRZLink message header for VISION_OUTBACK in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VISION_OUTBACK_H_
#define _VAR_MESSAGES_telemetry_VISION_OUTBACK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VISION_OUTBACK 58
#define PPRZ_MSG_ID_VISION_OUTBACK 58

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VISION_OUTBACK _send_msg(VISION_OUTBACK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VISION_OUTBACK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _status 
 * @param _het_moment 
 * @param _timeoutcount 
 * @param _vision_timeout 
 * @param _height 
 * @param _out_of_range 
 * @param _marker_enu_x 
 * @param _marker_enu_y 
 * @param _flow_x 
 * @param _flow_y 
 */
static inline void pprzlink_msg_v2_send_VISION_OUTBACK(struct pprzlink_msg * msg, uint8_t *_status, uint8_t *_het_moment, uint8_t *_timeoutcount, uint8_t *_vision_timeout, float *_height, float *_out_of_range, float *_marker_enu_x, float *_marker_enu_y, float *_flow_x, float *_flow_y) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VISION_OUTBACK, "VISION_OUTBACK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _het_moment, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _timeoutcount, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _vision_timeout, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _height, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _out_of_range, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _marker_enu_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _marker_enu_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flow_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flow_y, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VISION_OUTBACK pprz_msg_send_VISION_OUTBACK
#define DOWNLINK_SEND_VISION_OUTBACK(_trans, _dev, status, het_moment, timeoutcount, vision_timeout, height, out_of_range, marker_enu_x, marker_enu_y, flow_x, flow_y) pprz_msg_send_VISION_OUTBACK(&((_trans).trans_tx), &((_dev).device), AC_ID, status, het_moment, timeoutcount, vision_timeout, height, out_of_range, marker_enu_x, marker_enu_y, flow_x, flow_y)
/**
 * Sends a VISION_OUTBACK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _status 
 * @param _het_moment 
 * @param _timeoutcount 
 * @param _vision_timeout 
 * @param _height 
 * @param _out_of_range 
 * @param _marker_enu_x 
 * @param _marker_enu_y 
 * @param _flow_x 
 * @param _flow_y 
 */
static inline void pprz_msg_send_VISION_OUTBACK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_status, uint8_t *_het_moment, uint8_t *_timeoutcount, uint8_t *_vision_timeout, float *_height, float *_out_of_range, float *_marker_enu_x, float *_marker_enu_y, float *_flow_x, float *_flow_y) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VISION_OUTBACK(&msg,_status,_het_moment,_timeoutcount,_vision_timeout,_height,_out_of_range,_marker_enu_x,_marker_enu_y,_flow_x,_flow_y);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VISION_OUTBACK(_trans, _dev, status, het_moment, timeoutcount, vision_timeout, height, out_of_range, marker_enu_x, marker_enu_y, flow_x, flow_y) {}
static inline void pprz_send_msg_VISION_OUTBACK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_status __attribute__((unused)), uint8_t *_het_moment __attribute__((unused)), uint8_t *_timeoutcount __attribute__((unused)), uint8_t *_vision_timeout __attribute__((unused)), float *_height __attribute__((unused)), float *_out_of_range __attribute__((unused)), float *_marker_enu_x __attribute__((unused)), float *_marker_enu_y __attribute__((unused)), float *_flow_x __attribute__((unused)), float *_flow_y __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field status in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VISION_OUTBACK_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field het_moment in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VISION_OUTBACK_het_moment(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field timeoutcount in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VISION_OUTBACK_timeoutcount(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field vision_timeout in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VISION_OUTBACK_vision_timeout(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/** Getter for field height in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_height(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field out_of_range in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_out_of_range(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field marker_enu_x in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_marker_enu_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field marker_enu_y in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_marker_enu_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field flow_x in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_flow_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field flow_y in message VISION_OUTBACK
  *
  * @param _payload : a pointer to the VISION_OUTBACK message
  * @return 
  */
static inline float pprzlink_get_DL_VISION_OUTBACK_flow_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_VISION_OUTBACK_status(_payload) pprzlink_get_DL_VISION_OUTBACK_status(_payload)
#define DL_VISION_OUTBACK_het_moment(_payload) pprzlink_get_DL_VISION_OUTBACK_het_moment(_payload)
#define DL_VISION_OUTBACK_timeoutcount(_payload) pprzlink_get_DL_VISION_OUTBACK_timeoutcount(_payload)
#define DL_VISION_OUTBACK_vision_timeout(_payload) pprzlink_get_DL_VISION_OUTBACK_vision_timeout(_payload)
#define DL_VISION_OUTBACK_height(_payload) pprzlink_get_DL_VISION_OUTBACK_height(_payload)
#define DL_VISION_OUTBACK_out_of_range(_payload) pprzlink_get_DL_VISION_OUTBACK_out_of_range(_payload)
#define DL_VISION_OUTBACK_marker_enu_x(_payload) pprzlink_get_DL_VISION_OUTBACK_marker_enu_x(_payload)
#define DL_VISION_OUTBACK_marker_enu_y(_payload) pprzlink_get_DL_VISION_OUTBACK_marker_enu_y(_payload)
#define DL_VISION_OUTBACK_flow_x(_payload) pprzlink_get_DL_VISION_OUTBACK_flow_x(_payload)
#define DL_VISION_OUTBACK_flow_y(_payload) pprzlink_get_DL_VISION_OUTBACK_flow_y(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VISION_OUTBACK_H_

