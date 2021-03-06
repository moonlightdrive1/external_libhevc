/******************************************************************************
*
* Copyright (C) 2012 Ittiam Systems Pvt Ltd, Bangalore
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at:
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************/
/**
*******************************************************************************
* @file
*  ihevcd_function_selector_ssse3.c
*
* @brief
*  Contains functions to initialize function pointers used in hevc
*
* @author
*  Naveen
*
* @par List of Functions:
* @remarks
*  None
*
*******************************************************************************
*/
/*****************************************************************************/
/* File Includes                                                             */
/*****************************************************************************/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "ihevc_typedefs.h"
#include "iv.h"
#include "ivd.h"
#include "ihevc_defs.h"
#include "ihevc_debug.h"
#include "ihevc_structs.h"
#include "ihevc_macros.h"
#include "ihevc_platform_macros.h"
#include "ihevc_cabac_tables.h"
#include "ihevc_disp_mgr.h"
#include "ihevc_buf_mgr.h"
#include "ihevc_dpb_mgr.h"
#include "ihevc_error.h"

#include "ihevcd_defs.h"
#include "ihevcd_function_selector.h"
#include "ihevcd_structs.h"

void ihevcd_init_function_ptr_ssse3(void *pv_codec)
{
    codec_t *ps_codec = (codec_t *)pv_codec;

    ps_codec->s_func_selector.ihevc_deblk_chroma_horz_fptr                      =  &ihevc_deblk_chroma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_deblk_chroma_vert_fptr                      =  &ihevc_deblk_chroma_vert_ssse3;
    ps_codec->s_func_selector.ihevc_deblk_luma_vert_fptr                        =  &ihevc_deblk_luma_vert_ssse3;
    ps_codec->s_func_selector.ihevc_deblk_luma_horz_fptr                        =  &ihevc_deblk_luma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_copy_fptr                 =  &ihevc_inter_pred_chroma_copy_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_copy_w16out_fptr          =  &ihevc_inter_pred_chroma_copy_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_horz_fptr                 =  &ihevc_inter_pred_chroma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_horz_w16out_fptr          =  &ihevc_inter_pred_chroma_horz_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_vert_fptr                 =  &ihevc_inter_pred_chroma_vert_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_vert_w16inp_fptr          =  &ihevc_inter_pred_chroma_vert_w16inp_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_vert_w16inp_w16out_fptr   =  &ihevc_inter_pred_chroma_vert_w16inp_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_chroma_vert_w16out_fptr          =  &ihevc_inter_pred_chroma_vert_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_horz_fptr                   =  &ihevc_inter_pred_luma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_vert_fptr                   =  &ihevc_inter_pred_luma_vert_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_vert_w16out_fptr            =  &ihevc_inter_pred_luma_vert_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_vert_w16inp_fptr            =  &ihevc_inter_pred_luma_vert_w16inp_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_copy_fptr                   =  &ihevc_inter_pred_luma_copy_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_copy_w16out_fptr            =  &ihevc_inter_pred_luma_copy_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_horz_w16out_fptr            =  &ihevc_inter_pred_luma_horz_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_inter_pred_luma_vert_w16inp_w16out_fptr     =  &ihevc_inter_pred_luma_vert_w16inp_w16out_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_ref_substitution_fptr     =  &ihevc_intra_pred_chroma_ref_substitution;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_ref_substitution_fptr       =  &ihevc_intra_pred_luma_ref_substitution;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_ref_subst_all_avlble_fptr   =  &ihevc_intra_pred_luma_ref_subst_all_avlble;
    ps_codec->s_func_selector.ihevc_intra_pred_ref_filtering_fptr               =  &ihevc_intra_pred_ref_filtering_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_dc_fptr                   =  &ihevc_intra_pred_chroma_dc_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_horz_fptr                 =  &ihevc_intra_pred_chroma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode2_fptr                =  &ihevc_intra_pred_chroma_mode2_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode_18_34_fptr           =  &ihevc_intra_pred_chroma_mode_18_34_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode_27_to_33_fptr        =  &ihevc_intra_pred_chroma_mode_27_to_33_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode_3_to_9_fptr          =  &ihevc_intra_pred_chroma_mode_3_to_9_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_planar_fptr               =  &ihevc_intra_pred_chroma_planar_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_ver_fptr                  =  &ihevc_intra_pred_chroma_ver_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode_11_to_17_fptr        =  &ihevc_intra_pred_chroma_mode_11_to_17_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_chroma_mode_19_to_25_fptr        =  &ihevc_intra_pred_chroma_mode_19_to_25_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode_11_to_17_fptr          =  &ihevc_intra_pred_luma_mode_11_to_17_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode_19_to_25_fptr          =  &ihevc_intra_pred_luma_mode_19_to_25_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_dc_fptr                     =  &ihevc_intra_pred_luma_dc_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_horz_fptr                   =  &ihevc_intra_pred_luma_horz_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode2_fptr                  =  &ihevc_intra_pred_luma_mode2_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode_18_34_fptr             =  &ihevc_intra_pred_luma_mode_18_34_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode_27_to_33_fptr          =  &ihevc_intra_pred_luma_mode_27_to_33_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_mode_3_to_9_fptr            =  &ihevc_intra_pred_luma_mode_3_to_9_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_planar_fptr                 =  &ihevc_intra_pred_luma_planar_ssse3;
    ps_codec->s_func_selector.ihevc_intra_pred_luma_ver_fptr                    =  &ihevc_intra_pred_luma_ver_ssse3;
    ps_codec->s_func_selector.ihevc_itrans_4x4_ttype1_fptr                      =  &ihevc_itrans_4x4_ttype1;
    ps_codec->s_func_selector.ihevc_itrans_4x4_fptr                             =  &ihevc_itrans_4x4;
    ps_codec->s_func_selector.ihevc_itrans_8x8_fptr                             =  &ihevc_itrans_8x8;
    ps_codec->s_func_selector.ihevc_itrans_16x16_fptr                           =  &ihevc_itrans_16x16;
    ps_codec->s_func_selector.ihevc_itrans_32x32_fptr                           =  &ihevc_itrans_32x32;
    ps_codec->s_func_selector.ihevc_itrans_recon_4x4_ttype1_fptr                =  &ihevc_itrans_recon_4x4_ttype1_ssse3;
    ps_codec->s_func_selector.ihevc_itrans_recon_4x4_fptr                       =  &ihevc_itrans_recon_4x4_ssse3;
    ps_codec->s_func_selector.ihevc_itrans_recon_8x8_fptr                       =  &ihevc_itrans_recon_8x8_ssse3;
    ps_codec->s_func_selector.ihevc_itrans_recon_16x16_fptr                     =  &ihevc_itrans_recon_16x16_ssse3;
    ps_codec->s_func_selector.ihevc_itrans_recon_32x32_fptr                     =  &ihevc_itrans_recon_32x32_ssse3;
    ps_codec->s_func_selector.ihevc_chroma_itrans_recon_4x4_fptr                =  &ihevc_chroma_itrans_recon_4x4;
    ps_codec->s_func_selector.ihevc_chroma_itrans_recon_8x8_fptr                =  &ihevc_chroma_itrans_recon_8x8;
    ps_codec->s_func_selector.ihevc_chroma_itrans_recon_16x16_fptr              =  &ihevc_chroma_itrans_recon_16x16;
    ps_codec->s_func_selector.ihevc_recon_4x4_ttype1_fptr                       =  &ihevc_recon_4x4_ttype1;
    ps_codec->s_func_selector.ihevc_recon_4x4_fptr                              =  &ihevc_recon_4x4;
    ps_codec->s_func_selector.ihevc_recon_8x8_fptr                              =  &ihevc_recon_8x8;
    ps_codec->s_func_selector.ihevc_recon_16x16_fptr                            =  &ihevc_recon_16x16;
    ps_codec->s_func_selector.ihevc_recon_32x32_fptr                            =  &ihevc_recon_32x32;
    ps_codec->s_func_selector.ihevc_chroma_recon_4x4_fptr                       =  &ihevc_chroma_recon_4x4;
    ps_codec->s_func_selector.ihevc_chroma_recon_8x8_fptr                       =  &ihevc_chroma_recon_8x8;
    ps_codec->s_func_selector.ihevc_chroma_recon_16x16_fptr                     =  &ihevc_chroma_recon_16x16;
    ps_codec->s_func_selector.ihevc_memcpy_mul_8_fptr                           =  &ihevc_memcpy_mul_8;
    ps_codec->s_func_selector.ihevc_memcpy_fptr                                 =  &ihevc_memcpy;
    ps_codec->s_func_selector.ihevc_memset_mul_8_fptr                           =  &ihevc_memset_mul_8;
    ps_codec->s_func_selector.ihevc_memset_fptr                                 =  &ihevc_memset;
    ps_codec->s_func_selector.ihevc_memset_16bit_mul_8_fptr                     =  &ihevc_memset_16bit_mul_8;
    ps_codec->s_func_selector.ihevc_memset_16bit_fptr                           =  &ihevc_memset_16bit;
    ps_codec->s_func_selector.ihevc_pad_left_luma_fptr                          =  &ihevc_pad_left_luma;
    ps_codec->s_func_selector.ihevc_pad_left_chroma_fptr                        =  &ihevc_pad_left_chroma;
    ps_codec->s_func_selector.ihevc_pad_right_luma_fptr                         =  &ihevc_pad_right_luma;
    ps_codec->s_func_selector.ihevc_pad_right_chroma_fptr                       =  &ihevc_pad_right_chroma;
    ps_codec->s_func_selector.ihevc_weighted_pred_bi_fptr                       =  &ihevc_weighted_pred_bi_ssse3;
    ps_codec->s_func_selector.ihevc_weighted_pred_bi_default_fptr               =  &ihevc_weighted_pred_bi_default_ssse3;
    ps_codec->s_func_selector.ihevc_weighted_pred_uni_fptr                      =  &ihevc_weighted_pred_uni_ssse3;
    ps_codec->s_func_selector.ihevc_weighted_pred_chroma_bi_fptr                =  &ihevc_weighted_pred_chroma_bi_ssse3;
    ps_codec->s_func_selector.ihevc_weighted_pred_chroma_bi_default_fptr        =  &ihevc_weighted_pred_chroma_bi_default_ssse3;
    ps_codec->s_func_selector.ihevc_weighted_pred_chroma_uni_fptr               =  &ihevc_weighted_pred_chroma_uni_ssse3;
    ps_codec->s_func_selector.ihevc_sao_band_offset_luma_fptr                   =  &ihevc_sao_band_offset_luma_ssse3;
    ps_codec->s_func_selector.ihevc_sao_band_offset_chroma_fptr                 =  &ihevc_sao_band_offset_chroma_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class0_fptr                 =  &ihevc_sao_edge_offset_class0_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class0_chroma_fptr          =  &ihevc_sao_edge_offset_class0_chroma_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class1_fptr                 =  &ihevc_sao_edge_offset_class1_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class1_chroma_fptr          =  &ihevc_sao_edge_offset_class1_chroma_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class2_fptr                 =  &ihevc_sao_edge_offset_class2_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class2_chroma_fptr          =  &ihevc_sao_edge_offset_class2_chroma_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class3_fptr                 =  &ihevc_sao_edge_offset_class3_ssse3;
    ps_codec->s_func_selector.ihevc_sao_edge_offset_class3_chroma_fptr          =  &ihevc_sao_edge_offset_class3_chroma_ssse3;
    ps_codec->s_func_selector.ihevcd_fmt_conv_420sp_to_rgba8888_fptr            =  &ihevcd_fmt_conv_420sp_to_rgba8888;
    ps_codec->s_func_selector.ihevcd_fmt_conv_420sp_to_rgb565_fptr              =  &ihevcd_fmt_conv_420sp_to_rgb565;
    ps_codec->s_func_selector.ihevcd_fmt_conv_420sp_to_420sp_fptr               =  &ihevcd_fmt_conv_420sp_to_420sp;
    ps_codec->s_func_selector.ihevcd_fmt_conv_420sp_to_420p_fptr                =  &ihevcd_fmt_conv_420sp_to_420p;
    ps_codec->s_func_selector.ihevcd_itrans_recon_dc_luma_fptr                  =  &ihevcd_itrans_recon_dc_luma_ssse3;
    ps_codec->s_func_selector.ihevcd_itrans_recon_dc_chroma_fptr                =  &ihevcd_itrans_recon_dc_chroma_ssse3;
}
