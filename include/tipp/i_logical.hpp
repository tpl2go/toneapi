#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <ipp/ippi.h>

namespace tipp {
  namespace i {

    template <typename T, IppChannels C>
    static inline IppStatus And(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus And<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp32s, ippC1>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp32s, ippC3>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp32s, ippC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus And<Ipp32s, ippAC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus And_I(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus And_I<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_8u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_16u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus And_I<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAnd_32s_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AndC(const T *pSrc, int srcStep, T value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus AndC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u value, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u value, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s value, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AndC(const T *pSrc, int srcStep, const T *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus AndC<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[4], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus AndC<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AndC_I(T value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AndC_I<Ipp8u, ippC1>(Ipp8u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp16u, ippC1>(Ipp16u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp32s, ippC1>(Ipp32s value, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus AndC_I(const T *value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus AndC_I<Ipp8u, ippC3>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp16u, ippC3>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp32s, ippC3>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp8u, ippC4>(const Ipp8u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp16u, ippC4>(const Ipp16u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp32s, ippC4>(const Ipp32s value[4], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp8u, ippAC4>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_8u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp16u, ippAC4>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_16u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus AndC_I<Ipp32s, ippAC4>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAndC_32s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Or(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Or<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp32s, ippC1>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp32s, ippC3>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp32s, ippC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Or<Ipp32s, ippAC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Or_I(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Or_I<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_8u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_16u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Or_I<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOr_32s_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus OrC(const T *pSrc, int srcStep, T value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus OrC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u value, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u value, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s value, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus OrC(const T *pSrc, int srcStep, const T *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus OrC<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[4], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus OrC<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus OrC_I(T value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus OrC_I<Ipp8u, ippC1>(Ipp8u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp16u, ippC1>(Ipp16u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp32s, ippC1>(Ipp32s value, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus OrC_I(const T *value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus OrC_I<Ipp8u, ippC3>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp16u, ippC3>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp32s, ippC3>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp8u, ippC4>(const Ipp8u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp16u, ippC4>(const Ipp16u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp32s, ippC4>(const Ipp32s value[4], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp8u, ippAC4>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_8u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp16u, ippAC4>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_16u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus OrC_I<Ipp32s, ippAC4>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiOrC_32s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Xor(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Xor<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp32s, ippC1>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp32s, ippC3>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp32s, ippC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Xor<Ipp32s, ippAC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Xor_I(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Xor_I<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_8u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_16u_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Xor_I<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXor_32s_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus XorC(const T *pSrc, int srcStep, T value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus XorC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u value, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u value, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32s value, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus XorC(const T *pSrc, int srcStep, const T *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus XorC<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[4], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus XorC<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, const Ipp32s value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus XorC_I(T value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus XorC_I<Ipp8u, ippC1>(Ipp8u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp16u, ippC1>(Ipp16u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp32s, ippC1>(Ipp32s value, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus XorC_I(const T *value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus XorC_I<Ipp8u, ippC3>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp16u, ippC3>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp32s, ippC3>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp8u, ippC4>(const Ipp8u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp16u, ippC4>(const Ipp16u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp32s, ippC4>(const Ipp32s value[4], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp8u, ippAC4>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_8u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp16u, ippAC4>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_16u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus XorC_I<Ipp32s, ippAC4>(const Ipp32s value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiXorC_32s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Not(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Not<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Not<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Not<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Not<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Not_I(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Not_I<Ipp8u, ippC1>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Not_I<Ipp8u, ippC3>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Not_I<Ipp8u, ippC4>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Not_I<Ipp8u, ippAC4>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiNot_8u_AC4IR(pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus RShiftC(const T *pSrc, int srcStep, Ipp32u value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus RShiftC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp32u value, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp32u value, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp32u value, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32u value, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus RShiftC(const T *pSrc, int srcStep, const Ipp32u *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus RShiftC<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, const Ipp32u value[3], Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16s, ippC4>(const Ipp16s *pSrc, int srcStep, const Ipp32u value[4], Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[4], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp16s, ippAC4>(const Ipp16s *pSrc, int srcStep, const Ipp32u value[3], Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus RShiftC<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus RShiftC_I(Ipp32u value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus RShiftC_I<Ipp8u, ippC1>(Ipp32u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16u, ippC1>(Ipp32u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16s, ippC1>(Ipp32u value, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp32s, ippC1>(Ipp32u value, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus RShiftC_I(const Ipp32u *value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus RShiftC_I<Ipp8u, ippC3>(const Ipp32u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16u, ippC3>(const Ipp32u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16s, ippC3>(const Ipp32u value[3], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp32s, ippC3>(const Ipp32u value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp8u, ippC4>(const Ipp32u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16u, ippC4>(const Ipp32u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16s, ippC4>(const Ipp32u value[4], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp32s, ippC4>(const Ipp32u value[4], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp8u, ippAC4>(const Ipp32u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_8u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16u, ippAC4>(const Ipp32u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp16s, ippAC4>(const Ipp32u value[3], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_16s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus RShiftC_I<Ipp32s, ippAC4>(const Ipp32u value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiRShiftC_32s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus LShiftC(const T *pSrc, int srcStep, Ipp32u value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus LShiftC<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp32u value, Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp32u value, Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp32s, ippC1>(const Ipp32s *pSrc, int srcStep, Ipp32u value, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus LShiftC(const T *pSrc, int srcStep, const Ipp32u *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus LShiftC<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp32s, ippC3>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp32s, ippC4>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[4], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp32u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp32u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus LShiftC<Ipp32s, ippAC4>(const Ipp32s *pSrc, int srcStep, const Ipp32u value[3], Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus LShiftC_I(Ipp32u value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus LShiftC_I<Ipp8u, ippC1>(Ipp32u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp16u, ippC1>(Ipp32u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C1IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp32s, ippC1>(Ipp32u value, Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus LShiftC_I(const Ipp32u *value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus LShiftC_I<Ipp8u, ippC3>(const Ipp32u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp16u, ippC3>(const Ipp32u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp32s, ippC3>(const Ipp32u value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp8u, ippC4>(const Ipp32u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp16u, ippC4>(const Ipp32u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp32s, ippC4>(const Ipp32u value[4], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_C4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp8u, ippAC4>(const Ipp32u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_8u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp16u, ippAC4>(const Ipp32u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_16u_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus LShiftC_I<Ipp32s, ippAC4>(const Ipp32u value[3], Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLShiftC_32s_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }

  } // namespace i
} // namespace tipp
