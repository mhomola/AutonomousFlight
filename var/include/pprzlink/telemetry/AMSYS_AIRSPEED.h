/** @file
 *  @brief PPRZLink message header for AMSYS_AIRSPEED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AMSYS_AIRSPEED_H_
#define _VAR_MESSAGES_telemetry_AMSYS_AIRSPEED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AMSYS_AIRSPEED 66
#define PPRZ_MSG_ID_AMSYS_AIRSPEED 66

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AMSYS_AIRSPEED _send_msg(AMSYS_AIRSPEED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AMSYS_AIRSPEED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _asRaw 
 * @param _asPresure 
 * @param _asAirspeed 
 * @param _asAirsFilt 
 * @param _asTemp 
 */
static inline void pprzlink_msg_v2_send_AMSYS_AIRSPEED(struct pprzlink_msg * msg, uint16_t *_asRaw, float *_asPresure, float *_asAirspeed, float *_asAirsFilt, float *_asTemp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AMSYS_AIRSPEED, "AMSYS_AIRSPEED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _asRaw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _asPresure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _asAirspeed, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _asAirsFilt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _asTemp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AMSYS_AIRSPEED pprz_msg_send_AMSYS_AIRSPEED
#define DOWNLINK_SEND_AMSYS_AIRSPEED(_trans, _dev, asRaw, asPresure, asAirspeed, asAirsFilt, asTemp) pprz_msg_send_AMSYS_AIRSPEED(&((_trans).trans_tx), &((_dev).device), AC_ID, asRaw, asPresure, asAirspeed, asAirsFilt, asTemp)
/**
 * Sends a AMSYS_AIRSPEED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _asRaw 
 * @param _asPresure 
 * @param _asAirspeed 
 * @param _asAirsFilt 
 * @param _asTemp 
 */
static inline void pprz_msg_send_AMSYS_AIRSPEED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_asRaw, float *_asPresure, float *_asAirspeed, float *_asAirsFilt, float *_asTemp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AMSYS_AIRSPEED(&msg,_asRaw,_asPresure,_asAirspeed,_asAirsFilt,_asTemp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AMSYS_AIRSPEED(_trans, _dev, asRaw, asPresure, asAirspeed, asAirsFilt, asTemp) {}
static inline void pprz_send_msg_AMSYS_AIRSPEED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_asRaw __attribute__((unused)), float *_asPresure __attribute__((unused)), float *_asAirspeed __attribute__((unused)), float *_asAirsFilt __attribute__((unused)), float *_asTemp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field asRaw in message AMSYS_AIRSPEED
  *
  * @param _payload : a pointer to the AMSYS_AIRSPEED message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_AMSYS_AIRSPEED_asRaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field asPresure in message AMSYS_AIRSPEED
  *
  * @param _payload : a pointer to the AMSYS_AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_AIRSPEED_asPresure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field asAirspeed in message AMSYS_AIRSPEED
  *
  * @param _payload : a pointer to the AMSYS_AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_AIRSPEED_asAirspeed(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field asAirsFilt in message AMSYS_AIRSPEED
  *
  * @param _payload : a pointer to the AMSYS_AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_AIRSPEED_asAirsFilt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field asTemp in message AMSYS_AIRSPEED
  *
  * @param _payload : a pointer to the AMSYS_AIRSPEED message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_AIRSPEED_asTemp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/* Compatibility macros */
#define DL_AMSYS_AIRSPEED_asRaw(_payload) pprzlink_get_DL_AMSYS_AIRSPEED_asRaw(_payload)
#define DL_AMSYS_AIRSPEED_asPresure(_payload) pprzlink_get_DL_AMSYS_AIRSPEED_asPresure(_payload)
#define DL_AMSYS_AIRSPEED_asAirspeed(_payload) pprzlink_get_DL_AMSYS_AIRSPEED_asAirspeed(_payload)
#define DL_AMSYS_AIRSPEED_asAirsFilt(_payload) pprzlink_get_DL_AMSYS_AIRSPEED_asAirsFilt(_payload)
#define DL_AMSYS_AIRSPEED_asTemp(_payload) pprzlink_get_DL_AMSYS_AIRSPEED_asTemp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AMSYS_AIRSPEED_H_

