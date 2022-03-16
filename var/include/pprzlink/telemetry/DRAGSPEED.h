/** @file
 *  @brief PPRZLink message header for DRAGSPEED in class telemetry
 *
 *  
        Velocities in body axes (assuming small pitch/roll angles) as measured
        by the dragspeed module and by the INS.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DRAGSPEED_H_
#define _VAR_MESSAGES_telemetry_DRAGSPEED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DRAGSPEED 38
#define PPRZ_MSG_ID_DRAGSPEED 38

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DRAGSPEED _send_msg(DRAGSPEED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DRAGSPEED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _u_est Estimated velocity along body +x axis
 * @param _v_est Estimated velocity along body +y axis
 * @param _u_ins INS velocity along body +x axis
 * @param _v_ins INS velocity along body +y axis
 */
static inline void pprzlink_msg_v2_send_DRAGSPEED(struct pprzlink_msg * msg, float *_u_est, float *_v_est, float *_u_ins, float *_v_ins) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DRAGSPEED, "DRAGSPEED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _u_est, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _v_est, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _u_ins, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _v_ins, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DRAGSPEED pprz_msg_send_DRAGSPEED
#define DOWNLINK_SEND_DRAGSPEED(_trans, _dev, u_est, v_est, u_ins, v_ins) pprz_msg_send_DRAGSPEED(&((_trans).trans_tx), &((_dev).device), AC_ID, u_est, v_est, u_ins, v_ins)
/**
 * Sends a DRAGSPEED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _u_est Estimated velocity along body +x axis
 * @param _v_est Estimated velocity along body +y axis
 * @param _u_ins INS velocity along body +x axis
 * @param _v_ins INS velocity along body +y axis
 */
static inline void pprz_msg_send_DRAGSPEED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_u_est, float *_v_est, float *_u_ins, float *_v_ins) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DRAGSPEED(&msg,_u_est,_v_est,_u_ins,_v_ins);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DRAGSPEED(_trans, _dev, u_est, v_est, u_ins, v_ins) {}
static inline void pprz_send_msg_DRAGSPEED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_u_est __attribute__((unused)), float *_v_est __attribute__((unused)), float *_u_ins __attribute__((unused)), float *_v_ins __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field u_est in message DRAGSPEED
  *
  * @param _payload : a pointer to the DRAGSPEED message
  * @return Estimated velocity along body +x axis
  */
static inline float pprzlink_get_DL_DRAGSPEED_u_est(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field v_est in message DRAGSPEED
  *
  * @param _payload : a pointer to the DRAGSPEED message
  * @return Estimated velocity along body +y axis
  */
static inline float pprzlink_get_DL_DRAGSPEED_v_est(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field u_ins in message DRAGSPEED
  *
  * @param _payload : a pointer to the DRAGSPEED message
  * @return INS velocity along body +x axis
  */
static inline float pprzlink_get_DL_DRAGSPEED_u_ins(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field v_ins in message DRAGSPEED
  *
  * @param _payload : a pointer to the DRAGSPEED message
  * @return INS velocity along body +y axis
  */
static inline float pprzlink_get_DL_DRAGSPEED_v_ins(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_DRAGSPEED_u_est(_payload) pprzlink_get_DL_DRAGSPEED_u_est(_payload)
#define DL_DRAGSPEED_v_est(_payload) pprzlink_get_DL_DRAGSPEED_v_est(_payload)
#define DL_DRAGSPEED_u_ins(_payload) pprzlink_get_DL_DRAGSPEED_u_ins(_payload)
#define DL_DRAGSPEED_v_ins(_payload) pprzlink_get_DL_DRAGSPEED_v_ins(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DRAGSPEED_H_

