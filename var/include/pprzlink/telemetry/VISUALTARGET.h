/** @file
 *  @brief PPRZLink message header for VISUALTARGET in class telemetry
 *
 *  Generic message with pixel coordinates of detected targets
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VISUALTARGET_H_
#define _VAR_MESSAGES_telemetry_VISUALTARGET_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VISUALTARGET 235
#define PPRZ_MSG_ID_VISUALTARGET 235

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VISUALTARGET _send_msg(VISUALTARGET,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VISUALTARGET message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cnt Counter
 * @param _x Center pixel X
 * @param _y Center pixel X
 * @param _w Width in pixels
 * @param _h height in pixels
 * @param _source In case many detectors run, which one did find this target
 */
static inline void pprzlink_msg_v2_send_VISUALTARGET(struct pprzlink_msg * msg, uint16_t *_cnt, int16_t *_x, int16_t *_y, int16_t *_w, int16_t *_h, uint16_t *_source) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VISUALTARGET, "VISUALTARGET");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _y, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _w, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _h, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _source, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VISUALTARGET pprz_msg_send_VISUALTARGET
#define DOWNLINK_SEND_VISUALTARGET(_trans, _dev, cnt, x, y, w, h, source) pprz_msg_send_VISUALTARGET(&((_trans).trans_tx), &((_dev).device), AC_ID, cnt, x, y, w, h, source)
/**
 * Sends a VISUALTARGET message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cnt Counter
 * @param _x Center pixel X
 * @param _y Center pixel X
 * @param _w Width in pixels
 * @param _h height in pixels
 * @param _source In case many detectors run, which one did find this target
 */
static inline void pprz_msg_send_VISUALTARGET(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_cnt, int16_t *_x, int16_t *_y, int16_t *_w, int16_t *_h, uint16_t *_source) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VISUALTARGET(&msg,_cnt,_x,_y,_w,_h,_source);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VISUALTARGET(_trans, _dev, cnt, x, y, w, h, source) {}
static inline void pprz_send_msg_VISUALTARGET(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_cnt __attribute__((unused)), int16_t *_x __attribute__((unused)), int16_t *_y __attribute__((unused)), int16_t *_w __attribute__((unused)), int16_t *_h __attribute__((unused)), uint16_t *_source __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cnt in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return Counter
  */
static inline uint16_t pprzlink_get_DL_VISUALTARGET_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field x in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return Center pixel X
  */
static inline int16_t pprzlink_get_DL_VISUALTARGET_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field y in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return Center pixel X
  */
static inline int16_t pprzlink_get_DL_VISUALTARGET_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field w in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return Width in pixels
  */
static inline int16_t pprzlink_get_DL_VISUALTARGET_w(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/** Getter for field h in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return height in pixels
  */
static inline int16_t pprzlink_get_DL_VISUALTARGET_h(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/** Getter for field source in message VISUALTARGET
  *
  * @param _payload : a pointer to the VISUALTARGET message
  * @return In case many detectors run, which one did find this target
  */
static inline uint16_t pprzlink_get_DL_VISUALTARGET_source(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/* Compatibility macros */
#define DL_VISUALTARGET_cnt(_payload) pprzlink_get_DL_VISUALTARGET_cnt(_payload)
#define DL_VISUALTARGET_x(_payload) pprzlink_get_DL_VISUALTARGET_x(_payload)
#define DL_VISUALTARGET_y(_payload) pprzlink_get_DL_VISUALTARGET_y(_payload)
#define DL_VISUALTARGET_w(_payload) pprzlink_get_DL_VISUALTARGET_w(_payload)
#define DL_VISUALTARGET_h(_payload) pprzlink_get_DL_VISUALTARGET_h(_payload)
#define DL_VISUALTARGET_source(_payload) pprzlink_get_DL_VISUALTARGET_source(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VISUALTARGET_H_

