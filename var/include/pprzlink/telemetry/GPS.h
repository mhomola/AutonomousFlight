/** @file
 *  @brief PPRZLink message header for GPS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_H_
#define _VAR_MESSAGES_telemetry_GPS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS 8
#define PPRZ_MSG_ID_GPS 8

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS _send_msg(GPS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _mode 
 * @param _utm_east 
 * @param _utm_north 
 * @param _course 
 * @param _alt Altitude above geoid (MSL)
 * @param _speed norm of 2d ground speed in cm/s
 * @param _climb 
 * @param _week 
 * @param _itow 
 * @param _utm_zone 
 * @param _gps_nb_err 
 */
static inline void pprzlink_msg_v2_send_GPS(struct pprzlink_msg * msg, uint8_t *_mode, int32_t *_utm_east, int32_t *_utm_north, int16_t *_course, int32_t *_alt, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_utm_zone, uint8_t *_gps_nb_err) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+2+4+2+2+2+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+2+4+2+2+2+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS, "GPS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _utm_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _utm_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _course, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _speed, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _climb, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _week, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _itow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _utm_zone, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gps_nb_err, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS pprz_msg_send_GPS
#define DOWNLINK_SEND_GPS(_trans, _dev, mode, utm_east, utm_north, course, alt, speed, climb, week, itow, utm_zone, gps_nb_err) pprz_msg_send_GPS(&((_trans).trans_tx), &((_dev).device), AC_ID, mode, utm_east, utm_north, course, alt, speed, climb, week, itow, utm_zone, gps_nb_err)
/**
 * Sends a GPS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _mode 
 * @param _utm_east 
 * @param _utm_north 
 * @param _course 
 * @param _alt Altitude above geoid (MSL)
 * @param _speed norm of 2d ground speed in cm/s
 * @param _climb 
 * @param _week 
 * @param _itow 
 * @param _utm_zone 
 * @param _gps_nb_err 
 */
static inline void pprz_msg_send_GPS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_mode, int32_t *_utm_east, int32_t *_utm_north, int16_t *_course, int32_t *_alt, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_utm_zone, uint8_t *_gps_nb_err) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS(&msg,_mode,_utm_east,_utm_north,_course,_alt,_speed,_climb,_week,_itow,_utm_zone,_gps_nb_err);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS(_trans, _dev, mode, utm_east, utm_north, course, alt, speed, climb, week, itow, utm_zone, gps_nb_err) {}
static inline void pprz_send_msg_GPS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_mode __attribute__((unused)), int32_t *_utm_east __attribute__((unused)), int32_t *_utm_north __attribute__((unused)), int16_t *_course __attribute__((unused)), int32_t *_alt __attribute__((unused)), uint16_t *_speed __attribute__((unused)), int16_t *_climb __attribute__((unused)), uint16_t *_week __attribute__((unused)), uint32_t *_itow __attribute__((unused)), uint8_t *_utm_zone __attribute__((unused)), uint8_t *_gps_nb_err __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field mode in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field utm_east in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_utm_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 5);
}


/** Getter for field utm_north in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_utm_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field course in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_GPS_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 13);
}


/** Getter for field alt in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return Altitude above geoid (MSL)
  */
static inline int32_t pprzlink_get_DL_GPS_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 15);
}


/** Getter for field speed in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return norm of 2d ground speed in cm/s
  */
static inline uint16_t pprzlink_get_DL_GPS_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 19);
}


/** Getter for field climb in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_GPS_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 21);
}


/** Getter for field week in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GPS_week(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 23);
}


/** Getter for field itow in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_itow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 25);
}


/** Getter for field utm_zone in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_utm_zone(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 29);
}


/** Getter for field gps_nb_err in message GPS
  *
  * @param _payload : a pointer to the GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_gps_nb_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 30);
}


/* Compatibility macros */
#define DL_GPS_mode(_payload) pprzlink_get_DL_GPS_mode(_payload)
#define DL_GPS_utm_east(_payload) pprzlink_get_DL_GPS_utm_east(_payload)
#define DL_GPS_utm_north(_payload) pprzlink_get_DL_GPS_utm_north(_payload)
#define DL_GPS_course(_payload) pprzlink_get_DL_GPS_course(_payload)
#define DL_GPS_alt(_payload) pprzlink_get_DL_GPS_alt(_payload)
#define DL_GPS_speed(_payload) pprzlink_get_DL_GPS_speed(_payload)
#define DL_GPS_climb(_payload) pprzlink_get_DL_GPS_climb(_payload)
#define DL_GPS_week(_payload) pprzlink_get_DL_GPS_week(_payload)
#define DL_GPS_itow(_payload) pprzlink_get_DL_GPS_itow(_payload)
#define DL_GPS_utm_zone(_payload) pprzlink_get_DL_GPS_utm_zone(_payload)
#define DL_GPS_gps_nb_err(_payload) pprzlink_get_DL_GPS_gps_nb_err(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_H_

