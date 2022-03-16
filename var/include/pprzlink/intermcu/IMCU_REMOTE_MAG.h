/** @file
 *  @brief PPRZLink message header for IMCU_REMOTE_MAG in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_REMOTE_MAG_H_
#define _VAR_MESSAGES_intermcu_IMCU_REMOTE_MAG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_REMOTE_MAG 10
#define PPRZ_MSG_ID_IMCU_REMOTE_MAG 10

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_REMOTE_MAG _send_msg(IMCU_REMOTE_MAG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_REMOTE_MAG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _mag_x RAW Magnetometer Data
 * @param _mag_y 
 * @param _mag_z 
 */
static inline void pprzlink_msg_v2_send_IMCU_REMOTE_MAG(struct pprzlink_msg * msg, int16_t *_mag_x, int16_t *_mag_y, int16_t *_mag_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_REMOTE_MAG, "IMCU_REMOTE_MAG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mag_x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mag_y, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mag_z, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_REMOTE_MAG pprz_msg_send_IMCU_REMOTE_MAG
#define DOWNLINK_SEND_IMCU_REMOTE_MAG(_trans, _dev, mag_x, mag_y, mag_z) pprz_msg_send_IMCU_REMOTE_MAG(&((_trans).trans_tx), &((_dev).device), AC_ID, mag_x, mag_y, mag_z)
/**
 * Sends a IMCU_REMOTE_MAG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _mag_x RAW Magnetometer Data
 * @param _mag_y 
 * @param _mag_z 
 */
static inline void pprz_msg_send_IMCU_REMOTE_MAG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_mag_x, int16_t *_mag_y, int16_t *_mag_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_REMOTE_MAG(&msg,_mag_x,_mag_y,_mag_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_REMOTE_MAG(_trans, _dev, mag_x, mag_y, mag_z) {}
static inline void pprz_send_msg_IMCU_REMOTE_MAG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_mag_x __attribute__((unused)), int16_t *_mag_y __attribute__((unused)), int16_t *_mag_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field mag_x in message IMCU_REMOTE_MAG
  *
  * @param _payload : a pointer to the IMCU_REMOTE_MAG message
  * @return RAW Magnetometer Data
  */
static inline int16_t pprzlink_get_DL_IMCU_REMOTE_MAG_mag_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field mag_y in message IMCU_REMOTE_MAG
  *
  * @param _payload : a pointer to the IMCU_REMOTE_MAG message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IMCU_REMOTE_MAG_mag_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field mag_z in message IMCU_REMOTE_MAG
  *
  * @param _payload : a pointer to the IMCU_REMOTE_MAG message
  * @return 
  */
static inline int16_t pprzlink_get_DL_IMCU_REMOTE_MAG_mag_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/* Compatibility macros */
#define DL_IMCU_REMOTE_MAG_mag_x(_payload) pprzlink_get_DL_IMCU_REMOTE_MAG_mag_x(_payload)
#define DL_IMCU_REMOTE_MAG_mag_y(_payload) pprzlink_get_DL_IMCU_REMOTE_MAG_mag_y(_payload)
#define DL_IMCU_REMOTE_MAG_mag_z(_payload) pprzlink_get_DL_IMCU_REMOTE_MAG_mag_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_REMOTE_MAG_H_

