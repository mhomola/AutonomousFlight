/** @file
 *  @brief PPRZLink message header for GUIDANCE_H_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GUIDANCE_H_INT_H_
#define _VAR_MESSAGES_telemetry_GUIDANCE_H_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GUIDANCE_H_INT 144
#define PPRZ_MSG_ID_GUIDANCE_H_INT 144

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GUIDANCE_H_INT _send_msg(GUIDANCE_H_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GUIDANCE_H_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_x 
 * @param _sp_y 
 * @param _ref_x 
 * @param _ref_y 
 * @param _est_x 
 * @param _est_y 
 */
static inline void pprzlink_msg_v2_send_GUIDANCE_H_INT(struct pprzlink_msg * msg, int32_t *_sp_x, int32_t *_sp_y, int32_t *_ref_x, int32_t *_ref_y, int32_t *_est_x, int32_t *_est_y) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GUIDANCE_H_INT, "GUIDANCE_H_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_y, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GUIDANCE_H_INT pprz_msg_send_GUIDANCE_H_INT
#define DOWNLINK_SEND_GUIDANCE_H_INT(_trans, _dev, sp_x, sp_y, ref_x, ref_y, est_x, est_y) pprz_msg_send_GUIDANCE_H_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_x, sp_y, ref_x, ref_y, est_x, est_y)
/**
 * Sends a GUIDANCE_H_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_x 
 * @param _sp_y 
 * @param _ref_x 
 * @param _ref_y 
 * @param _est_x 
 * @param _est_y 
 */
static inline void pprz_msg_send_GUIDANCE_H_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_sp_x, int32_t *_sp_y, int32_t *_ref_x, int32_t *_ref_y, int32_t *_est_x, int32_t *_est_y) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GUIDANCE_H_INT(&msg,_sp_x,_sp_y,_ref_x,_ref_y,_est_x,_est_y);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GUIDANCE_H_INT(_trans, _dev, sp_x, sp_y, ref_x, ref_y, est_x, est_y) {}
static inline void pprz_send_msg_GUIDANCE_H_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_sp_x __attribute__((unused)), int32_t *_sp_y __attribute__((unused)), int32_t *_ref_x __attribute__((unused)), int32_t *_ref_y __attribute__((unused)), int32_t *_est_x __attribute__((unused)), int32_t *_est_y __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_x in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_sp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field sp_y in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_sp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ref_x in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_ref_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field ref_y in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_ref_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field est_x in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_est_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field est_y in message GUIDANCE_H_INT
  *
  * @param _payload : a pointer to the GUIDANCE_H_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_GUIDANCE_H_INT_est_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/* Compatibility macros */
#define DL_GUIDANCE_H_INT_sp_x(_payload) pprzlink_get_DL_GUIDANCE_H_INT_sp_x(_payload)
#define DL_GUIDANCE_H_INT_sp_y(_payload) pprzlink_get_DL_GUIDANCE_H_INT_sp_y(_payload)
#define DL_GUIDANCE_H_INT_ref_x(_payload) pprzlink_get_DL_GUIDANCE_H_INT_ref_x(_payload)
#define DL_GUIDANCE_H_INT_ref_y(_payload) pprzlink_get_DL_GUIDANCE_H_INT_ref_y(_payload)
#define DL_GUIDANCE_H_INT_est_x(_payload) pprzlink_get_DL_GUIDANCE_H_INT_est_x(_payload)
#define DL_GUIDANCE_H_INT_est_y(_payload) pprzlink_get_DL_GUIDANCE_H_INT_est_y(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GUIDANCE_H_INT_H_

