/** @file
 *  @brief PPRZLink message header for RLFILTER in class telemetry
 *
 *  Relative localization data for other tracked MAVs in terms of x y and z in the body axis
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RLFILTER_H_
#define _VAR_MESSAGES_telemetry_RLFILTER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RLFILTER 48
#define PPRZ_MSG_ID_RLFILTER 48

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RLFILTER _send_msg(RLFILTER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RLFILTER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _trackedID 
 * @param _rangearray 
 * @param _x_tracked 
 * @param _y_tracked 
 * @param _vx_own 
 * @param _vy_own 
 * @param _vx_tracked 
 * @param _vy_tracked 
 * @param _z_pos 
 */
static inline void pprzlink_msg_v2_send_RLFILTER(struct pprzlink_msg * msg, int32_t *_trackedID, float *_rangearray, float *_x_tracked, float *_y_tracked, float *_vx_own, float *_vy_own, float *_vx_tracked, float *_vy_tracked, float *_z_pos) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RLFILTER, "RLFILTER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _trackedID, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rangearray, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x_tracked, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y_tracked, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vx_own, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vy_own, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vx_tracked, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vy_tracked, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_pos, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RLFILTER pprz_msg_send_RLFILTER
#define DOWNLINK_SEND_RLFILTER(_trans, _dev, trackedID, rangearray, x_tracked, y_tracked, vx_own, vy_own, vx_tracked, vy_tracked, z_pos) pprz_msg_send_RLFILTER(&((_trans).trans_tx), &((_dev).device), AC_ID, trackedID, rangearray, x_tracked, y_tracked, vx_own, vy_own, vx_tracked, vy_tracked, z_pos)
/**
 * Sends a RLFILTER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _trackedID 
 * @param _rangearray 
 * @param _x_tracked 
 * @param _y_tracked 
 * @param _vx_own 
 * @param _vy_own 
 * @param _vx_tracked 
 * @param _vy_tracked 
 * @param _z_pos 
 */
static inline void pprz_msg_send_RLFILTER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_trackedID, float *_rangearray, float *_x_tracked, float *_y_tracked, float *_vx_own, float *_vy_own, float *_vx_tracked, float *_vy_tracked, float *_z_pos) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RLFILTER(&msg,_trackedID,_rangearray,_x_tracked,_y_tracked,_vx_own,_vy_own,_vx_tracked,_vy_tracked,_z_pos);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RLFILTER(_trans, _dev, trackedID, rangearray, x_tracked, y_tracked, vx_own, vy_own, vx_tracked, vy_tracked, z_pos) {}
static inline void pprz_send_msg_RLFILTER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_trackedID __attribute__((unused)), float *_rangearray __attribute__((unused)), float *_x_tracked __attribute__((unused)), float *_y_tracked __attribute__((unused)), float *_vx_own __attribute__((unused)), float *_vy_own __attribute__((unused)), float *_vx_tracked __attribute__((unused)), float *_vy_tracked __attribute__((unused)), float *_z_pos __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field trackedID in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_RLFILTER_trackedID(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field rangearray in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_rangearray(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field x_tracked in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_x_tracked(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field y_tracked in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_y_tracked(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field vx_own in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_vx_own(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field vy_own in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_vy_own(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field vx_tracked in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_vx_tracked(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field vy_tracked in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_vy_tracked(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field z_pos in message RLFILTER
  *
  * @param _payload : a pointer to the RLFILTER message
  * @return 
  */
static inline float pprzlink_get_DL_RLFILTER_z_pos(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/* Compatibility macros */
#define DL_RLFILTER_trackedID(_payload) pprzlink_get_DL_RLFILTER_trackedID(_payload)
#define DL_RLFILTER_rangearray(_payload) pprzlink_get_DL_RLFILTER_rangearray(_payload)
#define DL_RLFILTER_x_tracked(_payload) pprzlink_get_DL_RLFILTER_x_tracked(_payload)
#define DL_RLFILTER_y_tracked(_payload) pprzlink_get_DL_RLFILTER_y_tracked(_payload)
#define DL_RLFILTER_vx_own(_payload) pprzlink_get_DL_RLFILTER_vx_own(_payload)
#define DL_RLFILTER_vy_own(_payload) pprzlink_get_DL_RLFILTER_vy_own(_payload)
#define DL_RLFILTER_vx_tracked(_payload) pprzlink_get_DL_RLFILTER_vx_tracked(_payload)
#define DL_RLFILTER_vy_tracked(_payload) pprzlink_get_DL_RLFILTER_vy_tracked(_payload)
#define DL_RLFILTER_z_pos(_payload) pprzlink_get_DL_RLFILTER_z_pos(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RLFILTER_H_

