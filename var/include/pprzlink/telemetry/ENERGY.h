/** @file
 *  @brief PPRZLink message header for ENERGY in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ENERGY_H_
#define _VAR_MESSAGES_telemetry_ENERGY_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ENERGY 12
#define PPRZ_MSG_ID_ENERGY 12

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ENERGY _send_msg(ENERGY,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ENERGY message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _throttle Throttle setting
 * @param _voltage Input battery voltage
 * @param _current Current consumption
 * @param _power Electrical power
 * @param _charge Accumulated consumed charge
 * @param _energy Accumulated consumed energy
 */
static inline void pprzlink_msg_v2_send_ENERGY(struct pprzlink_msg * msg, uint8_t *_throttle, float *_voltage, float *_current, float *_power, float *_charge, float *_energy) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ENERGY, "ENERGY");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _throttle, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _voltage, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _power, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _charge, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _energy, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ENERGY pprz_msg_send_ENERGY
#define DOWNLINK_SEND_ENERGY(_trans, _dev, throttle, voltage, current, power, charge, energy) pprz_msg_send_ENERGY(&((_trans).trans_tx), &((_dev).device), AC_ID, throttle, voltage, current, power, charge, energy)
/**
 * Sends a ENERGY message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _throttle Throttle setting
 * @param _voltage Input battery voltage
 * @param _current Current consumption
 * @param _power Electrical power
 * @param _charge Accumulated consumed charge
 * @param _energy Accumulated consumed energy
 */
static inline void pprz_msg_send_ENERGY(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_throttle, float *_voltage, float *_current, float *_power, float *_charge, float *_energy) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ENERGY(&msg,_throttle,_voltage,_current,_power,_charge,_energy);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ENERGY(_trans, _dev, throttle, voltage, current, power, charge, energy) {}
static inline void pprz_send_msg_ENERGY(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_throttle __attribute__((unused)), float *_voltage __attribute__((unused)), float *_current __attribute__((unused)), float *_power __attribute__((unused)), float *_charge __attribute__((unused)), float *_energy __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field throttle in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Throttle setting
  */
static inline uint8_t pprzlink_get_DL_ENERGY_throttle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field voltage in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Input battery voltage
  */
static inline float pprzlink_get_DL_ENERGY_voltage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/** Getter for field current in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Current consumption
  */
static inline float pprzlink_get_DL_ENERGY_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field power in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Electrical power
  */
static inline float pprzlink_get_DL_ENERGY_power(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 13);
}


/** Getter for field charge in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Accumulated consumed charge
  */
static inline float pprzlink_get_DL_ENERGY_charge(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 17);
}


/** Getter for field energy in message ENERGY
  *
  * @param _payload : a pointer to the ENERGY message
  * @return Accumulated consumed energy
  */
static inline float pprzlink_get_DL_ENERGY_energy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 21);
}


/* Compatibility macros */
#define DL_ENERGY_throttle(_payload) pprzlink_get_DL_ENERGY_throttle(_payload)
#define DL_ENERGY_voltage(_payload) pprzlink_get_DL_ENERGY_voltage(_payload)
#define DL_ENERGY_current(_payload) pprzlink_get_DL_ENERGY_current(_payload)
#define DL_ENERGY_power(_payload) pprzlink_get_DL_ENERGY_power(_payload)
#define DL_ENERGY_charge(_payload) pprzlink_get_DL_ENERGY_charge(_payload)
#define DL_ENERGY_energy(_payload) pprzlink_get_DL_ENERGY_energy(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ENERGY_H_

