#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <complex>
#include <ipp/ippcore.h>
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <ipp/ippvm.h>
#include <stdexcept>

namespace tipp {
  namespace s {
    /* Essential Filter */
    static inline IppStatus SumWindow(const Ipp8u *pSrc, Ipp32f *pDst, int len, int maskSize) { return OptionalAssertNoError(ippsSumWindow_8u32f(pSrc, pDst, len, maskSize)); }
    static inline IppStatus SumWindow(const Ipp16s *pSrc, Ipp32f *pDst, int len, int maskSize) { return OptionalAssertNoError(ippsSumWindow_16s32f(pSrc, pDst, len, maskSize)); }

    static inline IppStatus FIRSR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const std::complex<float> *pSrc, std::complex<float> *pDst, int numIters, Ipp8u *pSpec, const std::complex<float> *pDlySrc, std::complex<float> *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, numIters, (IppsFIRSpec_32fc *)pSpec, (Ipp32fc *)pDlySrc, (Ipp32fc *)pDlyDst, pBuf)); }
    static inline IppStatus FIRSR(const std::complex<double> *pSrc, std::complex<double> *pDst, int numIters, Ipp8u *pSpec, const std::complex<double> *pDlySrc, std::complex<double> *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRSR_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, numIters, (IppsFIRSpec_64fc *)pSpec, (Ipp64fc *)pDlySrc, (Ipp64fc *)pDlyDst, pBuf)); }

    // FIRSRGetSize doesnt need wrapper

    template <typename T>
    static inline IppStatus FIRSRInit(const T *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec);
    template <>
    static inline IppStatus FIRSRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_32f(pTaps, tapsLen, algType, (IppsFIRSpec_32f *)pSpec));
    }
    template <>
    static inline IppStatus FIRSRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_32fc(pTaps, tapsLen, algType, (IppsFIRSpec_32fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRSRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_64f(pTaps, tapsLen, algType, (IppsFIRSpec_64f *)pSpec));
    }
    template <>
    static inline IppStatus FIRSRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_64fc(pTaps, tapsLen, algType, (IppsFIRSpec_64fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRSRInit<std::complex<double>>(const std::complex<double> *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_64fc((Ipp64fc *)pTaps, tapsLen, algType, (IppsFIRSpec_64fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRSRInit<std::complex<float>>(const std::complex<float> *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRSRInit_32fc((Ipp32fc *)pTaps, tapsLen, algType, (IppsFIRSpec_32fc *)pSpec));
    }

    static inline IppStatus FIRMR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const std::complex<float> *pSrc, std::complex<float> *pDst, int numIters, Ipp8u *pSpec, const std::complex<float> *pDlySrc, std::complex<float> *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, numIters, (IppsFIRSpec_32fc *)pSpec, (Ipp32fc *)pDlySrc, (Ipp32fc *)pDlyDst, pBuf)); }
    static inline IppStatus FIRMR(const std::complex<double> *pSrc, std::complex<double> *pDst, int numIters, Ipp8u *pSpec, const std::complex<double> *pDlySrc, std::complex<double> *pDlyDst, Ipp8u *pBuf) { return OptionalAssertNoError(ippsFIRMR_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, numIters, (IppsFIRSpec_64fc *)pSpec, (Ipp64fc *)pDlySrc, (Ipp64fc *)pDlyDst, pBuf)); }

    template <typename T>
    static inline IppStatus FIRMRInit(const T *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec);
    template <>
    static inline IppStatus FIRMRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_32f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32f *)pSpec));
    }
    template <>
    static inline IppStatus FIRMRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_64f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64f *)pSpec));
    }
    template <>
    static inline IppStatus FIRMRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_32fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRMRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_64fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRMRInit<std::complex<float>>(const std::complex<float> *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_32fc((Ipp32fc *)pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32fc *)pSpec));
    }
    template <>
    static inline IppStatus FIRMRInit<std::complex<double>>(const std::complex<double> *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec) {
      return OptionalAssertNoError(ippsFIRMRInit_64fc((Ipp64fc *)pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64fc *)pSpec));
    }

    static inline IppStatus Convolve(const Ipp32f *pSrc1, int src1Len, const Ipp32f *pSrc2, int src2Len, Ipp32f *pDst, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsConvolve_32f(pSrc1, src1Len, pSrc2, src2Len, pDst, algType, pBuffer)); }
    static inline IppStatus Convolve(const Ipp64f *pSrc1, int src1Len, const Ipp64f *pSrc2, int src2Len, Ipp64f *pDst, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsConvolve_64f(pSrc1, src1Len, pSrc2, src2Len, pDst, algType, pBuffer)); }

    static inline IppStatus CrossCorrNorm(const Ipp32f *pSrc1, int src1Len, const Ipp32f *pSrc2, int src2Len, Ipp32f *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_32f(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
    static inline IppStatus CrossCorrNorm(const Ipp64f *pSrc1, int src1Len, const Ipp64f *pSrc2, int src2Len, Ipp64f *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_64f(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
    static inline IppStatus CrossCorrNorm(const Ipp32fc *pSrc1, int src1Len, const Ipp32fc *pSrc2, int src2Len, Ipp32fc *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_32fc(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
    static inline IppStatus CrossCorrNorm(const Ipp64fc *pSrc1, int src1Len, const Ipp64fc *pSrc2, int src2Len, Ipp64fc *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_64fc(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
    static inline IppStatus CrossCorrNorm(const std::complex<float> *pSrc1, int src1Len, const std::complex<float> *pSrc2, int src2Len, std::complex<float> *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_32fc((Ipp32fc *)pSrc1, src1Len, (Ipp32fc *)pSrc2, src2Len, (Ipp32fc *)pDst, dstLen, lowLag, algType, pBuffer)); }
    static inline IppStatus CrossCorrNorm(const std::complex<double> *pSrc1, int src1Len, const std::complex<double> *pSrc2, int src2Len, std::complex<double> *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_64fc((Ipp64fc *)pSrc1, src1Len, (Ipp64fc *)pSrc2, src2Len, (Ipp64fc *)pDst, dstLen, lowLag, algType, pBuffer)); }

    static inline IppStatus FilterMedian(const Ipp8u *pSrc, Ipp8u *pDst, int len, int maskSize, const Ipp8u *pDlySrc, Ipp8u *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_8u(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian(const Ipp16s *pSrc, Ipp16s *pDst, int len, int maskSize, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_16s(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian(const Ipp32s *pSrc, Ipp32s *pDst, int len, int maskSize, const Ipp32s *pDlySrc, Ipp32s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32s(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian(const Ipp32f *pSrc, Ipp32f *pDst, int len, int maskSize, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32f(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian(const Ipp64f *pSrc, Ipp64f *pDst, int len, int maskSize, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_64f(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }

    static inline IppStatus FilterMedian_I(Ipp8u *pSrcDst, int len, int maskSize, const Ipp8u *pDlySrc, Ipp8u *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_8u_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian_I(Ipp16s *pSrcDst, int len, int maskSize, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_16s_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian_I(Ipp32s *pSrcDst, int len, int maskSize, const Ipp32s *pDlySrc, Ipp32s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32s_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian_I(Ipp32f *pSrcDst, int len, int maskSize, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32f_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
    static inline IppStatus FilterMedian_I(Ipp64f *pSrcDst, int len, int maskSize, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_64f_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }

    static inline IppStatus AutoCorrNorm(const Ipp32f *pSrc, int srcLen, Ipp32f *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_32f(pSrc, srcLen, pDst, dstLen, algType, pBuffer)); }
    static inline IppStatus AutoCorrNorm(const Ipp64f *pSrc, int srcLen, Ipp64f *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_64f(pSrc, srcLen, pDst, dstLen, algType, pBuffer)); }
    static inline IppStatus AutoCorrNorm(const Ipp32fc *pSrc, int srcLen, Ipp32fc *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_32fc(pSrc, srcLen, pDst, dstLen, algType, pBuffer)); }
    static inline IppStatus AutoCorrNorm(const Ipp64fc *pSrc, int srcLen, Ipp64fc *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_64fc(pSrc, srcLen, pDst, dstLen, algType, pBuffer)); }
    static inline IppStatus AutoCorrNorm(const std::complex<float> *pSrc, int srcLen, std::complex<float> *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_32fc((Ipp32fc *)pSrc, srcLen, (Ipp32fc *)pDst, dstLen, algType, pBuffer)); }
    static inline IppStatus AutoCorrNorm(const std::complex<double> *pSrc, int srcLen, std::complex<double> *pDst, int dstLen, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsAutoCorrNorm_64fc((Ipp64fc *)pSrc, srcLen, (Ipp64fc *)pDst, dstLen, algType, pBuffer)); }

    static inline IppStatus ResamplePolyphase(const Ipp16s *pSrc, int len, Ipp16s *pDst, Ipp64f factor, Ipp32f norm, Ipp64f *pTime, int *pOutlen, const IppsResamplingPolyphase_16s *pSpec) { return OptionalAssertNoError(ippsResamplePolyphase_16s(pSrc, len, pDst, factor, norm, pTime, pOutlen, pSpec)); }
    static inline IppStatus ResamplePolyphase(const Ipp32f *pSrc, int len, Ipp32f *pDst, Ipp64f factor, Ipp32f norm, Ipp64f *pTime, int *pOutlen, const IppsResamplingPolyphase_32f *pSpec) { return OptionalAssertNoError(ippsResamplePolyphase_32f(pSrc, len, pDst, factor, norm, pTime, pOutlen, pSpec)); }

    template <typename T>
    static inline IppStatus ResamplePolyphaseInit(Ipp32f window, int nStep, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint);
    template <>
    static inline IppStatus ResamplePolyphaseInit<Ipp16s>(Ipp32f window, int nStep, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseInit_16s(window, nStep, rollf, alpha, (IppsResamplingPolyphase_16s *)pSpec, hint));
    }
    template <>
    static inline IppStatus ResamplePolyphaseInit<Ipp32f>(Ipp32f window, int nStep, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseInit_32f(window, nStep, rollf, alpha, (IppsResamplingPolyphase_32f *)pSpec, hint));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseGetSize(Ipp32f window, int nStep, int *pSize, IppHintAlgorithm hint);
    template <>
    static inline IppStatus ResamplePolyphaseGetSize<Ipp16s>(Ipp32f window, int nStep, int *pSize, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseGetSize_16s(window, nStep, pSize, hint));
    }
    template <>
    static inline IppStatus ResamplePolyphaseGetSize<Ipp32f>(Ipp32f window, int nStep, int *pSize, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseGetSize_32f(window, nStep, pSize, hint));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseFixedInit(int inRate, int outRate, int len, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint);
    template <>
    static inline IppStatus ResamplePolyphaseFixedInit<Ipp16s>(int inRate, int outRate, int len, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixedInit_16s(inRate, outRate, len, rollf, alpha, (IppsResamplingPolyphaseFixed_16s *)pSpec, hint));
    }
    template <>
    static inline IppStatus ResamplePolyphaseFixedInit<Ipp32f>(int inRate, int outRate, int len, Ipp32f rollf, Ipp32f alpha, void *pSpec, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixedInit_32f(inRate, outRate, len, rollf, alpha, (IppsResamplingPolyphaseFixed_32f *)pSpec, hint));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseFixed(const T *pSrc, int len, T *pDst, Ipp32f norm, Ipp64f *pTime, int *pOutlen, const void *pSpec);
    template <>
    static inline IppStatus ResamplePolyphaseFixed<Ipp16s>(const Ipp16s *pSrc, int len, Ipp16s *pDst, Ipp32f norm, Ipp64f *pTime, int *pOutlen, const void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixed_16s(pSrc, len, pDst, norm, pTime, pOutlen, (const IppsResamplingPolyphaseFixed_16s *)pSpec));
    }
    template <>
    static inline IppStatus ResamplePolyphaseFixed<Ipp32f>(const Ipp32f *pSrc, int len, Ipp32f *pDst, Ipp32f norm, Ipp64f *pTime, int *pOutlen, const void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixed_32f(pSrc, len, pDst, norm, pTime, pOutlen, (const IppsResamplingPolyphaseFixed_32f *)pSpec));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseGetFixedFilter(T *pDst, int step, int height, const void *pSpec);
    template <>
    static inline IppStatus ResamplePolyphaseGetFixedFilter<Ipp16s>(Ipp16s *pDst, int step, int height, const void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseGetFixedFilter_16s(pDst, step, height, (const IppsResamplingPolyphaseFixed_16s *)pSpec));
    }
    template <>
    static inline IppStatus ResamplePolyphaseGetFixedFilter<Ipp32f>(Ipp32f *pDst, int step, int height, const void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseGetFixedFilter_32f(pDst, step, height, (const IppsResamplingPolyphaseFixed_32f *)pSpec));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseFixedGetSize(int inRate, int outRate, int len, int *pSize, int *pLen, int *pHeight, IppHintAlgorithm hint);
    template <>
    static inline IppStatus ResamplePolyphaseFixedGetSize<Ipp16s>(int inRate, int outRate, int len, int *pSize, int *pLen, int *pHeight, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixedGetSize_16s(inRate, outRate, len, pSize, pLen, pHeight, hint));
    }
    template <>
    static inline IppStatus ResamplePolyphaseFixedGetSize<Ipp32f>(int inRate, int outRate, int len, int *pSize, int *pLen, int *pHeight, IppHintAlgorithm hint) {
      return OptionalAssertNoError(ippsResamplePolyphaseFixedGetSize_32f(inRate, outRate, len, pSize, pLen, pHeight, hint));
    }

    template <typename T>
    static inline IppStatus ResamplePolyphaseSetFixedFilter(const T *pSrc, int step, int height, void *pSpec);
    template <>
    static inline IppStatus ResamplePolyphaseSetFixedFilter<Ipp16s>(const Ipp16s *pSrc, int step, int height, void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseSetFixedFilter_16s(pSrc, step, height, (IppsResamplingPolyphaseFixed_16s *)pSpec));
    }
    template <>
    static inline IppStatus ResamplePolyphaseSetFixedFilter<Ipp32f>(const Ipp32f *pSrc, int step, int height, void *pSpec) {
      return OptionalAssertNoError(ippsResamplePolyphaseSetFixedFilter_32f(pSrc, step, height, (IppsResamplingPolyphaseFixed_32f *)pSpec));
    }

    static inline IppStatus FIRSparse(const Ipp32f *pSrc, Ipp32f *pDst, int len, IppsFIRSparseState_32f *pState) { return OptionalAssertNoError(ippsFIRSparse_32f(pSrc, pDst, len, pState)); }
    static inline IppStatus FIRSparse(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, IppsFIRSparseState_32fc *pState) { return OptionalAssertNoError(ippsFIRSparse_32fc(pSrc, pDst, len, pState)); }
    static inline IppStatus FIRSparseInit(IppsFIRSparseState_32f **ppState, const Ipp32f *pNZTaps, const Ipp32s *pNZTapPos, int nzTapsLen, const Ipp32f *pDlyLine, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFIRSparseInit_32f(ppState, pNZTaps, pNZTapPos, nzTapsLen, pDlyLine, pBuffer)); }
    static inline IppStatus FIRSparseInit(IppsFIRSparseState_32fc **ppState, const Ipp32fc *pNZTaps, const Ipp32s *pNZTapPos, int nzTapsLen, const Ipp32fc *pDlyLine, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFIRSparseInit_32fc(ppState, pNZTaps, pNZTapPos, nzTapsLen, pDlyLine, pBuffer)); }
    template <typename T>
    static inline IppStatus FIRSparseGetStateSize(int nzTapsLen, int order, int *pStateSize);
    template <>
    static inline IppStatus FIRSparseGetStateSize<Ipp32f>(int nzTapsLen, int order, int *pStateSize) {
      return OptionalAssertNoError(ippsFIRSparseGetStateSize_32f(nzTapsLen, order, pStateSize));
    }
    template <>
    static inline IppStatus FIRSparseGetStateSize<Ipp32fc>(int nzTapsLen, int order, int *pStateSize) {
      return OptionalAssertNoError(ippsFIRSparseGetStateSize_32fc(nzTapsLen, order, pStateSize));
    }

    static inline IppStatus FIRSparseGetDlyLine(const IppsFIRSparseState_32f *pState, Ipp32f *pDlyLine) { return OptionalAssertNoError(ippsFIRSparseGetDlyLine_32f(pState, pDlyLine)); }
    static inline IppStatus FIRSparseGetDlyLine(const IppsFIRSparseState_32fc *pState, Ipp32fc *pDlyLine) { return OptionalAssertNoError(ippsFIRSparseGetDlyLine_32fc(pState, pDlyLine)); }
    static inline IppStatus FIRSparseSetDlyLine(IppsFIRSparseState_32f *pState, const Ipp32f *pDlyLine) { return OptionalAssertNoError(ippsFIRSparseSetDlyLine_32f(pState, pDlyLine)); }
    static inline IppStatus FIRSparseSetDlyLine(IppsFIRSparseState_32fc *pState, const Ipp32fc *pDlyLine) { return OptionalAssertNoError(ippsFIRSparseSetDlyLine_32fc(pState, pDlyLine)); }

    // IIRInit wrappers (Direct Form)
    template <typename T1, typename T2>
    static inline IppStatus IIRInit(void **ppState, const T1 *pTaps, int order, const T1 *pDlyLine, Ipp8u *pBuf);
    template <>
    static inline IppStatus IIRInit<Ipp32f, Ipp16s>(void **ppState, const Ipp32f *pTaps, int order, const Ipp32f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit32f_16s((IppsIIRState32f_16s **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64f, Ipp16s>(void **ppState, const Ipp64f *pTaps, int order, const Ipp64f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64f_16s((IppsIIRState64f_16s **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64f, Ipp32s>(void **ppState, const Ipp64f *pTaps, int order, const Ipp64f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64f_32s((IppsIIRState64f_32s **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp32fc, Ipp16sc>(void **ppState, const Ipp32fc *pTaps, int order, const Ipp32fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit32fc_16sc((IppsIIRState32fc_16sc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64fc, Ipp16sc>(void **ppState, const Ipp64fc *pTaps, int order, const Ipp64fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64fc_16sc((IppsIIRState64fc_16sc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64fc, Ipp32sc>(void **ppState, const Ipp64fc *pTaps, int order, const Ipp64fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64fc_32sc((IppsIIRState64fc_32sc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp32f, Ipp32f>(void **ppState, const Ipp32f *pTaps, int order, const Ipp32f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_32f((IppsIIRState_32f **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64f, Ipp32f>(void **ppState, const Ipp64f *pTaps, int order, const Ipp64f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64f_32f((IppsIIRState64f_32f **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64f, Ipp64f>(void **ppState, const Ipp64f *pTaps, int order, const Ipp64f *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_64f((IppsIIRState_64f **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp32fc, Ipp32fc>(void **ppState, const Ipp32fc *pTaps, int order, const Ipp32fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_32fc((IppsIIRState_32fc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64fc, Ipp32fc>(void **ppState, const Ipp64fc *pTaps, int order, const Ipp64fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit64fc_32fc((IppsIIRState64fc_32fc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<Ipp64fc, Ipp64fc>(void **ppState, const Ipp64fc *pTaps, int order, const Ipp64fc *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_64fc((IppsIIRState_64fc **)ppState, pTaps, order, pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<std::complex<float>, std::complex<float>>(void **ppState, const std::complex<float> *pTaps, int order, const std::complex<float> *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_32fc((IppsIIRState_32fc **)ppState, (Ipp32fc *)pTaps, order, (Ipp32fc *)pDlyLine, pBuf));
    }
    template <>
    static inline IppStatus IIRInit<std::complex<double>, std::complex<double>>(void **ppState, const std::complex<double> *pTaps, int order, const std::complex<double> *pDlyLine, Ipp8u *pBuf) {
      return OptionalAssertNoError(ippsIIRInit_64fc((IppsIIRState_64fc **)ppState, (Ipp64fc *)pTaps, order, (Ipp64fc *)pDlyLine, pBuf));
    }

    // IIRInit_BiQuad wrappers
    static inline IppStatus IIRInit_BiQuad(IppsIIRState32f_16s **ppState, const Ipp32f *pTaps, int numBq, const Ipp32f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit32f_BiQuad_16s(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64f_16s **ppState, const Ipp64f *pTaps, int numBq, const Ipp64f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64f_BiQuad_16s(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64f_32s **ppState, const Ipp64f *pTaps, int numBq, const Ipp64f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64f_BiQuad_32s(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState32fc_16sc **ppState, const Ipp32fc *pTaps, int numBq, const Ipp32fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit32fc_BiQuad_16sc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64fc_16sc **ppState, const Ipp64fc *pTaps, int numBq, const Ipp64fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64fc_BiQuad_16sc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64fc_32sc **ppState, const Ipp64fc *pTaps, int numBq, const Ipp64fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64fc_BiQuad_32sc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_32f **ppState, const Ipp32f *pTaps, int numBq, const Ipp32f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_32f(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64f_32f **ppState, const Ipp64f *pTaps, int numBq, const Ipp64f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64f_BiQuad_32f(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_64f **ppState, const Ipp64f *pTaps, int numBq, const Ipp64f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_64f(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_32fc **ppState, const Ipp32fc *pTaps, int numBq, const Ipp32fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_32fc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState64fc_32fc **ppState, const Ipp64fc *pTaps, int numBq, const Ipp64fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64fc_BiQuad_32fc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_64fc **ppState, const Ipp64fc *pTaps, int numBq, const Ipp64fc *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_64fc(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_32fc **ppState, const std::complex<float> *pTaps, int numBq, const std::complex<float> *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_32fc(ppState, (Ipp32fc *)pTaps, numBq, (Ipp32fc *)pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad(IppsIIRState_64fc **ppState, const std::complex<double> *pTaps, int numBq, const std::complex<double> *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_64fc(ppState, (Ipp64fc *)pTaps, numBq, (Ipp64fc *)pDlyLine, pBuf)); }

    // IIRInit_BiQuad_DF1 wrappers
    static inline IppStatus IIRInit_BiQuad_DF1(IppsIIRState64f_32s **ppState, const Ipp64f *pTaps, int numBq, const Ipp32s *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit64f_BiQuad_DF1_32s(ppState, pTaps, numBq, pDlyLine, pBuf)); }
    static inline IppStatus IIRInit_BiQuad_DF1(IppsIIRState_32f **ppState, const Ipp32f *pTaps, int numBq, const Ipp32f *pDlyLine, Ipp8u *pBuf) { return OptionalAssertNoError(ippsIIRInit_BiQuad_DF1_32f(ppState, pTaps, numBq, pDlyLine, pBuf)); }

    // IIRGetStateSize wrappers (Direct Form)
    template <typename T1, typename T2>
    static inline IppStatus IIRGetStateSize(int order, int *pBufferSize);
    template <>
    static inline IppStatus IIRGetStateSize<Ipp32f, Ipp16s>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize32f_16s(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64f, Ipp16s>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_16s(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64f, Ipp32s>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_32s(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp32fc, Ipp16sc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize32fc_16sc(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64fc, Ipp16sc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_16sc(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64fc, Ipp32sc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_32sc(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp32f, Ipp32f>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_32f(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64f, Ipp32f>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_32f(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64f, Ipp64f>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_64f(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp32fc, Ipp32fc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_32fc(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64fc, Ipp32fc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_32fc(order, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize<Ipp64fc, Ipp64fc>(int order, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_64fc(order, pBufferSize));
    }

    // IIRGetStateSize_BiQuad wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIRGetStateSize_BiQuad(int numBq, int *pBufferSize);
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp32f, Ipp16s>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize32f_BiQuad_16s(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64f, Ipp16s>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_BiQuad_16s(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64f, Ipp32s>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_BiQuad_32s(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp32fc, Ipp16sc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize32fc_BiQuad_16sc(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64fc, Ipp16sc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_BiQuad_16sc(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64fc, Ipp32sc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_BiQuad_32sc(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp32f, Ipp32f>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_BiQuad_32f(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64f, Ipp32f>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_BiQuad_32f(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64f, Ipp64f>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_BiQuad_64f(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp32fc, Ipp32fc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_BiQuad_32fc(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64fc, Ipp32fc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64fc_BiQuad_32fc(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad<Ipp64fc, Ipp64fc>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_BiQuad_64fc(numBq, pBufferSize));
    }

    // IIRGetStateSize_BiQuad_DF1 wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIRGetStateSize_BiQuad_DF1(int numBq, int *pBufferSize);
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad_DF1<Ipp64f, Ipp32s>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize64f_BiQuad_DF1_32s(numBq, pBufferSize));
    }
    template <>
    static inline IppStatus IIRGetStateSize_BiQuad_DF1<Ipp32f, Ipp32f>(int numBq, int *pBufferSize) {
      return OptionalAssertNoError(ippsIIRGetStateSize_BiQuad_DF1_32f(numBq, pBufferSize));
    }

    // IIRGetDlyLine wrappers

    template <typename T1, typename T2>
    static inline IppStatus IIRGetDlyLine(const void *pState, T1 *pDlyLine);
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp32f, Ipp16s>(const void *pState, Ipp32f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine32f_16s((const IppsIIRState32f_16s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64f, Ipp16s>(const void *pState, Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64f_16s((const IppsIIRState64f_16s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64f, Ipp32s>(const void *pState, Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64f_32s((const IppsIIRState64f_32s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp32fc, Ipp16sc>(const void *pState, Ipp32fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine32fc_16sc((const IppsIIRState32fc_16sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64fc, Ipp16sc>(const void *pState, Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64fc_16sc((const IppsIIRState64fc_16sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64fc, Ipp32sc>(const void *pState, Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64fc_32sc((const IppsIIRState64fc_32sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp32f, Ipp32f>(const void *pState, Ipp32f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_32f((const IppsIIRState_32f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64f, Ipp32f>(const void *pState, Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64f_32f((const IppsIIRState64f_32f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64f, Ipp64f>(const void *pState, Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_64f((const IppsIIRState_64f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp32fc, Ipp32fc>(const void *pState, Ipp32fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_32fc((const IppsIIRState_32fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64fc, Ipp32fc>(const void *pState, Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine64fc_32fc((const IppsIIRState64fc_32fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<Ipp64fc, Ipp64fc>(const void *pState, Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_64fc((const IppsIIRState_64fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<std::complex<float>, std::complex<float>>(const void *pState, std::complex<float> *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_32fc((const IppsIIRState_32fc *)pState, (Ipp32fc *)pDlyLine));
    }
    template <>
    static inline IppStatus IIRGetDlyLine<std::complex<double>, std::complex<double>>(const void *pState, std::complex<double> *pDlyLine) {
      return OptionalAssertNoError(ippsIIRGetDlyLine_64fc((const IppsIIRState_64fc *)pState, (Ipp64fc *)pDlyLine));
    }

    // IIRGetDlyLine_DF1 wrappers
    static inline IppStatus IIRGetDlyLine_DF1(const IppsIIRState64f_32s *pState, Ipp32s *pDlyLine) { return OptionalAssertNoError(ippsIIRGetDlyLine64f_DF1_32s(pState, pDlyLine)); }

    // IIRSetDlyLine wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIRSetDlyLine(void *pState, const T1 *pDlyLine);
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp32f, Ipp16s>(void *pState, const Ipp32f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine32f_16s((IppsIIRState32f_16s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64f, Ipp16s>(void *pState, const Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64f_16s((IppsIIRState64f_16s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64f, Ipp32s>(void *pState, const Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64f_32s((IppsIIRState64f_32s *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp32fc, Ipp16sc>(void *pState, const Ipp32fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine32fc_16sc((IppsIIRState32fc_16sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64fc, Ipp16sc>(void *pState, const Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64fc_16sc((IppsIIRState64fc_16sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64fc, Ipp32sc>(void *pState, const Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64fc_32sc((IppsIIRState64fc_32sc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp32f, Ipp32f>(void *pState, const Ipp32f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_32f((IppsIIRState_32f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64f, Ipp32f>(void *pState, const Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64f_32f((IppsIIRState64f_32f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64f, Ipp64f>(void *pState, const Ipp64f *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_64f((IppsIIRState_64f *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp32fc, Ipp32fc>(void *pState, const Ipp32fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_32fc((IppsIIRState_32fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64fc, Ipp32fc>(void *pState, const Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine64fc_32fc((IppsIIRState64fc_32fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<Ipp64fc, Ipp64fc>(void *pState, const Ipp64fc *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_64fc((IppsIIRState_64fc *)pState, pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<std::complex<float>, std::complex<float>>(void *pState, const std::complex<float> *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_32fc((IppsIIRState_32fc *)pState, (Ipp32fc *)pDlyLine));
    }
    template <>
    static inline IppStatus IIRSetDlyLine<std::complex<double>, std::complex<double>>(void *pState, const std::complex<double> *pDlyLine) {
      return OptionalAssertNoError(ippsIIRSetDlyLine_64fc((IppsIIRState_64fc *)pState, (Ipp64fc *)pDlyLine));
    }

    // IIRSetDlyLine_DF1 wrappers
    static inline IppStatus IIRSetDlyLine_DF1(IppsIIRState64f_32s *pState, const Ipp32s *pDlyLine) { return OptionalAssertNoError(ippsIIRSetDlyLine64f_DF1_32s(pState, pDlyLine)); }

    // IIR (Out-of-place, Sfs) wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIR_Sfs(const T2 *pSrc, T2 *pDst, int len, void *pState, int scaleFactor);
    template <>
    static inline IppStatus IIR_Sfs<Ipp32f, Ipp16s>(const Ipp16s *pSrc, Ipp16s *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR32f_16s_Sfs(pSrc, pDst, len, (IppsIIRState32f_16s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_Sfs<Ipp64f, Ipp16s>(const Ipp16s *pSrc, Ipp16s *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64f_16s_Sfs(pSrc, pDst, len, (IppsIIRState64f_16s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_Sfs<Ipp64f, Ipp32s>(const Ipp32s *pSrc, Ipp32s *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64f_32s_Sfs(pSrc, pDst, len, (IppsIIRState64f_32s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_Sfs<Ipp32fc, Ipp16sc>(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR32fc_16sc_Sfs(pSrc, pDst, len, (IppsIIRState32fc_16sc *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_Sfs<Ipp64fc, Ipp16sc>(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64fc_16sc_Sfs(pSrc, pDst, len, (IppsIIRState64fc_16sc *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_Sfs<Ipp64fc, Ipp32sc>(const Ipp32sc *pSrc, Ipp32sc *pDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64fc_32sc_Sfs(pSrc, pDst, len, (IppsIIRState64fc_32sc *)pState, scaleFactor));
    }

    // IIR (Out-of-place, Floating-point) wrappers

    template <typename T1, typename T2>
    static inline IppStatus IIR(const T2 *pSrc, T2 *pDst, int len, void *pState);
    template <>
    static inline IppStatus IIR<Ipp32f, Ipp32f>(const Ipp32f *pSrc, Ipp32f *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32f(pSrc, pDst, len, (IppsIIRState_32f *)pState));
    }
    template <>
    static inline IppStatus IIR<Ipp64f, Ipp64f>(const Ipp64f *pSrc, Ipp64f *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64f(pSrc, pDst, len, (IppsIIRState_64f *)pState));
    }
    template <>
    static inline IppStatus IIR<Ipp64f, Ipp32f>(const Ipp32f *pSrc, Ipp32f *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR64f_32f(pSrc, pDst, len, (IppsIIRState64f_32f *)pState));
    }
    template <>
    static inline IppStatus IIR<Ipp32fc, Ipp32fc>(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32fc(pSrc, pDst, len, (IppsIIRState_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR<Ipp64fc, Ipp64fc>(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64fc(pSrc, pDst, len, (IppsIIRState_64fc *)pState));
    }
    template <>
    static inline IppStatus IIR<Ipp64fc, Ipp32fc>(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR64fc_32fc(pSrc, pDst, len, (IppsIIRState64fc_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR<std::complex<float>, std::complex<float>>(const std::complex<float> *pSrc, std::complex<float> *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len, (IppsIIRState_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR<std::complex<double>, std::complex<double>>(const std::complex<double> *pSrc, std::complex<double> *pDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len, (IppsIIRState_64fc *)pState));
    }

    // IIR (In-place, Sfs) wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIR_ISfs(T2 *pSrcDst, int len, void *pState, int scaleFactor);
    template <>
    static inline IppStatus IIR_ISfs<Ipp32f, Ipp16s>(Ipp16s *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR32f_16s_ISfs(pSrcDst, len, (IppsIIRState32f_16s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_ISfs<Ipp32fc, Ipp16sc>(Ipp16sc *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR32fc_16sc_ISfs(pSrcDst, len, (IppsIIRState32fc_16sc *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_ISfs<Ipp64f, Ipp16s>(Ipp16s *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64f_16s_ISfs(pSrcDst, len, (IppsIIRState64f_16s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_ISfs<Ipp64f, Ipp32s>(Ipp32s *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64f_32s_ISfs(pSrcDst, len, (IppsIIRState64f_32s *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_ISfs<Ipp64fc, Ipp16sc>(Ipp16sc *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64fc_16sc_ISfs(pSrcDst, len, (IppsIIRState64fc_16sc *)pState, scaleFactor));
    }
    template <>
    static inline IppStatus IIR_ISfs<Ipp64fc, Ipp32sc>(Ipp32sc *pSrcDst, int len, void *pState, int scaleFactor) {
      return OptionalAssertNoError(ippsIIR64fc_32sc_ISfs(pSrcDst, len, (IppsIIRState64fc_32sc *)pState, scaleFactor));
    }

    // IIR (In-place, Floating-point) wrappers
    template <typename T1, typename T2>
    static inline IppStatus IIR_I(T2 *pSrcDst, int len, void *pState);
    template <>
    static inline IppStatus IIR_I<Ipp32f, Ipp32f>(Ipp32f *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32f_I(pSrcDst, len, (IppsIIRState_32f *)pState));
    }
    template <>
    static inline IppStatus IIR_I<Ipp64f, Ipp64f>(Ipp64f *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64f_I(pSrcDst, len, (IppsIIRState_64f *)pState));
    }
    template <>
    static inline IppStatus IIR_I<Ipp64f, Ipp32f>(Ipp32f *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR64f_32f_I(pSrcDst, len, (IppsIIRState64f_32f *)pState));
    }
    template <>
    static inline IppStatus IIR_I<Ipp32fc, Ipp32fc>(Ipp32fc *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32fc_I(pSrcDst, len, (IppsIIRState_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR_I<Ipp64fc, Ipp64fc>(Ipp64fc *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64fc_I(pSrcDst, len, (IppsIIRState_64fc *)pState));
    }
    template <>
    static inline IppStatus IIR_I<Ipp64fc, Ipp32fc>(Ipp32fc *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR64fc_32fc_I(pSrcDst, len, (IppsIIRState64fc_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR_I<std::complex<float>, std::complex<float>>(std::complex<float> *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_32fc_I((Ipp32fc *)pSrcDst, len, (IppsIIRState_32fc *)pState));
    }
    template <>
    static inline IppStatus IIR_I<std::complex<double>, std::complex<double>>(std::complex<double> *pSrcDst, int len, void *pState) {
      return OptionalAssertNoError(ippsIIR_64fc_I((Ipp64fc *)pSrcDst, len, (IppsIIRState_64fc *)pState));
    }

    // IIR (Planar/Multi-channel, Out-of-place) wrappers
    static inline IppStatus IIR_P(const Ipp32f **ppSrc, Ipp32f **ppDst, int len, int nChannels, IppsIIRState_32f **ppState) { return OptionalAssertNoError(ippsIIR_32f_P(ppSrc, ppDst, len, nChannels, ppState)); }

    // IIR (Planar/Multi-channel, Out-of-place, Sfs) wrappers
    static inline IppStatus IIR_PSfs(const Ipp32s **ppSrc, Ipp32s **ppDst, int len, int nChannels, IppsIIRState64f_32s **ppState, int *pScaleFactor) { return OptionalAssertNoError(ippsIIR64f_32s_PSfs(ppSrc, ppDst, len, nChannels, ppState, pScaleFactor)); }

    // IIR (Planar/Multi-channel, In-place) wrappers
    static inline IppStatus IIR_IP(Ipp32f **ppSrcDst, int len, int nChannels, IppsIIRState_32f **ppState) { return OptionalAssertNoError(ippsIIR_32f_IP(ppSrcDst, len, nChannels, ppState)); }

    // IIR (Planar/Multi-channel, In-place, Sfs) wrappers
    static inline IppStatus IIR_IPSfs(Ipp32s **ppSrcDst, int len, int nChannels, IppsIIRState64f_32s **ppState, int *pScaleFactor) { return OptionalAssertNoError(ippsIIR64f_32s_IPSfs(ppSrcDst, len, nChannels, ppState, pScaleFactor)); }
  } // namespace s
} // namespace tipp
