/** @file
 *  @brief PPRZLink message header for IMU_MAG_SETTINGS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_IMU_MAG_SETTINGS_H_
#define _VAR_MESSAGES_telemetry_IMU_MAG_SETTINGS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMU_MAG_SETTINGS 206
#define PPRZ_MSG_ID_IMU_MAG_SETTINGS 206

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMU_MAG_SETTINGS _send_msg(IMU_MAG_SETTINGS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMU_MAG_SETTINGS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _inclination 
 * @param _declination 
 * @param _hardiron_x 
 * @param _hardiron_y 
 * @param _hardiron_z 
 */
static inline void pprzlink_msg_v2_send_IMU_MAG_SETTINGS(struct pprzlink_msg * msg, float *_inclination, float *_declination, float *_hardiron_x, float *_hardiron_y, float *_hardiron_z) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMU_MAG_SETTINGS, "IMU_MAG_SETTINGS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _inclination, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _declination, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _hardiron_x, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _hardiron_y, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _hardiron_z, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMU_MAG_SETTINGS pprz_msg_send_IMU_MAG_SETTINGS
#define DOWNLINK_SEND_IMU_MAG_SETTINGS(_trans, _dev, inclination, declination, hardiron_x, hardiron_y, hardiron_z) pprz_msg_send_IMU_MAG_SETTINGS(&((_trans).trans_tx), &((_dev).device), AC_ID, inclination, declination, hardiron_x, hardiron_y, hardiron_z)
/**
 * Sends a IMU_MAG_SETTINGS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _inclination 
 * @param _declination 
 * @param _hardiron_x 
 * @param _hardiron_y 
 * @param _hardiron_z 
 */
static inline void pprz_msg_send_IMU_MAG_SETTINGS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_inclination, float *_declination, float *_hardiron_x, float *_hardiron_y, float *_hardiron_z) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMU_MAG_SETTINGS(&msg,_inclination,_declination,_hardiron_x,_hardiron_y,_hardiron_z);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMU_MAG_SETTINGS(_trans, _dev, inclination, declination, hardiron_x, hardiron_y, hardiron_z) {}
static inline void pprz_send_msg_IMU_MAG_SETTINGS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_inclination __attribute__((unused)), float *_declination __attribute__((unused)), float *_hardiron_x __attribute__((unused)), float *_hardiron_y __attribute__((unused)), float *_hardiron_z __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field inclination in message IMU_MAG_SETTINGS
  *
  * @param _payload : a pointer to the IMU_MAG_SETTINGS message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_MAG_SETTINGS_inclination(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field declination in message IMU_MAG_SETTINGS
  *
  * @param _payload : a pointer to the IMU_MAG_SETTINGS message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_MAG_SETTINGS_declination(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field hardiron_x in message IMU_MAG_SETTINGS
  *
  * @param _payload : a pointer to the IMU_MAG_SETTINGS message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_x(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field hardiron_y in message IMU_MAG_SETTINGS
  *
  * @param _payload : a pointer to the IMU_MAG_SETTINGS message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_y(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field hardiron_z in message IMU_MAG_SETTINGS
  *
  * @param _payload : a pointer to the IMU_MAG_SETTINGS message
  * @return 
  */
static inline float pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/* Compatibility macros */
#define DL_IMU_MAG_SETTINGS_inclination(_payload) pprzlink_get_DL_IMU_MAG_SETTINGS_inclination(_payload)
#define DL_IMU_MAG_SETTINGS_declination(_payload) pprzlink_get_DL_IMU_MAG_SETTINGS_declination(_payload)
#define DL_IMU_MAG_SETTINGS_hardiron_x(_payload) pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_x(_payload)
#define DL_IMU_MAG_SETTINGS_hardiron_y(_payload) pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_y(_payload)
#define DL_IMU_MAG_SETTINGS_hardiron_z(_payload) pprzlink_get_DL_IMU_MAG_SETTINGS_hardiron_z(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_IMU_MAG_SETTINGS_H_

