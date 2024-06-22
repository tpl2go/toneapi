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

    static inline void Or(const Ipp8u *pSrc1, const Ipp8u *pSrc2, Ipp8u *pDst, int len) { AssertNoError(ippsOr_8u(pSrc1, pSrc2, pDst, len)); }
    static inline void Or(const Ipp16u *pSrc1, const Ipp16u *pSrc2, Ipp16u *pDst, int len) { AssertNoError(ippsOr_16u(pSrc1, pSrc2, pDst, len)); }
    static inline void Or(const Ipp32u *pSrc1, const Ipp32u *pSrc2, Ipp32u *pDst, int len) { AssertNoError(ippsOr_32u(pSrc1, pSrc2, pDst, len)); }

    static inline void Or_I(const Ipp8u *pSrc, Ipp8u *pSrcDst, int len) { AssertNoError(ippsOr_8u_I(pSrc, pSrcDst, len)); }
    static inline void Or_I(const Ipp16u *pSrc, Ipp16u *pSrcDst, int len) { AssertNoError(ippsOr_16u_I(pSrc, pSrcDst, len)); }
    static inline void Or_I(const Ipp32u *pSrc, Ipp32u *pSrcDst, int len) { AssertNoError(ippsOr_32u_I(pSrc, pSrcDst, len)); }

    static inline void OrC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsOrC_8u(pSrc, val, pDst, len)); }
    static inline void OrC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsOrC_16u(pSrc, val, pDst, len)); }
    static inline void OrC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { AssertNoError(ippsOrC_32u(pSrc, val, pDst, len)); }

    static inline void OrC_I(Ipp8u val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsOrC_8u_I(val, pSrcDst, len)); }
    static inline void OrC_I(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsOrC_16u_I(val, pSrcDst, len)); }
    static inline void OrC_I(Ipp32u val, Ipp32u *pSrcDst, int len) { AssertNoError(ippsOrC_32u_I(val, pSrcDst, len)); }

    static inline void XorC(const Ipp8u *pSrc, Ipp8u val, Ipp8u *pDst, int len) { AssertNoError(ippsXorC_8u(pSrc, val, pDst, len)); }
    static inline void XorC(const Ipp16u *pSrc, Ipp16u val, Ipp16u *pDst, int len) { AssertNoError(ippsXorC_16u(pSrc, val, pDst, len)); }
    static inline void XorC(const Ipp32u *pSrc, Ipp32u val, Ipp32u *pDst, int len) { AssertNoError(ippsXorC_32u(pSrc, val, pDst, len)); }
    static inline void XorC(Ipp8u val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsXorC_8u_I(val, pSrcDst, len)); }
    static inline void XorC(Ipp16u val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsXorC_16u_I(val, pSrcDst, len)); }
    static inline void XorC(Ipp32u val, Ipp32u *pSrcDst, int len) { AssertNoError(ippsXorC_32u_I(val, pSrcDst, len)); }

    static inline void Not(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsNot_8u(pSrc, pDst, len)); }
    static inline void Not(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsNot_16u(pSrc, pDst, len)); }
    static inline void Not(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsNot_32u(pSrc, pDst, len)); }

    static inline void Not_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsNot_8u_I(pSrcDst, len)); }
    static inline void Not_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsNot_16u_I(pSrcDst, len)); }
    static inline void Not_I(Ipp32u *pSrcDst, int len) { AssertNoError(ippsNot_32u_I(pSrcDst, len)); }

    static inline void LShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { AssertNoError(ippsLShiftC_8u(pSrc, val, pDst, len)); }
    static inline void LShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { AssertNoError(ippsLShiftC_16s(pSrc, val, pDst, len)); }
    static inline void LShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { AssertNoError(ippsLShiftC_16u(pSrc, val, pDst, len)); }
    static inline void LShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { AssertNoError(ippsLShiftC_32s(pSrc, val, pDst, len)); }
    static inline void LShiftC_I(int val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsLShiftC_8u_I(val, pSrcDst, len)); }
    static inline void LShiftC_I(int val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsLShiftC_16u_I(val, pSrcDst, len)); }
    static inline void LShiftC_I(int val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsLShiftC_16s_I(val, pSrcDst, len)); }
    static inline void LShiftC_I(int val, Ipp32s *pSrcDst, int len) { AssertNoError(ippsLShiftC_32s_I(val, pSrcDst, len)); }

    static inline void RShiftC(const Ipp8u *pSrc, int val, Ipp8u *pDst, int len) { AssertNoError(ippsRShiftC_8u(pSrc, val, pDst, len)); }
    static inline void RShiftC(const Ipp16s *pSrc, int val, Ipp16s *pDst, int len) { AssertNoError(ippsRShiftC_16s(pSrc, val, pDst, len)); }
    static inline void RShiftC(const Ipp16u *pSrc, int val, Ipp16u *pDst, int len) { AssertNoError(ippsRShiftC_16u(pSrc, val, pDst, len)); }
    static inline void RShiftC(const Ipp32s *pSrc, int val, Ipp32s *pDst, int len) { AssertNoError(ippsRShiftC_32s(pSrc, val, pDst, len)); }
    static inline void RShiftC(int val, Ipp8u *pSrcDst, int len) { AssertNoError(ippsRShiftC_8u_I(val, pSrcDst, len)); }
    static inline void RShiftC(int val, Ipp16u *pSrcDst, int len) { AssertNoError(ippsRShiftC_16u_I(val, pSrcDst, len)); }
    static inline void RShiftC(int val, Ipp16s *pSrcDst, int len) { AssertNoError(ippsRShiftC_16s_I(val, pSrcDst, len)); }
    static inline void RShiftC(int val, Ipp32s *pSrcDst, int len) { AssertNoError(ippsRShiftC_32s_I(val, pSrcDst, len)); }

}
