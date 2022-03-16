/** @file
 *  @brief PPRZLink message header for AIRSPEED_ETS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AIRSPEED_ETS_H_
#define _VAR_MESSAGES_telemetry_AIRSPEED_ETS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AIRSPEED_ETS 57
#define PPRZ_MSG_ID_AIRSPEED_ETS 57

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AIRSPEED_ETS _send_msg(AIRSPEED_ETS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AIRSPEED_ETS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _adc 
 * @param _offset 
 * @param _scaled 
 */
static inline void pprzlink_msg_v2_send_AIRSPEED_ETS(struct pprzlink_msg * msg, uint16_t *_adc, uint16_t *_offset, float *_scaled) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AIRSPEED_ETS, "AIRSPEED_ETS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _adc, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _offset, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _scaled, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AIRSPEED_ETS pprz_msg_send_AIRSPEED_ETS
#define DOWNLINK_SEND_AIRSPEED_ETS(_trans, _dev, adc, offset, scaled) pprz_msg_send_AIRSPEED_ETS(&((_trans).trans_tx), &((_dev).device), AC_ID, adc, offset, scaled)
/**
 * Sends a AIRSPEED_ETS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _adc 
 * @param _offset 
 * @param _scaled 
 */
static inline void pprz_msg_send_AIRSPEED_ETS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_adc, uint16_t *_offset, float *_scaled) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AIRSPEED_ETS(&msg,_adc,_offset,_scaled);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AIRSPEED_ETS(_trans, _dev, adc, offset, scaled) {}
static inline void pprz_send_msg_AIRSPEED_ETS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_adc __attribute__((unused)), uint16_t *_offset __attribute__((unused)), float *_scaled __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field adc in message AIRSPEED_ETS
  *
  * @param _payload : a pointer to the AIRSPEED_ETS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_AIRSPEED_ETS_adc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field offset in message AIRSPEED_ETS
  *
  * @param _payload : a pointer to the AIRSPEED_ETS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_AIRSPEED_ETS_offset(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field scaled in message AIRSPEED_ETS
  *
  * @param _payload : a pointer to the AIRSPEED_ETS message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_ETS_scaled(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/* Compatibility macros */
#define DL_AIRSPEED_ETS_adc(_payload) pprzlink_get_DL_AIRSPEED_ETS_adc(_payload)
#define DL_AIRSPEED_ETS_offset(_payload) pprzlink_get_DL_AIRSPEED_ETS_offset(_payload)
#define DL_AIRSPEED_ETS_scaled(_payload) pprzlink_get_DL_AIRSPEED_ETS_scaled(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AIRSPEED_ETS_H_

