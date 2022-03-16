/** @file
 *  @brief PPRZLink message header for STEREOCAM_FOLLOW_ME in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_STEREOCAM_FOLLOW_ME_H_
#define _VAR_MESSAGES_intermcu_STEREOCAM_FOLLOW_ME_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STEREOCAM_FOLLOW_ME 83
#define PPRZ_MSG_ID_STEREOCAM_FOLLOW_ME 83

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STEREOCAM_FOLLOW_ME _send_msg(STEREOCAM_FOLLOW_ME,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STEREOCAM_FOLLOW_ME message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _headingToFollow 
 * @param _heightObject 
 * @param _distanceToObject 
 */
static inline void pprzlink_msg_v2_send_STEREOCAM_FOLLOW_ME(struct pprzlink_msg * msg, uint8_t *_headingToFollow, uint8_t *_heightObject, uint8_t *_distanceToObject) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STEREOCAM_FOLLOW_ME, "STEREOCAM_FOLLOW_ME");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _headingToFollow, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _heightObject, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _distanceToObject, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STEREOCAM_FOLLOW_ME pprz_msg_send_STEREOCAM_FOLLOW_ME
#define DOWNLINK_SEND_STEREOCAM_FOLLOW_ME(_trans, _dev, headingToFollow, heightObject, distanceToObject) pprz_msg_send_STEREOCAM_FOLLOW_ME(&((_trans).trans_tx), &((_dev).device), AC_ID, headingToFollow, heightObject, distanceToObject)
/**
 * Sends a STEREOCAM_FOLLOW_ME message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _headingToFollow 
 * @param _heightObject 
 * @param _distanceToObject 
 */
static inline void pprz_msg_send_STEREOCAM_FOLLOW_ME(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_headingToFollow, uint8_t *_heightObject, uint8_t *_distanceToObject) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STEREOCAM_FOLLOW_ME(&msg,_headingToFollow,_heightObject,_distanceToObject);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STEREOCAM_FOLLOW_ME(_trans, _dev, headingToFollow, heightObject, distanceToObject) {}
static inline void pprz_send_msg_STEREOCAM_FOLLOW_ME(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_headingToFollow __attribute__((unused)), uint8_t *_heightObject __attribute__((unused)), uint8_t *_distanceToObject __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field headingToFollow in message STEREOCAM_FOLLOW_ME
  *
  * @param _payload : a pointer to the STEREOCAM_FOLLOW_ME message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_FOLLOW_ME_headingToFollow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field heightObject in message STEREOCAM_FOLLOW_ME
  *
  * @param _payload : a pointer to the STEREOCAM_FOLLOW_ME message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_FOLLOW_ME_heightObject(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field distanceToObject in message STEREOCAM_FOLLOW_ME
  *
  * @param _payload : a pointer to the STEREOCAM_FOLLOW_ME message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREOCAM_FOLLOW_ME_distanceToObject(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/* Compatibility macros */
#define DL_STEREOCAM_FOLLOW_ME_headingToFollow(_payload) pprzlink_get_DL_STEREOCAM_FOLLOW_ME_headingToFollow(_payload)
#define DL_STEREOCAM_FOLLOW_ME_heightObject(_payload) pprzlink_get_DL_STEREOCAM_FOLLOW_ME_heightObject(_payload)
#define DL_STEREOCAM_FOLLOW_ME_distanceToObject(_payload) pprzlink_get_DL_STEREOCAM_FOLLOW_ME_distanceToObject(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_STEREOCAM_FOLLOW_ME_H_

