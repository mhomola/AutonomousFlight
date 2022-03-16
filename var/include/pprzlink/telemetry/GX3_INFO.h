/** @file
 *  @brief PPRZLink message header for GX3_INFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GX3_INFO_H_
#define _VAR_MESSAGES_telemetry_GX3_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GX3_INFO 73
#define PPRZ_MSG_ID_GX3_INFO 73

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GX3_INFO _send_msg(GX3_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GX3_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _GX3_freq 
 * @param _chksm_error 
 * @param _hdr_error 
 * @param _GX3_chksm 
 */
static inline void pprzlink_msg_v2_send_GX3_INFO(struct pprzlink_msg * msg, float *_GX3_freq, uint32_t *_chksm_error, uint32_t *_hdr_error, uint16_t *_GX3_chksm) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GX3_INFO, "GX3_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _GX3_freq, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _chksm_error, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _hdr_error, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _GX3_chksm, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GX3_INFO pprz_msg_send_GX3_INFO
#define DOWNLINK_SEND_GX3_INFO(_trans, _dev, GX3_freq, chksm_error, hdr_error, GX3_chksm) pprz_msg_send_GX3_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, GX3_freq, chksm_error, hdr_error, GX3_chksm)
/**
 * Sends a GX3_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _GX3_freq 
 * @param _chksm_error 
 * @param _hdr_error 
 * @param _GX3_chksm 
 */
static inline void pprz_msg_send_GX3_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_GX3_freq, uint32_t *_chksm_error, uint32_t *_hdr_error, uint16_t *_GX3_chksm) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GX3_INFO(&msg,_GX3_freq,_chksm_error,_hdr_error,_GX3_chksm);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GX3_INFO(_trans, _dev, GX3_freq, chksm_error, hdr_error, GX3_chksm) {}
static inline void pprz_send_msg_GX3_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_GX3_freq __attribute__((unused)), uint32_t *_chksm_error __attribute__((unused)), uint32_t *_hdr_error __attribute__((unused)), uint16_t *_GX3_chksm __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field GX3_freq in message GX3_INFO
  *
  * @param _payload : a pointer to the GX3_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_GX3_INFO_GX3_freq(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field chksm_error in message GX3_INFO
  *
  * @param _payload : a pointer to the GX3_INFO message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GX3_INFO_chksm_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field hdr_error in message GX3_INFO
  *
  * @param _payload : a pointer to the GX3_INFO message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_GX3_INFO_hdr_error(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 12);
}


/** Getter for field GX3_chksm in message GX3_INFO
  *
  * @param _payload : a pointer to the GX3_INFO message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_GX3_INFO_GX3_chksm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/* Compatibility macros */
#define DL_GX3_INFO_GX3_freq(_payload) pprzlink_get_DL_GX3_INFO_GX3_freq(_payload)
#define DL_GX3_INFO_chksm_error(_payload) pprzlink_get_DL_GX3_INFO_chksm_error(_payload)
#define DL_GX3_INFO_hdr_error(_payload) pprzlink_get_DL_GX3_INFO_hdr_error(_payload)
#define DL_GX3_INFO_GX3_chksm(_payload) pprzlink_get_DL_GX3_INFO_GX3_chksm(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GX3_INFO_H_

