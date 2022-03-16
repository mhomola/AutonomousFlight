/** @file
 *  @brief PPRZLink message header for SUPERBITRF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SUPERBITRF_H_
#define _VAR_MESSAGES_telemetry_SUPERBITRF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SUPERBITRF 72
#define PPRZ_MSG_ID_SUPERBITRF 72

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SUPERBITRF _send_msg(SUPERBITRF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SUPERBITRF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _status 
 * @param _cyrf_status 
 * @param _irq_count 
 * @param _rx_packet_count 
 * @param _tx_packet_count 
 * @param _transfer_timeouts 
 * @param _resync_count 
 * @param _uplink_count 
 * @param _rc_count 
 * @param _timing1 
 * @param _timing2 
 * @param _bind_mfg_id 
 * @param nb_mfg_id,_mfg_id 
 */
static inline void pprzlink_msg_v2_send_SUPERBITRF(struct pprzlink_msg * msg, uint8_t *_status, uint8_t *_cyrf_status, uint32_t *_irq_count, uint32_t *_rx_packet_count, uint32_t *_tx_packet_count, uint32_t *_transfer_timeouts, uint32_t *_resync_count, uint32_t *_uplink_count, uint32_t *_rc_count, uint32_t *_timing1, uint32_t *_timing2, uint32_t *_bind_mfg_id, uint8_t nb_mfg_id, uint8_t *_mfg_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+1+nb_mfg_id*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+1+nb_mfg_id*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SUPERBITRF, "SUPERBITRF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cyrf_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _irq_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _rx_packet_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tx_packet_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _transfer_timeouts, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _resync_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _uplink_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _rc_count, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _timing1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _timing2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _bind_mfg_id, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_mfg_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _mfg_id, nb_mfg_id*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SUPERBITRF pprz_msg_send_SUPERBITRF
#define DOWNLINK_SEND_SUPERBITRF(_trans, _dev, status, cyrf_status, irq_count, rx_packet_count, tx_packet_count, transfer_timeouts, resync_count, uplink_count, rc_count, timing1, timing2, bind_mfg_id, nb_mfg_id, mfg_id) pprz_msg_send_SUPERBITRF(&((_trans).trans_tx), &((_dev).device), AC_ID, status, cyrf_status, irq_count, rx_packet_count, tx_packet_count, transfer_timeouts, resync_count, uplink_count, rc_count, timing1, timing2, bind_mfg_id, nb_mfg_id, mfg_id)
/**
 * Sends a SUPERBITRF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _status 
 * @param _cyrf_status 
 * @param _irq_count 
 * @param _rx_packet_count 
 * @param _tx_packet_count 
 * @param _transfer_timeouts 
 * @param _resync_count 
 * @param _uplink_count 
 * @param _rc_count 
 * @param _timing1 
 * @param _timing2 
 * @param _bind_mfg_id 
 * @param nb_mfg_id,_mfg_id 
 */
static inline void pprz_msg_send_SUPERBITRF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_status, uint8_t *_cyrf_status, uint32_t *_irq_count, uint32_t *_rx_packet_count, uint32_t *_tx_packet_count, uint32_t *_transfer_timeouts, uint32_t *_resync_count, uint32_t *_uplink_count, uint32_t *_rc_count, uint32_t *_timing1, uint32_t *_timing2, uint32_t *_bind_mfg_id, uint8_t nb_mfg_id, uint8_t *_mfg_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SUPERBITRF(&msg,_status,_cyrf_status,_irq_count,_rx_packet_count,_tx_packet_count,_transfer_timeouts,_resync_count,_uplink_count,_rc_count,_timing1,_timing2,_bind_mfg_id,nb_mfg_id,_mfg_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SUPERBITRF(_trans, _dev, status, cyrf_status, irq_count, rx_packet_count, tx_packet_count, transfer_timeouts, resync_count, uplink_count, rc_count, timing1, timing2, bind_mfg_id, nb_mfg_id, mfg_id) {}
static inline void pprz_send_msg_SUPERBITRF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_status __attribute__((unused)), uint8_t *_cyrf_status __attribute__((unused)), uint32_t *_irq_count __attribute__((unused)), uint32_t *_rx_packet_count __attribute__((unused)), uint32_t *_tx_packet_count __attribute__((unused)), uint32_t *_transfer_timeouts __attribute__((unused)), uint32_t *_resync_count __attribute__((unused)), uint32_t *_uplink_count __attribute__((unused)), uint32_t *_rc_count __attribute__((unused)), uint32_t *_timing1 __attribute__((unused)), uint32_t *_timing2 __attribute__((unused)), uint32_t *_bind_mfg_id __attribute__((unused)), uint8_t nb_mfg_id __attribute__((unused)), uint8_t *_mfg_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field status in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SUPERBITRF_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field cyrf_status in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SUPERBITRF_cyrf_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field irq_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_irq_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}


/** Getter for field rx_packet_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_rx_packet_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 10);
}


/** Getter for field tx_packet_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_tx_packet_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 14);
}


/** Getter for field transfer_timeouts in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_transfer_timeouts(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 18);
}


/** Getter for field resync_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_resync_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 22);
}


/** Getter for field uplink_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_uplink_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 26);
}


/** Getter for field rc_count in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_rc_count(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 30);
}


/** Getter for field timing1 in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_timing1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 34);
}


/** Getter for field timing2 in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_timing2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 38);
}


/** Getter for field bind_mfg_id in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_SUPERBITRF_bind_mfg_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 42);
}

/** Getter for length of array mfg_id in message SUPERBITRF
 *
 * @return mfg_id : 
 */
 static inline uint8_t pprzlink_get_SUPERBITRF_mfg_id_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 46);
}

/** Getter for field mfg_id in message SUPERBITRF
  *
  * @param _payload : a pointer to the SUPERBITRF message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_SUPERBITRF_mfg_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 47);
}


/* Compatibility macros */
#define DL_SUPERBITRF_status(_payload) pprzlink_get_DL_SUPERBITRF_status(_payload)
#define DL_SUPERBITRF_cyrf_status(_payload) pprzlink_get_DL_SUPERBITRF_cyrf_status(_payload)
#define DL_SUPERBITRF_irq_count(_payload) pprzlink_get_DL_SUPERBITRF_irq_count(_payload)
#define DL_SUPERBITRF_rx_packet_count(_payload) pprzlink_get_DL_SUPERBITRF_rx_packet_count(_payload)
#define DL_SUPERBITRF_tx_packet_count(_payload) pprzlink_get_DL_SUPERBITRF_tx_packet_count(_payload)
#define DL_SUPERBITRF_transfer_timeouts(_payload) pprzlink_get_DL_SUPERBITRF_transfer_timeouts(_payload)
#define DL_SUPERBITRF_resync_count(_payload) pprzlink_get_DL_SUPERBITRF_resync_count(_payload)
#define DL_SUPERBITRF_uplink_count(_payload) pprzlink_get_DL_SUPERBITRF_uplink_count(_payload)
#define DL_SUPERBITRF_rc_count(_payload) pprzlink_get_DL_SUPERBITRF_rc_count(_payload)
#define DL_SUPERBITRF_timing1(_payload) pprzlink_get_DL_SUPERBITRF_timing1(_payload)
#define DL_SUPERBITRF_timing2(_payload) pprzlink_get_DL_SUPERBITRF_timing2(_payload)
#define DL_SUPERBITRF_bind_mfg_id(_payload) pprzlink_get_DL_SUPERBITRF_bind_mfg_id(_payload)
#define DL_SUPERBITRF_mfg_id_length(_payload) pprzlink_get_SUPERBITRF_mfg_id_length(_payload)
#define DL_SUPERBITRF_mfg_id(_payload) pprzlink_get_DL_SUPERBITRF_mfg_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SUPERBITRF_H_

