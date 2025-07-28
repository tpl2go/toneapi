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

    /* Essential Initialization */
    static inline IppStatus Copy(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsCopy_8u(pSrc, pDst, len)); }                        // unsigned char
    static inline IppStatus Copy(const Ipp8s *pSrc, Ipp8s *pDst, int len) { return OptionalAssertNoError(ippsCopy_8u((Ipp8u *)pSrc, (Ipp8u *)pDst, len)); }      // signed char  // REUSE
    static inline IppStatus Copy(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // unsigned short  // REUSE
    static inline IppStatus Copy(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s(pSrc, pDst, len)); }                     // signed short
    static inline IppStatus Copy(const Ipp32u *pSrc, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsCopy_32s((Ipp32s *)pSrc, (Ipp32s *)pDst, len)); } // unsigned int
    static inline IppStatus Copy(const Ipp32s *pSrc, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsCopy_32s(pSrc, pDst, len)); }                     // signed int
    static inline IppStatus Copy(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsCopy_32f(pSrc, pDst, len)); }                     // float
    static inline IppStatus Copy(const Ipp64s *pSrc, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsCopy_64s(pSrc, pDst, len)); }                     // __int64 (Windows*) or long long (Linux*)
    static inline IppStatus Copy(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsCopy_64f(pSrc, pDst, len)); }                     // double
    static inline IppStatus Copy(const Ipp8sc *pSrc, Ipp8sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // REUSE another copy function
    static inline IppStatus Copy(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_16sc(pSrc, pDst, len)); }                  // complex short
    static inline IppStatus Copy(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_32sc(pSrc, pDst, len)); }                  // complex signed int
    static inline IppStatus Copy(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsCopy_32fc(pSrc, pDst, len)); }                  // complex float
    static inline IppStatus Copy(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_64sc(pSrc, pDst, len)); }                  // complex signed long long
    static inline IppStatus Copy(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsCopy_64fc(pSrc, pDst, len)); }                  // complex double

    static inline IppStatus Move(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsMove_8u(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsMove_16s(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp32s *pSrc, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsMove_32s(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMove_32f(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMove_64f(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp64s *pSrc, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsMove_64s(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsMove_16sc(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsMove_32sc(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMove_32fc(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsMove_64sc(pSrc, pDst, len)); }
    static inline IppStatus Move(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMove_64fc(pSrc, pDst, len)); }

    static inline IppStatus Set(Ipp8u val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsSet_8u(val, pDst, len)); }
    static inline IppStatus Set(Ipp16s val, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsSet_16s(val, pDst, len)); }
    static inline IppStatus Set(Ipp16sc val, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsSet_16sc(val, pDst, len)); }
    static inline IppStatus Set(Ipp32s val, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsSet_32s(val, pDst, len)); }
    static inline IppStatus Set(Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSet_32f(val, pDst, len)); }
    static inline IppStatus Set(Ipp32sc val, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsSet_32sc(val, pDst, len)); }
    static inline IppStatus Set(Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSet_32fc(val, pDst, len)); }
    static inline IppStatus Set(Ipp64s val, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsSet_64s(val, pDst, len)); }
    static inline IppStatus Set(Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSet_64f(val, pDst, len)); }
    static inline IppStatus Set(Ipp64sc val, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsSet_64sc(val, pDst, len)); }
    static inline IppStatus Set(Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSet_64fc(val, pDst, len)); }

    static inline IppStatus Zero(Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsZero_8u(pDst, len)); }
    static inline IppStatus Zero(Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsZero_16s(pDst, len)); }
    static inline IppStatus Zero(Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsZero_32s(pDst, len)); }
    static inline IppStatus Zero(Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsZero_32f(pDst, len)); }
    static inline IppStatus Zero(Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsZero_64s(pDst, len)); }
    static inline IppStatus Zero(Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsZero_64f(pDst, len)); }
    static inline IppStatus Zero(Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsZero_16sc(pDst, len)); }
    static inline IppStatus Zero(Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsZero_32sc(pDst, len)); }
    static inline IppStatus Zero(Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsZero_32fc(pDst, len)); }
    static inline IppStatus Zero(Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsZero_64sc(pDst, len)); }
    static inline IppStatus Zero(Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsZero_64fc(pDst, len)); }

    static inline IppStatus Tone(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_16s(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline IppStatus Tone(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_16sc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline IppStatus Tone(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_32f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline IppStatus Tone(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_32fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline IppStatus Tone(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTone_64f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
    static inline IppStatus Tone(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTone_64fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }

    static inline IppStatus Triangle(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_16s(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline IppStatus Triangle(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_16sc(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline IppStatus Triangle(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_32f(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline IppStatus Triangle(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_32fc(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline IppStatus Triangle(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTriangle_64f(pDst, len, magn, rFreq, asym, pPhase)); }
    static inline IppStatus Triangle(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTriangle_64fc(pDst, len, magn, rFreq, asym, pPhase)); }

    static inline IppStatus VectorJaehne(Ipp8u *pDst, int len, Ipp8u magn) { return OptionalAssertNoError(ippsVectorJaehne_8u(pDst, len, magn)); }
    static inline IppStatus VectorJaehne(Ipp16u *pDst, int len, Ipp16u magn) { return OptionalAssertNoError(ippsVectorJaehne_16u(pDst, len, magn)); }
    static inline IppStatus VectorJaehne(Ipp16s *pDst, int len, Ipp16s magn) { return OptionalAssertNoError(ippsVectorJaehne_16s(pDst, len, magn)); }
    static inline IppStatus VectorJaehne(Ipp32s *pDst, int len, Ipp32s magn) { return OptionalAssertNoError(ippsVectorJaehne_32s(pDst, len, magn)); }
    static inline IppStatus VectorJaehne(Ipp32f *pDst, int len, Ipp32f magn) { return OptionalAssertNoError(ippsVectorJaehne_32f(pDst, len, magn)); }
    static inline IppStatus VectorJaehne(Ipp64f *pDst, int len, Ipp64f magn) { return OptionalAssertNoError(ippsVectorJaehne_64f(pDst, len, magn)); }

    static inline IppStatus VectorSlope(Ipp8u *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_8u(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp16u *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_16u(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp16s *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_16s(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp32u *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_32u(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp32s *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_32s(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp32f *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_32f(pDst, len, offset, slope)); }
    static inline IppStatus VectorSlope(Ipp64f *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_64f(pDst, len, offset, slope)); }

    static inline IppStatus RandGaussInit(void *pRandGaussState, Ipp8u mean, Ipp8u stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_8u((IppsRandGaussState_8u *)pRandGaussState, mean, stdDev, seed)); }
    static inline IppStatus RandGaussInit(void *pRandGaussState, Ipp16s mean, Ipp16s stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_16s((IppsRandGaussState_16s *)pRandGaussState, mean, stdDev, seed)); }
    static inline IppStatus RandGaussInit(void *pRandGaussState, Ipp32f mean, Ipp32f stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_32f((IppsRandGaussState_32f *)pRandGaussState, mean, stdDev, seed)); }
    static inline IppStatus RandGaussInit(void *pRandGaussState, Ipp64f mean, Ipp64f stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_64f((IppsRandGaussState_64f *)pRandGaussState, mean, stdDev, seed)); }

    template <typename T>
    static inline IppStatus RandGaussGetSize(int *pRandGaussStateSize);
    template <>
    static inline IppStatus RandGaussGetSize<Ipp8u>(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_8u(pRandGaussStateSize)); }
    template <>
    static inline IppStatus RandGaussGetSize<Ipp16s>(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_16s(pRandGaussStateSize)); }
    template <>
    static inline IppStatus RandGaussGetSize<Ipp32f>(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_32f(pRandGaussStateSize)); }
    template <>
    static inline IppStatus RandGaussGetSize<Ipp64f>(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_64f(pRandGaussStateSize)); }

    static inline IppStatus RandGauss(Ipp8u *pDst, int len, IppsRandGaussState_8u *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_8u(pDst, len, pRandGaussState)); }
    static inline IppStatus RandGauss(Ipp16s *pDst, int len, IppsRandGaussState_16s *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_16s(pDst, len, pRandGaussState)); }
    static inline IppStatus RandGauss(Ipp32f *pDst, int len, IppsRandGaussState_32f *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_32f(pDst, len, pRandGaussState)); }
    static inline IppStatus RandGauss(Ipp64f *pDst, int len, IppsRandGaussState_64f *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_64f(pDst, len, pRandGaussState)); }

    template <typename T>
    static inline IppStatus RandUniformGetSize(int *pRandUniformStateSize);
    template <>
    static inline IppStatus RandUniformGetSize<Ipp8u>(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_8u(pRandUniformStateSize)); }
    template <>
    static inline IppStatus RandUniformGetSize<Ipp16s>(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_16s(pRandUniformStateSize)); }
    template <>
    static inline IppStatus RandUniformGetSize<Ipp32f>(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_32f(pRandUniformStateSize)); }
    template <>
    static inline IppStatus RandUniformGetSize<Ipp64f>(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_64f(pRandUniformStateSize)); }

    static inline IppStatus RandUniformInit(void *pRandUniState, Ipp8u low, Ipp8u high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_8u((IppsRandUniState_8u *)pRandUniState, low, high, seed)); }
    static inline IppStatus RandUniformInit(void *pRandUniState, Ipp16s low, Ipp16s high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_16s((IppsRandUniState_16s *)pRandUniState, low, high, seed)); }
    static inline IppStatus RandUniformInit(void *pRandUniState, Ipp32f low, Ipp32f high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_32f((IppsRandUniState_32f *)pRandUniState, low, high, seed)); }
    static inline IppStatus RandUniformInit(void *pRandUniState, Ipp64f low, Ipp64f high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_64f((IppsRandUniState_64f *)pRandUniState, low, high, seed)); }

    static inline IppStatus RandUniform(Ipp8u *pDst, int len, void *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_8u(pDst, len, (IppsRandUniState_8u *)pRandUniState)); }
    static inline IppStatus RandUniform(Ipp16s *pDst, int len, void *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_16s(pDst, len, (IppsRandUniState_16s *)pRandUniState)); }
    static inline IppStatus RandUniform(Ipp32f *pDst, int len, void *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_32f(pDst, len, (IppsRandUniState_32f *)pRandUniState)); }
    static inline IppStatus RandUniform(Ipp64f *pDst, int len, void *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_64f(pDst, len, (IppsRandUniState_64f *)pRandUniState)); }
}
