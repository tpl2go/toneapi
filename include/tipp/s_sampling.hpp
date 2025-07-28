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

}
