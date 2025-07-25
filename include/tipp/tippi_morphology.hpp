#pragma once
#include <ipp/ippi.h>
#include <ipp/ippcv.h>
#include <ipp/ippcv_l.h>
#include "tipp_error.hpp"
#include "tipp_type.hpp"

namespace tipp
{
    template <typename T, int C>
    static inline IppStatus MorphAdvGetSize(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize);
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp8u, 3>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_8u_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp8u, 4>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_8u_C3R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp8u, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_8u_C4R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp16u, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_16u_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp16s, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_16s_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp32f, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_32f_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp32f, 3>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_32f_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphAdvGetSize<Ipp32f, 4>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphAdvGetSize_32f_C3R(roiSize, maskSize, pSpecSize, pBufferSize)); }

    template <typename T, int C>
    static inline IppStatus MorphAdvInit(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphAdvInit<Ipp8u, 3>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_8u_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp8u, 4>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_8u_C3R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp8u, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_8u_C4R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp16u, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_16u_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp16s, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_16s_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp32f, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_32f_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp32f, 3>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_32f_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphAdvInit<Ipp32f, 4>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphAdvState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphAdvInit_32f_C3R(roiSize, pMask, maskSize, pSpec, pBuffer)); }

    template <typename T, int C>
    static inline IppStatus MorphOpenBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphOpenBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphOpenBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphOpenBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpenBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpenBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphCloseBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphCloseBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphCloseBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphCloseBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphCloseBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphCloseBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphTophatBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphTophatBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphTophatBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphTophatBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophatBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophatBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <typename T, int C>
    static inline IppStatus MorphBlackhatBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus MorphBlackhatBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhatBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphAdvState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhatBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    /* --------------- */

    // ippiMorphClose_L
    template <typename T, int C>
    static inline IppStatus MorphClose_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphClose_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[3], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[4], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[3], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphClose_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[4], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphClose_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    // ippiMorphOpen_L
    template <typename T, int C>
    static inline IppStatus MorphOpen_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphOpen_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphOpen_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphOpen_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    // ippiMorphTophat_L
    template <typename T, int C>
    static inline IppStatus MorphTophat_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphTophat_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphTophat_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphTophat_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    // ippiMorphBlackhat_L
    template <typename T, int C>
    static inline IppStatus MorphBlackhat_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus MorphBlackhat_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphAdvStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiMorphBlackhat_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    /** --------------- */

    template <typename T, int C>
    static inline IppStatus Dilate_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus Dilate_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[3], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[4], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[3], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[4], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Dilate_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilate_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    /**--------------------- */

    template <typename T, int C>
    static inline IppStatus Erode_L(const T *pSrc, IppSizeL srcStep, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const T borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus Erode_L<Ipp8u, 1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_8u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp8u, 3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[3], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_8u_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp8u, 4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp8u borderValue[4], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_8u_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp32f, 1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_32f_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp32f, 3>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[3], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_32f_C3R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp32f, 4>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp32f borderValue[4], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_32f_C4R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp16u, 1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16u borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_16u_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }
    template <>
    static inline IppStatus Erode_L<Ipp16s, 1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, IppiBorderType borderType, const Ipp16s borderValue[1], const IppiMorphStateL *pMorphSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErode_16s_C1R_L(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pMorphSpec, pBuffer));
    }

    /*----------------------*/
    template <typename T, int C>
    static inline IppStatus MorphologyBorderGetSize(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize);
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp8u, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_8u_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp8u, 3>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_8u_C3R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp8u, 4>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_8u_C4R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp16u, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_16u_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp16s, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_16s_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp32f, 1>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_32f_C1R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp32f, 3>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_32f_C3R(roiSize, maskSize, pSpecSize, pBufferSize)); }
    template <>
    static inline IppStatus MorphologyBorderGetSize<Ipp32f, 4>(IppiSize roiSize, IppiSize maskSize, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippiMorphologyBorderGetSize_32f_C4R(roiSize, maskSize, pSpecSize, pBufferSize)); }

    template <typename T, int C>
    static inline IppStatus MorphologyBorderInit(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp8u, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_8u_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp8u, 3>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_8u_C3R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp8u, 4>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_8u_C4R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp16u, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_16u_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp16s, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_16s_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp32f, 1>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_32f_C1R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp32f, 3>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_32f_C3R(roiSize, pMask, maskSize, pSpec, pBuffer)); }
    template <>
    static inline IppStatus MorphologyBorderInit<Ipp32f, 4>(IppiSize roiSize, const Ipp8u *pMask, IppiSize maskSize, IppiMorphState *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippiMorphologyBorderInit_32f_C4R(roiSize, pMask, maskSize, pSpec, pBuffer)); }

    template <typename T, int C>
    static inline IppStatus DilateBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus DilateBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus DilateBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus DilateBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus DilateBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiDilateBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus ErodeBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus ErodeBorder<Ipp8u, 1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp16u, 1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16u borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp16s, 1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp16s borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp32f, 1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    template <typename T, int C>
    static inline IppStatus ErodeBorder(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, T *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer);
    template <>
    static inline IppStatus ErodeBorder<Ipp8u, 3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp8u, 4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp8u *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp32f, 4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }
    template <>
    static inline IppStatus ErodeBorder<Ipp32f, 3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, IppiBorderType borderType, Ipp32f *borderValue, const IppiMorphState *pSpec, Ipp8u *pBuffer)
    {
        return OptionalAssertNoError(ippiErodeBorder_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize, borderType, borderValue, pSpec, pBuffer));
    }

    /*---------------------*/
    static inline IppStatus MorphReconstructErode(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructErode_8u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructErode(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructErode_16u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructErode(const Ipp64f *pSrc, int srcStep, Ipp64f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructErode_64f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructErode(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructErode_32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, (Ipp32f *)pBuf, norm)); }

    static inline IppStatus MorphReconstructDilate(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructDilate_8u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructDilate(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructDilate_16u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructDilate(const Ipp64f *pSrc, int srcStep, Ipp64f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructDilate_64f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, pBuf, norm)); }
    static inline IppStatus MorphReconstructDilate(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp8u *pBuf, IppiNorm norm) { return OptionalAssertNoError(ippiMorphReconstructDilate_32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, (Ipp32f *)pBuf, norm)); }

}
