/** @file
 *  @brief PPRZLink message header for VECTORNAV_INFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VECTORNAV_INFO_H_
#define _VAR_MESSAGES_telemetry_VECTORNAV_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VECTORNAV_INFO 23
#define PPRZ_MSG_ID_VECTORNAV_INFO 23

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VECTORNAV_INFO _send_msg(VECTORNAV_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VECTORNAV_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _timestamp 
 * @param _chksm_error 
 * @param _hdr_error 
 * @param _rate 
 * @param _ins_status 
 * @param _ins_err 
 * @param _YprU1 
 * @param _YprU2 
 * @param _YprU3 
 */
static inline void pprzlink_msg_v2_send_VECTORNAV_INFO(struct pprzlink_msg * msg, float *_timestamp, uint32_t *_chksm_error, uint32_t *_hdr_error, uint16_t *_rate, uint8_t *_ins_status, uint8_t *_ins_err, float *_YprU1, float *_YprU2, float *_YprU3) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+2+1+1+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+2+1+1+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VECTORNAV_INFO, "VECTORNAV_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _timestamp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _chksm_error, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _hdr_error, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _rate, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ins_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ins_err, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _YprU1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _YprU2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _YprU3, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VECTORNAV_INFO pprz_msg_send_VECTORNAV_INFO
#define DOWNLINK_SEND_VECTORNAV_INFO(_trans, _dev, timestamp, chksm_error, hdr_error, rate, ins_status, ins_err, YprU1, YprU2, YprU3) pprz_msg_send_VECTORNAV_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, timestamp, chksm_error, hdr_error, rate, ins_status, ins_err, YprU1, YprU2, YprU3)
/**
 * Sends a VECTORNAV_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _timestamp 
 * @param _chksm_error 
 * @param _hdr_error 
 * @param _rate 
 * @param _ins_status 
 * @param _ins_err 
 * @param _YprU1 
 * @param _YprU2 
 * @param _YprU3 
 */
static inline void pprz_msg_send_VECTORNAV_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_timestamp, uint32_t *_chksm_error, uint32_t *_hdr_error, uint16_t *_rate, uint8_t *_ins_status, uint8_t *_ins_err, float *_YprU1, float *_YprU2, float *_YprU3) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VECTORNAV_INFO(&msg,_timestamp,_chksm_error,_hdr_error,_rate,_ins_status,_ins_err,_YprU1,_YprU2,_YprU3);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VECTORNAV_INFO(_trans, _dev, timestamp, chksm_error, hdr_error, rate, ins_status, ins_err, YprU1, YprU2, YprU3) {}
static inline void pprz_send_msg_VECTORNAV_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_timestamp __attribute__((unused)), uint32_t *_chksm_error __attribute__((unused)), uint32_t *_hdr_error __attribute__((unused)), uint16_t *_rate __attribute__((unused)), uint8_t *_ins_status __attribute__((unused)), uint8_t *_ins_err __attribute__((unused)), float *_YprU1 __attribute__((unused)), float *_YprU2 __attribute__((unused)), float *_YprU3 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field timestamp in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_VECTORNAV_INFO_timestamp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field chksm_error in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_VECTORNAV_INFO_chksm_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field hdr_error in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_VECTORNAV_INFO_hdr_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 12);
}


/** Getter for field rate in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_VECTORNAV_INFO_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field ins_status in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VECTORNAV_INFO_ins_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 18);
}


/** Getter for field ins_err in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_VECTORNAV_INFO_ins_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 19);
}


/** Getter for field YprU1 in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_VECTORNAV_INFO_YprU1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field YprU2 in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_VECTORNAV_INFO_YprU2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field YprU3 in message VECTORNAV_INFO
  *
  * @param _payload : a pointer to the VECTORNAV_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_VECTORNAV_INFO_YprU3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_VECTORNAV_INFO_timestamp(_payload) pprzlink_get_DL_VECTORNAV_INFO_timestamp(_payload)
#define DL_VECTORNAV_INFO_chksm_error(_payload) pprzlink_get_DL_VECTORNAV_INFO_chksm_error(_payload)
#define DL_VECTORNAV_INFO_hdr_error(_payload) pprzlink_get_DL_VECTORNAV_INFO_hdr_error(_payload)
#define DL_VECTORNAV_INFO_rate(_payload) pprzlink_get_DL_VECTORNAV_INFO_rate(_payload)
#define DL_VECTORNAV_INFO_ins_status(_payload) pprzlink_get_DL_VECTORNAV_INFO_ins_status(_payload)
#define DL_VECTORNAV_INFO_ins_err(_payload) pprzlink_get_DL_VECTORNAV_INFO_ins_err(_payload)
#define DL_VECTORNAV_INFO_YprU1(_payload) pprzlink_get_DL_VECTORNAV_INFO_YprU1(_payload)
#define DL_VECTORNAV_INFO_YprU2(_payload) pprzlink_get_DL_VECTORNAV_INFO_YprU2(_payload)
#define DL_VECTORNAV_INFO_YprU3(_payload) pprzlink_get_DL_VECTORNAV_INFO_YprU3(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VECTORNAV_INFO_H_

