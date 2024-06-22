#include <ipps.h>
#include <ipps_l.h>
#include <ippcore.h>
#include <stdexcept>
#include "tipp_error.hpp"
#include "tipps_vector.hpp"
#include "tipps.hpp"

namespace tipp
{

    template <typename T>
    void DFTGetSize(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
    template <>
    void DFTGetSize<Ipp32fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsDFTGetSize_C_32fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void DFTGetSize<Ipp64fc>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsDFTGetSize_C_64fc(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void DFTGetSize<float>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsDFTGetSize_R_32f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void DFTGetSize<double>(int length, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsDFTGetSize_R_64f(length, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

    template <typename T>
    static inline void DFTInit(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit);
    template <>
    void DFTInit<Ipp32fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { AssertNoError(ippsDFTInit_C_32fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_32fc *)pDFTSpec, pMemInit)); }
    template <>
    void DFTInit<Ipp64fc>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { AssertNoError(ippsDFTInit_C_64fc(length, flag, ippAlgHintNone, (IppsDFTSpec_C_64fc *)pDFTSpec, pMemInit)); }
    template <>
    void DFTInit<float>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { AssertNoError(ippsDFTInit_R_32f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_32f *)pDFTSpec, pMemInit)); }
    template <>
    void DFTInit<double>(int length, int flag, Ipp8u *pDFTSpec, Ipp8u *pMemInit) { AssertNoError(ippsDFTInit_R_64f(length, flag, ippAlgHintNone, (IppsDFTSpec_R_64f *)pDFTSpec, pMemInit)); }

    static inline void DFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTFwd_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
    static inline void DFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTFwd_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
    static inline void DFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }
    static inline void DFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }

    static inline void DFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTInv_CToC_32fc(pSrc, pDst, (const IppsDFTSpec_C_32fc *)pDFTSpec, pBuffer)); }
    static inline void DFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTInv_CToC_64fc(pSrc, pDst, (const IppsDFTSpec_C_64fc *)pDFTSpec, pBuffer)); }
    static inline void DFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsDFTSpec_R_64f *)pDFTSpec, pBuffer)); }
    static inline void DFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pDFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsDFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsDFTSpec_R_32f *)pDFTSpec, pBuffer)); }

    template <typename T>
    static inline int get_FwdSize(int nfft) { return nfft; }
    template <>
    int get_FwdSize<float>(int nfft) { return nfft / 2 + 1; }
    template <>
    int get_FwdSize<double>(int nfft) { return nfft / 2 + 1; }

    // Only 4 types are supported
    // Trc = Ipp64fc, Tc = Ipp64fc
    // Trc = Ipp32fc, Tc = Ipp32fc
    // Trc = Ipp64f, Tc = Ipp64fc
    // Trc = Ipp32f, Tc = Ipp32fc
    template <typename Trc, typename Tc>
    class DFT
    {
    private:
        std::vector<Ipp8u, IPPAllocator<Ipp8u>> m_pDFTSpec;
        std::vector<Ipp8u, IPPAllocator<Ipp8u>> m_pDFTWorkBuf;
        std::vector<Ipp8u, IPPAllocator<Ipp8u>> m_pDFTInitBuf;

        int m_inNFFT;
        int m_outNFFT;
        int m_flag;

    public:
        DFT() = default;

        DFT(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N) { initialise(nfft, flag); }

        void initialise(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N)
        {
            m_inNFFT = nfft;
            m_outNFFT = get_FwdSize<Trc>(nfft);
            m_flag = flag;

            int SizeSpec, SizeInit, SizeBuf;
            DFTGetSize<Trc>(nfft, flag, &SizeSpec, &SizeInit, &SizeBuf);

            m_pDFTSpec.resize(SizeSpec);
            m_pDFTWorkBuf.resize(SizeBuf);
            m_pDFTInitBuf.resize(SizeInit);

            DFTInit<Trc>(m_inNFFT, m_flag, m_pDFTSpec.data(), m_pDFTInitBuf.data());
        }

        void assertIsInitialised()
        {
            if (m_pDFTSpec.empty())
                throw std::invalid_argument("DFT not initalized");
        }

        void Fwd(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            DFTFwd(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data());
        }

        void Inv(const Tc *input, Trc *output)
        {
            assertIsInitialised();
            DFTInv(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data());
        }

        std::vector<Tc> Fwd(const std::vector<Trc> &input)
        {
            if (input.size() != m_inNFFT)
                throw std::invalid_argument("DFT: Input vector size is" + std::to_string(input.size()) + ". Expected " + std::to_string(m_inNFFT));
            std::vector<Tc> output(m_outNFFT);
            Fwd(input.data(), output.data());
            return output;
        }

        std::vector<Trc> Inv(const std::pmr::vector<Tc> &input)
        {
            if (input.size() != m_outNFFT)
                throw std::invalid_argument("IDFT: Input vector size is" + std::to_string(input.size()) + ". Expected " + std::to_string(m_outNFFT));
            std::vector<Trc> output(m_inNFFT);
            Inv(input.data(), output.data());
            return output;
        }

        int inSize() const { return m_inNFFT; }
        int outSize() const { return m_outNFFT; }
    };

    template <typename T>
    void FFTGetSize(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf);
    template <>
    void FFTGetSize<Ipp32fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsFFTGetSize_C_32fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void FFTGetSize<Ipp64fc>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsFFTGetSize_C_64fc(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void FFTGetSize<float>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsFFTGetSize_R_32f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }
    template <>
    void FFTGetSize<double>(int order, int flag, int *pSizeSpec, int *pSizeInit, int *pSizeBuf) { AssertNoError(ippsFFTGetSize_R_64f(order, flag, ippAlgHintNone, pSizeSpec, pSizeInit, pSizeBuf)); }

    template <typename T>
    static inline void FFTInit(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer);
    template <>
    void FFTInit<Ipp32fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { AssertNoError(ippsFFTInit_C_32fc((IppsFFTSpec_C_32fc **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
    template <>
    void FFTInit<Ipp64fc>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { AssertNoError(ippsFFTInit_C_64fc((IppsFFTSpec_C_64fc **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
    template <>
    void FFTInit<float>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { AssertNoError(ippsFFTInit_R_32f((IppsFFTSpec_R_32f **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }
    template <>
    void FFTInit<double>(void *ppFFTSpec, int order, int flag, Ipp8u *pDFTSpec, Ipp8u *pSpecBuffer) { AssertNoError(ippsFFTInit_R_64f((IppsFFTSpec_R_64f **)ppFFTSpec, order, flag, ippAlgHintNone, pDFTSpec, pSpecBuffer)); }

    static inline void FFTFwd(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd(const float *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_RToCCS_32f(pSrc, (float *)pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd(const double *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_RToCCS_64f(pSrc, (double *)pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

    static inline void FFTInv(const Ipp32fc *pSrc, Ipp32fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CToC_32fc(pSrc, pDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline void FFTInv(const Ipp64fc *pSrc, Ipp64fc *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CToC_64fc(pSrc, pDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline void FFTInv(const Ipp64fc *pSrc, double *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CCSToR_64f((const double *)pSrc, pDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
    static inline void FFTInv(const Ipp32fc *pSrc, float *pDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CCSToR_32f((const float *)pSrc, pDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

    static inline void FFTFwd_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd_I(float *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_RToCCS_32f_I(pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }
    static inline void FFTFwd_I(double *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTFwd_RToCCS_64f_I(pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }

    static inline void FFTInv_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CToC_32fc_I(pSrcDst, (const IppsFFTSpec_C_32fc *)pFFTSpec, pBuffer)); }
    static inline void FFTInv_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CToC_64fc_I(pSrcDst, (const IppsFFTSpec_C_64fc *)pFFTSpec, pBuffer)); }
    static inline void FFTInv_I(Ipp64fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CCSToR_64f_I((double *)pSrcDst, (const IppsFFTSpec_R_64f *)pFFTSpec, pBuffer)); }
    static inline void FFTInv_I(Ipp32fc *pSrcDst, const Ipp8u *pFFTSpec, Ipp8u *pBuffer) { AssertNoError(ippsFFTInv_CCSToR_32f_I((float *)pSrcDst, (const IppsFFTSpec_R_32f *)pFFTSpec, pBuffer)); }

    template <typename Trc, typename Tc>
    class FFT
    {
    private:
        vector<Ipp8u> m_pFFTSpec;
        vector<Ipp8u> m_pFFTWorkBuf;
        vector<Ipp8u> m_pFFTInitBuf;

        int m_inNFFT;
        int m_outNFFT;
        int m_flag;

    public:
        FFT() = default;

        FFT(int order, int flag = IPP_FFT_DIV_INV_BY_N) { initialise(order, flag); }

        void initialise(int order, int flag = IPP_FFT_DIV_INV_BY_N)
        {
            int SizeSpec, SizeInit, SizeBuf;

            FFTGetSize<Trc>(order, flag, &SizeSpec, &SizeInit, &SizeBuf);

            m_pFFTSpec.resize(SizeSpec);
            m_pFFTWorkBuf.resize(SizeBuf);
            m_pFFTInitBuf.resize(SizeInit);

            FFTInit<Trc>(nfft, flag, m_pFFTSpec.data(), m_pFFTInitBuf.data());

            m_inNFFT = 1 << order;
            m_outNFFT = get_FwdSize<Trc>(m_inNFFT);
            m_flag = flag;
        }

        void assertIsInitialised()
        {
            if (m_pFFTInitBuf.empty())
                throw std::invalid_argument("FFT not initalized");
        }

        void Fwd(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            FFTFwd(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data());
        }
        void Fwd_I(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            FFTFwd_I(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data());
        }
        void Inv(const Tc *input, Trc *output)
        {
            assertIsInitialised();
            FFTInv(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data());
        }
        void Inv_I(const Tc *input, Trc *output)
        {
            assertIsInitialised();
            FFTInv_I(input, output, m_pFFTSpec.data(), m_pFFTWorkBuf.data());
        }

        std::vector<Tc> Fwd(const std::vector<Trc> &input)
        {
            if (input.size() != m_inNFFT)
                throw std::invalid_argument("FFT: Input vector size is" + std::to_string(input.size()) + ". Expected " + std::to_string(m_inNFFT));
            std::vector<Tc> output(m_outNFFT);
            Fwd(input.data(), output.data());
            return output;
        }

        std::vector<Trc> Inv(const std::vector<Tc> &input)
        {
            if (input.size() != m_outNFFT)
                throw std::invalid_argument("IFFT: Input vector size is" + std::to_string(input.size()) + ". Expected " + std::to_string(m_outNFFT));
            std::vector<Trc> output(m_inNFFT);
            Inv(input.data(), output.data());
            return output;
        }

        int inSize() const { return m_inNFFT; }
        int outSize() const { return m_outNFFT; }
    };

    static inline void FIRSR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRSR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRSR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRSR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRSR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRSR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRSR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    template <typename T>
    void FIRSRGetSize(int tapsLen, int *pSpecSize, int *pBufSize);
    template <>
    void FIRSRGetSize<Ipp32f>(int tapsLen, int *pSpecSize, int *pBufSize) { AssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp32f, pSpecSize, pBufSize)); }
    template <>
    void FIRSRGetSize<Ipp32fc>(int tapsLen, int *pSpecSize, int *pBufSize) { AssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp32fc, pSpecSize, pBufSize)); }
    template <>
    void FIRSRGetSize<Ipp64f>(int tapsLen, int *pSpecSize, int *pBufSize) { AssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp64f, pSpecSize, pBufSize)); }
    template <>
    void FIRSRGetSize<Ipp64fc>(int tapsLen, int *pSpecSize, int *pBufSize) { AssertNoError(ippsFIRSRGetSize(tapsLen, IppDataType::ipp64fc, pSpecSize, pBufSize)); }

    template <typename T>
    void FIRSRInit(const T *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec);
    template <>
    void FIRSRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { AssertNoError(ippsFIRSRInit_32f(pTaps, tapsLen, algType, (IppsFIRSpec_32f *)pSpec)); }
    template <>
    void FIRSRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { AssertNoError(ippsFIRSRInit_32fc(pTaps, tapsLen, algType, (IppsFIRSpec_32fc *)pSpec)); }
    template <>
    void FIRSRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { AssertNoError(ippsFIRSRInit_64f(pTaps, tapsLen, algType, (IppsFIRSpec_64f *)pSpec)); }
    template <>
    void FIRSRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, IppAlgType algType, Ipp8u *pSpec) { AssertNoError(ippsFIRSRInit_64fc(pTaps, tapsLen, algType, (IppsFIRSpec_64fc *)pSpec)); }

    template <typename T, typename A>
    class FIRSR
    {
    private:
        vector<T> m_taps;

        vector<T> m_dly;
        vector<T> m_dlyDst;

        vector<Ipp8u> m_spec;
        vector<Ipp8u> m_buf;

        IppAlgType m_algType;

    public:
        FIRSR() = default;

        FIRSR(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }
        FIRSR(std::vector<T, A> taps, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps.data(), taps.size(), algType); }

        void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            m_algType = algType;
            int dlyLen = taplen - 1;
            m_dly.resize(dlyLen);
            m_dlyDst.resize(dlyLen);

            int specSize, bufSize;

            FIRSRGetSize<T>(taplen, &specSize, &bufSize);

            m_spec.resize(specSize);
            m_buf.resize(bufSize);

            FIRSRInit<T>(m_taps, taplen, m_algType, m_spec);

            m_taps.resize(taplen);
            Copy(taps, m_taps, taplen);
        }

        void assertIsInitialised()
        {
            if (m_spec.empty() || m_buf.empty())
                throw std::runtime_error("FIRSR not initialized");
        }

        void filter(const T *pSrc, T *pDst, int len)
        {
            assertIsInitialised();
            FIRSR<T>(pSrc, pDst, len, m_spec.data(), m_dly.data(), m_dlyDst.data(), m_buf.data());
            swap(m_dly, m_dlyDst);
        }
    };

    static inline void FIRMR(const Ipp32f *pSrc, Ipp32f *pDst, int numIters, Ipp8u *pSpec, const Ipp32f *pDlySrc, Ipp32f *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_32f(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRMR(const Ipp64f *pSrc, Ipp64f *pDst, int numIters, Ipp8u *pSpec, const Ipp64f *pDlySrc, Ipp64f *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_64f(pSrc, pDst, numIters, (IppsFIRSpec_64f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRMR(const Ipp32fc *pSrc, Ipp32fc *pDst, int numIters, Ipp8u *pSpec, const Ipp32fc *pDlySrc, Ipp32fc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_32fc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRMR(const Ipp64fc *pSrc, Ipp64fc *pDst, int numIters, Ipp8u *pSpec, const Ipp64fc *pDlySrc, Ipp64fc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_64fc(pSrc, pDst, numIters, (IppsFIRSpec_64fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRMR(const Ipp16s *pSrc, Ipp16s *pDst, int numIters, Ipp8u *pSpec, const Ipp16s *pDlySrc, Ipp16s *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_16s(pSrc, pDst, numIters, (IppsFIRSpec_32f *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    static inline void FIRMR(const Ipp16sc *pSrc, Ipp16sc *pDst, int numIters, Ipp8u *pSpec, const Ipp16sc *pDlySrc, Ipp16sc *pDlyDst, Ipp8u *pBuf)
    {
        AssertNoError(ippsFIRMR_16sc(pSrc, pDst, numIters, (IppsFIRSpec_32fc *)pSpec, pDlySrc, pDlyDst, pBuf));
    }

    template <typename T>
    void FIRMRGetSize(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize);
    template <>
    void FIRMRGetSize<Ipp32f>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
    {
        AssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp32f, pSpecSize, pBufSize));
    }
    template <>
    void FIRMRGetSize<Ipp64f>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
    {
        AssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp64f, pSpecSize, pBufSize));
    }
    template <>
    void FIRMRGetSize<Ipp32fc>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
    {
        AssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp32fc, pSpecSize, pBufSize));
    }
    template <>
    void FIRMRGetSize<Ipp64fc>(int tapsLen, int upFactor, int downFactor, int *pSpecSize, int *pBufSize)
    {
        AssertNoError(ippsFIRMRGetSize(tapsLen, upFactor, downFactor, IppDataType::ipp64fc, pSpecSize, pBufSize));
    }

    template <typename T>
    void FIRMRInit(const T *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec);
    template <>
    void FIRMRInit<Ipp32f>(const Ipp32f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
    {
        AssertNoError(ippsFIRMRInit_32f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32f *)pSpec));
    }
    template <>
    void FIRMRInit<Ipp64f>(const Ipp64f *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
    {
        AssertNoError(ippsFIRMRInit_64f(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64f *)pSpec));
    }
    template <>
    void FIRMRInit<Ipp32fc>(const Ipp32fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
    {
        AssertNoError(ippsFIRMRInit_32fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_32fc *)pSpec));
    }
    template <>
    void FIRMRInit<Ipp64fc>(const Ipp64fc *pTaps, int tapsLen, int upFactor, int upPhase, int downFactor, int downPhase, Ipp8u *pSpec)
    {
        AssertNoError(ippsFIRMRInit_64fc(pTaps, tapsLen, upFactor, upPhase, downFactor, downPhase, (IppsFIRSpec_64fc *)pSpec));
    }

    template <typename T, typename A>
    class FIRMR
    {
    private:
        vector<T> m_taps;

        vector<T> m_dly;
        vector<T> m_dlyDst;

        vector<Ipp8u> m_spec;
        vector<Ipp8u> m_buf;

        IppAlgType m_algType;

    public:
        FIRMR() = default;

        FIRMR(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

        FIRMR(std::vector<T, A> taps, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            FIRMR(taps.data(), taps.size(), algType);
        }

        void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            m_algType = algType;

            int specSize, bufSize;
            FIRMRGetSize<T>(taplen, &specSize, &bufSize);

            m_spec.resize(specSize);
            m_buf.resize(bufSize);

            FIRMRInit<T>(m_taps.data(), taplen, m_algType, m_spec.data());

            m_taps.resize(taplen);
            Copy(taps, m_taps, taplen);

            int m_dlyLen = taplen - 1;
            m_dly.resize(m_dlyLen);
            m_dlyDst.resize(m_dlyLen);
        }

        void assertIsInitialised()
        {
            if (m_spec.empty())
                throw std::runtime_error("FIRMR not initialized");
        }

        void filter(const T *pSrc, T *pDst, int len)
        {
            assertIsInitialised();
            FIRMR<T>(pSrc, pDst, len, m_spec, m_dly, m_dlyDst, m_buf);
            std::swap(m_dly, m_dlyDst);
        }
    };

    template <typename T>
    class FIRGen
    {
    private:
        vector<T> m_buffer;
        int m_tapsLen;

    public:
        FIRGen() = default;
        FIRGen(int tapsLen)
        {
            m_tapsLen = tapsLen;
            int bufSize;
            AssertNoError(ippsFIRGenGetBufferSize(tapsLen, &bufSize));
            m_buffer.resize(bufSize);
        }
    };
    //   ippsCountInRange_32s

    //   ippsCplxToReal_16sc
    //   ippsCplxToReal_32fc
    //   ippsCplxToReal_64fc

    //   ippsCrossCorrNormGetBufferSize
    //   ippsCrossCorrNorm_32f
    //   ippsCrossCorrNorm_32fc
    //   ippsCrossCorrNorm_64f
    //   ippsCrossCorrNorm_64fc

    //   ippsCubrt_32f
    //   ippsCubrt_32s16s_Sfs

    //   ippsConvBiased_32f

    //   ippsCrossCorrNormGetBufferSize
    //   ippsCrossCorrNorm_32f
    //   ippsCrossCorrNorm_32fc
    //   ippsCrossCorrNorm_64f
    //   ippsCrossCorrNorm_64fc

    //   ippsFIRGenBandpass_64f
    //   ippsFIRGenBandstop_64f
    //   ippsFIRGenGetBufferSize
    //   ippsFIRGenHighpass_64f
    //   ippsFIRGenLowpass_64f

    //   ippsFIRLMS32f_16s
    //   ippsFIRLMSGetDlyLine32f_16s
    //   ippsFIRLMSGetDlyLine_32f
    //   ippsFIRLMSGetStateSize32f_16s
    //   ippsFIRLMSGetStateSize_32f
    //   ippsFIRLMSGetTaps32f_16s
    //   ippsFIRLMSGetTaps_32f
    //   ippsFIRLMSInit32f_16s
    //   ippsFIRLMSInit_32f
    //   ippsFIRLMSSetDlyLine32f_16s
    //   ippsFIRLMSSetDlyLine_32f
    //   ippsFIRLMS_32f

    //   ippsFIRSparseGetDlyLine_32f
    //   ippsFIRSparseGetDlyLine_32fc
    //   ippsFIRSparseGetStateSize_32f
    //   ippsFIRSparseGetStateSize_32fc
    //   ippsFIRSparseInit_32f
    //   ippsFIRSparseInit_32fc
    //   ippsFIRSparseSetDlyLine_32f
    //   ippsFIRSparseSetDlyLine_32fc
    //   ippsFIRSparse_32f
    //   ippsFIRSparse_32fc
    //   ippsFilterMedianGetBufferSize
    //   ippsFilterMedian_16s
    //   ippsFilterMedian_16s_I
    //   ippsFilterMedian_32f
    //   ippsFilterMedian_32f_I
    //   ippsFilterMedian_32s
    //   ippsFilterMedian_32s_I
    //   ippsFilterMedian_64f
    //   ippsFilterMedian_64f_I
    //   ippsFilterMedian_8u
    //   ippsFilterMedian_8u_I

    //   ippsHilbertGetSize_32f32fc
    //   ippsHilbertGetSize_64f64fc
    //   ippsHilbertInit_32f32fc
    //   ippsHilbertInit_64f64fc
    //   ippsHilbert_32f32fc
    //   ippsHilbert_64f64fc
    //   ippsIIR32f_16s_ISfs
    //   ippsIIR32f_16s_Sfs
    //   ippsIIR32fc_16sc_ISfs
    //   ippsIIR32fc_16sc_Sfs
    //   ippsIIR64f_16s_ISfs
    //   ippsIIR64f_16s_Sfs
    //   ippsIIR64f_32f
    //   ippsIIR64f_32f_I
    //   ippsIIR64f_32s_IPSfs
    //   ippsIIR64f_32s_ISfs
    //   ippsIIR64f_32s_PSfs
    //   ippsIIR64f_32s_Sfs
    //   ippsIIR64fc_16sc_ISfs
    //   ippsIIR64fc_16sc_Sfs
    //   ippsIIR64fc_32fc
    //   ippsIIR64fc_32fc_I
    //   ippsIIR64fc_32sc_ISfs
    //   ippsIIR64fc_32sc_Sfs
    //   ippsIIRGenGetBufferSize
    //   ippsIIRGenHighpass_64f
    //   ippsIIRGenLowpass_64f
    //   ippsIIRGetDlyLine32f_16s
    //   ippsIIRGetDlyLine32fc_16sc
    //   ippsIIRGetDlyLine64f_16s
    //   ippsIIRGetDlyLine64f_32f
    //   ippsIIRGetDlyLine64f_32s
    //   ippsIIRGetDlyLine64f_DF1_32s
    //   ippsIIRGetDlyLine64fc_16sc
    //   ippsIIRGetDlyLine64fc_32fc
    //   ippsIIRGetDlyLine64fc_32sc
    //   ippsIIRGetDlyLine_32f
    //   ippsIIRGetDlyLine_32fc
    //   ippsIIRGetDlyLine_64f
    //   ippsIIRGetDlyLine_64fc
    //   ippsIIRGetStateSize32f_16s
    //   ippsIIRGetStateSize32f_BiQuad_16s
    //   ippsIIRGetStateSize32fc_16sc
    //   ippsIIRGetStateSize32fc_BiQuad_16sc
    //   ippsIIRGetStateSize64f_16s
    //   ippsIIRGetStateSize64f_32f
    //   ippsIIRGetStateSize64f_32s
    //   ippsIIRGetStateSize64f_BiQuad_16s
    //   ippsIIRGetStateSize64f_BiQuad_32f
    //   ippsIIRGetStateSize64f_BiQuad_32s
    //   ippsIIRGetStateSize64f_BiQuad_DF1_32s
    //   ippsIIRGetStateSize64fc_16sc
    //   ippsIIRGetStateSize64fc_32fc
    //   ippsIIRGetStateSize64fc_32sc
    //   ippsIIRGetStateSize64fc_BiQuad_16sc
    //   ippsIIRGetStateSize64fc_BiQuad_32fc
    //   ippsIIRGetStateSize64fc_BiQuad_32sc
    //   ippsIIRGetStateSize_32f
    //   ippsIIRGetStateSize_32fc
    //   ippsIIRGetStateSize_64f
    //   ippsIIRGetStateSize_64fc
    //   ippsIIRGetStateSize_BiQuad_32f
    //   ippsIIRGetStateSize_BiQuad_32fc
    //   ippsIIRGetStateSize_BiQuad_64f
    //   ippsIIRGetStateSize_BiQuad_64fc
    //   ippsIIRGetStateSize_BiQuad_DF1_32f
    //   ippsIIRIIR64f_32f
    //   ippsIIRIIR64f_32f_I
    //   ippsIIRIIRGetDlyLine64f_32f
    //   ippsIIRIIRGetDlyLine_32f
    //   ippsIIRIIRGetDlyLine_64f
    //   ippsIIRIIRGetStateSize64f_32f
    //   ippsIIRIIRGetStateSize_32f
    //   ippsIIRIIRGetStateSize_64f
    //   ippsIIRIIRInit64f_32f
    //   ippsIIRIIRInit_32f
    //   ippsIIRIIRInit_64f
    //   ippsIIRIIRSetDlyLine64f_32f
    //   ippsIIRIIRSetDlyLine_32f
    //   ippsIIRIIRSetDlyLine_64f
    //   ippsIIRIIR_32f
    //   ippsIIRIIR_32f_I
    //   ippsIIRIIR_64f
    //   ippsIIRIIR_64f_I
    //   ippsIIRInit32f_16s
    //   ippsIIRInit32f_BiQuad_16s
    //   ippsIIRInit32fc_16sc
    //   ippsIIRInit32fc_BiQuad_16sc
    //   ippsIIRInit64f_16s
    //   ippsIIRInit64f_32f
    //   ippsIIRInit64f_32s
    //   ippsIIRInit64f_BiQuad_16s
    //   ippsIIRInit64f_BiQuad_32f
    //   ippsIIRInit64f_BiQuad_32s
    //   ippsIIRInit64f_BiQuad_DF1_32s
    //   ippsIIRInit64fc_16sc
    //   ippsIIRInit64fc_32fc
    //   ippsIIRInit64fc_32sc
    //   ippsIIRInit64fc_BiQuad_16sc
    //   ippsIIRInit64fc_BiQuad_32fc
    //   ippsIIRInit64fc_BiQuad_32sc
    //   ippsIIRInit_32f
    //   ippsIIRInit_32fc
    //   ippsIIRInit_64f
    //   ippsIIRInit_64fc
    //   ippsIIRInit_BiQuad_32f
    //   ippsIIRInit_BiQuad_32fc
    //   ippsIIRInit_BiQuad_64f
    //   ippsIIRInit_BiQuad_64fc
    //   ippsIIRInit_BiQuad_DF1_32f
    //   ippsIIRSetDlyLine32f_16s
    //   ippsIIRSetDlyLine32fc_16sc
    //   ippsIIRSetDlyLine64f_16s
    //   ippsIIRSetDlyLine64f_32f
    //   ippsIIRSetDlyLine64f_32s
    //   ippsIIRSetDlyLine64f_DF1_32s
    //   ippsIIRSetDlyLine64fc_16sc
    //   ippsIIRSetDlyLine64fc_32fc
    //   ippsIIRSetDlyLine64fc_32sc
    //   ippsIIRSetDlyLine_32f
    //   ippsIIRSetDlyLine_32fc
    //   ippsIIRSetDlyLine_64f
    //   ippsIIRSetDlyLine_64fc
    //   ippsIIRSparseGetStateSize_32f
    //   ippsIIRSparseInit_32f
    //   ippsIIRSparse_32f
    //   ippsIIR_32f
    //   ippsIIR_32f_I
    //   ippsIIR_32f_IP
    //   ippsIIR_32f_P
    //   ippsIIR_32fc
    //   ippsIIR_32fc_I
    //   ippsIIR_64f
    //   ippsIIR_64f_I
    //   ippsIIR_64fc
    //   ippsIIR_64fc_I

    //   ippsPatternMatchGetBufferSize
    //   ippsPatternMatch_8u16u

    //   ippsRandGaussGetSize_16s
    //   ippsRandGaussGetSize_32f
    //   ippsRandGaussGetSize_64f
    //   ippsRandGaussGetSize_8u
    //   ippsRandGaussInit_16s
    //   ippsRandGaussInit_32f
    //   ippsRandGaussInit_64f
    //   ippsRandGaussInit_8u
    //   ippsRandGauss_16s
    //   ippsRandGauss_32f
    //   ippsRandGauss_64f
    //   ippsRandGauss_8u
    //   ippsRandUniformGetSize_16s
    //   ippsRandUniformGetSize_32f
    //   ippsRandUniformGetSize_64f
    //   ippsRandUniformGetSize_8u
    //   ippsRandUniformInit_16s
    //   ippsRandUniformInit_32f
    //   ippsRandUniformInit_64f
    //   ippsRandUniformInit_8u
    //   ippsRandUniform_16s
    //   ippsRandUniform_32f
    //   ippsRandUniform_64f
    //   ippsRandUniform_8u

    //   ippsResamplePolyphaseFixedGetSize_16s
    //   ippsResamplePolyphaseFixedGetSize_32f
    //   ippsResamplePolyphaseFixedInit_16s
    //   ippsResamplePolyphaseFixedInit_32f
    //   ippsResamplePolyphaseFixed_16s
    //   ippsResamplePolyphaseFixed_32f
    //   ippsResamplePolyphaseGetFixedFilter_16s
    //   ippsResamplePolyphaseGetFixedFilter_32f
    //   ippsResamplePolyphaseGetSize_16s
    //   ippsResamplePolyphaseGetSize_32f
    //   ippsResamplePolyphaseInit_16s
    //   ippsResamplePolyphaseInit_32f
    //   ippsResamplePolyphaseSetFixedFilter_16s
    //   ippsResamplePolyphaseSetFixedFilter_32f
    //   ippsResamplePolyphase_16s
    //   ippsResamplePolyphase_32f

    //   ippsSortRadixAscend_16s_I
    //   ippsSortRadixAscend_16u_I
    //   ippsSortRadixAscend_32f_I
    //   ippsSortRadixAscend_32f_I_L
    //   ippsSortRadixAscend_32s_I
    //   ippsSortRadixAscend_32s_I_L
    //   ippsSortRadixAscend_32u_I
    //   ippsSortRadixAscend_64f_I
    //   ippsSortRadixAscend_64f_I_L
    //   ippsSortRadixAscend_64s_I
    //   ippsSortRadixAscend_64s_I_L
    //   ippsSortRadixAscend_64u_I
    //   ippsSortRadixAscend_64u_I_L
    //   ippsSortRadixAscend_8u_I
    //   ippsSortRadixDescend_16s_I
    //   ippsSortRadixDescend_16u_I
    //   ippsSortRadixDescend_32f_I
    //   ippsSortRadixDescend_32f_I_L
    //   ippsSortRadixDescend_32s_I
    //   ippsSortRadixDescend_32s_I_L
    //   ippsSortRadixDescend_32u_I
    //   ippsSortRadixDescend_64f_I
    //   ippsSortRadixDescend_64f_I_L
    //   ippsSortRadixDescend_64s_I
    //   ippsSortRadixDescend_64s_I_L
    //   ippsSortRadixDescend_64u_I
    //   ippsSortRadixDescend_64u_I_L
    //   ippsSortRadixDescend_8u_I
    //   ippsSortRadixGetBufferSize
    //   ippsSortRadixGetBufferSize_L
    //   ippsSortRadixIndexAscend_16s
    //   ippsSortRadixIndexAscend_16u
    //   ippsSortRadixIndexAscend_32f
    //   ippsSortRadixIndexAscend_32s
    //   ippsSortRadixIndexAscend_32u
    //   ippsSortRadixIndexAscend_64f
    //   ippsSortRadixIndexAscend_64s
    //   ippsSortRadixIndexAscend_64s_L
    //   ippsSortRadixIndexAscend_64u
    //   ippsSortRadixIndexAscend_64u_L
    //   ippsSortRadixIndexAscend_8u
    //   ippsSortRadixIndexDescend_16s
    //   ippsSortRadixIndexDescend_16u
    //   ippsSortRadixIndexDescend_32f
    //   ippsSortRadixIndexDescend_32s
    //   ippsSortRadixIndexDescend_32u
    //   ippsSortRadixIndexDescend_64f
    //   ippsSortRadixIndexDescend_64s
    //   ippsSortRadixIndexDescend_64s_L
    //   ippsSortRadixIndexDescend_64u
    //   ippsSortRadixIndexDescend_64u_L
    //   ippsSortRadixIndexDescend_8u
    //   ippsSortRadixIndexGetBufferSize
    //   ippsSortRadixIndexGetBufferSize_L

    //   ippsTopKGetBufferSize
    //   ippsTopKInit_32f
    //   ippsTopKInit_32s
    //   ippsTopK_32f
    //   ippsTopK_32s

    //   ippsWTFwdGetDlyLine_16s32f
    //   ippsWTFwdGetDlyLine_16u32f
    //   ippsWTFwdGetDlyLine_32f
    //   ippsWTFwdGetDlyLine_8u32f
    //   ippsWTFwdGetSize
    //   ippsWTFwdInit_16s32f
    //   ippsWTFwdInit_16u32f
    //   ippsWTFwdInit_32f
    //   ippsWTFwdInit_8u32f
    //   ippsWTFwdSetDlyLine_16s32f
    //   ippsWTFwdSetDlyLine_16u32f
    //   ippsWTFwdSetDlyLine_32f
    //   ippsWTFwdSetDlyLine_8u32f
    //   ippsWTFwd_16s32f
    //   ippsWTFwd_16u32f
    //   ippsWTFwd_32f
    //   ippsWTFwd_8u32f
    //   ippsWTHaarFwd_16s_Sfs
    //   ippsWTHaarFwd_32f
    //   ippsWTHaarFwd_64f
    //   ippsWTHaarInv_16s_Sfs
    //   ippsWTHaarInv_32f
    //   ippsWTHaarInv_64f
    //   ippsWTInvGetDlyLine_32f
    //   ippsWTInvGetDlyLine_32f16s
    //   ippsWTInvGetDlyLine_32f16u
    //   ippsWTInvGetDlyLine_32f8u
    //   ippsWTInvGetSize
    //   ippsWTInvInit_32f
    //   ippsWTInvInit_32f16s
    //   ippsWTInvInit_32f16u
    //   ippsWTInvInit_32f8u
    //   ippsWTInvSetDlyLine_32f
    //   ippsWTInvSetDlyLine_32f16s
    //   ippsWTInvSetDlyLine_32f16u
    //   ippsWTInvSetDlyLine_32f8u
    //   ippsWTInv_32f
    //   ippsWTInv_32f16s
    //   ippsWTInv_32f16u
    //   ippsWTInv_32f8u

    //   ippsFIRGenBandpass_64f
    //   ippsFIRGenBandstop_64f
    //   ippsFIRGenGetBufferSize
    //   ippsFIRGenHighpass_64f
    //   ippsFIRGenLowpass_64f

    //   ippsFIRLMS32f_16s
    //   ippsFIRLMSGetDlyLine32f_16s
    //   ippsFIRLMSGetDlyLine_32f
    //   ippsFIRLMSGetStateSize32f_16s
    //   ippsFIRLMSGetStateSize_32f
    //   ippsFIRLMSGetTaps32f_16s
    //   ippsFIRLMSGetTaps_32f
    //   ippsFIRLMSInit32f_16s
    //   ippsFIRLMSInit_32f
    //   ippsFIRLMSSetDlyLine32f_16s
    //   ippsFIRLMSSetDlyLine_32f
    //   ippsFIRLMS_32f

    //   ippsFIRMR32f_32fc
    //   ippsFIRMRGetSize
    //   ippsFIRMRGetSize32f_32fc
    //   ippsFIRMRInit32f_32fc
    //   ippsFIRMRInit_32f
    //   ippsFIRMRInit_32fc
    //   ippsFIRMRInit_64f
    //   ippsFIRMRInit_64fc
    //   ippsFIRMR_16s
    //   ippsFIRMR_16sc
    //   ippsFIRMR_32f
    //   ippsFIRMR_32fc
    //   ippsFIRMR_64f
    //   ippsFIRMR_64fc
    //   ippsFIRSR32f_32fc
    //   ippsFIRSRGetSize
    //   ippsFIRSRGetSize32f_32fc
    //   ippsFIRSRInit32f_32fc
    //   ippsFIRSRInit_32f
    //   ippsFIRSRInit_32fc
    //   ippsFIRSRInit_64f
    //   ippsFIRSRInit_64fc
    //   ippsFIRSR_16s
    //   ippsFIRSR_16sc
    //   ippsFIRSR_32f
    //   ippsFIRSR_32fc
    //   ippsFIRSR_64f
    //   ippsFIRSR_64fc
    //   ippsFIRSparseGetDlyLine_32f
    //   ippsFIRSparseGetDlyLine_32fc
    //   ippsFIRSparseGetStateSize_32f
    //   ippsFIRSparseGetStateSize_32fc
    //   ippsFIRSparseInit_32f
    //   ippsFIRSparseInit_32fc
    //   ippsFIRSparseSetDlyLine_32f
    //   ippsFIRSparseSetDlyLine_32fc
    //   ippsFIRSparse_32f
    //   ippsFIRSparse_32fc
    //   ippsFilterMedianGetBufferSize
    //   ippsFilterMedian_16s
    //   ippsFilterMedian_16s_I
    //   ippsFilterMedian_32f
    //   ippsFilterMedian_32f_I
    //   ippsFilterMedian_32s
    //   ippsFilterMedian_32s_I
    //   ippsFilterMedian_64f
    //   ippsFilterMedian_64f_I
    //   ippsFilterMedian_8u
    //   ippsFilterMedian_8u_I

    //   ippsFindNearestOne_16u
    //   ippsFindNearest_16u

    //   ippsHilbertGetSize_32f32fc
    //   ippsHilbertGetSize_64f64fc
    //   ippsHilbertInit_32f32fc
    //   ippsHilbertInit_64f64fc
    //   ippsHilbert_32f32fc
    //   ippsHilbert_64f64fc
    //   ippsIIR32f_16s_ISfs
    //   ippsIIR32f_16s_Sfs
    //   ippsIIR32fc_16sc_ISfs
    //   ippsIIR32fc_16sc_Sfs
    //   ippsIIR64f_16s_ISfs
    //   ippsIIR64f_16s_Sfs
    //   ippsIIR64f_32f
    //   ippsIIR64f_32f_I
    //   ippsIIR64f_32s_IPSfs
    //   ippsIIR64f_32s_ISfs
    //   ippsIIR64f_32s_PSfs
    //   ippsIIR64f_32s_Sfs
    //   ippsIIR64fc_16sc_ISfs
    //   ippsIIR64fc_16sc_Sfs
    //   ippsIIR64fc_32fc
    //   ippsIIR64fc_32fc_I
    //   ippsIIR64fc_32sc_ISfs
    //   ippsIIR64fc_32sc_Sfs
    //   ippsIIRGenGetBufferSize
    //   ippsIIRGenHighpass_64f
    //   ippsIIRGenLowpass_64f
    //   ippsIIRGetDlyLine32f_16s
    //   ippsIIRGetDlyLine32fc_16sc
    //   ippsIIRGetDlyLine64f_16s
    //   ippsIIRGetDlyLine64f_32f
    //   ippsIIRGetDlyLine64f_32s
    //   ippsIIRGetDlyLine64f_DF1_32s
    //   ippsIIRGetDlyLine64fc_16sc
    //   ippsIIRGetDlyLine64fc_32fc
    //   ippsIIRGetDlyLine64fc_32sc
    //   ippsIIRGetDlyLine_32f
    //   ippsIIRGetDlyLine_32fc
    //   ippsIIRGetDlyLine_64f
    //   ippsIIRGetDlyLine_64fc
    //   ippsIIRGetStateSize32f_16s
    //   ippsIIRGetStateSize32f_BiQuad_16s
    //   ippsIIRGetStateSize32fc_16sc
    //   ippsIIRGetStateSize32fc_BiQuad_16sc
    //   ippsIIRGetStateSize64f_16s
    //   ippsIIRGetStateSize64f_32f
    //   ippsIIRGetStateSize64f_32s
    //   ippsIIRGetStateSize64f_BiQuad_16s
    //   ippsIIRGetStateSize64f_BiQuad_32f
    //   ippsIIRGetStateSize64f_BiQuad_32s
    //   ippsIIRGetStateSize64f_BiQuad_DF1_32s
    //   ippsIIRGetStateSize64fc_16sc
    //   ippsIIRGetStateSize64fc_32fc
    //   ippsIIRGetStateSize64fc_32sc
    //   ippsIIRGetStateSize64fc_BiQuad_16sc
    //   ippsIIRGetStateSize64fc_BiQuad_32fc
    //   ippsIIRGetStateSize64fc_BiQuad_32sc
    //   ippsIIRGetStateSize_32f
    //   ippsIIRGetStateSize_32fc
    //   ippsIIRGetStateSize_64f
    //   ippsIIRGetStateSize_64fc
    //   ippsIIRGetStateSize_BiQuad_32f
    //   ippsIIRGetStateSize_BiQuad_32fc
    //   ippsIIRGetStateSize_BiQuad_64f
    //   ippsIIRGetStateSize_BiQuad_64fc
    //   ippsIIRGetStateSize_BiQuad_DF1_32f
    //   ippsIIRIIR64f_32f
    //   ippsIIRIIR64f_32f_I
    //   ippsIIRIIRGetDlyLine64f_32f
    //   ippsIIRIIRGetDlyLine_32f
    //   ippsIIRIIRGetDlyLine_64f
    //   ippsIIRIIRGetStateSize64f_32f
    //   ippsIIRIIRGetStateSize_32f
    //   ippsIIRIIRGetStateSize_64f
    //   ippsIIRIIRInit64f_32f
    //   ippsIIRIIRInit_32f
    //   ippsIIRIIRInit_64f
    //   ippsIIRIIRSetDlyLine64f_32f
    //   ippsIIRIIRSetDlyLine_32f
    //   ippsIIRIIRSetDlyLine_64f
    //   ippsIIRIIR_32f
    //   ippsIIRIIR_32f_I
    //   ippsIIRIIR_64f
    //   ippsIIRIIR_64f_I
    //   ippsIIRInit32f_16s
    //   ippsIIRInit32f_BiQuad_16s
    //   ippsIIRInit32fc_16sc
    //   ippsIIRInit32fc_BiQuad_16sc
    //   ippsIIRInit64f_16s
    //   ippsIIRInit64f_32f
    //   ippsIIRInit64f_32s
    //   ippsIIRInit64f_BiQuad_16s
    //   ippsIIRInit64f_BiQuad_32f
    //   ippsIIRInit64f_BiQuad_32s
    //   ippsIIRInit64f_BiQuad_DF1_32s
    //   ippsIIRInit64fc_16sc
    //   ippsIIRInit64fc_32fc
    //   ippsIIRInit64fc_32sc
    //   ippsIIRInit64fc_BiQuad_16sc
    //   ippsIIRInit64fc_BiQuad_32fc
    //   ippsIIRInit64fc_BiQuad_32sc
    //   ippsIIRInit_32f
    //   ippsIIRInit_32fc
    //   ippsIIRInit_64f
    //   ippsIIRInit_64fc
    //   ippsIIRInit_BiQuad_32f
    //   ippsIIRInit_BiQuad_32fc
    //   ippsIIRInit_BiQuad_64f
    //   ippsIIRInit_BiQuad_64fc
    //   ippsIIRInit_BiQuad_DF1_32f
    //   ippsIIRSetDlyLine32f_16s
    //   ippsIIRSetDlyLine32fc_16sc
    //   ippsIIRSetDlyLine64f_16s
    //   ippsIIRSetDlyLine64f_32f
    //   ippsIIRSetDlyLine64f_32s
    //   ippsIIRSetDlyLine64f_DF1_32s
    //   ippsIIRSetDlyLine64fc_16sc
    //   ippsIIRSetDlyLine64fc_32fc
    //   ippsIIRSetDlyLine64fc_32sc
    //   ippsIIRSetDlyLine_32f
    //   ippsIIRSetDlyLine_32fc
    //   ippsIIRSetDlyLine_64f
    //   ippsIIRSetDlyLine_64fc
    //   ippsIIRSparseGetStateSize_32f
    //   ippsIIRSparseInit_32f
    //   ippsIIRSparse_32f
    //   ippsIIR_32f
    //   ippsIIR_32f_I
    //   ippsIIR_32f_IP
    //   ippsIIR_32f_P
    //   ippsIIR_32fc
    //   ippsIIR_32fc_I
    //   ippsIIR_64f
    //   ippsIIR_64f_I
    //   ippsIIR_64fc
    //   ippsIIR_64fc_I
}
