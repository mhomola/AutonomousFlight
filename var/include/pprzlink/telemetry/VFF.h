/** @file
 *  @brief PPRZLink message header for VFF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_VFF_H_
#define _VAR_MESSAGES_telemetry_VFF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VFF 162
#define PPRZ_MSG_ID_VFF 162

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VFF _send_msg(VFF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VFF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _measure 
 * @param _z 
 * @param _zd 
 * @param _bias 
 * @param _Pzz 
 * @param _Pzdzd 
 * @param _Pbb 
 */
static inline void pprzlink_msg_v2_send_VFF(struct pprzlink_msg * msg, float *_measure, float *_z, float *_zd, float *_bias, float *_Pzz, float *_Pzdzd, float *_Pbb) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VFF, "VFF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _measure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _zd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _bias, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pzz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pzdzd, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Pbb, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VFF pprz_msg_send_VFF
#define DOWNLINK_SEND_VFF(_trans, _dev, measure, z, zd, bias, Pzz, Pzdzd, Pbb) pprz_msg_send_VFF(&((_trans).trans_tx), &((_dev).device), AC_ID, measure, z, zd, bias, Pzz, Pzdzd, Pbb)
/**
 * Sends a VFF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _measure 
 * @param _z 
 * @param _zd 
 * @param _bias 
 * @param _Pzz 
 * @param _Pzdzd 
 * @param _Pbb 
 */
static inline void pprz_msg_send_VFF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_measure, float *_z, float *_zd, float *_bias, float *_Pzz, float *_Pzdzd, float *_Pbb) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VFF(&msg,_measure,_z,_zd,_bias,_Pzz,_Pzdzd,_Pbb);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VFF(_trans, _dev, measure, z, zd, bias, Pzz, Pzdzd, Pbb) {}
static inline void pprz_send_msg_VFF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_measure __attribute__((unused)), float *_z __attribute__((unused)), float *_zd __attribute__((unused)), float *_bias __attribute__((unused)), float *_Pzz __attribute__((unused)), float *_Pzdzd __attribute__((unused)), float *_Pbb __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field measure in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_measure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field z in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field zd in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_zd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field bias in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_bias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field Pzz in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_Pzz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field Pzdzd in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_Pzdzd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field Pbb in message VFF
  *
  * @param _payload : a pointer to the VFF message
  * @return 
  */
static inline float pprzlink_get_DL_VFF_Pbb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/* Compatibility macros */
#define DL_VFF_measure(_payload) pprzlink_get_DL_VFF_measure(_payload)
#define DL_VFF_z(_payload) pprzlink_get_DL_VFF_z(_payload)
#define DL_VFF_zd(_payload) pprzlink_get_DL_VFF_zd(_payload)
#define DL_VFF_bias(_payload) pprzlink_get_DL_VFF_bias(_payload)
#define DL_VFF_Pzz(_payload) pprzlink_get_DL_VFF_Pzz(_payload)
#define DL_VFF_Pzdzd(_payload) pprzlink_get_DL_VFF_Pzdzd(_payload)
#define DL_VFF_Pbb(_payload) pprzlink_get_DL_VFF_Pbb(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_VFF_H_

