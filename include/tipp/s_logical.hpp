#pragma once
#include <ipp/ippcore.h>
#include <ipp/ippvm.h>
#include <ipp/ipps.h>
#include <ipp/ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <stdexcept>

namespace tipp
{

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

}
