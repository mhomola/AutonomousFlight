/** @file
 *  @brief PPRZLink message header for ROTORCRAFT_STATUS in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTORCRAFT_STATUS_H_
#define _VAR_MESSAGES_telemetry_ROTORCRAFT_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTORCRAFT_STATUS 231
#define PPRZ_MSG_ID_ROTORCRAFT_STATUS 231

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTORCRAFT_STATUS _send_msg(ROTORCRAFT_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTORCRAFT_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _link_imu_nb_err 
 * @param _motor_nb_err 
 * @param _rc_status 
 * @param _frame_rate 
 * @param _gps_status 
 * @param _ap_mode 
 * @param _ap_in_flight 
 * @param _ap_motors_on 
 * @param _arming_status 
 * @param _ap_h_mode 
 * @param _ap_v_mode 
 * @param _cpu_time 
 * @param _vsupply 
 */
static inline void pprzlink_msg_v2_send_ROTORCRAFT_STATUS(struct pprzlink_msg * msg, uint32_t *_link_imu_nb_err, uint8_t *_motor_nb_err, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_in_flight, uint8_t *_ap_motors_on, uint8_t *_arming_status, uint8_t *_ap_h_mode, uint8_t *_ap_v_mode, uint16_t *_cpu_time, float *_vsupply) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+1+1+1+1+1+1+1+1+1+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+1+1+1+1+1+1+1+1+1+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTORCRAFT_STATUS, "ROTORCRAFT_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _link_imu_nb_err, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _motor_nb_err, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rc_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _frame_rate, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gps_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_in_flight, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_motors_on, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _arming_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_h_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_v_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _cpu_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vsupply, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTORCRAFT_STATUS pprz_msg_send_ROTORCRAFT_STATUS
#define DOWNLINK_SEND_ROTORCRAFT_STATUS(_trans, _dev, link_imu_nb_err, motor_nb_err, rc_status, frame_rate, gps_status, ap_mode, ap_in_flight, ap_motors_on, arming_status, ap_h_mode, ap_v_mode, cpu_time, vsupply) pprz_msg_send_ROTORCRAFT_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, link_imu_nb_err, motor_nb_err, rc_status, frame_rate, gps_status, ap_mode, ap_in_flight, ap_motors_on, arming_status, ap_h_mode, ap_v_mode, cpu_time, vsupply)
/**
 * Sends a ROTORCRAFT_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _link_imu_nb_err 
 * @param _motor_nb_err 
 * @param _rc_status 
 * @param _frame_rate 
 * @param _gps_status 
 * @param _ap_mode 
 * @param _ap_in_flight 
 * @param _ap_motors_on 
 * @param _arming_status 
 * @param _ap_h_mode 
 * @param _ap_v_mode 
 * @param _cpu_time 
 * @param _vsupply 
 */
static inline void pprz_msg_send_ROTORCRAFT_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_link_imu_nb_err, uint8_t *_motor_nb_err, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_in_flight, uint8_t *_ap_motors_on, uint8_t *_arming_status, uint8_t *_ap_h_mode, uint8_t *_ap_v_mode, uint16_t *_cpu_time, float *_vsupply) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTORCRAFT_STATUS(&msg,_link_imu_nb_err,_motor_nb_err,_rc_status,_frame_rate,_gps_status,_ap_mode,_ap_in_flight,_ap_motors_on,_arming_status,_ap_h_mode,_ap_v_mode,_cpu_time,_vsupply);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTORCRAFT_STATUS(_trans, _dev, link_imu_nb_err, motor_nb_err, rc_status, frame_rate, gps_status, ap_mode, ap_in_flight, ap_motors_on, arming_status, ap_h_mode, ap_v_mode, cpu_time, vsupply) {}
static inline void pprz_send_msg_ROTORCRAFT_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_link_imu_nb_err __attribute__((unused)), uint8_t *_motor_nb_err __attribute__((unused)), uint8_t *_rc_status __attribute__((unused)), uint8_t *_frame_rate __attribute__((unused)), uint8_t *_gps_status __attribute__((unused)), uint8_t *_ap_mode __attribute__((unused)), uint8_t *_ap_in_flight __attribute__((unused)), uint8_t *_ap_motors_on __attribute__((unused)), uint8_t *_arming_status __attribute__((unused)), uint8_t *_ap_h_mode __attribute__((unused)), uint8_t *_ap_v_mode __attribute__((unused)), uint16_t *_cpu_time __attribute__((unused)), float *_vsupply __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field link_imu_nb_err in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_ROTORCRAFT_STATUS_link_imu_nb_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field motor_nb_err in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_motor_nb_err(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field rc_status in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_rc_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 9);
}


/** Getter for field frame_rate in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_frame_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 10);
}


/** Getter for field gps_status in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_gps_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 11);
}


/** Getter for field ap_mode in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_ap_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 12);
}


/** Getter for field ap_in_flight in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_ap_in_flight(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 13);
}


/** Getter for field ap_motors_on in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_ap_motors_on(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 14);
}


/** Getter for field arming_status in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_arming_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 15);
}


/** Getter for field ap_h_mode in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_ap_h_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 16);
}


/** Getter for field ap_v_mode in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTORCRAFT_STATUS_ap_v_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 17);
}


/** Getter for field cpu_time in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTORCRAFT_STATUS_cpu_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/** Getter for field vsupply in message ROTORCRAFT_STATUS
  *
  * @param _payload : a pointer to the ROTORCRAFT_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_ROTORCRAFT_STATUS_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/* Compatibility macros */
#define DL_ROTORCRAFT_STATUS_link_imu_nb_err(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_link_imu_nb_err(_payload)
#define DL_ROTORCRAFT_STATUS_motor_nb_err(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_motor_nb_err(_payload)
#define DL_ROTORCRAFT_STATUS_rc_status(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_rc_status(_payload)
#define DL_ROTORCRAFT_STATUS_frame_rate(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_frame_rate(_payload)
#define DL_ROTORCRAFT_STATUS_gps_status(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_gps_status(_payload)
#define DL_ROTORCRAFT_STATUS_ap_mode(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_ap_mode(_payload)
#define DL_ROTORCRAFT_STATUS_ap_in_flight(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_ap_in_flight(_payload)
#define DL_ROTORCRAFT_STATUS_ap_motors_on(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_ap_motors_on(_payload)
#define DL_ROTORCRAFT_STATUS_arming_status(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_arming_status(_payload)
#define DL_ROTORCRAFT_STATUS_ap_h_mode(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_ap_h_mode(_payload)
#define DL_ROTORCRAFT_STATUS_ap_v_mode(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_ap_v_mode(_payload)
#define DL_ROTORCRAFT_STATUS_cpu_time(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_cpu_time(_payload)
#define DL_ROTORCRAFT_STATUS_vsupply(_payload) pprzlink_get_DL_ROTORCRAFT_STATUS_vsupply(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTORCRAFT_STATUS_H_

