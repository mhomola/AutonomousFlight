/** @file
 *  @brief PPRZLink message header for DGPS_RAW in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_DGPS_RAW_H_
#define _VAR_MESSAGES_datalink_DGPS_RAW_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DGPS_RAW 13
#define PPRZ_MSG_ID_DGPS_RAW 13

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DGPS_RAW _send_msg(DGPS_RAW,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DGPS_RAW message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _length 
 * @param nb_rtcm,_rtcm 
 */
static inline void pprzlink_msg_v2_send_DGPS_RAW(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_length, uint8_t nb_rtcm, uint8_t *_rtcm) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+nb_rtcm*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+nb_rtcm*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DGPS_RAW, "DGPS_RAW");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _length, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_rtcm, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _rtcm, nb_rtcm*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DGPS_RAW pprz_msg_send_DGPS_RAW
#define DOWNLINK_SEND_DGPS_RAW(_trans, _dev, ac_id, length, nb_rtcm, rtcm) pprz_msg_send_DGPS_RAW(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, length, nb_rtcm, rtcm)
/**
 * Sends a DGPS_RAW message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _length 
 * @param nb_rtcm,_rtcm 
 */
static inline void pprz_msg_send_DGPS_RAW(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_length, uint8_t nb_rtcm, uint8_t *_rtcm) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DGPS_RAW(&msg,_ac_id,_length,nb_rtcm,_rtcm);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DGPS_RAW(_trans, _dev, ac_id, length, nb_rtcm, rtcm) {}
static inline void pprz_send_msg_DGPS_RAW(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_length __attribute__((unused)), uint8_t nb_rtcm __attribute__((unused)), uint8_t *_rtcm __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message DGPS_RAW
  *
  * @param _payload : a pointer to the DGPS_RAW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_DGPS_RAW_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field length in message DGPS_RAW
  *
  * @param _payload : a pointer to the DGPS_RAW message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_DGPS_RAW_length(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for length of array rtcm in message DGPS_RAW
 *
 * @return rtcm : 
 */
 static inline uint8_t pprzlink_get_DGPS_RAW_rtcm_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for field rtcm in message DGPS_RAW
  *
  * @param _payload : a pointer to the DGPS_RAW message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_DGPS_RAW_rtcm(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 7);
}


/* Compatibility macros */
#define DL_DGPS_RAW_ac_id(_payload) pprzlink_get_DL_DGPS_RAW_ac_id(_payload)
#define DL_DGPS_RAW_length(_payload) pprzlink_get_DL_DGPS_RAW_length(_payload)
#define DL_DGPS_RAW_rtcm_length(_payload) pprzlink_get_DGPS_RAW_rtcm_length(_payload)
#define DL_DGPS_RAW_rtcm(_payload) pprzlink_get_DL_DGPS_RAW_rtcm(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_DGPS_RAW_H_

