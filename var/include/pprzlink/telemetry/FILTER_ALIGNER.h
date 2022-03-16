/** @file
 *  @brief PPRZLink message header for FILTER_ALIGNER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_FILTER_ALIGNER_H_
#define _VAR_MESSAGES_telemetry_FILTER_ALIGNER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_FILTER_ALIGNER 137
#define PPRZ_MSG_ID_FILTER_ALIGNER 137

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_FILTER_ALIGNER _send_msg(FILTER_ALIGNER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a FILTER_ALIGNER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lp_gp 
 * @param _lp_gq 
 * @param _lp_gr 
 * @param _gp 
 * @param _gq 
 * @param _gr 
 * @param _noise 
 * @param _cnt 
 * @param _status 
 */
static inline void pprzlink_msg_v2_send_FILTER_ALIGNER(struct pprzlink_msg * msg, int32_t *_lp_gp, int32_t *_lp_gq, int32_t *_lp_gr, int32_t *_gp, int32_t *_gq, int32_t *_gr, int32_t *_noise, int32_t *_cnt, uint8_t *_status) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_FILTER_ALIGNER, "FILTER_ALIGNER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lp_gp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lp_gq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lp_gr, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _gr, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _noise, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _cnt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_FILTER_ALIGNER pprz_msg_send_FILTER_ALIGNER
#define DOWNLINK_SEND_FILTER_ALIGNER(_trans, _dev, lp_gp, lp_gq, lp_gr, gp, gq, gr, noise, cnt, status) pprz_msg_send_FILTER_ALIGNER(&((_trans).trans_tx), &((_dev).device), AC_ID, lp_gp, lp_gq, lp_gr, gp, gq, gr, noise, cnt, status)
/**
 * Sends a FILTER_ALIGNER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lp_gp 
 * @param _lp_gq 
 * @param _lp_gr 
 * @param _gp 
 * @param _gq 
 * @param _gr 
 * @param _noise 
 * @param _cnt 
 * @param _status 
 */
static inline void pprz_msg_send_FILTER_ALIGNER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_lp_gp, int32_t *_lp_gq, int32_t *_lp_gr, int32_t *_gp, int32_t *_gq, int32_t *_gr, int32_t *_noise, int32_t *_cnt, uint8_t *_status) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_FILTER_ALIGNER(&msg,_lp_gp,_lp_gq,_lp_gr,_gp,_gq,_gr,_noise,_cnt,_status);
}


#else // DOWNLINK

#define DOWNLINK_SEND_FILTER_ALIGNER(_trans, _dev, lp_gp, lp_gq, lp_gr, gp, gq, gr, noise, cnt, status) {}
static inline void pprz_send_msg_FILTER_ALIGNER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_lp_gp __attribute__((unused)), int32_t *_lp_gq __attribute__((unused)), int32_t *_lp_gr __attribute__((unused)), int32_t *_gp __attribute__((unused)), int32_t *_gq __attribute__((unused)), int32_t *_gr __attribute__((unused)), int32_t *_noise __attribute__((unused)), int32_t *_cnt __attribute__((unused)), uint8_t *_status __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lp_gp in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_lp_gp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field lp_gq in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_lp_gq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field lp_gr in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_lp_gr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field gp in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_gp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field gq in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_gq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field gr in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_gr(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field noise in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_noise(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field cnt in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_ALIGNER_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field status in message FILTER_ALIGNER
  *
  * @param _payload : a pointer to the FILTER_ALIGNER message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_FILTER_ALIGNER_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 36);
}


/* Compatibility macros */
#define DL_FILTER_ALIGNER_lp_gp(_payload) pprzlink_get_DL_FILTER_ALIGNER_lp_gp(_payload)
#define DL_FILTER_ALIGNER_lp_gq(_payload) pprzlink_get_DL_FILTER_ALIGNER_lp_gq(_payload)
#define DL_FILTER_ALIGNER_lp_gr(_payload) pprzlink_get_DL_FILTER_ALIGNER_lp_gr(_payload)
#define DL_FILTER_ALIGNER_gp(_payload) pprzlink_get_DL_FILTER_ALIGNER_gp(_payload)
#define DL_FILTER_ALIGNER_gq(_payload) pprzlink_get_DL_FILTER_ALIGNER_gq(_payload)
#define DL_FILTER_ALIGNER_gr(_payload) pprzlink_get_DL_FILTER_ALIGNER_gr(_payload)
#define DL_FILTER_ALIGNER_noise(_payload) pprzlink_get_DL_FILTER_ALIGNER_noise(_payload)
#define DL_FILTER_ALIGNER_cnt(_payload) pprzlink_get_DL_FILTER_ALIGNER_cnt(_payload)
#define DL_FILTER_ALIGNER_status(_payload) pprzlink_get_DL_FILTER_ALIGNER_status(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_FILTER_ALIGNER_H_

