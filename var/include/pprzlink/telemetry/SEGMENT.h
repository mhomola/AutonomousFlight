/** @file
 *  @brief PPRZLink message header for SEGMENT in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SEGMENT_H_
#define _VAR_MESSAGES_telemetry_SEGMENT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SEGMENT 22
#define PPRZ_MSG_ID_SEGMENT 22

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SEGMENT _send_msg(SEGMENT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SEGMENT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _segment_east_1 
 * @param _segment_north_1 
 * @param _segment_east_2 
 * @param _segment_north_2 
 */
static inline void pprzlink_msg_v2_send_SEGMENT(struct pprzlink_msg * msg, float *_segment_east_1, float *_segment_north_1, float *_segment_east_2, float *_segment_north_2) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SEGMENT, "SEGMENT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _segment_east_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _segment_north_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _segment_east_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _segment_north_2, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SEGMENT pprz_msg_send_SEGMENT
#define DOWNLINK_SEND_SEGMENT(_trans, _dev, segment_east_1, segment_north_1, segment_east_2, segment_north_2) pprz_msg_send_SEGMENT(&((_trans).trans_tx), &((_dev).device), AC_ID, segment_east_1, segment_north_1, segment_east_2, segment_north_2)
/**
 * Sends a SEGMENT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _segment_east_1 
 * @param _segment_north_1 
 * @param _segment_east_2 
 * @param _segment_north_2 
 */
static inline void pprz_msg_send_SEGMENT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_segment_east_1, float *_segment_north_1, float *_segment_east_2, float *_segment_north_2) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SEGMENT(&msg,_segment_east_1,_segment_north_1,_segment_east_2,_segment_north_2);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SEGMENT(_trans, _dev, segment_east_1, segment_north_1, segment_east_2, segment_north_2) {}
static inline void pprz_send_msg_SEGMENT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_segment_east_1 __attribute__((unused)), float *_segment_north_1 __attribute__((unused)), float *_segment_east_2 __attribute__((unused)), float *_segment_north_2 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field segment_east_1 in message SEGMENT
  *
  * @param _payload : a pointer to the SEGMENT message
  * @return 
  */
static inline float pprzlink_get_DL_SEGMENT_segment_east_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field segment_north_1 in message SEGMENT
  *
  * @param _payload : a pointer to the SEGMENT message
  * @return 
  */
static inline float pprzlink_get_DL_SEGMENT_segment_north_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field segment_east_2 in message SEGMENT
  *
  * @param _payload : a pointer to the SEGMENT message
  * @return 
  */
static inline float pprzlink_get_DL_SEGMENT_segment_east_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field segment_north_2 in message SEGMENT
  *
  * @param _payload : a pointer to the SEGMENT message
  * @return 
  */
static inline float pprzlink_get_DL_SEGMENT_segment_north_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_SEGMENT_segment_east_1(_payload) pprzlink_get_DL_SEGMENT_segment_east_1(_payload)
#define DL_SEGMENT_segment_north_1(_payload) pprzlink_get_DL_SEGMENT_segment_north_1(_payload)
#define DL_SEGMENT_segment_east_2(_payload) pprzlink_get_DL_SEGMENT_segment_east_2(_payload)
#define DL_SEGMENT_segment_north_2(_payload) pprzlink_get_DL_SEGMENT_segment_north_2(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SEGMENT_H_

