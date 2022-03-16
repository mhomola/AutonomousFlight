/** @file
 *  @brief PPRZLink message header for RTOS_MON in class telemetry
 *
 *  
        RTOS monitoring
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_RTOS_MON_H_
#define _VAR_MESSAGES_telemetry_RTOS_MON_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_RTOS_MON 246
#define PPRZ_MSG_ID_RTOS_MON 246

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_RTOS_MON _send_msg(RTOS_MON,PPRZLINK_DEFAULT_VER)

/**
 * Sends a RTOS_MON message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _nb_threads Number of running threads
 * @param _cpu_load Global CPU load
 * @param _core_free Core free memory
 * @param _heap_free Total fragmented free memory in the heap
 * @param _heap_frags Number of fragments in the heap
 * @param _heap_largest Largest free block in the heap
 * @param _cpu_time 
 */
static inline void pprzlink_msg_v2_send_RTOS_MON(struct pprzlink_msg * msg, uint8_t *_nb_threads, uint8_t *_cpu_load, uint32_t *_core_free, uint32_t *_heap_free, uint32_t *_heap_frags, uint32_t *_heap_largest, float *_cpu_time) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_RTOS_MON, "RTOS_MON");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nb_threads, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _cpu_load, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _core_free, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _heap_free, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _heap_frags, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _heap_largest, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cpu_time, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_RTOS_MON pprz_msg_send_RTOS_MON
#define DOWNLINK_SEND_RTOS_MON(_trans, _dev, nb_threads, cpu_load, core_free, heap_free, heap_frags, heap_largest, cpu_time) pprz_msg_send_RTOS_MON(&((_trans).trans_tx), &((_dev).device), AC_ID, nb_threads, cpu_load, core_free, heap_free, heap_frags, heap_largest, cpu_time)
/**
 * Sends a RTOS_MON message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _nb_threads Number of running threads
 * @param _cpu_load Global CPU load
 * @param _core_free Core free memory
 * @param _heap_free Total fragmented free memory in the heap
 * @param _heap_frags Number of fragments in the heap
 * @param _heap_largest Largest free block in the heap
 * @param _cpu_time 
 */
static inline void pprz_msg_send_RTOS_MON(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_nb_threads, uint8_t *_cpu_load, uint32_t *_core_free, uint32_t *_heap_free, uint32_t *_heap_frags, uint32_t *_heap_largest, float *_cpu_time) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_RTOS_MON(&msg,_nb_threads,_cpu_load,_core_free,_heap_free,_heap_frags,_heap_largest,_cpu_time);
}


#else // DOWNLINK

#define DOWNLINK_SEND_RTOS_MON(_trans, _dev, nb_threads, cpu_load, core_free, heap_free, heap_frags, heap_largest, cpu_time) {}
static inline void pprz_send_msg_RTOS_MON(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_nb_threads __attribute__((unused)), uint8_t *_cpu_load __attribute__((unused)), uint32_t *_core_free __attribute__((unused)), uint32_t *_heap_free __attribute__((unused)), uint32_t *_heap_frags __attribute__((unused)), uint32_t *_heap_largest __attribute__((unused)), float *_cpu_time __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field nb_threads in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Number of running threads
  */
static inline uint8_t pprzlink_get_DL_RTOS_MON_nb_threads(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field cpu_load in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Global CPU load
  */
static inline uint8_t pprzlink_get_DL_RTOS_MON_cpu_load(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field core_free in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Core free memory
  */
static inline uint32_t pprzlink_get_DL_RTOS_MON_core_free(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}


/** Getter for field heap_free in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Total fragmented free memory in the heap
  */
static inline uint32_t pprzlink_get_DL_RTOS_MON_heap_free(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 10);
}


/** Getter for field heap_frags in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Number of fragments in the heap
  */
static inline uint32_t pprzlink_get_DL_RTOS_MON_heap_frags(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 14);
}


/** Getter for field heap_largest in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return Largest free block in the heap
  */
static inline uint32_t pprzlink_get_DL_RTOS_MON_heap_largest(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 18);
}


/** Getter for field cpu_time in message RTOS_MON
  *
  * @param _payload : a pointer to the RTOS_MON message
  * @return 
  */
static inline float pprzlink_get_DL_RTOS_MON_cpu_time(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 22);
}


/* Compatibility macros */
#define DL_RTOS_MON_nb_threads(_payload) pprzlink_get_DL_RTOS_MON_nb_threads(_payload)
#define DL_RTOS_MON_cpu_load(_payload) pprzlink_get_DL_RTOS_MON_cpu_load(_payload)
#define DL_RTOS_MON_core_free(_payload) pprzlink_get_DL_RTOS_MON_core_free(_payload)
#define DL_RTOS_MON_heap_free(_payload) pprzlink_get_DL_RTOS_MON_heap_free(_payload)
#define DL_RTOS_MON_heap_frags(_payload) pprzlink_get_DL_RTOS_MON_heap_frags(_payload)
#define DL_RTOS_MON_heap_largest(_payload) pprzlink_get_DL_RTOS_MON_heap_largest(_payload)
#define DL_RTOS_MON_cpu_time(_payload) pprzlink_get_DL_RTOS_MON_cpu_time(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_RTOS_MON_H_

