#pragma once
#include <ipp/ipptypes_l.h>
#include <ipp/ipptypes.h>
#include <ipp/ippcore.h>
#include <stdexcept>

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