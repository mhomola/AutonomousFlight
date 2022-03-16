/** @file
 *  @brief PPRZLink message header for HFF_DBG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_HFF_DBG_H_
#define _VAR_MESSAGES_telemetry_HFF_DBG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HFF_DBG 165
#define PPRZ_MSG_ID_HFF_DBG 165

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HFF_DBG _send_msg(HFF_DBG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HFF_DBG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _x_measure 
 * @param _y_measure 
 * @param _xd_measure 
 * @param _yd_measure 
 * @param _Pxx 
 * @param _Pyy 
 * @param _Pxdxd 
 * @param _Pydyd 
 * @param _Pxbiasxbias 
 * @param _Pybiasybias 
 */
static inline void pprzlink_msg_v2_send_HFF_DBG(struct pprzlink_msg * msg, float *_x_measure, float *_y_measure, float *_xd_measure, float *_yd_measure, float *_Pxx, float *_Pyy, float *_Pxdxd, float *_Pydyd, float *_Pxbiasxbias, float *_Pybiasybias) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HFF_DBG, "HFF_DBG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x_measure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y_measure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _xd_measure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _yd_measure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pxx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pyy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pxdxd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pydyd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pxbiasxbias, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pybiasybias, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HFF_DBG pprz_msg_send_HFF_DBG
#define DOWNLINK_SEND_HFF_DBG(_trans, _dev, x_measure, y_measure, xd_measure, yd_measure, Pxx, Pyy, Pxdxd, Pydyd, Pxbiasxbias, Pybiasybias) pprz_msg_send_HFF_DBG(&((_trans).trans_tx), &((_dev).device), AC_ID, x_measure, y_measure, xd_measure, yd_measure, Pxx, Pyy, Pxdxd, Pydyd, Pxbiasxbias, Pybiasybias)
/**
 * Sends a HFF_DBG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _x_measure 
 * @param _y_measure 
 * @param _xd_measure 
 * @param _yd_measure 
 * @param _Pxx 
 * @param _Pyy 
 * @param _Pxdxd 
 * @param _Pydyd 
 * @param _Pxbiasxbias 
 * @param _Pybiasybias 
 */
static inline void pprz_msg_send_HFF_DBG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_x_measure, float *_y_measure, float *_xd_measure, float *_yd_measure, float *_Pxx, float *_Pyy, float *_Pxdxd, float *_Pydyd, float *_Pxbiasxbias, float *_Pybiasybias) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HFF_DBG(&msg,_x_measure,_y_measure,_xd_measure,_yd_measure,_Pxx,_Pyy,_Pxdxd,_Pydyd,_Pxbiasxbias,_Pybiasybias);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HFF_DBG(_trans, _dev, x_measure, y_measure, xd_measure, yd_measure, Pxx, Pyy, Pxdxd, Pydyd, Pxbiasxbias, Pybiasybias) {}
static inline void pprz_send_msg_HFF_DBG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_x_measure __attribute__((unused)), float *_y_measure __attribute__((unused)), float *_xd_measure __attribute__((unused)), float *_yd_measure __attribute__((unused)), float *_Pxx __attribute__((unused)), float *_Pyy __attribute__((unused)), float *_Pxdxd __attribute__((unused)), float *_Pydyd __attribute__((unused)), float *_Pxbiasxbias __attribute__((unused)), float *_Pybiasybias __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field x_measure in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_x_measure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field y_measure in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_y_measure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field xd_measure in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_xd_measure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field yd_measure in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_yd_measure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field Pxx in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pxx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field Pyy in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pyy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field Pxdxd in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pxdxd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field Pydyd in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pydyd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field Pxbiasxbias in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pxbiasxbias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field Pybiasybias in message HFF_DBG
  *
  * @param _payload : a pointer to the HFF_DBG message
  * @return 
  */
static inline float pprzlink_get_DL_HFF_DBG_Pybiasybias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/* Compatibility macros */
#define DL_HFF_DBG_x_measure(_payload) pprzlink_get_DL_HFF_DBG_x_measure(_payload)
#define DL_HFF_DBG_y_measure(_payload) pprzlink_get_DL_HFF_DBG_y_measure(_payload)
#define DL_HFF_DBG_xd_measure(_payload) pprzlink_get_DL_HFF_DBG_xd_measure(_payload)
#define DL_HFF_DBG_yd_measure(_payload) pprzlink_get_DL_HFF_DBG_yd_measure(_payload)
#define DL_HFF_DBG_Pxx(_payload) pprzlink_get_DL_HFF_DBG_Pxx(_payload)
#define DL_HFF_DBG_Pyy(_payload) pprzlink_get_DL_HFF_DBG_Pyy(_payload)
#define DL_HFF_DBG_Pxdxd(_payload) pprzlink_get_DL_HFF_DBG_Pxdxd(_payload)
#define DL_HFF_DBG_Pydyd(_payload) pprzlink_get_DL_HFF_DBG_Pydyd(_payload)
#define DL_HFF_DBG_Pxbiasxbias(_payload) pprzlink_get_DL_HFF_DBG_Pxbiasxbias(_payload)
#define DL_HFF_DBG_Pybiasybias(_payload) pprzlink_get_DL_HFF_DBG_Pybiasybias(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_HFF_DBG_H_

