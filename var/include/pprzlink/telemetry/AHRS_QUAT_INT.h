/** @file
 *  @brief PPRZLink message header for AHRS_QUAT_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AHRS_QUAT_INT_H_
#define _VAR_MESSAGES_telemetry_AHRS_QUAT_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AHRS_QUAT_INT 157
#define PPRZ_MSG_ID_AHRS_QUAT_INT 157

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AHRS_QUAT_INT _send_msg(AHRS_QUAT_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AHRS_QUAT_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _weight 
 * @param _imu_qi 
 * @param _imu_qx 
 * @param _imu_qy 
 * @param _imu_qz 
 * @param _body_qi 
 * @param _body_qx 
 * @param _body_qy 
 * @param _body_qz 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_AHRS_QUAT_INT(struct pprzlink_msg * msg, float *_weight, int32_t *_imu_qi, int32_t *_imu_qx, int32_t *_imu_qy, int32_t *_imu_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AHRS_QUAT_INT, "AHRS_QUAT_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _weight, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_qi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_qx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_qy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_qz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_qi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_qx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_qy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_qz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AHRS_QUAT_INT pprz_msg_send_AHRS_QUAT_INT
#define DOWNLINK_SEND_AHRS_QUAT_INT(_trans, _dev, weight, imu_qi, imu_qx, imu_qy, imu_qz, body_qi, body_qx, body_qy, body_qz, comp_id) pprz_msg_send_AHRS_QUAT_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, weight, imu_qi, imu_qx, imu_qy, imu_qz, body_qi, body_qx, body_qy, body_qz, comp_id)
/**
 * Sends a AHRS_QUAT_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _weight 
 * @param _imu_qi 
 * @param _imu_qx 
 * @param _imu_qy 
 * @param _imu_qz 
 * @param _body_qi 
 * @param _body_qx 
 * @param _body_qy 
 * @param _body_qz 
 * @param _comp_id 
 */
static inline void pprz_msg_send_AHRS_QUAT_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_weight, int32_t *_imu_qi, int32_t *_imu_qx, int32_t *_imu_qy, int32_t *_imu_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AHRS_QUAT_INT(&msg,_weight,_imu_qi,_imu_qx,_imu_qy,_imu_qz,_body_qi,_body_qx,_body_qy,_body_qz,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AHRS_QUAT_INT(_trans, _dev, weight, imu_qi, imu_qx, imu_qy, imu_qz, body_qi, body_qx, body_qy, body_qz, comp_id) {}
static inline void pprz_send_msg_AHRS_QUAT_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_weight __attribute__((unused)), int32_t *_imu_qi __attribute__((unused)), int32_t *_imu_qx __attribute__((unused)), int32_t *_imu_qy __attribute__((unused)), int32_t *_imu_qz __attribute__((unused)), int32_t *_body_qi __attribute__((unused)), int32_t *_body_qx __attribute__((unused)), int32_t *_body_qy __attribute__((unused)), int32_t *_body_qz __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field weight in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline float pprzlink_get_DL_AHRS_QUAT_INT_weight(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field imu_qi in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_imu_qi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field imu_qx in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_imu_qx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field imu_qy in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_imu_qy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field imu_qz in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_imu_qz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field body_qi in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_body_qi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field body_qx in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_body_qx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field body_qy in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_body_qy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field body_qz in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_QUAT_INT_body_qz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field comp_id in message AHRS_QUAT_INT
  *
  * @param _payload : a pointer to the AHRS_QUAT_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_AHRS_QUAT_INT_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 40);
}


/* Compatibility macros */
#define DL_AHRS_QUAT_INT_weight(_payload) pprzlink_get_DL_AHRS_QUAT_INT_weight(_payload)
#define DL_AHRS_QUAT_INT_imu_qi(_payload) pprzlink_get_DL_AHRS_QUAT_INT_imu_qi(_payload)
#define DL_AHRS_QUAT_INT_imu_qx(_payload) pprzlink_get_DL_AHRS_QUAT_INT_imu_qx(_payload)
#define DL_AHRS_QUAT_INT_imu_qy(_payload) pprzlink_get_DL_AHRS_QUAT_INT_imu_qy(_payload)
#define DL_AHRS_QUAT_INT_imu_qz(_payload) pprzlink_get_DL_AHRS_QUAT_INT_imu_qz(_payload)
#define DL_AHRS_QUAT_INT_body_qi(_payload) pprzlink_get_DL_AHRS_QUAT_INT_body_qi(_payload)
#define DL_AHRS_QUAT_INT_body_qx(_payload) pprzlink_get_DL_AHRS_QUAT_INT_body_qx(_payload)
#define DL_AHRS_QUAT_INT_body_qy(_payload) pprzlink_get_DL_AHRS_QUAT_INT_body_qy(_payload)
#define DL_AHRS_QUAT_INT_body_qz(_payload) pprzlink_get_DL_AHRS_QUAT_INT_body_qz(_payload)
#define DL_AHRS_QUAT_INT_comp_id(_payload) pprzlink_get_DL_AHRS_QUAT_INT_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AHRS_QUAT_INT_H_

