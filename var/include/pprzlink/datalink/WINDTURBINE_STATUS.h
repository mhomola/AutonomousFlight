/** @file
 *  @brief PPRZLink message header for WINDTURBINE_STATUS in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_WINDTURBINE_STATUS_H_
#define _VAR_MESSAGES_datalink_WINDTURBINE_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_WINDTURBINE_STATUS 50
#define PPRZ_MSG_ID_WINDTURBINE_STATUS 50

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_WINDTURBINE_STATUS _send_msg(WINDTURBINE_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a WINDTURBINE_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _tb_id 
 * @param _sync_itow 
 * @param _cycle_time 
 */
static inline void pprzlink_msg_v2_send_WINDTURBINE_STATUS(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_tb_id, uint32_t *_sync_itow, uint32_t *_cycle_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_WINDTURBINE_STATUS, "WINDTURBINE_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _tb_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _sync_itow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _cycle_time, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_WINDTURBINE_STATUS pprz_msg_send_WINDTURBINE_STATUS
#define DOWNLINK_SEND_WINDTURBINE_STATUS(_trans, _dev, ac_id, tb_id, sync_itow, cycle_time) pprz_msg_send_WINDTURBINE_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, tb_id, sync_itow, cycle_time)
/**
 * Sends a WINDTURBINE_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _tb_id 
 * @param _sync_itow 
 * @param _cycle_time 
 */
static inline void pprz_msg_send_WINDTURBINE_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_tb_id, uint32_t *_sync_itow, uint32_t *_cycle_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_WINDTURBINE_STATUS(&msg,_ac_id,_tb_id,_sync_itow,_cycle_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_WINDTURBINE_STATUS(_trans, _dev, ac_id, tb_id, sync_itow, cycle_time) {}
static inline void pprz_send_msg_WINDTURBINE_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_tb_id __attribute__((unused)), uint32_t *_sync_itow __attribute__((unused)), uint32_t *_cycle_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message WINDTURBINE_STATUS
  *
  * @param _payload : a pointer to the WINDTURBINE_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WINDTURBINE_STATUS_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field tb_id in message WINDTURBINE_STATUS
  *
  * @param _payload : a pointer to the WINDTURBINE_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_WINDTURBINE_STATUS_tb_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field sync_itow in message WINDTURBINE_STATUS
  *
  * @param _payload : a pointer to the WINDTURBINE_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_WINDTURBINE_STATUS_sync_itow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}


/** Getter for field cycle_time in message WINDTURBINE_STATUS
  *
  * @param _payload : a pointer to the WINDTURBINE_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_WINDTURBINE_STATUS_cycle_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 10);
}


/* Compatibility macros */
#define DL_WINDTURBINE_STATUS_ac_id(_payload) pprzlink_get_DL_WINDTURBINE_STATUS_ac_id(_payload)
#define DL_WINDTURBINE_STATUS_tb_id(_payload) pprzlink_get_DL_WINDTURBINE_STATUS_tb_id(_payload)
#define DL_WINDTURBINE_STATUS_sync_itow(_payload) pprzlink_get_DL_WINDTURBINE_STATUS_sync_itow(_payload)
#define DL_WINDTURBINE_STATUS_cycle_time(_payload) pprzlink_get_DL_WINDTURBINE_STATUS_cycle_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_WINDTURBINE_STATUS_H_

