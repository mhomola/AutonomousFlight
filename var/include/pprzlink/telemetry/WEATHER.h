/** @file
 *  @brief PPRZLink message header for WEATHER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_WEATHER_H_
#define _VAR_MESSAGES_telemetry_WEATHER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WEATHER 219
#define PPRZ_MSG_ID_WEATHER 219

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WEATHER _send_msg(WEATHER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WEATHER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _p_amb 
 * @param _t_amb 
 * @param _windspeed 
 * @param _wind_from 
 * @param _humidity 
 */
static inline void pprzlink_msg_v2_send_WEATHER(struct pprzlink_msg * msg, float *_p_amb, float *_t_amb, float *_windspeed, float *_wind_from, float *_humidity) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WEATHER, "WEATHER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p_amb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _t_amb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _windspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _wind_from, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _humidity, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WEATHER pprz_msg_send_WEATHER
#define DOWNLINK_SEND_WEATHER(_trans, _dev, p_amb, t_amb, windspeed, wind_from, humidity) pprz_msg_send_WEATHER(&((_trans).trans_tx), &((_dev).device), AC_ID, p_amb, t_amb, windspeed, wind_from, humidity)
/**
 * Sends a WEATHER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _p_amb 
 * @param _t_amb 
 * @param _windspeed 
 * @param _wind_from 
 * @param _humidity 
 */
static inline void pprz_msg_send_WEATHER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_p_amb, float *_t_amb, float *_windspeed, float *_wind_from, float *_humidity) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WEATHER(&msg,_p_amb,_t_amb,_windspeed,_wind_from,_humidity);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WEATHER(_trans, _dev, p_amb, t_amb, windspeed, wind_from, humidity) {}
static inline void pprz_send_msg_WEATHER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_p_amb __attribute__((unused)), float *_t_amb __attribute__((unused)), float *_windspeed __attribute__((unused)), float *_wind_from __attribute__((unused)), float *_humidity __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field p_amb in message WEATHER
  *
  * @param _payload : a pointer to the WEATHER message
  * @return 
  */
static inline float pprzlink_get_DL_WEATHER_p_amb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field t_amb in message WEATHER
  *
  * @param _payload : a pointer to the WEATHER message
  * @return 
  */
static inline float pprzlink_get_DL_WEATHER_t_amb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field windspeed in message WEATHER
  *
  * @param _payload : a pointer to the WEATHER message
  * @return 
  */
static inline float pprzlink_get_DL_WEATHER_windspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field wind_from in message WEATHER
  *
  * @param _payload : a pointer to the WEATHER message
  * @return 
  */
static inline float pprzlink_get_DL_WEATHER_wind_from(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field humidity in message WEATHER
  *
  * @param _payload : a pointer to the WEATHER message
  * @return 
  */
static inline float pprzlink_get_DL_WEATHER_humidity(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/* Compatibility macros */
#define DL_WEATHER_p_amb(_payload) pprzlink_get_DL_WEATHER_p_amb(_payload)
#define DL_WEATHER_t_amb(_payload) pprzlink_get_DL_WEATHER_t_amb(_payload)
#define DL_WEATHER_windspeed(_payload) pprzlink_get_DL_WEATHER_windspeed(_payload)
#define DL_WEATHER_wind_from(_payload) pprzlink_get_DL_WEATHER_wind_from(_payload)
#define DL_WEATHER_humidity(_payload) pprzlink_get_DL_WEATHER_humidity(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_WEATHER_H_

