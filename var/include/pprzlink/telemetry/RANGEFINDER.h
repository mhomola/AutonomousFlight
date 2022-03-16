/** @file
 *  @brief PPRZLink message header for RANGEFINDER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RANGEFINDER_H_
#define _VAR_MESSAGES_telemetry_RANGEFINDER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RANGEFINDER 29
#define PPRZ_MSG_ID_RANGEFINDER 29

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RANGEFINDER _send_msg(RANGEFINDER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RANGEFINDER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _range 
 * @param _z_dot 
 * @param _z_dot_sum_err 
 * @param _z_dot_setpoint 
 * @param _z_sum_err 
 * @param _z_setpoint 
 * @param _flying 
 */
static inline void pprzlink_msg_v2_send_RANGEFINDER(struct pprzlink_msg * msg, uint16_t *_range, float *_z_dot, float *_z_dot_sum_err, float *_z_dot_setpoint, float *_z_sum_err, float *_z_setpoint, uint8_t *_flying) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RANGEFINDER, "RANGEFINDER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _range, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_dot, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_dot_sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_dot_setpoint, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_setpoint, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _flying, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RANGEFINDER pprz_msg_send_RANGEFINDER
#define DOWNLINK_SEND_RANGEFINDER(_trans, _dev, range, z_dot, z_dot_sum_err, z_dot_setpoint, z_sum_err, z_setpoint, flying) pprz_msg_send_RANGEFINDER(&((_trans).trans_tx), &((_dev).device), AC_ID, range, z_dot, z_dot_sum_err, z_dot_setpoint, z_sum_err, z_setpoint, flying)
/**
 * Sends a RANGEFINDER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _range 
 * @param _z_dot 
 * @param _z_dot_sum_err 
 * @param _z_dot_setpoint 
 * @param _z_sum_err 
 * @param _z_setpoint 
 * @param _flying 
 */
static inline void pprz_msg_send_RANGEFINDER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_range, float *_z_dot, float *_z_dot_sum_err, float *_z_dot_setpoint, float *_z_sum_err, float *_z_setpoint, uint8_t *_flying) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RANGEFINDER(&msg,_range,_z_dot,_z_dot_sum_err,_z_dot_setpoint,_z_sum_err,_z_setpoint,_flying);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RANGEFINDER(_trans, _dev, range, z_dot, z_dot_sum_err, z_dot_setpoint, z_sum_err, z_setpoint, flying) {}
static inline void pprz_send_msg_RANGEFINDER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_range __attribute__((unused)), float *_z_dot __attribute__((unused)), float *_z_dot_sum_err __attribute__((unused)), float *_z_dot_setpoint __attribute__((unused)), float *_z_sum_err __attribute__((unused)), float *_z_setpoint __attribute__((unused)), uint8_t *_flying __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field range in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_RANGEFINDER_range(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field z_dot in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline float pprzlink_get_DL_RANGEFINDER_z_dot(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field z_dot_sum_err in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline float pprzlink_get_DL_RANGEFINDER_z_dot_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field z_dot_setpoint in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline float pprzlink_get_DL_RANGEFINDER_z_dot_setpoint(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field z_sum_err in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline float pprzlink_get_DL_RANGEFINDER_z_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field z_setpoint in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline float pprzlink_get_DL_RANGEFINDER_z_setpoint(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field flying in message RANGEFINDER
  *
  * @param _payload : a pointer to the RANGEFINDER message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RANGEFINDER_flying(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 26);
}


/* Compatibility macros */
#define DL_RANGEFINDER_range(_payload) pprzlink_get_DL_RANGEFINDER_range(_payload)
#define DL_RANGEFINDER_z_dot(_payload) pprzlink_get_DL_RANGEFINDER_z_dot(_payload)
#define DL_RANGEFINDER_z_dot_sum_err(_payload) pprzlink_get_DL_RANGEFINDER_z_dot_sum_err(_payload)
#define DL_RANGEFINDER_z_dot_setpoint(_payload) pprzlink_get_DL_RANGEFINDER_z_dot_setpoint(_payload)
#define DL_RANGEFINDER_z_sum_err(_payload) pprzlink_get_DL_RANGEFINDER_z_sum_err(_payload)
#define DL_RANGEFINDER_z_setpoint(_payload) pprzlink_get_DL_RANGEFINDER_z_setpoint(_payload)
#define DL_RANGEFINDER_flying(_payload) pprzlink_get_DL_RANGEFINDER_flying(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RANGEFINDER_H_

