/** @file
 *  @brief PPRZLink message header for REMOTE_GPS_SMALL in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_REMOTE_GPS_SMALL_H_
#define _VAR_MESSAGES_datalink_REMOTE_GPS_SMALL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_REMOTE_GPS_SMALL 54
#define PPRZ_MSG_ID_REMOTE_GPS_SMALL 54

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_REMOTE_GPS_SMALL _send_msg(REMOTE_GPS_SMALL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a REMOTE_GPS_SMALL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _heading 
 * @param _pos_xyz bits 31-21 east position [cm] : bits 20-10 north position [cm] : bits 9-0 up position [cm]
 * @param _speed_xyz bits 31-21 east speed [cm/s] : bits 20-10 north speed [cm/s] : bits 9-0 climb speed [cm/s]
 * @param _tow 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_REMOTE_GPS_SMALL(struct pprzlink_msg * msg, int16_t *_heading, uint32_t *_pos_xyz, uint32_t *_speed_xyz, uint32_t *_tow, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_REMOTE_GPS_SMALL, "REMOTE_GPS_SMALL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _heading, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _pos_xyz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _speed_xyz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _tow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_REMOTE_GPS_SMALL pprz_msg_send_REMOTE_GPS_SMALL
#define DOWNLINK_SEND_REMOTE_GPS_SMALL(_trans, _dev, heading, pos_xyz, speed_xyz, tow, ac_id) pprz_msg_send_REMOTE_GPS_SMALL(&((_trans).trans_tx), &((_dev).device), AC_ID, heading, pos_xyz, speed_xyz, tow, ac_id)
/**
 * Sends a REMOTE_GPS_SMALL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _heading 
 * @param _pos_xyz bits 31-21 east position [cm] : bits 20-10 north position [cm] : bits 9-0 up position [cm]
 * @param _speed_xyz bits 31-21 east speed [cm/s] : bits 20-10 north speed [cm/s] : bits 9-0 climb speed [cm/s]
 * @param _tow 
 * @param _ac_id 
 */
static inline void pprz_msg_send_REMOTE_GPS_SMALL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int16_t *_heading, uint32_t *_pos_xyz, uint32_t *_speed_xyz, uint32_t *_tow, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_REMOTE_GPS_SMALL(&msg,_heading,_pos_xyz,_speed_xyz,_tow,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_REMOTE_GPS_SMALL(_trans, _dev, heading, pos_xyz, speed_xyz, tow, ac_id) {}
static inline void pprz_send_msg_REMOTE_GPS_SMALL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int16_t *_heading __attribute__((unused)), uint32_t *_pos_xyz __attribute__((unused)), uint32_t *_speed_xyz __attribute__((unused)), uint32_t *_tow __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field heading in message REMOTE_GPS_SMALL
  *
  * @param _payload : a pointer to the REMOTE_GPS_SMALL message
  * @return 
  */
static inline int16_t pprzlink_get_DL_REMOTE_GPS_SMALL_heading(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 4);
}


/** Getter for field pos_xyz in message REMOTE_GPS_SMALL
  *
  * @param _payload : a pointer to the REMOTE_GPS_SMALL message
  * @return bits 31-21 east position [cm] : bits 20-10 north position [cm] : bits 9-0 up position [cm]
  */
static inline uint32_t pprzlink_get_DL_REMOTE_GPS_SMALL_pos_xyz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}


/** Getter for field speed_xyz in message REMOTE_GPS_SMALL
  *
  * @param _payload : a pointer to the REMOTE_GPS_SMALL message
  * @return bits 31-21 east speed [cm/s] : bits 20-10 north speed [cm/s] : bits 9-0 climb speed [cm/s]
  */
static inline uint32_t pprzlink_get_DL_REMOTE_GPS_SMALL_speed_xyz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 10);
}


/** Getter for field tow in message REMOTE_GPS_SMALL
  *
  * @param _payload : a pointer to the REMOTE_GPS_SMALL message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_REMOTE_GPS_SMALL_tow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 14);
}


/** Getter for field ac_id in message REMOTE_GPS_SMALL
  *
  * @param _payload : a pointer to the REMOTE_GPS_SMALL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_REMOTE_GPS_SMALL_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 18);
}


/* Compatibility macros */
#define DL_REMOTE_GPS_SMALL_heading(_payload) pprzlink_get_DL_REMOTE_GPS_SMALL_heading(_payload)
#define DL_REMOTE_GPS_SMALL_pos_xyz(_payload) pprzlink_get_DL_REMOTE_GPS_SMALL_pos_xyz(_payload)
#define DL_REMOTE_GPS_SMALL_speed_xyz(_payload) pprzlink_get_DL_REMOTE_GPS_SMALL_speed_xyz(_payload)
#define DL_REMOTE_GPS_SMALL_tow(_payload) pprzlink_get_DL_REMOTE_GPS_SMALL_tow(_payload)
#define DL_REMOTE_GPS_SMALL_ac_id(_payload) pprzlink_get_DL_REMOTE_GPS_SMALL_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_REMOTE_GPS_SMALL_H_

