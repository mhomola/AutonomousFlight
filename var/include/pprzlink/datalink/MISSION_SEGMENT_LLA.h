/** @file
 *  @brief PPRZLink message header for MISSION_SEGMENT_LLA in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_MISSION_SEGMENT_LLA_H_
#define _VAR_MESSAGES_datalink_MISSION_SEGMENT_LLA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MISSION_SEGMENT_LLA 25
#define PPRZ_MSG_ID_MISSION_SEGMENT_LLA 25

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MISSION_SEGMENT_LLA _send_msg(MISSION_SEGMENT_LLA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MISSION_SEGMENT_LLA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _insert 
 * @param _segment_lat_1 
 * @param _segment_lon_1 
 * @param _segment_lat_2 
 * @param _segment_lon_2 
 * @param _segment_alt altitude above geoid (MSL)
 * @param _duration 
 * @param _index 
 */
static inline void pprzlink_msg_v2_send_MISSION_SEGMENT_LLA(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_insert, int32_t *_segment_lat_1, int32_t *_segment_lon_1, int32_t *_segment_lat_2, int32_t *_segment_lon_2, int32_t *_segment_alt, float *_duration, uint8_t *_index) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MISSION_SEGMENT_LLA, "MISSION_SEGMENT_LLA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _insert, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _segment_lat_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _segment_lon_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _segment_lat_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _segment_lon_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _segment_alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _duration, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _index, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MISSION_SEGMENT_LLA pprz_msg_send_MISSION_SEGMENT_LLA
#define DOWNLINK_SEND_MISSION_SEGMENT_LLA(_trans, _dev, ac_id, insert, segment_lat_1, segment_lon_1, segment_lat_2, segment_lon_2, segment_alt, duration, index) pprz_msg_send_MISSION_SEGMENT_LLA(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, insert, segment_lat_1, segment_lon_1, segment_lat_2, segment_lon_2, segment_alt, duration, index)
/**
 * Sends a MISSION_SEGMENT_LLA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _insert 
 * @param _segment_lat_1 
 * @param _segment_lon_1 
 * @param _segment_lat_2 
 * @param _segment_lon_2 
 * @param _segment_alt altitude above geoid (MSL)
 * @param _duration 
 * @param _index 
 */
static inline void pprz_msg_send_MISSION_SEGMENT_LLA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_insert, int32_t *_segment_lat_1, int32_t *_segment_lon_1, int32_t *_segment_lat_2, int32_t *_segment_lon_2, int32_t *_segment_alt, float *_duration, uint8_t *_index) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MISSION_SEGMENT_LLA(&msg,_ac_id,_insert,_segment_lat_1,_segment_lon_1,_segment_lat_2,_segment_lon_2,_segment_alt,_duration,_index);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MISSION_SEGMENT_LLA(_trans, _dev, ac_id, insert, segment_lat_1, segment_lon_1, segment_lat_2, segment_lon_2, segment_alt, duration, index) {}
static inline void pprz_send_msg_MISSION_SEGMENT_LLA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_insert __attribute__((unused)), int32_t *_segment_lat_1 __attribute__((unused)), int32_t *_segment_lon_1 __attribute__((unused)), int32_t *_segment_lat_2 __attribute__((unused)), int32_t *_segment_lon_2 __attribute__((unused)), int32_t *_segment_alt __attribute__((unused)), float *_duration __attribute__((unused)), uint8_t *_index __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_SEGMENT_LLA_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field insert in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_SEGMENT_LLA_insert(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field segment_lat_1 in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lat_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field segment_lon_1 in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lon_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field segment_lat_2 in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lat_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field segment_lon_2 in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lon_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field segment_alt in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return altitude above geoid (MSL)
  */
static inline int32_t pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 22);
}


/** Getter for field duration in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline float pprzlink_get_DL_MISSION_SEGMENT_LLA_duration(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/** Getter for field index in message MISSION_SEGMENT_LLA
  *
  * @param _payload : a pointer to the MISSION_SEGMENT_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_SEGMENT_LLA_index(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 30);
}


/* Compatibility macros */
#define DL_MISSION_SEGMENT_LLA_ac_id(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_ac_id(_payload)
#define DL_MISSION_SEGMENT_LLA_insert(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_insert(_payload)
#define DL_MISSION_SEGMENT_LLA_segment_lat_1(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lat_1(_payload)
#define DL_MISSION_SEGMENT_LLA_segment_lon_1(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lon_1(_payload)
#define DL_MISSION_SEGMENT_LLA_segment_lat_2(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lat_2(_payload)
#define DL_MISSION_SEGMENT_LLA_segment_lon_2(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_lon_2(_payload)
#define DL_MISSION_SEGMENT_LLA_segment_alt(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_segment_alt(_payload)
#define DL_MISSION_SEGMENT_LLA_duration(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_duration(_payload)
#define DL_MISSION_SEGMENT_LLA_index(_payload) pprzlink_get_DL_MISSION_SEGMENT_LLA_index(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_MISSION_SEGMENT_LLA_H_

