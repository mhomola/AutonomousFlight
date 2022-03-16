/** @file
 *  @brief PPRZLink message header for MINIMAL_COM in class telemetry
 *
 *  
        Minimal information for correct display in the GCS, in particular the Strip
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MINIMAL_COM_H_
#define _VAR_MESSAGES_telemetry_MINIMAL_COM_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MINIMAL_COM 93
#define PPRZ_MSG_ID_MINIMAL_COM 93

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MINIMAL_COM _send_msg(MINIMAL_COM,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MINIMAL_COM message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat Lattitude
 * @param _lon Longitude
 * @param _hmsl Altitude above mean sea level
 * @param _gspeed Ground speed norm
 * @param _course Ground speed direction
 * @param _climb Vertical speed
 * @param _vsupply Battery voltage
 * @param _throttle Throttle level
 * @param _ap_mode Current autopilot mode
 * @param _nav_block Current navigation block
 * @param _gps_mode GPS fix flag
 * @param _flight_time Flight time
 */
static inline void pprzlink_msg_v2_send_MINIMAL_COM(struct pprzlink_msg * msg, float *_lat, float *_lon, float *_hmsl, float *_gspeed, float *_course, float *_climb, float *_vsupply, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint8_t *_gps_mode, uint16_t *_flight_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+1+1+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+1+1+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MINIMAL_COM, "MINIMAL_COM");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vsupply, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _throttle, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nav_block, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gps_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flight_time, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MINIMAL_COM pprz_msg_send_MINIMAL_COM
#define DOWNLINK_SEND_MINIMAL_COM(_trans, _dev, lat, lon, hmsl, gspeed, course, climb, vsupply, throttle, ap_mode, nav_block, gps_mode, flight_time) pprz_msg_send_MINIMAL_COM(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, hmsl, gspeed, course, climb, vsupply, throttle, ap_mode, nav_block, gps_mode, flight_time)
/**
 * Sends a MINIMAL_COM message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat Lattitude
 * @param _lon Longitude
 * @param _hmsl Altitude above mean sea level
 * @param _gspeed Ground speed norm
 * @param _course Ground speed direction
 * @param _climb Vertical speed
 * @param _vsupply Battery voltage
 * @param _throttle Throttle level
 * @param _ap_mode Current autopilot mode
 * @param _nav_block Current navigation block
 * @param _gps_mode GPS fix flag
 * @param _flight_time Flight time
 */
static inline void pprz_msg_send_MINIMAL_COM(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_lat, float *_lon, float *_hmsl, float *_gspeed, float *_course, float *_climb, float *_vsupply, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint8_t *_gps_mode, uint16_t *_flight_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MINIMAL_COM(&msg,_lat,_lon,_hmsl,_gspeed,_course,_climb,_vsupply,_throttle,_ap_mode,_nav_block,_gps_mode,_flight_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MINIMAL_COM(_trans, _dev, lat, lon, hmsl, gspeed, course, climb, vsupply, throttle, ap_mode, nav_block, gps_mode, flight_time) {}
static inline void pprz_send_msg_MINIMAL_COM(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_lat __attribute__((unused)), float *_lon __attribute__((unused)), float *_hmsl __attribute__((unused)), float *_gspeed __attribute__((unused)), float *_course __attribute__((unused)), float *_climb __attribute__((unused)), float *_vsupply __attribute__((unused)), uint8_t *_throttle __attribute__((unused)), uint8_t *_ap_mode __attribute__((unused)), uint8_t *_nav_block __attribute__((unused)), uint8_t *_gps_mode __attribute__((unused)), uint16_t *_flight_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Lattitude
  */
static inline float pprzlink_get_DL_MINIMAL_COM_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field lon in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Longitude
  */
static inline float pprzlink_get_DL_MINIMAL_COM_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field hmsl in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Altitude above mean sea level
  */
static inline float pprzlink_get_DL_MINIMAL_COM_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field gspeed in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Ground speed norm
  */
static inline float pprzlink_get_DL_MINIMAL_COM_gspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field course in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Ground speed direction
  */
static inline float pprzlink_get_DL_MINIMAL_COM_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field climb in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Vertical speed
  */
static inline float pprzlink_get_DL_MINIMAL_COM_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field vsupply in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Battery voltage
  */
static inline float pprzlink_get_DL_MINIMAL_COM_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field throttle in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Throttle level
  */
static inline uint8_t pprzlink_get_DL_MINIMAL_COM_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 32);
}


/** Getter for field ap_mode in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Current autopilot mode
  */
static inline uint8_t pprzlink_get_DL_MINIMAL_COM_ap_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 33);
}


/** Getter for field nav_block in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Current navigation block
  */
static inline uint8_t pprzlink_get_DL_MINIMAL_COM_nav_block(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 34);
}


/** Getter for field gps_mode in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return GPS fix flag
  */
static inline uint8_t pprzlink_get_DL_MINIMAL_COM_gps_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 35);
}


/** Getter for field flight_time in message MINIMAL_COM
  *
  * @param _payload : a pointer to the MINIMAL_COM message
  * @return Flight time
  */
static inline uint16_t pprzlink_get_DL_MINIMAL_COM_flight_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 36);
}


/* Compatibility macros */
#define DL_MINIMAL_COM_lat(_payload) pprzlink_get_DL_MINIMAL_COM_lat(_payload)
#define DL_MINIMAL_COM_lon(_payload) pprzlink_get_DL_MINIMAL_COM_lon(_payload)
#define DL_MINIMAL_COM_hmsl(_payload) pprzlink_get_DL_MINIMAL_COM_hmsl(_payload)
#define DL_MINIMAL_COM_gspeed(_payload) pprzlink_get_DL_MINIMAL_COM_gspeed(_payload)
#define DL_MINIMAL_COM_course(_payload) pprzlink_get_DL_MINIMAL_COM_course(_payload)
#define DL_MINIMAL_COM_climb(_payload) pprzlink_get_DL_MINIMAL_COM_climb(_payload)
#define DL_MINIMAL_COM_vsupply(_payload) pprzlink_get_DL_MINIMAL_COM_vsupply(_payload)
#define DL_MINIMAL_COM_throttle(_payload) pprzlink_get_DL_MINIMAL_COM_throttle(_payload)
#define DL_MINIMAL_COM_ap_mode(_payload) pprzlink_get_DL_MINIMAL_COM_ap_mode(_payload)
#define DL_MINIMAL_COM_nav_block(_payload) pprzlink_get_DL_MINIMAL_COM_nav_block(_payload)
#define DL_MINIMAL_COM_gps_mode(_payload) pprzlink_get_DL_MINIMAL_COM_gps_mode(_payload)
#define DL_MINIMAL_COM_flight_time(_payload) pprzlink_get_DL_MINIMAL_COM_flight_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MINIMAL_COM_H_

