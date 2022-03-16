/** @file
 *  @brief PPRZLink message header for REMOTE_GPS in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_REMOTE_GPS_H_
#define _VAR_MESSAGES_datalink_REMOTE_GPS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_REMOTE_GPS 55
#define PPRZ_MSG_ID_REMOTE_GPS 55

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_REMOTE_GPS _send_msg(REMOTE_GPS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a REMOTE_GPS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _numsv 
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above WGS84 reference ellipsoid
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _tow 
 * @param _course 
 */
static inline void pprzlink_msg_v2_send_REMOTE_GPS(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_numsv, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, uint32_t *_tow, int32_t *_course) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_REMOTE_GPS, "REMOTE_GPS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _numsv, 1);
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
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_REMOTE_GPS pprz_msg_send_REMOTE_GPS
#define DOWNLINK_SEND_REMOTE_GPS(_trans, _dev, ac_id, numsv, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, tow, course) pprz_msg_send_REMOTE_GPS(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, numsv, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, tow, course)
/**
 * Sends a REMOTE_GPS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _numsv 
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above WGS84 reference ellipsoid
 * @param _hmsl Height above Mean Sea Level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _tow 
 * @param _course 
 */
static inline void pprz_msg_send_REMOTE_GPS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_numsv, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, uint32_t *_tow, int32_t *_course) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_REMOTE_GPS(&msg,_ac_id,_numsv,_ecef_x,_ecef_y,_ecef_z,_lat,_lon,_alt,_hmsl,_ecef_xd,_ecef_yd,_ecef_zd,_tow,_course);
}


#else // DOWNLINK

#define DOWNLINK_SEND_REMOTE_GPS(_trans, _dev, ac_id, numsv, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, tow, course) {}
static inline void pprz_send_msg_REMOTE_GPS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_numsv __attribute__((unused)), int32_t *_ecef_x __attribute__((unused)), int32_t *_ecef_y __attribute__((unused)), int32_t *_ecef_z __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), int32_t *_ecef_xd __attribute__((unused)), int32_t *_ecef_yd __attribute__((unused)), int32_t *_ecef_zd __attribute__((unused)), uint32_t *_tow __attribute__((unused)), int32_t *_course __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_REMOTE_GPS_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field numsv in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_REMOTE_GPS_numsv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field ecef_x in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field ecef_y in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field ecef_z in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field lat in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field lon in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 22);
}


/** Getter for field alt in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return Height above WGS84 reference ellipsoid
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 26);
}


/** Getter for field hmsl in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 30);
}


/** Getter for field ecef_xd in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 34);
}


/** Getter for field ecef_yd in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 38);
}


/** Getter for field ecef_zd in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_ecef_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 42);
}


/** Getter for field tow in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_REMOTE_GPS_tow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 46);
}


/** Getter for field course in message REMOTE_GPS
  *
  * @param _payload : a pointer to the REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_REMOTE_GPS_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 50);
}


/* Compatibility macros */
#define DL_REMOTE_GPS_ac_id(_payload) pprzlink_get_DL_REMOTE_GPS_ac_id(_payload)
#define DL_REMOTE_GPS_numsv(_payload) pprzlink_get_DL_REMOTE_GPS_numsv(_payload)
#define DL_REMOTE_GPS_ecef_x(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_x(_payload)
#define DL_REMOTE_GPS_ecef_y(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_y(_payload)
#define DL_REMOTE_GPS_ecef_z(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_z(_payload)
#define DL_REMOTE_GPS_lat(_payload) pprzlink_get_DL_REMOTE_GPS_lat(_payload)
#define DL_REMOTE_GPS_lon(_payload) pprzlink_get_DL_REMOTE_GPS_lon(_payload)
#define DL_REMOTE_GPS_alt(_payload) pprzlink_get_DL_REMOTE_GPS_alt(_payload)
#define DL_REMOTE_GPS_hmsl(_payload) pprzlink_get_DL_REMOTE_GPS_hmsl(_payload)
#define DL_REMOTE_GPS_ecef_xd(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_xd(_payload)
#define DL_REMOTE_GPS_ecef_yd(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_yd(_payload)
#define DL_REMOTE_GPS_ecef_zd(_payload) pprzlink_get_DL_REMOTE_GPS_ecef_zd(_payload)
#define DL_REMOTE_GPS_tow(_payload) pprzlink_get_DL_REMOTE_GPS_tow(_payload)
#define DL_REMOTE_GPS_course(_payload) pprzlink_get_DL_REMOTE_GPS_course(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_REMOTE_GPS_H_

