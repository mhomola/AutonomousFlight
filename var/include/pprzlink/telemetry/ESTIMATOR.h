/** @file
 *  @brief PPRZLink message header for ESTIMATOR in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ESTIMATOR_H_
#define _VAR_MESSAGES_telemetry_ESTIMATOR_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ESTIMATOR 42
#define PPRZ_MSG_ID_ESTIMATOR 42

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ESTIMATOR _send_msg(ESTIMATOR,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ESTIMATOR message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _z 
 * @param _z_dot 
 */
static inline void pprzlink_msg_v2_send_ESTIMATOR(struct pprzlink_msg * msg, float *_z, float *_z_dot) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ESTIMATOR, "ESTIMATOR");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_dot, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ESTIMATOR pprz_msg_send_ESTIMATOR
#define DOWNLINK_SEND_ESTIMATOR(_trans, _dev, z, z_dot) pprz_msg_send_ESTIMATOR(&((_trans).trans_tx), &((_dev).device), AC_ID, z, z_dot)
/**
 * Sends a ESTIMATOR message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _z 
 * @param _z_dot 
 */
static inline void pprz_msg_send_ESTIMATOR(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_z, float *_z_dot) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ESTIMATOR(&msg,_z,_z_dot);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ESTIMATOR(_trans, _dev, z, z_dot) {}
static inline void pprz_send_msg_ESTIMATOR(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_z __attribute__((unused)), float *_z_dot __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field z in message ESTIMATOR
  *
  * @param _payload : a pointer to the ESTIMATOR message
  * @return 
  */
static inline float pprzlink_get_DL_ESTIMATOR_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field z_dot in message ESTIMATOR
  *
  * @param _payload : a pointer to the ESTIMATOR message
  * @return 
  */
static inline float pprzlink_get_DL_ESTIMATOR_z_dot(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/* Compatibility macros */
#define DL_ESTIMATOR_z(_payload) pprzlink_get_DL_ESTIMATOR_z(_payload)
#define DL_ESTIMATOR_z_dot(_payload) pprzlink_get_DL_ESTIMATOR_z_dot(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ESTIMATOR_H_

