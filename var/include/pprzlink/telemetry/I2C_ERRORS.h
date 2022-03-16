/** @file
 *  @brief PPRZLink message header for I2C_ERRORS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_I2C_ERRORS_H_
#define _VAR_MESSAGES_telemetry_I2C_ERRORS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_I2C_ERRORS 253
#define PPRZ_MSG_ID_I2C_ERRORS 253

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_I2C_ERRORS _send_msg(I2C_ERRORS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a I2C_ERRORS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _wd_reset_cnt 
 * @param _queue_full_cnt 
 * @param _acknowledge_failure_cnt 
 * @param _misplaced_start_or_stop_cnt 
 * @param _arbitration_lost_cnt 
 * @param _overrun_or_underrun_cnt 
 * @param _pec_error_in_reception_cnt 
 * @param _timeout_or_tlow_error_cnt 
 * @param _smbus_alert_cnt 
 * @param _unexpected_event_cnt 
 * @param _last_unexpected_event 
 * @param _bus_number 
 */
static inline void pprzlink_msg_v2_send_I2C_ERRORS(struct pprzlink_msg * msg, uint16_t *_wd_reset_cnt, uint16_t *_queue_full_cnt, uint16_t *_acknowledge_failure_cnt, uint16_t *_misplaced_start_or_stop_cnt, uint16_t *_arbitration_lost_cnt, uint16_t *_overrun_or_underrun_cnt, uint16_t *_pec_error_in_reception_cnt, uint16_t *_timeout_or_tlow_error_cnt, uint16_t *_smbus_alert_cnt, uint16_t *_unexpected_event_cnt, uint32_t *_last_unexpected_event, uint8_t *_bus_number) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_I2C_ERRORS, "I2C_ERRORS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _wd_reset_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _queue_full_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _acknowledge_failure_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _misplaced_start_or_stop_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _arbitration_lost_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _overrun_or_underrun_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _pec_error_in_reception_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _timeout_or_tlow_error_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _smbus_alert_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _unexpected_event_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _last_unexpected_event, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bus_number, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_I2C_ERRORS pprz_msg_send_I2C_ERRORS
#define DOWNLINK_SEND_I2C_ERRORS(_trans, _dev, wd_reset_cnt, queue_full_cnt, acknowledge_failure_cnt, misplaced_start_or_stop_cnt, arbitration_lost_cnt, overrun_or_underrun_cnt, pec_error_in_reception_cnt, timeout_or_tlow_error_cnt, smbus_alert_cnt, unexpected_event_cnt, last_unexpected_event, bus_number) pprz_msg_send_I2C_ERRORS(&((_trans).trans_tx), &((_dev).device), AC_ID, wd_reset_cnt, queue_full_cnt, acknowledge_failure_cnt, misplaced_start_or_stop_cnt, arbitration_lost_cnt, overrun_or_underrun_cnt, pec_error_in_reception_cnt, timeout_or_tlow_error_cnt, smbus_alert_cnt, unexpected_event_cnt, last_unexpected_event, bus_number)
/**
 * Sends a I2C_ERRORS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _wd_reset_cnt 
 * @param _queue_full_cnt 
 * @param _acknowledge_failure_cnt 
 * @param _misplaced_start_or_stop_cnt 
 * @param _arbitration_lost_cnt 
 * @param _overrun_or_underrun_cnt 
 * @param _pec_error_in_reception_cnt 
 * @param _timeout_or_tlow_error_cnt 
 * @param _smbus_alert_cnt 
 * @param _unexpected_event_cnt 
 * @param _last_unexpected_event 
 * @param _bus_number 
 */
static inline void pprz_msg_send_I2C_ERRORS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_wd_reset_cnt, uint16_t *_queue_full_cnt, uint16_t *_acknowledge_failure_cnt, uint16_t *_misplaced_start_or_stop_cnt, uint16_t *_arbitration_lost_cnt, uint16_t *_overrun_or_underrun_cnt, uint16_t *_pec_error_in_reception_cnt, uint16_t *_timeout_or_tlow_error_cnt, uint16_t *_smbus_alert_cnt, uint16_t *_unexpected_event_cnt, uint32_t *_last_unexpected_event, uint8_t *_bus_number) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_I2C_ERRORS(&msg,_wd_reset_cnt,_queue_full_cnt,_acknowledge_failure_cnt,_misplaced_start_or_stop_cnt,_arbitration_lost_cnt,_overrun_or_underrun_cnt,_pec_error_in_reception_cnt,_timeout_or_tlow_error_cnt,_smbus_alert_cnt,_unexpected_event_cnt,_last_unexpected_event,_bus_number);
}


#else // DOWNLINK

#define DOWNLINK_SEND_I2C_ERRORS(_trans, _dev, wd_reset_cnt, queue_full_cnt, acknowledge_failure_cnt, misplaced_start_or_stop_cnt, arbitration_lost_cnt, overrun_or_underrun_cnt, pec_error_in_reception_cnt, timeout_or_tlow_error_cnt, smbus_alert_cnt, unexpected_event_cnt, last_unexpected_event, bus_number) {}
static inline void pprz_send_msg_I2C_ERRORS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_wd_reset_cnt __attribute__((unused)), uint16_t *_queue_full_cnt __attribute__((unused)), uint16_t *_acknowledge_failure_cnt __attribute__((unused)), uint16_t *_misplaced_start_or_stop_cnt __attribute__((unused)), uint16_t *_arbitration_lost_cnt __attribute__((unused)), uint16_t *_overrun_or_underrun_cnt __attribute__((unused)), uint16_t *_pec_error_in_reception_cnt __attribute__((unused)), uint16_t *_timeout_or_tlow_error_cnt __attribute__((unused)), uint16_t *_smbus_alert_cnt __attribute__((unused)), uint16_t *_unexpected_event_cnt __attribute__((unused)), uint32_t *_last_unexpected_event __attribute__((unused)), uint8_t *_bus_number __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field wd_reset_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_wd_reset_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field queue_full_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_queue_full_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field acknowledge_failure_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_acknowledge_failure_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field misplaced_start_or_stop_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_misplaced_start_or_stop_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field arbitration_lost_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_arbitration_lost_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field overrun_or_underrun_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_overrun_or_underrun_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field pec_error_in_reception_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_pec_error_in_reception_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field timeout_or_tlow_error_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_timeout_or_tlow_error_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/** Getter for field smbus_alert_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_smbus_alert_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 20);
}


/** Getter for field unexpected_event_cnt in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_I2C_ERRORS_unexpected_event_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field last_unexpected_event in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_I2C_ERRORS_last_unexpected_event(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 24);
}


/** Getter for field bus_number in message I2C_ERRORS
  *
  * @param _payload : a pointer to the I2C_ERRORS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_I2C_ERRORS_bus_number(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 28);
}


/* Compatibility macros */
#define DL_I2C_ERRORS_wd_reset_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_wd_reset_cnt(_payload)
#define DL_I2C_ERRORS_queue_full_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_queue_full_cnt(_payload)
#define DL_I2C_ERRORS_acknowledge_failure_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_acknowledge_failure_cnt(_payload)
#define DL_I2C_ERRORS_misplaced_start_or_stop_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_misplaced_start_or_stop_cnt(_payload)
#define DL_I2C_ERRORS_arbitration_lost_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_arbitration_lost_cnt(_payload)
#define DL_I2C_ERRORS_overrun_or_underrun_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_overrun_or_underrun_cnt(_payload)
#define DL_I2C_ERRORS_pec_error_in_reception_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_pec_error_in_reception_cnt(_payload)
#define DL_I2C_ERRORS_timeout_or_tlow_error_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_timeout_or_tlow_error_cnt(_payload)
#define DL_I2C_ERRORS_smbus_alert_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_smbus_alert_cnt(_payload)
#define DL_I2C_ERRORS_unexpected_event_cnt(_payload) pprzlink_get_DL_I2C_ERRORS_unexpected_event_cnt(_payload)
#define DL_I2C_ERRORS_last_unexpected_event(_payload) pprzlink_get_DL_I2C_ERRORS_last_unexpected_event(_payload)
#define DL_I2C_ERRORS_bus_number(_payload) pprzlink_get_DL_I2C_ERRORS_bus_number(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_I2C_ERRORS_H_

