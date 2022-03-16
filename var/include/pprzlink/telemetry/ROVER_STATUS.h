/** @file
 *  @brief PPRZLink message header for ROVER_STATUS in class telemetry
 *
 *  
        Rover status message
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROVER_STATUS_H_
#define _VAR_MESSAGES_telemetry_ROVER_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROVER_STATUS 230
#define PPRZ_MSG_ID_ROVER_STATUS 230

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROVER_STATUS _send_msg(ROVER_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROVER_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _rc_status 
 * @param _frame_rate 
 * @param _gps_status 
 * @param _ap_mode Rover AP modes are generated from XML file
 * @param _ap_motors_on 
 * @param _cpu_time 
 * @param _vsupply 
 */
static inline void pprzlink_msg_v2_send_ROVER_STATUS(struct pprzlink_msg * msg, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_motors_on, uint16_t *_cpu_time, float *_vsupply) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROVER_STATUS, "ROVER_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _rc_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _frame_rate, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _gps_status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_mode, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ap_motors_on, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _cpu_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vsupply, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROVER_STATUS pprz_msg_send_ROVER_STATUS
#define DOWNLINK_SEND_ROVER_STATUS(_trans, _dev, rc_status, frame_rate, gps_status, ap_mode, ap_motors_on, cpu_time, vsupply) pprz_msg_send_ROVER_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, rc_status, frame_rate, gps_status, ap_mode, ap_motors_on, cpu_time, vsupply)
/**
 * Sends a ROVER_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _rc_status 
 * @param _frame_rate 
 * @param _gps_status 
 * @param _ap_mode Rover AP modes are generated from XML file
 * @param _ap_motors_on 
 * @param _cpu_time 
 * @param _vsupply 
 */
static inline void pprz_msg_send_ROVER_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_motors_on, uint16_t *_cpu_time, float *_vsupply) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROVER_STATUS(&msg,_rc_status,_frame_rate,_gps_status,_ap_mode,_ap_motors_on,_cpu_time,_vsupply);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROVER_STATUS(_trans, _dev, rc_status, frame_rate, gps_status, ap_mode, ap_motors_on, cpu_time, vsupply) {}
static inline void pprz_send_msg_ROVER_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_rc_status __attribute__((unused)), uint8_t *_frame_rate __attribute__((unused)), uint8_t *_gps_status __attribute__((unused)), uint8_t *_ap_mode __attribute__((unused)), uint8_t *_ap_motors_on __attribute__((unused)), uint16_t *_cpu_time __attribute__((unused)), float *_vsupply __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field rc_status in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROVER_STATUS_rc_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field frame_rate in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROVER_STATUS_frame_rate(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field gps_status in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROVER_STATUS_gps_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field ap_mode in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return Rover AP modes are generated from XML file
  */
static inline uint8_t pprzlink_get_DL_ROVER_STATUS_ap_mode(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}


/** Getter for field ap_motors_on in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROVER_STATUS_ap_motors_on(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field cpu_time in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROVER_STATUS_cpu_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 9);
}


/** Getter for field vsupply in message ROVER_STATUS
  *
  * @param _payload : a pointer to the ROVER_STATUS message
  * @return 
  */
static inline float pprzlink_get_DL_ROVER_STATUS_vsupply(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 11);
}


/* Compatibility macros */
#define DL_ROVER_STATUS_rc_status(_payload) pprzlink_get_DL_ROVER_STATUS_rc_status(_payload)
#define DL_ROVER_STATUS_frame_rate(_payload) pprzlink_get_DL_ROVER_STATUS_frame_rate(_payload)
#define DL_ROVER_STATUS_gps_status(_payload) pprzlink_get_DL_ROVER_STATUS_gps_status(_payload)
#define DL_ROVER_STATUS_ap_mode(_payload) pprzlink_get_DL_ROVER_STATUS_ap_mode(_payload)
#define DL_ROVER_STATUS_ap_motors_on(_payload) pprzlink_get_DL_ROVER_STATUS_ap_motors_on(_payload)
#define DL_ROVER_STATUS_cpu_time(_payload) pprzlink_get_DL_ROVER_STATUS_cpu_time(_payload)
#define DL_ROVER_STATUS_vsupply(_payload) pprzlink_get_DL_ROVER_STATUS_vsupply(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROVER_STATUS_H_

