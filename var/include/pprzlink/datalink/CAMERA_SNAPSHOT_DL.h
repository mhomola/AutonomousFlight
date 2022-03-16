/** @file
 *  @brief PPRZLink message header for CAMERA_SNAPSHOT_DL in class datalink
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_datalink_CAMERA_SNAPSHOT_DL_H_
#define _VAR_MESSAGES_datalink_CAMERA_SNAPSHOT_DL_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CAMERA_SNAPSHOT_DL 35
#define PPRZ_MSG_ID_CAMERA_SNAPSHOT_DL 35

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CAMERA_SNAPSHOT_DL _send_msg(CAMERA_SNAPSHOT_DL,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CAMERA_SNAPSHOT_DL message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _camera_id Unique camera ID - consists of make,model and camera index
 * @param _snapshot_image_number Snapshot number in sequence
 * @param _camera_state State of the given camera
 * @param _snapshot_valid Flag checking whether the last snapshot was valid
 * @param _array_temp Imager sensor temperature, NaN if not measured
 * @param _lens_temp Lens temperature, NaN if not measured
 * @param _ac_id 
 */
static inline void pprzlink_msg_v2_send_CAMERA_SNAPSHOT_DL(struct pprzlink_msg * msg, uint16_t *_camera_id, uint16_t *_snapshot_image_number, uint8_t *_camera_state, uint8_t *_snapshot_valid, float *_array_temp, float *_lens_temp, uint8_t *_ac_id) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+2+2+1+1+4+4+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+2+2+1+1+4+4+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (2 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CAMERA_SNAPSHOT_DL, "CAMERA_SNAPSHOT_DL");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _camera_id, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _snapshot_image_number, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _camera_state, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _snapshot_valid, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _array_temp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _lens_temp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _ac_id, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CAMERA_SNAPSHOT_DL pprz_msg_send_CAMERA_SNAPSHOT_DL
#define DOWNLINK_SEND_CAMERA_SNAPSHOT_DL(_trans, _dev, camera_id, snapshot_image_number, camera_state, snapshot_valid, array_temp, lens_temp, ac_id) pprz_msg_send_CAMERA_SNAPSHOT_DL(&((_trans).trans_tx), &((_dev).device), AC_ID, camera_id, snapshot_image_number, camera_state, snapshot_valid, array_temp, lens_temp, ac_id)
/**
 * Sends a CAMERA_SNAPSHOT_DL message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _camera_id Unique camera ID - consists of make,model and camera index
 * @param _snapshot_image_number Snapshot number in sequence
 * @param _camera_state State of the given camera
 * @param _snapshot_valid Flag checking whether the last snapshot was valid
 * @param _array_temp Imager sensor temperature, NaN if not measured
 * @param _lens_temp Lens temperature, NaN if not measured
 * @param _ac_id 
 */
static inline void pprz_msg_send_CAMERA_SNAPSHOT_DL(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint16_t *_camera_id, uint16_t *_snapshot_image_number, uint8_t *_camera_state, uint8_t *_snapshot_valid, float *_array_temp, float *_lens_temp, uint8_t *_ac_id) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CAMERA_SNAPSHOT_DL(&msg,_camera_id,_snapshot_image_number,_camera_state,_snapshot_valid,_array_temp,_lens_temp,_ac_id);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CAMERA_SNAPSHOT_DL(_trans, _dev, camera_id, snapshot_image_number, camera_state, snapshot_valid, array_temp, lens_temp, ac_id) {}
static inline void pprz_send_msg_CAMERA_SNAPSHOT_DL(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint16_t *_camera_id __attribute__((unused)), uint16_t *_snapshot_image_number __attribute__((unused)), uint8_t *_camera_state __attribute__((unused)), uint8_t *_snapshot_valid __attribute__((unused)), float *_array_temp __attribute__((unused)), float *_lens_temp __attribute__((unused)), uint8_t *_ac_id __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field camera_id in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return Unique camera ID - consists of make,model and camera index
  */
static inline uint16_t pprzlink_get_DL_CAMERA_SNAPSHOT_DL_camera_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 4);
}


/** Getter for field snapshot_image_number in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return Snapshot number in sequence
  */
static inline uint16_t pprzlink_get_DL_CAMERA_SNAPSHOT_DL_snapshot_image_number(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 6);
}


/** Getter for field camera_state in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return State of the given camera
  */
static inline uint8_t pprzlink_get_DL_CAMERA_SNAPSHOT_DL_camera_state(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 8);
}


/** Getter for field snapshot_valid in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return Flag checking whether the last snapshot was valid
  */
static inline uint8_t pprzlink_get_DL_CAMERA_SNAPSHOT_DL_snapshot_valid(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 9);
}


/** Getter for field array_temp in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return Imager sensor temperature, NaN if not measured
  */
static inline float pprzlink_get_DL_CAMERA_SNAPSHOT_DL_array_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field lens_temp in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return Lens temperature, NaN if not measured
  */
static inline float pprzlink_get_DL_CAMERA_SNAPSHOT_DL_lens_temp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 14);
}


/** Getter for field ac_id in message CAMERA_SNAPSHOT_DL
  *
  * @param _payload : a pointer to the CAMERA_SNAPSHOT_DL message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_CAMERA_SNAPSHOT_DL_ac_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 18);
}


/* Compatibility macros */
#define DL_CAMERA_SNAPSHOT_DL_camera_id(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_camera_id(_payload)
#define DL_CAMERA_SNAPSHOT_DL_snapshot_image_number(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_snapshot_image_number(_payload)
#define DL_CAMERA_SNAPSHOT_DL_camera_state(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_camera_state(_payload)
#define DL_CAMERA_SNAPSHOT_DL_snapshot_valid(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_snapshot_valid(_payload)
#define DL_CAMERA_SNAPSHOT_DL_array_temp(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_array_temp(_payload)
#define DL_CAMERA_SNAPSHOT_DL_lens_temp(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_lens_temp(_payload)
#define DL_CAMERA_SNAPSHOT_DL_ac_id(_payload) pprzlink_get_DL_CAMERA_SNAPSHOT_DL_ac_id(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_datalink_CAMERA_SNAPSHOT_DL_H_

