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

    static inline IppStatus CplxToReal(const Ipp16sc *pSrc, Ipp16s *pDstRe, Ipp16s *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_16sc(pSrc, pDstRe, pDstIm, len)); }
    static inline IppStatus CplxToReal(const Ipp32fc *pSrc, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_32fc(pSrc, pDstRe, pDstIm, len)); }
    static inline IppStatus CplxToReal(const Ipp64fc *pSrc, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_64fc(pSrc, pDstRe, pDstIm, len)); }

    static inline IppStatus SortAscend_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_8u_I(pSrcDst, len)); }
    static inline IppStatus SortAscend_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_16u_I(pSrcDst, len)); }
    static inline IppStatus SortAscend_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_16s_I(pSrcDst, len)); }
    static inline IppStatus SortAscend_I(Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_32s_I(pSrcDst, len)); }
    static inline IppStatus SortAscend_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_32f_I(pSrcDst, len)); }
    static inline IppStatus SortAscend_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_64f_I(pSrcDst, len)); }

    static inline IppStatus SortDescend_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_8u_I(pSrcDst, len)); }
    static inline IppStatus SortDescend_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_16u_I(pSrcDst, len)); }
    static inline IppStatus SortDescend_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_16s_I(pSrcDst, len)); }
    static inline IppStatus SortDescend_I(Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_32s_I(pSrcDst, len)); }
    static inline IppStatus SortDescend_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_32f_I(pSrcDst, len)); }
    static inline IppStatus SortDescend_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_64f_I(pSrcDst, len)); }

    static inline IppStatus SortIndexAscend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_8u_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexAscend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_16u_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexAscend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_16s_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexAscend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_32s_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexAscend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_32f_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexAscend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_64f_I(pSrcDst, pDstIdx, len)); }

    static inline IppStatus SortIndexDescend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_8u_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexDescend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_16u_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexDescend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_16s_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexDescend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_32s_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexDescend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_32f_I(pSrcDst, pDstIdx, len)); }
    static inline IppStatus SortIndexDescend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_64f_I(pSrcDst, pDstIdx, len)); }

    template <typename T>
    static inline IppStatus SortRadixGetBufferSize(int len, int *pBuffferSize) { throw std::runtime_error("Unsupported data type for SortRadixGetBufferSize"); };
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp8u, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp16u, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32u, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64u, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp16s, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32s, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64s, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32f, pBuffferSize)); }
    template <>
    static inline IppStatus SortRadixGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64f, pBuffferSize)); }

    static inline IppStatus SortRadixAscend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64f_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32f_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_16u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_16s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_8u_I(pSrcDst, len, pBuffer)); }

    static inline IppStatus SortRadixDescend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64f_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32f_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_16u_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_16s_I(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_8u_I(pSrcDst, len, pBuffer)); }

    template <typename T>
    static inline IppStatus SortRadixGetBufferSize_L(int len, long long *pBuffferSize) { throw std::runtime_error("SortRadixGetBufferSize_L not implemented for this type"); };

    template <>
    static inline IppStatus SortRadixGetBufferSize_L<Ipp64u>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64u, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixGetBufferSize_L<Ipp32s>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32s, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixGetBufferSize_L<Ipp64s>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64s, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixGetBufferSize_L<Ipp32f>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32f, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixGetBufferSize_L<Ipp64f>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64f, pBuffferSize); }

    static inline IppStatus SortRadixAscend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64f_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64s_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64u_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32f_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixAscend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32s_I_L(pSrcDst, len, pBuffer)); }

    static inline IppStatus SortRadixDescend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64f_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64s_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64u_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32f_I_L(pSrcDst, len, pBuffer)); }
    static inline IppStatus SortRadixDescend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32s_I_L(pSrcDst, len, pBuffer)); }

    template <typename T>
    static inline IppStatus SortRadixIndexGetBufferSize(int len, int *pBuffferSize) { throw std::runtime_error("SortRadixIndexGetBufferSize not implemented for this type"); };
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp8u, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16u, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32u, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64u, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16s, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32s, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64s, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32f, pBuffferSize); }
    template <>
    static inline IppStatus SortRadixIndexGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64f, pBuffferSize); }

    // TODO
    IppStatus ippsSortRadixIndexAscend_8u(const Ipp8u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_16u(const Ipp16u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_16s(const Ipp16s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_32s(const Ipp32s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_32u(const Ipp32u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_32f(const Ipp32f *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_64f(const Ipp64f *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_64s(const Ipp64s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_64u(const Ipp64u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_8u(const Ipp8u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_16u(const Ipp16u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_16s(const Ipp16s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_32s(const Ipp32s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_32u(const Ipp32u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_32f(const Ipp32f *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_64f(const Ipp64f *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_64s(const Ipp64s *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_64u(const Ipp64u *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_64s_L(const Ipp64s *pSrc, IppSizeL srcStrideBytes, IppSizeL *pDstIndx, IppSizeL len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexAscend_64u_L(const Ipp64u *pSrc, IppSizeL srcStrideBytes, IppSizeL *pDstIndx, IppSizeL len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_64s_L(const Ipp64s *pSrc, IppSizeL srcStrideBytes, IppSizeL *pDstIndx, IppSizeL len, Ipp8u *pBuffer);

    IppStatus ippsSortRadixIndexDescend_64u_L(const Ipp64u *pSrc, IppSizeL srcStrideBytes, IppSizeL *pDstIndx, IppSizeL len, Ipp8u *pBuffer);

    // TopKGetBufferSize doesnt need wrappers
    // IppStatus ippsTopKGetBufferSize(Ipp64s srcLen, Ipp64s dstLen, IppDataType dataType, IppTopKMode hint, Ipp64s* bufSize);

    static inline IppStatus TopK(const Ipp32f *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, Ipp32f *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen, IppTopKMode hint, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsTopK_32f(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, dstLen, hint, pBuffer)); }
    static inline IppStatus TopK(const Ipp32s *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, Ipp32s *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen, IppTopKMode hint, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsTopK_32s(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, dstLen, hint, pBuffer)); }

    static inline IppStatus TopKInit(Ipp32s *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen) { return OptionalAssertNoError(ippsTopKInit_32s(pDstValue, pDstIndex, dstLen)); }
    static inline IppStatus TopKInit(Ipp32f *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen) { return OptionalAssertNoError(ippsTopKInit_32f(pDstValue, pDstIndex, dstLen)); }

    static inline IppStatus Conj(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsConj_16sc(pSrc, pDst, len)); }
    static inline IppStatus Conj(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsConj_32fc(pSrc, pDst, len)); }
    static inline IppStatus Conj(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsConj_64fc(pSrc, pDst, len)); }

    static inline IppStatus Conj_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_16sc_I(pSrcDst, len)); }
    static inline IppStatus Conj_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_32fc_I(pSrcDst, len)); }
    static inline IppStatus Conj_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_64fc_I(pSrcDst, len)); }

    static inline IppStatus ConjFlip(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_16sc(pSrc, pDst, len)); }
    static inline IppStatus ConjFlip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_32fc(pSrc, pDst, len)); }
    static inline IppStatus ConjFlip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_64fc(pSrc, pDst, len)); }

    static inline IppStatus Magnitude(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus Magnitude(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus Magnitude(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_32fc(pSrc, pDst, len)); }
    static inline IppStatus Magnitude(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_64fc(pSrc, pDst, len)); }
    static inline IppStatus Magnitude(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_16s32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus Magnitude(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_16sc32f(pSrc, pDst, len)); }

    static inline IppStatus Phase(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPhase_64fc(pSrc, pDst, len)); }
    static inline IppStatus Phase(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_32fc(pSrc, pDst, len)); }
    static inline IppStatus Phase(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_16sc32f(pSrc, pDst, len)); }
    static inline IppStatus Phase(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPhase_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus Phase(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus Phase(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_16s32f(pSrcRe, pSrcIm, pDst, len)); }

    static inline IppStatus PowerSpectr(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_64fc(pSrc, pDst, len)); }
    static inline IppStatus PowerSpectr(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_32fc(pSrc, pDst, len)); }
    static inline IppStatus PowerSpectr(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus PowerSpectr(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus PowerSpectr(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_16s32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus PowerSpectr(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_16sc32f(pSrc, pDst, len)); }

    static inline IppStatus RealToCplx(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_16s(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus RealToCplx(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline IppStatus RealToCplx(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_64f(pSrcRe, pSrcIm, pDst, len)); }

    static inline IppStatus Real(const Ipp16sc *pSrc, Ipp16s *pDstRe, int len) { return OptionalAssertNoError(ippsReal_16sc(pSrc, pDstRe, len)); }
    static inline IppStatus Real(const Ipp32fc *pSrc, Ipp32f *pDstRe, int len) { return OptionalAssertNoError(ippsReal_32fc(pSrc, pDstRe, len)); }
    static inline IppStatus Real(const Ipp64fc *pSrc, Ipp64f *pDstRe, int len) { return OptionalAssertNoError(ippsReal_64fc(pSrc, pDstRe, len)); }

    static inline IppStatus Imag(const Ipp16sc *pSrc, Ipp16s *pDstIm, int len) { return OptionalAssertNoError(ippsImag_16sc(pSrc, pDstIm, len)); }
    static inline IppStatus Imag(const Ipp32fc *pSrc, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsImag_32fc(pSrc, pDstIm, len)); }
    static inline IppStatus Imag(const Ipp64fc *pSrc, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsImag_64fc(pSrc, pDstIm, len)); }

    static inline IppStatus Threshold_LTAbsVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_64f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_16s(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s level, Ipp32s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32s(pSrc, pDst, len, level, value)); }

    static inline IppStatus Threshold_LTAbsVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_64f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_16s_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTAbsVal_I(Ipp32s *pSrcDst, int len, Ipp32s level, Ipp32s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32s_I(pSrcDst, len, level, value)); }

    static inline IppStatus Threshold_LTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTVal_16s(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTVal_32f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTVal_64f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_LTVal_16sc(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_32fc(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_64fc(pSrc, pDst, len, level, value)); }

    static inline IppStatus Threshold_GTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_GTVal_16s(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_GTVal_32f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_GTVal_64f(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_GTVal_16sc(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_32fc(pSrc, pDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_64fc(pSrc, pDst, len, level, value)); }

    static inline IppStatus Threshold_LTValGTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_16s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline IppStatus Threshold_LTValGTVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline IppStatus Threshold_LTValGTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32f(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }

    static inline IppStatus Threshold_LTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTVal_16s_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTVal_32f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTVal_64f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_LTVal_16sc_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_32fc_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_LTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_64fc_I(pSrcDst, len, level, value)); }

    static inline IppStatus Threshold_GTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_GTVal_16s_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_GTVal_32f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_GTVal_64f_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_GTVal_16sc_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_32fc_I(pSrcDst, len, level, value)); }
    static inline IppStatus Threshold_GTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_64fc_I(pSrcDst, len, level, value)); }

    static inline IppStatus Threshold_LTValGTVal_I(Ipp16s *pSrcDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_16s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline IppStatus Threshold_LTValGTVal_I(Ipp32s *pSrcDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline IppStatus Threshold_LTValGTVal_I(Ipp32f *pSrcDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline IppStatus Threshold_LTValGTVal_I(Ipp64f *pSrcDst, int len, Ipp64f levelLT, Ipp64f valueLT, Ipp64f levelGT, Ipp64f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_64f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }

    static inline IppStatus CartToPolar(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_32f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }
    static inline IppStatus CartToPolar(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_64f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }

    static inline IppStatus CartToPolar(const Ipp32fc *pSrc, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_32fc(pSrc, pDstMagn, pDstPhase, len)); }
    static inline IppStatus CartToPolar(const Ipp64fc *pSrc, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_64fc(pSrc, pDstMagn, pDstPhase, len)); }

    static inline IppStatus PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsPolarToCart_32f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
    static inline IppStatus PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsPolarToCart_64f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
    static inline IppStatus PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsPolarToCart_32fc(pSrcMagn, pSrcPhase, pDst, len)); }
    static inline IppStatus PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsPolarToCart_64fc(pSrcMagn, pSrcPhase, pDst, len)); }

    static inline IppStatus MaxOrder(const Ipp16s *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_16s(pSrc, len, pOrder)); }
    static inline IppStatus MaxOrder(const Ipp32s *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_32s(pSrc, len, pOrder)); }
    static inline IppStatus MaxOrder(const Ipp32f *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_32f(pSrc, len, pOrder)); }
    static inline IppStatus MaxOrder(const Ipp64f *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_64f(pSrc, len, pOrder)); }

    static inline IppStatus Flip(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsFlip_8u(pSrc, pDst, len)); }
    static inline IppStatus Flip(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsFlip_16u(pSrc, pDst, len)); }
    static inline IppStatus Flip(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsFlip_32f(pSrc, pDst, len)); }
    static inline IppStatus Flip(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsFlip_64f(pSrc, pDst, len)); }
    static inline IppStatus Flip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsFlip_32fc(pSrc, pDst, len)); }
    static inline IppStatus Flip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsFlip_64fc(pSrc, pDst, len)); }

    static inline IppStatus Flip_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_16u_I(pSrcDst, len)); }
    static inline IppStatus Flip_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_8u_I(pSrcDst, len)); }
    static inline IppStatus Flip_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_32f_I(pSrcDst, len)); }
    static inline IppStatus Flip_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_64f_I(pSrcDst, len)); }
    static inline IppStatus Flip_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_32fc_I(pSrcDst, len)); }
    static inline IppStatus Flip_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_64fc_I(pSrcDst, len)); }

    static inline IppStatus SwapBytes(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_16u(pSrc, pDst, len)); }
    static inline IppStatus SwapBytes(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_24u(pSrc, pDst, len)); }
    static inline IppStatus SwapBytes(const Ipp32u *pSrc, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_32u(pSrc, pDst, len)); }
    static inline IppStatus SwapBytes(const Ipp64u *pSrc, Ipp64u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_64u(pSrc, pDst, len)); }
    static inline IppStatus SwapBytes_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_16u_I(pSrcDst, len)); }
    static inline IppStatus SwapBytes_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_24u_I(pSrcDst, len)); }
    static inline IppStatus SwapBytes_I(Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_32u_I(pSrcDst, len)); }
    static inline IppStatus SwapBytes_I(Ipp64u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_64u_I(pSrcDst, len)); }

    // FindNearest doesnt need wrapper
    // IppStatus ippsFindNearest_16u(const Ipp16u* pVals, Ipp16u* pOutVals, int* pOutIndexes, int len, const Ipp16u *pTable, int tblLen);

    // FindNearestOne doesnt need wrapper
    //  IppStatus ippsFindNearestOne_16u(Ipp16u inpVal, Ipp16u* pOutVal, int* pOutIndex, const Ipp16u *pTable, int tblLen);
}
