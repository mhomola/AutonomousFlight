/** @file
 *  @brief PPRZLink message header for PPRZ_MODE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_PPRZ_MODE_H_
#define _VAR_MESSAGES_telemetry_PPRZ_MODE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_PPRZ_MODE 11
#define PPRZ_MSG_ID_PPRZ_MODE 11

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_PPRZ_MODE _send_msg(PPRZ_MODE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a PPRZ_MODE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ap_mode 
 * @param _ap_gaz 
 * @param _ap_lateral 
 * @param _ap_horizontal 
 * @param _if_calib_mode 
 * @param _mcu1_status 
 */
static inline void pprzlink_msg_v2_send_PPRZ_MODE(struct pprzlink_msg * msg, uint8_t *_ap_mode, uint8_t *_ap_gaz, uint8_t *_ap_lateral, uint8_t *_ap_horizontal, uint8_t *_if_calib_mode, uint8_t *_mcu1_status) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_PPRZ_MODE, "PPRZ_MODE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_gaz, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_lateral, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_horizontal, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _if_calib_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _mcu1_status, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_PPRZ_MODE pprz_msg_send_PPRZ_MODE
#define DOWNLINK_SEND_PPRZ_MODE(_trans, _dev, ap_mode, ap_gaz, ap_lateral, ap_horizontal, if_calib_mode, mcu1_status) pprz_msg_send_PPRZ_MODE(&((_trans).trans_tx), &((_dev).device), AC_ID, ap_mode, ap_gaz, ap_lateral, ap_horizontal, if_calib_mode, mcu1_status)
/**
 * Sends a PPRZ_MODE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ap_mode 
 * @param _ap_gaz 
 * @param _ap_lateral 
 * @param _ap_horizontal 
 * @param _if_calib_mode 
 * @param _mcu1_status 
 */
static inline void pprz_msg_send_PPRZ_MODE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ap_mode, uint8_t *_ap_gaz, uint8_t *_ap_lateral, uint8_t *_ap_horizontal, uint8_t *_if_calib_mode, uint8_t *_mcu1_status) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_PPRZ_MODE(&msg,_ap_mode,_ap_gaz,_ap_lateral,_ap_horizontal,_if_calib_mode,_mcu1_status);
}


#else // DOWNLINK

#define DOWNLINK_SEND_PPRZ_MODE(_trans, _dev, ap_mode, ap_gaz, ap_lateral, ap_horizontal, if_calib_mode, mcu1_status) {}
static inline void pprz_send_msg_PPRZ_MODE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ap_mode __attribute__((unused)), uint8_t *_ap_gaz __attribute__((unused)), uint8_t *_ap_lateral __attribute__((unused)), uint8_t *_ap_horizontal __attribute__((unused)), uint8_t *_if_calib_mode __attribute__((unused)), uint8_t *_mcu1_status __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ap_mode in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_ap_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field ap_gaz in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_ap_gaz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field ap_lateral in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_ap_lateral(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field ap_horizontal in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_ap_horizontal(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/** Getter for field if_calib_mode in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_if_calib_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field mcu1_status in message PPRZ_MODE
  *
  * @param _payload : a pointer to the PPRZ_MODE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_PPRZ_MODE_mcu1_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 9);
}


/* Compatibility macros */
#define DL_PPRZ_MODE_ap_mode(_payload) pprzlink_get_DL_PPRZ_MODE_ap_mode(_payload)
#define DL_PPRZ_MODE_ap_gaz(_payload) pprzlink_get_DL_PPRZ_MODE_ap_gaz(_payload)
#define DL_PPRZ_MODE_ap_lateral(_payload) pprzlink_get_DL_PPRZ_MODE_ap_lateral(_payload)
#define DL_PPRZ_MODE_ap_horizontal(_payload) pprzlink_get_DL_PPRZ_MODE_ap_horizontal(_payload)
#define DL_PPRZ_MODE_if_calib_mode(_payload) pprzlink_get_DL_PPRZ_MODE_if_calib_mode(_payload)
#define DL_PPRZ_MODE_mcu1_status(_payload) pprzlink_get_DL_PPRZ_MODE_mcu1_status(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_PPRZ_MODE_H_

