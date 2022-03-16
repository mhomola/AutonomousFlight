/** @file
 *  @brief PPRZLink message header for TURB_PRESSURE_VOLTAGE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TURB_PRESSURE_VOLTAGE_H_
#define _VAR_MESSAGES_telemetry_TURB_PRESSURE_VOLTAGE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TURB_PRESSURE_VOLTAGE 62
#define PPRZ_MSG_ID_TURB_PRESSURE_VOLTAGE 62

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TURB_PRESSURE_VOLTAGE _send_msg(TURB_PRESSURE_VOLTAGE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TURB_PRESSURE_VOLTAGE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ch_1_p 
 * @param _ch_1_t 
 * @param _ch_2_p 
 * @param _ch_2_t 
 * @param _ch_3_p 
 * @param _ch_3_t 
 * @param _ch_4_p 
 * @param _ch_4_t 
 * @param _ch_5_p 
 * @param _ch_5_t 
 * @param _ch_6_p 
 * @param _ch_6_t 
 * @param _ch_7_p 
 * @param _ch_7_t 
 * @param _gnd1 
 * @param _gnd2 
 */
static inline void pprzlink_msg_v2_send_TURB_PRESSURE_VOLTAGE(struct pprzlink_msg * msg, float *_ch_1_p, float *_ch_1_t, float *_ch_2_p, float *_ch_2_t, float *_ch_3_p, float *_ch_3_t, float *_ch_4_p, float *_ch_4_t, float *_ch_5_p, float *_ch_5_t, float *_ch_6_p, float *_ch_6_t, float *_ch_7_p, float *_ch_7_t, float *_gnd1, float *_gnd2) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TURB_PRESSURE_VOLTAGE, "TURB_PRESSURE_VOLTAGE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_1_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_1_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_2_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_2_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_3_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_3_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_4_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_4_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_5_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_5_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_6_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_6_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_7_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ch_7_t, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gnd1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _gnd2, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TURB_PRESSURE_VOLTAGE pprz_msg_send_TURB_PRESSURE_VOLTAGE
#define DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(_trans, _dev, ch_1_p, ch_1_t, ch_2_p, ch_2_t, ch_3_p, ch_3_t, ch_4_p, ch_4_t, ch_5_p, ch_5_t, ch_6_p, ch_6_t, ch_7_p, ch_7_t, gnd1, gnd2) pprz_msg_send_TURB_PRESSURE_VOLTAGE(&((_trans).trans_tx), &((_dev).device), AC_ID, ch_1_p, ch_1_t, ch_2_p, ch_2_t, ch_3_p, ch_3_t, ch_4_p, ch_4_t, ch_5_p, ch_5_t, ch_6_p, ch_6_t, ch_7_p, ch_7_t, gnd1, gnd2)
/**
 * Sends a TURB_PRESSURE_VOLTAGE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ch_1_p 
 * @param _ch_1_t 
 * @param _ch_2_p 
 * @param _ch_2_t 
 * @param _ch_3_p 
 * @param _ch_3_t 
 * @param _ch_4_p 
 * @param _ch_4_t 
 * @param _ch_5_p 
 * @param _ch_5_t 
 * @param _ch_6_p 
 * @param _ch_6_t 
 * @param _ch_7_p 
 * @param _ch_7_t 
 * @param _gnd1 
 * @param _gnd2 
 */
static inline void pprz_msg_send_TURB_PRESSURE_VOLTAGE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_ch_1_p, float *_ch_1_t, float *_ch_2_p, float *_ch_2_t, float *_ch_3_p, float *_ch_3_t, float *_ch_4_p, float *_ch_4_t, float *_ch_5_p, float *_ch_5_t, float *_ch_6_p, float *_ch_6_t, float *_ch_7_p, float *_ch_7_t, float *_gnd1, float *_gnd2) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TURB_PRESSURE_VOLTAGE(&msg,_ch_1_p,_ch_1_t,_ch_2_p,_ch_2_t,_ch_3_p,_ch_3_t,_ch_4_p,_ch_4_t,_ch_5_p,_ch_5_t,_ch_6_p,_ch_6_t,_ch_7_p,_ch_7_t,_gnd1,_gnd2);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(_trans, _dev, ch_1_p, ch_1_t, ch_2_p, ch_2_t, ch_3_p, ch_3_t, ch_4_p, ch_4_t, ch_5_p, ch_5_t, ch_6_p, ch_6_t, ch_7_p, ch_7_t, gnd1, gnd2) {}
static inline void pprz_send_msg_TURB_PRESSURE_VOLTAGE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_ch_1_p __attribute__((unused)), float *_ch_1_t __attribute__((unused)), float *_ch_2_p __attribute__((unused)), float *_ch_2_t __attribute__((unused)), float *_ch_3_p __attribute__((unused)), float *_ch_3_t __attribute__((unused)), float *_ch_4_p __attribute__((unused)), float *_ch_4_t __attribute__((unused)), float *_ch_5_p __attribute__((unused)), float *_ch_5_t __attribute__((unused)), float *_ch_6_p __attribute__((unused)), float *_ch_6_t __attribute__((unused)), float *_ch_7_p __attribute__((unused)), float *_ch_7_t __attribute__((unused)), float *_gnd1 __attribute__((unused)), float *_gnd2 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ch_1_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_1_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field ch_1_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_1_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field ch_2_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_2_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field ch_2_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_2_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field ch_3_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_3_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field ch_3_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_3_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field ch_4_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_4_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field ch_4_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_4_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field ch_5_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_5_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field ch_5_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_5_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field ch_6_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_6_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field ch_6_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_6_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field ch_7_p in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_7_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field ch_7_t in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_7_t(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field gnd1 in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_gnd1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field gnd2 in message TURB_PRESSURE_VOLTAGE
  *
  * @param _payload : a pointer to the TURB_PRESSURE_VOLTAGE message
  * @return 
  */
static inline float pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_gnd2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/* Compatibility macros */
#define DL_TURB_PRESSURE_VOLTAGE_ch_1_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_1_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_1_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_1_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_2_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_2_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_2_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_2_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_3_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_3_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_3_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_3_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_4_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_4_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_4_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_4_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_5_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_5_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_5_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_5_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_6_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_6_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_6_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_6_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_7_p(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_7_p(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_ch_7_t(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_ch_7_t(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_gnd1(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_gnd1(_payload)
#define DL_TURB_PRESSURE_VOLTAGE_gnd2(_payload) pprzlink_get_DL_TURB_PRESSURE_VOLTAGE_gnd2(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TURB_PRESSURE_VOLTAGE_H_

