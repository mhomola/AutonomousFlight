/** @file
 *  @brief PPRZLink message header for FLIGHT_BENCHMARK in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_FLIGHT_BENCHMARK_H_
#define _VAR_MESSAGES_telemetry_FLIGHT_BENCHMARK_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_FLIGHT_BENCHMARK 67
#define PPRZ_MSG_ID_FLIGHT_BENCHMARK 67

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_FLIGHT_BENCHMARK _send_msg(FLIGHT_BENCHMARK,PPRZLINK_DEFAULT_VER)

/**
 * Sends a FLIGHT_BENCHMARK message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _SE_As 
 * @param _SE_Alt 
 * @param _SE_Pos 
 * @param _Err_As 
 * @param _Err_Alt 
 * @param _Err_Pos 
 */
static inline void pprzlink_msg_v2_send_FLIGHT_BENCHMARK(struct pprzlink_msg * msg, float *_SE_As, float *_SE_Alt, float *_SE_Pos, float *_Err_As, float *_Err_Alt, float *_Err_Pos) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_FLIGHT_BENCHMARK, "FLIGHT_BENCHMARK");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _SE_As, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _SE_Alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _SE_Pos, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Err_As, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Err_Alt, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Err_Pos, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_FLIGHT_BENCHMARK pprz_msg_send_FLIGHT_BENCHMARK
#define DOWNLINK_SEND_FLIGHT_BENCHMARK(_trans, _dev, SE_As, SE_Alt, SE_Pos, Err_As, Err_Alt, Err_Pos) pprz_msg_send_FLIGHT_BENCHMARK(&((_trans).trans_tx), &((_dev).device), AC_ID, SE_As, SE_Alt, SE_Pos, Err_As, Err_Alt, Err_Pos)
/**
 * Sends a FLIGHT_BENCHMARK message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _SE_As 
 * @param _SE_Alt 
 * @param _SE_Pos 
 * @param _Err_As 
 * @param _Err_Alt 
 * @param _Err_Pos 
 */
static inline void pprz_msg_send_FLIGHT_BENCHMARK(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_SE_As, float *_SE_Alt, float *_SE_Pos, float *_Err_As, float *_Err_Alt, float *_Err_Pos) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_FLIGHT_BENCHMARK(&msg,_SE_As,_SE_Alt,_SE_Pos,_Err_As,_Err_Alt,_Err_Pos);
}


#else // DOWNLINK

#define DOWNLINK_SEND_FLIGHT_BENCHMARK(_trans, _dev, SE_As, SE_Alt, SE_Pos, Err_As, Err_Alt, Err_Pos) {}
static inline void pprz_send_msg_FLIGHT_BENCHMARK(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_SE_As __attribute__((unused)), float *_SE_Alt __attribute__((unused)), float *_SE_Pos __attribute__((unused)), float *_Err_As __attribute__((unused)), float *_Err_Alt __attribute__((unused)), float *_Err_Pos __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field SE_As in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_SE_As(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field SE_Alt in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_SE_Alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field SE_Pos in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_SE_Pos(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field Err_As in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_Err_As(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field Err_Alt in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_Err_Alt(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field Err_Pos in message FLIGHT_BENCHMARK
  *
  * @param _payload : a pointer to the FLIGHT_BENCHMARK message
  * @return 
  */
static inline float pprzlink_get_DL_FLIGHT_BENCHMARK_Err_Pos(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/* Compatibility macros */
#define DL_FLIGHT_BENCHMARK_SE_As(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_SE_As(_payload)
#define DL_FLIGHT_BENCHMARK_SE_Alt(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_SE_Alt(_payload)
#define DL_FLIGHT_BENCHMARK_SE_Pos(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_SE_Pos(_payload)
#define DL_FLIGHT_BENCHMARK_Err_As(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_Err_As(_payload)
#define DL_FLIGHT_BENCHMARK_Err_Alt(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_Err_Alt(_payload)
#define DL_FLIGHT_BENCHMARK_Err_Pos(_payload) pprzlink_get_DL_FLIGHT_BENCHMARK_Err_Pos(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_FLIGHT_BENCHMARK_H_

