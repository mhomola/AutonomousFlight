/** @file
 *  @brief PPRZLink message header for VIDEO_ROI in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_VIDEO_ROI_H_
#define _VAR_MESSAGES_datalink_VIDEO_ROI_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_VIDEO_ROI 155
#define PPRZ_MSG_ID_VIDEO_ROI 155

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_VIDEO_ROI _send_msg(VIDEO_ROI,PPRZLINK_DEFAULT_VER)

/**
 * Sends a VIDEO_ROI message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _ac_id The aircraft in which video stream you clicked 
 * @param _startx The x of the upper left corner of the selected area
 * @param _starty The y of the upper left corner of the selected area 
 * @param _width The width of the selected area 
 * @param _height The height of the selected area 
 * @param _downsized_width The width of the image you received. Added because a module the receives this message does not know how big the image was that was broadcasted 
 */
static inline void pprzlink_msg_v2_send_VIDEO_ROI(struct pprzlink_msg * msg, uint8_t *_ac_id, int32_t *_startx, int32_t *_starty, int32_t *_width, int32_t *_height, int32_t *_downsized_width) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_VIDEO_ROI, "VIDEO_ROI");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _startx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _starty, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _width, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _height, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _downsized_width, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_VIDEO_ROI pprz_msg_send_VIDEO_ROI
#define DOWNLINK_SEND_VIDEO_ROI(_trans, _dev, ac_id, startx, starty, width, height, downsized_width) pprz_msg_send_VIDEO_ROI(&((_trans).trans_tx), &((_dev).device), AC_ID, ac_id, startx, starty, width, height, downsized_width)
/**
 * Sends a VIDEO_ROI message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _ac_id The aircraft in which video stream you clicked 
 * @param _startx The x of the upper left corner of the selected area
 * @param _starty The y of the upper left corner of the selected area 
 * @param _width The width of the selected area 
 * @param _height The height of the selected area 
 * @param _downsized_width The width of the image you received. Added because a module the receives this message does not know how big the image was that was broadcasted 
 */
static inline void pprz_msg_send_VIDEO_ROI(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_ac_id, int32_t *_startx, int32_t *_starty, int32_t *_width, int32_t *_height, int32_t *_downsized_width) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_VIDEO_ROI(&msg,_ac_id,_startx,_starty,_width,_height,_downsized_width);
}


#else // DOWNLINK

#define DOWNLINK_SEND_VIDEO_ROI(_trans, _dev, ac_id, startx, starty, width, height, downsized_width) {}
static inline void pprz_send_msg_VIDEO_ROI(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_ac_id __attribute__((unused)), int32_t *_startx __attribute__((unused)), int32_t *_starty __attribute__((unused)), int32_t *_width __attribute__((unused)), int32_t *_height __attribute__((unused)), int32_t *_downsized_width __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field ac_id in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The aircraft in which video stream you clicked 
  */
static inline uint8_t pprzlink_get_DL_VIDEO_ROI_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field startx in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The x of the upper left corner of the selected area
  */
static inline int32_t pprzlink_get_DL_VIDEO_ROI_startx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 5);
}


/** Getter for field starty in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The y of the upper left corner of the selected area 
  */
static inline int32_t pprzlink_get_DL_VIDEO_ROI_starty(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 9);
}


/** Getter for field width in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The width of the selected area 
  */
static inline int32_t pprzlink_get_DL_VIDEO_ROI_width(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 13);
}


/** Getter for field height in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The height of the selected area 
  */
static inline int32_t pprzlink_get_DL_VIDEO_ROI_height(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 17);
}


/** Getter for field downsized_width in message VIDEO_ROI
  *
  * @param _payload : a pointer to the VIDEO_ROI message
  * @return The width of the image you received. Added because a module the receives this message does not know how big the image was that was broadcasted 
  */
static inline int32_t pprzlink_get_DL_VIDEO_ROI_downsized_width(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 21);
}


/* Compatibility macros */
#define DL_VIDEO_ROI_ac_id(_payload) pprzlink_get_DL_VIDEO_ROI_ac_id(_payload)
#define DL_VIDEO_ROI_startx(_payload) pprzlink_get_DL_VIDEO_ROI_startx(_payload)
#define DL_VIDEO_ROI_starty(_payload) pprzlink_get_DL_VIDEO_ROI_starty(_payload)
#define DL_VIDEO_ROI_width(_payload) pprzlink_get_DL_VIDEO_ROI_width(_payload)
#define DL_VIDEO_ROI_height(_payload) pprzlink_get_DL_VIDEO_ROI_height(_payload)
#define DL_VIDEO_ROI_downsized_width(_payload) pprzlink_get_DL_VIDEO_ROI_downsized_width(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_VIDEO_ROI_H_

