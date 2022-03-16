/** @file
 *  @brief PPRZLink message header for AOA in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AOA_H_
#define _VAR_MESSAGES_telemetry_AOA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AOA 69
#define PPRZ_MSG_ID_AOA 69

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AOA _send_msg(AOA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AOA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _raw 
 * @param _angle 
 */
static inline void pprzlink_msg_v2_send_AOA(struct pprzlink_msg * msg, uint32_t *_raw, float *_angle) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AOA, "AOA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _raw, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angle, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AOA pprz_msg_send_AOA
#define DOWNLINK_SEND_AOA(_trans, _dev, raw, angle) pprz_msg_send_AOA(&((_trans).trans_tx), &((_dev).device), AC_ID, raw, angle)
/**
 * Sends a AOA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _raw 
 * @param _angle 
 */
static inline void pprz_msg_send_AOA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_raw, float *_angle) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AOA(&msg,_raw,_angle);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AOA(_trans, _dev, raw, angle) {}
static inline void pprz_send_msg_AOA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_raw __attribute__((unused)), float *_angle __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field raw in message AOA
  *
  * @param _payload : a pointer to the AOA message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_AOA_raw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field angle in message AOA
  *
  * @param _payload : a pointer to the AOA message
  * @return 
  */
static inline float pprzlink_get_DL_AOA_angle(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/* Compatibility macros */
#define DL_AOA_raw(_payload) pprzlink_get_DL_AOA_raw(_payload)
#define DL_AOA_angle(_payload) pprzlink_get_DL_AOA_angle(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AOA_H_

