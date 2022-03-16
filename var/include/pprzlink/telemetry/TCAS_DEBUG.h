/** @file
 *  @brief PPRZLink message header for TCAS_DEBUG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TCAS_DEBUG_H_
#define _VAR_MESSAGES_telemetry_TCAS_DEBUG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TCAS_DEBUG 123
#define PPRZ_MSG_ID_TCAS_DEBUG 123

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TCAS_DEBUG _send_msg(TCAS_DEBUG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TCAS_DEBUG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _tau 
 */
static inline void pprzlink_msg_v2_send_TCAS_DEBUG(struct pprzlink_msg * msg, uint8_t *_ac_id, float *_tau) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TCAS_DEBUG, "TCAS_DEBUG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _tau, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TCAS_DEBUG pprz_msg_send_TCAS_DEBUG
#define DOWNLINK_SEND_TCAS_DEBUG(_trans, _dev, ac_id, tau) pprz_msg_send_TCAS_DEBUG(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, tau)
/**
 * Sends a TCAS_DEBUG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _tau 
 */
static inline void pprz_msg_send_TCAS_DEBUG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, float *_tau) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TCAS_DEBUG(&msg,_ac_id,_tau);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TCAS_DEBUG(_trans, _dev, ac_id, tau) {}
static inline void pprz_send_msg_TCAS_DEBUG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), float *_tau __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message TCAS_DEBUG
  *
  * @param _payload : a pointer to the TCAS_DEBUG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_TCAS_DEBUG_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field tau in message TCAS_DEBUG
  *
  * @param _payload : a pointer to the TCAS_DEBUG message
  * @return 
  */
static inline float pprzlink_get_DL_TCAS_DEBUG_tau(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/* Compatibility macros */
#define DL_TCAS_DEBUG_ac_id(_payload) pprzlink_get_DL_TCAS_DEBUG_ac_id(_payload)
#define DL_TCAS_DEBUG_tau(_payload) pprzlink_get_DL_TCAS_DEBUG_tau(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TCAS_DEBUG_H_

