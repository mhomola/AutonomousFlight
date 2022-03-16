/** @file
 *  @brief PPRZLink message header for NPS_SPEED_POS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_SPEED_POS_H_
#define _VAR_MESSAGES_telemetry_NPS_SPEED_POS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_SPEED_POS 240
#define PPRZ_MSG_ID_NPS_SPEED_POS 240

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_SPEED_POS _send_msg(NPS_SPEED_POS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_SPEED_POS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ltpp_xdd 
 * @param _ltpp_ydd 
 * @param _ltpp_zdd 
 * @param _ltpp_xd 
 * @param _ltpp_yd 
 * @param _ltpp_zd 
 * @param _ltpp_x 
 * @param _ltpp_y 
 * @param _ltpp_z 
 */
static inline void pprzlink_msg_v2_send_NPS_SPEED_POS(struct pprzlink_msg * msg, float *_ltpp_xdd, float *_ltpp_ydd, float *_ltpp_zdd, float *_ltpp_xd, float *_ltpp_yd, float *_ltpp_zd, float *_ltpp_x, float *_ltpp_y, float *_ltpp_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_SPEED_POS, "NPS_SPEED_POS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_xdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_ydd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_zdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_xd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_yd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ltpp_z, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_SPEED_POS pprz_msg_send_NPS_SPEED_POS
#define DOWNLINK_SEND_NPS_SPEED_POS(_trans, _dev, ltpp_xdd, ltpp_ydd, ltpp_zdd, ltpp_xd, ltpp_yd, ltpp_zd, ltpp_x, ltpp_y, ltpp_z) pprz_msg_send_NPS_SPEED_POS(&((_trans).trans_tx), &((_dev).device), AC_ID, ltpp_xdd, ltpp_ydd, ltpp_zdd, ltpp_xd, ltpp_yd, ltpp_zd, ltpp_x, ltpp_y, ltpp_z)
/**
 * Sends a NPS_SPEED_POS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ltpp_xdd 
 * @param _ltpp_ydd 
 * @param _ltpp_zdd 
 * @param _ltpp_xd 
 * @param _ltpp_yd 
 * @param _ltpp_zd 
 * @param _ltpp_x 
 * @param _ltpp_y 
 * @param _ltpp_z 
 */
static inline void pprz_msg_send_NPS_SPEED_POS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_ltpp_xdd, float *_ltpp_ydd, float *_ltpp_zdd, float *_ltpp_xd, float *_ltpp_yd, float *_ltpp_zd, float *_ltpp_x, float *_ltpp_y, float *_ltpp_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_SPEED_POS(&msg,_ltpp_xdd,_ltpp_ydd,_ltpp_zdd,_ltpp_xd,_ltpp_yd,_ltpp_zd,_ltpp_x,_ltpp_y,_ltpp_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_SPEED_POS(_trans, _dev, ltpp_xdd, ltpp_ydd, ltpp_zdd, ltpp_xd, ltpp_yd, ltpp_zd, ltpp_x, ltpp_y, ltpp_z) {}
static inline void pprz_send_msg_NPS_SPEED_POS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_ltpp_xdd __attribute__((unused)), float *_ltpp_ydd __attribute__((unused)), float *_ltpp_zdd __attribute__((unused)), float *_ltpp_xd __attribute__((unused)), float *_ltpp_yd __attribute__((unused)), float *_ltpp_zd __attribute__((unused)), float *_ltpp_x __attribute__((unused)), float *_ltpp_y __attribute__((unused)), float *_ltpp_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ltpp_xdd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_xdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field ltpp_ydd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_ydd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field ltpp_zdd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ltpp_xd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_xd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ltpp_yd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_yd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ltpp_zd in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field ltpp_x in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field ltpp_y in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field ltpp_z in message NPS_SPEED_POS
  *
  * @param _payload : a pointer to the NPS_SPEED_POS message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SPEED_POS_ltpp_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/* Compatibility macros */
#define DL_NPS_SPEED_POS_ltpp_xdd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_xdd(_payload)
#define DL_NPS_SPEED_POS_ltpp_ydd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_ydd(_payload)
#define DL_NPS_SPEED_POS_ltpp_zdd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_zdd(_payload)
#define DL_NPS_SPEED_POS_ltpp_xd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_xd(_payload)
#define DL_NPS_SPEED_POS_ltpp_yd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_yd(_payload)
#define DL_NPS_SPEED_POS_ltpp_zd(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_zd(_payload)
#define DL_NPS_SPEED_POS_ltpp_x(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_x(_payload)
#define DL_NPS_SPEED_POS_ltpp_y(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_y(_payload)
#define DL_NPS_SPEED_POS_ltpp_z(_payload) pprzlink_get_DL_NPS_SPEED_POS_ltpp_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_SPEED_POS_H_

