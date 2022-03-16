/** @file
 *  @brief PPRZLink message header for INS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_H_
#define _VAR_MESSAGES_telemetry_INS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS 198
#define PPRZ_MSG_ID_INS 198

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS _send_msg(INS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ins_x 
 * @param _ins_y 
 * @param _ins_z 
 * @param _ins_xd 
 * @param _ins_yd 
 * @param _ins_zd 
 * @param _ins_xdd 
 * @param _ins_ydd 
 * @param _ins_zdd 
 */
static inline void pprzlink_msg_v2_send_INS(struct pprzlink_msg * msg, int32_t *_ins_x, int32_t *_ins_y, int32_t *_ins_z, int32_t *_ins_xd, int32_t *_ins_yd, int32_t *_ins_zd, int32_t *_ins_xdd, int32_t *_ins_ydd, int32_t *_ins_zdd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS, "INS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_xdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_ydd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_zdd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS pprz_msg_send_INS
#define DOWNLINK_SEND_INS(_trans, _dev, ins_x, ins_y, ins_z, ins_xd, ins_yd, ins_zd, ins_xdd, ins_ydd, ins_zdd) pprz_msg_send_INS(&((_trans).trans_tx), &((_dev).device), AC_ID, ins_x, ins_y, ins_z, ins_xd, ins_yd, ins_zd, ins_xdd, ins_ydd, ins_zdd)
/**
 * Sends a INS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ins_x 
 * @param _ins_y 
 * @param _ins_z 
 * @param _ins_xd 
 * @param _ins_yd 
 * @param _ins_zd 
 * @param _ins_xdd 
 * @param _ins_ydd 
 * @param _ins_zdd 
 */
static inline void pprz_msg_send_INS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_ins_x, int32_t *_ins_y, int32_t *_ins_z, int32_t *_ins_xd, int32_t *_ins_yd, int32_t *_ins_zd, int32_t *_ins_xdd, int32_t *_ins_ydd, int32_t *_ins_zdd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS(&msg,_ins_x,_ins_y,_ins_z,_ins_xd,_ins_yd,_ins_zd,_ins_xdd,_ins_ydd,_ins_zdd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS(_trans, _dev, ins_x, ins_y, ins_z, ins_xd, ins_yd, ins_zd, ins_xdd, ins_ydd, ins_zdd) {}
static inline void pprz_send_msg_INS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_ins_x __attribute__((unused)), int32_t *_ins_y __attribute__((unused)), int32_t *_ins_z __attribute__((unused)), int32_t *_ins_xd __attribute__((unused)), int32_t *_ins_yd __attribute__((unused)), int32_t *_ins_zd __attribute__((unused)), int32_t *_ins_xdd __attribute__((unused)), int32_t *_ins_ydd __attribute__((unused)), int32_t *_ins_zdd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ins_x in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field ins_y in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ins_z in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field ins_xd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field ins_yd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field ins_zd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field ins_xdd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_xdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field ins_ydd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_ydd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field ins_zdd in message INS
  *
  * @param _payload : a pointer to the INS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_ins_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/* Compatibility macros */
#define DL_INS_ins_x(_payload) pprzlink_get_DL_INS_ins_x(_payload)
#define DL_INS_ins_y(_payload) pprzlink_get_DL_INS_ins_y(_payload)
#define DL_INS_ins_z(_payload) pprzlink_get_DL_INS_ins_z(_payload)
#define DL_INS_ins_xd(_payload) pprzlink_get_DL_INS_ins_xd(_payload)
#define DL_INS_ins_yd(_payload) pprzlink_get_DL_INS_ins_yd(_payload)
#define DL_INS_ins_zd(_payload) pprzlink_get_DL_INS_ins_zd(_payload)
#define DL_INS_ins_xdd(_payload) pprzlink_get_DL_INS_ins_xdd(_payload)
#define DL_INS_ins_ydd(_payload) pprzlink_get_DL_INS_ins_ydd(_payload)
#define DL_INS_ins_zdd(_payload) pprzlink_get_DL_INS_ins_zdd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_H_

