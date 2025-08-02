#pragma once
#include <ipp/ippcore.h>
#include <ipp/ippvm.h>
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <stdexcept>

namespace tipp
{
    namespace s
    {
        /* Essential Statistical */
        static inline IppStatus Sum(const Ipp32f *pSrc, int len, Ipp32f *pSum) { return OptionalAssertNoError(ippsSum_32f(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline IppStatus Sum(const Ipp32fc *pSrc, int len, Ipp32fc *pSum) { return OptionalAssertNoError(ippsSum_32fc(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline IppStatus Sum(const Ipp64f *pSrc, int len, Ipp64f *pSum) { return OptionalAssertNoError(ippsSum_64f(pSrc, len, pSum)); }
        static inline IppStatus Sum(const Ipp64fc *pSrc, int len, Ipp64fc *pSum) { return OptionalAssertNoError(ippsSum_64fc(pSrc, len, pSum)); }
        static inline IppStatus Sum(const std::complex<float> *pSrc, int len, std::complex<float> *pSum) { return OptionalAssertNoError(ippsSum_32fc((Ipp32fc *)pSrc, len, (Ipp32fc *)pSum, ippAlgHintAccurate)); }
        static inline IppStatus Sum(const std::complex<double> *pSrc, int len, std::complex<double> *pSum) { return OptionalAssertNoError(ippsSum_64fc((Ipp64fc *)pSrc, len, (Ipp64fc *)pSum)); }

        static inline IppStatus Sum_Sfs(const Ipp16s *pSrc, int len, Ipp16s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp32s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16s32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16sc_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp32sc *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16sc32sc_Sfs(pSrc, len, pSum, scaleFactor)); }

        static inline IppStatus MaxAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_16s(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_32s(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_32f(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_64f(pSrc, len, pMaxAbs, pIndx)); }

        static inline IppStatus MaxAbs(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_16s(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_32s(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_32f(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_64f(pSrc, len, pMaxAbs)); }

        static inline IppStatus MaxEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_64f(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus MaxEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_64f_I(pSrc, pSrcDst, len)); }

        static inline IppStatus MaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_16s(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_32s(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_32f(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_64f(pSrc, len, pMax, pIndx)); }

        static inline IppStatus Max(const Ipp16s *pSrc, int len, Ipp16s *pMax) { return OptionalAssertNoError(ippsMax_16s(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp32s *pSrc, int len, Ipp32s *pMax) { return OptionalAssertNoError(ippsMax_32s(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp32f *pSrc, int len, Ipp32f *pMax) { return OptionalAssertNoError(ippsMax_32f(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp64f *pSrc, int len, Ipp64f *pMax) { return OptionalAssertNoError(ippsMax_64f(pSrc, len, pMax)); }

        static inline IppStatus MeanStdDev(const Ipp32f *pSrc, int len, Ipp32f *pMean, Ipp32f *pStdDev) { return OptionalAssertNoError(ippsMeanStdDev_32f(pSrc, len, pMean, pStdDev, ippAlgHintAccurate)); }
        static inline IppStatus MeanStdDev(const Ipp64f *pSrc, int len, Ipp64f *pMean, Ipp64f *pStdDev) { return OptionalAssertNoError(ippsMeanStdDev_64f(pSrc, len, pMean, pStdDev)); }

        static inline IppStatus Mean(const Ipp32f *pSrc, int len, Ipp32f *pMean) { return OptionalAssertNoError(ippsMean_32f(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline IppStatus Mean(const Ipp32fc *pSrc, int len, Ipp32fc *pMean) { return OptionalAssertNoError(ippsMean_32fc(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline IppStatus Mean(const Ipp64f *pSrc, int len, Ipp64f *pMean) { return OptionalAssertNoError(ippsMean_64f(pSrc, len, pMean)); }
        static inline IppStatus Mean(const Ipp64fc *pSrc, int len, Ipp64fc *pMean) { return OptionalAssertNoError(ippsMean_64fc(pSrc, len, pMean)); }
        static inline IppStatus Mean(const std::complex<float> *pSrc, int len, std::complex<float> *pMean) { return OptionalAssertNoError(ippsMean_32fc((Ipp32fc *)pSrc, len, (Ipp32fc *)pMean, ippAlgHintAccurate)); }
        static inline IppStatus Mean(const std::complex<double> *pSrc, int len, std::complex<double> *pMean) { return OptionalAssertNoError(ippsMean_64fc((Ipp64fc *)pSrc, len, (Ipp64fc *)pMean)); }

        static inline IppStatus MinAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_16s(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_32s(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_32f(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_64f(pSrc, len, pMinAbs, pIndx)); }

        static inline IppStatus MinAbs(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_16s(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_32s(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_32f(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_64f(pSrc, len, pMinAbs)); }

        static inline IppStatus MinIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_16s(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_32s(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_32f(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_64f(pSrc, len, pMin, pIndx)); }

        static inline IppStatus MinMaxIndx(const Ipp8u *pSrc, int len, Ipp8u *pMin, int *pMinIndx, Ipp8u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_8u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp16u *pSrc, int len, Ipp16u *pMin, int *pMinIndx, Ipp16u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_16u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pMinIndx, Ipp16s *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_16s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32u *pSrc, int len, Ipp32u *pMin, int *pMinIndx, Ipp32u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pMinIndx, Ipp32s *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pMinIndx, Ipp32f *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pMinIndx, Ipp64f *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_64f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }

        static inline IppStatus MinMax(const Ipp8u *pSrc, int len, Ipp8u *pMin, Ipp8u *pMax) { return OptionalAssertNoError(ippsMinMax_8u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp16u *pSrc, int len, Ipp16u *pMin, Ipp16u *pMax) { return OptionalAssertNoError(ippsMinMax_16u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp16s *pSrc, int len, Ipp16s *pMin, Ipp16s *pMax) { return OptionalAssertNoError(ippsMinMax_16s(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32u *pSrc, int len, Ipp32u *pMin, Ipp32u *pMax) { return OptionalAssertNoError(ippsMinMax_32u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32s *pSrc, int len, Ipp32s *pMin, Ipp32s *pMax) { return OptionalAssertNoError(ippsMinMax_32s(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32f *pSrc, int len, Ipp32f *pMin, Ipp32f *pMax) { return OptionalAssertNoError(ippsMinMax_32f(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp64f *pSrc, int len, Ipp64f *pMin, Ipp64f *pMax) { return OptionalAssertNoError(ippsMinMax_64f(pSrc, len, pMin, pMax)); }

        static inline IppStatus Min(const Ipp16s *pSrc, int len, Ipp16s *pMin) { return OptionalAssertNoError(ippsMin_16s(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp32s *pSrc, int len, Ipp32s *pMin) { return OptionalAssertNoError(ippsMin_32s(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp32f *pSrc, int len, Ipp32f *pMin) { return OptionalAssertNoError(ippsMin_32f(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp64f *pSrc, int len, Ipp64f *pMin) { return OptionalAssertNoError(ippsMin_64f(pSrc, len, pMin)); }

        static inline IppStatus ReplaceNAN(Ipp32f *pSrcDst, int len, Ipp32f value) { return OptionalAssertNoError(ippsReplaceNAN_32f_I(pSrcDst, len, value)); }
        static inline IppStatus ReplaceNAN(Ipp64f *pSrcDst, int len, Ipp64f value) { return OptionalAssertNoError(ippsReplaceNAN_64f_I(pSrcDst, len, value)); }

        static inline IppStatus NormDiff_Inf(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_32fc32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, int len, float *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_32fc32f((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, int len, double *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_64fc64f((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, len, pNorm)); }

        static inline IppStatus NormDiff_L1(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, int len, double *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_32fc64f((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, int len, double *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_64fc64f((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, len, pNorm)); }

        static inline IppStatus NormDiff_L2(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, int len, double *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_32fc64f((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, int len, double *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_64fc64f((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, len, pNorm)); }

        static inline IppStatus Norm_Inf(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp32fc *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_32fc32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_64fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const std::complex<float> *pSrc, int len, float *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_32fc32f((Ipp32fc *)pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const std::complex<double> *pSrc, int len, double *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_64fc64f((Ipp64fc *)pSrc, len, pNorm)); }

        static inline IppStatus Norm_L1(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_32fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_64fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const std::complex<float> *pSrc, int len, double *pNorm) { return OptionalAssertNoError(ippsNorm_L1_32fc64f((Ipp32fc *)pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const std::complex<double> *pSrc, int len, double *pNorm) { return OptionalAssertNoError(ippsNorm_L1_64fc64f((Ipp64fc *)pSrc, len, pNorm)); }

        static inline IppStatus Norm_L2(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_32fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_64fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const std::complex<float> *pSrc, int len, double *pNorm) { return OptionalAssertNoError(ippsNorm_L2_32fc64f((Ipp32fc *)pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const std::complex<double> *pSrc, int len, double *pNorm) { return OptionalAssertNoError(ippsNorm_L2_64fc64f((Ipp64fc *)pSrc, len, pNorm)); }

        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pDp) { return OptionalAssertNoError(ippsDotProd_32f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { return OptionalAssertNoError(ippsDotProd_32fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp64f *pDp) { return OptionalAssertNoError(ippsDotProd_32f64f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pDp) { return OptionalAssertNoError(ippsDotProd_64f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64f *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_64f64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp64s *pDp) { return OptionalAssertNoError(ippsDotProd_16s64s(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16sc *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { return OptionalAssertNoError(ippsDotProd_16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { return OptionalAssertNoError(ippsDotProd_16s16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pDp) { return OptionalAssertNoError(ippsDotProd_16s32f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, int len, std::complex<float> *pDp) { return OptionalAssertNoError(ippsDotProd_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, len, (Ipp32fc *)pDp)); }
        static inline IppStatus DotProd(const float *pSrc1, const std::complex<float> *pSrc2, int len, std::complex<float> *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc(pSrc1, (Ipp32fc *)pSrc2, len, (Ipp32fc *)pDp)); }
        static inline IppStatus DotProd(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, int len, std::complex<double> *pDp) { return OptionalAssertNoError(ippsDotProd_32fc64fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, len, (Ipp64fc *)pDp)); }
        static inline IppStatus DotProd(const float *pSrc1, const std::complex<float> *pSrc2, int len, std::complex<double> *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc64fc(pSrc1, (Ipp32fc *)pSrc2, len, (Ipp64fc *)pDp)); }
        static inline IppStatus DotProd(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, int len, std::complex<double> *pDp) { return OptionalAssertNoError(ippsDotProd_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, len, (Ipp64fc *)pDp)); }
        static inline IppStatus DotProd(const double *pSrc1, const std::complex<double> *pSrc2, int len, std::complex<double> *pDp) { return OptionalAssertNoError(ippsDotProd_64f64fc(pSrc1, (Ipp64fc *)pSrc2, len, (Ipp64fc *)pDp)); }

        static inline IppStatus StdDev(const Ipp32f *pSrc, int len, Ipp32f *pStdDev) { return OptionalAssertNoError(ippsStdDev_32f(pSrc, len, pStdDev, ippAlgHintAccurate)); }
        static inline IppStatus StdDev(const Ipp64f *pSrc, int len, Ipp64f *pStdDev) { return OptionalAssertNoError(ippsStdDev_64f(pSrc, len, pStdDev)); }

    }

}
