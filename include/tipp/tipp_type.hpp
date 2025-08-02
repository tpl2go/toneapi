#pragma once
#include <complex>
#include <ipp/ippcore.h>
#include <ipp/ipptypes.h>
#include <type_traits>

namespace tipp {
  template <typename T>
  static inline IppDataType GetIppDataType();
  template <> static inline IppDataType GetIppDataType<Ipp32f>() { return ipp32f; }
  template <> static inline IppDataType GetIppDataType<Ipp64f>() { return ipp64f; }
  template <> static inline IppDataType GetIppDataType<Ipp32fc>() { return ipp32fc; }
  template <> static inline IppDataType GetIppDataType<Ipp64fc>() { return ipp64fc; }
  template <> static inline IppDataType GetIppDataType<Ipp16s>() { return ipp16s; }
  template <> static inline IppDataType GetIppDataType<Ipp16sc>() { return ipp16sc; }
  template <> static inline IppDataType GetIppDataType<Ipp8u>() { return ipp8u; }
  template <> static inline IppDataType GetIppDataType<Ipp32s>() { return ipp32s; }
  template <> static inline IppDataType GetIppDataType<Ipp32u>() { return ipp32u; }
  template <> static inline IppDataType GetIppDataType<Ipp64s>() { return ipp64s; }
  template <> static inline IppDataType GetIppDataType<Ipp64u>() { return ipp64u; }
  template <> static inline IppDataType GetIppDataType<std::complex<float>>() { return ipp32fc; }
  template <> static inline IppDataType GetIppDataType<std::complex<double>>() { return ipp64fc; }

  template <typename T>
  struct IsComplex : std::false_type {};
  template <> struct IsComplex<Ipp32fc> : std::true_type {};
  template <> struct IsComplex<Ipp64fc> : std::true_type {};
  template <> struct IsComplex<std::complex<float>> : std::true_type {};
  template <> struct IsComplex<std::complex<double>> : std::true_type {};

  template <typename T>
  struct ToCplx {
    using type = T;
  };

  template <> struct ToCplx<float> {
    using type = std::complex<float>;
  };

  template <> struct ToCplx<double> {
    using type = std::complex<double>;
  };

  template <> struct ToCplx<short> {
    using type = std::complex<short>;
  };

  template <typename T>
  struct ToReal {
    using type = T;
  };

  template <typename T>
  struct ToReal<std::complex<T>> {
    using type = T;
  };

  template <> struct ToReal<Ipp32fc> {
    using type = Ipp32f;
  };

  template <> struct ToReal<Ipp64fc> {
    using type = Ipp64f;
  };

} // namespace tipp