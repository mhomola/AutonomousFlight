/** @file
 *  @brief PPRZLink message header for PPRZ_DEBUG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_PPRZ_DEBUG_H_
#define _VAR_MESSAGES_telemetry_PPRZ_DEBUG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_PPRZ_DEBUG 247
#define PPRZ_MSG_ID_PPRZ_DEBUG 247

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_PPRZ_DEBUG _send_msg(PPRZ_DEBUG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a PPRZ_DEBUG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _module 
 * @param _errno 
 */
static inline void pprzlink_msg_v2_send_PPRZ_DEBUG(struct pprzlink_msg * msg, uint8_t *_module, uint8_t *_errno) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_PPRZ_DEBUG, "PPRZ_DEBUG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _module, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _errno, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_PPRZ_DEBUG pprz_msg_send_PPRZ_DEBUG
#define DOWNLINK_SEND_PPRZ_DEBUG(_trans, _dev, module, errno) pprz_msg_send_PPRZ_DEBUG(&((_trans).trans_tx), &((_dev).device), AC_ID, module, errno)
/**
 * Sends a PPRZ_DEBUG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _module 
 * @param _errno 
 */
static inline void pprz_msg_send_PPRZ_DEBUG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_module, uint8_t *_errno) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_PPRZ_DEBUG(&msg,_module,_errno);
}


#else // DOWNLINK

#define DOWNLINK_SEND_PPRZ_DEBUG(_trans, _dev, module, errno) {}
static inline void pprz_send_msg_PPRZ_DEBUG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_module __attribute__((unused)), uint8_t *_errno __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field module in message PPRZ_DEBUG
  *
  * @param _payload : a pointer to the PPRZ_DEBUG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_DEBUG_module(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field errno in message PPRZ_DEBUG
  *
  * @param _payload : a pointer to the PPRZ_DEBUG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_DEBUG_errno(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/* Compatibility macros */
#define DL_PPRZ_DEBUG_module(_payload) pprzlink_get_DL_PPRZ_DEBUG_module(_payload)
#define DL_PPRZ_DEBUG_errno(_payload) pprzlink_get_DL_PPRZ_DEBUG_errno(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_PPRZ_DEBUG_H_

