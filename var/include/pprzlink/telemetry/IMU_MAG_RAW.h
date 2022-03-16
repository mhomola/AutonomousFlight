/** @file
 *  @brief PPRZLink message header for IMU_MAG_RAW in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IMU_MAG_RAW_H_
#define _VAR_MESSAGES_telemetry_IMU_MAG_RAW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMU_MAG_RAW 205
#define PPRZ_MSG_ID_IMU_MAG_RAW 205

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMU_MAG_RAW _send_msg(IMU_MAG_RAW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMU_MAG_RAW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _mx 
 * @param _my 
 * @param _mz 
 */
static inline void pprzlink_msg_v2_send_IMU_MAG_RAW(struct pprzlink_msg * msg, int32_t *_mx, int32_t *_my, int32_t *_mz) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMU_MAG_RAW, "IMU_MAG_RAW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _mx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _my, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _mz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMU_MAG_RAW pprz_msg_send_IMU_MAG_RAW
#define DOWNLINK_SEND_IMU_MAG_RAW(_trans, _dev, mx, my, mz) pprz_msg_send_IMU_MAG_RAW(&((_trans).trans_tx), &((_dev).device), AC_ID, mx, my, mz)
/**
 * Sends a IMU_MAG_RAW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _mx 
 * @param _my 
 * @param _mz 
 */
static inline void pprz_msg_send_IMU_MAG_RAW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_mx, int32_t *_my, int32_t *_mz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMU_MAG_RAW(&msg,_mx,_my,_mz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMU_MAG_RAW(_trans, _dev, mx, my, mz) {}
static inline void pprz_send_msg_IMU_MAG_RAW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_mx __attribute__((unused)), int32_t *_my __attribute__((unused)), int32_t *_mz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field mx in message IMU_MAG_RAW
  *
  * @param _payload : a pointer to the IMU_MAG_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_MAG_RAW_mx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field my in message IMU_MAG_RAW
  *
  * @param _payload : a pointer to the IMU_MAG_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_MAG_RAW_my(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field mz in message IMU_MAG_RAW
  *
  * @param _payload : a pointer to the IMU_MAG_RAW message
  * @return 
  */
static inline int32_t pprzlink_get_DL_IMU_MAG_RAW_mz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/* Compatibility macros */
#define DL_IMU_MAG_RAW_mx(_payload) pprzlink_get_DL_IMU_MAG_RAW_mx(_payload)
#define DL_IMU_MAG_RAW_my(_payload) pprzlink_get_DL_IMU_MAG_RAW_my(_payload)
#define DL_IMU_MAG_RAW_mz(_payload) pprzlink_get_DL_IMU_MAG_RAW_mz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IMU_MAG_RAW_H_

