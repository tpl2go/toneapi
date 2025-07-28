#pragma once
#include <ipp/ipptypes.h>
#include <ipp/ippcore.h>

namespace tipp
{
    template <typename T>
    static inline IppDataType GetIppDataType();
    template <>
    static inline IppDataType GetIppDataType<Ipp32f>() { return ipp32f; }
    template <>
    static inline IppDataType GetIppDataType<Ipp64f>() { return ipp64f; }
    template <>
    static inline IppDataType GetIppDataType<Ipp32fc>() { return ipp32fc; }
    template <>
    static inline IppDataType GetIppDataType<Ipp64fc>() { return ipp64fc; }
    template <>
    static inline IppDataType GetIppDataType<Ipp16s>() { return ipp16s; }
    template <>
    static inline IppDataType GetIppDataType<Ipp16sc>() { return ipp16sc; }
    template <>
    static inline IppDataType GetIppDataType<Ipp8u>() { return ipp8u; }
    template <>
    static inline IppDataType GetIppDataType<Ipp32s>() { return ipp32s; }
    template <>
    static inline IppDataType GetIppDataType<Ipp32u>() { return ipp32u; }
    template <>
    static inline IppDataType GetIppDataType<Ipp64s>() { return ipp64s; }
    template <>
    static inline IppDataType GetIppDataType<Ipp64u>() { return ipp64u; }
}