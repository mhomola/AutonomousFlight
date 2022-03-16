/** @file
 *  @brief PPRZLink message header for XTEND_RSSI in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_XTEND_RSSI_H_
#define _VAR_MESSAGES_telemetry_XTEND_RSSI_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_XTEND_RSSI 70
#define PPRZ_MSG_ID_XTEND_RSSI 70

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_XTEND_RSSI _send_msg(XTEND_RSSI,PPRZLINK_DEFAULT_VER)

/**
 * Sends a XTEND_RSSI message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _datalink_time 
 * @param _rssi_fade_margin 
 * @param _duty 
 */
static inline void pprzlink_msg_v2_send_XTEND_RSSI(struct pprzlink_msg * msg, uint16_t *_datalink_time, uint8_t *_rssi_fade_margin, uint8_t *_duty) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_XTEND_RSSI, "XTEND_RSSI");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _datalink_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rssi_fade_margin, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _duty, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_XTEND_RSSI pprz_msg_send_XTEND_RSSI
#define DOWNLINK_SEND_XTEND_RSSI(_trans, _dev, datalink_time, rssi_fade_margin, duty) pprz_msg_send_XTEND_RSSI(&((_trans).trans_tx), &((_dev).device), AC_ID, datalink_time, rssi_fade_margin, duty)
/**
 * Sends a XTEND_RSSI message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _datalink_time 
 * @param _rssi_fade_margin 
 * @param _duty 
 */
static inline void pprz_msg_send_XTEND_RSSI(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_datalink_time, uint8_t *_rssi_fade_margin, uint8_t *_duty) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_XTEND_RSSI(&msg,_datalink_time,_rssi_fade_margin,_duty);
}


#else // DOWNLINK

#define DOWNLINK_SEND_XTEND_RSSI(_trans, _dev, datalink_time, rssi_fade_margin, duty) {}
static inline void pprz_send_msg_XTEND_RSSI(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_datalink_time __attribute__((unused)), uint8_t *_rssi_fade_margin __attribute__((unused)), uint8_t *_duty __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field datalink_time in message XTEND_RSSI
  *
  * @param _payload : a pointer to the XTEND_RSSI message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_XTEND_RSSI_datalink_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field rssi_fade_margin in message XTEND_RSSI
  *
  * @param _payload : a pointer to the XTEND_RSSI message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_XTEND_RSSI_rssi_fade_margin(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field duty in message XTEND_RSSI
  *
  * @param _payload : a pointer to the XTEND_RSSI message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_XTEND_RSSI_duty(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/* Compatibility macros */
#define DL_XTEND_RSSI_datalink_time(_payload) pprzlink_get_DL_XTEND_RSSI_datalink_time(_payload)
#define DL_XTEND_RSSI_rssi_fade_margin(_payload) pprzlink_get_DL_XTEND_RSSI_rssi_fade_margin(_payload)
#define DL_XTEND_RSSI_duty(_payload) pprzlink_get_DL_XTEND_RSSI_duty(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_XTEND_RSSI_H_

