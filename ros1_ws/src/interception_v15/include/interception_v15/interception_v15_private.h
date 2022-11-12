//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interception_v15_private.h
//
// Code generated for Simulink model 'interception_v15'.
//
// Model version                  : 7.82
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sat Oct 29 09:18:54 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_interception_v15_private_h_
#define RTW_HEADER_interception_v15_private_h_
#include "rtwtypes.h"
#include "interception_v15.h"
#include "interception_v15_types.h"

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern int32_T div_nzp_s32(int32_T numerator, int32_T denominator);
extern void interception_v_CurrentTime_Init(DW_CurrentTime_interception_v_T
  *localDW);
extern void interception_v15_CurrentTime(B_CurrentTime_interception_v1_T *localB);
extern void interception_v_CurrentTime_Term(DW_CurrentTime_interception_v_T
  *localDW);

#endif                                // RTW_HEADER_interception_v15_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
