/** @file
 *  @brief PPRZLink message header for TUNE_ROLL in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TUNE_ROLL_H_
#define _VAR_MESSAGES_telemetry_TUNE_ROLL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TUNE_ROLL 43
#define PPRZ_MSG_ID_TUNE_ROLL 43

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TUNE_ROLL _send_msg(TUNE_ROLL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TUNE_ROLL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _p 
 * @param _phi 
 * @param _phi_sp 
 */
static inline void pprzlink_msg_v2_send_TUNE_ROLL(struct pprzlink_msg * msg, float *_p, float *_phi, float *_phi_sp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TUNE_ROLL, "TUNE_ROLL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi_sp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TUNE_ROLL pprz_msg_send_TUNE_ROLL
#define DOWNLINK_SEND_TUNE_ROLL(_trans, _dev, p, phi, phi_sp) pprz_msg_send_TUNE_ROLL(&((_trans).trans_tx), &((_dev).device), AC_ID, p, phi, phi_sp)
/**
 * Sends a TUNE_ROLL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _p 
 * @param _phi 
 * @param _phi_sp 
 */
static inline void pprz_msg_send_TUNE_ROLL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_p, float *_phi, float *_phi_sp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TUNE_ROLL(&msg,_p,_phi,_phi_sp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TUNE_ROLL(_trans, _dev, p, phi, phi_sp) {}
static inline void pprz_send_msg_TUNE_ROLL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_p __attribute__((unused)), float *_phi __attribute__((unused)), float *_phi_sp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field p in message TUNE_ROLL
  *
  * @param _payload : a pointer to the TUNE_ROLL message
  * @return 
  */
static inline float pprzlink_get_DL_TUNE_ROLL_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field phi in message TUNE_ROLL
  *
  * @param _payload : a pointer to the TUNE_ROLL message
  * @return 
  */
static inline float pprzlink_get_DL_TUNE_ROLL_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field phi_sp in message TUNE_ROLL
  *
  * @param _payload : a pointer to the TUNE_ROLL message
  * @return 
  */
static inline float pprzlink_get_DL_TUNE_ROLL_phi_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_TUNE_ROLL_p(_payload) pprzlink_get_DL_TUNE_ROLL_p(_payload)
#define DL_TUNE_ROLL_phi(_payload) pprzlink_get_DL_TUNE_ROLL_phi(_payload)
#define DL_TUNE_ROLL_phi_sp(_payload) pprzlink_get_DL_TUNE_ROLL_phi_sp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TUNE_ROLL_H_

