/** @file
 *  @brief PPRZLink message header for HFF_GPS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_HFF_GPS_H_
#define _VAR_MESSAGES_telemetry_HFF_GPS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_HFF_GPS 166
#define PPRZ_MSG_ID_HFF_GPS 166

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_HFF_GPS _send_msg(HFF_GPS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a HFF_GPS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _lag_cnt 
 * @param _lag_cnt_err 
 * @param _save_cnt 
 */
static inline void pprzlink_msg_v2_send_HFF_GPS(struct pprzlink_msg * msg, uint16_t *_lag_cnt, int16_t *_lag_cnt_err, int16_t *_save_cnt) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_HFF_GPS, "HFF_GPS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _lag_cnt, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _lag_cnt_err, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _save_cnt, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_HFF_GPS pprz_msg_send_HFF_GPS
#define DOWNLINK_SEND_HFF_GPS(_trans, _dev, lag_cnt, lag_cnt_err, save_cnt) pprz_msg_send_HFF_GPS(&((_trans).trans_tx), &((_dev).device), AC_ID, lag_cnt, lag_cnt_err, save_cnt)
/**
 * Sends a HFF_GPS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _lag_cnt 
 * @param _lag_cnt_err 
 * @param _save_cnt 
 */
static inline void pprz_msg_send_HFF_GPS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_lag_cnt, int16_t *_lag_cnt_err, int16_t *_save_cnt) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_HFF_GPS(&msg,_lag_cnt,_lag_cnt_err,_save_cnt);
}


#else // DOWNLINK

#define DOWNLINK_SEND_HFF_GPS(_trans, _dev, lag_cnt, lag_cnt_err, save_cnt) {}
static inline void pprz_send_msg_HFF_GPS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_lag_cnt __attribute__((unused)), int16_t *_lag_cnt_err __attribute__((unused)), int16_t *_save_cnt __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field lag_cnt in message HFF_GPS
  *
  * @param _payload : a pointer to the HFF_GPS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_HFF_GPS_lag_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field lag_cnt_err in message HFF_GPS
  *
  * @param _payload : a pointer to the HFF_GPS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_HFF_GPS_lag_cnt_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 6);
}


/** Getter for field save_cnt in message HFF_GPS
  *
  * @param _payload : a pointer to the HFF_GPS message
  * @return 
  */
static inline int16_t pprzlink_get_DL_HFF_GPS_save_cnt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 8);
}


/* Compatibility macros */
#define DL_HFF_GPS_lag_cnt(_payload) pprzlink_get_DL_HFF_GPS_lag_cnt(_payload)
#define DL_HFF_GPS_lag_cnt_err(_payload) pprzlink_get_DL_HFF_GPS_lag_cnt_err(_payload)
#define DL_HFF_GPS_save_cnt(_payload) pprzlink_get_DL_HFF_GPS_save_cnt(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_HFF_GPS_H_

