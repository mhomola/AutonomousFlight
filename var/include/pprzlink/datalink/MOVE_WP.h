/** @file
 *  @brief PPRZLink message header for MOVE_WP in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_MOVE_WP_H_
#define _VAR_MESSAGES_datalink_MOVE_WP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MOVE_WP 2
#define PPRZ_MSG_ID_MOVE_WP 2

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MOVE_WP _send_msg(MOVE_WP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MOVE_WP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _wp_id 
 * @param _ac_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 */
static inline void pprzlink_msg_v2_send_MOVE_WP(struct pprzlink_msg * msg, uint8_t *_wp_id, uint8_t *_ac_id, int32_t *_lat, int32_t *_lon, int32_t *_alt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MOVE_WP, "MOVE_WP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _wp_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MOVE_WP pprz_msg_send_MOVE_WP
#define DOWNLINK_SEND_MOVE_WP(_trans, _dev, wp_id, ac_id, lat, lon, alt) pprz_msg_send_MOVE_WP(&((_trans).trans_tx), &((_dev).device), AC_ID, wp_id, ac_id, lat, lon, alt)
/**
 * Sends a MOVE_WP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _wp_id 
 * @param _ac_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 */
static inline void pprz_msg_send_MOVE_WP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_wp_id, uint8_t *_ac_id, int32_t *_lat, int32_t *_lon, int32_t *_alt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MOVE_WP(&msg,_wp_id,_ac_id,_lat,_lon,_alt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MOVE_WP(_trans, _dev, wp_id, ac_id, lat, lon, alt) {}
static inline void pprz_send_msg_MOVE_WP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_wp_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field wp_id in message MOVE_WP
  *
  * @param _payload : a pointer to the MOVE_WP message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MOVE_WP_wp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field ac_id in message MOVE_WP
  *
  * @param _payload : a pointer to the MOVE_WP message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MOVE_WP_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field lat in message MOVE_WP
  *
  * @param _payload : a pointer to the MOVE_WP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MOVE_WP_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field lon in message MOVE_WP
  *
  * @param _payload : a pointer to the MOVE_WP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MOVE_WP_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field alt in message MOVE_WP
  *
  * @param _payload : a pointer to the MOVE_WP message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_MOVE_WP_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/* Compatibility macros */
#define DL_MOVE_WP_wp_id(_payload) pprzlink_get_DL_MOVE_WP_wp_id(_payload)
#define DL_MOVE_WP_ac_id(_payload) pprzlink_get_DL_MOVE_WP_ac_id(_payload)
#define DL_MOVE_WP_lat(_payload) pprzlink_get_DL_MOVE_WP_lat(_payload)
#define DL_MOVE_WP_lon(_payload) pprzlink_get_DL_MOVE_WP_lon(_payload)
#define DL_MOVE_WP_alt(_payload) pprzlink_get_DL_MOVE_WP_alt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_MOVE_WP_H_

