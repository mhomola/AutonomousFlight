/** @file
 *  @brief PPRZLink message header for CLOUD_SENSOR in class telemetry
 *
 *  
        Geolocalized and timestamped data from the meteo cloud sensor module
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CLOUD_SENSOR_H_
#define _VAR_MESSAGES_telemetry_CLOUD_SENSOR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CLOUD_SENSOR 61
#define PPRZ_MSG_ID_CLOUD_SENSOR 61

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CLOUD_SENSOR _send_msg(CLOUD_SENSOR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CLOUD_SENSOR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat 
 * @param _lon 
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _itow GPS time of week
 * @param _coef Angstrom coefficient computed on board
 * @param nb_raw,_raw Raw values and extra measurements data
 */
static inline void pprzlink_msg_v2_send_CLOUD_SENSOR(struct pprzlink_msg * msg, int32_t *_lat, int32_t *_lon, int32_t *_hmsl, uint32_t *_itow, float *_coef, uint8_t nb_raw, float *_raw) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+1+nb_raw*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+1+nb_raw*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CLOUD_SENSOR, "CLOUD_SENSOR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _itow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _coef, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_raw, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _raw, nb_raw*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CLOUD_SENSOR pprz_msg_send_CLOUD_SENSOR
#define DOWNLINK_SEND_CLOUD_SENSOR(_trans, _dev, lat, lon, hmsl, itow, coef, nb_raw, raw) pprz_msg_send_CLOUD_SENSOR(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, hmsl, itow, coef, nb_raw, raw)
/**
 * Sends a CLOUD_SENSOR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat 
 * @param _lon 
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _itow GPS time of week
 * @param _coef Angstrom coefficient computed on board
 * @param nb_raw,_raw Raw values and extra measurements data
 */
static inline void pprz_msg_send_CLOUD_SENSOR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_lat, int32_t *_lon, int32_t *_hmsl, uint32_t *_itow, float *_coef, uint8_t nb_raw, float *_raw) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CLOUD_SENSOR(&msg,_lat,_lon,_hmsl,_itow,_coef,nb_raw,_raw);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CLOUD_SENSOR(_trans, _dev, lat, lon, hmsl, itow, coef, nb_raw, raw) {}
static inline void pprz_send_msg_CLOUD_SENSOR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), uint32_t *_itow __attribute__((unused)), float *_coef __attribute__((unused)), uint8_t nb_raw __attribute__((unused)), float *_raw __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return 
  */
static inline int32_t pprzlink_get_DL_CLOUD_SENSOR_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field lon in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return 
  */
static inline int32_t pprzlink_get_DL_CLOUD_SENSOR_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field hmsl in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_CLOUD_SENSOR_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field itow in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return GPS time of week
  */
static inline uint32_t pprzlink_get_DL_CLOUD_SENSOR_itow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 16);
}


/** Getter for field coef in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return Angstrom coefficient computed on board
  */
static inline float pprzlink_get_DL_CLOUD_SENSOR_coef(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}

/** Getter for length of array raw in message CLOUD_SENSOR
 *
 * @return raw : Raw values and extra measurements data
 */
 static inline uint8_t pprzlink_get_CLOUD_SENSOR_raw_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 24);
}

/** Getter for field raw in message CLOUD_SENSOR
  *
  * @param _payload : a pointer to the CLOUD_SENSOR message
  * @return Raw values and extra measurements data
  */
static inline float * pprzlink_get_DL_CLOUD_SENSOR_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 25);
}


/* Compatibility macros */
#define DL_CLOUD_SENSOR_lat(_payload) pprzlink_get_DL_CLOUD_SENSOR_lat(_payload)
#define DL_CLOUD_SENSOR_lon(_payload) pprzlink_get_DL_CLOUD_SENSOR_lon(_payload)
#define DL_CLOUD_SENSOR_hmsl(_payload) pprzlink_get_DL_CLOUD_SENSOR_hmsl(_payload)
#define DL_CLOUD_SENSOR_itow(_payload) pprzlink_get_DL_CLOUD_SENSOR_itow(_payload)
#define DL_CLOUD_SENSOR_coef(_payload) pprzlink_get_DL_CLOUD_SENSOR_coef(_payload)
#define DL_CLOUD_SENSOR_raw_length(_payload) pprzlink_get_CLOUD_SENSOR_raw_length(_payload)
#define DL_CLOUD_SENSOR_raw(_payload) pprzlink_get_DL_CLOUD_SENSOR_raw(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CLOUD_SENSOR_H_

