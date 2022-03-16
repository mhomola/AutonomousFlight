/** @file
 *  @brief PPRZLink message header for RC_3CH_ in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RC_3CH__H_
#define _VAR_MESSAGES_telemetry_RC_3CH__H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RC_3CH_ 51
#define PPRZ_MSG_ID_RC_3CH_ 51

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RC_3CH_ _send_msg(RC_3CH_,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RC_3CH_ message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _throttle_mode 
 * @param _roll 
 * @param _pitch 
 */
static inline void pprzlink_msg_v2_send_RC_3CH_(struct pprzlink_msg * msg, uint8_t *_throttle_mode, int8_t *_roll, int8_t *_pitch) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RC_3CH_, "RC_3CH_");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _throttle_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _roll, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _pitch, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RC_3CH_ pprz_msg_send_RC_3CH_
#define DOWNLINK_SEND_RC_3CH_(_trans, _dev, throttle_mode, roll, pitch) pprz_msg_send_RC_3CH_(&((_trans).trans_tx), &((_dev).device), AC_ID, throttle_mode, roll, pitch)
/**
 * Sends a RC_3CH_ message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _throttle_mode 
 * @param _roll 
 * @param _pitch 
 */
static inline void pprz_msg_send_RC_3CH_(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_throttle_mode, int8_t *_roll, int8_t *_pitch) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RC_3CH_(&msg,_throttle_mode,_roll,_pitch);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RC_3CH_(_trans, _dev, throttle_mode, roll, pitch) {}
static inline void pprz_send_msg_RC_3CH_(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_throttle_mode __attribute__((unused)), int8_t *_roll __attribute__((unused)), int8_t *_pitch __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field throttle_mode in message RC_3CH_
  *
  * @param _payload : a pointer to the RC_3CH_ message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_RC_3CH__throttle_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field roll in message RC_3CH_
  *
  * @param _payload : a pointer to the RC_3CH_ message
  * @return 
  */
static inline int8_t pprzlink_get_DL_RC_3CH__roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 5);
}


/** Getter for field pitch in message RC_3CH_
  *
  * @param _payload : a pointer to the RC_3CH_ message
  * @return 
  */
static inline int8_t pprzlink_get_DL_RC_3CH__pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 6);
}


/* Compatibility macros */
#define DL_RC_3CH__throttle_mode(_payload) pprzlink_get_DL_RC_3CH__throttle_mode(_payload)
#define DL_RC_3CH__roll(_payload) pprzlink_get_DL_RC_3CH__roll(_payload)
#define DL_RC_3CH__pitch(_payload) pprzlink_get_DL_RC_3CH__pitch(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RC_3CH__H_

