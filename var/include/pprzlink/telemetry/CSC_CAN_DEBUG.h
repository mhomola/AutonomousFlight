/** @file
 *  @brief PPRZLink message header for CSC_CAN_DEBUG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CSC_CAN_DEBUG_H_
#define _VAR_MESSAGES_telemetry_CSC_CAN_DEBUG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CSC_CAN_DEBUG 176
#define PPRZ_MSG_ID_CSC_CAN_DEBUG 176

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CSC_CAN_DEBUG _send_msg(CSC_CAN_DEBUG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CSC_CAN_DEBUG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _err_nb 
 * @param _err_code 
 */
static inline void pprzlink_msg_v2_send_CSC_CAN_DEBUG(struct pprzlink_msg * msg, uint32_t *_err_nb, uint32_t *_err_code) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CSC_CAN_DEBUG, "CSC_CAN_DEBUG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _err_nb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _err_code, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CSC_CAN_DEBUG pprz_msg_send_CSC_CAN_DEBUG
#define DOWNLINK_SEND_CSC_CAN_DEBUG(_trans, _dev, err_nb, err_code) pprz_msg_send_CSC_CAN_DEBUG(&((_trans).trans_tx), &((_dev).device), AC_ID, err_nb, err_code)
/**
 * Sends a CSC_CAN_DEBUG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _err_nb 
 * @param _err_code 
 */
static inline void pprz_msg_send_CSC_CAN_DEBUG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_err_nb, uint32_t *_err_code) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CSC_CAN_DEBUG(&msg,_err_nb,_err_code);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CSC_CAN_DEBUG(_trans, _dev, err_nb, err_code) {}
static inline void pprz_send_msg_CSC_CAN_DEBUG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_err_nb __attribute__((unused)), uint32_t *_err_code __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field err_nb in message CSC_CAN_DEBUG
  *
  * @param _payload : a pointer to the CSC_CAN_DEBUG message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_CSC_CAN_DEBUG_err_nb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field err_code in message CSC_CAN_DEBUG
  *
  * @param _payload : a pointer to the CSC_CAN_DEBUG message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_CSC_CAN_DEBUG_err_code(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/* Compatibility macros */
#define DL_CSC_CAN_DEBUG_err_nb(_payload) pprzlink_get_DL_CSC_CAN_DEBUG_err_nb(_payload)
#define DL_CSC_CAN_DEBUG_err_code(_payload) pprzlink_get_DL_CSC_CAN_DEBUG_err_code(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CSC_CAN_DEBUG_H_

