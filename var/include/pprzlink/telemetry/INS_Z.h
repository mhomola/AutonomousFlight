/** @file
 *  @brief PPRZLink message header for INS_Z in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_Z_H_
#define _VAR_MESSAGES_telemetry_INS_Z_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS_Z 151
#define PPRZ_MSG_ID_INS_Z 151

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS_Z _send_msg(INS_Z,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS_Z message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _baro_z 
 * @param _ins_z 
 * @param _ins_zd 
 * @param _ins_zdd 
 */
static inline void pprzlink_msg_v2_send_INS_Z(struct pprzlink_msg * msg, float *_baro_z, int32_t *_ins_z, int32_t *_ins_zd, int32_t *_ins_zdd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS_Z, "INS_Z");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _baro_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ins_zdd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS_Z pprz_msg_send_INS_Z
#define DOWNLINK_SEND_INS_Z(_trans, _dev, baro_z, ins_z, ins_zd, ins_zdd) pprz_msg_send_INS_Z(&((_trans).trans_tx), &((_dev).device), AC_ID, baro_z, ins_z, ins_zd, ins_zdd)
/**
 * Sends a INS_Z message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _baro_z 
 * @param _ins_z 
 * @param _ins_zd 
 * @param _ins_zdd 
 */
static inline void pprz_msg_send_INS_Z(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_baro_z, int32_t *_ins_z, int32_t *_ins_zd, int32_t *_ins_zdd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS_Z(&msg,_baro_z,_ins_z,_ins_zd,_ins_zdd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS_Z(_trans, _dev, baro_z, ins_z, ins_zd, ins_zdd) {}
static inline void pprz_send_msg_INS_Z(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_baro_z __attribute__((unused)), int32_t *_ins_z __attribute__((unused)), int32_t *_ins_zd __attribute__((unused)), int32_t *_ins_zdd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field baro_z in message INS_Z
  *
  * @param _payload : a pointer to the INS_Z message
  * @return 
  */
static inline float pprzlink_get_DL_INS_Z_baro_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field ins_z in message INS_Z
  *
  * @param _payload : a pointer to the INS_Z message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_Z_ins_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ins_zd in message INS_Z
  *
  * @param _payload : a pointer to the INS_Z message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_Z_ins_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field ins_zdd in message INS_Z
  *
  * @param _payload : a pointer to the INS_Z message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_Z_ins_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/* Compatibility macros */
#define DL_INS_Z_baro_z(_payload) pprzlink_get_DL_INS_Z_baro_z(_payload)
#define DL_INS_Z_ins_z(_payload) pprzlink_get_DL_INS_Z_ins_z(_payload)
#define DL_INS_Z_ins_zd(_payload) pprzlink_get_DL_INS_Z_ins_zd(_payload)
#define DL_INS_Z_ins_zdd(_payload) pprzlink_get_DL_INS_Z_ins_zdd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_Z_H_

