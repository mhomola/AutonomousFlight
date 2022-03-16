/** @file
 *  @brief PPRZLink message header for MISSION_PATH_LLA in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_MISSION_PATH_LLA_H_
#define _VAR_MESSAGES_datalink_MISSION_PATH_LLA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MISSION_PATH_LLA 27
#define PPRZ_MSG_ID_MISSION_PATH_LLA 27

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MISSION_PATH_LLA _send_msg(MISSION_PATH_LLA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MISSION_PATH_LLA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _insert 
 * @param _point_lat_1 
 * @param _point_lon_1 
 * @param _point_lat_2 
 * @param _point_lon_2 
 * @param _point_lat_3 
 * @param _point_lon_3 
 * @param _point_lat_4 
 * @param _point_lon_4 
 * @param _point_lat_5 
 * @param _point_lon_5 
 * @param _path_alt altitude above geoid (MSL)
 * @param _duration 
 * @param _nb 
 * @param _index 
 */
static inline void pprzlink_msg_v2_send_MISSION_PATH_LLA(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_insert, int32_t *_point_lat_1, int32_t *_point_lon_1, int32_t *_point_lat_2, int32_t *_point_lon_2, int32_t *_point_lat_3, int32_t *_point_lon_3, int32_t *_point_lat_4, int32_t *_point_lon_4, int32_t *_point_lat_5, int32_t *_point_lon_5, int32_t *_path_alt, float *_duration, uint8_t *_nb, uint8_t *_index) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MISSION_PATH_LLA, "MISSION_PATH_LLA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _insert, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lat_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lon_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lat_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lon_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lat_3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lon_3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lat_4, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lon_4, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lat_5, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _point_lon_5, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _path_alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _duration, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nb, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _index, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MISSION_PATH_LLA pprz_msg_send_MISSION_PATH_LLA
#define DOWNLINK_SEND_MISSION_PATH_LLA(_trans, _dev, ac_id, insert, point_lat_1, point_lon_1, point_lat_2, point_lon_2, point_lat_3, point_lon_3, point_lat_4, point_lon_4, point_lat_5, point_lon_5, path_alt, duration, nb, index) pprz_msg_send_MISSION_PATH_LLA(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, insert, point_lat_1, point_lon_1, point_lat_2, point_lon_2, point_lat_3, point_lon_3, point_lat_4, point_lon_4, point_lat_5, point_lon_5, path_alt, duration, nb, index)
/**
 * Sends a MISSION_PATH_LLA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _insert 
 * @param _point_lat_1 
 * @param _point_lon_1 
 * @param _point_lat_2 
 * @param _point_lon_2 
 * @param _point_lat_3 
 * @param _point_lon_3 
 * @param _point_lat_4 
 * @param _point_lon_4 
 * @param _point_lat_5 
 * @param _point_lon_5 
 * @param _path_alt altitude above geoid (MSL)
 * @param _duration 
 * @param _nb 
 * @param _index 
 */
static inline void pprz_msg_send_MISSION_PATH_LLA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_insert, int32_t *_point_lat_1, int32_t *_point_lon_1, int32_t *_point_lat_2, int32_t *_point_lon_2, int32_t *_point_lat_3, int32_t *_point_lon_3, int32_t *_point_lat_4, int32_t *_point_lon_4, int32_t *_point_lat_5, int32_t *_point_lon_5, int32_t *_path_alt, float *_duration, uint8_t *_nb, uint8_t *_index) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MISSION_PATH_LLA(&msg,_ac_id,_insert,_point_lat_1,_point_lon_1,_point_lat_2,_point_lon_2,_point_lat_3,_point_lon_3,_point_lat_4,_point_lon_4,_point_lat_5,_point_lon_5,_path_alt,_duration,_nb,_index);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MISSION_PATH_LLA(_trans, _dev, ac_id, insert, point_lat_1, point_lon_1, point_lat_2, point_lon_2, point_lat_3, point_lon_3, point_lat_4, point_lon_4, point_lat_5, point_lon_5, path_alt, duration, nb, index) {}
static inline void pprz_send_msg_MISSION_PATH_LLA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_insert __attribute__((unused)), int32_t *_point_lat_1 __attribute__((unused)), int32_t *_point_lon_1 __attribute__((unused)), int32_t *_point_lat_2 __attribute__((unused)), int32_t *_point_lon_2 __attribute__((unused)), int32_t *_point_lat_3 __attribute__((unused)), int32_t *_point_lon_3 __attribute__((unused)), int32_t *_point_lat_4 __attribute__((unused)), int32_t *_point_lon_4 __attribute__((unused)), int32_t *_point_lat_5 __attribute__((unused)), int32_t *_point_lon_5 __attribute__((unused)), int32_t *_path_alt __attribute__((unused)), float *_duration __attribute__((unused)), uint8_t *_nb __attribute__((unused)), uint8_t *_index __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_PATH_LLA_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field insert in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_PATH_LLA_insert(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field point_lat_1 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lat_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field point_lon_1 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lon_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field point_lat_2 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lat_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field point_lon_2 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lon_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field point_lat_3 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lat_3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 22);
}


/** Getter for field point_lon_3 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lon_3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 26);
}


/** Getter for field point_lat_4 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lat_4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 30);
}


/** Getter for field point_lon_4 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lon_4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 34);
}


/** Getter for field point_lat_5 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lat_5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 38);
}


/** Getter for field point_lon_5 in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_point_lon_5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 42);
}


/** Getter for field path_alt in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return altitude above geoid (MSL)
  */
static inline int32_t pprzlink_get_DL_MISSION_PATH_LLA_path_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 46);
}


/** Getter for field duration in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline float pprzlink_get_DL_MISSION_PATH_LLA_duration(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 50);
}


/** Getter for field nb in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_PATH_LLA_nb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 54);
}


/** Getter for field index in message MISSION_PATH_LLA
  *
  * @param _payload : a pointer to the MISSION_PATH_LLA message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_MISSION_PATH_LLA_index(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 55);
}


/* Compatibility macros */
#define DL_MISSION_PATH_LLA_ac_id(_payload) pprzlink_get_DL_MISSION_PATH_LLA_ac_id(_payload)
#define DL_MISSION_PATH_LLA_insert(_payload) pprzlink_get_DL_MISSION_PATH_LLA_insert(_payload)
#define DL_MISSION_PATH_LLA_point_lat_1(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lat_1(_payload)
#define DL_MISSION_PATH_LLA_point_lon_1(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lon_1(_payload)
#define DL_MISSION_PATH_LLA_point_lat_2(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lat_2(_payload)
#define DL_MISSION_PATH_LLA_point_lon_2(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lon_2(_payload)
#define DL_MISSION_PATH_LLA_point_lat_3(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lat_3(_payload)
#define DL_MISSION_PATH_LLA_point_lon_3(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lon_3(_payload)
#define DL_MISSION_PATH_LLA_point_lat_4(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lat_4(_payload)
#define DL_MISSION_PATH_LLA_point_lon_4(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lon_4(_payload)
#define DL_MISSION_PATH_LLA_point_lat_5(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lat_5(_payload)
#define DL_MISSION_PATH_LLA_point_lon_5(_payload) pprzlink_get_DL_MISSION_PATH_LLA_point_lon_5(_payload)
#define DL_MISSION_PATH_LLA_path_alt(_payload) pprzlink_get_DL_MISSION_PATH_LLA_path_alt(_payload)
#define DL_MISSION_PATH_LLA_duration(_payload) pprzlink_get_DL_MISSION_PATH_LLA_duration(_payload)
#define DL_MISSION_PATH_LLA_nb(_payload) pprzlink_get_DL_MISSION_PATH_LLA_nb(_payload)
#define DL_MISSION_PATH_LLA_index(_payload) pprzlink_get_DL_MISSION_PATH_LLA_index(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_MISSION_PATH_LLA_H_

