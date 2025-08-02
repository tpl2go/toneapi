#pragma once
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include "tipp_type.hpp"

namespace tipp
{
    namespace s
    {
        /* Essentials Arthimetic */

        static inline IppStatus AddC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsAddC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsAddC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const std::complex<float> *pSrc, std::complex<float> val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_32fc((Ipp32fc *)pSrc, *((Ipp32fc *)&val), pDst, len)); }
        static inline IppStatus AddC(const std::complex<double> *pSrc, std::complex<double> val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_64fc((Ipp64fc *)pSrc, *((Ipp64fc *)&val), pDst, len)); }

        static inline IppStatus AddC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(std::complex<float> val, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_32fc_I(*((Ipp32fc *)&val), (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus AddC_I(std::complex<double> val, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_64fc_I(*((Ipp64fc *)&val), (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus Add_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_64fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp16s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_16s32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const std::complex<float> *pSrc, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32fc_I((Ipp32fc *)pSrc, (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus Add_I(const std::complex<double> *pSrc, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_64fc_I((Ipp64fc *)pSrc, (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus Add(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsAdd_16s(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsAdd_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsAdd_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsAdd_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsAdd_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsAdd_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsAdd_32u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsAdd_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Add(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsAdd_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus AddProductC(const Ipp32f *pSrc, const Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProductC_32f(pSrc, val, pSrcDst, len)); }
        static inline IppStatus AddProductC(const Ipp64f *pSrc, const Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProductC_64f(pSrc, val, pSrcDst, len)); }

        static inline IppStatus AddProduct(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_32f(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_64f(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_32fc(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_64fc(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus AddProduct(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus MulC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMulC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMulC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMulC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMulC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const std::complex<float> *pSrc, std::complex<float> val, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsMulC_32fc((Ipp32fc *)pSrc, *((Ipp32fc *)&val), (Ipp32fc *)pDst, len)); }
        static inline IppStatus MulC(const std::complex<double> *pSrc, std::complex<double> val, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsMulC_64fc((Ipp64fc *)pSrc, *((Ipp64fc *)&val), (Ipp64fc *)pDst, len)); }

        static inline IppStatus MulC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(std::complex<float> val, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_32fc_I(*((Ipp32fc *)&val), (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus MulC_I(std::complex<double> val, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_64fc_I(*((Ipp64fc *)&val), (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsMul_16s(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMul_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMul_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMul_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsMul_8u16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32fc *pSrc2, const Ipp32f *pSrc1, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMul_16s32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsMul_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Mul(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsMul_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Mul_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_64fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32f *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const std::complex<float> *pSrc, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32fc_I((Ipp32fc *)pSrc, (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus Mul_I(const std::complex<double> *pSrc, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_64fc_I((Ipp64fc *)pSrc, (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus SubC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSubC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSubC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSubC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSubC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const std::complex<float> *pSrc, std::complex<float> val, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsSubC_32fc((Ipp32fc *)pSrc, *((Ipp32fc *)&val), (Ipp32fc *)pDst, len)); }
        static inline IppStatus SubC(const std::complex<double> *pSrc, std::complex<double> val, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsSubC_64fc((Ipp64fc *)pSrc, *((Ipp64fc *)&val), (Ipp64fc *)pDst, len)); }

        static inline IppStatus SubC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(std::complex<float> val, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_32fc_I(*((Ipp32fc *)&val), (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus SubC_I(std::complex<double> val, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_64fc_I(*((Ipp64fc *)&val), (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus SubC_ISfs(Ipp8u val, Ipp8u *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_8u_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubC_ISfs(Ipp16u val, Ipp16u *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16u_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubC_ISfs(Ipp16s val, Ipp16s *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16s_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubC_ISfs(Ipp32s val, Ipp32s *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_32s_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubC_ISfs(Ipp16sc val, Ipp16sc *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16sc_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubC_ISfs(Ipp32sc val, Ipp32sc *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_32sc_ISfs(val, pSrcDst, len, scaleFactor)); }

        static inline IppStatus SubC_Sfs(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_8u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubC_Sfs(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubC_Sfs(const Ipp16s *pSrc, Ipp16s val, Ipp16s *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubC_Sfs(const Ipp32s *pSrc, Ipp32s val, Ipp32s *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_32s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubC_Sfs(const Ipp16sc *pSrc, Ipp16sc val, Ipp16sc *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_16sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubC_Sfs(const Ipp32sc *pSrc, Ipp32sc val, Ipp32sc *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubC_32sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }

        static inline IppStatus SubCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_32f(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_64f(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const std::complex<float> *pSrc, std::complex<float> val, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc((Ipp32fc *)pSrc, *((Ipp32fc *)&val), (Ipp32fc *)pDst, len)); }
        static inline IppStatus SubCRev(const std::complex<double> *pSrc, std::complex<double> val, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc((Ipp64fc *)pSrc, *((Ipp64fc *)&val), (Ipp64fc *)pDst, len)); }

        static inline IppStatus SubCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_32f_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_64f_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(std::complex<float> val, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc_I(*((Ipp32fc *)&val), (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus SubCRev_I(std::complex<double> val, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc_I(*((Ipp64fc *)&val), (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus SubCRev_Sfs(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_8u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_Sfs(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16u_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_Sfs(const Ipp16s *pSrc, Ipp16s val, Ipp16s *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_Sfs(const Ipp32s *pSrc, Ipp32s val, Ipp32s *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_32s_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_Sfs(const Ipp16sc *pSrc, Ipp16sc val, Ipp16sc *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_Sfs(const Ipp32sc *pSrc, Ipp32sc val, Ipp32sc *pDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_32sc_Sfs(pSrc, val, pDst, len, scaleFactor)); }

        static inline IppStatus SubCRev_ISfs(Ipp8u val, Ipp8u *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_8u_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_ISfs(Ipp16u val, Ipp16u *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16u_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_ISfs(Ipp16s val, Ipp16s *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16s_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_ISfs(Ipp32s val, Ipp32s *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_32s_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_ISfs(Ipp16sc val, Ipp16sc *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_16sc_ISfs(val, pSrcDst, len, scaleFactor)); }
        static inline IppStatus SubCRev_ISfs(Ipp32sc val, Ipp32sc *pSrcDst, int len, int scaleFactor) { return OptionalAssertNoError(ippsSubCRev_32sc_ISfs(val, pSrcDst, len, scaleFactor)); }

        static inline IppStatus Sub(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsSub_16s(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSub_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSub_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSub_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSub_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSub_16s32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsSub_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Sub(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsSub_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Sub_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return ippsSub_16s_I(pSrc, pSrcDst, len); }
        static inline IppStatus Sub_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return ippsSub_32f_I(pSrc, pSrcDst, len); }
        static inline IppStatus Sub_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return ippsSub_64f_I(pSrc, pSrcDst, len); }
        static inline IppStatus Sub_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { return ippsSub_32fc_I(pSrc, pSrcDst, len); }
        static inline IppStatus Sub_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { return ippsSub_64fc_I(pSrc, pSrcDst, len); }

        static inline IppStatus DivC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(const double val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64f_I(val, reinterpret_cast<Ipp64f *>(pSrcDst), 2 * len)); }
        static inline IppStatus DivC_I(const float val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32f_I(val, reinterpret_cast<Ipp32f *>(pSrcDst), 2 * len)); }
        static inline IppStatus DivC_I(std::complex<float> val, std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32fc_I(*((Ipp32fc *)&val), (Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus DivC_I(std::complex<double> val, std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64fc_I(*((Ipp64fc *)&val), (Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus DivC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDivC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsDivC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp32fc *pSrc, Ipp32f val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_32f(reinterpret_cast<const Ipp32f *>(pSrc), val, reinterpret_cast<Ipp32f *>(pDst), 2 * len)); }
        static inline IppStatus DivC(const Ipp64fc *pSrc, Ipp64f val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_64f(reinterpret_cast<const Ipp64f *>(pSrc), val, reinterpret_cast<Ipp64f *>(pDst), 2 * len)); }
        static inline IppStatus DivC(const std::complex<float> *pSrc, std::complex<float> val, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsDivC_32fc((Ipp32fc *)pSrc, *((Ipp32fc *)&val), (Ipp32fc *)pDst, len)); }
        static inline IppStatus DivC(const std::complex<double> *pSrc, std::complex<double> val, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsDivC_64fc((Ipp64fc *)pSrc, *((Ipp64fc *)&val), (Ipp64fc *)pDst, len)); }

        static inline IppStatus DivCRev(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsDivCRev_16u(pSrc, val, pDst, len)); }
        static inline IppStatus DivCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDivCRev_32f(pSrc, val, pDst, len)); }

        static inline IppStatus DivCRev_I(Ipp16u val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsDivCRev_16u_I(val, pSrcDst, len)); }
        static inline IppStatus DivCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivCRev_32f_I(val, pSrcDst, len)); }

        static inline IppStatus Div(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDiv_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsDiv_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDiv_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDiv_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsDiv_32fc((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Div(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsDiv_64fc((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Abs(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsAbs_16s(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp32s *pSrc, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsAbs_32s(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsAbs_32f(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsAbs_64f(pSrc, pDst, len)); }

        static inline IppStatus Abs_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsAbs_16s_I(pSrcDst, len)); }
        static inline IppStatus Abs_I(Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsAbs_32s_I(pSrcDst, len)); }
        static inline IppStatus Abs_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAbs_32f_I(pSrcDst, len)); }
        static inline IppStatus Abs_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAbs_64f_I(pSrcDst, len)); }

        static inline IppStatus Sqr_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_32f_I(pSrcDst, len)); }
        static inline IppStatus Sqr_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_64f_I(pSrcDst, len)); }
        static inline IppStatus Sqr_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_32fc_I(pSrcDst, len)); }
        static inline IppStatus Sqr_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_64fc_I(pSrcDst, len)); }
        static inline IppStatus Sqr_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_32fc_I((Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus Sqr_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsSqr_64fc_I((Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus Sqr(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSqr_32f(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSqr_64f(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSqr_32fc(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSqr_64fc(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsSqr_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Sqr(const std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsSqr_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Sqrt_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_32f_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_64f_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc_I((Ipp32fc *)pSrcDst, len)); }
        static inline IppStatus Sqrt_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc_I((Ipp64fc *)pSrcDst, len)); }

        static inline IppStatus Sqrt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSqrt_32f(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSqrt_64f(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Sqrt(const std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        // Cubrt doesnt need wrapper
        // IppStatus ippsCubrt_32f(const Ipp32f* pSrc, Ipp32f* pDst, int len);

        static inline IppStatus Exp(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsExp_32f(pSrc, pDst, len)); }
        static inline IppStatus Exp(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsExp_64f(pSrc, pDst, len)); }

        static inline IppStatus Exp_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsExp_32f_I(pSrcDst, len)); }
        static inline IppStatus Exp_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsExp_64f_I(pSrcDst, len)); }

        static inline IppStatus Ln(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsLn_32f(pSrc, pDst, len)); }
        static inline IppStatus Ln(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsLn_64f(pSrc, pDst, len)); }
        static inline IppStatus Ln_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsLn_32f_I(pSrcDst, len)); }
        static inline IppStatus Ln_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsLn_64f_I(pSrcDst, len)); }

        static inline IppStatus SumLn(const Ipp32f *pSrc, int len, Ipp32f *pSum) { return OptionalAssertNoError(ippsSumLn_32f(pSrc, len, pSum)); }
        static inline IppStatus SumLn(const Ipp64f *pSrc, int len, Ipp64f *pSum) { return OptionalAssertNoError(ippsSumLn_64f(pSrc, len, pSum)); }
        static inline IppStatus SumLn(const Ipp32f *pSrc, int len, Ipp64f *pSum) { return OptionalAssertNoError(ippsSumLn_32f64f(pSrc, len, pSum)); }
        static inline IppStatus SumLn(const Ipp16s *pSrc, int len, Ipp32f *pSum) { return OptionalAssertNoError(ippsSumLn_16s32f(pSrc, len, pSum)); }

        static inline IppStatus Arctan(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsArctan_32f(pSrc, pDst, len)); }
        static inline IppStatus Arctan(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsArctan_64f(pSrc, pDst, len)); }

        static inline IppStatus Arctan_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsArctan_32f_I(pSrcDst, len)); }
        static inline IppStatus Arctan_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsArctan_64f_I(pSrcDst, len)); }

        static inline IppStatus Normalize(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32f(pSrc, pDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64f(pSrc, pDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32fc vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32fc(pSrc, pDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64fc vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64fc(pSrc, pDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize(const std::complex<float> *pSrc, std::complex<float> *pDst, int len, std::complex<float> vSub, float vDiv) { return OptionalAssertNoError(ippsNormalize_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len, *((Ipp32fc *)&vSub), vDiv)); }
        static inline IppStatus Normalize(const std::complex<double> *pSrc, std::complex<double> *pDst, int len, std::complex<double> vSub, double vDiv) { return OptionalAssertNoError(ippsNormalize_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len, *((Ipp64fc *)&vSub), vDiv)); }

        static inline IppStatus Normalize_I(Ipp32f *pSrcDst, int len, Ipp32f vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32f_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp64f *pSrcDst, int len, Ipp64f vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64f_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp32fc *pSrcDst, int len, Ipp32fc vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32fc_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp64fc *pSrcDst, int len, Ipp64fc vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64fc_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(std::complex<float> *pSrcDst, int len, std::complex<float> vSub, float vDiv) { return OptionalAssertNoError(ippsNormalize_32fc_I((Ipp32fc *)pSrcDst, len, *((Ipp32fc *)&vSub), vDiv)); }
        static inline IppStatus Normalize_I(std::complex<double> *pSrcDst, int len, std::complex<double> vSub, double vDiv) { return OptionalAssertNoError(ippsNormalize_64fc_I((Ipp64fc *)pSrcDst, len, *((Ipp64fc *)&vSub), vDiv)); }
    }
}
