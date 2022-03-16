/** @file
 *  @brief PPRZLink message header for NAVIGATION_REF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NAVIGATION_REF_H_
#define _VAR_MESSAGES_telemetry_NAVIGATION_REF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NAVIGATION_REF 9
#define PPRZ_MSG_ID_NAVIGATION_REF 9

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NAVIGATION_REF _send_msg(NAVIGATION_REF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NAVIGATION_REF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _utm_east 
 * @param _utm_north 
 * @param _utm_zone 
 * @param _ground_alt 
 */
static inline void pprzlink_msg_v2_send_NAVIGATION_REF(struct pprzlink_msg * msg, int32_t *_utm_east, int32_t *_utm_north, uint8_t *_utm_zone, float *_ground_alt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+1+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+1+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NAVIGATION_REF, "NAVIGATION_REF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _utm_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _utm_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _utm_zone, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ground_alt, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NAVIGATION_REF pprz_msg_send_NAVIGATION_REF
#define DOWNLINK_SEND_NAVIGATION_REF(_trans, _dev, utm_east, utm_north, utm_zone, ground_alt) pprz_msg_send_NAVIGATION_REF(&((_trans).trans_tx), &((_dev).device), AC_ID, utm_east, utm_north, utm_zone, ground_alt)
/**
 * Sends a NAVIGATION_REF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _utm_east 
 * @param _utm_north 
 * @param _utm_zone 
 * @param _ground_alt 
 */
static inline void pprz_msg_send_NAVIGATION_REF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_utm_east, int32_t *_utm_north, uint8_t *_utm_zone, float *_ground_alt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NAVIGATION_REF(&msg,_utm_east,_utm_north,_utm_zone,_ground_alt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NAVIGATION_REF(_trans, _dev, utm_east, utm_north, utm_zone, ground_alt) {}
static inline void pprz_send_msg_NAVIGATION_REF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_utm_east __attribute__((unused)), int32_t *_utm_north __attribute__((unused)), uint8_t *_utm_zone __attribute__((unused)), float *_ground_alt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field utm_east in message NAVIGATION_REF
  *
  * @param _payload : a pointer to the NAVIGATION_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_NAVIGATION_REF_utm_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field utm_north in message NAVIGATION_REF
  *
  * @param _payload : a pointer to the NAVIGATION_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_NAVIGATION_REF_utm_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field utm_zone in message NAVIGATION_REF
  *
  * @param _payload : a pointer to the NAVIGATION_REF message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_NAVIGATION_REF_utm_zone(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 12);
}


/** Getter for field ground_alt in message NAVIGATION_REF
  *
  * @param _payload : a pointer to the NAVIGATION_REF message
  * @return 
  */
static inline float pprzlink_get_DL_NAVIGATION_REF_ground_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/* Compatibility macros */
#define DL_NAVIGATION_REF_utm_east(_payload) pprzlink_get_DL_NAVIGATION_REF_utm_east(_payload)
#define DL_NAVIGATION_REF_utm_north(_payload) pprzlink_get_DL_NAVIGATION_REF_utm_north(_payload)
#define DL_NAVIGATION_REF_utm_zone(_payload) pprzlink_get_DL_NAVIGATION_REF_utm_zone(_payload)
#define DL_NAVIGATION_REF_ground_alt(_payload) pprzlink_get_DL_NAVIGATION_REF_ground_alt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NAVIGATION_REF_H_

