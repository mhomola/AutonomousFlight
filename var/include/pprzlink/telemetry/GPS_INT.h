/** @file
 *  @brief PPRZLink message header for GPS_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_INT_H_
#define _VAR_MESSAGES_telemetry_GPS_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_INT 155
#define PPRZ_MSG_ID_GPS_INT 155

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_INT _send_msg(GPS_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _lat 
 * @param _lon 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl height above mean sea level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _pacc 
 * @param _sacc 
 * @param _tow 
 * @param _pdop 
 * @param _numsv 
 * @param _fix 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_GPS_INT(struct pprzlink_msg * msg, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, uint32_t *_pacc, uint32_t *_sacc, uint32_t *_tow, uint16_t *_pdop, uint8_t *_numsv, uint8_t *_fix, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_INT, "GPS_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _pacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _sacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _pdop, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _numsv, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _fix, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_INT pprz_msg_send_GPS_INT
#define DOWNLINK_SEND_GPS_INT(_trans, _dev, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, pacc, sacc, tow, pdop, numsv, fix, comp_id) pprz_msg_send_GPS_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, pacc, sacc, tow, pdop, numsv, fix, comp_id)
/**
 * Sends a GPS_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _lat 
 * @param _lon 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl height above mean sea level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _pacc 
 * @param _sacc 
 * @param _tow 
 * @param _pdop 
 * @param _numsv 
 * @param _fix 
 * @param _comp_id 
 */
static inline void pprz_msg_send_GPS_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, uint32_t *_pacc, uint32_t *_sacc, uint32_t *_tow, uint16_t *_pdop, uint8_t *_numsv, uint8_t *_fix, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_INT(&msg,_ecef_x,_ecef_y,_ecef_z,_lat,_lon,_alt,_hmsl,_ecef_xd,_ecef_yd,_ecef_zd,_pacc,_sacc,_tow,_pdop,_numsv,_fix,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_INT(_trans, _dev, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, pacc, sacc, tow, pdop, numsv, fix, comp_id) {}
static inline void pprz_send_msg_GPS_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_ecef_x __attribute__((unused)), int32_t *_ecef_y __attribute__((unused)), int32_t *_ecef_z __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), int32_t *_ecef_xd __attribute__((unused)), int32_t *_ecef_yd __attribute__((unused)), int32_t *_ecef_zd __attribute__((unused)), uint32_t *_pacc __attribute__((unused)), uint32_t *_sacc __attribute__((unused)), uint32_t *_tow __attribute__((unused)), uint16_t *_pdop __attribute__((unused)), uint8_t *_numsv __attribute__((unused)), uint8_t *_fix __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ecef_x in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field ecef_y in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ecef_z in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field lat in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field lon in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field alt in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return altitude above WGS84 reference ellipsoid
  */
static inline int32_t pprzlink_get_DL_GPS_INT_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field hmsl in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return height above mean sea level (geoid)
  */
static inline int32_t pprzlink_get_DL_GPS_INT_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field ecef_xd in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field ecef_yd in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field ecef_zd in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_INT_ecef_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field pacc in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_INT_pacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 44);
}


/** Getter for field sacc in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_INT_sacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 48);
}


/** Getter for field tow in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_INT_tow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 52);
}


/** Getter for field pdop in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GPS_INT_pdop(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 56);
}


/** Getter for field numsv in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_INT_numsv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 58);
}


/** Getter for field fix in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_INT_fix(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 59);
}


/** Getter for field comp_id in message GPS_INT
  *
  * @param _payload : a pointer to the GPS_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_INT_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 60);
}


/* Compatibility macros */
#define DL_GPS_INT_ecef_x(_payload) pprzlink_get_DL_GPS_INT_ecef_x(_payload)
#define DL_GPS_INT_ecef_y(_payload) pprzlink_get_DL_GPS_INT_ecef_y(_payload)
#define DL_GPS_INT_ecef_z(_payload) pprzlink_get_DL_GPS_INT_ecef_z(_payload)
#define DL_GPS_INT_lat(_payload) pprzlink_get_DL_GPS_INT_lat(_payload)
#define DL_GPS_INT_lon(_payload) pprzlink_get_DL_GPS_INT_lon(_payload)
#define DL_GPS_INT_alt(_payload) pprzlink_get_DL_GPS_INT_alt(_payload)
#define DL_GPS_INT_hmsl(_payload) pprzlink_get_DL_GPS_INT_hmsl(_payload)
#define DL_GPS_INT_ecef_xd(_payload) pprzlink_get_DL_GPS_INT_ecef_xd(_payload)
#define DL_GPS_INT_ecef_yd(_payload) pprzlink_get_DL_GPS_INT_ecef_yd(_payload)
#define DL_GPS_INT_ecef_zd(_payload) pprzlink_get_DL_GPS_INT_ecef_zd(_payload)
#define DL_GPS_INT_pacc(_payload) pprzlink_get_DL_GPS_INT_pacc(_payload)
#define DL_GPS_INT_sacc(_payload) pprzlink_get_DL_GPS_INT_sacc(_payload)
#define DL_GPS_INT_tow(_payload) pprzlink_get_DL_GPS_INT_tow(_payload)
#define DL_GPS_INT_pdop(_payload) pprzlink_get_DL_GPS_INT_pdop(_payload)
#define DL_GPS_INT_numsv(_payload) pprzlink_get_DL_GPS_INT_numsv(_payload)
#define DL_GPS_INT_fix(_payload) pprzlink_get_DL_GPS_INT_fix(_payload)
#define DL_GPS_INT_comp_id(_payload) pprzlink_get_DL_GPS_INT_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_INT_H_

