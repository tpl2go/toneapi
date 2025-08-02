#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <complex>
#include <ipp/ippcore.h>
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <stdexcept>

namespace tipp {
  namespace s {
    /* Support */

    // ippsMalloc
    // limited to 2GB of memory
    template <typename T>
    static inline T *ippsMalloc(int len);
    template <> static inline Ipp8u *ippsMalloc<Ipp8u>(int len) { return ippsMalloc_8u(len); }
    template <> static inline Ipp16u *ippsMalloc<Ipp16u>(int len) { return ippsMalloc_16u(len); }
    template <> static inline Ipp32u *ippsMalloc<Ipp32u>(int len) { return ippsMalloc_32u(len); }
    template <> static inline Ipp8s *ippsMalloc<Ipp8s>(int len) { return ippsMalloc_8s(len); }
    template <> static inline Ipp16s *ippsMalloc<Ipp16s>(int len) { return ippsMalloc_16s(len); }
    template <> static inline Ipp32s *ippsMalloc<Ipp32s>(int len) { return ippsMalloc_32s(len); }
    template <> static inline Ipp64s *ippsMalloc<Ipp64s>(int len) { return ippsMalloc_64s(len); }
    template <> static inline Ipp32f *ippsMalloc<Ipp32f>(int len) { return ippsMalloc_32f(len); }
    template <> static inline Ipp64f *ippsMalloc<Ipp64f>(int len) { return ippsMalloc_64f(len); }
    template <> static inline Ipp8sc *ippsMalloc<Ipp8sc>(int len) { return ippsMalloc_8sc(len); }
    template <> static inline Ipp16sc *ippsMalloc<Ipp16sc>(int len) { return ippsMalloc_16sc(len); }
    template <> static inline Ipp32sc *ippsMalloc<Ipp32sc>(int len) { return ippsMalloc_32sc(len); }
    template <> static inline Ipp64sc *ippsMalloc<Ipp64sc>(int len) { return ippsMalloc_64sc(len); }
    template <> static inline Ipp32fc *ippsMalloc<Ipp32fc>(int len) { return ippsMalloc_32fc(len); }
    template <> static inline Ipp64fc *ippsMalloc<Ipp64fc>(int len) { return ippsMalloc_64fc(len); }
    template <> static inline std::complex<float> *ippsMalloc<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc(len)); }
    template <> static inline std::complex<double> *ippsMalloc<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc(len)); }

    // ippsMalloc_L
    // platform aware function -- introduced in 2017
    template <typename T>
    static inline T *ippsMalloc_L(int len) {
      throw std::runtime_error("ippsMalloc_L not implemented for this type");
    }
    template <> static inline Ipp8u *ippsMalloc_L<Ipp8u>(int len) { return ippsMalloc_8u_L(len); }
    template <> static inline Ipp16u *ippsMalloc_L<Ipp16u>(int len) { return ippsMalloc_16u_L(len); }
    template <> static inline Ipp32u *ippsMalloc_L<Ipp32u>(int len) { return ippsMalloc_32u_L(len); }
    template <> static inline Ipp8s *ippsMalloc_L<Ipp8s>(int len) { return ippsMalloc_8s_L(len); }
    template <> static inline Ipp16s *ippsMalloc_L<Ipp16s>(int len) { return ippsMalloc_16s_L(len); }
    template <> static inline Ipp32s *ippsMalloc_L<Ipp32s>(int len) { return ippsMalloc_32s_L(len); }
    template <> static inline Ipp64s *ippsMalloc_L<Ipp64s>(int len) { return ippsMalloc_64s_L(len); }
    template <> static inline Ipp32f *ippsMalloc_L<Ipp32f>(int len) { return ippsMalloc_32f_L(len); }
    template <> static inline Ipp64f *ippsMalloc_L<Ipp64f>(int len) { return ippsMalloc_64f_L(len); }
    template <> static inline Ipp8sc *ippsMalloc_L<Ipp8sc>(int len) { return ippsMalloc_8sc_L(len); }
    template <> static inline Ipp16sc *ippsMalloc_L<Ipp16sc>(int len) { return ippsMalloc_16sc_L(len); }
    template <> static inline Ipp32sc *ippsMalloc_L<Ipp32sc>(int len) { return ippsMalloc_32sc_L(len); }
    template <> static inline Ipp64sc *ippsMalloc_L<Ipp64sc>(int len) { return ippsMalloc_64sc_L(len); }
    template <> static inline Ipp32fc *ippsMalloc_L<Ipp32fc>(int len) { return ippsMalloc_32fc_L(len); }
    template <> static inline Ipp64fc *ippsMalloc_L<Ipp64fc>(int len) { return ippsMalloc_64fc_L(len); }
    template <> static inline std::complex<float> *ippsMalloc_L<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc_L(len)); }
    template <> static inline std::complex<double> *ippsMalloc_L<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc_L(len)); }
  } // namespace s
} // namespace tipp
