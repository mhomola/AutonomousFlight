/** @file
 *  @brief PPRZLink message header for BOOZ_NAV_STICK in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_BOOZ_NAV_STICK_H_
#define _VAR_MESSAGES_datalink_BOOZ_NAV_STICK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BOOZ_NAV_STICK 150
#define PPRZ_MSG_ID_BOOZ_NAV_STICK 150

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BOOZ_NAV_STICK _send_msg(BOOZ_NAV_STICK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BOOZ_NAV_STICK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _vx_sp 
 * @param _vy_sp 
 * @param _vz_sp 
 * @param _r_sp 
 */
static inline void pprzlink_msg_v2_send_BOOZ_NAV_STICK(struct pprzlink_msg * msg, uint8_t *_ac_id, int8_t *_vx_sp, int8_t *_vy_sp, int8_t *_vz_sp, int8_t *_r_sp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BOOZ_NAV_STICK, "BOOZ_NAV_STICK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _vx_sp, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _vy_sp, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _vz_sp, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT8, DL_FORMAT_SCALAR, (void *) _r_sp, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BOOZ_NAV_STICK pprz_msg_send_BOOZ_NAV_STICK
#define DOWNLINK_SEND_BOOZ_NAV_STICK(_trans, _dev, ac_id, vx_sp, vy_sp, vz_sp, r_sp) pprz_msg_send_BOOZ_NAV_STICK(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, vx_sp, vy_sp, vz_sp, r_sp)
/**
 * Sends a BOOZ_NAV_STICK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _vx_sp 
 * @param _vy_sp 
 * @param _vz_sp 
 * @param _r_sp 
 */
static inline void pprz_msg_send_BOOZ_NAV_STICK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, int8_t *_vx_sp, int8_t *_vy_sp, int8_t *_vz_sp, int8_t *_r_sp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BOOZ_NAV_STICK(&msg,_ac_id,_vx_sp,_vy_sp,_vz_sp,_r_sp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BOOZ_NAV_STICK(_trans, _dev, ac_id, vx_sp, vy_sp, vz_sp, r_sp) {}
static inline void pprz_send_msg_BOOZ_NAV_STICK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), int8_t *_vx_sp __attribute__((unused)), int8_t *_vy_sp __attribute__((unused)), int8_t *_vz_sp __attribute__((unused)), int8_t *_r_sp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message BOOZ_NAV_STICK
  *
  * @param _payload : a pointer to the BOOZ_NAV_STICK message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_BOOZ_NAV_STICK_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field vx_sp in message BOOZ_NAV_STICK
  *
  * @param _payload : a pointer to the BOOZ_NAV_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_BOOZ_NAV_STICK_vx_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 5);
}


/** Getter for field vy_sp in message BOOZ_NAV_STICK
  *
  * @param _payload : a pointer to the BOOZ_NAV_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_BOOZ_NAV_STICK_vy_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 6);
}


/** Getter for field vz_sp in message BOOZ_NAV_STICK
  *
  * @param _payload : a pointer to the BOOZ_NAV_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_BOOZ_NAV_STICK_vz_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 7);
}


/** Getter for field r_sp in message BOOZ_NAV_STICK
  *
  * @param _payload : a pointer to the BOOZ_NAV_STICK message
  * @return 
  */
static inline int8_t pprzlink_get_DL_BOOZ_NAV_STICK_r_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int8_t(_payload, 8);
}


/* Compatibility macros */
#define DL_BOOZ_NAV_STICK_ac_id(_payload) pprzlink_get_DL_BOOZ_NAV_STICK_ac_id(_payload)
#define DL_BOOZ_NAV_STICK_vx_sp(_payload) pprzlink_get_DL_BOOZ_NAV_STICK_vx_sp(_payload)
#define DL_BOOZ_NAV_STICK_vy_sp(_payload) pprzlink_get_DL_BOOZ_NAV_STICK_vy_sp(_payload)
#define DL_BOOZ_NAV_STICK_vz_sp(_payload) pprzlink_get_DL_BOOZ_NAV_STICK_vz_sp(_payload)
#define DL_BOOZ_NAV_STICK_r_sp(_payload) pprzlink_get_DL_BOOZ_NAV_STICK_r_sp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_BOOZ_NAV_STICK_H_

