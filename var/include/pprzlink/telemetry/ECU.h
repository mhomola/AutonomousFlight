/** @file
 *  @brief PPRZLink message header for ECU in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ECU_H_
#define _VAR_MESSAGES_telemetry_ECU_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ECU 19
#define PPRZ_MSG_ID_ECU 19

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ECU _send_msg(ECU,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ECU message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _stg_in 
 * @param _stb_in 
 * @param _ain1 
 * @param _ain2 
 * @param _ain3 
 * @param _ain4 
 */
static inline void pprzlink_msg_v2_send_ECU(struct pprzlink_msg * msg, uint8_t *_stg_in, uint8_t *_stb_in, float *_ain1, float *_ain2, float *_ain3, float *_ain4) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ECU, "ECU");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _stg_in, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _stb_in, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ain1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ain2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ain3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _ain4, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ECU pprz_msg_send_ECU
#define DOWNLINK_SEND_ECU(_trans, _dev, stg_in, stb_in, ain1, ain2, ain3, ain4) pprz_msg_send_ECU(&((_trans).trans_tx), &((_dev).device), AC_ID, stg_in, stb_in, ain1, ain2, ain3, ain4)
/**
 * Sends a ECU message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _stg_in 
 * @param _stb_in 
 * @param _ain1 
 * @param _ain2 
 * @param _ain3 
 * @param _ain4 
 */
static inline void pprz_msg_send_ECU(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_stg_in, uint8_t *_stb_in, float *_ain1, float *_ain2, float *_ain3, float *_ain4) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ECU(&msg,_stg_in,_stb_in,_ain1,_ain2,_ain3,_ain4);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ECU(_trans, _dev, stg_in, stb_in, ain1, ain2, ain3, ain4) {}
static inline void pprz_send_msg_ECU(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_stg_in __attribute__((unused)), uint8_t *_stb_in __attribute__((unused)), float *_ain1 __attribute__((unused)), float *_ain2 __attribute__((unused)), float *_ain3 __attribute__((unused)), float *_ain4 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field stg_in in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ECU_stg_in(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field stb_in in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ECU_stb_in(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field ain1 in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline float pprzlink_get_DL_ECU_ain1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field ain2 in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline float pprzlink_get_DL_ECU_ain2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field ain3 in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline float pprzlink_get_DL_ECU_ain3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field ain4 in message ECU
  *
  * @param _payload : a pointer to the ECU message
  * @return 
  */
static inline float pprzlink_get_DL_ECU_ain4(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 18);
}


/* Compatibility macros */
#define DL_ECU_stg_in(_payload) pprzlink_get_DL_ECU_stg_in(_payload)
#define DL_ECU_stb_in(_payload) pprzlink_get_DL_ECU_stb_in(_payload)
#define DL_ECU_ain1(_payload) pprzlink_get_DL_ECU_ain1(_payload)
#define DL_ECU_ain2(_payload) pprzlink_get_DL_ECU_ain2(_payload)
#define DL_ECU_ain3(_payload) pprzlink_get_DL_ECU_ain3(_payload)
#define DL_ECU_ain4(_payload) pprzlink_get_DL_ECU_ain4(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ECU_H_

