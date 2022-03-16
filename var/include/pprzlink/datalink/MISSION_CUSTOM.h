/** @file
 *  @brief PPRZLink message header for MISSION_CUSTOM in class datalink
 *
 *  
        Custom navigation pattern or action for mission controller.
        This will add the mission element correspond to the string identifier 'type' if it has been registered.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_MISSION_CUSTOM_H_
#define _VAR_MESSAGES_datalink_MISSION_CUSTOM_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MISSION_CUSTOM 28
#define PPRZ_MSG_ID_MISSION_CUSTOM 28

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MISSION_CUSTOM _send_msg(MISSION_CUSTOM,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MISSION_CUSTOM message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id Aircraft ID
 * @param _insert Insertion mode
 * @param _index Mission element index, should be unique
 * @param _type String identifier of the custom pattern
 * @param _duration Duration of the element or -1 for unlimited
 * @param nb_params,_params List of parameters, 12 max
 */
static inline void pprzlink_msg_v2_send_MISSION_CUSTOM(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_insert, uint8_t *_index, char *_type, float *_duration, uint8_t nb_params, float *_params) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+5*1+4+1+nb_params*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+5*1+4+1+nb_params*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MISSION_CUSTOM, "MISSION_CUSTOM");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _insert, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _index, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _type, 5*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _duration, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_params, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _params, nb_params*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MISSION_CUSTOM pprz_msg_send_MISSION_CUSTOM
#define DOWNLINK_SEND_MISSION_CUSTOM(_trans, _dev, ac_id, insert, index, type, duration, nb_params, params) pprz_msg_send_MISSION_CUSTOM(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, insert, index, type, duration, nb_params, params)
/**
 * Sends a MISSION_CUSTOM message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id Aircraft ID
 * @param _insert Insertion mode
 * @param _index Mission element index, should be unique
 * @param _type String identifier of the custom pattern
 * @param _duration Duration of the element or -1 for unlimited
 * @param nb_params,_params List of parameters, 12 max
 */
static inline void pprz_msg_send_MISSION_CUSTOM(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_insert, uint8_t *_index, char *_type, float *_duration, uint8_t nb_params, float *_params) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MISSION_CUSTOM(&msg,_ac_id,_insert,_index,_type,_duration,nb_params,_params);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MISSION_CUSTOM(_trans, _dev, ac_id, insert, index, type, duration, nb_params, params) {}
static inline void pprz_send_msg_MISSION_CUSTOM(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_insert __attribute__((unused)), uint8_t *_index __attribute__((unused)), char *_type __attribute__((unused)), float *_duration __attribute__((unused)), uint8_t nb_params __attribute__((unused)), float *_params __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return Aircraft ID
  */
static inline uint8_t pprzlink_get_DL_MISSION_CUSTOM_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field insert in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return Insertion mode
  */
static inline uint8_t pprzlink_get_DL_MISSION_CUSTOM_insert(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field index in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return Mission element index, should be unique
  */
static inline uint8_t pprzlink_get_DL_MISSION_CUSTOM_index(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for length of array type in message MISSION_CUSTOM
 *
 * @return type : String identifier of the custom pattern
 */
 static inline uint8_t pprzlink_get_MISSION_CUSTOM_type_length(void* _payload __attribute__ ((unused))) {
    return 5;
}

/** Getter for field type in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return String identifier of the custom pattern
  */
static inline char * pprzlink_get_DL_MISSION_CUSTOM_type(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 7);
}


/** Getter for field duration in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return Duration of the element or -1 for unlimited
  */
static inline float pprzlink_get_DL_MISSION_CUSTOM_duration(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}

/** Getter for length of array params in message MISSION_CUSTOM
 *
 * @return params : List of parameters, 12 max
 */
 static inline uint8_t pprzlink_get_MISSION_CUSTOM_params_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 16);
}

/** Getter for field params in message MISSION_CUSTOM
  *
  * @param _payload : a pointer to the MISSION_CUSTOM message
  * @return List of parameters, 12 max
  */
static inline float * pprzlink_get_DL_MISSION_CUSTOM_params(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 17);
}


/* Compatibility macros */
#define DL_MISSION_CUSTOM_ac_id(_payload) pprzlink_get_DL_MISSION_CUSTOM_ac_id(_payload)
#define DL_MISSION_CUSTOM_insert(_payload) pprzlink_get_DL_MISSION_CUSTOM_insert(_payload)
#define DL_MISSION_CUSTOM_index(_payload) pprzlink_get_DL_MISSION_CUSTOM_index(_payload)
#define DL_MISSION_CUSTOM_type_length(_payload) pprzlink_get_MISSION_CUSTOM_type_length(_payload)
#define DL_MISSION_CUSTOM_type(_payload) pprzlink_get_DL_MISSION_CUSTOM_type(_payload)
#define DL_MISSION_CUSTOM_duration(_payload) pprzlink_get_DL_MISSION_CUSTOM_duration(_payload)
#define DL_MISSION_CUSTOM_params_length(_payload) pprzlink_get_MISSION_CUSTOM_params_length(_payload)
#define DL_MISSION_CUSTOM_params(_payload) pprzlink_get_DL_MISSION_CUSTOM_params(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_MISSION_CUSTOM_H_

