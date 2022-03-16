/** @file
 *  @brief PPRZLink message header for NPS_POS_LLH in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_POS_LLH_H_
#define _VAR_MESSAGES_telemetry_NPS_POS_LLH_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_POS_LLH 238
#define PPRZ_MSG_ID_NPS_POS_LLH 238

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_POS_LLH _send_msg(NPS_POS_LLH,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_POS_LLH message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pprz_lat 
 * @param _lat_geod 
 * @param _lat_geoc 
 * @param _pprz_lon 
 * @param _lon 
 * @param _pprz_alt 
 * @param _alt_geod 
 * @param _agl 
 * @param _asl 
 */
static inline void pprzlink_msg_v2_send_NPS_POS_LLH(struct pprzlink_msg * msg, float *_pprz_lat, float *_lat_geod, float *_lat_geoc, float *_pprz_lon, float *_lon, float *_pprz_alt, float *_alt_geod, float *_agl, float *_asl) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_POS_LLH, "NPS_POS_LLH");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pprz_lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lat_geod, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lat_geoc, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pprz_lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pprz_alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alt_geod, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _agl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _asl, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_POS_LLH pprz_msg_send_NPS_POS_LLH
#define DOWNLINK_SEND_NPS_POS_LLH(_trans, _dev, pprz_lat, lat_geod, lat_geoc, pprz_lon, lon, pprz_alt, alt_geod, agl, asl) pprz_msg_send_NPS_POS_LLH(&((_trans).trans_tx), &((_dev).device), AC_ID, pprz_lat, lat_geod, lat_geoc, pprz_lon, lon, pprz_alt, alt_geod, agl, asl)
/**
 * Sends a NPS_POS_LLH message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pprz_lat 
 * @param _lat_geod 
 * @param _lat_geoc 
 * @param _pprz_lon 
 * @param _lon 
 * @param _pprz_alt 
 * @param _alt_geod 
 * @param _agl 
 * @param _asl 
 */
static inline void pprz_msg_send_NPS_POS_LLH(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_pprz_lat, float *_lat_geod, float *_lat_geoc, float *_pprz_lon, float *_lon, float *_pprz_alt, float *_alt_geod, float *_agl, float *_asl) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_POS_LLH(&msg,_pprz_lat,_lat_geod,_lat_geoc,_pprz_lon,_lon,_pprz_alt,_alt_geod,_agl,_asl);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_POS_LLH(_trans, _dev, pprz_lat, lat_geod, lat_geoc, pprz_lon, lon, pprz_alt, alt_geod, agl, asl) {}
static inline void pprz_send_msg_NPS_POS_LLH(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_pprz_lat __attribute__((unused)), float *_lat_geod __attribute__((unused)), float *_lat_geoc __attribute__((unused)), float *_pprz_lon __attribute__((unused)), float *_lon __attribute__((unused)), float *_pprz_alt __attribute__((unused)), float *_alt_geod __attribute__((unused)), float *_agl __attribute__((unused)), float *_asl __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pprz_lat in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_pprz_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field lat_geod in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_lat_geod(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field lat_geoc in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_lat_geoc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field pprz_lon in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_pprz_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field lon in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field pprz_alt in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_pprz_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field alt_geod in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_alt_geod(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field agl in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_agl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field asl in message NPS_POS_LLH
  *
  * @param _payload : a pointer to the NPS_POS_LLH message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_POS_LLH_asl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/* Compatibility macros */
#define DL_NPS_POS_LLH_pprz_lat(_payload) pprzlink_get_DL_NPS_POS_LLH_pprz_lat(_payload)
#define DL_NPS_POS_LLH_lat_geod(_payload) pprzlink_get_DL_NPS_POS_LLH_lat_geod(_payload)
#define DL_NPS_POS_LLH_lat_geoc(_payload) pprzlink_get_DL_NPS_POS_LLH_lat_geoc(_payload)
#define DL_NPS_POS_LLH_pprz_lon(_payload) pprzlink_get_DL_NPS_POS_LLH_pprz_lon(_payload)
#define DL_NPS_POS_LLH_lon(_payload) pprzlink_get_DL_NPS_POS_LLH_lon(_payload)
#define DL_NPS_POS_LLH_pprz_alt(_payload) pprzlink_get_DL_NPS_POS_LLH_pprz_alt(_payload)
#define DL_NPS_POS_LLH_alt_geod(_payload) pprzlink_get_DL_NPS_POS_LLH_alt_geod(_payload)
#define DL_NPS_POS_LLH_agl(_payload) pprzlink_get_DL_NPS_POS_LLH_agl(_payload)
#define DL_NPS_POS_LLH_asl(_payload) pprzlink_get_DL_NPS_POS_LLH_asl(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_POS_LLH_H_

