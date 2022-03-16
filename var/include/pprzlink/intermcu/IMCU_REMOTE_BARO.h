/** @file
 *  @brief PPRZLink message header for IMCU_REMOTE_BARO in class intermcu
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_intermcu_IMCU_REMOTE_BARO_H_
#define _VAR_MESSAGES_intermcu_IMCU_REMOTE_BARO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_IMCU_REMOTE_BARO 11
#define PPRZ_MSG_ID_IMCU_REMOTE_BARO 11

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_IMCU_REMOTE_BARO _send_msg(IMCU_REMOTE_BARO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a IMCU_REMOTE_BARO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _pitot_stat Static Barometric Pressure in Pascal
 * @param _pitot_temp Pressure Sensor Temperature
 */
static inline void pprzlink_msg_v2_send_IMCU_REMOTE_BARO(struct pprzlink_msg * msg, float *_pitot_stat, float *_pitot_temp) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (5 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_IMCU_REMOTE_BARO, "IMCU_REMOTE_BARO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitot_stat, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pitot_temp, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_IMCU_REMOTE_BARO pprz_msg_send_IMCU_REMOTE_BARO
#define DOWNLINK_SEND_IMCU_REMOTE_BARO(_trans, _dev, pitot_stat, pitot_temp) pprz_msg_send_IMCU_REMOTE_BARO(&((_trans).trans_tx), &((_dev).device), AC_ID, pitot_stat, pitot_temp)
/**
 * Sends a IMCU_REMOTE_BARO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _pitot_stat Static Barometric Pressure in Pascal
 * @param _pitot_temp Pressure Sensor Temperature
 */
static inline void pprz_msg_send_IMCU_REMOTE_BARO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_pitot_stat, float *_pitot_temp) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_IMCU_REMOTE_BARO(&msg,_pitot_stat,_pitot_temp);
}


#else // DOWNLINK

#define DOWNLINK_SEND_IMCU_REMOTE_BARO(_trans, _dev, pitot_stat, pitot_temp) {}
static inline void pprz_send_msg_IMCU_REMOTE_BARO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_pitot_stat __attribute__((unused)), float *_pitot_temp __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field pitot_stat in message IMCU_REMOTE_BARO
  *
  * @param _payload : a pointer to the IMCU_REMOTE_BARO message
  * @return Static Barometric Pressure in Pascal
  */
static inline float pprzlink_get_DL_IMCU_REMOTE_BARO_pitot_stat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field pitot_temp in message IMCU_REMOTE_BARO
  *
  * @param _payload : a pointer to the IMCU_REMOTE_BARO message
  * @return Pressure Sensor Temperature
  */
static inline float pprzlink_get_DL_IMCU_REMOTE_BARO_pitot_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/* Compatibility macros */
#define DL_IMCU_REMOTE_BARO_pitot_stat(_payload) pprzlink_get_DL_IMCU_REMOTE_BARO_pitot_stat(_payload)
#define DL_IMCU_REMOTE_BARO_pitot_temp(_payload) pprzlink_get_DL_IMCU_REMOTE_BARO_pitot_temp(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_intermcu_IMCU_REMOTE_BARO_H_

