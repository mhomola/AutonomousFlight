/** @file
 *  @brief PPRZLink message header for UART_ERRORS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_UART_ERRORS_H_
#define _VAR_MESSAGES_telemetry_UART_ERRORS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_UART_ERRORS 208
#define PPRZ_MSG_ID_UART_ERRORS 208

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_UART_ERRORS _send_msg(UART_ERRORS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a UART_ERRORS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _overrun_cnt 
 * @param _noise_err_cnt 
 * @param _framing_err_cnt 
 * @param _bus_number 
 */
static inline void pprzlink_msg_v2_send_UART_ERRORS(struct pprzlink_msg * msg, uint16_t *_overrun_cnt, uint16_t *_noise_err_cnt, uint16_t *_framing_err_cnt, uint8_t *_bus_number) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_UART_ERRORS, "UART_ERRORS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _overrun_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _noise_err_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _framing_err_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _bus_number, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_UART_ERRORS pprz_msg_send_UART_ERRORS
#define DOWNLINK_SEND_UART_ERRORS(_trans, _dev, overrun_cnt, noise_err_cnt, framing_err_cnt, bus_number) pprz_msg_send_UART_ERRORS(&((_trans).trans_tx), &((_dev).device), AC_ID, overrun_cnt, noise_err_cnt, framing_err_cnt, bus_number)
/**
 * Sends a UART_ERRORS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _overrun_cnt 
 * @param _noise_err_cnt 
 * @param _framing_err_cnt 
 * @param _bus_number 
 */
static inline void pprz_msg_send_UART_ERRORS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_overrun_cnt, uint16_t *_noise_err_cnt, uint16_t *_framing_err_cnt, uint8_t *_bus_number) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_UART_ERRORS(&msg,_overrun_cnt,_noise_err_cnt,_framing_err_cnt,_bus_number);
}


#else // DOWNLINK

#define DOWNLINK_SEND_UART_ERRORS(_trans, _dev, overrun_cnt, noise_err_cnt, framing_err_cnt, bus_number) {}
static inline void pprz_send_msg_UART_ERRORS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_overrun_cnt __attribute__((unused)), uint16_t *_noise_err_cnt __attribute__((unused)), uint16_t *_framing_err_cnt __attribute__((unused)), uint8_t *_bus_number __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field overrun_cnt in message UART_ERRORS
  *
  * @param _payload : a pointer to the UART_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_UART_ERRORS_overrun_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field noise_err_cnt in message UART_ERRORS
  *
  * @param _payload : a pointer to the UART_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_UART_ERRORS_noise_err_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field framing_err_cnt in message UART_ERRORS
  *
  * @param _payload : a pointer to the UART_ERRORS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_UART_ERRORS_framing_err_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field bus_number in message UART_ERRORS
  *
  * @param _payload : a pointer to the UART_ERRORS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_UART_ERRORS_bus_number(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 10);
}


/* Compatibility macros */
#define DL_UART_ERRORS_overrun_cnt(_payload) pprzlink_get_DL_UART_ERRORS_overrun_cnt(_payload)
#define DL_UART_ERRORS_noise_err_cnt(_payload) pprzlink_get_DL_UART_ERRORS_noise_err_cnt(_payload)
#define DL_UART_ERRORS_framing_err_cnt(_payload) pprzlink_get_DL_UART_ERRORS_framing_err_cnt(_payload)
#define DL_UART_ERRORS_bus_number(_payload) pprzlink_get_DL_UART_ERRORS_bus_number(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_UART_ERRORS_H_

