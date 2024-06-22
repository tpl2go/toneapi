#include <ipps.h>
#include <ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <vector>

namespace tipp
{
    static inline void AddC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsAddC_32f(pSrc, val, pDst, len)); }
    static inline void AddC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsAddC_64f(pSrc, val, pDst, len)); }
    static inline void AddC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsAddC_32fc(pSrc, val, pDst, len)); }
    static inline void AddC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsAddC_64fc(pSrc, val, pDst, len)); }

    static inline void AddC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsAddC_16s_I(val, pSrcDst, len)); }
    static inline void AddC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsAddC_32f_I(val, pSrcDst, len)); }
    static inline void AddC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsAddC_64f_I(val, pSrcDst, len)); }
    static inline void AddC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsAddC_32fc_I(val, pSrcDst, len)); }
    static inline void AddC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsAddC_64fc_I(val, pSrcDst, len)); }

    static inline void AddProductC(const Ipp32f *pSrc, const Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsAddProductC_32f(pSrc, val, pSrcDst, len)); }
    static inline void AddProductC(const Ipp64f *pSrc, const Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsAddProductC_64f(pSrc, val, pSrcDst, len)); }

    static inline void AddProduct(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pSrcDst, int len) { AssertNoError(ippsAddProduct_32f(pSrc1, pSrc2, pSrcDst, len)); }
    static inline void AddProduct(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pSrcDst, int len) { AssertNoError(ippsAddProduct_64f(pSrc1, pSrc2, pSrcDst, len)); }
    static inline void AddProduct(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsAddProduct_32fc(pSrc1, pSrc2, pSrcDst, len)); }
    static inline void AddProduct(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsAddProduct_64fc(pSrc1, pSrc2, pSrcDst, len)); }

    static inline void Add_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsAdd_16s_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsAdd_32f_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsAdd_64f_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsAdd_32fc_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsAdd_64fc_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp16s *pSrc, Ipp32s *pSrcDst, int len) { AssertNoError(ippsAdd_16s32s_I(pSrc, pSrcDst, len)); }
    static inline void Add_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { AssertNoError(ippsAdd_32u_I(pSrc, pSrcDst, len)); }

    static inline void Add(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { AssertNoError(ippsAdd_16s(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { AssertNoError(ippsAdd_16u(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsAdd_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsAdd_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { AssertNoError(ippsAdd_32fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { AssertNoError(ippsAdd_64fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Add(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { AssertNoError(ippsAdd_32u(pSrc1, pSrc2, pDst, len)); }

    static inline void MulC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsMulC_32f(pSrc, val, pDst, len)); }
    static inline void MulC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsMulC_64f(pSrc, val, pDst, len)); }
    static inline void MulC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsMulC_32fc(pSrc, val, pDst, len)); }
    static inline void MulC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsMulC_64fc(pSrc, val, pDst, len)); }
    static inline void MulC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMulC_16s_I(val, pSrcDst, len)); }
    static inline void MulC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulC_32f_I(val, pSrcDst, len)); }
    static inline void MulC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulC_64f_I(val, pSrcDst, len)); }
    static inline void MulC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsMulC_32fc_I(val, pSrcDst, len)); }
    static inline void MulC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsMulC_64fc_I(val, pSrcDst, len)); }

    static inline void Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { AssertNoError(ippsMul_16s(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMul_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsMul_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { AssertNoError(ippsMul_32fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { AssertNoError(ippsMul_64fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp16u *pDst, int len) { AssertNoError(ippsMul_8u16u(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { AssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp32fc *pSrc2, const Ipp32f *pSrc1, Ipp32fc *pDst, int len) { AssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMul_16s32f(pSrc1, pSrc2, pDst, len)); }

    static inline void Mul_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMul_16s_I(pSrc, pSrcDst, len)); }
    static inline void Mul_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMul_32f_I(pSrc, pSrcDst, len)); }
    static inline void Mul_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMul_64f_I(pSrc, pSrcDst, len)); }
    static inline void Mul_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsMul_32fc_I(pSrc, pSrcDst, len)); }
    static inline void Mul_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsMul_64fc_I(pSrc, pSrcDst, len)); }
    static inline void Mul_I(const Ipp32f *pSrc, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsMul_32f32fc_I(pSrc, pSrcDst, len)); }

    static inline void SubCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsSubCRev_32f(pSrc, val, pDst, len)); }
    static inline void SubCRev(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsSubCRev_64f(pSrc, val, pDst, len)); }
    static inline void SubCRev(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsSubCRev_32fc(pSrc, val, pDst, len)); }
    static inline void SubCRev(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsSubCRev_64fc(pSrc, val, pDst, len)); }

    static inline void SubCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsSubCRev_32f_I(val, pSrcDst, len)); }
    static inline void SubCRev_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsSubCRev_64f_I(val, pSrcDst, len)); }
    static inline void SubCRev_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsSubCRev_32fc_I(val, pSrcDst, len)); }
    static inline void SubCRev_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsSubCRev_64fc_I(val, pSrcDst, len)); }

    static inline void SubCRev_Sfs(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_8u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubCRev_Sfs(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubCRev_Sfs(const Ipp16s *pSrc, Ipp16s val, Ipp16s *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubCRev_Sfs(const Ipp32s *pSrc, Ipp32s val, Ipp32s *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_32s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubCRev_Sfs(const Ipp16sc *pSrc, Ipp16sc val, Ipp16sc *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubCRev_Sfs(const Ipp32sc *pSrc, Ipp32sc val, Ipp32sc *pDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_32sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }

    static inline void SubCRev_ISfs(Ipp8u val, Ipp8u *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_8u_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubCRev_ISfs(Ipp16u val, Ipp16u *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16u_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubCRev_ISfs(Ipp16s val, Ipp16s *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16s_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubCRev_ISfs(Ipp32s val, Ipp32s *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_32s_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubCRev_ISfs(Ipp16sc val, Ipp16sc *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_16sc_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubCRev_ISfs(Ipp32sc val, Ipp32sc *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubCRev_32sc_ISfs(val, pSrcDst, len, scaleFactor)); }

    static inline void SubC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsSubC_32f(pSrc, val, pDst, len)); }
    static inline void SubC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsSubC_32fc(pSrc, val, pDst, len)); }
    static inline void SubC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsSubC_64f(pSrc, val, pDst, len)); }
    static inline void SubC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsSubC_64fc(pSrc, val, pDst, len)); }

    static inline void SubC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsSubC_16s_I(val, pSrcDst, len)); }
    static inline void SubC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsSubC_32f_I(val, pSrcDst, len)); }
    static inline void SubC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsSubC_64f_I(val, pSrcDst, len)); }
    static inline void SubC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsSubC_32fc_I(val, pSrcDst, len)); }
    static inline void SubC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsSubC_64fc_I(val, pSrcDst, len)); }

    static inline void SubC_ISfs(Ipp8u val, Ipp8u *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_8u_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubC_ISfs(Ipp16u val, Ipp16u *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16u_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubC_ISfs(Ipp16s val, Ipp16s *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16s_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubC_ISfs(Ipp32s val, Ipp32s *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_32s_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubC_ISfs(Ipp16sc val, Ipp16sc *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16sc_ISfs(val, pSrcDst, len, scaleFactor)); }
    static inline void SubC_ISfs(Ipp32sc val, Ipp32sc *pSrcDst, int len, int scaleFactor) { AssertNoError(ippsSubC_32sc_ISfs(val, pSrcDst, len, scaleFactor)); }

    static inline void SubC_Sfs(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_8u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubC_Sfs(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubC_Sfs(const Ipp16s *pSrc, Ipp16s val, Ipp16s *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubC_Sfs(const Ipp32s *pSrc, Ipp32s val, Ipp32s *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_32s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubC_Sfs(const Ipp16sc *pSrc, Ipp16sc val, Ipp16sc *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_16sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }
    static inline void SubC_Sfs(const Ipp32sc *pSrc, Ipp32sc val, Ipp32sc *pDst, int len, int scaleFactor) { AssertNoError(ippsSubC_32sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }

    static inline void DivCRev(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsDivCRev_16u(pSrc, val, pDst, len)); }
    static inline void DivCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsDivCRev_32f(pSrc, val, pDst, len)); }

    static inline void DivCRev_I(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsDivCRev_16u_I(val, pSrcDst, len)); }
    static inline void DivCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsDivCRev_32f_I(val, pSrcDst, len)); }

    static inline void DivC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsDivC_32f_I(val, pSrcDst, len)); }
    static inline void DivC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsDivC_64f_I(val, pSrcDst, len)); }
    static inline void DivC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsDivC_32fc_I(val, pSrcDst, len)); }
    static inline void DivC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsDivC_64fc_I(val, pSrcDst, len)); }
    static inline void DivC_I(const double val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsDivC_64f_I(val, reinterpret_cast<Ipp64f *>(pSrcDst), 2 * len)); }
    static inline void DivC_I(const float val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsDivC_32f_I(val, reinterpret_cast<Ipp32f *>(pSrcDst), 2 * len)); }

    static inline void DivC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsDivC_32f(pSrc, val, pDst, len)); }
    static inline void DivC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsDivC_64f(pSrc, val, pDst, len)); }
    static inline void DivC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsDivC_32fc(pSrc, val, pDst, len)); }
    static inline void DivC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsDivC_64fc(pSrc, val, pDst, len)); }
    static inline void DivC(const Ipp32fc *pSrc, Ipp32f val, Ipp32fc *pDst, int len) { AssertNoError(ippsDivC_32f(reinterpret_cast<const Ipp32f *>(pSrc), val, reinterpret_cast<Ipp32f *>(pDst), 2 * len)); }
    static inline void DivC(const Ipp64fc *pSrc, Ipp64f val, Ipp64fc *pDst, int len) { AssertNoError(ippsDivC_64f(reinterpret_cast<const Ipp64f *>(pSrc), val, reinterpret_cast<Ipp64f *>(pDst), 2 * len)); }

    static inline void Div(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsDiv_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void Div(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsDiv_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void Div(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { AssertNoError(ippsDiv_32fc(pSrc1, pSrc2, pDst, len)); }
    static inline void Div(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { AssertNoError(ippsDiv_64fc(pSrc1, pSrc2, pDst, len)); }

    static inline void Abs(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsAbs_16s(pSrc, pDst, len)); }
    static inline void Abs(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsAbs_32s(pSrc, pDst, len)); }
    static inline void Abs(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsAbs_32f(pSrc, pDst, len)); }
    static inline void Abs(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsAbs_64f(pSrc, pDst, len)); }

    static inline void Abs_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsAbs_16s_I(pSrcDst, len)); }
    static inline void Abs_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsAbs_32s_I(pSrcDst, len)); }
    static inline void Abs_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsAbs_32f_I(pSrcDst, len)); }
    static inline void Abs_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsAbs_64f_I(pSrcDst, len)); }

    static inline void Sqr_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSqr_32f_I(pSrcDst, len)); }
    static inline void Sqr_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSqr_64f_I(pSrcDst, len)); }
    static inline void Sqr_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsSqr_32fc_I(pSrcDst, len)); }
    static inline void Sqr_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsSqr_64fc_I(pSrcDst, len)); }

    static inline void Sqr(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsSqr_32f(pSrc, pDst, len)); }
    static inline void Sqr(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsSqr_64f(pSrc, pDst, len)); }
    static inline void Sqr(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsSqr_32fc(pSrc, pDst, len)); }
    static inline void Sqr(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsSqr_64fc(pSrc, pDst, len)); }

    static inline void Sqrt_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSqrt_32f_I(pSrcDst, len)); }
    static inline void Sqrt_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSqrt_64f_I(pSrcDst, len)); }
    static inline void Sqrt_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsSqrt_32fc_I(pSrcDst, len)); }
    static inline void Sqrt_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsSqrt_64fc_I(pSrcDst, len)); }

    static inline void Sqrt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsSqrt_32f(pSrc, pDst, len)); }
    static inline void Sqrt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsSqrt_64f(pSrc, pDst, len)); }
    static inline void Sqrt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsSqrt_32fc(pSrc, pDst, len)); }
    static inline void Sqrt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsSqrt_64fc(pSrc, pDst, len)); }

    static inline void Exp(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsExp_32f(pSrc, pDst, len)); }
    static inline void Exp(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsExp_64f(pSrc, pDst, len)); }

    static inline void Exp_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsExp_32f_I(pSrcDst, len)); }
    static inline void Exp_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsExp_64f_I(pSrcDst, len)); }

    static inline void Ln(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsLn_32f(pSrc, pDst, len)); }
    static inline void Ln(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsLn_64f(pSrc, pDst, len)); }
    static inline void Ln_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsLn_32f_I(pSrcDst, len)); }
    static inline void Ln_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsLn_64f_I(pSrcDst, len)); }

    static inline void SumLn(const Ipp32f *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSumLn_32f(pSrc, len, pSum)); }
    static inline void SumLn(const Ipp64f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSumLn_64f(pSrc, len, pSum)); }
    static inline void SumLn(const Ipp32f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSumLn_32f64f(pSrc, len, pSum)); }
    static inline void SumLn(const Ipp16s *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSumLn_16s32f(pSrc, len, pSum)); }

    static inline void Arctan(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsArctan_32f(pSrc, pDst, len)); }
    static inline void Arctan(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsArctan_64f(pSrc, pDst, len)); }

    static inline void Arctan_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsArctan_32f_I(pSrcDst, len)); }
    static inline void Arctan_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsArctan_64f_I(pSrcDst, len)); }

    static inline void Normalize(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32f(pSrc, pDst, len, vSub, vDiv)); }
    static inline void Normalize(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64f(pSrc, pDst, len, vSub, vDiv)); }
    static inline void Normalize(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32fc vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32fc(pSrc, pDst, len, vSub, vDiv)); }
    static inline void Normalize(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64fc vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64fc(pSrc, pDst, len, vSub, vDiv)); }

    static inline void Normalize_I(Ipp32f *pSrcDst, int len, Ipp32f vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32f_I(pSrcDst, len, vSub, vDiv)); }
    static inline void Normalize_I(Ipp64f *pSrcDst, int len, Ipp64f vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64f_I(pSrcDst, len, vSub, vDiv)); }
    static inline void Normalize_I(Ipp32fc *pSrcDst, int len, Ipp32fc vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32fc_I(pSrcDst, len, vSub, vDiv)); }
    static inline void Normalize_I(Ipp64fc *pSrcDst, int len, Ipp64fc vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64fc_I(pSrcDst, len, vSub, vDiv)); }

}
