/** @file
 *  @brief PPRZLink message header for GPS_RXMRTCM in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GPS_RXMRTCM_H_
#define _VAR_MESSAGES_telemetry_GPS_RXMRTCM_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_RXMRTCM 249
#define PPRZ_MSG_ID_GPS_RXMRTCM 249

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_RXMRTCM _send_msg(GPS_RXMRTCM,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_RXMRTCM message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _Msg1005 
 * @param _Msg1077 
 * @param _Msg1087 
 * @param _Crc1005 
 * @param _Crc1077 
 * @param _Crc1087 
 */
static inline void pprzlink_msg_v2_send_GPS_RXMRTCM(struct pprzlink_msg * msg, uint32_t *_Msg1005, uint32_t *_Msg1077, uint32_t *_Msg1087, uint32_t *_Crc1005, uint32_t *_Crc1077, uint32_t *_Crc1087) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_RXMRTCM, "GPS_RXMRTCM");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Msg1005, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Msg1077, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Msg1087, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Crc1005, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Crc1077, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _Crc1087, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_RXMRTCM pprz_msg_send_GPS_RXMRTCM
#define DOWNLINK_SEND_GPS_RXMRTCM(_trans, _dev, Msg1005, Msg1077, Msg1087, Crc1005, Crc1077, Crc1087) pprz_msg_send_GPS_RXMRTCM(&((_trans).trans_tx), &((_dev).device), AC_ID, Msg1005, Msg1077, Msg1087, Crc1005, Crc1077, Crc1087)
/**
 * Sends a GPS_RXMRTCM message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _Msg1005 
 * @param _Msg1077 
 * @param _Msg1087 
 * @param _Crc1005 
 * @param _Crc1077 
 * @param _Crc1087 
 */
static inline void pprz_msg_send_GPS_RXMRTCM(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_Msg1005, uint32_t *_Msg1077, uint32_t *_Msg1087, uint32_t *_Crc1005, uint32_t *_Crc1077, uint32_t *_Crc1087) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_RXMRTCM(&msg,_Msg1005,_Msg1077,_Msg1087,_Crc1005,_Crc1077,_Crc1087);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_RXMRTCM(_trans, _dev, Msg1005, Msg1077, Msg1087, Crc1005, Crc1077, Crc1087) {}
static inline void pprz_send_msg_GPS_RXMRTCM(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_Msg1005 __attribute__((unused)), uint32_t *_Msg1077 __attribute__((unused)), uint32_t *_Msg1087 __attribute__((unused)), uint32_t *_Crc1005 __attribute__((unused)), uint32_t *_Crc1077 __attribute__((unused)), uint32_t *_Crc1087 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field Msg1005 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Msg1005(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field Msg1077 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Msg1077(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field Msg1087 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Msg1087(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 12);
}


/** Getter for field Crc1005 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Crc1005(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 16);
}


/** Getter for field Crc1077 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Crc1077(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 20);
}


/** Getter for field Crc1087 in message GPS_RXMRTCM
  *
  * @param _payload : a pointer to the GPS_RXMRTCM message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GPS_RXMRTCM_Crc1087(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 24);
}


/* Compatibility macros */
#define DL_GPS_RXMRTCM_Msg1005(_payload) pprzlink_get_DL_GPS_RXMRTCM_Msg1005(_payload)
#define DL_GPS_RXMRTCM_Msg1077(_payload) pprzlink_get_DL_GPS_RXMRTCM_Msg1077(_payload)
#define DL_GPS_RXMRTCM_Msg1087(_payload) pprzlink_get_DL_GPS_RXMRTCM_Msg1087(_payload)
#define DL_GPS_RXMRTCM_Crc1005(_payload) pprzlink_get_DL_GPS_RXMRTCM_Crc1005(_payload)
#define DL_GPS_RXMRTCM_Crc1077(_payload) pprzlink_get_DL_GPS_RXMRTCM_Crc1077(_payload)
#define DL_GPS_RXMRTCM_Crc1087(_payload) pprzlink_get_DL_GPS_RXMRTCM_Crc1087(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GPS_RXMRTCM_H_

