/** @file
 *  @brief PPRZLink message header for AIR_DATA in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AIR_DATA_H_
#define _VAR_MESSAGES_telemetry_AIR_DATA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AIR_DATA 222
#define PPRZ_MSG_ID_AIR_DATA 222

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AIR_DATA _send_msg(AIR_DATA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AIR_DATA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pressure static pressure
 * @param _diff_p differential pressure
 * @param _temp air temperature
 * @param _qnh barometric pressure adjusted to sea level
 * @param _amsl_baro barometric altitude above mean sea level
 * @param _airspeed Equivalent Air Speed (or Calibrated Air Speed at low speed/altitude)
 * @param _tas True Air Speed (when P, T and P_diff are available)
 */
static inline void pprzlink_msg_v2_send_AIR_DATA(struct pprzlink_msg * msg, float *_pressure, float *_diff_p, float *_temp, float *_qnh, float *_amsl_baro, float *_airspeed, float *_tas) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AIR_DATA, "AIR_DATA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _diff_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _qnh, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _amsl_baro, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _tas, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AIR_DATA pprz_msg_send_AIR_DATA
#define DOWNLINK_SEND_AIR_DATA(_trans, _dev, pressure, diff_p, temp, qnh, amsl_baro, airspeed, tas) pprz_msg_send_AIR_DATA(&((_trans).trans_tx), &((_dev).device), AC_ID, pressure, diff_p, temp, qnh, amsl_baro, airspeed, tas)
/**
 * Sends a AIR_DATA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pressure static pressure
 * @param _diff_p differential pressure
 * @param _temp air temperature
 * @param _qnh barometric pressure adjusted to sea level
 * @param _amsl_baro barometric altitude above mean sea level
 * @param _airspeed Equivalent Air Speed (or Calibrated Air Speed at low speed/altitude)
 * @param _tas True Air Speed (when P, T and P_diff are available)
 */
static inline void pprz_msg_send_AIR_DATA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_pressure, float *_diff_p, float *_temp, float *_qnh, float *_amsl_baro, float *_airspeed, float *_tas) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AIR_DATA(&msg,_pressure,_diff_p,_temp,_qnh,_amsl_baro,_airspeed,_tas);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AIR_DATA(_trans, _dev, pressure, diff_p, temp, qnh, amsl_baro, airspeed, tas) {}
static inline void pprz_send_msg_AIR_DATA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_pressure __attribute__((unused)), float *_diff_p __attribute__((unused)), float *_temp __attribute__((unused)), float *_qnh __attribute__((unused)), float *_amsl_baro __attribute__((unused)), float *_airspeed __attribute__((unused)), float *_tas __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pressure in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return static pressure
  */
static inline float pprzlink_get_DL_AIR_DATA_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field diff_p in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return differential pressure
  */
static inline float pprzlink_get_DL_AIR_DATA_diff_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field temp in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return air temperature
  */
static inline float pprzlink_get_DL_AIR_DATA_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field qnh in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return barometric pressure adjusted to sea level
  */
static inline float pprzlink_get_DL_AIR_DATA_qnh(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field amsl_baro in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return barometric altitude above mean sea level
  */
static inline float pprzlink_get_DL_AIR_DATA_amsl_baro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field airspeed in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return Equivalent Air Speed (or Calibrated Air Speed at low speed/altitude)
  */
static inline float pprzlink_get_DL_AIR_DATA_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field tas in message AIR_DATA
  *
  * @param _payload : a pointer to the AIR_DATA message
  * @return True Air Speed (when P, T and P_diff are available)
  */
static inline float pprzlink_get_DL_AIR_DATA_tas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_AIR_DATA_pressure(_payload) pprzlink_get_DL_AIR_DATA_pressure(_payload)
#define DL_AIR_DATA_diff_p(_payload) pprzlink_get_DL_AIR_DATA_diff_p(_payload)
#define DL_AIR_DATA_temp(_payload) pprzlink_get_DL_AIR_DATA_temp(_payload)
#define DL_AIR_DATA_qnh(_payload) pprzlink_get_DL_AIR_DATA_qnh(_payload)
#define DL_AIR_DATA_amsl_baro(_payload) pprzlink_get_DL_AIR_DATA_amsl_baro(_payload)
#define DL_AIR_DATA_airspeed(_payload) pprzlink_get_DL_AIR_DATA_airspeed(_payload)
#define DL_AIR_DATA_tas(_payload) pprzlink_get_DL_AIR_DATA_tas(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AIR_DATA_H_

