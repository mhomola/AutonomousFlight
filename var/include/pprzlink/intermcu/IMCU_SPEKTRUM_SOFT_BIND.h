/** @file
 *  @brief PPRZLink message header for IMCU_SPEKTRUM_SOFT_BIND in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_SPEKTRUM_SOFT_BIND_H_
#define _VAR_MESSAGES_intermcu_IMCU_SPEKTRUM_SOFT_BIND_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_SPEKTRUM_SOFT_BIND 3
#define PPRZ_MSG_ID_IMCU_SPEKTRUM_SOFT_BIND 3

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_SPEKTRUM_SOFT_BIND _send_msg(IMCU_SPEKTRUM_SOFT_BIND,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_SPEKTRUM_SOFT_BIND message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 */
static inline void pprzlink_msg_v2_send_IMCU_SPEKTRUM_SOFT_BIND(struct pprzlink_msg * msg) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_SPEKTRUM_SOFT_BIND, "IMCU_SPEKTRUM_SOFT_BIND");
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_SPEKTRUM_SOFT_BIND pprz_msg_send_IMCU_SPEKTRUM_SOFT_BIND
#define DOWNLINK_SEND_IMCU_SPEKTRUM_SOFT_BIND(_trans, _dev) pprz_msg_send_IMCU_SPEKTRUM_SOFT_BIND(&((_trans).trans_tx), &((_dev).device), AC_ID)
/**
 * Sends a IMCU_SPEKTRUM_SOFT_BIND message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 */
static inline void pprz_msg_send_IMCU_SPEKTRUM_SOFT_BIND(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_SPEKTRUM_SOFT_BIND(&msg);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_SPEKTRUM_SOFT_BIND(_trans, _dev) {}
static inline void pprz_send_msg_IMCU_SPEKTRUM_SOFT_BIND(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused))) {}

#endif // DOWNLINK



/* Compatibility macros */




#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_SPEKTRUM_SOFT_BIND_H_

