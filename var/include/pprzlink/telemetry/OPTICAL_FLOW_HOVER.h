/** @file
 *  @brief PPRZLink message header for OPTICAL_FLOW_HOVER in class telemetry
 *
 *  
        This messages includes the messages send by the Optical Flow Hover module, providing data for all three axes.
      
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_OPTICAL_FLOW_HOVER_H_
#define _VAR_MESSAGES_telemetry_OPTICAL_FLOW_HOVER_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_OPTICAL_FLOW_HOVER 243
#define PPRZ_MSG_ID_OPTICAL_FLOW_HOVER 243

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_OPTICAL_FLOW_HOVER _send_msg(OPTICAL_FLOW_HOVER,PPRZLINK_DEFAULT_VER)

/**
 * Sends a OPTICAL_FLOW_HOVER message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _flowX  Filtered Horizontal velocity in X / height used in Optical Flow Hover
 * @param _flowY  Filtered Horizontal velocity in X / height used in Optical Flow Hover
 * @param _Divergence  Filtered vertical velocity / height used in Optical Flow Hover
 * @param _cov_flowX  covariance of Ventral flow in X and past ventral flow in X
 * @param _cov_flowY  covariance of Ventral flow in Y and past ventral flow in Y
 * @param _cov_divZ  covariance of divergence and past divergence or thrust history
 * @param _pusedX  Gain used in the X feedback
 * @param _pusedY  Gain used in the Y feedback
 * @param _pusedZ  Gain used in the Z feedback
 * @param _sum_errX  Sum of errors in X
 * @param _sum_errY  Sum of errors in Y
 * @param _sum_errZ  Sum of errors in Z
 * @param _thrust  The thrust
 * @param _phi_des  The desired phi angle in degrees
 * @param _theta_des  The desired theta angle in degrees
 */
static inline void pprzlink_msg_v2_send_OPTICAL_FLOW_HOVER(struct pprzlink_msg * msg, float *_flowX, float *_flowY, float *_Divergence, float *_cov_flowX, float *_cov_flowY, float *_cov_divZ, float *_pusedX, float *_pusedY, float *_pusedZ, float *_sum_errX, float *_sum_errY, float *_sum_errZ, int32_t *_thrust, float *_phi_des, float *_theta_des) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_OPTICAL_FLOW_HOVER, "OPTICAL_FLOW_HOVER");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flowX, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _flowY, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _Divergence, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cov_flowX, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cov_flowY, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _cov_divZ, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pusedX, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pusedY, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _pusedZ, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sum_errX, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sum_errY, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _sum_errZ, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _thrust, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi_des, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta_des, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_OPTICAL_FLOW_HOVER pprz_msg_send_OPTICAL_FLOW_HOVER
#define DOWNLINK_SEND_OPTICAL_FLOW_HOVER(_trans, _dev, flowX, flowY, Divergence, cov_flowX, cov_flowY, cov_divZ, pusedX, pusedY, pusedZ, sum_errX, sum_errY, sum_errZ, thrust, phi_des, theta_des) pprz_msg_send_OPTICAL_FLOW_HOVER(&((_trans).trans_tx), &((_dev).device), AC_ID, flowX, flowY, Divergence, cov_flowX, cov_flowY, cov_divZ, pusedX, pusedY, pusedZ, sum_errX, sum_errY, sum_errZ, thrust, phi_des, theta_des)
/**
 * Sends a OPTICAL_FLOW_HOVER message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _flowX  Filtered Horizontal velocity in X / height used in Optical Flow Hover
 * @param _flowY  Filtered Horizontal velocity in X / height used in Optical Flow Hover
 * @param _Divergence  Filtered vertical velocity / height used in Optical Flow Hover
 * @param _cov_flowX  covariance of Ventral flow in X and past ventral flow in X
 * @param _cov_flowY  covariance of Ventral flow in Y and past ventral flow in Y
 * @param _cov_divZ  covariance of divergence and past divergence or thrust history
 * @param _pusedX  Gain used in the X feedback
 * @param _pusedY  Gain used in the Y feedback
 * @param _pusedZ  Gain used in the Z feedback
 * @param _sum_errX  Sum of errors in X
 * @param _sum_errY  Sum of errors in Y
 * @param _sum_errZ  Sum of errors in Z
 * @param _thrust  The thrust
 * @param _phi_des  The desired phi angle in degrees
 * @param _theta_des  The desired theta angle in degrees
 */
static inline void pprz_msg_send_OPTICAL_FLOW_HOVER(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_flowX, float *_flowY, float *_Divergence, float *_cov_flowX, float *_cov_flowY, float *_cov_divZ, float *_pusedX, float *_pusedY, float *_pusedZ, float *_sum_errX, float *_sum_errY, float *_sum_errZ, int32_t *_thrust, float *_phi_des, float *_theta_des) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_OPTICAL_FLOW_HOVER(&msg,_flowX,_flowY,_Divergence,_cov_flowX,_cov_flowY,_cov_divZ,_pusedX,_pusedY,_pusedZ,_sum_errX,_sum_errY,_sum_errZ,_thrust,_phi_des,_theta_des);
}


#else // DOWNLINK

#define DOWNLINK_SEND_OPTICAL_FLOW_HOVER(_trans, _dev, flowX, flowY, Divergence, cov_flowX, cov_flowY, cov_divZ, pusedX, pusedY, pusedZ, sum_errX, sum_errY, sum_errZ, thrust, phi_des, theta_des) {}
static inline void pprz_send_msg_OPTICAL_FLOW_HOVER(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_flowX __attribute__((unused)), float *_flowY __attribute__((unused)), float *_Divergence __attribute__((unused)), float *_cov_flowX __attribute__((unused)), float *_cov_flowY __attribute__((unused)), float *_cov_divZ __attribute__((unused)), float *_pusedX __attribute__((unused)), float *_pusedY __attribute__((unused)), float *_pusedZ __attribute__((unused)), float *_sum_errX __attribute__((unused)), float *_sum_errY __attribute__((unused)), float *_sum_errZ __attribute__((unused)), int32_t *_thrust __attribute__((unused)), float *_phi_des __attribute__((unused)), float *_theta_des __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field flowX in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Filtered Horizontal velocity in X / height used in Optical Flow Hover
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_flowX(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field flowY in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Filtered Horizontal velocity in X / height used in Optical Flow Hover
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_flowY(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field Divergence in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Filtered vertical velocity / height used in Optical Flow Hover
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_Divergence(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field cov_flowX in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  covariance of Ventral flow in X and past ventral flow in X
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_flowX(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field cov_flowY in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  covariance of Ventral flow in Y and past ventral flow in Y
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_flowY(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field cov_divZ in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  covariance of divergence and past divergence or thrust history
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_divZ(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field pusedX in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Gain used in the X feedback
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedX(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field pusedY in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Gain used in the Y feedback
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedY(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field pusedZ in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Gain used in the Z feedback
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedZ(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field sum_errX in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Sum of errors in X
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errX(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field sum_errY in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Sum of errors in Y
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errY(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field sum_errZ in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  Sum of errors in Z
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errZ(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field thrust in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  The thrust
  */
static inline int32_t pprzlink_get_DL_OPTICAL_FLOW_HOVER_thrust(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 52);
}


/** Getter for field phi_des in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  The desired phi angle in degrees
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_phi_des(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field theta_des in message OPTICAL_FLOW_HOVER
  *
  * @param _payload : a pointer to the OPTICAL_FLOW_HOVER message
  * @return  The desired theta angle in degrees
  */
static inline float pprzlink_get_DL_OPTICAL_FLOW_HOVER_theta_des(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/* Compatibility macros */
#define DL_OPTICAL_FLOW_HOVER_flowX(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_flowX(_payload)
#define DL_OPTICAL_FLOW_HOVER_flowY(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_flowY(_payload)
#define DL_OPTICAL_FLOW_HOVER_Divergence(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_Divergence(_payload)
#define DL_OPTICAL_FLOW_HOVER_cov_flowX(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_flowX(_payload)
#define DL_OPTICAL_FLOW_HOVER_cov_flowY(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_flowY(_payload)
#define DL_OPTICAL_FLOW_HOVER_cov_divZ(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_cov_divZ(_payload)
#define DL_OPTICAL_FLOW_HOVER_pusedX(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedX(_payload)
#define DL_OPTICAL_FLOW_HOVER_pusedY(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedY(_payload)
#define DL_OPTICAL_FLOW_HOVER_pusedZ(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_pusedZ(_payload)
#define DL_OPTICAL_FLOW_HOVER_sum_errX(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errX(_payload)
#define DL_OPTICAL_FLOW_HOVER_sum_errY(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errY(_payload)
#define DL_OPTICAL_FLOW_HOVER_sum_errZ(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_sum_errZ(_payload)
#define DL_OPTICAL_FLOW_HOVER_thrust(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_thrust(_payload)
#define DL_OPTICAL_FLOW_HOVER_phi_des(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_phi_des(_payload)
#define DL_OPTICAL_FLOW_HOVER_theta_des(_payload) pprzlink_get_DL_OPTICAL_FLOW_HOVER_theta_des(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_OPTICAL_FLOW_HOVER_H_

