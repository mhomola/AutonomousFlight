/** @file
 *  @brief PPRZLink message header for IMU_GYRO_LP in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IMU_GYRO_LP_H_
#define _VAR_MESSAGES_telemetry_IMU_GYRO_LP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMU_GYRO_LP 209
#define PPRZ_MSG_ID_IMU_GYRO_LP 209

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMU_GYRO_LP _send_msg(IMU_GYRO_LP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMU_GYRO_LP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _gp 
 * @param _gq 
 * @param _gr 
 */
static inline void pprzlink_msg_v2_send_IMU_GYRO_LP(struct pprzlink_msg * msg, float *_gp, float *_gq, float *_gr) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMU_GYRO_LP, "IMU_GYRO_LP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gr, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMU_GYRO_LP pprz_msg_send_IMU_GYRO_LP
#define DOWNLINK_SEND_IMU_GYRO_LP(_trans, _dev, gp, gq, gr) pprz_msg_send_IMU_GYRO_LP(&((_trans).trans_tx), &((_dev).device), AC_ID, gp, gq, gr)
/**
 * Sends a IMU_GYRO_LP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _gp 
 * @param _gq 
 * @param _gr 
 */
static inline void pprz_msg_send_IMU_GYRO_LP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_gp, float *_gq, float *_gr) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMU_GYRO_LP(&msg,_gp,_gq,_gr);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMU_GYRO_LP(_trans, _dev, gp, gq, gr) {}
static inline void pprz_send_msg_IMU_GYRO_LP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_gp __attribute__((unused)), float *_gq __attribute__((unused)), float *_gr __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field gp in message IMU_GYRO_LP
  *
  * @param _payload : a pointer to the IMU_GYRO_LP message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_GYRO_LP_gp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field gq in message IMU_GYRO_LP
  *
  * @param _payload : a pointer to the IMU_GYRO_LP message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_GYRO_LP_gq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field gr in message IMU_GYRO_LP
  *
  * @param _payload : a pointer to the IMU_GYRO_LP message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_GYRO_LP_gr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_IMU_GYRO_LP_gp(_payload) pprzlink_get_DL_IMU_GYRO_LP_gp(_payload)
#define DL_IMU_GYRO_LP_gq(_payload) pprzlink_get_DL_IMU_GYRO_LP_gq(_payload)
#define DL_IMU_GYRO_LP_gr(_payload) pprzlink_get_DL_IMU_GYRO_LP_gr(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IMU_GYRO_LP_H_

