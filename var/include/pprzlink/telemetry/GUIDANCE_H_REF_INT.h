/** @file
 *  @brief PPRZLink message header for GUIDANCE_H_REF_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GUIDANCE_H_REF_INT_H_
#define _VAR_MESSAGES_telemetry_GUIDANCE_H_REF_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GUIDANCE_H_REF_INT 149
#define PPRZ_MSG_ID_GUIDANCE_H_REF_INT 149

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GUIDANCE_H_REF_INT _send_msg(GUIDANCE_H_REF_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GUIDANCE_H_REF_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_x 
 * @param _ref_x 
 * @param _sp_xd 
 * @param _ref_xd 
 * @param _ref_xdd 
 * @param _sp_y 
 * @param _ref_y 
 * @param _sp_yd 
 * @param _ref_yd 
 * @param _ref_ydd 
 */
static inline void pprzlink_msg_v2_send_GUIDANCE_H_REF_INT(struct pprzlink_msg * msg, int32_t *_sp_x, int32_t *_ref_x, int32_t *_sp_xd, int32_t *_ref_xd, int32_t *_ref_xdd, int32_t *_sp_y, int32_t *_ref_y, int32_t *_sp_yd, int32_t *_ref_yd, int32_t *_ref_ydd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GUIDANCE_H_REF_INT, "GUIDANCE_H_REF_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_xdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_ydd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GUIDANCE_H_REF_INT pprz_msg_send_GUIDANCE_H_REF_INT
#define DOWNLINK_SEND_GUIDANCE_H_REF_INT(_trans, _dev, sp_x, ref_x, sp_xd, ref_xd, ref_xdd, sp_y, ref_y, sp_yd, ref_yd, ref_ydd) pprz_msg_send_GUIDANCE_H_REF_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_x, ref_x, sp_xd, ref_xd, ref_xdd, sp_y, ref_y, sp_yd, ref_yd, ref_ydd)
/**
 * Sends a GUIDANCE_H_REF_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_x 
 * @param _ref_x 
 * @param _sp_xd 
 * @param _ref_xd 
 * @param _ref_xdd 
 * @param _sp_y 
 * @param _ref_y 
 * @param _sp_yd 
 * @param _ref_yd 
 * @param _ref_ydd 
 */
static inline void pprz_msg_send_GUIDANCE_H_REF_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_sp_x, int32_t *_ref_x, int32_t *_sp_xd, int32_t *_ref_xd, int32_t *_ref_xdd, int32_t *_sp_y, int32_t *_ref_y, int32_t *_sp_yd, int32_t *_ref_yd, int32_t *_ref_ydd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GUIDANCE_H_REF_INT(&msg,_sp_x,_ref_x,_sp_xd,_ref_xd,_ref_xdd,_sp_y,_ref_y,_sp_yd,_ref_yd,_ref_ydd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GUIDANCE_H_REF_INT(_trans, _dev, sp_x, ref_x, sp_xd, ref_xd, ref_xdd, sp_y, ref_y, sp_yd, ref_yd, ref_ydd) {}
static inline void pprz_send_msg_GUIDANCE_H_REF_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_sp_x __attribute__((unused)), int32_t *_ref_x __attribute__((unused)), int32_t *_sp_xd __attribute__((unused)), int32_t *_ref_xd __attribute__((unused)), int32_t *_ref_xdd __attribute__((unused)), int32_t *_sp_y __attribute__((unused)), int32_t *_ref_y __attribute__((unused)), int32_t *_sp_yd __attribute__((unused)), int32_t *_ref_yd __attribute__((unused)), int32_t *_ref_ydd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_x in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field ref_x in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field sp_xd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field ref_xd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field ref_xdd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_xdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field sp_y in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field ref_y in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field sp_yd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field ref_yd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field ref_ydd in message GUIDANCE_H_REF_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_REF_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_ydd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/* Compatibility macros */
#define DL_GUIDANCE_H_REF_INT_sp_x(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_x(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_x(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_x(_payload)
#define DL_GUIDANCE_H_REF_INT_sp_xd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_xd(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_xd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_xd(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_xdd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_xdd(_payload)
#define DL_GUIDANCE_H_REF_INT_sp_y(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_y(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_y(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_y(_payload)
#define DL_GUIDANCE_H_REF_INT_sp_yd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_sp_yd(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_yd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_yd(_payload)
#define DL_GUIDANCE_H_REF_INT_ref_ydd(_payload) pprzlink_get_DL_GUIDANCE_H_REF_INT_ref_ydd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GUIDANCE_H_REF_INT_H_

