#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <ipp/ippcv.h>

namespace tipp {
  namespace cv {
    template <typename T, IppChannels C>
    static inline IppStatus AddSquare(const T *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AddSquare<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_8u32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddSquare<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_16u32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddSquare<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AddSquare(const T *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AddSquare<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_8u32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddSquare<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_16u32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddSquare<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddSquare_32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }

    // Case 1: In-place operation
    template <typename T>
    static inline IppStatus AddProduct(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AddProduct<Ipp8upC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_8u32f_C1IR(pSrc1, src1Step, pSrc2, src2Step, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddProduct<Ipp16u>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_16u32f_C1IR(pSrc1, src1Step, pSrc2, src2Step, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddProduct<Ipp32f>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_32f_C1IR(pSrc1, src1Step, pSrc2, src2Step, pSrcDst, srcDstStep, roiSize)); }

    // Case 2: Masked in-place operation
    template <typename T>
    static inline IppStatus AddProduct_MR(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AddProduct_MR<Ipp8u>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_8u32f_C1IMR(pSrc1, src1Step, pSrc2, src2Step, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddProduct_MR<Ipp16u>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_16u32f_C1IMR(pSrc1, src1Step, pSrc2, src2Step, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AddProduct_MR<Ipp32f>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAddProduct_32f_C1IMR(pSrc1, src1Step, pSrc2, src2Step, pMask, maskStep, pSrcDst, srcDstStep, roiSize)); }

    // Case 1: In-place operation
    template <typename T, IppChannels C>
    static inline IppStatus AddWeighted_I(const T *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha);
    template <> static inline IppStatus AddWeighted_I<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_8u32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, alpha)); }
    template <> static inline IppStatus AddWeighted_I<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_16u32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, alpha)); }
    template <> static inline IppStatus AddWeighted_I<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, alpha)); }

    template <typename T, IppChannels C>
    static inline IppStatus AddWeighted_M(const T *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha);
    template <> static inline IppStatus AddWeighted_M<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_8u32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize, alpha)); }
    template <> static inline IppStatus AddWeighted_M<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_16u32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize, alpha)); }
    template <> static inline IppStatus AddWeighted_M<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, const Ipp8u *pMask, int maskStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_32f_C1IMR(pSrc, srcStep, pMask, maskStep, pSrcDst, srcDstStep, roiSize, alpha)); }

    template <typename T, IppChannels C>
    static inline IppStatus AddWeighted(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize, Ipp32f alpha);
    template <> static inline IppStatus AddWeighted<Ipp32f, ippC1>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize, Ipp32f alpha) { return OptionalAssertNoError(ippiAddWeighted_32f_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, alpha)); }

    template <typename T, IppChannels C>
    static inline IppStatus AbsDiff(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus AbsDiff<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbsDiff_8u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AbsDiff<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbsDiff_16u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AbsDiff<Ipp32f, ippC1>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbsDiff_32f_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AbsDiff<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbsDiff_8u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AbsDiffC(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, T value);
    template <> static inline IppStatus AbsDiffC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, Ipp8u value) { return OptionalAssertNoError(ippiAbsDiffC_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, value)); }
    template <> static inline IppStatus AbsDiffC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, Ipp16u value) { return OptionalAssertNoError(ippiAbsDiffC_16u_C1R(pSrc, srcStep, pDst, dstStep, roiSize, value)); }
    template <> static inline IppStatus AbsDiffC<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize, Ipp32f value) { return OptionalAssertNoError(ippiAbsDiffC_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize, value)); }

  } // namespace cv
} // namespace tipp
