/** @file
 *  @brief PPRZLink message header for HOVER_LOOP in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_HOVER_LOOP_H_
#define _VAR_MESSAGES_telemetry_HOVER_LOOP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HOVER_LOOP 146
#define PPRZ_MSG_ID_HOVER_LOOP 146

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HOVER_LOOP _send_msg(HOVER_LOOP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HOVER_LOOP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _sp_x 
 * @param _sp_y 
 * @param _est_x 
 * @param _est_y 
 * @param _est_xd 
 * @param _est_yd 
 * @param _est_xdd 
 * @param _est_ydd 
 * @param _err_x 
 * @param _err_y 
 * @param _err_xd 
 * @param _err_yd 
 * @param _err_sum_x 
 * @param _err_sum_y 
 * @param _cmd_x 
 * @param _cmd_y 
 * @param _cmd_heading 
 */
static inline void pprzlink_msg_v2_send_HOVER_LOOP(struct pprzlink_msg * msg, int32_t *_sp_x, int32_t *_sp_y, int32_t *_est_x, int32_t *_est_y, int32_t *_est_xd, int32_t *_est_yd, int32_t *_est_xdd, int32_t *_est_ydd, int32_t *_err_x, int32_t *_err_y, int32_t *_err_xd, int32_t *_err_yd, int32_t *_err_sum_x, int32_t *_err_sum_y, int32_t *_cmd_x, int32_t *_cmd_y, float *_cmd_heading) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HOVER_LOOP, "HOVER_LOOP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_xdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_ydd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_sum_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _err_sum_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cmd_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cmd_heading, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HOVER_LOOP pprz_msg_send_HOVER_LOOP
#define DOWNLINK_SEND_HOVER_LOOP(_trans, _dev, sp_x, sp_y, est_x, est_y, est_xd, est_yd, est_xdd, est_ydd, err_x, err_y, err_xd, err_yd, err_sum_x, err_sum_y, cmd_x, cmd_y, cmd_heading) pprz_msg_send_HOVER_LOOP(&((_trans).trans_tx), &((_dev).device), AC_ID, sp_x, sp_y, est_x, est_y, est_xd, est_yd, est_xdd, est_ydd, err_x, err_y, err_xd, err_yd, err_sum_x, err_sum_y, cmd_x, cmd_y, cmd_heading)
/**
 * Sends a HOVER_LOOP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _sp_x 
 * @param _sp_y 
 * @param _est_x 
 * @param _est_y 
 * @param _est_xd 
 * @param _est_yd 
 * @param _est_xdd 
 * @param _est_ydd 
 * @param _err_x 
 * @param _err_y 
 * @param _err_xd 
 * @param _err_yd 
 * @param _err_sum_x 
 * @param _err_sum_y 
 * @param _cmd_x 
 * @param _cmd_y 
 * @param _cmd_heading 
 */
static inline void pprz_msg_send_HOVER_LOOP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_sp_x, int32_t *_sp_y, int32_t *_est_x, int32_t *_est_y, int32_t *_est_xd, int32_t *_est_yd, int32_t *_est_xdd, int32_t *_est_ydd, int32_t *_err_x, int32_t *_err_y, int32_t *_err_xd, int32_t *_err_yd, int32_t *_err_sum_x, int32_t *_err_sum_y, int32_t *_cmd_x, int32_t *_cmd_y, float *_cmd_heading) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HOVER_LOOP(&msg,_sp_x,_sp_y,_est_x,_est_y,_est_xd,_est_yd,_est_xdd,_est_ydd,_err_x,_err_y,_err_xd,_err_yd,_err_sum_x,_err_sum_y,_cmd_x,_cmd_y,_cmd_heading);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HOVER_LOOP(_trans, _dev, sp_x, sp_y, est_x, est_y, est_xd, est_yd, est_xdd, est_ydd, err_x, err_y, err_xd, err_yd, err_sum_x, err_sum_y, cmd_x, cmd_y, cmd_heading) {}
static inline void pprz_send_msg_HOVER_LOOP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_sp_x __attribute__((unused)), int32_t *_sp_y __attribute__((unused)), int32_t *_est_x __attribute__((unused)), int32_t *_est_y __attribute__((unused)), int32_t *_est_xd __attribute__((unused)), int32_t *_est_yd __attribute__((unused)), int32_t *_est_xdd __attribute__((unused)), int32_t *_est_ydd __attribute__((unused)), int32_t *_err_x __attribute__((unused)), int32_t *_err_y __attribute__((unused)), int32_t *_err_xd __attribute__((unused)), int32_t *_err_yd __attribute__((unused)), int32_t *_err_sum_x __attribute__((unused)), int32_t *_err_sum_y __attribute__((unused)), int32_t *_cmd_x __attribute__((unused)), int32_t *_cmd_y __attribute__((unused)), float *_cmd_heading __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field sp_x in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_sp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field sp_y in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_sp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field est_x in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field est_y in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field est_xd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field est_yd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field est_xdd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_xdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field est_ydd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_est_ydd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field err_x in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field err_y in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field err_xd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field err_yd in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field err_sum_x in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_sum_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field err_sum_y in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_err_sum_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field cmd_x in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_cmd_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 60);
}


/** Getter for field cmd_y in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_HOVER_LOOP_cmd_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 64);
}


/** Getter for field cmd_heading in message HOVER_LOOP
  *
  * @param _payload : a pointer to the HOVER_LOOP message
  * @return 
  */
static inline float pprzlink_get_DL_HOVER_LOOP_cmd_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/* Compatibility macros */
#define DL_HOVER_LOOP_sp_x(_payload) pprzlink_get_DL_HOVER_LOOP_sp_x(_payload)
#define DL_HOVER_LOOP_sp_y(_payload) pprzlink_get_DL_HOVER_LOOP_sp_y(_payload)
#define DL_HOVER_LOOP_est_x(_payload) pprzlink_get_DL_HOVER_LOOP_est_x(_payload)
#define DL_HOVER_LOOP_est_y(_payload) pprzlink_get_DL_HOVER_LOOP_est_y(_payload)
#define DL_HOVER_LOOP_est_xd(_payload) pprzlink_get_DL_HOVER_LOOP_est_xd(_payload)
#define DL_HOVER_LOOP_est_yd(_payload) pprzlink_get_DL_HOVER_LOOP_est_yd(_payload)
#define DL_HOVER_LOOP_est_xdd(_payload) pprzlink_get_DL_HOVER_LOOP_est_xdd(_payload)
#define DL_HOVER_LOOP_est_ydd(_payload) pprzlink_get_DL_HOVER_LOOP_est_ydd(_payload)
#define DL_HOVER_LOOP_err_x(_payload) pprzlink_get_DL_HOVER_LOOP_err_x(_payload)
#define DL_HOVER_LOOP_err_y(_payload) pprzlink_get_DL_HOVER_LOOP_err_y(_payload)
#define DL_HOVER_LOOP_err_xd(_payload) pprzlink_get_DL_HOVER_LOOP_err_xd(_payload)
#define DL_HOVER_LOOP_err_yd(_payload) pprzlink_get_DL_HOVER_LOOP_err_yd(_payload)
#define DL_HOVER_LOOP_err_sum_x(_payload) pprzlink_get_DL_HOVER_LOOP_err_sum_x(_payload)
#define DL_HOVER_LOOP_err_sum_y(_payload) pprzlink_get_DL_HOVER_LOOP_err_sum_y(_payload)
#define DL_HOVER_LOOP_cmd_x(_payload) pprzlink_get_DL_HOVER_LOOP_cmd_x(_payload)
#define DL_HOVER_LOOP_cmd_y(_payload) pprzlink_get_DL_HOVER_LOOP_cmd_y(_payload)
#define DL_HOVER_LOOP_cmd_heading(_payload) pprzlink_get_DL_HOVER_LOOP_cmd_heading(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_HOVER_LOOP_H_

