/** @file
 *  @brief PPRZLink message header for EXTERNAL_FILTER_SOLUTION in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_EXTERNAL_FILTER_SOLUTION_H_
#define _VAR_MESSAGES_datalink_EXTERNAL_FILTER_SOLUTION_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_EXTERNAL_FILTER_SOLUTION 151
#define PPRZ_MSG_ID_EXTERNAL_FILTER_SOLUTION 151

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_EXTERNAL_FILTER_SOLUTION _send_msg(EXTERNAL_FILTER_SOLUTION,PPRZLINK_DEFAULT_VER)

/**
 * Sends a EXTERNAL_FILTER_SOLUTION message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _status 
 * @param _x 
 * @param _xd 
 * @param _y 
 * @param _yd 
 */
static inline void pprzlink_msg_v2_send_EXTERNAL_FILTER_SOLUTION(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_status, float *_x, float *_xd, float *_y, float *_yd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_EXTERNAL_FILTER_SOLUTION, "EXTERNAL_FILTER_SOLUTION");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _yd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_EXTERNAL_FILTER_SOLUTION pprz_msg_send_EXTERNAL_FILTER_SOLUTION
#define DOWNLINK_SEND_EXTERNAL_FILTER_SOLUTION(_trans, _dev, ac_id, status, x, xd, y, yd) pprz_msg_send_EXTERNAL_FILTER_SOLUTION(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, status, x, xd, y, yd)
/**
 * Sends a EXTERNAL_FILTER_SOLUTION message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _status 
 * @param _x 
 * @param _xd 
 * @param _y 
 * @param _yd 
 */
static inline void pprz_msg_send_EXTERNAL_FILTER_SOLUTION(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_status, float *_x, float *_xd, float *_y, float *_yd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_EXTERNAL_FILTER_SOLUTION(&msg,_ac_id,_status,_x,_xd,_y,_yd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_EXTERNAL_FILTER_SOLUTION(_trans, _dev, ac_id, status, x, xd, y, yd) {}
static inline void pprz_send_msg_EXTERNAL_FILTER_SOLUTION(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_status __attribute__((unused)), float *_x __attribute__((unused)), float *_xd __attribute__((unused)), float *_y __attribute__((unused)), float *_yd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field status in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field x in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline float pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field xd in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline float pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field y in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline float pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field yd in message EXTERNAL_FILTER_SOLUTION
  *
  * @param _payload : a pointer to the EXTERNAL_FILTER_SOLUTION message
  * @return 
  */
static inline float pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/* Compatibility macros */
#define DL_EXTERNAL_FILTER_SOLUTION_ac_id(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_ac_id(_payload)
#define DL_EXTERNAL_FILTER_SOLUTION_status(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_status(_payload)
#define DL_EXTERNAL_FILTER_SOLUTION_x(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_x(_payload)
#define DL_EXTERNAL_FILTER_SOLUTION_xd(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_xd(_payload)
#define DL_EXTERNAL_FILTER_SOLUTION_y(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_y(_payload)
#define DL_EXTERNAL_FILTER_SOLUTION_yd(_payload) pprzlink_get_DL_EXTERNAL_FILTER_SOLUTION_yd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_EXTERNAL_FILTER_SOLUTION_H_

