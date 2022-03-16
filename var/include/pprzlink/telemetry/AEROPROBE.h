/** @file
 *  @brief PPRZLink message header for AEROPROBE in class telemetry
 *
 *  
        Airflow data returned by OTF and uADC 3D probes from Aeroprobe.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AEROPROBE_H_
#define _VAR_MESSAGES_telemetry_AEROPROBE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AEROPROBE 179
#define PPRZ_MSG_ID_AEROPROBE 179

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AEROPROBE _send_msg(AEROPROBE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AEROPROBE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _counter 
 * @param _velocity 
 * @param _a_attack 
 * @param _a_sideslip 
 * @param _altitude 
 * @param _dynamic_p 
 * @param _static_p 
 * @param _checksum 
 */
static inline void pprzlink_msg_v2_send_AEROPROBE(struct pprzlink_msg * msg, uint32_t *_counter, int16_t *_velocity, int16_t *_a_attack, int16_t *_a_sideslip, int32_t *_altitude, int32_t *_dynamic_p, int32_t *_static_p, uint8_t *_checksum) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+2+2+2+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+2+2+2+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AEROPROBE, "AEROPROBE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _counter, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _velocity, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _a_attack, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _a_sideslip, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _altitude, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _dynamic_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _static_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _checksum, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AEROPROBE pprz_msg_send_AEROPROBE
#define DOWNLINK_SEND_AEROPROBE(_trans, _dev, counter, velocity, a_attack, a_sideslip, altitude, dynamic_p, static_p, checksum) pprz_msg_send_AEROPROBE(&((_trans).trans_tx), &((_dev).device), AC_ID, counter, velocity, a_attack, a_sideslip, altitude, dynamic_p, static_p, checksum)
/**
 * Sends a AEROPROBE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _counter 
 * @param _velocity 
 * @param _a_attack 
 * @param _a_sideslip 
 * @param _altitude 
 * @param _dynamic_p 
 * @param _static_p 
 * @param _checksum 
 */
static inline void pprz_msg_send_AEROPROBE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_counter, int16_t *_velocity, int16_t *_a_attack, int16_t *_a_sideslip, int32_t *_altitude, int32_t *_dynamic_p, int32_t *_static_p, uint8_t *_checksum) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AEROPROBE(&msg,_counter,_velocity,_a_attack,_a_sideslip,_altitude,_dynamic_p,_static_p,_checksum);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AEROPROBE(_trans, _dev, counter, velocity, a_attack, a_sideslip, altitude, dynamic_p, static_p, checksum) {}
static inline void pprz_send_msg_AEROPROBE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_counter __attribute__((unused)), int16_t *_velocity __attribute__((unused)), int16_t *_a_attack __attribute__((unused)), int16_t *_a_sideslip __attribute__((unused)), int32_t *_altitude __attribute__((unused)), int32_t *_dynamic_p __attribute__((unused)), int32_t *_static_p __attribute__((unused)), uint8_t *_checksum __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field counter in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_AEROPROBE_counter(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field velocity in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int16_t pprzlink_get_DL_AEROPROBE_velocity(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field a_attack in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int16_t pprzlink_get_DL_AEROPROBE_a_attack(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/** Getter for field a_sideslip in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int16_t pprzlink_get_DL_AEROPROBE_a_sideslip(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 12);
}


/** Getter for field altitude in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AEROPROBE_altitude(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field dynamic_p in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AEROPROBE_dynamic_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field static_p in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AEROPROBE_static_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 22);
}


/** Getter for field checksum in message AEROPROBE
  *
  * @param _payload : a pointer to the AEROPROBE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_AEROPROBE_checksum(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 26);
}


/* Compatibility macros */
#define DL_AEROPROBE_counter(_payload) pprzlink_get_DL_AEROPROBE_counter(_payload)
#define DL_AEROPROBE_velocity(_payload) pprzlink_get_DL_AEROPROBE_velocity(_payload)
#define DL_AEROPROBE_a_attack(_payload) pprzlink_get_DL_AEROPROBE_a_attack(_payload)
#define DL_AEROPROBE_a_sideslip(_payload) pprzlink_get_DL_AEROPROBE_a_sideslip(_payload)
#define DL_AEROPROBE_altitude(_payload) pprzlink_get_DL_AEROPROBE_altitude(_payload)
#define DL_AEROPROBE_dynamic_p(_payload) pprzlink_get_DL_AEROPROBE_dynamic_p(_payload)
#define DL_AEROPROBE_static_p(_payload) pprzlink_get_DL_AEROPROBE_static_p(_payload)
#define DL_AEROPROBE_checksum(_payload) pprzlink_get_DL_AEROPROBE_checksum(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AEROPROBE_H_

