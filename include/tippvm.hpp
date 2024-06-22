#include <ippvm.h>
#include "tipp_error.hpp"
namespace ipp
{
    namespace ippvm
    {
        static inline void Abs(const Ipp32fc *pSrc, Ipp32f *pDst, Ipp32s len) { AssertNoError(ippsAbs_32fc_A24(pSrc, pDst, len)); }
        static inline void Abs(const Ipp64fc *pSrc, Ipp64f *pDst, Ipp32s len) { AssertNoError(ippsAbs_64fc_A53(pSrc, pDst, len)); }

        static inline IppStatus Cos(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return ippsCos_32f_A24(pSrc, pDst, len); }
        static inline IppStatus Cos(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return ippsCos_64f_A53(pSrc, pDst, len); }
        static inline IppStatus Cos(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return ippsCos_32fc_A24(pSrc, pDst, len); }
        static inline IppStatus Cos(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return ippsCos_64fc_A53(pSrc, pDst, len); }

        IppStatus ippsAcos_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);
        IppStatus ippsAcos_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAcos_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAcos_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);

        IppStatus ippsAcosh_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAcosh_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAcosh_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAcosh_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        // Add is already availble in ipps.hpp
        //   ippsAdd_32f_A24
        //   ippsAdd_32fc_A24
        //   ippsAdd_64f_A53
        //   ippsAdd_64fc_A53

        IppStatus ippsArg_32fc_A24(const Ipp32fc *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsArg_64fc_A53(const Ipp64fc *pSrc, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsAsin_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAsin_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAsin_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAsin_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsSin_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsSin_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsSin_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsSin_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsAsinh_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAsinh_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAsinh_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAsinh_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsAtan2_32f_A24(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAtan2_64f_A53(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsAtan_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAtan_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAtan_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAtan_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsAtanh_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsAtanh_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);
        IppStatus ippsAtanh_32fc_A24(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsAtanh_64fc_A53(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsCIS_32fc_A24(const Ipp32f *pSrc, Ipp32fc *pDst, Ipp32s len);
        IppStatus ippsCIS_64fc_A53(const Ipp64f *pSrc, Ipp64fc *pDst, Ipp32s len);

        IppStatus ippsCbrt_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsCbrt_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsCdfNormInv_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsCdfNormInv_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsCdfNorm_32f_A24(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsCdfNorm_64f_A53(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsCeil_32f(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len);
        IppStatus ippsCeil_64f(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len);

        IppStatus ippsConj_16sc(const Ipp16sc *pSrc, Ipp16sc *pDst, int len);
        IppStatus ippsConj_32fc(const Ipp32fc *pSrc, Ipp32fc *pDst, int len);
        IppStatus ippsConj_64fc(const Ipp64fc *pSrc, Ipp64fc *pDst, int len);
        IppStatus ippsConj_16sc_I(Ipp16sc *pSrcDst, int len);
        IppStatus ippsConj_32fc_I(Ipp32fc *pSrcDst, int len);
        IppStatus ippsConj_64fc_I(Ipp64fc *pSrcDst, int len);

        /**
 *
 *
 * ippsAbs_32f_A24




                  ippsCeil_32f
                  ippsCeil_64f
                  ippsConj_32fc_A24
                  ippsConj_64fc_A53
                  ippsCos_32f_A11
                  ippsCos_32f_A21
                  ippsCos_32f_A24
                  ippsCos_32fc_A11
                  ippsCos_32fc_A21
                  ippsCos_32fc_A24
                  ippsCos_64f_A26
                  ippsCos_64f_A50
                  ippsCos_64f_A53
                  ippsCos_64fc_A26
                  ippsCos_64fc_A50
                  ippsCos_64fc_A53
                  ippsCosh_32f_A11
                  ippsCosh_32f_A21
                  ippsCosh_32f_A24
                  ippsCosh_32fc_A11
                  ippsCosh_32fc_A21
                  ippsCosh_32fc_A24
                  ippsCosh_64f_A26
                  ippsCosh_64f_A50
                  ippsCosh_64f_A53
                  ippsCosh_64fc_A26
                  ippsCosh_64fc_A50
                  ippsCosh_64fc_A53
                  ippsDiv_32f_A11
                  ippsDiv_32f_A21
                  ippsDiv_32f_A24
                  ippsDiv_32fc_A11
                  ippsDiv_32fc_A21
                  ippsDiv_32fc_A24
                  ippsDiv_64f_A26
                  ippsDiv_64f_A50
                  ippsDiv_64f_A53
                  ippsDiv_64fc_A26
                  ippsDiv_64fc_A50
                  ippsDiv_64fc_A53
                  ippsErfInv_32f_A11
                  ippsErfInv_32f_A21
                  ippsErfInv_32f_A24
                  ippsErfInv_64f_A26
                  ippsErfInv_64f_A50
                  ippsErfInv_64f_A53
                  ippsErf_32f_A11
                  ippsErf_32f_A21
                  ippsErf_32f_A24
                  ippsErf_64f_A26
                  ippsErf_64f_A50
                  ippsErf_64f_A53
                  ippsErfcInv_32f_A11
                  ippsErfcInv_32f_A21
                  ippsErfcInv_32f_A24
                  ippsErfcInv_64f_A26
                  ippsErfcInv_64f_A50
                  ippsErfcInv_64f_A53
                  ippsErfc_32f_A11
                  ippsErfc_32f_A21
                  ippsErfc_32f_A24
                  ippsErfc_64f_A26
                  ippsErfc_64f_A50
                  ippsErfc_64f_A53
                  ippsExp_32f_A11
                  ippsExp_32f_A21
                  ippsExp_32f_A24
                  ippsExp_32fc_A11
                  ippsExp_32fc_A21
                  ippsExp_32fc_A24
                  ippsExp_64f_A26
                  ippsExp_64f_A50
                  ippsExp_64f_A53
                  ippsExp_64fc_A26
                  ippsExp_64fc_A50
                  ippsExp_64fc_A53
                  ippsExpm1_32f_A11
                  ippsExpm1_32f_A21
                  ippsExpm1_32f_A24
                  ippsExpm1_64f_A26
                  ippsExpm1_64f_A50
                  ippsExpm1_64f_A53
                  ippsFloor_32f
                  ippsFloor_64f
                  ippsFrac_32f
                  ippsFrac_64f
                  ippsHypot_32f_A11
                  ippsHypot_32f_A21
                  ippsHypot_32f_A24
                  ippsHypot_64f_A26
                  ippsHypot_64f_A50
                  ippsHypot_64f_A53
                  ippsInvCbrt_32f_A11
                  ippsInvCbrt_32f_A21
                  ippsInvCbrt_32f_A24
                  ippsInvCbrt_64f_A26
                  ippsInvCbrt_64f_A50
                  ippsInvCbrt_64f_A53
                  ippsInvSqrt_32f_A11
                  ippsInvSqrt_32f_A21
                  ippsInvSqrt_32f_A24
                  ippsInvSqrt_64f_A26
                  ippsInvSqrt_64f_A50
                  ippsInvSqrt_64f_A53
                  ippsInv_32f_A11
                  ippsInv_32f_A21
                  ippsInv_32f_A24
                  ippsInv_64f_A26
                  ippsInv_64f_A50
                  ippsInv_64f_A53
                  ippsLn_32f_A11
                  ippsLn_32f_A21
                  ippsLn_32f_A24
                  ippsLn_32fc_A11
                  ippsLn_32fc_A21
                  ippsLn_32fc_A24
                  ippsLn_64f_A26
                  ippsLn_64f_A50
                  ippsLn_64f_A53
                  ippsLn_64fc_A26
                  ippsLn_64fc_A50
                  ippsLn_64fc_A53
                  ippsLog10_32f_A11
                  ippsLog10_32f_A21
                  ippsLog10_32f_A24
                  ippsLog10_32fc_A11
                  ippsLog10_32fc_A21
                  ippsLog10_32fc_A24
                  ippsLog10_64f_A26
                  ippsLog10_64f_A50
                  ippsLog10_64f_A53
                  ippsLog10_64fc_A26
                  ippsLog10_64fc_A50
                  ippsLog10_64fc_A53
                  ippsLog1p_32f_A11
                  ippsLog1p_32f_A21
                  ippsLog1p_32f_A24
                  ippsLog1p_64f_A26
                  ippsLog1p_64f_A50
                  ippsLog1p_64f_A53
                  ippsModf_32f
                  ippsModf_64f
                  ippsMulByConj_32fc_A11
                  ippsMulByConj_32fc_A21
                  ippsMulByConj_32fc_A24
                  ippsMulByConj_64fc_A26
                  ippsMulByConj_64fc_A50
                  ippsMulByConj_64fc_A53
                  ippsMul_32f_A24
                  ippsMul_32fc_A11
                  ippsMul_32fc_A21
                  ippsMul_32fc_A24
                  ippsMul_64f_A53
                  ippsMul_64fc_A26
                  ippsMul_64fc_A50
                  ippsMul_64fc_A53
                  ippsNearbyInt_32f
                  ippsNearbyInt_64f
                  ippsPow2o3_32f_A11
                  ippsPow2o3_32f_A21
                  ippsPow2o3_32f_A24
                  ippsPow2o3_64f_A26
                  ippsPow2o3_64f_A50
                  ippsPow2o3_64f_A53
                  ippsPow3o2_32f_A11
                  ippsPow3o2_32f_A21
                  ippsPow3o2_32f_A24
                  ippsPow3o2_64f_A26
                  ippsPow3o2_64f_A50
                  ippsPow3o2_64f_A53
                  ippsPow_32f_A11
                  ippsPow_32f_A21
                  ippsPow_32f_A24
                  ippsPow_32fc_A11
                  ippsPow_32fc_A21
                  ippsPow_32fc_A24
                  ippsPow_64f_A26
                  ippsPow_64f_A50
                  ippsPow_64f_A53
                  ippsPow_64fc_A26
                  ippsPow_64fc_A50
                  ippsPow_64fc_A53
                  ippsPowx_32f_A11
                  ippsPowx_32f_A21
                  ippsPowx_32f_A24
                  ippsPowx_32fc_A11
                  ippsPowx_32fc_A21
                  ippsPowx_32fc_A24
                  ippsPowx_64f_A26
                  ippsPowx_64f_A50
                  ippsPowx_64f_A53
                  ippsPowx_64fc_A26
                  ippsPowx_64fc_A50
                  ippsPowx_64fc_A53
                  ippsRint_32f
                  ippsRint_64f
                  ippsRound_32f
                  ippsRound_64f
                  ippsSinCos_32f_A11
                  ippsSinCos_32f_A21
                  ippsSinCos_32f_A24
                  ippsSinCos_64f_A26
                  ippsSinCos_64f_A50
                  ippsSinCos_64f_A53
                  ippsSin_32f_A11
                  ippsSin_32f_A21
                  ippsSin_32f_A24
                  ippsSin_32fc_A11
                  ippsSin_32fc_A21
                  ippsSin_32fc_A24
                  ippsSin_64f_A26
                  ippsSin_64f_A50
                  ippsSin_64f_A53
                  ippsSin_64fc_A26
                  ippsSin_64fc_A50
                  ippsSin_64fc_A53
                  ippsSinh_32f_A11
                  ippsSinh_32f_A21
                  ippsSinh_32f_A24
                  ippsSinh_32fc_A11
                  ippsSinh_32fc_A21
                  ippsSinh_32fc_A24
                  ippsSinh_64f_A26
                  ippsSinh_64f_A50
                  ippsSinh_64f_A53
                  ippsSinh_64fc_A26
                  ippsSinh_64fc_A50
                  ippsSinh_64fc_A53
                  ippsSqr_32f_A24
                  ippsSqr_64f_A53
                  ippsSqrt_32f_A11
                  ippsSqrt_32f_A21
                  ippsSqrt_32f_A24
                  ippsSqrt_32fc_A11
                  ippsSqrt_32fc_A21
                  ippsSqrt_32fc_A24
                  ippsSqrt_64f_A26
                  ippsSqrt_64f_A50
                  ippsSqrt_64f_A53
                  ippsSqrt_64fc_A26
                  ippsSqrt_64fc_A50
                  ippsSqrt_64fc_A53
                  ippsSub_32f_A24
                  ippsSub_32fc_A24
                  ippsSub_64f_A53
                  ippsSub_64fc_A53
                  ippsTan_32f_A11
                  ippsTan_32f_A21
                  ippsTan_32f_A24
                  ippsTan_32fc_A11
                  ippsTan_32fc_A21
                  ippsTan_32fc_A24
                  ippsTan_64f_A26
                  ippsTan_64f_A50
                  ippsTan_64f_A53
                  ippsTan_64fc_A26
                  ippsTan_64fc_A50
                  ippsTan_64fc_A53
                  ippsTanh_32f_A11
                  ippsTanh_32f_A21
                  ippsTanh_32f_A24
                  ippsTanh_32fc_A11
                  ippsTanh_32fc_A21
                  ippsTanh_32fc_A24
                  ippsTanh_64f_A26
                  ippsTanh_64f_A50
                  ippsTanh_64f_A53
                  ippsTanh_64fc_A26
                  ippsTanh_64fc_A50
                  ippsTanh_64fc_A53
                  ippsTrunc_32f
                  ippsTrunc_64f
                  ippvmGetLibVersion
 */

    }
}