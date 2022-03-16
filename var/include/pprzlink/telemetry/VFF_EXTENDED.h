/** @file
 *  @brief PPRZLink message header for VFF_EXTENDED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VFF_EXTENDED_H_
#define _VAR_MESSAGES_telemetry_VFF_EXTENDED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VFF_EXTENDED 161
#define PPRZ_MSG_ID_VFF_EXTENDED 161

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VFF_EXTENDED _send_msg(VFF_EXTENDED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VFF_EXTENDED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _meas_baro 
 * @param _meas_alt 
 * @param _z 
 * @param _zd 
 * @param _zdd 
 * @param _bias 
 * @param _offset 
 * @param _obs_height 
 * @param _Pzz 
 * @param _Pzdzd 
 * @param _Pbb 
 * @param _Poffsetoffset 
 * @param _Pobsobs 
 */
static inline void pprzlink_msg_v2_send_VFF_EXTENDED(struct pprzlink_msg * msg, float *_meas_baro, float *_meas_alt, float *_z, float *_zd, float *_zdd, float *_bias, float *_offset, float *_obs_height, float *_Pzz, float *_Pzdzd, float *_Pbb, float *_Poffsetoffset, float *_Pobsobs) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VFF_EXTENDED, "VFF_EXTENDED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _meas_baro, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _meas_alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _zdd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _offset, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _obs_height, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pzz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pzdzd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pbb, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Poffsetoffset, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pobsobs, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VFF_EXTENDED pprz_msg_send_VFF_EXTENDED
#define DOWNLINK_SEND_VFF_EXTENDED(_trans, _dev, meas_baro, meas_alt, z, zd, zdd, bias, offset, obs_height, Pzz, Pzdzd, Pbb, Poffsetoffset, Pobsobs) pprz_msg_send_VFF_EXTENDED(&((_trans).trans_tx), &((_dev).device), AC_ID, meas_baro, meas_alt, z, zd, zdd, bias, offset, obs_height, Pzz, Pzdzd, Pbb, Poffsetoffset, Pobsobs)
/**
 * Sends a VFF_EXTENDED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _meas_baro 
 * @param _meas_alt 
 * @param _z 
 * @param _zd 
 * @param _zdd 
 * @param _bias 
 * @param _offset 
 * @param _obs_height 
 * @param _Pzz 
 * @param _Pzdzd 
 * @param _Pbb 
 * @param _Poffsetoffset 
 * @param _Pobsobs 
 */
static inline void pprz_msg_send_VFF_EXTENDED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_meas_baro, float *_meas_alt, float *_z, float *_zd, float *_zdd, float *_bias, float *_offset, float *_obs_height, float *_Pzz, float *_Pzdzd, float *_Pbb, float *_Poffsetoffset, float *_Pobsobs) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VFF_EXTENDED(&msg,_meas_baro,_meas_alt,_z,_zd,_zdd,_bias,_offset,_obs_height,_Pzz,_Pzdzd,_Pbb,_Poffsetoffset,_Pobsobs);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VFF_EXTENDED(_trans, _dev, meas_baro, meas_alt, z, zd, zdd, bias, offset, obs_height, Pzz, Pzdzd, Pbb, Poffsetoffset, Pobsobs) {}
static inline void pprz_send_msg_VFF_EXTENDED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_meas_baro __attribute__((unused)), float *_meas_alt __attribute__((unused)), float *_z __attribute__((unused)), float *_zd __attribute__((unused)), float *_zdd __attribute__((unused)), float *_bias __attribute__((unused)), float *_offset __attribute__((unused)), float *_obs_height __attribute__((unused)), float *_Pzz __attribute__((unused)), float *_Pzdzd __attribute__((unused)), float *_Pbb __attribute__((unused)), float *_Poffsetoffset __attribute__((unused)), float *_Pobsobs __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field meas_baro in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_meas_baro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field meas_alt in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_meas_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field z in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field zd in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field zdd in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_zdd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field bias in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_bias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field offset in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_offset(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field obs_height in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_obs_height(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field Pzz in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_Pzz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field Pzdzd in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_Pzdzd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field Pbb in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_Pbb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field Poffsetoffset in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_Poffsetoffset(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field Pobsobs in message VFF_EXTENDED
  *
  * @param _payload : a pointer to the VFF_EXTENDED message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_EXTENDED_Pobsobs(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/* Compatibility macros */
#define DL_VFF_EXTENDED_meas_baro(_payload) pprzlink_get_DL_VFF_EXTENDED_meas_baro(_payload)
#define DL_VFF_EXTENDED_meas_alt(_payload) pprzlink_get_DL_VFF_EXTENDED_meas_alt(_payload)
#define DL_VFF_EXTENDED_z(_payload) pprzlink_get_DL_VFF_EXTENDED_z(_payload)
#define DL_VFF_EXTENDED_zd(_payload) pprzlink_get_DL_VFF_EXTENDED_zd(_payload)
#define DL_VFF_EXTENDED_zdd(_payload) pprzlink_get_DL_VFF_EXTENDED_zdd(_payload)
#define DL_VFF_EXTENDED_bias(_payload) pprzlink_get_DL_VFF_EXTENDED_bias(_payload)
#define DL_VFF_EXTENDED_offset(_payload) pprzlink_get_DL_VFF_EXTENDED_offset(_payload)
#define DL_VFF_EXTENDED_obs_height(_payload) pprzlink_get_DL_VFF_EXTENDED_obs_height(_payload)
#define DL_VFF_EXTENDED_Pzz(_payload) pprzlink_get_DL_VFF_EXTENDED_Pzz(_payload)
#define DL_VFF_EXTENDED_Pzdzd(_payload) pprzlink_get_DL_VFF_EXTENDED_Pzdzd(_payload)
#define DL_VFF_EXTENDED_Pbb(_payload) pprzlink_get_DL_VFF_EXTENDED_Pbb(_payload)
#define DL_VFF_EXTENDED_Poffsetoffset(_payload) pprzlink_get_DL_VFF_EXTENDED_Poffsetoffset(_payload)
#define DL_VFF_EXTENDED_Pobsobs(_payload) pprzlink_get_DL_VFF_EXTENDED_Pobsobs(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VFF_EXTENDED_H_

