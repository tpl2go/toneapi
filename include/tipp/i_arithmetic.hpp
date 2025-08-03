#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <ipp/ippi.h>

namespace tipp {
  namespace i {

    template <typename T, IppChannels C>
    static inline IppStatus Abs(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Abs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippAC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippAC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Abs(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Abs<Ipp16s, ippC1>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC1>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippC3>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC3>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippC4>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp16s, ippAC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_16s_AC4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Abs<Ipp32f, ippAC4>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiAbs_32f_AC4IR(pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sqr_Sfs(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Sqr_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp8u, ippC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16u, ippC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16s, ippC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp8u, ippAC4>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_AC4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16u, ippAC4>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_AC4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_Sfs<Ipp16s, ippAC4>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_AC4RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sqr(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Sqr<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sqr<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sqr<Ipp32f, ippC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Sqr<Ipp32f, ippAC4>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sqr_I_Sfs(T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Sqr_I_Sfs<Ipp8u, ippC1>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16u, ippC1>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16s, ippC1>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp8u, ippC3>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16u, ippC3>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16s, ippC3>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp8u, ippC4>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_C4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16u, ippC4>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_C4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16s, ippC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_C4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp8u, ippAC4>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_8u_AC4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16u, ippAC4>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16u_AC4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Sqr_I_Sfs<Ipp16s, ippAC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiSqr_16s_AC4IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Sqr_I(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Sqr_I<Ipp32f, ippC1>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sqr_I<Ipp32f, ippC3>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sqr_I<Ipp32f, ippC4>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Sqr_I<Ipp32f, ippAC4>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiSqr_32f_AC4IR(pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Ln_Sfs(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Ln_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_8u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16s_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_8u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16s_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Ln(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Ln<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLn_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Ln<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLn_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Ln_I_Sfs(T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Ln_I_Sfs<Ipp8u, ippC1>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_8u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_I_Sfs<Ipp16u, ippC1>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_I_Sfs<Ipp16s, ippC1>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16s_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_I_Sfs<Ipp8u, ippC3>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_8u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_I_Sfs<Ipp16u, ippC3>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Ln_I_Sfs<Ipp16s, ippC3>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiLn_16s_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Ln_I(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Ln_I<Ipp32f, ippC1>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLn_32f_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Ln_I<Ipp32f, ippC3>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiLn_32f_C3IR(pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Exp_Sfs(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Exp_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_8u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16u_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16s_C1RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_8u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc, int srcStep, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16u_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16s_C3RSfs(pSrc, srcStep, pDst, dstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Exp(const T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Exp<Ipp32f, ippC1>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiExp_32f_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Exp<Ipp32f, ippC3>(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiExp_32f_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Exp_I_Sfs(T *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor);
    template <> static inline IppStatus Exp_I_Sfs<Ipp8u, ippC1>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_8u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_I_Sfs<Ipp16u, ippC1>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16u_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_I_Sfs<Ipp16s, ippC1>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16s_C1IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_I_Sfs<Ipp8u, ippC3>(Ipp8u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_8u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_I_Sfs<Ipp16u, ippC3>(Ipp16u *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16u_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }
    template <> static inline IppStatus Exp_I_Sfs<Ipp16s, ippC3>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize, int scaleFactor) { return OptionalAssertNoError(ippiExp_16s_C3IRSfs(pSrcDst, srcDstStep, roiSize, scaleFactor)); }

    template <typename T, IppChannels C>
    static inline IppStatus Exp_I(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Exp_I<Ipp32f, ippC1>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiExp_32f_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Exp_I<Ipp32f, ippC3>(Ipp32f *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiExp_32f_C3IR(pSrcDst, srcDstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus DotProd(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp);
    template <> static inline IppStatus DotProd<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp) { return OptionalAssertNoError(ippiDotProd_8u64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp) { return OptionalAssertNoError(ippiDotProd_16u64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16s, ippC1>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp) { return OptionalAssertNoError(ippiDotProd_16s64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32u, ippC1>(const Ipp32u *pSrc1, int src1Step, const Ipp32u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp) { return OptionalAssertNoError(ippiDotProd_32u64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32s, ippC1>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp) { return OptionalAssertNoError(ippiDotProd_32s64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }

    template <typename T, IppChannels C>
    static inline IppStatus DotProd(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp);
    template <> static inline IppStatus DotProd<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_8u64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_16u64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16s, ippC3>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_16s64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32u, ippC3>(const Ipp32u *pSrc1, int src1Step, const Ipp32u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_32u64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32s, ippC3>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_32s64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4]) { return OptionalAssertNoError(ippiDotProd_8u64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4]) { return OptionalAssertNoError(ippiDotProd_16u64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16s, ippC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4]) { return OptionalAssertNoError(ippiDotProd_16s64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32u, ippC4>(const Ipp32u *pSrc1, int src1Step, const Ipp32u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4]) { return OptionalAssertNoError(ippiDotProd_32u64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32s, ippC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4]) { return OptionalAssertNoError(ippiDotProd_32s64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_8u64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_16u64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp16s, ippAC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_16s64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32u, ippAC4>(const Ipp32u *pSrc1, int src1Step, const Ipp32u *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_32u64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }
    template <> static inline IppStatus DotProd<Ipp32s, ippAC4>(const Ipp32s *pSrc1, int src1Step, const Ipp32s *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3]) { return OptionalAssertNoError(ippiDotProd_32s64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp)); }

    template <typename T, IppChannels C>
    static inline IppStatus DotProd(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp, IppHintAlgorithm hint);
    template <> static inline IppStatus DotProd<Ipp32f, ippC1>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, IppiSize roiSize, Ipp64f *pDp, IppHintAlgorithm hint) { return OptionalAssertNoError(ippiDotProd_32f64f_C1R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp, hint)); }
    template <> static inline IppStatus DotProd<Ipp32f, ippC3>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3], IppHintAlgorithm hint) { return OptionalAssertNoError(ippiDotProd_32f64f_C3R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp, hint)); }
    template <> static inline IppStatus DotProd<Ipp32f, ippC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[4], IppHintAlgorithm hint) { return OptionalAssertNoError(ippiDotProd_32f64f_C4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp, hint)); }
    template <> static inline IppStatus DotProd<Ipp32f, ippAC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, IppiSize roiSize, Ipp64f pDp[3], IppHintAlgorithm hint) { return OptionalAssertNoError(ippiDotProd_32f64f_AC4R(pSrc1, src1Step, pSrc2, src2Step, roiSize, pDp, hint)); }

    template <typename T>
    static inline IppStatus DotProdCol_L2(const T *const ppSrcRow[], const T *pTaps, int tapsLen, T *pDst, int width);
    template <> static inline IppStatus DotProdCol_L2<Ipp32f>(const Ipp32f *const ppSrcRow[], const Ipp32f *pTaps, int tapsLen, Ipp32f *pDst, int width) { return OptionalAssertNoError(ippiDotProdCol_32f_L2(ppSrcRow, pTaps, tapsLen, pDst, width)); }
    template <> static inline IppStatus DotProdCol_L2<Ipp64f>(const Ipp64f *const ppSrcRow[], const Ipp64f *pTaps, int tapsLen, Ipp64f *pDst, int width) { return OptionalAssertNoError(ippiDotProdCol_64f_L2(ppSrcRow, pTaps, tapsLen, pDst, width)); }

    template <typename T, IppChannels C>
    static inline IppStatus Complement(T *pSrc, int srcStep, T *pDst, int dstStep, IppiSize roiSize);
    template <> static inline IppStatus Complement<Ipp8s, ippC1>(Ipp8s *pSrc, int srcStep, Ipp8s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp16s, ippC1>(Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp32s, ippC1>(Ipp32s *pSrc, int srcStep, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C1R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp8s, ippC3>(Ipp8s *pSrc, int srcStep, Ipp8s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp16s, ippC3>(Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp32s, ippC3>(Ipp32s *pSrc, int srcStep, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C3R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp8s, ippC4>(Ipp8s *pSrc, int srcStep, Ipp8s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp16s, ippC4>(Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp32s, ippC4>(Ipp32s *pSrc, int srcStep, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp8s, ippAC4>(Ipp8s *pSrc, int srcStep, Ipp8s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp16s, ippAC4>(Ipp16s *pSrc, int srcStep, Ipp16s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }
    template <> static inline IppStatus Complement<Ipp32s, ippAC4>(Ipp32s *pSrc, int srcStep, Ipp32s *pDst, int dstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_AC4R(pSrc, srcStep, pDst, dstStep, roiSize)); }

    template <typename T, IppChannels C>
    static inline IppStatus Complement_I(T *pSrcDst, int srcDstStep, IppiSize roiSize);
    template <> static inline IppStatus Complement_I<Ipp8s, ippC1>(Ipp8s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp16s, ippC1>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp32s, ippC1>(Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C1IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp8s, ippC3>(Ipp8s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp16s, ippC3>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp32s, ippC3>(Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C3IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp8s, ippC4>(Ipp8s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp16s, ippC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp32s, ippC4>(Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_C4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp8s, ippAC4>(Ipp8s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_8s_AC4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp16s, ippAC4>(Ipp16s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_16s_AC4IR(pSrcDst, srcDstStep, roiSize)); }
    template <> static inline IppStatus Complement_I<Ipp32s, ippAC4>(Ipp32s *pSrcDst, int srcDstStep, IppiSize roiSize) { return OptionalAssertNoError(ippiComplement_32s_AC4IR(pSrcDst, srcDstStep, roiSize)); }
  } // namespace i
} // namespace tipp
