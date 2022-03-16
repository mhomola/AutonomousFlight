/** @file
 *  @brief PPRZLink message header for IMCU_REMOTE_GPS in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_REMOTE_GPS_H_
#define _VAR_MESSAGES_intermcu_IMCU_REMOTE_GPS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_REMOTE_GPS 62
#define PPRZ_MSG_ID_IMCU_REMOTE_GPS 62

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_REMOTE_GPS _send_msg(IMCU_REMOTE_GPS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_REMOTE_GPS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl height above mean sea level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _course 
 * @param _gspeed 
 * @param _pacc 
 * @param _sacc 
 * @param _numsv 
 * @param _fix 
 */
static inline void pprzlink_msg_v2_send_IMCU_REMOTE_GPS(struct pprzlink_msg * msg, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, int32_t *_course, uint16_t *_gspeed, uint32_t *_pacc, uint32_t *_sacc, uint8_t *_numsv, uint8_t *_fix) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+2+4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+2+4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_REMOTE_GPS, "IMCU_REMOTE_GPS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _gspeed, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _pacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _sacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _numsv, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _fix, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_REMOTE_GPS pprz_msg_send_IMCU_REMOTE_GPS
#define DOWNLINK_SEND_IMCU_REMOTE_GPS(_trans, _dev, ecef_x, ecef_y, ecef_z, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, course, gspeed, pacc, sacc, numsv, fix) pprz_msg_send_IMCU_REMOTE_GPS(&((_trans).trans_tx), &((_dev).device), AC_ID, ecef_x, ecef_y, ecef_z, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, course, gspeed, pacc, sacc, numsv, fix)
/**
 * Sends a IMCU_REMOTE_GPS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ecef_x 
 * @param _ecef_y 
 * @param _ecef_z 
 * @param _alt altitude above WGS84 reference ellipsoid
 * @param _hmsl height above mean sea level (geoid)
 * @param _ecef_xd 
 * @param _ecef_yd 
 * @param _ecef_zd 
 * @param _course 
 * @param _gspeed 
 * @param _pacc 
 * @param _sacc 
 * @param _numsv 
 * @param _fix 
 */
static inline void pprz_msg_send_IMCU_REMOTE_GPS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, int32_t *_course, uint16_t *_gspeed, uint32_t *_pacc, uint32_t *_sacc, uint8_t *_numsv, uint8_t *_fix) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_REMOTE_GPS(&msg,_ecef_x,_ecef_y,_ecef_z,_alt,_hmsl,_ecef_xd,_ecef_yd,_ecef_zd,_course,_gspeed,_pacc,_sacc,_numsv,_fix);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_REMOTE_GPS(_trans, _dev, ecef_x, ecef_y, ecef_z, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, course, gspeed, pacc, sacc, numsv, fix) {}
static inline void pprz_send_msg_IMCU_REMOTE_GPS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_ecef_x __attribute__((unused)), int32_t *_ecef_y __attribute__((unused)), int32_t *_ecef_z __attribute__((unused)), int32_t *_alt __attribute__((unused)), int32_t *_hmsl __attribute__((unused)), int32_t *_ecef_xd __attribute__((unused)), int32_t *_ecef_yd __attribute__((unused)), int32_t *_ecef_zd __attribute__((unused)), int32_t *_course __attribute__((unused)), uint16_t *_gspeed __attribute__((unused)), uint32_t *_pacc __attribute__((unused)), uint32_t *_sacc __attribute__((unused)), uint8_t *_numsv __attribute__((unused)), uint8_t *_fix __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ecef_x in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field ecef_y in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ecef_z in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field alt in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return altitude above WGS84 reference ellipsoid
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field hmsl in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return height above mean sea level (geoid)
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_hmsl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field ecef_xd in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field ecef_yd in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field ecef_zd in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field course in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMCU_REMOTE_GPS_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field gspeed in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_IMCU_REMOTE_GPS_gspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 40);
}


/** Getter for field pacc in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_IMCU_REMOTE_GPS_pacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 42);
}


/** Getter for field sacc in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_IMCU_REMOTE_GPS_sacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 46);
}


/** Getter for field numsv in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_REMOTE_GPS_numsv(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 50);
}


/** Getter for field fix in message IMCU_REMOTE_GPS
  *
  * @param _payload : a pointer to the IMCU_REMOTE_GPS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_REMOTE_GPS_fix(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 51);
}


/* Compatibility macros */
#define DL_IMCU_REMOTE_GPS_ecef_x(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_x(_payload)
#define DL_IMCU_REMOTE_GPS_ecef_y(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_y(_payload)
#define DL_IMCU_REMOTE_GPS_ecef_z(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_z(_payload)
#define DL_IMCU_REMOTE_GPS_alt(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_alt(_payload)
#define DL_IMCU_REMOTE_GPS_hmsl(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_hmsl(_payload)
#define DL_IMCU_REMOTE_GPS_ecef_xd(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_xd(_payload)
#define DL_IMCU_REMOTE_GPS_ecef_yd(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_yd(_payload)
#define DL_IMCU_REMOTE_GPS_ecef_zd(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_ecef_zd(_payload)
#define DL_IMCU_REMOTE_GPS_course(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_course(_payload)
#define DL_IMCU_REMOTE_GPS_gspeed(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_gspeed(_payload)
#define DL_IMCU_REMOTE_GPS_pacc(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_pacc(_payload)
#define DL_IMCU_REMOTE_GPS_sacc(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_sacc(_payload)
#define DL_IMCU_REMOTE_GPS_numsv(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_numsv(_payload)
#define DL_IMCU_REMOTE_GPS_fix(_payload) pprzlink_get_DL_IMCU_REMOTE_GPS_fix(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_REMOTE_GPS_H_

