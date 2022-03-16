/** @file
 *  @brief PPRZLink message header for BARO_MS5611 in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_BARO_MS5611_H_
#define _VAR_MESSAGES_telemetry_BARO_MS5611_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_BARO_MS5611 116
#define PPRZ_MSG_ID_BARO_MS5611 116

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_BARO_MS5611 _send_msg(BARO_MS5611,PPRZLINK_DEFAULT_VER)

/**
 * Sends a BARO_MS5611 message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _d1 
 * @param _d2 
 * @param _pressure 
 * @param _temp 
 */
static inline void pprzlink_msg_v2_send_BARO_MS5611(struct pprzlink_msg * msg, uint32_t *_d1, uint32_t *_d2, float *_pressure, float *_temp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_BARO_MS5611, "BARO_MS5611");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _d1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _d2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pressure, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _temp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_BARO_MS5611 pprz_msg_send_BARO_MS5611
#define DOWNLINK_SEND_BARO_MS5611(_trans, _dev, d1, d2, pressure, temp) pprz_msg_send_BARO_MS5611(&((_trans).trans_tx), &((_dev).device), AC_ID, d1, d2, pressure, temp)
/**
 * Sends a BARO_MS5611 message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _d1 
 * @param _d2 
 * @param _pressure 
 * @param _temp 
 */
static inline void pprz_msg_send_BARO_MS5611(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_d1, uint32_t *_d2, float *_pressure, float *_temp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_BARO_MS5611(&msg,_d1,_d2,_pressure,_temp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_BARO_MS5611(_trans, _dev, d1, d2, pressure, temp) {}
static inline void pprz_send_msg_BARO_MS5611(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_d1 __attribute__((unused)), uint32_t *_d2 __attribute__((unused)), float *_pressure __attribute__((unused)), float *_temp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field d1 in message BARO_MS5611
  *
  * @param _payload : a pointer to the BARO_MS5611 message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_BARO_MS5611_d1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}


/** Getter for field d2 in message BARO_MS5611
  *
  * @param _payload : a pointer to the BARO_MS5611 message
  * @return 
  */
static inline uint32_t pprzlink_get_DL_BARO_MS5611_d2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 8);
}


/** Getter for field pressure in message BARO_MS5611
  *
  * @param _payload : a pointer to the BARO_MS5611 message
  * @return 
  */
static inline float pprzlink_get_DL_BARO_MS5611_pressure(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field temp in message BARO_MS5611
  *
  * @param _payload : a pointer to the BARO_MS5611 message
  * @return 
  */
static inline float pprzlink_get_DL_BARO_MS5611_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_BARO_MS5611_d1(_payload) pprzlink_get_DL_BARO_MS5611_d1(_payload)
#define DL_BARO_MS5611_d2(_payload) pprzlink_get_DL_BARO_MS5611_d2(_payload)
#define DL_BARO_MS5611_pressure(_payload) pprzlink_get_DL_BARO_MS5611_pressure(_payload)
#define DL_BARO_MS5611_temp(_payload) pprzlink_get_DL_BARO_MS5611_temp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_BARO_MS5611_H_

