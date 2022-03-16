/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_CAM_STICK in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_ROTORCRAFT_CAM_STICK_H_
#define _VAR_MESSAGES_datalink_ROTORCRAFT_CAM_STICK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_CAM_STICK 152
#define PPRZ_MSG_ID_ROTORCRAFT_CAM_STICK 152

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_CAM_STICK _send_msg(ROTORCRAFT_CAM_STICK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_CAM_STICK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _tilt 
 * @param _pan 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_CAM_STICK(struct pprzlink_msg * msg, uint8_t *_ac_id, int8_t *_tilt, int8_t *_pan) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_CAM_STICK, "ROTORCRAFT_CAM_STICK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _tilt, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _pan, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_CAM_STICK pprz_msg_send_ROTORCRAFT_CAM_STICK
#define DOWNLINK_SEND_ROTORCRAFT_CAM_STICK(_trans, _dev, ac_id, tilt, pan) pprz_msg_send_ROTORCRAFT_CAM_STICK(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, tilt, pan)
/**
 * Sends a ROTORCRAFT_CAM_STICK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _tilt 
 * @param _pan 
 */
static inline void pprz_msg_send_ROTORCRAFT_CAM_STICK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, int8_t *_tilt, int8_t *_pan) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_CAM_STICK(&msg,_ac_id,_tilt,_pan);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_CAM_STICK(_trans, _dev, ac_id, tilt, pan) {}
static inline void pprz_send_msg_ROTORCRAFT_CAM_STICK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), int8_t *_tilt __attribute__((unused)), int8_t *_pan __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message ROTORCRAFT_CAM_STICK
  *
  * @param _payload : a pointer to the ROTORCRAFT_CAM_STICK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_CAM_STICK_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field tilt in message ROTORCRAFT_CAM_STICK
  *
  * @param _payload : a pointer to the ROTORCRAFT_CAM_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_ROTORCRAFT_CAM_STICK_tilt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 5);
}


/** Getter for field pan in message ROTORCRAFT_CAM_STICK
  *
  * @param _payload : a pointer to the ROTORCRAFT_CAM_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_ROTORCRAFT_CAM_STICK_pan(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 6);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_CAM_STICK_ac_id(_payload) pprzlink_get_DL_ROTORCRAFT_CAM_STICK_ac_id(_payload)
#define DL_ROTORCRAFT_CAM_STICK_tilt(_payload) pprzlink_get_DL_ROTORCRAFT_CAM_STICK_tilt(_payload)
#define DL_ROTORCRAFT_CAM_STICK_pan(_payload) pprzlink_get_DL_ROTORCRAFT_CAM_STICK_pan(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_ROTORCRAFT_CAM_STICK_H_

