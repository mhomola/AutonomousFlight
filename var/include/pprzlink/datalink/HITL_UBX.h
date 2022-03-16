/** @file
 *  @brief PPRZLink message header for HITL_UBX in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_HITL_UBX_H_
#define _VAR_MESSAGES_datalink_HITL_UBX_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HITL_UBX 6
#define PPRZ_MSG_ID_HITL_UBX 6

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HITL_UBX _send_msg(HITL_UBX,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HITL_UBX message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _class 
 * @param _id 
 * @param _ac_id 
 * @param nb_ubx_payload,_ubx_payload 
 */
static inline void pprzlink_msg_v2_send_HITL_UBX(struct pprzlink_msg * msg, uint8_t *_class, uint8_t *_id, uint8_t *_ac_id, uint8_t nb_ubx_payload, uint8_t *_ubx_payload) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+nb_ubx_payload*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+nb_ubx_payload*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HITL_UBX, "HITL_UBX");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _class, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_ubx_payload, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _ubx_payload, nb_ubx_payload*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HITL_UBX pprz_msg_send_HITL_UBX
#define DOWNLINK_SEND_HITL_UBX(_trans, _dev, class, id, ac_id, nb_ubx_payload, ubx_payload) pprz_msg_send_HITL_UBX(&((_trans).trans_tx), &((_dev).device), AC_ID, class, id, ac_id, nb_ubx_payload, ubx_payload)
/**
 * Sends a HITL_UBX message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _class 
 * @param _id 
 * @param _ac_id 
 * @param nb_ubx_payload,_ubx_payload 
 */
static inline void pprz_msg_send_HITL_UBX(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_class, uint8_t *_id, uint8_t *_ac_id, uint8_t nb_ubx_payload, uint8_t *_ubx_payload) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HITL_UBX(&msg,_class,_id,_ac_id,nb_ubx_payload,_ubx_payload);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HITL_UBX(_trans, _dev, class, id, ac_id, nb_ubx_payload, ubx_payload) {}
static inline void pprz_send_msg_HITL_UBX(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_class __attribute__((unused)), uint8_t *_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t nb_ubx_payload __attribute__((unused)), uint8_t *_ubx_payload __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field class in message HITL_UBX
  *
  * @param _payload : a pointer to the HITL_UBX message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_UBX_class(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field id in message HITL_UBX
  *
  * @param _payload : a pointer to the HITL_UBX message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_UBX_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field ac_id in message HITL_UBX
  *
  * @param _payload : a pointer to the HITL_UBX message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_HITL_UBX_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for length of array ubx_payload in message HITL_UBX
 *
 * @return ubx_payload : 
 */
 static inline uint8_t pprzlink_get_HITL_UBX_ubx_payload_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 7);
}

/** Getter for field ubx_payload in message HITL_UBX
  *
  * @param _payload : a pointer to the HITL_UBX message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_HITL_UBX_ubx_payload(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 8);
}


/* Compatibility macros */
#define DL_HITL_UBX_class(_payload) pprzlink_get_DL_HITL_UBX_class(_payload)
#define DL_HITL_UBX_id(_payload) pprzlink_get_DL_HITL_UBX_id(_payload)
#define DL_HITL_UBX_ac_id(_payload) pprzlink_get_DL_HITL_UBX_ac_id(_payload)
#define DL_HITL_UBX_ubx_payload_length(_payload) pprzlink_get_HITL_UBX_ubx_payload_length(_payload)
#define DL_HITL_UBX_ubx_payload(_payload) pprzlink_get_DL_HITL_UBX_ubx_payload(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_HITL_UBX_H_

