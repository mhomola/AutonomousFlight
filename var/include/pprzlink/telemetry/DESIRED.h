/** @file
 *  @brief PPRZLink message header for DESIRED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DESIRED_H_
#define _VAR_MESSAGES_telemetry_DESIRED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DESIRED 16
#define PPRZ_MSG_ID_DESIRED 16

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DESIRED _send_msg(DESIRED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DESIRED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _roll 
 * @param _pitch 
 * @param _course 
 * @param _x 
 * @param _y 
 * @param _altitude 
 * @param _climb 
 * @param _airspeed 
 */
static inline void pprzlink_msg_v2_send_DESIRED(struct pprzlink_msg * msg, float *_roll, float *_pitch, float *_course, float *_x, float *_y, float *_altitude, float *_climb, float *_airspeed) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DESIRED, "DESIRED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _roll, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitch, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _altitude, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DESIRED pprz_msg_send_DESIRED
#define DOWNLINK_SEND_DESIRED(_trans, _dev, roll, pitch, course, x, y, altitude, climb, airspeed) pprz_msg_send_DESIRED(&((_trans).trans_tx), &((_dev).device), AC_ID, roll, pitch, course, x, y, altitude, climb, airspeed)
/**
 * Sends a DESIRED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _roll 
 * @param _pitch 
 * @param _course 
 * @param _x 
 * @param _y 
 * @param _altitude 
 * @param _climb 
 * @param _airspeed 
 */
static inline void pprz_msg_send_DESIRED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_roll, float *_pitch, float *_course, float *_x, float *_y, float *_altitude, float *_climb, float *_airspeed) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DESIRED(&msg,_roll,_pitch,_course,_x,_y,_altitude,_climb,_airspeed);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DESIRED(_trans, _dev, roll, pitch, course, x, y, altitude, climb, airspeed) {}
static inline void pprz_send_msg_DESIRED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_roll __attribute__((unused)), float *_pitch __attribute__((unused)), float *_course __attribute__((unused)), float *_x __attribute__((unused)), float *_y __attribute__((unused)), float *_altitude __attribute__((unused)), float *_climb __attribute__((unused)), float *_airspeed __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field roll in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field pitch in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field course in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field x in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field y in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field altitude in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_altitude(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field climb in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field airspeed in message DESIRED
  *
  * @param _payload : a pointer to the DESIRED message
  * @return 
  */
static inline float pprzlink_get_DL_DESIRED_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/* Compatibility macros */
#define DL_DESIRED_roll(_payload) pprzlink_get_DL_DESIRED_roll(_payload)
#define DL_DESIRED_pitch(_payload) pprzlink_get_DL_DESIRED_pitch(_payload)
#define DL_DESIRED_course(_payload) pprzlink_get_DL_DESIRED_course(_payload)
#define DL_DESIRED_x(_payload) pprzlink_get_DL_DESIRED_x(_payload)
#define DL_DESIRED_y(_payload) pprzlink_get_DL_DESIRED_y(_payload)
#define DL_DESIRED_altitude(_payload) pprzlink_get_DL_DESIRED_altitude(_payload)
#define DL_DESIRED_climb(_payload) pprzlink_get_DL_DESIRED_climb(_payload)
#define DL_DESIRED_airspeed(_payload) pprzlink_get_DL_DESIRED_airspeed(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DESIRED_H_

