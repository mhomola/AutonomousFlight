/** @file
 *  @brief PPRZLink message header for WINDTUNNEL_MEAS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_WINDTUNNEL_MEAS_H_
#define _VAR_MESSAGES_telemetry_WINDTUNNEL_MEAS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WINDTUNNEL_MEAS 211
#define PPRZ_MSG_ID_WINDTUNNEL_MEAS 211

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WINDTUNNEL_MEAS _send_msg(WINDTUNNEL_MEAS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WINDTUNNEL_MEAS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _aoa Angle of attack
 * @param _airspeed Airspeed measured
 * @param _voltage Voltage measured
 * @param _current Current measured
 * @param _power Calculated power (Voltage * Current)
 * @param nb_commands,_commands Commands send to actuators
 */
static inline void pprzlink_msg_v2_send_WINDTUNNEL_MEAS(struct pprzlink_msg * msg, float *_aoa, float *_airspeed, float *_voltage, float *_current, float *_power, uint8_t nb_commands, int32_t *_commands) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+1+nb_commands*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+1+nb_commands*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WINDTUNNEL_MEAS, "WINDTUNNEL_MEAS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _aoa, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _voltage, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _power, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_commands, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_ARRAY, (void *) _commands, nb_commands*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WINDTUNNEL_MEAS pprz_msg_send_WINDTUNNEL_MEAS
#define DOWNLINK_SEND_WINDTUNNEL_MEAS(_trans, _dev, aoa, airspeed, voltage, current, power, nb_commands, commands) pprz_msg_send_WINDTUNNEL_MEAS(&((_trans).trans_tx), &((_dev).device), AC_ID, aoa, airspeed, voltage, current, power, nb_commands, commands)
/**
 * Sends a WINDTUNNEL_MEAS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _aoa Angle of attack
 * @param _airspeed Airspeed measured
 * @param _voltage Voltage measured
 * @param _current Current measured
 * @param _power Calculated power (Voltage * Current)
 * @param nb_commands,_commands Commands send to actuators
 */
static inline void pprz_msg_send_WINDTUNNEL_MEAS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_aoa, float *_airspeed, float *_voltage, float *_current, float *_power, uint8_t nb_commands, int32_t *_commands) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WINDTUNNEL_MEAS(&msg,_aoa,_airspeed,_voltage,_current,_power,nb_commands,_commands);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WINDTUNNEL_MEAS(_trans, _dev, aoa, airspeed, voltage, current, power, nb_commands, commands) {}
static inline void pprz_send_msg_WINDTUNNEL_MEAS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_aoa __attribute__((unused)), float *_airspeed __attribute__((unused)), float *_voltage __attribute__((unused)), float *_current __attribute__((unused)), float *_power __attribute__((unused)), uint8_t nb_commands __attribute__((unused)), int32_t *_commands __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field aoa in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Angle of attack
  */
static inline float pprzlink_get_DL_WINDTUNNEL_MEAS_aoa(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field airspeed in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Airspeed measured
  */
static inline float pprzlink_get_DL_WINDTUNNEL_MEAS_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field voltage in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Voltage measured
  */
static inline float pprzlink_get_DL_WINDTUNNEL_MEAS_voltage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field current in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Current measured
  */
static inline float pprzlink_get_DL_WINDTUNNEL_MEAS_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field power in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Calculated power (Voltage * Current)
  */
static inline float pprzlink_get_DL_WINDTUNNEL_MEAS_power(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}

/** Getter for length of array commands in message WINDTUNNEL_MEAS
 *
 * @return commands : Commands send to actuators
 */
 static inline uint8_t pprzlink_get_WINDTUNNEL_MEAS_commands_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 24);
}

/** Getter for field commands in message WINDTUNNEL_MEAS
  *
  * @param _payload : a pointer to the WINDTUNNEL_MEAS message
  * @return Commands send to actuators
  */
static inline int32_t * pprzlink_get_DL_WINDTUNNEL_MEAS_commands(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t_array(_payload, 25);
}


/* Compatibility macros */
#define DL_WINDTUNNEL_MEAS_aoa(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_aoa(_payload)
#define DL_WINDTUNNEL_MEAS_airspeed(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_airspeed(_payload)
#define DL_WINDTUNNEL_MEAS_voltage(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_voltage(_payload)
#define DL_WINDTUNNEL_MEAS_current(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_current(_payload)
#define DL_WINDTUNNEL_MEAS_power(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_power(_payload)
#define DL_WINDTUNNEL_MEAS_commands_length(_payload) pprzlink_get_WINDTUNNEL_MEAS_commands_length(_payload)
#define DL_WINDTUNNEL_MEAS_commands(_payload) pprzlink_get_DL_WINDTUNNEL_MEAS_commands(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_WINDTUNNEL_MEAS_H_

