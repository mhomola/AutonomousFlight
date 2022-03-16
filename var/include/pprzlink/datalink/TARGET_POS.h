/** @file
 *  @brief PPRZLink message header for TARGET_POS in class datalink
 *
 *  
        Global position, speed and ID a target for functions like Follow Me
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_TARGET_POS_H_
#define _VAR_MESSAGES_datalink_TARGET_POS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TARGET_POS 57
#define PPRZ_MSG_ID_TARGET_POS 57

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TARGET_POS _send_msg(TARGET_POS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TARGET_POS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _target_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _speed Ground speed
 * @param _climb Climb speed
 * @param _course 
 */
static inline void pprzlink_msg_v2_send_TARGET_POS(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_target_id, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_speed, float *_climb, float *_course) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TARGET_POS, "TARGET_POS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _target_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TARGET_POS pprz_msg_send_TARGET_POS
#define DOWNLINK_SEND_TARGET_POS(_trans, _dev, ac_id, target_id, lat, lon, alt, speed, climb, course) pprz_msg_send_TARGET_POS(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, target_id, lat, lon, alt, speed, climb, course)
/**
 * Sends a TARGET_POS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _target_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _speed Ground speed
 * @param _climb Climb speed
 * @param _course 
 */
static inline void pprz_msg_send_TARGET_POS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_target_id, int32_t *_lat, int32_t *_lon, int32_t *_alt, float *_speed, float *_climb, float *_course) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TARGET_POS(&msg,_ac_id,_target_id,_lat,_lon,_alt,_speed,_climb,_course);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TARGET_POS(_trans, _dev, ac_id, target_id, lat, lon, alt, speed, climb, course) {}
static inline void pprz_send_msg_TARGET_POS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_target_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), float *_speed __attribute__((unused)), float *_climb __attribute__((unused)), float *_course __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_TARGET_POS_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field target_id in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_TARGET_POS_target_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field lat in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field lon in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field alt in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_TARGET_POS_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field speed in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return Ground speed
  */
static inline float pprzlink_get_DL_TARGET_POS_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field climb in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return Climb speed
  */
static inline float pprzlink_get_DL_TARGET_POS_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field course in message TARGET_POS
  *
  * @param _payload : a pointer to the TARGET_POS message
  * @return 
  */
static inline float pprzlink_get_DL_TARGET_POS_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/* Compatibility macros */
#define DL_TARGET_POS_ac_id(_payload) pprzlink_get_DL_TARGET_POS_ac_id(_payload)
#define DL_TARGET_POS_target_id(_payload) pprzlink_get_DL_TARGET_POS_target_id(_payload)
#define DL_TARGET_POS_lat(_payload) pprzlink_get_DL_TARGET_POS_lat(_payload)
#define DL_TARGET_POS_lon(_payload) pprzlink_get_DL_TARGET_POS_lon(_payload)
#define DL_TARGET_POS_alt(_payload) pprzlink_get_DL_TARGET_POS_alt(_payload)
#define DL_TARGET_POS_speed(_payload) pprzlink_get_DL_TARGET_POS_speed(_payload)
#define DL_TARGET_POS_climb(_payload) pprzlink_get_DL_TARGET_POS_climb(_payload)
#define DL_TARGET_POS_course(_payload) pprzlink_get_DL_TARGET_POS_course(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_TARGET_POS_H_

