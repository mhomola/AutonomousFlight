/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_FP_MIN in class telemetry
 *
 *  Minimalistic message to track Rotorcraft over very low bandwidth links
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_MIN_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_MIN_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_FP_MIN 217
#define PPRZ_MSG_ID_ROTORCRAFT_FP_MIN 217

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_FP_MIN _send_msg(ROTORCRAFT_FP_MIN,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_FP_MIN message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _east 
 * @param _north 
 * @param _up 
 * @param _gspeed 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_FP_MIN(struct pprzlink_msg * msg, int32_t *_east, int32_t *_north, int32_t *_up, uint16_t *_gspeed) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_FP_MIN, "ROTORCRAFT_FP_MIN");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _up, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _gspeed, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_FP_MIN pprz_msg_send_ROTORCRAFT_FP_MIN
#define DOWNLINK_SEND_ROTORCRAFT_FP_MIN(_trans, _dev, east, north, up, gspeed) pprz_msg_send_ROTORCRAFT_FP_MIN(&((_trans).trans_tx), &((_dev).device), AC_ID, east, north, up, gspeed)
/**
 * Sends a ROTORCRAFT_FP_MIN message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _east 
 * @param _north 
 * @param _up 
 * @param _gspeed 
 */
static inline void pprz_msg_send_ROTORCRAFT_FP_MIN(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_east, int32_t *_north, int32_t *_up, uint16_t *_gspeed) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_FP_MIN(&msg,_east,_north,_up,_gspeed);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_FP_MIN(_trans, _dev, east, north, up, gspeed) {}
static inline void pprz_send_msg_ROTORCRAFT_FP_MIN(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_east __attribute__((unused)), int32_t *_north __attribute__((unused)), int32_t *_up __attribute__((unused)), uint16_t *_gspeed __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field east in message ROTORCRAFT_FP_MIN
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP_MIN message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_MIN_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field north in message ROTORCRAFT_FP_MIN
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP_MIN message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_MIN_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field up in message ROTORCRAFT_FP_MIN
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP_MIN message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_MIN_up(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field gspeed in message ROTORCRAFT_FP_MIN
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP_MIN message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTORCRAFT_FP_MIN_gspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_FP_MIN_east(_payload) pprzlink_get_DL_ROTORCRAFT_FP_MIN_east(_payload)
#define DL_ROTORCRAFT_FP_MIN_north(_payload) pprzlink_get_DL_ROTORCRAFT_FP_MIN_north(_payload)
#define DL_ROTORCRAFT_FP_MIN_up(_payload) pprzlink_get_DL_ROTORCRAFT_FP_MIN_up(_payload)
#define DL_ROTORCRAFT_FP_MIN_gspeed(_payload) pprzlink_get_DL_ROTORCRAFT_FP_MIN_gspeed(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_MIN_H_

