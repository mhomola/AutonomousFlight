/** @file
 *  @brief PPRZLink message header for AMSYS_BARO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AMSYS_BARO_H_
#define _VAR_MESSAGES_telemetry_AMSYS_BARO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AMSYS_BARO 65
#define PPRZ_MSG_ID_AMSYS_BARO 65

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AMSYS_BARO _send_msg(AMSYS_BARO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AMSYS_BARO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pBaroRaw 
 * @param _pBaro  
 * @param _pHomePressure 
 * @param _AltOffset 
 * @param _aktuell 
 * @param _Over_Ground 
 * @param _tempBaro 
 */
static inline void pprzlink_msg_v2_send_AMSYS_BARO(struct pprzlink_msg * msg, uint16_t *_pBaroRaw, float *_pBaro, float *_pHomePressure, float *_AltOffset, float *_aktuell, float *_Over_Ground, float *_tempBaro) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AMSYS_BARO, "AMSYS_BARO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _pBaroRaw, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pBaro, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pHomePressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _AltOffset, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _aktuell, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Over_Ground, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _tempBaro, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AMSYS_BARO pprz_msg_send_AMSYS_BARO
#define DOWNLINK_SEND_AMSYS_BARO(_trans, _dev, pBaroRaw, pBaro, pHomePressure, AltOffset, aktuell, Over_Ground, tempBaro) pprz_msg_send_AMSYS_BARO(&((_trans).trans_tx), &((_dev).device), AC_ID, pBaroRaw, pBaro, pHomePressure, AltOffset, aktuell, Over_Ground, tempBaro)
/**
 * Sends a AMSYS_BARO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pBaroRaw 
 * @param _pBaro  
 * @param _pHomePressure 
 * @param _AltOffset 
 * @param _aktuell 
 * @param _Over_Ground 
 * @param _tempBaro 
 */
static inline void pprz_msg_send_AMSYS_BARO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_pBaroRaw, float *_pBaro, float *_pHomePressure, float *_AltOffset, float *_aktuell, float *_Over_Ground, float *_tempBaro) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AMSYS_BARO(&msg,_pBaroRaw,_pBaro,_pHomePressure,_AltOffset,_aktuell,_Over_Ground,_tempBaro);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AMSYS_BARO(_trans, _dev, pBaroRaw, pBaro, pHomePressure, AltOffset, aktuell, Over_Ground, tempBaro) {}
static inline void pprz_send_msg_AMSYS_BARO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_pBaroRaw __attribute__((unused)), float *_pBaro __attribute__((unused)), float *_pHomePressure __attribute__((unused)), float *_AltOffset __attribute__((unused)), float *_aktuell __attribute__((unused)), float *_Over_Ground __attribute__((unused)), float *_tempBaro __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pBaroRaw in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_AMSYS_BARO_pBaroRaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field pBaro in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return  
  */
static inline float pprzlink_get_DL_AMSYS_BARO_pBaro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field pHomePressure in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_BARO_pHomePressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field AltOffset in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_BARO_AltOffset(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field aktuell in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_BARO_aktuell(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field Over_Ground in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_BARO_Over_Ground(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field tempBaro in message AMSYS_BARO
  *
  * @param _payload : a pointer to the AMSYS_BARO message
  * @return 
  */
static inline float pprzlink_get_DL_AMSYS_BARO_tempBaro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/* Compatibility macros */
#define DL_AMSYS_BARO_pBaroRaw(_payload) pprzlink_get_DL_AMSYS_BARO_pBaroRaw(_payload)
#define DL_AMSYS_BARO_pBaro(_payload) pprzlink_get_DL_AMSYS_BARO_pBaro(_payload)
#define DL_AMSYS_BARO_pHomePressure(_payload) pprzlink_get_DL_AMSYS_BARO_pHomePressure(_payload)
#define DL_AMSYS_BARO_AltOffset(_payload) pprzlink_get_DL_AMSYS_BARO_AltOffset(_payload)
#define DL_AMSYS_BARO_aktuell(_payload) pprzlink_get_DL_AMSYS_BARO_aktuell(_payload)
#define DL_AMSYS_BARO_Over_Ground(_payload) pprzlink_get_DL_AMSYS_BARO_Over_Ground(_payload)
#define DL_AMSYS_BARO_tempBaro(_payload) pprzlink_get_DL_AMSYS_BARO_tempBaro(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AMSYS_BARO_H_

