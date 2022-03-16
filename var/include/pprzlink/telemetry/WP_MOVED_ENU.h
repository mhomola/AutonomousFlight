/** @file
 *  @brief PPRZLink message header for WP_MOVED_ENU in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_WP_MOVED_ENU_H_
#define _VAR_MESSAGES_telemetry_WP_MOVED_ENU_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WP_MOVED_ENU 49
#define PPRZ_MSG_ID_WP_MOVED_ENU 49

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WP_MOVED_ENU _send_msg(WP_MOVED_ENU,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WP_MOVED_ENU message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _wp_id 
 * @param _east 
 * @param _north 
 * @param _up 
 */
static inline void pprzlink_msg_v2_send_WP_MOVED_ENU(struct pprzlink_msg * msg, uint8_t *_wp_id, int32_t *_east, int32_t *_north, int32_t *_up) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WP_MOVED_ENU, "WP_MOVED_ENU");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _wp_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _up, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WP_MOVED_ENU pprz_msg_send_WP_MOVED_ENU
#define DOWNLINK_SEND_WP_MOVED_ENU(_trans, _dev, wp_id, east, north, up) pprz_msg_send_WP_MOVED_ENU(&((_trans).trans_tx), &((_dev).device), AC_ID, wp_id, east, north, up)
/**
 * Sends a WP_MOVED_ENU message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _wp_id 
 * @param _east 
 * @param _north 
 * @param _up 
 */
static inline void pprz_msg_send_WP_MOVED_ENU(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_wp_id, int32_t *_east, int32_t *_north, int32_t *_up) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WP_MOVED_ENU(&msg,_wp_id,_east,_north,_up);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WP_MOVED_ENU(_trans, _dev, wp_id, east, north, up) {}
static inline void pprz_send_msg_WP_MOVED_ENU(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_wp_id __attribute__((unused)), int32_t *_east __attribute__((unused)), int32_t *_north __attribute__((unused)), int32_t *_up __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field wp_id in message WP_MOVED_ENU
  *
  * @param _payload : a pointer to the WP_MOVED_ENU message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WP_MOVED_ENU_wp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field east in message WP_MOVED_ENU
  *
  * @param _payload : a pointer to the WP_MOVED_ENU message
  * @return 
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_ENU_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 5);
}


/** Getter for field north in message WP_MOVED_ENU
  *
  * @param _payload : a pointer to the WP_MOVED_ENU message
  * @return 
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_ENU_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field up in message WP_MOVED_ENU
  *
  * @param _payload : a pointer to the WP_MOVED_ENU message
  * @return 
  */
static inline int32_t pprzlink_get_DL_WP_MOVED_ENU_up(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 13);
}


/* Compatibility macros */
#define DL_WP_MOVED_ENU_wp_id(_payload) pprzlink_get_DL_WP_MOVED_ENU_wp_id(_payload)
#define DL_WP_MOVED_ENU_east(_payload) pprzlink_get_DL_WP_MOVED_ENU_east(_payload)
#define DL_WP_MOVED_ENU_north(_payload) pprzlink_get_DL_WP_MOVED_ENU_north(_payload)
#define DL_WP_MOVED_ENU_up(_payload) pprzlink_get_DL_WP_MOVED_ENU_up(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_WP_MOVED_ENU_H_

