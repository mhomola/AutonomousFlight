/** @file
 *  @brief PPRZLink message header for CALIBRATION in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CALIBRATION_H_
#define _VAR_MESSAGES_telemetry_CALIBRATION_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CALIBRATION 14
#define PPRZ_MSG_ID_CALIBRATION 14

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CALIBRATION _send_msg(CALIBRATION,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CALIBRATION message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _climb_sum_err 
 * @param _climb_gaz_submode 
 */
static inline void pprzlink_msg_v2_send_CALIBRATION(struct pprzlink_msg * msg, float *_climb_sum_err, uint8_t *_climb_gaz_submode) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CALIBRATION, "CALIBRATION");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _climb_sum_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _climb_gaz_submode, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CALIBRATION pprz_msg_send_CALIBRATION
#define DOWNLINK_SEND_CALIBRATION(_trans, _dev, climb_sum_err, climb_gaz_submode) pprz_msg_send_CALIBRATION(&((_trans).trans_tx), &((_dev).device), AC_ID, climb_sum_err, climb_gaz_submode)
/**
 * Sends a CALIBRATION message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _climb_sum_err 
 * @param _climb_gaz_submode 
 */
static inline void pprz_msg_send_CALIBRATION(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_climb_sum_err, uint8_t *_climb_gaz_submode) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CALIBRATION(&msg,_climb_sum_err,_climb_gaz_submode);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CALIBRATION(_trans, _dev, climb_sum_err, climb_gaz_submode) {}
static inline void pprz_send_msg_CALIBRATION(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_climb_sum_err __attribute__((unused)), uint8_t *_climb_gaz_submode __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field climb_sum_err in message CALIBRATION
  *
  * @param _payload : a pointer to the CALIBRATION message
  * @return 
  */
static inline float pprzlink_get_DL_CALIBRATION_climb_sum_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field climb_gaz_submode in message CALIBRATION
  *
  * @param _payload : a pointer to the CALIBRATION message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_CALIBRATION_climb_gaz_submode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/* Compatibility macros */
#define DL_CALIBRATION_climb_sum_err(_payload) pprzlink_get_DL_CALIBRATION_climb_sum_err(_payload)
#define DL_CALIBRATION_climb_gaz_submode(_payload) pprzlink_get_DL_CALIBRATION_climb_gaz_submode(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CALIBRATION_H_

