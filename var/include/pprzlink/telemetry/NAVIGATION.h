/** @file
 *  @brief PPRZLink message header for NAVIGATION in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NAVIGATION_H_
#define _VAR_MESSAGES_telemetry_NAVIGATION_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NAVIGATION 10
#define PPRZ_MSG_ID_NAVIGATION 10

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NAVIGATION _send_msg(NAVIGATION,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NAVIGATION message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cur_block 
 * @param _cur_stage 
 * @param _pos_x 
 * @param _pos_y 
 * @param _dist_wp 
 * @param _dist_home 
 * @param _flight_time 
 * @param _block_time 
 * @param _stage_time 
 * @param _kill_auto_throttle 
 * @param _circle_count 
 * @param _oval_count 
 */
static inline void pprzlink_msg_v2_send_NAVIGATION(struct pprzlink_msg * msg, uint8_t *_cur_block, uint8_t *_cur_stage, float *_pos_x, float *_pos_y, float *_dist_wp, float *_dist_home, uint16_t *_flight_time, uint16_t *_block_time, uint16_t *_stage_time, uint8_t *_kill_auto_throttle, uint8_t *_circle_count, uint8_t *_oval_count) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+2+2+2+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+2+2+2+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NAVIGATION, "NAVIGATION");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cur_block, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cur_stage, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pos_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _dist_wp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _dist_home, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flight_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _block_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _stage_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _kill_auto_throttle, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _circle_count, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _oval_count, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NAVIGATION pprz_msg_send_NAVIGATION
#define DOWNLINK_SEND_NAVIGATION(_trans, _dev, cur_block, cur_stage, pos_x, pos_y, dist_wp, dist_home, flight_time, block_time, stage_time, kill_auto_throttle, circle_count, oval_count) pprz_msg_send_NAVIGATION(&((_trans).trans_tx), &((_dev).device), AC_ID, cur_block, cur_stage, pos_x, pos_y, dist_wp, dist_home, flight_time, block_time, stage_time, kill_auto_throttle, circle_count, oval_count)
/**
 * Sends a NAVIGATION message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cur_block 
 * @param _cur_stage 
 * @param _pos_x 
 * @param _pos_y 
 * @param _dist_wp 
 * @param _dist_home 
 * @param _flight_time 
 * @param _block_time 
 * @param _stage_time 
 * @param _kill_auto_throttle 
 * @param _circle_count 
 * @param _oval_count 
 */
static inline void pprz_msg_send_NAVIGATION(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_cur_block, uint8_t *_cur_stage, float *_pos_x, float *_pos_y, float *_dist_wp, float *_dist_home, uint16_t *_flight_time, uint16_t *_block_time, uint16_t *_stage_time, uint8_t *_kill_auto_throttle, uint8_t *_circle_count, uint8_t *_oval_count) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NAVIGATION(&msg,_cur_block,_cur_stage,_pos_x,_pos_y,_dist_wp,_dist_home,_flight_time,_block_time,_stage_time,_kill_auto_throttle,_circle_count,_oval_count);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NAVIGATION(_trans, _dev, cur_block, cur_stage, pos_x, pos_y, dist_wp, dist_home, flight_time, block_time, stage_time, kill_auto_throttle, circle_count, oval_count) {}
static inline void pprz_send_msg_NAVIGATION(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_cur_block __attribute__((unused)), uint8_t *_cur_stage __attribute__((unused)), float *_pos_x __attribute__((unused)), float *_pos_y __attribute__((unused)), float *_dist_wp __attribute__((unused)), float *_dist_home __attribute__((unused)), uint16_t *_flight_time __attribute__((unused)), uint16_t *_block_time __attribute__((unused)), uint16_t *_stage_time __attribute__((unused)), uint8_t *_kill_auto_throttle __attribute__((unused)), uint8_t *_circle_count __attribute__((unused)), uint8_t *_oval_count __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cur_block in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_cur_block(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field cur_stage in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_cur_stage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field pos_x in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline float pprzlink_get_DL_NAVIGATION_pos_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field pos_y in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline float pprzlink_get_DL_NAVIGATION_pos_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field dist_wp in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline float pprzlink_get_DL_NAVIGATION_dist_wp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field dist_home in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline float pprzlink_get_DL_NAVIGATION_dist_home(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field flight_time in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_NAVIGATION_flight_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field block_time in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_NAVIGATION_block_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 24);
}


/** Getter for field stage_time in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_NAVIGATION_stage_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 26);
}


/** Getter for field kill_auto_throttle in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_kill_auto_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 28);
}


/** Getter for field circle_count in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_circle_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 29);
}


/** Getter for field oval_count in message NAVIGATION
  *
  * @param _payload : a pointer to the NAVIGATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_oval_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 30);
}


/* Compatibility macros */
#define DL_NAVIGATION_cur_block(_payload) pprzlink_get_DL_NAVIGATION_cur_block(_payload)
#define DL_NAVIGATION_cur_stage(_payload) pprzlink_get_DL_NAVIGATION_cur_stage(_payload)
#define DL_NAVIGATION_pos_x(_payload) pprzlink_get_DL_NAVIGATION_pos_x(_payload)
#define DL_NAVIGATION_pos_y(_payload) pprzlink_get_DL_NAVIGATION_pos_y(_payload)
#define DL_NAVIGATION_dist_wp(_payload) pprzlink_get_DL_NAVIGATION_dist_wp(_payload)
#define DL_NAVIGATION_dist_home(_payload) pprzlink_get_DL_NAVIGATION_dist_home(_payload)
#define DL_NAVIGATION_flight_time(_payload) pprzlink_get_DL_NAVIGATION_flight_time(_payload)
#define DL_NAVIGATION_block_time(_payload) pprzlink_get_DL_NAVIGATION_block_time(_payload)
#define DL_NAVIGATION_stage_time(_payload) pprzlink_get_DL_NAVIGATION_stage_time(_payload)
#define DL_NAVIGATION_kill_auto_throttle(_payload) pprzlink_get_DL_NAVIGATION_kill_auto_throttle(_payload)
#define DL_NAVIGATION_circle_count(_payload) pprzlink_get_DL_NAVIGATION_circle_count(_payload)
#define DL_NAVIGATION_oval_count(_payload) pprzlink_get_DL_NAVIGATION_oval_count(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NAVIGATION_H_

