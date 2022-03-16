/* This file has been generated from /home/npsd/paparazzi/conf/modules/ahrs_int_cmpl_quat.xml /home/npsd/paparazzi/conf/modules/video_rtp_stream.xml /home/npsd/paparazzi/conf/modules/video_capture.xml /home/npsd/paparazzi/conf/modules/stabilization_indi_simple.xml /home/npsd/paparazzi/conf/modules/orange_avoider_guided.xml /home/npsd/paparazzi/conf/modules/ins_extended.xml /home/npsd/paparazzi/conf/modules/guidance_rotorcraft.xml /home/npsd/paparazzi/conf/modules/cv_detect_color_object.xml /home/npsd/paparazzi/conf/modules/bebop_cam.xml /home/npsd/paparazzi/conf/modules/gps.xml /home/npsd/paparazzi/conf/modules/imu_common.xml /home/npsd/paparazzi/conf/modules/nav_basic_rotorcraft.xml /home/npsd/paparazzi/conf/settings/rotorcraft_basic.xml */
/* Version v6.1.0_stable-0-g3508db681 */
/* Please DO NOT EDIT */

#ifndef SETTINGS_H
#define SETTINGS_H


#include "generated/periodic_telemetry.h"
#include "autopilot.h"
#include "navigation.h"
#include "modules/imu/imu.h"
#include "modules/gps/gps.h"
#include "boards/bebop/mt9f002.h"
#include "guidance/guidance_h.h"
#include "guidance/guidance_v.h"
#include "modules/ins/vf_extended_float.h"
#include "stabilization/stabilization_indi_simple.h"
#include "computer_vision/video_capture.h"
#include "computer_vision/viewvideo.h"
#include "modules/ahrs/ahrs_int_cmpl_quat.h"
#include "generated/modules.h"

#define SETTINGS_NAMES { \
 { "telemetry_mode_Main" }, \
 { "video_thread_video_thread_periodic_status" }, \
 { "logger_file_file_logger_periodic_status" }, \
 { "gps_nps_gps_nps_periodic_check_status" }, \
 { "autopilot_mode_auto2" }, \
 { "autopilot.kill_throttle" }, \
 { "autopilot.power_switch" }, \
 { "autopilot.mode" }, \
 { "flight_altitude" }, \
 { "nav_heading" }, \
 { "nav_radius" }, \
 { "nav_climb_vspeed" }, \
 { "nav_descend_vspeed" }, \
 { "imu.body_to_imu.eulers_f.phi" }, \
 { "imu.body_to_imu.eulers_f.theta" }, \
 { "imu.body_to_imu.eulers_f.psi" }, \
 { "imu.b2i_set_current" }, \
 { "multi_gps_mode" }, \
 { "mt9f002.set_zoom" }, \
 { "mt9f002.set_offset_x" }, \
 { "mt9f002.set_offset_y" }, \
 { "mt9f002_send_resolution" }, \
 { "mt9f002.gain_green1" }, \
 { "mt9f002.gain_green2" }, \
 { "mt9f002.gain_blue" }, \
 { "mt9f002.gain_red" }, \
 { "mt9f002_send_color" }, \
 { "mt9f002.target_exposure " }, \
 { "mt9f002_send_exposure" }, \
 { "cod_lum_min1" }, \
 { "cod_lum_max1" }, \
 { "cod_cb_min1" }, \
 { "cod_cb_max1" }, \
 { "cod_cr_min1" }, \
 { "cod_cr_max1" }, \
 { "cod_draw1" }, \
 { "cod_lum_min2" }, \
 { "cod_lum_max2" }, \
 { "cod_cb_min2" }, \
 { "cod_cb_max2" }, \
 { "cod_cr_min2" }, \
 { "cod_cr_max2" }, \
 { "cod_draw2" }, \
 { "guidance_h.use_ref" }, \
 { "gh_ref.max_speed" }, \
 { "guidance_h.approx_force_by_thrust" }, \
 { "gh_ref.tau" }, \
 { "gh_ref.omega" }, \
 { "gh_ref.zeta" }, \
 { "guidance_h.gains.p" }, \
 { "guidance_h.gains.d" }, \
 { "guidance_h.gains.i" }, \
 { "guidance_h.gains.v" }, \
 { "guidance_h.gains.a" }, \
 { "guidance_h.sp.pos.x" }, \
 { "guidance_h.sp.pos.y" }, \
 { "guidance_v_kp" }, \
 { "guidance_v_kd" }, \
 { "guidance_v_ki" }, \
 { "guidance_v_nominal_throttle" }, \
 { "guidance_v_adapt_throttle_enabled" }, \
 { "guidance_v_z_sp" }, \
 { "vff.accel_noise" }, \
 { "vff.r_baro" }, \
 { "vff.r_alt" }, \
 { "vff.r_obs_height" }, \
 { "oag_color_count_frac" }, \
 { "oag_floor_count_frac" }, \
 { "oag_max_speed" }, \
 { "oag_heading_rate" }, \
 { "indi.gains.att.p" }, \
 { "indi.gains.rate.p" }, \
 { "indi.g1.p" }, \
 { "indi.gains.att.q" }, \
 { "indi.gains.rate.q" }, \
 { "indi.g1.q" }, \
 { "indi.gains.att.r" }, \
 { "indi.gains.rate.r" }, \
 { "indi.g1.r" }, \
 { "indi.g2" }, \
 { "indi.adaptive" }, \
 { "indi.max_rate" }, \
 { "indi.attitude_max_yaw_rate" }, \
 { "indi.cutoff_r" }, \
 { "video_capture_record_video" }, \
 { "video_capture_take_shot" }, \
 { "viewvideo.use_rtp" }, \
 { "ahrs_icq.gravity_heuristic_factor" }, \
 { "ahrs_icq.accel_omega" }, \
 { "ahrs_icq.accel_zeta" }, \
 { "ahrs_icq.mag_omega" }, \
 { "ahrs_icq.mag_zeta" }, \
};
#define SETTINGS_NAMES_SHORT { \
 "tel_mod_Mai" , \
 "vid_thr_vid_thr_" , \
 "log_fil_fil_log_" , \
 "gps_nps_gps_nps_" , \
 "aut_mod_aut" , \
 "aut_kil_thr" , \
 "aut_pow_swi" , \
 "aut_mod" , \
 "fli_alt" , \
 "nav_hea" , \
 "nav_rad" , \
 "nav_cli_vsp" , \
 "nav_des_vsp" , \
 "imu_bod_to_imu_e" , \
 "imu_bod_to_imu_e" , \
 "imu_bod_to_imu_e" , \
 "imu_b2i_set_cur" , \
 "mul_gps_mod" , \
 "mt9_set_zoo" , \
 "mt9_set_off_x" , \
 "mt9_set_off_y" , \
 "mt9_sen_res" , \
 "mt9_gai_gre" , \
 "mt9_gai_gre" , \
 "mt9_gai_blu" , \
 "mt9_gai_red" , \
 "mt9_sen_col" , \
 "mt9_tar_exp" , \
 "mt9_sen_exp" , \
 "cod_lum_min" , \
 "cod_lum_max" , \
 "cod_cb_min" , \
 "cod_cb_max" , \
 "cod_cr_min" , \
 "cod_cr_max" , \
 "cod_dra" , \
 "cod_lum_min" , \
 "cod_lum_max" , \
 "cod_cb_min" , \
 "cod_cb_max" , \
 "cod_cr_min" , \
 "cod_cr_max" , \
 "cod_dra" , \
 "gui_h_use_ref" , \
 "gh_ref_max_spe" , \
 "gui_h_app_for_by" , \
 "gh_ref_tau" , \
 "gh_ref_ome" , \
 "gh_ref_zet" , \
 "gui_h_gai_p" , \
 "gui_h_gai_d" , \
 "gui_h_gai_i" , \
 "gui_h_gai_v" , \
 "gui_h_gai_a" , \
 "gui_h_sp_pos_x" , \
 "gui_h_sp_pos_y" , \
 "gui_v_kp" , \
 "gui_v_kd" , \
 "gui_v_ki" , \
 "gui_v_nom_thr" , \
 "gui_v_ada_thr_en" , \
 "gui_v_z_sp" , \
 "vff_acc_noi" , \
 "vff_r_bar" , \
 "vff_r_alt" , \
 "vff_r_obs_hei" , \
 "oag_col_cou_fra" , \
 "oag_flo_cou_fra" , \
 "oag_max_spe" , \
 "oag_hea_rat" , \
 "ind_gai_att_p" , \
 "ind_gai_rat_p" , \
 "ind_g1_p" , \
 "ind_gai_att_q" , \
 "ind_gai_rat_q" , \
 "ind_g1_q" , \
 "ind_gai_att_r" , \
 "ind_gai_rat_r" , \
 "ind_g1_r" , \
 "ind_g2" , \
 "ind_ada" , \
 "ind_max_rat" , \
 "ind_att_max_yaw_" , \
 "ind_cut_r" , \
 "vid_cap_rec_vid" , \
 "vid_cap_tak_sho" , \
 "vie_use_rtp" , \
 "ahr_icq_gra_heu_" , \
 "ahr_icq_acc_ome" , \
 "ahr_icq_acc_zet" , \
 "ahr_icq_mag_ome" , \
 "ahr_icq_mag_zet" , \
};
#define NB_SETTING 92
#define DlSetting(_idx, _value) { \
  switch (_idx) { \
    case 0: telemetry_mode_Main = _value; break;\
    case 1: video_thread_video_thread_periodic_status = _value; break;\
    case 2: logger_file_file_logger_periodic_status = _value; break;\
    case 3: gps_nps_gps_nps_periodic_check_status = _value; break;\
    case 4: autopilot_mode_auto2 = _value; break;\
    case 5: autopilot_KillThrottle( _value ); _value = autopilot.kill_throttle; break;\
    case 6: autopilot_SetPowerSwitch( _value ); _value = autopilot.power_switch; break;\
    case 7: autopilot_SetModeHandler( _value ); _value = autopilot.mode; break;\
    case 8: navigation_SetFlightAltitude( _value ); _value = flight_altitude; break;\
    case 9: nav_heading = _value; break;\
    case 10: nav_radius = _value; break;\
    case 11: nav_climb_vspeed = _value; break;\
    case 12: nav_descend_vspeed = _value; break;\
    case 13: imu_SetBodyToImuPhi( _value ); _value = imu.body_to_imu.eulers_f.phi; break;\
    case 14: imu_SetBodyToImuTheta( _value ); _value = imu.body_to_imu.eulers_f.theta; break;\
    case 15: imu_SetBodyToImuPsi( _value ); _value = imu.body_to_imu.eulers_f.psi; break;\
    case 16: imu_SetBodyToImuCurrent( _value ); _value = imu.b2i_set_current; break;\
    case 17: multi_gps_mode = _value; break;\
    case 18: mt9f002.set_zoom = _value; break;\
    case 19: mt9f002.set_offset_x = _value; break;\
    case 20: mt9f002.set_offset_y = _value; break;\
    case 21: mt9f002_setting_update_resolution( _value ); _value = mt9f002_send_resolution; break;\
    case 22: mt9f002.gain_green1 = _value; break;\
    case 23: mt9f002.gain_green2 = _value; break;\
    case 24: mt9f002.gain_blue = _value; break;\
    case 25: mt9f002.gain_red = _value; break;\
    case 26: mt9f002_setting_update_color( _value ); _value = mt9f002_send_color; break;\
    case 27: mt9f002.target_exposure  = _value; break;\
    case 28: mt9f002_setting_update_exposure( _value ); _value = mt9f002_send_exposure; break;\
    case 29: cod_lum_min1 = _value; break;\
    case 30: cod_lum_max1 = _value; break;\
    case 31: cod_cb_min1 = _value; break;\
    case 32: cod_cb_max1 = _value; break;\
    case 33: cod_cr_min1 = _value; break;\
    case 34: cod_cr_max1 = _value; break;\
    case 35: cod_draw1 = _value; break;\
    case 36: cod_lum_min2 = _value; break;\
    case 37: cod_lum_max2 = _value; break;\
    case 38: cod_cb_min2 = _value; break;\
    case 39: cod_cb_max2 = _value; break;\
    case 40: cod_cr_min2 = _value; break;\
    case 41: cod_cr_max2 = _value; break;\
    case 42: cod_draw2 = _value; break;\
    case 43: guidance_h_SetUseRef( _value ); _value = guidance_h.use_ref; break;\
    case 44: guidance_h_SetMaxSpeed( _value ); _value = gh_ref.max_speed; break;\
    case 45: guidance_h.approx_force_by_thrust = _value; break;\
    case 46: guidance_h_SetTau( _value ); _value = gh_ref.tau; break;\
    case 47: guidance_h_SetOmega( _value ); _value = gh_ref.omega; break;\
    case 48: guidance_h_SetZeta( _value ); _value = gh_ref.zeta; break;\
    case 49: guidance_h.gains.p = _value; break;\
    case 50: guidance_h.gains.d = _value; break;\
    case 51: guidance_h_set_igain( _value ); _value = guidance_h.gains.i; break;\
    case 52: guidance_h.gains.v = _value; break;\
    case 53: guidance_h.gains.a = _value; break;\
    case 54: guidance_h.sp.pos.x = _value; break;\
    case 55: guidance_h.sp.pos.y = _value; break;\
    case 56: guidance_v_kp = _value; break;\
    case 57: guidance_v_kd = _value; break;\
    case 58: guidance_v_SetKi( _value ); _value = guidance_v_ki; break;\
    case 59: guidance_v_nominal_throttle = _value; break;\
    case 60: guidance_v_adapt_throttle_enabled = _value; break;\
    case 61: guidance_v_z_sp = _value; break;\
    case 62: vff.accel_noise = _value; break;\
    case 63: vff.r_baro = _value; break;\
    case 64: vff.r_alt = _value; break;\
    case 65: vff.r_obs_height = _value; break;\
    case 66: oag_color_count_frac = _value; break;\
    case 67: oag_floor_count_frac = _value; break;\
    case 68: oag_max_speed = _value; break;\
    case 69: oag_heading_rate = _value; break;\
    case 70: indi.gains.att.p = _value; break;\
    case 71: indi.gains.rate.p = _value; break;\
    case 72: indi.g1.p = _value; break;\
    case 73: indi.gains.att.q = _value; break;\
    case 74: indi.gains.rate.q = _value; break;\
    case 75: indi.g1.q = _value; break;\
    case 76: indi.gains.att.r = _value; break;\
    case 77: indi.gains.rate.r = _value; break;\
    case 78: indi.g1.r = _value; break;\
    case 79: indi.g2 = _value; break;\
    case 80: indi.adaptive = _value; break;\
    case 81: indi.max_rate = _value; break;\
    case 82: indi.attitude_max_yaw_rate = _value; break;\
    case 83: stabilization_indi_simple_reset_r_filter_cutoff( _value ); _value = indi.cutoff_r; break;\
    case 84: video_capture_record_video = _value; break;\
    case 85: video_capture_take_shot = _value; break;\
    case 86: viewvideo.use_rtp = _value; break;\
    case 87: ahrs_icq.gravity_heuristic_factor = _value; break;\
    case 88: ahrs_int_cmpl_quat_SetAccelOmega( _value ); _value = ahrs_icq.accel_omega; break;\
    case 89: ahrs_int_cmpl_quat_SetAccelZeta( _value ); _value = ahrs_icq.accel_zeta; break;\
    case 90: ahrs_int_cmpl_quat_SetMagOmega( _value ); _value = ahrs_icq.mag_omega; break;\
    case 91: ahrs_int_cmpl_quat_SetMagZeta( _value ); _value = ahrs_icq.mag_zeta; break;\
    default: break;\
  }\
}
#define PeriodicSendDlValue(_trans, _dev) { \
  static uint8_t i;\
  float var;\
  if (i >= 92) i = 0;\
  switch (i) { \
    case 0: var = telemetry_mode_Main; break;\
    case 1: var = video_thread_video_thread_periodic_status; break;\
    case 2: var = logger_file_file_logger_periodic_status; break;\
    case 3: var = gps_nps_gps_nps_periodic_check_status; break;\
    case 4: var = autopilot_mode_auto2; break;\
    case 5: var = autopilot.kill_throttle; break;\
    case 6: var = autopilot.power_switch; break;\
    case 7: var = autopilot.mode; break;\
    case 8: var = flight_altitude; break;\
    case 9: var = nav_heading; break;\
    case 10: var = nav_radius; break;\
    case 11: var = nav_climb_vspeed; break;\
    case 12: var = nav_descend_vspeed; break;\
    case 13: var = imu.body_to_imu.eulers_f.phi; break;\
    case 14: var = imu.body_to_imu.eulers_f.theta; break;\
    case 15: var = imu.body_to_imu.eulers_f.psi; break;\
    case 16: var = imu.b2i_set_current; break;\
    case 17: var = multi_gps_mode; break;\
    case 18: var = mt9f002.set_zoom; break;\
    case 19: var = mt9f002.set_offset_x; break;\
    case 20: var = mt9f002.set_offset_y; break;\
    case 21: var = mt9f002_send_resolution; break;\
    case 22: var = mt9f002.gain_green1; break;\
    case 23: var = mt9f002.gain_green2; break;\
    case 24: var = mt9f002.gain_blue; break;\
    case 25: var = mt9f002.gain_red; break;\
    case 26: var = mt9f002_send_color; break;\
    case 27: var = mt9f002.target_exposure ; break;\
    case 28: var = mt9f002_send_exposure; break;\
    case 29: var = cod_lum_min1; break;\
    case 30: var = cod_lum_max1; break;\
    case 31: var = cod_cb_min1; break;\
    case 32: var = cod_cb_max1; break;\
    case 33: var = cod_cr_min1; break;\
    case 34: var = cod_cr_max1; break;\
    case 35: var = cod_draw1; break;\
    case 36: var = cod_lum_min2; break;\
    case 37: var = cod_lum_max2; break;\
    case 38: var = cod_cb_min2; break;\
    case 39: var = cod_cb_max2; break;\
    case 40: var = cod_cr_min2; break;\
    case 41: var = cod_cr_max2; break;\
    case 42: var = cod_draw2; break;\
    case 43: var = guidance_h.use_ref; break;\
    case 44: var = gh_ref.max_speed; break;\
    case 45: var = guidance_h.approx_force_by_thrust; break;\
    case 46: var = gh_ref.tau; break;\
    case 47: var = gh_ref.omega; break;\
    case 48: var = gh_ref.zeta; break;\
    case 49: var = guidance_h.gains.p; break;\
    case 50: var = guidance_h.gains.d; break;\
    case 51: var = guidance_h.gains.i; break;\
    case 52: var = guidance_h.gains.v; break;\
    case 53: var = guidance_h.gains.a; break;\
    case 54: var = guidance_h.sp.pos.x; break;\
    case 55: var = guidance_h.sp.pos.y; break;\
    case 56: var = guidance_v_kp; break;\
    case 57: var = guidance_v_kd; break;\
    case 58: var = guidance_v_ki; break;\
    case 59: var = guidance_v_nominal_throttle; break;\
    case 60: var = guidance_v_adapt_throttle_enabled; break;\
    case 61: var = guidance_v_z_sp; break;\
    case 62: var = vff.accel_noise; break;\
    case 63: var = vff.r_baro; break;\
    case 64: var = vff.r_alt; break;\
    case 65: var = vff.r_obs_height; break;\
    case 66: var = oag_color_count_frac; break;\
    case 67: var = oag_floor_count_frac; break;\
    case 68: var = oag_max_speed; break;\
    case 69: var = oag_heading_rate; break;\
    case 70: var = indi.gains.att.p; break;\
    case 71: var = indi.gains.rate.p; break;\
    case 72: var = indi.g1.p; break;\
    case 73: var = indi.gains.att.q; break;\
    case 74: var = indi.gains.rate.q; break;\
    case 75: var = indi.g1.q; break;\
    case 76: var = indi.gains.att.r; break;\
    case 77: var = indi.gains.rate.r; break;\
    case 78: var = indi.g1.r; break;\
    case 79: var = indi.g2; break;\
    case 80: var = indi.adaptive; break;\
    case 81: var = indi.max_rate; break;\
    case 82: var = indi.attitude_max_yaw_rate; break;\
    case 83: var = indi.cutoff_r; break;\
    case 84: var = video_capture_record_video; break;\
    case 85: var = video_capture_take_shot; break;\
    case 86: var = viewvideo.use_rtp; break;\
    case 87: var = ahrs_icq.gravity_heuristic_factor; break;\
    case 88: var = ahrs_icq.accel_omega; break;\
    case 89: var = ahrs_icq.accel_zeta; break;\
    case 90: var = ahrs_icq.mag_omega; break;\
    case 91: var = ahrs_icq.mag_zeta; break;\
    default: var = 0.; break;\
  }\
  pprz_msg_send_DL_VALUE(_trans, _dev, AC_ID, &i, &var);\
  i++;\
}
static inline float settings_get_value(uint8_t i) {
  switch (i) {
    case 0: return telemetry_mode_Main;
    case 1: return video_thread_video_thread_periodic_status;
    case 2: return logger_file_file_logger_periodic_status;
    case 3: return gps_nps_gps_nps_periodic_check_status;
    case 4: return autopilot_mode_auto2;
    case 5: return autopilot.kill_throttle;
    case 6: return autopilot.power_switch;
    case 7: return autopilot.mode;
    case 8: return flight_altitude;
    case 9: return nav_heading;
    case 10: return nav_radius;
    case 11: return nav_climb_vspeed;
    case 12: return nav_descend_vspeed;
    case 13: return imu.body_to_imu.eulers_f.phi;
    case 14: return imu.body_to_imu.eulers_f.theta;
    case 15: return imu.body_to_imu.eulers_f.psi;
    case 16: return imu.b2i_set_current;
    case 17: return multi_gps_mode;
    case 18: return mt9f002.set_zoom;
    case 19: return mt9f002.set_offset_x;
    case 20: return mt9f002.set_offset_y;
    case 21: return mt9f002_send_resolution;
    case 22: return mt9f002.gain_green1;
    case 23: return mt9f002.gain_green2;
    case 24: return mt9f002.gain_blue;
    case 25: return mt9f002.gain_red;
    case 26: return mt9f002_send_color;
    case 27: return mt9f002.target_exposure ;
    case 28: return mt9f002_send_exposure;
    case 29: return cod_lum_min1;
    case 30: return cod_lum_max1;
    case 31: return cod_cb_min1;
    case 32: return cod_cb_max1;
    case 33: return cod_cr_min1;
    case 34: return cod_cr_max1;
    case 35: return cod_draw1;
    case 36: return cod_lum_min2;
    case 37: return cod_lum_max2;
    case 38: return cod_cb_min2;
    case 39: return cod_cb_max2;
    case 40: return cod_cr_min2;
    case 41: return cod_cr_max2;
    case 42: return cod_draw2;
    case 43: return guidance_h.use_ref;
    case 44: return gh_ref.max_speed;
    case 45: return guidance_h.approx_force_by_thrust;
    case 46: return gh_ref.tau;
    case 47: return gh_ref.omega;
    case 48: return gh_ref.zeta;
    case 49: return guidance_h.gains.p;
    case 50: return guidance_h.gains.d;
    case 51: return guidance_h.gains.i;
    case 52: return guidance_h.gains.v;
    case 53: return guidance_h.gains.a;
    case 54: return guidance_h.sp.pos.x;
    case 55: return guidance_h.sp.pos.y;
    case 56: return guidance_v_kp;
    case 57: return guidance_v_kd;
    case 58: return guidance_v_ki;
    case 59: return guidance_v_nominal_throttle;
    case 60: return guidance_v_adapt_throttle_enabled;
    case 61: return guidance_v_z_sp;
    case 62: return vff.accel_noise;
    case 63: return vff.r_baro;
    case 64: return vff.r_alt;
    case 65: return vff.r_obs_height;
    case 66: return oag_color_count_frac;
    case 67: return oag_floor_count_frac;
    case 68: return oag_max_speed;
    case 69: return oag_heading_rate;
    case 70: return indi.gains.att.p;
    case 71: return indi.gains.rate.p;
    case 72: return indi.g1.p;
    case 73: return indi.gains.att.q;
    case 74: return indi.gains.rate.q;
    case 75: return indi.g1.q;
    case 76: return indi.gains.att.r;
    case 77: return indi.gains.rate.r;
    case 78: return indi.g1.r;
    case 79: return indi.g2;
    case 80: return indi.adaptive;
    case 81: return indi.max_rate;
    case 82: return indi.attitude_max_yaw_rate;
    case 83: return indi.cutoff_r;
    case 84: return video_capture_record_video;
    case 85: return video_capture_take_shot;
    case 86: return viewvideo.use_rtp;
    case 87: return ahrs_icq.gravity_heuristic_factor;
    case 88: return ahrs_icq.accel_omega;
    case 89: return ahrs_icq.accel_zeta;
    case 90: return ahrs_icq.mag_omega;
    case 91: return ahrs_icq.mag_zeta;
    default: return 0.;
  }
}

/* Persistent Settings */
struct PersistentSettings {
  float s_0; /* imu.body_to_imu.eulers_f.phi */
  float s_1; /* imu.body_to_imu.eulers_f.theta */
  float s_2; /* imu.body_to_imu.eulers_f.psi */
  float s_3; /* guidance_h.use_ref */
  float s_4; /* gh_ref.max_speed */
  uint8_t s_5; /* guidance_h.approx_force_by_thrust */
  float s_6; /* gh_ref.tau */
  float s_7; /* gh_ref.omega */
  float s_8; /* gh_ref.zeta */
  int32_t s_9; /* guidance_h.gains.p */
  int32_t s_10; /* guidance_h.gains.d */
  int32_t s_11; /* guidance_h.gains.i */
  int32_t s_12; /* guidance_h.gains.v */
  int32_t s_13; /* guidance_h.gains.a */
  float s_14; /* guidance_v_kp */
  float s_15; /* guidance_v_kd */
  float s_16; /* guidance_v_ki */
  float s_17; /* guidance_v_nominal_throttle */
  float s_18; /* guidance_v_adapt_throttle_enabled */
  float s_19; /* indi.gains.att.p */
  float s_20; /* indi.gains.rate.p */
  float s_21; /* indi.g1.p */
  float s_22; /* indi.gains.att.q */
  float s_23; /* indi.gains.rate.q */
  float s_24; /* indi.g1.q */
  float s_25; /* indi.gains.att.r */
  float s_26; /* indi.gains.rate.r */
  float s_27; /* indi.g1.r */
  float s_28; /* indi.g2 */
  uint8_t s_29; /* indi.adaptive */
  uint8_t s_30; /* ahrs_icq.gravity_heuristic_factor */
  float s_31; /* ahrs_icq.accel_omega */
  float s_32; /* ahrs_icq.accel_zeta */
  float s_33; /* ahrs_icq.mag_omega */
  float s_34; /* ahrs_icq.mag_zeta */
};

extern struct PersistentSettings pers_settings;

static inline void persistent_settings_store( void ) {
  pers_settings.s_0 = imu.body_to_imu.eulers_f.phi;
  pers_settings.s_1 = imu.body_to_imu.eulers_f.theta;
  pers_settings.s_2 = imu.body_to_imu.eulers_f.psi;
  pers_settings.s_3 = guidance_h.use_ref;
  pers_settings.s_4 = gh_ref.max_speed;
  pers_settings.s_5 = guidance_h.approx_force_by_thrust;
  pers_settings.s_6 = gh_ref.tau;
  pers_settings.s_7 = gh_ref.omega;
  pers_settings.s_8 = gh_ref.zeta;
  pers_settings.s_9 = guidance_h.gains.p;
  pers_settings.s_10 = guidance_h.gains.d;
  pers_settings.s_11 = guidance_h.gains.i;
  pers_settings.s_12 = guidance_h.gains.v;
  pers_settings.s_13 = guidance_h.gains.a;
  pers_settings.s_14 = guidance_v_kp;
  pers_settings.s_15 = guidance_v_kd;
  pers_settings.s_16 = guidance_v_ki;
  pers_settings.s_17 = guidance_v_nominal_throttle;
  pers_settings.s_18 = guidance_v_adapt_throttle_enabled;
  pers_settings.s_19 = indi.gains.att.p;
  pers_settings.s_20 = indi.gains.rate.p;
  pers_settings.s_21 = indi.g1.p;
  pers_settings.s_22 = indi.gains.att.q;
  pers_settings.s_23 = indi.gains.rate.q;
  pers_settings.s_24 = indi.g1.q;
  pers_settings.s_25 = indi.gains.att.r;
  pers_settings.s_26 = indi.gains.rate.r;
  pers_settings.s_27 = indi.g1.r;
  pers_settings.s_28 = indi.g2;
  pers_settings.s_29 = indi.adaptive;
  pers_settings.s_30 = ahrs_icq.gravity_heuristic_factor;
  pers_settings.s_31 = ahrs_icq.accel_omega;
  pers_settings.s_32 = ahrs_icq.accel_zeta;
  pers_settings.s_33 = ahrs_icq.mag_omega;
  pers_settings.s_34 = ahrs_icq.mag_zeta;
}

static inline void persistent_settings_load( void ) {
  imu_SetBodyToImuPhi( pers_settings.s_0 );
  imu_SetBodyToImuTheta( pers_settings.s_1 );
  imu_SetBodyToImuPsi( pers_settings.s_2 );
  guidance_h_SetUseRef( pers_settings.s_3 );
  guidance_h_SetMaxSpeed( pers_settings.s_4 );
  guidance_h.approx_force_by_thrust = pers_settings.s_5;
  guidance_h_SetTau( pers_settings.s_6 );
  guidance_h_SetOmega( pers_settings.s_7 );
  guidance_h_SetZeta( pers_settings.s_8 );
  guidance_h.gains.p = pers_settings.s_9;
  guidance_h.gains.d = pers_settings.s_10;
  guidance_h_set_igain( pers_settings.s_11 );
  guidance_h.gains.v = pers_settings.s_12;
  guidance_h.gains.a = pers_settings.s_13;
  guidance_v_kp = pers_settings.s_14;
  guidance_v_kd = pers_settings.s_15;
  guidance_v_SetKi( pers_settings.s_16 );
  guidance_v_nominal_throttle = pers_settings.s_17;
  guidance_v_adapt_throttle_enabled = pers_settings.s_18;
  indi.gains.att.p = pers_settings.s_19;
  indi.gains.rate.p = pers_settings.s_20;
  indi.g1.p = pers_settings.s_21;
  indi.gains.att.q = pers_settings.s_22;
  indi.gains.rate.q = pers_settings.s_23;
  indi.g1.q = pers_settings.s_24;
  indi.gains.att.r = pers_settings.s_25;
  indi.gains.rate.r = pers_settings.s_26;
  indi.g1.r = pers_settings.s_27;
  indi.g2 = pers_settings.s_28;
  indi.adaptive = pers_settings.s_29;
  ahrs_icq.gravity_heuristic_factor = pers_settings.s_30;
  ahrs_int_cmpl_quat_SetAccelOmega( pers_settings.s_31 );
  ahrs_int_cmpl_quat_SetAccelZeta( pers_settings.s_32 );
  ahrs_int_cmpl_quat_SetMagOmega( pers_settings.s_33 );
  ahrs_int_cmpl_quat_SetMagZeta( pers_settings.s_34 );
}

#endif // SETTINGS_H
