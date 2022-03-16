/** @file
 *  @brief PPRZLink message header for GEIGER_COUNTER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GEIGER_COUNTER_H_
#define _VAR_MESSAGES_telemetry_GEIGER_COUNTER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GEIGER_COUNTER 153
#define PPRZ_MSG_ID_GEIGER_COUNTER 153

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GEIGER_COUNTER _send_msg(GEIGER_COUNTER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GEIGER_COUNTER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _tube1 
 * @param _tube2 
 * @param _vsupply 
 */
static inline void pprzlink_msg_v2_send_GEIGER_COUNTER(struct pprzlink_msg * msg, uint32_t *_tube1, uint32_t *_tube2, uint16_t *_vsupply) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GEIGER_COUNTER, "GEIGER_COUNTER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tube1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tube2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _vsupply, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GEIGER_COUNTER pprz_msg_send_GEIGER_COUNTER
#define DOWNLINK_SEND_GEIGER_COUNTER(_trans, _dev, tube1, tube2, vsupply) pprz_msg_send_GEIGER_COUNTER(&((_trans).trans_tx), &((_dev).device), AC_ID, tube1, tube2, vsupply)
/**
 * Sends a GEIGER_COUNTER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _tube1 
 * @param _tube2 
 * @param _vsupply 
 */
static inline void pprz_msg_send_GEIGER_COUNTER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_tube1, uint32_t *_tube2, uint16_t *_vsupply) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GEIGER_COUNTER(&msg,_tube1,_tube2,_vsupply);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GEIGER_COUNTER(_trans, _dev, tube1, tube2, vsupply) {}
static inline void pprz_send_msg_GEIGER_COUNTER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_tube1 __attribute__((unused)), uint32_t *_tube2 __attribute__((unused)), uint16_t *_vsupply __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field tube1 in message GEIGER_COUNTER
  *
  * @param _payload : a pointer to the GEIGER_COUNTER message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GEIGER_COUNTER_tube1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field tube2 in message GEIGER_COUNTER
  *
  * @param _payload : a pointer to the GEIGER_COUNTER message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GEIGER_COUNTER_tube2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field vsupply in message GEIGER_COUNTER
  *
  * @param _payload : a pointer to the GEIGER_COUNTER message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GEIGER_COUNTER_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/* Compatibility macros */
#define DL_GEIGER_COUNTER_tube1(_payload) pprzlink_get_DL_GEIGER_COUNTER_tube1(_payload)
#define DL_GEIGER_COUNTER_tube2(_payload) pprzlink_get_DL_GEIGER_COUNTER_tube2(_payload)
#define DL_GEIGER_COUNTER_vsupply(_payload) pprzlink_get_DL_GEIGER_COUNTER_vsupply(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GEIGER_COUNTER_H_

