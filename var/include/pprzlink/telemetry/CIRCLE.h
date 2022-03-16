/** @file
 *  @brief PPRZLink message header for CIRCLE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CIRCLE_H_
#define _VAR_MESSAGES_telemetry_CIRCLE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CIRCLE 21
#define PPRZ_MSG_ID_CIRCLE 21

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CIRCLE _send_msg(CIRCLE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CIRCLE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _center_east 
 * @param _center_north 
 * @param _radius 
 */
static inline void pprzlink_msg_v2_send_CIRCLE(struct pprzlink_msg * msg, float *_center_east, float *_center_north, float *_radius) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CIRCLE, "CIRCLE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _center_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _center_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _radius, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CIRCLE pprz_msg_send_CIRCLE
#define DOWNLINK_SEND_CIRCLE(_trans, _dev, center_east, center_north, radius) pprz_msg_send_CIRCLE(&((_trans).trans_tx), &((_dev).device), AC_ID, center_east, center_north, radius)
/**
 * Sends a CIRCLE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _center_east 
 * @param _center_north 
 * @param _radius 
 */
static inline void pprz_msg_send_CIRCLE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_center_east, float *_center_north, float *_radius) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CIRCLE(&msg,_center_east,_center_north,_radius);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CIRCLE(_trans, _dev, center_east, center_north, radius) {}
static inline void pprz_send_msg_CIRCLE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_center_east __attribute__((unused)), float *_center_north __attribute__((unused)), float *_radius __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field center_east in message CIRCLE
  *
  * @param _payload : a pointer to the CIRCLE message
  * @return 
  */
static inline float pprzlink_get_DL_CIRCLE_center_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field center_north in message CIRCLE
  *
  * @param _payload : a pointer to the CIRCLE message
  * @return 
  */
static inline float pprzlink_get_DL_CIRCLE_center_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field radius in message CIRCLE
  *
  * @param _payload : a pointer to the CIRCLE message
  * @return 
  */
static inline float pprzlink_get_DL_CIRCLE_radius(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_CIRCLE_center_east(_payload) pprzlink_get_DL_CIRCLE_center_east(_payload)
#define DL_CIRCLE_center_north(_payload) pprzlink_get_DL_CIRCLE_center_north(_payload)
#define DL_CIRCLE_radius(_payload) pprzlink_get_DL_CIRCLE_radius(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CIRCLE_H_

