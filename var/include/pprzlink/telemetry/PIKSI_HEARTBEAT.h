/** @file
 *  @brief PPRZLink message header for PIKSI_HEARTBEAT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_PIKSI_HEARTBEAT_H_
#define _VAR_MESSAGES_telemetry_PIKSI_HEARTBEAT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_PIKSI_HEARTBEAT 108
#define PPRZ_MSG_ID_PIKSI_HEARTBEAT 108

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_PIKSI_HEARTBEAT _send_msg(PIKSI_HEARTBEAT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a PIKSI_HEARTBEAT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _heartbeat 
 */
static inline void pprzlink_msg_v2_send_PIKSI_HEARTBEAT(struct pprzlink_msg * msg, uint32_t *_heartbeat) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_PIKSI_HEARTBEAT, "PIKSI_HEARTBEAT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _heartbeat, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_PIKSI_HEARTBEAT pprz_msg_send_PIKSI_HEARTBEAT
#define DOWNLINK_SEND_PIKSI_HEARTBEAT(_trans, _dev, heartbeat) pprz_msg_send_PIKSI_HEARTBEAT(&((_trans).trans_tx), &((_dev).device), AC_ID, heartbeat)
/**
 * Sends a PIKSI_HEARTBEAT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _heartbeat 
 */
static inline void pprz_msg_send_PIKSI_HEARTBEAT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_heartbeat) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_PIKSI_HEARTBEAT(&msg,_heartbeat);
}


#else // DOWNLINK

#define DOWNLINK_SEND_PIKSI_HEARTBEAT(_trans, _dev, heartbeat) {}
static inline void pprz_send_msg_PIKSI_HEARTBEAT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_heartbeat __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field heartbeat in message PIKSI_HEARTBEAT
  *
  * @param _payload : a pointer to the PIKSI_HEARTBEAT message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_PIKSI_HEARTBEAT_heartbeat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/* Compatibility macros */
#define DL_PIKSI_HEARTBEAT_heartbeat(_payload) pprzlink_get_DL_PIKSI_HEARTBEAT_heartbeat(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_PIKSI_HEARTBEAT_H_

