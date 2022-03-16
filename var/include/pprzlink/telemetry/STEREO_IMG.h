/** @file
 *  @brief PPRZLink message header for STEREO_IMG in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STEREO_IMG_H_
#define _VAR_MESSAGES_telemetry_STEREO_IMG_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STEREO_IMG 229
#define PPRZ_MSG_ID_STEREO_IMG 229

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STEREO_IMG _send_msg(STEREO_IMG,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STEREO_IMG message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _type 
 * @param _width 
 * @param _height 
 * @param _package_nb 
 * @param nb_image_data,_image_data 
 */
static inline void pprzlink_msg_v2_send_STEREO_IMG(struct pprzlink_msg * msg, uint8_t *_type, uint8_t *_width, uint8_t *_height, uint8_t *_package_nb, uint8_t nb_image_data, uint8_t *_image_data) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+1+1+1+nb_image_data*1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+1+1+1+nb_image_data*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STEREO_IMG, "STEREO_IMG");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _type, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _width, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _height, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _package_nb, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_image_data, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_ARRAY, (void *) _image_data, nb_image_data*1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STEREO_IMG pprz_msg_send_STEREO_IMG
#define DOWNLINK_SEND_STEREO_IMG(_trans, _dev, type, width, height, package_nb, nb_image_data, image_data) pprz_msg_send_STEREO_IMG(&((_trans).trans_tx), &((_dev).device), AC_ID, type, width, height, package_nb, nb_image_data, image_data)
/**
 * Sends a STEREO_IMG message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _type 
 * @param _width 
 * @param _height 
 * @param _package_nb 
 * @param nb_image_data,_image_data 
 */
static inline void pprz_msg_send_STEREO_IMG(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_type, uint8_t *_width, uint8_t *_height, uint8_t *_package_nb, uint8_t nb_image_data, uint8_t *_image_data) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STEREO_IMG(&msg,_type,_width,_height,_package_nb,nb_image_data,_image_data);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STEREO_IMG(_trans, _dev, type, width, height, package_nb, nb_image_data, image_data) {}
static inline void pprz_send_msg_STEREO_IMG(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_type __attribute__((unused)), uint8_t *_width __attribute__((unused)), uint8_t *_height __attribute__((unused)), uint8_t *_package_nb __attribute__((unused)), uint8_t nb_image_data __attribute__((unused)), uint8_t *_image_data __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field type in message STEREO_IMG
  *
  * @param _payload : a pointer to the STEREO_IMG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREO_IMG_type(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field width in message STEREO_IMG
  *
  * @param _payload : a pointer to the STEREO_IMG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREO_IMG_width(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field height in message STEREO_IMG
  *
  * @param _payload : a pointer to the STEREO_IMG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREO_IMG_height(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}


/** Getter for field package_nb in message STEREO_IMG
  *
  * @param _payload : a pointer to the STEREO_IMG message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_STEREO_IMG_package_nb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 7);
}

/** Getter for length of array image_data in message STEREO_IMG
 *
 * @return image_data : 
 */
 static inline uint8_t pprzlink_get_STEREO_IMG_image_data_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 8);
}

/** Getter for field image_data in message STEREO_IMG
  *
  * @param _payload : a pointer to the STEREO_IMG message
  * @return 
  */
static inline uint8_t * pprzlink_get_DL_STEREO_IMG_image_data(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t_array(_payload, 9);
}


/* Compatibility macros */
#define DL_STEREO_IMG_type(_payload) pprzlink_get_DL_STEREO_IMG_type(_payload)
#define DL_STEREO_IMG_width(_payload) pprzlink_get_DL_STEREO_IMG_width(_payload)
#define DL_STEREO_IMG_height(_payload) pprzlink_get_DL_STEREO_IMG_height(_payload)
#define DL_STEREO_IMG_package_nb(_payload) pprzlink_get_DL_STEREO_IMG_package_nb(_payload)
#define DL_STEREO_IMG_image_data_length(_payload) pprzlink_get_STEREO_IMG_image_data_length(_payload)
#define DL_STEREO_IMG_image_data(_payload) pprzlink_get_DL_STEREO_IMG_image_data(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STEREO_IMG_H_

