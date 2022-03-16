/** @file
 *  @brief PPRZLink message header for HFF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_HFF_H_
#define _VAR_MESSAGES_telemetry_HFF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HFF 164
#define PPRZ_MSG_ID_HFF 164

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HFF _send_msg(HFF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HFF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _x 
 * @param _y 
 * @param _xd 
 * @param _yd 
 * @param _xdd 
 * @param _ydd 
 * @param _xbias 
 * @param _ybias 
 */
static inline void pprzlink_msg_v2_send_HFF(struct pprzlink_msg * msg, float *_x, float *_y, float *_xd, float *_yd, float *_xdd, float *_ydd, float *_xbias, float *_ybias) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HFF, "HFF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _xdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ydd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _xbias, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ybias, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HFF pprz_msg_send_HFF
#define DOWNLINK_SEND_HFF(_trans, _dev, x, y, xd, yd, xdd, ydd, xbias, ybias) pprz_msg_send_HFF(&((_trans).trans_tx), &((_dev).device), AC_ID, x, y, xd, yd, xdd, ydd, xbias, ybias)
/**
 * Sends a HFF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _x 
 * @param _y 
 * @param _xd 
 * @param _yd 
 * @param _xdd 
 * @param _ydd 
 * @param _xbias 
 * @param _ybias 
 */
static inline void pprz_msg_send_HFF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_x, float *_y, float *_xd, float *_yd, float *_xdd, float *_ydd, float *_xbias, float *_ybias) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HFF(&msg,_x,_y,_xd,_yd,_xdd,_ydd,_xbias,_ybias);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HFF(_trans, _dev, x, y, xd, yd, xdd, ydd, xbias, ybias) {}
static inline void pprz_send_msg_HFF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_x __attribute__((unused)), float *_y __attribute__((unused)), float *_xd __attribute__((unused)), float *_yd __attribute__((unused)), float *_xdd __attribute__((unused)), float *_ydd __attribute__((unused)), float *_xbias __attribute__((unused)), float *_ybias __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field x in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field y in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field xd in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field yd in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field xdd in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_xdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ydd in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_ydd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field xbias in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_xbias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field ybias in message HFF
  *
  * @param _payload : a pointer to the HFF message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_ybias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/* Compatibility macros */
#define DL_HFF_x(_payload) pprzlink_get_DL_HFF_x(_payload)
#define DL_HFF_y(_payload) pprzlink_get_DL_HFF_y(_payload)
#define DL_HFF_xd(_payload) pprzlink_get_DL_HFF_xd(_payload)
#define DL_HFF_yd(_payload) pprzlink_get_DL_HFF_yd(_payload)
#define DL_HFF_xdd(_payload) pprzlink_get_DL_HFF_xdd(_payload)
#define DL_HFF_ydd(_payload) pprzlink_get_DL_HFF_ydd(_payload)
#define DL_HFF_xbias(_payload) pprzlink_get_DL_HFF_xbias(_payload)
#define DL_HFF_ybias(_payload) pprzlink_get_DL_HFF_ybias(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_HFF_H_

