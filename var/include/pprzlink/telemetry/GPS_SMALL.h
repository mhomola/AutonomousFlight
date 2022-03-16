/** @file
 *  @brief PPRZLink message header for GPS_SMALL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_SMALL_H_
#define _VAR_MESSAGES_telemetry_GPS_SMALL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_SMALL 252
#define PPRZ_MSG_ID_GPS_SMALL 252

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_SMALL _send_msg(GPS_SMALL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_SMALL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _multiplex_speed bits 31-21 course in decideg : bits 20-10 ground speed in cm/s : bits 9-0 climb speed in cm/s
 * @param _lat 
 * @param _lon 
 * @param _alt height above the ellipsoid
 */
static inline void pprzlink_msg_v2_send_GPS_SMALL(struct pprzlink_msg * msg, uint32_t *_multiplex_speed, int32_t *_lat, int32_t *_lon, int16_t *_alt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_SMALL, "GPS_SMALL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _multiplex_speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _alt, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_SMALL pprz_msg_send_GPS_SMALL
#define DOWNLINK_SEND_GPS_SMALL(_trans, _dev, multiplex_speed, lat, lon, alt) pprz_msg_send_GPS_SMALL(&((_trans).trans_tx), &((_dev).device), AC_ID, multiplex_speed, lat, lon, alt)
/**
 * Sends a GPS_SMALL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _multiplex_speed bits 31-21 course in decideg : bits 20-10 ground speed in cm/s : bits 9-0 climb speed in cm/s
 * @param _lat 
 * @param _lon 
 * @param _alt height above the ellipsoid
 */
static inline void pprz_msg_send_GPS_SMALL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_multiplex_speed, int32_t *_lat, int32_t *_lon, int16_t *_alt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_SMALL(&msg,_multiplex_speed,_lat,_lon,_alt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_SMALL(_trans, _dev, multiplex_speed, lat, lon, alt) {}
static inline void pprz_send_msg_GPS_SMALL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_multiplex_speed __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int16_t *_alt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field multiplex_speed in message GPS_SMALL
  *
  * @param _payload : a pointer to the GPS_SMALL message
  * @return bits 31-21 course in decideg : bits 20-10 ground speed in cm/s : bits 9-0 climb speed in cm/s
  */
static inline uint32_t pprzlink_get_DL_GPS_SMALL_multiplex_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field lat in message GPS_SMALL
  *
  * @param _payload : a pointer to the GPS_SMALL message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_SMALL_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field lon in message GPS_SMALL
  *
  * @param _payload : a pointer to the GPS_SMALL message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_SMALL_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field alt in message GPS_SMALL
  *
  * @param _payload : a pointer to the GPS_SMALL message
  * @return height above the ellipsoid
  */
static inline int16_t pprzlink_get_DL_GPS_SMALL_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 16);
}


/* Compatibility macros */
#define DL_GPS_SMALL_multiplex_speed(_payload) pprzlink_get_DL_GPS_SMALL_multiplex_speed(_payload)
#define DL_GPS_SMALL_lat(_payload) pprzlink_get_DL_GPS_SMALL_lat(_payload)
#define DL_GPS_SMALL_lon(_payload) pprzlink_get_DL_GPS_SMALL_lon(_payload)
#define DL_GPS_SMALL_alt(_payload) pprzlink_get_DL_GPS_SMALL_alt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_SMALL_H_

