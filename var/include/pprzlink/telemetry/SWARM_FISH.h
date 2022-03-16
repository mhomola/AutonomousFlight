/** @file
 *  @brief PPRZLink message header for SWARM_FISH in class telemetry
 *
 *  
        State of the swarm fish navigation
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SWARM_FISH_H_
#define _VAR_MESSAGES_telemetry_SWARM_FISH_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SWARM_FISH 77
#define PPRZ_MSG_ID_SWARM_FISH 77

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SWARM_FISH _send_msg(SWARM_FISH,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SWARM_FISH message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _heading Current Heading
 * @param _step_size Current step size
 * @param _rw Distance to wall
 * @param _fw Wall interaction coef
 * @param _theta_w Angle to wall
 * @param _f_fluct Fluctation effect
 * @param _f_wall Wall effect
 * @param _f_ali Alignement effect
 * @param _f_att Attraction effect
 */
static inline void pprzlink_msg_v2_send_SWARM_FISH(struct pprzlink_msg * msg, float *_heading, float *_step_size, float *_rw, float *_fw, float *_theta_w, float *_f_fluct, float *_f_wall, float *_f_ali, float *_f_att) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SWARM_FISH, "SWARM_FISH");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _heading, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _step_size, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta_w, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _f_fluct, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _f_wall, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _f_ali, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _f_att, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SWARM_FISH pprz_msg_send_SWARM_FISH
#define DOWNLINK_SEND_SWARM_FISH(_trans, _dev, heading, step_size, rw, fw, theta_w, f_fluct, f_wall, f_ali, f_att) pprz_msg_send_SWARM_FISH(&((_trans).trans_tx), &((_dev).device), AC_ID, heading, step_size, rw, fw, theta_w, f_fluct, f_wall, f_ali, f_att)
/**
 * Sends a SWARM_FISH message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _heading Current Heading
 * @param _step_size Current step size
 * @param _rw Distance to wall
 * @param _fw Wall interaction coef
 * @param _theta_w Angle to wall
 * @param _f_fluct Fluctation effect
 * @param _f_wall Wall effect
 * @param _f_ali Alignement effect
 * @param _f_att Attraction effect
 */
static inline void pprz_msg_send_SWARM_FISH(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_heading, float *_step_size, float *_rw, float *_fw, float *_theta_w, float *_f_fluct, float *_f_wall, float *_f_ali, float *_f_att) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SWARM_FISH(&msg,_heading,_step_size,_rw,_fw,_theta_w,_f_fluct,_f_wall,_f_ali,_f_att);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SWARM_FISH(_trans, _dev, heading, step_size, rw, fw, theta_w, f_fluct, f_wall, f_ali, f_att) {}
static inline void pprz_send_msg_SWARM_FISH(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_heading __attribute__((unused)), float *_step_size __attribute__((unused)), float *_rw __attribute__((unused)), float *_fw __attribute__((unused)), float *_theta_w __attribute__((unused)), float *_f_fluct __attribute__((unused)), float *_f_wall __attribute__((unused)), float *_f_ali __attribute__((unused)), float *_f_att __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field heading in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Current Heading
  */
static inline float pprzlink_get_DL_SWARM_FISH_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field step_size in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Current step size
  */
static inline float pprzlink_get_DL_SWARM_FISH_step_size(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field rw in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Distance to wall
  */
static inline float pprzlink_get_DL_SWARM_FISH_rw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field fw in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Wall interaction coef
  */
static inline float pprzlink_get_DL_SWARM_FISH_fw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field theta_w in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Angle to wall
  */
static inline float pprzlink_get_DL_SWARM_FISH_theta_w(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field f_fluct in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Fluctation effect
  */
static inline float pprzlink_get_DL_SWARM_FISH_f_fluct(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field f_wall in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Wall effect
  */
static inline float pprzlink_get_DL_SWARM_FISH_f_wall(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field f_ali in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Alignement effect
  */
static inline float pprzlink_get_DL_SWARM_FISH_f_ali(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field f_att in message SWARM_FISH
  *
  * @param _payload : a pointer to the SWARM_FISH message
  * @return Attraction effect
  */
static inline float pprzlink_get_DL_SWARM_FISH_f_att(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/* Compatibility macros */
#define DL_SWARM_FISH_heading(_payload) pprzlink_get_DL_SWARM_FISH_heading(_payload)
#define DL_SWARM_FISH_step_size(_payload) pprzlink_get_DL_SWARM_FISH_step_size(_payload)
#define DL_SWARM_FISH_rw(_payload) pprzlink_get_DL_SWARM_FISH_rw(_payload)
#define DL_SWARM_FISH_fw(_payload) pprzlink_get_DL_SWARM_FISH_fw(_payload)
#define DL_SWARM_FISH_theta_w(_payload) pprzlink_get_DL_SWARM_FISH_theta_w(_payload)
#define DL_SWARM_FISH_f_fluct(_payload) pprzlink_get_DL_SWARM_FISH_f_fluct(_payload)
#define DL_SWARM_FISH_f_wall(_payload) pprzlink_get_DL_SWARM_FISH_f_wall(_payload)
#define DL_SWARM_FISH_f_ali(_payload) pprzlink_get_DL_SWARM_FISH_f_ali(_payload)
#define DL_SWARM_FISH_f_att(_payload) pprzlink_get_DL_SWARM_FISH_f_att(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SWARM_FISH_H_

