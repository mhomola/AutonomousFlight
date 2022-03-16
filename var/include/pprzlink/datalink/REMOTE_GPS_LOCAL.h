/** @file
 *  @brief PPRZLink message header for REMOTE_GPS_LOCAL in class datalink
 *
 *  
        Position and speed in local frame from a remote GPS or motion capture system
        Global position transformations are handled onboard if needed
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_REMOTE_GPS_LOCAL_H_
#define _VAR_MESSAGES_datalink_REMOTE_GPS_LOCAL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_REMOTE_GPS_LOCAL 56
#define PPRZ_MSG_ID_REMOTE_GPS_LOCAL 56

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_REMOTE_GPS_LOCAL _send_msg(REMOTE_GPS_LOCAL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a REMOTE_GPS_LOCAL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _pad 
 * @param _enu_x 
 * @param _enu_y 
 * @param _enu_z 
 * @param _enu_xd 
 * @param _enu_yd 
 * @param _enu_zd 
 * @param _tow 
 * @param _course 
 */
static inline void pprzlink_msg_v2_send_REMOTE_GPS_LOCAL(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_pad, float *_enu_x, float *_enu_y, float *_enu_z, float *_enu_xd, float *_enu_yd, float *_enu_zd, uint32_t *_tow, float *_course) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_REMOTE_GPS_LOCAL, "REMOTE_GPS_LOCAL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _pad, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _enu_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _course, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_REMOTE_GPS_LOCAL pprz_msg_send_REMOTE_GPS_LOCAL
#define DOWNLINK_SEND_REMOTE_GPS_LOCAL(_trans, _dev, ac_id, pad, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, tow, course) pprz_msg_send_REMOTE_GPS_LOCAL(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, pad, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, tow, course)
/**
 * Sends a REMOTE_GPS_LOCAL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _pad 
 * @param _enu_x 
 * @param _enu_y 
 * @param _enu_z 
 * @param _enu_xd 
 * @param _enu_yd 
 * @param _enu_zd 
 * @param _tow 
 * @param _course 
 */
static inline void pprz_msg_send_REMOTE_GPS_LOCAL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_pad, float *_enu_x, float *_enu_y, float *_enu_z, float *_enu_xd, float *_enu_yd, float *_enu_zd, uint32_t *_tow, float *_course) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_REMOTE_GPS_LOCAL(&msg,_ac_id,_pad,_enu_x,_enu_y,_enu_z,_enu_xd,_enu_yd,_enu_zd,_tow,_course);
}


#else // DOWNLINK

#define DOWNLINK_SEND_REMOTE_GPS_LOCAL(_trans, _dev, ac_id, pad, enu_x, enu_y, enu_z, enu_xd, enu_yd, enu_zd, tow, course) {}
static inline void pprz_send_msg_REMOTE_GPS_LOCAL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_pad __attribute__((unused)), float *_enu_x __attribute__((unused)), float *_enu_y __attribute__((unused)), float *_enu_z __attribute__((unused)), float *_enu_xd __attribute__((unused)), float *_enu_yd __attribute__((unused)), float *_enu_zd __attribute__((unused)), uint32_t *_tow __attribute__((unused)), float *_course __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_REMOTE_GPS_LOCAL_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field pad in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_REMOTE_GPS_LOCAL_pad(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field enu_x in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field enu_y in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field enu_z in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field enu_xd in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field enu_yd in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field enu_zd in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/** Getter for field tow in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_REMOTE_GPS_LOCAL_tow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 30);
}


/** Getter for field course in message REMOTE_GPS_LOCAL
  *
  * @param _payload : a pointer to the REMOTE_GPS_LOCAL message
  * @return 
  */
static inline float pprzlink_get_DL_REMOTE_GPS_LOCAL_course(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 34);
}


/* Compatibility macros */
#define DL_REMOTE_GPS_LOCAL_ac_id(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_ac_id(_payload)
#define DL_REMOTE_GPS_LOCAL_pad(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_pad(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_x(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_x(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_y(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_y(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_z(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_z(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_xd(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_xd(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_yd(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_yd(_payload)
#define DL_REMOTE_GPS_LOCAL_enu_zd(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_enu_zd(_payload)
#define DL_REMOTE_GPS_LOCAL_tow(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_tow(_payload)
#define DL_REMOTE_GPS_LOCAL_course(_payload) pprzlink_get_DL_REMOTE_GPS_LOCAL_course(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_REMOTE_GPS_LOCAL_H_

