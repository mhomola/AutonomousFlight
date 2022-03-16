/** @file
 *  @brief PPRZLink message header for MS5611_COEFF in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_MS5611_COEFF_H_
#define _VAR_MESSAGES_telemetry_MS5611_COEFF_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_MS5611_COEFF 117
#define PPRZ_MSG_ID_MS5611_COEFF 117

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_MS5611_COEFF _send_msg(MS5611_COEFF,PPRZLINK_DEFAULT_VER)

/**
 * Sends a MS5611_COEFF message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _c0 
 * @param _c1 
 * @param _c2 
 * @param _c3 
 * @param _c4 
 * @param _c5 
 * @param _c6 
 * @param _c7 
 */
static inline void pprzlink_msg_v2_send_MS5611_COEFF(struct pprzlink_msg * msg, uint16_t *_c0, uint16_t *_c1, uint16_t *_c2, uint16_t *_c3, uint16_t *_c4, uint16_t *_c5, uint16_t *_c6, uint16_t *_c7) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_MS5611_COEFF, "MS5611_COEFF");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c4, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c5, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c6, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _c7, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_MS5611_COEFF pprz_msg_send_MS5611_COEFF
#define DOWNLINK_SEND_MS5611_COEFF(_trans, _dev, c0, c1, c2, c3, c4, c5, c6, c7) pprz_msg_send_MS5611_COEFF(&((_trans).trans_tx), &((_dev).device), AC_ID, c0, c1, c2, c3, c4, c5, c6, c7)
/**
 * Sends a MS5611_COEFF message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _c0 
 * @param _c1 
 * @param _c2 
 * @param _c3 
 * @param _c4 
 * @param _c5 
 * @param _c6 
 * @param _c7 
 */
static inline void pprz_msg_send_MS5611_COEFF(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_c0, uint16_t *_c1, uint16_t *_c2, uint16_t *_c3, uint16_t *_c4, uint16_t *_c5, uint16_t *_c6, uint16_t *_c7) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_MS5611_COEFF(&msg,_c0,_c1,_c2,_c3,_c4,_c5,_c6,_c7);
}


#else // DOWNLINK

#define DOWNLINK_SEND_MS5611_COEFF(_trans, _dev, c0, c1, c2, c3, c4, c5, c6, c7) {}
static inline void pprz_send_msg_MS5611_COEFF(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_c0 __attribute__((unused)), uint16_t *_c1 __attribute__((unused)), uint16_t *_c2 __attribute__((unused)), uint16_t *_c3 __attribute__((unused)), uint16_t *_c4 __attribute__((unused)), uint16_t *_c5 __attribute__((unused)), uint16_t *_c6 __attribute__((unused)), uint16_t *_c7 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field c0 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field c1 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field c2 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 8);
}


/** Getter for field c3 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 10);
}


/** Getter for field c4 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 12);
}


/** Getter for field c5 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c5(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field c6 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c6(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 16);
}


/** Getter for field c7 in message MS5611_COEFF
  *
  * @param _payload : a pointer to the MS5611_COEFF message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_MS5611_COEFF_c7(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 18);
}


/* Compatibility macros */
#define DL_MS5611_COEFF_c0(_payload) pprzlink_get_DL_MS5611_COEFF_c0(_payload)
#define DL_MS5611_COEFF_c1(_payload) pprzlink_get_DL_MS5611_COEFF_c1(_payload)
#define DL_MS5611_COEFF_c2(_payload) pprzlink_get_DL_MS5611_COEFF_c2(_payload)
#define DL_MS5611_COEFF_c3(_payload) pprzlink_get_DL_MS5611_COEFF_c3(_payload)
#define DL_MS5611_COEFF_c4(_payload) pprzlink_get_DL_MS5611_COEFF_c4(_payload)
#define DL_MS5611_COEFF_c5(_payload) pprzlink_get_DL_MS5611_COEFF_c5(_payload)
#define DL_MS5611_COEFF_c6(_payload) pprzlink_get_DL_MS5611_COEFF_c6(_payload)
#define DL_MS5611_COEFF_c7(_payload) pprzlink_get_DL_MS5611_COEFF_c7(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_MS5611_COEFF_H_

