/** @file
 *  @brief PPRZLink message header for POTENTIAL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_POTENTIAL_H_
#define _VAR_MESSAGES_telemetry_POTENTIAL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_POTENTIAL 124
#define PPRZ_MSG_ID_POTENTIAL 124

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_POTENTIAL _send_msg(POTENTIAL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a POTENTIAL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _east 
 * @param _north 
 * @param _alt 
 * @param _speed 
 * @param _climb 
 */
static inline void pprzlink_msg_v2_send_POTENTIAL(struct pprzlink_msg * msg, float *_east, float *_north, float *_alt, float *_speed, float *_climb) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_POTENTIAL, "POTENTIAL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_POTENTIAL pprz_msg_send_POTENTIAL
#define DOWNLINK_SEND_POTENTIAL(_trans, _dev, east, north, alt, speed, climb) pprz_msg_send_POTENTIAL(&((_trans).trans_tx), &((_dev).device), AC_ID, east, north, alt, speed, climb)
/**
 * Sends a POTENTIAL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _east 
 * @param _north 
 * @param _alt 
 * @param _speed 
 * @param _climb 
 */
static inline void pprz_msg_send_POTENTIAL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_east, float *_north, float *_alt, float *_speed, float *_climb) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_POTENTIAL(&msg,_east,_north,_alt,_speed,_climb);
}


#else // DOWNLINK

#define DOWNLINK_SEND_POTENTIAL(_trans, _dev, east, north, alt, speed, climb) {}
static inline void pprz_send_msg_POTENTIAL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_east __attribute__((unused)), float *_north __attribute__((unused)), float *_alt __attribute__((unused)), float *_speed __attribute__((unused)), float *_climb __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field east in message POTENTIAL
  *
  * @param _payload : a pointer to the POTENTIAL message
  * @return 
  */
static inline float pprzlink_get_DL_POTENTIAL_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field north in message POTENTIAL
  *
  * @param _payload : a pointer to the POTENTIAL message
  * @return 
  */
static inline float pprzlink_get_DL_POTENTIAL_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field alt in message POTENTIAL
  *
  * @param _payload : a pointer to the POTENTIAL message
  * @return 
  */
static inline float pprzlink_get_DL_POTENTIAL_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field speed in message POTENTIAL
  *
  * @param _payload : a pointer to the POTENTIAL message
  * @return 
  */
static inline float pprzlink_get_DL_POTENTIAL_speed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field climb in message POTENTIAL
  *
  * @param _payload : a pointer to the POTENTIAL message
  * @return 
  */
static inline float pprzlink_get_DL_POTENTIAL_climb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/* Compatibility macros */
#define DL_POTENTIAL_east(_payload) pprzlink_get_DL_POTENTIAL_east(_payload)
#define DL_POTENTIAL_north(_payload) pprzlink_get_DL_POTENTIAL_north(_payload)
#define DL_POTENTIAL_alt(_payload) pprzlink_get_DL_POTENTIAL_alt(_payload)
#define DL_POTENTIAL_speed(_payload) pprzlink_get_DL_POTENTIAL_speed(_payload)
#define DL_POTENTIAL_climb(_payload) pprzlink_get_DL_POTENTIAL_climb(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_POTENTIAL_H_

