/** @file
 *  @brief PPRZLink message header for MISSION_UPDATE in class datalink
 *
 *  
        Update parameters of a mission element without changing the mission element list or current execution.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_MISSION_UPDATE_H_
#define _VAR_MESSAGES_datalink_MISSION_UPDATE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MISSION_UPDATE 29
#define PPRZ_MSG_ID_MISSION_UPDATE 29

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MISSION_UPDATE _send_msg(MISSION_UPDATE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MISSION_UPDATE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id Aircraft ID
 * @param _index Index of mission element to update
 * @param _duration Duration of the element, -1 for unlimited, -9 for no change
 * @param nb_params,_params List of parameters, 12 max
 */
static inline void pprzlink_msg_v2_send_MISSION_UPDATE(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_index, float *_duration, uint8_t nb_params, float *_params) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+1+nb_params*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+1+nb_params*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MISSION_UPDATE, "MISSION_UPDATE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _index, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _duration, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_params, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _params, nb_params*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MISSION_UPDATE pprz_msg_send_MISSION_UPDATE
#define DOWNLINK_SEND_MISSION_UPDATE(_trans, _dev, ac_id, index, duration, nb_params, params) pprz_msg_send_MISSION_UPDATE(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, index, duration, nb_params, params)
/**
 * Sends a MISSION_UPDATE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id Aircraft ID
 * @param _index Index of mission element to update
 * @param _duration Duration of the element, -1 for unlimited, -9 for no change
 * @param nb_params,_params List of parameters, 12 max
 */
static inline void pprz_msg_send_MISSION_UPDATE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_index, float *_duration, uint8_t nb_params, float *_params) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MISSION_UPDATE(&msg,_ac_id,_index,_duration,nb_params,_params);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MISSION_UPDATE(_trans, _dev, ac_id, index, duration, nb_params, params) {}
static inline void pprz_send_msg_MISSION_UPDATE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_index __attribute__((unused)), float *_duration __attribute__((unused)), uint8_t nb_params __attribute__((unused)), float *_params __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message MISSION_UPDATE
  *
  * @param _payload : a pointer to the MISSION_UPDATE message
  * @return Aircraft ID
  */
static inline uint8_t pprzlink_get_DL_MISSION_UPDATE_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field index in message MISSION_UPDATE
  *
  * @param _payload : a pointer to the MISSION_UPDATE message
  * @return Index of mission element to update
  */
static inline uint8_t pprzlink_get_DL_MISSION_UPDATE_index(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field duration in message MISSION_UPDATE
  *
  * @param _payload : a pointer to the MISSION_UPDATE message
  * @return Duration of the element, -1 for unlimited, -9 for no change
  */
static inline float pprzlink_get_DL_MISSION_UPDATE_duration(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}

/** Getter for length of array params in message MISSION_UPDATE
 *
 * @return params : List of parameters, 12 max
 */
 static inline uint8_t pprzlink_get_MISSION_UPDATE_params_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 10);
}

/** Getter for field params in message MISSION_UPDATE
  *
  * @param _payload : a pointer to the MISSION_UPDATE message
  * @return List of parameters, 12 max
  */
static inline float * pprzlink_get_DL_MISSION_UPDATE_params(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 11);
}


/* Compatibility macros */
#define DL_MISSION_UPDATE_ac_id(_payload) pprzlink_get_DL_MISSION_UPDATE_ac_id(_payload)
#define DL_MISSION_UPDATE_index(_payload) pprzlink_get_DL_MISSION_UPDATE_index(_payload)
#define DL_MISSION_UPDATE_duration(_payload) pprzlink_get_DL_MISSION_UPDATE_duration(_payload)
#define DL_MISSION_UPDATE_params_length(_payload) pprzlink_get_MISSION_UPDATE_params_length(_payload)
#define DL_MISSION_UPDATE_params(_payload) pprzlink_get_DL_MISSION_UPDATE_params(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_MISSION_UPDATE_H_

