/** @file
 *  @brief PPRZLink message header for DC_SHOT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DC_SHOT_H_
#define _VAR_MESSAGES_telemetry_DC_SHOT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DC_SHOT 110
#define PPRZ_MSG_ID_DC_SHOT 110

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DC_SHOT _send_msg(DC_SHOT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DC_SHOT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _photo_nr 
 * @param _lat Gedetic latitude
 * @param _lon Longitude
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _phi Euler angle around x-axis (roll)
 * @param _theta Euler angle around y-axis (pitch)
 * @param _psi Euler angle around z-axis (yaw)
 * @param _course Course over ground (CW/north)
 * @param _speed horizontal ground speed
 * @param _itow GPS time of week
 */
static inline void pprzlink_msg_v2_send_DC_SHOT(struct pprzlink_msg * msg, int16_t *_photo_nr, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int16_t *_phi, int16_t *_theta, int16_t *_psi, int16_t *_course, uint16_t *_speed, uint32_t *_itow) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+2+2+2+2+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+2+2+2+2+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DC_SHOT, "DC_SHOT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _photo_nr, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _phi, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _theta, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _psi, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _course, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _speed, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _itow, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DC_SHOT pprz_msg_send_DC_SHOT
#define DOWNLINK_SEND_DC_SHOT(_trans, _dev, photo_nr, lat, lon, alt, hmsl, phi, theta, psi, course, speed, itow) pprz_msg_send_DC_SHOT(&((_trans).trans_tx), &((_dev).device), AC_ID, photo_nr, lat, lon, alt, hmsl, phi, theta, psi, course, speed, itow)
/**
 * Sends a DC_SHOT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _photo_nr 
 * @param _lat Gedetic latitude
 * @param _lon Longitude
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _phi Euler angle around x-axis (roll)
 * @param _theta Euler angle around y-axis (pitch)
 * @param _psi Euler angle around z-axis (yaw)
 * @param _course Course over ground (CW/north)
 * @param _speed horizontal ground speed
 * @param _itow GPS time of week
 */
static inline void pprz_msg_send_DC_SHOT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_photo_nr, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int16_t *_phi, int16_t *_theta, int16_t *_psi, int16_t *_course, uint16_t *_speed, uint32_t *_itow) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DC_SHOT(&msg,_photo_nr,_lat,_lon,_alt,_hmsl,_phi,_theta,_psi,_course,_speed,_itow);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DC_SHOT(_trans, _dev, photo_nr, lat, lon, alt, hmsl, phi, theta, psi, course, speed, itow) {}
static inline void pprz_send_msg_DC_SHOT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_photo_nr __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), int16_t *_phi __attribute__((unused)), int16_t *_theta __attribute__((unused)), int16_t *_psi __attribute__((unused)), int16_t *_course __attribute__((unused)), uint16_t *_speed __attribute__((unused)), uint32_t *_itow __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field photo_nr in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return 
  */
static inline int16_t pprzlink_get_DL_DC_SHOT_photo_nr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field lat in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Gedetic latitude
  */
static inline int32_t pprzlink_get_DL_DC_SHOT_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field lon in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Longitude
  */
static inline int32_t pprzlink_get_DL_DC_SHOT_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field alt in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return altitude above WGS84 reference ellipsoid
  */
static inline int32_t pprzlink_get_DL_DC_SHOT_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field hmsl in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_DC_SHOT_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field phi in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Euler angle around x-axis (roll)
  */
static inline int16_t pprzlink_get_DL_DC_SHOT_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 22);
}


/** Getter for field theta in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Euler angle around y-axis (pitch)
  */
static inline int16_t pprzlink_get_DL_DC_SHOT_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 24);
}


/** Getter for field psi in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Euler angle around z-axis (yaw)
  */
static inline int16_t pprzlink_get_DL_DC_SHOT_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 26);
}


/** Getter for field course in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return Course over ground (CW/north)
  */
static inline int16_t pprzlink_get_DL_DC_SHOT_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 28);
}


/** Getter for field speed in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return horizontal ground speed
  */
static inline uint16_t pprzlink_get_DL_DC_SHOT_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 30);
}


/** Getter for field itow in message DC_SHOT
  *
  * @param _payload : a pointer to the DC_SHOT message
  * @return GPS time of week
  */
static inline uint32_t pprzlink_get_DL_DC_SHOT_itow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 32);
}


/* Compatibility macros */
#define DL_DC_SHOT_photo_nr(_payload) pprzlink_get_DL_DC_SHOT_photo_nr(_payload)
#define DL_DC_SHOT_lat(_payload) pprzlink_get_DL_DC_SHOT_lat(_payload)
#define DL_DC_SHOT_lon(_payload) pprzlink_get_DL_DC_SHOT_lon(_payload)
#define DL_DC_SHOT_alt(_payload) pprzlink_get_DL_DC_SHOT_alt(_payload)
#define DL_DC_SHOT_hmsl(_payload) pprzlink_get_DL_DC_SHOT_hmsl(_payload)
#define DL_DC_SHOT_phi(_payload) pprzlink_get_DL_DC_SHOT_phi(_payload)
#define DL_DC_SHOT_theta(_payload) pprzlink_get_DL_DC_SHOT_theta(_payload)
#define DL_DC_SHOT_psi(_payload) pprzlink_get_DL_DC_SHOT_psi(_payload)
#define DL_DC_SHOT_course(_payload) pprzlink_get_DL_DC_SHOT_course(_payload)
#define DL_DC_SHOT_speed(_payload) pprzlink_get_DL_DC_SHOT_speed(_payload)
#define DL_DC_SHOT_itow(_payload) pprzlink_get_DL_DC_SHOT_itow(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DC_SHOT_H_

