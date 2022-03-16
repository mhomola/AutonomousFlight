/** @file
 *  @brief PPRZLink message header for METEO_STICK in class telemetry
 *
 *  
        Data from the MeteoSitck sensor board
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_METEO_STICK_H_
#define _VAR_MESSAGES_telemetry_METEO_STICK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_METEO_STICK 55
#define PPRZ_MSG_ID_METEO_STICK 55

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_METEO_STICK _send_msg(METEO_STICK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a METEO_STICK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat 
 * @param _lon 
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _itow GPS time of week
 * @param _pressure absolute static pressure
 * @param _temperature temperature
 * @param _humidity relative humidity
 * @param _airspeed calibrated airspeed
 */
static inline void pprzlink_msg_v2_send_METEO_STICK(struct pprzlink_msg * msg, int32_t *_lat, int32_t *_lon, int32_t *_hmsl, uint32_t *_itow, float *_pressure, float *_temperature, float *_humidity, float *_airspeed) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_METEO_STICK, "METEO_STICK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _itow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temperature, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _humidity, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_METEO_STICK pprz_msg_send_METEO_STICK
#define DOWNLINK_SEND_METEO_STICK(_trans, _dev, lat, lon, hmsl, itow, pressure, temperature, humidity, airspeed) pprz_msg_send_METEO_STICK(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, hmsl, itow, pressure, temperature, humidity, airspeed)
/**
 * Sends a METEO_STICK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat 
 * @param _lon 
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _itow GPS time of week
 * @param _pressure absolute static pressure
 * @param _temperature temperature
 * @param _humidity relative humidity
 * @param _airspeed calibrated airspeed
 */
static inline void pprz_msg_send_METEO_STICK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_lat, int32_t *_lon, int32_t *_hmsl, uint32_t *_itow, float *_pressure, float *_temperature, float *_humidity, float *_airspeed) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_METEO_STICK(&msg,_lat,_lon,_hmsl,_itow,_pressure,_temperature,_humidity,_airspeed);
}


#else // DOWNLINK

#define DOWNLINK_SEND_METEO_STICK(_trans, _dev, lat, lon, hmsl, itow, pressure, temperature, humidity, airspeed) {}
static inline void pprz_send_msg_METEO_STICK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), uint32_t *_itow __attribute__((unused)), float *_pressure __attribute__((unused)), float *_temperature __attribute__((unused)), float *_humidity __attribute__((unused)), float *_airspeed __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return 
  */
static inline int32_t pprzlink_get_DL_METEO_STICK_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field lon in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return 
  */
static inline int32_t pprzlink_get_DL_METEO_STICK_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field hmsl in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_METEO_STICK_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field itow in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return GPS time of week
  */
static inline uint32_t pprzlink_get_DL_METEO_STICK_itow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 16);
}


/** Getter for field pressure in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return absolute static pressure
  */
static inline float pprzlink_get_DL_METEO_STICK_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field temperature in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return temperature
  */
static inline float pprzlink_get_DL_METEO_STICK_temperature(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field humidity in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return relative humidity
  */
static inline float pprzlink_get_DL_METEO_STICK_humidity(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field airspeed in message METEO_STICK
  *
  * @param _payload : a pointer to the METEO_STICK message
  * @return calibrated airspeed
  */
static inline float pprzlink_get_DL_METEO_STICK_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/* Compatibility macros */
#define DL_METEO_STICK_lat(_payload) pprzlink_get_DL_METEO_STICK_lat(_payload)
#define DL_METEO_STICK_lon(_payload) pprzlink_get_DL_METEO_STICK_lon(_payload)
#define DL_METEO_STICK_hmsl(_payload) pprzlink_get_DL_METEO_STICK_hmsl(_payload)
#define DL_METEO_STICK_itow(_payload) pprzlink_get_DL_METEO_STICK_itow(_payload)
#define DL_METEO_STICK_pressure(_payload) pprzlink_get_DL_METEO_STICK_pressure(_payload)
#define DL_METEO_STICK_temperature(_payload) pprzlink_get_DL_METEO_STICK_temperature(_payload)
#define DL_METEO_STICK_humidity(_payload) pprzlink_get_DL_METEO_STICK_humidity(_payload)
#define DL_METEO_STICK_airspeed(_payload) pprzlink_get_DL_METEO_STICK_airspeed(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_METEO_STICK_H_

