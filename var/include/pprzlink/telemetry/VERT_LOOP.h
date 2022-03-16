/** @file
 *  @brief PPRZLink message header for VERT_LOOP in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VERT_LOOP_H_
#define _VAR_MESSAGES_telemetry_VERT_LOOP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VERT_LOOP 145
#define PPRZ_MSG_ID_VERT_LOOP 145

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VERT_LOOP _send_msg(VERT_LOOP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VERT_LOOP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _z_sp 
 * @param _zd_sp 
 * @param _est_z 
 * @param _est_zd 
 * @param _est_zdd 
 * @param _ref_z 
 * @param _ref_zd 
 * @param _ref_zdd 
 * @param _adp_inv_m 
 * @param _adp_cov 
 * @param _adp_meas 
 * @param _sum_err 
 * @param _ff_cmd 
 * @param _fb_cmd 
 * @param _delta_t 
 */
static inline void pprzlink_msg_v2_send_VERT_LOOP(struct pprzlink_msg * msg, int32_t *_z_sp, int32_t *_zd_sp, int32_t *_est_z, int32_t *_est_zd, int32_t *_est_zdd, int32_t *_ref_z, int32_t *_ref_zd, int32_t *_ref_zdd, int32_t *_adp_inv_m, int32_t *_adp_cov, int32_t *_adp_meas, int32_t *_sum_err, int32_t *_ff_cmd, int32_t *_fb_cmd, int32_t *_delta_t) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VERT_LOOP, "VERT_LOOP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _z_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _zd_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _est_zdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ref_zdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _adp_inv_m, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _adp_cov, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _adp_meas, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ff_cmd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _fb_cmd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _delta_t, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VERT_LOOP pprz_msg_send_VERT_LOOP
#define DOWNLINK_SEND_VERT_LOOP(_trans, _dev, z_sp, zd_sp, est_z, est_zd, est_zdd, ref_z, ref_zd, ref_zdd, adp_inv_m, adp_cov, adp_meas, sum_err, ff_cmd, fb_cmd, delta_t) pprz_msg_send_VERT_LOOP(&((_trans).trans_tx), &((_dev).device), AC_ID, z_sp, zd_sp, est_z, est_zd, est_zdd, ref_z, ref_zd, ref_zdd, adp_inv_m, adp_cov, adp_meas, sum_err, ff_cmd, fb_cmd, delta_t)
/**
 * Sends a VERT_LOOP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _z_sp 
 * @param _zd_sp 
 * @param _est_z 
 * @param _est_zd 
 * @param _est_zdd 
 * @param _ref_z 
 * @param _ref_zd 
 * @param _ref_zdd 
 * @param _adp_inv_m 
 * @param _adp_cov 
 * @param _adp_meas 
 * @param _sum_err 
 * @param _ff_cmd 
 * @param _fb_cmd 
 * @param _delta_t 
 */
static inline void pprz_msg_send_VERT_LOOP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_z_sp, int32_t *_zd_sp, int32_t *_est_z, int32_t *_est_zd, int32_t *_est_zdd, int32_t *_ref_z, int32_t *_ref_zd, int32_t *_ref_zdd, int32_t *_adp_inv_m, int32_t *_adp_cov, int32_t *_adp_meas, int32_t *_sum_err, int32_t *_ff_cmd, int32_t *_fb_cmd, int32_t *_delta_t) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VERT_LOOP(&msg,_z_sp,_zd_sp,_est_z,_est_zd,_est_zdd,_ref_z,_ref_zd,_ref_zdd,_adp_inv_m,_adp_cov,_adp_meas,_sum_err,_ff_cmd,_fb_cmd,_delta_t);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VERT_LOOP(_trans, _dev, z_sp, zd_sp, est_z, est_zd, est_zdd, ref_z, ref_zd, ref_zdd, adp_inv_m, adp_cov, adp_meas, sum_err, ff_cmd, fb_cmd, delta_t) {}
static inline void pprz_send_msg_VERT_LOOP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_z_sp __attribute__((unused)), int32_t *_zd_sp __attribute__((unused)), int32_t *_est_z __attribute__((unused)), int32_t *_est_zd __attribute__((unused)), int32_t *_est_zdd __attribute__((unused)), int32_t *_ref_z __attribute__((unused)), int32_t *_ref_zd __attribute__((unused)), int32_t *_ref_zdd __attribute__((unused)), int32_t *_adp_inv_m __attribute__((unused)), int32_t *_adp_cov __attribute__((unused)), int32_t *_adp_meas __attribute__((unused)), int32_t *_sum_err __attribute__((unused)), int32_t *_ff_cmd __attribute__((unused)), int32_t *_fb_cmd __attribute__((unused)), int32_t *_delta_t __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field z_sp in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_z_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field zd_sp in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_zd_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field est_z in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_est_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field est_zd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_est_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field est_zdd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_est_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field ref_z in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_ref_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field ref_zd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_ref_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field ref_zdd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_ref_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field adp_inv_m in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_adp_inv_m(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field adp_cov in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_adp_cov(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field adp_meas in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_adp_meas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field sum_err in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field ff_cmd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_ff_cmd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field fb_cmd in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_fb_cmd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field delta_t in message VERT_LOOP
  *
  * @param _payload : a pointer to the VERT_LOOP message
  * @return 
  */
static inline int32_t pprzlink_get_DL_VERT_LOOP_delta_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 60);
}


/* Compatibility macros */
#define DL_VERT_LOOP_z_sp(_payload) pprzlink_get_DL_VERT_LOOP_z_sp(_payload)
#define DL_VERT_LOOP_zd_sp(_payload) pprzlink_get_DL_VERT_LOOP_zd_sp(_payload)
#define DL_VERT_LOOP_est_z(_payload) pprzlink_get_DL_VERT_LOOP_est_z(_payload)
#define DL_VERT_LOOP_est_zd(_payload) pprzlink_get_DL_VERT_LOOP_est_zd(_payload)
#define DL_VERT_LOOP_est_zdd(_payload) pprzlink_get_DL_VERT_LOOP_est_zdd(_payload)
#define DL_VERT_LOOP_ref_z(_payload) pprzlink_get_DL_VERT_LOOP_ref_z(_payload)
#define DL_VERT_LOOP_ref_zd(_payload) pprzlink_get_DL_VERT_LOOP_ref_zd(_payload)
#define DL_VERT_LOOP_ref_zdd(_payload) pprzlink_get_DL_VERT_LOOP_ref_zdd(_payload)
#define DL_VERT_LOOP_adp_inv_m(_payload) pprzlink_get_DL_VERT_LOOP_adp_inv_m(_payload)
#define DL_VERT_LOOP_adp_cov(_payload) pprzlink_get_DL_VERT_LOOP_adp_cov(_payload)
#define DL_VERT_LOOP_adp_meas(_payload) pprzlink_get_DL_VERT_LOOP_adp_meas(_payload)
#define DL_VERT_LOOP_sum_err(_payload) pprzlink_get_DL_VERT_LOOP_sum_err(_payload)
#define DL_VERT_LOOP_ff_cmd(_payload) pprzlink_get_DL_VERT_LOOP_ff_cmd(_payload)
#define DL_VERT_LOOP_fb_cmd(_payload) pprzlink_get_DL_VERT_LOOP_fb_cmd(_payload)
#define DL_VERT_LOOP_delta_t(_payload) pprzlink_get_DL_VERT_LOOP_delta_t(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VERT_LOOP_H_

