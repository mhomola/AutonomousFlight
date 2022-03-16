/** @file
 *  @brief PPRZLink message header for ATMOSPHERE_CHARGE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ATMOSPHERE_CHARGE_H_
#define _VAR_MESSAGES_telemetry_ATMOSPHERE_CHARGE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ATMOSPHERE_CHARGE 118
#define PPRZ_MSG_ID_ATMOSPHERE_CHARGE 118

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ATMOSPHERE_CHARGE _send_msg(ATMOSPHERE_CHARGE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ATMOSPHERE_CHARGE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _t0 
 * @param _t1 
 * @param _t2 
 * @param _t3 
 * @param _t4 
 * @param _t5 
 * @param _t6 
 * @param _t7 
 * @param _t8 
 * @param _t9 
 */
static inline void pprzlink_msg_v2_send_ATMOSPHERE_CHARGE(struct pprzlink_msg * msg, uint16_t *_t0, uint16_t *_t1, uint16_t *_t2, uint16_t *_t3, uint16_t *_t4, uint16_t *_t5, uint16_t *_t6, uint16_t *_t7, uint16_t *_t8, uint16_t *_t9) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ATMOSPHERE_CHARGE, "ATMOSPHERE_CHARGE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t4, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t5, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t6, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t7, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t8, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _t9, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ATMOSPHERE_CHARGE pprz_msg_send_ATMOSPHERE_CHARGE
#define DOWNLINK_SEND_ATMOSPHERE_CHARGE(_trans, _dev, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) pprz_msg_send_ATMOSPHERE_CHARGE(&((_trans).trans_tx), &((_dev).device), AC_ID, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9)
/**
 * Sends a ATMOSPHERE_CHARGE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _t0 
 * @param _t1 
 * @param _t2 
 * @param _t3 
 * @param _t4 
 * @param _t5 
 * @param _t6 
 * @param _t7 
 * @param _t8 
 * @param _t9 
 */
static inline void pprz_msg_send_ATMOSPHERE_CHARGE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_t0, uint16_t *_t1, uint16_t *_t2, uint16_t *_t3, uint16_t *_t4, uint16_t *_t5, uint16_t *_t6, uint16_t *_t7, uint16_t *_t8, uint16_t *_t9) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ATMOSPHERE_CHARGE(&msg,_t0,_t1,_t2,_t3,_t4,_t5,_t6,_t7,_t8,_t9);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ATMOSPHERE_CHARGE(_trans, _dev, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) {}
static inline void pprz_send_msg_ATMOSPHERE_CHARGE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_t0 __attribute__((unused)), uint16_t *_t1 __attribute__((unused)), uint16_t *_t2 __attribute__((unused)), uint16_t *_t3 __attribute__((unused)), uint16_t *_t4 __attribute__((unused)), uint16_t *_t5 __attribute__((unused)), uint16_t *_t6 __attribute__((unused)), uint16_t *_t7 __attribute__((unused)), uint16_t *_t8 __attribute__((unused)), uint16_t *_t9 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field t0 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field t1 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field t2 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field t3 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field t4 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field t5 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field t6 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t6(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field t7 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t7(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/** Getter for field t8 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t8(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 20);
}


/** Getter for field t9 in message ATMOSPHERE_CHARGE
  *
  * @param _payload : a pointer to the ATMOSPHERE_CHARGE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ATMOSPHERE_CHARGE_t9(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/* Compatibility macros */
#define DL_ATMOSPHERE_CHARGE_t0(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t0(_payload)
#define DL_ATMOSPHERE_CHARGE_t1(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t1(_payload)
#define DL_ATMOSPHERE_CHARGE_t2(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t2(_payload)
#define DL_ATMOSPHERE_CHARGE_t3(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t3(_payload)
#define DL_ATMOSPHERE_CHARGE_t4(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t4(_payload)
#define DL_ATMOSPHERE_CHARGE_t5(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t5(_payload)
#define DL_ATMOSPHERE_CHARGE_t6(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t6(_payload)
#define DL_ATMOSPHERE_CHARGE_t7(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t7(_payload)
#define DL_ATMOSPHERE_CHARGE_t8(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t8(_payload)
#define DL_ATMOSPHERE_CHARGE_t9(_payload) pprzlink_get_DL_ATMOSPHERE_CHARGE_t9(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ATMOSPHERE_CHARGE_H_

