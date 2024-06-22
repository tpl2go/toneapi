#pragma once
#include <ipp.h>
#include <complex>
#include "tipp_error.hpp"

namespace tipp
{
    static inline void Copy(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsCopy_8u(pSrc, pDst, len)); }                        // unsigned char
    static inline void Copy(const Ipp8s *pSrc, Ipp8s *pDst, int len) { AssertNoError(ippsCopy_8u((Ipp8u *)pSrc, (Ipp8u *)pDst, len)); }      // signed char  // REUSE
    static inline void Copy(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // unsigned short  // REUSE
    static inline void Copy(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsCopy_16s(pSrc, pDst, len)); }                     // signed short
    static inline void Copy(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsCopy_32s((Ipp32s *)pSrc, (Ipp32s *)pDst, len)); } // unsigned int
    static inline void Copy(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsCopy_32s(pSrc, pDst, len)); }                     // signed int
    static inline void Copy(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsCopy_32f(pSrc, pDst, len)); }                     // float
    static inline void Copy(const Ipp64s *pSrc, Ipp64s *pDst, int len) { AssertNoError(ippsCopy_64s(pSrc, pDst, len)); }                     // __int64 (Windows*) or long long (Linux*)
    static inline void Copy(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsCopy_64f(pSrc, pDst, len)); }                     // double
    static inline void Copy(const Ipp8sc *pSrc, Ipp8sc *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // REUSE another copy function
    static inline void Copy(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsCopy_16sc(pSrc, pDst, len)); }                  // complex short
    static inline void Copy(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { AssertNoError(ippsCopy_32sc(pSrc, pDst, len)); }                  // complex signed int
    static inline void Copy(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsCopy_32fc(pSrc, pDst, len)); }                  // complex float
    static inline void Copy(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { AssertNoError(ippsCopy_64sc(pSrc, pDst, len)); }                  // complex signed long long
    static inline void Copy(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsCopy_64fc(pSrc, pDst, len)); }                  // complex double

    static inline void Move(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsMove_8u(pSrc, pDst, len)); }
    static inline void Move(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsMove_16s(pSrc, pDst, len)); }
    static inline void Move(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsMove_32s(pSrc, pDst, len)); }
    static inline void Move(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMove_32f(pSrc, pDst, len)); }
    static inline void Move(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsMove_64f(pSrc, pDst, len)); }
    static inline void Move(const Ipp64s *pSrc, Ipp64s *pDst, int len) { AssertNoError(ippsMove_64s(pSrc, pDst, len)); }
    static inline void Move(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsMove_16sc(pSrc, pDst, len)); }
    static inline void Move(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { AssertNoError(ippsMove_32sc(pSrc, pDst, len)); }
    static inline void Move(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsMove_32fc(pSrc, pDst, len)); }
    static inline void Move(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { AssertNoError(ippsMove_64sc(pSrc, pDst, len)); }
    static inline void Move(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsMove_64fc(pSrc, pDst, len)); }

    static inline void Set(Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsSet_8u(val, pDst, len)); }
    static inline void Set(Ipp16s val, Ipp16s *pDst, int len) { AssertNoError(ippsSet_16s(val, pDst, len)); }
    static inline void Set(Ipp16sc val, Ipp16sc *pDst, int len) { AssertNoError(ippsSet_16sc(val, pDst, len)); }
    static inline void Set(Ipp32s val, Ipp32s *pDst, int len) { AssertNoError(ippsSet_32s(val, pDst, len)); }
    static inline void Set(Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsSet_32f(val, pDst, len)); }
    static inline void Set(Ipp32sc val, Ipp32sc *pDst, int len) { AssertNoError(ippsSet_32sc(val, pDst, len)); }
    static inline void Set(Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsSet_32fc(val, pDst, len)); }
    static inline void Set(Ipp64s val, Ipp64s *pDst, int len) { AssertNoError(ippsSet_64s(val, pDst, len)); }
    static inline void Set(Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsSet_64f(val, pDst, len)); }
    static inline void Set(Ipp64sc val, Ipp64sc *pDst, int len) { AssertNoError(ippsSet_64sc(val, pDst, len)); }
    static inline void Set(Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsSet_64fc(val, pDst, len)); }

    static inline void Zero(Ipp8u *pDst, int len) { AssertNoError(ippsZero_8u(pDst, len)); }
    static inline void Zero(Ipp16s *pDst, int len) { AssertNoError(ippsZero_16s(pDst, len)); }
    static inline void Zero(Ipp32s *pDst, int len) { AssertNoError(ippsZero_32s(pDst, len)); }
    static inline void Zero(Ipp32f *pDst, int len) { AssertNoError(ippsZero_32f(pDst, len)); }
    static inline void Zero(Ipp64s *pDst, int len) { AssertNoError(ippsZero_64s(pDst, len)); }
    static inline void Zero(Ipp64f *pDst, int len) { AssertNoError(ippsZero_64f(pDst, len)); }
    static inline void Zero(Ipp16sc *pDst, int len) { AssertNoError(ippsZero_16sc(pDst, len)); }
    static inline void Zero(Ipp32sc *pDst, int len) { AssertNoError(ippsZero_32sc(pDst, len)); }
    static inline void Zero(Ipp32fc *pDst, int len) { AssertNoError(ippsZero_32fc(pDst, len)); }
    static inline void Zero(Ipp64sc *pDst, int len) { AssertNoError(ippsZero_64sc(pDst, len)); }
    static inline void Zero(Ipp64fc *pDst, int len) { AssertNoError(ippsZero_64fc(pDst, len)); }

    static inline void Tone(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_16s(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline void Tone(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_16sc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline void Tone(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_32f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline void Tone(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_32fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline void Tone(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { AssertNoError(ippsTone_64f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline void Tone(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { AssertNoError(ippsTone_64fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }

    static inline void Triangle(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_16s(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline void Triangle(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_16sc(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline void Triangle(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_32f(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline void Triangle(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_32fc(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline void Triangle(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { AssertNoError(ippsTriangle_64f(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline void Triangle(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { AssertNoError(ippsTriangle_64fc(pDst, len, magn, rFreq, asym, pPhase)); }

    static inline void VectorJaehne(Ipp8u *pDst, int len, Ipp8u magn) { AssertNoError(ippsVectorJaehne_8u(pDst, len, magn)); }
    static inline void VectorJaehne(Ipp16u *pDst, int len, Ipp16u magn) { AssertNoError(ippsVectorJaehne_16u(pDst, len, magn)); }
    static inline void VectorJaehne(Ipp16s *pDst, int len, Ipp16s magn) { AssertNoError(ippsVectorJaehne_16s(pDst, len, magn)); }
    static inline void VectorJaehne(Ipp32s *pDst, int len, Ipp32s magn) { AssertNoError(ippsVectorJaehne_32s(pDst, len, magn)); }
    static inline void VectorJaehne(Ipp32f *pDst, int len, Ipp32f magn) { AssertNoError(ippsVectorJaehne_32f(pDst, len, magn)); }
    static inline void VectorJaehne(Ipp64f *pDst, int len, Ipp64f magn) { AssertNoError(ippsVectorJaehne_64f(pDst, len, magn)); }

    static inline void VectorSlope(Ipp8u *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_8u(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp16u *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_16u(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp16s *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_16s(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp32u *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_32u(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp32s *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_32s(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp32f *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_32f(pDst, len, offset, slope)); }
    static inline void VectorSlope(Ipp64f *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_64f(pDst, len, offset, slope)); }

    //   ippsRandGaussGetSize_16s
    //   ippsRandGaussGetSize_32f
    //   ippsRandGaussGetSize_64f
    //   ippsRandGaussGetSize_8u
    //   ippsRandGaussInit_16s
    //   ippsRandGaussInit_32f
    //   ippsRandGaussInit_64f
    //   ippsRandGaussInit_8u
    //   ippsRandGauss_16s
    //   ippsRandGauss_32f
    //   ippsRandGauss_64f
    //   ippsRandGauss_8u
    //   ippsRandUniformGetSize_16s
    //   ippsRandUniformGetSize_32f
    //   ippsRandUniformGetSize_64f
    //   ippsRandUniformGetSize_8u
    //   ippsRandUniformInit_16s
    //   ippsRandUniformInit_32f
    //   ippsRandUniformInit_64f
    //   ippsRandUniformInit_8u
    //   ippsRandUniform_16s
    //   ippsRandUniform_32f
    //   ippsRandUniform_64f
    //   ippsRandUniform_8u
}
