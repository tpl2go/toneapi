#include <ipps.h>
#include <ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <vector>

namespace tipp
{

    static inline void Sum(const Ipp32f *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSum_32f(pSrc, len, pSum, ippAlgHintAccurate)); }
    static inline void Sum(const Ipp32fc *pSrc, int len, Ipp32fc *pSum) { AssertNoError(ippsSum_32fc(pSrc, len, pSum, ippAlgHintAccurate)); }
    static inline void Sum(const Ipp64f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSum_64f(pSrc, len, pSum)); }
    static inline void Sum(const Ipp64fc *pSrc, int len, Ipp64fc *pSum) { AssertNoError(ippsSum_64fc(pSrc, len, pSum)); }

    static inline void Sum_Sfs(const Ipp16s *pSrc, int len, Ipp16s *pSum, int scaleFactor) { AssertNoError(ippsSum_16s_Sfs(pSrc, len, pSum, scaleFactor)); }
    static inline void Sum_Sfs(const Ipp32s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { AssertNoError(ippsSum_32s_Sfs(pSrc, len, pSum, scaleFactor)); }
    static inline void Sum_Sfs(const Ipp16s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { AssertNoError(ippsSum_16s32s_Sfs(pSrc, len, pSum, scaleFactor)); }
    static inline void Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pSum, int scaleFactor) { AssertNoError(ippsSum_16sc_Sfs(pSrc, len, pSum, scaleFactor)); }
    static inline void Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp32sc *pSum, int scaleFactor) { AssertNoError(ippsSum_16sc32sc_Sfs(pSrc, len, pSum, scaleFactor)); }

    static inline void MaxAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_16s(pSrc, len, pMaxAbs, pIndx)); }
    static inline void MaxAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_32s(pSrc, len, pMaxAbs, pIndx)); }
    static inline void MaxAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_32f(pSrc, len, pMaxAbs, pIndx)); }
    static inline void MaxAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_64f(pSrc, len, pMaxAbs, pIndx)); }

    static inline void MaxAbs(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs) { AssertNoError(ippsMaxAbs_16s(pSrc, len, pMaxAbs)); }
    static inline void MaxAbs(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs) { AssertNoError(ippsMaxAbs_32s(pSrc, len, pMaxAbs)); }
    static inline void MaxAbs(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs) { AssertNoError(ippsMaxAbs_32f(pSrc, len, pMaxAbs)); }
    static inline void MaxAbs(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs) { AssertNoError(ippsMaxAbs_64f(pSrc, len, pMaxAbs)); }

    static inline void MaxEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_8u(pSrc1, pSrc2, pDst, len)); }
    static inline void MaxEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_16u(pSrc1, pSrc2, pDst, len)); }
    static inline void MaxEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void MaxEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void MinEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_8u(pSrc1, pSrc2, pDst, len)); }
    static inline void MinEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_16u(pSrc1, pSrc2, pDst, len)); }
    static inline void MinEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void MinEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void MaxEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsMaxEvery_8u_I(pSrc, pSrcDst, len)); }
    static inline void MaxEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsMaxEvery_16u_I(pSrc, pSrcDst, len)); }
    static inline void MaxEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMaxEvery_16s_I(pSrc, pSrcDst, len)); }
    static inline void MaxEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { AssertNoError(ippsMaxEvery_32s_I(pSrc, pSrcDst, len)); }
    static inline void MaxEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMaxEvery_32f_I(pSrc, pSrcDst, len)); }
    static inline void MaxEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { AssertNoError(ippsMaxEvery_64f_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsMinEvery_8u_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsMinEvery_16u_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMinEvery_16s_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { AssertNoError(ippsMinEvery_32s_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMinEvery_32f_I(pSrc, pSrcDst, len)); }
    static inline void MinEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { AssertNoError(ippsMinEvery_64f_I(pSrc, pSrcDst, len)); }

    static inline void MaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_16s(pSrc, len, pMax, pIndx)); }
    static inline void MaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_32s(pSrc, len, pMax, pIndx)); }
    static inline void MaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_32f(pSrc, len, pMax, pIndx)); }
    static inline void MaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_64f(pSrc, len, pMax, pIndx)); }

    static inline void Max(const Ipp16s *pSrc, int len, Ipp16s *pMax) { AssertNoError(ippsMax_16s(pSrc, len, pMax)); }
    static inline void Max(const Ipp32s *pSrc, int len, Ipp32s *pMax) { AssertNoError(ippsMax_32s(pSrc, len, pMax)); }
    static inline void Max(const Ipp32f *pSrc, int len, Ipp32f *pMax) { AssertNoError(ippsMax_32f(pSrc, len, pMax)); }
    static inline void Max(const Ipp64f *pSrc, int len, Ipp64f *pMax) { AssertNoError(ippsMax_64f(pSrc, len, pMax)); }

    static inline void MeanStdDev(const Ipp32f *pSrc, int len, Ipp32f *pMean, Ipp32f *pStdDev) { AssertNoError(ippsMeanStdDev_32f(pSrc, len, pMean, pStdDev, ippAlgHintAccurate)); }
    static inline void MeanStdDev(const Ipp64f *pSrc, int len, Ipp64f *pMean, Ipp64f *pStdDev) { AssertNoError(ippsMeanStdDev_64f(pSrc, len, pMean, pStdDev)); }

    static inline void Mean(const Ipp32f *pSrc, int len, Ipp32f *pMean) { AssertNoError(ippsMean_32f(pSrc, len, pMean, ippAlgHintAccurate)); }
    static inline void Mean(const Ipp32fc *pSrc, int len, Ipp32fc *pMean) { AssertNoError(ippsMean_32fc(pSrc, len, pMean, ippAlgHintAccurate)); }
    static inline void Mean(const Ipp64f *pSrc, int len, Ipp64f *pMean) { AssertNoError(ippsMean_64f(pSrc, len, pMean)); }
    static inline void Mean(const Ipp64fc *pSrc, int len, Ipp64fc *pMean) { AssertNoError(ippsMean_64fc(pSrc, len, pMean)); }

    static inline void MinAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_16s(pSrc, len, pMinAbs, pIndx)); }
    static inline void MinAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_32s(pSrc, len, pMinAbs, pIndx)); }
    static inline void MinAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_32f(pSrc, len, pMinAbs, pIndx)); }
    static inline void MinAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_64f(pSrc, len, pMinAbs, pIndx)); }

    static inline void MinAbs(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs) { AssertNoError(ippsMinAbs_16s(pSrc, len, pMinAbs)); }
    static inline void MinAbs(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs) { AssertNoError(ippsMinAbs_32s(pSrc, len, pMinAbs)); }
    static inline void MinAbs(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs) { AssertNoError(ippsMinAbs_32f(pSrc, len, pMinAbs)); }
    static inline void MinAbs(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs) { AssertNoError(ippsMinAbs_64f(pSrc, len, pMinAbs)); }

    static inline void MinIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pIndx) { AssertNoError(ippsMinIndx_16s(pSrc, len, pMin, pIndx)); }
    static inline void MinIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pIndx) { AssertNoError(ippsMinIndx_32s(pSrc, len, pMin, pIndx)); }
    static inline void MinIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pIndx) { AssertNoError(ippsMinIndx_32f(pSrc, len, pMin, pIndx)); }
    static inline void MinIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pIndx) { AssertNoError(ippsMinIndx_64f(pSrc, len, pMin, pIndx)); }

    static inline void MinMaxIndx(const Ipp8u *pSrc, int len, Ipp8u *pMin, int *pMinIndx, Ipp8u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_8u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp16u *pSrc, int len, Ipp16u *pMin, int *pMinIndx, Ipp16u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_16u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pMinIndx, Ipp16s *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_16s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp32u *pSrc, int len, Ipp32u *pMin, int *pMinIndx, Ipp32u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pMinIndx, Ipp32s *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pMinIndx, Ipp32f *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
    static inline void MinMaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pMinIndx, Ipp64f *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_64f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }

    static inline void MinMax(const Ipp8u *pSrc, int len, Ipp8u *pMin, Ipp8u *pMax) { AssertNoError(ippsMinMax_8u(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp16u *pSrc, int len, Ipp16u *pMin, Ipp16u *pMax) { AssertNoError(ippsMinMax_16u(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp16s *pSrc, int len, Ipp16s *pMin, Ipp16s *pMax) { AssertNoError(ippsMinMax_16s(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp32u *pSrc, int len, Ipp32u *pMin, Ipp32u *pMax) { AssertNoError(ippsMinMax_32u(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp32s *pSrc, int len, Ipp32s *pMin, Ipp32s *pMax) { AssertNoError(ippsMinMax_32s(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp32f *pSrc, int len, Ipp32f *pMin, Ipp32f *pMax) { AssertNoError(ippsMinMax_32f(pSrc, len, pMin, pMax)); }
    static inline void MinMax(const Ipp64f *pSrc, int len, Ipp64f *pMin, Ipp64f *pMax) { AssertNoError(ippsMinMax_64f(pSrc, len, pMin, pMax)); }

    static inline void Min(const Ipp16s *pSrc, int len, Ipp16s *pMin) { AssertNoError(ippsMin_16s(pSrc, len, pMin)); }
    static inline void Min(const Ipp32s *pSrc, int len, Ipp32s *pMin) { AssertNoError(ippsMin_32s(pSrc, len, pMin)); }
    static inline void Min(const Ipp32f *pSrc, int len, Ipp32f *pMin) { AssertNoError(ippsMin_32f(pSrc, len, pMin)); }
    static inline void Min(const Ipp64f *pSrc, int len, Ipp64f *pMin) { AssertNoError(ippsMin_64f(pSrc, len, pMin)); }

    static inline void ReplaceNAN(Ipp32f *pSrcDst, int len, Ipp32f value) { AssertNoError(ippsReplaceNAN_32f_I(pSrcDst, len, value)); }
    static inline void ReplaceNAN(Ipp64f *pSrcDst, int len, Ipp64f value) { AssertNoError(ippsReplaceNAN_64f_I(pSrcDst, len, value)); }

    static inline void NormDiff_Inf(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_Inf(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_Inf_64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_Inf(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_16s32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_Inf(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_32fc32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_Inf(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_Inf_64fc64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L1(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L1_32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L1(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L1(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L1_16s32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L1(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_32fc64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L1(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_64fc64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L2(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L2_32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L2(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L2(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L2_16s32f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L2(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_32fc64f(pSrc1, pSrc2, len, pNorm)); }
    static inline void NormDiff_L2(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_64fc64f(pSrc1, pSrc2, len, pNorm)); }

    static inline void Norm_Inf(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_32f(pSrc, len, pNorm)); }
    static inline void Norm_Inf(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_Inf_64f(pSrc, len, pNorm)); }
    static inline void Norm_Inf(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_16s32f(pSrc, len, pNorm)); }
    static inline void Norm_Inf(const Ipp32fc *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_32fc32f(pSrc, len, pNorm)); }
    static inline void Norm_Inf(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_Inf_64fc64f(pSrc, len, pNorm)); }
    static inline void Norm_L1(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L1_32f(pSrc, len, pNorm)); }
    static inline void Norm_L1(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_64f(pSrc, len, pNorm)); }
    static inline void Norm_L1(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L1_16s32f(pSrc, len, pNorm)); }
    static inline void Norm_L1(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_32fc64f(pSrc, len, pNorm)); }
    static inline void Norm_L1(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_64fc64f(pSrc, len, pNorm)); }
    static inline void Norm_L2(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L2_32f(pSrc, len, pNorm)); }
    static inline void Norm_L2(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_64f(pSrc, len, pNorm)); }
    static inline void Norm_L2(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L2_16s32f(pSrc, len, pNorm)); }
    static inline void Norm_L2(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_32fc64f(pSrc, len, pNorm)); }
    static inline void Norm_L2(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_64fc64f(pSrc, len, pNorm)); }

    static inline void DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pDp) { AssertNoError(ippsDotProd_32f(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { AssertNoError(ippsDotProd_32fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { AssertNoError(ippsDotProd_32f32fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp64f *pDp) { AssertNoError(ippsDotProd_32f64f(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_32fc64fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_32f32fc64fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pDp) { AssertNoError(ippsDotProd_64f(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_64fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp64f *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_64f64fc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp64s *pDp) { AssertNoError(ippsDotProd_16s64s(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp16sc *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { AssertNoError(ippsDotProd_16sc64sc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp16s *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { AssertNoError(ippsDotProd_16s16sc64sc(pSrc1, pSrc2, len, pDp)); }
    static inline void DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pDp) { AssertNoError(ippsDotProd_16s32f(pSrc1, pSrc2, len, pDp)); }

    static inline void StdDev(const Ipp32f *pSrc, int len, Ipp32f *pStdDev) { AssertNoError(ippsStdDev_32f(pSrc, len, pStdDev, ippAlgHintAccurate)); }
    static inline void StdDev(const Ipp64f *pSrc, int len, Ipp64f *pStdDev) { AssertNoError(ippsStdDev_64f(pSrc, len, pStdDev)); }

}
