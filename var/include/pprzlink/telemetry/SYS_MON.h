/** @file
 *  @brief PPRZLink message header for SYS_MON in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SYS_MON_H_
#define _VAR_MESSAGES_telemetry_SYS_MON_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SYS_MON 33
#define PPRZ_MSG_ID_SYS_MON 33

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SYS_MON _send_msg(SYS_MON,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SYS_MON message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _periodic_time 
 * @param _periodic_time_min 
 * @param _periodic_time_max 
 * @param _periodic_cycle 
 * @param _periodic_cycle_min 
 * @param _periodic_cycle_max 
 * @param _event_number 
 * @param _cpu_load 
 * @param _cpu_time 
 */
static inline void pprzlink_msg_v2_send_SYS_MON(struct pprzlink_msg * msg, uint16_t *_periodic_time, uint16_t *_periodic_time_min, uint16_t *_periodic_time_max, uint16_t *_periodic_cycle, uint16_t *_periodic_cycle_min, uint16_t *_periodic_cycle_max, uint16_t *_event_number, uint8_t *_cpu_load, float *_cpu_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+1+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+1+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SYS_MON, "SYS_MON");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_time_min, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_time_max, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_cycle, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_cycle_min, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _periodic_cycle_max, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _event_number, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cpu_load, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cpu_time, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SYS_MON pprz_msg_send_SYS_MON
#define DOWNLINK_SEND_SYS_MON(_trans, _dev, periodic_time, periodic_time_min, periodic_time_max, periodic_cycle, periodic_cycle_min, periodic_cycle_max, event_number, cpu_load, cpu_time) pprz_msg_send_SYS_MON(&((_trans).trans_tx), &((_dev).device), AC_ID, periodic_time, periodic_time_min, periodic_time_max, periodic_cycle, periodic_cycle_min, periodic_cycle_max, event_number, cpu_load, cpu_time)
/**
 * Sends a SYS_MON message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _periodic_time 
 * @param _periodic_time_min 
 * @param _periodic_time_max 
 * @param _periodic_cycle 
 * @param _periodic_cycle_min 
 * @param _periodic_cycle_max 
 * @param _event_number 
 * @param _cpu_load 
 * @param _cpu_time 
 */
static inline void pprz_msg_send_SYS_MON(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_periodic_time, uint16_t *_periodic_time_min, uint16_t *_periodic_time_max, uint16_t *_periodic_cycle, uint16_t *_periodic_cycle_min, uint16_t *_periodic_cycle_max, uint16_t *_event_number, uint8_t *_cpu_load, float *_cpu_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SYS_MON(&msg,_periodic_time,_periodic_time_min,_periodic_time_max,_periodic_cycle,_periodic_cycle_min,_periodic_cycle_max,_event_number,_cpu_load,_cpu_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SYS_MON(_trans, _dev, periodic_time, periodic_time_min, periodic_time_max, periodic_cycle, periodic_cycle_min, periodic_cycle_max, event_number, cpu_load, cpu_time) {}
static inline void pprz_send_msg_SYS_MON(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_periodic_time __attribute__((unused)), uint16_t *_periodic_time_min __attribute__((unused)), uint16_t *_periodic_time_max __attribute__((unused)), uint16_t *_periodic_cycle __attribute__((unused)), uint16_t *_periodic_cycle_min __attribute__((unused)), uint16_t *_periodic_cycle_max __attribute__((unused)), uint16_t *_event_number __attribute__((unused)), uint8_t *_cpu_load __attribute__((unused)), float *_cpu_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field periodic_time in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field periodic_time_min in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_time_min(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field periodic_time_max in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_time_max(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field periodic_cycle in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_cycle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field periodic_cycle_min in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_cycle_min(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field periodic_cycle_max in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_periodic_cycle_max(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field event_number in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SYS_MON_event_number(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field cpu_load in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SYS_MON_cpu_load(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 18);
}


/** Getter for field cpu_time in message SYS_MON
  *
  * @param _payload : a pointer to the SYS_MON message
  * @return 
  */
static inline float pprzlink_get_DL_SYS_MON_cpu_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 19);
}


/* Compatibility macros */
#define DL_SYS_MON_periodic_time(_payload) pprzlink_get_DL_SYS_MON_periodic_time(_payload)
#define DL_SYS_MON_periodic_time_min(_payload) pprzlink_get_DL_SYS_MON_periodic_time_min(_payload)
#define DL_SYS_MON_periodic_time_max(_payload) pprzlink_get_DL_SYS_MON_periodic_time_max(_payload)
#define DL_SYS_MON_periodic_cycle(_payload) pprzlink_get_DL_SYS_MON_periodic_cycle(_payload)
#define DL_SYS_MON_periodic_cycle_min(_payload) pprzlink_get_DL_SYS_MON_periodic_cycle_min(_payload)
#define DL_SYS_MON_periodic_cycle_max(_payload) pprzlink_get_DL_SYS_MON_periodic_cycle_max(_payload)
#define DL_SYS_MON_event_number(_payload) pprzlink_get_DL_SYS_MON_event_number(_payload)
#define DL_SYS_MON_cpu_load(_payload) pprzlink_get_DL_SYS_MON_cpu_load(_payload)
#define DL_SYS_MON_cpu_time(_payload) pprzlink_get_DL_SYS_MON_cpu_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SYS_MON_H_

