/** @file
 *  @brief PPRZLink message header for INS_REF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_REF_H_
#define _VAR_MESSAGES_telemetry_INS_REF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS_REF 154
#define PPRZ_MSG_ID_INS_REF 154

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS_REF _send_msg(INS_REF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS_REF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ecef_x0 
 * @param _ecef_y0 
 * @param _ecef_z0 
 * @param _lat0 
 * @param _lon0 
 * @param _alt0 
 * @param _hmsl0 
 * @param _baro_qfe 
 */
static inline void pprzlink_msg_v2_send_INS_REF(struct pprzlink_msg * msg, int32_t *_ecef_x0, int32_t *_ecef_y0, int32_t *_ecef_z0, int32_t *_lat0, int32_t *_lon0, int32_t *_alt0, int32_t *_hmsl0, float *_baro_qfe) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS_REF, "INS_REF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_x0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_y0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _ecef_z0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lat0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _lon0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _alt0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _hmsl0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _baro_qfe, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS_REF pprz_msg_send_INS_REF
#define DOWNLINK_SEND_INS_REF(_trans, _dev, ecef_x0, ecef_y0, ecef_z0, lat0, lon0, alt0, hmsl0, baro_qfe) pprz_msg_send_INS_REF(&((_trans).trans_tx), &((_dev).device), AC_ID, ecef_x0, ecef_y0, ecef_z0, lat0, lon0, alt0, hmsl0, baro_qfe)
/**
 * Sends a INS_REF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ecef_x0 
 * @param _ecef_y0 
 * @param _ecef_z0 
 * @param _lat0 
 * @param _lon0 
 * @param _alt0 
 * @param _hmsl0 
 * @param _baro_qfe 
 */
static inline void pprz_msg_send_INS_REF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, int32_t *_ecef_x0, int32_t *_ecef_y0, int32_t *_ecef_z0, int32_t *_lat0, int32_t *_lon0, int32_t *_alt0, int32_t *_hmsl0, float *_baro_qfe) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS_REF(&msg,_ecef_x0,_ecef_y0,_ecef_z0,_lat0,_lon0,_alt0,_hmsl0,_baro_qfe);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS_REF(_trans, _dev, ecef_x0, ecef_y0, ecef_z0, lat0, lon0, alt0, hmsl0, baro_qfe) {}
static inline void pprz_send_msg_INS_REF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), int32_t *_ecef_x0 __attribute__((unused)), int32_t *_ecef_y0 __attribute__((unused)), int32_t *_ecef_z0 __attribute__((unused)), int32_t *_lat0 __attribute__((unused)), int32_t *_lon0 __attribute__((unused)), int32_t *_alt0 __attribute__((unused)), int32_t *_hmsl0 __attribute__((unused)), float *_baro_qfe __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ecef_x0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_ecef_x0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 4);
}


/** Getter for field ecef_y0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_ecef_y0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 8);
}


/** Getter for field ecef_z0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_ecef_z0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 12);
}


/** Getter for field lat0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_lat0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/** Getter for field lon0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_lon0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 20);
}


/** Getter for field alt0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_alt0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 24);
}


/** Getter for field hmsl0 in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_REF_hmsl0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 28);
}


/** Getter for field baro_qfe in message INS_REF
  *
  * @param _payload : a pointer to the INS_REF message
  * @return 
  */
static inline float pprzlink_get_DL_INS_REF_baro_qfe(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/* Compatibility macros */
#define DL_INS_REF_ecef_x0(_payload) pprzlink_get_DL_INS_REF_ecef_x0(_payload)
#define DL_INS_REF_ecef_y0(_payload) pprzlink_get_DL_INS_REF_ecef_y0(_payload)
#define DL_INS_REF_ecef_z0(_payload) pprzlink_get_DL_INS_REF_ecef_z0(_payload)
#define DL_INS_REF_lat0(_payload) pprzlink_get_DL_INS_REF_lat0(_payload)
#define DL_INS_REF_lon0(_payload) pprzlink_get_DL_INS_REF_lon0(_payload)
#define DL_INS_REF_alt0(_payload) pprzlink_get_DL_INS_REF_alt0(_payload)
#define DL_INS_REF_hmsl0(_payload) pprzlink_get_DL_INS_REF_hmsl0(_payload)
#define DL_INS_REF_baro_qfe(_payload) pprzlink_get_DL_INS_REF_baro_qfe(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_REF_H_

