#pragma once
#include <ipp/ippi.h>
#include "tipp_error.hpp"
#include "tipp_type.hpp"

namespace tipp
{
    namespace cv
    {
        template <typename T, IppChannels C>
        static inline IppStatus Add_Sfs(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor);
        template <>
        static inline IppStatus Add_Sfs<Ipp8u, ippC1>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_8u_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }
        template <>
        static inline IppStatus Add_Sfs<Ipp16u, ippC1>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16u_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }
        template <>
        static inline IppStatus Add_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16s_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }
        template <>
        static inline IppStatus Add_Sfs<Ipp16s, ippC1>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16s_C1RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }
        template <>
        static inline IppStatus Add_Sfs<Ipp8u, ippC3>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_8u_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16u, ippC3>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16u_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16s, ippC3>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16s_C3RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp8u, ippC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_8u_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16u, ippC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16u_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16s, ippC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16s_C4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp8u, ippAC4>(const Ipp8u *pSrc1, int src1Step, const Ipp8u *pSrc2, int src2Step, Ipp8u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_8u_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16u, ippAC4>(const Ipp16u *pSrc1, int src1Step, const Ipp16u *pSrc2, int src2Step, Ipp16u *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16u_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <>
        static inline IppStatus Add_Sfs<Ipp16s, ippAC4>(const Ipp16s *pSrc1, int src1Step, const Ipp16s *pSrc2, int src2Step, Ipp16s *pDst, int dstStep, IppiSize roiSize, int scaleFactor)
        {
            return OptionalAssertNoError(ippiAdd_16s_AC4RSfs(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
        }

        template <typename T, IppChannels C>
        static inline IppStatus Add(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize);
        template <>
        static inline IppStatus Add<Ipp32f, ippC1>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize)
        {
            return OptionalAssertNoError(ippiAdd_32f_C1R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize));
        }
        template <>
        static inline IppStatus Add<Ipp32f, ippC3>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize)
        {
            return OptionalAssertNoError(ippiAdd_32f_C3R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize));
        }
        template <>
        static inline IppStatus Add<Ipp32f, ippC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize)
        {
            return OptionalAssertNoError(ippiAdd_32f_C4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize));
        }
        template <>
        static inline IppStatus Add<Ipp32f, ippAC4>(const Ipp32f *pSrc1, int src1Step, const Ipp32f *pSrc2, int src2Step, Ipp32f *pDst, int dstStep, IppiSize roiSize)
        {
            return OptionalAssertNoError(ippiAdd_32f_AC4R(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize));
        }

    }
}
