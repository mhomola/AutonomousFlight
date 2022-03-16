/** @file
 *  @brief PPRZLink message header for GPS_SOL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_SOL_H_
#define _VAR_MESSAGES_telemetry_GPS_SOL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_SOL 17
#define PPRZ_MSG_ID_GPS_SOL 17

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_SOL _send_msg(GPS_SOL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_SOL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _Pacc 
 * @param _Sacc 
 * @param _PDOP 
 * @param _numSV 
 */
static inline void pprzlink_msg_v2_send_GPS_SOL(struct pprzlink_msg * msg, uint32_t *_Pacc, uint32_t *_Sacc, uint16_t *_PDOP, uint8_t *_numSV) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_SOL, "GPS_SOL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Pacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Sacc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _PDOP, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _numSV, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_SOL pprz_msg_send_GPS_SOL
#define DOWNLINK_SEND_GPS_SOL(_trans, _dev, Pacc, Sacc, PDOP, numSV) pprz_msg_send_GPS_SOL(&((_trans).trans_tx), &((_dev).device), AC_ID, Pacc, Sacc, PDOP, numSV)
/**
 * Sends a GPS_SOL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _Pacc 
 * @param _Sacc 
 * @param _PDOP 
 * @param _numSV 
 */
static inline void pprz_msg_send_GPS_SOL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_Pacc, uint32_t *_Sacc, uint16_t *_PDOP, uint8_t *_numSV) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_SOL(&msg,_Pacc,_Sacc,_PDOP,_numSV);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_SOL(_trans, _dev, Pacc, Sacc, PDOP, numSV) {}
static inline void pprz_send_msg_GPS_SOL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_Pacc __attribute__((unused)), uint32_t *_Sacc __attribute__((unused)), uint16_t *_PDOP __attribute__((unused)), uint8_t *_numSV __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field Pacc in message GPS_SOL
  *
  * @param _payload : a pointer to the GPS_SOL message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_SOL_Pacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field Sacc in message GPS_SOL
  *
  * @param _payload : a pointer to the GPS_SOL message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_SOL_Sacc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field PDOP in message GPS_SOL
  *
  * @param _payload : a pointer to the GPS_SOL message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GPS_SOL_PDOP(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field numSV in message GPS_SOL
  *
  * @param _payload : a pointer to the GPS_SOL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_SOL_numSV(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 14);
}


/* Compatibility macros */
#define DL_GPS_SOL_Pacc(_payload) pprzlink_get_DL_GPS_SOL_Pacc(_payload)
#define DL_GPS_SOL_Sacc(_payload) pprzlink_get_DL_GPS_SOL_Sacc(_payload)
#define DL_GPS_SOL_PDOP(_payload) pprzlink_get_DL_GPS_SOL_PDOP(_payload)
#define DL_GPS_SOL_numSV(_payload) pprzlink_get_DL_GPS_SOL_numSV(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_SOL_H_

