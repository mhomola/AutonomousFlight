/** @file
 *  @brief PPRZLink message header for RSSI in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RSSI_H_
#define _VAR_MESSAGES_telemetry_RSSI_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RSSI 28
#define PPRZ_MSG_ID_RSSI 28

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RSSI _send_msg(RSSI,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RSSI message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _rssi 
 * @param _tx_power 
 */
static inline void pprzlink_msg_v2_send_RSSI(struct pprzlink_msg * msg, uint8_t *_rssi, uint8_t *_tx_power) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RSSI, "RSSI");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rssi, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _tx_power, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RSSI pprz_msg_send_RSSI
#define DOWNLINK_SEND_RSSI(_trans, _dev, rssi, tx_power) pprz_msg_send_RSSI(&((_trans).trans_tx), &((_dev).device), AC_ID, rssi, tx_power)
/**
 * Sends a RSSI message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _rssi 
 * @param _tx_power 
 */
static inline void pprz_msg_send_RSSI(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_rssi, uint8_t *_tx_power) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RSSI(&msg,_rssi,_tx_power);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RSSI(_trans, _dev, rssi, tx_power) {}
static inline void pprz_send_msg_RSSI(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_rssi __attribute__((unused)), uint8_t *_tx_power __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field rssi in message RSSI
  *
  * @param _payload : a pointer to the RSSI message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_rssi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field tx_power in message RSSI
  *
  * @param _payload : a pointer to the RSSI message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_tx_power(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/* Compatibility macros */
#define DL_RSSI_rssi(_payload) pprzlink_get_DL_RSSI_rssi(_payload)
#define DL_RSSI_tx_power(_payload) pprzlink_get_DL_RSSI_tx_power(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RSSI_H_

