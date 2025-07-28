#pragma once
#include <ipp/ippcore.h>
#include <ipp/ippvm.h>
#include <ipp/ipps.h>
#include <complex>
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <stdexcept>

namespace tipp
{

    template <typename Tr>
    static inline IppStatus HilbertGetSize(int length, IppHintAlgorithm hint, int *pSpecSize, int *pBufferSize);
    template <>
    static inline IppStatus HilbertGetSize<Ipp32f>(int length, IppHintAlgorithm hint, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippsHilbertGetSize_32f32fc(length, hint, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus HilbertGetSize<Ipp64f>(int length, IppHintAlgorithm hint, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippsHilbertGetSize_64f64fc(length, hint, pSpecSize, pBufferSize)); }
    template <typename Tr>
    static inline IppStatus HilbertInit(int length, IppHintAlgorithm hint, IppsHilbertSpec *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus HilbertInit<Ipp32f>(int length, IppHintAlgorithm hint, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbertInit_32f32fc(length, hint, pSpec, pBuffer)); }
    template <>
    static inline IppStatus HilbertInit<Ipp64f>(int length, IppHintAlgorithm hint, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbertInit_64f64fc(length, hint, pSpec, pBuffer)); }
    static inline IppStatus Hilbert(const Ipp32f *pSrc, Ipp32fc *pDst, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbert_32f32fc(pSrc, pDst, pSpec, pBuffer)); }
    static inline IppStatus Hilbert(const Ipp64f *pSrc, Ipp64fc *pDst, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbert_64f64fc(pSrc, pDst, pSpec, pBuffer)); }

    template <typename T>
    static inline IppStatus WTFwdGetSize(int lenLow, int offsLow, int lenHigh, int offsHigh, int *pStateSize) { return OptionalAssertNoError(ippsWTFwdGetSize(GetIppDataType<T>(), lenLow, offsLow, lenHigh, offsHigh, pStateSize)); }
    template <typename T>
    inline IppStatus WTInvGetSize(int lenLow, int offsLow, int lenHigh, int offsHigh, int *pStateSize) { return OptionalAssertNoError(ippsWTInvGetSize(GetIppDataType<T>(), lenLow, offsLow, lenHigh, offsHigh, pStateSize)); }

    template <typename T>
    static inline IppStatus WTFwdInit(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh);
    template <>
    static inline IppStatus WTFwdInit<Ipp32f>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTFwdInit_32f((IppsWTFwdState_32f *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTFwdInit<Ipp8u>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTFwdInit_8u32f((IppsWTFwdState_8u32f *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTFwdInit<Ipp16s>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTFwdInit_16s32f((IppsWTFwdState_16s32f *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTFwdInit<Ipp16u>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTFwdInit_16u32f((IppsWTFwdState_16u32f *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }

    template <typename T>
    static inline IppStatus WTInvInit(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh);
    template <>
    static inline IppStatus WTInvInit<Ipp32f>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTInvInit_32f((IppsWTInvState_32f *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTInvInit<Ipp8u>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTInvInit_32f8u((IppsWTInvState_32f8u *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTInvInit<Ipp16s>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTInvInit_32f16s((IppsWTInvState_32f16s *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }
    template <>
    static inline IppStatus WTInvInit<Ipp16u>(void *pState, const Ipp32f *pTapsLow, int lenLow, int offsLow, const Ipp32f *pTapsHigh, int lenHigh, int offsHigh) { return OptionalAssertNoError(ippsWTInvInit_32f16u((IppsWTInvState_32f16u *)pState, pTapsLow, lenLow, offsLow, pTapsHigh, lenHigh, offsHigh)); }

    static inline IppStatus WTFwd(const Ipp32f *pSrc, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen, void *pState) { return OptionalAssertNoError(ippsWTFwd_32f(pSrc, pDstLow, pDstHigh, dstLen, (IppsWTFwdState_32f *)pState)); }
    static inline IppStatus WTFwd(const Ipp8u *pSrc, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen, void *pState) { return OptionalAssertNoError(ippsWTFwd_8u32f(pSrc, pDstLow, pDstHigh, dstLen, (IppsWTFwdState_8u32f *)pState)); }
    static inline IppStatus WTFwd(const Ipp16s *pSrc, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen, void *pState) { return OptionalAssertNoError(ippsWTFwd_16s32f(pSrc, pDstLow, pDstHigh, dstLen, (IppsWTFwdState_16s32f *)pState)); }
    static inline IppStatus WTFwd(const Ipp16u *pSrc, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen, void *pState) { return OptionalAssertNoError(ippsWTFwd_16u32f(pSrc, pDstLow, pDstHigh, dstLen, (IppsWTFwdState_16u32f *)pState)); }

    template <typename T>
    static inline IppStatus WTFwdSetDlyLine(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh);
    template <>
    static inline IppStatus WTFwdSetDlyLine<Ipp32f>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdSetDlyLine_32f((IppsWTFwdState_32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdSetDlyLine<Ipp8u>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdSetDlyLine_8u32f((IppsWTFwdState_8u32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdSetDlyLine<Ipp16s>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdSetDlyLine_16s32f((IppsWTFwdState_16s32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdSetDlyLine<Ipp16u>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdSetDlyLine_16u32f((IppsWTFwdState_16u32f *)pState, pDlyLow, pDlyHigh)); }

    template <typename T>
    static inline IppStatus WTFwdGetDlyLine(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh);
    template <>
    static inline IppStatus WTFwdGetDlyLine<Ipp32f>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdGetDlyLine_32f((IppsWTFwdState_32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdGetDlyLine<Ipp8u>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdGetDlyLine_8u32f((IppsWTFwdState_8u32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdGetDlyLine<Ipp16s>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdGetDlyLine_16s32f((IppsWTFwdState_16s32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTFwdGetDlyLine<Ipp16u>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTFwdGetDlyLine_16u32f((IppsWTFwdState_16u32f *)pState, pDlyLow, pDlyHigh)); }

    template <typename T>
    static inline IppStatus WTInv(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, int srcLen, T *pDst, void *pState);
    template <>
    static inline IppStatus WTInv<Ipp32f>(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, int srcLen, Ipp32f *pDst, void *pState) { return OptionalAssertNoError(ippsWTInv_32f(pSrcLow, pSrcHigh, srcLen, pDst, (IppsWTInvState_32f *)pState)); }
    template <>
    static inline IppStatus WTInv<Ipp8u>(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, int srcLen, Ipp8u *pDst, void *pState) { return OptionalAssertNoError(ippsWTInv_32f8u(pSrcLow, pSrcHigh, srcLen, pDst, (IppsWTInvState_32f8u *)pState)); }
    template <>
    static inline IppStatus WTInv<Ipp16s>(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, int srcLen, Ipp16s *pDst, void *pState) { return OptionalAssertNoError(ippsWTInv_32f16s(pSrcLow, pSrcHigh, srcLen, pDst, (IppsWTInvState_32f16s *)pState)); }
    template <>
    static inline IppStatus WTInv<Ipp16u>(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, int srcLen, Ipp16u *pDst, void *pState) { return OptionalAssertNoError(ippsWTInv_32f16u(pSrcLow, pSrcHigh, srcLen, pDst, (IppsWTInvState_32f16u *)pState)); }

    template <typename T>
    static inline IppStatus WTInvSetDlyLine(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh);
    template <>
    static inline IppStatus WTInvSetDlyLine<Ipp32f>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvSetDlyLine_32f((IppsWTInvState_32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvSetDlyLine<Ipp8u>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvSetDlyLine_32f8u((IppsWTInvState_32f8u *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvSetDlyLine<Ipp16s>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvSetDlyLine_32f16s((IppsWTInvState_32f16s *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvSetDlyLine<Ipp16u>(void *pState, const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvSetDlyLine_32f16u((IppsWTInvState_32f16u *)pState, pDlyLow, pDlyHigh)); }

    template <typename T>
    static inline IppStatus WTInvGetDlyLine(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh);
    template <>
    static inline IppStatus WTInvGetDlyLine<Ipp32f>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvGetDlyLine_32f((IppsWTInvState_32f *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvGetDlyLine<Ipp8u>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvGetDlyLine_32f8u((IppsWTInvState_32f8u *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvGetDlyLine<Ipp16s>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvGetDlyLine_32f16s((IppsWTInvState_32f16s *)pState, pDlyLow, pDlyHigh)); }
    template <>
    static inline IppStatus WTInvGetDlyLine<Ipp16u>(void *pState, Ipp32f *pDlyLow, Ipp32f *pDlyHigh) { return OptionalAssertNoError(ippsWTInvGetDlyLine_32f16u((IppsWTInvState_32f16u *)pState, pDlyLow, pDlyHigh)); }

    static inline IppStatus WTHaarFwd(const Ipp32f *pSrc, int len, Ipp32f *pDstLow, Ipp32f *pDstHigh) { return OptionalAssertNoError(ippsWTHaarFwd_32f(pSrc, len, pDstLow, pDstHigh)); }
    static inline IppStatus WTHaarFwd(const Ipp64f *pSrc, int len, Ipp64f *pDstLow, Ipp64f *pDstHigh) { return OptionalAssertNoError(ippsWTHaarFwd_64f(pSrc, len, pDstLow, pDstHigh)); }
    static inline IppStatus WTHaarInv(const Ipp32f *pSrcLow, const Ipp32f *pSrcHigh, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWTHaarInv_32f(pSrcLow, pSrcHigh, pDst, len)); }
    static inline IppStatus WTHaarInv(const Ipp64f *pSrcLow, const Ipp64f *pSrcHigh, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWTHaarInv_64f(pSrcLow, pSrcHigh, pDst, len)); }

    template <typename T>
    static inline IppStatus DFTGetSize(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
    template <>
    static inline IppStatus DFTGetSize<Ipp32fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_C_32fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus DFTGetSize<Ipp64fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_C_64fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus DFTGetSize<float>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_R_32f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus DFTGetSize<double>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_R_64f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

    template <typename T>
    static inline IppStatus DFTInit(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit);
    template <>
    static inline IppStatus DFTInit<Ipp32fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_C_32fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_32fc *)pDFTSpec, pMemInit)); }
    template <>
    static inline IppStatus DFTInit<Ipp64fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_C_64fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_64fc *)pDFTSpec, pMemInit)); }
    template <>
    static inline IppStatus DFTInit<float>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_R_32f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_32f *)pDFTSpec, pMemInit)); }
    template <>
    static inline IppStatus DFTInit<double>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_R_64f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_64f *)pDFTSpec, pMemInit)); }

    static inline IppStatus DFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }

    static inline IppStatus DFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }
    static inline IppStatus DFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }

    template <typename T>
    static inline int DFT_Get_FwdSize(int nfft) { return nfft; }
    template <>
    static inline int DFT_Get_FwdSize<float>(int nfft) { return nfft / 2 + 1; }
    template <>
    static inline int DFT_Get_FwdSize<double>(int nfft) { return nfft / 2 + 1; }

    template <typename T>
    static inline IppStatus FFTGetSize(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
    template <>
    static inline IppStatus FFTGetSize<Ipp32fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_C_32fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus FFTGetSize<Ipp64fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_C_64fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus FFTGetSize<float>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_R_32f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    static inline IppStatus FFTGetSize<double>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_R_64f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

    template <typename T>
    static inline IppStatus FFTInit(void *ppFFTSpec, int order, int flag, Ipp8u *pSpec, Ipp8u *pSpecBuffer);
    template <>
    static inline IppStatus FFTInit<Ipp32fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_C_32fc((IppsFFTSpec_C_32fc **)ppFFTSpec, order, flag, ippAlgHintNone, pSpec, pSpecBuffer)); }
    template <>
    static inline IppStatus FFTInit<Ipp64fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_C_64fc((IppsFFTSpec_C_64fc **)ppFFTSpec, order, flag, ippAlgHintNone, pSpec, pSpecBuffer)); }
    template <>
    static inline IppStatus FFTInit<float>(void *ppFFTSpec, int order, int flag, Ipp8u *pSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_R_32f((IppsFFTSpec_R_32f **)ppFFTSpec, order, flag, ippAlgHintNone, pSpec, pSpecBuffer)); }
    template <>
    static inline IppStatus FFTInit<double>(void *ppFFTSpec, int order, int flag, Ipp8u *pSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_R_64f((IppsFFTSpec_R_64f **)ppFFTSpec, order, flag, ippAlgHintNone, pSpec, pSpecBuffer)); }

    static inline IppStatus FFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

    static inline IppStatus FFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

    static inline IppStatus FFTFwd_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd_I(float *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_32f_I(pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTFwd_I(double *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_64f_I(pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

    static inline IppStatus FFTInv_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv_I(Ipp64f *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_64f_I((double *)pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
    static inline IppStatus FFTInv_I(Ipp32f *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_32f_I((float *)pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

}
