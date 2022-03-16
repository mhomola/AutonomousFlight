/** @file
 *  @brief PPRZLink message header for DATALINK_REPORT in class telemetry
 *
 *  Datalink status reported by an aircraft for the ground
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_DATALINK_REPORT_H_
#define _VAR_MESSAGES_telemetry_DATALINK_REPORT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_DATALINK_REPORT 30
#define PPRZ_MSG_ID_DATALINK_REPORT 30

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_DATALINK_REPORT _send_msg(DATALINK_REPORT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a DATALINK_REPORT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _uplink_lost_time 
 * @param _uplink_nb_msgs 
 * @param _downlink_nb_msgs 
 * @param _downlink_rate 
 * @param _uplink_rate 
 * @param _downlink_ovrn 
 */
static inline void pprzlink_msg_v2_send_DATALINK_REPORT(struct pprzlink_msg * msg, uint16_t *_uplink_lost_time, uint16_t *_uplink_nb_msgs, uint16_t *_downlink_nb_msgs, uint16_t *_downlink_rate, uint16_t *_uplink_rate, uint8_t *_downlink_ovrn) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_DATALINK_REPORT, "DATALINK_REPORT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _uplink_lost_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _uplink_nb_msgs, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _downlink_nb_msgs, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _downlink_rate, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _uplink_rate, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _downlink_ovrn, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_DATALINK_REPORT pprz_msg_send_DATALINK_REPORT
#define DOWNLINK_SEND_DATALINK_REPORT(_trans, _dev, uplink_lost_time, uplink_nb_msgs, downlink_nb_msgs, downlink_rate, uplink_rate, downlink_ovrn) pprz_msg_send_DATALINK_REPORT(&((_trans).trans_tx), &((_dev).device), AC_ID, uplink_lost_time, uplink_nb_msgs, downlink_nb_msgs, downlink_rate, uplink_rate, downlink_ovrn)
/**
 * Sends a DATALINK_REPORT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _uplink_lost_time 
 * @param _uplink_nb_msgs 
 * @param _downlink_nb_msgs 
 * @param _downlink_rate 
 * @param _uplink_rate 
 * @param _downlink_ovrn 
 */
static inline void pprz_msg_send_DATALINK_REPORT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_uplink_lost_time, uint16_t *_uplink_nb_msgs, uint16_t *_downlink_nb_msgs, uint16_t *_downlink_rate, uint16_t *_uplink_rate, uint8_t *_downlink_ovrn) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_DATALINK_REPORT(&msg,_uplink_lost_time,_uplink_nb_msgs,_downlink_nb_msgs,_downlink_rate,_uplink_rate,_downlink_ovrn);
}


#else // DOWNLINK

#define DOWNLINK_SEND_DATALINK_REPORT(_trans, _dev, uplink_lost_time, uplink_nb_msgs, downlink_nb_msgs, downlink_rate, uplink_rate, downlink_ovrn) {}
static inline void pprz_send_msg_DATALINK_REPORT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_uplink_lost_time __attribute__((unused)), uint16_t *_uplink_nb_msgs __attribute__((unused)), uint16_t *_downlink_nb_msgs __attribute__((unused)), uint16_t *_downlink_rate __attribute__((unused)), uint16_t *_uplink_rate __attribute__((unused)), uint8_t *_downlink_ovrn __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field uplink_lost_time in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DATALINK_REPORT_uplink_lost_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field uplink_nb_msgs in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DATALINK_REPORT_uplink_nb_msgs(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field downlink_nb_msgs in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DATALINK_REPORT_downlink_nb_msgs(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field downlink_rate in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DATALINK_REPORT_downlink_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field uplink_rate in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_DATALINK_REPORT_uplink_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field downlink_ovrn in message DATALINK_REPORT
  *
  * @param _payload : a pointer to the DATALINK_REPORT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_DATALINK_REPORT_downlink_ovrn(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 14);
}


/* Compatibility macros */
#define DL_DATALINK_REPORT_uplink_lost_time(_payload) pprzlink_get_DL_DATALINK_REPORT_uplink_lost_time(_payload)
#define DL_DATALINK_REPORT_uplink_nb_msgs(_payload) pprzlink_get_DL_DATALINK_REPORT_uplink_nb_msgs(_payload)
#define DL_DATALINK_REPORT_downlink_nb_msgs(_payload) pprzlink_get_DL_DATALINK_REPORT_downlink_nb_msgs(_payload)
#define DL_DATALINK_REPORT_downlink_rate(_payload) pprzlink_get_DL_DATALINK_REPORT_downlink_rate(_payload)
#define DL_DATALINK_REPORT_uplink_rate(_payload) pprzlink_get_DL_DATALINK_REPORT_uplink_rate(_payload)
#define DL_DATALINK_REPORT_downlink_ovrn(_payload) pprzlink_get_DL_DATALINK_REPORT_downlink_ovrn(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_DATALINK_REPORT_H_

