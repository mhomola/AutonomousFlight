/** @file
 *  @brief PPRZLink message header for GENERIC_COM in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GENERIC_COM_H_
#define _VAR_MESSAGES_telemetry_GENERIC_COM_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GENERIC_COM 81
#define PPRZ_MSG_ID_GENERIC_COM 81

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GENERIC_COM _send_msg(GENERIC_COM,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GENERIC_COM message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lat 
 * @param _lon 
 * @param _alt 
 * @param _gspeed 
 * @param _course 
 * @param _airspeed 
 * @param _vsupply 
 * @param _charge 
 * @param _throttle 
 * @param _ap_mode 
 * @param _nav_block 
 * @param _flight_time 
 */
static inline void pprzlink_msg_v2_send_GENERIC_COM(struct pprzlink_msg * msg, int32_t *_lat, int32_t *_lon, int16_t *_alt, uint16_t *_gspeed, int16_t *_course, uint16_t *_airspeed, uint8_t *_vsupply, uint8_t *_charge, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint16_t *_flight_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+2+2+2+2+1+1+1+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+2+2+2+2+1+1+1+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GENERIC_COM, "GENERIC_COM");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _alt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _gspeed, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _course, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _airspeed, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _vsupply, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _charge, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _throttle, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nav_block, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flight_time, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GENERIC_COM pprz_msg_send_GENERIC_COM
#define DOWNLINK_SEND_GENERIC_COM(_trans, _dev, lat, lon, alt, gspeed, course, airspeed, vsupply, charge, throttle, ap_mode, nav_block, flight_time) pprz_msg_send_GENERIC_COM(&((_trans).trans_tx), &((_dev).device), AC_ID, lat, lon, alt, gspeed, course, airspeed, vsupply, charge, throttle, ap_mode, nav_block, flight_time)
/**
 * Sends a GENERIC_COM message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lat 
 * @param _lon 
 * @param _alt 
 * @param _gspeed 
 * @param _course 
 * @param _airspeed 
 * @param _vsupply 
 * @param _charge 
 * @param _throttle 
 * @param _ap_mode 
 * @param _nav_block 
 * @param _flight_time 
 */
static inline void pprz_msg_send_GENERIC_COM(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_lat, int32_t *_lon, int16_t *_alt, uint16_t *_gspeed, int16_t *_course, uint16_t *_airspeed, uint8_t *_vsupply, uint8_t *_charge, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint16_t *_flight_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GENERIC_COM(&msg,_lat,_lon,_alt,_gspeed,_course,_airspeed,_vsupply,_charge,_throttle,_ap_mode,_nav_block,_flight_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GENERIC_COM(_trans, _dev, lat, lon, alt, gspeed, course, airspeed, vsupply, charge, throttle, ap_mode, nav_block, flight_time) {}
static inline void pprz_send_msg_GENERIC_COM(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int16_t *_alt __attribute__((unused)), uint16_t *_gspeed __attribute__((unused)), int16_t *_course __attribute__((unused)), uint16_t *_airspeed __attribute__((unused)), uint8_t *_vsupply __attribute__((unused)), uint8_t *_charge __attribute__((unused)), uint8_t *_throttle __attribute__((unused)), uint8_t *_ap_mode __attribute__((unused)), uint8_t *_nav_block __attribute__((unused)), uint16_t *_flight_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lat in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GENERIC_COM_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field lon in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GENERIC_COM_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field alt in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_GENERIC_COM_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/** Getter for field gspeed in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GENERIC_COM_gspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field course in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_GENERIC_COM_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 16);
}


/** Getter for field airspeed in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GENERIC_COM_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/** Getter for field vsupply in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GENERIC_COM_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 20);
}


/** Getter for field charge in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GENERIC_COM_charge(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 21);
}


/** Getter for field throttle in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GENERIC_COM_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 22);
}


/** Getter for field ap_mode in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GENERIC_COM_ap_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 23);
}


/** Getter for field nav_block in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GENERIC_COM_nav_block(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 24);
}


/** Getter for field flight_time in message GENERIC_COM
  *
  * @param _payload : a pointer to the GENERIC_COM message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GENERIC_COM_flight_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 25);
}


/* Compatibility macros */
#define DL_GENERIC_COM_lat(_payload) pprzlink_get_DL_GENERIC_COM_lat(_payload)
#define DL_GENERIC_COM_lon(_payload) pprzlink_get_DL_GENERIC_COM_lon(_payload)
#define DL_GENERIC_COM_alt(_payload) pprzlink_get_DL_GENERIC_COM_alt(_payload)
#define DL_GENERIC_COM_gspeed(_payload) pprzlink_get_DL_GENERIC_COM_gspeed(_payload)
#define DL_GENERIC_COM_course(_payload) pprzlink_get_DL_GENERIC_COM_course(_payload)
#define DL_GENERIC_COM_airspeed(_payload) pprzlink_get_DL_GENERIC_COM_airspeed(_payload)
#define DL_GENERIC_COM_vsupply(_payload) pprzlink_get_DL_GENERIC_COM_vsupply(_payload)
#define DL_GENERIC_COM_charge(_payload) pprzlink_get_DL_GENERIC_COM_charge(_payload)
#define DL_GENERIC_COM_throttle(_payload) pprzlink_get_DL_GENERIC_COM_throttle(_payload)
#define DL_GENERIC_COM_ap_mode(_payload) pprzlink_get_DL_GENERIC_COM_ap_mode(_payload)
#define DL_GENERIC_COM_nav_block(_payload) pprzlink_get_DL_GENERIC_COM_nav_block(_payload)
#define DL_GENERIC_COM_flight_time(_payload) pprzlink_get_DL_GENERIC_COM_flight_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GENERIC_COM_H_

