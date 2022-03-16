/** @file
 *  @brief PPRZLink message header for JEVOIS in class telemetry
 *
 *  
        Debug message for the JeVois smart camera
        corresponding to the standardized messages
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_JEVOIS_H_
#define _VAR_MESSAGES_telemetry_JEVOIS_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_JEVOIS 80
#define PPRZ_MSG_ID_JEVOIS 80

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_JEVOIS _send_msg(JEVOIS,PPRZLINK_DEFAULT_VER)

/**
 * Sends a JEVOIS message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _type Standardized message type JEVOIS_MSG_[T1|N1|D1|T2|N2|D2|F2|T3|N3|D3|F3]
 * @param nb_id,_id Text string describing the reported object
 * @param _nb Number of elements in the coordinates array
 * @param nb_coord,_coord List of coordinates corresponding to 1D, 2D or 3D messages
 * @param _dim 1, 2 or 3D dimension
 * @param _quat Quaternion that relates the object's frame to the camera's frame, if appropriate
 */
static inline void pprzlink_msg_v2_send_JEVOIS(struct pprzlink_msg * msg, uint8_t *_type, uint8_t nb_id, char *_id, uint8_t *_nb, uint8_t nb_coord, int16_t *_coord, uint16_t *_dim, float *_quat) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+nb_id*1+1+1+nb_coord*2+3*2+4*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+nb_id*1+1+1+nb_coord*2+3*2+4*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_JEVOIS, "JEVOIS");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _type, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_id, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_CHAR, DL_FORMAT_ARRAY, (void *) _id, nb_id*1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _nb, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_coord, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_ARRAY, (void *) _coord, nb_coord*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_ARRAY, (void *) _dim, 3*2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _quat, 4*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_JEVOIS pprz_msg_send_JEVOIS
#define DOWNLINK_SEND_JEVOIS(_trans, _dev, type, nb_id, id, nb, nb_coord, coord, dim, quat) pprz_msg_send_JEVOIS(&((_trans).trans_tx), &((_dev).device), AC_ID, type, nb_id, id, nb, nb_coord, coord, dim, quat)
/**
 * Sends a JEVOIS message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _type Standardized message type JEVOIS_MSG_[T1|N1|D1|T2|N2|D2|F2|T3|N3|D3|F3]
 * @param nb_id,_id Text string describing the reported object
 * @param _nb Number of elements in the coordinates array
 * @param nb_coord,_coord List of coordinates corresponding to 1D, 2D or 3D messages
 * @param _dim 1, 2 or 3D dimension
 * @param _quat Quaternion that relates the object's frame to the camera's frame, if appropriate
 */
static inline void pprz_msg_send_JEVOIS(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_type, uint8_t nb_id, char *_id, uint8_t *_nb, uint8_t nb_coord, int16_t *_coord, uint16_t *_dim, float *_quat) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_JEVOIS(&msg,_type,nb_id,_id,_nb,nb_coord,_coord,_dim,_quat);
}


#else // DOWNLINK

#define DOWNLINK_SEND_JEVOIS(_trans, _dev, type, nb_id, id, nb, nb_coord, coord, dim, quat) {}
static inline void pprz_send_msg_JEVOIS(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_type __attribute__((unused)), uint8_t nb_id __attribute__((unused)), char *_id __attribute__((unused)), uint8_t *_nb __attribute__((unused)), uint8_t nb_coord __attribute__((unused)), int16_t *_coord __attribute__((unused)), uint16_t *_dim __attribute__((unused)), float *_quat __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field type in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return Standardized message type JEVOIS_MSG_[T1|N1|D1|T2|N2|D2|F2|T3|N3|D3|F3]
  */
static inline uint8_t pprzlink_get_DL_JEVOIS_type(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}

/** Getter for length of array id in message JEVOIS
 *
 * @return id : Text string describing the reported object
 */
 static inline uint8_t pprzlink_get_JEVOIS_id_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 5);
}

/** Getter for field id in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return Text string describing the reported object
  */
static inline char * pprzlink_get_DL_JEVOIS_id(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_char_array(_payload, 6);
}


/** Getter for field nb in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return Number of elements in the coordinates array
  */
static inline uint8_t pprzlink_get_DL_JEVOIS_nb(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 6);
}

/** Getter for length of array coord in message JEVOIS
 *
 * @return coord : List of coordinates corresponding to 1D, 2D or 3D messages
 */
 static inline uint8_t pprzlink_get_JEVOIS_coord_length(void* _payload) {
    return _PPRZ_VAL_uint8_t(_payload, 7);
}

/** Getter for field coord in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return List of coordinates corresponding to 1D, 2D or 3D messages
  */
static inline int16_t * pprzlink_get_DL_JEVOIS_coord(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t_array(_payload, 8);
}

/** Getter for length of array dim in message JEVOIS
 *
 * @return dim : 1, 2 or 3D dimension
 */
 static inline uint8_t pprzlink_get_JEVOIS_dim_length(void* _payload __attribute__ ((unused))) {
    return 3;
}

/** Getter for field dim in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return 1, 2 or 3D dimension
  */
static inline uint16_t * pprzlink_get_DL_JEVOIS_dim(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t_array(_payload, 8);
}

/** Getter for length of array quat in message JEVOIS
 *
 * @return quat : Quaternion that relates the object's frame to the camera's frame, if appropriate
 */
 static inline uint8_t pprzlink_get_JEVOIS_quat_length(void* _payload __attribute__ ((unused))) {
    return _PPRZ_VAL_fixed_len_aligned(4);
}

/** Getter for field quat in message JEVOIS
  *
  * @param _payload : a pointer to the JEVOIS message
  * @return Quaternion that relates the object's frame to the camera's frame, if appropriate
  */
static inline float * pprzlink_get_DL_JEVOIS_quat(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 14);
}


/* Compatibility macros */
#define DL_JEVOIS_type(_payload) pprzlink_get_DL_JEVOIS_type(_payload)
#define DL_JEVOIS_id_length(_payload) pprzlink_get_JEVOIS_id_length(_payload)
#define DL_JEVOIS_id(_payload) pprzlink_get_DL_JEVOIS_id(_payload)
#define DL_JEVOIS_nb(_payload) pprzlink_get_DL_JEVOIS_nb(_payload)
#define DL_JEVOIS_coord_length(_payload) pprzlink_get_JEVOIS_coord_length(_payload)
#define DL_JEVOIS_coord(_payload) pprzlink_get_DL_JEVOIS_coord(_payload)
#define DL_JEVOIS_dim_length(_payload) pprzlink_get_JEVOIS_dim_length(_payload)
#define DL_JEVOIS_dim(_payload) pprzlink_get_DL_JEVOIS_dim(_payload)
#define DL_JEVOIS_quat_length(_payload) pprzlink_get_JEVOIS_quat_length(_payload)
#define DL_JEVOIS_quat(_payload) pprzlink_get_DL_JEVOIS_quat(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_JEVOIS_H_

