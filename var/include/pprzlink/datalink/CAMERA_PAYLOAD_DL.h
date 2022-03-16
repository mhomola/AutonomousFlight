/** @file
 *  @brief PPRZLink message header for CAMERA_PAYLOAD_DL in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_CAMERA_PAYLOAD_DL_H_
#define _VAR_MESSAGES_datalink_CAMERA_PAYLOAD_DL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CAMERA_PAYLOAD_DL 34
#define PPRZ_MSG_ID_CAMERA_PAYLOAD_DL 34

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CAMERA_PAYLOAD_DL _send_msg(CAMERA_PAYLOAD_DL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CAMERA_PAYLOAD_DL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _error_code Error codes of the payload
 * @param _timestamp Payload computer seconds sice startup
 * @param _used_memory Percentage of used memory (RAM) of the payload computer rounded up to whole percent
 * @param _used_disk Percentage of used disk of the payload computer rounded up to whole percent
 * @param _door_status Payload door open/close
 */
static inline void pprzlink_msg_v2_send_CAMERA_PAYLOAD_DL(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_error_code, float *_timestamp, uint8_t *_used_memory, uint8_t *_used_disk, uint8_t *_door_status) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CAMERA_PAYLOAD_DL, "CAMERA_PAYLOAD_DL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _error_code, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _timestamp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _used_memory, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _used_disk, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _door_status, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CAMERA_PAYLOAD_DL pprz_msg_send_CAMERA_PAYLOAD_DL
#define DOWNLINK_SEND_CAMERA_PAYLOAD_DL(_trans, _dev, ac_id, error_code, timestamp, used_memory, used_disk, door_status) pprz_msg_send_CAMERA_PAYLOAD_DL(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, error_code, timestamp, used_memory, used_disk, door_status)
/**
 * Sends a CAMERA_PAYLOAD_DL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _error_code Error codes of the payload
 * @param _timestamp Payload computer seconds sice startup
 * @param _used_memory Percentage of used memory (RAM) of the payload computer rounded up to whole percent
 * @param _used_disk Percentage of used disk of the payload computer rounded up to whole percent
 * @param _door_status Payload door open/close
 */
static inline void pprz_msg_send_CAMERA_PAYLOAD_DL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_error_code, float *_timestamp, uint8_t *_used_memory, uint8_t *_used_disk, uint8_t *_door_status) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CAMERA_PAYLOAD_DL(&msg,_ac_id,_error_code,_timestamp,_used_memory,_used_disk,_door_status);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CAMERA_PAYLOAD_DL(_trans, _dev, ac_id, error_code, timestamp, used_memory, used_disk, door_status) {}
static inline void pprz_send_msg_CAMERA_PAYLOAD_DL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_error_code __attribute__((unused)), float *_timestamp __attribute__((unused)), uint8_t *_used_memory __attribute__((unused)), uint8_t *_used_disk __attribute__((unused)), uint8_t *_door_status __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_CAMERA_PAYLOAD_DL_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field error_code in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return Error codes of the payload
  */
static inline uint8_t pprzlink_get_DL_CAMERA_PAYLOAD_DL_error_code(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field timestamp in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return Payload computer seconds sice startup
  */
static inline float pprzlink_get_DL_CAMERA_PAYLOAD_DL_timestamp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field used_memory in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return Percentage of used memory (RAM) of the payload computer rounded up to whole percent
  */
static inline uint8_t pprzlink_get_DL_CAMERA_PAYLOAD_DL_used_memory(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 10);
}


/** Getter for field used_disk in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return Percentage of used disk of the payload computer rounded up to whole percent
  */
static inline uint8_t pprzlink_get_DL_CAMERA_PAYLOAD_DL_used_disk(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 11);
}


/** Getter for field door_status in message CAMERA_PAYLOAD_DL
  *
  * @param _payload : a pointer to the CAMERA_PAYLOAD_DL message
  * @return Payload door open/close
  */
static inline uint8_t pprzlink_get_DL_CAMERA_PAYLOAD_DL_door_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 12);
}


/* Compatibility macros */
#define DL_CAMERA_PAYLOAD_DL_ac_id(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_ac_id(_payload)
#define DL_CAMERA_PAYLOAD_DL_error_code(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_error_code(_payload)
#define DL_CAMERA_PAYLOAD_DL_timestamp(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_timestamp(_payload)
#define DL_CAMERA_PAYLOAD_DL_used_memory(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_used_memory(_payload)
#define DL_CAMERA_PAYLOAD_DL_used_disk(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_used_disk(_payload)
#define DL_CAMERA_PAYLOAD_DL_door_status(_payload) pprzlink_get_DL_CAMERA_PAYLOAD_DL_door_status(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_CAMERA_PAYLOAD_DL_H_

