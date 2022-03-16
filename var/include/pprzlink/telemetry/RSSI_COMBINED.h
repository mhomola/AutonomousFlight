/** @file
 *  @brief PPRZLink message header for RSSI_COMBINED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RSSI_COMBINED_H_
#define _VAR_MESSAGES_telemetry_RSSI_COMBINED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RSSI_COMBINED 39
#define PPRZ_MSG_ID_RSSI_COMBINED 39

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RSSI_COMBINED _send_msg(RSSI_COMBINED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RSSI_COMBINED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _remote_rssi 
 * @param _tx_power 
 * @param _local_rssi 
 * @param _local_noise 
 * @param _remote_noise 
 */
static inline void pprzlink_msg_v2_send_RSSI_COMBINED(struct pprzlink_msg * msg, uint8_t *_remote_rssi, uint8_t *_tx_power, uint8_t *_local_rssi, uint8_t *_local_noise, uint8_t *_remote_noise) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RSSI_COMBINED, "RSSI_COMBINED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _remote_rssi, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _tx_power, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _local_rssi, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _local_noise, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _remote_noise, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RSSI_COMBINED pprz_msg_send_RSSI_COMBINED
#define DOWNLINK_SEND_RSSI_COMBINED(_trans, _dev, remote_rssi, tx_power, local_rssi, local_noise, remote_noise) pprz_msg_send_RSSI_COMBINED(&((_trans).trans_tx), &((_dev).device), AC_ID, remote_rssi, tx_power, local_rssi, local_noise, remote_noise)
/**
 * Sends a RSSI_COMBINED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _remote_rssi 
 * @param _tx_power 
 * @param _local_rssi 
 * @param _local_noise 
 * @param _remote_noise 
 */
static inline void pprz_msg_send_RSSI_COMBINED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_remote_rssi, uint8_t *_tx_power, uint8_t *_local_rssi, uint8_t *_local_noise, uint8_t *_remote_noise) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RSSI_COMBINED(&msg,_remote_rssi,_tx_power,_local_rssi,_local_noise,_remote_noise);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RSSI_COMBINED(_trans, _dev, remote_rssi, tx_power, local_rssi, local_noise, remote_noise) {}
static inline void pprz_send_msg_RSSI_COMBINED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_remote_rssi __attribute__((unused)), uint8_t *_tx_power __attribute__((unused)), uint8_t *_local_rssi __attribute__((unused)), uint8_t *_local_noise __attribute__((unused)), uint8_t *_remote_noise __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field remote_rssi in message RSSI_COMBINED
  *
  * @param _payload : a pointer to the RSSI_COMBINED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_COMBINED_remote_rssi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field tx_power in message RSSI_COMBINED
  *
  * @param _payload : a pointer to the RSSI_COMBINED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_COMBINED_tx_power(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field local_rssi in message RSSI_COMBINED
  *
  * @param _payload : a pointer to the RSSI_COMBINED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_COMBINED_local_rssi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field local_noise in message RSSI_COMBINED
  *
  * @param _payload : a pointer to the RSSI_COMBINED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_COMBINED_local_noise(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/** Getter for field remote_noise in message RSSI_COMBINED
  *
  * @param _payload : a pointer to the RSSI_COMBINED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RSSI_COMBINED_remote_noise(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/* Compatibility macros */
#define DL_RSSI_COMBINED_remote_rssi(_payload) pprzlink_get_DL_RSSI_COMBINED_remote_rssi(_payload)
#define DL_RSSI_COMBINED_tx_power(_payload) pprzlink_get_DL_RSSI_COMBINED_tx_power(_payload)
#define DL_RSSI_COMBINED_local_rssi(_payload) pprzlink_get_DL_RSSI_COMBINED_local_rssi(_payload)
#define DL_RSSI_COMBINED_local_noise(_payload) pprzlink_get_DL_RSSI_COMBINED_local_noise(_payload)
#define DL_RSSI_COMBINED_remote_noise(_payload) pprzlink_get_DL_RSSI_COMBINED_remote_noise(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RSSI_COMBINED_H_

