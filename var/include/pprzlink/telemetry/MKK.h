/** @file
 *  @brief PPRZLink message header for MKK in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MKK_H_
#define _VAR_MESSAGES_telemetry_MKK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MKK 36
#define PPRZ_MSG_ID_MKK 36

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MKK _send_msg(MKK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MKK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _nr 
 * @param _rpm 
 * @param _current 
 * @param _temp 
 */
static inline void pprzlink_msg_v2_send_MKK(struct pprzlink_msg * msg, uint8_t *_nr, uint8_t *_rpm, uint8_t *_current, int8_t *_temp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MKK, "MKK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nr, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rpm, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _current, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _temp, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MKK pprz_msg_send_MKK
#define DOWNLINK_SEND_MKK(_trans, _dev, nr, rpm, current, temp) pprz_msg_send_MKK(&((_trans).trans_tx), &((_dev).device), AC_ID, nr, rpm, current, temp)
/**
 * Sends a MKK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _nr 
 * @param _rpm 
 * @param _current 
 * @param _temp 
 */
static inline void pprz_msg_send_MKK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_nr, uint8_t *_rpm, uint8_t *_current, int8_t *_temp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MKK(&msg,_nr,_rpm,_current,_temp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MKK(_trans, _dev, nr, rpm, current, temp) {}
static inline void pprz_send_msg_MKK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_nr __attribute__((unused)), uint8_t *_rpm __attribute__((unused)), uint8_t *_current __attribute__((unused)), int8_t *_temp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field nr in message MKK
  *
  * @param _payload : a pointer to the MKK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MKK_nr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field rpm in message MKK
  *
  * @param _payload : a pointer to the MKK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MKK_rpm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field current in message MKK
  *
  * @param _payload : a pointer to the MKK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MKK_current(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field temp in message MKK
  *
  * @param _payload : a pointer to the MKK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_MKK_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 7);
}


/* Compatibility macros */
#define DL_MKK_nr(_payload) pprzlink_get_DL_MKK_nr(_payload)
#define DL_MKK_rpm(_payload) pprzlink_get_DL_MKK_rpm(_payload)
#define DL_MKK_current(_payload) pprzlink_get_DL_MKK_current(_payload)
#define DL_MKK_temp(_payload) pprzlink_get_DL_MKK_temp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MKK_H_

