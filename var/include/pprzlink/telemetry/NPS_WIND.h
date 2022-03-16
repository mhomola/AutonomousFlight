/** @file
 *  @brief PPRZLink message header for NPS_WIND in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_WIND_H_
#define _VAR_MESSAGES_telemetry_NPS_WIND_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_WIND 244
#define PPRZ_MSG_ID_NPS_WIND 244

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_WIND _send_msg(NPS_WIND,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_WIND message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _vx 
 * @param _vy 
 * @param _vz 
 */
static inline void pprzlink_msg_v2_send_NPS_WIND(struct pprzlink_msg * msg, float *_vx, float *_vy, float *_vz) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_WIND, "NPS_WIND");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vz, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_WIND pprz_msg_send_NPS_WIND
#define DOWNLINK_SEND_NPS_WIND(_trans, _dev, vx, vy, vz) pprz_msg_send_NPS_WIND(&((_trans).trans_tx), &((_dev).device), AC_ID, vx, vy, vz)
/**
 * Sends a NPS_WIND message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _vx 
 * @param _vy 
 * @param _vz 
 */
static inline void pprz_msg_send_NPS_WIND(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_vx, float *_vy, float *_vz) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_WIND(&msg,_vx,_vy,_vz);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_WIND(_trans, _dev, vx, vy, vz) {}
static inline void pprz_send_msg_NPS_WIND(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_vx __attribute__((unused)), float *_vy __attribute__((unused)), float *_vz __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field vx in message NPS_WIND
  *
  * @param _payload : a pointer to the NPS_WIND message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_WIND_vx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field vy in message NPS_WIND
  *
  * @param _payload : a pointer to the NPS_WIND message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_WIND_vy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field vz in message NPS_WIND
  *
  * @param _payload : a pointer to the NPS_WIND message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_WIND_vz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/* Compatibility macros */
#define DL_NPS_WIND_vx(_payload) pprzlink_get_DL_NPS_WIND_vx(_payload)
#define DL_NPS_WIND_vy(_payload) pprzlink_get_DL_NPS_WIND_vy(_payload)
#define DL_NPS_WIND_vz(_payload) pprzlink_get_DL_NPS_WIND_vz(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_WIND_H_

