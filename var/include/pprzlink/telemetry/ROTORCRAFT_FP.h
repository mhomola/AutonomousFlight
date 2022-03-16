/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_FP in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_FP 147
#define PPRZ_MSG_ID_ROTORCRAFT_FP 147

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_FP _send_msg(ROTORCRAFT_FP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_FP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _east 
 * @param _north 
 * @param _up 
 * @param _veast 
 * @param _vnorth 
 * @param _vup 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _carrot_east 
 * @param _carrot_north 
 * @param _carrot_up 
 * @param _carrot_psi 
 * @param _thrust 
 * @param _flight_time 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_FP(struct pprzlink_msg * msg, int32_t *_east, int32_t *_north, int32_t *_up, int32_t *_veast, int32_t *_vnorth, int32_t *_vup, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_carrot_east, int32_t *_carrot_north, int32_t *_carrot_up, int32_t *_carrot_psi, int32_t *_thrust, uint16_t *_flight_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_FP, "ROTORCRAFT_FP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _up, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _veast, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _vnorth, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _vup, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _carrot_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _carrot_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _carrot_up, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _carrot_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flight_time, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_FP pprz_msg_send_ROTORCRAFT_FP
#define DOWNLINK_SEND_ROTORCRAFT_FP(_trans, _dev, east, north, up, veast, vnorth, vup, phi, theta, psi, carrot_east, carrot_north, carrot_up, carrot_psi, thrust, flight_time) pprz_msg_send_ROTORCRAFT_FP(&((_trans).trans_tx), &((_dev).device), AC_ID, east, north, up, veast, vnorth, vup, phi, theta, psi, carrot_east, carrot_north, carrot_up, carrot_psi, thrust, flight_time)
/**
 * Sends a ROTORCRAFT_FP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _east 
 * @param _north 
 * @param _up 
 * @param _veast 
 * @param _vnorth 
 * @param _vup 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _carrot_east 
 * @param _carrot_north 
 * @param _carrot_up 
 * @param _carrot_psi 
 * @param _thrust 
 * @param _flight_time 
 */
static inline void pprz_msg_send_ROTORCRAFT_FP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_east, int32_t *_north, int32_t *_up, int32_t *_veast, int32_t *_vnorth, int32_t *_vup, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_carrot_east, int32_t *_carrot_north, int32_t *_carrot_up, int32_t *_carrot_psi, int32_t *_thrust, uint16_t *_flight_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_FP(&msg,_east,_north,_up,_veast,_vnorth,_vup,_phi,_theta,_psi,_carrot_east,_carrot_north,_carrot_up,_carrot_psi,_thrust,_flight_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_FP(_trans, _dev, east, north, up, veast, vnorth, vup, phi, theta, psi, carrot_east, carrot_north, carrot_up, carrot_psi, thrust, flight_time) {}
static inline void pprz_send_msg_ROTORCRAFT_FP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_east __attribute__((unused)), int32_t *_north __attribute__((unused)), int32_t *_up __attribute__((unused)), int32_t *_veast __attribute__((unused)), int32_t *_vnorth __attribute__((unused)), int32_t *_vup __attribute__((unused)), int32_t *_phi __attribute__((unused)), int32_t *_theta __attribute__((unused)), int32_t *_psi __attribute__((unused)), int32_t *_carrot_east __attribute__((unused)), int32_t *_carrot_north __attribute__((unused)), int32_t *_carrot_up __attribute__((unused)), int32_t *_carrot_psi __attribute__((unused)), int32_t *_thrust __attribute__((unused)), uint16_t *_flight_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field east in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field north in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field up in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_up(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field veast in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_veast(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field vnorth in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_vnorth(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field vup in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_vup(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field phi in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field theta in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field psi in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field carrot_east in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_carrot_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field carrot_north in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_carrot_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field carrot_up in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_carrot_up(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field carrot_psi in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_carrot_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field thrust in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTORCRAFT_FP_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field flight_time in message ROTORCRAFT_FP
  *
  * @param _payload : a pointer to the ROTORCRAFT_FP message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTORCRAFT_FP_flight_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 60);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_FP_east(_payload) pprzlink_get_DL_ROTORCRAFT_FP_east(_payload)
#define DL_ROTORCRAFT_FP_north(_payload) pprzlink_get_DL_ROTORCRAFT_FP_north(_payload)
#define DL_ROTORCRAFT_FP_up(_payload) pprzlink_get_DL_ROTORCRAFT_FP_up(_payload)
#define DL_ROTORCRAFT_FP_veast(_payload) pprzlink_get_DL_ROTORCRAFT_FP_veast(_payload)
#define DL_ROTORCRAFT_FP_vnorth(_payload) pprzlink_get_DL_ROTORCRAFT_FP_vnorth(_payload)
#define DL_ROTORCRAFT_FP_vup(_payload) pprzlink_get_DL_ROTORCRAFT_FP_vup(_payload)
#define DL_ROTORCRAFT_FP_phi(_payload) pprzlink_get_DL_ROTORCRAFT_FP_phi(_payload)
#define DL_ROTORCRAFT_FP_theta(_payload) pprzlink_get_DL_ROTORCRAFT_FP_theta(_payload)
#define DL_ROTORCRAFT_FP_psi(_payload) pprzlink_get_DL_ROTORCRAFT_FP_psi(_payload)
#define DL_ROTORCRAFT_FP_carrot_east(_payload) pprzlink_get_DL_ROTORCRAFT_FP_carrot_east(_payload)
#define DL_ROTORCRAFT_FP_carrot_north(_payload) pprzlink_get_DL_ROTORCRAFT_FP_carrot_north(_payload)
#define DL_ROTORCRAFT_FP_carrot_up(_payload) pprzlink_get_DL_ROTORCRAFT_FP_carrot_up(_payload)
#define DL_ROTORCRAFT_FP_carrot_psi(_payload) pprzlink_get_DL_ROTORCRAFT_FP_carrot_psi(_payload)
#define DL_ROTORCRAFT_FP_thrust(_payload) pprzlink_get_DL_ROTORCRAFT_FP_thrust(_payload)
#define DL_ROTORCRAFT_FP_flight_time(_payload) pprzlink_get_DL_ROTORCRAFT_FP_flight_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_FP_H_

