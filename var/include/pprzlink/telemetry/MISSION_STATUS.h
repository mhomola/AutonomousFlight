/** @file
 *  @brief PPRZLink message header for MISSION_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MISSION_STATUS_H_
#define _VAR_MESSAGES_telemetry_MISSION_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MISSION_STATUS 79
#define PPRZ_MSG_ID_MISSION_STATUS 79

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MISSION_STATUS _send_msg(MISSION_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MISSION_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _remaining_time 
 * @param nb_index_list,_index_list 
 */
static inline void pprzlink_msg_v2_send_MISSION_STATUS(struct pprzlink_msg * msg, float *_remaining_time, uint8_t nb_index_list, uint8_t *_index_list) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+nb_index_list*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+nb_index_list*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MISSION_STATUS, "MISSION_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _remaining_time, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_index_list, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _index_list, nb_index_list*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MISSION_STATUS pprz_msg_send_MISSION_STATUS
#define DOWNLINK_SEND_MISSION_STATUS(_trans, _dev, remaining_time, nb_index_list, index_list) pprz_msg_send_MISSION_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, remaining_time, nb_index_list, index_list)
/**
 * Sends a MISSION_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _remaining_time 
 * @param nb_index_list,_index_list 
 */
static inline void pprz_msg_send_MISSION_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_remaining_time, uint8_t nb_index_list, uint8_t *_index_list) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MISSION_STATUS(&msg,_remaining_time,nb_index_list,_index_list);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MISSION_STATUS(_trans, _dev, remaining_time, nb_index_list, index_list) {}
static inline void pprz_send_msg_MISSION_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_remaining_time __attribute__((unused)), uint8_t nb_index_list __attribute__((unused)), uint8_t *_index_list __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field remaining_time in message MISSION_STATUS
  *
  * @param _payload : a pointer to the MISSION_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_MISSION_STATUS_remaining_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}

/** Getter for length of array index_list in message MISSION_STATUS
 *
 * @return index_list : 
 */
 static inline uint8_t pprzlink_get_MISSION_STATUS_index_list_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 8);
}

/** Getter for field index_list in message MISSION_STATUS
  *
  * @param _payload : a pointer to the MISSION_STATUS message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_MISSION_STATUS_index_list(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 9);
}


/* Compatibility macros */
#define DL_MISSION_STATUS_remaining_time(_payload) pprzlink_get_DL_MISSION_STATUS_remaining_time(_payload)
#define DL_MISSION_STATUS_index_list_length(_payload) pprzlink_get_MISSION_STATUS_index_list_length(_payload)
#define DL_MISSION_STATUS_index_list(_payload) pprzlink_get_DL_MISSION_STATUS_index_list(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MISSION_STATUS_H_

