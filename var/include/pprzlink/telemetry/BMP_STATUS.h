/** @file
 *  @brief PPRZLink message header for BMP_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_BMP_STATUS_H_
#define _VAR_MESSAGES_telemetry_BMP_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BMP_STATUS 84
#define PPRZ_MSG_ID_BMP_STATUS 84

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BMP_STATUS _send_msg(BMP_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BMP_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _UP 
 * @param _UT 
 * @param _press 
 * @param _temp 
 */
static inline void pprzlink_msg_v2_send_BMP_STATUS(struct pprzlink_msg * msg, int32_t *_UP, int32_t *_UT, int32_t *_press, int32_t *_temp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BMP_STATUS, "BMP_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _UP, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _UT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _press, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _temp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BMP_STATUS pprz_msg_send_BMP_STATUS
#define DOWNLINK_SEND_BMP_STATUS(_trans, _dev, UP, UT, press, temp) pprz_msg_send_BMP_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, UP, UT, press, temp)
/**
 * Sends a BMP_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _UP 
 * @param _UT 
 * @param _press 
 * @param _temp 
 */
static inline void pprz_msg_send_BMP_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_UP, int32_t *_UT, int32_t *_press, int32_t *_temp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BMP_STATUS(&msg,_UP,_UT,_press,_temp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BMP_STATUS(_trans, _dev, UP, UT, press, temp) {}
static inline void pprz_send_msg_BMP_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_UP __attribute__((unused)), int32_t *_UT __attribute__((unused)), int32_t *_press __attribute__((unused)), int32_t *_temp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field UP in message BMP_STATUS
  *
  * @param _payload : a pointer to the BMP_STATUS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BMP_STATUS_UP(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field UT in message BMP_STATUS
  *
  * @param _payload : a pointer to the BMP_STATUS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BMP_STATUS_UT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field press in message BMP_STATUS
  *
  * @param _payload : a pointer to the BMP_STATUS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BMP_STATUS_press(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field temp in message BMP_STATUS
  *
  * @param _payload : a pointer to the BMP_STATUS message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BMP_STATUS_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/* Compatibility macros */
#define DL_BMP_STATUS_UP(_payload) pprzlink_get_DL_BMP_STATUS_UP(_payload)
#define DL_BMP_STATUS_UT(_payload) pprzlink_get_DL_BMP_STATUS_UT(_payload)
#define DL_BMP_STATUS_press(_payload) pprzlink_get_DL_BMP_STATUS_press(_payload)
#define DL_BMP_STATUS_temp(_payload) pprzlink_get_DL_BMP_STATUS_temp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_BMP_STATUS_H_

