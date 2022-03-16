/** @file
 *  @brief PPRZLink message header for CAM in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CAM_H_
#define _VAR_MESSAGES_telemetry_CAM_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CAM 20
#define PPRZ_MSG_ID_CAM 20

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CAM _send_msg(CAM,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CAM message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pan 
 * @param _tilt 
 * @param _target_x 
 * @param _target_y 
 */
static inline void pprzlink_msg_v2_send_CAM(struct pprzlink_msg * msg, int16_t *_pan, int16_t *_tilt, int16_t *_target_x, int16_t *_target_y) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CAM, "CAM");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _pan, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _tilt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _target_x, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _target_y, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CAM pprz_msg_send_CAM
#define DOWNLINK_SEND_CAM(_trans, _dev, pan, tilt, target_x, target_y) pprz_msg_send_CAM(&((_trans).trans_tx), &((_dev).device), AC_ID, pan, tilt, target_x, target_y)
/**
 * Sends a CAM message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pan 
 * @param _tilt 
 * @param _target_x 
 * @param _target_y 
 */
static inline void pprz_msg_send_CAM(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_pan, int16_t *_tilt, int16_t *_target_x, int16_t *_target_y) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CAM(&msg,_pan,_tilt,_target_x,_target_y);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CAM(_trans, _dev, pan, tilt, target_x, target_y) {}
static inline void pprz_send_msg_CAM(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_pan __attribute__((unused)), int16_t *_tilt __attribute__((unused)), int16_t *_target_x __attribute__((unused)), int16_t *_target_y __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pan in message CAM
  *
  * @param _payload : a pointer to the CAM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_CAM_pan(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field tilt in message CAM
  *
  * @param _payload : a pointer to the CAM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_CAM_tilt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field target_x in message CAM
  *
  * @param _payload : a pointer to the CAM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_CAM_target_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/** Getter for field target_y in message CAM
  *
  * @param _payload : a pointer to the CAM message
  * @return 
  */
static inline int16_t pprzlink_get_DL_CAM_target_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/* Compatibility macros */
#define DL_CAM_pan(_payload) pprzlink_get_DL_CAM_pan(_payload)
#define DL_CAM_tilt(_payload) pprzlink_get_DL_CAM_tilt(_payload)
#define DL_CAM_target_x(_payload) pprzlink_get_DL_CAM_target_x(_payload)
#define DL_CAM_target_y(_payload) pprzlink_get_DL_CAM_target_y(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CAM_H_

