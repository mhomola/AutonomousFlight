/** @file
 *  @brief PPRZLink message header for STEREOCAM_VELOCITY in class intermcu
 *
 *  Velocity measured using optical flow and stereovision. All parameters are in the camera frame
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_STEREOCAM_VELOCITY_H_
#define _VAR_MESSAGES_intermcu_STEREOCAM_VELOCITY_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STEREOCAM_VELOCITY 81
#define PPRZ_MSG_ID_STEREOCAM_VELOCITY 81

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STEREOCAM_VELOCITY _send_msg(STEREOCAM_VELOCITY,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STEREOCAM_VELOCITY message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _resolution Resolution of the vel and pos messages
 * @param _dt_frame Time difference to previous frame
 * @param _dt Time difference to previous message, not strictly required
 * @param _velx Velocity estimaed using stereo edgeflow
 * @param _vely 
 * @param _velz 
 * @param _dposx Distance traveled since the last message
 * @param _dposy 
 * @param _dposz 
 * @param _vRMS RMS of the velocity estimate
 * @param _posRMS RMS of the position
 * @param _avg_dist Average distance to scene
 */
static inline void pprzlink_msg_v2_send_STEREOCAM_VELOCITY(struct pprzlink_msg * msg, uint8_t *_resolution, uint8_t *_dt_frame, uint8_t *_dt, int16_t *_velx, int16_t *_vely, int16_t *_velz, int16_t *_dposx, int16_t *_dposy, int16_t *_dposz, uint8_t *_vRMS, uint8_t *_posRMS, uint16_t *_avg_dist) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+2+2+2+2+2+2+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+2+2+2+2+2+2+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STEREOCAM_VELOCITY, "STEREOCAM_VELOCITY");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _resolution, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _dt_frame, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _dt, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _velx, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _vely, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _velz, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _dposx, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _dposy, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _dposz, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _vRMS, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _posRMS, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _avg_dist, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STEREOCAM_VELOCITY pprz_msg_send_STEREOCAM_VELOCITY
#define DOWNLINK_SEND_STEREOCAM_VELOCITY(_trans, _dev, resolution, dt_frame, dt, velx, vely, velz, dposx, dposy, dposz, vRMS, posRMS, avg_dist) pprz_msg_send_STEREOCAM_VELOCITY(&((_trans).trans_tx), &((_dev).device), AC_ID, resolution, dt_frame, dt, velx, vely, velz, dposx, dposy, dposz, vRMS, posRMS, avg_dist)
/**
 * Sends a STEREOCAM_VELOCITY message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _resolution Resolution of the vel and pos messages
 * @param _dt_frame Time difference to previous frame
 * @param _dt Time difference to previous message, not strictly required
 * @param _velx Velocity estimaed using stereo edgeflow
 * @param _vely 
 * @param _velz 
 * @param _dposx Distance traveled since the last message
 * @param _dposy 
 * @param _dposz 
 * @param _vRMS RMS of the velocity estimate
 * @param _posRMS RMS of the position
 * @param _avg_dist Average distance to scene
 */
static inline void pprz_msg_send_STEREOCAM_VELOCITY(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_resolution, uint8_t *_dt_frame, uint8_t *_dt, int16_t *_velx, int16_t *_vely, int16_t *_velz, int16_t *_dposx, int16_t *_dposy, int16_t *_dposz, uint8_t *_vRMS, uint8_t *_posRMS, uint16_t *_avg_dist) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STEREOCAM_VELOCITY(&msg,_resolution,_dt_frame,_dt,_velx,_vely,_velz,_dposx,_dposy,_dposz,_vRMS,_posRMS,_avg_dist);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STEREOCAM_VELOCITY(_trans, _dev, resolution, dt_frame, dt, velx, vely, velz, dposx, dposy, dposz, vRMS, posRMS, avg_dist) {}
static inline void pprz_send_msg_STEREOCAM_VELOCITY(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_resolution __attribute__((unused)), uint8_t *_dt_frame __attribute__((unused)), uint8_t *_dt __attribute__((unused)), int16_t *_velx __attribute__((unused)), int16_t *_vely __attribute__((unused)), int16_t *_velz __attribute__((unused)), int16_t *_dposx __attribute__((unused)), int16_t *_dposy __attribute__((unused)), int16_t *_dposz __attribute__((unused)), uint8_t *_vRMS __attribute__((unused)), uint8_t *_posRMS __attribute__((unused)), uint16_t *_avg_dist __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field resolution in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Resolution of the vel and pos messages
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_VELOCITY_resolution(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field dt_frame in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Time difference to previous frame
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_VELOCITY_dt_frame(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field dt in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Time difference to previous message, not strictly required
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_VELOCITY_dt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field velx in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Velocity estimaed using stereo edgeflow
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_velx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 7);
}


/** Getter for field vely in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return 
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_vely(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 9);
}


/** Getter for field velz in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return 
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_velz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 11);
}


/** Getter for field dposx in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Distance traveled since the last message
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_dposx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 13);
}


/** Getter for field dposy in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return 
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_dposy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 15);
}


/** Getter for field dposz in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return 
  */
static inline int16_t pprzlink_get_DL_STEREOCAM_VELOCITY_dposz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 17);
}


/** Getter for field vRMS in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return RMS of the velocity estimate
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_VELOCITY_vRMS(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 19);
}


/** Getter for field posRMS in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return RMS of the position
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_VELOCITY_posRMS(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 20);
}


/** Getter for field avg_dist in message STEREOCAM_VELOCITY
  *
  * @param _payload : a pointer to the STEREOCAM_VELOCITY message
  * @return Average distance to scene
  */
static inline uint16_t pprzlink_get_DL_STEREOCAM_VELOCITY_avg_dist(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 21);
}


/* Compatibility macros */
#define DL_STEREOCAM_VELOCITY_resolution(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_resolution(_payload)
#define DL_STEREOCAM_VELOCITY_dt_frame(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_dt_frame(_payload)
#define DL_STEREOCAM_VELOCITY_dt(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_dt(_payload)
#define DL_STEREOCAM_VELOCITY_velx(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_velx(_payload)
#define DL_STEREOCAM_VELOCITY_vely(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_vely(_payload)
#define DL_STEREOCAM_VELOCITY_velz(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_velz(_payload)
#define DL_STEREOCAM_VELOCITY_dposx(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_dposx(_payload)
#define DL_STEREOCAM_VELOCITY_dposy(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_dposy(_payload)
#define DL_STEREOCAM_VELOCITY_dposz(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_dposz(_payload)
#define DL_STEREOCAM_VELOCITY_vRMS(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_vRMS(_payload)
#define DL_STEREOCAM_VELOCITY_posRMS(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_posRMS(_payload)
#define DL_STEREOCAM_VELOCITY_avg_dist(_payload) pprzlink_get_DL_STEREOCAM_VELOCITY_avg_dist(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_STEREOCAM_VELOCITY_H_

