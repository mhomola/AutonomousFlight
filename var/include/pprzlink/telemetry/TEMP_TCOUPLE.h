/** @file
 *  @brief PPRZLink message header for TEMP_TCOUPLE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_TEMP_TCOUPLE_H_
#define _VAR_MESSAGES_telemetry_TEMP_TCOUPLE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_TEMP_TCOUPLE 126
#define PPRZ_MSG_ID_TEMP_TCOUPLE 126

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_TEMP_TCOUPLE _send_msg(TEMP_TCOUPLE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a TEMP_TCOUPLE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _fval0 
 * @param _fval1 
 * @param _fval2 
 * @param _fval3 
 * @param _fref0 
 * @param _fref1 
 * @param _fref2 
 * @param _fref3 
 * @param _val0 
 * @param _val1 
 * @param _val2 
 * @param _val3 
 * @param _ref0 
 * @param _ref1 
 * @param _ref2 
 * @param _ref3 
 */
static inline void pprzlink_msg_v2_send_TEMP_TCOUPLE(struct pprzlink_msg * msg, float *_fval0, float *_fval1, float *_fval2, float *_fval3, float *_fref0, float *_fref1, float *_fref2, float *_fref3, uint16_t *_val0, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_ref0, uint16_t *_ref1, uint16_t *_ref2, uint16_t *_ref3) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_TEMP_TCOUPLE, "TEMP_TCOUPLE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fval0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fval1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fval2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fval3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fref0, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fref1, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fref2, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fref3, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _val3, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ref0, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ref1, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ref2, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ref3, 2);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_TEMP_TCOUPLE pprz_msg_send_TEMP_TCOUPLE
#define DOWNLINK_SEND_TEMP_TCOUPLE(_trans, _dev, fval0, fval1, fval2, fval3, fref0, fref1, fref2, fref3, val0, val1, val2, val3, ref0, ref1, ref2, ref3) pprz_msg_send_TEMP_TCOUPLE(&((_trans).trans_tx), &((_dev).device), AC_ID, fval0, fval1, fval2, fval3, fref0, fref1, fref2, fref3, val0, val1, val2, val3, ref0, ref1, ref2, ref3)
/**
 * Sends a TEMP_TCOUPLE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _fval0 
 * @param _fval1 
 * @param _fval2 
 * @param _fval3 
 * @param _fref0 
 * @param _fref1 
 * @param _fref2 
 * @param _fref3 
 * @param _val0 
 * @param _val1 
 * @param _val2 
 * @param _val3 
 * @param _ref0 
 * @param _ref1 
 * @param _ref2 
 * @param _ref3 
 */
static inline void pprz_msg_send_TEMP_TCOUPLE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_fval0, float *_fval1, float *_fval2, float *_fval3, float *_fref0, float *_fref1, float *_fref2, float *_fref3, uint16_t *_val0, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_ref0, uint16_t *_ref1, uint16_t *_ref2, uint16_t *_ref3) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_TEMP_TCOUPLE(&msg,_fval0,_fval1,_fval2,_fval3,_fref0,_fref1,_fref2,_fref3,_val0,_val1,_val2,_val3,_ref0,_ref1,_ref2,_ref3);
}


#else // DOWNLINK

#define DOWNLINK_SEND_TEMP_TCOUPLE(_trans, _dev, fval0, fval1, fval2, fval3, fref0, fref1, fref2, fref3, val0, val1, val2, val3, ref0, ref1, ref2, ref3) {}
static inline void pprz_send_msg_TEMP_TCOUPLE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_fval0 __attribute__((unused)), float *_fval1 __attribute__((unused)), float *_fval2 __attribute__((unused)), float *_fval3 __attribute__((unused)), float *_fref0 __attribute__((unused)), float *_fref1 __attribute__((unused)), float *_fref2 __attribute__((unused)), float *_fref3 __attribute__((unused)), uint16_t *_val0 __attribute__((unused)), uint16_t *_val1 __attribute__((unused)), uint16_t *_val2 __attribute__((unused)), uint16_t *_val3 __attribute__((unused)), uint16_t *_ref0 __attribute__((unused)), uint16_t *_ref1 __attribute__((unused)), uint16_t *_ref2 __attribute__((unused)), uint16_t *_ref3 __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field fval0 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fval0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field fval1 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fval1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field fval2 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fval2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field fval3 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fval3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field fref0 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fref0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field fref1 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fref1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field fref2 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fref2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field fref3 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline float pprzlink_get_DL_TEMP_TCOUPLE_fref3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field val0 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_val0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 36);
}


/** Getter for field val1 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_val1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 38);
}


/** Getter for field val2 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_val2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 40);
}


/** Getter for field val3 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_val3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 42);
}


/** Getter for field ref0 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_ref0(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 44);
}


/** Getter for field ref1 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_ref1(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 46);
}


/** Getter for field ref2 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_ref2(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 48);
}


/** Getter for field ref3 in message TEMP_TCOUPLE
  *
  * @param _payload : a pointer to the TEMP_TCOUPLE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_TEMP_TCOUPLE_ref3(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 50);
}


/* Compatibility macros */
#define DL_TEMP_TCOUPLE_fval0(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fval0(_payload)
#define DL_TEMP_TCOUPLE_fval1(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fval1(_payload)
#define DL_TEMP_TCOUPLE_fval2(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fval2(_payload)
#define DL_TEMP_TCOUPLE_fval3(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fval3(_payload)
#define DL_TEMP_TCOUPLE_fref0(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fref0(_payload)
#define DL_TEMP_TCOUPLE_fref1(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fref1(_payload)
#define DL_TEMP_TCOUPLE_fref2(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fref2(_payload)
#define DL_TEMP_TCOUPLE_fref3(_payload) pprzlink_get_DL_TEMP_TCOUPLE_fref3(_payload)
#define DL_TEMP_TCOUPLE_val0(_payload) pprzlink_get_DL_TEMP_TCOUPLE_val0(_payload)
#define DL_TEMP_TCOUPLE_val1(_payload) pprzlink_get_DL_TEMP_TCOUPLE_val1(_payload)
#define DL_TEMP_TCOUPLE_val2(_payload) pprzlink_get_DL_TEMP_TCOUPLE_val2(_payload)
#define DL_TEMP_TCOUPLE_val3(_payload) pprzlink_get_DL_TEMP_TCOUPLE_val3(_payload)
#define DL_TEMP_TCOUPLE_ref0(_payload) pprzlink_get_DL_TEMP_TCOUPLE_ref0(_payload)
#define DL_TEMP_TCOUPLE_ref1(_payload) pprzlink_get_DL_TEMP_TCOUPLE_ref1(_payload)
#define DL_TEMP_TCOUPLE_ref2(_payload) pprzlink_get_DL_TEMP_TCOUPLE_ref2(_payload)
#define DL_TEMP_TCOUPLE_ref3(_payload) pprzlink_get_DL_TEMP_TCOUPLE_ref3(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_TEMP_TCOUPLE_H_

