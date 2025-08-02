#pragma once
#include "s_transforms.hpp"
#include "tipp_vector.hpp"
#include "tipp_error.hpp"
#include "tipp_type.hpp"
#include <stdexcept>
#include <utility>

namespace tipp
{
    namespace s
    {
        template <typename T>
        class Hilbert_Engine
        {
        protected:
            vector<Ipp8u> m_Buffer;
            vector<Ipp8u> m_Spec;
            int m_length;

        public:
            Hilbert_Engine() = default;

            explicit Hilbert_Engine(int length)
            {
                initialise(length);
            }

            void initialise(int length)
            {
                m_length = length;
                int bufferSize;
                int specSize;
                OptionalAssertNoError(HilbertGetSize<T>(length, ippAlgHintAccurate, &specSize, &bufferSize));
                m_Buffer.resize(bufferSize);
                m_Spec.resize(specSize);

                OptionalAssertNoError(HilbertInit<T>(length, ippAlgHintAccurate, (IppsHilbertSpec *)m_Spec.data(), m_Buffer.data()));
            }

            void assertIsInitialised()
            {
                if (m_Buffer.empty())
                    throw std::runtime_error("Hilbert_Engine not initialized");
            }

            IppStatus forward(const T *pSrc, T *pDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(Hilbert(pSrc, pDst, (IppsHilbertSpec *)m_Spec.data(), m_Buffer.data()));
            }

            vector<T> forward_V(vector<T> Src)
            {
                if (Src.size() != m_length)
                    throw std::invalid_argument("Input vector size does not match the initialized length");
                vector<T> output(m_length);
                Fwd(Src.data(), output.data());
                return output;
            }
        };

        // Only 4 types are supported
        // Trc = Ipp64fc, Tc = Ipp64fc
        // Trc = Ipp32fc, Tc = Ipp32fc
        // Trc = Ipp64f, Tc = Ipp64fc
        // Trc = Ipp32f, Tc = Ipp32fc
        template <typename Trc, typename Tc>
        class DFT_Engine
        {
        protected:
            vector<Ipp8u> m_pDFTSpec;
            vector<Ipp8u> m_pDFTWorkBuf;
            vector<Ipp8u> m_pDFTInitBuf;

            int m_inNFFT;
            int m_outNFFT;
            int m_flag;

        public:
            DFT_Engine() = default;

            DFT_Engine(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N) { initialise(nfft, flag); }

            void initialise(const int nfft, const int flag = IPP_FFT_DIV_INV_BY_N)
            {
                m_inNFFT = nfft;
                if constexpr (IsComplex<Trc>::value)
                {
                    m_outNFFT = nfft;
                }
                else
                {
                    m_outNFFT = nfft / 2 + 1;
                }
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
                    throw std::runtime_error("DFT_Engine not initalized");
            }

            IppStatus forward(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(DFTFwd(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data()));
            }

            vector<Tc> forward_V(vector<Trc> input)
            {
                if (input.size() != m_inNFFT)
                    throw std::invalid_argument("Input vector size does not match the initialized input size");
                vector<Tc> output(m_outNFFT);
                Fwd(input.data(), output.data());
                return output;
            }

            IppStatus inverse(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(DFTInv(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data()));
            }

            vector<Trc> inverse_V(const Tc *input)
            {
                if (input.size() != m_outNFFT)
                    throw std::invalid_argument("Input vector size does not match the initialized output size");
                vector<Trc> output(m_inNFFT);
                Inv(input, output.data());
                return output;
            }

            int inSize() const { return m_inNFFT; }
            int outSize() const { return m_outNFFT; }
        };

        template <typename Trc, typename Tc>
        class FFT_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_pFFTWorkBuf; // Double pointer to the FFT specification structure to be created.
            vector<Ipp8u> m_Buffer;

            int m_inNFFT;
            int m_outNFFT;
            int m_flag;
            int m_order;

        public:
            FFT_Engine() = default;

            FFT_Engine(int order, int flag = IPP_FFT_DIV_INV_BY_N) { initialise(order, flag); }

            void initialise(int order, int flag = IPP_FFT_DIV_INV_BY_N)
            {
                int SizeSpec, SizeInit, SizeBuf;

                FFTGetSize<Trc>(order, flag, &SizeSpec, &SizeInit, &SizeBuf);

                m_Spec.resize(SizeSpec);
                m_pFFTWorkBuf.resize(SizeInit);
                m_Buffer.resize(SizeBuf);

                FFTInit<Trc>(m_pFFTWorkBuf.data(), order, flag, m_Spec.data(), m_Buffer.data());

                m_inNFFT = 1 << order;
                if constexpr (IsComplex<Trc>::value)
                {
                    m_outNFFT = nfft;
                }
                else
                {
                    m_outNFFT = nfft / 2 + 1;
                }

                m_flag = flag;
                m_order = order;
            }

            void assertIsInitialised()
            {
                if (m_Buffer.empty())
                    throw std::runtime_error("FFT not initalized");
            }

            IppStatus forward(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTFwd(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus forward_I(const Trc *input, Tc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTFwd_I(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus inverse(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTInv(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
            }
            IppStatus inverse_I(const Tc *input, Trc *output)
            {
                assertIsInitialised();
                return OptionalAssertNoError(FFTInv_I(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
            }

            int inSize() const { return m_inNFFT; }
            int outSize() const { return m_outNFFT; }
        };

        template <typename T>
        class WT_Engine
        {
        protected:
            vector<Ipp8u> m_Fwd_State;
            vector<Ipp8u> m_Inv_State;

            vector<T> m_High_dlyLine;
            vector<T> m_Low_dlyLine;

            int m_lenLow;
            int m_offsLow;
            int m_lenHigh;
            int m_offsHigh;
            int m_dlyLowLen;
            int m_dlyHighLen;

            bool m_Is_Fwd_Initialised = false;
            bool m_Is_Inv_Initialised = false;

        public:
            WT_Engine() = default;

            WT_Engine(int lenLow, int offsLow, int lenHigh, int offsHigh) { initialise(lenLow, offsLow, lenHigh, offsHigh); }

            void initialise(int lenLow, int offsLow, int lenHigh, int offsHigh)
            {

                m_lenLow = lenLow;
                m_offsLow = offsLow;
                m_lenHigh = lenHigh;
                m_offsHigh = offsHigh;

                m_dlyLowLen = lenLow + offsLow - 1;
                m_dlyHighLen = lenHigh + offsHigh - 1;

                int FwdStateSize;
                int InvStateSize;
                WTFwdGetSize<T>(lenLow, offsLow, lenHigh, offsHigh, &FwdStateSize);
                WTInvGetSize<T>(lenLow, offsLow, lenHigh, offsHigh, &InvStateSize);

                m_Fwd_State.resize(FwdStateSize);
                m_Inv_State.resize(InvStateSize);

                m_High_dlyLine.resize(m_dlyHighLen);
                m_Low_dlyLine.resize(m_dlyLowLen);
            }

            IppStatus forward(const T *input, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen)
            {
                if (m_Fwd_State.empty())
                    throw std::runtime_error("Buffer not initalized");
                return OptionalAssertNoError(WTFwd(input, pDstLow, pDstHigh, dstLen, m_Fwd_State.data()));
            }

            IppStatus inverse(const Ipp32f *input, Ipp32f *pSrcHigh, int srcLen, T *pDst)
            {
                if (m_Inv_State.empty())
                    throw std::runtime_error("Buffer not initalized");
                return OptionalAssertNoError(WTInv(input, pSrcHigh, srcLen, pDst, m_Inv_State.data()));
            }

            IppStatus InvGetDlyLine(Ipp32f *pDlyLow, Ipp32f *pDlyHigh)
            {
                return OptionalAssertNoError(WTInvGetDlyLine<T>(m_Inv_State.data(), pDlyLow, pDlyHigh));
            }

            IppStatus InvSetDlyLine(const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh)
            {
                return OptionalAssertNoError(WTInvSetDlyLine<T>(m_Inv_State.data(), pDlyLow, pDlyHigh));
            }

            IppStatus FwdGetDlyLine(Ipp32f *pDlyLow, Ipp32f *pDlyHigh)
            {
                return OptionalAssertNoError(WTFwdGetDlyLine<T>(m_Inv_State.data(), pDlyLow, pDlyHigh));
            }

            IppStatus FwdSetDlyLine(const Ipp32f *pDlyLow, const Ipp32f *pDlyHigh)
            {
                return OptionalAssertNoError(WTFwdSetDlyLine<T>(m_Inv_State.data(), pDlyLow, pDlyHigh));
            }
        };
    }
}
