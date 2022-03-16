/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_NAV_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_NAV_STATUS_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_NAV_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_NAV_STATUS 159
#define PPRZ_MSG_ID_ROTORCRAFT_NAV_STATUS 159

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_NAV_STATUS _send_msg(ROTORCRAFT_NAV_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_NAV_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _block_time 
 * @param _stage_time 
 * @param _dist_home 
 * @param _dist_wp 
 * @param _cur_block 
 * @param _cur_stage 
 * @param _horizontal_mode 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_NAV_STATUS(struct pprzlink_msg * msg, uint16_t *_block_time, uint16_t *_stage_time, float *_dist_home, float *_dist_wp, uint8_t *_cur_block, uint8_t *_cur_stage, uint8_t *_horizontal_mode) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+4+4+1+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+4+4+1+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_NAV_STATUS, "ROTORCRAFT_NAV_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _block_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _stage_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _dist_home, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _dist_wp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cur_block, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cur_stage, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _horizontal_mode, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_NAV_STATUS pprz_msg_send_ROTORCRAFT_NAV_STATUS
#define DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(_trans, _dev, block_time, stage_time, dist_home, dist_wp, cur_block, cur_stage, horizontal_mode) pprz_msg_send_ROTORCRAFT_NAV_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, block_time, stage_time, dist_home, dist_wp, cur_block, cur_stage, horizontal_mode)
/**
 * Sends a ROTORCRAFT_NAV_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _block_time 
 * @param _stage_time 
 * @param _dist_home 
 * @param _dist_wp 
 * @param _cur_block 
 * @param _cur_stage 
 * @param _horizontal_mode 
 */
static inline void pprz_msg_send_ROTORCRAFT_NAV_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_block_time, uint16_t *_stage_time, float *_dist_home, float *_dist_wp, uint8_t *_cur_block, uint8_t *_cur_stage, uint8_t *_horizontal_mode) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_NAV_STATUS(&msg,_block_time,_stage_time,_dist_home,_dist_wp,_cur_block,_cur_stage,_horizontal_mode);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(_trans, _dev, block_time, stage_time, dist_home, dist_wp, cur_block, cur_stage, horizontal_mode) {}
static inline void pprz_send_msg_ROTORCRAFT_NAV_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_block_time __attribute__((unused)), uint16_t *_stage_time __attribute__((unused)), float *_dist_home __attribute__((unused)), float *_dist_wp __attribute__((unused)), uint8_t *_cur_block __attribute__((unused)), uint8_t *_cur_stage __attribute__((unused)), uint8_t *_horizontal_mode __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field block_time in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_block_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field stage_time in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_stage_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field dist_home in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_dist_home(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field dist_wp in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_dist_wp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field cur_block in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_cur_block(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/** Getter for field cur_stage in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_cur_stage(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 17);
}


/** Getter for field horizontal_mode in message ROTORCRAFT_NAV_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_NAV_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_horizontal_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 18);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_NAV_STATUS_block_time(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_block_time(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_stage_time(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_stage_time(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_dist_home(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_dist_home(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_dist_wp(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_dist_wp(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_cur_block(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_cur_block(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_cur_stage(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_cur_stage(_payload)
#define DL_ROTORCRAFT_NAV_STATUS_horizontal_mode(_payload) pprzlink_get_DL_ROTORCRAFT_NAV_STATUS_horizontal_mode(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_NAV_STATUS_H_

