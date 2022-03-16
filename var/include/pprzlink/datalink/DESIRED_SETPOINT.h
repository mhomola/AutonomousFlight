/** @file
 *  @brief PPRZLink message header for DESIRED_SETPOINT in class datalink
 *
 *  
        This message is used to set 3D desired vehicle's states such as accelerations or velocities.
        The 'flag' field can be used at the user convenience to provide indication about the type of
        value to track (like  position, speed, acceleration, ...) or the reference frame (ENU / NED,
        LTP / body frame, ...)
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_DESIRED_SETPOINT_H_
#define _VAR_MESSAGES_datalink_DESIRED_SETPOINT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DESIRED_SETPOINT 15
#define PPRZ_MSG_ID_DESIRED_SETPOINT 15

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DESIRED_SETPOINT _send_msg(DESIRED_SETPOINT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DESIRED_SETPOINT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id AC_ID of the vehicle
 * @param _flag Up to the user, for example to distinguish between ENU or NED
 * @param _ux Quantity to be tracked in the X axis
 * @param _uy Quantity to be tracked in the Y axis
 * @param _uz Quantity to be tracked in the Z axis
 */
static inline void pprzlink_msg_v2_send_DESIRED_SETPOINT(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_flag, float *_ux, float *_uy, float *_uz) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DESIRED_SETPOINT, "DESIRED_SETPOINT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _flag, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ux, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _uy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _uz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DESIRED_SETPOINT pprz_msg_send_DESIRED_SETPOINT
#define DOWNLINK_SEND_DESIRED_SETPOINT(_trans, _dev, ac_id, flag, ux, uy, uz) pprz_msg_send_DESIRED_SETPOINT(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, flag, ux, uy, uz)
/**
 * Sends a DESIRED_SETPOINT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id AC_ID of the vehicle
 * @param _flag Up to the user, for example to distinguish between ENU or NED
 * @param _ux Quantity to be tracked in the X axis
 * @param _uy Quantity to be tracked in the Y axis
 * @param _uz Quantity to be tracked in the Z axis
 */
static inline void pprz_msg_send_DESIRED_SETPOINT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_flag, float *_ux, float *_uy, float *_uz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DESIRED_SETPOINT(&msg,_ac_id,_flag,_ux,_uy,_uz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DESIRED_SETPOINT(_trans, _dev, ac_id, flag, ux, uy, uz) {}
static inline void pprz_send_msg_DESIRED_SETPOINT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_flag __attribute__((unused)), float *_ux __attribute__((unused)), float *_uy __attribute__((unused)), float *_uz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message DESIRED_SETPOINT
  *
  * @param _payload : a pointer to the DESIRED_SETPOINT message
  * @return AC_ID of the vehicle
  */
static inline uint8_t pprzlink_get_DL_DESIRED_SETPOINT_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field flag in message DESIRED_SETPOINT
  *
  * @param _payload : a pointer to the DESIRED_SETPOINT message
  * @return Up to the user, for example to distinguish between ENU or NED
  */
static inline uint8_t pprzlink_get_DL_DESIRED_SETPOINT_flag(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field ux in message DESIRED_SETPOINT
  *
  * @param _payload : a pointer to the DESIRED_SETPOINT message
  * @return Quantity to be tracked in the X axis
  */
static inline float pprzlink_get_DL_DESIRED_SETPOINT_ux(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field uy in message DESIRED_SETPOINT
  *
  * @param _payload : a pointer to the DESIRED_SETPOINT message
  * @return Quantity to be tracked in the Y axis
  */
static inline float pprzlink_get_DL_DESIRED_SETPOINT_uy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field uz in message DESIRED_SETPOINT
  *
  * @param _payload : a pointer to the DESIRED_SETPOINT message
  * @return Quantity to be tracked in the Z axis
  */
static inline float pprzlink_get_DL_DESIRED_SETPOINT_uz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/* Compatibility macros */
#define DL_DESIRED_SETPOINT_ac_id(_payload) pprzlink_get_DL_DESIRED_SETPOINT_ac_id(_payload)
#define DL_DESIRED_SETPOINT_flag(_payload) pprzlink_get_DL_DESIRED_SETPOINT_flag(_payload)
#define DL_DESIRED_SETPOINT_ux(_payload) pprzlink_get_DL_DESIRED_SETPOINT_ux(_payload)
#define DL_DESIRED_SETPOINT_uy(_payload) pprzlink_get_DL_DESIRED_SETPOINT_uy(_payload)
#define DL_DESIRED_SETPOINT_uz(_payload) pprzlink_get_DL_DESIRED_SETPOINT_uz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_DESIRED_SETPOINT_H_

