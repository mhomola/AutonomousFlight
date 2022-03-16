/** @file
 *  @brief PPRZLink message header for UBLOX_INFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_UBLOX_INFO_H_
#define _VAR_MESSAGES_telemetry_UBLOX_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_UBLOX_INFO 74
#define PPRZ_MSG_ID_UBLOX_INFO 74

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_UBLOX_INFO _send_msg(UBLOX_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a UBLOX_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _baud 
 * @param _ver_sw_h 
 * @param _ver_sw_l 
 * @param _ver_hw_h 
 * @param _ver_hw_l 
 * @param _sbas 
 * @param _gnss 
 */
static inline void pprzlink_msg_v2_send_UBLOX_INFO(struct pprzlink_msg * msg, uint32_t *_baud, uint8_t *_ver_sw_h, uint8_t *_ver_sw_l, uint16_t *_ver_hw_h, uint16_t *_ver_hw_l, uint8_t *_sbas, uint8_t *_gnss) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+1+2+2+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+1+2+2+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_UBLOX_INFO, "UBLOX_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _baud, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ver_sw_h, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ver_sw_l, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ver_hw_h, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ver_hw_l, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _sbas, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gnss, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_UBLOX_INFO pprz_msg_send_UBLOX_INFO
#define DOWNLINK_SEND_UBLOX_INFO(_trans, _dev, baud, ver_sw_h, ver_sw_l, ver_hw_h, ver_hw_l, sbas, gnss) pprz_msg_send_UBLOX_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, baud, ver_sw_h, ver_sw_l, ver_hw_h, ver_hw_l, sbas, gnss)
/**
 * Sends a UBLOX_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _baud 
 * @param _ver_sw_h 
 * @param _ver_sw_l 
 * @param _ver_hw_h 
 * @param _ver_hw_l 
 * @param _sbas 
 * @param _gnss 
 */
static inline void pprz_msg_send_UBLOX_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_baud, uint8_t *_ver_sw_h, uint8_t *_ver_sw_l, uint16_t *_ver_hw_h, uint16_t *_ver_hw_l, uint8_t *_sbas, uint8_t *_gnss) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_UBLOX_INFO(&msg,_baud,_ver_sw_h,_ver_sw_l,_ver_hw_h,_ver_hw_l,_sbas,_gnss);
}


#else // DOWNLINK

#define DOWNLINK_SEND_UBLOX_INFO(_trans, _dev, baud, ver_sw_h, ver_sw_l, ver_hw_h, ver_hw_l, sbas, gnss) {}
static inline void pprz_send_msg_UBLOX_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_baud __attribute__((unused)), uint8_t *_ver_sw_h __attribute__((unused)), uint8_t *_ver_sw_l __attribute__((unused)), uint16_t *_ver_hw_h __attribute__((unused)), uint16_t *_ver_hw_l __attribute__((unused)), uint8_t *_sbas __attribute__((unused)), uint8_t *_gnss __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field baud in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_UBLOX_INFO_baud(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field ver_sw_h in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_UBLOX_INFO_ver_sw_h(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field ver_sw_l in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_UBLOX_INFO_ver_sw_l(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 9);
}


/** Getter for field ver_hw_h in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_UBLOX_INFO_ver_hw_h(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field ver_hw_l in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_UBLOX_INFO_ver_hw_l(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field sbas in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_UBLOX_INFO_sbas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 14);
}


/** Getter for field gnss in message UBLOX_INFO
  *
  * @param _payload : a pointer to the UBLOX_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_UBLOX_INFO_gnss(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 15);
}


/* Compatibility macros */
#define DL_UBLOX_INFO_baud(_payload) pprzlink_get_DL_UBLOX_INFO_baud(_payload)
#define DL_UBLOX_INFO_ver_sw_h(_payload) pprzlink_get_DL_UBLOX_INFO_ver_sw_h(_payload)
#define DL_UBLOX_INFO_ver_sw_l(_payload) pprzlink_get_DL_UBLOX_INFO_ver_sw_l(_payload)
#define DL_UBLOX_INFO_ver_hw_h(_payload) pprzlink_get_DL_UBLOX_INFO_ver_hw_h(_payload)
#define DL_UBLOX_INFO_ver_hw_l(_payload) pprzlink_get_DL_UBLOX_INFO_ver_hw_l(_payload)
#define DL_UBLOX_INFO_sbas(_payload) pprzlink_get_DL_UBLOX_INFO_sbas(_payload)
#define DL_UBLOX_INFO_gnss(_payload) pprzlink_get_DL_UBLOX_INFO_gnss(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_UBLOX_INFO_H_

