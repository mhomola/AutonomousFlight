/** @file
 *  @brief PPRZLink message header for GPS_RTK in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_RTK_H_
#define _VAR_MESSAGES_telemetry_GPS_RTK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_RTK 251
#define PPRZ_MSG_ID_GPS_RTK 251

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_RTK _send_msg(GPS_RTK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_RTK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _iTOW 
 * @param _refStationId 
 * @param _relPosN 
 * @param _relPosE 
 * @param _relPosD 
 * @param _relPosHPN 
 * @param _relPosHPE 
 * @param _relPosHPD 
 * @param _accN 
 * @param _accE 
 * @param _accD 
 * @param _carrSoln 
 * @param _relPosValid 
 * @param _diffSoln 
 * @param _gnssFixOK 
 */
static inline void pprzlink_msg_v2_send_GPS_RTK(struct pprzlink_msg * msg, uint32_t *_iTOW, uint16_t *_refStationId, int32_t *_relPosN, int32_t *_relPosE, int32_t *_relPosD, int8_t *_relPosHPN, int8_t *_relPosHPE, int8_t *_relPosHPD, uint32_t *_accN, uint32_t *_accE, uint32_t *_accD, uint8_t *_carrSoln, uint8_t *_relPosValid, uint8_t *_diffSoln, uint8_t *_gnssFixOK) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+2+4+4+4+1+1+1+4+4+4+1+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+2+4+4+4+1+1+1+4+4+4+1+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_RTK, "GPS_RTK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _iTOW, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _refStationId, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _relPosN, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _relPosE, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _relPosD, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _relPosHPN, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _relPosHPE, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _relPosHPD, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _accN, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _accE, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _accD, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _carrSoln, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _relPosValid, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _diffSoln, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gnssFixOK, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_RTK pprz_msg_send_GPS_RTK
#define DOWNLINK_SEND_GPS_RTK(_trans, _dev, iTOW, refStationId, relPosN, relPosE, relPosD, relPosHPN, relPosHPE, relPosHPD, accN, accE, accD, carrSoln, relPosValid, diffSoln, gnssFixOK) pprz_msg_send_GPS_RTK(&((_trans).trans_tx), &((_dev).device), AC_ID, iTOW, refStationId, relPosN, relPosE, relPosD, relPosHPN, relPosHPE, relPosHPD, accN, accE, accD, carrSoln, relPosValid, diffSoln, gnssFixOK)
/**
 * Sends a GPS_RTK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _iTOW 
 * @param _refStationId 
 * @param _relPosN 
 * @param _relPosE 
 * @param _relPosD 
 * @param _relPosHPN 
 * @param _relPosHPE 
 * @param _relPosHPD 
 * @param _accN 
 * @param _accE 
 * @param _accD 
 * @param _carrSoln 
 * @param _relPosValid 
 * @param _diffSoln 
 * @param _gnssFixOK 
 */
static inline void pprz_msg_send_GPS_RTK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_iTOW, uint16_t *_refStationId, int32_t *_relPosN, int32_t *_relPosE, int32_t *_relPosD, int8_t *_relPosHPN, int8_t *_relPosHPE, int8_t *_relPosHPD, uint32_t *_accN, uint32_t *_accE, uint32_t *_accD, uint8_t *_carrSoln, uint8_t *_relPosValid, uint8_t *_diffSoln, uint8_t *_gnssFixOK) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_RTK(&msg,_iTOW,_refStationId,_relPosN,_relPosE,_relPosD,_relPosHPN,_relPosHPE,_relPosHPD,_accN,_accE,_accD,_carrSoln,_relPosValid,_diffSoln,_gnssFixOK);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_RTK(_trans, _dev, iTOW, refStationId, relPosN, relPosE, relPosD, relPosHPN, relPosHPE, relPosHPD, accN, accE, accD, carrSoln, relPosValid, diffSoln, gnssFixOK) {}
static inline void pprz_send_msg_GPS_RTK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_iTOW __attribute__((unused)), uint16_t *_refStationId __attribute__((unused)), int32_t *_relPosN __attribute__((unused)), int32_t *_relPosE __attribute__((unused)), int32_t *_relPosD __attribute__((unused)), int8_t *_relPosHPN __attribute__((unused)), int8_t *_relPosHPE __attribute__((unused)), int8_t *_relPosHPD __attribute__((unused)), uint32_t *_accN __attribute__((unused)), uint32_t *_accE __attribute__((unused)), uint32_t *_accD __attribute__((unused)), uint8_t *_carrSoln __attribute__((unused)), uint8_t *_relPosValid __attribute__((unused)), uint8_t *_diffSoln __attribute__((unused)), uint8_t *_gnssFixOK __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field iTOW in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RTK_iTOW(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field refStationId in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GPS_RTK_refStationId(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field relPosN in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_RTK_relPosN(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field relPosE in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_RTK_relPosE(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field relPosD in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GPS_RTK_relPosD(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field relPosHPN in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_GPS_RTK_relPosHPN(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 22);
}


/** Getter for field relPosHPE in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_GPS_RTK_relPosHPE(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 23);
}


/** Getter for field relPosHPD in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_GPS_RTK_relPosHPD(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 24);
}


/** Getter for field accN in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RTK_accN(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 25);
}


/** Getter for field accE in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RTK_accE(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 29);
}


/** Getter for field accD in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RTK_accD(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 33);
}


/** Getter for field carrSoln in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_RTK_carrSoln(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 37);
}


/** Getter for field relPosValid in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_RTK_relPosValid(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 38);
}


/** Getter for field diffSoln in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_RTK_diffSoln(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 39);
}


/** Getter for field gnssFixOK in message GPS_RTK
  *
  * @param _payload : a pointer to the GPS_RTK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_RTK_gnssFixOK(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 40);
}


/* Compatibility macros */
#define DL_GPS_RTK_iTOW(_payload) pprzlink_get_DL_GPS_RTK_iTOW(_payload)
#define DL_GPS_RTK_refStationId(_payload) pprzlink_get_DL_GPS_RTK_refStationId(_payload)
#define DL_GPS_RTK_relPosN(_payload) pprzlink_get_DL_GPS_RTK_relPosN(_payload)
#define DL_GPS_RTK_relPosE(_payload) pprzlink_get_DL_GPS_RTK_relPosE(_payload)
#define DL_GPS_RTK_relPosD(_payload) pprzlink_get_DL_GPS_RTK_relPosD(_payload)
#define DL_GPS_RTK_relPosHPN(_payload) pprzlink_get_DL_GPS_RTK_relPosHPN(_payload)
#define DL_GPS_RTK_relPosHPE(_payload) pprzlink_get_DL_GPS_RTK_relPosHPE(_payload)
#define DL_GPS_RTK_relPosHPD(_payload) pprzlink_get_DL_GPS_RTK_relPosHPD(_payload)
#define DL_GPS_RTK_accN(_payload) pprzlink_get_DL_GPS_RTK_accN(_payload)
#define DL_GPS_RTK_accE(_payload) pprzlink_get_DL_GPS_RTK_accE(_payload)
#define DL_GPS_RTK_accD(_payload) pprzlink_get_DL_GPS_RTK_accD(_payload)
#define DL_GPS_RTK_carrSoln(_payload) pprzlink_get_DL_GPS_RTK_carrSoln(_payload)
#define DL_GPS_RTK_relPosValid(_payload) pprzlink_get_DL_GPS_RTK_relPosValid(_payload)
#define DL_GPS_RTK_diffSoln(_payload) pprzlink_get_DL_GPS_RTK_diffSoln(_payload)
#define DL_GPS_RTK_gnssFixOK(_payload) pprzlink_get_DL_GPS_RTK_gnssFixOK(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_RTK_H_

