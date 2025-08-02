#pragma once
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <complex>
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <stdexcept>

#define PI 3.14159265358979323846264338327950288419
namespace tipp {
  namespace s {
    static inline IppStatus WinBartlett(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16s(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32f(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64f(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16sc(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc(pSrc, pDst, len)); }
    static inline IppStatus WinBartlett(const std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
    static inline IppStatus WinBartlett(const std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

    static inline IppStatus WinBartlett_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16s_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32f_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64f_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_16sc_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc_I(pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_32fc_I((Ipp32fc *)pSrcDst, len)); }
    static inline IppStatus WinBartlett_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBartlett_64fc_I((Ipp64fc *)pSrcDst, len)); }

    static inline IppStatus WinBlackman(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16s(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16sc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32f(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64f(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const std::complex<float> *pSrc, std::complex<float> *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len, alpha)); }
    static inline IppStatus WinBlackman(const std::complex<double> *pSrc, std::complex<double> *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len, alpha)); }

    static inline IppStatus WinBlackmanStd(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16s(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16sc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32f(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64f(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanStd(const std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
    static inline IppStatus WinBlackmanStd(const std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

    static inline IppStatus WinBlackmanOpt(const Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16s(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16sc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32f(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64f(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc(pSrc, pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
    static inline IppStatus WinBlackmanOpt(const std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

    static inline IppStatus WinBlackman_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16s_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_16sc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32f_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64f_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(std::complex<float> *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinBlackman_32fc_I((Ipp32fc *)pSrcDst, len, alpha)); }
    static inline IppStatus WinBlackman_I(std::complex<double> *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinBlackman_64fc_I((Ipp64fc *)pSrcDst, len, alpha)); }

    static inline IppStatus WinBlackmanOpt_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16s_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_16sc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32f_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64f_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_32fc_I((Ipp32fc *)pSrcDst, len)); }
    static inline IppStatus WinBlackmanOpt_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanOpt_64fc_I((Ipp64fc *)pSrcDst, len)); }

    static inline IppStatus WinBlackmanStd_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16s_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_16sc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32f_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64f_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc_I(pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_32fc_I((Ipp32fc *)pSrcDst, len)); }
    static inline IppStatus WinBlackmanStd_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinBlackmanStd_64fc_I((Ipp64fc *)pSrcDst, len)); }

    static inline IppStatus WinHamming(Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_16s(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_32f(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_64f(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_16sc(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc(pSrc, pDst, len)); }
    static inline IppStatus WinHamming(std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
    static inline IppStatus WinHamming(std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

    static inline IppStatus WinHamming_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_16s_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_32f_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_64f_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_16sc_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc_I(pSrcDst, len)); }
    static inline IppStatus WinHamming_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_32fc_I((Ipp32fc *)pSrcDst, len)); }
    static inline IppStatus WinHamming_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHamming_64fc_I((Ipp64fc *)pSrcDst, len)); }

    static inline IppStatus WinHann(Ipp16s *pSrc, Ipp16s *pDst, int len) { return OptionalAssertNoError(ippsWinHann_16s(pSrc, pDst, len)); }
    static inline IppStatus WinHann(Ipp16sc *pSrc, Ipp16sc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_16sc(pSrc, pDst, len)); }
    static inline IppStatus WinHann(Ipp32f *pSrc, Ipp32f *pDst, int len) { return OptionalAssertNoError(ippsWinHann_32f(pSrc, pDst, len)); }
    static inline IppStatus WinHann(Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc(pSrc, pDst, len)); }
    static inline IppStatus WinHann(Ipp64f *pSrc, Ipp64f *pDst, int len) { return OptionalAssertNoError(ippsWinHann_64f(pSrc, pDst, len)); }
    static inline IppStatus WinHann(Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc(pSrc, pDst, len)); }
    static inline IppStatus WinHann(std::complex<float> *pSrc, std::complex<float> *pDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
    static inline IppStatus WinHann(std::complex<double> *pSrc, std::complex<double> *pDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

    static inline IppStatus WinHann_I(Ipp16s *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_16s_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(Ipp16sc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_16sc_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(Ipp32f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_32f_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(Ipp32fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(Ipp64f *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_64f_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(Ipp64fc *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc_I(pSrcDst, len)); }
    static inline IppStatus WinHann_I(std::complex<float> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_32fc_I((Ipp32fc *)pSrcDst, len)); }
    static inline IppStatus WinHann_I(std::complex<double> *pSrcDst, int len) { return OptionalAssertNoError(ippsWinHann_64fc_I((Ipp64fc *)pSrcDst, len)); }

    static inline IppStatus WinKaiser(Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16s(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32f(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64f(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16sc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc(pSrc, pDst, len, alpha)); }
    static inline IppStatus WinKaiser(std::complex<float> *pSrc, std::complex<float> *pDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len, alpha)); }
    static inline IppStatus WinKaiser(std::complex<double> *pSrc, std::complex<double> *pDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len, alpha)); }

    static inline IppStatus WinKaiser_I(Ipp16s *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16s_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(Ipp32f *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32f_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(Ipp64f *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64f_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(Ipp16sc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_16sc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(Ipp32fc *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(Ipp64fc *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc_I(pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(std::complex<float> *pSrcDst, int len, Ipp32f alpha) { return OptionalAssertNoError(ippsWinKaiser_32fc_I((Ipp32fc *)pSrcDst, len, alpha)); }
    static inline IppStatus WinKaiser_I(std::complex<double> *pSrcDst, int len, Ipp64f alpha) { return OptionalAssertNoError(ippsWinKaiser_64fc_I((Ipp64fc *)pSrcDst, len, alpha)); }

  } // namespace s

} // namespace tipp
