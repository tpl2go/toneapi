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

    //   ippsAutoCorrNormGetBufferSize
    //   ippsAutoCorrNorm_32f
    //   ippsAutoCorrNorm_32fc
    //   ippsAutoCorrNorm_64f
    //   ippsAutoCorrNorm_64fc

    static inline void Goertz(const Ipp32f *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { AssertNoError(ippsGoertz_32f(pSrc, len, pVal, rFreq)); }
    static inline void Goertz(const Ipp64f *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { AssertNoError(ippsGoertz_64f(pSrc, len, pVal, rFreq)); }
    static inline void Goertz(const Ipp32fc *pSrc, int len, Ipp32fc *pVal, Ipp32f rFreq) { AssertNoError(ippsGoertz_32fc(pSrc, len, pVal, rFreq)); }
    static inline void Goertz(const Ipp64fc *pSrc, int len, Ipp64fc *pVal, Ipp64f rFreq) { AssertNoError(ippsGoertz_64fc(pSrc, len, pVal, rFreq)); }
    static inline void Goertz_Sfs(const Ipp16s *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { AssertNoError(ippsGoertz_16s_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }
    static inline void Goertz_Sfs(const Ipp16sc *pSrc, int len, Ipp16sc *pVal, Ipp32f rFreq, int scaleFactor) { AssertNoError(ippsGoertz_16sc_Sfs(pSrc, len, pVal, rFreq, scaleFactor)); }

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

    //   ippsZeroCrossing_16s32f
    //   ippsZeroCrossing_32f

}
