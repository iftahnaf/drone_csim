//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interception_v15.cpp
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
#include "interception_v15.h"
#include "rtwtypes.h"
#include "interception_v15_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <float.h>

// Named constants for Chart: '<Root>/logic'
const uint8_T interception_v15_IN_Emergency = 1U;
const uint8_T interception_v15_IN_Init = 2U;
const uint8_T interception_v15_IN_Return = 4U;
const uint8_T interception_v1_IN_Intercepting = 3U;

// Block signals (default storage)
B_interception_v15_T interception_v15_B;

// Block states (default storage)
DW_interception_v15_T interception_v15_DW;

// Real-time model
RT_MODEL_interception_v15_T interception_v15_M_ = RT_MODEL_interception_v15_T();
RT_MODEL_interception_v15_T *const interception_v15_M = &interception_v15_M_;

// Forward declaration for local functions
static real_T interception_v15_norm(const real_T x[3]);
static real_T interception_v15_rt_hypotd_snf(real_T u0, real_T u1);
static void interception_v15_sqrt(creal_T *x);
static void interception_v15_xzlartg_h(const creal_T f, const creal_T g, real_T *
  cs, creal_T *sn);
static void interception_v15_xzlartg(const creal_T f, const creal_T g, real_T
  *cs, creal_T *sn, creal_T *r);
static void interception_v15_xzhgeqz_a(const creal_T A_data[], const int32_T
  A_size[2], int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[],
  int32_T *alpha1_size, creal_T beta1_data[], int32_T *beta1_size);
static void interception_v15_xzgeev_f(const real_T A_data[], const int32_T
  A_size[2], int32_T *info, creal_T alpha1_data[], int32_T *alpha1_size, creal_T
  beta1_data[], int32_T *beta1_size);
static boolean_T interception_v15_cplxpairv(creal_T x_data[], const int32_T
  *x_size, real_T tol);
static void interception_v15_xzhgeqz(creal_T A[16], int32_T ilo, int32_T ihi,
  creal_T Z[16], int32_T *info, creal_T alpha1[4], creal_T beta1[4]);
static void interception_v15_xztgevc(const creal_T A[16], creal_T V[16]);
static void interception_v15_xzgeev(const real_T A[16], int32_T *info, creal_T
  alpha1[4], creal_T beta1[4], creal_T V[16]);
static real_T interception_v15_xnrm2(int32_T n, const real_T x[16], int32_T ix0);
static void interception_v15_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, real_T C[16], int32_T ic0, real_T work[4]);
static real_T interception_v15_xnrm2_l(int32_T n, const real_T x[3]);
static real_T interception_v15_xzlarfg(int32_T n, real_T *alpha1, real_T x[3]);
static void interception_v15_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d,
  real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
static int32_T interception_v15_xhseqr(real_T h[16], real_T z[16]);
static void interception_v15_schur(const real_T A[16], real_T V[16], real_T T[16]);
static void rate_scheduler(void);
int32_T div_nzp_s32(int32_T numerator, int32_T denominator)
{
  uint32_T tempAbsQuotient;
  tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                     static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
    static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>(denominator));
  return (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
    (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
}

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (interception_v15_M->Timing.TaskCounters.TID[1])++;
  if ((interception_v15_M->Timing.TaskCounters.TID[1]) > 2) {// Sample time: [0.1s, 0.0s] 
    interception_v15_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// System initialize for atomic system:
void interception_v_CurrentTime_Init(DW_CurrentTime_interception_v_T *localDW)
{
  // Start for MATLABSystem: '<S19>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void interception_v15_CurrentTime(B_CurrentTime_interception_v1_T *localB)
{
  // MATLABSystem: '<S19>/Current Time'
  currentROSTimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void interception_v_CurrentTime_Term(DW_CurrentTime_interception_v_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Current Time'
}

// Function for MATLAB Function: '<S6>/Controller'
static real_T interception_v15_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static real_T interception_v15_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  interception_v15_B.a = fabs(u0);
  interception_v15_B.b = fabs(u1);
  if (interception_v15_B.a < interception_v15_B.b) {
    interception_v15_B.a /= interception_v15_B.b;
    y = sqrt(interception_v15_B.a * interception_v15_B.a + 1.0) *
      interception_v15_B.b;
  } else if (interception_v15_B.a > interception_v15_B.b) {
    interception_v15_B.b /= interception_v15_B.a;
    y = sqrt(interception_v15_B.b * interception_v15_B.b + 1.0) *
      interception_v15_B.a;
  } else if (rtIsNaN(interception_v15_B.b)) {
    y = (rtNaN);
  } else {
    y = interception_v15_B.a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_sqrt(creal_T *x)
{
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      interception_v15_B.absxr = 0.0;
      interception_v15_B.absxi = sqrt(-x->re);
    } else {
      interception_v15_B.absxr = sqrt(x->re);
      interception_v15_B.absxi = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      interception_v15_B.absxr = sqrt(-x->im / 2.0);
      interception_v15_B.absxi = -interception_v15_B.absxr;
    } else {
      interception_v15_B.absxr = sqrt(x->im / 2.0);
      interception_v15_B.absxi = interception_v15_B.absxr;
    }
  } else if (rtIsNaN(x->re)) {
    interception_v15_B.absxr = (rtNaN);
    interception_v15_B.absxi = (rtNaN);
  } else if (rtIsNaN(x->im)) {
    interception_v15_B.absxr = (rtNaN);
    interception_v15_B.absxi = (rtNaN);
  } else if (rtIsInf(x->im)) {
    interception_v15_B.absxr = fabs(x->im);
    interception_v15_B.absxi = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      interception_v15_B.absxr = 0.0;
      interception_v15_B.absxi = x->im * -x->re;
    } else {
      interception_v15_B.absxr = x->re;
      interception_v15_B.absxi = 0.0;
    }
  } else {
    interception_v15_B.absxr = fabs(x->re);
    interception_v15_B.absxi = fabs(x->im);
    if ((interception_v15_B.absxr > 4.4942328371557893E+307) ||
        (interception_v15_B.absxi > 4.4942328371557893E+307)) {
      interception_v15_B.absxr *= 0.5;
      interception_v15_B.absxi = interception_v15_rt_hypotd_snf
        (interception_v15_B.absxr, interception_v15_B.absxi * 0.5);
      if (interception_v15_B.absxi > interception_v15_B.absxr) {
        interception_v15_B.absxr = sqrt(interception_v15_B.absxr /
          interception_v15_B.absxi + 1.0) * sqrt(interception_v15_B.absxi);
      } else {
        interception_v15_B.absxr = sqrt(interception_v15_B.absxi) *
          1.4142135623730951;
      }
    } else {
      interception_v15_B.absxr = sqrt((interception_v15_rt_hypotd_snf
        (interception_v15_B.absxr, interception_v15_B.absxi) +
        interception_v15_B.absxr) * 0.5);
    }

    if (x->re > 0.0) {
      interception_v15_B.absxi = x->im / interception_v15_B.absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        interception_v15_B.absxi = -interception_v15_B.absxr;
      } else {
        interception_v15_B.absxi = interception_v15_B.absxr;
      }

      interception_v15_B.absxr = x->im / interception_v15_B.absxi * 0.5;
    }
  }

  x->re = interception_v15_B.absxr;
  x->im = interception_v15_B.absxi;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xzlartg_h(const creal_T f, const creal_T g, real_T *
  cs, creal_T *sn)
{
  int32_T count;
  boolean_T guard1 = false;
  interception_v15_B.d = fabs(f.re);
  interception_v15_B.scale_n = interception_v15_B.d;
  interception_v15_B.f2s_o = fabs(f.im);
  if (interception_v15_B.f2s_o > interception_v15_B.d) {
    interception_v15_B.scale_n = interception_v15_B.f2s_o;
  }

  interception_v15_B.gs_re_m = fabs(g.re);
  interception_v15_B.gs_im_j = fabs(g.im);
  if (interception_v15_B.gs_im_j > interception_v15_B.gs_re_m) {
    interception_v15_B.gs_re_m = interception_v15_B.gs_im_j;
  }

  if (interception_v15_B.gs_re_m > interception_v15_B.scale_n) {
    interception_v15_B.scale_n = interception_v15_B.gs_re_m;
  }

  interception_v15_B.fs_re_c = f.re;
  interception_v15_B.fs_im_m = f.im;
  interception_v15_B.gs_re_m = g.re;
  interception_v15_B.gs_im_j = g.im;
  count = 0;
  guard1 = false;
  if (interception_v15_B.scale_n >= 7.4428285367870146E+137) {
    do {
      count++;
      interception_v15_B.fs_re_c *= 1.3435752215134178E-138;
      interception_v15_B.fs_im_m *= 1.3435752215134178E-138;
      interception_v15_B.gs_re_m *= 1.3435752215134178E-138;
      interception_v15_B.gs_im_j *= 1.3435752215134178E-138;
      interception_v15_B.scale_n *= 1.3435752215134178E-138;
    } while ((interception_v15_B.scale_n >= 7.4428285367870146E+137) && (count <
              20));

    guard1 = true;
  } else if (interception_v15_B.scale_n <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        interception_v15_B.fs_re_c *= 7.4428285367870146E+137;
        interception_v15_B.fs_im_m *= 7.4428285367870146E+137;
        interception_v15_B.gs_re_m *= 7.4428285367870146E+137;
        interception_v15_B.gs_im_j *= 7.4428285367870146E+137;
        interception_v15_B.scale_n *= 7.4428285367870146E+137;
      } while (interception_v15_B.scale_n <= 1.3435752215134178E-138);

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    interception_v15_B.scale_n = interception_v15_B.fs_re_c *
      interception_v15_B.fs_re_c + interception_v15_B.fs_im_m *
      interception_v15_B.fs_im_m;
    interception_v15_B.g2_i = interception_v15_B.gs_re_m *
      interception_v15_B.gs_re_m + interception_v15_B.gs_im_j *
      interception_v15_B.gs_im_j;
    interception_v15_B.x_m = interception_v15_B.g2_i;
    if (interception_v15_B.g2_i < 1.0) {
      interception_v15_B.x_m = 1.0;
    }

    if (interception_v15_B.scale_n <= interception_v15_B.x_m *
        2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        interception_v15_B.d = interception_v15_rt_hypotd_snf
          (interception_v15_B.gs_re_m, interception_v15_B.gs_im_j);
        sn->re = interception_v15_B.gs_re_m / interception_v15_B.d;
        sn->im = -interception_v15_B.gs_im_j / interception_v15_B.d;
      } else {
        interception_v15_B.scale_n = sqrt(interception_v15_B.g2_i);
        *cs = interception_v15_rt_hypotd_snf(interception_v15_B.fs_re_c,
          interception_v15_B.fs_im_m) / interception_v15_B.scale_n;
        if (interception_v15_B.f2s_o > interception_v15_B.d) {
          interception_v15_B.d = interception_v15_B.f2s_o;
        }

        if (interception_v15_B.d > 1.0) {
          interception_v15_B.d = interception_v15_rt_hypotd_snf(f.re, f.im);
          interception_v15_B.fs_re_c = f.re / interception_v15_B.d;
          interception_v15_B.fs_im_m = f.im / interception_v15_B.d;
        } else {
          interception_v15_B.fs_re_c = 7.4428285367870146E+137 * f.re;
          interception_v15_B.f2s_o = 7.4428285367870146E+137 * f.im;
          interception_v15_B.d = interception_v15_rt_hypotd_snf
            (interception_v15_B.fs_re_c, interception_v15_B.f2s_o);
          interception_v15_B.fs_re_c /= interception_v15_B.d;
          interception_v15_B.fs_im_m = interception_v15_B.f2s_o /
            interception_v15_B.d;
        }

        interception_v15_B.gs_re_m /= interception_v15_B.scale_n;
        interception_v15_B.gs_im_j = -interception_v15_B.gs_im_j /
          interception_v15_B.scale_n;
        sn->re = interception_v15_B.fs_re_c * interception_v15_B.gs_re_m -
          interception_v15_B.fs_im_m * interception_v15_B.gs_im_j;
        sn->im = interception_v15_B.fs_re_c * interception_v15_B.gs_im_j +
          interception_v15_B.fs_im_m * interception_v15_B.gs_re_m;
      }
    } else {
      interception_v15_B.f2s_o = sqrt(interception_v15_B.g2_i /
        interception_v15_B.scale_n + 1.0);
      *cs = 1.0 / interception_v15_B.f2s_o;
      interception_v15_B.d = interception_v15_B.scale_n +
        interception_v15_B.g2_i;
      interception_v15_B.fs_re_c = interception_v15_B.f2s_o *
        interception_v15_B.fs_re_c / interception_v15_B.d;
      interception_v15_B.fs_im_m = interception_v15_B.f2s_o *
        interception_v15_B.fs_im_m / interception_v15_B.d;
      sn->re = interception_v15_B.fs_re_c * interception_v15_B.gs_re_m -
        interception_v15_B.fs_im_m * -interception_v15_B.gs_im_j;
      sn->im = interception_v15_B.fs_re_c * -interception_v15_B.gs_im_j +
        interception_v15_B.fs_im_m * interception_v15_B.gs_re_m;
    }
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xzlartg(const creal_T f, const creal_T g, real_T
  *cs, creal_T *sn, creal_T *r)
{
  int32_T count;
  int8_T rescaledir;
  boolean_T guard1 = false;
  interception_v15_B.f2s = fabs(f.re);
  interception_v15_B.scale_l = interception_v15_B.f2s;
  interception_v15_B.di = fabs(f.im);
  if (interception_v15_B.di > interception_v15_B.f2s) {
    interception_v15_B.scale_l = interception_v15_B.di;
  }

  interception_v15_B.gs_re = fabs(g.re);
  interception_v15_B.gs_im = fabs(g.im);
  if (interception_v15_B.gs_im > interception_v15_B.gs_re) {
    interception_v15_B.gs_re = interception_v15_B.gs_im;
  }

  if (interception_v15_B.gs_re > interception_v15_B.scale_l) {
    interception_v15_B.scale_l = interception_v15_B.gs_re;
  }

  interception_v15_B.fs_re = f.re;
  interception_v15_B.fs_im = f.im;
  interception_v15_B.gs_re = g.re;
  interception_v15_B.gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (interception_v15_B.scale_l >= 7.4428285367870146E+137) {
    do {
      count++;
      interception_v15_B.fs_re *= 1.3435752215134178E-138;
      interception_v15_B.fs_im *= 1.3435752215134178E-138;
      interception_v15_B.gs_re *= 1.3435752215134178E-138;
      interception_v15_B.gs_im *= 1.3435752215134178E-138;
      interception_v15_B.scale_l *= 1.3435752215134178E-138;
    } while ((interception_v15_B.scale_l >= 7.4428285367870146E+137) && (count +
              1 < 20));

    rescaledir = 1;
    guard1 = true;
  } else if (interception_v15_B.scale_l <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        interception_v15_B.fs_re *= 7.4428285367870146E+137;
        interception_v15_B.fs_im *= 7.4428285367870146E+137;
        interception_v15_B.gs_re *= 7.4428285367870146E+137;
        interception_v15_B.gs_im *= 7.4428285367870146E+137;
        interception_v15_B.scale_l *= 7.4428285367870146E+137;
      } while (interception_v15_B.scale_l <= 1.3435752215134178E-138);

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    interception_v15_B.scale_l = interception_v15_B.fs_re *
      interception_v15_B.fs_re + interception_v15_B.fs_im *
      interception_v15_B.fs_im;
    interception_v15_B.g2 = interception_v15_B.gs_re * interception_v15_B.gs_re
      + interception_v15_B.gs_im * interception_v15_B.gs_im;
    interception_v15_B.x = interception_v15_B.g2;
    if (interception_v15_B.g2 < 1.0) {
      interception_v15_B.x = 1.0;
    }

    if (interception_v15_B.scale_l <= interception_v15_B.x *
        2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = interception_v15_rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        interception_v15_B.f2s = interception_v15_rt_hypotd_snf
          (interception_v15_B.gs_re, interception_v15_B.gs_im);
        sn->re = interception_v15_B.gs_re / interception_v15_B.f2s;
        sn->im = -interception_v15_B.gs_im / interception_v15_B.f2s;
      } else {
        interception_v15_B.scale_l = sqrt(interception_v15_B.g2);
        *cs = interception_v15_rt_hypotd_snf(interception_v15_B.fs_re,
          interception_v15_B.fs_im) / interception_v15_B.scale_l;
        if (interception_v15_B.di > interception_v15_B.f2s) {
          interception_v15_B.f2s = interception_v15_B.di;
        }

        if (interception_v15_B.f2s > 1.0) {
          interception_v15_B.f2s = interception_v15_rt_hypotd_snf(f.re, f.im);
          interception_v15_B.fs_re = f.re / interception_v15_B.f2s;
          interception_v15_B.fs_im = f.im / interception_v15_B.f2s;
        } else {
          interception_v15_B.fs_re = 7.4428285367870146E+137 * f.re;
          interception_v15_B.di = 7.4428285367870146E+137 * f.im;
          interception_v15_B.f2s = interception_v15_rt_hypotd_snf
            (interception_v15_B.fs_re, interception_v15_B.di);
          interception_v15_B.fs_re /= interception_v15_B.f2s;
          interception_v15_B.fs_im = interception_v15_B.di /
            interception_v15_B.f2s;
        }

        interception_v15_B.gs_re /= interception_v15_B.scale_l;
        interception_v15_B.gs_im = -interception_v15_B.gs_im /
          interception_v15_B.scale_l;
        sn->re = interception_v15_B.fs_re * interception_v15_B.gs_re -
          interception_v15_B.fs_im * interception_v15_B.gs_im;
        sn->im = interception_v15_B.fs_re * interception_v15_B.gs_im +
          interception_v15_B.fs_im * interception_v15_B.gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      interception_v15_B.f2s = sqrt(interception_v15_B.g2 /
        interception_v15_B.scale_l + 1.0);
      r->re = interception_v15_B.f2s * interception_v15_B.fs_re;
      r->im = interception_v15_B.f2s * interception_v15_B.fs_im;
      *cs = 1.0 / interception_v15_B.f2s;
      interception_v15_B.f2s = interception_v15_B.scale_l +
        interception_v15_B.g2;
      interception_v15_B.fs_re = r->re / interception_v15_B.f2s;
      interception_v15_B.f2s = r->im / interception_v15_B.f2s;
      sn->re = interception_v15_B.fs_re * interception_v15_B.gs_re -
        interception_v15_B.f2s * -interception_v15_B.gs_im;
      sn->im = interception_v15_B.fs_re * -interception_v15_B.gs_im +
        interception_v15_B.f2s * interception_v15_B.gs_re;
      if (rescaledir > 0) {
        for (int32_T b_i = 0; b_i <= count; b_i++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (int32_T b_i = 0; b_i <= count; b_i++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/Numeric Calculation of Tgo'
static void interception_v15_xzhgeqz_a(const creal_T A_data[], const int32_T
  A_size[2], int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[],
  int32_T *alpha1_size, creal_T beta1_data[], int32_T *beta1_size)
{
  int32_T b_A_size_idx_0;
  int32_T col;
  int32_T iiter;
  int32_T ilast;
  int32_T ilastm1;
  int32_T nm1;
  boolean_T failed;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  b_A_size_idx_0 = A_size[0];
  nm1 = A_size[0] * A_size[1];
  if (nm1 - 1 >= 0) {
    memcpy(&interception_v15_B.b_A_data[0], &A_data[0], static_cast<uint32_T>
           (nm1) * sizeof(creal_T));
  }

  *info = 0;
  if ((A_size[0] == 1) && (A_size[1] == 1)) {
    ihi = 1;
  }

  interception_v15_B.n = A_size[0];
  *alpha1_size = A_size[0];
  nm1 = A_size[0];
  if (nm1 - 1 >= 0) {
    memset(&alpha1_data[0], 0, static_cast<uint32_T>(nm1) * sizeof(creal_T));
  }

  *beta1_size = A_size[0];
  nm1 = A_size[0];
  for (ilast = 0; ilast < nm1; ilast++) {
    beta1_data[ilast].re = 1.0;
    beta1_data[ilast].im = 0.0;
  }

  interception_v15_B.eshift_re = 0.0;
  interception_v15_B.eshift_im = 0.0;
  interception_v15_B.ctemp.re = 0.0;
  interception_v15_B.ctemp.im = 0.0;
  interception_v15_B.anorm = 0.0;
  if (ilo <= ihi) {
    interception_v15_B.scale = 3.3121686421112381E-170;
    interception_v15_B.ssq = 0.0;
    nm1 = ihi - ilo;
    for (ilastm1 = 0; ilastm1 <= nm1; ilastm1++) {
      interception_v15_B.colscale = 3.3121686421112381E-170;
      interception_v15_B.anorm = 0.0;
      col = (ilo + ilastm1) - 1;
      if (ilastm1 + 1 <= nm1) {
        ilast = ilastm1 + 1;
      } else {
        ilast = nm1;
      }

      ilast += ilo;
      for (iiter = ilo; iiter <= ilast; iiter++) {
        interception_v15_B.absxk_l = fabs(A_data[(A_size[0] * col + iiter) - 1].
          re);
        if (interception_v15_B.absxk_l > interception_v15_B.colscale) {
          interception_v15_B.t_d = interception_v15_B.colscale /
            interception_v15_B.absxk_l;
          interception_v15_B.anorm = interception_v15_B.anorm *
            interception_v15_B.t_d * interception_v15_B.t_d + 1.0;
          interception_v15_B.colscale = interception_v15_B.absxk_l;
        } else {
          interception_v15_B.t_d = interception_v15_B.absxk_l /
            interception_v15_B.colscale;
          interception_v15_B.anorm += interception_v15_B.t_d *
            interception_v15_B.t_d;
        }

        interception_v15_B.absxk_l = fabs(A_data[(A_size[0] * col + iiter) - 1].
          im);
        if (interception_v15_B.absxk_l > interception_v15_B.colscale) {
          interception_v15_B.t_d = interception_v15_B.colscale /
            interception_v15_B.absxk_l;
          interception_v15_B.anorm = interception_v15_B.anorm *
            interception_v15_B.t_d * interception_v15_B.t_d + 1.0;
          interception_v15_B.colscale = interception_v15_B.absxk_l;
        } else {
          interception_v15_B.t_d = interception_v15_B.absxk_l /
            interception_v15_B.colscale;
          interception_v15_B.anorm += interception_v15_B.t_d *
            interception_v15_B.t_d;
        }
      }

      if (interception_v15_B.scale >= interception_v15_B.colscale) {
        interception_v15_B.colscale /= interception_v15_B.scale;
        interception_v15_B.ssq += interception_v15_B.colscale *
          interception_v15_B.colscale * interception_v15_B.anorm;
      } else {
        interception_v15_B.scale /= interception_v15_B.colscale;
        interception_v15_B.ssq = interception_v15_B.scale *
          interception_v15_B.scale * interception_v15_B.ssq +
          interception_v15_B.anorm;
        interception_v15_B.scale = interception_v15_B.colscale;
      }
    }

    interception_v15_B.anorm = interception_v15_B.scale * sqrt
      (interception_v15_B.ssq);
  }

  interception_v15_B.ssq = 2.2250738585072014E-308;
  interception_v15_B.scale = 2.2204460492503131E-16 * interception_v15_B.anorm;
  if (interception_v15_B.scale > 2.2250738585072014E-308) {
    interception_v15_B.ssq = interception_v15_B.scale;
  }

  interception_v15_B.scale = 2.2250738585072014E-308;
  if (interception_v15_B.anorm > 2.2250738585072014E-308) {
    interception_v15_B.scale = interception_v15_B.anorm;
  }

  interception_v15_B.anorm = 1.0 / interception_v15_B.scale;
  interception_v15_B.scale = 1.0 / sqrt(static_cast<real_T>(A_size[0]));
  failed = true;
  for (ilast = ihi + 1; ilast <= interception_v15_B.n; ilast++) {
    alpha1_data[ilast - 1] = A_data[((ilast - 1) * A_size[0] + ilast) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    int32_T jiter;
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    interception_v15_B.n = ilo;
    nm1 = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    col = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (jiter <= ((ihi - ilo) + 1) * 30 - 1) {
        int32_T colscale_tmp;
        int32_T colscale_tmp_tmp;
        int32_T jp1;
        boolean_T exitg2;
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else {
          jp1 = b_A_size_idx_0 * ilast + ilast;
          colscale_tmp_tmp = b_A_size_idx_0 * ilastm1;
          colscale_tmp = ilastm1 + colscale_tmp_tmp;
          interception_v15_B.colscale = ((fabs(interception_v15_B.b_A_data[jp1].
            re) + fabs(interception_v15_B.b_A_data[jp1].im)) + (fabs
            (interception_v15_B.b_A_data[colscale_tmp].re) + fabs
            (interception_v15_B.b_A_data[colscale_tmp].im))) *
            2.2204460492503131E-16;
          if ((interception_v15_B.colscale <= 2.2250738585072014E-308) ||
              rtIsNaN(interception_v15_B.colscale)) {
            interception_v15_B.colscale = 2.2250738585072014E-308;
          }

          colscale_tmp_tmp += ilast;
          if (fabs(interception_v15_B.b_A_data[colscale_tmp_tmp].re) + fabs
              (interception_v15_B.b_A_data[colscale_tmp_tmp].im) <=
              interception_v15_B.colscale) {
            interception_v15_B.b_A_data[colscale_tmp_tmp].re = 0.0;
            interception_v15_B.b_A_data[colscale_tmp_tmp].im = 0.0;
            goto60 = true;
          } else {
            boolean_T guard3 = false;
            interception_v15_B.j_f = ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (interception_v15_B.j_f + 1 >= ilo)) {
              if (interception_v15_B.j_f + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                colscale_tmp_tmp = (interception_v15_B.j_f - 1) * b_A_size_idx_0;
                jp1 = (interception_v15_B.j_f + colscale_tmp_tmp) - 1;
                colscale_tmp = b_A_size_idx_0 * interception_v15_B.j_f +
                  interception_v15_B.j_f;
                interception_v15_B.colscale = ((fabs
                  (interception_v15_B.b_A_data[jp1].re) + fabs
                  (interception_v15_B.b_A_data[jp1].im)) + (fabs
                  (interception_v15_B.b_A_data[colscale_tmp].re) + fabs
                  (interception_v15_B.b_A_data[colscale_tmp].im))) *
                  2.2204460492503131E-16;
                if ((interception_v15_B.colscale <= 2.2250738585072014E-308) ||
                    rtIsNaN(interception_v15_B.colscale)) {
                  interception_v15_B.colscale = 2.2250738585072014E-308;
                }

                colscale_tmp_tmp += interception_v15_B.j_f;
                if (fabs(interception_v15_B.b_A_data[colscale_tmp_tmp].re) +
                    fabs(interception_v15_B.b_A_data[colscale_tmp_tmp].im) <=
                    interception_v15_B.colscale) {
                  interception_v15_B.b_A_data[colscale_tmp_tmp].re = 0.0;
                  interception_v15_B.b_A_data[colscale_tmp_tmp].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  interception_v15_B.j_f--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              interception_v15_B.n = interception_v15_B.j_f + 1;
              goto70 = true;
            }
          }
        }

        if ((!goto60) && (!goto70)) {
          interception_v15_B.n = *alpha1_size;
          for (ilast = 0; ilast < interception_v15_B.n; ilast++) {
            alpha1_data[ilast].re = (rtNaN);
            alpha1_data[ilast].im = 0.0;
          }

          interception_v15_B.n = *beta1_size;
          for (ilast = 0; ilast < interception_v15_B.n; ilast++) {
            beta1_data[ilast].re = (rtNaN);
            beta1_data[ilast].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else if (goto60) {
          goto60 = false;
          alpha1_data[ilast] = interception_v15_B.b_A_data[b_A_size_idx_0 *
            ilast + ilast];
          ilast = ilastm1;
          ilastm1--;
          if (ilast + 1 < ilo) {
            failed = false;
            guard2 = true;
            exitg1 = 1;
          } else {
            iiter = 0;
            interception_v15_B.eshift_re = 0.0;
            interception_v15_B.eshift_im = 0.0;
            col = ilast + 1;
            jiter++;
          }
        } else {
          if (goto70) {
            goto70 = false;
            iiter++;
            if (iiter - div_nzp_s32(iiter, 10) * 10 != 0) {
              colscale_tmp = b_A_size_idx_0 * ilast + ilast;
              interception_v15_B.x_re = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].re;
              interception_v15_B.t_d = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].im;
              if (interception_v15_B.t_d == 0.0) {
                interception_v15_B.colscale = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.absxk_l = 0.0;
              } else if (interception_v15_B.x_re == 0.0) {
                interception_v15_B.colscale = 0.0;
                interception_v15_B.absxk_l = interception_v15_B.t_d /
                  interception_v15_B.scale;
              } else {
                interception_v15_B.colscale = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.absxk_l = interception_v15_B.t_d /
                  interception_v15_B.scale;
              }

              colscale_tmp = b_A_size_idx_0 * ilast + ilastm1;
              interception_v15_B.x_re = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].re;
              interception_v15_B.t_d = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].im;
              if (interception_v15_B.t_d == 0.0) {
                interception_v15_B.stemp.re = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.stemp.im = 0.0;
              } else if (interception_v15_B.x_re == 0.0) {
                interception_v15_B.stemp.re = 0.0;
                interception_v15_B.stemp.im = interception_v15_B.t_d /
                  interception_v15_B.scale;
              } else {
                interception_v15_B.stemp.re = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.stemp.im = interception_v15_B.t_d /
                  interception_v15_B.scale;
              }

              interception_v15_sqrt(&interception_v15_B.stemp);
              colscale_tmp = b_A_size_idx_0 * ilastm1 + ilast;
              interception_v15_B.x_re = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].re;
              interception_v15_B.t_d = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].im;
              if (interception_v15_B.t_d == 0.0) {
                interception_v15_B.y.re = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.y.im = 0.0;
              } else if (interception_v15_B.x_re == 0.0) {
                interception_v15_B.y.re = 0.0;
                interception_v15_B.y.im = interception_v15_B.t_d /
                  interception_v15_B.scale;
              } else {
                interception_v15_B.y.re = interception_v15_B.x_re /
                  interception_v15_B.scale;
                interception_v15_B.y.im = interception_v15_B.t_d /
                  interception_v15_B.scale;
              }

              interception_v15_sqrt(&interception_v15_B.y);
              interception_v15_B.ctemp.re = interception_v15_B.stemp.re *
                interception_v15_B.y.re - interception_v15_B.stemp.im *
                interception_v15_B.y.im;
              interception_v15_B.ctemp.im = interception_v15_B.stemp.re *
                interception_v15_B.y.im + interception_v15_B.stemp.im *
                interception_v15_B.y.re;
              if ((interception_v15_B.ctemp.re != 0.0) ||
                  (interception_v15_B.ctemp.im != 0.0)) {
                colscale_tmp = b_A_size_idx_0 * ilastm1 + ilastm1;
                interception_v15_B.x_re = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].re;
                interception_v15_B.t_d = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].im;
                if (interception_v15_B.t_d == 0.0) {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d = 0.0;
                } else if (interception_v15_B.x_re == 0.0) {
                  interception_v15_B.x_re = 0.0;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                } else {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                }

                interception_v15_B.x_re = (interception_v15_B.x_re -
                  interception_v15_B.colscale) * 0.5;
                interception_v15_B.x_im = (interception_v15_B.t_d -
                  interception_v15_B.absxk_l) * 0.5;
                interception_v15_B.temp2 = fabs(interception_v15_B.x_re) + fabs
                  (interception_v15_B.x_im);
                interception_v15_B.temp = fabs(interception_v15_B.ctemp.re) +
                  fabs(interception_v15_B.ctemp.im);
                if ((!(interception_v15_B.temp >= interception_v15_B.temp2)) &&
                    (!rtIsNaN(interception_v15_B.temp2))) {
                  interception_v15_B.temp = interception_v15_B.temp2;
                }

                if (interception_v15_B.x_im == 0.0) {
                  interception_v15_B.stemp.re = interception_v15_B.x_re /
                    interception_v15_B.temp;
                  interception_v15_B.stemp.im = 0.0;
                } else if (interception_v15_B.x_re == 0.0) {
                  interception_v15_B.stemp.re = 0.0;
                  interception_v15_B.stemp.im = interception_v15_B.x_im /
                    interception_v15_B.temp;
                } else {
                  interception_v15_B.stemp.re = interception_v15_B.x_re /
                    interception_v15_B.temp;
                  interception_v15_B.stemp.im = interception_v15_B.x_im /
                    interception_v15_B.temp;
                }

                if (interception_v15_B.ctemp.im == 0.0) {
                  interception_v15_B.y.re = interception_v15_B.ctemp.re /
                    interception_v15_B.temp;
                  interception_v15_B.y.im = 0.0;
                } else if (interception_v15_B.ctemp.re == 0.0) {
                  interception_v15_B.y.re = 0.0;
                  interception_v15_B.y.im = interception_v15_B.ctemp.im /
                    interception_v15_B.temp;
                } else {
                  interception_v15_B.y.re = interception_v15_B.ctemp.re /
                    interception_v15_B.temp;
                  interception_v15_B.y.im = interception_v15_B.ctemp.im /
                    interception_v15_B.temp;
                }

                interception_v15_B.stemp_im_tmp_d = interception_v15_B.stemp.re *
                  interception_v15_B.stemp.im;
                interception_v15_B.stemp.re = (interception_v15_B.stemp.re *
                  interception_v15_B.stemp.re - interception_v15_B.stemp.im *
                  interception_v15_B.stemp.im) + (interception_v15_B.y.re *
                  interception_v15_B.y.re - interception_v15_B.y.im *
                  interception_v15_B.y.im);
                interception_v15_B.t_d = interception_v15_B.y.re *
                  interception_v15_B.y.im;
                interception_v15_B.stemp.im = (interception_v15_B.t_d +
                  interception_v15_B.t_d) + (interception_v15_B.stemp_im_tmp_d +
                  interception_v15_B.stemp_im_tmp_d);
                interception_v15_sqrt(&interception_v15_B.stemp);
                interception_v15_B.y.re = interception_v15_B.temp *
                  interception_v15_B.stemp.re;
                interception_v15_B.y.im = interception_v15_B.temp *
                  interception_v15_B.stemp.im;
                if (interception_v15_B.temp2 > 0.0) {
                  if (interception_v15_B.x_im == 0.0) {
                    interception_v15_B.t_d = interception_v15_B.x_re /
                      interception_v15_B.temp2;
                    interception_v15_B.temp2 = 0.0;
                  } else {
                    if (interception_v15_B.x_re == 0.0) {
                      interception_v15_B.t_d = 0.0;
                    } else {
                      interception_v15_B.t_d = interception_v15_B.x_re /
                        interception_v15_B.temp2;
                    }

                    interception_v15_B.temp2 = interception_v15_B.x_im /
                      interception_v15_B.temp2;
                  }

                  if (interception_v15_B.t_d * interception_v15_B.y.re +
                      interception_v15_B.temp2 * interception_v15_B.y.im < 0.0)
                  {
                    interception_v15_B.y.re = -interception_v15_B.y.re;
                    interception_v15_B.y.im = -interception_v15_B.y.im;
                  }
                }

                interception_v15_B.x_re += interception_v15_B.y.re;
                interception_v15_B.x_im += interception_v15_B.y.im;
                if (interception_v15_B.x_im == 0.0) {
                  if (interception_v15_B.ctemp.im == 0.0) {
                    interception_v15_B.t_d = interception_v15_B.ctemp.re /
                      interception_v15_B.x_re;
                    interception_v15_B.x_re = 0.0;
                  } else if (interception_v15_B.ctemp.re == 0.0) {
                    interception_v15_B.t_d = 0.0;
                    interception_v15_B.x_re = interception_v15_B.ctemp.im /
                      interception_v15_B.x_re;
                  } else {
                    interception_v15_B.t_d = interception_v15_B.ctemp.re /
                      interception_v15_B.x_re;
                    interception_v15_B.x_re = interception_v15_B.ctemp.im /
                      interception_v15_B.x_re;
                  }
                } else if (interception_v15_B.x_re == 0.0) {
                  if (interception_v15_B.ctemp.re == 0.0) {
                    interception_v15_B.t_d = interception_v15_B.ctemp.im /
                      interception_v15_B.x_im;
                    interception_v15_B.x_re = 0.0;
                  } else if (interception_v15_B.ctemp.im == 0.0) {
                    interception_v15_B.t_d = 0.0;
                    interception_v15_B.x_re = -(interception_v15_B.ctemp.re /
                      interception_v15_B.x_im);
                  } else {
                    interception_v15_B.t_d = interception_v15_B.ctemp.im /
                      interception_v15_B.x_im;
                    interception_v15_B.x_re = -(interception_v15_B.ctemp.re /
                      interception_v15_B.x_im);
                  }
                } else {
                  interception_v15_B.temp2 = fabs(interception_v15_B.x_re);
                  interception_v15_B.t_d = fabs(interception_v15_B.x_im);
                  if (interception_v15_B.temp2 > interception_v15_B.t_d) {
                    interception_v15_B.temp2 = interception_v15_B.x_im /
                      interception_v15_B.x_re;
                    interception_v15_B.x_re += interception_v15_B.temp2 *
                      interception_v15_B.x_im;
                    interception_v15_B.t_d = (interception_v15_B.temp2 *
                      interception_v15_B.ctemp.im + interception_v15_B.ctemp.re)
                      / interception_v15_B.x_re;
                    interception_v15_B.x_re = (interception_v15_B.ctemp.im -
                      interception_v15_B.temp2 * interception_v15_B.ctemp.re) /
                      interception_v15_B.x_re;
                  } else if (interception_v15_B.t_d == interception_v15_B.temp2)
                  {
                    interception_v15_B.x_re = interception_v15_B.x_re > 0.0 ?
                      0.5 : -0.5;
                    interception_v15_B.x_im = interception_v15_B.x_im > 0.0 ?
                      0.5 : -0.5;
                    interception_v15_B.t_d = (interception_v15_B.ctemp.re *
                      interception_v15_B.x_re + interception_v15_B.ctemp.im *
                      interception_v15_B.x_im) / interception_v15_B.temp2;
                    interception_v15_B.x_re = (interception_v15_B.ctemp.im *
                      interception_v15_B.x_re - interception_v15_B.ctemp.re *
                      interception_v15_B.x_im) / interception_v15_B.temp2;
                  } else {
                    interception_v15_B.temp2 = interception_v15_B.x_re /
                      interception_v15_B.x_im;
                    interception_v15_B.x_re = interception_v15_B.temp2 *
                      interception_v15_B.x_re + interception_v15_B.x_im;
                    interception_v15_B.t_d = (interception_v15_B.temp2 *
                      interception_v15_B.ctemp.re + interception_v15_B.ctemp.im)
                      / interception_v15_B.x_re;
                    interception_v15_B.x_re = (interception_v15_B.temp2 *
                      interception_v15_B.ctemp.im - interception_v15_B.ctemp.re)
                      / interception_v15_B.x_re;
                  }
                }

                interception_v15_B.colscale -= interception_v15_B.ctemp.re *
                  interception_v15_B.t_d - interception_v15_B.ctemp.im *
                  interception_v15_B.x_re;
                interception_v15_B.absxk_l -= interception_v15_B.ctemp.re *
                  interception_v15_B.x_re + interception_v15_B.ctemp.im *
                  interception_v15_B.t_d;
              }
            } else {
              if (iiter - div_nzp_s32(iiter, 20) * 20 == 0) {
                colscale_tmp = b_A_size_idx_0 * ilast + ilast;
                interception_v15_B.x_re = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].re;
                interception_v15_B.t_d = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].im;
                if (interception_v15_B.t_d == 0.0) {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d = 0.0;
                } else if (interception_v15_B.x_re == 0.0) {
                  interception_v15_B.x_re = 0.0;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                } else {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                }

                interception_v15_B.eshift_re += interception_v15_B.x_re;
                interception_v15_B.eshift_im += interception_v15_B.t_d;
              } else {
                colscale_tmp = b_A_size_idx_0 * ilastm1 + ilast;
                interception_v15_B.x_re = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].re;
                interception_v15_B.t_d = interception_v15_B.anorm *
                  interception_v15_B.b_A_data[colscale_tmp].im;
                if (interception_v15_B.t_d == 0.0) {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d = 0.0;
                } else if (interception_v15_B.x_re == 0.0) {
                  interception_v15_B.x_re = 0.0;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                } else {
                  interception_v15_B.x_re /= interception_v15_B.scale;
                  interception_v15_B.t_d /= interception_v15_B.scale;
                }

                interception_v15_B.eshift_re += interception_v15_B.x_re;
                interception_v15_B.eshift_im += interception_v15_B.t_d;
              }

              interception_v15_B.colscale = interception_v15_B.eshift_re;
              interception_v15_B.absxk_l = interception_v15_B.eshift_im;
            }

            interception_v15_B.j_f = ilastm1;
            jp1 = ilastm1 + 1;
            exitg2 = false;
            while ((!exitg2) && (interception_v15_B.j_f + 1 >
                                 interception_v15_B.n)) {
              nm1 = interception_v15_B.j_f + 1;
              colscale_tmp_tmp = b_A_size_idx_0 * interception_v15_B.j_f;
              colscale_tmp = interception_v15_B.j_f + colscale_tmp_tmp;
              interception_v15_B.ctemp.re = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].re -
                interception_v15_B.colscale * interception_v15_B.scale;
              interception_v15_B.ctemp.im = interception_v15_B.anorm *
                interception_v15_B.b_A_data[colscale_tmp].im -
                interception_v15_B.absxk_l * interception_v15_B.scale;
              interception_v15_B.temp = fabs(interception_v15_B.ctemp.re) + fabs
                (interception_v15_B.ctemp.im);
              jp1 += colscale_tmp_tmp;
              interception_v15_B.temp2 = (fabs(interception_v15_B.b_A_data[jp1].
                re) + fabs(interception_v15_B.b_A_data[jp1].im)) *
                interception_v15_B.anorm;
              interception_v15_B.t_d = interception_v15_B.temp;
              if (interception_v15_B.temp2 > interception_v15_B.temp) {
                interception_v15_B.t_d = interception_v15_B.temp2;
              }

              if ((interception_v15_B.t_d < 1.0) && (interception_v15_B.t_d !=
                   0.0)) {
                interception_v15_B.temp /= interception_v15_B.t_d;
                interception_v15_B.temp2 /= interception_v15_B.t_d;
              }

              colscale_tmp_tmp = (interception_v15_B.j_f - 1) * b_A_size_idx_0 +
                interception_v15_B.j_f;
              if ((fabs(interception_v15_B.b_A_data[colscale_tmp_tmp].re) + fabs
                   (interception_v15_B.b_A_data[colscale_tmp_tmp].im)) *
                  interception_v15_B.temp2 <= interception_v15_B.temp *
                  interception_v15_B.ssq) {
                goto90 = true;
                exitg2 = true;
              } else {
                jp1 = interception_v15_B.j_f;
                interception_v15_B.j_f--;
              }
            }

            if (!goto90) {
              nm1 = interception_v15_B.n;
              colscale_tmp = ((interception_v15_B.n - 1) * b_A_size_idx_0 +
                              interception_v15_B.n) - 1;
              interception_v15_B.ctemp.re =
                interception_v15_B.b_A_data[colscale_tmp].re *
                interception_v15_B.anorm - interception_v15_B.colscale *
                interception_v15_B.scale;
              interception_v15_B.ctemp.im =
                interception_v15_B.b_A_data[colscale_tmp].im *
                interception_v15_B.anorm - interception_v15_B.absxk_l *
                interception_v15_B.scale;
            }

            goto90 = false;
            interception_v15_B.j_f = (nm1 - 1) * b_A_size_idx_0 + nm1;
            interception_v15_B.ascale.re =
              interception_v15_B.b_A_data[interception_v15_B.j_f].re *
              interception_v15_B.anorm;
            interception_v15_B.ascale.im =
              interception_v15_B.b_A_data[interception_v15_B.j_f].im *
              interception_v15_B.anorm;
            interception_v15_xzlartg_h(interception_v15_B.ctemp,
              interception_v15_B.ascale, &interception_v15_B.colscale,
              &interception_v15_B.y);
            interception_v15_B.j_f = nm1;
            jp1 = nm1 - 2;
            while (interception_v15_B.j_f < ilast + 1) {
              int32_T t_tmp;
              if (interception_v15_B.j_f > nm1) {
                interception_v15_xzlartg(interception_v15_B.b_A_data
                  [(interception_v15_B.j_f + b_A_size_idx_0 * jp1) - 1],
                  interception_v15_B.b_A_data[interception_v15_B.j_f +
                  b_A_size_idx_0 * jp1], &interception_v15_B.colscale,
                  &interception_v15_B.y, &interception_v15_B.b_A_data
                  [(interception_v15_B.j_f + b_A_size_idx_0 * jp1) - 1]);
                colscale_tmp_tmp = b_A_size_idx_0 * jp1 + interception_v15_B.j_f;
                interception_v15_B.b_A_data[colscale_tmp_tmp].re = 0.0;
                interception_v15_B.b_A_data[colscale_tmp_tmp].im = 0.0;
              }

              for (jp1 = interception_v15_B.j_f; jp1 <= col; jp1++) {
                t_tmp = (jp1 - 1) * b_A_size_idx_0 + interception_v15_B.j_f;
                interception_v15_B.t_d = interception_v15_B.b_A_data[t_tmp].im;
                interception_v15_B.absxk_l = interception_v15_B.b_A_data[t_tmp].
                  re;
                interception_v15_B.x_re = interception_v15_B.b_A_data[((jp1 - 1)
                  * b_A_size_idx_0 + interception_v15_B.j_f) - 1].re;
                interception_v15_B.stemp.re = (interception_v15_B.absxk_l *
                  interception_v15_B.y.re - interception_v15_B.t_d *
                  interception_v15_B.y.im) + interception_v15_B.x_re *
                  interception_v15_B.colscale;
                colscale_tmp_tmp = (jp1 - 1) * b_A_size_idx_0;
                interception_v15_B.x_im = interception_v15_B.b_A_data
                  [(interception_v15_B.j_f + colscale_tmp_tmp) - 1].im;
                interception_v15_B.stemp.im = (interception_v15_B.t_d *
                  interception_v15_B.y.re + interception_v15_B.absxk_l *
                  interception_v15_B.y.im) + interception_v15_B.x_im *
                  interception_v15_B.colscale;
                interception_v15_B.b_A_data[interception_v15_B.j_f +
                  colscale_tmp_tmp].re = interception_v15_B.absxk_l *
                  interception_v15_B.colscale - (interception_v15_B.x_re *
                  interception_v15_B.y.re + interception_v15_B.x_im *
                  interception_v15_B.y.im);
                colscale_tmp_tmp = (jp1 - 1) * b_A_size_idx_0;
                interception_v15_B.b_A_data[interception_v15_B.j_f +
                  colscale_tmp_tmp].im = interception_v15_B.t_d *
                  interception_v15_B.colscale - (interception_v15_B.x_im *
                  interception_v15_B.y.re - interception_v15_B.y.im *
                  interception_v15_B.x_re);
                interception_v15_B.b_A_data[(interception_v15_B.j_f +
                  colscale_tmp_tmp) - 1] = interception_v15_B.stemp;
              }

              interception_v15_B.y.re = -interception_v15_B.y.re;
              interception_v15_B.y.im = -interception_v15_B.y.im;
              jp1 = interception_v15_B.j_f;
              if (ilast + 1 < interception_v15_B.j_f + 2) {
                jp1 = ilast - 1;
              }

              for (colscale_tmp_tmp = interception_v15_B.n; colscale_tmp_tmp <=
                   jp1 + 2; colscale_tmp_tmp++) {
                t_tmp = ((interception_v15_B.j_f - 1) * b_A_size_idx_0 +
                         colscale_tmp_tmp) - 1;
                interception_v15_B.t_d = interception_v15_B.b_A_data[t_tmp].im;
                interception_v15_B.absxk_l = interception_v15_B.b_A_data[t_tmp].
                  re;
                colscale_tmp = (b_A_size_idx_0 * interception_v15_B.j_f +
                                colscale_tmp_tmp) - 1;
                interception_v15_B.x_re =
                  interception_v15_B.b_A_data[colscale_tmp].re;
                interception_v15_B.stemp.re = (interception_v15_B.absxk_l *
                  interception_v15_B.y.re - interception_v15_B.t_d *
                  interception_v15_B.y.im) + interception_v15_B.x_re *
                  interception_v15_B.colscale;
                interception_v15_B.x_im =
                  interception_v15_B.b_A_data[colscale_tmp].im;
                interception_v15_B.stemp.im = (interception_v15_B.t_d *
                  interception_v15_B.y.re + interception_v15_B.absxk_l *
                  interception_v15_B.y.im) + interception_v15_B.x_im *
                  interception_v15_B.colscale;
                interception_v15_B.b_A_data[t_tmp].re =
                  interception_v15_B.absxk_l * interception_v15_B.colscale -
                  (interception_v15_B.x_re * interception_v15_B.y.re +
                   interception_v15_B.x_im * interception_v15_B.y.im);
                interception_v15_B.b_A_data[t_tmp].im = interception_v15_B.t_d *
                  interception_v15_B.colscale - (interception_v15_B.x_im *
                  interception_v15_B.y.re - interception_v15_B.y.im *
                  interception_v15_B.x_re);
                interception_v15_B.b_A_data[colscale_tmp] =
                  interception_v15_B.stemp;
              }

              jp1 = interception_v15_B.j_f - 1;
              interception_v15_B.j_f++;
            }
          }

          jiter++;
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (interception_v15_B.n = 0; interception_v15_B.n <= ilast;
           interception_v15_B.n++) {
        alpha1_data[interception_v15_B.n].re = (rtNaN);
        alpha1_data[interception_v15_B.n].im = 0.0;
        beta1_data[interception_v15_B.n].re = (rtNaN);
        beta1_data[interception_v15_B.n].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    ilast = static_cast<uint8_T>(ilo - 1);
    for (interception_v15_B.n = 0; interception_v15_B.n < ilast;
         interception_v15_B.n++) {
      alpha1_data[interception_v15_B.n] =
        interception_v15_B.b_A_data[b_A_size_idx_0 * interception_v15_B.n +
        interception_v15_B.n];
    }
  }
}

// Function for MATLAB Function: '<Root>/Numeric Calculation of Tgo'
static void interception_v15_xzgeev_f(const real_T A_data[], const int32_T
  A_size[2], int32_T *info, creal_T alpha1_data[], int32_T *alpha1_size, creal_T
  beta1_data[], int32_T *beta1_size)
{
  boolean_T exitg1;
  interception_v15_B.At_size[0] = A_size[0];
  interception_v15_B.At_size[1] = A_size[1];
  interception_v15_B.loop_ub = A_size[0] * A_size[1];
  for (interception_v15_B.k = 0; interception_v15_B.k <
       interception_v15_B.loop_ub; interception_v15_B.k++) {
    interception_v15_B.At_data[interception_v15_B.k].re =
      A_data[interception_v15_B.k];
    interception_v15_B.At_data[interception_v15_B.k].im = 0.0;
  }

  *info = 0;
  interception_v15_B.anrm = 0.0;
  interception_v15_B.loop_ub = A_size[0] * A_size[1];
  interception_v15_B.k = 0;
  exitg1 = false;
  while ((!exitg1) && (interception_v15_B.k <= interception_v15_B.loop_ub - 1))
  {
    interception_v15_B.absxk_g = interception_v15_rt_hypotd_snf
      (interception_v15_B.At_data[interception_v15_B.k].re,
       interception_v15_B.At_data[interception_v15_B.k].im);
    if (rtIsNaN(interception_v15_B.absxk_g)) {
      interception_v15_B.anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (interception_v15_B.absxk_g > interception_v15_B.anrm) {
        interception_v15_B.anrm = interception_v15_B.absxk_g;
      }

      interception_v15_B.k++;
    }
  }

  if (rtIsInf(interception_v15_B.anrm) || rtIsNaN(interception_v15_B.anrm)) {
    *alpha1_size = A_size[0];
    interception_v15_B.loop_ub = A_size[0];
    for (interception_v15_B.k = 0; interception_v15_B.k <
         interception_v15_B.loop_ub; interception_v15_B.k++) {
      alpha1_data[interception_v15_B.k].re = (rtNaN);
      alpha1_data[interception_v15_B.k].im = 0.0;
    }

    *beta1_size = A_size[0];
    interception_v15_B.loop_ub = A_size[0];
    for (interception_v15_B.k = 0; interception_v15_B.k <
         interception_v15_B.loop_ub; interception_v15_B.k++) {
      beta1_data[interception_v15_B.k].re = (rtNaN);
      beta1_data[interception_v15_B.k].im = 0.0;
    }
  } else {
    boolean_T guard1 = false;
    boolean_T ilascl;
    boolean_T notdone;
    ilascl = false;
    interception_v15_B.absxk_g = interception_v15_B.anrm;
    guard1 = false;
    if ((interception_v15_B.anrm > 0.0) && (interception_v15_B.anrm <
         6.7178761075670888E-139)) {
      interception_v15_B.absxk_g = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else if (interception_v15_B.anrm > 1.4885657073574029E+138) {
      interception_v15_B.absxk_g = 1.4885657073574029E+138;
      ilascl = true;
      guard1 = true;
    }

    if (guard1) {
      interception_v15_B.cfromc = interception_v15_B.anrm;
      interception_v15_B.ctoc = interception_v15_B.absxk_g;
      notdone = true;
      while (notdone) {
        interception_v15_B.cfrom1 = interception_v15_B.cfromc *
          2.0041683600089728E-292;
        interception_v15_B.cto1 = interception_v15_B.ctoc / 4.9896007738368E+291;
        if ((interception_v15_B.cfrom1 > interception_v15_B.ctoc) &&
            (interception_v15_B.ctoc != 0.0)) {
          interception_v15_B.stemp_im_tmp = 2.0041683600089728E-292;
          interception_v15_B.cfromc = interception_v15_B.cfrom1;
        } else if (interception_v15_B.cto1 > interception_v15_B.cfromc) {
          interception_v15_B.stemp_im_tmp = 4.9896007738368E+291;
          interception_v15_B.ctoc = interception_v15_B.cto1;
        } else {
          interception_v15_B.stemp_im_tmp = interception_v15_B.ctoc /
            interception_v15_B.cfromc;
          notdone = false;
        }

        for (interception_v15_B.k = 0; interception_v15_B.k <
             interception_v15_B.loop_ub; interception_v15_B.k++) {
          interception_v15_B.At_data[interception_v15_B.k].re *=
            interception_v15_B.stemp_im_tmp;
          interception_v15_B.At_data[interception_v15_B.k].im *=
            interception_v15_B.stemp_im_tmp;
        }
      }
    }

    interception_v15_B.loop_ub = 1;
    interception_v15_B.k = A_size[0];
    if (A_size[0] <= 1) {
      interception_v15_B.k = 1;
    } else {
      int32_T exitg3;
      boolean_T exitg4;
      do {
        exitg3 = 0;
        interception_v15_B.jcol = 0;
        interception_v15_B.c_n = 0;
        notdone = false;
        interception_v15_B.ii = interception_v15_B.k;
        exitg1 = false;
        while ((!exitg1) && (interception_v15_B.ii > 0)) {
          interception_v15_B.nzcount = 0;
          interception_v15_B.jcol = interception_v15_B.ii;
          interception_v15_B.c_n = interception_v15_B.k;
          interception_v15_B.jj = 0;
          exitg4 = false;
          while ((!exitg4) && (interception_v15_B.jj <= static_cast<uint8_T>
                               (interception_v15_B.k) - 1)) {
            interception_v15_B.atmp_tmp = (interception_v15_B.At_size[0] *
              interception_v15_B.jj + interception_v15_B.ii) - 1;
            if ((interception_v15_B.At_data[interception_v15_B.atmp_tmp].re !=
                 0.0) || (interception_v15_B.At_data[interception_v15_B.atmp_tmp]
                          .im != 0.0) || (interception_v15_B.jj + 1 ==
                 interception_v15_B.ii)) {
              if (interception_v15_B.nzcount == 0) {
                interception_v15_B.c_n = interception_v15_B.jj + 1;
                interception_v15_B.nzcount = 1;
                interception_v15_B.jj++;
              } else {
                interception_v15_B.nzcount = 2;
                exitg4 = true;
              }
            } else {
              interception_v15_B.jj++;
            }
          }

          if (interception_v15_B.nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            interception_v15_B.ii--;
          }
        }

        if (!notdone) {
          exitg3 = 2;
        } else {
          interception_v15_B.ii = interception_v15_B.At_size[0];
          if (interception_v15_B.jcol != interception_v15_B.k) {
            for (interception_v15_B.nzcount = 1; interception_v15_B.nzcount <=
                 interception_v15_B.ii; interception_v15_B.nzcount++) {
              interception_v15_B.jj = (interception_v15_B.nzcount - 1) *
                interception_v15_B.At_size[0];
              interception_v15_B.atmp_tmp = (interception_v15_B.jcol +
                interception_v15_B.jj) - 1;
              interception_v15_B.atmp =
                interception_v15_B.At_data[interception_v15_B.atmp_tmp];
              interception_v15_B.At_data[interception_v15_B.atmp_tmp] =
                interception_v15_B.At_data[(interception_v15_B.k +
                interception_v15_B.jj) - 1];
              interception_v15_B.At_data[(interception_v15_B.k +
                interception_v15_B.At_size[0] * (interception_v15_B.nzcount - 1))
                - 1] = interception_v15_B.atmp;
            }
          }

          if (interception_v15_B.c_n != interception_v15_B.k) {
            interception_v15_B.jcol = static_cast<uint8_T>(interception_v15_B.k);
            for (interception_v15_B.ii = 0; interception_v15_B.ii <
                 interception_v15_B.jcol; interception_v15_B.ii++) {
              interception_v15_B.jj = (interception_v15_B.c_n - 1) *
                interception_v15_B.At_size[0];
              interception_v15_B.atmp =
                interception_v15_B.At_data[interception_v15_B.ii +
                interception_v15_B.jj];
              interception_v15_B.nzcount = (interception_v15_B.k - 1) *
                interception_v15_B.At_size[0] + interception_v15_B.ii;
              interception_v15_B.At_data[interception_v15_B.ii +
                interception_v15_B.jj] =
                interception_v15_B.At_data[interception_v15_B.nzcount];
              interception_v15_B.At_data[interception_v15_B.nzcount] =
                interception_v15_B.atmp;
            }
          }

          interception_v15_B.k--;
          if (interception_v15_B.k == 1) {
            exitg3 = 1;
          }
        }
      } while (exitg3 == 0);

      if (exitg3 == 1) {
      } else {
        int32_T exitg2;
        do {
          exitg2 = 0;
          interception_v15_B.jcol = 0;
          interception_v15_B.c_n = 0;
          notdone = false;
          interception_v15_B.ii = interception_v15_B.loop_ub;
          exitg1 = false;
          while ((!exitg1) && (interception_v15_B.ii <= interception_v15_B.k)) {
            interception_v15_B.nzcount = 0;
            interception_v15_B.jcol = interception_v15_B.k;
            interception_v15_B.c_n = interception_v15_B.ii;
            interception_v15_B.jj = interception_v15_B.loop_ub;
            exitg4 = false;
            while ((!exitg4) && (interception_v15_B.jj <= interception_v15_B.k))
            {
              interception_v15_B.atmp_tmp = ((interception_v15_B.ii - 1) *
                interception_v15_B.At_size[0] + interception_v15_B.jj) - 1;
              if ((interception_v15_B.At_data[interception_v15_B.atmp_tmp].re !=
                   0.0) ||
                  (interception_v15_B.At_data[interception_v15_B.atmp_tmp].im !=
                   0.0) || (interception_v15_B.jj == interception_v15_B.ii)) {
                if (interception_v15_B.nzcount == 0) {
                  interception_v15_B.jcol = interception_v15_B.jj;
                  interception_v15_B.nzcount = 1;
                  interception_v15_B.jj++;
                } else {
                  interception_v15_B.nzcount = 2;
                  exitg4 = true;
                }
              } else {
                interception_v15_B.jj++;
              }
            }

            if (interception_v15_B.nzcount < 2) {
              notdone = true;
              exitg1 = true;
            } else {
              interception_v15_B.ii++;
            }
          }

          if (!notdone) {
            exitg2 = 1;
          } else {
            interception_v15_B.ii = interception_v15_B.At_size[0];
            if (interception_v15_B.jcol != interception_v15_B.loop_ub) {
              for (interception_v15_B.nzcount = interception_v15_B.loop_ub;
                   interception_v15_B.nzcount <= interception_v15_B.ii;
                   interception_v15_B.nzcount++) {
                interception_v15_B.jj = (interception_v15_B.nzcount - 1) *
                  interception_v15_B.At_size[0];
                interception_v15_B.atmp_tmp = (interception_v15_B.jcol +
                  interception_v15_B.jj) - 1;
                interception_v15_B.atmp =
                  interception_v15_B.At_data[interception_v15_B.atmp_tmp];
                interception_v15_B.At_data[interception_v15_B.atmp_tmp] =
                  interception_v15_B.At_data[(interception_v15_B.loop_ub +
                  interception_v15_B.jj) - 1];
                interception_v15_B.At_data[(interception_v15_B.loop_ub +
                  interception_v15_B.At_size[0] * (interception_v15_B.nzcount -
                  1)) - 1] = interception_v15_B.atmp;
              }
            }

            if (interception_v15_B.c_n != interception_v15_B.loop_ub) {
              interception_v15_B.jcol = static_cast<uint8_T>
                (interception_v15_B.k);
              for (interception_v15_B.ii = 0; interception_v15_B.ii <
                   interception_v15_B.jcol; interception_v15_B.ii++) {
                interception_v15_B.jj = (interception_v15_B.c_n - 1) *
                  interception_v15_B.At_size[0] + interception_v15_B.ii;
                interception_v15_B.atmp =
                  interception_v15_B.At_data[interception_v15_B.jj];
                interception_v15_B.nzcount = (interception_v15_B.loop_ub - 1) *
                  interception_v15_B.At_size[0] + interception_v15_B.ii;
                interception_v15_B.At_data[interception_v15_B.jj] =
                  interception_v15_B.At_data[interception_v15_B.nzcount];
                interception_v15_B.At_data[interception_v15_B.nzcount] =
                  interception_v15_B.atmp;
              }
            }

            interception_v15_B.loop_ub++;
            if (interception_v15_B.loop_ub == interception_v15_B.k) {
              exitg2 = 1;
            }
          }
        } while (exitg2 == 0);
      }
    }

    interception_v15_B.c_n = A_size[0];
    if ((A_size[0] > 1) && (interception_v15_B.k >= interception_v15_B.loop_ub +
         2)) {
      interception_v15_B.jcol = interception_v15_B.loop_ub - 1;
      while (interception_v15_B.jcol + 1 < interception_v15_B.k - 1) {
        interception_v15_B.ii = interception_v15_B.k - 1;
        while (interception_v15_B.ii + 1 > interception_v15_B.jcol + 2) {
          interception_v15_xzlartg(interception_v15_B.At_data
            [(interception_v15_B.ii + interception_v15_B.At_size[0] *
              interception_v15_B.jcol) - 1],
            interception_v15_B.At_data[interception_v15_B.ii +
            interception_v15_B.At_size[0] * interception_v15_B.jcol],
            &interception_v15_B.cfromc, &interception_v15_B.atmp,
            &interception_v15_B.At_data[(interception_v15_B.ii +
            interception_v15_B.At_size[0] * interception_v15_B.jcol) - 1]);
          interception_v15_B.atmp_tmp = interception_v15_B.At_size[0] *
            interception_v15_B.jcol + interception_v15_B.ii;
          interception_v15_B.At_data[interception_v15_B.atmp_tmp].re = 0.0;
          interception_v15_B.At_data[interception_v15_B.atmp_tmp].im = 0.0;
          for (interception_v15_B.nzcount = interception_v15_B.jcol + 2;
               interception_v15_B.nzcount <= interception_v15_B.c_n;
               interception_v15_B.nzcount++) {
            interception_v15_B.ctoc = interception_v15_B.At_data
              [(interception_v15_B.nzcount - 1) * interception_v15_B.At_size[0]
              + interception_v15_B.ii].im;
            interception_v15_B.atmp_tmp = (interception_v15_B.nzcount - 1) *
              interception_v15_B.At_size[0];
            interception_v15_B.jj = interception_v15_B.ii +
              interception_v15_B.atmp_tmp;
            interception_v15_B.cfrom1 =
              interception_v15_B.At_data[interception_v15_B.jj].re;
            interception_v15_B.atmp_tmp = (interception_v15_B.ii +
              interception_v15_B.atmp_tmp) - 1;
            interception_v15_B.cto1 =
              interception_v15_B.At_data[interception_v15_B.atmp_tmp].re;
            interception_v15_B.stemp_im_tmp =
              interception_v15_B.At_data[interception_v15_B.atmp_tmp].im;
            interception_v15_B.At_data[interception_v15_B.jj].re =
              interception_v15_B.cfrom1 * interception_v15_B.cfromc -
              (interception_v15_B.cto1 * interception_v15_B.atmp.re +
               interception_v15_B.stemp_im_tmp * interception_v15_B.atmp.im);
            interception_v15_B.At_data[interception_v15_B.jj].im =
              interception_v15_B.ctoc * interception_v15_B.cfromc -
              (interception_v15_B.stemp_im_tmp * interception_v15_B.atmp.re -
               interception_v15_B.atmp.im * interception_v15_B.cto1);
            interception_v15_B.At_data[interception_v15_B.atmp_tmp].re =
              (interception_v15_B.cfrom1 * interception_v15_B.atmp.re -
               interception_v15_B.ctoc * interception_v15_B.atmp.im) +
              interception_v15_B.cto1 * interception_v15_B.cfromc;
            interception_v15_B.At_data[(interception_v15_B.ii +
              interception_v15_B.At_size[0] * (interception_v15_B.nzcount - 1))
              - 1].im = (interception_v15_B.ctoc * interception_v15_B.atmp.re +
                         interception_v15_B.cfrom1 * interception_v15_B.atmp.im)
              + interception_v15_B.stemp_im_tmp * interception_v15_B.cfromc;
          }

          interception_v15_B.atmp.re = -interception_v15_B.atmp.re;
          interception_v15_B.atmp.im = -interception_v15_B.atmp.im;
          for (interception_v15_B.nzcount = 1; interception_v15_B.nzcount <=
               interception_v15_B.k; interception_v15_B.nzcount++) {
            interception_v15_B.jj = (interception_v15_B.ii - 1) *
              interception_v15_B.At_size[0];
            interception_v15_B.atmp_tmp = (interception_v15_B.nzcount +
              interception_v15_B.jj) - 1;
            interception_v15_B.ctoc =
              interception_v15_B.At_data[interception_v15_B.atmp_tmp].im;
            interception_v15_B.cfrom1 =
              interception_v15_B.At_data[interception_v15_B.atmp_tmp].re;
            interception_v15_B.atmp_tmp = interception_v15_B.At_size[0] *
              interception_v15_B.ii;
            interception_v15_B.cto1 = interception_v15_B.At_data
              [(interception_v15_B.nzcount + interception_v15_B.atmp_tmp) - 1].
              re;
            interception_v15_B.stemp_im_tmp = interception_v15_B.At_data
              [(interception_v15_B.nzcount + interception_v15_B.atmp_tmp) - 1].
              im;
            interception_v15_B.At_data[(interception_v15_B.nzcount +
              interception_v15_B.jj) - 1].re = interception_v15_B.cfrom1 *
              interception_v15_B.cfromc - (interception_v15_B.cto1 *
              interception_v15_B.atmp.re + interception_v15_B.stemp_im_tmp *
              interception_v15_B.atmp.im);
            interception_v15_B.At_data[(interception_v15_B.nzcount +
              interception_v15_B.jj) - 1].im = interception_v15_B.ctoc *
              interception_v15_B.cfromc - (interception_v15_B.stemp_im_tmp *
              interception_v15_B.atmp.re - interception_v15_B.atmp.im *
              interception_v15_B.cto1);
            interception_v15_B.atmp_tmp = (interception_v15_B.nzcount +
              interception_v15_B.atmp_tmp) - 1;
            interception_v15_B.At_data[interception_v15_B.atmp_tmp].re =
              (interception_v15_B.cfrom1 * interception_v15_B.atmp.re -
               interception_v15_B.ctoc * interception_v15_B.atmp.im) +
              interception_v15_B.cto1 * interception_v15_B.cfromc;
            interception_v15_B.At_data[interception_v15_B.atmp_tmp].im =
              (interception_v15_B.ctoc * interception_v15_B.atmp.re +
               interception_v15_B.cfrom1 * interception_v15_B.atmp.im) +
              interception_v15_B.stemp_im_tmp * interception_v15_B.cfromc;
          }

          interception_v15_B.ii--;
        }

        interception_v15_B.jcol++;
      }
    }

    interception_v15_xzhgeqz_a(interception_v15_B.At_data,
      interception_v15_B.At_size, interception_v15_B.loop_ub,
      interception_v15_B.k, info, alpha1_data, alpha1_size, beta1_data,
      beta1_size);
    if ((*info == 0) && ilascl) {
      ilascl = true;
      while (ilascl) {
        interception_v15_B.cfromc = interception_v15_B.absxk_g *
          2.0041683600089728E-292;
        interception_v15_B.ctoc = interception_v15_B.anrm / 4.9896007738368E+291;
        if ((interception_v15_B.cfromc > interception_v15_B.anrm) &&
            (interception_v15_B.anrm != 0.0)) {
          interception_v15_B.cfrom1 = 2.0041683600089728E-292;
          interception_v15_B.absxk_g = interception_v15_B.cfromc;
        } else if (interception_v15_B.ctoc > interception_v15_B.absxk_g) {
          interception_v15_B.cfrom1 = 4.9896007738368E+291;
          interception_v15_B.anrm = interception_v15_B.ctoc;
        } else {
          interception_v15_B.cfrom1 = interception_v15_B.anrm /
            interception_v15_B.absxk_g;
          ilascl = false;
        }

        interception_v15_B.loop_ub = *alpha1_size;
        for (interception_v15_B.k = 0; interception_v15_B.k <
             interception_v15_B.loop_ub; interception_v15_B.k++) {
          interception_v15_B.atmp = alpha1_data[interception_v15_B.k];
          interception_v15_B.atmp.re *= interception_v15_B.cfrom1;
          interception_v15_B.atmp.im *= interception_v15_B.cfrom1;
          alpha1_data[interception_v15_B.k] = interception_v15_B.atmp;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/Numeric Calculation of Tgo'
static boolean_T interception_v15_cplxpairv(creal_T x_data[], const int32_T
  *x_size, real_T tol)
{
  int32_T b_i;
  int32_T c_j;
  int32_T i;
  int32_T i2;
  int32_T j_k_tmp;
  int32_T k0;
  int32_T kEnd;
  int32_T ng;
  int32_T pEnd;
  int32_T qEnd;
  boolean_T exitg1;
  boolean_T pairable;
  interception_v15_B.n_m = *x_size;
  interception_v15_B.nc = *x_size;
  b_i = *x_size;
  for (pEnd = 0; pEnd < b_i; pEnd++) {
    interception_v15_B.zr_data[pEnd] = x_data[pEnd].re;
  }

  if (static_cast<int8_T>(*x_size) - 1 >= 0) {
    memset(&interception_v15_B.idx_data[0], 0, static_cast<uint32_T>(
            static_cast<int8_T>(*x_size)) * sizeof(int32_T));
  }

  b_i = *x_size - 1;
  for (pEnd = 1; pEnd <= b_i; pEnd += 2) {
    if ((interception_v15_B.zr_data[pEnd - 1] <= interception_v15_B.zr_data[pEnd])
        || rtIsNaN(interception_v15_B.zr_data[pEnd])) {
      interception_v15_B.idx_data[pEnd - 1] = pEnd;
      interception_v15_B.idx_data[pEnd] = pEnd + 1;
    } else {
      interception_v15_B.idx_data[pEnd - 1] = pEnd + 1;
      interception_v15_B.idx_data[pEnd] = pEnd;
    }
  }

  if ((static_cast<uint32_T>(*x_size) & 1U) != 0U) {
    interception_v15_B.idx_data[*x_size - 1] = *x_size;
  }

  b_i = 2;
  while (b_i < interception_v15_B.nc) {
    k0 = b_i << 1;
    ng = 1;
    for (c_j = b_i + 1; c_j < interception_v15_B.nc + 1; c_j = i + b_i) {
      qEnd = ng;
      kEnd = c_j - 1;
      i = ng + k0;
      if (i > interception_v15_B.nc + 1) {
        i = interception_v15_B.nc + 1;
      }

      pEnd = 0;
      i2 = i - ng;
      while (pEnd + 1 <= i2) {
        interception_v15_B.zr0 =
          interception_v15_B.zr_data[interception_v15_B.idx_data[kEnd] - 1];
        j_k_tmp = interception_v15_B.idx_data[qEnd - 1];
        if ((interception_v15_B.zr_data[j_k_tmp - 1] <= interception_v15_B.zr0) ||
            rtIsNaN(interception_v15_B.zr0)) {
          interception_v15_B.b_iwork_data[pEnd] = j_k_tmp;
          qEnd++;
          if (qEnd == c_j) {
            while (kEnd + 1 < i) {
              pEnd++;
              interception_v15_B.b_iwork_data[pEnd] =
                interception_v15_B.idx_data[kEnd];
              kEnd++;
            }
          }
        } else {
          interception_v15_B.b_iwork_data[pEnd] =
            interception_v15_B.idx_data[kEnd];
          kEnd++;
          if (kEnd + 1 == i) {
            while (qEnd < c_j) {
              pEnd++;
              interception_v15_B.b_iwork_data[pEnd] =
                interception_v15_B.idx_data[qEnd - 1];
              qEnd++;
            }
          }
        }

        pEnd++;
      }

      for (pEnd = 0; pEnd < i2; pEnd++) {
        interception_v15_B.idx_data[(ng + pEnd) - 1] =
          interception_v15_B.b_iwork_data[pEnd];
      }

      ng = i;
    }

    b_i = k0;
  }

  b_i = 0;
  interception_v15_B.nc = 0;
  k0 = *x_size;
  for (pEnd = 0; pEnd < k0; pEnd++) {
    ng = interception_v15_B.idx_data[pEnd];
    interception_v15_B.zr0 = x_data[ng - 1].re;
    interception_v15_B.absxk_tmp = x_data[ng - 1].im;
    interception_v15_B.absxk_e = interception_v15_rt_hypotd_snf
      (interception_v15_B.zr0, interception_v15_B.absxk_tmp);
    if (fabs(x_data[ng - 1].im) <= tol * interception_v15_B.absxk_e) {
      b_i++;
      i = interception_v15_B.n_m - b_i;
      interception_v15_B.zr_data[i] = interception_v15_B.zr0;
      interception_v15_B.zi_data[i] = 0.0;
      interception_v15_B.absx_data[pEnd] = interception_v15_B.absxk_e;
    } else {
      interception_v15_B.nc++;
      interception_v15_B.zr_data[interception_v15_B.nc - 1] =
        interception_v15_B.zr0;
      interception_v15_B.zi_data[interception_v15_B.nc - 1] =
        interception_v15_B.absxk_tmp;
      interception_v15_B.absx_data[interception_v15_B.nc - 1] =
        interception_v15_B.absxk_e;
    }
  }

  for (k0 = 0; k0 < b_i; k0++) {
    pEnd = interception_v15_B.nc + k0;
    x_data[pEnd].re = interception_v15_B.zr_data[(interception_v15_B.n_m - k0) -
      1];
    x_data[pEnd].im = 0.0;
  }

  for (pEnd = 0; pEnd < interception_v15_B.nc; pEnd++) {
    x_data[pEnd].re = interception_v15_B.zr_data[pEnd];
    x_data[pEnd].im = interception_v15_B.zi_data[pEnd];
  }

  pairable = ((interception_v15_B.nc & 1) != 1);
  if (pairable) {
    pEnd = 1;
    exitg1 = false;
    while ((!exitg1) && (pEnd <= interception_v15_B.nc)) {
      if (interception_v15_B.zr_data[pEnd] - interception_v15_B.zr_data[pEnd - 1]
          > interception_v15_B.absx_data[pEnd - 1] * tol) {
        pairable = false;
        exitg1 = true;
      } else {
        pEnd += 2;
      }
    }
  }

  if (pairable) {
    interception_v15_B.n_m = 1;
    exitg1 = false;
    while ((!exitg1) && (interception_v15_B.n_m < interception_v15_B.nc)) {
      int32_T ng_tmp;
      uint32_T pairable_tmp;
      interception_v15_B.zr0 = interception_v15_B.zr_data[interception_v15_B.n_m
        - 1];
      k0 = interception_v15_B.n_m;
      b_i = interception_v15_B.n_m - 2;
      while ((interception_v15_B.n_m < interception_v15_B.nc) &&
             (interception_v15_B.zr_data[interception_v15_B.n_m] -
              interception_v15_B.zr0 <=
              interception_v15_B.absx_data[interception_v15_B.n_m - 1] * tol)) {
        interception_v15_B.n_m++;
      }

      ng_tmp = interception_v15_B.n_m - k0;
      ng = (interception_v15_B.n_m - k0) + 1;
      pairable_tmp = static_cast<uint32_T>(ng_tmp + 1) & 1U;
      pairable = (pairable_tmp == 0U);
      if (!pairable) {
        exitg1 = true;
      } else {
        boolean_T exitg2;
        for (pEnd = 1; pEnd <= ng - 1; pEnd += 2) {
          i = b_i + pEnd;
          interception_v15_B.zr0 = interception_v15_B.zi_data[i + 1];
          if ((interception_v15_B.zi_data[i] <= interception_v15_B.zr0) ||
              rtIsNaN(interception_v15_B.zr0)) {
            interception_v15_B.idx_data[i] = pEnd;
            interception_v15_B.idx_data[i + 1] = pEnd + 1;
          } else {
            interception_v15_B.idx_data[i] = pEnd + 1;
            interception_v15_B.idx_data[i + 1] = pEnd;
          }
        }

        if (pairable_tmp != 0U) {
          interception_v15_B.idx_data[(b_i + ng_tmp) + 1] = ng_tmp + 1;
        }

        i = 2;
        while (i < ng_tmp + 1) {
          i2 = i << 1;
          c_j = 1;
          pEnd = i + 1;
          while (pEnd < ng_tmp + 2) {
            int32_T f_k;
            int32_T q;
            ng = c_j;
            q = pEnd;
            qEnd = c_j + i2;
            if (qEnd > ng_tmp + 2) {
              qEnd = ng_tmp + 2;
            }

            f_k = 0;
            kEnd = qEnd - c_j;
            while (f_k + 1 <= kEnd) {
              int32_T c_b_tmp_tmp;
              c_b_tmp_tmp = interception_v15_B.idx_data[b_i + q];
              interception_v15_B.zr0 = interception_v15_B.zi_data[c_b_tmp_tmp +
                b_i];
              j_k_tmp = interception_v15_B.idx_data[b_i + ng];
              if ((interception_v15_B.zi_data[j_k_tmp + b_i] <=
                   interception_v15_B.zr0) || rtIsNaN(interception_v15_B.zr0)) {
                interception_v15_B.iwork_data[f_k] = j_k_tmp;
                ng++;
                if (ng == pEnd) {
                  while (q < qEnd) {
                    f_k++;
                    interception_v15_B.iwork_data[f_k] =
                      interception_v15_B.idx_data[b_i + q];
                    q++;
                  }
                }
              } else {
                interception_v15_B.iwork_data[f_k] = c_b_tmp_tmp;
                q++;
                if (q == qEnd) {
                  while (ng < pEnd) {
                    f_k++;
                    interception_v15_B.iwork_data[f_k] =
                      interception_v15_B.idx_data[b_i + ng];
                    ng++;
                  }
                }
              }

              f_k++;
            }

            for (pEnd = 0; pEnd < kEnd; pEnd++) {
              interception_v15_B.idx_data[(b_i + c_j) + pEnd] =
                interception_v15_B.iwork_data[pEnd];
            }

            c_j = qEnd;
            pEnd = qEnd + i;
          }

          i = i2;
        }

        pEnd = k0;
        exitg2 = false;
        while ((!exitg2) && (pEnd <= interception_v15_B.n_m)) {
          i = interception_v15_B.idx_data[pEnd - 1] + b_i;
          if (fabs(interception_v15_B.zi_data[interception_v15_B.idx_data
                   [((interception_v15_B.n_m - pEnd) + k0) - 1] + b_i] +
                   interception_v15_B.zi_data[i]) > tol *
              interception_v15_B.absx_data[i]) {
            pairable = false;
            exitg2 = true;
          } else {
            pEnd++;
          }
        }

        if (!pairable) {
          exitg1 = true;
        } else {
          ng = (ng_tmp + 1) >> 1;
          for (k0 = 0; k0 < ng; k0++) {
            i = interception_v15_B.idx_data[(interception_v15_B.n_m - k0) - 1] +
              b_i;
            pEnd = ((k0 + 1) << 1) + b_i;
            x_data[pEnd - 1].re = interception_v15_B.zr_data[i];
            x_data[pEnd - 1].im = -interception_v15_B.zi_data[i];
            x_data[pEnd].re = interception_v15_B.zr_data[i];
            x_data[pEnd].im = interception_v15_B.zi_data[i];
          }

          interception_v15_B.n_m++;
        }
      }
    }
  }

  return pairable;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    real_T q;
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xzhgeqz(creal_T A[16], int32_T ilo, int32_T ihi,
  creal_T Z[16], int32_T *info, creal_T alpha1[4], creal_T beta1[4])
{
  int32_T absxk_tmp;
  int32_T col;
  int32_T ifirst;
  int32_T iiter;
  int32_T ilast;
  int32_T jp1;
  int32_T nm1;
  boolean_T failed;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *info = 0;
  alpha1[0].re = 0.0;
  alpha1[0].im = 0.0;
  beta1[0].re = 1.0;
  beta1[0].im = 0.0;
  alpha1[1].re = 0.0;
  alpha1[1].im = 0.0;
  beta1[1].re = 1.0;
  beta1[1].im = 0.0;
  alpha1[2].re = 0.0;
  alpha1[2].im = 0.0;
  beta1[2].re = 1.0;
  beta1[2].im = 0.0;
  alpha1[3].re = 0.0;
  alpha1[3].im = 0.0;
  beta1[3].re = 1.0;
  beta1[3].im = 0.0;
  interception_v15_B.eshift_re_j = 0.0;
  interception_v15_B.eshift_im_o = 0.0;
  interception_v15_B.ctemp_m.re = 0.0;
  interception_v15_B.ctemp_m.im = 0.0;
  interception_v15_B.anorm_h = 0.0;
  if (ilo <= ihi) {
    interception_v15_B.scale_e = 3.3121686421112381E-170;
    interception_v15_B.ssq_b = 0.0;
    nm1 = ihi - ilo;
    for (ilast = 0; ilast <= nm1; ilast++) {
      interception_v15_B.colscale_j = 3.3121686421112381E-170;
      interception_v15_B.anorm_h = 0.0;
      col = (ilo + ilast) - 1;
      if (ilast + 1 <= nm1) {
        jp1 = ilast + 1;
      } else {
        jp1 = nm1;
      }

      iiter = ilo + jp1;
      for (ifirst = ilo; ifirst <= iiter; ifirst++) {
        absxk_tmp = ((col << 2) + ifirst) - 1;
        interception_v15_B.absxk_f = fabs(A[absxk_tmp].re);
        if (interception_v15_B.absxk_f > interception_v15_B.colscale_j) {
          interception_v15_B.t_a = interception_v15_B.colscale_j /
            interception_v15_B.absxk_f;
          interception_v15_B.anorm_h = interception_v15_B.anorm_h *
            interception_v15_B.t_a * interception_v15_B.t_a + 1.0;
          interception_v15_B.colscale_j = interception_v15_B.absxk_f;
        } else {
          interception_v15_B.t_a = interception_v15_B.absxk_f /
            interception_v15_B.colscale_j;
          interception_v15_B.anorm_h += interception_v15_B.t_a *
            interception_v15_B.t_a;
        }

        interception_v15_B.absxk_f = fabs(A[absxk_tmp].im);
        if (interception_v15_B.absxk_f > interception_v15_B.colscale_j) {
          interception_v15_B.t_a = interception_v15_B.colscale_j /
            interception_v15_B.absxk_f;
          interception_v15_B.anorm_h = interception_v15_B.anorm_h *
            interception_v15_B.t_a * interception_v15_B.t_a + 1.0;
          interception_v15_B.colscale_j = interception_v15_B.absxk_f;
        } else {
          interception_v15_B.t_a = interception_v15_B.absxk_f /
            interception_v15_B.colscale_j;
          interception_v15_B.anorm_h += interception_v15_B.t_a *
            interception_v15_B.t_a;
        }
      }

      if (interception_v15_B.scale_e >= interception_v15_B.colscale_j) {
        interception_v15_B.colscale_j /= interception_v15_B.scale_e;
        interception_v15_B.ssq_b += interception_v15_B.colscale_j *
          interception_v15_B.colscale_j * interception_v15_B.anorm_h;
      } else {
        interception_v15_B.scale_e /= interception_v15_B.colscale_j;
        interception_v15_B.ssq_b = interception_v15_B.scale_e *
          interception_v15_B.scale_e * interception_v15_B.ssq_b +
          interception_v15_B.anorm_h;
        interception_v15_B.scale_e = interception_v15_B.colscale_j;
      }
    }

    interception_v15_B.anorm_h = interception_v15_B.scale_e * sqrt
      (interception_v15_B.ssq_b);
  }

  interception_v15_B.ssq_b = 2.2250738585072014E-308;
  interception_v15_B.scale_e = 2.2204460492503131E-16 *
    interception_v15_B.anorm_h;
  if (interception_v15_B.scale_e > 2.2250738585072014E-308) {
    interception_v15_B.ssq_b = interception_v15_B.scale_e;
  }

  interception_v15_B.scale_e = 2.2250738585072014E-308;
  if (interception_v15_B.anorm_h > 2.2250738585072014E-308) {
    interception_v15_B.scale_e = interception_v15_B.anorm_h;
  }

  interception_v15_B.anorm_h = 1.0 / interception_v15_B.scale_e;
  failed = true;
  for (ilast = ihi + 1; ilast < 5; ilast++) {
    alpha1[ilast - 1] = A[(((ilast - 1) << 2) + ilast) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    ifirst = ilo;
    nm1 = ilo;
    ilast = ihi - 1;
    col = ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    absxk_tmp = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (absxk_tmp <= ((ihi - ilo) + 1) * 30 - 1) {
        int32_T j;
        int32_T u1_tmp_tmp;
        boolean_T exitg2;
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else {
          jp1 = (ilast << 2) + ilast;
          u1_tmp_tmp = col << 2;
          j = u1_tmp_tmp + col;
          interception_v15_B.scale_e = ((fabs(A[jp1].re) + fabs(A[jp1].im)) +
            (fabs(A[j].re) + fabs(A[j].im))) * 2.2204460492503131E-16;
          if ((interception_v15_B.scale_e <= 2.2250738585072014E-308) || rtIsNaN
              (interception_v15_B.scale_e)) {
            interception_v15_B.scale_e = 2.2250738585072014E-308;
          }

          jp1 = u1_tmp_tmp + ilast;
          if (fabs(A[jp1].re) + fabs(A[jp1].im) <= interception_v15_B.scale_e) {
            A[jp1].re = 0.0;
            A[jp1].im = 0.0;
            goto60 = true;
          } else {
            boolean_T guard3 = false;
            j = col;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (j + 1 >= ilo)) {
              if (j + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                u1_tmp_tmp = ((j - 1) << 2) + j;
                jp1 = (j << 2) + j;
                interception_v15_B.scale_e = ((fabs(A[u1_tmp_tmp - 1].re) + fabs
                  (A[u1_tmp_tmp - 1].im)) + (fabs(A[jp1].re) + fabs(A[jp1].im)))
                  * 2.2204460492503131E-16;
                if ((interception_v15_B.scale_e <= 2.2250738585072014E-308) ||
                    rtIsNaN(interception_v15_B.scale_e)) {
                  interception_v15_B.scale_e = 2.2250738585072014E-308;
                }

                if (fabs(A[u1_tmp_tmp].re) + fabs(A[u1_tmp_tmp].im) <=
                    interception_v15_B.scale_e) {
                  A[u1_tmp_tmp].re = 0.0;
                  A[u1_tmp_tmp].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  j--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              ifirst = j + 1;
              goto70 = true;
            }
          }
        }

        if ((!goto60) && (!goto70)) {
          alpha1[0].re = (rtNaN);
          alpha1[0].im = 0.0;
          beta1[0].re = (rtNaN);
          beta1[0].im = 0.0;
          alpha1[1].re = (rtNaN);
          alpha1[1].im = 0.0;
          beta1[1].re = (rtNaN);
          beta1[1].im = 0.0;
          alpha1[2].re = (rtNaN);
          alpha1[2].im = 0.0;
          beta1[2].re = (rtNaN);
          beta1[2].im = 0.0;
          alpha1[3].re = (rtNaN);
          alpha1[3].im = 0.0;
          beta1[3].re = (rtNaN);
          beta1[3].im = 0.0;
          for (jp1 = 0; jp1 < 16; jp1++) {
            Z[jp1].re = (rtNaN);
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else if (goto60) {
          goto60 = false;
          alpha1[ilast] = A[(ilast << 2) + ilast];
          ilast = col;
          col--;
          if (ilast + 1 < ilo) {
            failed = false;
            guard2 = true;
            exitg1 = 1;
          } else {
            iiter = 0;
            interception_v15_B.eshift_re_j = 0.0;
            interception_v15_B.eshift_im_o = 0.0;
            absxk_tmp++;
          }
        } else {
          if (goto70) {
            int32_T ctemp_tmp;
            goto70 = false;
            iiter++;
            if (iiter - div_nzp_s32(iiter, 10) * 10 != 0) {
              j = (ilast << 2) + ilast;
              interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
              interception_v15_B.absxk_f = A[j].im * interception_v15_B.anorm_h;
              if (interception_v15_B.absxk_f == 0.0) {
                interception_v15_B.scale_e = interception_v15_B.t_a / 0.5;
                interception_v15_B.colscale_j = 0.0;
              } else if (interception_v15_B.t_a == 0.0) {
                interception_v15_B.scale_e = 0.0;
                interception_v15_B.colscale_j = interception_v15_B.absxk_f / 0.5;
              } else {
                interception_v15_B.scale_e = interception_v15_B.t_a / 0.5;
                interception_v15_B.colscale_j = interception_v15_B.absxk_f / 0.5;
              }

              j = (ilast << 2) + col;
              interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
              interception_v15_B.absxk_f = A[j].im * interception_v15_B.anorm_h;
              if (interception_v15_B.absxk_f == 0.0) {
                interception_v15_B.stemp_p.re = interception_v15_B.t_a / 0.5;
                interception_v15_B.stemp_p.im = 0.0;
              } else if (interception_v15_B.t_a == 0.0) {
                interception_v15_B.stemp_p.re = 0.0;
                interception_v15_B.stemp_p.im = interception_v15_B.absxk_f / 0.5;
              } else {
                interception_v15_B.stemp_p.re = interception_v15_B.t_a / 0.5;
                interception_v15_B.stemp_p.im = interception_v15_B.absxk_f / 0.5;
              }

              interception_v15_sqrt(&interception_v15_B.stemp_p);
              j = (col << 2) + ilast;
              interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
              interception_v15_B.absxk_f = A[j].im * interception_v15_B.anorm_h;
              if (interception_v15_B.absxk_f == 0.0) {
                interception_v15_B.y_n.re = interception_v15_B.t_a / 0.5;
                interception_v15_B.y_n.im = 0.0;
              } else if (interception_v15_B.t_a == 0.0) {
                interception_v15_B.y_n.re = 0.0;
                interception_v15_B.y_n.im = interception_v15_B.absxk_f / 0.5;
              } else {
                interception_v15_B.y_n.re = interception_v15_B.t_a / 0.5;
                interception_v15_B.y_n.im = interception_v15_B.absxk_f / 0.5;
              }

              interception_v15_sqrt(&interception_v15_B.y_n);
              interception_v15_B.ctemp_m.re = interception_v15_B.stemp_p.re *
                interception_v15_B.y_n.re - interception_v15_B.stemp_p.im *
                interception_v15_B.y_n.im;
              interception_v15_B.ctemp_m.im = interception_v15_B.stemp_p.re *
                interception_v15_B.y_n.im + interception_v15_B.stemp_p.im *
                interception_v15_B.y_n.re;
              if ((interception_v15_B.ctemp_m.re != 0.0) ||
                  (interception_v15_B.ctemp_m.im != 0.0)) {
                j = (col << 2) + col;
                interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
                interception_v15_B.absxk_f = A[j].im *
                  interception_v15_B.anorm_h;
                if (interception_v15_B.absxk_f == 0.0) {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f = 0.0;
                } else if (interception_v15_B.t_a == 0.0) {
                  interception_v15_B.t_a = 0.0;
                  interception_v15_B.absxk_f /= 0.5;
                } else {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f /= 0.5;
                }

                interception_v15_B.t_a = (interception_v15_B.t_a -
                  interception_v15_B.scale_e) * 0.5;
                interception_v15_B.x_im_j = (interception_v15_B.absxk_f -
                  interception_v15_B.colscale_j) * 0.5;
                interception_v15_B.temp2_d = fabs(interception_v15_B.t_a) + fabs
                  (interception_v15_B.x_im_j);
                interception_v15_B.temp_b = fabs(interception_v15_B.ctemp_m.re)
                  + fabs(interception_v15_B.ctemp_m.im);
                if ((!(interception_v15_B.temp_b >= interception_v15_B.temp2_d))
                    && (!rtIsNaN(interception_v15_B.temp2_d))) {
                  interception_v15_B.temp_b = interception_v15_B.temp2_d;
                }

                if (interception_v15_B.x_im_j == 0.0) {
                  interception_v15_B.stemp_p.re = interception_v15_B.t_a /
                    interception_v15_B.temp_b;
                  interception_v15_B.stemp_p.im = 0.0;
                } else if (interception_v15_B.t_a == 0.0) {
                  interception_v15_B.stemp_p.re = 0.0;
                  interception_v15_B.stemp_p.im = interception_v15_B.x_im_j /
                    interception_v15_B.temp_b;
                } else {
                  interception_v15_B.stemp_p.re = interception_v15_B.t_a /
                    interception_v15_B.temp_b;
                  interception_v15_B.stemp_p.im = interception_v15_B.x_im_j /
                    interception_v15_B.temp_b;
                }

                if (interception_v15_B.ctemp_m.im == 0.0) {
                  interception_v15_B.y_n.re = interception_v15_B.ctemp_m.re /
                    interception_v15_B.temp_b;
                  interception_v15_B.y_n.im = 0.0;
                } else if (interception_v15_B.ctemp_m.re == 0.0) {
                  interception_v15_B.y_n.re = 0.0;
                  interception_v15_B.y_n.im = interception_v15_B.ctemp_m.im /
                    interception_v15_B.temp_b;
                } else {
                  interception_v15_B.y_n.re = interception_v15_B.ctemp_m.re /
                    interception_v15_B.temp_b;
                  interception_v15_B.y_n.im = interception_v15_B.ctemp_m.im /
                    interception_v15_B.temp_b;
                }

                interception_v15_B.stemp_im_tmp_n =
                  interception_v15_B.stemp_p.re * interception_v15_B.stemp_p.im;
                interception_v15_B.stemp_p.re = (interception_v15_B.stemp_p.re *
                  interception_v15_B.stemp_p.re - interception_v15_B.stemp_p.im *
                  interception_v15_B.stemp_p.im) + (interception_v15_B.y_n.re *
                  interception_v15_B.y_n.re - interception_v15_B.y_n.im *
                  interception_v15_B.y_n.im);
                interception_v15_B.absxk_f = interception_v15_B.y_n.re *
                  interception_v15_B.y_n.im;
                interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f +
                  interception_v15_B.absxk_f) +
                  (interception_v15_B.stemp_im_tmp_n +
                   interception_v15_B.stemp_im_tmp_n);
                interception_v15_sqrt(&interception_v15_B.stemp_p);
                interception_v15_B.y_n.re = interception_v15_B.temp_b *
                  interception_v15_B.stemp_p.re;
                interception_v15_B.y_n.im = interception_v15_B.temp_b *
                  interception_v15_B.stemp_p.im;
                if (interception_v15_B.temp2_d > 0.0) {
                  if (interception_v15_B.x_im_j == 0.0) {
                    interception_v15_B.absxk_f = interception_v15_B.t_a /
                      interception_v15_B.temp2_d;
                    interception_v15_B.temp2_d = 0.0;
                  } else {
                    if (interception_v15_B.t_a == 0.0) {
                      interception_v15_B.absxk_f = 0.0;
                    } else {
                      interception_v15_B.absxk_f = interception_v15_B.t_a /
                        interception_v15_B.temp2_d;
                    }

                    interception_v15_B.temp2_d = interception_v15_B.x_im_j /
                      interception_v15_B.temp2_d;
                  }

                  if (interception_v15_B.absxk_f * interception_v15_B.y_n.re +
                      interception_v15_B.temp2_d * interception_v15_B.y_n.im <
                      0.0) {
                    interception_v15_B.y_n.re = -interception_v15_B.y_n.re;
                    interception_v15_B.y_n.im = -interception_v15_B.y_n.im;
                  }
                }

                interception_v15_B.t_a += interception_v15_B.y_n.re;
                interception_v15_B.x_im_j += interception_v15_B.y_n.im;
                if (interception_v15_B.x_im_j == 0.0) {
                  if (interception_v15_B.ctemp_m.im == 0.0) {
                    interception_v15_B.absxk_f = interception_v15_B.ctemp_m.re /
                      interception_v15_B.t_a;
                    interception_v15_B.t_a = 0.0;
                  } else if (interception_v15_B.ctemp_m.re == 0.0) {
                    interception_v15_B.absxk_f = 0.0;
                    interception_v15_B.t_a = interception_v15_B.ctemp_m.im /
                      interception_v15_B.t_a;
                  } else {
                    interception_v15_B.absxk_f = interception_v15_B.ctemp_m.re /
                      interception_v15_B.t_a;
                    interception_v15_B.t_a = interception_v15_B.ctemp_m.im /
                      interception_v15_B.t_a;
                  }
                } else if (interception_v15_B.t_a == 0.0) {
                  if (interception_v15_B.ctemp_m.re == 0.0) {
                    interception_v15_B.absxk_f = interception_v15_B.ctemp_m.im /
                      interception_v15_B.x_im_j;
                    interception_v15_B.t_a = 0.0;
                  } else if (interception_v15_B.ctemp_m.im == 0.0) {
                    interception_v15_B.absxk_f = 0.0;
                    interception_v15_B.t_a = -(interception_v15_B.ctemp_m.re /
                      interception_v15_B.x_im_j);
                  } else {
                    interception_v15_B.absxk_f = interception_v15_B.ctemp_m.im /
                      interception_v15_B.x_im_j;
                    interception_v15_B.t_a = -(interception_v15_B.ctemp_m.re /
                      interception_v15_B.x_im_j);
                  }
                } else {
                  interception_v15_B.temp2_d = fabs(interception_v15_B.t_a);
                  interception_v15_B.absxk_f = fabs(interception_v15_B.x_im_j);
                  if (interception_v15_B.temp2_d > interception_v15_B.absxk_f) {
                    interception_v15_B.temp2_d = interception_v15_B.x_im_j /
                      interception_v15_B.t_a;
                    interception_v15_B.t_a += interception_v15_B.temp2_d *
                      interception_v15_B.x_im_j;
                    interception_v15_B.absxk_f = (interception_v15_B.temp2_d *
                      interception_v15_B.ctemp_m.im +
                      interception_v15_B.ctemp_m.re) / interception_v15_B.t_a;
                    interception_v15_B.t_a = (interception_v15_B.ctemp_m.im -
                      interception_v15_B.temp2_d * interception_v15_B.ctemp_m.re)
                      / interception_v15_B.t_a;
                  } else if (interception_v15_B.absxk_f ==
                             interception_v15_B.temp2_d) {
                    interception_v15_B.t_a = interception_v15_B.t_a > 0.0 ? 0.5 :
                      -0.5;
                    interception_v15_B.x_im_j = interception_v15_B.x_im_j > 0.0 ?
                      0.5 : -0.5;
                    interception_v15_B.absxk_f = (interception_v15_B.ctemp_m.re *
                      interception_v15_B.t_a + interception_v15_B.ctemp_m.im *
                      interception_v15_B.x_im_j) / interception_v15_B.temp2_d;
                    interception_v15_B.t_a = (interception_v15_B.ctemp_m.im *
                      interception_v15_B.t_a - interception_v15_B.ctemp_m.re *
                      interception_v15_B.x_im_j) / interception_v15_B.temp2_d;
                  } else {
                    interception_v15_B.temp2_d = interception_v15_B.t_a /
                      interception_v15_B.x_im_j;
                    interception_v15_B.t_a = interception_v15_B.temp2_d *
                      interception_v15_B.t_a + interception_v15_B.x_im_j;
                    interception_v15_B.absxk_f = (interception_v15_B.temp2_d *
                      interception_v15_B.ctemp_m.re +
                      interception_v15_B.ctemp_m.im) / interception_v15_B.t_a;
                    interception_v15_B.t_a = (interception_v15_B.temp2_d *
                      interception_v15_B.ctemp_m.im -
                      interception_v15_B.ctemp_m.re) / interception_v15_B.t_a;
                  }
                }

                interception_v15_B.scale_e -= interception_v15_B.ctemp_m.re *
                  interception_v15_B.absxk_f - interception_v15_B.ctemp_m.im *
                  interception_v15_B.t_a;
                interception_v15_B.colscale_j -= interception_v15_B.ctemp_m.re *
                  interception_v15_B.t_a + interception_v15_B.ctemp_m.im *
                  interception_v15_B.absxk_f;
              }
            } else {
              if (iiter - div_nzp_s32(iiter, 20) * 20 == 0) {
                j = (ilast << 2) + ilast;
                interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
                interception_v15_B.absxk_f = A[j].im *
                  interception_v15_B.anorm_h;
                if (interception_v15_B.absxk_f == 0.0) {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f = 0.0;
                } else if (interception_v15_B.t_a == 0.0) {
                  interception_v15_B.t_a = 0.0;
                  interception_v15_B.absxk_f /= 0.5;
                } else {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f /= 0.5;
                }

                interception_v15_B.eshift_re_j += interception_v15_B.t_a;
                interception_v15_B.eshift_im_o += interception_v15_B.absxk_f;
              } else {
                j = (col << 2) + ilast;
                interception_v15_B.t_a = A[j].re * interception_v15_B.anorm_h;
                interception_v15_B.absxk_f = A[j].im *
                  interception_v15_B.anorm_h;
                if (interception_v15_B.absxk_f == 0.0) {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f = 0.0;
                } else if (interception_v15_B.t_a == 0.0) {
                  interception_v15_B.t_a = 0.0;
                  interception_v15_B.absxk_f /= 0.5;
                } else {
                  interception_v15_B.t_a /= 0.5;
                  interception_v15_B.absxk_f /= 0.5;
                }

                interception_v15_B.eshift_re_j += interception_v15_B.t_a;
                interception_v15_B.eshift_im_o += interception_v15_B.absxk_f;
              }

              interception_v15_B.scale_e = interception_v15_B.eshift_re_j;
              interception_v15_B.colscale_j = interception_v15_B.eshift_im_o;
            }

            j = col;
            jp1 = col + 1;
            exitg2 = false;
            while ((!exitg2) && (j + 1 > ifirst)) {
              nm1 = j + 1;
              u1_tmp_tmp = j << 2;
              ctemp_tmp = u1_tmp_tmp + j;
              interception_v15_B.ctemp_m.re = A[ctemp_tmp].re *
                interception_v15_B.anorm_h - interception_v15_B.scale_e * 0.5;
              interception_v15_B.ctemp_m.im = A[ctemp_tmp].im *
                interception_v15_B.anorm_h - interception_v15_B.colscale_j * 0.5;
              interception_v15_B.temp_b = fabs(interception_v15_B.ctemp_m.re) +
                fabs(interception_v15_B.ctemp_m.im);
              jp1 += u1_tmp_tmp;
              interception_v15_B.temp2_d = (fabs(A[jp1].re) + fabs(A[jp1].im)) *
                interception_v15_B.anorm_h;
              interception_v15_B.absxk_f = interception_v15_B.temp_b;
              if (interception_v15_B.temp2_d > interception_v15_B.temp_b) {
                interception_v15_B.absxk_f = interception_v15_B.temp2_d;
              }

              if ((interception_v15_B.absxk_f < 1.0) &&
                  (interception_v15_B.absxk_f != 0.0)) {
                interception_v15_B.temp_b /= interception_v15_B.absxk_f;
                interception_v15_B.temp2_d /= interception_v15_B.absxk_f;
              }

              jp1 = ((j - 1) << 2) + j;
              if ((fabs(A[jp1].re) + fabs(A[jp1].im)) *
                  interception_v15_B.temp2_d <= interception_v15_B.temp_b *
                  interception_v15_B.ssq_b) {
                goto90 = true;
                exitg2 = true;
              } else {
                jp1 = j;
                j--;
              }
            }

            if (!goto90) {
              nm1 = ifirst;
              ctemp_tmp = (((ifirst - 1) << 2) + ifirst) - 1;
              interception_v15_B.ctemp_m.re = A[ctemp_tmp].re *
                interception_v15_B.anorm_h - interception_v15_B.scale_e * 0.5;
              interception_v15_B.ctemp_m.im = A[ctemp_tmp].im *
                interception_v15_B.anorm_h - interception_v15_B.colscale_j * 0.5;
            }

            goto90 = false;
            j = ((nm1 - 1) << 2) + nm1;
            interception_v15_B.ascale_l.re = A[j].re *
              interception_v15_B.anorm_h;
            interception_v15_B.ascale_l.im = A[j].im *
              interception_v15_B.anorm_h;
            interception_v15_xzlartg_h(interception_v15_B.ctemp_m,
              interception_v15_B.ascale_l, &interception_v15_B.scale_e,
              &interception_v15_B.y_n);
            j = nm1;
            jp1 = nm1 - 2;
            while (j < ilast + 1) {
              int32_T stemp_tmp;
              if (j > nm1) {
                interception_v15_xzlartg(A[(j + (jp1 << 2)) - 1], A[j + (jp1 <<
                  2)], &interception_v15_B.scale_e, &interception_v15_B.y_n, &A
                  [(j + (jp1 << 2)) - 1]);
                jp1 = (jp1 << 2) + j;
                A[jp1].re = 0.0;
                A[jp1].im = 0.0;
              }

              for (jp1 = j; jp1 < 5; jp1++) {
                u1_tmp_tmp = ((jp1 - 1) << 2) + j;
                interception_v15_B.absxk_f = A[u1_tmp_tmp].im;
                interception_v15_B.colscale_j = A[u1_tmp_tmp].re;
                interception_v15_B.t_a = A[u1_tmp_tmp - 1].re;
                interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                  interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                  interception_v15_B.y_n.im) + interception_v15_B.t_a *
                  interception_v15_B.scale_e;
                interception_v15_B.x_im_j = A[u1_tmp_tmp - 1].im;
                interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                  interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                  interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                  interception_v15_B.scale_e;
                A[u1_tmp_tmp].re = interception_v15_B.colscale_j *
                  interception_v15_B.scale_e - (interception_v15_B.t_a *
                  interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                  interception_v15_B.y_n.im);
                A[u1_tmp_tmp].im = A[u1_tmp_tmp].im * interception_v15_B.scale_e
                  - (interception_v15_B.y_n.re * interception_v15_B.x_im_j -
                     interception_v15_B.y_n.im * interception_v15_B.t_a);
                A[u1_tmp_tmp - 1] = interception_v15_B.stemp_p;
              }

              interception_v15_B.y_n.re = -interception_v15_B.y_n.re;
              interception_v15_B.y_n.im = -interception_v15_B.y_n.im;
              ctemp_tmp = j;
              if (ilast + 1 < j + 2) {
                ctemp_tmp = ilast - 1;
              }

              for (jp1 = 1; jp1 <= ctemp_tmp + 2; jp1++) {
                u1_tmp_tmp = (((j - 1) << 2) + jp1) - 1;
                interception_v15_B.absxk_f = A[u1_tmp_tmp].im;
                interception_v15_B.colscale_j = A[u1_tmp_tmp].re;
                stemp_tmp = ((j << 2) + jp1) - 1;
                interception_v15_B.t_a = A[stemp_tmp].re;
                interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                  interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                  interception_v15_B.y_n.im) + interception_v15_B.t_a *
                  interception_v15_B.scale_e;
                interception_v15_B.x_im_j = A[stemp_tmp].im;
                interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                  interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                  interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                  interception_v15_B.scale_e;
                A[u1_tmp_tmp].re = interception_v15_B.colscale_j *
                  interception_v15_B.scale_e - (interception_v15_B.t_a *
                  interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                  interception_v15_B.y_n.im);
                A[u1_tmp_tmp].im = A[u1_tmp_tmp].im * interception_v15_B.scale_e
                  - (interception_v15_B.y_n.re * interception_v15_B.x_im_j -
                     interception_v15_B.y_n.im * interception_v15_B.t_a);
                A[stemp_tmp] = interception_v15_B.stemp_p;
              }

              u1_tmp_tmp = (j - 1) << 2;
              interception_v15_B.absxk_f = Z[u1_tmp_tmp].im;
              interception_v15_B.colscale_j = Z[u1_tmp_tmp].re;
              stemp_tmp = j << 2;
              interception_v15_B.t_a = Z[stemp_tmp].re;
              interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                interception_v15_B.y_n.im) + interception_v15_B.t_a *
                interception_v15_B.scale_e;
              interception_v15_B.x_im_j = Z[stemp_tmp].im;
              interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                interception_v15_B.scale_e;
              Z[u1_tmp_tmp].re = interception_v15_B.colscale_j *
                interception_v15_B.scale_e - (interception_v15_B.t_a *
                interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                interception_v15_B.y_n.im);
              Z[u1_tmp_tmp].im = Z[u1_tmp_tmp].im * interception_v15_B.scale_e -
                (interception_v15_B.y_n.re * interception_v15_B.x_im_j -
                 interception_v15_B.y_n.im * interception_v15_B.t_a);
              Z[stemp_tmp] = interception_v15_B.stemp_p;
              interception_v15_B.absxk_f = Z[u1_tmp_tmp + 1].im;
              interception_v15_B.colscale_j = Z[u1_tmp_tmp + 1].re;
              interception_v15_B.t_a = Z[stemp_tmp + 1].re;
              interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                interception_v15_B.y_n.im) + interception_v15_B.t_a *
                interception_v15_B.scale_e;
              interception_v15_B.x_im_j = Z[stemp_tmp + 1].im;
              interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                interception_v15_B.scale_e;
              Z[u1_tmp_tmp + 1].re = interception_v15_B.colscale_j *
                interception_v15_B.scale_e - (interception_v15_B.t_a *
                interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                interception_v15_B.y_n.im);
              Z[u1_tmp_tmp + 1].im = Z[u1_tmp_tmp + 1].im *
                interception_v15_B.scale_e - (interception_v15_B.y_n.re *
                interception_v15_B.x_im_j - interception_v15_B.y_n.im *
                interception_v15_B.t_a);
              Z[stemp_tmp + 1] = interception_v15_B.stemp_p;
              interception_v15_B.absxk_f = Z[u1_tmp_tmp + 2].im;
              interception_v15_B.colscale_j = Z[u1_tmp_tmp + 2].re;
              interception_v15_B.t_a = Z[stemp_tmp + 2].re;
              interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                interception_v15_B.y_n.im) + interception_v15_B.t_a *
                interception_v15_B.scale_e;
              interception_v15_B.x_im_j = Z[stemp_tmp + 2].im;
              interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                interception_v15_B.scale_e;
              Z[u1_tmp_tmp + 2].re = interception_v15_B.colscale_j *
                interception_v15_B.scale_e - (interception_v15_B.t_a *
                interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                interception_v15_B.y_n.im);
              Z[u1_tmp_tmp + 2].im = Z[u1_tmp_tmp + 2].im *
                interception_v15_B.scale_e - (interception_v15_B.y_n.re *
                interception_v15_B.x_im_j - interception_v15_B.y_n.im *
                interception_v15_B.t_a);
              Z[stemp_tmp + 2] = interception_v15_B.stemp_p;
              interception_v15_B.absxk_f = Z[u1_tmp_tmp + 3].im;
              interception_v15_B.colscale_j = Z[u1_tmp_tmp + 3].re;
              interception_v15_B.t_a = Z[stemp_tmp + 3].re;
              interception_v15_B.stemp_p.re = (interception_v15_B.colscale_j *
                interception_v15_B.y_n.re - interception_v15_B.absxk_f *
                interception_v15_B.y_n.im) + interception_v15_B.t_a *
                interception_v15_B.scale_e;
              interception_v15_B.x_im_j = Z[stemp_tmp + 3].im;
              interception_v15_B.stemp_p.im = (interception_v15_B.absxk_f *
                interception_v15_B.y_n.re + interception_v15_B.colscale_j *
                interception_v15_B.y_n.im) + interception_v15_B.x_im_j *
                interception_v15_B.scale_e;
              Z[u1_tmp_tmp + 3].re = interception_v15_B.colscale_j *
                interception_v15_B.scale_e - (interception_v15_B.t_a *
                interception_v15_B.y_n.re + interception_v15_B.x_im_j *
                interception_v15_B.y_n.im);
              Z[u1_tmp_tmp + 3].im = Z[u1_tmp_tmp + 3].im *
                interception_v15_B.scale_e - (interception_v15_B.y_n.re *
                interception_v15_B.x_im_j - interception_v15_B.y_n.im *
                interception_v15_B.t_a);
              Z[stemp_tmp + 3] = interception_v15_B.stemp_p;
              jp1 = j - 1;
              j++;
            }
          }

          absxk_tmp++;
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (ifirst = 0; ifirst <= ilast; ifirst++) {
        alpha1[ifirst].re = (rtNaN);
        alpha1[ifirst].im = 0.0;
        beta1[ifirst].re = (rtNaN);
        beta1[ifirst].im = 0.0;
      }

      for (jp1 = 0; jp1 < 16; jp1++) {
        Z[jp1].re = (rtNaN);
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    ifirst = static_cast<uint8_T>(ilo - 1);
    for (ilast = 0; ilast < ifirst; ilast++) {
      alpha1[ilast] = A[(ilast << 2) + ilast];
    }
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xztgevc(const creal_T A[16], creal_T V[16])
{
  int32_T i;
  int32_T rworka_tmp;
  interception_v15_B.rworka[0] = 0.0;
  interception_v15_B.rworka[1] = 0.0;
  interception_v15_B.rworka[2] = 0.0;
  interception_v15_B.rworka[3] = 0.0;
  interception_v15_B.anorm_c = fabs(A[0].re) + fabs(A[0].im);
  for (int32_T j = 0; j < 3; j++) {
    for (i = 0; i <= j; i++) {
      rworka_tmp = ((j + 1) << 2) + i;
      interception_v15_B.rworka[j + 1] += fabs(A[rworka_tmp].re) + fabs
        (A[rworka_tmp].im);
    }

    i = (((j + 1) << 2) + j) + 1;
    interception_v15_B.ascale_p = (fabs(A[i].re) + fabs(A[i].im)) +
      interception_v15_B.rworka[j + 1];
    if (interception_v15_B.ascale_p > interception_v15_B.anorm_c) {
      interception_v15_B.anorm_c = interception_v15_B.ascale_p;
    }
  }

  interception_v15_B.ascale_p = interception_v15_B.anorm_c;
  if (interception_v15_B.anorm_c < 2.2250738585072014E-308) {
    interception_v15_B.ascale_p = 2.2250738585072014E-308;
  }

  interception_v15_B.ascale_p = 1.0 / interception_v15_B.ascale_p;
  for (int32_T j = 3; j >= 0; j--) {
    real_T bim;
    int32_T d_re_tmp_tmp;
    boolean_T lscalea;
    boolean_T lscaleb;
    i = j << 2;
    rworka_tmp = i + j;
    interception_v15_B.salpha_re = A[rworka_tmp].re;
    interception_v15_B.salpha_im = A[rworka_tmp].im;
    interception_v15_B.acoeff = (fabs(interception_v15_B.salpha_re) + fabs
      (interception_v15_B.salpha_im)) * interception_v15_B.ascale_p;
    if (interception_v15_B.acoeff < 1.0) {
      interception_v15_B.acoeff = 1.0;
    }

    interception_v15_B.temp_p = 1.0 / interception_v15_B.acoeff;
    interception_v15_B.salpha_re = interception_v15_B.salpha_re *
      interception_v15_B.temp_p * interception_v15_B.ascale_p;
    interception_v15_B.salpha_im = interception_v15_B.salpha_im *
      interception_v15_B.temp_p * interception_v15_B.ascale_p;
    interception_v15_B.acoeff = interception_v15_B.temp_p *
      interception_v15_B.ascale_p;
    lscalea = ((interception_v15_B.temp_p >= 2.2250738585072014E-308) &&
               (interception_v15_B.acoeff < 4.0083367200179456E-292));
    interception_v15_B.dmin = fabs(interception_v15_B.salpha_re) + fabs
      (interception_v15_B.salpha_im);
    lscaleb = ((interception_v15_B.dmin >= 2.2250738585072014E-308) &&
               (interception_v15_B.dmin < 4.0083367200179456E-292));
    interception_v15_B.scale_a = 1.0;
    if (lscalea) {
      interception_v15_B.scale_a = interception_v15_B.anorm_c;
      if (interception_v15_B.anorm_c > 2.4948003869184E+291) {
        interception_v15_B.scale_a = 2.4948003869184E+291;
      }

      interception_v15_B.scale_a *= 4.0083367200179456E-292 /
        interception_v15_B.temp_p;
    }

    if (lscaleb) {
      interception_v15_B.d_re = 4.0083367200179456E-292 /
        interception_v15_B.dmin;
      if (interception_v15_B.d_re > interception_v15_B.scale_a) {
        interception_v15_B.scale_a = interception_v15_B.d_re;
      }
    }

    if (lscalea || lscaleb) {
      interception_v15_B.d_re = interception_v15_B.acoeff;
      if (interception_v15_B.acoeff < 1.0) {
        interception_v15_B.d_re = 1.0;
      }

      if (interception_v15_B.dmin > interception_v15_B.d_re) {
        interception_v15_B.d_re = interception_v15_B.dmin;
      }

      interception_v15_B.dmin = 1.0 / (2.2250738585072014E-308 *
        interception_v15_B.d_re);
      if (interception_v15_B.dmin < interception_v15_B.scale_a) {
        interception_v15_B.scale_a = interception_v15_B.dmin;
      }

      if (lscalea) {
        interception_v15_B.acoeff = interception_v15_B.scale_a *
          interception_v15_B.temp_p * interception_v15_B.ascale_p;
      } else {
        interception_v15_B.acoeff *= interception_v15_B.scale_a;
      }

      interception_v15_B.salpha_re *= interception_v15_B.scale_a;
      interception_v15_B.salpha_im *= interception_v15_B.scale_a;
    }

    memset(&interception_v15_B.work1[0], 0, sizeof(creal_T) << 2U);
    interception_v15_B.work1[j].re = 1.0;
    interception_v15_B.work1[j].im = 0.0;
    interception_v15_B.dmin = 2.2204460492503131E-16 * interception_v15_B.acoeff
      * interception_v15_B.anorm_c;
    interception_v15_B.temp_p = (fabs(interception_v15_B.salpha_re) + fabs
      (interception_v15_B.salpha_im)) * 2.2204460492503131E-16;
    if (interception_v15_B.temp_p > interception_v15_B.dmin) {
      interception_v15_B.dmin = interception_v15_B.temp_p;
    }

    if (interception_v15_B.dmin < 2.2250738585072014E-308) {
      interception_v15_B.dmin = 2.2250738585072014E-308;
    }

    for (rworka_tmp = 0; rworka_tmp < j; rworka_tmp++) {
      d_re_tmp_tmp = i + rworka_tmp;
      interception_v15_B.work1[rworka_tmp].re = A[d_re_tmp_tmp].re *
        interception_v15_B.acoeff;
      interception_v15_B.work1[rworka_tmp].im = A[d_re_tmp_tmp].im *
        interception_v15_B.acoeff;
    }

    interception_v15_B.work1[j].re = 1.0;
    interception_v15_B.work1[j].im = 0.0;
    for (rworka_tmp = j; rworka_tmp >= 1; rworka_tmp--) {
      int32_T d_re_tmp;
      d_re_tmp_tmp = (rworka_tmp - 1) << 2;
      d_re_tmp = (d_re_tmp_tmp + rworka_tmp) - 1;
      interception_v15_B.d_re = A[d_re_tmp].re * interception_v15_B.acoeff -
        interception_v15_B.salpha_re;
      interception_v15_B.scale_a = A[d_re_tmp].im * interception_v15_B.acoeff -
        interception_v15_B.salpha_im;
      if (fabs(interception_v15_B.d_re) + fabs(interception_v15_B.scale_a) <=
          interception_v15_B.dmin) {
        interception_v15_B.d_re = interception_v15_B.dmin;
        interception_v15_B.scale_a = 0.0;
      }

      interception_v15_B.work2_idx_3_re = fabs(interception_v15_B.d_re);
      bim = fabs(interception_v15_B.scale_a);
      interception_v15_B.temp_p = interception_v15_B.work2_idx_3_re + bim;
      if (interception_v15_B.temp_p < 1.0) {
        interception_v15_B.work2_idx_3_im = fabs
          (interception_v15_B.work1[rworka_tmp - 1].re) + fabs
          (interception_v15_B.work1[rworka_tmp - 1].im);
        if (interception_v15_B.work2_idx_3_im >= interception_v15_B.temp_p *
            1.1235582092889474E+307) {
          interception_v15_B.temp_p = 1.0 / interception_v15_B.work2_idx_3_im;
          for (d_re_tmp = 0; d_re_tmp <= j; d_re_tmp++) {
            interception_v15_B.work1_j = interception_v15_B.work1[d_re_tmp];
            interception_v15_B.work1_j.re *= interception_v15_B.temp_p;
            interception_v15_B.work1_j.im *= interception_v15_B.temp_p;
            interception_v15_B.work1[d_re_tmp] = interception_v15_B.work1_j;
          }
        }
      }

      interception_v15_B.temp_p = interception_v15_B.work1[rworka_tmp - 1].re;
      interception_v15_B.work2_idx_3_im = interception_v15_B.work1[rworka_tmp -
        1].im;
      if (interception_v15_B.scale_a == 0.0) {
        if (-interception_v15_B.work2_idx_3_im == 0.0) {
          interception_v15_B.work1[rworka_tmp - 1].re =
            -interception_v15_B.temp_p / interception_v15_B.d_re;
          interception_v15_B.work1[rworka_tmp - 1].im = 0.0;
        } else if (-interception_v15_B.temp_p == 0.0) {
          interception_v15_B.work1[rworka_tmp - 1].re = 0.0;
          interception_v15_B.work1[rworka_tmp - 1].im =
            -interception_v15_B.work2_idx_3_im / interception_v15_B.d_re;
        } else {
          interception_v15_B.work1[rworka_tmp - 1].re =
            -interception_v15_B.temp_p / interception_v15_B.d_re;
          interception_v15_B.work1[rworka_tmp - 1].im =
            -interception_v15_B.work2_idx_3_im / interception_v15_B.d_re;
        }
      } else if (interception_v15_B.d_re == 0.0) {
        if (-interception_v15_B.temp_p == 0.0) {
          interception_v15_B.work1[rworka_tmp - 1].re =
            -interception_v15_B.work2_idx_3_im / interception_v15_B.scale_a;
          interception_v15_B.work1[rworka_tmp - 1].im = 0.0;
        } else if (-interception_v15_B.work2_idx_3_im == 0.0) {
          interception_v15_B.work1[rworka_tmp - 1].re = 0.0;
          interception_v15_B.work1[rworka_tmp - 1].im =
            -(-interception_v15_B.temp_p / interception_v15_B.scale_a);
        } else {
          interception_v15_B.work1[rworka_tmp - 1].re =
            -interception_v15_B.work2_idx_3_im / interception_v15_B.scale_a;
          interception_v15_B.work1[rworka_tmp - 1].im =
            -(-interception_v15_B.temp_p / interception_v15_B.scale_a);
        }
      } else if (interception_v15_B.work2_idx_3_re > bim) {
        interception_v15_B.work2_idx_3_re = interception_v15_B.scale_a /
          interception_v15_B.d_re;
        interception_v15_B.scale_a = interception_v15_B.work2_idx_3_re *
          interception_v15_B.scale_a + interception_v15_B.d_re;
        interception_v15_B.work1[rworka_tmp - 1].re =
          (interception_v15_B.work2_idx_3_re *
           -interception_v15_B.work2_idx_3_im - interception_v15_B.temp_p) /
          interception_v15_B.scale_a;
        interception_v15_B.work1[rworka_tmp - 1].im =
          (-interception_v15_B.work2_idx_3_im -
           interception_v15_B.work2_idx_3_re * -interception_v15_B.temp_p) /
          interception_v15_B.scale_a;
      } else if (bim == interception_v15_B.work2_idx_3_re) {
        interception_v15_B.d_re = interception_v15_B.d_re > 0.0 ? 0.5 : -0.5;
        interception_v15_B.scale_a = interception_v15_B.scale_a > 0.0 ? 0.5 :
          -0.5;
        interception_v15_B.work1[rworka_tmp - 1].re =
          (-interception_v15_B.temp_p * interception_v15_B.d_re +
           -interception_v15_B.work2_idx_3_im * interception_v15_B.scale_a) /
          interception_v15_B.work2_idx_3_re;
        interception_v15_B.work1[rworka_tmp - 1].im =
          (-interception_v15_B.work2_idx_3_im * interception_v15_B.d_re -
           -interception_v15_B.temp_p * interception_v15_B.scale_a) /
          interception_v15_B.work2_idx_3_re;
      } else {
        interception_v15_B.work2_idx_3_re = interception_v15_B.d_re /
          interception_v15_B.scale_a;
        interception_v15_B.scale_a += interception_v15_B.work2_idx_3_re *
          interception_v15_B.d_re;
        interception_v15_B.work1[rworka_tmp - 1].re =
          (interception_v15_B.work2_idx_3_re * -interception_v15_B.temp_p -
           interception_v15_B.work2_idx_3_im) / interception_v15_B.scale_a;
        interception_v15_B.work1[rworka_tmp - 1].im =
          (interception_v15_B.work2_idx_3_re *
           -interception_v15_B.work2_idx_3_im - (-interception_v15_B.temp_p)) /
          interception_v15_B.scale_a;
      }

      if (rworka_tmp > 1) {
        if (fabs(interception_v15_B.work1[rworka_tmp - 1].re) + fabs
            (interception_v15_B.work1[rworka_tmp - 1].im) > 1.0) {
          interception_v15_B.temp_p = 1.0 / (fabs
            (interception_v15_B.work1[rworka_tmp - 1].re) + fabs
            (interception_v15_B.work1[rworka_tmp - 1].im));
          if (interception_v15_B.rworka[rworka_tmp - 1] *
              interception_v15_B.acoeff >= 1.1235582092889474E+307 *
              interception_v15_B.temp_p) {
            for (d_re_tmp = 0; d_re_tmp <= j; d_re_tmp++) {
              interception_v15_B.work1_j = interception_v15_B.work1[d_re_tmp];
              interception_v15_B.work1_j.re *= interception_v15_B.temp_p;
              interception_v15_B.work1_j.im *= interception_v15_B.temp_p;
              interception_v15_B.work1[d_re_tmp] = interception_v15_B.work1_j;
            }
          }
        }

        interception_v15_B.d_re = interception_v15_B.work1[rworka_tmp - 1].re *
          interception_v15_B.acoeff;
        interception_v15_B.scale_a = interception_v15_B.work1[rworka_tmp - 1].im
          * interception_v15_B.acoeff;
        for (d_re_tmp = 0; d_re_tmp <= rworka_tmp - 2; d_re_tmp++) {
          int32_T work1_tmp;
          interception_v15_B.work1_j = interception_v15_B.work1[d_re_tmp];
          work1_tmp = d_re_tmp_tmp + d_re_tmp;
          interception_v15_B.temp_p = A[work1_tmp].im;
          interception_v15_B.work2_idx_3_re = A[work1_tmp].re;
          interception_v15_B.work1_j.re += interception_v15_B.work2_idx_3_re *
            interception_v15_B.d_re - interception_v15_B.temp_p *
            interception_v15_B.scale_a;
          interception_v15_B.work1_j.im += interception_v15_B.temp_p *
            interception_v15_B.d_re + interception_v15_B.work2_idx_3_re *
            interception_v15_B.scale_a;
          interception_v15_B.work1[d_re_tmp] = interception_v15_B.work1_j;
        }
      }
    }

    interception_v15_B.salpha_re = 0.0;
    interception_v15_B.salpha_im = 0.0;
    interception_v15_B.acoeff = 0.0;
    interception_v15_B.dmin = 0.0;
    interception_v15_B.scale_a = 0.0;
    interception_v15_B.d_re = 0.0;
    interception_v15_B.work2_idx_3_re = 0.0;
    interception_v15_B.work2_idx_3_im = 0.0;
    for (rworka_tmp = 0; rworka_tmp <= j; rworka_tmp++) {
      real_T work2_idx_0_re_tmp;
      real_T work2_idx_0_re_tmp_0;
      d_re_tmp_tmp = rworka_tmp << 2;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp].re;
      interception_v15_B.temp_p = interception_v15_B.work1[rworka_tmp].im;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp].im;
      bim = interception_v15_B.work1[rworka_tmp].re;
      interception_v15_B.salpha_re += work2_idx_0_re_tmp * bim -
        work2_idx_0_re_tmp_0 * interception_v15_B.temp_p;
      interception_v15_B.salpha_im += work2_idx_0_re_tmp *
        interception_v15_B.temp_p + work2_idx_0_re_tmp_0 * bim;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 1].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 1].im;
      interception_v15_B.acoeff += work2_idx_0_re_tmp * bim -
        work2_idx_0_re_tmp_0 * interception_v15_B.temp_p;
      interception_v15_B.dmin += work2_idx_0_re_tmp * interception_v15_B.temp_p
        + work2_idx_0_re_tmp_0 * bim;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 2].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 2].im;
      interception_v15_B.scale_a += work2_idx_0_re_tmp * bim -
        work2_idx_0_re_tmp_0 * interception_v15_B.temp_p;
      interception_v15_B.d_re += work2_idx_0_re_tmp * interception_v15_B.temp_p
        + work2_idx_0_re_tmp_0 * bim;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 3].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 3].im;
      interception_v15_B.work2_idx_3_re += work2_idx_0_re_tmp * bim -
        work2_idx_0_re_tmp_0 * interception_v15_B.temp_p;
      interception_v15_B.work2_idx_3_im += work2_idx_0_re_tmp *
        interception_v15_B.temp_p + work2_idx_0_re_tmp_0 * bim;
    }

    interception_v15_B.temp_p = fabs(interception_v15_B.salpha_re) + fabs
      (interception_v15_B.salpha_im);
    bim = fabs(interception_v15_B.acoeff) + fabs(interception_v15_B.dmin);
    if (bim > interception_v15_B.temp_p) {
      interception_v15_B.temp_p = bim;
    }

    bim = fabs(interception_v15_B.scale_a) + fabs(interception_v15_B.d_re);
    if (bim > interception_v15_B.temp_p) {
      interception_v15_B.temp_p = bim;
    }

    bim = fabs(interception_v15_B.work2_idx_3_re) + fabs
      (interception_v15_B.work2_idx_3_im);
    if (bim > interception_v15_B.temp_p) {
      interception_v15_B.temp_p = bim;
    }

    if (interception_v15_B.temp_p > 2.2250738585072014E-308) {
      interception_v15_B.temp_p = 1.0 / interception_v15_B.temp_p;
      V[i].re = interception_v15_B.temp_p * interception_v15_B.salpha_re;
      V[i].im = interception_v15_B.temp_p * interception_v15_B.salpha_im;
      d_re_tmp_tmp = (j << 2) + 1;
      V[d_re_tmp_tmp].re = interception_v15_B.temp_p * interception_v15_B.acoeff;
      V[d_re_tmp_tmp].im = interception_v15_B.temp_p * interception_v15_B.dmin;
      d_re_tmp_tmp = (j << 2) + 2;
      V[d_re_tmp_tmp].re = interception_v15_B.temp_p *
        interception_v15_B.scale_a;
      V[d_re_tmp_tmp].im = interception_v15_B.temp_p * interception_v15_B.d_re;
      d_re_tmp_tmp = (j << 2) + 3;
      V[d_re_tmp_tmp].re = interception_v15_B.temp_p *
        interception_v15_B.work2_idx_3_re;
      V[d_re_tmp_tmp].im = interception_v15_B.temp_p *
        interception_v15_B.work2_idx_3_im;
    } else {
      V[i].re = 0.0;
      V[i].im = 0.0;
      V[i + 1].re = 0.0;
      V[i + 1].im = 0.0;
      V[i + 2].re = 0.0;
      V[i + 2].im = 0.0;
      V[i + 3].re = 0.0;
      V[i + 3].im = 0.0;
    }
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xzgeev(const real_T A[16], int32_T *info, creal_T
  alpha1[4], creal_T beta1[4], creal_T V[16])
{
  boolean_T exitg1;
  for (interception_v15_B.g_k = 0; interception_v15_B.g_k < 16;
       interception_v15_B.g_k++) {
    interception_v15_B.At[interception_v15_B.g_k].re = A[interception_v15_B.g_k];
    interception_v15_B.At[interception_v15_B.g_k].im = 0.0;
  }

  *info = 0;
  interception_v15_B.anrm_o = 0.0;
  interception_v15_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (interception_v15_B.b_k < 16)) {
    interception_v15_B.b_absxk = interception_v15_rt_hypotd_snf
      (interception_v15_B.At[interception_v15_B.b_k].re,
       interception_v15_B.At[interception_v15_B.b_k].im);
    if (rtIsNaN(interception_v15_B.b_absxk)) {
      interception_v15_B.anrm_o = (rtNaN);
      exitg1 = true;
    } else {
      if (interception_v15_B.b_absxk > interception_v15_B.anrm_o) {
        interception_v15_B.anrm_o = interception_v15_B.b_absxk;
      }

      interception_v15_B.b_k++;
    }
  }

  if (rtIsInf(interception_v15_B.anrm_o) || rtIsNaN(interception_v15_B.anrm_o))
  {
    alpha1[0].re = (rtNaN);
    alpha1[0].im = 0.0;
    beta1[0].re = (rtNaN);
    beta1[0].im = 0.0;
    alpha1[1].re = (rtNaN);
    alpha1[1].im = 0.0;
    beta1[1].re = (rtNaN);
    beta1[1].im = 0.0;
    alpha1[2].re = (rtNaN);
    alpha1[2].im = 0.0;
    beta1[2].re = (rtNaN);
    beta1[2].im = 0.0;
    alpha1[3].re = (rtNaN);
    alpha1[3].im = 0.0;
    beta1[3].re = (rtNaN);
    beta1[3].im = 0.0;
    for (interception_v15_B.g_k = 0; interception_v15_B.g_k < 16;
         interception_v15_B.g_k++) {
      V[interception_v15_B.g_k].re = (rtNaN);
      V[interception_v15_B.g_k].im = 0.0;
    }
  } else {
    int32_T exitg3;
    boolean_T exitg4;
    boolean_T guard1 = false;
    boolean_T ilascl;
    boolean_T notdone;
    ilascl = false;
    interception_v15_B.b_absxk = interception_v15_B.anrm_o;
    guard1 = false;
    if ((interception_v15_B.anrm_o > 0.0) && (interception_v15_B.anrm_o <
         6.7178761075670888E-139)) {
      interception_v15_B.b_absxk = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else if (interception_v15_B.anrm_o > 1.4885657073574029E+138) {
      interception_v15_B.b_absxk = 1.4885657073574029E+138;
      ilascl = true;
      guard1 = true;
    }

    if (guard1) {
      interception_v15_B.cfromc_b = interception_v15_B.anrm_o;
      interception_v15_B.ctoc_n = interception_v15_B.b_absxk;
      notdone = true;
      while (notdone) {
        interception_v15_B.vtemp = interception_v15_B.cfromc_b *
          2.0041683600089728E-292;
        interception_v15_B.cto1_b = interception_v15_B.ctoc_n /
          4.9896007738368E+291;
        if ((interception_v15_B.vtemp > interception_v15_B.ctoc_n) &&
            (interception_v15_B.ctoc_n != 0.0)) {
          interception_v15_B.stemp_im_tmp_l = 2.0041683600089728E-292;
          interception_v15_B.cfromc_b = interception_v15_B.vtemp;
        } else if (interception_v15_B.cto1_b > interception_v15_B.cfromc_b) {
          interception_v15_B.stemp_im_tmp_l = 4.9896007738368E+291;
          interception_v15_B.ctoc_n = interception_v15_B.cto1_b;
        } else {
          interception_v15_B.stemp_im_tmp_l = interception_v15_B.ctoc_n /
            interception_v15_B.cfromc_b;
          notdone = false;
        }

        for (interception_v15_B.g_k = 0; interception_v15_B.g_k < 16;
             interception_v15_B.g_k++) {
          interception_v15_B.atmp_g =
            interception_v15_B.At[interception_v15_B.g_k];
          interception_v15_B.atmp_g.re *= interception_v15_B.stemp_im_tmp_l;
          interception_v15_B.atmp_g.im *= interception_v15_B.stemp_im_tmp_l;
          interception_v15_B.At[interception_v15_B.g_k] =
            interception_v15_B.atmp_g;
        }
      }
    }

    interception_v15_B.rscale[0] = 1;
    interception_v15_B.rscale[1] = 1;
    interception_v15_B.rscale[2] = 1;
    interception_v15_B.rscale[3] = 1;
    interception_v15_B.e_i = 1;
    interception_v15_B.b_k = 4;
    do {
      exitg3 = 0;
      interception_v15_B.jrow = 0;
      interception_v15_B.jcol_l = 0;
      notdone = false;
      interception_v15_B.ii_g = interception_v15_B.b_k;
      exitg1 = false;
      while ((!exitg1) && (interception_v15_B.ii_g > 0)) {
        interception_v15_B.nzcount_c = 0;
        interception_v15_B.jrow = interception_v15_B.ii_g;
        interception_v15_B.jcol_l = interception_v15_B.b_k;
        interception_v15_B.jj_o = 0;
        exitg4 = false;
        while ((!exitg4) && (interception_v15_B.jj_o <= static_cast<uint8_T>
                             (interception_v15_B.b_k) - 1)) {
          interception_v15_B.g_k = ((interception_v15_B.jj_o << 2) +
            interception_v15_B.ii_g) - 1;
          if ((interception_v15_B.At[interception_v15_B.g_k].re != 0.0) ||
              (interception_v15_B.At[interception_v15_B.g_k].im != 0.0) ||
              (interception_v15_B.jj_o + 1 == interception_v15_B.ii_g)) {
            if (interception_v15_B.nzcount_c == 0) {
              interception_v15_B.jcol_l = interception_v15_B.jj_o + 1;
              interception_v15_B.nzcount_c = 1;
              interception_v15_B.jj_o++;
            } else {
              interception_v15_B.nzcount_c = 2;
              exitg4 = true;
            }
          } else {
            interception_v15_B.jj_o++;
          }
        }

        if (interception_v15_B.nzcount_c < 2) {
          notdone = true;
          exitg1 = true;
        } else {
          interception_v15_B.ii_g--;
        }
      }

      if (!notdone) {
        exitg3 = 2;
      } else {
        if (interception_v15_B.jrow != interception_v15_B.b_k) {
          interception_v15_B.atmp_g =
            interception_v15_B.At[interception_v15_B.jrow - 1];
          interception_v15_B.At[interception_v15_B.jrow - 1] =
            interception_v15_B.At[interception_v15_B.b_k - 1];
          interception_v15_B.At[interception_v15_B.b_k - 1] =
            interception_v15_B.atmp_g;
          interception_v15_B.atmp_g =
            interception_v15_B.At[interception_v15_B.jrow + 3];
          interception_v15_B.At[interception_v15_B.jrow + 3] =
            interception_v15_B.At[interception_v15_B.b_k + 3];
          interception_v15_B.At[interception_v15_B.b_k + 3] =
            interception_v15_B.atmp_g;
          interception_v15_B.atmp_g =
            interception_v15_B.At[interception_v15_B.jrow + 7];
          interception_v15_B.At[interception_v15_B.jrow + 7] =
            interception_v15_B.At[interception_v15_B.b_k + 7];
          interception_v15_B.At[interception_v15_B.b_k + 7] =
            interception_v15_B.atmp_g;
          interception_v15_B.atmp_g =
            interception_v15_B.At[interception_v15_B.jrow + 11];
          interception_v15_B.At[interception_v15_B.jrow + 11] =
            interception_v15_B.At[interception_v15_B.b_k + 11];
          interception_v15_B.At[interception_v15_B.b_k + 11] =
            interception_v15_B.atmp_g;
        }

        if (interception_v15_B.jcol_l != interception_v15_B.b_k) {
          for (interception_v15_B.jrow = 0; interception_v15_B.jrow <
               interception_v15_B.b_k; interception_v15_B.jrow++) {
            interception_v15_B.g_k = ((interception_v15_B.jcol_l - 1) << 2) +
              interception_v15_B.jrow;
            interception_v15_B.atmp_g =
              interception_v15_B.At[interception_v15_B.g_k];
            interception_v15_B.ii_g = ((interception_v15_B.b_k - 1) << 2) +
              interception_v15_B.jrow;
            interception_v15_B.At[interception_v15_B.g_k] =
              interception_v15_B.At[interception_v15_B.ii_g];
            interception_v15_B.At[interception_v15_B.ii_g] =
              interception_v15_B.atmp_g;
          }
        }

        interception_v15_B.rscale[interception_v15_B.b_k - 1] =
          interception_v15_B.jcol_l;
        interception_v15_B.b_k--;
        if (interception_v15_B.b_k == 1) {
          interception_v15_B.rscale[0] = 1;
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
    } else {
      int32_T exitg2;
      do {
        exitg2 = 0;
        interception_v15_B.jrow = 0;
        interception_v15_B.jcol_l = 0;
        notdone = false;
        interception_v15_B.ii_g = interception_v15_B.e_i;
        exitg1 = false;
        while ((!exitg1) && (interception_v15_B.ii_g <= interception_v15_B.b_k))
        {
          interception_v15_B.nzcount_c = 0;
          interception_v15_B.jrow = interception_v15_B.b_k;
          interception_v15_B.jcol_l = interception_v15_B.ii_g;
          interception_v15_B.jj_o = interception_v15_B.e_i;
          exitg4 = false;
          while ((!exitg4) && (interception_v15_B.jj_o <= interception_v15_B.b_k))
          {
            interception_v15_B.g_k = (((interception_v15_B.ii_g - 1) << 2) +
              interception_v15_B.jj_o) - 1;
            if ((interception_v15_B.At[interception_v15_B.g_k].re != 0.0) ||
                (interception_v15_B.At[interception_v15_B.g_k].im != 0.0) ||
                (interception_v15_B.jj_o == interception_v15_B.ii_g)) {
              if (interception_v15_B.nzcount_c == 0) {
                interception_v15_B.jrow = interception_v15_B.jj_o;
                interception_v15_B.nzcount_c = 1;
                interception_v15_B.jj_o++;
              } else {
                interception_v15_B.nzcount_c = 2;
                exitg4 = true;
              }
            } else {
              interception_v15_B.jj_o++;
            }
          }

          if (interception_v15_B.nzcount_c < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            interception_v15_B.ii_g++;
          }
        }

        if (!notdone) {
          exitg2 = 1;
        } else {
          if (interception_v15_B.jrow != interception_v15_B.e_i) {
            for (interception_v15_B.nzcount_c = interception_v15_B.e_i;
                 interception_v15_B.nzcount_c < 5; interception_v15_B.nzcount_c
                 ++) {
              interception_v15_B.g_k = (interception_v15_B.nzcount_c - 1) << 2;
              interception_v15_B.jj_o = (interception_v15_B.g_k +
                interception_v15_B.jrow) - 1;
              interception_v15_B.atmp_g =
                interception_v15_B.At[interception_v15_B.jj_o];
              interception_v15_B.ii_g = (interception_v15_B.g_k +
                interception_v15_B.e_i) - 1;
              interception_v15_B.At[interception_v15_B.jj_o] =
                interception_v15_B.At[interception_v15_B.ii_g];
              interception_v15_B.At[interception_v15_B.ii_g] =
                interception_v15_B.atmp_g;
            }
          }

          if (interception_v15_B.jcol_l != interception_v15_B.e_i) {
            for (interception_v15_B.jrow = 0; interception_v15_B.jrow <
                 interception_v15_B.b_k; interception_v15_B.jrow++) {
              interception_v15_B.g_k = ((interception_v15_B.jcol_l - 1) << 2) +
                interception_v15_B.jrow;
              interception_v15_B.atmp_g =
                interception_v15_B.At[interception_v15_B.g_k];
              interception_v15_B.ii_g = ((interception_v15_B.e_i - 1) << 2) +
                interception_v15_B.jrow;
              interception_v15_B.At[interception_v15_B.g_k] =
                interception_v15_B.At[interception_v15_B.ii_g];
              interception_v15_B.At[interception_v15_B.ii_g] =
                interception_v15_B.atmp_g;
            }
          }

          interception_v15_B.rscale[interception_v15_B.e_i - 1] =
            interception_v15_B.jcol_l;
          interception_v15_B.e_i++;
          if (interception_v15_B.e_i == interception_v15_B.b_k) {
            interception_v15_B.rscale[interception_v15_B.e_i - 1] =
              interception_v15_B.e_i;
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }

    memset(&V[0], 0, sizeof(creal_T) << 4U);
    V[0].re = 1.0;
    V[0].im = 0.0;
    V[5].re = 1.0;
    V[5].im = 0.0;
    V[10].re = 1.0;
    V[10].im = 0.0;
    V[15].re = 1.0;
    V[15].im = 0.0;
    if (interception_v15_B.b_k >= interception_v15_B.e_i + 2) {
      interception_v15_B.jcol_l = interception_v15_B.e_i - 1;
      while (interception_v15_B.jcol_l + 1 < interception_v15_B.b_k - 1) {
        interception_v15_B.jrow = interception_v15_B.b_k - 1;
        while (interception_v15_B.jrow + 1 > interception_v15_B.jcol_l + 2) {
          interception_v15_xzlartg(interception_v15_B.At
            [(interception_v15_B.jrow + (interception_v15_B.jcol_l << 2)) - 1],
            interception_v15_B.At[interception_v15_B.jrow +
            (interception_v15_B.jcol_l << 2)], &interception_v15_B.cfromc_b,
            &interception_v15_B.atmp_g, &interception_v15_B.At
            [(interception_v15_B.jrow + (interception_v15_B.jcol_l << 2)) - 1]);
          interception_v15_B.g_k = (interception_v15_B.jcol_l << 2) +
            interception_v15_B.jrow;
          interception_v15_B.At[interception_v15_B.g_k].re = 0.0;
          interception_v15_B.At[interception_v15_B.g_k].im = 0.0;
          for (interception_v15_B.ii_g = interception_v15_B.jcol_l + 2;
               interception_v15_B.ii_g < 5; interception_v15_B.ii_g++) {
            interception_v15_B.g_k = ((interception_v15_B.ii_g - 1) << 2) +
              interception_v15_B.jrow;
            interception_v15_B.ctoc_n =
              interception_v15_B.At[interception_v15_B.g_k].im;
            interception_v15_B.vtemp =
              interception_v15_B.At[interception_v15_B.g_k].re;
            interception_v15_B.cto1_b =
              interception_v15_B.At[interception_v15_B.g_k - 1].re;
            interception_v15_B.stemp_im_tmp_l =
              interception_v15_B.At[interception_v15_B.g_k - 1].im;
            interception_v15_B.At[interception_v15_B.g_k].re =
              interception_v15_B.vtemp * interception_v15_B.cfromc_b -
              (interception_v15_B.cto1_b * interception_v15_B.atmp_g.re +
               interception_v15_B.stemp_im_tmp_l * interception_v15_B.atmp_g.im);
            interception_v15_B.At[interception_v15_B.g_k].im =
              interception_v15_B.ctoc_n * interception_v15_B.cfromc_b -
              (interception_v15_B.stemp_im_tmp_l * interception_v15_B.atmp_g.re
               - interception_v15_B.atmp_g.im * interception_v15_B.cto1_b);
            interception_v15_B.At[interception_v15_B.g_k - 1].re =
              (interception_v15_B.vtemp * interception_v15_B.atmp_g.re -
               interception_v15_B.ctoc_n * interception_v15_B.atmp_g.im) +
              interception_v15_B.cto1_b * interception_v15_B.cfromc_b;
            interception_v15_B.At[interception_v15_B.g_k - 1].im =
              (interception_v15_B.ctoc_n * interception_v15_B.atmp_g.re +
               interception_v15_B.vtemp * interception_v15_B.atmp_g.im) +
              interception_v15_B.stemp_im_tmp_l * interception_v15_B.cfromc_b;
          }

          interception_v15_B.atmp_g.re = -interception_v15_B.atmp_g.re;
          interception_v15_B.atmp_g.im = -interception_v15_B.atmp_g.im;
          for (interception_v15_B.ii_g = 1; interception_v15_B.ii_g <=
               interception_v15_B.b_k; interception_v15_B.ii_g++) {
            interception_v15_B.g_k = (((interception_v15_B.jrow - 1) << 2) +
              interception_v15_B.ii_g) - 1;
            interception_v15_B.ctoc_n =
              interception_v15_B.At[interception_v15_B.g_k].im;
            interception_v15_B.vtemp =
              interception_v15_B.At[interception_v15_B.g_k].re;
            interception_v15_B.nzcount_c = ((interception_v15_B.jrow << 2) +
              interception_v15_B.ii_g) - 1;
            interception_v15_B.cto1_b =
              interception_v15_B.At[interception_v15_B.nzcount_c].re;
            interception_v15_B.stemp_im_tmp_l =
              interception_v15_B.At[interception_v15_B.nzcount_c].im;
            interception_v15_B.At[interception_v15_B.g_k].re =
              interception_v15_B.vtemp * interception_v15_B.cfromc_b -
              (interception_v15_B.cto1_b * interception_v15_B.atmp_g.re +
               interception_v15_B.stemp_im_tmp_l * interception_v15_B.atmp_g.im);
            interception_v15_B.At[interception_v15_B.g_k].im =
              interception_v15_B.ctoc_n * interception_v15_B.cfromc_b -
              (interception_v15_B.stemp_im_tmp_l * interception_v15_B.atmp_g.re
               - interception_v15_B.atmp_g.im * interception_v15_B.cto1_b);
            interception_v15_B.At[interception_v15_B.nzcount_c].re =
              (interception_v15_B.vtemp * interception_v15_B.atmp_g.re -
               interception_v15_B.ctoc_n * interception_v15_B.atmp_g.im) +
              interception_v15_B.cto1_b * interception_v15_B.cfromc_b;
            interception_v15_B.At[interception_v15_B.nzcount_c].im =
              (interception_v15_B.ctoc_n * interception_v15_B.atmp_g.re +
               interception_v15_B.vtemp * interception_v15_B.atmp_g.im) +
              interception_v15_B.stemp_im_tmp_l * interception_v15_B.cfromc_b;
          }

          interception_v15_B.g_k = (interception_v15_B.jrow - 1) << 2;
          interception_v15_B.ctoc_n = V[interception_v15_B.g_k].im;
          interception_v15_B.vtemp = V[interception_v15_B.g_k].re;
          interception_v15_B.nzcount_c = interception_v15_B.jrow << 2;
          interception_v15_B.cto1_b = V[interception_v15_B.nzcount_c].re;
          interception_v15_B.stemp_im_tmp_l = V[interception_v15_B.nzcount_c].im;
          V[interception_v15_B.g_k].re = interception_v15_B.vtemp *
            interception_v15_B.cfromc_b - (interception_v15_B.cto1_b *
            interception_v15_B.atmp_g.re + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.im);
          V[interception_v15_B.g_k].im = interception_v15_B.ctoc_n *
            interception_v15_B.cfromc_b - (interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.re - interception_v15_B.atmp_g.im *
            interception_v15_B.cto1_b);
          V[interception_v15_B.nzcount_c].re = (interception_v15_B.vtemp *
            interception_v15_B.atmp_g.re - interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.im) + interception_v15_B.cto1_b *
            interception_v15_B.cfromc_b;
          V[interception_v15_B.nzcount_c].im = (interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.re + interception_v15_B.vtemp *
            interception_v15_B.atmp_g.im) + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.cfromc_b;
          interception_v15_B.ctoc_n = V[interception_v15_B.g_k + 1].im;
          interception_v15_B.vtemp = V[interception_v15_B.g_k + 1].re;
          interception_v15_B.cto1_b = V[interception_v15_B.nzcount_c + 1].re;
          interception_v15_B.stemp_im_tmp_l = V[interception_v15_B.nzcount_c + 1]
            .im;
          V[interception_v15_B.g_k + 1].re = interception_v15_B.vtemp *
            interception_v15_B.cfromc_b - (interception_v15_B.cto1_b *
            interception_v15_B.atmp_g.re + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.im);
          V[interception_v15_B.g_k + 1].im = interception_v15_B.ctoc_n *
            interception_v15_B.cfromc_b - (interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.re - interception_v15_B.atmp_g.im *
            interception_v15_B.cto1_b);
          V[interception_v15_B.nzcount_c + 1].re = (interception_v15_B.vtemp *
            interception_v15_B.atmp_g.re - interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.im) + interception_v15_B.cto1_b *
            interception_v15_B.cfromc_b;
          V[interception_v15_B.nzcount_c + 1].im = (interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.re + interception_v15_B.vtemp *
            interception_v15_B.atmp_g.im) + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.cfromc_b;
          interception_v15_B.ctoc_n = V[interception_v15_B.g_k + 2].im;
          interception_v15_B.vtemp = V[interception_v15_B.g_k + 2].re;
          interception_v15_B.cto1_b = V[interception_v15_B.nzcount_c + 2].re;
          interception_v15_B.stemp_im_tmp_l = V[interception_v15_B.nzcount_c + 2]
            .im;
          V[interception_v15_B.g_k + 2].re = interception_v15_B.vtemp *
            interception_v15_B.cfromc_b - (interception_v15_B.cto1_b *
            interception_v15_B.atmp_g.re + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.im);
          V[interception_v15_B.g_k + 2].im = interception_v15_B.ctoc_n *
            interception_v15_B.cfromc_b - (interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.re - interception_v15_B.atmp_g.im *
            interception_v15_B.cto1_b);
          V[interception_v15_B.nzcount_c + 2].re = (interception_v15_B.vtemp *
            interception_v15_B.atmp_g.re - interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.im) + interception_v15_B.cto1_b *
            interception_v15_B.cfromc_b;
          V[interception_v15_B.nzcount_c + 2].im = (interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.re + interception_v15_B.vtemp *
            interception_v15_B.atmp_g.im) + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.cfromc_b;
          interception_v15_B.ctoc_n = V[interception_v15_B.g_k + 3].im;
          interception_v15_B.vtemp = V[interception_v15_B.g_k + 3].re;
          interception_v15_B.cto1_b = V[interception_v15_B.nzcount_c + 3].re;
          interception_v15_B.stemp_im_tmp_l = V[interception_v15_B.nzcount_c + 3]
            .im;
          V[interception_v15_B.g_k + 3].re = interception_v15_B.vtemp *
            interception_v15_B.cfromc_b - (interception_v15_B.cto1_b *
            interception_v15_B.atmp_g.re + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.im);
          V[interception_v15_B.g_k + 3].im = interception_v15_B.ctoc_n *
            interception_v15_B.cfromc_b - (interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.atmp_g.re - interception_v15_B.atmp_g.im *
            interception_v15_B.cto1_b);
          V[interception_v15_B.nzcount_c + 3].re = (interception_v15_B.vtemp *
            interception_v15_B.atmp_g.re - interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.im) + interception_v15_B.cto1_b *
            interception_v15_B.cfromc_b;
          V[interception_v15_B.nzcount_c + 3].im = (interception_v15_B.ctoc_n *
            interception_v15_B.atmp_g.re + interception_v15_B.vtemp *
            interception_v15_B.atmp_g.im) + interception_v15_B.stemp_im_tmp_l *
            interception_v15_B.cfromc_b;
          interception_v15_B.jrow--;
        }

        interception_v15_B.jcol_l++;
      }
    }

    interception_v15_xzhgeqz(interception_v15_B.At, interception_v15_B.e_i,
      interception_v15_B.b_k, V, info, alpha1, beta1);
    if (*info == 0) {
      interception_v15_xztgevc(interception_v15_B.At, V);
      if (interception_v15_B.e_i > 1) {
        interception_v15_B.e_i -= 2;
        while (interception_v15_B.e_i + 1 >= 1) {
          interception_v15_B.g_k =
            interception_v15_B.rscale[interception_v15_B.e_i] - 1;
          if (interception_v15_B.e_i + 1 !=
              interception_v15_B.rscale[interception_v15_B.e_i]) {
            interception_v15_B.atmp_g = V[interception_v15_B.e_i];
            V[interception_v15_B.e_i] = V[interception_v15_B.g_k];
            V[interception_v15_B.g_k] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 4];
            V[interception_v15_B.e_i + 4] = V[interception_v15_B.g_k + 4];
            V[interception_v15_B.g_k + 4] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 8];
            V[interception_v15_B.e_i + 8] = V[interception_v15_B.g_k + 8];
            V[interception_v15_B.g_k + 8] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 12];
            V[interception_v15_B.e_i + 12] = V[interception_v15_B.g_k + 12];
            V[interception_v15_B.g_k + 12] = interception_v15_B.atmp_g;
          }

          interception_v15_B.e_i--;
        }
      }

      if (interception_v15_B.b_k < 4) {
        for (interception_v15_B.e_i = interception_v15_B.b_k + 1;
             interception_v15_B.e_i < 5; interception_v15_B.e_i++) {
          interception_v15_B.g_k =
            interception_v15_B.rscale[interception_v15_B.e_i - 1];
          if (interception_v15_B.g_k != interception_v15_B.e_i) {
            interception_v15_B.atmp_g = V[interception_v15_B.e_i - 1];
            V[interception_v15_B.e_i - 1] = V[interception_v15_B.g_k - 1];
            V[interception_v15_B.g_k - 1] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 3];
            V[interception_v15_B.e_i + 3] = V[interception_v15_B.g_k + 3];
            V[interception_v15_B.g_k + 3] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 7];
            V[interception_v15_B.e_i + 7] = V[interception_v15_B.g_k + 7];
            V[interception_v15_B.g_k + 7] = interception_v15_B.atmp_g;
            interception_v15_B.atmp_g = V[interception_v15_B.e_i + 11];
            V[interception_v15_B.e_i + 11] = V[interception_v15_B.g_k + 11];
            V[interception_v15_B.g_k + 11] = interception_v15_B.atmp_g;
          }
        }
      }

      for (interception_v15_B.b_k = 0; interception_v15_B.b_k < 4;
           interception_v15_B.b_k++) {
        interception_v15_B.e_i = interception_v15_B.b_k << 2;
        interception_v15_B.cfromc_b = V[interception_v15_B.e_i].re;
        interception_v15_B.ctoc_n = V[interception_v15_B.e_i].im;
        interception_v15_B.vtemp = fabs(interception_v15_B.cfromc_b) + fabs
          (interception_v15_B.ctoc_n);
        interception_v15_B.cto1_b = fabs(V[interception_v15_B.e_i + 1].re) +
          fabs(V[interception_v15_B.e_i + 1].im);
        if (interception_v15_B.cto1_b > interception_v15_B.vtemp) {
          interception_v15_B.vtemp = interception_v15_B.cto1_b;
        }

        interception_v15_B.cto1_b = fabs(V[interception_v15_B.e_i + 2].re) +
          fabs(V[interception_v15_B.e_i + 2].im);
        if (interception_v15_B.cto1_b > interception_v15_B.vtemp) {
          interception_v15_B.vtemp = interception_v15_B.cto1_b;
        }

        interception_v15_B.cto1_b = fabs(V[interception_v15_B.e_i + 3].re) +
          fabs(V[interception_v15_B.e_i + 3].im);
        if (interception_v15_B.cto1_b > interception_v15_B.vtemp) {
          interception_v15_B.vtemp = interception_v15_B.cto1_b;
        }

        if (interception_v15_B.vtemp >= 6.7178761075670888E-139) {
          interception_v15_B.vtemp = 1.0 / interception_v15_B.vtemp;
          V[interception_v15_B.e_i].re = interception_v15_B.cfromc_b *
            interception_v15_B.vtemp;
          V[interception_v15_B.e_i].im = interception_v15_B.ctoc_n *
            interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 1].re *= interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 1].im *= interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 2].re *= interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 2].im *= interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 3].re *= interception_v15_B.vtemp;
          V[interception_v15_B.e_i + 3].im *= interception_v15_B.vtemp;
        }
      }

      if (ilascl) {
        ilascl = true;
        while (ilascl) {
          interception_v15_B.cfromc_b = interception_v15_B.b_absxk *
            2.0041683600089728E-292;
          interception_v15_B.ctoc_n = interception_v15_B.anrm_o /
            4.9896007738368E+291;
          if ((interception_v15_B.cfromc_b > interception_v15_B.anrm_o) &&
              (interception_v15_B.anrm_o != 0.0)) {
            interception_v15_B.vtemp = 2.0041683600089728E-292;
            interception_v15_B.b_absxk = interception_v15_B.cfromc_b;
          } else if (interception_v15_B.ctoc_n > interception_v15_B.b_absxk) {
            interception_v15_B.vtemp = 4.9896007738368E+291;
            interception_v15_B.anrm_o = interception_v15_B.ctoc_n;
          } else {
            interception_v15_B.vtemp = interception_v15_B.anrm_o /
              interception_v15_B.b_absxk;
            ilascl = false;
          }

          alpha1[0].re *= interception_v15_B.vtemp;
          alpha1[0].im *= interception_v15_B.vtemp;
          alpha1[1].re *= interception_v15_B.vtemp;
          alpha1[1].im *= interception_v15_B.vtemp;
          alpha1[2].re *= interception_v15_B.vtemp;
          alpha1[2].im *= interception_v15_B.vtemp;
          alpha1[3].re *= interception_v15_B.vtemp;
          alpha1[3].im *= interception_v15_B.vtemp;
        }
      }
    }
  }

  for (interception_v15_B.b_k = 0; interception_v15_B.b_k <= 12;
       interception_v15_B.b_k += 4) {
    interception_v15_B.anrm_o = 0.0;
    interception_v15_B.b_absxk = 3.3121686421112381E-170;
    for (interception_v15_B.e_i = interception_v15_B.b_k + 1;
         interception_v15_B.e_i <= interception_v15_B.b_k + 4;
         interception_v15_B.e_i++) {
      interception_v15_B.cfromc_b = fabs(V[interception_v15_B.e_i - 1].re);
      if (interception_v15_B.cfromc_b > interception_v15_B.b_absxk) {
        interception_v15_B.ctoc_n = interception_v15_B.b_absxk /
          interception_v15_B.cfromc_b;
        interception_v15_B.anrm_o = interception_v15_B.anrm_o *
          interception_v15_B.ctoc_n * interception_v15_B.ctoc_n + 1.0;
        interception_v15_B.b_absxk = interception_v15_B.cfromc_b;
      } else {
        interception_v15_B.ctoc_n = interception_v15_B.cfromc_b /
          interception_v15_B.b_absxk;
        interception_v15_B.anrm_o += interception_v15_B.ctoc_n *
          interception_v15_B.ctoc_n;
      }

      interception_v15_B.cfromc_b = fabs(V[interception_v15_B.e_i - 1].im);
      if (interception_v15_B.cfromc_b > interception_v15_B.b_absxk) {
        interception_v15_B.ctoc_n = interception_v15_B.b_absxk /
          interception_v15_B.cfromc_b;
        interception_v15_B.anrm_o = interception_v15_B.anrm_o *
          interception_v15_B.ctoc_n * interception_v15_B.ctoc_n + 1.0;
        interception_v15_B.b_absxk = interception_v15_B.cfromc_b;
      } else {
        interception_v15_B.ctoc_n = interception_v15_B.cfromc_b /
          interception_v15_B.b_absxk;
        interception_v15_B.anrm_o += interception_v15_B.ctoc_n *
          interception_v15_B.ctoc_n;
      }
    }

    interception_v15_B.anrm_o = interception_v15_B.b_absxk * sqrt
      (interception_v15_B.anrm_o);
    for (interception_v15_B.e_i = interception_v15_B.b_k + 1;
         interception_v15_B.e_i <= interception_v15_B.b_k + 4;
         interception_v15_B.e_i++) {
      interception_v15_B.b_absxk = V[interception_v15_B.e_i - 1].re;
      interception_v15_B.cfromc_b = V[interception_v15_B.e_i - 1].im;
      if (interception_v15_B.cfromc_b == 0.0) {
        V[interception_v15_B.e_i - 1].re = interception_v15_B.b_absxk /
          interception_v15_B.anrm_o;
        V[interception_v15_B.e_i - 1].im = 0.0;
      } else if (interception_v15_B.b_absxk == 0.0) {
        V[interception_v15_B.e_i - 1].re = 0.0;
        V[interception_v15_B.e_i - 1].im = interception_v15_B.cfromc_b /
          interception_v15_B.anrm_o;
      } else {
        V[interception_v15_B.e_i - 1].re = interception_v15_B.b_absxk /
          interception_v15_B.anrm_o;
        V[interception_v15_B.e_i - 1].im = interception_v15_B.cfromc_b /
          interception_v15_B.anrm_o;
      }
    }
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static real_T interception_v15_xnrm2(int32_T n, const real_T x[16], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (int32_T k = ix0; k <= ix0 + 1; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, real_T C[16], int32_T ic0, real_T work[4])
{
  int32_T coltop;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = ((lastc - 1) << 2) + ic0;
      jA = coltop;
      do {
        exitg1 = 0;
        if (jA <= (coltop + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T e;
    if (lastc != 0) {
      memset(&work[0], 0, static_cast<uint8_T>(lastc) * sizeof(real_T));
      d = ((lastc - 1) << 2) + ic0;
      for (coltop = ic0; coltop <= d; coltop += 4) {
        c = 0.0;
        e = coltop + lastv;
        for (jA = coltop; jA < e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = (coltop - ic0) >> 2;
        work[jA] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = static_cast<uint8_T>(lastc);
      for (lastc = 0; lastc < d; lastc++) {
        if (work[lastc] != 0.0) {
          c = work[lastc] * -tau;
          e = lastv + jA;
          for (coltop = jA; coltop < e; coltop++) {
            C[coltop - 1] += C[((iv0 + coltop) - jA) - 1] * c;
          }
        }

        jA += 4;
      }
    }
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static real_T interception_v15_xnrm2_l(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      interception_v15_B.scale_as = 3.3121686421112381E-170;
      interception_v15_B.absxk_i = fabs(x[1]);
      if (interception_v15_B.absxk_i > 3.3121686421112381E-170) {
        y = 1.0;
        interception_v15_B.scale_as = interception_v15_B.absxk_i;
      } else {
        interception_v15_B.t_l = interception_v15_B.absxk_i /
          3.3121686421112381E-170;
        y = interception_v15_B.t_l * interception_v15_B.t_l;
      }

      interception_v15_B.absxk_i = fabs(x[2]);
      if (interception_v15_B.absxk_i > interception_v15_B.scale_as) {
        interception_v15_B.t_l = interception_v15_B.scale_as /
          interception_v15_B.absxk_i;
        y = y * interception_v15_B.t_l * interception_v15_B.t_l + 1.0;
        interception_v15_B.scale_as = interception_v15_B.absxk_i;
      } else {
        interception_v15_B.t_l = interception_v15_B.absxk_i /
          interception_v15_B.scale_as;
        y += interception_v15_B.t_l * interception_v15_B.t_l;
      }

      y = interception_v15_B.scale_as * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static real_T interception_v15_xzlarfg(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    interception_v15_B.xnorm = interception_v15_xnrm2_l(n - 1, x);
    if (interception_v15_B.xnorm != 0.0) {
      interception_v15_B.xnorm = interception_v15_rt_hypotd_snf(*alpha1,
        interception_v15_B.xnorm);
      if (*alpha1 >= 0.0) {
        interception_v15_B.xnorm = -interception_v15_B.xnorm;
      }

      if (fabs(interception_v15_B.xnorm) < 1.0020841800044864E-292) {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          for (int32_T c_k = 2; c_k <= n; c_k++) {
            x[c_k - 1] *= 9.9792015476736E+291;
          }

          interception_v15_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(interception_v15_B.xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));

        interception_v15_B.xnorm = interception_v15_rt_hypotd_snf(*alpha1,
          interception_v15_xnrm2_l(n - 1, x));
        if (*alpha1 >= 0.0) {
          interception_v15_B.xnorm = -interception_v15_B.xnorm;
        }

        tau = (interception_v15_B.xnorm - *alpha1) / interception_v15_B.xnorm;
        interception_v15_B.a_a = 1.0 / (*alpha1 - interception_v15_B.xnorm);
        for (int32_T c_k = 2; c_k <= n; c_k++) {
          x[c_k - 1] *= interception_v15_B.a_a;
        }

        for (int32_T c_k = 0; c_k < knt; c_k++) {
          interception_v15_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = interception_v15_B.xnorm;
      } else {
        tau = (interception_v15_B.xnorm - *alpha1) / interception_v15_B.xnorm;
        interception_v15_B.a_a = 1.0 / (*alpha1 - interception_v15_B.xnorm);
        for (int32_T knt = 2; knt <= n; knt++) {
          x[knt - 1] *= interception_v15_B.a_a;
        }

        *alpha1 = interception_v15_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d,
  real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    interception_v15_B.temp_h = *d;
    *d = *a;
    *a = interception_v15_B.temp_h;
    *b = -*c;
    *c = 0.0;
  } else {
    interception_v15_B.temp_h = *a - *d;
    if ((interception_v15_B.temp_h == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      int32_T count;
      int32_T tmp;
      boolean_T tmp_0;
      interception_v15_B.p = 0.5 * interception_v15_B.temp_h;
      interception_v15_B.scale_c = fabs(*b);
      interception_v15_B.bcmis = fabs(*c);
      tmp_0 = rtIsNaN(interception_v15_B.bcmis);
      if ((interception_v15_B.scale_c >= interception_v15_B.bcmis) || tmp_0) {
        interception_v15_B.bcmax = interception_v15_B.scale_c;
      } else {
        interception_v15_B.bcmax = interception_v15_B.bcmis;
      }

      if ((interception_v15_B.scale_c <= interception_v15_B.bcmis) || tmp_0) {
        interception_v15_B.bcmis = interception_v15_B.scale_c;
      }

      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }

      if (!(*c < 0.0)) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      interception_v15_B.bcmis = interception_v15_B.bcmis * static_cast<real_T>
        (count) * static_cast<real_T>(tmp);
      interception_v15_B.scale_c = fabs(interception_v15_B.p);
      if ((!(interception_v15_B.scale_c >= interception_v15_B.bcmax)) &&
          (!rtIsNaN(interception_v15_B.bcmax))) {
        interception_v15_B.scale_c = interception_v15_B.bcmax;
      }

      interception_v15_B.z = interception_v15_B.p / interception_v15_B.scale_c *
        interception_v15_B.p + interception_v15_B.bcmax /
        interception_v15_B.scale_c * interception_v15_B.bcmis;
      if (interception_v15_B.z >= 8.8817841970012523E-16) {
        if (!(interception_v15_B.p < 0.0)) {
          interception_v15_B.temp_h = sqrt(interception_v15_B.scale_c) * sqrt
            (interception_v15_B.z);
        } else {
          interception_v15_B.temp_h = -(sqrt(interception_v15_B.scale_c) * sqrt
            (interception_v15_B.z));
        }

        interception_v15_B.z = interception_v15_B.p + interception_v15_B.temp_h;
        *a = *d + interception_v15_B.z;
        *d -= interception_v15_B.bcmax / interception_v15_B.z *
          interception_v15_B.bcmis;
        interception_v15_B.bcmax = interception_v15_rt_hypotd_snf(*c,
          interception_v15_B.z);
        *cs = interception_v15_B.z / interception_v15_B.bcmax;
        *sn = *c / interception_v15_B.bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        interception_v15_B.p = *b + *c;
        interception_v15_B.bcmax = fabs(interception_v15_B.temp_h);
        interception_v15_B.scale_c = fabs(interception_v15_B.p);
        if ((interception_v15_B.bcmax >= interception_v15_B.scale_c) || rtIsNaN
            (interception_v15_B.scale_c)) {
          interception_v15_B.scale_c = interception_v15_B.bcmax;
        }

        count = 0;
        while ((interception_v15_B.scale_c >= 7.4428285367870146E+137) && (count
                <= 20)) {
          interception_v15_B.p *= 1.3435752215134178E-138;
          interception_v15_B.temp_h *= 1.3435752215134178E-138;
          interception_v15_B.bcmax = fabs(interception_v15_B.temp_h);
          interception_v15_B.scale_c = fabs(interception_v15_B.p);
          if ((interception_v15_B.bcmax >= interception_v15_B.scale_c) ||
              rtIsNaN(interception_v15_B.scale_c)) {
            interception_v15_B.scale_c = interception_v15_B.bcmax;
          }

          count++;
        }

        while ((interception_v15_B.scale_c <= 1.3435752215134178E-138) && (count
                <= 20)) {
          interception_v15_B.p *= 7.4428285367870146E+137;
          interception_v15_B.temp_h *= 7.4428285367870146E+137;
          interception_v15_B.bcmax = fabs(interception_v15_B.temp_h);
          interception_v15_B.scale_c = fabs(interception_v15_B.p);
          if ((interception_v15_B.bcmax >= interception_v15_B.scale_c) ||
              rtIsNaN(interception_v15_B.scale_c)) {
            interception_v15_B.scale_c = interception_v15_B.bcmax;
          }

          count++;
        }

        interception_v15_B.bcmax = interception_v15_rt_hypotd_snf
          (interception_v15_B.p, interception_v15_B.temp_h);
        *cs = sqrt((fabs(interception_v15_B.p) / interception_v15_B.bcmax + 1.0)
                   * 0.5);
        if (!(interception_v15_B.p < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }

        *sn = -(0.5 * interception_v15_B.temp_h / (interception_v15_B.bcmax *
                 *cs)) * static_cast<real_T>(count);
        interception_v15_B.temp_h = *a * *cs + *b * *sn;
        interception_v15_B.p = -*a * *sn + *b * *cs;
        interception_v15_B.bcmax = *c * *cs + *d * *sn;
        interception_v15_B.scale_c = -*c * *sn + *d * *cs;
        *b = interception_v15_B.p * *cs + interception_v15_B.scale_c * *sn;
        *c = -interception_v15_B.temp_h * *sn + interception_v15_B.bcmax * *cs;
        interception_v15_B.temp_h = ((interception_v15_B.temp_h * *cs +
          interception_v15_B.bcmax * *sn) + (-interception_v15_B.p * *sn +
          interception_v15_B.scale_c * *cs)) * 0.5;
        *a = interception_v15_B.temp_h;
        *d = interception_v15_B.temp_h;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              interception_v15_B.bcmis = sqrt(fabs(*b));
              interception_v15_B.scale_c = sqrt(fabs(*c));
              if (!(*c < 0.0)) {
                interception_v15_B.p = interception_v15_B.bcmis *
                  interception_v15_B.scale_c;
              } else {
                interception_v15_B.p = -(interception_v15_B.bcmis *
                  interception_v15_B.scale_c);
              }

              interception_v15_B.bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = interception_v15_B.temp_h + interception_v15_B.p;
              *d = interception_v15_B.temp_h - interception_v15_B.p;
              *b -= *c;
              *c = 0.0;
              interception_v15_B.p = interception_v15_B.bcmis *
                interception_v15_B.bcmax;
              interception_v15_B.bcmax *= interception_v15_B.scale_c;
              interception_v15_B.temp_h = *cs * interception_v15_B.p - *sn *
                interception_v15_B.bcmax;
              *sn = *cs * interception_v15_B.bcmax + *sn * interception_v15_B.p;
              *cs = interception_v15_B.temp_h;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            interception_v15_B.temp_h = *cs;
            *cs = -*sn;
            *sn = interception_v15_B.temp_h;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static int32_T interception_v15_xhseqr(real_T h[16], real_T z[16])
{
  int32_T i;
  int32_T info;
  int32_T kdefl;
  boolean_T exitg1;
  info = 0;
  interception_v15_B.v[0] = 0.0;
  interception_v15_B.v[1] = 0.0;
  interception_v15_B.v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  kdefl = 0;
  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T L;
    int32_T its;
    int32_T k;
    int32_T m;
    int32_T nr;
    int32_T tst_tmp;
    boolean_T exitg2;
    boolean_T goto150;
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      boolean_T exitg3;
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        m = ((k - 1) << 2) + k;
        if (fabs(h[m]) <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          tst_tmp = (k << 2) + k;
          interception_v15_B.tst = fabs(h[m - 1]) + fabs(h[tst_tmp]);
          if (interception_v15_B.tst == 0.0) {
            if (k - 1 >= 1) {
              interception_v15_B.tst = fabs(h[(((k - 2) << 2) + k) - 1]);
            }

            if (k + 2 <= 4) {
              interception_v15_B.tst += fabs(h[tst_tmp + 1]);
            }
          }

          interception_v15_B.ba = fabs(h[m]);
          if (interception_v15_B.ba <= 2.2204460492503131E-16 *
              interception_v15_B.tst) {
            interception_v15_B.tst = fabs(h[tst_tmp - 1]);
            if (interception_v15_B.ba > interception_v15_B.tst) {
              interception_v15_B.ab = interception_v15_B.ba;
              interception_v15_B.ba = interception_v15_B.tst;
            } else {
              interception_v15_B.ab = interception_v15_B.tst;
            }

            interception_v15_B.tst = h[tst_tmp];
            interception_v15_B.htmp1 = fabs(interception_v15_B.tst);
            interception_v15_B.tst = fabs(h[m - 1] - interception_v15_B.tst);
            if (interception_v15_B.htmp1 > interception_v15_B.tst) {
              interception_v15_B.aa = interception_v15_B.htmp1;
              interception_v15_B.htmp1 = interception_v15_B.tst;
            } else {
              interception_v15_B.aa = interception_v15_B.tst;
            }

            interception_v15_B.tst = interception_v15_B.aa +
              interception_v15_B.ab;
            interception_v15_B.htmp1 = interception_v15_B.aa /
              interception_v15_B.tst * interception_v15_B.htmp1 *
              2.2204460492503131E-16;
            if ((interception_v15_B.htmp1 <= 4.0083367200179456E-292) || rtIsNaN
                (interception_v15_B.htmp1)) {
              interception_v15_B.htmp1 = 4.0083367200179456E-292;
            }

            if (interception_v15_B.ab / interception_v15_B.tst *
                interception_v15_B.ba <= interception_v15_B.htmp1) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        kdefl++;
        if (kdefl - div_nzp_s32(kdefl, 20) * 20 == 0) {
          interception_v15_B.tst = fabs(h[(((i - 2) << 2) + i) - 1]) + fabs(h
            [((i - 1) << 2) + i]);
          interception_v15_B.ab = h[(i << 2) + i] + 0.75 *
            interception_v15_B.tst;
          interception_v15_B.h12 = -0.4375 * interception_v15_B.tst;
          interception_v15_B.aa = interception_v15_B.tst;
          interception_v15_B.htmp1 = interception_v15_B.ab;
        } else if (kdefl - div_nzp_s32(kdefl, 10) * 10 == 0) {
          interception_v15_B.tst = fabs(h[(((k + 1) << 2) + k) + 2]) + fabs(h
            [((k << 2) + k) + 1]);
          interception_v15_B.ab = h[(k << 2) + k] + 0.75 *
            interception_v15_B.tst;
          interception_v15_B.h12 = -0.4375 * interception_v15_B.tst;
          interception_v15_B.aa = interception_v15_B.tst;
          interception_v15_B.htmp1 = interception_v15_B.ab;
        } else {
          m = ((i - 1) << 2) + i;
          interception_v15_B.ab = h[m - 1];
          interception_v15_B.aa = h[m];
          tst_tmp = (i << 2) + i;
          interception_v15_B.h12 = h[tst_tmp - 1];
          interception_v15_B.htmp1 = h[tst_tmp];
        }

        interception_v15_B.tst = ((fabs(interception_v15_B.ab) + fabs
          (interception_v15_B.h12)) + fabs(interception_v15_B.aa)) + fabs
          (interception_v15_B.htmp1);
        if (interception_v15_B.tst == 0.0) {
          interception_v15_B.ab = 0.0;
          interception_v15_B.htmp1 = 0.0;
          interception_v15_B.ba = 0.0;
          interception_v15_B.aa = 0.0;
        } else {
          interception_v15_B.ab /= interception_v15_B.tst;
          interception_v15_B.htmp1 /= interception_v15_B.tst;
          interception_v15_B.ba = (interception_v15_B.ab +
            interception_v15_B.htmp1) / 2.0;
          interception_v15_B.ab = (interception_v15_B.ab - interception_v15_B.ba)
            * (interception_v15_B.htmp1 - interception_v15_B.ba) -
            interception_v15_B.h12 / interception_v15_B.tst *
            (interception_v15_B.aa / interception_v15_B.tst);
          interception_v15_B.aa = sqrt(fabs(interception_v15_B.ab));
          if (interception_v15_B.ab >= 0.0) {
            interception_v15_B.ab = interception_v15_B.ba *
              interception_v15_B.tst;
            interception_v15_B.ba = interception_v15_B.ab;
            interception_v15_B.htmp1 = interception_v15_B.aa *
              interception_v15_B.tst;
            interception_v15_B.aa = -interception_v15_B.htmp1;
          } else {
            interception_v15_B.ab = interception_v15_B.ba +
              interception_v15_B.aa;
            interception_v15_B.ba -= interception_v15_B.aa;
            if (fabs(interception_v15_B.ab - interception_v15_B.htmp1) <= fabs
                (interception_v15_B.ba - interception_v15_B.htmp1)) {
              interception_v15_B.ab *= interception_v15_B.tst;
              interception_v15_B.ba = interception_v15_B.ab;
            } else {
              interception_v15_B.ba *= interception_v15_B.tst;
              interception_v15_B.ab = interception_v15_B.ba;
            }

            interception_v15_B.htmp1 = 0.0;
            interception_v15_B.aa = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          tst_tmp = ((m - 1) << 2) + m;
          interception_v15_B.h21s = h[tst_tmp];
          interception_v15_B.h12 = h[tst_tmp - 1];
          interception_v15_B.s_tmp = interception_v15_B.h12 -
            interception_v15_B.ba;
          interception_v15_B.tst = (fabs(interception_v15_B.s_tmp) + fabs
            (interception_v15_B.aa)) + fabs(interception_v15_B.h21s);
          interception_v15_B.h21s /= interception_v15_B.tst;
          tst_tmp = (m << 2) + m;
          interception_v15_B.v[0] = (interception_v15_B.s_tmp /
            interception_v15_B.tst * (interception_v15_B.h12 -
            interception_v15_B.ab) + h[tst_tmp - 1] * interception_v15_B.h21s) -
            interception_v15_B.aa / interception_v15_B.tst *
            interception_v15_B.htmp1;
          interception_v15_B.s_tmp = h[tst_tmp];
          interception_v15_B.v[1] = (((interception_v15_B.h12 +
            interception_v15_B.s_tmp) - interception_v15_B.ab) -
            interception_v15_B.ba) * interception_v15_B.h21s;
          interception_v15_B.v[2] = h[tst_tmp + 1] * interception_v15_B.h21s;
          interception_v15_B.tst = (fabs(interception_v15_B.v[0]) + fabs
            (interception_v15_B.v[1])) + fabs(interception_v15_B.v[2]);
          interception_v15_B.v[0] /= interception_v15_B.tst;
          interception_v15_B.v[1] /= interception_v15_B.tst;
          interception_v15_B.v[2] /= interception_v15_B.tst;
          if ((k + 1 == m) || (fabs(h[m - 1]) * (fabs(interception_v15_B.v[1]) +
                fabs(interception_v15_B.v[2])) <= ((fabs(interception_v15_B.h12)
                 + fabs(h[0])) + fabs(interception_v15_B.s_tmp)) *
                               (2.2204460492503131E-16 * fabs
                                (interception_v15_B.v[0])))) {
            exitg3 = true;
          } else {
            m--;
          }
        }

        for (tst_tmp = m; tst_tmp <= i; tst_tmp++) {
          int32_T hoffset;
          int32_T j;
          nr = (i - tst_tmp) + 2;
          if (nr >= 3) {
            nr = 3;
          }

          if (tst_tmp > m) {
            hoffset = (((tst_tmp - 2) << 2) + tst_tmp) - 1;
            for (j = 0; j < nr; j++) {
              interception_v15_B.v[j] = h[j + hoffset];
            }
          }

          interception_v15_B.ab = interception_v15_B.v[0];
          interception_v15_B.tst = interception_v15_xzlarfg(nr,
            &interception_v15_B.ab, interception_v15_B.v);
          interception_v15_B.v[0] = interception_v15_B.ab;
          if (tst_tmp > m) {
            h[(tst_tmp + ((tst_tmp - 2) << 2)) - 1] = interception_v15_B.ab;
            h[tst_tmp + ((tst_tmp - 2) << 2)] = 0.0;
            if (tst_tmp < i) {
              h[tst_tmp + 1] = 0.0;
            }
          } else if (m > k + 1) {
            h[tst_tmp - 1] *= 1.0 - interception_v15_B.tst;
          }

          interception_v15_B.ab = interception_v15_B.v[1];
          interception_v15_B.ba = interception_v15_B.tst * interception_v15_B.v
            [1];
          switch (nr) {
           case 3:
            {
              int32_T e;
              int32_T sum1_tmp;
              interception_v15_B.aa = interception_v15_B.v[2];
              interception_v15_B.h12 = interception_v15_B.tst *
                interception_v15_B.v[2];
              for (nr = tst_tmp; nr < 5; nr++) {
                j = ((nr - 1) << 2) + tst_tmp;
                interception_v15_B.htmp1 = (h[j - 1] + h[j] *
                  interception_v15_B.ab) + h[j + 1] * interception_v15_B.aa;
                h[j - 1] -= interception_v15_B.htmp1 * interception_v15_B.tst;
                h[j] -= interception_v15_B.htmp1 * interception_v15_B.ba;
                h[j + 1] -= interception_v15_B.htmp1 * interception_v15_B.h12;
              }

              if (tst_tmp + 3 <= i + 1) {
                e = tst_tmp + 3;
              } else {
                e = i + 1;
              }

              for (hoffset = 0; hoffset < e; hoffset++) {
                j = ((tst_tmp - 1) << 2) + hoffset;
                nr = (tst_tmp << 2) + hoffset;
                sum1_tmp = ((tst_tmp + 1) << 2) + hoffset;
                interception_v15_B.htmp1 = (h[nr] * interception_v15_B.ab + h[j])
                  + h[sum1_tmp] * interception_v15_B.aa;
                h[j] -= interception_v15_B.htmp1 * interception_v15_B.tst;
                h[nr] -= interception_v15_B.htmp1 * interception_v15_B.ba;
                h[sum1_tmp] -= interception_v15_B.htmp1 * interception_v15_B.h12;
              }

              for (hoffset = 0; hoffset < 4; hoffset++) {
                j = ((tst_tmp - 1) << 2) + hoffset;
                nr = (tst_tmp << 2) + hoffset;
                sum1_tmp = ((tst_tmp + 1) << 2) + hoffset;
                interception_v15_B.htmp1 = (z[nr] * interception_v15_B.ab + z[j])
                  + z[sum1_tmp] * interception_v15_B.aa;
                z[j] -= interception_v15_B.htmp1 * interception_v15_B.tst;
                z[nr] -= interception_v15_B.htmp1 * interception_v15_B.ba;
                z[sum1_tmp] -= interception_v15_B.htmp1 * interception_v15_B.h12;
              }
            }
            break;

           case 2:
            for (nr = tst_tmp; nr < 5; nr++) {
              j = ((nr - 1) << 2) + tst_tmp;
              interception_v15_B.aa = h[j - 1];
              interception_v15_B.htmp1 = h[j] * interception_v15_B.ab +
                interception_v15_B.aa;
              h[j - 1] = interception_v15_B.aa - interception_v15_B.htmp1 *
                interception_v15_B.tst;
              h[j] -= interception_v15_B.htmp1 * interception_v15_B.ba;
            }

            for (hoffset = 0; hoffset <= i; hoffset++) {
              j = ((tst_tmp - 1) << 2) + hoffset;
              nr = (tst_tmp << 2) + hoffset;
              interception_v15_B.htmp1 = h[nr] * interception_v15_B.ab + h[j];
              h[j] -= interception_v15_B.htmp1 * interception_v15_B.tst;
              h[nr] -= interception_v15_B.htmp1 * interception_v15_B.ba;
            }

            for (hoffset = 0; hoffset < 4; hoffset++) {
              j = ((tst_tmp - 1) << 2) + hoffset;
              interception_v15_B.aa = z[j];
              nr = (tst_tmp << 2) + hoffset;
              interception_v15_B.htmp1 = z[nr] * interception_v15_B.ab +
                interception_v15_B.aa;
              z[j] = interception_v15_B.aa - interception_v15_B.htmp1 *
                interception_v15_B.tst;
              z[nr] -= interception_v15_B.htmp1 * interception_v15_B.ba;
            }
            break;
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((i + 1 != L) && (L == i)) {
        kdefl = i << 2;
        k = kdefl + i;
        interception_v15_B.ba = h[k - 1];
        its = (i - 1) << 2;
        tst_tmp = its + i;
        interception_v15_B.htmp1 = h[tst_tmp];
        interception_v15_B.aa = h[k];
        interception_v15_xdlanv2(&h[(i + ((i - 1) << 2)) - 1],
          &interception_v15_B.ba, &interception_v15_B.htmp1,
          &interception_v15_B.aa, &interception_v15_B.h12,
          &interception_v15_B.s_tmp, &interception_v15_B.h21s,
          &interception_v15_B.a__4, &interception_v15_B.tst,
          &interception_v15_B.ab);
        h[k - 1] = interception_v15_B.ba;
        h[tst_tmp] = interception_v15_B.htmp1;
        h[k] = interception_v15_B.aa;
        if (i + 1 < 4) {
          m = ((i + 1) << 2) + i;
          tst_tmp = 3 - i;
          for (k = 0; k < tst_tmp; k++) {
            nr = (k << 2) + m;
            interception_v15_B.ba = h[nr];
            interception_v15_B.htmp1 = h[nr - 1];
            h[nr] = interception_v15_B.ba * interception_v15_B.tst -
              interception_v15_B.htmp1 * interception_v15_B.ab;
            h[nr - 1] = interception_v15_B.htmp1 * interception_v15_B.tst +
              interception_v15_B.ba * interception_v15_B.ab;
          }
        }

        if (i - 1 >= 1) {
          k = static_cast<uint8_T>(i - 1);
          for (i = 0; i < k; i++) {
            m = kdefl + i;
            tst_tmp = its + i;
            interception_v15_B.ba = h[tst_tmp] * interception_v15_B.tst + h[m] *
              interception_v15_B.ab;
            h[m] = h[m] * interception_v15_B.tst - h[tst_tmp] *
              interception_v15_B.ab;
            h[tst_tmp] = interception_v15_B.ba;
          }
        }

        interception_v15_B.ba = interception_v15_B.tst * z[its] +
          interception_v15_B.ab * z[kdefl];
        z[kdefl] = interception_v15_B.tst * z[kdefl] - interception_v15_B.ab *
          z[its];
        z[its] = interception_v15_B.ba;
        interception_v15_B.ba = z[kdefl + 1];
        interception_v15_B.htmp1 = z[its + 1];
        z[kdefl + 1] = interception_v15_B.ba * interception_v15_B.tst -
          interception_v15_B.htmp1 * interception_v15_B.ab;
        z[its + 1] = interception_v15_B.htmp1 * interception_v15_B.tst +
          interception_v15_B.ba * interception_v15_B.ab;
        interception_v15_B.ba = z[kdefl + 2];
        interception_v15_B.htmp1 = z[its + 2];
        z[kdefl + 2] = interception_v15_B.ba * interception_v15_B.tst -
          interception_v15_B.htmp1 * interception_v15_B.ab;
        z[its + 2] = interception_v15_B.htmp1 * interception_v15_B.tst +
          interception_v15_B.ba * interception_v15_B.ab;
        interception_v15_B.ba = z[kdefl + 3];
        interception_v15_B.htmp1 = z[its + 3];
        z[kdefl + 3] = interception_v15_B.ba * interception_v15_B.tst -
          interception_v15_B.htmp1 * interception_v15_B.ab;
        z[its + 3] = interception_v15_B.htmp1 * interception_v15_B.tst +
          interception_v15_B.ba * interception_v15_B.ab;
      }

      kdefl = 0;
      i = L - 2;
    }
  }

  h[3] = 0.0;
  return info;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void interception_v15_schur(const real_T A[16], real_T V[16], real_T T[16])
{
  boolean_T p;
  p = true;
  for (interception_v15_B.f_i = 0; interception_v15_B.f_i < 16;
       interception_v15_B.f_i++) {
    interception_v15_B.A = A[interception_v15_B.f_i];
    if (p && (rtIsInf(interception_v15_B.A) || rtIsNaN(interception_v15_B.A))) {
      p = false;
    }
  }

  if (!p) {
    for (interception_v15_B.ix0 = 0; interception_v15_B.ix0 < 16;
         interception_v15_B.ix0++) {
      V[interception_v15_B.ix0] = (rtNaN);
    }

    interception_v15_B.f_i = 2;
    for (interception_v15_B.ia = 0; interception_v15_B.ia < 3;
         interception_v15_B.ia++) {
      if (interception_v15_B.f_i <= 4) {
        memset(&V[((interception_v15_B.ia << 2) + interception_v15_B.f_i) + -1],
               0, static_cast<uint32_T>(-interception_v15_B.f_i + 5) * sizeof
               (real_T));
      }

      interception_v15_B.f_i++;
    }

    for (interception_v15_B.ix0 = 0; interception_v15_B.ix0 < 16;
         interception_v15_B.ix0++) {
      T[interception_v15_B.ix0] = (rtNaN);
    }
  } else {
    memcpy(&T[0], &A[0], sizeof(real_T) << 4U);
    interception_v15_B.work[0] = 0.0;
    interception_v15_B.work[1] = 0.0;
    interception_v15_B.work[2] = 0.0;
    interception_v15_B.work[3] = 0.0;
    for (interception_v15_B.f_i = 0; interception_v15_B.f_i < 3;
         interception_v15_B.f_i++) {
      interception_v15_B.ia = interception_v15_B.f_i << 2;
      interception_v15_B.in = (interception_v15_B.f_i + 1) << 2;
      interception_v15_B.alpha1_tmp = (interception_v15_B.ia +
        interception_v15_B.f_i) + 1;
      interception_v15_B.A = T[interception_v15_B.alpha1_tmp];
      if (interception_v15_B.f_i + 3 <= 4) {
        interception_v15_B.ix0 = interception_v15_B.f_i + 3;
      } else {
        interception_v15_B.ix0 = 4;
      }

      interception_v15_B.ix0 += interception_v15_B.ia;
      interception_v15_B.tau[interception_v15_B.f_i] = 0.0;
      interception_v15_B.beta1 = interception_v15_xnrm2(2 -
        interception_v15_B.f_i, T, interception_v15_B.ix0);
      if (interception_v15_B.beta1 != 0.0) {
        interception_v15_B.beta1 = interception_v15_rt_hypotd_snf
          (interception_v15_B.A, interception_v15_B.beta1);
        if (interception_v15_B.A >= 0.0) {
          interception_v15_B.beta1 = -interception_v15_B.beta1;
        }

        if (fabs(interception_v15_B.beta1) < 1.0020841800044864E-292) {
          interception_v15_B.knt = 0;
          interception_v15_B.lastc = (interception_v15_B.ix0 -
            interception_v15_B.f_i) + 1;
          do {
            interception_v15_B.knt++;
            for (interception_v15_B.rowleft = interception_v15_B.ix0;
                 interception_v15_B.rowleft <= interception_v15_B.lastc;
                 interception_v15_B.rowleft++) {
              T[interception_v15_B.rowleft - 1] *= 9.9792015476736E+291;
            }

            interception_v15_B.beta1 *= 9.9792015476736E+291;
            interception_v15_B.A *= 9.9792015476736E+291;
          } while ((fabs(interception_v15_B.beta1) < 1.0020841800044864E-292) &&
                   (interception_v15_B.knt < 20));

          interception_v15_B.beta1 = interception_v15_rt_hypotd_snf
            (interception_v15_B.A, interception_v15_xnrm2(2 -
              interception_v15_B.f_i, T, interception_v15_B.ix0));
          if (interception_v15_B.A >= 0.0) {
            interception_v15_B.beta1 = -interception_v15_B.beta1;
          }

          interception_v15_B.tau[interception_v15_B.f_i] =
            (interception_v15_B.beta1 - interception_v15_B.A) /
            interception_v15_B.beta1;
          interception_v15_B.A = 1.0 / (interception_v15_B.A -
            interception_v15_B.beta1);
          for (interception_v15_B.rowleft = interception_v15_B.ix0;
               interception_v15_B.rowleft <= interception_v15_B.lastc;
               interception_v15_B.rowleft++) {
            T[interception_v15_B.rowleft - 1] *= interception_v15_B.A;
          }

          for (interception_v15_B.ix0 = 0; interception_v15_B.ix0 <
               interception_v15_B.knt; interception_v15_B.ix0++) {
            interception_v15_B.beta1 *= 1.0020841800044864E-292;
          }

          interception_v15_B.A = interception_v15_B.beta1;
        } else {
          interception_v15_B.tau[interception_v15_B.f_i] =
            (interception_v15_B.beta1 - interception_v15_B.A) /
            interception_v15_B.beta1;
          interception_v15_B.A = 1.0 / (interception_v15_B.A -
            interception_v15_B.beta1);
          interception_v15_B.knt = (interception_v15_B.ix0 -
            interception_v15_B.f_i) + 1;
          for (interception_v15_B.lastc = interception_v15_B.ix0;
               interception_v15_B.lastc <= interception_v15_B.knt;
               interception_v15_B.lastc++) {
            T[interception_v15_B.lastc - 1] *= interception_v15_B.A;
          }

          interception_v15_B.A = interception_v15_B.beta1;
        }
      }

      T[interception_v15_B.alpha1_tmp] = 1.0;
      interception_v15_B.ix0 = (interception_v15_B.f_i + interception_v15_B.ia)
        + 1;
      if (interception_v15_B.tau[interception_v15_B.f_i] != 0.0) {
        boolean_T exitg2;
        interception_v15_B.knt = 2 - interception_v15_B.f_i;
        interception_v15_B.lastc = (interception_v15_B.ix0 -
          interception_v15_B.f_i) + 2;
        while ((interception_v15_B.knt + 1 > 0) && (T[interception_v15_B.lastc] ==
                0.0)) {
          interception_v15_B.knt--;
          interception_v15_B.lastc--;
        }

        interception_v15_B.lastc = 4;
        exitg2 = false;
        while ((!exitg2) && (interception_v15_B.lastc > 0)) {
          int32_T exitg1;
          interception_v15_B.rowleft = interception_v15_B.in +
            interception_v15_B.lastc;
          interception_v15_B.c_ia = interception_v15_B.rowleft;
          do {
            exitg1 = 0;
            if (interception_v15_B.c_ia <= (interception_v15_B.knt << 2) +
                interception_v15_B.rowleft) {
              if (T[interception_v15_B.c_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                interception_v15_B.c_ia += 4;
              }
            } else {
              interception_v15_B.lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        interception_v15_B.knt = -1;
        interception_v15_B.lastc = 0;
      }

      if (interception_v15_B.knt + 1 > 0) {
        if (interception_v15_B.lastc != 0) {
          memset(&interception_v15_B.work[0], 0, static_cast<uint32_T>
                 (interception_v15_B.lastc) * sizeof(real_T));
          interception_v15_B.rowleft = interception_v15_B.ix0;
          interception_v15_B.c_ia = ((interception_v15_B.knt << 2) +
            interception_v15_B.in) + 1;
          for (interception_v15_B.iac = interception_v15_B.in + 1;
               interception_v15_B.iac <= interception_v15_B.c_ia;
               interception_v15_B.iac += 4) {
            interception_v15_B.l = interception_v15_B.iac +
              interception_v15_B.lastc;
            for (interception_v15_B.b_ia = interception_v15_B.iac;
                 interception_v15_B.b_ia < interception_v15_B.l;
                 interception_v15_B.b_ia++) {
              interception_v15_B.work_tmp = interception_v15_B.b_ia -
                interception_v15_B.iac;
              interception_v15_B.work[interception_v15_B.work_tmp] +=
                T[interception_v15_B.b_ia - 1] * T[interception_v15_B.rowleft];
            }

            interception_v15_B.rowleft++;
          }
        }

        if (!(-interception_v15_B.tau[interception_v15_B.f_i] == 0.0)) {
          interception_v15_B.rowleft = interception_v15_B.in;
          for (interception_v15_B.c_ia = 0; interception_v15_B.c_ia <=
               interception_v15_B.knt; interception_v15_B.c_ia++) {
            interception_v15_B.beta1 = T[interception_v15_B.ix0 +
              interception_v15_B.c_ia];
            if (interception_v15_B.beta1 != 0.0) {
              interception_v15_B.beta1 *=
                -interception_v15_B.tau[interception_v15_B.f_i];
              interception_v15_B.iac = interception_v15_B.lastc +
                interception_v15_B.rowleft;
              for (interception_v15_B.l = interception_v15_B.rowleft + 1;
                   interception_v15_B.l <= interception_v15_B.iac;
                   interception_v15_B.l++) {
                T[interception_v15_B.l - 1] += interception_v15_B.work
                  [(interception_v15_B.l - interception_v15_B.rowleft) - 1] *
                  interception_v15_B.beta1;
              }
            }

            interception_v15_B.rowleft += 4;
          }
        }
      }

      interception_v15_xzlarf(3 - interception_v15_B.f_i, 3 -
        interception_v15_B.f_i, (interception_v15_B.f_i + interception_v15_B.ia)
        + 2, interception_v15_B.tau[interception_v15_B.f_i], T,
        (interception_v15_B.f_i + interception_v15_B.in) + 2,
        interception_v15_B.work);
      T[interception_v15_B.alpha1_tmp] = interception_v15_B.A;
    }

    memcpy(&V[0], &T[0], sizeof(real_T) << 4U);
    for (interception_v15_B.f_i = 2; interception_v15_B.f_i >= 0;
         interception_v15_B.f_i--) {
      interception_v15_B.ia = (interception_v15_B.f_i + 1) << 2;
      for (interception_v15_B.in = 0; interception_v15_B.in <=
           interception_v15_B.f_i; interception_v15_B.in++) {
        V[interception_v15_B.ia + interception_v15_B.in] = 0.0;
      }

      for (interception_v15_B.in = interception_v15_B.f_i + 3;
           interception_v15_B.in < 5; interception_v15_B.in++) {
        interception_v15_B.alpha1_tmp = interception_v15_B.ia +
          interception_v15_B.in;
        V[interception_v15_B.alpha1_tmp - 1] = V[interception_v15_B.alpha1_tmp -
          5];
      }
    }

    V[1] = 0.0;
    V[2] = 0.0;
    V[3] = 0.0;
    V[0] = 1.0;
    interception_v15_B.work[0] = 0.0;
    interception_v15_B.work[1] = 0.0;
    interception_v15_B.work[2] = 0.0;
    interception_v15_B.work[3] = 0.0;
    for (interception_v15_B.f_i = 2; interception_v15_B.f_i >= 0;
         interception_v15_B.f_i--) {
      interception_v15_B.ia = ((interception_v15_B.f_i << 2) +
        interception_v15_B.f_i) + 5;
      if (interception_v15_B.f_i + 1 < 3) {
        V[interception_v15_B.ia] = 1.0;
        interception_v15_xzlarf(3 - interception_v15_B.f_i, 2 -
          interception_v15_B.f_i, interception_v15_B.ia + 1,
          interception_v15_B.tau[interception_v15_B.f_i], V,
          interception_v15_B.ia + 5, interception_v15_B.work);
        interception_v15_B.in = (interception_v15_B.ia - interception_v15_B.f_i)
          + 3;
        for (interception_v15_B.alpha1_tmp = interception_v15_B.ia + 2;
             interception_v15_B.alpha1_tmp <= interception_v15_B.in;
             interception_v15_B.alpha1_tmp++) {
          V[interception_v15_B.alpha1_tmp - 1] *=
            -interception_v15_B.tau[interception_v15_B.f_i];
        }
      }

      V[interception_v15_B.ia] = 1.0 -
        interception_v15_B.tau[interception_v15_B.f_i];
      for (interception_v15_B.in = 0; interception_v15_B.in <
           interception_v15_B.f_i; interception_v15_B.in++) {
        V[(interception_v15_B.ia - interception_v15_B.in) - 1] = 0.0;
      }
    }

    interception_v15_xhseqr(T, V);
  }
}

// Model step function
void interception_v15_step(void)
{
  boolean_T exitg1;
  boolean_T paired;

  // Outputs for Atomic SubSystem: '<Root>/Missile Velocity'
  // MATLABSystem: '<S10>/SourceBlock'
  paired = Sub_interception_v15_179.getLatestMessage
    (&interception_v15_B.BusAssignment4);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S29>/Enable'

  if (paired) {
    // SignalConversion generated from: '<S29>/In1'
    interception_v15_B.In1_m = interception_v15_B.BusAssignment4;
  }

  // End of MATLABSystem: '<S10>/SourceBlock'
  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Missile Velocity'

  // Outputs for Atomic SubSystem: '<Root>/Missile Position'
  // MATLABSystem: '<S9>/SourceBlock'
  paired = Sub_interception_v15_180.getLatestMessage
    (&interception_v15_B.BusAssignment_h);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S28>/Enable'

  if (paired) {
    // SignalConversion generated from: '<S28>/In1'
    interception_v15_B.In1 = interception_v15_B.BusAssignment_h;
  }

  // End of MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Missile Position'

  // RateTransition: '<Root>/Rate Transition'
  if (interception_v15_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<Root>/Rate Transition'
    interception_v15_B.RateTransition[0] =
      interception_v15_DW.RateTransition_Buffer0[0];
    interception_v15_B.RateTransition[1] =
      interception_v15_DW.RateTransition_Buffer0[1];
    interception_v15_B.RateTransition[2] =
      interception_v15_DW.RateTransition_Buffer0[2];
  }

  // End of RateTransition: '<Root>/Rate Transition'

  // Saturate: '<Root>/Saturation'
  if (interception_v15_B.RateTransition[0] >
      interception_v15_P.Saturation_UpperSat[0]) {
    interception_v15_B.rtb_Saturation_idx_0 =
      interception_v15_P.Saturation_UpperSat[0];
  } else if (interception_v15_B.RateTransition[0] <
             interception_v15_P.Saturation_LowerSat[0]) {
    interception_v15_B.rtb_Saturation_idx_0 =
      interception_v15_P.Saturation_LowerSat[0];
  } else {
    interception_v15_B.rtb_Saturation_idx_0 = interception_v15_B.RateTransition
      [0];
  }

  if (interception_v15_B.RateTransition[1] >
      interception_v15_P.Saturation_UpperSat[1]) {
    interception_v15_B.rtb_Saturation_idx_1 =
      interception_v15_P.Saturation_UpperSat[1];
  } else if (interception_v15_B.RateTransition[1] <
             interception_v15_P.Saturation_LowerSat[1]) {
    interception_v15_B.rtb_Saturation_idx_1 =
      interception_v15_P.Saturation_LowerSat[1];
  } else {
    interception_v15_B.rtb_Saturation_idx_1 = interception_v15_B.RateTransition
      [1];
  }

  if (interception_v15_B.RateTransition[2] >
      interception_v15_P.Saturation_UpperSat[2]) {
    interception_v15_B.rtb_Saturation_idx_2 =
      interception_v15_P.Saturation_UpperSat[2];
  } else if (interception_v15_B.RateTransition[2] <
             interception_v15_P.Saturation_LowerSat[2]) {
    interception_v15_B.rtb_Saturation_idx_2 =
      interception_v15_P.Saturation_LowerSat[2];
  } else {
    interception_v15_B.rtb_Saturation_idx_2 = interception_v15_B.RateTransition
      [2];
  }

  // End of Saturate: '<Root>/Saturation'

  // Sum: '<Root>/Add - Pose'
  interception_v15_B.AddPose[0] = interception_v15_B.rtb_Saturation_idx_0 -
    interception_v15_B.In1.Pose.Position.X;
  interception_v15_B.AddPose[1] = interception_v15_B.rtb_Saturation_idx_1 -
    interception_v15_B.In1.Pose.Position.Y;
  interception_v15_B.AddPose[2] = interception_v15_B.rtb_Saturation_idx_2 -
    interception_v15_B.In1.Pose.Position.Z;

  // MATLABSystem: '<S22>/Get Parameter'
  ParamGet_interception_v15_269.get_parameter(&interception_v15_B.y_idx_0);

  // MATLABSystem: '<S22>/Get Parameter1'
  ParamGet_interception_v15_270.get_parameter(&interception_v15_B.y_idx_1);

  // MATLABSystem: '<S22>/Get Parameter2'
  ParamGet_interception_v15_271.get_parameter(&interception_v15_B.y_idx_2);

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   Delay: '<Root>/Delay'

  if ((interception_v15_DW.Delay_DSTATE[0U] < 10.0) && (interception_v15_DW.flag
       == 0.0)) {
    interception_v15_B.y_idx_0 = 0.0;
    interception_v15_B.y_idx_1 = 0.0;
    interception_v15_B.y_idx_2 = 0.0;
    interception_v15_B.active = 0;
  } else {
    interception_v15_DW.flag = 1.0;
    interception_v15_B.active = 1;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function2'

  // SignalConversion generated from: '<S18>/Math Function' incorporates:
  //   MATLAB Function: '<S6>/Controller'
  //   SignalConversion generated from: '<S24>/ SFunction '

  interception_v15_B.MathFunction_j[0] = interception_v15_B.In1_m.Twist.Linear.X;
  interception_v15_B.MathFunction_j[1] = interception_v15_B.In1_m.Twist.Linear.Y;
  interception_v15_B.MathFunction_j[2] = interception_v15_B.In1_m.Twist.Linear.Z;

  // Sum: '<Root>/Add - Velocity' incorporates:
  //   SignalConversion generated from: '<S18>/Math Function'

  interception_v15_B.AddVelocity[0] = interception_v15_B.y_idx_0 -
    interception_v15_B.In1_m.Twist.Linear.X;
  interception_v15_B.AddVelocity[1] = interception_v15_B.y_idx_1 -
    interception_v15_B.In1_m.Twist.Linear.Y;
  interception_v15_B.AddVelocity[2] = interception_v15_B.y_idx_2 -
    interception_v15_B.In1_m.Twist.Linear.Z;

  // MATLABSystem: '<Root>/Get Parameter6'
  ParamGet_interception_v15_480.get_parameter(&interception_v15_B.zb_des_idx_2);

  // MATLABSystem: '<Root>/Get Parameter10'
  ParamGet_interception_v15_506.get_parameter(&interception_v15_B.b_absx);

  // MATLABSystem: '<Root>/Get Parameter2'
  ParamGet_interception_v15_276.get_parameter(&interception_v15_B.tgo4);

  // MATLAB Function: '<Root>/Numeric Calculation of Tgo' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter10'
  //   MATLABSystem: '<Root>/Get Parameter6'

  interception_v15_B.rtb_u_idx_2 = interception_v15_norm
    (interception_v15_B.AddVelocity);
  interception_v15_B.rtb_u_idx_0 = interception_v15_norm
    (interception_v15_B.AddPose);
  interception_v15_B.c[0] = interception_v15_B.zb_des_idx_2 *
    interception_v15_B.zb_des_idx_2 / 4.0;
  interception_v15_B.c[1] = 0.0;
  interception_v15_B.c[2] = -(interception_v15_B.rtb_u_idx_2 *
    interception_v15_B.rtb_u_idx_2) + interception_v15_B.b_absx *
    interception_v15_B.zb_des_idx_2;
  interception_v15_B.c[3] = (-2.0 * interception_v15_B.AddPose[0] *
    interception_v15_B.AddVelocity[0] + -2.0 * interception_v15_B.AddPose[1] *
    interception_v15_B.AddVelocity[1]) + -2.0 * interception_v15_B.AddPose[2] *
    interception_v15_B.AddVelocity[2];
  interception_v15_B.c[4] = -(interception_v15_B.rtb_u_idx_0 *
    interception_v15_B.rtb_u_idx_0) + interception_v15_B.b_absx *
    interception_v15_B.b_absx;
  memset(&interception_v15_B.tgoroots_data[0], 0, sizeof(creal_T) << 2U);
  interception_v15_B.k1 = 1;
  while ((interception_v15_B.k1 <= 5) &&
         (!(interception_v15_B.c[interception_v15_B.k1 - 1] != 0.0))) {
    interception_v15_B.k1++;
  }

  interception_v15_B.k2 = 5;
  while ((interception_v15_B.k2 >= interception_v15_B.k1) &&
         (!(interception_v15_B.c[interception_v15_B.k2 - 1] != 0.0))) {
    interception_v15_B.k2--;
  }

  if (interception_v15_B.k1 < interception_v15_B.k2) {
    interception_v15_B.companDim = interception_v15_B.k2 - interception_v15_B.k1;
    exitg1 = false;
    while ((!exitg1) && (interception_v15_B.companDim > 0)) {
      boolean_T exitg2;
      interception_v15_B.j = 0;
      exitg2 = false;
      while ((!exitg2) && (interception_v15_B.j + 1 <=
                           interception_v15_B.companDim)) {
        interception_v15_B.ctmp[interception_v15_B.j] =
          interception_v15_B.c[interception_v15_B.k1 + interception_v15_B.j] /
          interception_v15_B.c[interception_v15_B.k1 - 1];
        if (rtIsInf(fabs(interception_v15_B.ctmp[interception_v15_B.j]))) {
          exitg2 = true;
        } else {
          interception_v15_B.j++;
        }
      }

      if (interception_v15_B.j + 1 > interception_v15_B.companDim) {
        exitg1 = true;
      } else {
        interception_v15_B.k1++;
        interception_v15_B.companDim--;
      }
    }

    if (interception_v15_B.companDim < 1) {
      if (5 - interception_v15_B.k2 < 1) {
        interception_v15_B.tgoroots_size = 0;
      } else {
        interception_v15_B.tgoroots_size = 5 - interception_v15_B.k2;
      }
    } else {
      interception_v15_B.c_a_size[0] = interception_v15_B.companDim;
      interception_v15_B.c_a_size[1] = interception_v15_B.companDim;
      interception_v15_B.k1 = interception_v15_B.companDim *
        interception_v15_B.companDim;
      memset(&interception_v15_B.c_a_data[0], 0, static_cast<uint32_T>
             (interception_v15_B.k1) * sizeof(real_T));
      for (interception_v15_B.j = 0; interception_v15_B.j <=
           interception_v15_B.companDim - 2; interception_v15_B.j++) {
        interception_v15_B.k1 = interception_v15_B.companDim *
          interception_v15_B.j;
        interception_v15_B.c_a_data[interception_v15_B.k1] =
          -interception_v15_B.ctmp[interception_v15_B.j];
        interception_v15_B.c_a_data[(interception_v15_B.j +
          interception_v15_B.k1) + 1] = 1.0;
      }

      interception_v15_B.c_a_data[interception_v15_B.companDim *
        (interception_v15_B.companDim - 1)] =
        -interception_v15_B.ctmp[interception_v15_B.companDim - 1];
      interception_v15_B.k1 = 4 - interception_v15_B.k2;
      if (interception_v15_B.k1 >= 0) {
        memset(&interception_v15_B.tgoroots_data[0], 0, static_cast<uint32_T>
               (interception_v15_B.k1 + 1) * sizeof(creal_T));
      }

      if (interception_v15_B.companDim == 1) {
        for (interception_v15_B.j = 0; interception_v15_B.j <
             interception_v15_B.companDim; interception_v15_B.j++) {
          interception_v15_B.eiga_data[interception_v15_B.j].re =
            interception_v15_B.c_a_data[interception_v15_B.j];
          interception_v15_B.eiga_data[interception_v15_B.j].im = 0.0;
        }
      } else {
        boolean_T d_paired;
        interception_v15_xzgeev_f(interception_v15_B.c_a_data,
          interception_v15_B.c_a_size, &interception_v15_B.j,
          interception_v15_B.eiga_data, &interception_v15_B.eiga_size,
          interception_v15_B.vwork_data, &interception_v15_B.vwork_size);
        for (interception_v15_B.j = 0; interception_v15_B.j <
             interception_v15_B.companDim; interception_v15_B.j++) {
          interception_v15_B.eiga =
            interception_v15_B.eiga_data[interception_v15_B.j];
          interception_v15_B.rtb_u_idx_0 = interception_v15_B.eiga.re;
          interception_v15_B.rtb_u_idx_2 =
            interception_v15_B.vwork_data[interception_v15_B.j].re;
          interception_v15_B.rtb_u_idx_1 =
            interception_v15_B.vwork_data[interception_v15_B.j].im;
          if (interception_v15_B.rtb_u_idx_1 == 0.0) {
            if (interception_v15_B.eiga.im == 0.0) {
              interception_v15_B.eiga.re /= interception_v15_B.rtb_u_idx_2;
              interception_v15_B.eiga.im = 0.0;
            } else if (interception_v15_B.eiga.re == 0.0) {
              interception_v15_B.eiga.re = 0.0;
              interception_v15_B.eiga.im /= interception_v15_B.rtb_u_idx_2;
            } else {
              interception_v15_B.eiga.re /= interception_v15_B.rtb_u_idx_2;
              interception_v15_B.eiga.im /= interception_v15_B.rtb_u_idx_2;
            }
          } else if (interception_v15_B.rtb_u_idx_2 == 0.0) {
            if (interception_v15_B.eiga.re == 0.0) {
              interception_v15_B.eiga.re = interception_v15_B.eiga.im /
                interception_v15_B.rtb_u_idx_1;
              interception_v15_B.eiga.im = 0.0;
            } else if (interception_v15_B.eiga.im == 0.0) {
              interception_v15_B.eiga.re = 0.0;
              interception_v15_B.eiga.im = -(interception_v15_B.rtb_u_idx_0 /
                interception_v15_B.rtb_u_idx_1);
            } else {
              interception_v15_B.eiga.re = interception_v15_B.eiga.im /
                interception_v15_B.rtb_u_idx_1;
              interception_v15_B.eiga.im = -(interception_v15_B.rtb_u_idx_0 /
                interception_v15_B.rtb_u_idx_1);
            }
          } else {
            interception_v15_B.Tan = fabs(interception_v15_B.rtb_u_idx_2);
            interception_v15_B.zb_des_idx_2 = fabs
              (interception_v15_B.rtb_u_idx_1);
            if (interception_v15_B.Tan > interception_v15_B.zb_des_idx_2) {
              interception_v15_B.Tan = interception_v15_B.rtb_u_idx_1 /
                interception_v15_B.rtb_u_idx_2;
              interception_v15_B.rtb_u_idx_1 = interception_v15_B.Tan *
                interception_v15_B.rtb_u_idx_1 + interception_v15_B.rtb_u_idx_2;
              interception_v15_B.eiga.re = (interception_v15_B.Tan *
                interception_v15_B.eiga.im + interception_v15_B.eiga.re) /
                interception_v15_B.rtb_u_idx_1;
              interception_v15_B.eiga.im = (interception_v15_B.eiga.im -
                interception_v15_B.Tan * interception_v15_B.rtb_u_idx_0) /
                interception_v15_B.rtb_u_idx_1;
            } else if (interception_v15_B.zb_des_idx_2 == interception_v15_B.Tan)
            {
              interception_v15_B.rtb_u_idx_2 = interception_v15_B.rtb_u_idx_2 >
                0.0 ? 0.5 : -0.5;
              interception_v15_B.rtb_u_idx_1 = interception_v15_B.rtb_u_idx_1 >
                0.0 ? 0.5 : -0.5;
              interception_v15_B.eiga.re = (interception_v15_B.eiga.re *
                interception_v15_B.rtb_u_idx_2 + interception_v15_B.eiga.im *
                interception_v15_B.rtb_u_idx_1) / interception_v15_B.Tan;
              interception_v15_B.eiga.im = (interception_v15_B.eiga.im *
                interception_v15_B.rtb_u_idx_2 - interception_v15_B.rtb_u_idx_0 *
                interception_v15_B.rtb_u_idx_1) / interception_v15_B.Tan;
            } else {
              interception_v15_B.Tan = interception_v15_B.rtb_u_idx_2 /
                interception_v15_B.rtb_u_idx_1;
              interception_v15_B.rtb_u_idx_1 += interception_v15_B.Tan *
                interception_v15_B.rtb_u_idx_2;
              interception_v15_B.eiga.re = (interception_v15_B.Tan *
                interception_v15_B.eiga.re + interception_v15_B.eiga.im) /
                interception_v15_B.rtb_u_idx_1;
              interception_v15_B.eiga.im = (interception_v15_B.Tan *
                interception_v15_B.eiga.im - interception_v15_B.rtb_u_idx_0) /
                interception_v15_B.rtb_u_idx_1;
            }
          }

          interception_v15_B.eiga_data[interception_v15_B.j] =
            interception_v15_B.eiga;
        }

        interception_v15_B.alpha1_size = interception_v15_B.eiga_size;
        interception_v15_B.k1 = interception_v15_B.eiga_size;
        if (interception_v15_B.k1 - 1 >= 0) {
          memcpy(&interception_v15_B.alpha1_data[0],
                 &interception_v15_B.eiga_data[0], static_cast<uint32_T>
                 (interception_v15_B.k1) * sizeof(creal_T));
        }

        interception_v15_B.k1 = 2;
        if (interception_v15_B.eiga_size != 1) {
          interception_v15_B.k1 = 1;
        }

        paired = true;
        if (interception_v15_B.eiga_size == 1) {
          paired = interception_v15_cplxpairv(interception_v15_B.alpha1_data,
            &interception_v15_B.alpha1_size, 1.4210854715202004E-14);
        } else {
          if (interception_v15_B.k1 <= 1) {
            interception_v15_B.j = interception_v15_B.eiga_size;
          } else {
            interception_v15_B.j = 1;
          }

          if (interception_v15_B.j != 1) {
            paired = interception_v15_cplxpairv(interception_v15_B.alpha1_data,
              &interception_v15_B.alpha1_size, 1.4210854715202004E-14);
          } else {
            if (interception_v15_B.k1 <= 1) {
              interception_v15_B.j = interception_v15_B.eiga_size;
            } else {
              interception_v15_B.j = 1;
            }

            interception_v15_B.b_vstride = interception_v15_B.j - 1;
            interception_v15_B.vstride = 1;
            for (interception_v15_B.j = 0; interception_v15_B.j <=
                 interception_v15_B.k1 - 2; interception_v15_B.j++) {
              interception_v15_B.vstride *= interception_v15_B.eiga_size;
            }

            if (interception_v15_B.k1 <= 1) {
              interception_v15_B.j = interception_v15_B.eiga_size;
            } else {
              interception_v15_B.j = 1;
            }

            interception_v15_B.vwork_size = interception_v15_B.j;
            for (interception_v15_B.k1 = 0; interception_v15_B.k1 <
                 interception_v15_B.vstride; interception_v15_B.k1++) {
              for (interception_v15_B.j = 0; interception_v15_B.j <=
                   interception_v15_B.b_vstride; interception_v15_B.j++) {
                interception_v15_B.vwork_data[interception_v15_B.j] =
                  interception_v15_B.alpha1_data[interception_v15_B.j *
                  interception_v15_B.vstride + interception_v15_B.k1];
              }

              d_paired = interception_v15_cplxpairv
                (interception_v15_B.vwork_data, &interception_v15_B.vwork_size,
                 1.4210854715202004E-14);
              for (interception_v15_B.j = 0; interception_v15_B.j <=
                   interception_v15_B.b_vstride; interception_v15_B.j++) {
                interception_v15_B.alpha1_data[interception_v15_B.k1 +
                  interception_v15_B.j * interception_v15_B.vstride] =
                  interception_v15_B.vwork_data[interception_v15_B.j];
              }

              if ((!paired) || (!d_paired)) {
                paired = false;
              }
            }
          }
        }

        if (!paired) {
          interception_v15_B.vstride = 2;
          if (interception_v15_B.alpha1_size != 1) {
            interception_v15_B.vstride = 1;
          }

          paired = true;
          if (interception_v15_B.alpha1_size == 1) {
            paired = interception_v15_cplxpairv(interception_v15_B.alpha1_data,
              &interception_v15_B.alpha1_size, 3.637978807091713E-12);
          } else {
            if (interception_v15_B.vstride <= 1) {
              interception_v15_B.j = interception_v15_B.alpha1_size;
            } else {
              interception_v15_B.j = 1;
            }

            if (interception_v15_B.j != 1) {
              paired = interception_v15_cplxpairv(interception_v15_B.alpha1_data,
                &interception_v15_B.alpha1_size, 3.637978807091713E-12);
            } else {
              if (interception_v15_B.vstride <= 1) {
                interception_v15_B.j = interception_v15_B.alpha1_size;
              } else {
                interception_v15_B.j = 1;
              }

              interception_v15_B.k1 = interception_v15_B.j - 1;
              interception_v15_B.b_vstride = 1;
              for (interception_v15_B.j = 0; interception_v15_B.j <=
                   interception_v15_B.vstride - 2; interception_v15_B.j++) {
                interception_v15_B.b_vstride *= interception_v15_B.alpha1_size;
              }

              if (interception_v15_B.vstride <= 1) {
                interception_v15_B.j = interception_v15_B.alpha1_size;
              } else {
                interception_v15_B.j = 1;
              }

              interception_v15_B.vwork_size = interception_v15_B.j;
              for (interception_v15_B.j = 0; interception_v15_B.j <
                   interception_v15_B.b_vstride; interception_v15_B.j++) {
                for (interception_v15_B.vstride = 0; interception_v15_B.vstride <=
                     interception_v15_B.k1; interception_v15_B.vstride++) {
                  interception_v15_B.vwork_data[interception_v15_B.vstride] =
                    interception_v15_B.alpha1_data[interception_v15_B.vstride *
                    interception_v15_B.b_vstride + interception_v15_B.j];
                }

                d_paired = interception_v15_cplxpairv
                  (interception_v15_B.vwork_data, &interception_v15_B.vwork_size,
                   3.637978807091713E-12);
                for (interception_v15_B.vstride = 0; interception_v15_B.vstride <=
                     interception_v15_B.k1; interception_v15_B.vstride++) {
                  interception_v15_B.alpha1_data[interception_v15_B.j +
                    interception_v15_B.vstride * interception_v15_B.b_vstride] =
                    interception_v15_B.vwork_data[interception_v15_B.vstride];
                }

                if ((!paired) || (!d_paired)) {
                  paired = false;
                }
              }
            }
          }
        }

        if (paired) {
          for (interception_v15_B.j = 0; interception_v15_B.j <
               interception_v15_B.companDim; interception_v15_B.j++) {
            interception_v15_B.eiga_data[interception_v15_B.j] =
              interception_v15_B.alpha1_data[(interception_v15_B.companDim -
              interception_v15_B.j) - 1];
          }
        }
      }

      for (interception_v15_B.j = 0; interception_v15_B.j <
           interception_v15_B.companDim; interception_v15_B.j++) {
        interception_v15_B.tgoroots_data[(interception_v15_B.j -
          interception_v15_B.k2) + 5] =
          interception_v15_B.eiga_data[interception_v15_B.j];
      }

      interception_v15_B.tgoroots_size = (interception_v15_B.companDim -
        interception_v15_B.k2) + 5;
    }
  } else if (5 - interception_v15_B.k2 < 1) {
    interception_v15_B.tgoroots_size = 0;
  } else {
    interception_v15_B.tgoroots_size = 5 - interception_v15_B.k2;
  }

  interception_v15_B.companDim = interception_v15_B.tgoroots_size;
  interception_v15_B.k1 = interception_v15_B.tgoroots_size;
  for (interception_v15_B.j = 0; interception_v15_B.j < interception_v15_B.k1;
       interception_v15_B.j++) {
    interception_v15_B.x_data[interception_v15_B.j] =
      interception_v15_B.tgoroots_data[interception_v15_B.j].im;
  }

  for (interception_v15_B.k2 = 0; interception_v15_B.k2 <
       interception_v15_B.companDim; interception_v15_B.k2++) {
    interception_v15_B.y_data[interception_v15_B.k2] = fabs
      (interception_v15_B.x_data[interception_v15_B.k2]);
  }

  interception_v15_B.bb_size = interception_v15_B.tgoroots_size;
  interception_v15_B.k1 = interception_v15_B.tgoroots_size;
  for (interception_v15_B.j = 0; interception_v15_B.j < interception_v15_B.k1;
       interception_v15_B.j++) {
    interception_v15_B.bb_data[interception_v15_B.j] =
      ((interception_v15_B.y_data[interception_v15_B.j] < 1.0E-9) &&
       (interception_v15_B.tgoroots_data[interception_v15_B.j].re >= 0.0));
  }

  interception_v15_B.companDim = interception_v15_B.bb_size;
  interception_v15_B.j = 0;
  for (interception_v15_B.k2 = 0; interception_v15_B.k2 <
       interception_v15_B.companDim; interception_v15_B.k2++) {
    if (interception_v15_B.bb_data[interception_v15_B.k2]) {
      interception_v15_B.j++;
    }
  }

  if (interception_v15_B.j != 0) {
    interception_v15_B.k2 = interception_v15_B.bb_size - 1;
    interception_v15_B.j = 0;
    for (interception_v15_B.companDim = 0; interception_v15_B.companDim <=
         interception_v15_B.k2; interception_v15_B.companDim++) {
      if (interception_v15_B.bb_data[interception_v15_B.companDim]) {
        interception_v15_B.j++;
      }
    }

    interception_v15_B.k1 = interception_v15_B.j;
    interception_v15_B.j = 0;
    for (interception_v15_B.companDim = 0; interception_v15_B.companDim <=
         interception_v15_B.k2; interception_v15_B.companDim++) {
      if (interception_v15_B.bb_data[interception_v15_B.companDim]) {
        interception_v15_B.b_data[interception_v15_B.j] = static_cast<int8_T>
          (interception_v15_B.companDim + 1);
        interception_v15_B.j++;
      }
    }

    for (interception_v15_B.j = 0; interception_v15_B.j < interception_v15_B.k1;
         interception_v15_B.j++) {
      interception_v15_B.x_data[interception_v15_B.j] =
        interception_v15_B.tgoroots_data[interception_v15_B.b_data[interception_v15_B.j]
        - 1].re;
    }

    if (static_cast<uint8_T>(interception_v15_B.k1 - 1) + 1 <= 2) {
      if (static_cast<uint8_T>(interception_v15_B.k1 - 1) + 1 == 1) {
        interception_v15_B.tgo4 = interception_v15_B.x_data[0];
      } else {
        interception_v15_B.tgo4 =
          interception_v15_B.x_data[interception_v15_B.k1 - 1];
        if (interception_v15_B.x_data[0] > interception_v15_B.tgo4) {
        } else if (rtIsNaN(interception_v15_B.x_data[0])) {
          if (!rtIsNaN(interception_v15_B.tgo4)) {
          } else {
            interception_v15_B.tgo4 = interception_v15_B.x_data[0];
          }
        } else {
          interception_v15_B.tgo4 = interception_v15_B.x_data[0];
        }
      }
    } else {
      if (!rtIsNaN(interception_v15_B.x_data[0])) {
        interception_v15_B.k2 = 1;
      } else {
        interception_v15_B.k2 = 0;
        interception_v15_B.j = 2;
        exitg1 = false;
        while ((!exitg1) && (interception_v15_B.j <= interception_v15_B.k1)) {
          if (!rtIsNaN(interception_v15_B.x_data[interception_v15_B.j - 1])) {
            interception_v15_B.k2 = interception_v15_B.j;
            exitg1 = true;
          } else {
            interception_v15_B.j++;
          }
        }
      }

      if (interception_v15_B.k2 == 0) {
        interception_v15_B.tgo4 = interception_v15_B.x_data[0];
      } else {
        interception_v15_B.tgo4 =
          interception_v15_B.x_data[interception_v15_B.k2 - 1];
        for (interception_v15_B.j = interception_v15_B.k2 + 1;
             interception_v15_B.j <= interception_v15_B.k1; interception_v15_B.j
             ++) {
          interception_v15_B.Tan =
            interception_v15_B.x_data[interception_v15_B.j - 1];
          if (interception_v15_B.tgo4 > interception_v15_B.Tan) {
            interception_v15_B.tgo4 = interception_v15_B.Tan;
          }
        }
      }
    }
  }

  // End of MATLAB Function: '<Root>/Numeric Calculation of Tgo'

  // MATLABSystem: '<Root>/Get Parameter4'
  ParamGet_interception_v15_479.get_parameter(&interception_v15_B.zb_des_idx_2);

  // MATLABSystem: '<Root>/Get Parameter7'
  ParamGet_interception_v15_482.get_parameter(&interception_v15_B.b_absx);

  // MATLABSystem: '<Root>/Get Parameter11'
  ParamGet_interception_v15_583.get_parameter(&interception_v15_B.absx);

  // MATLAB Function: '<S6>/Controller' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter11'
  //   MATLABSystem: '<Root>/Get Parameter4'
  //   MATLABSystem: '<Root>/Get Parameter7'
  //   SignalConversion generated from: '<S18>/Math Function'
  //   SignalConversion generated from: '<S24>/ SFunction '

  interception_v15_B.rtb_u_idx_2 = interception_v15_B.absx *
    interception_v15_norm(interception_v15_B.MathFunction_j);
  interception_v15_B.MathFunction_j[0] = interception_v15_B.tgo4 *
    interception_v15_B.AddVelocity[0] + interception_v15_B.AddPose[0];
  interception_v15_B.MathFunction_j[1] = interception_v15_B.tgo4 *
    interception_v15_B.AddVelocity[1] + interception_v15_B.AddPose[1];
  interception_v15_B.MathFunction_j[2] = interception_v15_B.tgo4 *
    interception_v15_B.AddVelocity[2] + interception_v15_B.AddPose[2];
  interception_v15_B.Tan = interception_v15_norm
    (interception_v15_B.MathFunction_j);
  interception_v15_B.rtb_u_idx_0 = interception_v15_B.zb_des_idx_2 *
    interception_v15_B.MathFunction_j[0] / interception_v15_B.Tan +
    interception_v15_B.rtb_u_idx_2 * interception_v15_B.In1_m.Twist.Linear.X;
  interception_v15_B.rtb_u_idx_1 = interception_v15_B.zb_des_idx_2 *
    interception_v15_B.MathFunction_j[1] / interception_v15_B.Tan +
    interception_v15_B.rtb_u_idx_2 * interception_v15_B.In1_m.Twist.Linear.Y;
  interception_v15_B.rtb_u_idx_2 = (interception_v15_B.zb_des_idx_2 *
    interception_v15_B.MathFunction_j[2] / interception_v15_B.Tan +
    interception_v15_B.rtb_u_idx_2 * interception_v15_B.In1_m.Twist.Linear.Z) +
    interception_v15_B.b_absx;

  // Trigonometry: '<S6>/Tan' incorporates:
  //   Product: '<S6>/Divide1'

  interception_v15_B.Tan = atan(interception_v15_B.AddPose[0] /
    interception_v15_B.AddPose[1]);

  // MATLAB Function: '<S6>/MATLAB Function'
  if (rtIsInf(interception_v15_B.Tan) || rtIsNaN(interception_v15_B.Tan)) {
    interception_v15_B.Tan = (rtNaN);
    interception_v15_B.yb_des_idx_1 = (rtNaN);
  } else {
    int8_T n;
    interception_v15_B.zb_des_idx_2 = rt_remd_snf(interception_v15_B.Tan, 360.0);
    interception_v15_B.Tan = interception_v15_B.zb_des_idx_2;
    interception_v15_B.b_absx = fabs(interception_v15_B.zb_des_idx_2);
    interception_v15_B.absx = interception_v15_B.b_absx;
    if (interception_v15_B.b_absx > 180.0) {
      if (interception_v15_B.zb_des_idx_2 > 0.0) {
        interception_v15_B.Tan = interception_v15_B.zb_des_idx_2 - 360.0;
      } else {
        interception_v15_B.Tan = interception_v15_B.zb_des_idx_2 + 360.0;
      }

      interception_v15_B.absx = fabs(interception_v15_B.Tan);
    }

    if (interception_v15_B.absx <= 45.0) {
      interception_v15_B.Tan *= 0.017453292519943295;
      n = 0;
    } else if (interception_v15_B.absx <= 135.0) {
      if (interception_v15_B.Tan > 0.0) {
        interception_v15_B.Tan = (interception_v15_B.Tan - 90.0) *
          0.017453292519943295;
        n = 1;
      } else {
        interception_v15_B.Tan = (interception_v15_B.Tan + 90.0) *
          0.017453292519943295;
        n = -1;
      }
    } else if (interception_v15_B.Tan > 0.0) {
      interception_v15_B.Tan = (interception_v15_B.Tan - 180.0) *
        0.017453292519943295;
      n = 2;
    } else {
      interception_v15_B.Tan = (interception_v15_B.Tan + 180.0) *
        0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      interception_v15_B.Tan = cos(interception_v15_B.Tan);
      break;

     case 1:
      interception_v15_B.Tan = -sin(interception_v15_B.Tan);
      break;

     case -1:
      interception_v15_B.Tan = sin(interception_v15_B.Tan);
      break;

     default:
      interception_v15_B.Tan = -cos(interception_v15_B.Tan);
      break;
    }

    if (interception_v15_B.b_absx > 180.0) {
      if (interception_v15_B.zb_des_idx_2 > 0.0) {
        interception_v15_B.zb_des_idx_2 -= 360.0;
      } else {
        interception_v15_B.zb_des_idx_2 += 360.0;
      }

      interception_v15_B.b_absx = fabs(interception_v15_B.zb_des_idx_2);
    }

    if (interception_v15_B.b_absx <= 45.0) {
      interception_v15_B.zb_des_idx_2 *= 0.017453292519943295;
      n = 0;
    } else if (interception_v15_B.b_absx <= 135.0) {
      if (interception_v15_B.zb_des_idx_2 > 0.0) {
        interception_v15_B.zb_des_idx_2 = (interception_v15_B.zb_des_idx_2 -
          90.0) * 0.017453292519943295;
        n = 1;
      } else {
        interception_v15_B.zb_des_idx_2 = (interception_v15_B.zb_des_idx_2 +
          90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (interception_v15_B.zb_des_idx_2 > 0.0) {
      interception_v15_B.zb_des_idx_2 = (interception_v15_B.zb_des_idx_2 - 180.0)
        * 0.017453292519943295;
      n = 2;
    } else {
      interception_v15_B.zb_des_idx_2 = (interception_v15_B.zb_des_idx_2 + 180.0)
        * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      interception_v15_B.yb_des_idx_1 = sin(interception_v15_B.zb_des_idx_2);
      break;

     case 1:
      interception_v15_B.yb_des_idx_1 = cos(interception_v15_B.zb_des_idx_2);
      break;

     case -1:
      interception_v15_B.yb_des_idx_1 = -cos(interception_v15_B.zb_des_idx_2);
      break;

     default:
      interception_v15_B.yb_des_idx_1 = -sin(interception_v15_B.zb_des_idx_2);
      break;
    }
  }

  interception_v15_B.absx = 3.3121686421112381E-170;
  interception_v15_B.absxk = fabs(interception_v15_B.rtb_u_idx_0);
  if (interception_v15_B.absxk > 3.3121686421112381E-170) {
    interception_v15_B.yb_des_idx_0 = 1.0;
    interception_v15_B.absx = interception_v15_B.absxk;
  } else {
    interception_v15_B.t = interception_v15_B.absxk / 3.3121686421112381E-170;
    interception_v15_B.yb_des_idx_0 = interception_v15_B.t *
      interception_v15_B.t;
  }

  interception_v15_B.absxk = fabs(interception_v15_B.rtb_u_idx_1);
  if (interception_v15_B.absxk > interception_v15_B.absx) {
    interception_v15_B.t = interception_v15_B.absx / interception_v15_B.absxk;
    interception_v15_B.yb_des_idx_0 = interception_v15_B.yb_des_idx_0 *
      interception_v15_B.t * interception_v15_B.t + 1.0;
    interception_v15_B.absx = interception_v15_B.absxk;
  } else {
    interception_v15_B.t = interception_v15_B.absxk / interception_v15_B.absx;
    interception_v15_B.yb_des_idx_0 += interception_v15_B.t *
      interception_v15_B.t;
  }

  interception_v15_B.absxk = fabs(interception_v15_B.rtb_u_idx_2);
  if (interception_v15_B.absxk > interception_v15_B.absx) {
    interception_v15_B.t = interception_v15_B.absx / interception_v15_B.absxk;
    interception_v15_B.yb_des_idx_0 = interception_v15_B.yb_des_idx_0 *
      interception_v15_B.t * interception_v15_B.t + 1.0;
    interception_v15_B.absx = interception_v15_B.absxk;
  } else {
    interception_v15_B.t = interception_v15_B.absxk / interception_v15_B.absx;
    interception_v15_B.yb_des_idx_0 += interception_v15_B.t *
      interception_v15_B.t;
  }

  interception_v15_B.yb_des_idx_0 = interception_v15_B.absx * sqrt
    (interception_v15_B.yb_des_idx_0);
  interception_v15_B.b_absx = interception_v15_B.rtb_u_idx_0 /
    interception_v15_B.yb_des_idx_0;
  interception_v15_B.absx = interception_v15_B.rtb_u_idx_1 /
    interception_v15_B.yb_des_idx_0;
  interception_v15_B.zb_des_idx_2 = interception_v15_B.rtb_u_idx_2 /
    interception_v15_B.yb_des_idx_0;
  interception_v15_B.t = interception_v15_B.absx * 0.0 -
    interception_v15_B.yb_des_idx_1 * interception_v15_B.zb_des_idx_2;
  interception_v15_B.MathFunction_j[0] = interception_v15_B.t;
  interception_v15_B.K14 = interception_v15_B.Tan *
    interception_v15_B.zb_des_idx_2 - interception_v15_B.b_absx * 0.0;
  interception_v15_B.MathFunction_j[1] = interception_v15_B.K14;
  interception_v15_B.c_tmp = interception_v15_B.b_absx *
    interception_v15_B.yb_des_idx_1 - interception_v15_B.Tan *
    interception_v15_B.absx;
  interception_v15_B.MathFunction_j[2] = interception_v15_B.c_tmp;
  interception_v15_B.Tan = interception_v15_norm
    (interception_v15_B.MathFunction_j);
  interception_v15_B.yb_des_idx_0 = interception_v15_B.t /
    interception_v15_B.Tan;
  interception_v15_B.yb_des_idx_1 = interception_v15_B.K14 /
    interception_v15_B.Tan;
  interception_v15_B.absxk = interception_v15_B.c_tmp / interception_v15_B.Tan;
  interception_v15_B.t = interception_v15_B.yb_des_idx_1 *
    interception_v15_B.zb_des_idx_2 - interception_v15_B.absx *
    interception_v15_B.absxk;
  interception_v15_B.MathFunction_j[0] = interception_v15_B.t;
  interception_v15_B.K14 = interception_v15_B.b_absx * interception_v15_B.absxk
    - interception_v15_B.yb_des_idx_0 * interception_v15_B.zb_des_idx_2;
  interception_v15_B.MathFunction_j[1] = interception_v15_B.K14;
  interception_v15_B.c_tmp = interception_v15_B.yb_des_idx_0 *
    interception_v15_B.absx - interception_v15_B.b_absx *
    interception_v15_B.yb_des_idx_1;
  interception_v15_B.MathFunction_j[2] = interception_v15_B.c_tmp;
  interception_v15_B.Tan = interception_v15_norm
    (interception_v15_B.MathFunction_j);
  interception_v15_B.MathFunction_j[0] = interception_v15_B.t /
    interception_v15_B.Tan;
  interception_v15_B.MathFunction_j[1] = interception_v15_B.K14 /
    interception_v15_B.Tan;
  interception_v15_B.MathFunction_j[2] = interception_v15_B.c_tmp /
    interception_v15_B.Tan;
  interception_v15_B.Tan = interception_v15_B.yb_des_idx_0 +
    interception_v15_B.MathFunction_j[1];
  interception_v15_B.t = interception_v15_B.b_absx +
    interception_v15_B.MathFunction_j[2];
  interception_v15_B.K14 = interception_v15_B.absxk - interception_v15_B.absx;
  interception_v15_B.absx += interception_v15_B.absxk;
  interception_v15_B.b_absx -= interception_v15_B.MathFunction_j[2];
  interception_v15_B.yb_des_idx_0 = interception_v15_B.MathFunction_j[1] -
    interception_v15_B.yb_des_idx_0;
  interception_v15_B.c_a_data[0] = ((interception_v15_B.MathFunction_j[0] -
    interception_v15_B.yb_des_idx_1) - interception_v15_B.zb_des_idx_2) / 3.0;
  interception_v15_B.c_a_data[4] = interception_v15_B.Tan / 3.0;
  interception_v15_B.c_a_data[8] = interception_v15_B.t / 3.0;
  interception_v15_B.c_a_data[12] = interception_v15_B.K14 / 3.0;
  interception_v15_B.c_a_data[1] = interception_v15_B.Tan / 3.0;
  interception_v15_B.c_a_data[5] = ((interception_v15_B.yb_des_idx_1 -
    interception_v15_B.MathFunction_j[0]) - interception_v15_B.zb_des_idx_2) /
    3.0;
  interception_v15_B.c_a_data[9] = interception_v15_B.absx / 3.0;
  interception_v15_B.c_a_data[13] = interception_v15_B.b_absx / 3.0;
  interception_v15_B.c_a_data[2] = interception_v15_B.t / 3.0;
  interception_v15_B.c_a_data[6] = interception_v15_B.absx / 3.0;
  interception_v15_B.c_a_data[10] = ((interception_v15_B.zb_des_idx_2 -
    interception_v15_B.MathFunction_j[0]) - interception_v15_B.yb_des_idx_1) /
    3.0;
  interception_v15_B.c_a_data[14] = interception_v15_B.yb_des_idx_0 / 3.0;
  interception_v15_B.c_a_data[3] = interception_v15_B.K14 / 3.0;
  interception_v15_B.c_a_data[7] = interception_v15_B.b_absx / 3.0;
  interception_v15_B.c_a_data[11] = interception_v15_B.yb_des_idx_0 / 3.0;
  interception_v15_B.c_a_data[15] = ((interception_v15_B.MathFunction_j[0] +
    interception_v15_B.yb_des_idx_1) + interception_v15_B.zb_des_idx_2) / 3.0;
  paired = true;
  for (interception_v15_B.k2 = 0; interception_v15_B.k2 < 16;
       interception_v15_B.k2++) {
    interception_v15_B.Tan = interception_v15_B.c_a_data[interception_v15_B.k2];
    if (paired && (rtIsInf(interception_v15_B.Tan) || rtIsNaN
                   (interception_v15_B.Tan))) {
      paired = false;
    }
  }

  if (!paired) {
    for (interception_v15_B.j = 0; interception_v15_B.j < 16;
         interception_v15_B.j++) {
      interception_v15_B.V[interception_v15_B.j].re = (rtNaN);
      interception_v15_B.V[interception_v15_B.j].im = 0.0;
    }

    interception_v15_B.e_x[0].re = (rtNaN);
    interception_v15_B.e_x[1].re = (rtNaN);
    interception_v15_B.e_x[2].re = (rtNaN);
    interception_v15_B.e_x[3].re = (rtNaN);
  } else {
    int32_T exitg3;
    paired = true;
    interception_v15_B.j = 0;
    exitg1 = false;
    while ((!exitg1) && (interception_v15_B.j < 4)) {
      interception_v15_B.k2 = 0;
      do {
        exitg3 = 0;
        if (interception_v15_B.k2 <= interception_v15_B.j) {
          if (!(interception_v15_B.c_a_data[(interception_v15_B.j << 2) +
                interception_v15_B.k2] == interception_v15_B.c_a_data
                [(interception_v15_B.k2 << 2) + interception_v15_B.j])) {
            paired = false;
            exitg3 = 1;
          } else {
            interception_v15_B.k2++;
          }
        } else {
          interception_v15_B.j++;
          exitg3 = 2;
        }
      } while (exitg3 == 0);

      if (exitg3 == 1) {
        exitg1 = true;
      }
    }

    if (paired) {
      interception_v15_schur(interception_v15_B.c_a_data, interception_v15_B.U,
        interception_v15_B.T);
      for (interception_v15_B.j = 0; interception_v15_B.j < 16;
           interception_v15_B.j++) {
        interception_v15_B.V[interception_v15_B.j].re =
          interception_v15_B.U[interception_v15_B.j];
        interception_v15_B.V[interception_v15_B.j].im = 0.0;
      }

      interception_v15_B.e_x[0].re = interception_v15_B.T[0];
      interception_v15_B.e_x[1].re = interception_v15_B.T[5];
      interception_v15_B.e_x[2].re = interception_v15_B.T[10];
      interception_v15_B.e_x[3].re = interception_v15_B.T[15];
    } else {
      paired = true;
      interception_v15_B.k2 = 0;
      exitg1 = false;
      while ((!exitg1) && (interception_v15_B.k2 < 4)) {
        interception_v15_B.companDim = 0;
        do {
          exitg3 = 0;
          if (interception_v15_B.companDim <= interception_v15_B.k2) {
            if (!(interception_v15_B.c_a_data[(interception_v15_B.k2 << 2) +
                  interception_v15_B.companDim] == -interception_v15_B.c_a_data
                  [(interception_v15_B.companDim << 2) + interception_v15_B.k2]))
            {
              paired = false;
              exitg3 = 1;
            } else {
              interception_v15_B.companDim++;
            }
          } else {
            interception_v15_B.k2++;
            exitg3 = 2;
          }
        } while (exitg3 == 0);

        if (exitg3 == 1) {
          exitg1 = true;
        }
      }

      if (paired) {
        interception_v15_schur(interception_v15_B.c_a_data, interception_v15_B.U,
          interception_v15_B.T);
        interception_v15_B.companDim = 1;
        do {
          exitg3 = 0;
          if (interception_v15_B.companDim <= 4) {
            boolean_T guard1 = false;
            guard1 = false;
            if (interception_v15_B.companDim != 4) {
              interception_v15_B.Tan = interception_v15_B.T
                [((interception_v15_B.companDim - 1) << 2) +
                interception_v15_B.companDim];
              if (interception_v15_B.Tan != 0.0) {
                interception_v15_B.Tan = fabs(interception_v15_B.Tan);
                interception_v15_B.e_x[interception_v15_B.companDim - 1].re =
                  0.0;
                interception_v15_B.e_x[interception_v15_B.companDim - 1].im =
                  interception_v15_B.Tan;
                interception_v15_B.e_x[interception_v15_B.companDim].re = 0.0;
                interception_v15_B.e_x[interception_v15_B.companDim].im =
                  -interception_v15_B.Tan;
                interception_v15_B.companDim += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              interception_v15_B.e_x[interception_v15_B.companDim - 1].re = 0.0;
              interception_v15_B.e_x[interception_v15_B.companDim - 1].im = 0.0;
              interception_v15_B.companDim++;
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);

        for (interception_v15_B.j = 0; interception_v15_B.j < 16;
             interception_v15_B.j++) {
          interception_v15_B.V[interception_v15_B.j].re =
            interception_v15_B.U[interception_v15_B.j];
          interception_v15_B.V[interception_v15_B.j].im = 0.0;
        }

        interception_v15_B.k1 = 1;
        do {
          exitg3 = 0;
          if (interception_v15_B.k1 <= 4) {
            if (interception_v15_B.k1 != 4) {
              interception_v15_B.j = (interception_v15_B.k1 - 1) << 2;
              interception_v15_B.Tan = interception_v15_B.T[interception_v15_B.j
                + interception_v15_B.k1];
              if (interception_v15_B.Tan != 0.0) {
                if (interception_v15_B.Tan < 0.0) {
                  interception_v15_B.k2 = 1;
                } else {
                  interception_v15_B.k2 = -1;
                }

                interception_v15_B.b_absx =
                  interception_v15_B.V[interception_v15_B.j].re;
                interception_v15_B.companDim = interception_v15_B.k1 << 2;
                interception_v15_B.zb_des_idx_2 =
                  interception_v15_B.V[interception_v15_B.companDim].re *
                  static_cast<real_T>(interception_v15_B.k2);
                if (interception_v15_B.zb_des_idx_2 == 0.0) {
                  interception_v15_B.V[interception_v15_B.j].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j].im = 0.0;
                } else if (interception_v15_B.b_absx == 0.0) {
                  interception_v15_B.V[interception_v15_B.j].re = 0.0;
                  interception_v15_B.V[interception_v15_B.j].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                } else {
                  interception_v15_B.V[interception_v15_B.j].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                }

                interception_v15_B.V[interception_v15_B.companDim].re =
                  interception_v15_B.V[interception_v15_B.j].re;
                interception_v15_B.V[interception_v15_B.companDim].im =
                  -interception_v15_B.V[interception_v15_B.j].im;
                interception_v15_B.b_absx =
                  interception_v15_B.V[interception_v15_B.j + 1].re;
                interception_v15_B.zb_des_idx_2 =
                  interception_v15_B.V[interception_v15_B.companDim + 1].re *
                  static_cast<real_T>(interception_v15_B.k2);
                if (interception_v15_B.zb_des_idx_2 == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 1].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 1].im = 0.0;
                } else if (interception_v15_B.b_absx == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 1].re = 0.0;
                  interception_v15_B.V[interception_v15_B.j + 1].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                } else {
                  interception_v15_B.V[interception_v15_B.j + 1].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 1].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                }

                interception_v15_B.V[interception_v15_B.companDim + 1].re =
                  interception_v15_B.V[interception_v15_B.j + 1].re;
                interception_v15_B.V[interception_v15_B.companDim + 1].im =
                  -interception_v15_B.V[interception_v15_B.j + 1].im;
                interception_v15_B.b_absx =
                  interception_v15_B.V[interception_v15_B.j + 2].re;
                interception_v15_B.zb_des_idx_2 =
                  interception_v15_B.V[interception_v15_B.companDim + 2].re *
                  static_cast<real_T>(interception_v15_B.k2);
                if (interception_v15_B.zb_des_idx_2 == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 2].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 2].im = 0.0;
                } else if (interception_v15_B.b_absx == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 2].re = 0.0;
                  interception_v15_B.V[interception_v15_B.j + 2].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                } else {
                  interception_v15_B.V[interception_v15_B.j + 2].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 2].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                }

                interception_v15_B.V[interception_v15_B.companDim + 2].re =
                  interception_v15_B.V[interception_v15_B.j + 2].re;
                interception_v15_B.V[interception_v15_B.companDim + 2].im =
                  -interception_v15_B.V[interception_v15_B.j + 2].im;
                interception_v15_B.b_absx =
                  interception_v15_B.V[interception_v15_B.j + 3].re;
                interception_v15_B.zb_des_idx_2 =
                  interception_v15_B.V[interception_v15_B.companDim + 3].re *
                  static_cast<real_T>(interception_v15_B.k2);
                if (interception_v15_B.zb_des_idx_2 == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 3].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 3].im = 0.0;
                } else if (interception_v15_B.b_absx == 0.0) {
                  interception_v15_B.V[interception_v15_B.j + 3].re = 0.0;
                  interception_v15_B.V[interception_v15_B.j + 3].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                } else {
                  interception_v15_B.V[interception_v15_B.j + 3].re =
                    interception_v15_B.b_absx / 1.4142135623730951;
                  interception_v15_B.V[interception_v15_B.j + 3].im =
                    interception_v15_B.zb_des_idx_2 / 1.4142135623730951;
                }

                interception_v15_B.V[interception_v15_B.companDim + 3].re =
                  interception_v15_B.V[interception_v15_B.j + 3].re;
                interception_v15_B.V[interception_v15_B.companDim + 3].im =
                  -interception_v15_B.V[interception_v15_B.j + 3].im;
                interception_v15_B.k1 += 2;
              } else {
                interception_v15_B.k1++;
              }
            } else {
              interception_v15_B.k1++;
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);
      } else {
        interception_v15_xzgeev(interception_v15_B.c_a_data,
          &interception_v15_B.j, interception_v15_B.e_x,
          interception_v15_B.tgoroots_data, interception_v15_B.V);
        if (interception_v15_B.tgoroots_data[0].im == 0.0) {
          if (interception_v15_B.e_x[0].im == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[0].re /
              interception_v15_B.tgoroots_data[0].re;
          } else if (interception_v15_B.e_x[0].re == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[0].re /
              interception_v15_B.tgoroots_data[0].re;
          }
        } else if (interception_v15_B.tgoroots_data[0].re == 0.0) {
          if (interception_v15_B.e_x[0].re == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[0].im /
              interception_v15_B.tgoroots_data[0].im;
          } else if (interception_v15_B.e_x[0].im == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[0].im /
              interception_v15_B.tgoroots_data[0].im;
          }
        } else {
          interception_v15_B.Tan = fabs(interception_v15_B.tgoroots_data[0].re);
          interception_v15_B.zb_des_idx_2 = fabs
            (interception_v15_B.tgoroots_data[0].im);
          if (interception_v15_B.Tan > interception_v15_B.zb_des_idx_2) {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[0].im /
              interception_v15_B.tgoroots_data[0].re;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[0].im + interception_v15_B.e_x[0].re) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[0].im +
               interception_v15_B.tgoroots_data[0].re);
          } else if (interception_v15_B.zb_des_idx_2 == interception_v15_B.Tan)
          {
            interception_v15_B.Tan = ((interception_v15_B.tgoroots_data[0].re >
              0.0 ? 0.5 : -0.5) * interception_v15_B.e_x[0].re +
              (interception_v15_B.tgoroots_data[0].im > 0.0 ? 0.5 : -0.5) *
              interception_v15_B.e_x[0].im) / interception_v15_B.Tan;
          } else {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[0].re /
              interception_v15_B.tgoroots_data[0].im;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[0].re + interception_v15_B.e_x[0].im) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[0].re +
               interception_v15_B.tgoroots_data[0].im);
          }
        }

        interception_v15_B.e_x[0].re = interception_v15_B.Tan;
        if (interception_v15_B.tgoroots_data[1].im == 0.0) {
          if (interception_v15_B.e_x[1].im == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[1].re /
              interception_v15_B.tgoroots_data[1].re;
          } else if (interception_v15_B.e_x[1].re == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[1].re /
              interception_v15_B.tgoroots_data[1].re;
          }
        } else if (interception_v15_B.tgoroots_data[1].re == 0.0) {
          if (interception_v15_B.e_x[1].re == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[1].im /
              interception_v15_B.tgoroots_data[1].im;
          } else if (interception_v15_B.e_x[1].im == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[1].im /
              interception_v15_B.tgoroots_data[1].im;
          }
        } else {
          interception_v15_B.Tan = fabs(interception_v15_B.tgoroots_data[1].re);
          interception_v15_B.zb_des_idx_2 = fabs
            (interception_v15_B.tgoroots_data[1].im);
          if (interception_v15_B.Tan > interception_v15_B.zb_des_idx_2) {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[1].im /
              interception_v15_B.tgoroots_data[1].re;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[1].im + interception_v15_B.e_x[1].re) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[1].im +
               interception_v15_B.tgoroots_data[1].re);
          } else if (interception_v15_B.zb_des_idx_2 == interception_v15_B.Tan)
          {
            interception_v15_B.Tan = ((interception_v15_B.tgoroots_data[1].re >
              0.0 ? 0.5 : -0.5) * interception_v15_B.e_x[1].re +
              (interception_v15_B.tgoroots_data[1].im > 0.0 ? 0.5 : -0.5) *
              interception_v15_B.e_x[1].im) / interception_v15_B.Tan;
          } else {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[1].re /
              interception_v15_B.tgoroots_data[1].im;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[1].re + interception_v15_B.e_x[1].im) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[1].re +
               interception_v15_B.tgoroots_data[1].im);
          }
        }

        interception_v15_B.e_x[1].re = interception_v15_B.Tan;
        if (interception_v15_B.tgoroots_data[2].im == 0.0) {
          if (interception_v15_B.e_x[2].im == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[2].re /
              interception_v15_B.tgoroots_data[2].re;
          } else if (interception_v15_B.e_x[2].re == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[2].re /
              interception_v15_B.tgoroots_data[2].re;
          }
        } else if (interception_v15_B.tgoroots_data[2].re == 0.0) {
          if (interception_v15_B.e_x[2].re == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[2].im /
              interception_v15_B.tgoroots_data[2].im;
          } else if (interception_v15_B.e_x[2].im == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[2].im /
              interception_v15_B.tgoroots_data[2].im;
          }
        } else {
          interception_v15_B.Tan = fabs(interception_v15_B.tgoroots_data[2].re);
          interception_v15_B.zb_des_idx_2 = fabs
            (interception_v15_B.tgoroots_data[2].im);
          if (interception_v15_B.Tan > interception_v15_B.zb_des_idx_2) {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[2].im /
              interception_v15_B.tgoroots_data[2].re;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[2].im + interception_v15_B.e_x[2].re) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[2].im +
               interception_v15_B.tgoroots_data[2].re);
          } else if (interception_v15_B.zb_des_idx_2 == interception_v15_B.Tan)
          {
            interception_v15_B.Tan = ((interception_v15_B.tgoroots_data[2].re >
              0.0 ? 0.5 : -0.5) * interception_v15_B.e_x[2].re +
              (interception_v15_B.tgoroots_data[2].im > 0.0 ? 0.5 : -0.5) *
              interception_v15_B.e_x[2].im) / interception_v15_B.Tan;
          } else {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[2].re /
              interception_v15_B.tgoroots_data[2].im;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[2].re + interception_v15_B.e_x[2].im) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[2].re +
               interception_v15_B.tgoroots_data[2].im);
          }
        }

        interception_v15_B.e_x[2].re = interception_v15_B.Tan;
        if (interception_v15_B.tgoroots_data[3].im == 0.0) {
          if (interception_v15_B.e_x[3].im == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[3].re /
              interception_v15_B.tgoroots_data[3].re;
          } else if (interception_v15_B.e_x[3].re == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[3].re /
              interception_v15_B.tgoroots_data[3].re;
          }
        } else if (interception_v15_B.tgoroots_data[3].re == 0.0) {
          if (interception_v15_B.e_x[3].re == 0.0) {
            interception_v15_B.Tan = interception_v15_B.e_x[3].im /
              interception_v15_B.tgoroots_data[3].im;
          } else if (interception_v15_B.e_x[3].im == 0.0) {
            interception_v15_B.Tan = 0.0;
          } else {
            interception_v15_B.Tan = interception_v15_B.e_x[3].im /
              interception_v15_B.tgoroots_data[3].im;
          }
        } else {
          interception_v15_B.Tan = fabs(interception_v15_B.tgoroots_data[3].re);
          interception_v15_B.zb_des_idx_2 = fabs
            (interception_v15_B.tgoroots_data[3].im);
          if (interception_v15_B.Tan > interception_v15_B.zb_des_idx_2) {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[3].im /
              interception_v15_B.tgoroots_data[3].re;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[3].im + interception_v15_B.e_x[3].re) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[3].im +
               interception_v15_B.tgoroots_data[3].re);
          } else if (interception_v15_B.zb_des_idx_2 == interception_v15_B.Tan)
          {
            interception_v15_B.Tan = ((interception_v15_B.tgoroots_data[3].re >
              0.0 ? 0.5 : -0.5) * interception_v15_B.e_x[3].re +
              (interception_v15_B.tgoroots_data[3].im > 0.0 ? 0.5 : -0.5) *
              interception_v15_B.e_x[3].im) / interception_v15_B.Tan;
          } else {
            interception_v15_B.Tan = interception_v15_B.tgoroots_data[3].re /
              interception_v15_B.tgoroots_data[3].im;
            interception_v15_B.Tan = (interception_v15_B.Tan *
              interception_v15_B.e_x[3].re + interception_v15_B.e_x[3].im) /
              (interception_v15_B.Tan * interception_v15_B.tgoroots_data[3].re +
               interception_v15_B.tgoroots_data[3].im);
          }
        }

        interception_v15_B.e_x[3].re = interception_v15_B.Tan;
      }
    }
  }

  interception_v15_B.quat[0] = interception_v15_B.e_x[0].re;
  interception_v15_B.quat[1] = interception_v15_B.e_x[1].re;
  interception_v15_B.quat[2] = interception_v15_B.e_x[2].re;
  interception_v15_B.quat[3] = interception_v15_B.e_x[3].re;
  if (!rtIsNaN(interception_v15_B.e_x[0].re)) {
    interception_v15_B.k2 = 0;
  } else {
    interception_v15_B.k2 = -1;
    interception_v15_B.j = 2;
    exitg1 = false;
    while ((!exitg1) && (interception_v15_B.j < 5)) {
      if (!rtIsNaN(interception_v15_B.quat[interception_v15_B.j - 1])) {
        interception_v15_B.k2 = interception_v15_B.j - 1;
        exitg1 = true;
      } else {
        interception_v15_B.j++;
      }
    }
  }

  if (interception_v15_B.k2 + 1 == 0) {
    interception_v15_B.companDim = 0;
  } else {
    interception_v15_B.zb_des_idx_2 =
      interception_v15_B.quat[interception_v15_B.k2];
    interception_v15_B.companDim = interception_v15_B.k2;
    for (interception_v15_B.j = interception_v15_B.k2 + 2; interception_v15_B.j <
         5; interception_v15_B.j++) {
      interception_v15_B.Tan = interception_v15_B.quat[interception_v15_B.j - 1];
      if (interception_v15_B.zb_des_idx_2 < interception_v15_B.Tan) {
        interception_v15_B.zb_des_idx_2 = interception_v15_B.Tan;
        interception_v15_B.companDim = interception_v15_B.j - 1;
      }
    }
  }

  interception_v15_B.k2 = interception_v15_B.companDim << 2;
  interception_v15_B.quat[0] = interception_v15_B.V[interception_v15_B.k2 + 3].
    re;
  interception_v15_B.quat[1] = interception_v15_B.V[interception_v15_B.k2].re;
  interception_v15_B.quat[2] = interception_v15_B.V[interception_v15_B.k2 + 1].
    re;
  interception_v15_B.quat[3] = interception_v15_B.V[interception_v15_B.k2 + 2].
    re;
  if (interception_v15_B.quat[0] < 0.0) {
    interception_v15_B.quat[0] = -interception_v15_B.quat[0];
    interception_v15_B.quat[1] = -interception_v15_B.quat[1];
    interception_v15_B.quat[2] = -interception_v15_B.quat[2];
    interception_v15_B.quat[3] = -interception_v15_B.quat[3];
  }

  // End of MATLAB Function: '<S6>/MATLAB Function'

  // Sum: '<S17>/Sum of Elements' incorporates:
  //   Math: '<S17>/Math Function'

  interception_v15_B.Tan = (interception_v15_B.AddPose[0] *
    interception_v15_B.AddPose[0] + interception_v15_B.AddPose[1] *
    interception_v15_B.AddPose[1]) + interception_v15_B.AddPose[2] *
    interception_v15_B.AddPose[2];

  // Math: '<S17>/Math Function1' incorporates:
  //   Sum: '<S17>/Sum of Elements'
  //
  //  About '<S17>/Math Function1':
  //   Operator: sqrt

  if (interception_v15_B.Tan < 0.0) {
    interception_v15_B.yb_des_idx_1 = -sqrt(fabs(interception_v15_B.Tan));
  } else {
    interception_v15_B.yb_des_idx_1 = sqrt(interception_v15_B.Tan);
  }

  // End of Math: '<S17>/Math Function1'

  // MATLABSystem: '<Root>/Get Parameter13'
  ParamGet_interception_v15_552.get_parameter(&interception_v15_B.zb_des_idx_2);

  // MATLABSystem: '<Root>/Get Parameter14'
  ParamGet_interception_v15_553.get_parameter(&interception_v15_B.b_absx);

  // Chart: '<Root>/logic' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter13'
  //   MATLABSystem: '<Root>/Get Parameter14'

  if (interception_v15_DW.temporalCounter_i1 < 31U) {
    interception_v15_DW.temporalCounter_i1 = static_cast<uint8_T>
      (interception_v15_DW.temporalCounter_i1 + 1U);
  }

  if (interception_v15_DW.is_active_c3_interception_v15 == 0U) {
    interception_v15_DW.is_active_c3_interception_v15 = 1U;
    interception_v15_DW.is_c3_interception_v15 = interception_v15_IN_Init;
    interception_v15_DW.temporalCounter_i1 = 0U;
  } else {
    switch (interception_v15_DW.is_c3_interception_v15) {
     case interception_v15_IN_Emergency:
      interception_v15_B.state = 0.0;
      interception_v15_B.stop = 1.0;
      break;

     case interception_v15_IN_Init:
      if (interception_v15_DW.temporalCounter_i1 >= 30U) {
        interception_v15_DW.is_c3_interception_v15 =
          interception_v1_IN_Intercepting;
        interception_v15_B.state = 1.0;
        interception_v15_B.stop = 0.0;
        interception_v15_DW.done = (interception_v15_B.yb_des_idx_1 > 1.0E+6);
        interception_v15_DW.tmp_range = interception_v15_B.yb_des_idx_1;
      }
      break;

     case interception_v1_IN_Intercepting:
      interception_v15_B.absx = 3.3121686421112381E-170;
      interception_v15_B.absxk = fabs(interception_v15_B.RateTransition[0]);
      if (interception_v15_B.absxk > 3.3121686421112381E-170) {
        interception_v15_B.yb_des_idx_0 = 1.0;
        interception_v15_B.absx = interception_v15_B.absxk;
      } else {
        interception_v15_B.t = interception_v15_B.absxk /
          3.3121686421112381E-170;
        interception_v15_B.yb_des_idx_0 = interception_v15_B.t *
          interception_v15_B.t;
      }

      interception_v15_B.absxk = fabs(interception_v15_B.RateTransition[1]);
      if (interception_v15_B.absxk > interception_v15_B.absx) {
        interception_v15_B.t = interception_v15_B.absx /
          interception_v15_B.absxk;
        interception_v15_B.yb_des_idx_0 = interception_v15_B.yb_des_idx_0 *
          interception_v15_B.t * interception_v15_B.t + 1.0;
        interception_v15_B.absx = interception_v15_B.absxk;
      } else {
        interception_v15_B.t = interception_v15_B.absxk /
          interception_v15_B.absx;
        interception_v15_B.yb_des_idx_0 += interception_v15_B.t *
          interception_v15_B.t;
      }

      if ((interception_v15_B.absx * sqrt(interception_v15_B.yb_des_idx_0) >
           interception_v15_B.zb_des_idx_2) || (fabs
           (interception_v15_B.RateTransition[2]) > interception_v15_B.b_absx))
      {
        interception_v15_DW.is_c3_interception_v15 =
          interception_v15_IN_Emergency;
        interception_v15_B.state = 0.0;
        interception_v15_B.stop = 1.0;
      } else if ((interception_v15_DW.done != 0.0) && (interception_v15_B.active
                  != 0)) {
        interception_v15_DW.is_c3_interception_v15 = interception_v15_IN_Return;
        interception_v15_B.state = 0.0;
        interception_v15_B.stop = 0.0;
      } else {
        interception_v15_B.state = 1.0;
        interception_v15_B.stop = 0.0;
        interception_v15_DW.done = (interception_v15_B.yb_des_idx_1 >
          interception_v15_DW.tmp_range);
        interception_v15_DW.tmp_range = interception_v15_B.yb_des_idx_1;
      }
      break;

     default:
      // case IN_Return:
      interception_v15_B.state = 0.0;
      interception_v15_B.stop = 0.0;
      break;
    }
  }

  // End of Chart: '<Root>/logic'

  // MATLABSystem: '<Root>/Get Parameter5'
  ParamGet_interception_v15_281.get_parameter(&interception_v15_B.zb_des_idx_2);

  // Outputs for Enabled SubSystem: '<Root>/Sending thrust commands' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (interception_v15_B.state > 0.0) {
    interception_v15_CurrentTime(&interception_v15_B.CurrentTime_pn);

    // BusAssignment: '<S20>/Bus Assignment' incorporates:
    //   Constant: '<S32>/Constant'
    //   DataTypeConversion: '<Root>/Data Type Conversion1'
    //   MATLABSystem: '<Root>/Get Parameter5'

    interception_v15_B.BusAssignment = interception_v15_P.Constant_Value_h;
    interception_v15_B.BusAssignment.Header.Stamp =
      interception_v15_B.CurrentTime_pn.CurrentTime;
    interception_v15_B.BusAssignment.Orientation.W = interception_v15_B.quat[0];
    interception_v15_B.BusAssignment.Orientation.X = interception_v15_B.quat[1];
    interception_v15_B.BusAssignment.Orientation.Y = interception_v15_B.quat[2];
    interception_v15_B.BusAssignment.Orientation.Z = interception_v15_B.quat[3];
    interception_v15_B.BusAssignment.Thrust = static_cast<real32_T>
      (interception_v15_B.zb_des_idx_2);

    // Outputs for Atomic SubSystem: '<S20>/Publish'
    // MATLABSystem: '<S33>/SinkBlock'
    Pub_interception_v15_178.publish(&interception_v15_B.BusAssignment);

    // End of Outputs for SubSystem: '<S20>/Publish'
  }

  // End of Outputs for SubSystem: '<Root>/Sending thrust commands'

  // Sum: '<S18>/Sum of Elements' incorporates:
  //   Math: '<S18>/Math Function'
  //   SignalConversion generated from: '<S18>/Math Function'

  interception_v15_B.Tan = (interception_v15_B.In1_m.Twist.Linear.X *
    interception_v15_B.In1_m.Twist.Linear.X +
    interception_v15_B.In1_m.Twist.Linear.Y *
    interception_v15_B.In1_m.Twist.Linear.Y) +
    interception_v15_B.In1_m.Twist.Linear.Z *
    interception_v15_B.In1_m.Twist.Linear.Z;

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_interception_v15_334.get_parameter(&interception_v15_B.zb_des_idx_2);

  // MATLABSystem: '<Root>/Get Parameter8'
  ParamGet_interception_v15_339.get_parameter(&interception_v15_B.b_absx);

  // MATLABSystem: '<Root>/Get Parameter9'
  ParamGet_interception_v15_340.get_parameter(&interception_v15_B.absx);

  // Outputs for Enabled SubSystem: '<Root>/Sending position commands' incorporates:
  //   EnablePort: '<S19>/Enable'

  // Logic: '<Root>/NOT'
  if (!(interception_v15_B.state != 0.0)) {
    interception_v15_CurrentTime(&interception_v15_B.CurrentTime_p);

    // BusAssignment: '<S19>/Bus Assignment' incorporates:
    //   Constant: '<S30>/Constant'
    //   MATLABSystem: '<Root>/Get Parameter'
    //   MATLABSystem: '<Root>/Get Parameter8'
    //   MATLABSystem: '<Root>/Get Parameter9'

    interception_v15_B.BusAssignment_h = interception_v15_P.Constant_Value_d;
    interception_v15_B.BusAssignment_h.Header.Stamp =
      interception_v15_B.CurrentTime_p.CurrentTime;
    interception_v15_B.BusAssignment_h.Pose.Position.X =
      interception_v15_B.zb_des_idx_2;
    interception_v15_B.BusAssignment_h.Pose.Position.Y =
      interception_v15_B.b_absx;
    interception_v15_B.BusAssignment_h.Pose.Position.Z = interception_v15_B.absx;

    // Outputs for Atomic SubSystem: '<S19>/Publish'
    // MATLABSystem: '<S31>/SinkBlock'
    Pub_interception_v15_311.publish(&interception_v15_B.BusAssignment_h);

    // End of Outputs for SubSystem: '<S19>/Publish'
  }

  // End of Logic: '<Root>/NOT'
  // End of Outputs for SubSystem: '<Root>/Sending position commands'

  // MATLABSystem: '<Root>/Set Parameter1'
  ParamSet_interception_v15_576.set_parameter(interception_v15_B.state);

  // Stop: '<Root>/Stop Simulation'
  if (interception_v15_B.stop != 0.0) {
    rtmSetStopRequested(interception_v15_M, 1);
  }

  // End of Stop: '<Root>/Stop Simulation'

  // MinMax: '<S8>/MinMax' incorporates:
  //   Memory: '<S27>/Memory'
  //   Switch: '<S27>/Reset'

  if ((interception_v15_B.yb_des_idx_1 <=
       interception_v15_DW.Memory_PreviousInput) || rtIsNaN
      (interception_v15_DW.Memory_PreviousInput)) {
    // Switch: '<S27>/Reset'
    interception_v15_DW.Memory_PreviousInput = interception_v15_B.yb_des_idx_1;
  }

  // End of MinMax: '<S8>/MinMax'

  // MATLABSystem: '<Root>/Set Parameter'
  ParamSet_interception_v15_573.set_parameter
    (interception_v15_DW.Memory_PreviousInput);

  // MATLABSystem: '<Root>/Current Time'
  currentROSTimeBus(&interception_v15_B.rtb_CurrentTime_d);

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_interception_v15_275.get_parameter(&interception_v15_B.zb_des_idx_2);

  // DotProduct: '<S26>/Dot Product'
  interception_v15_B.rtb_u_idx_0 = (interception_v15_B.rtb_u_idx_0 *
    interception_v15_B.rtb_u_idx_0 + interception_v15_B.rtb_u_idx_1 *
    interception_v15_B.rtb_u_idx_1) + interception_v15_B.rtb_u_idx_2 *
    interception_v15_B.rtb_u_idx_2;

  // BusAssignment: '<Root>/Bus Assignment3' incorporates:
  //   Constant: '<S4>/Constant'
  //   MATLABSystem: '<Root>/Current Time'

  interception_v15_B.BusAssignment = interception_v15_P.Constant_Value;
  interception_v15_B.BusAssignment.Header.Stamp =
    interception_v15_B.rtb_CurrentTime_d;
  interception_v15_B.BusAssignment.Orientation.W = interception_v15_B.quat[0];
  interception_v15_B.BusAssignment.Orientation.X = interception_v15_B.quat[1];
  interception_v15_B.BusAssignment.Orientation.Y = interception_v15_B.quat[2];
  interception_v15_B.BusAssignment.Orientation.Z = interception_v15_B.quat[3];

  // Math: '<S26>/Math Function1' incorporates:
  //   DotProduct: '<S26>/Dot Product'
  //
  //  About '<S26>/Math Function1':
  //   Operator: sqrt

  if (interception_v15_B.rtb_u_idx_0 < 0.0) {
    interception_v15_B.rtb_u_idx_0 = -sqrt(fabs(interception_v15_B.rtb_u_idx_0));
  } else {
    interception_v15_B.rtb_u_idx_0 = sqrt(interception_v15_B.rtb_u_idx_0);
  }

  // BusAssignment: '<Root>/Bus Assignment3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   MATLABSystem: '<Root>/Get Parameter1'
  //   Math: '<S26>/Math Function1'
  //   Product: '<S6>/Divide'
  //
  //  About '<S26>/Math Function1':
  //   Operator: sqrt

  interception_v15_B.BusAssignment.Thrust = static_cast<real32_T>
    (interception_v15_B.zb_des_idx_2 * interception_v15_B.rtb_u_idx_0);

  // Outputs for Atomic SubSystem: '<Root>/Publish3'
  // MATLABSystem: '<S15>/SinkBlock'
  Pub_interception_v15_451.publish(&interception_v15_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish3'

  // BusAssignment: '<Root>/Bus Assignment4' incorporates:
  //   Constant: '<S5>/Constant'
  //   MATLABSystem: '<Root>/Current Time'

  interception_v15_B.BusAssignment4 = interception_v15_P.Constant_Value_e;
  interception_v15_B.BusAssignment4.Header.Stamp =
    interception_v15_B.rtb_CurrentTime_d;
  interception_v15_B.BusAssignment4.Twist.Linear.X =
    interception_v15_B.AddVelocity[0];
  interception_v15_B.BusAssignment4.Twist.Linear.Y =
    interception_v15_B.AddVelocity[1];
  interception_v15_B.BusAssignment4.Twist.Linear.Z =
    interception_v15_B.AddVelocity[2];

  // Outputs for Atomic SubSystem: '<Root>/Publish4'
  // MATLABSystem: '<S16>/SinkBlock'
  Pub_interception_v15_469.publish(&interception_v15_B.BusAssignment4);

  // End of Outputs for SubSystem: '<Root>/Publish4'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S2>/Constant'
  //   MATLABSystem: '<Root>/Current Time'

  interception_v15_B.BusAssignment_h = interception_v15_P.Constant_Value_i;
  interception_v15_B.BusAssignment_h.Header.Stamp =
    interception_v15_B.rtb_CurrentTime_d;
  interception_v15_B.BusAssignment_h.Pose.Position.X =
    interception_v15_B.rtb_Saturation_idx_0;
  interception_v15_B.BusAssignment_h.Pose.Position.Y =
    interception_v15_B.rtb_Saturation_idx_1;
  interception_v15_B.BusAssignment_h.Pose.Position.Z =
    interception_v15_B.rtb_Saturation_idx_2;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S13>/SinkBlock'
  Pub_interception_v15_442.publish(&interception_v15_B.BusAssignment_h);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<S3>/Constant'
  //   MATLABSystem: '<Root>/Current Time'

  interception_v15_B.BusAssignment_h = interception_v15_P.Constant_Value_a;
  interception_v15_B.BusAssignment_h.Header.Stamp =
    interception_v15_B.rtb_CurrentTime_d;
  interception_v15_B.BusAssignment_h.Pose.Position =
    interception_v15_B.In1.Pose.Position;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S14>/SinkBlock'
  Pub_interception_v15_446.publish(&interception_v15_B.BusAssignment_h);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  interception_v15_B.BusAssignment_k = interception_v15_P.Constant_Value_g;
  interception_v15_B.BusAssignment_k.Real = interception_v15_B.tgo4;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S12>/SinkBlock'
  Pub_interception_v15_350.publish(&interception_v15_B.BusAssignment_k);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // MATLABSystem: '<S21>/Get Parameter'
  ParamGet_interception_v15_262.get_parameter(&interception_v15_B.zb_des_idx_2);

  // MATLABSystem: '<S21>/Get Parameter1'
  ParamGet_interception_v15_263.get_parameter(&interception_v15_B.b_absx);

  // MATLABSystem: '<S21>/Get Parameter2'
  ParamGet_interception_v15_264.get_parameter(&interception_v15_B.absx);
  if (interception_v15_M->Timing.TaskCounters.TID[1] == 0) {
    // DiscreteIntegrator: '<Root>/Vel2Pos' incorporates:
    //   MATLABSystem: '<S21>/Get Parameter'
    //   MATLABSystem: '<S21>/Get Parameter1'
    //   MATLABSystem: '<S21>/Get Parameter2'

    if (interception_v15_DW.Vel2Pos_IC_LOADING != 0) {
      interception_v15_DW.Vel2Pos_DSTATE[0] = interception_v15_B.zb_des_idx_2;
      interception_v15_DW.Vel2Pos_DSTATE[1] = interception_v15_B.b_absx;
      interception_v15_DW.Vel2Pos_DSTATE[2] = interception_v15_B.absx;
    }

    // End of DiscreteIntegrator: '<Root>/Vel2Pos'

    // Update for RateTransition: '<Root>/Rate Transition'
    interception_v15_DW.RateTransition_Buffer0[0] =
      interception_v15_DW.Vel2Pos_DSTATE[0];
    interception_v15_DW.RateTransition_Buffer0[1] =
      interception_v15_DW.Vel2Pos_DSTATE[1];
    interception_v15_DW.RateTransition_Buffer0[2] =
      interception_v15_DW.Vel2Pos_DSTATE[2];
  }

  // Update for Delay: '<Root>/Delay'
  interception_v15_DW.Delay_DSTATE[0] = interception_v15_DW.Delay_DSTATE[1];

  // Math: '<S18>/Math Function1' incorporates:
  //   Sum: '<S18>/Sum of Elements'
  //
  //  About '<S18>/Math Function1':
  //   Operator: sqrt

  if (interception_v15_B.Tan < 0.0) {
    // Update for Delay: '<Root>/Delay'
    interception_v15_DW.Delay_DSTATE[1] = -sqrt(fabs(interception_v15_B.Tan));
  } else {
    // Update for Delay: '<Root>/Delay'
    interception_v15_DW.Delay_DSTATE[1] = sqrt(interception_v15_B.Tan);
  }

  // End of Math: '<S18>/Math Function1'
  if (interception_v15_M->Timing.TaskCounters.TID[1] == 0) {
    // Update for DiscreteIntegrator: '<Root>/Vel2Pos'
    interception_v15_DW.Vel2Pos_IC_LOADING = 0U;
    interception_v15_DW.Vel2Pos_DSTATE[0] += interception_v15_P.Vel2Pos_gainval *
      interception_v15_B.y_idx_0;
    interception_v15_DW.Vel2Pos_DSTATE[1] += interception_v15_P.Vel2Pos_gainval *
      interception_v15_B.y_idx_1;
    interception_v15_DW.Vel2Pos_DSTATE[2] += interception_v15_P.Vel2Pos_gainval *
      interception_v15_B.y_idx_2;
  }

  rate_scheduler();
}

// Model initialize function
void interception_v15_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    char_T b_zeroDelimName[23];
    char_T b_zeroDelimTopic_0[18];
    char_T b_zeroDelimTopic[16];
    static const char_T tmp[37] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/', 'l',
      'o', 'c', 'a', 'l', '_', 'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '/', 'v',
      'e', 'l', 'o', 'c', 'i', 't', 'y', '_', 'l', 'o', 'c', 'a', 'l' };

    static const char_T tmp_0[27] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'l', 'o', 'c', 'a', 'l', '_', 'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '/',
      'p', 'o', 's', 'e' };

    static const char_T tmp_1[29] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      's', 'e', 't', 'p', 'o', 'i', 'n', 't', '_', 'r', 'a', 'w', '/', 'a', 't',
      't', 'i', 't', 'u', 'd', 'e' };

    static const char_T tmp_2[31] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      's', 'e', 't', 'p', 'o', 'i', 'n', 't', '_', 'p', 'o', 's', 'i', 't', 'i',
      'o', 'n', '/', 'l', 'o', 'c', 'a', 'l' };

    static const char_T tmp_3[15] = { '/', 'i', 'n', 't', 'e', 'r', 'c', 'e',
      'p', 't', 'i', 'o', 'n', '/', 'u' };

    static const char_T tmp_4[15] = { '/', 'i', 'n', 't', 'e', 'r', 'c', 'e',
      'p', 't', 'i', 'o', 'n', '/', 'v' };

    static const char_T tmp_5[17] = { '/', 'i', 'n', 't', 'e', 'r', 'c', 'e',
      'p', 't', 'i', 'o', 'n', '/', 'r', '_', 'e' };

    static const char_T tmp_6[17] = { '/', 'i', 'n', 't', 'e', 'r', 'c', 'e',
      'p', 't', 'i', 'o', 'n', '/', 'r', '_', 'p' };

    static const char_T tmp_7[17] = { '/', 'i', 'n', 't', 'e', 'r', 'c', 'e',
      'p', 't', 'i', 'o', 'n', '/', 'T', 'g', 'o' };

    static const char_T tmp_8[25] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'v', 'x' };

    static const char_T tmp_9[25] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'v', 'y' };

    static const char_T tmp_a[25] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'v', 'z' };

    static const char_T tmp_b[30] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'd', 'e',
      'l', 't', 'a', '_', 'r', 'h', 'o' };

    static const char_T tmp_c[22] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm' };

    static const char_T tmp_d[28] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'i',
      'n', '_', 't', 'g', 'o' };

    static const char_T tmp_e[26] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'r', 'h',
      'o', '_', 'u' };

    static const char_T tmp_f[22] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'g' };

    static const char_T tmp_g[26] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'k', '_',
      'g', 'u', 'i' };

    static const char_T tmp_h[29] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'a',
      'x', '_', 'd', 'i', 's', 't' };

    static const char_T tmp_i[31] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'a',
      'x', '_', 'h', 'e', 'i', 'g', 'h', 't' };

    static const char_T tmp_j[31] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'a',
      'x', '_', 't', 'h', 'r', 'u', 's', 't' };

    static const char_T tmp_k[23] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'x', 'f'
    };

    static const char_T tmp_l[23] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'y', 'f'
    };

    static const char_T tmp_m[23] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'z', 'f'
    };

    static const char_T tmp_n[26] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 's', 't',
      'a', 't', 'e' };

    static const char_T tmp_o[34] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'i',
      's', 's', '_', 'd', 'i', 's', 't', 'a', 'n', 'c', 'e' };

    static const char_T tmp_p[25] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 'm', 'a',
      's', 's' };

    static const char_T tmp_q[24] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'x' };

    static const char_T tmp_r[24] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'y' };

    static const char_T tmp_s[24] = { '/', 'm', 'a', 'v', 'r', 'o', 's', '/',
      'i', 'n', 't', 'e', 'r', 'c', 'e', 'p', 't', 'i', 'o', 'n', '/', 't', '_',
      'z' };

    // Start for RateTransition: '<Root>/Rate Transition'
    interception_v15_B.RateTransition[0] =
      interception_v15_P.RateTransition_InitialCondition;
    interception_v15_B.RateTransition[1] =
      interception_v15_P.RateTransition_InitialCondition;
    interception_v15_B.RateTransition[2] =
      interception_v15_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    interception_v15_DW.RateTransition_Buffer0[0] =
      interception_v15_P.RateTransition_InitialCondition;
    interception_v15_DW.RateTransition_Buffer0[1] =
      interception_v15_P.RateTransition_InitialCondition;
    interception_v15_DW.RateTransition_Buffer0[2] =
      interception_v15_P.RateTransition_InitialCondition;

    // InitializeConditions for Delay: '<Root>/Delay'
    interception_v15_DW.Delay_DSTATE[0] =
      interception_v15_P.Delay_InitialCondition;
    interception_v15_DW.Delay_DSTATE[1] =
      interception_v15_P.Delay_InitialCondition;

    // InitializeConditions for Switch: '<S27>/Reset' incorporates:
    //   Memory: '<S27>/Memory'

    interception_v15_DW.Memory_PreviousInput =
      interception_v15_P.MinMaxRunningResettable_vinit;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Vel2Pos'
    interception_v15_DW.Vel2Pos_IC_LOADING = 1U;

    // SystemInitialize for Atomic SubSystem: '<Root>/Missile Velocity'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S29>/In1' incorporates:
    //   Outport: '<S29>/Out1'

    interception_v15_B.In1_m = interception_v15_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    interception_v15_DW.obj_e.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_e.isInitialized = 1;
    for (int32_T i = 0; i < 37; i++) {
      interception_v15_B.b_zeroDelimTopic[i] = tmp[i];
    }

    interception_v15_B.b_zeroDelimTopic[37] = '\x00';
    Sub_interception_v15_179.createSubscriber
      (&interception_v15_B.b_zeroDelimTopic[0], 1);
    interception_v15_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Missile Velocity'

    // SystemInitialize for Atomic SubSystem: '<Root>/Missile Position'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S28>/In1' incorporates:
    //   Outport: '<S28>/Out1'

    interception_v15_B.In1 = interception_v15_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    interception_v15_DW.obj_e0.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_e0.isInitialized = 1;
    for (int32_T i = 0; i < 27; i++) {
      interception_v15_B.b_zeroDelimTopic_b[i] = tmp_0[i];
    }

    interception_v15_B.b_zeroDelimTopic_b[27] = '\x00';
    Sub_interception_v15_180.createSubscriber
      (&interception_v15_B.b_zeroDelimTopic_b[0], 1);
    interception_v15_DW.obj_e0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Missile Position'

    // SystemInitialize for Enabled SubSystem: '<Root>/Sending thrust commands'
    // SystemInitialize for Atomic SubSystem: '<S20>/Publish'
    // Start for MATLABSystem: '<S33>/SinkBlock'
    interception_v15_DW.obj_gb.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_gb.isInitialized = 1;
    for (int32_T i = 0; i < 29; i++) {
      interception_v15_B.b_zeroDelimTopic_k[i] = tmp_1[i];
    }

    interception_v15_B.b_zeroDelimTopic_k[29] = '\x00';
    Pub_interception_v15_178.createPublisher
      (&interception_v15_B.b_zeroDelimTopic_k[0], 1);
    interception_v15_DW.obj_gb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S33>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S20>/Publish'
    interception_v_CurrentTime_Init(&interception_v15_DW.CurrentTime_pn);

    // End of SystemInitialize for SubSystem: '<Root>/Sending thrust commands'

    // SystemInitialize for Enabled SubSystem: '<Root>/Sending position commands' 
    // SystemInitialize for Atomic SubSystem: '<S19>/Publish'
    // Start for MATLABSystem: '<S31>/SinkBlock'
    interception_v15_DW.obj_ap.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_ap.isInitialized = 1;
    for (int32_T i = 0; i < 31; i++) {
      interception_v15_B.b_zeroDelimTopic_m[i] = tmp_2[i];
    }

    interception_v15_B.b_zeroDelimTopic_m[31] = '\x00';
    Pub_interception_v15_311.createPublisher
      (&interception_v15_B.b_zeroDelimTopic_m[0], 1);
    interception_v15_DW.obj_ap.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S31>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S19>/Publish'
    interception_v_CurrentTime_Init(&interception_v15_DW.CurrentTime_p);

    // End of SystemInitialize for SubSystem: '<Root>/Sending position commands' 

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S15>/SinkBlock'
    interception_v15_DW.obj_mm.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_mm.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      b_zeroDelimTopic[i] = tmp_3[i];
    }

    b_zeroDelimTopic[15] = '\x00';
    Pub_interception_v15_451.createPublisher(&b_zeroDelimTopic[0], 1);
    interception_v15_DW.obj_mm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S15>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish4'
    // Start for MATLABSystem: '<S16>/SinkBlock'
    interception_v15_DW.obj_go.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_go.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      b_zeroDelimTopic[i] = tmp_4[i];
    }

    b_zeroDelimTopic[15] = '\x00';
    Pub_interception_v15_469.createPublisher(&b_zeroDelimTopic[0], 1);
    interception_v15_DW.obj_go.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S13>/SinkBlock'
    interception_v15_DW.obj_ft.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_ft.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = tmp_5[i];
    }

    b_zeroDelimTopic_0[17] = '\x00';
    Pub_interception_v15_442.createPublisher(&b_zeroDelimTopic_0[0], 1);
    interception_v15_DW.obj_ft.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S13>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S14>/SinkBlock'
    interception_v15_DW.obj_c5.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_c5.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = tmp_6[i];
    }

    b_zeroDelimTopic_0[17] = '\x00';
    Pub_interception_v15_446.createPublisher(&b_zeroDelimTopic_0[0], 1);
    interception_v15_DW.obj_c5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S12>/SinkBlock'
    interception_v15_DW.obj_cs.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_cs.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = tmp_7[i];
    }

    b_zeroDelimTopic_0[17] = '\x00';
    Pub_interception_v15_350.createPublisher(&b_zeroDelimTopic_0[0], 1);
    interception_v15_DW.obj_cs.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // Start for MATLABSystem: '<S22>/Get Parameter'
    interception_v15_DW.obj_b.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_b.isInitialized = 1;
    for (int32_T i = 0; i < 25; i++) {
      interception_v15_B.b_zeroDelimName_cv[i] = tmp_8[i];
    }

    interception_v15_B.b_zeroDelimName_cv[25] = '\x00';
    ParamGet_interception_v15_269.initialize
      (&interception_v15_B.b_zeroDelimName_cv[0]);
    ParamGet_interception_v15_269.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_269.set_initial_value(0.0);
    interception_v15_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S22>/Get Parameter'

    // Start for MATLABSystem: '<S22>/Get Parameter1'
    interception_v15_DW.obj_i.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_i.isInitialized = 1;
    for (int32_T i = 0; i < 25; i++) {
      interception_v15_B.b_zeroDelimName_cv[i] = tmp_9[i];
    }

    interception_v15_B.b_zeroDelimName_cv[25] = '\x00';
    ParamGet_interception_v15_270.initialize
      (&interception_v15_B.b_zeroDelimName_cv[0]);
    ParamGet_interception_v15_270.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_270.set_initial_value(0.0);
    interception_v15_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S22>/Get Parameter1'

    // Start for MATLABSystem: '<S22>/Get Parameter2'
    interception_v15_DW.obj_c.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_c.isInitialized = 1;
    for (int32_T i = 0; i < 25; i++) {
      interception_v15_B.b_zeroDelimName_cv[i] = tmp_a[i];
    }

    interception_v15_B.b_zeroDelimName_cv[25] = '\x00';
    ParamGet_interception_v15_271.initialize
      (&interception_v15_B.b_zeroDelimName_cv[0]);
    ParamGet_interception_v15_271.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_271.set_initial_value(0.0);
    interception_v15_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S22>/Get Parameter2'

    // Start for MATLABSystem: '<Root>/Get Parameter6'
    interception_v15_DW.obj_av.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_av.isInitialized = 1;
    for (int32_T i = 0; i < 30; i++) {
      interception_v15_B.b_zeroDelimName_c[i] = tmp_b[i];
    }

    interception_v15_B.b_zeroDelimName_c[30] = '\x00';
    ParamGet_interception_v15_480.initialize
      (&interception_v15_B.b_zeroDelimName_c[0]);
    ParamGet_interception_v15_480.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_480.set_initial_value(50.0);
    interception_v15_DW.obj_av.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter6'

    // Start for MATLABSystem: '<Root>/Get Parameter10'
    interception_v15_DW.obj_pb.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_pb.isInitialized = 1;
    for (int32_T i = 0; i < 22; i++) {
      b_zeroDelimName[i] = tmp_c[i];
    }

    b_zeroDelimName[22] = '\x00';
    ParamGet_interception_v15_506.initialize(&b_zeroDelimName[0]);
    ParamGet_interception_v15_506.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_506.set_initial_value(0.1);
    interception_v15_DW.obj_pb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter10'

    // Start for MATLABSystem: '<Root>/Get Parameter2'
    interception_v15_DW.obj_bh.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_bh.isInitialized = 1;
    for (int32_T i = 0; i < 28; i++) {
      interception_v15_B.b_zeroDelimName_cx[i] = tmp_d[i];
    }

    interception_v15_B.b_zeroDelimName_cx[28] = '\x00';
    ParamGet_interception_v15_276.initialize
      (&interception_v15_B.b_zeroDelimName_cx[0]);
    ParamGet_interception_v15_276.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_276.set_initial_value(0.2);
    interception_v15_DW.obj_bh.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter2'

    // Start for MATLABSystem: '<Root>/Get Parameter4'
    interception_v15_DW.obj_l.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 26; i++) {
      interception_v15_B.b_zeroDelimName_p[i] = tmp_e[i];
    }

    interception_v15_B.b_zeroDelimName_p[26] = '\x00';
    ParamGet_interception_v15_479.initialize
      (&interception_v15_B.b_zeroDelimName_p[0]);
    ParamGet_interception_v15_479.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_479.set_initial_value(60.0);
    interception_v15_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter4'

    // Start for MATLABSystem: '<Root>/Get Parameter7'
    interception_v15_DW.obj_p.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 22; i++) {
      b_zeroDelimName[i] = tmp_f[i];
    }

    b_zeroDelimName[22] = '\x00';
    ParamGet_interception_v15_482.initialize(&b_zeroDelimName[0]);
    ParamGet_interception_v15_482.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_482.set_initial_value(9.81);
    interception_v15_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter7'

    // Start for MATLABSystem: '<Root>/Get Parameter11'
    interception_v15_DW.obj_ak.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_ak.isInitialized = 1;
    for (int32_T i = 0; i < 26; i++) {
      interception_v15_B.b_zeroDelimName_p[i] = tmp_g[i];
    }

    interception_v15_B.b_zeroDelimName_p[26] = '\x00';
    ParamGet_interception_v15_583.initialize
      (&interception_v15_B.b_zeroDelimName_p[0]);
    ParamGet_interception_v15_583.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_583.set_initial_value(0.07);
    interception_v15_DW.obj_ak.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter11'

    // Start for MATLABSystem: '<Root>/Get Parameter13'
    interception_v15_DW.obj_pt.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_pt.isInitialized = 1;
    for (int32_T i = 0; i < 29; i++) {
      interception_v15_B.b_zeroDelimTopic_k[i] = tmp_h[i];
    }

    interception_v15_B.b_zeroDelimTopic_k[29] = '\x00';
    ParamGet_interception_v15_552.initialize
      (&interception_v15_B.b_zeroDelimTopic_k[0]);
    ParamGet_interception_v15_552.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_552.set_initial_value(260.0);
    interception_v15_DW.obj_pt.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter13'

    // Start for MATLABSystem: '<Root>/Get Parameter14'
    interception_v15_DW.obj_f.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_f.isInitialized = 1;
    for (int32_T i = 0; i < 31; i++) {
      interception_v15_B.b_zeroDelimTopic_m[i] = tmp_i[i];
    }

    interception_v15_B.b_zeroDelimTopic_m[31] = '\x00';
    ParamGet_interception_v15_553.initialize
      (&interception_v15_B.b_zeroDelimTopic_m[0]);
    ParamGet_interception_v15_553.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_553.set_initial_value(100.0);
    interception_v15_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter14'

    // Start for MATLABSystem: '<Root>/Get Parameter5'
    interception_v15_DW.obj_o.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_o.isInitialized = 1;
    for (int32_T i = 0; i < 31; i++) {
      interception_v15_B.b_zeroDelimTopic_m[i] = tmp_j[i];
    }

    interception_v15_B.b_zeroDelimTopic_m[31] = '\x00';
    ParamGet_interception_v15_281.initialize
      (&interception_v15_B.b_zeroDelimTopic_m[0]);
    ParamGet_interception_v15_281.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_281.set_initial_value(0.75);
    interception_v15_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter5'

    // Start for MATLABSystem: '<Root>/Get Parameter'
    interception_v15_DW.obj_d.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_d.isInitialized = 1;
    for (int32_T i = 0; i < 23; i++) {
      interception_v15_B.b_zeroDelimName_g[i] = tmp_k[i];
    }

    interception_v15_B.b_zeroDelimName_g[23] = '\x00';
    ParamGet_interception_v15_334.initialize
      (&interception_v15_B.b_zeroDelimName_g[0]);
    ParamGet_interception_v15_334.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_334.set_initial_value(10.0);
    interception_v15_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter'

    // Start for MATLABSystem: '<Root>/Get Parameter8'
    interception_v15_DW.obj_mn.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_mn.isInitialized = 1;
    for (int32_T i = 0; i < 23; i++) {
      interception_v15_B.b_zeroDelimName_g[i] = tmp_l[i];
    }

    interception_v15_B.b_zeroDelimName_g[23] = '\x00';
    ParamGet_interception_v15_339.initialize
      (&interception_v15_B.b_zeroDelimName_g[0]);
    ParamGet_interception_v15_339.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_339.set_initial_value(10.0);
    interception_v15_DW.obj_mn.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter8'

    // Start for MATLABSystem: '<Root>/Get Parameter9'
    interception_v15_DW.obj_m.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_m.isInitialized = 1;
    for (int32_T i = 0; i < 23; i++) {
      interception_v15_B.b_zeroDelimName_g[i] = tmp_m[i];
    }

    interception_v15_B.b_zeroDelimName_g[23] = '\x00';
    ParamGet_interception_v15_340.initialize
      (&interception_v15_B.b_zeroDelimName_g[0]);
    ParamGet_interception_v15_340.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_340.set_initial_value(15.0);
    interception_v15_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter9'

    // Start for MATLABSystem: '<Root>/Set Parameter1'
    interception_v15_DW.obj_j.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 26; i++) {
      interception_v15_B.b_zeroDelimName_p[i] = tmp_n[i];
    }

    interception_v15_B.b_zeroDelimName_p[26] = '\x00';
    ParamSet_interception_v15_576.initialize
      (&interception_v15_B.b_zeroDelimName_p[0]);
    interception_v15_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Set Parameter1'

    // Start for MATLABSystem: '<Root>/Set Parameter'
    interception_v15_DW.obj_hv.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_hv.isInitialized = 1;
    for (int32_T i = 0; i < 34; i++) {
      interception_v15_B.b_zeroDelimName[i] = tmp_o[i];
    }

    interception_v15_B.b_zeroDelimName[34] = '\x00';
    ParamSet_interception_v15_573.initialize
      (&interception_v15_B.b_zeroDelimName[0]);
    interception_v15_DW.obj_hv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Set Parameter'

    // Start for MATLABSystem: '<Root>/Current Time'
    interception_v15_DW.obj.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj.isInitialized = 1;
    interception_v15_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    interception_v15_DW.obj_a3.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_a3.isInitialized = 1;
    for (int32_T i = 0; i < 25; i++) {
      interception_v15_B.b_zeroDelimName_cv[i] = tmp_p[i];
    }

    interception_v15_B.b_zeroDelimName_cv[25] = '\x00';
    ParamGet_interception_v15_275.initialize
      (&interception_v15_B.b_zeroDelimName_cv[0]);
    ParamGet_interception_v15_275.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_275.set_initial_value(1.0);
    interception_v15_DW.obj_a3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter1'

    // Start for MATLABSystem: '<S21>/Get Parameter'
    interception_v15_DW.obj_a.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_a.isInitialized = 1;
    for (int32_T i = 0; i < 24; i++) {
      interception_v15_B.b_zeroDelimName_f[i] = tmp_q[i];
    }

    interception_v15_B.b_zeroDelimName_f[24] = '\x00';
    ParamGet_interception_v15_262.initialize
      (&interception_v15_B.b_zeroDelimName_f[0]);
    ParamGet_interception_v15_262.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_262.set_initial_value(50.0);
    interception_v15_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/Get Parameter'

    // Start for MATLABSystem: '<S21>/Get Parameter1'
    interception_v15_DW.obj_h.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_h.isInitialized = 1;
    for (int32_T i = 0; i < 24; i++) {
      interception_v15_B.b_zeroDelimName_f[i] = tmp_r[i];
    }

    interception_v15_B.b_zeroDelimName_f[24] = '\x00';
    ParamGet_interception_v15_263.initialize
      (&interception_v15_B.b_zeroDelimName_f[0]);
    ParamGet_interception_v15_263.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_263.set_initial_value(50.0);
    interception_v15_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/Get Parameter1'

    // Start for MATLABSystem: '<S21>/Get Parameter2'
    interception_v15_DW.obj_g.matlabCodegenIsDeleted = false;
    interception_v15_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 24; i++) {
      interception_v15_B.b_zeroDelimName_f[i] = tmp_s[i];
    }

    interception_v15_B.b_zeroDelimName_f[24] = '\x00';
    ParamGet_interception_v15_264.initialize
      (&interception_v15_B.b_zeroDelimName_f[0]);
    ParamGet_interception_v15_264.initialize_error_codes(0, 1, 2, 3);
    ParamGet_interception_v15_264.set_initial_value(50.0);
    interception_v15_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/Get Parameter2'
  }
}

// Model terminate function
void interception_v15_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Missile Velocity'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!interception_v15_DW.obj_e.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Missile Velocity'

  // Terminate for Atomic SubSystem: '<Root>/Missile Position'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!interception_v15_DW.obj_e0.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_e0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Missile Position'

  // Terminate for MATLABSystem: '<S22>/Get Parameter'
  if (!interception_v15_DW.obj_b.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/Get Parameter'

  // Terminate for MATLABSystem: '<S22>/Get Parameter1'
  if (!interception_v15_DW.obj_i.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/Get Parameter1'

  // Terminate for MATLABSystem: '<S22>/Get Parameter2'
  if (!interception_v15_DW.obj_c.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/Get Parameter2'

  // Terminate for MATLABSystem: '<Root>/Get Parameter6'
  if (!interception_v15_DW.obj_av.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_av.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter6'

  // Terminate for MATLABSystem: '<Root>/Get Parameter10'
  if (!interception_v15_DW.obj_pb.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_pb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter10'

  // Terminate for MATLABSystem: '<Root>/Get Parameter2'
  if (!interception_v15_DW.obj_bh.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_bh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter2'

  // Terminate for MATLABSystem: '<Root>/Get Parameter4'
  if (!interception_v15_DW.obj_l.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter4'

  // Terminate for MATLABSystem: '<Root>/Get Parameter7'
  if (!interception_v15_DW.obj_p.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter7'

  // Terminate for MATLABSystem: '<Root>/Get Parameter11'
  if (!interception_v15_DW.obj_ak.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_ak.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter11'

  // Terminate for MATLABSystem: '<Root>/Get Parameter13'
  if (!interception_v15_DW.obj_pt.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_pt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter13'

  // Terminate for MATLABSystem: '<Root>/Get Parameter14'
  if (!interception_v15_DW.obj_f.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter14'

  // Terminate for MATLABSystem: '<Root>/Get Parameter5'
  if (!interception_v15_DW.obj_o.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter5'

  // Terminate for Enabled SubSystem: '<Root>/Sending thrust commands'
  interception_v_CurrentTime_Term(&interception_v15_DW.CurrentTime_pn);

  // Terminate for Atomic SubSystem: '<S20>/Publish'
  // Terminate for MATLABSystem: '<S33>/SinkBlock'
  if (!interception_v15_DW.obj_gb.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_gb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/SinkBlock'
  // End of Terminate for SubSystem: '<S20>/Publish'
  // End of Terminate for SubSystem: '<Root>/Sending thrust commands'

  // Terminate for MATLABSystem: '<Root>/Get Parameter'
  if (!interception_v15_DW.obj_d.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter'

  // Terminate for MATLABSystem: '<Root>/Get Parameter8'
  if (!interception_v15_DW.obj_mn.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_mn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter8'

  // Terminate for MATLABSystem: '<Root>/Get Parameter9'
  if (!interception_v15_DW.obj_m.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter9'

  // Terminate for Enabled SubSystem: '<Root>/Sending position commands'
  interception_v_CurrentTime_Term(&interception_v15_DW.CurrentTime_p);

  // Terminate for Atomic SubSystem: '<S19>/Publish'
  // Terminate for MATLABSystem: '<S31>/SinkBlock'
  if (!interception_v15_DW.obj_ap.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_ap.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/SinkBlock'
  // End of Terminate for SubSystem: '<S19>/Publish'
  // End of Terminate for SubSystem: '<Root>/Sending position commands'

  // Terminate for MATLABSystem: '<Root>/Set Parameter1'
  if (!interception_v15_DW.obj_j.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Set Parameter1'

  // Terminate for MATLABSystem: '<Root>/Set Parameter'
  if (!interception_v15_DW.obj_hv.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_hv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Set Parameter'

  // Terminate for MATLABSystem: '<Root>/Current Time'
  if (!interception_v15_DW.obj.matlabCodegenIsDeleted) {
    interception_v15_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Current Time'

  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!interception_v15_DW.obj_a3.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_a3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S15>/SinkBlock'
  if (!interception_v15_DW.obj_mm.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_mm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'

  // Terminate for Atomic SubSystem: '<Root>/Publish4'
  // Terminate for MATLABSystem: '<S16>/SinkBlock'
  if (!interception_v15_DW.obj_go.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_go.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish4'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S13>/SinkBlock'
  if (!interception_v15_DW.obj_ft.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_ft.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S14>/SinkBlock'
  if (!interception_v15_DW.obj_c5.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_c5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!interception_v15_DW.obj_cs.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_cs.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for MATLABSystem: '<S21>/Get Parameter'
  if (!interception_v15_DW.obj_a.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter'

  // Terminate for MATLABSystem: '<S21>/Get Parameter1'
  if (!interception_v15_DW.obj_h.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter1'

  // Terminate for MATLABSystem: '<S21>/Get Parameter2'
  if (!interception_v15_DW.obj_g.matlabCodegenIsDeleted) {
    interception_v15_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter2'
}

//
// File trailer for generated code.
//
// [EOF]
//
