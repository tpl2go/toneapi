#include <ipps.h>
#include <ipps_l.h>
#include <ippcore.h>
#include <stdexcept>
#include "tipp_error.hpp"
#include "tipps_support.hpp"
#include "tipps.hpp"

namespace tipp
{

    static inline void ConjCcs(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjCcs_32fc(pSrc, pDst, lenDst)); }
    static inline void ConjCcs(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjCcs_64fc(pSrc, pDst, lenDst)); }

    static inline void ConjCcs_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjCcs_32fc_I(pSrcDst, lenDst)); }
    static inline void ConjCcs_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjCcs_64fc_I(pSrcDst, lenDst)); }

    static inline void ConjPack(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjPack_32fc(pSrc, pDst, lenDst)); }
    static inline void ConjPack(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjPack_64fc(pSrc, pDst, lenDst)); }

    static inline void ConjPack_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPack_32fc_I(pSrcDst, lenDst)); }
    static inline void ConjPack_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPack_64fc_I(pSrcDst, lenDst)); }

    static inline void ConjPerm(const Ipp32f *pSrc, Ipp32fc *pDst, int lenDst) { AssertNoError(ippsConjPerm_32fc(pSrc, pDst, lenDst)); }
    static inline void ConjPerm(const Ipp64f *pSrc, Ipp64fc *pDst, int lenDst) { AssertNoError(ippsConjPerm_64fc(pSrc, pDst, lenDst)); }

    static inline void ConjPerm_I(Ipp32fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPerm_32fc_I(pSrcDst, lenDst)); }
    static inline void ConjPerm_I(Ipp64fc *pSrcDst, int lenDst) { AssertNoError(ippsConjPerm_64fc_I(pSrcDst, lenDst)); }

    static inline void MulPackConj_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPackConj_32f_I(pSrc, pSrcDst, len)); }
    static inline void MulPackConj_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPackConj_64f_I(pSrc, pSrcDst, len)); }

    static inline void MulPack(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMulPack_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void MulPack(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsMulPack_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void MulPack_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPack_32f_I(pSrc, pSrcDst, len)); }
    static inline void MulPack_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPack_64f_I(pSrc, pSrcDst, len)); }

    static inline void MulPerm(const Ipp32f *pSrc1, const Ipp32f *pSrc2, Ipp32f *pDst, int len) { AssertNoError(ippsMulPerm_32f(pSrc1, pSrc2, pDst, len)); }
    static inline void MulPerm(const Ipp64f *pSrc1, const Ipp64f *pSrc2, Ipp64f *pDst, int len) { AssertNoError(ippsMulPerm_64f(pSrc1, pSrc2, pDst, len)); }
    static inline void MulPerm_I(const Ipp32f *pSrc, Ipp32f *pSrcDst, int len) { AssertNoError(ippsMulPerm_32f_I(pSrc, pSrcDst, len)); }
    static inline void MulPerm_I(const Ipp64f *pSrc, Ipp64f *pSrcDst, int len) { AssertNoError(ippsMulPerm_64f_I(pSrc, pSrcDst, len)); }

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
}
