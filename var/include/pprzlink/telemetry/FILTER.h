/** @file
 *  @brief PPRZLink message header for FILTER in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_FILTER_H_
#define _VAR_MESSAGES_telemetry_FILTER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_FILTER 134
#define PPRZ_MSG_ID_FILTER 134

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_FILTER _send_msg(FILTER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a FILTER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _measure_phi 
 * @param _measure_theta 
 * @param _measure_psi 
 * @param _corrected_phi 
 * @param _corrected_theta 
 * @param _corrected_psi 
 * @param _correction_phi 
 * @param _correction_theta 
 * @param _correction_psi 
 * @param _bp 
 * @param _bq 
 * @param _br 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_FILTER(struct pprzlink_msg * msg, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_measure_phi, int32_t *_measure_theta, int32_t *_measure_psi, int32_t *_corrected_phi, int32_t *_corrected_theta, int32_t *_corrected_psi, int32_t *_correction_phi, int32_t *_correction_theta, int32_t *_correction_psi, int32_t *_bp, int32_t *_bq, int32_t *_br, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_FILTER, "FILTER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _measure_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _measure_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _measure_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _corrected_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _corrected_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _corrected_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _correction_phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _correction_theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _correction_psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _bp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _bq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _br, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_FILTER pprz_msg_send_FILTER
#define DOWNLINK_SEND_FILTER(_trans, _dev, phi, theta, psi, measure_phi, measure_theta, measure_psi, corrected_phi, corrected_theta, corrected_psi, correction_phi, correction_theta, correction_psi, bp, bq, br, comp_id) pprz_msg_send_FILTER(&((_trans).trans_tx), &((_dev).device), AC_ID, phi, theta, psi, measure_phi, measure_theta, measure_psi, corrected_phi, corrected_theta, corrected_psi, correction_phi, correction_theta, correction_psi, bp, bq, br, comp_id)
/**
 * Sends a FILTER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _measure_phi 
 * @param _measure_theta 
 * @param _measure_psi 
 * @param _corrected_phi 
 * @param _corrected_theta 
 * @param _corrected_psi 
 * @param _correction_phi 
 * @param _correction_theta 
 * @param _correction_psi 
 * @param _bp 
 * @param _bq 
 * @param _br 
 * @param _comp_id 
 */
static inline void pprz_msg_send_FILTER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_measure_phi, int32_t *_measure_theta, int32_t *_measure_psi, int32_t *_corrected_phi, int32_t *_corrected_theta, int32_t *_corrected_psi, int32_t *_correction_phi, int32_t *_correction_theta, int32_t *_correction_psi, int32_t *_bp, int32_t *_bq, int32_t *_br, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_FILTER(&msg,_phi,_theta,_psi,_measure_phi,_measure_theta,_measure_psi,_corrected_phi,_corrected_theta,_corrected_psi,_correction_phi,_correction_theta,_correction_psi,_bp,_bq,_br,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_FILTER(_trans, _dev, phi, theta, psi, measure_phi, measure_theta, measure_psi, corrected_phi, corrected_theta, corrected_psi, correction_phi, correction_theta, correction_psi, bp, bq, br, comp_id) {}
static inline void pprz_send_msg_FILTER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_phi __attribute__((unused)), int32_t *_theta __attribute__((unused)), int32_t *_psi __attribute__((unused)), int32_t *_measure_phi __attribute__((unused)), int32_t *_measure_theta __attribute__((unused)), int32_t *_measure_psi __attribute__((unused)), int32_t *_corrected_phi __attribute__((unused)), int32_t *_corrected_theta __attribute__((unused)), int32_t *_corrected_psi __attribute__((unused)), int32_t *_correction_phi __attribute__((unused)), int32_t *_correction_theta __attribute__((unused)), int32_t *_correction_psi __attribute__((unused)), int32_t *_bp __attribute__((unused)), int32_t *_bq __attribute__((unused)), int32_t *_br __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field phi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field theta in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field psi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field measure_phi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_measure_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field measure_theta in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_measure_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field measure_psi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_measure_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field corrected_phi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_corrected_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field corrected_theta in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_corrected_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 32);
}


/** Getter for field corrected_psi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_corrected_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 36);
}


/** Getter for field correction_phi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_correction_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 40);
}


/** Getter for field correction_theta in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_correction_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 44);
}


/** Getter for field correction_psi in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_correction_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 48);
}


/** Getter for field bp in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_bp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field bq in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_bq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 56);
}


/** Getter for field br in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline int32_t pprzlink_get_DL_FILTER_br(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 60);
}


/** Getter for field comp_id in message FILTER
  *
  * @param _payload : a pointer to the FILTER message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_FILTER_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 64);
}


/* Compatibility macros */
#define DL_FILTER_phi(_payload) pprzlink_get_DL_FILTER_phi(_payload)
#define DL_FILTER_theta(_payload) pprzlink_get_DL_FILTER_theta(_payload)
#define DL_FILTER_psi(_payload) pprzlink_get_DL_FILTER_psi(_payload)
#define DL_FILTER_measure_phi(_payload) pprzlink_get_DL_FILTER_measure_phi(_payload)
#define DL_FILTER_measure_theta(_payload) pprzlink_get_DL_FILTER_measure_theta(_payload)
#define DL_FILTER_measure_psi(_payload) pprzlink_get_DL_FILTER_measure_psi(_payload)
#define DL_FILTER_corrected_phi(_payload) pprzlink_get_DL_FILTER_corrected_phi(_payload)
#define DL_FILTER_corrected_theta(_payload) pprzlink_get_DL_FILTER_corrected_theta(_payload)
#define DL_FILTER_corrected_psi(_payload) pprzlink_get_DL_FILTER_corrected_psi(_payload)
#define DL_FILTER_correction_phi(_payload) pprzlink_get_DL_FILTER_correction_phi(_payload)
#define DL_FILTER_correction_theta(_payload) pprzlink_get_DL_FILTER_correction_theta(_payload)
#define DL_FILTER_correction_psi(_payload) pprzlink_get_DL_FILTER_correction_psi(_payload)
#define DL_FILTER_bp(_payload) pprzlink_get_DL_FILTER_bp(_payload)
#define DL_FILTER_bq(_payload) pprzlink_get_DL_FILTER_bq(_payload)
#define DL_FILTER_br(_payload) pprzlink_get_DL_FILTER_br(_payload)
#define DL_FILTER_comp_id(_payload) pprzlink_get_DL_FILTER_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_FILTER_H_

