/** @file
 *  @brief PPRZLink message header for ESC in class telemetry
 *
 *  
        Electronic Speed Controller data
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ESC_H_
#define _VAR_MESSAGES_telemetry_ESC_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ESC 245
#define PPRZ_MSG_ID_ESC 245

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ESC _send_msg(ESC,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ESC message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _amps Current consumption
 * @param _bat_volts Input battery voltage
 * @param _power Electrical power
 * @param _rpm Motor rotation speed
 * @param _motor_volts Motor voltage
 * @param _energy Accumulated consumed energy
 * @param _motor_id Motor ID
 */
static inline void pprzlink_msg_v2_send_ESC(struct pprzlink_msg * msg, float *_amps, float *_bat_volts, float *_power, float *_rpm, float *_motor_volts, float *_energy, uint8_t *_motor_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ESC, "ESC");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _amps, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bat_volts, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _power, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _rpm, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _motor_volts, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _energy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _motor_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ESC pprz_msg_send_ESC
#define DOWNLINK_SEND_ESC(_trans, _dev, amps, bat_volts, power, rpm, motor_volts, energy, motor_id) pprz_msg_send_ESC(&((_trans).trans_tx), &((_dev).device), AC_ID, amps, bat_volts, power, rpm, motor_volts, energy, motor_id)
/**
 * Sends a ESC message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _amps Current consumption
 * @param _bat_volts Input battery voltage
 * @param _power Electrical power
 * @param _rpm Motor rotation speed
 * @param _motor_volts Motor voltage
 * @param _energy Accumulated consumed energy
 * @param _motor_id Motor ID
 */
static inline void pprz_msg_send_ESC(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_amps, float *_bat_volts, float *_power, float *_rpm, float *_motor_volts, float *_energy, uint8_t *_motor_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ESC(&msg,_amps,_bat_volts,_power,_rpm,_motor_volts,_energy,_motor_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ESC(_trans, _dev, amps, bat_volts, power, rpm, motor_volts, energy, motor_id) {}
static inline void pprz_send_msg_ESC(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_amps __attribute__((unused)), float *_bat_volts __attribute__((unused)), float *_power __attribute__((unused)), float *_rpm __attribute__((unused)), float *_motor_volts __attribute__((unused)), float *_energy __attribute__((unused)), uint8_t *_motor_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field amps in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Current consumption
  */
static inline float pprzlink_get_DL_ESC_amps(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field bat_volts in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Input battery voltage
  */
static inline float pprzlink_get_DL_ESC_bat_volts(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field power in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Electrical power
  */
static inline float pprzlink_get_DL_ESC_power(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field rpm in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Motor rotation speed
  */
static inline float pprzlink_get_DL_ESC_rpm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field motor_volts in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Motor voltage
  */
static inline float pprzlink_get_DL_ESC_motor_volts(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field energy in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Accumulated consumed energy
  */
static inline float pprzlink_get_DL_ESC_energy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field motor_id in message ESC
  *
  * @param _payload : a pointer to the ESC message
  * @return Motor ID
  */
static inline uint8_t pprzlink_get_DL_ESC_motor_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 28);
}


/* Compatibility macros */
#define DL_ESC_amps(_payload) pprzlink_get_DL_ESC_amps(_payload)
#define DL_ESC_bat_volts(_payload) pprzlink_get_DL_ESC_bat_volts(_payload)
#define DL_ESC_power(_payload) pprzlink_get_DL_ESC_power(_payload)
#define DL_ESC_rpm(_payload) pprzlink_get_DL_ESC_rpm(_payload)
#define DL_ESC_motor_volts(_payload) pprzlink_get_DL_ESC_motor_volts(_payload)
#define DL_ESC_energy(_payload) pprzlink_get_DL_ESC_energy(_payload)
#define DL_ESC_motor_id(_payload) pprzlink_get_DL_ESC_motor_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ESC_H_

