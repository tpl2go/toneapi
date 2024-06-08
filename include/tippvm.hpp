#include <ippvm.h>
#include "tipp_error.hpp"
namespace ipp
{
    namespace ippvm
    {
        static inline void Abs(const Ipp32fc *pSrc, Ipp32f *pDst, Ipp32s len) { AssertNoError(ippsAbs_32fc_A24(pSrc, pDst, len)); }
        static inline void Abs(const Ipp64fc *pSrc, Ipp64f *pDst, Ipp32s len) { AssertNoError(ippsAbs_64fc_A53(pSrc, pDst, len)); }

    }
}