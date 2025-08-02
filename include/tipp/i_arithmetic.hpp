#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <ipp/ippi.h>

namespace tipp {
  namespace cv {
    namespace {
      template <typename T, IppChannels C>
      struct AddSfsTrait;

      template <> struct AddSfsTrait<Ipp8u, ippC1> {
        static constexpr auto func = ippiAdd_8u_C1RSfs;
      };

      template <> struct AddSfsTrait<Ipp16u, ippC1> {
        static constexpr auto func = ippiAdd_16u_C1RSfs;
      };

      template <> struct AddSfsTrait<Ipp16s, ippC1> {
        static constexpr auto func = ippiAdd_16s_C1RSfs;
      };

      template <> struct AddSfsTrait<Ipp8u, ippC3> {
        static constexpr auto func = ippiAdd_8u_C3RSfs;
      };

      template <> struct AddSfsTrait<Ipp16u, ippC3> {
        static constexpr auto func = ippiAdd_16u_C3RSfs;
      };

      template <> struct AddSfsTrait<Ipp16s, ippC3> {
        static constexpr auto func = ippiAdd_16s_C3RSfs;
      };

      template <> struct AddSfsTrait<Ipp8u, ippC4> {
        static constexpr auto func = ippiAdd_8u_C4RSfs;
      };

      template <> struct AddSfsTrait<Ipp16u, ippC4> {
        static constexpr auto func = ippiAdd_16u_C4RSfs;
      };

      template <> struct AddSfsTrait<Ipp16s, ippC4> {
        static constexpr auto func = ippiAdd_16s_C4RSfs;
      };

      template <> struct AddSfsTrait<Ipp8u, ippAC4> {
        static constexpr auto func = ippiAdd_8u_AC4RSfs;
      };

      template <> struct AddSfsTrait<Ipp16u, ippAC4> {
        static constexpr auto func = ippiAdd_16u_AC4RSfs;
      };

      template <> struct AddSfsTrait<Ipp16s, ippAC4> {
        static constexpr auto func = ippiAdd_16s_AC4RSfs;
      };
    } // namespace

    template <typename T, IppChannels C>
    static inline IppStatus Add_Sfs(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize, int scaleFactor) {
      return OptionalAssertNoError(AddSfsTrait<T, C>::func(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize, scaleFactor));
    }

    namespace {
      template <typename T, IppChannels C>
      struct AddTrait;

      // Specializations for different combinations
      template <> struct AddTrait<Ipp32f, ippC1> {
        static constexpr auto func = ippiAdd_32f_C1R;
      };

      template <> struct AddTrait<Ipp32f, ippC3> {
        static constexpr auto func = ippiAdd_32f_C3R;
      };

      template <> struct AddTrait<Ipp32f, ippC4> {
        static constexpr auto func = ippiAdd_32f_C4R;
      };

      template <> struct AddTrait<Ipp32f, ippAC4> {
        static constexpr auto func = ippiAdd_32f_AC4R;
      };
    } // namespace

    template <typename T, IppChannels C>
    static inline IppStatus Add(const T *pSrc1, int src1Step, const T *pSrc2, int src2Step, T *pDst, int dstStep, IppiSize roiSize) {
      return OptionalAssertNoError(AddTrait<T, C>::func(pSrc1, src1Step, pSrc2, src2Step, pDst, dstStep, roiSize));
    }

  } // namespace cv
} // namespace tipp
