#include <ipps.h>
#include <ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include <vector>

namespace tipp
{
    namespace ipps
    {
        static inline void Abs(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsAbs_16s(pSrc, pDst, len)); }
        static inline void Abs(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsAbs_32s(pSrc, pDst, len)); }
        static inline void Abs(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsAbs_32f(pSrc, pDst, len)); }
        static inline void Abs(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsAbs_64f(pSrc, pDst, len)); }

        static inline void Abs_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsAbs_16s_I(pSrcDst, len)); }
        static inline void Abs_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsAbs_32s_I(pSrcDst, len)); }
        static inline void Abs_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsAbs_32f_I(pSrcDst, len)); }
        static inline void Abs_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsAbs_64f_I(pSrcDst, len)); }

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

        static inline void AndC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsAndC_8u(pSrc, val, pDst, len)); }
        static inline void AndC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsAndC_16u(pSrc, val, pDst, len)); }
        static inline void AndC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { AssertNoError(ippsAndC_32u(pSrc, val, pDst, len)); }
        static inline void AndC_I(Ipp8u val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsAndC_8u_I(val, pSrcDst, len)); }
        static inline void AndC_I(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsAndC_16u_I(val, pSrcDst, len)); }
        static inline void AndC_I(Ipp32u val, Ipp32u *pSrcDst, int len) { AssertNoError(ippsAndC_32u_I(val, pSrcDst, len)); }

        static inline void And(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, int len) { AssertNoError(ippsAnd_8u(pSrc1, pSrc2, pDst, len)); }
        static inline void And(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { AssertNoError(ippsAnd_16u(pSrc1, pSrc2, pDst, len)); }
        static inline void And(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { AssertNoError(ippsAnd_32u(pSrc1, pSrc2, pDst, len)); }
        static inline void And_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsAnd_8u_I(pSrc, pSrcDst, len)); }
        static inline void And_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsAnd_16u_I(pSrc, pSrcDst, len)); }
        static inline void And_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { AssertNoError(ippsAnd_32u_I(pSrc, pSrcDst, len)); }

        static inline void Arctan(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsArctan_32f(pSrc, pDst, len)); }
        static inline void Arctan(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsArctan_64f(pSrc, pDst, len)); }
        static inline void Arctan_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsArctan_32f_I(pSrcDst, len)); }
        static inline void Arctan_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsArctan_64f_I(pSrcDst, len)); }

        //   ippsAutoCorrNormGetBufferSize
        //   ippsAutoCorrNorm_32f
        //   ippsAutoCorrNorm_32fc
        //   ippsAutoCorrNorm_64f
        //   ippsAutoCorrNorm_64fc

        static inline void CartToPolar(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_32f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }
        static inline void CartToPolar(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_64f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }
        static inline void CartToPolar(const Ipp32fc *pSrc, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_32fc(pSrc, pDstMagn, pDstPhase, len)); }
        static inline void CartToPolar(const Ipp64fc *pSrc, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_64fc(pSrc, pDstMagn, pDstPhase, len)); }

        static inline void ConjCcs(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjCcs_32fc(pSrc, pDst, lenDst)); }
        static inline void ConjCcs(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjCcs_64fc(pSrc, pDst, lenDst)); }
        static inline void ConjCcs_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjCcs_32fc_I(pSrcDst, lenDst)); }
        static inline void ConjCcs_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjCcs_64fc_I(pSrcDst, lenDst)); }

        static inline void ConjFlip(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsConjFlip_16sc(pSrc, pDst, len)); }
        static inline void ConjFlip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsConjFlip_32fc(pSrc, pDst, len)); }
        static inline void ConjFlip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsConjFlip_64fc(pSrc, pDst, len)); }

        static inline void ConjPack(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjPack_32fc(pSrc, pDst, lenDst)); }
        static inline void ConjPack(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjPack_64fc(pSrc, pDst, lenDst)); }
        static inline void ConjPack_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPack_32fc_I(pSrcDst, lenDst)); }
        static inline void ConjPack_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPack_64fc_I(pSrcDst, lenDst)); }

        static inline void ConjPerm(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjPerm_32fc(pSrc, pDst, lenDst)); }
        static inline void ConjPerm(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjPerm_64fc(pSrc, pDst, lenDst)); }
        static inline void ConjPerm_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPerm_32fc_I(pSrcDst, lenDst)); }
        static inline void ConjPerm_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPerm_64fc_I(pSrcDst, lenDst)); }

        static inline void Conj(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsConj_16sc(pSrc, pDst, len)); }
        static inline void Conj(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsConj_32fc(pSrc, pDst, len)); }
        static inline void Conj(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsConj_64fc(pSrc, pDst, len)); }
        static inline void Conj_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsConj_16sc_I(pSrcDst, len)); }
        static inline void Conj_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsConj_32fc_I(pSrcDst, len)); }
        static inline void Conj_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsConj_64fc_I(pSrcDst, len)); }

        //   ippsConvBiased_32f

        //   ippsConvert_16f16s_Sfs
        //   ippsConvert_16f32f
        //   ippsConvert_16s16f
        //   ippsConvert_16s32f
        //   ippsConvert_16s32f_Sfs
        //   ippsConvert_16s32s
        //   ippsConvert_16s64f_Sfs
        //   ippsConvert_16s8s_Sfs
        //   ippsConvert_16u32f
        //   ippsConvert_24s32f
        //   ippsConvert_24s32s
        //   ippsConvert_24u32f
        //   ippsConvert_24u32u
        //   ippsConvert_32f16f
        //   ippsConvert_32f16s_Sfs
        //   ippsConvert_32f16u_Sfs
        //   ippsConvert_32f24s_Sfs
        //   ippsConvert_32f24u_Sfs
        //   ippsConvert_32f32s_Sfs
        //   ippsConvert_32f64f
        //   ippsConvert_32f8s_Sfs
        //   ippsConvert_32f8u_Sfs
        //   ippsConvert_32s16s
        //   ippsConvert_32s16s_Sfs
        //   ippsConvert_32s24s_Sfs
        //   ippsConvert_32s32f
        //   ippsConvert_32s32f_Sfs
        //   ippsConvert_32s64f
        //   ippsConvert_32s64f_Sfs
        //   ippsConvert_32u24u_Sfs
        //   ippsConvert_64f16s_Sfs
        //   ippsConvert_64f16u_Sfs
        //   ippsConvert_64f32f
        //   ippsConvert_64f32s_Sfs
        //   ippsConvert_64f64s_Sfs
        //   ippsConvert_64f8s_Sfs
        //   ippsConvert_64f8u_Sfs
        //   ippsConvert_64s32s_Sfs
        //   ippsConvert_64s64f
        //   ippsConvert_8s16s
        //   ippsConvert_8s32f
        //   ippsConvert_8s8u
        //   ippsConvert_8u32f
        //   ippsConvert_8u8s_Sfs

        //   ippsConvolveGetBufferSize
        //   ippsConvolve_32f
        //   ippsConvolve_64f

        //   ippsCopyBE_1u
        //   ippsCopyLE_1u

        static inline void Copy(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsCopy_8u(pSrc, pDst, len)); }                        // unsigned char
        static inline void Copy(const Ipp8s *pSrc, Ipp8s *pDst, int len) { AssertNoError(ippsCopy_8u((Ipp8u *)pSrc, (Ipp8u *)pDst, len)); }      // signed char  // REUSE
        static inline void Copy(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // unsigned short  // REUSE
        static inline void Copy(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsCopy_16s(pSrc, pDst, len)); }                     // signed short
        static inline void Copy(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsCopy_32s((Ipp32s *)pSrc, (Ipp32s *)pDst, len)); } // unsigned int
        static inline void Copy(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsCopy_32s(pSrc, pDst, len)); }                     // signed int
        static inline void Copy(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsCopy_32f(pSrc, pDst, len)); }                     // float
        static inline void Copy(const Ipp64s *pSrc, Ipp64s *pDst, int len) { AssertNoError(ippsCopy_64s(pSrc, pDst, len)); }                     // __int64 (Windows*) or long long (Linux*)
        static inline void Copy(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsCopy_64f(pSrc, pDst, len)); }                     // double
        static inline void Copy(const Ipp8sc *pSrc, Ipp8sc *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // REUSE another copy function
        static inline void Copy(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsCopy_16sc(pSrc, pDst, len)); }                  // complex short
        static inline void Copy(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { AssertNoError(ippsCopy_32sc(pSrc, pDst, len)); }                  // complex signed int
        static inline void Copy(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsCopy_32fc(pSrc, pDst, len)); }                  // complex float
        static inline void Copy(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { AssertNoError(ippsCopy_64sc(pSrc, pDst, len)); }                  // complex signed long long
        static inline void Copy(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsCopy_64fc(pSrc, pDst, len)); }                  // complex double

        //   ippsCountInRange_32s

        //   ippsCplxToReal_16sc
        //   ippsCplxToReal_32fc
        //   ippsCplxToReal_64fc

        //   ippsCrossCorrNormGetBufferSize
        //   ippsCrossCorrNorm_32f
        //   ippsCrossCorrNorm_32fc
        //   ippsCrossCorrNorm_64f
        //   ippsCrossCorrNorm_64fc

        //   ippsCubrt_32f
        //   ippsCubrt_32s16s_Sfs

        //   ippsDCTFwdGetSize_32f
        //   ippsDCTFwdGetSize_64f
        //   ippsDCTFwdInit_32f
        //   ippsDCTFwdInit_64f
        //   ippsDCTFwd_32f
        //   ippsDCTFwd_32f_I
        //   ippsDCTFwd_64f
        //   ippsDCTFwd_64f_I
        //   ippsDCTInvGetSize_32f
        //   ippsDCTInvGetSize_64f
        //   ippsDCTInvInit_32f
        //   ippsDCTInvInit_64f
        //   ippsDCTInv_32f
        //   ippsDCTInv_32f_I
        //   ippsDCTInv_64f
        //   ippsDCTInv_64f_I
        //   ippsDFTFwd_CToC_16fc
        //   ippsDFTFwd_CToC_32f
        //   ippsDFTFwd_CToC_32fc
        //   ippsDFTFwd_CToC_64f
        //   ippsDFTFwd_CToC_64fc
        //   ippsDFTFwd_Direct_CToC_16fc
        //   ippsDFTFwd_RToCCS_32f
        //   ippsDFTFwd_RToCCS_64f
        //   ippsDFTFwd_RToPack_32f
        //   ippsDFTFwd_RToPack_64f
        //   ippsDFTFwd_RToPerm_32f
        //   ippsDFTFwd_RToPerm_64f
        //   ippsDFTGetSize_C_16fc
        //   ippsDFTGetSize_C_32f
        //   ippsDFTGetSize_C_32fc
        //   ippsDFTGetSize_C_64f
        //   ippsDFTGetSize_C_64fc
        //   ippsDFTGetSize_R_32f
        //   ippsDFTGetSize_R_64f
        //   ippsDFTInit_C_16fc
        //   ippsDFTInit_C_32f
        //   ippsDFTInit_C_32fc
        //   ippsDFTInit_C_64f
        //   ippsDFTInit_C_64fc
        //   ippsDFTInit_R_32f
        //   ippsDFTInit_R_64f
        //   ippsDFTInv_CCSToR_32f
        //   ippsDFTInv_CCSToR_64f
        //   ippsDFTInv_CToC_16fc
        //   ippsDFTInv_CToC_32f
        //   ippsDFTInv_CToC_32fc
        //   ippsDFTInv_CToC_64f
        //   ippsDFTInv_CToC_64fc
        //   ippsDFTInv_Direct_CToC_16fc
        //   ippsDFTInv_PackToR_32f
        //   ippsDFTInv_PackToR_64f
        //   ippsDFTInv_PermToR_32f
        //   ippsDFTInv_PermToR_64f

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

        static inline void DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pDp) { AssertNoError(ippsDotProd_32f(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { AssertNoError(ippsDotProd_32fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32fc *pDp) { AssertNoError(ippsDotProd_32f32fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp64f *pDp) { AssertNoError(ippsDotProd_32f64f(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp32f *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_32f32fc64fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pDp) { AssertNoError(ippsDotProd_64f(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_64fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp64f *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64fc *pDp) { AssertNoError(ippsDotProd_64f64fc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp64s *pDp) { AssertNoError(ippsDotProd_16s64s(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp16sc *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { AssertNoError(ippsDotProd_16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp16s *pSrc1, const Ipp16sc *pSrc2, int len, Ipp64sc *pDp) { AssertNoError(ippsDotProd_16s16sc64sc(pSrc1, pSrc2, len, pDp)); }
        static inline void DotProd(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pDp) { AssertNoError(ippsDotProd_16s32f(pSrc1, pSrc2, len, pDp)); }

        static inline void Exp(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsExp_32f(pSrc, pDst, len)); }
        static inline void Exp(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsExp_64f(pSrc, pDst, len)); }
        static inline void Exp_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsExp_32f_I(pSrcDst, len)); }
        static inline void Exp_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsExp_64f_I(pSrcDst, len)); }

        //   ippsFFTFwd_CToC_16fc
        //   ippsFFTFwd_CToC_32f
        //   ippsFFTFwd_CToC_32f_I
        //   ippsFFTFwd_CToC_32fc
        //   ippsFFTFwd_CToC_32fc_I
        //   ippsFFTFwd_CToC_64f
        //   ippsFFTFwd_CToC_64f_I
        //   ippsFFTFwd_CToC_64fc
        //   ippsFFTFwd_CToC_64fc_I
        //   ippsFFTFwd_RToCCS_32f
        //   ippsFFTFwd_RToCCS_32f_I
        //   ippsFFTFwd_RToCCS_64f
        //   ippsFFTFwd_RToCCS_64f_I
        //   ippsFFTFwd_RToPack_32f
        //   ippsFFTFwd_RToPack_32f_I
        //   ippsFFTFwd_RToPack_64f
        //   ippsFFTFwd_RToPack_64f_I
        //   ippsFFTFwd_RToPerm_32f
        //   ippsFFTFwd_RToPerm_32f_I
        //   ippsFFTFwd_RToPerm_64f
        //   ippsFFTFwd_RToPerm_64f_I
        //   ippsFFTGetSize_C_16fc
        //   ippsFFTGetSize_C_32f
        //   ippsFFTGetSize_C_32fc
        //   ippsFFTGetSize_C_64f
        //   ippsFFTGetSize_C_64fc
        //   ippsFFTGetSize_R_32f
        //   ippsFFTGetSize_R_64f
        //   ippsFFTInit_C_16fc
        //   ippsFFTInit_C_32f
        //   ippsFFTInit_C_32fc
        //   ippsFFTInit_C_64f
        //   ippsFFTInit_C_64fc
        //   ippsFFTInit_R_32f
        //   ippsFFTInit_R_64f
        //   ippsFFTInv_CCSToR_32f
        //   ippsFFTInv_CCSToR_32f_I
        //   ippsFFTInv_CCSToR_64f
        //   ippsFFTInv_CCSToR_64f_I
        //   ippsFFTInv_CToC_16fc
        //   ippsFFTInv_CToC_32f
        //   ippsFFTInv_CToC_32f_I
        //   ippsFFTInv_CToC_32fc
        //   ippsFFTInv_CToC_32fc_I
        //   ippsFFTInv_CToC_64f
        //   ippsFFTInv_CToC_64f_I
        //   ippsFFTInv_CToC_64fc
        //   ippsFFTInv_CToC_64fc_I
        //   ippsFFTInv_PackToR_32f
        //   ippsFFTInv_PackToR_32f_I
        //   ippsFFTInv_PackToR_64f
        //   ippsFFTInv_PackToR_64f_I
        //   ippsFFTInv_PermToR_32f
        //   ippsFFTInv_PermToR_32f_I
        //   ippsFFTInv_PermToR_64f
        //   ippsFFTInv_PermToR_64f_I

        //   ippsFIRGenBandpass_64f
        //   ippsFIRGenBandstop_64f
        //   ippsFIRGenGetBufferSize
        //   ippsFIRGenHighpass_64f
        //   ippsFIRGenLowpass_64f

        //   ippsFIRLMS32f_16s
        //   ippsFIRLMSGetDlyLine32f_16s
        //   ippsFIRLMSGetDlyLine_32f
        //   ippsFIRLMSGetStateSize32f_16s
        //   ippsFIRLMSGetStateSize_32f
        //   ippsFIRLMSGetTaps32f_16s
        //   ippsFIRLMSGetTaps_32f
        //   ippsFIRLMSInit32f_16s
        //   ippsFIRLMSInit_32f
        //   ippsFIRLMSSetDlyLine32f_16s
        //   ippsFIRLMSSetDlyLine_32f
        //   ippsFIRLMS_32f

        //   ippsFIRMR32f_32fc
        //   ippsFIRMRGetSize
        //   ippsFIRMRGetSize32f_32fc
        //   ippsFIRMRInit32f_32fc
        //   ippsFIRMRInit_32f
        //   ippsFIRMRInit_32fc
        //   ippsFIRMRInit_64f
        //   ippsFIRMRInit_64fc
        //   ippsFIRMR_16s
        //   ippsFIRMR_16sc
        //   ippsFIRMR_32f
        //   ippsFIRMR_32fc
        //   ippsFIRMR_64f
        //   ippsFIRMR_64fc
        //   ippsFIRSR32f_32fc
        //   ippsFIRSRGetSize
        //   ippsFIRSRGetSize32f_32fc
        //   ippsFIRSRInit32f_32fc
        //   ippsFIRSRInit_32f
        //   ippsFIRSRInit_32fc
        //   ippsFIRSRInit_64f
        //   ippsFIRSRInit_64fc
        //   ippsFIRSR_16s
        //   ippsFIRSR_16sc
        //   ippsFIRSR_32f
        //   ippsFIRSR_32fc
        //   ippsFIRSR_64f
        //   ippsFIRSR_64fc
        //   ippsFIRSparseGetDlyLine_32f
        //   ippsFIRSparseGetDlyLine_32fc
        //   ippsFIRSparseGetStateSize_32f
        //   ippsFIRSparseGetStateSize_32fc
        //   ippsFIRSparseInit_32f
        //   ippsFIRSparseInit_32fc
        //   ippsFIRSparseSetDlyLine_32f
        //   ippsFIRSparseSetDlyLine_32fc
        //   ippsFIRSparse_32f
        //   ippsFIRSparse_32fc
        //   ippsFilterMedianGetBufferSize
        //   ippsFilterMedian_16s
        //   ippsFilterMedian_16s_I
        //   ippsFilterMedian_32f
        //   ippsFilterMedian_32f_I
        //   ippsFilterMedian_32s
        //   ippsFilterMedian_32s_I
        //   ippsFilterMedian_64f
        //   ippsFilterMedian_64f_I
        //   ippsFilterMedian_8u
        //   ippsFilterMedian_8u_I

        //   ippsFindNearestOne_16u
        //   ippsFindNearest_16u

        static inline void Flip(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsFlip_8u(pSrc, pDst, len)); }
        static inline void Flip(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsFlip_16u(pSrc, pDst, len)); }
        static inline void Flip(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsFlip_32f(pSrc, pDst, len)); }
        static inline void Flip(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsFlip_64f(pSrc, pDst, len)); }
        static inline void Flip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsFlip_32fc(pSrc, pDst, len)); }
        static inline void Flip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsFlip_64fc(pSrc, pDst, len)); }
        static inline void Flip_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsFlip_16u_I(pSrcDst, len)); }
        static inline void Flip_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsFlip_8u_I(pSrcDst, len)); }
        static inline void Flip_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsFlip_32f_I(pSrcDst, len)); }
        static inline void Flip_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsFlip_64f_I(pSrcDst, len)); }
        static inline void Flip_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsFlip_32fc_I(pSrcDst, len)); }
        static inline void Flip_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsFlip_64fc_I(pSrcDst, len)); }

        //   ippsFree
        //   ippsGetLibVersion

        static inline void Goertz(const Ipp32f *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { AssertNoError(ippsGoertz_32f(pSrc, len, pVal, rFreq)); }
        static inline void Goertz(const Ipp64f *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { AssertNoError(ippsGoertz_64f(pSrc, len, pVal, rFreq)); }
        static inline void Goertz(const Ipp32fc *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { AssertNoError(ippsGoertz_32fc(pSrc, len, pVal, rFreq)); }
        static inline void Goertz(const Ipp64fc *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { AssertNoError(ippsGoertz_64fc(pSrc, len, pVal, rFreq)); }
        static inline void Goertz_Sfs(const Ipp16s *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { AssertNoError(ippsGoertz_16s_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }
        static inline void Goertz_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { AssertNoError(ippsGoertz_16sc_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }

        //   ippsHilbertGetSize_32f32fc
        //   ippsHilbertGetSize_64f64fc
        //   ippsHilbertInit_32f32fc
        //   ippsHilbertInit_64f64fc
        //   ippsHilbert_32f32fc
        //   ippsHilbert_64f64fc
        //   ippsIIR32f_16s_ISfs
        //   ippsIIR32f_16s_Sfs
        //   ippsIIR32fc_16sc_ISfs
        //   ippsIIR32fc_16sc_Sfs
        //   ippsIIR64f_16s_ISfs
        //   ippsIIR64f_16s_Sfs
        //   ippsIIR64f_32f
        //   ippsIIR64f_32f_I
        //   ippsIIR64f_32s_IPSfs
        //   ippsIIR64f_32s_ISfs
        //   ippsIIR64f_32s_PSfs
        //   ippsIIR64f_32s_Sfs
        //   ippsIIR64fc_16sc_ISfs
        //   ippsIIR64fc_16sc_Sfs
        //   ippsIIR64fc_32fc
        //   ippsIIR64fc_32fc_I
        //   ippsIIR64fc_32sc_ISfs
        //   ippsIIR64fc_32sc_Sfs
        //   ippsIIRGenGetBufferSize
        //   ippsIIRGenHighpass_64f
        //   ippsIIRGenLowpass_64f
        //   ippsIIRGetDlyLine32f_16s
        //   ippsIIRGetDlyLine32fc_16sc
        //   ippsIIRGetDlyLine64f_16s
        //   ippsIIRGetDlyLine64f_32f
        //   ippsIIRGetDlyLine64f_32s
        //   ippsIIRGetDlyLine64f_DF1_32s
        //   ippsIIRGetDlyLine64fc_16sc
        //   ippsIIRGetDlyLine64fc_32fc
        //   ippsIIRGetDlyLine64fc_32sc
        //   ippsIIRGetDlyLine_32f
        //   ippsIIRGetDlyLine_32fc
        //   ippsIIRGetDlyLine_64f
        //   ippsIIRGetDlyLine_64fc
        //   ippsIIRGetStateSize32f_16s
        //   ippsIIRGetStateSize32f_BiQuad_16s
        //   ippsIIRGetStateSize32fc_16sc
        //   ippsIIRGetStateSize32fc_BiQuad_16sc
        //   ippsIIRGetStateSize64f_16s
        //   ippsIIRGetStateSize64f_32f
        //   ippsIIRGetStateSize64f_32s
        //   ippsIIRGetStateSize64f_BiQuad_16s
        //   ippsIIRGetStateSize64f_BiQuad_32f
        //   ippsIIRGetStateSize64f_BiQuad_32s
        //   ippsIIRGetStateSize64f_BiQuad_DF1_32s
        //   ippsIIRGetStateSize64fc_16sc
        //   ippsIIRGetStateSize64fc_32fc
        //   ippsIIRGetStateSize64fc_32sc
        //   ippsIIRGetStateSize64fc_BiQuad_16sc
        //   ippsIIRGetStateSize64fc_BiQuad_32fc
        //   ippsIIRGetStateSize64fc_BiQuad_32sc
        //   ippsIIRGetStateSize_32f
        //   ippsIIRGetStateSize_32fc
        //   ippsIIRGetStateSize_64f
        //   ippsIIRGetStateSize_64fc
        //   ippsIIRGetStateSize_BiQuad_32f
        //   ippsIIRGetStateSize_BiQuad_32fc
        //   ippsIIRGetStateSize_BiQuad_64f
        //   ippsIIRGetStateSize_BiQuad_64fc
        //   ippsIIRGetStateSize_BiQuad_DF1_32f
        //   ippsIIRIIR64f_32f
        //   ippsIIRIIR64f_32f_I
        //   ippsIIRIIRGetDlyLine64f_32f
        //   ippsIIRIIRGetDlyLine_32f
        //   ippsIIRIIRGetDlyLine_64f
        //   ippsIIRIIRGetStateSize64f_32f
        //   ippsIIRIIRGetStateSize_32f
        //   ippsIIRIIRGetStateSize_64f
        //   ippsIIRIIRInit64f_32f
        //   ippsIIRIIRInit_32f
        //   ippsIIRIIRInit_64f
        //   ippsIIRIIRSetDlyLine64f_32f
        //   ippsIIRIIRSetDlyLine_32f
        //   ippsIIRIIRSetDlyLine_64f
        //   ippsIIRIIR_32f
        //   ippsIIRIIR_32f_I
        //   ippsIIRIIR_64f
        //   ippsIIRIIR_64f_I
        //   ippsIIRInit32f_16s
        //   ippsIIRInit32f_BiQuad_16s
        //   ippsIIRInit32fc_16sc
        //   ippsIIRInit32fc_BiQuad_16sc
        //   ippsIIRInit64f_16s
        //   ippsIIRInit64f_32f
        //   ippsIIRInit64f_32s
        //   ippsIIRInit64f_BiQuad_16s
        //   ippsIIRInit64f_BiQuad_32f
        //   ippsIIRInit64f_BiQuad_32s
        //   ippsIIRInit64f_BiQuad_DF1_32s
        //   ippsIIRInit64fc_16sc
        //   ippsIIRInit64fc_32fc
        //   ippsIIRInit64fc_32sc
        //   ippsIIRInit64fc_BiQuad_16sc
        //   ippsIIRInit64fc_BiQuad_32fc
        //   ippsIIRInit64fc_BiQuad_32sc
        //   ippsIIRInit_32f
        //   ippsIIRInit_32fc
        //   ippsIIRInit_64f
        //   ippsIIRInit_64fc
        //   ippsIIRInit_BiQuad_32f
        //   ippsIIRInit_BiQuad_32fc
        //   ippsIIRInit_BiQuad_64f
        //   ippsIIRInit_BiQuad_64fc
        //   ippsIIRInit_BiQuad_DF1_32f
        //   ippsIIRSetDlyLine32f_16s
        //   ippsIIRSetDlyLine32fc_16sc
        //   ippsIIRSetDlyLine64f_16s
        //   ippsIIRSetDlyLine64f_32f
        //   ippsIIRSetDlyLine64f_32s
        //   ippsIIRSetDlyLine64f_DF1_32s
        //   ippsIIRSetDlyLine64fc_16sc
        //   ippsIIRSetDlyLine64fc_32fc
        //   ippsIIRSetDlyLine64fc_32sc
        //   ippsIIRSetDlyLine_32f
        //   ippsIIRSetDlyLine_32fc
        //   ippsIIRSetDlyLine_64f
        //   ippsIIRSetDlyLine_64fc
        //   ippsIIRSparseGetStateSize_32f
        //   ippsIIRSparseInit_32f
        //   ippsIIRSparse_32f
        //   ippsIIR_32f
        //   ippsIIR_32f_I
        //   ippsIIR_32f_IP
        //   ippsIIR_32f_P
        //   ippsIIR_32fc
        //   ippsIIR_32fc_I
        //   ippsIIR_64f
        //   ippsIIR_64f_I
        //   ippsIIR_64fc
        //   ippsIIR_64fc_I

        static inline void Imag(const Ipp16sc *pSrc, Ipp16s *pDstIm, int len) { AssertNoError(ippsImag_16sc(pSrc, pDstIm, len)); }
        static inline void Imag(const Ipp32fc *pSrc, Ipp32f *pDstIm, int len) { AssertNoError(ippsImag_32fc(pSrc, pDstIm, len)); }
        static inline void Imag(const Ipp64fc *pSrc, Ipp64f *pDstIm, int len) { AssertNoError(ippsImag_64fc(pSrc, pDstIm, len)); }

        static inline void LShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { AssertNoError(ippsLShiftC_8u(pSrc, val, pDst, len)); }
        static inline void LShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { AssertNoError(ippsLShiftC_16s(pSrc, val, pDst, len)); }
        static inline void LShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { AssertNoError(ippsLShiftC_16u(pSrc, val, pDst, len)); }
        static inline void LShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { AssertNoError(ippsLShiftC_32s(pSrc, val, pDst, len)); }
        static inline void LShiftC_I(int val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsLShiftC_8u_I(val, pSrcDst, len)); }
        static inline void LShiftC_I(int val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsLShiftC_16u_I(val, pSrcDst, len)); }
        static inline void LShiftC_I(int val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsLShiftC_16s_I(val, pSrcDst, len)); }
        static inline void LShiftC_I(int val, Ipp32s *pSrcDst, int len) { AssertNoError(ippsLShiftC_32s_I(val, pSrcDst, len)); }

        static inline void Ln(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsLn_32f(pSrc, pDst, len)); }
        static inline void Ln(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsLn_64f(pSrc, pDst, len)); }
        static inline void Ln_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsLn_32f_I(pSrcDst, len)); }
        static inline void Ln_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsLn_64f_I(pSrcDst, len)); }

        static inline void Magnitude(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void Magnitude(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsMagnitude_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void Magnitude(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_32fc(pSrc, pDst, len)); }
        static inline void Magnitude(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsMagnitude_64fc(pSrc, pDst, len)); }
        static inline void Magnitude(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_16s32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void Magnitude(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_16sc32f(pSrc, pDst, len)); }

        // ippsMalloc
        // limited to 2GB of memory
        template <typename T>
        static inline T *ippsMalloc(int len) { return ippsMalloc_8u(len); } // default
        template <>
        Ipp8u *ippsMalloc<Ipp8u>(int len) { return ippsMalloc_8u(len); }
        template <>
        Ipp16u *ippsMalloc<Ipp16u>(int len) { return ippsMalloc_16u(len); }
        template <>
        Ipp32u *ippsMalloc<Ipp32u>(int len) { return ippsMalloc_32u(len); }
        template <>
        Ipp8s *ippsMalloc<Ipp8s>(int len) { return ippsMalloc_8s(len); }
        template <>
        Ipp16s *ippsMalloc<Ipp16s>(int len) { return ippsMalloc_16s(len); }
        template <>
        Ipp32s *ippsMalloc<Ipp32s>(int len) { return ippsMalloc_32s(len); }
        template <>
        Ipp64s *ippsMalloc<Ipp64s>(int len) { return ippsMalloc_64s(len); }
        template <>
        Ipp32f *ippsMalloc<Ipp32f>(int len) { return ippsMalloc_32f(len); }
        template <>
        Ipp64f *ippsMalloc<Ipp64f>(int len) { return ippsMalloc_64f(len); }
        template <>
        Ipp8sc *ippsMalloc<Ipp8sc>(int len) { return ippsMalloc_8sc(len); }
        template <>
        Ipp16sc *ippsMalloc<Ipp16sc>(int len) { return ippsMalloc_16sc(len); }
        template <>
        Ipp32sc *ippsMalloc<Ipp32sc>(int len) { return ippsMalloc_32sc(len); }
        template <>
        Ipp64sc *ippsMalloc<Ipp64sc>(int len) { return ippsMalloc_64sc(len); }
        template <>
        Ipp32fc *ippsMalloc<Ipp32fc>(int len) { return ippsMalloc_32fc(len); }
        template <>
        Ipp64fc *ippsMalloc<Ipp64fc>(int len) { return ippsMalloc_64fc(len); }
        template <>
        std::complex<float> *ippsMalloc<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc(len)); }
        template <>
        std::complex<double> *ippsMalloc<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc(len)); }

        // ippsMalloc_L
        // platform aware function -- introduced in 2017
        template <typename T>
        static inline T *ippsMalloc_L(int len) { return ippsMalloc_8u_L(len); } // default
        template <>
        Ipp8u *ippsMalloc_L<Ipp8u>(int len) { return ippsMalloc_8u_L(len); }
        template <>
        Ipp16u *ippsMalloc_L<Ipp16u>(int len) { return ippsMalloc_16u_L(len); }
        template <>
        Ipp32u *ippsMalloc_L<Ipp32u>(int len) { return ippsMalloc_32u_L(len); }
        template <>
        Ipp8s *ippsMalloc_L<Ipp8s>(int len) { return ippsMalloc_8s_L(len); }
        template <>
        Ipp16s *ippsMalloc_L<Ipp16s>(int len) { return ippsMalloc_16s_L(len); }
        template <>
        Ipp32s *ippsMalloc_L<Ipp32s>(int len) { return ippsMalloc_32s_L(len); }
        template <>
        Ipp64s *ippsMalloc_L<Ipp64s>(int len) { return ippsMalloc_64s_L(len); }
        template <>
        Ipp32f *ippsMalloc_L<Ipp32f>(int len) { return ippsMalloc_32f_L(len); }
        template <>
        Ipp64f *ippsMalloc_L<Ipp64f>(int len) { return ippsMalloc_64f_L(len); }
        template <>
        Ipp8sc *ippsMalloc_L<Ipp8sc>(int len) { return ippsMalloc_8sc_L(len); }
        template <>
        Ipp16sc *ippsMalloc_L<Ipp16sc>(int len) { return ippsMalloc_16sc_L(len); }
        template <>
        Ipp32sc *ippsMalloc_L<Ipp32sc>(int len) { return ippsMalloc_32sc_L(len); }
        template <>
        Ipp64sc *ippsMalloc_L<Ipp64sc>(int len) { return ippsMalloc_64sc_L(len); }
        template <>
        Ipp32fc *ippsMalloc_L<Ipp32fc>(int len) { return ippsMalloc_32fc_L(len); }
        template <>
        Ipp64fc *ippsMalloc_L<Ipp64fc>(int len) { return ippsMalloc_64fc_L(len); }
        template <>
        std::complex<float> *ippsMalloc_L<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc_L(len)); }
        template <>
        std::complex<double> *ippsMalloc_L<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc_L(len)); }

        static inline void MaxAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_16s(pSrc, len, pMaxAbs, pIndx)); }
        static inline void MaxAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_32s(pSrc, len, pMaxAbs, pIndx)); }
        static inline void MaxAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_32f(pSrc, len, pMaxAbs, pIndx)); }
        static inline void MaxAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs, int *pIndx) { AssertNoError(ippsMaxAbsIndx_64f(pSrc, len, pMaxAbs, pIndx)); }

        static inline void MaxAbs(const Ipp16s *pSrc, int len, Ipp16s *pMaxAbs) { AssertNoError(ippsMaxAbs_16s(pSrc, len, pMaxAbs)); }
        static inline void MaxAbs(const Ipp32s *pSrc, int len, Ipp32s *pMaxAbs) { AssertNoError(ippsMaxAbs_32s(pSrc, len, pMaxAbs)); }
        static inline void MaxAbs(const Ipp32f *pSrc, int len, Ipp32f *pMaxAbs) { AssertNoError(ippsMaxAbs_32f(pSrc, len, pMaxAbs)); }
        static inline void MaxAbs(const Ipp64f *pSrc, int len, Ipp64f *pMaxAbs) { AssertNoError(ippsMaxAbs_64f(pSrc, len, pMaxAbs)); }

        static inline void MaxEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline void MaxEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline void MaxEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline void MaxEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { AssertNoError(ippsMaxEvery_64f(pSrc1, pSrc2, pDst, len)); }
        static inline void MinEvery(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_8u(pSrc1, pSrc2, pDst, len)); }
        static inline void MinEvery(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_16u(pSrc1, pSrc2, pDst, len)); }
        static inline void MinEvery(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_32f(pSrc1, pSrc2, pDst, len)); }
        static inline void MinEvery(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32u len) { AssertNoError(ippsMinEvery_64f(pSrc1, pSrc2, pDst, len)); }
        static inline void MaxEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsMaxEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline void MaxEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsMaxEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline void MaxEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMaxEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline void MaxEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { AssertNoError(ippsMaxEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline void MaxEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMaxEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline void MaxEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { AssertNoError(ippsMaxEvery_64f_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsMinEvery_8u_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsMinEvery_16u_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp16s *pSrc, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMinEvery_16s_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp32s *pSrc, Ipp32s *pSrcDst, int len) { AssertNoError(ippsMinEvery_32s_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMinEvery_32f_I(pSrc, pSrcDst, len)); }
        static inline void MinEvery_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, Ipp32u len) { AssertNoError(ippsMinEvery_64f_I(pSrc, pSrcDst, len)); }

        static inline void MaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_16s(pSrc, len, pMax, pIndx)); }
        static inline void MaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_32s(pSrc, len, pMax, pIndx)); }
        static inline void MaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_32f(pSrc, len, pMax, pIndx)); }
        static inline void MaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMax, int *pIndx) { AssertNoError(ippsMaxIndx_64f(pSrc, len, pMax, pIndx)); }

        static inline void MaxOrder(const Ipp16s *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_16s(pSrc, len, pOrder)); }
        static inline void MaxOrder(const Ipp32s *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_32s(pSrc, len, pOrder)); }
        static inline void MaxOrder(const Ipp32f *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_32f(pSrc, len, pOrder)); }
        static inline void MaxOrder(const Ipp64f *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_64f(pSrc, len, pOrder)); }

        static inline void Max(const Ipp16s *pSrc, int len, Ipp16s *pMax) { AssertNoError(ippsMax_16s(pSrc, len, pMax)); }
        static inline void Max(const Ipp32s *pSrc, int len, Ipp32s *pMax) { AssertNoError(ippsMax_32s(pSrc, len, pMax)); }
        static inline void Max(const Ipp32f *pSrc, int len, Ipp32f *pMax) { AssertNoError(ippsMax_32f(pSrc, len, pMax)); }
        static inline void Max(const Ipp64f *pSrc, int len, Ipp64f *pMax) { AssertNoError(ippsMax_64f(pSrc, len, pMax)); }

        static inline void MeanStdDev(const Ipp32f *pSrc, int len, Ipp32f *pMean, Ipp32f *pStdDev) { AssertNoError(ippsMeanStdDev_32f(pSrc, len, pMean, pStdDev, ippAlgHintAccurate)); }
        static inline void MeanStdDev(const Ipp64f *pSrc, int len, Ipp64f *pMean, Ipp64f *pStdDev) { AssertNoError(ippsMeanStdDev_64f(pSrc, len, pMean, pStdDev)); }

        static inline void Mean(const Ipp32f *pSrc, int len, Ipp32f *pMean) { AssertNoError(ippsMean_32f(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline void Mean(const Ipp32fc *pSrc, int len, Ipp32fc *pMean) { AssertNoError(ippsMean_32fc(pSrc, len, pMean, ippAlgHintAccurate)); }
        static inline void Mean(const Ipp64f *pSrc, int len, Ipp64f *pMean) { AssertNoError(ippsMean_64f(pSrc, len, pMean)); }
        static inline void Mean(const Ipp64fc *pSrc, int len, Ipp64fc *pMean) { AssertNoError(ippsMean_64fc(pSrc, len, pMean)); }

        static inline void MinAbsIndx(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_16s(pSrc, len, pMinAbs, pIndx)); }
        static inline void MinAbsIndx(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_32s(pSrc, len, pMinAbs, pIndx)); }
        static inline void MinAbsIndx(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_32f(pSrc, len, pMinAbs, pIndx)); }
        static inline void MinAbsIndx(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs, int *pIndx) { AssertNoError(ippsMinAbsIndx_64f(pSrc, len, pMinAbs, pIndx)); }

        static inline void MinAbs(const Ipp16s *pSrc, int len, Ipp16s *pMinAbs) { AssertNoError(ippsMinAbs_16s(pSrc, len, pMinAbs)); }
        static inline void MinAbs(const Ipp32s *pSrc, int len, Ipp32s *pMinAbs) { AssertNoError(ippsMinAbs_32s(pSrc, len, pMinAbs)); }
        static inline void MinAbs(const Ipp32f *pSrc, int len, Ipp32f *pMinAbs) { AssertNoError(ippsMinAbs_32f(pSrc, len, pMinAbs)); }
        static inline void MinAbs(const Ipp64f *pSrc, int len, Ipp64f *pMinAbs) { AssertNoError(ippsMinAbs_64f(pSrc, len, pMinAbs)); }

        static inline void MinIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pIndx) { AssertNoError(ippsMinIndx_16s(pSrc, len, pMin, pIndx)); }
        static inline void MinIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pIndx) { AssertNoError(ippsMinIndx_32s(pSrc, len, pMin, pIndx)); }
        static inline void MinIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pIndx) { AssertNoError(ippsMinIndx_32f(pSrc, len, pMin, pIndx)); }
        static inline void MinIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pIndx) { AssertNoError(ippsMinIndx_64f(pSrc, len, pMin, pIndx)); }

        static inline void MinMaxIndx(const Ipp8u *pSrc, int len, Ipp8u *pMin, int *pMinIndx, Ipp8u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_8u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp16u *pSrc, int len, Ipp16u *pMin, int *pMinIndx, Ipp16u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_16u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp16s *pSrc, int len, Ipp16s *pMin, int *pMinIndx, Ipp16s *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_16s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp32u *pSrc, int len, Ipp32u *pMin, int *pMinIndx, Ipp32u *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32u(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp32s *pSrc, int len, Ipp32s *pMin, int *pMinIndx, Ipp32s *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32s(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp32f *pSrc, int len, Ipp32f *pMin, int *pMinIndx, Ipp32f *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_32f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }
        static inline void MinMaxIndx(const Ipp64f *pSrc, int len, Ipp64f *pMin, int *pMinIndx, Ipp64f *pMax, int *pMaxIndx) { AssertNoError(ippsMinMaxIndx_64f(pSrc, len, pMin, pMinIndx, pMax, pMaxIndx)); }

        static inline void MinMax(const Ipp8u *pSrc, int len, Ipp8u *pMin, Ipp8u *pMax) { AssertNoError(ippsMinMax_8u(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp16u *pSrc, int len, Ipp16u *pMin, Ipp16u *pMax) { AssertNoError(ippsMinMax_16u(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp16s *pSrc, int len, Ipp16s *pMin, Ipp16s *pMax) { AssertNoError(ippsMinMax_16s(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp32u *pSrc, int len, Ipp32u *pMin, Ipp32u *pMax) { AssertNoError(ippsMinMax_32u(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp32s *pSrc, int len, Ipp32s *pMin, Ipp32s *pMax) { AssertNoError(ippsMinMax_32s(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp32f *pSrc, int len, Ipp32f *pMin, Ipp32f *pMax) { AssertNoError(ippsMinMax_32f(pSrc, len, pMin, pMax)); }
        static inline void MinMax(const Ipp64f *pSrc, int len, Ipp64f *pMin, Ipp64f *pMax) { AssertNoError(ippsMinMax_64f(pSrc, len, pMin, pMax)); }

        static inline void Min(const Ipp16s *pSrc, int len, Ipp16s *pMin) { AssertNoError(ippsMin_16s(pSrc, len, pMin)); }
        static inline void Min(const Ipp32s *pSrc, int len, Ipp32s *pMin) { AssertNoError(ippsMin_32s(pSrc, len, pMin)); }
        static inline void Min(const Ipp32f *pSrc, int len, Ipp32f *pMin) { AssertNoError(ippsMin_32f(pSrc, len, pMin)); }
        static inline void Min(const Ipp64f *pSrc, int len, Ipp64f *pMin) { AssertNoError(ippsMin_64f(pSrc, len, pMin)); }

        static inline void Move(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsMove_8u(pSrc, pDst, len)); }
        static inline void Move(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsMove_16s(pSrc, pDst, len)); }
        static inline void Move(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsMove_32s(pSrc, pDst, len)); }
        static inline void Move(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMove_32f(pSrc, pDst, len)); }
        static inline void Move(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsMove_64f(pSrc, pDst, len)); }
        static inline void Move(const Ipp64s *pSrc, Ipp64s *pDst, int len) { AssertNoError(ippsMove_64s(pSrc, pDst, len)); }
        static inline void Move(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsMove_16sc(pSrc, pDst, len)); }
        static inline void Move(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { AssertNoError(ippsMove_32sc(pSrc, pDst, len)); }
        static inline void Move(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsMove_32fc(pSrc, pDst, len)); }
        static inline void Move(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { AssertNoError(ippsMove_64sc(pSrc, pDst, len)); }
        static inline void Move(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsMove_64fc(pSrc, pDst, len)); }

        static inline void MulC(const Ipp32f *pSrc, Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsMulC_32f(pSrc, val, pDst, len)); }
        static inline void MulC(const Ipp64f *pSrc, Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsMulC_64f(pSrc, val, pDst, len)); }
        static inline void MulC(const Ipp32fc *pSrc, Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsMulC_32fc(pSrc, val, pDst, len)); }
        static inline void MulC(const Ipp64fc *pSrc, Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsMulC_64fc(pSrc, val, pDst, len)); }
        static inline void MulC_I(Ipp16s val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsMulC_16s_I(val, pSrcDst, len)); }
        static inline void MulC_I(Ipp32f val, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulC_32f_I(val, pSrcDst, len)); }
        static inline void MulC_I(Ipp64f val, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulC_64f_I(val, pSrcDst, len)); }
        static inline void MulC_I(Ipp32fc val, Ipp32fc *pSrcDst, int len) { AssertNoError(ippsMulC_32fc_I(val, pSrcDst, len)); }
        static inline void MulC_I(Ipp64fc val, Ipp64fc *pSrcDst, int len) { AssertNoError(ippsMulC_64fc_I(val, pSrcDst, len)); }

        static inline void MulPackConj_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPackConj_32f_I(pSrc, pSrcDst, len)); }
        static inline void MulPackConj_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPackConj_64f_I(pSrc, pSrcDst, len)); }

        static inline void MulPack(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMulPack_32f(pSrc1, pSrc2, pDst, len)); }
        static inline void MulPack(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsMulPack_64f(pSrc1, pSrc2, pDst, len)); }
        static inline void MulPack_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPack_32f_I(pSrc, pSrcDst, len)); }
        static inline void MulPack_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPack_64f_I(pSrc, pSrcDst, len)); }

        static inline void MulPerm(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMulPerm_32f(pSrc1, pSrc2, pDst, len)); }
        static inline void MulPerm(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsMulPerm_64f(pSrc1, pSrc2, pDst, len)); }
        static inline void MulPerm_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPerm_32f_I(pSrc, pSrcDst, len)); }
        static inline void MulPerm_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPerm_64f_I(pSrc, pSrcDst, len)); }

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

        static inline void NormDiff_Inf(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_Inf(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_Inf_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_Inf(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_Inf(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_Inf_32fc32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_Inf(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_Inf_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L1(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L1_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L1(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L1(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L1_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L1(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L1(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L1_64fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L2(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L2_32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L2(const Ipp64f *pSrc1, const Ipp64f *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L2(const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len, Ipp32f *pNorm) { AssertNoError(ippsNormDiff_L2_16s32f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L2(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_32fc64f(pSrc1, pSrc2, len, pNorm)); }
        static inline void NormDiff_L2(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, int len, Ipp64f *pNorm) { AssertNoError(ippsNormDiff_L2_64fc64f(pSrc1, pSrc2, len, pNorm)); }

        static inline void Norm_Inf(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_32f(pSrc, len, pNorm)); }
        static inline void Norm_Inf(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_Inf_64f(pSrc, len, pNorm)); }
        static inline void Norm_Inf(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_16s32f(pSrc, len, pNorm)); }
        static inline void Norm_Inf(const Ipp32fc *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_Inf_32fc32f(pSrc, len, pNorm)); }
        static inline void Norm_Inf(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_Inf_64fc64f(pSrc, len, pNorm)); }
        static inline void Norm_L1(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L1_32f(pSrc, len, pNorm)); }
        static inline void Norm_L1(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_64f(pSrc, len, pNorm)); }
        static inline void Norm_L1(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L1_16s32f(pSrc, len, pNorm)); }
        static inline void Norm_L1(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_32fc64f(pSrc, len, pNorm)); }
        static inline void Norm_L1(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L1_64fc64f(pSrc, len, pNorm)); }
        static inline void Norm_L2(const Ipp32f *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L2_32f(pSrc, len, pNorm)); }
        static inline void Norm_L2(const Ipp64f *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_64f(pSrc, len, pNorm)); }
        static inline void Norm_L2(const Ipp16s *pSrc, int len, Ipp32f *pNorm) { AssertNoError(ippsNorm_L2_16s32f(pSrc, len, pNorm)); }
        static inline void Norm_L2(const Ipp32fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_32fc64f(pSrc, len, pNorm)); }
        static inline void Norm_L2(const Ipp64fc *pSrc, int len, Ipp64f *pNorm) { AssertNoError(ippsNorm_L2_64fc64f(pSrc, len, pNorm)); }

        static inline void Normalize(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32f(pSrc, pDst, len, vSub, vDiv)); }
        static inline void Normalize(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64f(pSrc, pDst, len, vSub, vDiv)); }
        static inline void Normalize(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32fc vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32fc(pSrc, pDst, len, vSub, vDiv)); }
        static inline void Normalize(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64fc vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64fc(pSrc, pDst, len, vSub, vDiv)); }

        static inline void Normalize_I(Ipp32f *pSrcDst, int len, Ipp32f vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32f_I(pSrcDst, len, vSub, vDiv)); }
        static inline void Normalize_I(Ipp64f *pSrcDst, int len, Ipp64f vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64f_I(pSrcDst, len, vSub, vDiv)); }
        static inline void Normalize_I(Ipp32fc *pSrcDst, int len, Ipp32fc vSub, Ipp32f vDiv) { AssertNoError(ippsNormalize_32fc_I(pSrcDst, len, vSub, vDiv)); }
        static inline void Normalize_I(Ipp64fc *pSrcDst, int len, Ipp64fc vSub, Ipp64f vDiv) { AssertNoError(ippsNormalize_64fc_I(pSrcDst, len, vSub, vDiv)); }

        static inline void Not(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsNot_8u(pSrc, pDst, len)); }
        static inline void Not(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsNot_16u(pSrc, pDst, len)); }
        static inline void Not(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsNot_32u(pSrc, pDst, len)); }

        static inline void Not_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsNot_8u_I(pSrcDst, len)); }
        static inline void Not_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsNot_16u_I(pSrcDst, len)); }
        static inline void Not_I(Ipp32u *pSrcDst, int len) { AssertNoError(ippsNot_32u_I(pSrcDst, len)); }

        static inline void OrC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsOrC_8u(pSrc, val, pDst, len)); }
        static inline void OrC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsOrC_16u(pSrc, val, pDst, len)); }
        static inline void OrC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { AssertNoError(ippsOrC_32u(pSrc, val, pDst, len)); }

        static inline void OrC_I(Ipp8u val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsOrC_8u_I(val, pSrcDst, len)); }
        static inline void OrC_I(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsOrC_16u_I(val, pSrcDst, len)); }
        static inline void OrC_I(Ipp32u val, Ipp32u *pSrcDst, int len) { AssertNoError(ippsOrC_32u_I(val, pSrcDst, len)); }

        static inline void Or(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, int len) { AssertNoError(ippsOr_8u(pSrc1, pSrc2, pDst, len)); }
        static inline void Or(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { AssertNoError(ippsOr_16u(pSrc1, pSrc2, pDst, len)); }
        static inline void Or(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { AssertNoError(ippsOr_32u(pSrc1, pSrc2, pDst, len)); }

        static inline void Or_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsOr_8u_I(pSrc, pSrcDst, len)); }
        static inline void Or_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsOr_16u_I(pSrc, pSrcDst, len)); }
        static inline void Or_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { AssertNoError(ippsOr_32u_I(pSrc, pSrcDst, len)); }

        //   ippsPatternMatchGetBufferSize
        //   ippsPatternMatch_8u16u

        static inline void Phase(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsPhase_64fc(pSrc, pDst, len)); }
        static inline void Phase(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_32fc(pSrc, pDst, len)); }
        static inline void Phase(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_16sc32f(pSrc, pDst, len)); }
        static inline void Phase(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsPhase_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void Phase(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void Phase(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_16s32f(pSrcRe, pSrcIm, pDst, len)); }

        static inline void PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { AssertNoError(ippsPolarToCart_32f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
        static inline void PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { AssertNoError(ippsPolarToCart_64f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
        static inline void PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32fc *pDst, int len) { AssertNoError(ippsPolarToCart_32fc(pSrcMagn, pSrcPhase, pDst, len)); }
        static inline void PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64fc *pDst, int len) { AssertNoError(ippsPolarToCart_64fc(pSrcMagn, pSrcPhase, pDst, len)); }

        static inline void PowerSpectr(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsPowerSpectr_64fc(pSrc, pDst, len)); }
        static inline void PowerSpectr(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_32fc(pSrc, pDst, len)); }
        static inline void PowerSpectr(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsPowerSpectr_64f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void PowerSpectr(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void PowerSpectr(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_16s32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void PowerSpectr(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_16sc32f(pSrc, pDst, len)); }

        static inline void RShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { AssertNoError(ippsRShiftC_8u(pSrc, val, pDst, len)); }
        static inline void RShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { AssertNoError(ippsRShiftC_16s(pSrc, val, pDst, len)); }
        static inline void RShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { AssertNoError(ippsRShiftC_16u(pSrc, val, pDst, len)); }
        static inline void RShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { AssertNoError(ippsRShiftC_32s(pSrc, val, pDst, len)); }
        static inline void RShiftC(int val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsRShiftC_8u_I(val, pSrcDst, len)); }
        static inline void RShiftC(int val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsRShiftC_16u_I(val, pSrcDst, len)); }
        static inline void RShiftC(int val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsRShiftC_16s_I(val, pSrcDst, len)); }
        static inline void RShiftC(int val, Ipp32s *pSrcDst, int len) { AssertNoError(ippsRShiftC_32s_I(val, pSrcDst, len)); }

        //   ippsRandGaussGetSize_16s
        //   ippsRandGaussGetSize_32f
        //   ippsRandGaussGetSize_64f
        //   ippsRandGaussGetSize_8u
        //   ippsRandGaussInit_16s
        //   ippsRandGaussInit_32f
        //   ippsRandGaussInit_64f
        //   ippsRandGaussInit_8u
        //   ippsRandGauss_16s
        //   ippsRandGauss_32f
        //   ippsRandGauss_64f
        //   ippsRandGauss_8u
        //   ippsRandUniformGetSize_16s
        //   ippsRandUniformGetSize_32f
        //   ippsRandUniformGetSize_64f
        //   ippsRandUniformGetSize_8u
        //   ippsRandUniformInit_16s
        //   ippsRandUniformInit_32f
        //   ippsRandUniformInit_64f
        //   ippsRandUniformInit_8u
        //   ippsRandUniform_16s
        //   ippsRandUniform_32f
        //   ippsRandUniform_64f
        //   ippsRandUniform_8u

        static inline void RealToCplx(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp16sc *pDst, int len) { AssertNoError(ippsRealToCplx_16s(pSrcRe, pSrcIm, pDst, len)); }
        static inline void RealToCplx(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32fc *pDst, int len) { AssertNoError(ippsRealToCplx_32f(pSrcRe, pSrcIm, pDst, len)); }
        static inline void RealToCplx(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64fc *pDst, int len) { AssertNoError(ippsRealToCplx_64f(pSrcRe, pSrcIm, pDst, len)); }

        static inline void Real(const Ipp16sc *pSrc, Ipp16s *pDstRe, int len) { AssertNoError(ippsReal_16sc(pSrc, pDstRe, len)); }
        static inline void Real(const Ipp32fc *pSrc, Ipp32f *pDstRe, int len) { AssertNoError(ippsReal_32fc(pSrc, pDstRe, len)); }
        static inline void Real(const Ipp64fc *pSrc, Ipp64f *pDstRe, int len) { AssertNoError(ippsReal_64fc(pSrc, pDstRe, len)); }

        static inline void ReplaceNAN(Ipp32f *pSrcDst, int len, Ipp32f value) { AssertNoError(ippsReplaceNAN_32f_I(pSrcDst, len, value)); }
        static inline void ReplaceNAN(Ipp64f *pSrcDst, int len, Ipp64f value) { AssertNoError(ippsReplaceNAN_64f_I(pSrcDst, len, value)); }

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

        static inline void SampleDown(const Ipp16s *pSrc, int srcLen, Ipp16s *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_16s(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleDown(const Ipp32f *pSrc, int srcLen, Ipp32f *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_32f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleDown(const Ipp64f *pSrc, int srcLen, Ipp64f *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_64f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleDown(const Ipp16sc *pSrc, int srcLen, Ipp16sc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_16sc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleDown(const Ipp32fc *pSrc, int srcLen, Ipp32fc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_32fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleDown(const Ipp64fc *pSrc, int srcLen, Ipp64fc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleDown_64fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }

        static inline void SampleUp(const Ipp16s *pSrc, int srcLen, Ipp16s *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_16s(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleUp(const Ipp32f *pSrc, int srcLen, Ipp32f *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_32f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleUp(const Ipp64f *pSrc, int srcLen, Ipp64f *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_64f(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleUp(const Ipp16sc *pSrc, int srcLen, Ipp16sc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_16sc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleUp(const Ipp32fc *pSrc, int srcLen, Ipp32fc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_32fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }
        static inline void SampleUp(const Ipp64fc *pSrc, int srcLen, Ipp64fc *pDst, int *pDstLen, int factor, int *pPhase) { AssertNoError(ippsSampleUp_64fc(pSrc, srcLen, pDst, pDstLen, factor, pPhase)); }

        static inline void Set(Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsSet_8u(val, pDst, len)); }
        static inline void Set(Ipp16s val, Ipp16s *pDst, int len) { AssertNoError(ippsSet_16s(val, pDst, len)); }
        static inline void Set(Ipp16sc val, Ipp16sc *pDst, int len) { AssertNoError(ippsSet_16sc(val, pDst, len)); }
        static inline void Set(Ipp32s val, Ipp32s *pDst, int len) { AssertNoError(ippsSet_32s(val, pDst, len)); }
        static inline void Set(Ipp32f val, Ipp32f *pDst, int len) { AssertNoError(ippsSet_32f(val, pDst, len)); }
        static inline void Set(Ipp32sc val, Ipp32sc *pDst, int len) { AssertNoError(ippsSet_32sc(val, pDst, len)); }
        static inline void Set(Ipp32fc val, Ipp32fc *pDst, int len) { AssertNoError(ippsSet_32fc(val, pDst, len)); }
        static inline void Set(Ipp64s val, Ipp64s *pDst, int len) { AssertNoError(ippsSet_64s(val, pDst, len)); }
        static inline void Set(Ipp64f val, Ipp64f *pDst, int len) { AssertNoError(ippsSet_64f(val, pDst, len)); }
        static inline void Set(Ipp64sc val, Ipp64sc *pDst, int len) { AssertNoError(ippsSet_64sc(val, pDst, len)); }
        static inline void Set(Ipp64fc val, Ipp64fc *pDst, int len) { AssertNoError(ippsSet_64fc(val, pDst, len)); }

        static inline void SortAscend_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSortAscend_8u_I(pSrcDst, len)); }
        static inline void SortAscend_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSortAscend_16u_I(pSrcDst, len)); }
        static inline void SortAscend_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsSortAscend_16s_I(pSrcDst, len)); }
        static inline void SortAscend_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsSortAscend_32s_I(pSrcDst, len)); }
        static inline void SortAscend_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSortAscend_32f_I(pSrcDst, len)); }
        static inline void SortAscend_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSortAscend_64f_I(pSrcDst, len)); }

        static inline void SortDescend_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSortDescend_8u_I(pSrcDst, len)); }
        static inline void SortDescend_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSortDescend_16u_I(pSrcDst, len)); }
        static inline void SortDescend_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsSortDescend_16s_I(pSrcDst, len)); }
        static inline void SortDescend_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsSortDescend_32s_I(pSrcDst, len)); }
        static inline void SortDescend_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSortDescend_32f_I(pSrcDst, len)); }
        static inline void SortDescend_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSortDescend_64f_I(pSrcDst, len)); }

        static inline void SortIndexAscend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_8u_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexAscend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_16u_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexAscend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_16s_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexAscend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_32s_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexAscend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_32f_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexAscend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_64f_I(pSrcDst, pDstIdx, len)); }

        static inline void SortIndexDescend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_8u_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexDescend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_16u_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexDescend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_16s_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexDescend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_32s_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexDescend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_32f_I(pSrcDst, pDstIdx, len)); }
        static inline void SortIndexDescend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_64f_I(pSrcDst, pDstIdx, len)); }

        //   ippsSortRadixAscend_16s_I
        //   ippsSortRadixAscend_16u_I
        //   ippsSortRadixAscend_32f_I
        //   ippsSortRadixAscend_32f_I_L
        //   ippsSortRadixAscend_32s_I
        //   ippsSortRadixAscend_32s_I_L
        //   ippsSortRadixAscend_32u_I
        //   ippsSortRadixAscend_64f_I
        //   ippsSortRadixAscend_64f_I_L
        //   ippsSortRadixAscend_64s_I
        //   ippsSortRadixAscend_64s_I_L
        //   ippsSortRadixAscend_64u_I
        //   ippsSortRadixAscend_64u_I_L
        //   ippsSortRadixAscend_8u_I
        //   ippsSortRadixDescend_16s_I
        //   ippsSortRadixDescend_16u_I
        //   ippsSortRadixDescend_32f_I
        //   ippsSortRadixDescend_32f_I_L
        //   ippsSortRadixDescend_32s_I
        //   ippsSortRadixDescend_32s_I_L
        //   ippsSortRadixDescend_32u_I
        //   ippsSortRadixDescend_64f_I
        //   ippsSortRadixDescend_64f_I_L
        //   ippsSortRadixDescend_64s_I
        //   ippsSortRadixDescend_64s_I_L
        //   ippsSortRadixDescend_64u_I
        //   ippsSortRadixDescend_64u_I_L
        //   ippsSortRadixDescend_8u_I
        //   ippsSortRadixGetBufferSize
        //   ippsSortRadixGetBufferSize_L
        //   ippsSortRadixIndexAscend_16s
        //   ippsSortRadixIndexAscend_16u
        //   ippsSortRadixIndexAscend_32f
        //   ippsSortRadixIndexAscend_32s
        //   ippsSortRadixIndexAscend_32u
        //   ippsSortRadixIndexAscend_64f
        //   ippsSortRadixIndexAscend_64s
        //   ippsSortRadixIndexAscend_64s_L
        //   ippsSortRadixIndexAscend_64u
        //   ippsSortRadixIndexAscend_64u_L
        //   ippsSortRadixIndexAscend_8u
        //   ippsSortRadixIndexDescend_16s
        //   ippsSortRadixIndexDescend_16u
        //   ippsSortRadixIndexDescend_32f
        //   ippsSortRadixIndexDescend_32s
        //   ippsSortRadixIndexDescend_32u
        //   ippsSortRadixIndexDescend_64f
        //   ippsSortRadixIndexDescend_64s
        //   ippsSortRadixIndexDescend_64s_L
        //   ippsSortRadixIndexDescend_64u
        //   ippsSortRadixIndexDescend_64u_L
        //   ippsSortRadixIndexDescend_8u
        //   ippsSortRadixIndexGetBufferSize
        //   ippsSortRadixIndexGetBufferSize_L

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

        static inline void StdDev(const Ipp32f *pSrc, int len, Ipp32f *pStdDev) { AssertNoError(ippsStdDev_32f(pSrc, len, pStdDev, ippAlgHintAccurate)); }
        static inline void StdDev(const Ipp64f *pSrc, int len, Ipp64f *pStdDev) { AssertNoError(ippsStdDev_64f(pSrc, len, pStdDev)); }

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

        static inline void SumLn(const Ipp32f *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSumLn_32f(pSrc, len, pSum)); }
        static inline void SumLn(const Ipp64f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSumLn_64f(pSrc, len, pSum)); }
        static inline void SumLn(const Ipp32f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSumLn_32f64f(pSrc, len, pSum)); }
        static inline void SumLn(const Ipp16s *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSumLn_16s32f(pSrc, len, pSum)); }

        static inline void SumWindow(const Ipp8u *pSrc, Ipp32f *pDst, int len, int maskSize) { AssertNoError(ippsSumWindow_8u32f(pSrc, pDst, len, maskSize)); }
        static inline void SumWindow(const Ipp16s *pSrc, Ipp32f *pDst, int len, int maskSize) { AssertNoError(ippsSumWindow_16s32f(pSrc, pDst, len, maskSize)); }

        static inline void Sum(const Ipp32f *pSrc, int len, Ipp32f *pSum) { AssertNoError(ippsSum_32f(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline void Sum(const Ipp32fc *pSrc, int len, Ipp32fc *pSum) { AssertNoError(ippsSum_32fc(pSrc, len, pSum, ippAlgHintAccurate)); }
        static inline void Sum(const Ipp64f *pSrc, int len, Ipp64f *pSum) { AssertNoError(ippsSum_64f(pSrc, len, pSum)); }
        static inline void Sum(const Ipp64fc *pSrc, int len, Ipp64fc *pSum) { AssertNoError(ippsSum_64fc(pSrc, len, pSum)); }

        static inline void Sum_Sfs(const Ipp16s *pSrc, int len, Ipp16s *pSum, int scaleFactor) { AssertNoError(ippsSum_16s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline void Sum_Sfs(const Ipp32s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { AssertNoError(ippsSum_32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline void Sum_Sfs(const Ipp16s *pSrc, int len, Ipp32s *pSum, int scaleFactor) { AssertNoError(ippsSum_16s32s_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline void Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pSum, int scaleFactor) { AssertNoError(ippsSum_16sc_Sfs(pSrc, len, pSum, scaleFactor)); }
        static inline void Sum_Sfs(const Ipp16sc *pSrc, int len, Ipp32sc *pSum, int scaleFactor) { AssertNoError(ippsSum_16sc32sc_Sfs(pSrc, len, pSum, scaleFactor)); }

        static inline void SwapBytes(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsSwapBytes_16u(pSrc, pDst, len)); }
        static inline void SwapBytes(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsSwapBytes_24u(pSrc, pDst, len)); }
        static inline void SwapBytes(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsSwapBytes_32u(pSrc, pDst, len)); }
        static inline void SwapBytes(const Ipp64u *pSrc, Ipp64u *pDst, int len) { AssertNoError(ippsSwapBytes_64u(pSrc, pDst, len)); }
        static inline void SwapBytes_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_16u_I(pSrcDst, len)); }
        static inline void SwapBytes_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_24u_I(pSrcDst, len)); }
        static inline void SwapBytes_I(Ipp32u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_32u_I(pSrcDst, len)); }
        static inline void SwapBytes_I(Ipp64u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_64u_I(pSrcDst, len)); }

        static inline void Threshold_LTAbsVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTAbsVal_32f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTAbsVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTAbsVal_64f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTAbsVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTAbsVal_16s(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTAbsVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s level, Ipp32s value) { AssertNoError(ippsThreshold_LTAbsVal_32s(pSrc, pDst, len, level, value)); }

        static inline void Threshold_LTAbsVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTAbsVal_32f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTAbsVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTAbsVal_64f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTAbsVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTAbsVal_16s_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTAbsVal_I(Ipp32s *pSrcDst, int len, Ipp32s level, Ipp32s value) { AssertNoError(ippsThreshold_LTAbsVal_32s_I(pSrcDst, len, level, value)); }

        static inline void Threshold_LTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTVal_16s(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTVal_32f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTVal_64f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_LTVal_16sc(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_LTVal_32fc(pSrc, pDst, len, level, value)); }
        static inline void Threshold_LTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_LTVal_64fc(pSrc, pDst, len, level, value)); }

        static inline void Threshold_GTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_GTVal_16s(pSrc, pDst, len, level, value)); }
        static inline void Threshold_GTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_GTVal_32f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_GTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_GTVal_64f(pSrc, pDst, len, level, value)); }
        static inline void Threshold_GTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_GTVal_16sc(pSrc, pDst, len, level, value)); }
        static inline void Threshold_GTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_GTVal_32fc(pSrc, pDst, len, level, value)); }
        static inline void Threshold_GTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_GTVal_64fc(pSrc, pDst, len, level, value)); }

        static inline void Threshold_LTValGTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_16s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline void Threshold_LTValGTVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline void Threshold_LTValGTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32f(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }

        static inline void Threshold_LTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTVal_16s_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTVal_32f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTVal_64f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_LTVal_16sc_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_LTVal_32fc_I(pSrcDst, len, level, value)); }
        static inline void Threshold_LTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_LTVal_64fc_I(pSrcDst, len, level, value)); }

        static inline void Threshold_GTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_GTVal_16s_I(pSrcDst, len, level, value)); }
        static inline void Threshold_GTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_GTVal_32f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_GTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_GTVal_64f_I(pSrcDst, len, level, value)); }
        static inline void Threshold_GTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_GTVal_16sc_I(pSrcDst, len, level, value)); }
        static inline void Threshold_GTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_GTVal_32fc_I(pSrcDst, len, level, value)); }
        static inline void Threshold_GTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_GTVal_64fc_I(pSrcDst, len, level, value)); }

        static inline void Threshold_LTValGTVal_I(Ipp16s *pSrcDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_16s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline void Threshold_LTValGTVal_I(Ipp32s *pSrcDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline void Threshold_LTValGTVal_I(Ipp32f *pSrcDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
        static inline void Threshold_LTValGTVal_I(Ipp64f *pSrcDst, int len, Ipp64f levelLT, Ipp64f valueLT, Ipp64f levelGT, Ipp64f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_64f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }

        static inline void Tone(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_16s(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline void Tone(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_16sc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline void Tone(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_32f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline void Tone(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f *pPhase) { AssertNoError(ippsTone_32fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline void Tone(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { AssertNoError(ippsTone_64f(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }
        static inline void Tone(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f *pPhase) { AssertNoError(ippsTone_64fc(pDst, len, magn, rFreq, pPhase, ippAlgHintAccurate)); }

        //   ippsTopKGetBufferSize
        //   ippsTopKInit_32f
        //   ippsTopKInit_32s
        //   ippsTopK_32f
        //   ippsTopK_32s
        static inline void Triangle(Ipp16s *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_16s(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline void Triangle(Ipp16sc *pDst, int len, Ipp16s magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_16sc(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline void Triangle(Ipp32f *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_32f(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline void Triangle(Ipp32fc *pDst, int len, Ipp32f magn, Ipp32f rFreq, Ipp32f asym, Ipp32f *pPhase) { AssertNoError(ippsTriangle_32fc(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline void Triangle(Ipp64f *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { AssertNoError(ippsTriangle_64f(pDst, len, magn, rFreq, asym, pPhase)); }
        static inline void Triangle(Ipp64fc *pDst, int len, Ipp64f magn, Ipp64f rFreq, Ipp64f asym, Ipp64f *pPhase) { AssertNoError(ippsTriangle_64fc(pDst, len, magn, rFreq, asym, pPhase)); }

        static inline void VectorJaehne(Ipp8u *pDst, int len, Ipp8u magn) { AssertNoError(ippsVectorJaehne_8u(pDst, len, magn)); }
        static inline void VectorJaehne(Ipp16u *pDst, int len, Ipp16u magn) { AssertNoError(ippsVectorJaehne_16u(pDst, len, magn)); }
        static inline void VectorJaehne(Ipp16s *pDst, int len, Ipp16s magn) { AssertNoError(ippsVectorJaehne_16s(pDst, len, magn)); }
        static inline void VectorJaehne(Ipp32s *pDst, int len, Ipp32s magn) { AssertNoError(ippsVectorJaehne_32s(pDst, len, magn)); }
        static inline void VectorJaehne(Ipp32f *pDst, int len, Ipp32f magn) { AssertNoError(ippsVectorJaehne_32f(pDst, len, magn)); }
        static inline void VectorJaehne(Ipp64f *pDst, int len, Ipp64f magn) { AssertNoError(ippsVectorJaehne_64f(pDst, len, magn)); }

        static inline void VectorSlope(Ipp8u *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_8u(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp16u *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_16u(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp16s *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_16s(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp32u *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_32u(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp32s *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_32s(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp32f *pDst, int len, Ipp32f offset, Ipp32f slope) { AssertNoError(ippsVectorSlope_32f(pDst, len, offset, slope)); }
        static inline void VectorSlope(Ipp64f *pDst, int len, Ipp64f offset, Ipp64f slope) { AssertNoError(ippsVectorSlope_64f(pDst, len, offset, slope)); }

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
        static inline void WinBartlett(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsWinBartlett_16s(pSrc, pDst, len)); }
        static inline void WinBartlett(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsWinBartlett_32f(pSrc, pDst, len)); }
        static inline void WinBartlett(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsWinBartlett_64f(pSrc, pDst, len)); }
        static inline void WinBartlett(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsWinBartlett_16sc(pSrc, pDst, len)); }
        static inline void WinBartlett(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsWinBartlett_32fc(pSrc, pDst, len)); }
        static inline void WinBartlett(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsWinBartlett_64fc(pSrc, pDst, len)); }
        static inline void WinBartlett_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsWinBartlett_16s_I(pSrcDst, len)); }
        static inline void WinBartlett_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsWinBartlett_32f_I(pSrcDst, len)); }
        static inline void WinBartlett_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsWinBartlett_64f_I(pSrcDst, len)); }
        static inline void WinBartlett_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsWinBartlett_16sc_I(pSrcDst, len)); }
        static inline void WinBartlett_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsWinBartlett_32fc_I(pSrcDst, len)); }
        static inline void WinBartlett_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsWinBartlett_64fc_I(pSrcDst, len)); }

        static inline void WinBlackman(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_16s(pSrc, pDst, len, alpha)); }
        static inline void WinBlackman(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_16sc(pSrc, pDst, len, alpha)); }
        static inline void WinBlackman(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_32f(pSrc, pDst, len, alpha)); }
        static inline void WinBlackman(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_32fc(pSrc, pDst, len, alpha)); }
        static inline void WinBlackman(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { AssertNoError(ippsWinBlackman_64f(pSrc, pDst, len, alpha)); }
        static inline void WinBlackman(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { AssertNoError(ippsWinBlackman_64fc(pSrc, pDst, len, alpha)); }

        static inline void WinBlackmanStd(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsWinBlackmanStd_16s(pSrc, pDst, len)); }
        static inline void WinBlackmanStd(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsWinBlackmanStd_16sc(pSrc, pDst, len)); }
        static inline void WinBlackmanStd(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsWinBlackmanStd_32f(pSrc, pDst, len)); }
        static inline void WinBlackmanStd(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsWinBlackmanStd_32fc(pSrc, pDst, len)); }
        static inline void WinBlackmanStd(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsWinBlackmanStd_64f(pSrc, pDst, len)); }
        static inline void WinBlackmanStd(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsWinBlackmanStd_64fc(pSrc, pDst, len)); }

        static inline void WinBlackmanOpt(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_16s(pSrc, pDst, len)); }
        static inline void WinBlackmanOpt(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_16sc(pSrc, pDst, len)); }
        static inline void WinBlackmanOpt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_32f(pSrc, pDst, len)); }
        static inline void WinBlackmanOpt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_32fc(pSrc, pDst, len)); }
        static inline void WinBlackmanOpt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_64f(pSrc, pDst, len)); }
        static inline void WinBlackmanOpt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsWinBlackmanOpt_64fc(pSrc, pDst, len)); }

        static inline void WinBlackman_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_16s_I(pSrcDst, len, alpha)); }
        static inline void WinBlackman_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_16sc_I(pSrcDst, len, alpha)); }
        static inline void WinBlackman_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_32f_I(pSrcDst, len, alpha)); }
        static inline void WinBlackman_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinBlackman_32fc_I(pSrcDst, len, alpha)); }
        static inline void WinBlackman_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { AssertNoError(ippsWinBlackman_64f_I(pSrcDst, len, alpha)); }
        static inline void WinBlackman_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { AssertNoError(ippsWinBlackman_64fc_I(pSrcDst, len, alpha)); }

        static inline void WinBlackmanOpt_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_16s_I(pSrcDst, len)); }
        static inline void WinBlackmanOpt_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_16sc_I(pSrcDst, len)); }
        static inline void WinBlackmanOpt_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_32f_I(pSrcDst, len)); }
        static inline void WinBlackmanOpt_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_32fc_I(pSrcDst, len)); }
        static inline void WinBlackmanOpt_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_64f_I(pSrcDst, len)); }
        static inline void WinBlackmanOpt_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanOpt_64fc_I(pSrcDst, len)); }

        static inline void WinBlackmanStd_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_16s_I(pSrcDst, len)); }
        static inline void WinBlackmanStd_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_16sc_I(pSrcDst, len)); }
        static inline void WinBlackmanStd_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_32f_I(pSrcDst, len)); }
        static inline void WinBlackmanStd_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_32fc_I(pSrcDst, len)); }
        static inline void WinBlackmanStd_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_64f_I(pSrcDst, len)); }
        static inline void WinBlackmanStd_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsWinBlackmanStd_64fc_I(pSrcDst, len)); }

        static inline void WinHamming(Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsWinHamming_16s(pSrc, pDst, len)); }
        static inline void WinHamming(Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsWinHamming_32f(pSrc, pDst, len)); }
        static inline void WinHamming(Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsWinHamming_64f(pSrc, pDst, len)); }
        static inline void WinHamming(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsWinHamming_16sc(pSrc, pDst, len)); }
        static inline void WinHamming(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsWinHamming_32fc(pSrc, pDst, len)); }
        static inline void WinHamming(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsWinHamming_64fc(pSrc, pDst, len)); }
        static inline void WinHamming_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsWinHamming_16s_I(pSrcDst, len)); }
        static inline void WinHamming_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsWinHamming_32f_I(pSrcDst, len)); }
        static inline void WinHamming_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsWinHamming_64f_I(pSrcDst, len)); }
        static inline void WinHamming_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsWinHamming_16sc_I(pSrcDst, len)); }
        static inline void WinHamming_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsWinHamming_32fc_I(pSrcDst, len)); }
        static inline void WinHamming_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsWinHamming_64fc_I(pSrcDst, len)); }

        static inline void WinHann(Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsWinHann_16s(pSrc, pDst, len)); }
        static inline void WinHann(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsWinHann_16sc(pSrc, pDst, len)); }
        static inline void WinHann(Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsWinHann_32f(pSrc, pDst, len)); }
        static inline void WinHann(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsWinHann_32fc(pSrc, pDst, len)); }
        static inline void WinHann(Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsWinHann_64f(pSrc, pDst, len)); }
        static inline void WinHann(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsWinHann_64fc(pSrc, pDst, len)); }
        static inline void WinHann_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsWinHann_16s_I(pSrcDst, len)); }
        static inline void WinHann_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsWinHann_16sc_I(pSrcDst, len)); }
        static inline void WinHann_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsWinHann_32f_I(pSrcDst, len)); }
        static inline void WinHann_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsWinHann_32fc_I(pSrcDst, len)); }
        static inline void WinHann_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsWinHann_64f_I(pSrcDst, len)); }
        static inline void WinHann_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsWinHann_64fc_I(pSrcDst, len)); }

        static inline void WinKaiser(Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_16s(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser(Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_32f(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser(Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { AssertNoError(ippsWinKaiser_64f(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser(Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_16sc(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser(Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_32fc(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser(Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { AssertNoError(ippsWinKaiser_64fc(pSrc, pDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_16s_I(pSrcDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_32f_I(pSrcDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { AssertNoError(ippsWinKaiser_64f_I(pSrcDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_16sc_I(pSrcDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { AssertNoError(ippsWinKaiser_32fc_I(pSrcDst, len, alpha)); }
        static inline void WinKaiser_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { AssertNoError(ippsWinKaiser_64fc_I(pSrcDst, len, alpha)); }

        static inline void XorC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsXorC_8u(pSrc, val, pDst, len)); }
        static inline void XorC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsXorC_16u(pSrc, val, pDst, len)); }
        static inline void XorC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { AssertNoError(ippsXorC_32u(pSrc, val, pDst, len)); }
        static inline void XorC(Ipp8u val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsXorC_8u_I(val, pSrcDst, len)); }
        static inline void XorC(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsXorC_16u_I(val, pSrcDst, len)); }
        static inline void XorC(Ipp32u val, Ipp32u *pSrcDst, int len) { AssertNoError(ippsXorC_32u_I(val, pSrcDst, len)); }

        //   ippsZeroCrossing_16s32f
        //   ippsZeroCrossing_32f
        static inline void Zero(Ipp8u *pDst, int len) { AssertNoError(ippsZero_8u(pDst, len)); }
        static inline void Zero(Ipp16s *pDst, int len) { AssertNoError(ippsZero_16s(pDst, len)); }
        static inline void Zero(Ipp32s *pDst, int len) { AssertNoError(ippsZero_32s(pDst, len)); }
        static inline void Zero(Ipp32f *pDst, int len) { AssertNoError(ippsZero_32f(pDst, len)); }
        static inline void Zero(Ipp64s *pDst, int len) { AssertNoError(ippsZero_64s(pDst, len)); }
        static inline void Zero(Ipp64f *pDst, int len) { AssertNoError(ippsZero_64f(pDst, len)); }
        static inline void Zero(Ipp16sc *pDst, int len) { AssertNoError(ippsZero_16sc(pDst, len)); }
        static inline void Zero(Ipp32sc *pDst, int len) { AssertNoError(ippsZero_32sc(pDst, len)); }
        static inline void Zero(Ipp32fc *pDst, int len) { AssertNoError(ippsZero_32fc(pDst, len)); }
        static inline void Zero(Ipp64sc *pDst, int len) { AssertNoError(ippsZero_64sc(pDst, len)); }
        static inline void Zero(Ipp64fc *pDst, int len) { AssertNoError(ippsZero_64fc(pDst, len)); }

    }
}