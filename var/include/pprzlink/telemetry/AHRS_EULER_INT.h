/** @file
 *  @brief PPRZLink message header for AHRS_EULER_INT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AHRS_EULER_INT_H_
#define _VAR_MESSAGES_telemetry_AHRS_EULER_INT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AHRS_EULER_INT 156
#define PPRZ_MSG_ID_AHRS_EULER_INT 156

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AHRS_EULER_INT _send_msg(AHRS_EULER_INT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AHRS_EULER_INT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _imu_phi 
 * @param _imu_theta 
 * @param _imu_psi 
 * @param _body_phi 
 * @param _body_theta 
 * @param _body_psi 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_AHRS_EULER_INT(struct pprzlink_msg * msg, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AHRS_EULER_INT, "AHRS_EULER_INT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _imu_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _body_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AHRS_EULER_INT pprz_msg_send_AHRS_EULER_INT
#define DOWNLINK_SEND_AHRS_EULER_INT(_trans, _dev, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi, comp_id) pprz_msg_send_AHRS_EULER_INT(&((_trans).trans_tx), &((_dev).device), AC_ID, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi, comp_id)
/**
 * Sends a AHRS_EULER_INT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _imu_phi 
 * @param _imu_theta 
 * @param _imu_psi 
 * @param _body_phi 
 * @param _body_theta 
 * @param _body_psi 
 * @param _comp_id 
 */
static inline void pprz_msg_send_AHRS_EULER_INT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AHRS_EULER_INT(&msg,_imu_phi,_imu_theta,_imu_psi,_body_phi,_body_theta,_body_psi,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AHRS_EULER_INT(_trans, _dev, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi, comp_id) {}
static inline void pprz_send_msg_AHRS_EULER_INT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_imu_phi __attribute__((unused)), int32_t *_imu_theta __attribute__((unused)), int32_t *_imu_psi __attribute__((unused)), int32_t *_body_phi __attribute__((unused)), int32_t *_body_theta __attribute__((unused)), int32_t *_body_psi __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field imu_phi in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_imu_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field imu_theta in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_imu_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field imu_psi in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_imu_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field body_phi in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_body_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field body_theta in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_body_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field body_psi in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_AHRS_EULER_INT_body_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field comp_id in message AHRS_EULER_INT
  *
  * @param _payload : a pointer to the AHRS_EULER_INT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_AHRS_EULER_INT_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 28);
}


/* Compatibility macros */
#define DL_AHRS_EULER_INT_imu_phi(_payload) pprzlink_get_DL_AHRS_EULER_INT_imu_phi(_payload)
#define DL_AHRS_EULER_INT_imu_theta(_payload) pprzlink_get_DL_AHRS_EULER_INT_imu_theta(_payload)
#define DL_AHRS_EULER_INT_imu_psi(_payload) pprzlink_get_DL_AHRS_EULER_INT_imu_psi(_payload)
#define DL_AHRS_EULER_INT_body_phi(_payload) pprzlink_get_DL_AHRS_EULER_INT_body_phi(_payload)
#define DL_AHRS_EULER_INT_body_theta(_payload) pprzlink_get_DL_AHRS_EULER_INT_body_theta(_payload)
#define DL_AHRS_EULER_INT_body_psi(_payload) pprzlink_get_DL_AHRS_EULER_INT_body_psi(_payload)
#define DL_AHRS_EULER_INT_comp_id(_payload) pprzlink_get_DL_AHRS_EULER_INT_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AHRS_EULER_INT_H_

