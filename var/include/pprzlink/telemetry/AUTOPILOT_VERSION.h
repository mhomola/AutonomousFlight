/** @file
 *  @brief PPRZLink message header for AUTOPILOT_VERSION in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_AUTOPILOT_VERSION_H_
#define _VAR_MESSAGES_telemetry_AUTOPILOT_VERSION_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_AUTOPILOT_VERSION 1
#define PPRZ_MSG_ID_AUTOPILOT_VERSION 1

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_AUTOPILOT_VERSION _send_msg(AUTOPILOT_VERSION,PPRZLINK_DEFAULT_VER)

/**
 * Sends a AUTOPILOT_VERSION message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _version version encoded as: MAJOR * 10000 + MINOR * 100 + PATCH
 * @param nb_desc,_desc version description as string from paparazzi_version
 */
static inline void pprzlink_msg_v2_send_AUTOPILOT_VERSION(struct pprzlink_msg * msg, uint32_t *_version, uint8_t nb_desc, char *_desc) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+1+nb_desc*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+1+nb_desc*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_AUTOPILOT_VERSION, "AUTOPILOT_VERSION");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT32, DL_FORMAT_SCALAR, (void *) _version, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_desc, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _desc, nb_desc*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_AUTOPILOT_VERSION pprz_msg_send_AUTOPILOT_VERSION
#define DOWNLINK_SEND_AUTOPILOT_VERSION(_trans, _dev, version, nb_desc, desc) pprz_msg_send_AUTOPILOT_VERSION(&((_trans).trans_tx), &((_dev).device), AC_ID, version, nb_desc, desc)
/**
 * Sends a AUTOPILOT_VERSION message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _version version encoded as: MAJOR * 10000 + MINOR * 100 + PATCH
 * @param nb_desc,_desc version description as string from paparazzi_version
 */
static inline void pprz_msg_send_AUTOPILOT_VERSION(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint32_t *_version, uint8_t nb_desc, char *_desc) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_AUTOPILOT_VERSION(&msg,_version,nb_desc,_desc);
}


#else // DOWNLINK

#define DOWNLINK_SEND_AUTOPILOT_VERSION(_trans, _dev, version, nb_desc, desc) {}
static inline void pprz_send_msg_AUTOPILOT_VERSION(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint32_t *_version __attribute__((unused)), uint8_t nb_desc __attribute__((unused)), char *_desc __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field version in message AUTOPILOT_VERSION
  *
  * @param _payload : a pointer to the AUTOPILOT_VERSION message
  * @return version encoded as: MAJOR * 10000 + MINOR * 100 + PATCH
  */
static inline uint32_t pprzlink_get_DL_AUTOPILOT_VERSION_version(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint32_t(_payload, 4);
}

/** Getter for length of array desc in message AUTOPILOT_VERSION
 *
 * @return desc : version description as string from paparazzi_version
 */
 static inline uint8_t pprzlink_get_AUTOPILOT_VERSION_desc_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 8);
}

/** Getter for field desc in message AUTOPILOT_VERSION
  *
  * @param _payload : a pointer to the AUTOPILOT_VERSION message
  * @return version description as string from paparazzi_version
  */
static inline char * pprzlink_get_DL_AUTOPILOT_VERSION_desc(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 9);
}


/* Compatibility macros */
#define DL_AUTOPILOT_VERSION_version(_payload) pprzlink_get_DL_AUTOPILOT_VERSION_version(_payload)
#define DL_AUTOPILOT_VERSION_desc_length(_payload) pprzlink_get_AUTOPILOT_VERSION_desc_length(_payload)
#define DL_AUTOPILOT_VERSION_desc(_payload) pprzlink_get_DL_AUTOPILOT_VERSION_desc(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_AUTOPILOT_VERSION_H_

