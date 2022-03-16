/** @file
 *  @brief PPRZLink message header for WP_MOVED_LLA in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_WP_MOVED_LLA_H_
#define _VAR_MESSAGES_telemetry_WP_MOVED_LLA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WP_MOVED_LLA 47
#define PPRZ_MSG_ID_WP_MOVED_LLA 47

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WP_MOVED_LLA _send_msg(WP_MOVED_LLA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WP_MOVED_LLA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _wp_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 */
static inline void pprzlink_msg_v2_send_WP_MOVED_LLA(struct pprzlink_msg * msg, uint8_t *_wp_id, int32_t *_lat, int32_t *_lon, int32_t *_alt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WP_MOVED_LLA, "WP_MOVED_LLA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _wp_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WP_MOVED_LLA pprz_msg_send_WP_MOVED_LLA
#define DOWNLINK_SEND_WP_MOVED_LLA(_trans, _dev, wp_id, lat, lon, alt) pprz_msg_send_WP_MOVED_LLA(&((_trans).trans_tx), &((_dev).device), AC_ID, wp_id, lat, lon, alt)
/**
 * Sends a WP_MOVED_LLA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _wp_id 
 * @param _lat 
 * @param _lon 
 * @param _alt Height above Mean Sea Level (geoid)
 */
static inline void pprz_msg_send_WP_MOVED_LLA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_wp_id, int32_t *_lat, int32_t *_lon, int32_t *_alt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WP_MOVED_LLA(&msg,_wp_id,_lat,_lon,_alt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WP_MOVED_LLA(_trans, _dev, wp_id, lat, lon, alt) {}
static inline void pprz_send_msg_WP_MOVED_LLA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_wp_id __attribute__((unused)), int32_t *_lat __attribute__((unused)), int32_t *_lon __attribute__((unused)), int32_t *_alt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field wp_id in message WP_MOVED_LLA
  *
  * @param _payload : a pointer to the WP_MOVED_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WP_MOVED_LLA_wp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field lat in message WP_MOVED_LLA
  *
  * @param _payload : a pointer to the WP_MOVED_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_LLA_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 5);
}


/** Getter for field lon in message WP_MOVED_LLA
  *
  * @param _payload : a pointer to the WP_MOVED_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_LLA_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field alt in message WP_MOVED_LLA
  *
  * @param _payload : a pointer to the WP_MOVED_LLA message
  * @return Height above Mean Sea Level (geoid)
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_LLA_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 13);
}


/* Compatibility macros */
#define DL_WP_MOVED_LLA_wp_id(_payload) pprzlink_get_DL_WP_MOVED_LLA_wp_id(_payload)
#define DL_WP_MOVED_LLA_lat(_payload) pprzlink_get_DL_WP_MOVED_LLA_lat(_payload)
#define DL_WP_MOVED_LLA_lon(_payload) pprzlink_get_DL_WP_MOVED_LLA_lon(_payload)
#define DL_WP_MOVED_LLA_alt(_payload) pprzlink_get_DL_WP_MOVED_LLA_alt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_WP_MOVED_LLA_H_

