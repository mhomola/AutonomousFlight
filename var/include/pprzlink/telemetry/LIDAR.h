/** @file
 *  @brief PPRZLink message header for LIDAR in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_LIDAR_H_
#define _VAR_MESSAGES_telemetry_LIDAR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_LIDAR 234
#define PPRZ_MSG_ID_LIDAR 234

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_LIDAR _send_msg(LIDAR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a LIDAR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _distance 
 * @param _status 
 * @param _trans_status 
 */
static inline void pprzlink_msg_v2_send_LIDAR(struct pprzlink_msg * msg, float *_distance, uint8_t *_status, uint8_t *_trans_status) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_LIDAR, "LIDAR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _distance, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _trans_status, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_LIDAR pprz_msg_send_LIDAR
#define DOWNLINK_SEND_LIDAR(_trans, _dev, distance, status, trans_status) pprz_msg_send_LIDAR(&((_trans).trans_tx), &((_dev).device), AC_ID, distance, status, trans_status)
/**
 * Sends a LIDAR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _distance 
 * @param _status 
 * @param _trans_status 
 */
static inline void pprz_msg_send_LIDAR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_distance, uint8_t *_status, uint8_t *_trans_status) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_LIDAR(&msg,_distance,_status,_trans_status);
}


#else // DOWNLINK

#define DOWNLINK_SEND_LIDAR(_trans, _dev, distance, status, trans_status) {}
static inline void pprz_send_msg_LIDAR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_distance __attribute__((unused)), uint8_t *_status __attribute__((unused)), uint8_t *_trans_status __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field distance in message LIDAR
  *
  * @param _payload : a pointer to the LIDAR message
  * @return 
  */
static inline float pprzlink_get_DL_LIDAR_distance(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field status in message LIDAR
  *
  * @param _payload : a pointer to the LIDAR message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_LIDAR_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field trans_status in message LIDAR
  *
  * @param _payload : a pointer to the LIDAR message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_LIDAR_trans_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 9);
}


/* Compatibility macros */
#define DL_LIDAR_distance(_payload) pprzlink_get_DL_LIDAR_distance(_payload)
#define DL_LIDAR_status(_payload) pprzlink_get_DL_LIDAR_status(_payload)
#define DL_LIDAR_trans_status(_payload) pprzlink_get_DL_LIDAR_trans_status(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_LIDAR_H_

