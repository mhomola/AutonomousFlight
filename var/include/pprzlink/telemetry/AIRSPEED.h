/** @file
 *  @brief PPRZLink message header for AIRSPEED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AIRSPEED_H_
#define _VAR_MESSAGES_telemetry_AIRSPEED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AIRSPEED 54
#define PPRZ_MSG_ID_AIRSPEED 54

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AIRSPEED _send_msg(AIRSPEED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AIRSPEED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _airspeed 
 * @param _airspeed_sp 
 * @param _airspeed_cnt 
 * @param _groundspeed_sp 
 */
static inline void pprzlink_msg_v2_send_AIRSPEED(struct pprzlink_msg * msg, float *_airspeed, float *_airspeed_sp, float *_airspeed_cnt, float *_groundspeed_sp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AIRSPEED, "AIRSPEED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed_cnt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _groundspeed_sp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AIRSPEED pprz_msg_send_AIRSPEED
#define DOWNLINK_SEND_AIRSPEED(_trans, _dev, airspeed, airspeed_sp, airspeed_cnt, groundspeed_sp) pprz_msg_send_AIRSPEED(&((_trans).trans_tx), &((_dev).device), AC_ID, airspeed, airspeed_sp, airspeed_cnt, groundspeed_sp)
/**
 * Sends a AIRSPEED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _airspeed 
 * @param _airspeed_sp 
 * @param _airspeed_cnt 
 * @param _groundspeed_sp 
 */
static inline void pprz_msg_send_AIRSPEED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_airspeed, float *_airspeed_sp, float *_airspeed_cnt, float *_groundspeed_sp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AIRSPEED(&msg,_airspeed,_airspeed_sp,_airspeed_cnt,_groundspeed_sp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AIRSPEED(_trans, _dev, airspeed, airspeed_sp, airspeed_cnt, groundspeed_sp) {}
static inline void pprz_send_msg_AIRSPEED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_airspeed __attribute__((unused)), float *_airspeed_sp __attribute__((unused)), float *_airspeed_cnt __attribute__((unused)), float *_groundspeed_sp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field airspeed in message AIRSPEED
  *
  * @param _payload : a pointer to the AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field airspeed_sp in message AIRSPEED
  *
  * @param _payload : a pointer to the AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_airspeed_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field airspeed_cnt in message AIRSPEED
  *
  * @param _payload : a pointer to the AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_airspeed_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field groundspeed_sp in message AIRSPEED
  *
  * @param _payload : a pointer to the AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_groundspeed_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_AIRSPEED_airspeed(_payload) pprzlink_get_DL_AIRSPEED_airspeed(_payload)
#define DL_AIRSPEED_airspeed_sp(_payload) pprzlink_get_DL_AIRSPEED_airspeed_sp(_payload)
#define DL_AIRSPEED_airspeed_cnt(_payload) pprzlink_get_DL_AIRSPEED_airspeed_cnt(_payload)
#define DL_AIRSPEED_groundspeed_sp(_payload) pprzlink_get_DL_AIRSPEED_groundspeed_sp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AIRSPEED_H_

