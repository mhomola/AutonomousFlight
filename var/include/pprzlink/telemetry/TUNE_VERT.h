/** @file
 *  @brief PPRZLink message header for TUNE_VERT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TUNE_VERT_H_
#define _VAR_MESSAGES_telemetry_TUNE_VERT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TUNE_VERT 213
#define PPRZ_MSG_ID_TUNE_VERT 213

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TUNE_VERT _send_msg(TUNE_VERT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TUNE_VERT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _z_sp 
 * @param _est_z 
 * @param _ref_z 
 * @param _ref_zd 
 */
static inline void pprzlink_msg_v2_send_TUNE_VERT(struct pprzlink_msg * msg, int32_t *_z_sp, int32_t *_est_z, int32_t *_ref_z, int32_t *_ref_zd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TUNE_VERT, "TUNE_VERT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _z_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_zd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TUNE_VERT pprz_msg_send_TUNE_VERT
#define DOWNLINK_SEND_TUNE_VERT(_trans, _dev, z_sp, est_z, ref_z, ref_zd) pprz_msg_send_TUNE_VERT(&((_trans).trans_tx), &((_dev).device), AC_ID, z_sp, est_z, ref_z, ref_zd)
/**
 * Sends a TUNE_VERT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _z_sp 
 * @param _est_z 
 * @param _ref_z 
 * @param _ref_zd 
 */
static inline void pprz_msg_send_TUNE_VERT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_z_sp, int32_t *_est_z, int32_t *_ref_z, int32_t *_ref_zd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TUNE_VERT(&msg,_z_sp,_est_z,_ref_z,_ref_zd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TUNE_VERT(_trans, _dev, z_sp, est_z, ref_z, ref_zd) {}
static inline void pprz_send_msg_TUNE_VERT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_z_sp __attribute__((unused)), int32_t *_est_z __attribute__((unused)), int32_t *_ref_z __attribute__((unused)), int32_t *_ref_zd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field z_sp in message TUNE_VERT
  *
  * @param _payload : a pointer to the TUNE_VERT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TUNE_VERT_z_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field est_z in message TUNE_VERT
  *
  * @param _payload : a pointer to the TUNE_VERT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TUNE_VERT_est_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ref_z in message TUNE_VERT
  *
  * @param _payload : a pointer to the TUNE_VERT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TUNE_VERT_ref_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field ref_zd in message TUNE_VERT
  *
  * @param _payload : a pointer to the TUNE_VERT message
  * @return 
  */
static inline int32_t pprzlink_get_DL_TUNE_VERT_ref_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/* Compatibility macros */
#define DL_TUNE_VERT_z_sp(_payload) pprzlink_get_DL_TUNE_VERT_z_sp(_payload)
#define DL_TUNE_VERT_est_z(_payload) pprzlink_get_DL_TUNE_VERT_est_z(_payload)
#define DL_TUNE_VERT_ref_z(_payload) pprzlink_get_DL_TUNE_VERT_ref_z(_payload)
#define DL_TUNE_VERT_ref_zd(_payload) pprzlink_get_DL_TUNE_VERT_ref_zd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TUNE_VERT_H_

