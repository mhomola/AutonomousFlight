/** @file
 *  @brief PPRZLink message header for AIRSPEED_MS45XX in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AIRSPEED_MS45XX_H_
#define _VAR_MESSAGES_telemetry_AIRSPEED_MS45XX_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AIRSPEED_MS45XX 138
#define PPRZ_MSG_ID_AIRSPEED_MS45XX 138

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AIRSPEED_MS45XX _send_msg(AIRSPEED_MS45XX,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AIRSPEED_MS45XX message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _diffPress 
 * @param _temperature 
 * @param _airspeed 
 */
static inline void pprzlink_msg_v2_send_AIRSPEED_MS45XX(struct pprzlink_msg * msg, float *_diffPress, int16_t *_temperature, float *_airspeed) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AIRSPEED_MS45XX, "AIRSPEED_MS45XX");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _diffPress, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _temperature, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _airspeed, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AIRSPEED_MS45XX pprz_msg_send_AIRSPEED_MS45XX
#define DOWNLINK_SEND_AIRSPEED_MS45XX(_trans, _dev, diffPress, temperature, airspeed) pprz_msg_send_AIRSPEED_MS45XX(&((_trans).trans_tx), &((_dev).device), AC_ID, diffPress, temperature, airspeed)
/**
 * Sends a AIRSPEED_MS45XX message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _diffPress 
 * @param _temperature 
 * @param _airspeed 
 */
static inline void pprz_msg_send_AIRSPEED_MS45XX(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_diffPress, int16_t *_temperature, float *_airspeed) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AIRSPEED_MS45XX(&msg,_diffPress,_temperature,_airspeed);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AIRSPEED_MS45XX(_trans, _dev, diffPress, temperature, airspeed) {}
static inline void pprz_send_msg_AIRSPEED_MS45XX(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_diffPress __attribute__((unused)), int16_t *_temperature __attribute__((unused)), float *_airspeed __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field diffPress in message AIRSPEED_MS45XX
  *
  * @param _payload : a pointer to the AIRSPEED_MS45XX message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_MS45XX_diffPress(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field temperature in message AIRSPEED_MS45XX
  *
  * @param _payload : a pointer to the AIRSPEED_MS45XX message
  * @return 
  */
static inline int16_t pprzlink_get_DL_AIRSPEED_MS45XX_temperature(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field airspeed in message AIRSPEED_MS45XX
  *
  * @param _payload : a pointer to the AIRSPEED_MS45XX message
  * @return 
  */
static inline float pprzlink_get_DL_AIRSPEED_MS45XX_airspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/* Compatibility macros */
#define DL_AIRSPEED_MS45XX_diffPress(_payload) pprzlink_get_DL_AIRSPEED_MS45XX_diffPress(_payload)
#define DL_AIRSPEED_MS45XX_temperature(_payload) pprzlink_get_DL_AIRSPEED_MS45XX_temperature(_payload)
#define DL_AIRSPEED_MS45XX_airspeed(_payload) pprzlink_get_DL_AIRSPEED_MS45XX_airspeed(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AIRSPEED_MS45XX_H_

