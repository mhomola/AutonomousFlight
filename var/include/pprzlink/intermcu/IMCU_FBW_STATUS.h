/** @file
 *  @brief PPRZLink message header for IMCU_FBW_STATUS in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_FBW_STATUS_H_
#define _VAR_MESSAGES_intermcu_IMCU_FBW_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_FBW_STATUS 4
#define PPRZ_MSG_ID_IMCU_FBW_STATUS 4

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_FBW_STATUS _send_msg(IMCU_FBW_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_FBW_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _mode 
 * @param _rc_status 
 * @param _frame_rate 
 * @param _vsupply 
 * @param _current 
 */
static inline void pprzlink_msg_v2_send_IMCU_FBW_STATUS(struct pprzlink_msg * msg, uint8_t *_mode, uint8_t *_rc_status, uint8_t *_frame_rate, float *_vsupply, float *_current) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_FBW_STATUS, "IMCU_FBW_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rc_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _frame_rate, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vsupply, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_FBW_STATUS pprz_msg_send_IMCU_FBW_STATUS
#define DOWNLINK_SEND_IMCU_FBW_STATUS(_trans, _dev, mode, rc_status, frame_rate, vsupply, current) pprz_msg_send_IMCU_FBW_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, mode, rc_status, frame_rate, vsupply, current)
/**
 * Sends a IMCU_FBW_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _mode 
 * @param _rc_status 
 * @param _frame_rate 
 * @param _vsupply 
 * @param _current 
 */
static inline void pprz_msg_send_IMCU_FBW_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_mode, uint8_t *_rc_status, uint8_t *_frame_rate, float *_vsupply, float *_current) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_FBW_STATUS(&msg,_mode,_rc_status,_frame_rate,_vsupply,_current);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_FBW_STATUS(_trans, _dev, mode, rc_status, frame_rate, vsupply, current) {}
static inline void pprz_send_msg_IMCU_FBW_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_mode __attribute__((unused)), uint8_t *_rc_status __attribute__((unused)), uint8_t *_frame_rate __attribute__((unused)), float *_vsupply __attribute__((unused)), float *_current __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field mode in message IMCU_FBW_STATUS
  *
  * @param _payload : a pointer to the IMCU_FBW_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_FBW_STATUS_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field rc_status in message IMCU_FBW_STATUS
  *
  * @param _payload : a pointer to the IMCU_FBW_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_FBW_STATUS_rc_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field frame_rate in message IMCU_FBW_STATUS
  *
  * @param _payload : a pointer to the IMCU_FBW_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_IMCU_FBW_STATUS_frame_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field vsupply in message IMCU_FBW_STATUS
  *
  * @param _payload : a pointer to the IMCU_FBW_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_IMCU_FBW_STATUS_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 7);
}


/** Getter for field current in message IMCU_FBW_STATUS
  *
  * @param _payload : a pointer to the IMCU_FBW_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_IMCU_FBW_STATUS_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 11);
}


/* Compatibility macros */
#define DL_IMCU_FBW_STATUS_mode(_payload) pprzlink_get_DL_IMCU_FBW_STATUS_mode(_payload)
#define DL_IMCU_FBW_STATUS_rc_status(_payload) pprzlink_get_DL_IMCU_FBW_STATUS_rc_status(_payload)
#define DL_IMCU_FBW_STATUS_frame_rate(_payload) pprzlink_get_DL_IMCU_FBW_STATUS_frame_rate(_payload)
#define DL_IMCU_FBW_STATUS_vsupply(_payload) pprzlink_get_DL_IMCU_FBW_STATUS_vsupply(_payload)
#define DL_IMCU_FBW_STATUS_current(_payload) pprzlink_get_DL_IMCU_FBW_STATUS_current(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_FBW_STATUS_H_

