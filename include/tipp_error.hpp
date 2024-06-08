#include <ipp.h>
#include <stdexcept>

#ifndef TIPP_ERROR
static inline void AssertNoError(IppStatus status)
{
    if (status != ippStsNoErr)
        throw std::runtime_error(ippGetStatusString(status));
}
#define TIPP_ERROR
#endif