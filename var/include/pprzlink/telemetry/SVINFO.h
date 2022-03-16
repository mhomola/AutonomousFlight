/** @file
 *  @brief PPRZLink message header for SVINFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SVINFO_H_
#define _VAR_MESSAGES_telemetry_SVINFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SVINFO 25
#define PPRZ_MSG_ID_SVINFO 25

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SVINFO _send_msg(SVINFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SVINFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _chn 
 * @param _SVID 
 * @param _Flags 
 * @param _QI 
 * @param _CNO 
 * @param _Elev 
 * @param _Azim 
 */
static inline void pprzlink_msg_v2_send_SVINFO(struct pprzlink_msg * msg, uint8_t *_chn, uint8_t *_SVID, uint8_t *_Flags, uint8_t *_QI, uint8_t *_CNO, int8_t *_Elev, int16_t *_Azim) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1+1+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1+1+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SVINFO, "SVINFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _chn, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _SVID, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _Flags, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _QI, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _CNO, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _Elev, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _Azim, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SVINFO pprz_msg_send_SVINFO
#define DOWNLINK_SEND_SVINFO(_trans, _dev, chn, SVID, Flags, QI, CNO, Elev, Azim) pprz_msg_send_SVINFO(&((_trans).trans_tx), &((_dev).device), AC_ID, chn, SVID, Flags, QI, CNO, Elev, Azim)
/**
 * Sends a SVINFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _chn 
 * @param _SVID 
 * @param _Flags 
 * @param _QI 
 * @param _CNO 
 * @param _Elev 
 * @param _Azim 
 */
static inline void pprz_msg_send_SVINFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_chn, uint8_t *_SVID, uint8_t *_Flags, uint8_t *_QI, uint8_t *_CNO, int8_t *_Elev, int16_t *_Azim) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SVINFO(&msg,_chn,_SVID,_Flags,_QI,_CNO,_Elev,_Azim);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SVINFO(_trans, _dev, chn, SVID, Flags, QI, CNO, Elev, Azim) {}
static inline void pprz_send_msg_SVINFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_chn __attribute__((unused)), uint8_t *_SVID __attribute__((unused)), uint8_t *_Flags __attribute__((unused)), uint8_t *_QI __attribute__((unused)), uint8_t *_CNO __attribute__((unused)), int8_t *_Elev __attribute__((unused)), int16_t *_Azim __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field chn in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SVINFO_chn(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field SVID in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SVINFO_SVID(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field Flags in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SVINFO_Flags(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field QI in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SVINFO_QI(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/** Getter for field CNO in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_SVINFO_CNO(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field Elev in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline int8_t pprzlink_get_DL_SVINFO_Elev(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 9);
}


/** Getter for field Azim in message SVINFO
  *
  * @param _payload : a pointer to the SVINFO message
  * @return 
  */
static inline int16_t pprzlink_get_DL_SVINFO_Azim(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 10);
}


/* Compatibility macros */
#define DL_SVINFO_chn(_payload) pprzlink_get_DL_SVINFO_chn(_payload)
#define DL_SVINFO_SVID(_payload) pprzlink_get_DL_SVINFO_SVID(_payload)
#define DL_SVINFO_Flags(_payload) pprzlink_get_DL_SVINFO_Flags(_payload)
#define DL_SVINFO_QI(_payload) pprzlink_get_DL_SVINFO_QI(_payload)
#define DL_SVINFO_CNO(_payload) pprzlink_get_DL_SVINFO_CNO(_payload)
#define DL_SVINFO_Elev(_payload) pprzlink_get_DL_SVINFO_Elev(_payload)
#define DL_SVINFO_Azim(_payload) pprzlink_get_DL_SVINFO_Azim(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SVINFO_H_

