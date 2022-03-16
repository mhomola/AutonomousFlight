/** @file
 *  @brief PPRZLink message header for GEO_MAG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_GEO_MAG_H_
#define _VAR_MESSAGES_telemetry_GEO_MAG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GEO_MAG 163
#define PPRZ_MSG_ID_GEO_MAG 163

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GEO_MAG _send_msg(GEO_MAG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GEO_MAG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _Hx 
 * @param _Hy 
 * @param _Hz 
 * @param _comp_id 
 */
static inline void pprzlink_msg_v2_send_GEO_MAG(struct pprzlink_msg * msg, float *_Hx, float *_Hy, float *_Hz, uint8_t *_comp_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GEO_MAG, "GEO_MAG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Hx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Hy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Hz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _comp_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GEO_MAG pprz_msg_send_GEO_MAG
#define DOWNLINK_SEND_GEO_MAG(_trans, _dev, Hx, Hy, Hz, comp_id) pprz_msg_send_GEO_MAG(&((_trans).trans_tx), &((_dev).device), AC_ID, Hx, Hy, Hz, comp_id)
/**
 * Sends a GEO_MAG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _Hx 
 * @param _Hy 
 * @param _Hz 
 * @param _comp_id 
 */
static inline void pprz_msg_send_GEO_MAG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_Hx, float *_Hy, float *_Hz, uint8_t *_comp_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GEO_MAG(&msg,_Hx,_Hy,_Hz,_comp_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GEO_MAG(_trans, _dev, Hx, Hy, Hz, comp_id) {}
static inline void pprz_send_msg_GEO_MAG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_Hx __attribute__((unused)), float *_Hy __attribute__((unused)), float *_Hz __attribute__((unused)), uint8_t *_comp_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field Hx in message GEO_MAG
  *
  * @param _payload : a pointer to the GEO_MAG message
  * @return 
  */
static inline float pprzlink_get_DL_GEO_MAG_Hx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field Hy in message GEO_MAG
  *
  * @param _payload : a pointer to the GEO_MAG message
  * @return 
  */
static inline float pprzlink_get_DL_GEO_MAG_Hy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field Hz in message GEO_MAG
  *
  * @param _payload : a pointer to the GEO_MAG message
  * @return 
  */
static inline float pprzlink_get_DL_GEO_MAG_Hz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field comp_id in message GEO_MAG
  *
  * @param _payload : a pointer to the GEO_MAG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GEO_MAG_comp_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/* Compatibility macros */
#define DL_GEO_MAG_Hx(_payload) pprzlink_get_DL_GEO_MAG_Hx(_payload)
#define DL_GEO_MAG_Hy(_payload) pprzlink_get_DL_GEO_MAG_Hy(_payload)
#define DL_GEO_MAG_Hz(_payload) pprzlink_get_DL_GEO_MAG_Hz(_payload)
#define DL_GEO_MAG_comp_id(_payload) pprzlink_get_DL_GEO_MAG_comp_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_GEO_MAG_H_

