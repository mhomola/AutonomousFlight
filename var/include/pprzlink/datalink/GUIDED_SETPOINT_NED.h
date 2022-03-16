/** @file
 *  @brief PPRZLink message header for GUIDED_SETPOINT_NED in class datalink
 *
 *  
        Set vehicle position or velocity in NED.
        Frame can be specified with the bits 0-3
        Velocity of position setpoint can be specified with the bits 5-7
        Flags field definition:
        - bit 0: x,y as offset coordinates
        - bit 1: x,y in body coordinates
        - bit 2: z as offset coordinates
        - bit 3: yaw as offset coordinates
        - bit 4: free
        - bit 5: x,y as vel
        - bit 6: z as vel
        - bit 7: yaw as rate
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_GUIDED_SETPOINT_NED_H_
#define _VAR_MESSAGES_datalink_GUIDED_SETPOINT_NED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GUIDED_SETPOINT_NED 40
#define PPRZ_MSG_ID_GUIDED_SETPOINT_NED 40

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GUIDED_SETPOINT_NED _send_msg(GUIDED_SETPOINT_NED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GUIDED_SETPOINT_NED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _flags bits 0-3: frame, bits 5-7: use as velocity
 * @param _x X position/velocity in NED
 * @param _y Y position/velocity in NED
 * @param _z Z position/velocity in NED (negative altitude)
 * @param _yaw yaw/rate setpoint
 */
static inline void pprzlink_msg_v2_send_GUIDED_SETPOINT_NED(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_flags, float *_x, float *_y, float *_z, float *_yaw) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GUIDED_SETPOINT_NED, "GUIDED_SETPOINT_NED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _flags, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _yaw, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GUIDED_SETPOINT_NED pprz_msg_send_GUIDED_SETPOINT_NED
#define DOWNLINK_SEND_GUIDED_SETPOINT_NED(_trans, _dev, ac_id, flags, x, y, z, yaw) pprz_msg_send_GUIDED_SETPOINT_NED(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, flags, x, y, z, yaw)
/**
 * Sends a GUIDED_SETPOINT_NED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _flags bits 0-3: frame, bits 5-7: use as velocity
 * @param _x X position/velocity in NED
 * @param _y Y position/velocity in NED
 * @param _z Z position/velocity in NED (negative altitude)
 * @param _yaw yaw/rate setpoint
 */
static inline void pprz_msg_send_GUIDED_SETPOINT_NED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_flags, float *_x, float *_y, float *_z, float *_yaw) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GUIDED_SETPOINT_NED(&msg,_ac_id,_flags,_x,_y,_z,_yaw);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GUIDED_SETPOINT_NED(_trans, _dev, ac_id, flags, x, y, z, yaw) {}
static inline void pprz_send_msg_GUIDED_SETPOINT_NED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_flags __attribute__((unused)), float *_x __attribute__((unused)), float *_y __attribute__((unused)), float *_z __attribute__((unused)), float *_yaw __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GUIDED_SETPOINT_NED_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field flags in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return bits 0-3: frame, bits 5-7: use as velocity
  */
static inline uint8_t pprzlink_get_DL_GUIDED_SETPOINT_NED_flags(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field x in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return X position/velocity in NED
  */
static inline float pprzlink_get_DL_GUIDED_SETPOINT_NED_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field y in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return Y position/velocity in NED
  */
static inline float pprzlink_get_DL_GUIDED_SETPOINT_NED_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field z in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return Z position/velocity in NED (negative altitude)
  */
static inline float pprzlink_get_DL_GUIDED_SETPOINT_NED_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field yaw in message GUIDED_SETPOINT_NED
  *
  * @param _payload : a pointer to the GUIDED_SETPOINT_NED message
  * @return yaw/rate setpoint
  */
static inline float pprzlink_get_DL_GUIDED_SETPOINT_NED_yaw(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/* Compatibility macros */
#define DL_GUIDED_SETPOINT_NED_ac_id(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_ac_id(_payload)
#define DL_GUIDED_SETPOINT_NED_flags(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_flags(_payload)
#define DL_GUIDED_SETPOINT_NED_x(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_x(_payload)
#define DL_GUIDED_SETPOINT_NED_y(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_y(_payload)
#define DL_GUIDED_SETPOINT_NED_z(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_z(_payload)
#define DL_GUIDED_SETPOINT_NED_yaw(_payload) pprzlink_get_DL_GUIDED_SETPOINT_NED_yaw(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_GUIDED_SETPOINT_NED_H_

