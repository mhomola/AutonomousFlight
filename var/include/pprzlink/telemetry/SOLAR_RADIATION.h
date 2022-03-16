/** @file
 *  @brief PPRZLink message header for SOLAR_RADIATION in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SOLAR_RADIATION_H_
#define _VAR_MESSAGES_telemetry_SOLAR_RADIATION_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SOLAR_RADIATION 119
#define PPRZ_MSG_ID_SOLAR_RADIATION 119

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SOLAR_RADIATION _send_msg(SOLAR_RADIATION,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SOLAR_RADIATION message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _up_t0 
 * @param _dn_t0 
 * @param _up_t1 
 * @param _dn_t1 
 * @param _up_t2 
 * @param _dn_t2 
 * @param _up_t3 
 * @param _dn_t3 
 * @param _up_t4 
 * @param _dn_t4 
 * @param _up_t5 
 * @param _dn_t5 
 * @param _up_t6 
 * @param _dn_t6 
 * @param _up_t7 
 * @param _dn_t7 
 * @param _up_t8 
 * @param _dn_t8 
 * @param _up_t9 
 * @param _dn_t9 
 */
static inline void pprzlink_msg_v2_send_SOLAR_RADIATION(struct pprzlink_msg * msg, uint16_t *_up_t0, uint16_t *_dn_t0, uint16_t *_up_t1, uint16_t *_dn_t1, uint16_t *_up_t2, uint16_t *_dn_t2, uint16_t *_up_t3, uint16_t *_dn_t3, uint16_t *_up_t4, uint16_t *_dn_t4, uint16_t *_up_t5, uint16_t *_dn_t5, uint16_t *_up_t6, uint16_t *_dn_t6, uint16_t *_up_t7, uint16_t *_dn_t7, uint16_t *_up_t8, uint16_t *_dn_t8, uint16_t *_up_t9, uint16_t *_dn_t9) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SOLAR_RADIATION, "SOLAR_RADIATION");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t4, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t4, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t5, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t5, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t6, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t6, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t7, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t7, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t8, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t8, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _up_t9, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _dn_t9, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SOLAR_RADIATION pprz_msg_send_SOLAR_RADIATION
#define DOWNLINK_SEND_SOLAR_RADIATION(_trans, _dev, up_t0, dn_t0, up_t1, dn_t1, up_t2, dn_t2, up_t3, dn_t3, up_t4, dn_t4, up_t5, dn_t5, up_t6, dn_t6, up_t7, dn_t7, up_t8, dn_t8, up_t9, dn_t9) pprz_msg_send_SOLAR_RADIATION(&((_trans).trans_tx), &((_dev).device), AC_ID, up_t0, dn_t0, up_t1, dn_t1, up_t2, dn_t2, up_t3, dn_t3, up_t4, dn_t4, up_t5, dn_t5, up_t6, dn_t6, up_t7, dn_t7, up_t8, dn_t8, up_t9, dn_t9)
/**
 * Sends a SOLAR_RADIATION message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _up_t0 
 * @param _dn_t0 
 * @param _up_t1 
 * @param _dn_t1 
 * @param _up_t2 
 * @param _dn_t2 
 * @param _up_t3 
 * @param _dn_t3 
 * @param _up_t4 
 * @param _dn_t4 
 * @param _up_t5 
 * @param _dn_t5 
 * @param _up_t6 
 * @param _dn_t6 
 * @param _up_t7 
 * @param _dn_t7 
 * @param _up_t8 
 * @param _dn_t8 
 * @param _up_t9 
 * @param _dn_t9 
 */
static inline void pprz_msg_send_SOLAR_RADIATION(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_up_t0, uint16_t *_dn_t0, uint16_t *_up_t1, uint16_t *_dn_t1, uint16_t *_up_t2, uint16_t *_dn_t2, uint16_t *_up_t3, uint16_t *_dn_t3, uint16_t *_up_t4, uint16_t *_dn_t4, uint16_t *_up_t5, uint16_t *_dn_t5, uint16_t *_up_t6, uint16_t *_dn_t6, uint16_t *_up_t7, uint16_t *_dn_t7, uint16_t *_up_t8, uint16_t *_dn_t8, uint16_t *_up_t9, uint16_t *_dn_t9) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SOLAR_RADIATION(&msg,_up_t0,_dn_t0,_up_t1,_dn_t1,_up_t2,_dn_t2,_up_t3,_dn_t3,_up_t4,_dn_t4,_up_t5,_dn_t5,_up_t6,_dn_t6,_up_t7,_dn_t7,_up_t8,_dn_t8,_up_t9,_dn_t9);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SOLAR_RADIATION(_trans, _dev, up_t0, dn_t0, up_t1, dn_t1, up_t2, dn_t2, up_t3, dn_t3, up_t4, dn_t4, up_t5, dn_t5, up_t6, dn_t6, up_t7, dn_t7, up_t8, dn_t8, up_t9, dn_t9) {}
static inline void pprz_send_msg_SOLAR_RADIATION(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_up_t0 __attribute__((unused)), uint16_t *_dn_t0 __attribute__((unused)), uint16_t *_up_t1 __attribute__((unused)), uint16_t *_dn_t1 __attribute__((unused)), uint16_t *_up_t2 __attribute__((unused)), uint16_t *_dn_t2 __attribute__((unused)), uint16_t *_up_t3 __attribute__((unused)), uint16_t *_dn_t3 __attribute__((unused)), uint16_t *_up_t4 __attribute__((unused)), uint16_t *_dn_t4 __attribute__((unused)), uint16_t *_up_t5 __attribute__((unused)), uint16_t *_dn_t5 __attribute__((unused)), uint16_t *_up_t6 __attribute__((unused)), uint16_t *_dn_t6 __attribute__((unused)), uint16_t *_up_t7 __attribute__((unused)), uint16_t *_dn_t7 __attribute__((unused)), uint16_t *_up_t8 __attribute__((unused)), uint16_t *_dn_t8 __attribute__((unused)), uint16_t *_up_t9 __attribute__((unused)), uint16_t *_dn_t9 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field up_t0 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field dn_t0 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field up_t1 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field dn_t1 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field up_t2 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field dn_t2 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field up_t3 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field dn_t3 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/** Getter for field up_t4 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 20);
}


/** Getter for field dn_t4 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field up_t5 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 24);
}


/** Getter for field dn_t5 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 26);
}


/** Getter for field up_t6 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t6(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 28);
}


/** Getter for field dn_t6 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t6(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 30);
}


/** Getter for field up_t7 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t7(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 32);
}


/** Getter for field dn_t7 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t7(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 34);
}


/** Getter for field up_t8 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t8(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 36);
}


/** Getter for field dn_t8 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t8(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 38);
}


/** Getter for field up_t9 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_up_t9(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 40);
}


/** Getter for field dn_t9 in message SOLAR_RADIATION
  *
  * @param _payload : a pointer to the SOLAR_RADIATION message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SOLAR_RADIATION_dn_t9(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 42);
}


/* Compatibility macros */
#define DL_SOLAR_RADIATION_up_t0(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t0(_payload)
#define DL_SOLAR_RADIATION_dn_t0(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t0(_payload)
#define DL_SOLAR_RADIATION_up_t1(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t1(_payload)
#define DL_SOLAR_RADIATION_dn_t1(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t1(_payload)
#define DL_SOLAR_RADIATION_up_t2(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t2(_payload)
#define DL_SOLAR_RADIATION_dn_t2(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t2(_payload)
#define DL_SOLAR_RADIATION_up_t3(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t3(_payload)
#define DL_SOLAR_RADIATION_dn_t3(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t3(_payload)
#define DL_SOLAR_RADIATION_up_t4(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t4(_payload)
#define DL_SOLAR_RADIATION_dn_t4(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t4(_payload)
#define DL_SOLAR_RADIATION_up_t5(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t5(_payload)
#define DL_SOLAR_RADIATION_dn_t5(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t5(_payload)
#define DL_SOLAR_RADIATION_up_t6(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t6(_payload)
#define DL_SOLAR_RADIATION_dn_t6(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t6(_payload)
#define DL_SOLAR_RADIATION_up_t7(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t7(_payload)
#define DL_SOLAR_RADIATION_dn_t7(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t7(_payload)
#define DL_SOLAR_RADIATION_up_t8(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t8(_payload)
#define DL_SOLAR_RADIATION_dn_t8(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t8(_payload)
#define DL_SOLAR_RADIATION_up_t9(_payload) pprzlink_get_DL_SOLAR_RADIATION_up_t9(_payload)
#define DL_SOLAR_RADIATION_dn_t9(_payload) pprzlink_get_DL_SOLAR_RADIATION_dn_t9(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SOLAR_RADIATION_H_

