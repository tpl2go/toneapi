#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <ipp/ippi.h>

namespace tipp {
  namespace i {

    template <typename T, IppChannels C>
    static inline IppStatus Sub_Sfs(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Sub_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16s, ippAC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs<Ipp16s, ippC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }

    // Case 2: Floating-point operations without scale factor
    template <typename T, IppChannels C>
    static inline IppStatus Sub(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Sub<Ipp32f, ippC1>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub<Ipp32f, ippC3>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub<Ipp32f, ippAC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub<Ipp32f, ippC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    // Case 3: In-place operation on integer or complex data
    template <typename T, IppChannels C>
    static inline IppStatus Sub_I_Sfs(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Sub_I_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C1IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C1IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C1IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C3IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C3IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C3IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_AC4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_AC4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16s, ippAC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_AC4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs<Ipp16s, ippC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C4IRSfs(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    // Case 4: In-place operation on floating-point or complex data
    template <typename T, IppChannels C>
    static inline IppStatus Sub_I(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Sub_I<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C1IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sub_I<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C3IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sub_I<Ipp32f, ippAC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_AC4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sub_I<Ipp32f, ippC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSub_32f_C4IR(pSrc, srcStep, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sub_L(const T *pSrc1, IppSizeL src1Step, const T *pSrc2, IppSizeL src2Step, T *pDst, IppSizeL dstStep, IppiSizeL roiSize);
    template <> static inline IppStatus Sub_L<Ipp32f, ippC1>(const Ipp32f *pSrc1, IppSizeL src1Step, const Ipp32f *pSrc2, IppSizeL src2Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C1R_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_L<Ipp32f, ippC3>(const Ipp32f *pSrc1, IppSizeL src1Step, const Ipp32f *pSrc2, IppSizeL src2Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C3R_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_L<Ipp32f, ippC4>(const Ipp32f *pSrc1, IppSizeL src1Step, const Ipp32f *pSrc2, IppSizeL src2Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C4R_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_L<Ipp32f, ippAC4>(const Ipp32f *pSrc1, IppSizeL src1Step, const Ipp32f *pSrc2, IppSizeL src2Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_AC4R_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sub_Sfs_L(const T *pSrc1, IppSizeL src1Step, const T *pSrc2, IppSizeL src2Step, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus Sub_Sfs_L<Ipp8u, ippC1>(const Ipp8u *pSrc1, IppSizeL src1Step, const Ipp8u *pSrc2, IppSizeL src2Step, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C1RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16u, ippC1>(const Ipp16u *pSrc1, IppSizeL src1Step, const Ipp16u *pSrc2, IppSizeL src2Step, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C1RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16s, ippC1>(const Ipp16s *pSrc1, IppSizeL src1Step, const Ipp16s *pSrc2, IppSizeL src2Step, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C1RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp8u, ippC3>(const Ipp8u *pSrc1, IppSizeL src1Step, const Ipp8u *pSrc2, IppSizeL src2Step, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C3RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16u, ippC3>(const Ipp16u *pSrc1, IppSizeL src1Step, const Ipp16u *pSrc2, IppSizeL src2Step, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C3RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16s, ippC3>(const Ipp16s *pSrc1, IppSizeL src1Step, const Ipp16s *pSrc2, IppSizeL src2Step, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C3RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp8u, ippAC4>(const Ipp8u *pSrc1, IppSizeL src1Step, const Ipp8u *pSrc2, IppSizeL src2Step, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_AC4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16u, ippAC4>(const Ipp16u *pSrc1, IppSizeL src1Step, const Ipp16u *pSrc2, IppSizeL src2Step, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_AC4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16s, ippAC4>(const Ipp16s *pSrc1, IppSizeL src1Step, const Ipp16s *pSrc2, IppSizeL src2Step, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_AC4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp8u, ippC4>(const Ipp8u *pSrc1, IppSizeL src1Step, const Ipp8u *pSrc2, IppSizeL src2Step, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16u, ippC4>(const Ipp16u *pSrc1, IppSizeL src1Step, const Ipp16u *pSrc2, IppSizeL src2Step, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_Sfs_L<Ipp16s, ippC4>(const Ipp16s *pSrc1, IppSizeL src1Step, const Ipp16s *pSrc2, IppSizeL src2Step, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C4RSfs_L(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sub_I_Sfs_L(const T *pSrc, IppSizeL srcStep, T *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp8u, ippC1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C1IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16u, ippC1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C1IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16s, ippC1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C1IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp8u, ippC3>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C3IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16u, ippC3>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C3IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16s, ippC3>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C3IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp8u, ippAC4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_AC4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16u, ippAC4>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_AC4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16s, ippAC4>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_AC4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp8u, ippC4>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_8u_C4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16u, ippC4>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16u_C4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sub_I_Sfs_L<Ipp16s, ippC4>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSub_16s_C4IRSfs_L(pSrc, srcStep, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sub_I_L(const T *pSrc1, IppSizeL src1Step, T *pDst, IppSizeL dstStep, IppiSizeL roiSize);
    template <> static inline IppStatus Sub_I_L<Ipp32f, ippC1>(const Ipp32f *pSrc1, IppSizeL src1Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C1IR_L(pSrc1, src1Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_I_L<Ipp32f, ippC3>(const Ipp32f *pSrc1, IppSizeL src1Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C3IR_L(pSrc1, src1Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_I_L<Ipp32f, ippAC4>(const Ipp32f *pSrc1, IppSizeL src1Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_AC4IR_L(pSrc1, src1Step, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sub_I_L<Ipp32f, ippC4>(const Ipp32f *pSrc1, IppSizeL src1Step, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSub_32f_C4IR_L(pSrc1, src1Step, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs(const T *pSrc, int srcStep, T value, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u value, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C1RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u value, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C1RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s value, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C1RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs(const T *pSrc, int srcStep, const T *value, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C3RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C3RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, const Ipp16s value[3], Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C3RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[4], Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[4], Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC4>(const Ipp16s *pSrc, int srcStep, const Ipp16s value[4], Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, const Ipp8u value[3], Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_AC4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, const Ipp16u value[3], Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_AC4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippAC4>(const Ipp16s *pSrc, int srcStep, const Ipp16s value[3], Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_AC4RSfs(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC(const T *pSrc, int srcStep, T value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus SubC<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f value, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C1R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC(const T *pSrc, int srcStep, const T *value, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus SubC<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, const Ipp32f value[3], Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C3R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus SubC<Ipp32f, ippC4>(const Ipp32f *pSrc, int srcStep, const Ipp32f value[4], Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus SubC<Ipp32f, ippAC4>(const Ipp32f *pSrc, int srcStep, const Ipp32f value[3], Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_AC4R(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs(T value, T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);

    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC1>(Ipp8u value, Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C1IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC1>(Ipp16u value, Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C1IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC1>(Ipp16s value, Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C1IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs(const T value[], T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);

    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC3>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C3IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC3>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C3IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC3>(const Ipp16s value[3], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C3IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippC4>(const Ipp8u value[4], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippC4>(const Ipp16u value[4], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippC4>(const Ipp16s value[4], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <> static inline IppStatus SubC_Sfs<Ipp8u, ippAC4>(const Ipp8u value[3], Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_AC4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16u, ippAC4>(const Ipp16u value[3], Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_AC4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs<Ipp16s, ippAC4>(const Ipp16s value[3], Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_AC4IRSfs(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_I(T value, T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus SubC_I<Ipp32f, ippC1>(Ipp32f value, Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C1IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_I(const T value[], T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus SubC_I<Ipp32f, ippC3>(const Ipp32f value[3], Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C3IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus SubC_I<Ipp32f, ippAC4>(const Ipp32f value[3], Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_AC4IR(value, pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus SubC_I<Ipp32f, ippC4>(const Ipp32f value[4], Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSubC_32f_C4IR(value, pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs_L(const T *pSrc, IppSizeL srcStep, T value, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_Sfs_L<Ipp8u, ippC1>(const Ipp8u *pSrc, IppSizeL srcStep, Ipp8u value, Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C1RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16u, ippC1>(const Ipp16u *pSrc, IppSizeL srcStep, Ipp16u value, Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C1RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16s, ippC1>(const Ipp16s *pSrc, IppSizeL srcStep, Ipp16s value, Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C1RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }

    // Case 10: Not-in-place operation on multi-channel integer data with platform-aware functions
    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs_L(const T *pSrc, IppSizeL srcStep, const T *value, T *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_Sfs_L<Ipp8u, ippC3>(const Ipp8u *pSrc, IppSizeL srcStep, const Ipp8u value[3], Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C3RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16u, ippC3>(const Ipp16u *pSrc, IppSizeL srcStep, const Ipp16u value[3], Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C3RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16s, ippC3>(const Ipp16s *pSrc, IppSizeL srcStep, const Ipp16s value[3], Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C3RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp8u, ippAC4>(const Ipp8u *pSrc, IppSizeL srcStep, const Ipp8u value[3], Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_AC4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16u, ippAC4>(const Ipp16u *pSrc, IppSizeL srcStep, const Ipp16u value[3], Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_AC4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16s, ippAC4>(const Ipp16s *pSrc, IppSizeL srcStep, const Ipp16s value[3], Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_AC4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp8u, ippC4>(const Ipp8u *pSrc, IppSizeL srcStep, const Ipp8u value[4], Ipp8u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16u, ippC4>(const Ipp16u *pSrc, IppSizeL srcStep, const Ipp16u value[4], Ipp16u *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_L<Ipp16s, ippC4>(const Ipp16s *pSrc, IppSizeL srcStep, const Ipp16s value[4], Ipp16s *pDst, IppSizeL dstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C4RSfs_L(pSrc, srcStep, value, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_I_Sfs_L(T value, T *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_I_Sfs_L<Ipp8u, ippC1>(Ipp8u value, Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C1IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_I_Sfs_L<Ipp16u, ippC1>(Ipp16u value, Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C1IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_I_Sfs_L<Ipp16s, ippC1>(Ipp16s value, Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C1IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_L(const T *pSrc, IppSizeL srcStep, T value, T *pDst, IppSizeL dstStep, IppiSizeL roiSize);
    template <> static inline IppStatus SubC_L<Ipp32f, ippC1>(const Ipp32f *pSrc, IppSizeL srcStep, Ipp32f value, Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSubC_32f_C1R_L(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_L(const T *pSrc, IppSizeL srcStep, const T value[], T *pDst, IppSizeL dstStep, IppiSizeL roiSize);
    template <> static inline IppStatus SubC_L<Ipp32f, ippC3>(const Ipp32f *pSrc, IppSizeL srcStep, const Ipp32f value[3], Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSubC_32f_C3R_L(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus SubC_L<Ipp32f, ippAC4>(const Ipp32f *pSrc, IppSizeL srcStep, const Ipp32f value[3], Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSubC_32f_AC4R_L(pSrc, srcStep, value, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus SubC_L<Ipp32f, ippC4>(const Ipp32f *pSrc, IppSizeL srcStep, const Ipp32f value[4], Ipp32f *pDst, IppSizeL dstStep, IppiSizeL roiSize) { return OptionalAssertNoError(ippiSubC_32f_C4R_L(pSrc, srcStep, value, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus SubC_Sfs_I_L(const T value[], T *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor);
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp8u, ippC3>(const Ipp8u value[3], Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C3IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16u, ippC3>(const Ipp16u value[3], Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C3IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16s, ippC3>(const Ipp16s value[3], Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C3IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp8u, ippAC4>(const Ipp8u value[3], Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_AC4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16u, ippAC4>(const Ipp16u value[3], Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_AC4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16s, ippAC4>(const Ipp16s value[3], Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_AC4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp8u, ippC4>(const Ipp8u value[4], Ipp8u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_8u_C4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16u, ippC4>(const Ipp16u value[4], Ipp16u *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16u_C4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus SubC_Sfs_I_L<Ipp16s, ippC4>(const Ipp16s value[4], Ipp16s *pSrcDst, IppSizeL srcDstStep, IppiSizeL roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSubC_16s_C4IRSfs_L(value, pSrcDst, srcDstStep, roiSize, scaleFactor)); }

  } // namespace i
} // namespace tipp
