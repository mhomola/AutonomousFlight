/** @file
 *  @brief PPRZLink message header for INDI_G in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INDI_G_H_
#define _VAR_MESSAGES_telemetry_INDI_G_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INDI_G 250
#define PPRZ_MSG_ID_INDI_G 250

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INDI_G _send_msg(INDI_G,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INDI_G message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param nb_G1_roll,_G1_roll 
 * @param nb_G1_pitch,_G1_pitch 
 * @param nb_G1_yaw,_G1_yaw 
 * @param nb_G1_thrust,_G1_thrust 
 * @param nb_G2,_G2 
 */
static inline void pprzlink_msg_v2_send_INDI_G(struct pprzlink_msg * msg, uint8_t nb_G1_roll, float *_G1_roll, uint8_t nb_G1_pitch, float *_G1_pitch, uint8_t nb_G1_yaw, float *_G1_yaw, uint8_t nb_G1_thrust, float *_G1_thrust, uint8_t nb_G2, float *_G2) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+nb_G1_roll*4+1+nb_G1_pitch*4+1+nb_G1_yaw*4+1+nb_G1_thrust*4+1+nb_G2*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+nb_G1_roll*4+1+nb_G1_pitch*4+1+nb_G1_yaw*4+1+nb_G1_thrust*4+1+nb_G2*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INDI_G, "INDI_G");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_G1_roll, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _G1_roll, nb_G1_roll*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_G1_pitch, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _G1_pitch, nb_G1_pitch*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_G1_yaw, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _G1_yaw, nb_G1_yaw*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_G1_thrust, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _G1_thrust, nb_G1_thrust*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_G2, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _G2, nb_G2*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INDI_G pprz_msg_send_INDI_G
#define DOWNLINK_SEND_INDI_G(_trans, _dev, nb_G1_roll, G1_roll, nb_G1_pitch, G1_pitch, nb_G1_yaw, G1_yaw, nb_G1_thrust, G1_thrust, nb_G2, G2) pprz_msg_send_INDI_G(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_G1_roll, G1_roll, nb_G1_pitch, G1_pitch, nb_G1_yaw, G1_yaw, nb_G1_thrust, G1_thrust, nb_G2, G2)
/**
 * Sends a INDI_G message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param nb_G1_roll,_G1_roll 
 * @param nb_G1_pitch,_G1_pitch 
 * @param nb_G1_yaw,_G1_yaw 
 * @param nb_G1_thrust,_G1_thrust 
 * @param nb_G2,_G2 
 */
static inline void pprz_msg_send_INDI_G(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t nb_G1_roll, float *_G1_roll, uint8_t nb_G1_pitch, float *_G1_pitch, uint8_t nb_G1_yaw, float *_G1_yaw, uint8_t nb_G1_thrust, float *_G1_thrust, uint8_t nb_G2, float *_G2) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INDI_G(&msg,nb_G1_roll,_G1_roll,nb_G1_pitch,_G1_pitch,nb_G1_yaw,_G1_yaw,nb_G1_thrust,_G1_thrust,nb_G2,_G2);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INDI_G(_trans, _dev, nb_G1_roll, G1_roll, nb_G1_pitch, G1_pitch, nb_G1_yaw, G1_yaw, nb_G1_thrust, G1_thrust, nb_G2, G2) {}
static inline void pprz_send_msg_INDI_G(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t nb_G1_roll __attribute__((unused)), float *_G1_roll __attribute__((unused)), uint8_t nb_G1_pitch __attribute__((unused)), float *_G1_pitch __attribute__((unused)), uint8_t nb_G1_yaw __attribute__((unused)), float *_G1_yaw __attribute__((unused)), uint8_t nb_G1_thrust __attribute__((unused)), float *_G1_thrust __attribute__((unused)), uint8_t nb_G2 __attribute__((unused)), float *_G2 __attribute__((unused))) {}

#endif // DOWNLINK

/** Getter for length of array G1_roll in message INDI_G
 *
 * @return G1_roll : 
 */
 static inline uint8_t pprzlink_get_INDI_G_G1_roll_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 4);
}

/** Getter for field G1_roll in message INDI_G
  *
  * @param _payload : a pointer to the INDI_G message
  * @return 
  */
static inline float * pprzlink_get_DL_INDI_G_G1_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 5);
}

/** Getter for length of array G1_pitch in message INDI_G
 *
 * @return G1_pitch : 
 */
 static inline uint8_t pprzlink_get_INDI_G_G1_pitch_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 5);
}

/** Getter for field G1_pitch in message INDI_G
  *
  * @param _payload : a pointer to the INDI_G message
  * @return 
  */
static inline float * pprzlink_get_DL_INDI_G_G1_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 6);
}

/** Getter for length of array G1_yaw in message INDI_G
 *
 * @return G1_yaw : 
 */
 static inline uint8_t pprzlink_get_INDI_G_G1_yaw_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 6);
}

/** Getter for field G1_yaw in message INDI_G
  *
  * @param _payload : a pointer to the INDI_G message
  * @return 
  */
static inline float * pprzlink_get_DL_INDI_G_G1_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 7);
}

/** Getter for length of array G1_thrust in message INDI_G
 *
 * @return G1_thrust : 
 */
 static inline uint8_t pprzlink_get_INDI_G_G1_thrust_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 7);
}

/** Getter for field G1_thrust in message INDI_G
  *
  * @param _payload : a pointer to the INDI_G message
  * @return 
  */
static inline float * pprzlink_get_DL_INDI_G_G1_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 8);
}

/** Getter for length of array G2 in message INDI_G
 *
 * @return G2 : 
 */
 static inline uint8_t pprzlink_get_INDI_G_G2_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 8);
}

/** Getter for field G2 in message INDI_G
  *
  * @param _payload : a pointer to the INDI_G message
  * @return 
  */
static inline float * pprzlink_get_DL_INDI_G_G2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 9);
}


/* Compatibility macros */
#define DL_INDI_G_G1_roll_length(_payload) pprzlink_get_INDI_G_G1_roll_length(_payload)
#define DL_INDI_G_G1_roll(_payload) pprzlink_get_DL_INDI_G_G1_roll(_payload)
#define DL_INDI_G_G1_pitch_length(_payload) pprzlink_get_INDI_G_G1_pitch_length(_payload)
#define DL_INDI_G_G1_pitch(_payload) pprzlink_get_DL_INDI_G_G1_pitch(_payload)
#define DL_INDI_G_G1_yaw_length(_payload) pprzlink_get_INDI_G_G1_yaw_length(_payload)
#define DL_INDI_G_G1_yaw(_payload) pprzlink_get_DL_INDI_G_G1_yaw(_payload)
#define DL_INDI_G_G1_thrust_length(_payload) pprzlink_get_INDI_G_G1_thrust_length(_payload)
#define DL_INDI_G_G1_thrust(_payload) pprzlink_get_DL_INDI_G_G1_thrust(_payload)
#define DL_INDI_G_G2_length(_payload) pprzlink_get_INDI_G_G2_length(_payload)
#define DL_INDI_G_G2(_payload) pprzlink_get_DL_INDI_G_G2(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INDI_G_H_

