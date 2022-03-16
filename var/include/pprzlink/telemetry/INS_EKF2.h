/** @file
 *  @brief PPRZLink message header for INS_EKF2 in class telemetry
 *
 *  
        Extended Kalman Filter 2 status message which gives feedback about the input- and output states of the filter.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_EKF2_H_
#define _VAR_MESSAGES_telemetry_INS_EKF2_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS_EKF2 167
#define PPRZ_MSG_ID_INS_EKF2 167

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS_EKF2 _send_msg(INS_EKF2,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS_EKF2 message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _control_mode description of the control status (bitfields from common.h)
 * @param _filter_fault_status numerical errors in output states (bitfields from common.h)
 * @param _gps_check_status quality check of the GPS feedback (bitfields from common.h)
 * @param _soln_status which output states are valid or has an error (bitfields from common.h)
 * @param _innov_test_status which inputs exceed the innovation test
 * @param _innov_mag 
 * @param _innov_vel 
 * @param _innov_pos 
 * @param _innov_hgt 
 * @param _innov_tas 
 * @param _innov_hagl 
 * @param _innov_flow 
 * @param _innov_beta 
 * @param _mag_decl Magnetic declination
 * @param _terrain_status terrain detection for valid for ground sensors
 * @param _dead_reckoning active if all positioning sensors fail
 */
static inline void pprzlink_msg_v2_send_INS_EKF2(struct pprzlink_msg * msg, uint32_t *_control_mode, uint16_t *_filter_fault_status, uint16_t *_gps_check_status, uint16_t *_soln_status, uint16_t *_innov_test_status, float *_innov_mag, float *_innov_vel, float *_innov_pos, float *_innov_hgt, float *_innov_tas, float *_innov_hagl, float *_innov_flow, float *_innov_beta, float *_mag_decl, uint8_t *_terrain_status, uint8_t *_dead_reckoning) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+2+2+2+2+4+4+4+4+4+4+4+4+4+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+2+2+2+2+4+4+4+4+4+4+4+4+4+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS_EKF2, "INS_EKF2");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _control_mode, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _filter_fault_status, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _gps_check_status, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _soln_status, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _innov_test_status, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_mag, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_vel, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_pos, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_hgt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_tas, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_hagl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_flow, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _innov_beta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _mag_decl, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _terrain_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _dead_reckoning, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS_EKF2 pprz_msg_send_INS_EKF2
#define DOWNLINK_SEND_INS_EKF2(_trans, _dev, control_mode, filter_fault_status, gps_check_status, soln_status, innov_test_status, innov_mag, innov_vel, innov_pos, innov_hgt, innov_tas, innov_hagl, innov_flow, innov_beta, mag_decl, terrain_status, dead_reckoning) pprz_msg_send_INS_EKF2(&((_trans).trans_tx), &((_dev).device), AC_ID, control_mode, filter_fault_status, gps_check_status, soln_status, innov_test_status, innov_mag, innov_vel, innov_pos, innov_hgt, innov_tas, innov_hagl, innov_flow, innov_beta, mag_decl, terrain_status, dead_reckoning)
/**
 * Sends a INS_EKF2 message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _control_mode description of the control status (bitfields from common.h)
 * @param _filter_fault_status numerical errors in output states (bitfields from common.h)
 * @param _gps_check_status quality check of the GPS feedback (bitfields from common.h)
 * @param _soln_status which output states are valid or has an error (bitfields from common.h)
 * @param _innov_test_status which inputs exceed the innovation test
 * @param _innov_mag 
 * @param _innov_vel 
 * @param _innov_pos 
 * @param _innov_hgt 
 * @param _innov_tas 
 * @param _innov_hagl 
 * @param _innov_flow 
 * @param _innov_beta 
 * @param _mag_decl Magnetic declination
 * @param _terrain_status terrain detection for valid for ground sensors
 * @param _dead_reckoning active if all positioning sensors fail
 */
static inline void pprz_msg_send_INS_EKF2(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_control_mode, uint16_t *_filter_fault_status, uint16_t *_gps_check_status, uint16_t *_soln_status, uint16_t *_innov_test_status, float *_innov_mag, float *_innov_vel, float *_innov_pos, float *_innov_hgt, float *_innov_tas, float *_innov_hagl, float *_innov_flow, float *_innov_beta, float *_mag_decl, uint8_t *_terrain_status, uint8_t *_dead_reckoning) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS_EKF2(&msg,_control_mode,_filter_fault_status,_gps_check_status,_soln_status,_innov_test_status,_innov_mag,_innov_vel,_innov_pos,_innov_hgt,_innov_tas,_innov_hagl,_innov_flow,_innov_beta,_mag_decl,_terrain_status,_dead_reckoning);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS_EKF2(_trans, _dev, control_mode, filter_fault_status, gps_check_status, soln_status, innov_test_status, innov_mag, innov_vel, innov_pos, innov_hgt, innov_tas, innov_hagl, innov_flow, innov_beta, mag_decl, terrain_status, dead_reckoning) {}
static inline void pprz_send_msg_INS_EKF2(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_control_mode __attribute__((unused)), uint16_t *_filter_fault_status __attribute__((unused)), uint16_t *_gps_check_status __attribute__((unused)), uint16_t *_soln_status __attribute__((unused)), uint16_t *_innov_test_status __attribute__((unused)), float *_innov_mag __attribute__((unused)), float *_innov_vel __attribute__((unused)), float *_innov_pos __attribute__((unused)), float *_innov_hgt __attribute__((unused)), float *_innov_tas __attribute__((unused)), float *_innov_hagl __attribute__((unused)), float *_innov_flow __attribute__((unused)), float *_innov_beta __attribute__((unused)), float *_mag_decl __attribute__((unused)), uint8_t *_terrain_status __attribute__((unused)), uint8_t *_dead_reckoning __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field control_mode in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return description of the control status (bitfields from common.h)
  */
static inline uint32_t pprzlink_get_DL_INS_EKF2_control_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field filter_fault_status in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return numerical errors in output states (bitfields from common.h)
  */
static inline uint16_t pprzlink_get_DL_INS_EKF2_filter_fault_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field gps_check_status in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return quality check of the GPS feedback (bitfields from common.h)
  */
static inline uint16_t pprzlink_get_DL_INS_EKF2_gps_check_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field soln_status in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return which output states are valid or has an error (bitfields from common.h)
  */
static inline uint16_t pprzlink_get_DL_INS_EKF2_soln_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field innov_test_status in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return which inputs exceed the innovation test
  */
static inline uint16_t pprzlink_get_DL_INS_EKF2_innov_test_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field innov_mag in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_mag(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field innov_vel in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_vel(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field innov_pos in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_pos(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field innov_hgt in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_hgt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field innov_tas in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_tas(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field innov_hagl in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_hagl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field innov_flow in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_flow(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field innov_beta in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return 
  */
static inline float pprzlink_get_DL_INS_EKF2_innov_beta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field mag_decl in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return Magnetic declination
  */
static inline float pprzlink_get_DL_INS_EKF2_mag_decl(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field terrain_status in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return terrain detection for valid for ground sensors
  */
static inline uint8_t pprzlink_get_DL_INS_EKF2_terrain_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 52);
}


/** Getter for field dead_reckoning in message INS_EKF2
  *
  * @param _payload : a pointer to the INS_EKF2 message
  * @return active if all positioning sensors fail
  */
static inline uint8_t pprzlink_get_DL_INS_EKF2_dead_reckoning(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 53);
}


/* Compatibility macros */
#define DL_INS_EKF2_control_mode(_payload) pprzlink_get_DL_INS_EKF2_control_mode(_payload)
#define DL_INS_EKF2_filter_fault_status(_payload) pprzlink_get_DL_INS_EKF2_filter_fault_status(_payload)
#define DL_INS_EKF2_gps_check_status(_payload) pprzlink_get_DL_INS_EKF2_gps_check_status(_payload)
#define DL_INS_EKF2_soln_status(_payload) pprzlink_get_DL_INS_EKF2_soln_status(_payload)
#define DL_INS_EKF2_innov_test_status(_payload) pprzlink_get_DL_INS_EKF2_innov_test_status(_payload)
#define DL_INS_EKF2_innov_mag(_payload) pprzlink_get_DL_INS_EKF2_innov_mag(_payload)
#define DL_INS_EKF2_innov_vel(_payload) pprzlink_get_DL_INS_EKF2_innov_vel(_payload)
#define DL_INS_EKF2_innov_pos(_payload) pprzlink_get_DL_INS_EKF2_innov_pos(_payload)
#define DL_INS_EKF2_innov_hgt(_payload) pprzlink_get_DL_INS_EKF2_innov_hgt(_payload)
#define DL_INS_EKF2_innov_tas(_payload) pprzlink_get_DL_INS_EKF2_innov_tas(_payload)
#define DL_INS_EKF2_innov_hagl(_payload) pprzlink_get_DL_INS_EKF2_innov_hagl(_payload)
#define DL_INS_EKF2_innov_flow(_payload) pprzlink_get_DL_INS_EKF2_innov_flow(_payload)
#define DL_INS_EKF2_innov_beta(_payload) pprzlink_get_DL_INS_EKF2_innov_beta(_payload)
#define DL_INS_EKF2_mag_decl(_payload) pprzlink_get_DL_INS_EKF2_mag_decl(_payload)
#define DL_INS_EKF2_terrain_status(_payload) pprzlink_get_DL_INS_EKF2_terrain_status(_payload)
#define DL_INS_EKF2_dead_reckoning(_payload) pprzlink_get_DL_INS_EKF2_dead_reckoning(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_EKF2_H_

