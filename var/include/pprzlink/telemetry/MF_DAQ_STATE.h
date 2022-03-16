/** @file
 *  @brief PPRZLink message header for MF_DAQ_STATE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MF_DAQ_STATE_H_
#define _VAR_MESSAGES_telemetry_MF_DAQ_STATE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MF_DAQ_STATE 214
#define PPRZ_MSG_ID_MF_DAQ_STATE 214

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MF_DAQ_STATE _send_msg(MF_DAQ_STATE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MF_DAQ_STATE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _flight_time 
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _ve 
 * @param _vn 
 * @param _vu 
 * @param _lat 
 * @param _lon 
 * @param _alt 
 * @param _we 
 * @param _wn 
 */
static inline void pprzlink_msg_v2_send_MF_DAQ_STATE(struct pprzlink_msg * msg, uint16_t *_flight_time, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi, float *_ax, float *_ay, float *_az, float *_ve, float *_vn, float *_vu, float *_lat, float *_lon, float *_alt, float *_we, float *_wn) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MF_DAQ_STATE, "MF_DAQ_STATE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flight_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ax, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ay, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _az, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ve, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vn, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vu, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lon, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _we, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _wn, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MF_DAQ_STATE pprz_msg_send_MF_DAQ_STATE
#define DOWNLINK_SEND_MF_DAQ_STATE(_trans, _dev, flight_time, p, q, r, phi, theta, psi, ax, ay, az, ve, vn, vu, lat, lon, alt, we, wn) pprz_msg_send_MF_DAQ_STATE(&((_trans).trans_tx), &((_dev).device), AC_ID, flight_time, p, q, r, phi, theta, psi, ax, ay, az, ve, vn, vu, lat, lon, alt, we, wn)
/**
 * Sends a MF_DAQ_STATE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _flight_time 
 * @param _p 
 * @param _q 
 * @param _r 
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _ve 
 * @param _vn 
 * @param _vu 
 * @param _lat 
 * @param _lon 
 * @param _alt 
 * @param _we 
 * @param _wn 
 */
static inline void pprz_msg_send_MF_DAQ_STATE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_flight_time, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi, float *_ax, float *_ay, float *_az, float *_ve, float *_vn, float *_vu, float *_lat, float *_lon, float *_alt, float *_we, float *_wn) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MF_DAQ_STATE(&msg,_flight_time,_p,_q,_r,_phi,_theta,_psi,_ax,_ay,_az,_ve,_vn,_vu,_lat,_lon,_alt,_we,_wn);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MF_DAQ_STATE(_trans, _dev, flight_time, p, q, r, phi, theta, psi, ax, ay, az, ve, vn, vu, lat, lon, alt, we, wn) {}
static inline void pprz_send_msg_MF_DAQ_STATE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_flight_time __attribute__((unused)), float *_p __attribute__((unused)), float *_q __attribute__((unused)), float *_r __attribute__((unused)), float *_phi __attribute__((unused)), float *_theta __attribute__((unused)), float *_psi __attribute__((unused)), float *_ax __attribute__((unused)), float *_ay __attribute__((unused)), float *_az __attribute__((unused)), float *_ve __attribute__((unused)), float *_vn __attribute__((unused)), float *_vu __attribute__((unused)), float *_lat __attribute__((unused)), float *_lon __attribute__((unused)), float *_alt __attribute__((unused)), float *_we __attribute__((unused)), float *_wn __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field flight_time in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MF_DAQ_STATE_flight_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field p in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field q in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field r in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field phi in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/** Getter for field theta in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/** Getter for field psi in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 26);
}


/** Getter for field ax in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 30);
}


/** Getter for field ay in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 34);
}


/** Getter for field az in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 38);
}


/** Getter for field ve in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_ve(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 42);
}


/** Getter for field vn in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_vn(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 46);
}


/** Getter for field vu in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_vu(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 50);
}


/** Getter for field lat in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_lat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 54);
}


/** Getter for field lon in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_lon(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 58);
}


/** Getter for field alt in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 62);
}


/** Getter for field we in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_we(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 66);
}


/** Getter for field wn in message MF_DAQ_STATE
  *
  * @param _payload : a pointer to the MF_DAQ_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_MF_DAQ_STATE_wn(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 70);
}


/* Compatibility macros */
#define DL_MF_DAQ_STATE_flight_time(_payload) pprzlink_get_DL_MF_DAQ_STATE_flight_time(_payload)
#define DL_MF_DAQ_STATE_p(_payload) pprzlink_get_DL_MF_DAQ_STATE_p(_payload)
#define DL_MF_DAQ_STATE_q(_payload) pprzlink_get_DL_MF_DAQ_STATE_q(_payload)
#define DL_MF_DAQ_STATE_r(_payload) pprzlink_get_DL_MF_DAQ_STATE_r(_payload)
#define DL_MF_DAQ_STATE_phi(_payload) pprzlink_get_DL_MF_DAQ_STATE_phi(_payload)
#define DL_MF_DAQ_STATE_theta(_payload) pprzlink_get_DL_MF_DAQ_STATE_theta(_payload)
#define DL_MF_DAQ_STATE_psi(_payload) pprzlink_get_DL_MF_DAQ_STATE_psi(_payload)
#define DL_MF_DAQ_STATE_ax(_payload) pprzlink_get_DL_MF_DAQ_STATE_ax(_payload)
#define DL_MF_DAQ_STATE_ay(_payload) pprzlink_get_DL_MF_DAQ_STATE_ay(_payload)
#define DL_MF_DAQ_STATE_az(_payload) pprzlink_get_DL_MF_DAQ_STATE_az(_payload)
#define DL_MF_DAQ_STATE_ve(_payload) pprzlink_get_DL_MF_DAQ_STATE_ve(_payload)
#define DL_MF_DAQ_STATE_vn(_payload) pprzlink_get_DL_MF_DAQ_STATE_vn(_payload)
#define DL_MF_DAQ_STATE_vu(_payload) pprzlink_get_DL_MF_DAQ_STATE_vu(_payload)
#define DL_MF_DAQ_STATE_lat(_payload) pprzlink_get_DL_MF_DAQ_STATE_lat(_payload)
#define DL_MF_DAQ_STATE_lon(_payload) pprzlink_get_DL_MF_DAQ_STATE_lon(_payload)
#define DL_MF_DAQ_STATE_alt(_payload) pprzlink_get_DL_MF_DAQ_STATE_alt(_payload)
#define DL_MF_DAQ_STATE_we(_payload) pprzlink_get_DL_MF_DAQ_STATE_we(_payload)
#define DL_MF_DAQ_STATE_wn(_payload) pprzlink_get_DL_MF_DAQ_STATE_wn(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MF_DAQ_STATE_H_

