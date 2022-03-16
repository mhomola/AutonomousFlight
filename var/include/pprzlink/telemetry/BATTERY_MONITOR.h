/** @file
 *  @brief PPRZLink message header for BATTERY_MONITOR in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_BATTERY_MONITOR_H_
#define _VAR_MESSAGES_telemetry_BATTERY_MONITOR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BATTERY_MONITOR 248
#define PPRZ_MSG_ID_BATTERY_MONITOR 248

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BATTERY_MONITOR _send_msg(BATTERY_MONITOR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BATTERY_MONITOR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _version Battery monitor version
 * @param _bus_dev_stat Bus monitor status
 * @param _bus_trans_stat Bus monitor i2c transaction status
 * @param _current_raw Raw bus current reading
 * @param _current Bus current
 * @param _bus_voltage Bus voltage
 * @param nb_bus_temp_raw,_bus_temp_raw Raw temperature reading
 * @param nb_bus_temp,_bus_temp Battery temperatures
 * @param _bal1_trans_stat Cell bank 1 monitor i2c transaction status
 * @param nb_bal1_cells,_bal1_cells Cell bank 1 voltage
 * @param _bal2_trans_stat Cell bank 2 monitor i2c transaction status
 * @param nb_bal2_cells,_bal2_cells Cell bank 2 voltage
 * @param _safety_plug Safety plug voltage
 */
static inline void pprzlink_msg_v2_send_BATTERY_MONITOR(struct pprzlink_msg * msg, uint8_t *_version, uint8_t *_bus_dev_stat, uint8_t *_bus_trans_stat, uint16_t *_current_raw, float *_current, uint16_t *_bus_voltage, uint8_t nb_bus_temp_raw, uint16_t *_bus_temp_raw, uint8_t nb_bus_temp, float *_bus_temp, uint8_t *_bal1_trans_stat, uint8_t nb_bal1_cells, uint16_t *_bal1_cells, uint8_t *_bal2_trans_stat, uint8_t nb_bal2_cells, uint16_t *_bal2_cells, uint16_t *_safety_plug) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+2+4+2+1+nb_bus_temp_raw*2+1+nb_bus_temp*4+1+1+nb_bal1_cells*2+1+1+nb_bal2_cells*2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+2+4+2+1+nb_bus_temp_raw*2+1+nb_bus_temp*4+1+1+nb_bal1_cells*2+1+1+nb_bal2_cells*2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BATTERY_MONITOR, "BATTERY_MONITOR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _version, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bus_dev_stat, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bus_trans_stat, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _current_raw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _bus_voltage, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_bus_temp_raw, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_ARRAY, (void *) _bus_temp_raw, nb_bus_temp_raw*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_bus_temp, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _bus_temp, nb_bus_temp*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bal1_trans_stat, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_bal1_cells, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_ARRAY, (void *) _bal1_cells, nb_bal1_cells*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bal2_trans_stat, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_bal2_cells, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_ARRAY, (void *) _bal2_cells, nb_bal2_cells*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _safety_plug, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BATTERY_MONITOR pprz_msg_send_BATTERY_MONITOR
#define DOWNLINK_SEND_BATTERY_MONITOR(_trans, _dev, version, bus_dev_stat, bus_trans_stat, current_raw, current, bus_voltage, nb_bus_temp_raw, bus_temp_raw, nb_bus_temp, bus_temp, bal1_trans_stat, nb_bal1_cells, bal1_cells, bal2_trans_stat, nb_bal2_cells, bal2_cells, safety_plug) pprz_msg_send_BATTERY_MONITOR(&((_trans).trans_tx), &((_dev).device), AC_ID, version, bus_dev_stat, bus_trans_stat, current_raw, current, bus_voltage, nb_bus_temp_raw, bus_temp_raw, nb_bus_temp, bus_temp, bal1_trans_stat, nb_bal1_cells, bal1_cells, bal2_trans_stat, nb_bal2_cells, bal2_cells, safety_plug)
/**
 * Sends a BATTERY_MONITOR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _version Battery monitor version
 * @param _bus_dev_stat Bus monitor status
 * @param _bus_trans_stat Bus monitor i2c transaction status
 * @param _current_raw Raw bus current reading
 * @param _current Bus current
 * @param _bus_voltage Bus voltage
 * @param nb_bus_temp_raw,_bus_temp_raw Raw temperature reading
 * @param nb_bus_temp,_bus_temp Battery temperatures
 * @param _bal1_trans_stat Cell bank 1 monitor i2c transaction status
 * @param nb_bal1_cells,_bal1_cells Cell bank 1 voltage
 * @param _bal2_trans_stat Cell bank 2 monitor i2c transaction status
 * @param nb_bal2_cells,_bal2_cells Cell bank 2 voltage
 * @param _safety_plug Safety plug voltage
 */
static inline void pprz_msg_send_BATTERY_MONITOR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_version, uint8_t *_bus_dev_stat, uint8_t *_bus_trans_stat, uint16_t *_current_raw, float *_current, uint16_t *_bus_voltage, uint8_t nb_bus_temp_raw, uint16_t *_bus_temp_raw, uint8_t nb_bus_temp, float *_bus_temp, uint8_t *_bal1_trans_stat, uint8_t nb_bal1_cells, uint16_t *_bal1_cells, uint8_t *_bal2_trans_stat, uint8_t nb_bal2_cells, uint16_t *_bal2_cells, uint16_t *_safety_plug) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BATTERY_MONITOR(&msg,_version,_bus_dev_stat,_bus_trans_stat,_current_raw,_current,_bus_voltage,nb_bus_temp_raw,_bus_temp_raw,nb_bus_temp,_bus_temp,_bal1_trans_stat,nb_bal1_cells,_bal1_cells,_bal2_trans_stat,nb_bal2_cells,_bal2_cells,_safety_plug);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BATTERY_MONITOR(_trans, _dev, version, bus_dev_stat, bus_trans_stat, current_raw, current, bus_voltage, nb_bus_temp_raw, bus_temp_raw, nb_bus_temp, bus_temp, bal1_trans_stat, nb_bal1_cells, bal1_cells, bal2_trans_stat, nb_bal2_cells, bal2_cells, safety_plug) {}
static inline void pprz_send_msg_BATTERY_MONITOR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_version __attribute__((unused)), uint8_t *_bus_dev_stat __attribute__((unused)), uint8_t *_bus_trans_stat __attribute__((unused)), uint16_t *_current_raw __attribute__((unused)), float *_current __attribute__((unused)), uint16_t *_bus_voltage __attribute__((unused)), uint8_t nb_bus_temp_raw __attribute__((unused)), uint16_t *_bus_temp_raw __attribute__((unused)), uint8_t nb_bus_temp __attribute__((unused)), float *_bus_temp __attribute__((unused)), uint8_t *_bal1_trans_stat __attribute__((unused)), uint8_t nb_bal1_cells __attribute__((unused)), uint16_t *_bal1_cells __attribute__((unused)), uint8_t *_bal2_trans_stat __attribute__((unused)), uint8_t nb_bal2_cells __attribute__((unused)), uint16_t *_bal2_cells __attribute__((unused)), uint16_t *_safety_plug __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field version in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Battery monitor version
  */
static inline uint8_t pprzlink_get_DL_BATTERY_MONITOR_version(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field bus_dev_stat in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Bus monitor status
  */
static inline uint8_t pprzlink_get_DL_BATTERY_MONITOR_bus_dev_stat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field bus_trans_stat in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Bus monitor i2c transaction status
  */
static inline uint8_t pprzlink_get_DL_BATTERY_MONITOR_bus_trans_stat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field current_raw in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Raw bus current reading
  */
static inline uint16_t pprzlink_get_DL_BATTERY_MONITOR_current_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 7);
}


/** Getter for field current in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Bus current
  */
static inline float pprzlink_get_DL_BATTERY_MONITOR_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field bus_voltage in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Bus voltage
  */
static inline uint16_t pprzlink_get_DL_BATTERY_MONITOR_bus_voltage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 13);
}

/** Getter for length of array bus_temp_raw in message BATTERY_MONITOR
 *
 * @return bus_temp_raw : Raw temperature reading
 */
 static inline uint8_t pprzlink_get_BATTERY_MONITOR_bus_temp_raw_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 15);
}

/** Getter for field bus_temp_raw in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Raw temperature reading
  */
static inline uint16_t * pprzlink_get_DL_BATTERY_MONITOR_bus_temp_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t_array(_payload, 16);
}

/** Getter for length of array bus_temp in message BATTERY_MONITOR
 *
 * @return bus_temp : Battery temperatures
 */
 static inline uint8_t pprzlink_get_BATTERY_MONITOR_bus_temp_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 16);
}

/** Getter for field bus_temp in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Battery temperatures
  */
static inline float * pprzlink_get_DL_BATTERY_MONITOR_bus_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 17);
}


/** Getter for field bal1_trans_stat in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Cell bank 1 monitor i2c transaction status
  */
static inline uint8_t pprzlink_get_DL_BATTERY_MONITOR_bal1_trans_stat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 17);
}

/** Getter for length of array bal1_cells in message BATTERY_MONITOR
 *
 * @return bal1_cells : Cell bank 1 voltage
 */
 static inline uint8_t pprzlink_get_BATTERY_MONITOR_bal1_cells_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 18);
}

/** Getter for field bal1_cells in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Cell bank 1 voltage
  */
static inline uint16_t * pprzlink_get_DL_BATTERY_MONITOR_bal1_cells(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t_array(_payload, 19);
}


/** Getter for field bal2_trans_stat in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Cell bank 2 monitor i2c transaction status
  */
static inline uint8_t pprzlink_get_DL_BATTERY_MONITOR_bal2_trans_stat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 19);
}

/** Getter for length of array bal2_cells in message BATTERY_MONITOR
 *
 * @return bal2_cells : Cell bank 2 voltage
 */
 static inline uint8_t pprzlink_get_BATTERY_MONITOR_bal2_cells_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 20);
}

/** Getter for field bal2_cells in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Cell bank 2 voltage
  */
static inline uint16_t * pprzlink_get_DL_BATTERY_MONITOR_bal2_cells(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t_array(_payload, 21);
}


/** Getter for field safety_plug in message BATTERY_MONITOR
  *
  * @param _payload : a pointer to the BATTERY_MONITOR message
  * @return Safety plug voltage
  */
static inline uint16_t pprzlink_get_DL_BATTERY_MONITOR_safety_plug(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 21);
}


/* Compatibility macros */
#define DL_BATTERY_MONITOR_version(_payload) pprzlink_get_DL_BATTERY_MONITOR_version(_payload)
#define DL_BATTERY_MONITOR_bus_dev_stat(_payload) pprzlink_get_DL_BATTERY_MONITOR_bus_dev_stat(_payload)
#define DL_BATTERY_MONITOR_bus_trans_stat(_payload) pprzlink_get_DL_BATTERY_MONITOR_bus_trans_stat(_payload)
#define DL_BATTERY_MONITOR_current_raw(_payload) pprzlink_get_DL_BATTERY_MONITOR_current_raw(_payload)
#define DL_BATTERY_MONITOR_current(_payload) pprzlink_get_DL_BATTERY_MONITOR_current(_payload)
#define DL_BATTERY_MONITOR_bus_voltage(_payload) pprzlink_get_DL_BATTERY_MONITOR_bus_voltage(_payload)
#define DL_BATTERY_MONITOR_bus_temp_raw_length(_payload) pprzlink_get_BATTERY_MONITOR_bus_temp_raw_length(_payload)
#define DL_BATTERY_MONITOR_bus_temp_raw(_payload) pprzlink_get_DL_BATTERY_MONITOR_bus_temp_raw(_payload)
#define DL_BATTERY_MONITOR_bus_temp_length(_payload) pprzlink_get_BATTERY_MONITOR_bus_temp_length(_payload)
#define DL_BATTERY_MONITOR_bus_temp(_payload) pprzlink_get_DL_BATTERY_MONITOR_bus_temp(_payload)
#define DL_BATTERY_MONITOR_bal1_trans_stat(_payload) pprzlink_get_DL_BATTERY_MONITOR_bal1_trans_stat(_payload)
#define DL_BATTERY_MONITOR_bal1_cells_length(_payload) pprzlink_get_BATTERY_MONITOR_bal1_cells_length(_payload)
#define DL_BATTERY_MONITOR_bal1_cells(_payload) pprzlink_get_DL_BATTERY_MONITOR_bal1_cells(_payload)
#define DL_BATTERY_MONITOR_bal2_trans_stat(_payload) pprzlink_get_DL_BATTERY_MONITOR_bal2_trans_stat(_payload)
#define DL_BATTERY_MONITOR_bal2_cells_length(_payload) pprzlink_get_BATTERY_MONITOR_bal2_cells_length(_payload)
#define DL_BATTERY_MONITOR_bal2_cells(_payload) pprzlink_get_DL_BATTERY_MONITOR_bal2_cells(_payload)
#define DL_BATTERY_MONITOR_safety_plug(_payload) pprzlink_get_DL_BATTERY_MONITOR_safety_plug(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_BATTERY_MONITOR_H_

