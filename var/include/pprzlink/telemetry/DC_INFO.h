/** @file
 *  @brief PPRZLink message header for DC_INFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DC_INFO_H_
#define _VAR_MESSAGES_telemetry_DC_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DC_INFO 64
#define PPRZ_MSG_ID_DC_INFO 64

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DC_INFO _send_msg(DC_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DC_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _mode 
 * @param _lat 
 * @param _lon 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _course 
 * @param _photo_nr 
 * @param _dist 
 * @param _next_dist 
 * @param _start_x 
 * @param _start_y 
 * @param _start_angle 
 * @param _angle 
 * @param _last_block 
 * @param _count 
 * @param _shutter 
 */
static inline void pprzlink_msg_v2_send_DC_INFO(struct pprzlink_msg * msg, int16_t *_mode, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_course, uint16_t *_photo_nr, float *_dist, float *_next_dist, float *_start_x, float *_start_y, float *_start_angle, float *_angle, float *_last_block, uint16_t *_count, uint8_t *_shutter) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+2+4+4+4+4+4+4+4+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+2+4+4+4+4+4+4+4+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DC_INFO, "DC_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mode, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _photo_nr, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _dist, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _next_dist, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _start_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _start_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _start_angle, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angle, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _last_block, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _count, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _shutter, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DC_INFO pprz_msg_send_DC_INFO
#define DOWNLINK_SEND_DC_INFO(_trans, _dev, mode, lat, lon, alt, course, photo_nr, dist, next_dist, start_x, start_y, start_angle, angle, last_block, count, shutter) pprz_msg_send_DC_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, mode, lat, lon, alt, course, photo_nr, dist, next_dist, start_x, start_y, start_angle, angle, last_block, count, shutter)
/**
 * Sends a DC_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _mode 
 * @param _lat 
 * @param _lon 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _course 
 * @param _photo_nr 
 * @param _dist 
 * @param _next_dist 
 * @param _start_x 
 * @param _start_y 
 * @param _start_angle 
 * @param _angle 
 * @param _last_block 
 * @param _count 
 * @param _shutter 
 */
static inline void pprz_msg_send_DC_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_mode, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_course, uint16_t *_photo_nr, float *_dist, float *_next_dist, float *_start_x, float *_start_y, float *_start_angle, float *_angle, float *_last_block, uint16_t *_count, uint8_t *_shutter) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DC_INFO(&msg,_mode,_lat,_lon,_alt,_course,_photo_nr,_dist,_next_dist,_start_x,_start_y,_start_angle,_angle,_last_block,_count,_shutter);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DC_INFO(_trans, _dev, mode, lat, lon, alt, course, photo_nr, dist, next_dist, start_x, start_y, start_angle, angle, last_block, count, shutter) {}
static inline void pprz_send_msg_DC_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_mode __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), float *_course __attribute__((unused)), uint16_t *_photo_nr __attribute__((unused)), float *_dist __attribute__((unused)), float *_next_dist __attribute__((unused)), float *_start_x __attribute__((unused)), float *_start_y __attribute__((unused)), float *_start_angle __attribute__((unused)), float *_angle __attribute__((unused)), float *_last_block __attribute__((unused)), uint16_t *_count __attribute__((unused)), uint8_t *_shutter __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field mode in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline int16_t pprzlink_get_DL_DC_INFO_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field lat in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline int32_t pprzlink_get_DL_DC_INFO_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field lon in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline int32_t pprzlink_get_DL_DC_INFO_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field alt in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return altitude above WGS84 reference ellipsoid
  */
static inline int32_t pprzlink_get_DL_DC_INFO_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field course in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field photo_nr in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DC_INFO_photo_nr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field dist in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_dist(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field next_dist in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_next_dist(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field start_x in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_start_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field start_y in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_start_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field start_angle in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_start_angle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field angle in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_angle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field last_block in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_DC_INFO_last_block(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field count in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DC_INFO_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 52);
}


/** Getter for field shutter in message DC_INFO
  *
  * @param _payload : a pointer to the DC_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_DC_INFO_shutter(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 54);
}


/* Compatibility macros */
#define DL_DC_INFO_mode(_payload) pprzlink_get_DL_DC_INFO_mode(_payload)
#define DL_DC_INFO_lat(_payload) pprzlink_get_DL_DC_INFO_lat(_payload)
#define DL_DC_INFO_lon(_payload) pprzlink_get_DL_DC_INFO_lon(_payload)
#define DL_DC_INFO_alt(_payload) pprzlink_get_DL_DC_INFO_alt(_payload)
#define DL_DC_INFO_course(_payload) pprzlink_get_DL_DC_INFO_course(_payload)
#define DL_DC_INFO_photo_nr(_payload) pprzlink_get_DL_DC_INFO_photo_nr(_payload)
#define DL_DC_INFO_dist(_payload) pprzlink_get_DL_DC_INFO_dist(_payload)
#define DL_DC_INFO_next_dist(_payload) pprzlink_get_DL_DC_INFO_next_dist(_payload)
#define DL_DC_INFO_start_x(_payload) pprzlink_get_DL_DC_INFO_start_x(_payload)
#define DL_DC_INFO_start_y(_payload) pprzlink_get_DL_DC_INFO_start_y(_payload)
#define DL_DC_INFO_start_angle(_payload) pprzlink_get_DL_DC_INFO_start_angle(_payload)
#define DL_DC_INFO_angle(_payload) pprzlink_get_DL_DC_INFO_angle(_payload)
#define DL_DC_INFO_last_block(_payload) pprzlink_get_DL_DC_INFO_last_block(_payload)
#define DL_DC_INFO_count(_payload) pprzlink_get_DL_DC_INFO_count(_payload)
#define DL_DC_INFO_shutter(_payload) pprzlink_get_DL_DC_INFO_shutter(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DC_INFO_H_

