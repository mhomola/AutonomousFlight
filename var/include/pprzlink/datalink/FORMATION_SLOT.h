/** @file
 *  @brief PPRZLink message header for FORMATION_SLOT in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_FORMATION_SLOT_H_
#define _VAR_MESSAGES_datalink_FORMATION_SLOT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_FORMATION_SLOT 9
#define PPRZ_MSG_ID_FORMATION_SLOT 9

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_FORMATION_SLOT _send_msg(FORMATION_SLOT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a FORMATION_SLOT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _mode 
 * @param _slot_east 
 * @param _slot_north 
 * @param _slot_alt 
 */
static inline void pprzlink_msg_v2_send_FORMATION_SLOT(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_mode, float *_slot_east, float *_slot_north, float *_slot_alt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_FORMATION_SLOT, "FORMATION_SLOT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _slot_east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _slot_north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _slot_alt, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_FORMATION_SLOT pprz_msg_send_FORMATION_SLOT
#define DOWNLINK_SEND_FORMATION_SLOT(_trans, _dev, ac_id, mode, slot_east, slot_north, slot_alt) pprz_msg_send_FORMATION_SLOT(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, mode, slot_east, slot_north, slot_alt)
/**
 * Sends a FORMATION_SLOT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _mode 
 * @param _slot_east 
 * @param _slot_north 
 * @param _slot_alt 
 */
static inline void pprz_msg_send_FORMATION_SLOT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_mode, float *_slot_east, float *_slot_north, float *_slot_alt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_FORMATION_SLOT(&msg,_ac_id,_mode,_slot_east,_slot_north,_slot_alt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_FORMATION_SLOT(_trans, _dev, ac_id, mode, slot_east, slot_north, slot_alt) {}
static inline void pprz_send_msg_FORMATION_SLOT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_mode __attribute__((unused)), float *_slot_east __attribute__((unused)), float *_slot_north __attribute__((unused)), float *_slot_alt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message FORMATION_SLOT
  *
  * @param _payload : a pointer to the FORMATION_SLOT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_FORMATION_SLOT_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field mode in message FORMATION_SLOT
  *
  * @param _payload : a pointer to the FORMATION_SLOT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_FORMATION_SLOT_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field slot_east in message FORMATION_SLOT
  *
  * @param _payload : a pointer to the FORMATION_SLOT message
  * @return 
  */
static inline float pprzlink_get_DL_FORMATION_SLOT_slot_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field slot_north in message FORMATION_SLOT
  *
  * @param _payload : a pointer to the FORMATION_SLOT message
  * @return 
  */
static inline float pprzlink_get_DL_FORMATION_SLOT_slot_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field slot_alt in message FORMATION_SLOT
  *
  * @param _payload : a pointer to the FORMATION_SLOT message
  * @return 
  */
static inline float pprzlink_get_DL_FORMATION_SLOT_slot_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/* Compatibility macros */
#define DL_FORMATION_SLOT_ac_id(_payload) pprzlink_get_DL_FORMATION_SLOT_ac_id(_payload)
#define DL_FORMATION_SLOT_mode(_payload) pprzlink_get_DL_FORMATION_SLOT_mode(_payload)
#define DL_FORMATION_SLOT_slot_east(_payload) pprzlink_get_DL_FORMATION_SLOT_slot_east(_payload)
#define DL_FORMATION_SLOT_slot_north(_payload) pprzlink_get_DL_FORMATION_SLOT_slot_north(_payload)
#define DL_FORMATION_SLOT_slot_alt(_payload) pprzlink_get_DL_FORMATION_SLOT_slot_alt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_FORMATION_SLOT_H_

