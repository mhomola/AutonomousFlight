/** @file
 *  @brief PPRZLink message header for EXTERNAL_MAG_RAW in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_EXTERNAL_MAG_RAW_H_
#define _VAR_MESSAGES_datalink_EXTERNAL_MAG_RAW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_EXTERNAL_MAG_RAW 154
#define PPRZ_MSG_ID_EXTERNAL_MAG_RAW 154

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_EXTERNAL_MAG_RAW _send_msg(EXTERNAL_MAG_RAW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a EXTERNAL_MAG_RAW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _x 
 * @param _y 
 * @param _z 
 */
static inline void pprzlink_msg_v2_send_EXTERNAL_MAG_RAW(struct pprzlink_msg * msg, int16_t *_x, int16_t *_y, int16_t *_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_EXTERNAL_MAG_RAW, "EXTERNAL_MAG_RAW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _y, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _z, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_EXTERNAL_MAG_RAW pprz_msg_send_EXTERNAL_MAG_RAW
#define DOWNLINK_SEND_EXTERNAL_MAG_RAW(_trans, _dev, x, y, z) pprz_msg_send_EXTERNAL_MAG_RAW(&((_trans).trans_tx), &((_dev).device), AC_ID, x, y, z)
/**
 * Sends a EXTERNAL_MAG_RAW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _x 
 * @param _y 
 * @param _z 
 */
static inline void pprz_msg_send_EXTERNAL_MAG_RAW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_x, int16_t *_y, int16_t *_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_EXTERNAL_MAG_RAW(&msg,_x,_y,_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_EXTERNAL_MAG_RAW(_trans, _dev, x, y, z) {}
static inline void pprz_send_msg_EXTERNAL_MAG_RAW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_x __attribute__((unused)), int16_t *_y __attribute__((unused)), int16_t *_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field x in message EXTERNAL_MAG_RAW
  *
  * @param _payload : a pointer to the EXTERNAL_MAG_RAW message
  * @return 
  */
static inline int16_t pprzlink_get_DL_EXTERNAL_MAG_RAW_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field y in message EXTERNAL_MAG_RAW
  *
  * @param _payload : a pointer to the EXTERNAL_MAG_RAW message
  * @return 
  */
static inline int16_t pprzlink_get_DL_EXTERNAL_MAG_RAW_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field z in message EXTERNAL_MAG_RAW
  *
  * @param _payload : a pointer to the EXTERNAL_MAG_RAW message
  * @return 
  */
static inline int16_t pprzlink_get_DL_EXTERNAL_MAG_RAW_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/* Compatibility macros */
#define DL_EXTERNAL_MAG_RAW_x(_payload) pprzlink_get_DL_EXTERNAL_MAG_RAW_x(_payload)
#define DL_EXTERNAL_MAG_RAW_y(_payload) pprzlink_get_DL_EXTERNAL_MAG_RAW_y(_payload)
#define DL_EXTERNAL_MAG_RAW_z(_payload) pprzlink_get_DL_EXTERNAL_MAG_RAW_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_EXTERNAL_MAG_RAW_H_

