/** @file
 *  @brief PPRZLink message header for TEMP_ADC in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TEMP_ADC_H_
#define _VAR_MESSAGES_telemetry_TEMP_ADC_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TEMP_ADC 148
#define PPRZ_MSG_ID_TEMP_ADC 148

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TEMP_ADC _send_msg(TEMP_ADC,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TEMP_ADC message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _temp1 
 * @param _temp2 
 * @param _temp3 
 */
static inline void pprzlink_msg_v2_send_TEMP_ADC(struct pprzlink_msg * msg, float *_temp1, float *_temp2, float *_temp3) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TEMP_ADC, "TEMP_ADC");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp3, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TEMP_ADC pprz_msg_send_TEMP_ADC
#define DOWNLINK_SEND_TEMP_ADC(_trans, _dev, temp1, temp2, temp3) pprz_msg_send_TEMP_ADC(&((_trans).trans_tx), &((_dev).device), AC_ID, temp1, temp2, temp3)
/**
 * Sends a TEMP_ADC message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _temp1 
 * @param _temp2 
 * @param _temp3 
 */
static inline void pprz_msg_send_TEMP_ADC(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_temp1, float *_temp2, float *_temp3) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TEMP_ADC(&msg,_temp1,_temp2,_temp3);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TEMP_ADC(_trans, _dev, temp1, temp2, temp3) {}
static inline void pprz_send_msg_TEMP_ADC(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_temp1 __attribute__((unused)), float *_temp2 __attribute__((unused)), float *_temp3 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field temp1 in message TEMP_ADC
  *
  * @param _payload : a pointer to the TEMP_ADC message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_ADC_temp1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field temp2 in message TEMP_ADC
  *
  * @param _payload : a pointer to the TEMP_ADC message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_ADC_temp2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field temp3 in message TEMP_ADC
  *
  * @param _payload : a pointer to the TEMP_ADC message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_ADC_temp3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_TEMP_ADC_temp1(_payload) pprzlink_get_DL_TEMP_ADC_temp1(_payload)
#define DL_TEMP_ADC_temp2(_payload) pprzlink_get_DL_TEMP_ADC_temp2(_payload)
#define DL_TEMP_ADC_temp3(_payload) pprzlink_get_DL_TEMP_ADC_temp3(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TEMP_ADC_H_

