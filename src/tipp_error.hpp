#include <ipp/ipptypes_l.h>
#include <ipp/ipptypes.h>
#include <ipp/ippcore.h>
#include <stdexcept>

#ifndef TIPP_ERROR
static inline void AssertNoError(IppStatus status)
{
    if (status != ippStsNoErr)
        throw std::runtime_error(ippGetStatusString(status));
}

static inline IppStatus OptionalAssertNoError(IppStatus status)
{
#ifdef ASSERT_IPP_NOERROR
    if (status != ippStsNoErr)
        throw std::runtime_error(ippGetStatusString(status));
#endif
    return status;
}
#define TIPP_ERROR
#endif