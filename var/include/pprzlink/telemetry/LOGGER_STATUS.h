/** @file
 *  @brief PPRZLink message header for LOGGER_STATUS in class telemetry
 *
 *  
        Logger status and error id (dependent of the logging system)
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_LOGGER_STATUS_H_
#define _VAR_MESSAGES_telemetry_LOGGER_STATUS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_LOGGER_STATUS 92
#define PPRZ_MSG_ID_LOGGER_STATUS 92

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_LOGGER_STATUS _send_msg(LOGGER_STATUS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a LOGGER_STATUS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _status General status of the logger
 * @param _errno Error number, depend of the logging system, provides detailed information
 * @param _used Accumulated number of bytes written by the logger
 * @param nb_filenames,_filenames The filenames currently in use by the logger (First sdlog, second Flight recorder for chibios)
 */
static inline void pprzlink_msg_v2_send_LOGGER_STATUS(struct pprzlink_msg * msg, uint8_t *_status, uint8_t *_errno, uint32_t *_used, uint8_t nb_filenames, char *_filenames) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+1+nb_filenames*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+1+nb_filenames*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_LOGGER_STATUS, "LOGGER_STATUS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _status, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _errno, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _used, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_filenames, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _filenames, nb_filenames*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_LOGGER_STATUS pprz_msg_send_LOGGER_STATUS
#define DOWNLINK_SEND_LOGGER_STATUS(_trans, _dev, status, errno, used, nb_filenames, filenames) pprz_msg_send_LOGGER_STATUS(&((_trans).trans_tx), &((_dev).device), AC_ID, status, errno, used, nb_filenames, filenames)
/**
 * Sends a LOGGER_STATUS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _status General status of the logger
 * @param _errno Error number, depend of the logging system, provides detailed information
 * @param _used Accumulated number of bytes written by the logger
 * @param nb_filenames,_filenames The filenames currently in use by the logger (First sdlog, second Flight recorder for chibios)
 */
static inline void pprz_msg_send_LOGGER_STATUS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_status, uint8_t *_errno, uint32_t *_used, uint8_t nb_filenames, char *_filenames) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_LOGGER_STATUS(&msg,_status,_errno,_used,nb_filenames,_filenames);
}


#else // DOWNLINK

#define DOWNLINK_SEND_LOGGER_STATUS(_trans, _dev, status, errno, used, nb_filenames, filenames) {}
static inline void pprz_send_msg_LOGGER_STATUS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_status __attribute__((unused)), uint8_t *_errno __attribute__((unused)), uint32_t *_used __attribute__((unused)), uint8_t nb_filenames __attribute__((unused)), char *_filenames __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field status in message LOGGER_STATUS
  *
  * @param _payload : a pointer to the LOGGER_STATUS message
  * @return General status of the logger
  */
static inline uint8_t pprzlink_get_DL_LOGGER_STATUS_status(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field errno in message LOGGER_STATUS
  *
  * @param _payload : a pointer to the LOGGER_STATUS message
  * @return Error number, depend of the logging system, provides detailed information
  */
static inline uint8_t pprzlink_get_DL_LOGGER_STATUS_errno(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field used in message LOGGER_STATUS
  *
  * @param _payload : a pointer to the LOGGER_STATUS message
  * @return Accumulated number of bytes written by the logger
  */
static inline uint32_t pprzlink_get_DL_LOGGER_STATUS_used(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 6);
}

/** Getter for length of array filenames in message LOGGER_STATUS
 *
 * @return filenames : The filenames currently in use by the logger (First sdlog, second Flight recorder for chibios)
 */
 static inline uint8_t pprzlink_get_LOGGER_STATUS_filenames_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 10);
}

/** Getter for field filenames in message LOGGER_STATUS
  *
  * @param _payload : a pointer to the LOGGER_STATUS message
  * @return The filenames currently in use by the logger (First sdlog, second Flight recorder for chibios)
  */
static inline char * pprzlink_get_DL_LOGGER_STATUS_filenames(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 11);
}


/* Compatibility macros */
#define DL_LOGGER_STATUS_status(_payload) pprzlink_get_DL_LOGGER_STATUS_status(_payload)
#define DL_LOGGER_STATUS_errno(_payload) pprzlink_get_DL_LOGGER_STATUS_errno(_payload)
#define DL_LOGGER_STATUS_used(_payload) pprzlink_get_DL_LOGGER_STATUS_used(_payload)
#define DL_LOGGER_STATUS_filenames_length(_payload) pprzlink_get_LOGGER_STATUS_filenames_length(_payload)
#define DL_LOGGER_STATUS_filenames(_payload) pprzlink_get_DL_LOGGER_STATUS_filenames(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_LOGGER_STATUS_H_

