/** @file
 *  @brief PPRZLink message header for FMS_TIME in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_FMS_TIME_H_
#define _VAR_MESSAGES_telemetry_FMS_TIME_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_FMS_TIME 180
#define PPRZ_MSG_ID_FMS_TIME 180

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_FMS_TIME _send_msg(FMS_TIME,PPRZLINK_DEFAULT_VER)

/**
 * Sends a FMS_TIME message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _tv_sec 
 * @param _tv_nsec 
 * @param _delay_ns 
 */
static inline void pprzlink_msg_v2_send_FMS_TIME(struct pprzlink_msg * msg, uint32_t *_tv_sec, uint32_t *_tv_nsec, uint32_t *_delay_ns) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_FMS_TIME, "FMS_TIME");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tv_sec, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tv_nsec, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _delay_ns, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_FMS_TIME pprz_msg_send_FMS_TIME
#define DOWNLINK_SEND_FMS_TIME(_trans, _dev, tv_sec, tv_nsec, delay_ns) pprz_msg_send_FMS_TIME(&((_trans).trans_tx), &((_dev).device), AC_ID, tv_sec, tv_nsec, delay_ns)
/**
 * Sends a FMS_TIME message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _tv_sec 
 * @param _tv_nsec 
 * @param _delay_ns 
 */
static inline void pprz_msg_send_FMS_TIME(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_tv_sec, uint32_t *_tv_nsec, uint32_t *_delay_ns) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_FMS_TIME(&msg,_tv_sec,_tv_nsec,_delay_ns);
}


#else // DOWNLINK

#define DOWNLINK_SEND_FMS_TIME(_trans, _dev, tv_sec, tv_nsec, delay_ns) {}
static inline void pprz_send_msg_FMS_TIME(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_tv_sec __attribute__((unused)), uint32_t *_tv_nsec __attribute__((unused)), uint32_t *_delay_ns __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field tv_sec in message FMS_TIME
  *
  * @param _payload : a pointer to the FMS_TIME message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_FMS_TIME_tv_sec(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field tv_nsec in message FMS_TIME
  *
  * @param _payload : a pointer to the FMS_TIME message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_FMS_TIME_tv_nsec(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field delay_ns in message FMS_TIME
  *
  * @param _payload : a pointer to the FMS_TIME message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_FMS_TIME_delay_ns(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 12);
}


/* Compatibility macros */
#define DL_FMS_TIME_tv_sec(_payload) pprzlink_get_DL_FMS_TIME_tv_sec(_payload)
#define DL_FMS_TIME_tv_nsec(_payload) pprzlink_get_DL_FMS_TIME_tv_nsec(_payload)
#define DL_FMS_TIME_delay_ns(_payload) pprzlink_get_DL_FMS_TIME_delay_ns(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_FMS_TIME_H_

