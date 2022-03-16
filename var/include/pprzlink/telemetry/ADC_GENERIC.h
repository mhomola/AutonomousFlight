/** @file
 *  @brief PPRZLink message header for ADC_GENERIC in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ADC_GENERIC_H_
#define _VAR_MESSAGES_telemetry_ADC_GENERIC_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ADC_GENERIC 18
#define PPRZ_MSG_ID_ADC_GENERIC 18

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ADC_GENERIC _send_msg(ADC_GENERIC,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ADC_GENERIC message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _val1 
 * @param _val2 
 */
static inline void pprzlink_msg_v2_send_ADC_GENERIC(struct pprzlink_msg * msg, uint16_t *_val1, uint16_t *_val2) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ADC_GENERIC, "ADC_GENERIC");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val2, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ADC_GENERIC pprz_msg_send_ADC_GENERIC
#define DOWNLINK_SEND_ADC_GENERIC(_trans, _dev, val1, val2) pprz_msg_send_ADC_GENERIC(&((_trans).trans_tx), &((_dev).device), AC_ID, val1, val2)
/**
 * Sends a ADC_GENERIC message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _val1 
 * @param _val2 
 */
static inline void pprz_msg_send_ADC_GENERIC(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_val1, uint16_t *_val2) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ADC_GENERIC(&msg,_val1,_val2);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ADC_GENERIC(_trans, _dev, val1, val2) {}
static inline void pprz_send_msg_ADC_GENERIC(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_val1 __attribute__((unused)), uint16_t *_val2 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field val1 in message ADC_GENERIC
  *
  * @param _payload : a pointer to the ADC_GENERIC message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ADC_GENERIC_val1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field val2 in message ADC_GENERIC
  *
  * @param _payload : a pointer to the ADC_GENERIC message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ADC_GENERIC_val2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/* Compatibility macros */
#define DL_ADC_GENERIC_val1(_payload) pprzlink_get_DL_ADC_GENERIC_val1(_payload)
#define DL_ADC_GENERIC_val2(_payload) pprzlink_get_DL_ADC_GENERIC_val2(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ADC_GENERIC_H_

