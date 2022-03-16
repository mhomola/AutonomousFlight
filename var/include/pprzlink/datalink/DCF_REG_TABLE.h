/** @file
 *  @brief PPRZLink message header for DCF_REG_TABLE in class datalink
 *
 *  Init the table of an aircraft for the Distributed Circular Formation algorithm. If the nei_id is equal to zero, then you wipe out (clean) the whole table of the aircraft.
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_DCF_REG_TABLE_H_
#define _VAR_MESSAGES_datalink_DCF_REG_TABLE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DCF_REG_TABLE 158
#define PPRZ_MSG_ID_DCF_REG_TABLE 158

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DCF_REG_TABLE _send_msg(DCF_REG_TABLE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DCF_REG_TABLE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id ID of the table's aircraft to be updated
 * @param _nei_id ID of the neighbor for the table
 * @param _desired_sigma Desired angle to have w.r.t. the neighbor
 */
static inline void pprzlink_msg_v2_send_DCF_REG_TABLE(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_nei_id, int16_t *_desired_sigma) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DCF_REG_TABLE, "DCF_REG_TABLE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nei_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _desired_sigma, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DCF_REG_TABLE pprz_msg_send_DCF_REG_TABLE
#define DOWNLINK_SEND_DCF_REG_TABLE(_trans, _dev, ac_id, nei_id, desired_sigma) pprz_msg_send_DCF_REG_TABLE(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, nei_id, desired_sigma)
/**
 * Sends a DCF_REG_TABLE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id ID of the table's aircraft to be updated
 * @param _nei_id ID of the neighbor for the table
 * @param _desired_sigma Desired angle to have w.r.t. the neighbor
 */
static inline void pprz_msg_send_DCF_REG_TABLE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_nei_id, int16_t *_desired_sigma) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DCF_REG_TABLE(&msg,_ac_id,_nei_id,_desired_sigma);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DCF_REG_TABLE(_trans, _dev, ac_id, nei_id, desired_sigma) {}
static inline void pprz_send_msg_DCF_REG_TABLE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_nei_id __attribute__((unused)), int16_t *_desired_sigma __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message DCF_REG_TABLE
  *
  * @param _payload : a pointer to the DCF_REG_TABLE message
  * @return ID of the table's aircraft to be updated
  */
static inline uint8_t pprzlink_get_DL_DCF_REG_TABLE_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field nei_id in message DCF_REG_TABLE
  *
  * @param _payload : a pointer to the DCF_REG_TABLE message
  * @return ID of the neighbor for the table
  */
static inline uint8_t pprzlink_get_DL_DCF_REG_TABLE_nei_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field desired_sigma in message DCF_REG_TABLE
  *
  * @param _payload : a pointer to the DCF_REG_TABLE message
  * @return Desired angle to have w.r.t. the neighbor
  */
static inline int16_t pprzlink_get_DL_DCF_REG_TABLE_desired_sigma(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/* Compatibility macros */
#define DL_DCF_REG_TABLE_ac_id(_payload) pprzlink_get_DL_DCF_REG_TABLE_ac_id(_payload)
#define DL_DCF_REG_TABLE_nei_id(_payload) pprzlink_get_DL_DCF_REG_TABLE_nei_id(_payload)
#define DL_DCF_REG_TABLE_desired_sigma(_payload) pprzlink_get_DL_DCF_REG_TABLE_desired_sigma(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_DCF_REG_TABLE_H_

