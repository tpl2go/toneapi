#include <ippcore.h>
#include <ippvm.h>
#include <complex>
#include "tipp_error.hpp"
#include <stdexcept>

namespace tipp
{

    namespace signal
    {
        /* Essentials Arthimetic */

        static inline IppStatus AddC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsAddC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsAddC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus AddC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsAddC_64fc(pSrc, val, pDst, len)); }

        static inline IppStatus AddC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus AddC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddC_64fc_I(val, pSrcDst, len)); }

        static inline IppStatus AddProductC(const Ipp32f *pSrc, const Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProductC_32f(pSrc, val, pSrcDst, len)); }
        static inline IppStatus AddProductC(const Ipp64f *pSrc, const Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProductC_64f(pSrc, val, pSrcDst, len)); }

        static inline IppStatus AddProduct(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_32f(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_64f(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_32fc(pSrc1, pSrc2, pSrcDst, len)); }
        static inline IppStatus AddProduct(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAddProduct_64fc(pSrc1, pSrc2, pSrcDst, len)); }

        static inline IppStatus Add_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_64fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp16s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_16s32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Add_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsAdd_32u_I(pSrc, pSrcDst, len)); }

        static inline IppStatus Add(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsAdd_16s(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsAdd_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsAdd_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsAdd_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsAdd_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsAdd_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsAdd_32u(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus MulC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMulC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMulC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMulC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus MulC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMulC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus MulC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus MulC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMulC_64fc_I(val, pSrcDst, len)); }

        static inline IppStatus Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsMul_16s(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMul_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMul_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMul_64fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsMul_8u16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp32fc *pSrc2, const Ipp32f *pSrc1, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Mul(const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMul_16s32f(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Mul_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32fc *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp64fc *pSrc, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_64fc_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Mul_I(const Ipp32f *pSrc, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsMul_32f32fc_I(pSrc, pSrcDst, len)); }

        static inline IppStatus SubCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_32f(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_64f(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubCRev(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc(pSrc, val, pDst, len)); }

        static inline IppStatus SubCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_32f_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_64f_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubCRev_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubCRev_64fc_I(val, pSrcDst, len)); }

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

        static inline IppStatus SubC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSubC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSubC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSubC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus SubC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSubC_64fc(pSrc, val, pDst, len)); }

        static inline IppStatus SubC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus SubC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSubC_64fc_I(val, pSrcDst, len)); }

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

        static inline IppStatus DivCRev(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsDivCRev_16u(pSrc, val, pDst, len)); }
        static inline IppStatus DivCRev(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDivCRev_32f(pSrc, val, pDst, len)); }

        static inline IppStatus DivCRev_I(Ipp16u val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsDivCRev_16u_I(val, pSrcDst, len)); }
        static inline IppStatus DivCRev_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivCRev_32f_I(val, pSrcDst, len)); }

        static inline IppStatus DivC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32f_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64f_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32fc_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64fc_I(val, pSrcDst, len)); }
        static inline IppStatus DivC_I(const double val, Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_64f_I(val, reinterpret_cast<Ipp64f *>(pSrcDst), 2 * len)); }
        static inline IppStatus DivC_I(const float val, Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsDivC_32f_I(val, reinterpret_cast<Ipp32f *>(pSrcDst), 2 * len)); }

        static inline IppStatus DivC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDivC_32f(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsDivC_64f(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_32fc(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_64fc(pSrc, val, pDst, len)); }
        static inline IppStatus DivC(const Ipp32fc *pSrc, Ipp32f val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_32f(reinterpret_cast<const Ipp32f *>(pSrc), val, reinterpret_cast<Ipp32f *>(pDst), 2 * len)); }
        static inline IppStatus DivC(const Ipp64fc *pSrc, Ipp64f val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDivC_64f(reinterpret_cast<const Ipp64f *>(pSrc), val, reinterpret_cast<Ipp64f *>(pDst), 2 * len)); }

        static inline IppStatus Div(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsDiv_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsDiv_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsDiv_32fc(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Div(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsDiv_64fc(pSrc1, pSrc2, pDst, len)); }

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

        static inline IppStatus Sqr(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSqr_32f(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSqr_64f(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSqr_32fc(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSqr_64fc(pSrc, pDst, len)); }

        static inline IppStatus Sqrt_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_32f_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_64f_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc_I(pSrcDst, len)); }
        static inline IppStatus Sqrt_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc_I(pSrcDst, len)); }

        static inline IppStatus Sqrt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSqrt_32f(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSqrt_64f(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSqrt_32fc(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSqrt_64fc(pSrc, pDst, len)); }

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

        static inline IppStatus Normalize_I(Ipp32f *pSrcDst, int len, Ipp32f vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32f_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp64f *pSrcDst, int len, Ipp64f vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64f_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp32fc *pSrcDst, int len, Ipp32fc vSub, Ipp32f vDiv) { return OptionalAssertNoError(ippsNormalize_32fc_I(pSrcDst, len, vSub, vDiv)); }
        static inline IppStatus Normalize_I(Ipp64fc *pSrcDst, int len, Ipp64fc vSub, Ipp64f vDiv) { return OptionalAssertNoError(ippsNormalize_64fc_I(pSrcDst, len, vSub, vDiv)); }

        static inline IppStatus Goertz(const Ipp32f *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { return OptionalAssertNoError(ippsGoertz_32f(pSrc, len, pVal, rFreq)); }
        static inline IppStatus Goertz(const Ipp64f *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { return OptionalAssertNoError(ippsGoertz_64f(pSrc, len, pVal, rFreq)); }
        static inline IppStatus Goertz(const Ipp32fc *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { return OptionalAssertNoError(ippsGoertz_32fc(pSrc, len, pVal, rFreq)); }
        static inline IppStatus Goertz(const Ipp64fc *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { return OptionalAssertNoError(ippsGoertz_64fc(pSrc, len, pVal, rFreq)); }
        static inline IppStatus Goertz_Sfs(const Ipp16s *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { return OptionalAssertNoError(ippsGoertz_16s_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }
        static inline IppStatus Goertz_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { return OptionalAssertNoError(ippsGoertz_16sc_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }

        /* Essential Convert */

        static inline IppStatus CplxToReal(const Ipp16sc *pSrc, Ipp16s *pDstRe, Ipp16s *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_16sc(pSrc, pDstRe, pDstIm, len)); }
        static inline IppStatus CplxToReal(const Ipp32fc *pSrc, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_32fc(pSrc, pDstRe, pDstIm, len)); }
        static inline IppStatus CplxToReal(const Ipp64fc *pSrc, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsCplxToReal_64fc(pSrc, pDstRe, pDstIm, len)); }

        static inline IppStatus SortAscend_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_8u_I(pSrcDst, len)); }
        static inline IppStatus SortAscend_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_16u_I(pSrcDst, len)); }
        static inline IppStatus SortAscend_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_16s_I(pSrcDst, len)); }
        static inline IppStatus SortAscend_I(Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_32s_I(pSrcDst, len)); }
        static inline IppStatus SortAscend_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_32f_I(pSrcDst, len)); }
        static inline IppStatus SortAscend_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortAscend_64f_I(pSrcDst, len)); }

        static inline IppStatus SortDescend_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_8u_I(pSrcDst, len)); }
        static inline IppStatus SortDescend_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_16u_I(pSrcDst, len)); }
        static inline IppStatus SortDescend_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_16s_I(pSrcDst, len)); }
        static inline IppStatus SortDescend_I(Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_32s_I(pSrcDst, len)); }
        static inline IppStatus SortDescend_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_32f_I(pSrcDst, len)); }
        static inline IppStatus SortDescend_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsSortDescend_64f_I(pSrcDst, len)); }

        static inline IppStatus SortIndexAscend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_8u_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexAscend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_16u_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexAscend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_16s_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexAscend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_32s_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexAscend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_32f_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexAscend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexAscend_64f_I(pSrcDst, pDstIdx, len)); }

        static inline IppStatus SortIndexDescend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_8u_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexDescend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_16u_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexDescend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_16s_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexDescend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_32s_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexDescend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_32f_I(pSrcDst, pDstIdx, len)); }
        static inline IppStatus SortIndexDescend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { return OptionalAssertNoError(ippsSortIndexDescend_64f_I(pSrcDst, pDstIdx, len)); }

        template <typename T>
        static inline IppStatus SortRadixGetBufferSize(int len, int *pBuffferSize) { throw std::runtime_error("Unsupported data type for SortRadixGetBufferSize"); };
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp8u, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp16u, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32u, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64u, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp16s, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32s, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64s, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp32f, pBuffferSize)); }
        template <>
        static inline IppStatus SortRadixGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { return OptionalAssertNoError(ippsSortRadixGetBufferSize(len, IppDataType::ipp64f, pBuffferSize)); }

        static inline IppStatus SortRadixAscend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64f_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32f_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_16u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_16s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_8u_I(pSrcDst, len, pBuffer)); }

        static inline IppStatus SortRadixDescend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64f_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32f_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_16u_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_16s_I(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_8u_I(pSrcDst, len, pBuffer)); }

        template <typename T>
        class SortRadix_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadix_Engine() = default;

            explicit SortRadix_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadixEngine not initialized");
            }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixGetBufferSize<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised;
                SortRadixAscend_I(pSrcDst, m_len, m_buffer.data());
            }
            void sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised;
                SortRadixDescend_I(pSrcDst, m_len, m_buffer.data());
            }
        };

        template <typename T>
        static inline IppStatus SortRadixGetBufferSize_L(int len, long long *pBuffferSize) { throw std::runtime_error("SortRadixGetBufferSize_L not implemented for this type"); };

        template <>
        static inline IppStatus SortRadixGetBufferSize_L<Ipp64u>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64u, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixGetBufferSize_L<Ipp32s>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32s, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixGetBufferSize_L<Ipp64s>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64s, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixGetBufferSize_L<Ipp32f>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32f, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixGetBufferSize_L<Ipp64f>(int len, long long *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64f, pBuffferSize); }

        static inline IppStatus SortRadixAscend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64f_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64s_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_64u_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32f_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixAscend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixAscend_32s_I_L(pSrcDst, len, pBuffer)); }

        static inline IppStatus SortRadixDescend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64f_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64s_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_64u_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32f_I_L(pSrcDst, len, pBuffer)); }
        static inline IppStatus SortRadixDescend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsSortRadixDescend_32s_I_L(pSrcDst, len, pBuffer)); }

        template <typename T>
        class SortRadix_L_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadix_L_Engine() = default;

            explicit SortRadix_L_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadix_L_Engine not initialized");
            }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixGetBufferSize_L<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised();
                SortRadixAscend_I_L(pSrcDst, m_len, m_buffer.data());
            }
            void sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised();
                SortRadixDescend_I_L(pSrcDst, m_len, m_buffer.data());
            }
        };

        template <typename T>
        static inline IppStatus SortRadixIndexGetBufferSize(int len, int *pBuffferSize) { throw std::runtime_error("SortRadixIndexGetBufferSize not implemented for this type"); };
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp8u, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16u, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32u, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64u, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16s, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32s, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64s, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32f, pBuffferSize); }
        template <>
        static inline IppStatus SortRadixIndexGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64f, pBuffferSize); }

        template <typename T>
        class SortRadixIndex_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadixIndex_Engine() = default;

            explicit SortRadixIndex_Engine(int len) { initialise(len); }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixIndexGetBufferSize<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadixIndexEngine not initialized");
            }

            IppStatus sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(SortRadixIndexAscend_I(pSrcDst, m_len, m_buffer.data()));
            }
            IppStatus sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(SortRadixIndexDescend_I(pSrcDst, m_len, m_buffer.data()));
            }
        };

        //   ippsTopKGetBufferSize
        //   ippsTopKInit_32f
        //   ippsTopKInit_32s
        //   ippsTopK_32f
        //   ippsTopK_32s

        static inline IppStatus Conj(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsConj_16sc(pSrc, pDst, len)); }
        static inline IppStatus Conj(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsConj_32fc(pSrc, pDst, len)); }
        static inline IppStatus Conj(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsConj_64fc(pSrc, pDst, len)); }

        static inline IppStatus Conj_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_16sc_I(pSrcDst, len)); }
        static inline IppStatus Conj_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_32fc_I(pSrcDst, len)); }
        static inline IppStatus Conj_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsConj_64fc_I(pSrcDst, len)); }

        static inline IppStatus ConjFlip(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_16sc(pSrc, pDst, len)); }
        static inline IppStatus ConjFlip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_32fc(pSrc, pDst, len)); }
        static inline IppStatus ConjFlip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsConjFlip_64fc(pSrc, pDst, len)); }

        static inline IppStatus Magnitude(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus Magnitude(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus Magnitude(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_32fc(pSrc, pDst, len)); }
        static inline IppStatus Magnitude(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_64fc(pSrc, pDst, len)); }
        static inline IppStatus Magnitude(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_16s32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus Magnitude(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMagnitude_16sc32f(pSrc, pDst, len)); }

        static inline IppStatus Phase(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPhase_64fc(pSrc, pDst, len)); }
        static inline IppStatus Phase(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_32fc(pSrc, pDst, len)); }
        static inline IppStatus Phase(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_16sc32f(pSrc, pDst, len)); }
        static inline IppStatus Phase(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPhase_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus Phase(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus Phase(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPhase_16s32f(pSrcRe, pSrcIm, pDst, len)); }

        static inline IppStatus PowerSpectr(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_64fc(pSrc, pDst, len)); }
        static inline IppStatus PowerSpectr(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_32fc(pSrc, pDst, len)); }
        static inline IppStatus PowerSpectr(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus PowerSpectr(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus PowerSpectr(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_16s32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus PowerSpectr(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsPowerSpectr_16sc32f(pSrc, pDst, len)); }

        static inline IppStatus RealToCplx(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_16s(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus RealToCplx(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline IppStatus RealToCplx(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsRealToCplx_64f(pSrcRe, pSrcIm, pDst, len)); }

        static inline IppStatus Real(const Ipp16sc *pSrc, Ipp16s *pDstRe, int len) { return OptionalAssertNoError(ippsReal_16sc(pSrc, pDstRe, len)); }
        static inline IppStatus Real(const Ipp32fc *pSrc, Ipp32f *pDstRe, int len) { return OptionalAssertNoError(ippsReal_32fc(pSrc, pDstRe, len)); }
        static inline IppStatus Real(const Ipp64fc *pSrc, Ipp64f *pDstRe, int len) { return OptionalAssertNoError(ippsReal_64fc(pSrc, pDstRe, len)); }

        static inline IppStatus Imag(const Ipp16sc *pSrc, Ipp16s *pDstIm, int len) { return OptionalAssertNoError(ippsImag_16sc(pSrc, pDstIm, len)); }
        static inline IppStatus Imag(const Ipp32fc *pSrc, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsImag_32fc(pSrc, pDstIm, len)); }
        static inline IppStatus Imag(const Ipp64fc *pSrc, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsImag_64fc(pSrc, pDstIm, len)); }

        static inline IppStatus Threshold_LTAbsVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_64f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_16s(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s level, Ipp32s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32s(pSrc, pDst, len, level, value)); }

        static inline IppStatus Threshold_LTAbsVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_64f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_16s_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTAbsVal_I(Ipp32s *pSrcDst, int len, Ipp32s level, Ipp32s value) { return OptionalAssertNoError(ippsThreshold_LTAbsVal_32s_I(pSrcDst, len, level, value)); }

        static inline IppStatus Threshold_LTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTVal_16s(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTVal_32f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTVal_64f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_LTVal_16sc(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_32fc(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_64fc(pSrc, pDst, len, level, value)); }

        static inline IppStatus Threshold_GTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_GTVal_16s(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_GTVal_32f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_GTVal_64f(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_GTVal_16sc(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_32fc(pSrc, pDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_64fc(pSrc, pDst, len, level, value)); }

        static inline IppStatus Threshold_LTValGTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_16s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline IppStatus Threshold_LTValGTVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline IppStatus Threshold_LTValGTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32f(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }

        static inline IppStatus Threshold_LTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_LTVal_16s_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_LTVal_32f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_LTVal_64f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_LTVal_16sc_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_32fc_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_LTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_LTVal_64fc_I(pSrcDst, len, level, value)); }

        static inline IppStatus Threshold_GTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { return OptionalAssertNoError(ippsThreshold_GTVal_16s_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { return OptionalAssertNoError(ippsThreshold_GTVal_32f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { return OptionalAssertNoError(ippsThreshold_GTVal_64f_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { return OptionalAssertNoError(ippsThreshold_GTVal_16sc_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_32fc_I(pSrcDst, len, level, value)); }
        static inline IppStatus Threshold_GTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { return OptionalAssertNoError(ippsThreshold_GTVal_64fc_I(pSrcDst, len, level, value)); }

        static inline IppStatus Threshold_LTValGTVal_I(Ipp16s *pSrcDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_16s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline IppStatus Threshold_LTValGTVal_I(Ipp32s *pSrcDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline IppStatus Threshold_LTValGTVal_I(Ipp32f *pSrcDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_32f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline IppStatus Threshold_LTValGTVal_I(Ipp64f *pSrcDst, int len, Ipp64f levelLT, Ipp64f valueLT, Ipp64f levelGT, Ipp64f valueGT) { return OptionalAssertNoError(ippsThreshold_LTValGTVal_64f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }

        static inline IppStatus CartToPolar(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_32f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }
        static inline IppStatus CartToPolar(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_64f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }

        static inline IppStatus CartToPolar(const Ipp32fc *pSrc, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_32fc(pSrc, pDstMagn, pDstPhase, len)); }
        static inline IppStatus CartToPolar(const Ipp64fc *pSrc, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { return OptionalAssertNoError(ippsCartToPolar_64fc(pSrc, pDstMagn, pDstPhase, len)); }

        static inline IppStatus PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { return OptionalAssertNoError(ippsPolarToCart_32f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
        static inline IppStatus PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { return OptionalAssertNoError(ippsPolarToCart_64f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
        static inline IppStatus PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsPolarToCart_32fc(pSrcMagn, pSrcPhase, pDst, len)); }
        static inline IppStatus PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsPolarToCart_64fc(pSrcMagn, pSrcPhase, pDst, len)); }

        static inline IppStatus MaxOrder(const Ipp16s *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_16s(pSrc, len, pOrder)); }
        static inline IppStatus MaxOrder(const Ipp32s *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_32s(pSrc, len, pOrder)); }
        static inline IppStatus MaxOrder(const Ipp32f *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_32f(pSrc, len, pOrder)); }
        static inline IppStatus MaxOrder(const Ipp64f *pSrc, int len, int *pOrder) { return OptionalAssertNoError(ippsMaxOrder_64f(pSrc, len, pOrder)); }

        static inline IppStatus Flip(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsFlip_8u(pSrc, pDst, len)); }
        static inline IppStatus Flip(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsFlip_16u(pSrc, pDst, len)); }
        static inline IppStatus Flip(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsFlip_32f(pSrc, pDst, len)); }
        static inline IppStatus Flip(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsFlip_64f(pSrc, pDst, len)); }
        static inline IppStatus Flip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsFlip_32fc(pSrc, pDst, len)); }
        static inline IppStatus Flip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsFlip_64fc(pSrc, pDst, len)); }

        static inline IppStatus Flip_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_16u_I(pSrcDst, len)); }
        static inline IppStatus Flip_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_8u_I(pSrcDst, len)); }
        static inline IppStatus Flip_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_32f_I(pSrcDst, len)); }
        static inline IppStatus Flip_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_64f_I(pSrcDst, len)); }
        static inline IppStatus Flip_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_32fc_I(pSrcDst, len)); }
        static inline IppStatus Flip_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsFlip_64fc_I(pSrcDst, len)); }

        static inline IppStatus SwapBytes(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_16u(pSrc, pDst, len)); }
        static inline IppStatus SwapBytes(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_24u(pSrc, pDst, len)); }
        static inline IppStatus SwapBytes(const Ipp32u *pSrc, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_32u(pSrc, pDst, len)); }
        static inline IppStatus SwapBytes(const Ipp64u *pSrc, Ipp64u *pDst, int len) { return OptionalAssertNoError(ippsSwapBytes_64u(pSrc, pDst, len)); }
        static inline IppStatus SwapBytes_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_16u_I(pSrcDst, len)); }
        static inline IppStatus SwapBytes_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_24u_I(pSrcDst, len)); }
        static inline IppStatus SwapBytes_I(Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_32u_I(pSrcDst, len)); }
        static inline IppStatus SwapBytes_I(Ipp64u *pSrcDst, int len) { return OptionalAssertNoError(ippsSwapBytes_64u_I(pSrcDst, len)); }

        /* Essential Logical */
        static inline IppStatus AndC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsAndC_8u(pSrc, val, pDst, len)); }
        static inline IppStatus AndC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsAndC_16u(pSrc, val, pDst, len)); }
        static inline IppStatus AndC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsAndC_32u(pSrc, val, pDst, len)); }

        static inline IppStatus AndC_I(Ipp8u val, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsAndC_8u_I(val, pSrcDst, len)); }
        static inline IppStatus AndC_I(Ipp16u val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsAndC_16u_I(val, pSrcDst, len)); }
        static inline IppStatus AndC_I(Ipp32u val, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsAndC_32u_I(val, pSrcDst, len)); }

        static inline IppStatus And(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsAnd_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus And(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsAnd_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus And(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsAnd_32u(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus And_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsAnd_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus And_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsAnd_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus And_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsAnd_32u_I(pSrc, pSrcDst, len)); }

        static inline IppStatus Or(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsOr_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Or(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsOr_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Or(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsOr_32u(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Or_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsOr_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Or_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsOr_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus Or_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsOr_32u_I(pSrc, pSrcDst, len)); }

        static inline IppStatus OrC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsOrC_8u(pSrc, val, pDst, len)); }
        static inline IppStatus OrC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsOrC_16u(pSrc, val, pDst, len)); }
        static inline IppStatus OrC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsOrC_32u(pSrc, val, pDst, len)); }

        static inline IppStatus OrC_I(Ipp8u val, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsOrC_8u_I(val, pSrcDst, len)); }
        static inline IppStatus OrC_I(Ipp16u val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsOrC_16u_I(val, pSrcDst, len)); }
        static inline IppStatus OrC_I(Ipp32u val, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsOrC_32u_I(val, pSrcDst, len)); }

        static inline IppStatus XorC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsXorC_8u(pSrc, val, pDst, len)); }
        static inline IppStatus XorC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsXorC_16u(pSrc, val, pDst, len)); }
        static inline IppStatus XorC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsXorC_32u(pSrc, val, pDst, len)); }
        static inline IppStatus XorC(Ipp8u val, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsXorC_8u_I(val, pSrcDst, len)); }
        static inline IppStatus XorC(Ipp16u val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsXorC_16u_I(val, pSrcDst, len)); }
        static inline IppStatus XorC(Ipp32u val, Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsXorC_32u_I(val, pSrcDst, len)); }

        static inline IppStatus Not(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsNot_8u(pSrc, pDst, len)); }
        static inline IppStatus Not(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsNot_16u(pSrc, pDst, len)); }
        static inline IppStatus Not(const Ipp32u *pSrc, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsNot_32u(pSrc, pDst, len)); }

        static inline IppStatus Not_I(Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsNot_8u_I(pSrcDst, len)); }
        static inline IppStatus Not_I(Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsNot_16u_I(pSrcDst, len)); }
        static inline IppStatus Not_I(Ipp32u *pSrcDst, int len) { return OptionalAssertNoError(ippsNot_32u_I(pSrcDst, len)); }

        static inline IppStatus LShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsLShiftC_8u(pSrc, val, pDst, len)); }
        static inline IppStatus LShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsLShiftC_16s(pSrc, val, pDst, len)); }
        static inline IppStatus LShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsLShiftC_16u(pSrc, val, pDst, len)); }
        static inline IppStatus LShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsLShiftC_32s(pSrc, val, pDst, len)); }
        static inline IppStatus LShiftC_I(int val, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsLShiftC_8u_I(val, pSrcDst, len)); }
        static inline IppStatus LShiftC_I(int val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsLShiftC_16u_I(val, pSrcDst, len)); }
        static inline IppStatus LShiftC_I(int val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsLShiftC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus LShiftC_I(int val, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsLShiftC_32s_I(val, pSrcDst, len)); }

        static inline IppStatus RShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsRShiftC_8u(pSrc, val, pDst, len)); }
        static inline IppStatus RShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsRShiftC_16s(pSrc, val, pDst, len)); }
        static inline IppStatus RShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsRShiftC_16u(pSrc, val, pDst, len)); }
        static inline IppStatus RShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsRShiftC_32s(pSrc, val, pDst, len)); }
        static inline IppStatus RShiftC(int val, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsRShiftC_8u_I(val, pSrcDst, len)); }
        static inline IppStatus RShiftC(int val, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsRShiftC_16u_I(val, pSrcDst, len)); }
        static inline IppStatus RShiftC(int val, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsRShiftC_16s_I(val, pSrcDst, len)); }
        static inline IppStatus RShiftC(int val, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsRShiftC_32s_I(val, pSrcDst, len)); }

        /* Essential Sampling */
        static inline IppStatus SampleDown(const Ipp16s *pSrc, int srcLen, Ipp16s *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_16s(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleDown(const Ipp32f *pSrc, int srcLen, Ipp32f *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_32f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleDown(const Ipp64f *pSrc, int srcLen, Ipp64f *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_64f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleDown(const Ipp16sc *pSrc, int srcLen, Ipp16sc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_16sc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleDown(const Ipp32fc *pSrc, int srcLen, Ipp32fc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_32fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleDown(const Ipp64fc *pSrc, int srcLen, Ipp64fc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleDown_64fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }

        static inline IppStatus SampleUp(const Ipp16s *pSrc, int srcLen, Ipp16s *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_16s(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleUp(const Ipp32f *pSrc, int srcLen, Ipp32f *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_32f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleUp(const Ipp64f *pSrc, int srcLen, Ipp64f *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_64f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleUp(const Ipp16sc *pSrc, int srcLen, Ipp16sc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_16sc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleUp(const Ipp32fc *pSrc, int srcLen, Ipp32fc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_32fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline IppStatus SampleUp(const Ipp64fc *pSrc, int srcLen, Ipp64fc *pDst, int *pDstLen, int factor, int *pPhase) { return OptionalAssertNoError(ippsSampleUp_64fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }

        /* Essential Statistical */
        static inline IppStatus Sum(const Ipp32f *pSrc, int len, Ipp32f *pSum) { return OptionalAssertNoError(ippsSum_32f(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline IppStatus Sum(const Ipp32fc *pSrc, int len, Ipp32fc *pSum) { return OptionalAssertNoError(ippsSum_32fc(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline IppStatus Sum(const Ipp64f *pSrc, int len, Ipp64f *pSum) { return OptionalAssertNoError(ippsSum_64f(pSrc, len, pSum)); }
        static inline IppStatus Sum(const Ipp64fc *pSrc, int len, Ipp64fc *pSum) { return OptionalAssertNoError(ippsSum_64fc(pSrc, len, pSum)); }

        static inline IppStatus Sum_Sfs(const Ipp16s *pSrc, int len, Ipp16s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp32s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16s32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16sc_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline IppStatus Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp32sc *pSum, int scaleFactor) { return OptionalAssertNoError(ippsSum_16sc32sc_Sfs(pSrc, len, pSum, scaleFactor)); }

        static inline IppStatus MaxAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_16s(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_32s(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_32f(pSrc, len, pMaxAbs, pIndx)); }
        static inline IppStatus MaxAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs, int *pIndx) { return OptionalAssertNoError(ippsMaxAbsIndx_64f(pSrc, len, pMaxAbs, pIndx)); }

        static inline IppStatus MaxAbs(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_16s(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_32s(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_32f(pSrc, len, pMaxAbs)); }
        static inline IppStatus MaxAbs(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs) { return OptionalAssertNoError(ippsMaxAbs_64f(pSrc, len, pMaxAbs)); }

        static inline IppStatus MaxEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MinEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMaxEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MaxEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { return OptionalAssertNoError(ippsMaxEvery_64f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMinEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MinEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { return OptionalAssertNoError(ippsMinEvery_64f_I(pSrc, pSrcDst, len)); }

        static inline IppStatus MaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_16s(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_32s(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_32f(pSrc, len, pMax, pIndx)); }
        static inline IppStatus MaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMax, int *pIndx) { return OptionalAssertNoError(ippsMaxIndx_64f(pSrc, len, pMax, pIndx)); }

        static inline IppStatus Max(const Ipp16s *pSrc, int len, Ipp16s *pMax) { return OptionalAssertNoError(ippsMax_16s(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp32s *pSrc, int len, Ipp32s *pMax) { return OptionalAssertNoError(ippsMax_32s(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp32f *pSrc, int len, Ipp32f *pMax) { return OptionalAssertNoError(ippsMax_32f(pSrc, len, pMax)); }
        static inline IppStatus Max(const Ipp64f *pSrc, int len, Ipp64f *pMax) { return OptionalAssertNoError(ippsMax_64f(pSrc, len, pMax)); }

        static inline IppStatus MeanStdDev(const Ipp32f *pSrc, int len, Ipp32f *pMean, Ipp32f *pStdDev) { return OptionalAssertNoError(ippsMeanStdDev_32f(pSrc, len, pMean, pStdDev, ippAlgHintAccurate)); }
        static inline IppStatus MeanStdDev(const Ipp64f *pSrc, int len, Ipp64f *pMean, Ipp64f *pStdDev) { return OptionalAssertNoError(ippsMeanStdDev_64f(pSrc, len, pMean, pStdDev)); }

        static inline IppStatus Mean(const Ipp32f *pSrc, int len, Ipp32f *pMean) { return OptionalAssertNoError(ippsMean_32f(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline IppStatus Mean(const Ipp32fc *pSrc, int len, Ipp32fc *pMean) { return OptionalAssertNoError(ippsMean_32fc(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline IppStatus Mean(const Ipp64f *pSrc, int len, Ipp64f *pMean) { return OptionalAssertNoError(ippsMean_64f(pSrc, len, pMean)); }
        static inline IppStatus Mean(const Ipp64fc *pSrc, int len, Ipp64fc *pMean) { return OptionalAssertNoError(ippsMean_64fc(pSrc, len, pMean)); }

        static inline IppStatus MinAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_16s(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_32s(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_32f(pSrc, len, pMinAbs, pIndx)); }
        static inline IppStatus MinAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs, int *pIndx) { return OptionalAssertNoError(ippsMinAbsIndx_64f(pSrc, len, pMinAbs, pIndx)); }

        static inline IppStatus MinAbs(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_16s(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_32s(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_32f(pSrc, len, pMinAbs)); }
        static inline IppStatus MinAbs(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs) { return OptionalAssertNoError(ippsMinAbs_64f(pSrc, len, pMinAbs)); }

        static inline IppStatus MinIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_16s(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_32s(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_32f(pSrc, len, pMin, pIndx)); }
        static inline IppStatus MinIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pIndx) { return OptionalAssertNoError(ippsMinIndx_64f(pSrc, len, pMin, pIndx)); }

        static inline IppStatus MinMaxIndx(const Ipp8u *pSrc, int len, Ipp8u *pMin, int *pMinIndx, Ipp8u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_8u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp16u *pSrc, int len, Ipp16u *pMin, int *pMinIndx, Ipp16u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_16u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pMinIndx, Ipp16s *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_16s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32u *pSrc, int len, Ipp32u *pMin, int *pMinIndx, Ipp32u *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pMinIndx, Ipp32s *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pMinIndx, Ipp32f *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_32f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline IppStatus MinMaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pMinIndx, Ipp64f *pMax, int *pMaxIndx) { return OptionalAssertNoError(ippsMinMaxIndx_64f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }

        static inline IppStatus MinMax(const Ipp8u *pSrc, int len, Ipp8u *pMin, Ipp8u *pMax) { return OptionalAssertNoError(ippsMinMax_8u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp16u *pSrc, int len, Ipp16u *pMin, Ipp16u *pMax) { return OptionalAssertNoError(ippsMinMax_16u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp16s *pSrc, int len, Ipp16s *pMin, Ipp16s *pMax) { return OptionalAssertNoError(ippsMinMax_16s(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32u *pSrc, int len, Ipp32u *pMin, Ipp32u *pMax) { return OptionalAssertNoError(ippsMinMax_32u(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32s *pSrc, int len, Ipp32s *pMin, Ipp32s *pMax) { return OptionalAssertNoError(ippsMinMax_32s(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp32f *pSrc, int len, Ipp32f *pMin, Ipp32f *pMax) { return OptionalAssertNoError(ippsMinMax_32f(pSrc, len, pMin, pMax)); }
        static inline IppStatus MinMax(const Ipp64f *pSrc, int len, Ipp64f *pMin, Ipp64f *pMax) { return OptionalAssertNoError(ippsMinMax_64f(pSrc, len, pMin, pMax)); }

        static inline IppStatus Min(const Ipp16s *pSrc, int len, Ipp16s *pMin) { return OptionalAssertNoError(ippsMin_16s(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp32s *pSrc, int len, Ipp32s *pMin) { return OptionalAssertNoError(ippsMin_32s(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp32f *pSrc, int len, Ipp32f *pMin) { return OptionalAssertNoError(ippsMin_32f(pSrc, len, pMin)); }
        static inline IppStatus Min(const Ipp64f *pSrc, int len, Ipp64f *pMin) { return OptionalAssertNoError(ippsMin_64f(pSrc, len, pMin)); }

        static inline IppStatus ReplaceNAN(Ipp32f *pSrcDst, int len, Ipp32f value) { return OptionalAssertNoError(ippsReplaceNAN_32f_I(pSrcDst, len, value)); }
        static inline IppStatus ReplaceNAN(Ipp64f *pSrcDst, int len, Ipp64f value) { return OptionalAssertNoError(ippsReplaceNAN_64f_I(pSrcDst, len, value)); }

        static inline IppStatus NormDiff_Inf(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_32fc32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_Inf(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_Inf_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L1(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L1_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline IppStatus NormDiff_L2(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNormDiff_L2_64fc64f(pSrc1, pSrc2, len, pNorm)); }

        static inline IppStatus Norm_Inf(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp32fc *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_32fc32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_Inf(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_Inf_64fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_32fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L1(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L1_64fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_16s32f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_32fc64f(pSrc, len, pNorm)); }
        static inline IppStatus Norm_L2(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { return OptionalAssertNoError(ippsNorm_L2_64fc64f(pSrc, len, pNorm)); }

        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pDp) { return OptionalAssertNoError(ippsDotProd_32f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { return OptionalAssertNoError(ippsDotProd_32fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp64f *pDp) { return OptionalAssertNoError(ippsDotProd_32f64f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_32f32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pDp) { return OptionalAssertNoError(ippsDotProd_64f(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp64f *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { return OptionalAssertNoError(ippsDotProd_64f64fc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp64s *pDp) { return OptionalAssertNoError(ippsDotProd_16s64s(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16sc *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { return OptionalAssertNoError(ippsDotProd_16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { return OptionalAssertNoError(ippsDotProd_16s16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline IppStatus DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pDp) { return OptionalAssertNoError(ippsDotProd_16s32f(pSrc1, pSrc2, len, pDp)); }

        static inline IppStatus StdDev(const Ipp32f *pSrc, int len, Ipp32f *pStdDev) { return OptionalAssertNoError(ippsStdDev_32f(pSrc, len, pStdDev, ippAlgHintAccurate)); }
        static inline IppStatus StdDev(const Ipp64f *pSrc, int len, Ipp64f *pStdDev) { return OptionalAssertNoError(ippsStdDev_64f(pSrc, len, pStdDev)); }

        /* Essential Filter */
        static inline IppStatus SumWindow(const Ipp8u *pSrc, Ipp32f *pDst, int len, int maskSize) { return OptionalAssertNoError(ippsSumWindow_8u32f(pSrc, pDst, len, maskSize)); }
        static inline IppStatus SumWindow(const Ipp16s *pSrc, Ipp32f *pDst, int len, int maskSize) { return OptionalAssertNoError(ippsSumWindow_16s32f(pSrc, pDst, len, maskSize)); }

        static inline IppStatus FIRSR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRSR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRSR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRSR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRSR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRSR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRSR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        template <typename T>
        static inline IppStatus FIRSRGetSize(int tapsLen, int *pSpecSize, int *pBufSize);
        template <>
        static inline IppStatus FIRSRGetSize<Ipp32f>(int tapsLen, int *pSpecSize, int *pBufSize) { return OptionalAssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp32f, pSpecSize, pBufSize)); }
        template <>
        static inline IppStatus FIRSRGetSize<Ipp32fc>(int tapsLen, int *pSpecSize, int *pBufSize) { return OptionalAssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp32fc, pSpecSize, pBufSize)); }
        template <>
        static inline IppStatus FIRSRGetSize<Ipp64f>(int tapsLen, int *pSpecSize, int *pBufSize) { return OptionalAssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp64f, pSpecSize, pBufSize)); }
        template <>
        static inline IppStatus FIRSRGetSize<Ipp64fc>(int tapsLen, int *pSpecSize, int *pBufSize) { return OptionalAssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp64fc, pSpecSize, pBufSize)); }

        template <typename T>
        static inline IppStatus FIRSRInit(const T *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec);
        template <>
        static inline IppStatus FIRSRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { return OptionalAssertNoError(ippsFIRSRInit_32f(pTaps, tapsLen, algType, (IppsFIRSpec_32f *)pSpec)); }
        template <>
        static inline IppStatus FIRSRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { return OptionalAssertNoError(ippsFIRSRInit_32fc(pTaps, tapsLen, algType, (IppsFIRSpec_32fc *)pSpec)); }
        template <>
        static inline IppStatus FIRSRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { return OptionalAssertNoError(ippsFIRSRInit_64f(pTaps, tapsLen, algType, (IppsFIRSpec_64f *)pSpec)); }
        template <>
        static inline IppStatus FIRSRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { return OptionalAssertNoError(ippsFIRSRInit_64fc(pTaps, tapsLen, algType, (IppsFIRSpec_64fc *)pSpec)); }

        template <typename T>
        class FIRSR_Engine
        {
        protected:
            vector<T> m_taps;

            vector<T> m_dly;
            vector<T> m_dlyDst;

            vector<Ipp8u> m_spec;
            vector<Ipp8u> m_buf;

            IppAlgType m_algType;

        public:
            FIRSR_Engine() = default;

            FIRSR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

            void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
            {
                m_algType = algType;
                int dlyLen = taplen - 1;
                m_dly.resize(dlyLen);
                m_dlyDst.resize(dlyLen);

                int specSize, bufSize;

                FIRSRGetSize<T>(taplen, &specSize, &bufSize);

                m_spec.resize(specSize);
                m_buf.resize(bufSize);

                FIRSRInit<T>(m_taps, taplen, m_algType, m_spec);

                m_taps.resize(taplen);
                Copy(taps, m_taps, taplen);
            }

            void assertIsInitialised()
            {
                if (m_spec.empty() || m_buf.empty())
                    throw std::runtime_error("FIRSR not initialized");
            }

            void filter(const T *pSrc, T *pDst, int len)
            {
                assertIsInitialised();
                FIRSR<T>(pSrc, pDst, len, m_spec.data(), m_dly.data(), m_dlyDst.data(), m_buf.data());
                swap(m_dly, m_dlyDst);
            }
        };

        static inline IppStatus FIRMR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRMR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRMR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRMR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRMR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        static inline IppStatus FIRMR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf)
        {
            return OptionalAssertNoError(ippsFIRMR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
        }

        template <typename T>
        static inline IppStatus FIRMRGetSize(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize);
        template <>
        static inline IppStatus FIRMRGetSize<Ipp32f>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
        {
            return OptionalAssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp32f, pSpecSize, pBufSize));
        }
        template <>
        static inline IppStatus FIRMRGetSize<Ipp64f>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
        {
            return OptionalAssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp64f, pSpecSize, pBufSize));
        }
        template <>
        static inline IppStatus FIRMRGetSize<Ipp32fc>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
        {
            return OptionalAssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp32fc, pSpecSize, pBufSize));
        }
        template <>
        static inline IppStatus FIRMRGetSize<Ipp64fc>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
        {
            return OptionalAssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp64fc, pSpecSize, pBufSize));
        }

        template <typename T>
        static inline IppStatus FIRMRInit(const T *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec);
        template <>
        static inline IppStatus FIRMRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
        {
            return OptionalAssertNoError(ippsFIRMRInit_32f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32f *)pSpec));
        }
        template <>
        static inline IppStatus FIRMRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
        {
            return OptionalAssertNoError(ippsFIRMRInit_64f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64f *)pSpec));
        }
        template <>
        static inline IppStatus FIRMRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
        {
            return OptionalAssertNoError(ippsFIRMRInit_32fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32fc *)pSpec));
        }
        template <>
        static inline IppStatus FIRMRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
        {
            return OptionalAssertNoError(ippsFIRMRInit_64fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64fc *)pSpec));
        }

        template <typename T>
        class FIRMR_Engine
        {
        protected:
            vector<T> m_taps;

            vector<T> m_dly;
            vector<T> m_dlyDst;

            vector<Ipp8u> m_spec;
            vector<Ipp8u> m_buf;

            IppAlgType m_algType;

        public:
            FIRMR_Engine() = default;

            FIRMR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

            void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
            {
                m_algType = algType;

                int specSize, bufSize;
                FIRMRGetSize<T>(taplen, &specSize, &bufSize);

                m_spec.resize(specSize);
                m_buf.resize(bufSize);

                FIRMRInit<T>(m_taps.data(), taplen, m_algType, m_spec.data());

                m_taps.resize(taplen);
                Copy(taps, m_taps, taplen);

                int m_dlyLen = taplen - 1;
                m_dly.resize(m_dlyLen);
                m_dlyDst.resize(m_dlyLen);
            }

            void assertIsInitialised()
            {
                if (m_spec.empty())
                    throw std::runtime_error("FIRMR not initialized");
            }

            void filter(const T *pSrc, T *pDst, int len)
            {
                assertIsInitialised();
                FIRMR<T>(pSrc, pDst, len, m_spec, m_dly, m_dlyDst, m_buf);
                swap(m_dly, m_dlyDst);
            }
        };

        template <typename T>
        class FIRGen_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_tapsLen;

        public:
            FIRGen_Engine() = default;
            FIRGen_Engine(int tapsLen)
            {
                initialise(tapsLen);
            }

            void initialise(int tapsLen)
            {
                m_tapsLen = tapsLen;
                int bufSize;
                OptionalAssertNoError(ippsFIRGenGetBufferSize(tapsLen, &bufSize));
                m_buffer.resize(bufSize);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("FIRGen not initialized");
            }

            IppStatus highpass(Ipp64f rFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenHighpass_64f(rFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus lowpass(Ipp64f rFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenLowpass_64f(rFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus bandpass(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenBandpass_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus bandstop(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenBandstop_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }
        };

        template <typename T>
        class FIRLMS_Engine
        {
        protected:
            float mu = 0.001f;
            vector<Ipp8u> m_buffer;
            IppsFIRLMSState_32f *pState = nullptr; // pointer to a region of memory in buffer

        public:
            // TODO: add mu as a parameter to the constructor
            // TODO: check how to use this class

            FIRLMS_Engine() = default;

            explicit FIRLMS_Engine(int tapsLen)
            {
                int BufferSize;
                OptionalAssertNoError(ippsFIRLMSGetStateSize_32f(tapsLen, 0, &BufferSize));
                m_buffer.resize(BufferSize);
                // zero initialise taps and delay line
                OptionalAssertNoError(ippsFIRLMSInit_32f(&pState, nullptr, tapsLen, nullptr, 0, m_buffer.data()));
            }

            IppStatus filter(const Ipp32f *pSrc, const Ipp32f *pRef, Ipp32f *pDst, int len)
            {
                return OptionalAssertNoError(ippsFIRLMS_32f(pSrc, pRef, pDst, len, mu, pState));
            }

            // Retrieves the tap values from the FIR LMS filter.
            void getTaps(Ipp32f *pOutTaps) { ippsFIRLMSGetTaps_32f(pState, pOutTaps); }

            IppStatus getDlyLine(Ipp32f *pDlyLine, int *pDlyLineIndex)
            {
                return OptionalAssertNoError(ippsFIRLMSGetDlyLine_32f(pState, pDlyLine, pDlyLineIndex));
            }

            IppStatus setDlyLine(const Ipp32f *pDlyLine, int dlyLineIndex)
            {
                // This function copies the delay line values from pDlyLine,
                // and the current delay line index from dlyLineIndex,
                // and stores them into the state structure pState.
                return OptionalAssertNoError(ippsFIRLMSSetDlyLine_32f(pState, pDlyLine, dlyLineIndex));
            }
        };

        template <typename T>
        static inline IppDataType GetIppDataType()
        {
            throw std::runtime_error("Unsupported data type");
        }
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

        static inline IppStatus CrossCorrNorm(const Ipp32f *pSrc1, int src1Len, const Ipp32f *pSrc2, int src2Len, Ipp32f *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_32f(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
        static inline IppStatus CrossCorrNorm(const Ipp64f *pSrc1, int src1Len, const Ipp64f *pSrc2, int src2Len, Ipp64f *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_64f(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
        static inline IppStatus CrossCorrNorm(const Ipp32fc *pSrc1, int src1Len, const Ipp32fc *pSrc2, int src2Len, Ipp32fc *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_32fc(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }
        static inline IppStatus CrossCorrNorm(const Ipp64fc *pSrc1, int src1Len, const Ipp64fc *pSrc2, int src2Len, Ipp64fc *pDst, int dstLen, int lowLag, IppEnum algType, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsCrossCorrNorm_64fc(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, algType, pBuffer)); }

        template <typename T>
        class CrossCorrNorm_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            int m_src1Len, m_src2Len, m_dstLen, m_lowLag;
            int m_algType;

        public:
            CrossCorrNorm_Engine() = default;

            explicit CrossCorrNorm_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("CrossCorrNorm not initialized");
            }

            void initialise(int src1Len, int src2Len, int dstLen, int lowLag, int algType)
            {
                // algoType : Bit-field mask for the algorithm type definition. Possible values are the results of composition of the IppAlgType and IppsNormOp values.
                // IppAlgType : ippAlgAuto, ippAlgDirect, ippAlgFFT, ippAlgMask
                // IppsNormOp : ippsNormNone, ippsNormA, ippsNormB, ippsNormMask

                int BufferSize;
                ippsCrossCorrNormGetBufferSize(src1Len, src2Len, dstLen, lowLag, GetIppDataType<T>(), algType, &BufferSize);
                m_buffer.resize(BufferSize);
                m_src1Len = src1Len;
                m_src2Len = src2Len;
                m_dstLen = dstLen;
                m_lowLag = lowLag;
                m_algType = algType;
            }

            void filter(const Ipp64fc *pSrc1, int src1Len, const Ipp64fc *pSrc2, int src2Len, Ipp64fc *pDst, int dstLen, int lowLag)
            {
                assertIsInitialised();
                CrossCorrNorm(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, m_algType, m_buffer.data());
            }
        };

        static inline IppStatus FilterMedian(const Ipp8u *pSrc, Ipp8u *pDst, int len, int maskSize, const Ipp8u *pDlySrc, Ipp8u *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_8u(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian(const Ipp16s *pSrc, Ipp16s *pDst, int len, int maskSize, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_16s(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian(const Ipp32s *pSrc, Ipp32s *pDst, int len, int maskSize, const Ipp32s *pDlySrc, Ipp32s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32s(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian(const Ipp32f *pSrc, Ipp32f *pDst, int len, int maskSize, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32f(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian(const Ipp64f *pSrc, Ipp64f *pDst, int len, int maskSize, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_64f(pSrc, pDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }

        static inline IppStatus FilterMedian_I(Ipp8u *pSrcDst, int len, int maskSize, const Ipp8u *pDlySrc, Ipp8u *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_8u_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian_I(Ipp16s *pSrcDst, int len, int maskSize, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_16s_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian_I(Ipp32s *pSrcDst, int len, int maskSize, const Ipp32s *pDlySrc, Ipp32s *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32s_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian_I(Ipp32f *pSrcDst, int len, int maskSize, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_32f_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }
        static inline IppStatus FilterMedian_I(Ipp64f *pSrcDst, int len, int maskSize, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFilterMedian_64f_I(pSrcDst, len, maskSize, pDlySrc, pDlyDst, pBuffer)); }

        template <typename T>
        class FilterMedian_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            vector<T> m_srcDly;
            vector<T> m_dstDly;
            int m_maskSize;

        public:
            FilterMedian_Engine() = default;

            explicit FilterMedian_Engine(int maskSize)
            {
                initialise(maskSize);
            }

            void initialise(int maskSize)
            {
                // Median mask size, must be a positive integer. If an even value is specified, the function subtracts 1 and uses the odd value of the filter mask for median filtering

                m_maskSize = maskSize;
                int bufferSize;
                OptionalAssertNoError(ippsFilterMedianGetBufferSize(maskSize, GetIppDataType<T>(), &bufferSize));
                m_buffer.resize(bufferSize);

                int dlyLen = maskSize - 1;
                m_srcDly.resize(dlyLen);
                m_dstDly.resize(dlyLen);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("FilterMedian not initialized");
            }

            IppStatus filter(const T *pSrc, T *pDst, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(ippsFilterMedian(pSrc, pDst, len, m_maskSize, m_srcDly.data(), m_dstDly.data(), m_buffer.data()));
            }

            IppStatus filter_I(const T *pSrcDst, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(ippsFilterMedian_I(pSrcDst, len, m_maskSize, m_srcDly.data(), m_dstDly.data(), m_buffer.data()));
            }

            void getSrcDlyLine(T *pDlyLine)
            {
                for (int i = 0; i < m_srcDly.size(); ++i)
                {
                    pDlyLine[i] = m_srcDly[i];
                }
            }

            IppStatus setSrcDlyLine(const T *pDlyLine)
            {
                m_srcDly.set_array(pDlyLine);
            }

            void getDstDlyLine(T *pDlyLine)
            {
                for (int i = 0; i < m_dstDly.size(); ++i)
                {
                    pDlyLine[i] = m_dstDly[i];
                }
            }

            IppStatus setDstDlyLine(const T *pDlyLine)
            {
                m_dstDly.set_array(pDlyLine);
            }
        };

        static inline IppStatus HilbertGetSize(int length, IppHintAlgorithm hint, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippsHilbertGetSize_32f32fc(length, hint, pSpecSize, pBufferSize)); }
        static inline IppStatus HilbertGetSize(int length, IppHintAlgorithm hint, int *pSpecSize, int *pBufferSize) { return OptionalAssertNoError(ippsHilbertGetSize_64f64fc(length, hint, pSpecSize, pBufferSize)); }
        static inline IppStatus HilbertInit(int length, IppHintAlgorithm hint, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbertInit_32f32fc(length, hint, pSpec, pBuffer)); }
        static inline IppStatus HilbertInit(int length, IppHintAlgorithm hint, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbertInit_64f64fc(length, hint, pSpec, pBuffer)); }
        static inline IppStatus Hilbert(const Ipp32f *pSrc, Ipp32fc *pDst, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbert_32f32fc(pSrc, pDst, pSpec, pBuffer)); }
        static inline IppStatus Hilbert(const Ipp64f *pSrc, Ipp64fc *pDst, IppsHilbertSpec *pSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsHilbert_64f64fc(pSrc, pDst, pSpec, pBuffer)); }

        template <typename T>
        class Hilbert_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            vector<Ipp8u> m_spec;
            int m_length;

        public:
            Hilbert_Engine() = default;

            explicit Hilbert_Engine(int length)
            {
                initialise(length);
            }

            void initialise(int length)
            {
                m_length = length;
                int bufferSize;
                int specSize;
                OptionalAssertNoError(HilbertGetSize(length, ippAlgHintAccurate, &specSize, &bufferSize));
                m_buffer.resize(bufferSize);
                m_spec.resize(specSize);

                OptionalAssertNoError(HilbertInit(length, ippAlgHintAccurate, (IppsHilbertSpec *)m_spec.data(), m_buffer.data()));
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("Hilbert_Engine not initialized");
            }

            IppStatus Fwd(const T *pSrc, T *pDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(Hilbert(pSrc, pDst, (IppsHilbertSpec *)m_spec.data(), m_buffer.data()));
            }
        };

        static inline IppStatus TopK(const Ipp32f *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, Ipp32f *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen, IppTopKMode hint, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsTopK_32f(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, dstLen, hint, pBuffer)); }
        static inline IppStatus TopK(const Ipp32s *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, Ipp32s *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen, IppTopKMode hint, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsTopK_32s(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, dstLen, hint, pBuffer)); }

        static inline IppStatus TopKInit(Ipp32s *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen) { return OptionalAssertNoError(ippsTopKInit_32s(pDstValue, pDstIndex, dstLen)); }
        static inline IppStatus TopKInit(Ipp32f *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen) { return OptionalAssertNoError(ippsTopKInit_32f(pDstValue, pDstIndex, dstLen)); }

        template <typename T>
        class TopK_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            int m_srcLen;
            int m_dstLen;
            IppTopKMode m_hint; // ippTopKAuto, ippTopKDirect, ippTopKRadix

        public:
            TopK_Engine() = default;

            TopK_Engine(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto)
            {
                initialise(srcLen, dstLen, hint);
            }

            void initialise(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto)
            {
                // Parameter to choose the optimization that is most suitable for the srcLen+dstlen(K) combination, supported values: ippTopKAuto/ ippTopKDirect/ ippTopKRadix.

                m_srcLen = srcLen;
                m_dstLen = dstLen;
                m_hint = hint;
                int bufferSize;
                OptionalAssertNoError(ippsTopKGetBufferSize(srcLen, dstLen, GetIppDataType<T>(), hint, &bufferSize));
                m_buffer.resize(bufferSize);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("TopK_Engine not initialized");
            }

            IppStatus get_topk(const Ipp32f *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, Ipp32f *pDstValue, Ipp64s *pDstIndex, Ipp64s dstLen)
            {
                assertIsInitialised();
                OptionalAssertNoError(TopKInit(pDstValue, pDstIndex, dstLen));
                return OptionalAssertNoError(TopK(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, dstLen, m_hint, m_buffer.data()));
            }
        };

        /* Essential Initialization */
        static inline IppStatus Copy(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsCopy_8u(pSrc, pDst, len)); }                        // unsigned char
        static inline IppStatus Copy(const Ipp8s *pSrc, Ipp8s *pDst, int len) { return OptionalAssertNoError(ippsCopy_8u((Ipp8u *)pSrc, (Ipp8u *)pDst, len)); }      // signed char  // REUSE
        static inline IppStatus Copy(const Ipp16u *pSrc, Ipp16u *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // unsigned short  // REUSE
        static inline IppStatus Copy(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s(pSrc, pDst, len)); }                     // signed short
        static inline IppStatus Copy(const Ipp32u *pSrc, Ipp32u *pDst, int len) { return OptionalAssertNoError(ippsCopy_32s((Ipp32s *)pSrc, (Ipp32s *)pDst, len)); } // unsigned int
        static inline IppStatus Copy(const Ipp32s *pSrc, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsCopy_32s(pSrc, pDst, len)); }                     // signed int
        static inline IppStatus Copy(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsCopy_32f(pSrc, pDst, len)); }                     // float
        static inline IppStatus Copy(const Ipp64s *pSrc, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsCopy_64s(pSrc, pDst, len)); }                     // __int64 (Windows*) or long long (Linux*)
        static inline IppStatus Copy(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsCopy_64f(pSrc, pDst, len)); }                     // double
        static inline IppStatus Copy(const Ipp8sc *pSrc, Ipp8sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // REUSE another copy function
        static inline IppStatus Copy(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_16sc(pSrc, pDst, len)); }                  // complex short
        static inline IppStatus Copy(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_32sc(pSrc, pDst, len)); }                  // complex signed int
        static inline IppStatus Copy(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsCopy_32fc(pSrc, pDst, len)); }                  // complex float
        static inline IppStatus Copy(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsCopy_64sc(pSrc, pDst, len)); }                  // complex signed long long
        static inline IppStatus Copy(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsCopy_64fc(pSrc, pDst, len)); }                  // complex double

        static inline IppStatus Move(const Ipp8u *pSrc, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsMove_8u(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsMove_16s(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp32s *pSrc, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsMove_32s(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMove_32f(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMove_64f(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp64s *pSrc, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsMove_64s(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsMove_16sc(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsMove_32sc(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsMove_32fc(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsMove_64sc(pSrc, pDst, len)); }
        static inline IppStatus Move(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsMove_64fc(pSrc, pDst, len)); }

        static inline IppStatus Set(Ipp8u val, Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsSet_8u(val, pDst, len)); }
        static inline IppStatus Set(Ipp16s val, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsSet_16s(val, pDst, len)); }
        static inline IppStatus Set(Ipp16sc val, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsSet_16sc(val, pDst, len)); }
        static inline IppStatus Set(Ipp32s val, Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsSet_32s(val, pDst, len)); }
        static inline IppStatus Set(Ipp32f val, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsSet_32f(val, pDst, len)); }
        static inline IppStatus Set(Ipp32sc val, Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsSet_32sc(val, pDst, len)); }
        static inline IppStatus Set(Ipp32fc val, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsSet_32fc(val, pDst, len)); }
        static inline IppStatus Set(Ipp64s val, Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsSet_64s(val, pDst, len)); }
        static inline IppStatus Set(Ipp64f val, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsSet_64f(val, pDst, len)); }
        static inline IppStatus Set(Ipp64sc val, Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsSet_64sc(val, pDst, len)); }
        static inline IppStatus Set(Ipp64fc val, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsSet_64fc(val, pDst, len)); }

        static inline IppStatus Zero(Ipp8u *pDst, int len) { return OptionalAssertNoError(ippsZero_8u(pDst, len)); }
        static inline IppStatus Zero(Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsZero_16s(pDst, len)); }
        static inline IppStatus Zero(Ipp32s *pDst, int len) { return OptionalAssertNoError(ippsZero_32s(pDst, len)); }
        static inline IppStatus Zero(Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsZero_32f(pDst, len)); }
        static inline IppStatus Zero(Ipp64s *pDst, int len) { return OptionalAssertNoError(ippsZero_64s(pDst, len)); }
        static inline IppStatus Zero(Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsZero_64f(pDst, len)); }
        static inline IppStatus Zero(Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsZero_16sc(pDst, len)); }
        static inline IppStatus Zero(Ipp32sc *pDst, int len) { return OptionalAssertNoError(ippsZero_32sc(pDst, len)); }
        static inline IppStatus Zero(Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsZero_32fc(pDst, len)); }
        static inline IppStatus Zero(Ipp64sc *pDst, int len) { return OptionalAssertNoError(ippsZero_64sc(pDst, len)); }
        static inline IppStatus Zero(Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsZero_64fc(pDst, len)); }

        static inline IppStatus Tone(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_16s(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline IppStatus Tone(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_16sc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline IppStatus Tone(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_32f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline IppStatus Tone(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTone_32fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline IppStatus Tone(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTone_64f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline IppStatus Tone(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTone_64fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }

        static inline IppStatus Triangle(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_16s(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline IppStatus Triangle(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_16sc(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline IppStatus Triangle(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_32f(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline IppStatus Triangle(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { return OptionalAssertNoError(ippsTriangle_32fc(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline IppStatus Triangle(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTriangle_64f(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline IppStatus Triangle(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { return OptionalAssertNoError(ippsTriangle_64fc(pDst, len, magn, rFreq, asym, pPhase)); }

        static inline IppStatus VectorJaehne(Ipp8u *pDst, int len, Ipp8u magn) { return OptionalAssertNoError(ippsVectorJaehne_8u(pDst, len, magn)); }
        static inline IppStatus VectorJaehne(Ipp16u *pDst, int len, Ipp16u magn) { return OptionalAssertNoError(ippsVectorJaehne_16u(pDst, len, magn)); }
        static inline IppStatus VectorJaehne(Ipp16s *pDst, int len, Ipp16s magn) { return OptionalAssertNoError(ippsVectorJaehne_16s(pDst, len, magn)); }
        static inline IppStatus VectorJaehne(Ipp32s *pDst, int len, Ipp32s magn) { return OptionalAssertNoError(ippsVectorJaehne_32s(pDst, len, magn)); }
        static inline IppStatus VectorJaehne(Ipp32f *pDst, int len, Ipp32f magn) { return OptionalAssertNoError(ippsVectorJaehne_32f(pDst, len, magn)); }
        static inline IppStatus VectorJaehne(Ipp64f *pDst, int len, Ipp64f magn) { return OptionalAssertNoError(ippsVectorJaehne_64f(pDst, len, magn)); }

        static inline IppStatus VectorSlope(Ipp8u *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_8u(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp16u *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_16u(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp16s *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_16s(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp32u *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_32u(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp32s *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_32s(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp32f *pDst, int len, Ipp32f offset, Ipp32f slope) { return OptionalAssertNoError(ippsVectorSlope_32f(pDst, len, offset, slope)); }
        static inline IppStatus VectorSlope(Ipp64f *pDst, int len, Ipp64f offset, Ipp64f slope) { return OptionalAssertNoError(ippsVectorSlope_64f(pDst, len, offset, slope)); }

        static inline IppStatus RandGaussInit(IppsRandGaussState_8u *pRandGaussState, Ipp8u mean, Ipp8u stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_8u(pRandGaussState, mean, stdDev, seed)); }
        static inline IppStatus RandGaussInit(IppsRandGaussState_16s *pRandGaussState, Ipp16s mean, Ipp16s stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_16s(pRandGaussState, mean, stdDev, seed)); }
        static inline IppStatus RandGaussInit(IppsRandGaussState_32f *pRandGaussState, Ipp32f mean, Ipp32f stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_32f(pRandGaussState, mean, stdDev, seed)); }
        static inline IppStatus RandGaussInit(IppsRandGaussState_64f *pRandGaussState, Ipp64f mean, Ipp64f stdDev, unsigned int seed) { return OptionalAssertNoError(ippsRandGaussInit_64f(pRandGaussState, mean, stdDev, seed)); }

        static inline IppStatus RandGaussGetSize(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_8u(pRandGaussStateSize)); }
        static inline IppStatus RandGaussGetSize(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_32f(pRandGaussStateSize)); }
        static inline IppStatus RandGaussGetSize(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_16s(pRandGaussStateSize)); }
        static inline IppStatus RandGaussGetSize(int *pRandGaussStateSize) { return OptionalAssertNoError(ippsRandGaussGetSize_64f(pRandGaussStateSize)); }

        static inline IppStatus RandGauss(Ipp8u *pDst, int len, IppsRandGaussState_8u *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_8u(pDst, len, pRandGaussState)); }
        static inline IppStatus RandGauss(Ipp16s *pDst, int len, IppsRandGaussState_16s *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_16s(pDst, len, pRandGaussState)); }
        static inline IppStatus RandGauss(Ipp32f *pDst, int len, IppsRandGaussState_32f *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_32f(pDst, len, pRandGaussState)); }
        static inline IppStatus RandGauss(Ipp64f *pDst, int len, IppsRandGaussState_64f *pRandGaussState) { return OptionalAssertNoError(ippsRandGauss_64f(pDst, len, pRandGaussState)); }

        template <typename T>
        class RandGauss_Engine
        {
        protected:
            vector<T> m_pRandGaussState;
            T m_mean;
            T m_stdDev;
            unsigned int m_seed;

        public:
            RandGauss_Engine() = default;

            RandGauss_Engine(T mean, T stdDev, unsigned int seed) { initialise(mean, stdDev, seed); }

            void initialise(T mean, T stdDev, unsigned int seed)
            {
                m_mean = mean;
                m_stdDev = stdDev;
                m_seed = seed;

                int size;
                OptionalAssertNoError(RandGaussGetSize<T>(&size));
                m_pRandGaussState.resize(size);

                OptionalAssertNoError(RandGaussInit<T>(m_pRandGaussState.data(), m_mean, m_stdDev, m_seed));
            }

            void assertIsInitialised()
            {
                if (m_pRandGaussState.empty())
                    throw std::invalid_argument("DFT not initalized");
            }

            IppStatus sample(T *output, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError((output, len, m_pRandGaussState.data()));
            }
        };

        static inline IppStatus RandUniformGetSize(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_8u(pRandUniformStateSize)); }
        static inline IppStatus RandUniformGetSize(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_16s(pRandUniformStateSize)); }
        static inline IppStatus RandUniformGetSize(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_32f(pRandUniformStateSize)); }
        static inline IppStatus RandUniformGetSize(int *pRandUniformStateSize) { return OptionalAssertNoError(ippsRandUniformGetSize_64f(pRandUniformStateSize)); }

        static inline IppStatus RandUniformInit(IppsRandUniState_8u *pRandUniState, Ipp8u low, Ipp8u high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_8u(pRandUniState, low, high, seed)); }
        static inline IppStatus RandUniformInit(IppsRandUniState_16s *pRandUniState, Ipp16s low, Ipp16s high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_16s(pRandUniState, low, high, seed)); }
        static inline IppStatus RandUniformInit(IppsRandUniState_32f *pRandUniState, Ipp32f low, Ipp32f high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_32f(pRandUniState, low, high, seed)); }
        static inline IppStatus RandUniformInit(IppsRandUniState_64f *pRandUniState, Ipp64f low, Ipp64f high, unsigned int seed) { return OptionalAssertNoError(ippsRandUniformInit_64f(pRandUniState, low, high, seed)); }

        static inline IppStatus RandUniform(Ipp8u *pDst, int len, IppsRandUniState_8u *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_8u(pDst, len, pRandUniState)); }
        static inline IppStatus RandUniform(Ipp16s *pDst, int len, IppsRandUniState_16s *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_16s(pDst, len, pRandUniState)); }
        static inline IppStatus RandUniform(Ipp32f *pDst, int len, IppsRandUniState_32f *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_32f(pDst, len, pRandUniState)); }
        static inline IppStatus RandUniform(Ipp64f *pDst, int len, IppsRandUniState_64f *pRandUniState) { return OptionalAssertNoError(ippsRandUniform_64f(pDst, len, pRandUniState)); }

        template <typename T>
        class RandUniform_Engine
        {
        protected:
            vector<T> m_pRandUniformState;
            T m_low;
            T m_high;
            unsigned int m_seed;

        public:
            RandUniform_Engine() = default;
            RandUniform_Engine(T low, T high, unsigned int seed) { initialise(low, high, seed); }
            void initialise(T low, T high, unsigned int seed)
            {
                m_low = low;
                m_high = high;
                m_seed = seed;

                int size;
                OptionalAssertNoError(RandUniformGetSize<T>(&size));
                m_pRandUniformState.resize(size);

                OptionalAssertNoError(RandUniformInit<T>(m_pRandUniformState.data(), m_low, m_high, m_seed));
            }
            void assertIsInitialised()
            {
                if (m_pRandUniformState.empty())
                    throw std::invalid_argument("RandUniform_Engine not initalized");
            }
            IppStatus sample(T *output, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(RandUniform<T>(output, len, m_pRandUniformState.data()));
            }
        };
        /* Support */

        // ippsMalloc
        // limited to 2GB of memory
        template <typename T>
        static inline T *ippsMalloc(int len)
        {
            throw std::runtime_error("ippsMalloc not implemented for this type");
        } // default
        template <>
        static inline Ipp8u *ippsMalloc<Ipp8u>(int len) { return ippsMalloc_8u(len); }
        template <>
        static inline Ipp16u *ippsMalloc<Ipp16u>(int len) { return ippsMalloc_16u(len); }
        template <>
        static inline Ipp32u *ippsMalloc<Ipp32u>(int len) { return ippsMalloc_32u(len); }
        template <>
        static inline Ipp8s *ippsMalloc<Ipp8s>(int len) { return ippsMalloc_8s(len); }
        template <>
        static inline Ipp16s *ippsMalloc<Ipp16s>(int len) { return ippsMalloc_16s(len); }
        template <>
        static inline Ipp32s *ippsMalloc<Ipp32s>(int len) { return ippsMalloc_32s(len); }
        template <>
        static inline Ipp64s *ippsMalloc<Ipp64s>(int len) { return ippsMalloc_64s(len); }
        template <>
        static inline Ipp32f *ippsMalloc<Ipp32f>(int len) { return ippsMalloc_32f(len); }
        template <>
        static inline Ipp64f *ippsMalloc<Ipp64f>(int len) { return ippsMalloc_64f(len); }
        template <>
        static inline Ipp8sc *ippsMalloc<Ipp8sc>(int len) { return ippsMalloc_8sc(len); }
        template <>
        static inline Ipp16sc *ippsMalloc<Ipp16sc>(int len) { return ippsMalloc_16sc(len); }
        template <>
        static inline Ipp32sc *ippsMalloc<Ipp32sc>(int len) { return ippsMalloc_32sc(len); }
        template <>
        static inline Ipp64sc *ippsMalloc<Ipp64sc>(int len) { return ippsMalloc_64sc(len); }
        template <>
        static inline Ipp32fc *ippsMalloc<Ipp32fc>(int len) { return ippsMalloc_32fc(len); }
        template <>
        static inline Ipp64fc *ippsMalloc<Ipp64fc>(int len) { return ippsMalloc_64fc(len); }
        template <>
        static inline std::complex<float> *ippsMalloc<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc(len)); }
        template <>
        static inline std::complex<double> *ippsMalloc<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc(len)); }

        // ippsMalloc_L
        // platform aware function -- introduced in 2017
        template <typename T>
        static inline T *ippsMalloc_L(int len)
        {
            throw std::runtime_error("ippsMalloc_L not implemented for this type");
        }
        template <>
        static inline Ipp8u *ippsMalloc_L<Ipp8u>(int len) { return ippsMalloc_8u_L(len); }
        template <>
        static inline Ipp16u *ippsMalloc_L<Ipp16u>(int len) { return ippsMalloc_16u_L(len); }
        template <>
        static inline Ipp32u *ippsMalloc_L<Ipp32u>(int len) { return ippsMalloc_32u_L(len); }
        template <>
        static inline Ipp8s *ippsMalloc_L<Ipp8s>(int len) { return ippsMalloc_8s_L(len); }
        template <>
        static inline Ipp16s *ippsMalloc_L<Ipp16s>(int len) { return ippsMalloc_16s_L(len); }
        template <>
        static inline Ipp32s *ippsMalloc_L<Ipp32s>(int len) { return ippsMalloc_32s_L(len); }
        template <>
        static inline Ipp64s *ippsMalloc_L<Ipp64s>(int len) { return ippsMalloc_64s_L(len); }
        template <>
        static inline Ipp32f *ippsMalloc_L<Ipp32f>(int len) { return ippsMalloc_32f_L(len); }
        template <>
        static inline Ipp64f *ippsMalloc_L<Ipp64f>(int len) { return ippsMalloc_64f_L(len); }
        template <>
        static inline Ipp8sc *ippsMalloc_L<Ipp8sc>(int len) { return ippsMalloc_8sc_L(len); }
        template <>
        static inline Ipp16sc *ippsMalloc_L<Ipp16sc>(int len) { return ippsMalloc_16sc_L(len); }
        template <>
        static inline Ipp32sc *ippsMalloc_L<Ipp32sc>(int len) { return ippsMalloc_32sc_L(len); }
        template <>
        static inline Ipp64sc *ippsMalloc_L<Ipp64sc>(int len) { return ippsMalloc_64sc_L(len); }
        template <>
        static inline Ipp32fc *ippsMalloc_L<Ipp32fc>(int len) { return ippsMalloc_32fc_L(len); }
        template <>
        static inline Ipp64fc *ippsMalloc_L<Ipp64fc>(int len) { return ippsMalloc_64fc_L(len); }
        template <>
        static inline std::complex<float> *ippsMalloc_L<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc_L(len)); }
        template <>
        static inline std::complex<double> *ippsMalloc_L<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc_L(len)); }

        template <typename T>
        class vector
        {
            typedef T value_type;
            typedef T *pointer;
            typedef const T *const_pointer;
            typedef T &reference;
            typedef const T &const_reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;

            friend void swap(vector &a, vector &b) noexcept
            {
                using std::swap;
                swap(a.m_numel, b.m_numel);
                swap(a.m_data, b.m_data);
                swap(a.m_cap, b.m_cap);
            }

        protected:
            size_type m_numel = 0;
            size_type m_cap = 0;
            pointer m_data = nullptr;

        public:
            // Constructors

            // Default constructor
            vector() = default;

            explicit vector(size_type count)
            {
                m_numel = count;
                reserve(m_numel);
            }

            vector(size_type count, const value_type &value)
            {
                m_numel = count;
                reserve(m_numel);
                set(value);
            }

            // Copy constructor
            vector(const vector &other)
            {
                reserve(m_numel);
                Copy(other.m_data, m_data, (int)m_numel);
                m_numel = other.m_numel;
            }

            // Move constructor
            // Move constructors typically "steal" the resources held by the argument
            // rather than make copies of them, and leave the argument in some valid
            // but otherwise indeterminate state.
            vector(vector &&other)
            {
                // steal other's data
                m_numel = other.m_numel;
                m_cap = other.m_cap;
                m_data = other.m_data;

                // nullify other
                other.m_data = nullptr;
                other.m_cap = 0;
                other.m_numel = 0;
            }

            // Copy Assignment operator
            vector &operator=(vector &other)
            {
                if (this != &other)
                {
                    if (other.m_numel > 0)
                    {
                        reserve(other.m_numel);
                        Copy(other.m_data, m_data, (int)m_numel);
                    }
                    m_numel = other.m_numel;
                }
                return *this;
            }

            // Move Assignment operator
            vector &operator=(vector &&other) noexcept
            {
                if (this != &other)
                {
                    // free own data
                    if (m_data != nullptr)
                        ippsFree(m_data);

                    // steal other's data
                    m_numel = other.m_numel;
                    m_cap = other.m_cap;
                    m_data = other.m_data;

                    // nullify other
                    other.m_data = nullptr;
                    other.m_cap = 0;
                    other.m_numel = 0;
                }
                return *this;
            }

            ~vector()
            {
                if (m_data != nullptr)
                    ippsFree(m_data);
            }

            /*
            Resizes the container so that it contains n elements.
            If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
            If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
            If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
            If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
            */
            void resize(size_type new_count)
            {

                reserve(new_count);

                if (new_count > m_numel) // value initialise new elements
                    for (int i = m_numel; i < new_count; i++)
                        new (&m_data[i]) value_type{};
                else if (new_count < m_numel) // destroy excess elements
                    for (int i = new_count; i < m_numel; i++)
                        m_data[i].~value_type();

                m_numel = new_count;
            }

            void resize(size_t new_count, const T &value)
            {

                reserve(new_count);

                if (new_count > m_numel) // copy construct new elements
                    for (int i = m_numel; i < new_count; i++)
                        new (&m_data[i]) value_type(value);
                else if (new_count < m_numel) // destroy excess elements
                    for (int i = new_count; i < m_numel; i++)
                        m_data[i].~value_type();

                m_numel = new_count;
            }

            void reserve(size_type new_cap)
            {
                if (new_cap > m_cap)
                {
                    value_type *new_data = ippsMalloc<value_type>(new_cap);
                    if (m_data != nullptr)
                    {
                        Copy(m_data, new_data, (int)m_numel);
                        ippsFree(m_data);
                    }
                    m_data = new_data;
                    m_cap = new_cap;
                }
            }

            void set(const_reference value)
            {
                for (int i = 0; i < m_numel; i++)
                    new (&m_data[i]) value_type(value);
            }

            // Unsafee method, use with caution
            void set_array(pointer pData)
            {
                for (int i = 0; i < m_numel; i++)
                    m_data[i] = pData[i];
            }

            pointer data() { return m_data; }
            const_pointer data() const { return m_data; }

            reference back() { return m_data[m_numel - 1]; }
            const_reference back() const { return m_data[m_numel - 1]; }

            reference front() { return m_data[0]; }

            const_reference front() const { return m_data[0]; }

            reference at(size_type pos)
            {
                if (pos < m_numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
            }

            const_reference at(size_type pos) const
            {
                if (pos < m_numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
            }

            reference operator[](size_type pos) { return m_data[pos]; }

            const_reference operator[](size_type pos) const { return m_data[pos]; }

            void push_back(const_reference value)
            {
                // check size
                if (m_numel == m_cap)
                {
                    m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
                }

                m_data[m_numel] = value;
                m_numel++;
            }

            void push_back(T &&value)
            {
                // check size
                if (m_numel == m_cap)
                {
                    m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
                }

                m_data[m_numel] = value;
                m_numel++;
            }

            size_type size() const { return m_numel; }

            size_type capacity() const { return m_cap; }

            void clear() { m_numel = 0; }

            bool empty() const noexcept { return m_numel == 0; }

            // Iterators
            pointer begin() { return m_data; }

            const_pointer begin() const { return m_data; }

            pointer end() { return m_data + m_numel; }

            const_pointer end() const { return m_data + m_numel; }

            // Const iterators
            const_pointer cbegin() const { return m_data; }

            const_pointer cend() const { return m_data + m_numel; }
        };

        // Custom Allocator for use with STL vector
        template <class T>
        struct IPPallocator
        {
            typedef T value_type;
            IPPallocator() noexcept {} // default ctor not required by C++ Standard Library

            // A converting copy constructor:
            template <class U>
            IPPallocator(const IPPallocator<U> &) noexcept {}

            template <class U>
            bool operator==(const IPPallocator<U> &) const noexcept { return true; }

            template <class U>
            bool operator!=(const IPPallocator<U> &) const noexcept { return false; }

            T *allocate(const size_t n) const
            {
                return ippsMalloc<T>(n);
            }
            void deallocate(T *const p, size_t) const noexcept
            {
                ippsFree(p);
            }
        };

        /* Transforms */
        static inline IppStatus ConjCcs(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjCcs_32fc(pSrc, pDst, lenDst)); }
        static inline IppStatus ConjCcs(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjCcs_64fc(pSrc, pDst, lenDst)); }

        static inline IppStatus ConjCcs_I(Ipp32fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjCcs_32fc_I(pSrcDst, lenDst)); }
        static inline IppStatus ConjCcs_I(Ipp64fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjCcs_64fc_I(pSrcDst, lenDst)); }

        static inline IppStatus ConjPack(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjPack_32fc(pSrc, pDst, lenDst)); }
        static inline IppStatus ConjPack(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjPack_64fc(pSrc, pDst, lenDst)); }

        static inline IppStatus ConjPack_I(Ipp32fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjPack_32fc_I(pSrcDst, lenDst)); }
        static inline IppStatus ConjPack_I(Ipp64fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjPack_64fc_I(pSrcDst, lenDst)); }

        static inline IppStatus ConjPerm(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjPerm_32fc(pSrc, pDst, lenDst)); }
        static inline IppStatus ConjPerm(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { return OptionalAssertNoError(ippsConjPerm_64fc(pSrc, pDst, lenDst)); }

        static inline IppStatus ConjPerm_I(Ipp32fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjPerm_32fc_I(pSrcDst, lenDst)); }
        static inline IppStatus ConjPerm_I(Ipp64fc *pSrcDst, int lenDst) { return OptionalAssertNoError(ippsConjPerm_64fc_I(pSrcDst, lenDst)); }

        static inline IppStatus MulPackConj_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPackConj_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MulPackConj_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPackConj_64f_I(pSrc, pSrcDst, len)); }

        static inline IppStatus MulPack(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMulPack_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulPack(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMulPack_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulPack_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPack_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MulPack_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPack_64f_I(pSrc, pSrcDst, len)); }

        static inline IppStatus MulPerm(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsMulPerm_32f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulPerm(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsMulPerm_64f(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulPerm_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPerm_32f_I(pSrc, pSrcDst, len)); }
        static inline IppStatus MulPerm_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsMulPerm_64f_I(pSrc, pSrcDst, len)); }

        template <typename T>
        static inline IppStatus DFTGetSize(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
        template <>
        static inline IppStatus DFTGetSize<Ipp32fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_C_32fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus DFTGetSize<Ipp64fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_C_64fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus DFTGetSize<float>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_R_32f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus DFTGetSize<double>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsDFTGetSize_R_64f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

        template <typename T>
        static inline IppStatus DFTInit(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit);
        template <>
        static inline IppStatus DFTInit<Ipp32fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_C_32fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_32fc *)pDFTSpec, pMemInit)); }
        template <>
        static inline IppStatus DFTInit<Ipp64fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_C_64fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_64fc *)pDFTSpec, pMemInit)); }
        template <>
        static inline IppStatus DFTInit<float>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_R_32f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_32f *)pDFTSpec, pMemInit)); }
        template <>
        static inline IppStatus DFTInit<double>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { return OptionalAssertNoError(ippsDFTInit_R_64f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_64f *)pDFTSpec, pMemInit)); }

        static inline IppStatus DFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }

        static inline IppStatus DFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }
        static inline IppStatus DFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsDFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }

        template <typename T>
        static inline int get_FwdSize(int nfft) { return nfft; }
        template <>
        static inline int get_FwdSize<float>(int nfft) { return nfft / 2 + 1; }
        template <>
        static inline int get_FwdSize<double>(int nfft) { return nfft / 2 + 1; }

        // Only 4 types are supported
        // Trc = Ipp64fc, Tc = Ipp64fc
        // Trc = Ipp32fc, Tc = Ipp32fc
        // Trc = Ipp64f, Tc = Ipp64fc
        // Trc = Ipp32f, Tc = Ipp32fc
        template <typename Trc, typename Tc>
        class DFT_Engine
        {
        protected:
            vector<Ipp8u> m_pDFTSpec;
            vector<Ipp8u> m_pDFTWorkBuf;
            vector<Ipp8u> m_pDFTInitBuf;

            int m_inNFFT;
            int m_outNFFT;
            int m_flag;

        public:
            DFT_Engine() = default;

            DFT_Engine(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N) { initialise(nfft, flag); }

            void initialise(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N)
            {
                m_inNFFT = nfft;
                m_outNFFT = get_FwdSize<Trc>(nfft);
                m_flag = flag;

                int SizeSpec, SizeInit, SizeBuf;
                DFTGetSize<Trc>(nfft, flag, &SizeSpec, &SizeInit, &SizeBuf);

                m_pDFTSpec.resize(SizeSpec);
                m_pDFTWorkBuf.resize(SizeBuf);
                m_pDFTInitBuf.resize(SizeInit);

                DFTInit<Trc>(m_inNFFT, m_flag, m_pDFTSpec.data(), m_pDFTInitBuf.data());
            }

            void assertIsInitialised()
            {
                if (m_pDFTSpec.empty())
                    throw std::invalid_argument("DFT not initalized");
            }

            void Fwd(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                DFTFwd(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data());
            }

            void Inv(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                DFTInv(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data());
            }

            int inSize() const { return m_inNFFT; }
            int outSize() const { return m_outNFFT; }
        };

        template <typename T>
        static inline IppStatus FFTGetSize(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
        template <>
        static inline IppStatus FFTGetSize<Ipp32fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_C_32fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus FFTGetSize<Ipp64fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_C_64fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus FFTGetSize<float>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_R_32f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
        template <>
        static inline IppStatus FFTGetSize<double>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { return OptionalAssertNoError(ippsFFTGetSize_R_64f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

        template <typename T>
        static inline IppStatus FFTInit(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer);
        template <>
        static inline IppStatus FFTInit<Ipp32fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_C_32fc((IppsFFTSpec_C_32fc **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
        template <>
        static inline IppStatus FFTInit<Ipp64fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_C_64fc((IppsFFTSpec_C_64fc **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
        template <>
        static inline IppStatus FFTInit<float>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_R_32f((IppsFFTSpec_R_32f **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
        template <>
        static inline IppStatus FFTInit<double>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { return OptionalAssertNoError(ippsFFTInit_R_64f((IppsFFTSpec_R_64f **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }

        static inline IppStatus FFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

        static inline IppStatus FFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

        static inline IppStatus FFTFwd_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd_I(float *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_32f_I(pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTFwd_I(double *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTFwd_RToCCS_64f_I(pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

        static inline IppStatus FFTInv_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_64f_I((double *)pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
        static inline IppStatus FFTInv_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { return OptionalAssertNoError(ippsFFTInv_CCSToR_32f_I((float *)pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

        template <typename Trc, typename Tc>
        class FFT_Engine
        {
        protected:
            vector<Ipp8u> m_pFFTSpec;
            vector<Ipp8u> m_pFFTWorkBuf;
            vector<Ipp8u> m_pFFTInitBuf;

            int m_inNFFT;
            int m_outNFFT;
            int m_flag;

        public:
            FFT_Engine() = default;

            FFT_Engine(int order, int flag = IPP_FFT_DIV_INV_BY_N) { initialise(order, flag); }

            void initialise(int order, int flag = IPP_FFT_DIV_INV_BY_N)
            {
                int SizeSpec, SizeInit, SizeBuf;

                FFTGetSize<Trc>(order, flag, &SizeSpec, &SizeInit, &SizeBuf);

                m_pFFTSpec.resize(SizeSpec);
                m_pFFTWorkBuf.resize(SizeBuf);
                m_pFFTInitBuf.resize(SizeInit);

                FFTInit<Trc>(nfft, flag, m_pFFTSpec.data(), m_pFFTInitBuf.data());

                m_inNFFT = 1 << order;
                m_outNFFT = get_FwdSize<Trc>(m_inNFFT);
                m_flag = flag;
            }

            void assertIsInitialised()
            {
                if (m_pFFTInitBuf.empty())
                    throw std::invalid_argument("FFT not initalized");
            }

            IppStatus Fwd(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTFwd(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus Fwd_I(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTFwd_I(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus Inv(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTInv(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus Inv_I(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTInv_I(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data()));
            }

            int inSize() const { return m_inNFFT; }
            int outSize() const { return m_outNFFT; }
        };

        //   ippsPatternMatchGetBufferSize
        //   ippsPatternMatch_8u16u

        //   ippsResamplePolyphaseFixedGetSize_16s
        //   ippsResamplePolyphaseFixedGetSize_32f
        //   ippsResamplePolyphaseFixedInit_16s
        //   ippsResamplePolyphaseFixedInit_32f
        //   ippsResamplePolyphaseFixed_16s
        //   ippsResamplePolyphaseFixed_32f
        //   ippsResamplePolyphaseGetFixedFilter_16s
        //   ippsResamplePolyphaseGetFixedFilter_32f
        //   ippsResamplePolyphaseGetSize_16s
        //   ippsResamplePolyphaseGetSize_32f
        //   ippsResamplePolyphaseInit_16s
        //   ippsResamplePolyphaseInit_32f
        //   ippsResamplePolyphaseSetFixedFilter_16s
        //   ippsResamplePolyphaseSetFixedFilter_32f
        //   ippsResamplePolyphase_16s
        //   ippsResamplePolyphase_32f

        //   ippsWTFwdGetDlyLine_16s32f
        //   ippsWTFwdGetDlyLine_16u32f
        //   ippsWTFwdGetDlyLine_32f
        //   ippsWTFwdGetDlyLine_8u32f
        //   ippsWTFwdGetSize
        //   ippsWTFwdInit_16s32f
        //   ippsWTFwdInit_16u32f
        //   ippsWTFwdInit_32f
        //   ippsWTFwdInit_8u32f
        //   ippsWTFwdSetDlyLine_16s32f
        //   ippsWTFwdSetDlyLine_16u32f
        //   ippsWTFwdSetDlyLine_32f
        //   ippsWTFwdSetDlyLine_8u32f
        //   ippsWTFwd_16s32f
        //   ippsWTFwd_16u32f
        //   ippsWTFwd_32f
        //   ippsWTFwd_8u32f
        //   ippsWTHaarFwd_16s_Sfs
        //   ippsWTHaarFwd_32f
        //   ippsWTHaarFwd_64f
        //   ippsWTHaarInv_16s_Sfs
        //   ippsWTHaarInv_32f
        //   ippsWTHaarInv_64f
        //   ippsWTInvGetDlyLine_32f
        //   ippsWTInvGetDlyLine_32f16s
        //   ippsWTInvGetDlyLine_32f16u
        //   ippsWTInvGetDlyLine_32f8u
        //   ippsWTInvGetSize
        //   ippsWTInvInit_32f
        //   ippsWTInvInit_32f16s
        //   ippsWTInvInit_32f16u
        //   ippsWTInvInit_32f8u
        //   ippsWTInvSetDlyLine_32f
        //   ippsWTInvSetDlyLine_32f16s
        //   ippsWTInvSetDlyLine_32f16u
        //   ippsWTInvSetDlyLine_32f8u
        //   ippsWTInv_32f
        //   ippsWTInv_32f16s
        //   ippsWTInv_32f16u
        //   ippsWTInv_32f8u
        static inline IppStatus WinBartlett(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16s(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32f(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64f(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16sc(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc(pSrc, pDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16s_I(pSrcDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32f_I(pSrcDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64f_I(pSrcDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16sc_I(pSrcDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc_I(pSrcDst, len)); }
        static inline IppStatus WinBartlett_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc_I(pSrcDst, len)); }

        static inline IppStatus WinBlackman(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16s(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinBlackman(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16sc(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinBlackman(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32f(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinBlackman(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinBlackman(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64f(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinBlackman(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc(pSrc, pDst, len, alpha)); }

        static inline IppStatus WinBlackmanStd(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16s(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanStd(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16sc(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanStd(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32f(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanStd(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanStd(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64f(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanStd(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc(pSrc, pDst, len)); }

        static inline IppStatus WinBlackmanOpt(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16s(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanOpt(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16sc(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanOpt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32f(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanOpt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanOpt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64f(pSrc, pDst, len)); }
        static inline IppStatus WinBlackmanOpt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc(pSrc, pDst, len)); }

        static inline IppStatus WinBlackman_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16s_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinBlackman_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16sc_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinBlackman_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32f_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinBlackman_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinBlackman_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64f_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinBlackman_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc_I(pSrcDst, len, alpha)); }

        static inline IppStatus WinBlackmanOpt_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16s_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanOpt_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16sc_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanOpt_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32f_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanOpt_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanOpt_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64f_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanOpt_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc_I(pSrcDst, len)); }

        static inline IppStatus WinBlackmanStd_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16s_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanStd_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16sc_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanStd_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32f_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanStd_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanStd_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64f_I(pSrcDst, len)); }
        static inline IppStatus WinBlackmanStd_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc_I(pSrcDst, len)); }

        static inline IppStatus WinHamming(Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_16s(pSrc, pDst, len)); }
        static inline IppStatus WinHamming(Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_32f(pSrc, pDst, len)); }
        static inline IppStatus WinHamming(Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_64f(pSrc, pDst, len)); }
        static inline IppStatus WinHamming(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_16sc(pSrc, pDst, len)); }
        static inline IppStatus WinHamming(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc(pSrc, pDst, len)); }
        static inline IppStatus WinHamming(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc(pSrc, pDst, len)); }
        static inline IppStatus WinHamming_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_16s_I(pSrcDst, len)); }
        static inline IppStatus WinHamming_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_32f_I(pSrcDst, len)); }
        static inline IppStatus WinHamming_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_64f_I(pSrcDst, len)); }
        static inline IppStatus WinHamming_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_16sc_I(pSrcDst, len)); }
        static inline IppStatus WinHamming_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc_I(pSrcDst, len)); }
        static inline IppStatus WinHamming_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc_I(pSrcDst, len)); }

        static inline IppStatus WinHann(Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinHann_16s(pSrc, pDst, len)); }
        static inline IppStatus WinHann(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_16sc(pSrc, pDst, len)); }
        static inline IppStatus WinHann(Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinHann_32f(pSrc, pDst, len)); }
        static inline IppStatus WinHann(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc(pSrc, pDst, len)); }
        static inline IppStatus WinHann(Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinHann_64f(pSrc, pDst, len)); }
        static inline IppStatus WinHann(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc(pSrc, pDst, len)); }
        static inline IppStatus WinHann_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_16s_I(pSrcDst, len)); }
        static inline IppStatus WinHann_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_16sc_I(pSrcDst, len)); }
        static inline IppStatus WinHann_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_32f_I(pSrcDst, len)); }
        static inline IppStatus WinHann_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc_I(pSrcDst, len)); }
        static inline IppStatus WinHann_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_64f_I(pSrcDst, len)); }
        static inline IppStatus WinHann_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc_I(pSrcDst, len)); }

        static inline IppStatus WinKaiser(Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16s(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser(Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32f(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser(Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64f(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser(Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16sc(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser(Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser(Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc(pSrc, pDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16s_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32f_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64f_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16sc_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc_I(pSrcDst, len, alpha)); }
        static inline IppStatus WinKaiser_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc_I(pSrcDst, len, alpha)); }

        //   ippsZeroCrossing_16s32f
        //   ippsZeroCrossing_32f
    }
}
