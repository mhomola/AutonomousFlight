/** @file
 *  @brief PPRZLink message header for WP_MOVED in class telemetry
 *
 *  
      Waypoint with id wp_id has been updated/moved to the specified UTM coordinates.
    
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_WP_MOVED_H_
#define _VAR_MESSAGES_telemetry_WP_MOVED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WP_MOVED 35
#define PPRZ_MSG_ID_WP_MOVED 35

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WP_MOVED _send_msg(WP_MOVED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WP_MOVED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _wp_id 
 * @param _utm_east 
 * @param _utm_north 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _utm_zone 
 */
static inline void pprzlink_msg_v2_send_WP_MOVED(struct pprzlink_msg * msg, uint8_t *_wp_id, float *_utm_east, float *_utm_north, float *_alt, uint8_t *_utm_zone) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WP_MOVED, "WP_MOVED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _wp_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _utm_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _utm_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _utm_zone, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WP_MOVED pprz_msg_send_WP_MOVED
#define DOWNLINK_SEND_WP_MOVED(_trans, _dev, wp_id, utm_east, utm_north, alt, utm_zone) pprz_msg_send_WP_MOVED(&((_trans).trans_tx), &((_dev).device), AC_ID, wp_id, utm_east, utm_north, alt, utm_zone)
/**
 * Sends a WP_MOVED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _wp_id 
 * @param _utm_east 
 * @param _utm_north 
 * @param _alt Height above Mean Sea Level (geoid)
 * @param _utm_zone 
 */
static inline void pprz_msg_send_WP_MOVED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_wp_id, float *_utm_east, float *_utm_north, float *_alt, uint8_t *_utm_zone) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WP_MOVED(&msg,_wp_id,_utm_east,_utm_north,_alt,_utm_zone);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WP_MOVED(_trans, _dev, wp_id, utm_east, utm_north, alt, utm_zone) {}
static inline void pprz_send_msg_WP_MOVED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_wp_id __attribute__((unused)), float *_utm_east __attribute__((unused)), float *_utm_north __attribute__((unused)), float *_alt __attribute__((unused)), uint8_t *_utm_zone __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field wp_id in message WP_MOVED
  *
  * @param _payload : a pointer to the WP_MOVED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WP_MOVED_wp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field utm_east in message WP_MOVED
  *
  * @param _payload : a pointer to the WP_MOVED message
  * @return 
  */
static inline float pprzlink_get_DL_WP_MOVED_utm_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/** Getter for field utm_north in message WP_MOVED
  *
  * @param _payload : a pointer to the WP_MOVED message
  * @return 
  */
static inline float pprzlink_get_DL_WP_MOVED_utm_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field alt in message WP_MOVED
  *
  * @param _payload : a pointer to the WP_MOVED message
  * @return Height above Mean Sea Level (geoid)
  */
static inline float pprzlink_get_DL_WP_MOVED_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/** Getter for field utm_zone in message WP_MOVED
  *
  * @param _payload : a pointer to the WP_MOVED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WP_MOVED_utm_zone(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 17);
}


/* Compatibility macros */
#define DL_WP_MOVED_wp_id(_payload) pprzlink_get_DL_WP_MOVED_wp_id(_payload)
#define DL_WP_MOVED_utm_east(_payload) pprzlink_get_DL_WP_MOVED_utm_east(_payload)
#define DL_WP_MOVED_utm_north(_payload) pprzlink_get_DL_WP_MOVED_utm_north(_payload)
#define DL_WP_MOVED_alt(_payload) pprzlink_get_DL_WP_MOVED_alt(_payload)
#define DL_WP_MOVED_utm_zone(_payload) pprzlink_get_DL_WP_MOVED_utm_zone(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_WP_MOVED_H_

