/** @file
 *  @brief PPRZLink message header for CAM_POINT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CAM_POINT_H_
#define _VAR_MESSAGES_telemetry_CAM_POINT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CAM_POINT 63
#define PPRZ_MSG_ID_CAM_POINT 63

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CAM_POINT _send_msg(CAM_POINT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CAM_POINT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _cam_point_distance_from_home 
 * @param _cam_point_lat 
 * @param _cam_point_lon 
 */
static inline void pprzlink_msg_v2_send_CAM_POINT(struct pprzlink_msg * msg, uint16_t *_cam_point_distance_from_home, float *_cam_point_lat, float *_cam_point_lon) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CAM_POINT, "CAM_POINT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _cam_point_distance_from_home, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cam_point_lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cam_point_lon, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CAM_POINT pprz_msg_send_CAM_POINT
#define DOWNLINK_SEND_CAM_POINT(_trans, _dev, cam_point_distance_from_home, cam_point_lat, cam_point_lon) pprz_msg_send_CAM_POINT(&((_trans).trans_tx), &((_dev).device), AC_ID, cam_point_distance_from_home, cam_point_lat, cam_point_lon)
/**
 * Sends a CAM_POINT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _cam_point_distance_from_home 
 * @param _cam_point_lat 
 * @param _cam_point_lon 
 */
static inline void pprz_msg_send_CAM_POINT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_cam_point_distance_from_home, float *_cam_point_lat, float *_cam_point_lon) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CAM_POINT(&msg,_cam_point_distance_from_home,_cam_point_lat,_cam_point_lon);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CAM_POINT(_trans, _dev, cam_point_distance_from_home, cam_point_lat, cam_point_lon) {}
static inline void pprz_send_msg_CAM_POINT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_cam_point_distance_from_home __attribute__((unused)), float *_cam_point_lat __attribute__((unused)), float *_cam_point_lon __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field cam_point_distance_from_home in message CAM_POINT
  *
  * @param _payload : a pointer to the CAM_POINT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_CAM_POINT_cam_point_distance_from_home(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field cam_point_lat in message CAM_POINT
  *
  * @param _payload : a pointer to the CAM_POINT message
  * @return 
  */
static inline float pprzlink_get_DL_CAM_POINT_cam_point_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field cam_point_lon in message CAM_POINT
  *
  * @param _payload : a pointer to the CAM_POINT message
  * @return 
  */
static inline float pprzlink_get_DL_CAM_POINT_cam_point_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/* Compatibility macros */
#define DL_CAM_POINT_cam_point_distance_from_home(_payload) pprzlink_get_DL_CAM_POINT_cam_point_distance_from_home(_payload)
#define DL_CAM_POINT_cam_point_lat(_payload) pprzlink_get_DL_CAM_POINT_cam_point_lat(_payload)
#define DL_CAM_POINT_cam_point_lon(_payload) pprzlink_get_DL_CAM_POINT_cam_point_lon(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CAM_POINT_H_

