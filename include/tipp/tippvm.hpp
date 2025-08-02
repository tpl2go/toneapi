#pragma once
#include <ipp/ippvm.h>
#include "tipp_error.hpp"
#include <complex>

namespace tipp
{
    namespace vm
    {
        // real valued Abs function already defined in ipps.h
        static inline IppStatus Abs(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp32fc *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Abs(const Ipp64fc *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Abs(const std::complex<float> *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_32fc_A24((Ipp32fc *)pSrc, pDst, len)); }
        static inline IppStatus Abs(const std::complex<double> *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAbs_64fc_A53((Ipp64fc *)pSrc, pDst, len)); }

        // Add function already defined in ipps.h
        static inline IppStatus Add(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAdd_32f_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAdd_64f_A53(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAdd_32fc_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Add(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAdd_64fc_A53(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Acos(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Acos(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Acos(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Acos(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Acos(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }
        static inline IppStatus Acos(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcos_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }

        static inline IppStatus Acosh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Acosh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Acosh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Acosh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Acosh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Acosh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAcosh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Arg(const Ipp32fc *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsArg_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Arg(const Ipp64fc *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsArg_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Arg(const std::complex<float> *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsArg_32fc_A24((Ipp32fc *)pSrc, pDst, len)); }
        static inline IppStatus Arg(const std::complex<double> *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsArg_64fc_A53((Ipp64fc *)pSrc, pDst, len)); }

        static inline IppStatus Asin(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Asin(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Asin(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Asin(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Asin(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Asin(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsin_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Sin(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Sin(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Sin(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Sin(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Sin(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Sin(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSin_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Asinh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Asinh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Asinh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Asinh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Asinh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Asinh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAsinh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Atan2(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan2_32f_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Atan2(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan2_64f_A53(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Atan(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Atan(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Atan(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Atan(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Atan(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Atan(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtan_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Atanh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Atanh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Atanh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Atanh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Atanh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Atanh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsAtanh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus CIS(const Ipp32f *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCIS_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus CIS(const Ipp64f *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCIS_64fc_A53(pSrc, pDst, len)); }

        static inline IppStatus Cbrt(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCbrt_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Cbrt(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCbrt_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus CdfNormInv(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCdfNormInv_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus CdfNormInv(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCdfNormInv_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus CdfNorm(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCdfNorm_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus CdfNorm(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCdfNorm_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Ceil(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCeil_32f(pSrc, pDst, len)); }
        static inline IppStatus Ceil(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCeil_64f(pSrc, pDst, len)); }

        static inline IppStatus Cos(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Cos(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Cos(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Cos(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Cos(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Cos(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCos_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Cosh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Cosh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Cosh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Cosh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Cosh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Cosh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsCosh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        // Conj function already defined in ipps.h
        // static inline IppStatus Conj(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { return OptionalAssertNoError(ippsConj_32fc_A24(pSrc, pDst, len)); }
        // static inline IppStatus Conj(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { return OptionalAssertNoError(ippsConj_64fc_A53(pSrc, pDst, len)); }

        // real valued Div function already defined in ipps.h
        // static inline IppStatus Div(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsDiv_32f_A24(pSrc1, pSrc2, pDst, len)); }
        // static inline IppStatus Div(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsDiv_64f_A53(pSrc1, pSrc2, pDst, len)); }
        // static inline IppStatus Div(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsDiv_32fc_A24(pSrc1, pSrc2, pDst, len)); }
        // static inline IppStatus Div(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsDiv_64fc_A53(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Erf(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErf_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Erf(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErf_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus ErfInv(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfInv_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus ErfInv(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfInv_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Erfc(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfc_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Erfc(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfc_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus ErfcInv(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfcInv_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus ErfcInv(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsErfcInv_64f_A53(pSrc, pDst, len)); }

        // real valued Exp function already defined in ipps.h
        // static inline IppStatus Exp(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_32f_A24(pSrc, pDst, len)); }
        // static inline IppStatus Exp(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Exp(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Exp(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Exp(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Exp(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExp_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Expm1(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExpm1_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Expm1(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsExpm1_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Floor(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsFloor_32f(pSrc, pDst, len)); }
        static inline IppStatus Floor(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsFloor_64f(pSrc, pDst, len)); }

        static inline IppStatus Frac(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsFrac_32f(pSrc, pDst, len)); }
        static inline IppStatus Frac(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsFrac_64f(pSrc, pDst, len)); }

        static inline IppStatus Hypot(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsHypot_32f_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Hypot(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsHypot_64f_A53(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus InvCbrt(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInvCbrt_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus InvCbrt(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInvCbrt_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus InvSqrt(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInvSqrt_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus InvSqrt(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInvSqrt_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Inv(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInv_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Inv(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsInv_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Ln(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLn_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Ln(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLn_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Ln(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLn_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Ln(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLn_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Log10(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Log10(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Log10(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Log10(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Log10(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Log10(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog10_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Log1p(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog1p_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Log1p(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsLog1p_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Modf(const Ipp32f *pSrc, Ipp32f *pDst1, Ipp32f *pDst2, Ipp32s len) { return OptionalAssertNoError(ippsModf_32f(pSrc, pDst1, pDst2, len)); }
        static inline IppStatus Modf(const Ipp64f *pSrc, Ipp64f *pDst1, Ipp64f *pDst2, Ipp32s len) { return OptionalAssertNoError(ippsModf_64f(pSrc, pDst1, pDst2, len)); }

        static inline IppStatus MulByConj(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsMulByConj_32fc_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulByConj(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsMulByConj_64fc_A53(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus MulByConj(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsMulByConj_32fc_A24((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus MulByConj(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsMulByConj_64fc_A53((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus NearbyInt(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsNearbyInt_32f(pSrc, pDst, len)); }
        static inline IppStatus NearbyInt(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsNearbyInt_64f(pSrc, pDst, len)); }

        static inline IppStatus Pow2o3(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow2o3_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Pow2o3(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow2o3_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Pow3o2(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow3o2_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Pow3o2(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow3o2_64f_A53(pSrc, pDst, len)); }

        static inline IppStatus Pow(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_32f_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Pow(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_64f_A53(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Pow(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_32fc_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Pow(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_64fc_A53(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Pow(const std::complex<float> *pSrc1, const std::complex<float> *pSrc2, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_32fc_A24((Ipp32fc *)pSrc1, (Ipp32fc *)pSrc2, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Pow(const std::complex<double> *pSrc1, const std::complex<double> *pSrc2, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPow_64fc_A53((Ipp64fc *)pSrc1, (Ipp64fc *)pSrc2, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Powx(const Ipp32f *pSrc1, const Ipp32f ConstValue, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_32f_A24(pSrc1, ConstValue, pDst, len)); }
        static inline IppStatus Powx(const Ipp64f *pSrc1, const Ipp64f ConstValue, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_64f_A53(pSrc1, ConstValue, pDst, len)); }
        static inline IppStatus Powx(const Ipp32fc *pSrc1, const Ipp32fc ConstValue, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_32fc_A24(pSrc1, ConstValue, pDst, len)); }
        static inline IppStatus Powx(const Ipp64fc *pSrc1, const Ipp64fc ConstValue, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_64fc_A53(pSrc1, ConstValue, pDst, len)); }
        static inline IppStatus Powx(const std::complex<float> *pSrc1, const std::complex<float> ConstValue, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_32fc_A24((Ipp32fc *)pSrc1, *((Ipp32fc *)&ConstValue), (Ipp32fc *)pDst, len)); }
        static inline IppStatus Powx(const std::complex<double> *pSrc1, const std::complex<double> ConstValue, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsPowx_64fc_A53((Ipp64fc *)pSrc1, *((Ipp64fc *)&ConstValue), (Ipp64fc *)pDst, len)); }

        static inline IppStatus Rint(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsRint_32f(pSrc, pDst, len)); }
        static inline IppStatus Rint(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsRint_64f(pSrc, pDst, len)); }

        static inline IppStatus Round(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsRound_32f(pSrc, pDst, len)); }
        static inline IppStatus Round(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsRound_64f(pSrc, pDst, len)); }

        static inline IppStatus SinCos(const Ipp32f *pSrc, Ipp32f *pDst1, Ipp32f *pDst2, Ipp32s len) { return OptionalAssertNoError(ippsSinCos_32f_A24(pSrc, pDst1, pDst2, len)); }
        static inline IppStatus SinCos(const Ipp64f *pSrc, Ipp64f *pDst1, Ipp64f *pDst2, Ipp32s len) { return OptionalAssertNoError(ippsSinCos_64f_A53(pSrc, pDst1, pDst2, len)); }

        static inline IppStatus Sinh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Sinh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Sinh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Sinh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Sinh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Sinh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSinh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        // Sqr function already defined in ipps.h
        static inline IppStatus Sqr(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqr_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Sqr(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqr_64f_A53(pSrc, pDst, len)); }

        // Sqrt function already defined in ipps.h
        static inline IppStatus Sqrt(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqrt_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqrt_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqrt_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Sqrt(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSqrt_64fc_A53(pSrc, pDst, len)); }

        // Sub function already defined in ipps.h
        static inline IppStatus Sub(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSub_32f_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSub_64f_A53(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp32fc *pSrc1, const Ipp32fc *pSrc2, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSub_32fc_A24(pSrc1, pSrc2, pDst, len)); }
        static inline IppStatus Sub(const Ipp64fc *pSrc1, const Ipp64fc *pSrc2, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsSub_64fc_A53(pSrc1, pSrc2, pDst, len)); }

        static inline IppStatus Tan(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Tan(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Tan(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Tan(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Tan(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Tan(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTan_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Tanh(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_32f_A24(pSrc, pDst, len)); }
        static inline IppStatus Tanh(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_64f_A53(pSrc, pDst, len)); }
        static inline IppStatus Tanh(const Ipp32fc *pSrc, Ipp32fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_32fc_A24(pSrc, pDst, len)); }
        static inline IppStatus Tanh(const Ipp64fc *pSrc, Ipp64fc *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_64fc_A53(pSrc, pDst, len)); }
        static inline IppStatus Tanh(const std::complex<float> *pSrc, std::complex<float> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_32fc_A24((Ipp32fc *)pSrc, (Ipp32fc *)pDst, len)); }
        static inline IppStatus Tanh(const std::complex<double> *pSrc, std::complex<double> *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTanh_64fc_A53((Ipp64fc *)pSrc, (Ipp64fc *)pDst, len)); }

        static inline IppStatus Trunc(const Ipp32f *pSrc, Ipp32f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTrunc_32f(pSrc, pDst, len)); }
        static inline IppStatus Trunc(const Ipp64f *pSrc, Ipp64f *pDst, Ipp32s len) { return OptionalAssertNoError(ippsTrunc_64f(pSrc, pDst, len)); }

    }

}
