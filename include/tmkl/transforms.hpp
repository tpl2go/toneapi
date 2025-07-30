#pragma once
#include <mkl.h>
#include <complex>

template <typename T>
static inline MKL_LONG MKLDFT_CreateDescriptor(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length);

template <>
MKL_LONG MKLDFT_CreateDescriptor<MKL_Complex8>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_SINGLE, DFTI_COMPLEX, 1, length);
}
template <>
MKL_LONG MKLDFT_CreateDescriptor<std::complex<float>>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_SINGLE, DFTI_COMPLEX, 1, length);
}
template <>
MKL_LONG MKLDFT_CreateDescriptor<std::complex<double>>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_DOUBLE, DFTI_COMPLEX, 1, length);
}
template <>
MKL_LONG MKLDFT_CreateDescriptor<MKL_Complex16>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_DOUBLE, DFTI_COMPLEX, 1, length);
}
template <>
MKL_LONG MKLDFT_CreateDescriptor<float>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_SINGLE, DFTI_REAL, 1, length);
}
template <>
MKL_LONG MKLDFT_CreateDescriptor<double>(DFTI_DESCRIPTOR_HANDLE *pHandle, MKL_LONG length)
{
    return DftiCreateDescriptor(pHandle, DFTI_DOUBLE, DFTI_REAL, 1, length);
}

// MKLDFT_forward

template <typename Trc, typename Tc>
static inline void MKLDFT_forward(DFTI_DESCRIPTOR_HANDLE Handle, Trc *input, Tc *output);

template <>
void MKLDFT_forward<std::complex<float>, std::complex<float>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<float> *input, std::complex<float> *output)
{
    DftiComputeForward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_forward<float, std::complex<float>>(DFTI_DESCRIPTOR_HANDLE Handle, float *input, std::complex<float> *output)
{
    DftiComputeForward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_forward<std::complex<double>, std::complex<double>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<double> *input, std::complex<double> *output)
{
    DftiComputeForward(Handle, (double *)input, (double *)output);
}

template <>
void MKLDFT_forward<double, std::complex<double>>(DFTI_DESCRIPTOR_HANDLE Handle, double *input, std::complex<double> *output)
{
    DftiComputeForward(Handle, (double *)input, (double *)output);
}

template <>
void MKLDFT_forward<MKL_Complex8, MKL_Complex8>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex8 *input, MKL_Complex8 *output)
{
    DftiComputeForward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_forward<float, MKL_Complex8>(DFTI_DESCRIPTOR_HANDLE Handle, float *input, MKL_Complex8 *output)
{
    DftiComputeForward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_forward<MKL_Complex16, MKL_Complex16>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex16 *input, MKL_Complex16 *output)
{
    DftiComputeForward(Handle, (double *)input, (double *)output);
}

template <>
void MKLDFT_forward<double, MKL_Complex16>(DFTI_DESCRIPTOR_HANDLE Handle, double *input, MKL_Complex16 *output)
{
    DftiComputeForward(Handle, (double *)input, (double *)output);
}

// MKLDFT_backwards

template <typename Trc, typename Tc>
static inline void MKLDFT_backwards(DFTI_DESCRIPTOR_HANDLE Handle, Tc *input, Trc *output);

template <>
void MKLDFT_backwards<MKL_Complex8, MKL_Complex8>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex8 *input, MKL_Complex8 *output)
{
    DftiComputeBackward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_backwards<float, MKL_Complex8>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex8 *input, float *output)
{
    DftiComputeBackward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_backwards<MKL_Complex16, MKL_Complex16>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex16 *input, MKL_Complex16 *output)
{
    DftiComputeBackward(Handle, (double *)input, (double *)output);
}

template <>
void MKLDFT_backwards<double, MKL_Complex16>(DFTI_DESCRIPTOR_HANDLE Handle, MKL_Complex16 *input, double *output)
{
    DftiComputeBackward(Handle, (double *)input, (double *)output);
}

///////////////////////////////////
template <>
void MKLDFT_backwards<std::complex<float>, std::complex<float>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<float> *input, std::complex<float> *output)
{
    DftiComputeBackward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_backwards<float, std::complex<float>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<float> *input, float *output)
{
    DftiComputeBackward(Handle, (float *)input, (float *)output);
}

template <>
void MKLDFT_backwards<std::complex<double>, std::complex<double>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<double> *input, std::complex<double> *output)
{
    DftiComputeBackward(Handle, (double *)input, (double *)output);
}

template <>
void MKLDFT_backwards<double, std::complex<double>>(DFTI_DESCRIPTOR_HANDLE Handle, std::complex<double> *input, double *output)
{
    DftiComputeBackward(Handle, (double *)input, (double *)output);
}

template <typename Trc, typename Tc>
class MKLDFT
{
public:
    DFTI_DESCRIPTOR_HANDLE m_handle;
    size_t m_outNFFT;

    // Constructor
    MKLDFT(size_t nfft)
    {
        MKLDFT_CreateDescriptor<Trc>(&m_handle, nfft);
        DftiSetValue(m_handle, DFTI_PLACEMENT, DFTI_NOT_INPLACE);
        DftiSetValue(m_handle, DFTI_BACKWARD_SCALE, 1. / ((double)nfft));
        DftiSetValue(m_handle, DFTI_PACKED_FORMAT, DFTI_CCE_FORMAT);
        DftiCommitDescriptor(m_handle);
        m_outNFFT = get_FwdSize<Trc>(nfft);
    }

    // Destructor
    ~MKLDFT()
    {
        DftiFreeDescriptor(&m_handle);
    }

    // Forward
    void forward(Trc *input, Tc *output)
    {
        MKLDFT_forward(m_handle, input, output);
    }

    // Backwards
    void backward(Tc *input, Trc *output)
    {
        MKLDFT_backwards(m_handle, input, output);
    }
};