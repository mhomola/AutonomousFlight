/** @file
 *  @brief PPRZLink message header for SET_ACTUATOR in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_SET_ACTUATOR_H_
#define _VAR_MESSAGES_datalink_SET_ACTUATOR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SET_ACTUATOR 100
#define PPRZ_MSG_ID_SET_ACTUATOR 100

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SET_ACTUATOR _send_msg(SET_ACTUATOR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SET_ACTUATOR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _value 
 * @param _no 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_SET_ACTUATOR(struct pprzlink_msg * msg, uint16_t *_value, uint8_t *_no, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SET_ACTUATOR, "SET_ACTUATOR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _value, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _no, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SET_ACTUATOR pprz_msg_send_SET_ACTUATOR
#define DOWNLINK_SEND_SET_ACTUATOR(_trans, _dev, value, no, ac_id) pprz_msg_send_SET_ACTUATOR(&((_trans).trans_tx), &((_dev).device), AC_ID, value, no, ac_id)
/**
 * Sends a SET_ACTUATOR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _value 
 * @param _no 
 * @param _ac_id 
 */
static inline void pprz_msg_send_SET_ACTUATOR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_value, uint8_t *_no, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SET_ACTUATOR(&msg,_value,_no,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SET_ACTUATOR(_trans, _dev, value, no, ac_id) {}
static inline void pprz_send_msg_SET_ACTUATOR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_value __attribute__((unused)), uint8_t *_no __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field value in message SET_ACTUATOR
  *
  * @param _payload : a pointer to the SET_ACTUATOR message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_SET_ACTUATOR_value(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field no in message SET_ACTUATOR
  *
  * @param _payload : a pointer to the SET_ACTUATOR message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SET_ACTUATOR_no(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field ac_id in message SET_ACTUATOR
  *
  * @param _payload : a pointer to the SET_ACTUATOR message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SET_ACTUATOR_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/* Compatibility macros */
#define DL_SET_ACTUATOR_value(_payload) pprzlink_get_DL_SET_ACTUATOR_value(_payload)
#define DL_SET_ACTUATOR_no(_payload) pprzlink_get_DL_SET_ACTUATOR_no(_payload)
#define DL_SET_ACTUATOR_ac_id(_payload) pprzlink_get_DL_SET_ACTUATOR_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_SET_ACTUATOR_H_

