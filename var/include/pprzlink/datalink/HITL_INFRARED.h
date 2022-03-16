/** @file
 *  @brief PPRZLink message header for HITL_INFRARED in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_HITL_INFRARED_H_
#define _VAR_MESSAGES_datalink_HITL_INFRARED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HITL_INFRARED 7
#define PPRZ_MSG_ID_HITL_INFRARED 7

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HITL_INFRARED _send_msg(HITL_INFRARED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HITL_INFRARED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _roll 
 * @param _pitch 
 * @param _top 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_HITL_INFRARED(struct pprzlink_msg * msg, int16_t *_roll, int16_t *_pitch, int16_t *_top, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HITL_INFRARED, "HITL_INFRARED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _roll, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _pitch, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _top, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HITL_INFRARED pprz_msg_send_HITL_INFRARED
#define DOWNLINK_SEND_HITL_INFRARED(_trans, _dev, roll, pitch, top, ac_id) pprz_msg_send_HITL_INFRARED(&((_trans).trans_tx), &((_dev).device), AC_ID, roll, pitch, top, ac_id)
/**
 * Sends a HITL_INFRARED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _roll 
 * @param _pitch 
 * @param _top 
 * @param _ac_id 
 */
static inline void pprz_msg_send_HITL_INFRARED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_roll, int16_t *_pitch, int16_t *_top, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HITL_INFRARED(&msg,_roll,_pitch,_top,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HITL_INFRARED(_trans, _dev, roll, pitch, top, ac_id) {}
static inline void pprz_send_msg_HITL_INFRARED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_roll __attribute__((unused)), int16_t *_pitch __attribute__((unused)), int16_t *_top __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field roll in message HITL_INFRARED
  *
  * @param _payload : a pointer to the HITL_INFRARED message
  * @return 
  */
static inline int16_t pprzlink_get_DL_HITL_INFRARED_roll(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field pitch in message HITL_INFRARED
  *
  * @param _payload : a pointer to the HITL_INFRARED message
  * @return 
  */
static inline int16_t pprzlink_get_DL_HITL_INFRARED_pitch(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field top in message HITL_INFRARED
  *
  * @param _payload : a pointer to the HITL_INFRARED message
  * @return 
  */
static inline int16_t pprzlink_get_DL_HITL_INFRARED_top(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field ac_id in message HITL_INFRARED
  *
  * @param _payload : a pointer to the HITL_INFRARED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_INFRARED_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 10);
}


/* Compatibility macros */
#define DL_HITL_INFRARED_roll(_payload) pprzlink_get_DL_HITL_INFRARED_roll(_payload)
#define DL_HITL_INFRARED_pitch(_payload) pprzlink_get_DL_HITL_INFRARED_pitch(_payload)
#define DL_HITL_INFRARED_top(_payload) pprzlink_get_DL_HITL_INFRARED_top(_payload)
#define DL_HITL_INFRARED_ac_id(_payload) pprzlink_get_DL_HITL_INFRARED_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_HITL_INFRARED_H_

