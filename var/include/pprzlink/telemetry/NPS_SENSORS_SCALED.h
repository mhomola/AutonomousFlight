/** @file
 *  @brief PPRZLink message header for NPS_SENSORS_SCALED in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_NPS_SENSORS_SCALED_H_
#define _VAR_MESSAGES_telemetry_NPS_SENSORS_SCALED_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_NPS_SENSORS_SCALED 197
#define PPRZ_MSG_ID_NPS_SENSORS_SCALED 197

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_NPS_SENSORS_SCALED _send_msg(NPS_SENSORS_SCALED,PPRZLINK_DEFAULT_VER)

/**
 * Sends a NPS_SENSORS_SCALED message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _acc_x 
 * @param _acc_y 
 * @param _acc_z 
 * @param _mag_x 
 * @param _mag_y 
 * @param _mag_z 
 */
static inline void pprzlink_msg_v2_send_NPS_SENSORS_SCALED(struct pprzlink_msg * msg, float *_acc_x, float *_acc_y, float *_acc_z, float *_mag_x, float *_mag_y, float *_mag_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_NPS_SENSORS_SCALED, "NPS_SENSORS_SCALED");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _acc_z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_z, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_NPS_SENSORS_SCALED pprz_msg_send_NPS_SENSORS_SCALED
#define DOWNLINK_SEND_NPS_SENSORS_SCALED(_trans, _dev, acc_x, acc_y, acc_z, mag_x, mag_y, mag_z) pprz_msg_send_NPS_SENSORS_SCALED(&((_trans).trans_tx), &((_dev).device), AC_ID, acc_x, acc_y, acc_z, mag_x, mag_y, mag_z)
/**
 * Sends a NPS_SENSORS_SCALED message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _acc_x 
 * @param _acc_y 
 * @param _acc_z 
 * @param _mag_x 
 * @param _mag_y 
 * @param _mag_z 
 */
static inline void pprz_msg_send_NPS_SENSORS_SCALED(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_acc_x, float *_acc_y, float *_acc_z, float *_mag_x, float *_mag_y, float *_mag_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_NPS_SENSORS_SCALED(&msg,_acc_x,_acc_y,_acc_z,_mag_x,_mag_y,_mag_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_NPS_SENSORS_SCALED(_trans, _dev, acc_x, acc_y, acc_z, mag_x, mag_y, mag_z) {}
static inline void pprz_send_msg_NPS_SENSORS_SCALED(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_acc_x __attribute__((unused)), float *_acc_y __attribute__((unused)), float *_acc_z __attribute__((unused)), float *_mag_x __attribute__((unused)), float *_mag_y __attribute__((unused)), float *_mag_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field acc_x in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_acc_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field acc_y in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_acc_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field acc_z in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_acc_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field mag_x in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_mag_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field mag_y in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_mag_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field mag_z in message NPS_SENSORS_SCALED
  *
  * @param _payload : a pointer to the NPS_SENSORS_SCALED message
  * @return 
  */
static inline float pprzlink_get_DL_NPS_SENSORS_SCALED_mag_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/* Compatibility macros */
#define DL_NPS_SENSORS_SCALED_acc_x(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_acc_x(_payload)
#define DL_NPS_SENSORS_SCALED_acc_y(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_acc_y(_payload)
#define DL_NPS_SENSORS_SCALED_acc_z(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_acc_z(_payload)
#define DL_NPS_SENSORS_SCALED_mag_x(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_mag_x(_payload)
#define DL_NPS_SENSORS_SCALED_mag_y(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_mag_y(_payload)
#define DL_NPS_SENSORS_SCALED_mag_z(_payload) pprzlink_get_DL_NPS_SENSORS_SCALED_mag_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_NPS_SENSORS_SCALED_H_

