#pragma once
#include <span>
#include "s_arithmetic.hpp"
#include <stdexcept>
#include "tipp_error.hpp"

namespace tipp
{

    /* Essentials Arthimetic */
    template <typename T>
    static inline IppStatus AddC(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return AddC(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus AddC_I(std::span<T> SrcDst, T val)
    {
        return AddC_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Add_I(std::span<const T> Src, std::span<T> SrcDst)
    {
        if (Src.size() != SrcDst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Add_I(Src.data(), SrcDst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Add(std::span<const T> Src1, std::span<const T> Src2, std::span<T> Dst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != Dst.size())
            throw std::invalid_argument("All spans must have the same size");
        return Add(Src1.data(), Src2.data(), Dst.data(), Src1.size());
    };

    template <typename T>
    static inline IppStatus AddProductC(std::span<const T> Src, T val, std::span<T> SrcDst)
    {
        if (Src.size() != SrcDst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return AddProductC(Src.data(), val, SrcDst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus AddProduct(std::span<const T> Src1, std::span<const T> Src2, std::span<T> SrcDst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != SrcDst.size())
            throw std::invalid_argument("All spans must have the same size");
        return AddProduct(Src1.data(), Src2.data(), SrcDst.data(), Src1.size());
    };

    template <typename T>
    static inline IppStatus MulC(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return MulC(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus MulC_I(std::span<T> SrcDst, T val)
    {
        return MulC_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Mul(std::span<const T> Src1, std::span<const T> Src2, std::span<T> Dst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != Dst.size())
            throw std::invalid_argument("All spans must have the same size");
        return Mul(Src1.data(), Src2.data(), Dst.data(), Src1.size());
    };

    template <typename T>
    static inline IppStatus Mul(std::span<const T> Src1, std::span<const T> Src2, std::span<T> Dst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != Dst.size())
            throw std::invalid_argument("All spans must have the same size");
        return Mul(Src1.data(), Src2.data(), Dst.data(), Src1.size());
    };

    template <typename T>
    static inline IppStatus Mul_I(std::span<const T> Src, std::span<T> SrcDst)
    {
        if (Src.size() != SrcDst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Mul_I(Src.data(), SrcDst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus SubC(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return SubC(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus SubC_I(T val, std::span<T> SrcDst)
    {
        return SubC_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus SubC_ISfs(T val, std::span<T> SrcDst, int scaleFactor)
    {
        return SubC_ISfs(val, SrcDst.data(), SrcDst.size(), scaleFactor);
    };

    template <typename T>
    static inline IppStatus SubC_Sfs(std::span<const T> Src, T val, std::span<T> Dst, int scaleFactor)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return SubC_Sfs(Src.data(), val, Dst.data(), Src.size(), scaleFactor);
    };

    template <typename T>
    static inline IppStatus SubCRev(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return SubCRev(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus SubCRev_I(T val, std::span<T> SrcDst)
    {
        return SubCRev_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus SubCRev_Sfs(std::span<const T> Src, T val, std::span<T> Dst, int scaleFactor)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return SubCRev_Sfs(Src.data(), val, Dst.data(), Src.size(), scaleFactor);
    };
    template <typename T>
    static inline IppStatus SubCRev_ISfs(T val, std::span<T> SrcDst, int scaleFactor)
    {
        return SubCRev_ISfs(val, SrcDst.data(), SrcDst.size(), scaleFactor);
    };

    template <typename T>
    static inline IppStatus Sub(std::span<const T> Src1, std::span<const T> Src2, std::span<T> Dst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != Dst.size())
            throw std::invalid_argument("All spans must have the same size");
        return Sub(Src1.data(), Src2.data(), Dst.data(), Src1.size());
    };
    template <typename T>
    static inline IppStatus DivC_I(std::span<T> SrcDst, T val)
    {
        return DivC_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus DivC(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return DivC(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus DivCRev(std::span<const T> Src, T val, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return DivCRev(Src.data(), val, Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus DivCRev_I(std::span<T> SrcDst, T val)
    {
        return DivCRev_I(val, SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Div(std::span<const T> Src1, std::span<const T> Src2, std::span<T> Dst)
    {
        if (Src1.size() != Src2.size() || Src1.size() != Dst.size())
            throw std::invalid_argument("All spans must have the same size");
        return Div(Src1.data(), Src2.data(), Dst.data(), Src1.size());
    };

    template <typename T>
    static inline IppStatus Abs(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Abs(Src.data(), Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Abs_I(std::span<T> SrcDst)
    {
        return Abs_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Sqr_I(std::span<T> SrcDst)
    {
        return Sqr_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Sqr(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Sqr(Src.data(), Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Sqrt_I(std::span<T> SrcDst)
    {
        return Sqrt_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Sqrt(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Sqrt(Src.data(), Dst.data(), Src.size());
    };

    // Cubrt doesnt need wrapper
    // IppStatus ippsCubrt_32f(const Ipp32f* pSrc, Ipp32f* pDst, int len);

    template <typename T>
    static inline IppStatus Exp(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Exp(Src.data(), Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Exp_I(std::span<T> SrcDst)
    {
        return Exp_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Ln(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Ln(Src.data(), Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Ln_I(std::span<T> SrcDst)
    {
        return Ln_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus SumLn(std::span<const T> Src, T *pSum)
    {
        return SumLn(Src.data(), Src.size(), pSum);
    };

    template <typename T>
    static inline IppStatus Arctan(std::span<const T> Src, std::span<T> Dst)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Arctan(Src.data(), Dst.data(), Src.size());
    };

    template <typename T>
    static inline IppStatus Arctan_I(std::span<T> SrcDst)
    {
        return Arctan_I(SrcDst.data(), SrcDst.size());
    };

    template <typename T>
    static inline IppStatus Normalize(std::span<const T> Src, std::span<T> Dst, T vSub, T vDiv)
    {
        if (Src.size() != Dst.size())
            throw std::invalid_argument("Source and destination spans must have the same size");
        return Normalize(Src.data(), Dst.data(), Src.size(), vSub, vDiv);
    };

    template <typename T>
    static inline IppStatus Normalize_I(std::span<T> SrcDst, T vSub, T vDiv)
    {
        return Normalize_I(SrcDst.data(), SrcDst.size(), vSub, vDiv);
    };

}
