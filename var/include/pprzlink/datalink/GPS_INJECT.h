/** @file
 *  @brief PPRZLink message header for GPS_INJECT in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_GPS_INJECT_H_
#define _VAR_MESSAGES_datalink_GPS_INJECT_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_GPS_INJECT 153
#define PPRZ_MSG_ID_GPS_INJECT 153

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_GPS_INJECT _send_msg(GPS_INJECT,PPRZLINK_DEFAULT_VER)

/**
 * Sends a GPS_INJECT message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id 
 * @param _packet_id 
 * @param nb_data,_data 
 */
static inline void pprzlink_msg_v2_send_GPS_INJECT(struct pprzlink_msg * msg, uint8_t *_ac_id, uint8_t *_packet_id, uint8_t nb_data, uint8_t *_data) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+nb_data*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+nb_data*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_GPS_INJECT, "GPS_INJECT");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _packet_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_data, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _data, nb_data*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_GPS_INJECT pprz_msg_send_GPS_INJECT
#define DOWNLINK_SEND_GPS_INJECT(_trans, _dev, ac_id, packet_id, nb_data, data) pprz_msg_send_GPS_INJECT(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, packet_id, nb_data, data)
/**
 * Sends a GPS_INJECT message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id 
 * @param _packet_id 
 * @param nb_data,_data 
 */
static inline void pprz_msg_send_GPS_INJECT(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, uint8_t *_packet_id, uint8_t nb_data, uint8_t *_data) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_GPS_INJECT(&msg,_ac_id,_packet_id,nb_data,_data);
}


#else // DOWNLINK

#define DOWNLINK_SEND_GPS_INJECT(_trans, _dev, ac_id, packet_id, nb_data, data) {}
static inline void pprz_send_msg_GPS_INJECT(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), uint8_t *_packet_id __attribute__((unused)), uint8_t nb_data __attribute__((unused)), uint8_t *_data __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message GPS_INJECT
  *
  * @param _payload : a pointer to the GPS_INJECT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_INJECT_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field packet_id in message GPS_INJECT
  *
  * @param _payload : a pointer to the GPS_INJECT message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_GPS_INJECT_packet_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for length of array data in message GPS_INJECT
 *
 * @return data : 
 */
 static inline uint8_t pprzlink_get_GPS_INJECT_data_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for field data in message GPS_INJECT
  *
  * @param _payload : a pointer to the GPS_INJECT message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_GPS_INJECT_data(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 7);
}


/* Compatibility macros */
#define DL_GPS_INJECT_ac_id(_payload) pprzlink_get_DL_GPS_INJECT_ac_id(_payload)
#define DL_GPS_INJECT_packet_id(_payload) pprzlink_get_DL_GPS_INJECT_packet_id(_payload)
#define DL_GPS_INJECT_data_length(_payload) pprzlink_get_GPS_INJECT_data_length(_payload)
#define DL_GPS_INJECT_data(_payload) pprzlink_get_DL_GPS_INJECT_data(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_GPS_INJECT_H_

