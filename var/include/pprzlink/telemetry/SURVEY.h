/** @file
 *  @brief PPRZLink message header for SURVEY in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_SURVEY_H_
#define _VAR_MESSAGES_telemetry_SURVEY_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_SURVEY 27
#define PPRZ_MSG_ID_SURVEY 27

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_SURVEY _send_msg(SURVEY,PPRZLINK_DEFAULT_VER)

/**
 * Sends a SURVEY message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _east 
 * @param _north 
 * @param _west 
 * @param _south 
 */
static inline void pprzlink_msg_v2_send_SURVEY(struct pprzlink_msg * msg, float *_east, float *_north, float *_west, float *_south) {
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
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_SURVEY, "SURVEY");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _east, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _north, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _west, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _south, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_SURVEY pprz_msg_send_SURVEY
#define DOWNLINK_SEND_SURVEY(_trans, _dev, east, north, west, south) pprz_msg_send_SURVEY(&((_trans).trans_tx), &((_dev).device), AC_ID, east, north, west, south)
/**
 * Sends a SURVEY message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _east 
 * @param _north 
 * @param _west 
 * @param _south 
 */
static inline void pprz_msg_send_SURVEY(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_east, float *_north, float *_west, float *_south) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_SURVEY(&msg,_east,_north,_west,_south);
}


#else // DOWNLINK

#define DOWNLINK_SEND_SURVEY(_trans, _dev, east, north, west, south) {}
static inline void pprz_send_msg_SURVEY(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_east __attribute__((unused)), float *_north __attribute__((unused)), float *_west __attribute__((unused)), float *_south __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field east in message SURVEY
  *
  * @param _payload : a pointer to the SURVEY message
  * @return 
  */
static inline float pprzlink_get_DL_SURVEY_east(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field north in message SURVEY
  *
  * @param _payload : a pointer to the SURVEY message
  * @return 
  */
static inline float pprzlink_get_DL_SURVEY_north(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field west in message SURVEY
  *
  * @param _payload : a pointer to the SURVEY message
  * @return 
  */
static inline float pprzlink_get_DL_SURVEY_west(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field south in message SURVEY
  *
  * @param _payload : a pointer to the SURVEY message
  * @return 
  */
static inline float pprzlink_get_DL_SURVEY_south(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/* Compatibility macros */
#define DL_SURVEY_east(_payload) pprzlink_get_DL_SURVEY_east(_payload)
#define DL_SURVEY_north(_payload) pprzlink_get_DL_SURVEY_north(_payload)
#define DL_SURVEY_west(_payload) pprzlink_get_DL_SURVEY_west(_payload)
#define DL_SURVEY_south(_payload) pprzlink_get_DL_SURVEY_south(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_SURVEY_H_

