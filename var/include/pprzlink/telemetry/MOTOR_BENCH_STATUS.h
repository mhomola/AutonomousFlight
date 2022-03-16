/** @file
 *  @brief PPRZLink message header for MOTOR_BENCH_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MOTOR_BENCH_STATUS_H_
#define _VAR_MESSAGES_telemetry_MOTOR_BENCH_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MOTOR_BENCH_STATUS 94
#define PPRZ_MSG_ID_MOTOR_BENCH_STATUS 94

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MOTOR_BENCH_STATUS _send_msg(MOTOR_BENCH_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MOTOR_BENCH_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _time_ticks 
 * @param _throttle 
 * @param _rpm 
 * @param _current 
 * @param _thrust 
 * @param _torque 
 * @param _time_s 
 * @param _mode 
 */
static inline void pprzlink_msg_v2_send_MOTOR_BENCH_STATUS(struct pprzlink_msg * msg, uint32_t *_time_ticks, float *_throttle, float *_rpm, float *_current, float *_thrust, float *_torque, uint16_t *_time_s, uint8_t *_mode) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MOTOR_BENCH_STATUS, "MOTOR_BENCH_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _time_ticks, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _throttle, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rpm, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _torque, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _time_s, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _mode, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MOTOR_BENCH_STATUS pprz_msg_send_MOTOR_BENCH_STATUS
#define DOWNLINK_SEND_MOTOR_BENCH_STATUS(_trans, _dev, time_ticks, throttle, rpm, current, thrust, torque, time_s, mode) pprz_msg_send_MOTOR_BENCH_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, time_ticks, throttle, rpm, current, thrust, torque, time_s, mode)
/**
 * Sends a MOTOR_BENCH_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _time_ticks 
 * @param _throttle 
 * @param _rpm 
 * @param _current 
 * @param _thrust 
 * @param _torque 
 * @param _time_s 
 * @param _mode 
 */
static inline void pprz_msg_send_MOTOR_BENCH_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_time_ticks, float *_throttle, float *_rpm, float *_current, float *_thrust, float *_torque, uint16_t *_time_s, uint8_t *_mode) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MOTOR_BENCH_STATUS(&msg,_time_ticks,_throttle,_rpm,_current,_thrust,_torque,_time_s,_mode);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MOTOR_BENCH_STATUS(_trans, _dev, time_ticks, throttle, rpm, current, thrust, torque, time_s, mode) {}
static inline void pprz_send_msg_MOTOR_BENCH_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_time_ticks __attribute__((unused)), float *_throttle __attribute__((unused)), float *_rpm __attribute__((unused)), float *_current __attribute__((unused)), float *_thrust __attribute__((unused)), float *_torque __attribute__((unused)), uint16_t *_time_s __attribute__((unused)), uint8_t *_mode __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field time_ticks in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_MOTOR_BENCH_STATUS_time_ticks(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field throttle in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_BENCH_STATUS_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field rpm in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_BENCH_STATUS_rpm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field current in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_BENCH_STATUS_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field thrust in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_BENCH_STATUS_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field torque in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MOTOR_BENCH_STATUS_torque(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field time_s in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MOTOR_BENCH_STATUS_time_s(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 28);
}


/** Getter for field mode in message MOTOR_BENCH_STATUS
  *
  * @param _payload : a pointer to the MOTOR_BENCH_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MOTOR_BENCH_STATUS_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 30);
}


/* Compatibility macros */
#define DL_MOTOR_BENCH_STATUS_time_ticks(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_time_ticks(_payload)
#define DL_MOTOR_BENCH_STATUS_throttle(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_throttle(_payload)
#define DL_MOTOR_BENCH_STATUS_rpm(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_rpm(_payload)
#define DL_MOTOR_BENCH_STATUS_current(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_current(_payload)
#define DL_MOTOR_BENCH_STATUS_thrust(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_thrust(_payload)
#define DL_MOTOR_BENCH_STATUS_torque(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_torque(_payload)
#define DL_MOTOR_BENCH_STATUS_time_s(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_time_s(_payload)
#define DL_MOTOR_BENCH_STATUS_mode(_payload) pprzlink_get_DL_MOTOR_BENCH_STATUS_mode(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MOTOR_BENCH_STATUS_H_

