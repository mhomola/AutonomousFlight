/** @file
 *  @brief PPRZLink message header for CHIRP in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_CHIRP_H_
#define _VAR_MESSAGES_telemetry_CHIRP_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_CHIRP 45
#define PPRZ_MSG_ID_CHIRP 45

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_CHIRP _send_msg(CHIRP,PPRZLINK_DEFAULT_VER)

/**
 * Sends a CHIRP message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _active Chirp is active
 * @param _percentage_done Percentage done
 * @param _current_frequency Current frequency
 * @param _axis Current chirp axis
 * @param _amplitude Amplitude
 * @param _fstart Start frequency
 * @param _fstop Stop frequency
 * @param _noise_onaxis_ratio Noise ratio onaxis
 * @param _noise_offaxis Noise offaxis
 * @param _current_value Current chirp value
 * @param _fade_in Fade in feature active
 * @param _exponential Exponential chirp active
 */
static inline void pprzlink_msg_v2_send_CHIRP(struct pprzlink_msg * msg, uint8_t *_active, float *_percentage_done, float *_current_frequency, uint8_t *_axis, int16_t *_amplitude, float *_fstart, float *_fstop, float *_noise_onaxis_ratio, float *_noise_offaxis, int16_t *_current_value, uint8_t *_fade_in, uint8_t *_exponential) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+4+4+1+2+4+4+4+4+2+1+1);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+4+4+1+2+4+4+4+4+2+1+1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_CHIRP, "CHIRP");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _active, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _percentage_done, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _current_frequency, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _axis, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _amplitude, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fstart, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _fstop, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _noise_onaxis_ratio, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _noise_offaxis, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT16, DL_FORMAT_SCALAR, (void *) _current_value, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _fade_in, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _exponential, 1);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_CHIRP pprz_msg_send_CHIRP
#define DOWNLINK_SEND_CHIRP(_trans, _dev, active, percentage_done, current_frequency, axis, amplitude, fstart, fstop, noise_onaxis_ratio, noise_offaxis, current_value, fade_in, exponential) pprz_msg_send_CHIRP(&((_trans).trans_tx), &((_dev).device), AC_ID, active, percentage_done, current_frequency, axis, amplitude, fstart, fstop, noise_onaxis_ratio, noise_offaxis, current_value, fade_in, exponential)
/**
 * Sends a CHIRP message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _active Chirp is active
 * @param _percentage_done Percentage done
 * @param _current_frequency Current frequency
 * @param _axis Current chirp axis
 * @param _amplitude Amplitude
 * @param _fstart Start frequency
 * @param _fstop Stop frequency
 * @param _noise_onaxis_ratio Noise ratio onaxis
 * @param _noise_offaxis Noise offaxis
 * @param _current_value Current chirp value
 * @param _fade_in Fade in feature active
 * @param _exponential Exponential chirp active
 */
static inline void pprz_msg_send_CHIRP(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_active, float *_percentage_done, float *_current_frequency, uint8_t *_axis, int16_t *_amplitude, float *_fstart, float *_fstop, float *_noise_onaxis_ratio, float *_noise_offaxis, int16_t *_current_value, uint8_t *_fade_in, uint8_t *_exponential) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_CHIRP(&msg,_active,_percentage_done,_current_frequency,_axis,_amplitude,_fstart,_fstop,_noise_onaxis_ratio,_noise_offaxis,_current_value,_fade_in,_exponential);
}


#else // DOWNLINK

#define DOWNLINK_SEND_CHIRP(_trans, _dev, active, percentage_done, current_frequency, axis, amplitude, fstart, fstop, noise_onaxis_ratio, noise_offaxis, current_value, fade_in, exponential) {}
static inline void pprz_send_msg_CHIRP(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_active __attribute__((unused)), float *_percentage_done __attribute__((unused)), float *_current_frequency __attribute__((unused)), uint8_t *_axis __attribute__((unused)), int16_t *_amplitude __attribute__((unused)), float *_fstart __attribute__((unused)), float *_fstop __attribute__((unused)), float *_noise_onaxis_ratio __attribute__((unused)), float *_noise_offaxis __attribute__((unused)), int16_t *_current_value __attribute__((unused)), uint8_t *_fade_in __attribute__((unused)), uint8_t *_exponential __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field active in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Chirp is active
  */
static inline uint8_t pprzlink_get_DL_CHIRP_active(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field percentage_done in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Percentage done
  */
static inline float pprzlink_get_DL_CHIRP_percentage_done(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 5);
}


/** Getter for field current_frequency in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Current frequency
  */
static inline float pprzlink_get_DL_CHIRP_current_frequency(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 9);
}


/** Getter for field axis in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Current chirp axis
  */
static inline uint8_t pprzlink_get_DL_CHIRP_axis(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 13);
}


/** Getter for field amplitude in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Amplitude
  */
static inline int16_t pprzlink_get_DL_CHIRP_amplitude(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 14);
}


/** Getter for field fstart in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Start frequency
  */
static inline float pprzlink_get_DL_CHIRP_fstart(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field fstop in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Stop frequency
  */
static inline float pprzlink_get_DL_CHIRP_fstop(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field noise_onaxis_ratio in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Noise ratio onaxis
  */
static inline float pprzlink_get_DL_CHIRP_noise_onaxis_ratio(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field noise_offaxis in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Noise offaxis
  */
static inline float pprzlink_get_DL_CHIRP_noise_offaxis(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field current_value in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Current chirp value
  */
static inline int16_t pprzlink_get_DL_CHIRP_current_value(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int16_t(_payload, 32);
}


/** Getter for field fade_in in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Fade in feature active
  */
static inline uint8_t pprzlink_get_DL_CHIRP_fade_in(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 34);
}


/** Getter for field exponential in message CHIRP
  *
  * @param _payload : a pointer to the CHIRP message
  * @return Exponential chirp active
  */
static inline uint8_t pprzlink_get_DL_CHIRP_exponential(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 35);
}


/* Compatibility macros */
#define DL_CHIRP_active(_payload) pprzlink_get_DL_CHIRP_active(_payload)
#define DL_CHIRP_percentage_done(_payload) pprzlink_get_DL_CHIRP_percentage_done(_payload)
#define DL_CHIRP_current_frequency(_payload) pprzlink_get_DL_CHIRP_current_frequency(_payload)
#define DL_CHIRP_axis(_payload) pprzlink_get_DL_CHIRP_axis(_payload)
#define DL_CHIRP_amplitude(_payload) pprzlink_get_DL_CHIRP_amplitude(_payload)
#define DL_CHIRP_fstart(_payload) pprzlink_get_DL_CHIRP_fstart(_payload)
#define DL_CHIRP_fstop(_payload) pprzlink_get_DL_CHIRP_fstop(_payload)
#define DL_CHIRP_noise_onaxis_ratio(_payload) pprzlink_get_DL_CHIRP_noise_onaxis_ratio(_payload)
#define DL_CHIRP_noise_offaxis(_payload) pprzlink_get_DL_CHIRP_noise_offaxis(_payload)
#define DL_CHIRP_current_value(_payload) pprzlink_get_DL_CHIRP_current_value(_payload)
#define DL_CHIRP_fade_in(_payload) pprzlink_get_DL_CHIRP_fade_in(_payload)
#define DL_CHIRP_exponential(_payload) pprzlink_get_DL_CHIRP_exponential(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_CHIRP_H_

