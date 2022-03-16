/** @file
 *  @brief PPRZLink message header for GUIDANCE_INDI_HYBRID in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GUIDANCE_INDI_HYBRID_H_
#define _VAR_MESSAGES_telemetry_GUIDANCE_INDI_HYBRID_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GUIDANCE_INDI_HYBRID 37
#define PPRZ_MSG_ID_GUIDANCE_INDI_HYBRID 37

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GUIDANCE_INDI_HYBRID _send_msg(GUIDANCE_INDI_HYBRID,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GUIDANCE_INDI_HYBRID message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_accel_x 
 * @param _sp_accel_y 
 * @param _sp_accel_z 
 * @param _euler_cmd_x 
 * @param _euler_cmd_y 
 * @param _euler_cmd_z 
 * @param _accelned_filt_x 
 * @param _accelned_filt_y 
 * @param _accelned_filt_z 
 * @param _speed_sp_x 
 * @param _speed_sp_y 
 * @param _speed_sp_z 
 */
static inline void pprzlink_msg_v2_send_GUIDANCE_INDI_HYBRID(struct pprzlink_msg * msg, float *_sp_accel_x, float *_sp_accel_y, float *_sp_accel_z, float *_euler_cmd_x, float *_euler_cmd_y, float *_euler_cmd_z, float *_accelned_filt_x, float *_accelned_filt_y, float *_accelned_filt_z, float *_speed_sp_x, float *_speed_sp_y, float *_speed_sp_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GUIDANCE_INDI_HYBRID, "GUIDANCE_INDI_HYBRID");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_accel_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_accel_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sp_accel_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _euler_cmd_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _euler_cmd_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _euler_cmd_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accelned_filt_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accelned_filt_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _accelned_filt_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed_sp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed_sp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _speed_sp_z, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GUIDANCE_INDI_HYBRID pprz_msg_send_GUIDANCE_INDI_HYBRID
#define DOWNLINK_SEND_GUIDANCE_INDI_HYBRID(_trans, _dev, sp_accel_x, sp_accel_y, sp_accel_z, euler_cmd_x, euler_cmd_y, euler_cmd_z, accelned_filt_x, accelned_filt_y, accelned_filt_z, speed_sp_x, speed_sp_y, speed_sp_z) pprz_msg_send_GUIDANCE_INDI_HYBRID(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_accel_x, sp_accel_y, sp_accel_z, euler_cmd_x, euler_cmd_y, euler_cmd_z, accelned_filt_x, accelned_filt_y, accelned_filt_z, speed_sp_x, speed_sp_y, speed_sp_z)
/**
 * Sends a GUIDANCE_INDI_HYBRID message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_accel_x 
 * @param _sp_accel_y 
 * @param _sp_accel_z 
 * @param _euler_cmd_x 
 * @param _euler_cmd_y 
 * @param _euler_cmd_z 
 * @param _accelned_filt_x 
 * @param _accelned_filt_y 
 * @param _accelned_filt_z 
 * @param _speed_sp_x 
 * @param _speed_sp_y 
 * @param _speed_sp_z 
 */
static inline void pprz_msg_send_GUIDANCE_INDI_HYBRID(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_sp_accel_x, float *_sp_accel_y, float *_sp_accel_z, float *_euler_cmd_x, float *_euler_cmd_y, float *_euler_cmd_z, float *_accelned_filt_x, float *_accelned_filt_y, float *_accelned_filt_z, float *_speed_sp_x, float *_speed_sp_y, float *_speed_sp_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GUIDANCE_INDI_HYBRID(&msg,_sp_accel_x,_sp_accel_y,_sp_accel_z,_euler_cmd_x,_euler_cmd_y,_euler_cmd_z,_accelned_filt_x,_accelned_filt_y,_accelned_filt_z,_speed_sp_x,_speed_sp_y,_speed_sp_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GUIDANCE_INDI_HYBRID(_trans, _dev, sp_accel_x, sp_accel_y, sp_accel_z, euler_cmd_x, euler_cmd_y, euler_cmd_z, accelned_filt_x, accelned_filt_y, accelned_filt_z, speed_sp_x, speed_sp_y, speed_sp_z) {}
static inline void pprz_send_msg_GUIDANCE_INDI_HYBRID(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_sp_accel_x __attribute__((unused)), float *_sp_accel_y __attribute__((unused)), float *_sp_accel_z __attribute__((unused)), float *_euler_cmd_x __attribute__((unused)), float *_euler_cmd_y __attribute__((unused)), float *_euler_cmd_z __attribute__((unused)), float *_accelned_filt_x __attribute__((unused)), float *_accelned_filt_y __attribute__((unused)), float *_accelned_filt_z __attribute__((unused)), float *_speed_sp_x __attribute__((unused)), float *_speed_sp_y __attribute__((unused)), float *_speed_sp_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_accel_x in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field sp_accel_y in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field sp_accel_z in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field euler_cmd_x in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field euler_cmd_y in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field euler_cmd_z in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field accelned_filt_x in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field accelned_filt_y in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field accelned_filt_z in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field speed_sp_x in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field speed_sp_y in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field speed_sp_z in message GUIDANCE_INDI_HYBRID
  *
  * @param _payload : a pointer to the GUIDANCE_INDI_HYBRID message
  * @return 
  */
static inline float pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/* Compatibility macros */
#define DL_GUIDANCE_INDI_HYBRID_sp_accel_x(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_x(_payload)
#define DL_GUIDANCE_INDI_HYBRID_sp_accel_y(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_y(_payload)
#define DL_GUIDANCE_INDI_HYBRID_sp_accel_z(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_sp_accel_z(_payload)
#define DL_GUIDANCE_INDI_HYBRID_euler_cmd_x(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_x(_payload)
#define DL_GUIDANCE_INDI_HYBRID_euler_cmd_y(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_y(_payload)
#define DL_GUIDANCE_INDI_HYBRID_euler_cmd_z(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_euler_cmd_z(_payload)
#define DL_GUIDANCE_INDI_HYBRID_accelned_filt_x(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_x(_payload)
#define DL_GUIDANCE_INDI_HYBRID_accelned_filt_y(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_y(_payload)
#define DL_GUIDANCE_INDI_HYBRID_accelned_filt_z(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_accelned_filt_z(_payload)
#define DL_GUIDANCE_INDI_HYBRID_speed_sp_x(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_x(_payload)
#define DL_GUIDANCE_INDI_HYBRID_speed_sp_y(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_y(_payload)
#define DL_GUIDANCE_INDI_HYBRID_speed_sp_z(_payload) pprzlink_get_DL_GUIDANCE_INDI_HYBRID_speed_sp_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GUIDANCE_INDI_HYBRID_H_

