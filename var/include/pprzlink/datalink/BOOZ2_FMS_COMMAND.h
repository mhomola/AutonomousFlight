/** @file
 *  @brief PPRZLink message header for BOOZ2_FMS_COMMAND in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_BOOZ2_FMS_COMMAND_H_
#define _VAR_MESSAGES_datalink_BOOZ2_FMS_COMMAND_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BOOZ2_FMS_COMMAND 149
#define PPRZ_MSG_ID_BOOZ2_FMS_COMMAND 149

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BOOZ2_FMS_COMMAND _send_msg(BOOZ2_FMS_COMMAND,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BOOZ2_FMS_COMMAND message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _h_mode 
 * @param _v_mode 
 * @param _v_sp 
 * @param _h_sp_1 
 * @param _h_sp_2 
 * @param _h_sp_3 
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_BOOZ2_FMS_COMMAND(struct pprzlink_msg * msg, uint8_t *_h_mode, uint8_t *_v_mode, int32_t *_v_sp, int32_t *_h_sp_1, int32_t *_h_sp_2, int32_t *_h_sp_3, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BOOZ2_FMS_COMMAND, "BOOZ2_FMS_COMMAND");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _h_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _v_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _v_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _h_sp_1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _h_sp_2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _h_sp_3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BOOZ2_FMS_COMMAND pprz_msg_send_BOOZ2_FMS_COMMAND
#define DOWNLINK_SEND_BOOZ2_FMS_COMMAND(_trans, _dev, h_mode, v_mode, v_sp, h_sp_1, h_sp_2, h_sp_3, ac_id) pprz_msg_send_BOOZ2_FMS_COMMAND(&((_trans).trans_tx), &((_dev).device), AC_ID, h_mode, v_mode, v_sp, h_sp_1, h_sp_2, h_sp_3, ac_id)
/**
 * Sends a BOOZ2_FMS_COMMAND message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _h_mode 
 * @param _v_mode 
 * @param _v_sp 
 * @param _h_sp_1 
 * @param _h_sp_2 
 * @param _h_sp_3 
 * @param _ac_id 
 */
static inline void pprz_msg_send_BOOZ2_FMS_COMMAND(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_h_mode, uint8_t *_v_mode, int32_t *_v_sp, int32_t *_h_sp_1, int32_t *_h_sp_2, int32_t *_h_sp_3, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BOOZ2_FMS_COMMAND(&msg,_h_mode,_v_mode,_v_sp,_h_sp_1,_h_sp_2,_h_sp_3,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BOOZ2_FMS_COMMAND(_trans, _dev, h_mode, v_mode, v_sp, h_sp_1, h_sp_2, h_sp_3, ac_id) {}
static inline void pprz_send_msg_BOOZ2_FMS_COMMAND(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_h_mode __attribute__((unused)), uint8_t *_v_mode __attribute__((unused)), int32_t *_v_sp __attribute__((unused)), int32_t *_h_sp_1 __attribute__((unused)), int32_t *_h_sp_2 __attribute__((unused)), int32_t *_h_sp_3 __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field h_mode in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field v_mode in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_v_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field v_sp in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_v_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 6);
}


/** Getter for field h_sp_1 in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 10);
}


/** Getter for field h_sp_2 in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 14);
}


/** Getter for field h_sp_3 in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline int32_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 18);
}


/** Getter for field ac_id in message BOOZ2_FMS_COMMAND
  *
  * @param _payload : a pointer to the BOOZ2_FMS_COMMAND message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_BOOZ2_FMS_COMMAND_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 22);
}


/* Compatibility macros */
#define DL_BOOZ2_FMS_COMMAND_h_mode(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_mode(_payload)
#define DL_BOOZ2_FMS_COMMAND_v_mode(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_v_mode(_payload)
#define DL_BOOZ2_FMS_COMMAND_v_sp(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_v_sp(_payload)
#define DL_BOOZ2_FMS_COMMAND_h_sp_1(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_1(_payload)
#define DL_BOOZ2_FMS_COMMAND_h_sp_2(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_2(_payload)
#define DL_BOOZ2_FMS_COMMAND_h_sp_3(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_h_sp_3(_payload)
#define DL_BOOZ2_FMS_COMMAND_ac_id(_payload) pprzlink_get_DL_BOOZ2_FMS_COMMAND_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_BOOZ2_FMS_COMMAND_H_

