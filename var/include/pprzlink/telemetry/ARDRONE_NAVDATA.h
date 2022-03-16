/** @file
 *  @brief PPRZLink message header for ARDRONE_NAVDATA in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ARDRONE_NAVDATA_H_
#define _VAR_MESSAGES_telemetry_ARDRONE_NAVDATA_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ARDRONE_NAVDATA 5
#define PPRZ_MSG_ID_ARDRONE_NAVDATA 5

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ARDRONE_NAVDATA _send_msg(ARDRONE_NAVDATA,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ARDRONE_NAVDATA message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _taille 
 * @param _nu_trame 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _vx 
 * @param _vy 
 * @param _vz 
 * @param _temperature_acc 
 * @param _temperature_gyro 
 * @param _ultrasound 
 * @param _us_debut_echo 
 * @param _us_fin_echo 
 * @param _us_association_echo 
 * @param _us_distance_echo 
 * @param _us_curve_time 
 * @param _us_curve_value 
 * @param _us_curve_ref 
 * @param _nb_echo 
 * @param _sum_echo 
 * @param _gradient 
 * @param _flag_echo_ini 
 * @param _pressure 
 * @param _temperature_pressure 
 * @param _mx 
 * @param _my 
 * @param _mz 
 * @param _chksum 
 * @param _checksum_errors 
 */
static inline void pprzlink_msg_v2_send_ARDRONE_NAVDATA(struct pprzlink_msg * msg, uint16_t *_taille, uint16_t *_nu_trame, uint16_t *_ax, uint16_t *_ay, uint16_t *_az, int16_t *_vx, int16_t *_vy, int16_t *_vz, uint16_t *_temperature_acc, uint16_t *_temperature_gyro, uint16_t *_ultrasound, uint16_t *_us_debut_echo, uint16_t *_us_fin_echo, uint16_t *_us_association_echo, uint16_t *_us_distance_echo, uint16_t *_us_curve_time, uint16_t *_us_curve_value, uint16_t *_us_curve_ref, uint16_t *_nb_echo, uint32_t *_sum_echo, int16_t *_gradient, uint16_t *_flag_echo_ini, int32_t *_pressure, uint16_t *_temperature_pressure, int16_t *_mx, int16_t *_my, int16_t *_mz, uint16_t *_chksum, uint32_t *_checksum_errors) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+4+2+2+4+2+2+2+2+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+4+2+2+4+2+2+2+2+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ARDRONE_NAVDATA, "ARDRONE_NAVDATA");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _taille, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _nu_trame, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ax, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ay, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _az, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _vx, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _vy, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _vz, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _temperature_acc, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _temperature_gyro, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ultrasound, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_debut_echo, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_fin_echo, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_association_echo, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_distance_echo, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_curve_time, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_curve_value, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _us_curve_ref, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _nb_echo, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _sum_echo, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _gradient, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _flag_echo_ini, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _temperature_pressure, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mx, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _my, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _mz, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _chksum, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _checksum_errors, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ARDRONE_NAVDATA pprz_msg_send_ARDRONE_NAVDATA
#define DOWNLINK_SEND_ARDRONE_NAVDATA(_trans, _dev, taille, nu_trame, ax, ay, az, vx, vy, vz, temperature_acc, temperature_gyro, ultrasound, us_debut_echo, us_fin_echo, us_association_echo, us_distance_echo, us_curve_time, us_curve_value, us_curve_ref, nb_echo, sum_echo, gradient, flag_echo_ini, pressure, temperature_pressure, mx, my, mz, chksum, checksum_errors) pprz_msg_send_ARDRONE_NAVDATA(&((_trans).trans_tx), &((_dev).device), AC_ID, taille, nu_trame, ax, ay, az, vx, vy, vz, temperature_acc, temperature_gyro, ultrasound, us_debut_echo, us_fin_echo, us_association_echo, us_distance_echo, us_curve_time, us_curve_value, us_curve_ref, nb_echo, sum_echo, gradient, flag_echo_ini, pressure, temperature_pressure, mx, my, mz, chksum, checksum_errors)
/**
 * Sends a ARDRONE_NAVDATA message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _taille 
 * @param _nu_trame 
 * @param _ax 
 * @param _ay 
 * @param _az 
 * @param _vx 
 * @param _vy 
 * @param _vz 
 * @param _temperature_acc 
 * @param _temperature_gyro 
 * @param _ultrasound 
 * @param _us_debut_echo 
 * @param _us_fin_echo 
 * @param _us_association_echo 
 * @param _us_distance_echo 
 * @param _us_curve_time 
 * @param _us_curve_value 
 * @param _us_curve_ref 
 * @param _nb_echo 
 * @param _sum_echo 
 * @param _gradient 
 * @param _flag_echo_ini 
 * @param _pressure 
 * @param _temperature_pressure 
 * @param _mx 
 * @param _my 
 * @param _mz 
 * @param _chksum 
 * @param _checksum_errors 
 */
static inline void pprz_msg_send_ARDRONE_NAVDATA(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_taille, uint16_t *_nu_trame, uint16_t *_ax, uint16_t *_ay, uint16_t *_az, int16_t *_vx, int16_t *_vy, int16_t *_vz, uint16_t *_temperature_acc, uint16_t *_temperature_gyro, uint16_t *_ultrasound, uint16_t *_us_debut_echo, uint16_t *_us_fin_echo, uint16_t *_us_association_echo, uint16_t *_us_distance_echo, uint16_t *_us_curve_time, uint16_t *_us_curve_value, uint16_t *_us_curve_ref, uint16_t *_nb_echo, uint32_t *_sum_echo, int16_t *_gradient, uint16_t *_flag_echo_ini, int32_t *_pressure, uint16_t *_temperature_pressure, int16_t *_mx, int16_t *_my, int16_t *_mz, uint16_t *_chksum, uint32_t *_checksum_errors) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ARDRONE_NAVDATA(&msg,_taille,_nu_trame,_ax,_ay,_az,_vx,_vy,_vz,_temperature_acc,_temperature_gyro,_ultrasound,_us_debut_echo,_us_fin_echo,_us_association_echo,_us_distance_echo,_us_curve_time,_us_curve_value,_us_curve_ref,_nb_echo,_sum_echo,_gradient,_flag_echo_ini,_pressure,_temperature_pressure,_mx,_my,_mz,_chksum,_checksum_errors);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ARDRONE_NAVDATA(_trans, _dev, taille, nu_trame, ax, ay, az, vx, vy, vz, temperature_acc, temperature_gyro, ultrasound, us_debut_echo, us_fin_echo, us_association_echo, us_distance_echo, us_curve_time, us_curve_value, us_curve_ref, nb_echo, sum_echo, gradient, flag_echo_ini, pressure, temperature_pressure, mx, my, mz, chksum, checksum_errors) {}
static inline void pprz_send_msg_ARDRONE_NAVDATA(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_taille __attribute__((unused)), uint16_t *_nu_trame __attribute__((unused)), uint16_t *_ax __attribute__((unused)), uint16_t *_ay __attribute__((unused)), uint16_t *_az __attribute__((unused)), int16_t *_vx __attribute__((unused)), int16_t *_vy __attribute__((unused)), int16_t *_vz __attribute__((unused)), uint16_t *_temperature_acc __attribute__((unused)), uint16_t *_temperature_gyro __attribute__((unused)), uint16_t *_ultrasound __attribute__((unused)), uint16_t *_us_debut_echo __attribute__((unused)), uint16_t *_us_fin_echo __attribute__((unused)), uint16_t *_us_association_echo __attribute__((unused)), uint16_t *_us_distance_echo __attribute__((unused)), uint16_t *_us_curve_time __attribute__((unused)), uint16_t *_us_curve_value __attribute__((unused)), uint16_t *_us_curve_ref __attribute__((unused)), uint16_t *_nb_echo __attribute__((unused)), uint32_t *_sum_echo __attribute__((unused)), int16_t *_gradient __attribute__((unused)), uint16_t *_flag_echo_ini __attribute__((unused)), int32_t *_pressure __attribute__((unused)), uint16_t *_temperature_pressure __attribute__((unused)), int16_t *_mx __attribute__((unused)), int16_t *_my __attribute__((unused)), int16_t *_mz __attribute__((unused)), uint16_t *_chksum __attribute__((unused)), uint32_t *_checksum_errors __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field taille in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_taille(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field nu_trame in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_nu_trame(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field ax in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_ax(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field ay in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_ay(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field az in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_az(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field vx in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_vx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 14);
}


/** Getter for field vy in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_vy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 16);
}


/** Getter for field vz in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_vz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 18);
}


/** Getter for field temperature_acc in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_temperature_acc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 20);
}


/** Getter for field temperature_gyro in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_temperature_gyro(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 22);
}


/** Getter for field ultrasound in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_ultrasound(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 24);
}


/** Getter for field us_debut_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_debut_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 26);
}


/** Getter for field us_fin_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_fin_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 28);
}


/** Getter for field us_association_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_association_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 30);
}


/** Getter for field us_distance_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_distance_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 32);
}


/** Getter for field us_curve_time in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 34);
}


/** Getter for field us_curve_value in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_value(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 36);
}


/** Getter for field us_curve_ref in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 38);
}


/** Getter for field nb_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_nb_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 40);
}


/** Getter for field sum_echo in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_ARDRONE_NAVDATA_sum_echo(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 42);
}


/** Getter for field gradient in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_gradient(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 46);
}


/** Getter for field flag_echo_ini in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_flag_echo_ini(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 48);
}


/** Getter for field pressure in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ARDRONE_NAVDATA_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 50);
}


/** Getter for field temperature_pressure in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_temperature_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 54);
}


/** Getter for field mx in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_mx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 56);
}


/** Getter for field my in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_my(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 58);
}


/** Getter for field mz in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline int16_t pprzlink_get_DL_ARDRONE_NAVDATA_mz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 60);
}


/** Getter for field chksum in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ARDRONE_NAVDATA_chksum(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 62);
}


/** Getter for field checksum_errors in message ARDRONE_NAVDATA
  *
  * @param _payload : a pointer to the ARDRONE_NAVDATA message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_ARDRONE_NAVDATA_checksum_errors(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 64);
}


/* Compatibility macros */
#define DL_ARDRONE_NAVDATA_taille(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_taille(_payload)
#define DL_ARDRONE_NAVDATA_nu_trame(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_nu_trame(_payload)
#define DL_ARDRONE_NAVDATA_ax(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_ax(_payload)
#define DL_ARDRONE_NAVDATA_ay(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_ay(_payload)
#define DL_ARDRONE_NAVDATA_az(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_az(_payload)
#define DL_ARDRONE_NAVDATA_vx(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_vx(_payload)
#define DL_ARDRONE_NAVDATA_vy(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_vy(_payload)
#define DL_ARDRONE_NAVDATA_vz(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_vz(_payload)
#define DL_ARDRONE_NAVDATA_temperature_acc(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_temperature_acc(_payload)
#define DL_ARDRONE_NAVDATA_temperature_gyro(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_temperature_gyro(_payload)
#define DL_ARDRONE_NAVDATA_ultrasound(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_ultrasound(_payload)
#define DL_ARDRONE_NAVDATA_us_debut_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_debut_echo(_payload)
#define DL_ARDRONE_NAVDATA_us_fin_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_fin_echo(_payload)
#define DL_ARDRONE_NAVDATA_us_association_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_association_echo(_payload)
#define DL_ARDRONE_NAVDATA_us_distance_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_distance_echo(_payload)
#define DL_ARDRONE_NAVDATA_us_curve_time(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_time(_payload)
#define DL_ARDRONE_NAVDATA_us_curve_value(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_value(_payload)
#define DL_ARDRONE_NAVDATA_us_curve_ref(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_us_curve_ref(_payload)
#define DL_ARDRONE_NAVDATA_nb_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_nb_echo(_payload)
#define DL_ARDRONE_NAVDATA_sum_echo(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_sum_echo(_payload)
#define DL_ARDRONE_NAVDATA_gradient(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_gradient(_payload)
#define DL_ARDRONE_NAVDATA_flag_echo_ini(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_flag_echo_ini(_payload)
#define DL_ARDRONE_NAVDATA_pressure(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_pressure(_payload)
#define DL_ARDRONE_NAVDATA_temperature_pressure(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_temperature_pressure(_payload)
#define DL_ARDRONE_NAVDATA_mx(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_mx(_payload)
#define DL_ARDRONE_NAVDATA_my(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_my(_payload)
#define DL_ARDRONE_NAVDATA_mz(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_mz(_payload)
#define DL_ARDRONE_NAVDATA_chksum(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_chksum(_payload)
#define DL_ARDRONE_NAVDATA_checksum_errors(_payload) pprzlink_get_DL_ARDRONE_NAVDATA_checksum_errors(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ARDRONE_NAVDATA_H_

