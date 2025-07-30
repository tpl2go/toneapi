#pragma once
#include "s_filtering.hpp"
#include "tipp_vector.hpp"
#include "tipp_error.hpp"
#include <stdexcept>
#include <utility>
#include <span>

namespace tipp
{

    template <typename T>
    class FIRSR_Engine
    {
    protected:
        vector<T> m_taps;

        vector<T> m_DlySrc;
        vector<T> m_dlyDst;

        vector<Ipp8u> m_Spec;
        vector<Ipp8u> m_Buffer;

        IppAlgType m_algType;

    public:
        FIRSR_Engine() = default;

        FIRSR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

        void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            m_algType = algType;
            int dlyLen = taplen - 1;
            m_DlySrc.resize(dlyLen);
            m_dlyDst.resize(dlyLen);

            int specSize, bufSize;

            ippsFIRSRGetSize(taplen, GetIppDataType<T>(), &specSize, &bufSize);

            m_Spec.resize(specSize);
            m_Buffer.resize(bufSize);

            FIRSRInit<T>(m_taps, taplen, m_algType, m_Spec);

            m_taps.resize(taplen);
            Copy(taps, m_taps, taplen);
        }

        void assertIsInitialised()
        {
            if (m_Spec.empty() || m_Buffer.empty())
                throw std::runtime_error("FIRSR not initialized");
        }

        void filter(const T *pSrc, T *pDst, int len)
        {
            assertIsInitialised();
            FIRSR(pSrc, pDst, len, m_Spec.data(), m_DlySrc.data(), m_dlyDst.data(), m_Buffer.data());
            swap(m_DlySrc, m_dlyDst);
        }
    };

    template <typename T>
    class FIRMR_Engine
    {
    protected:
        int m_dlyLen;
        vector<T> m_taps;

        vector<T> m_DlySrc;
        vector<T> m_DlyDst;

        vector<Ipp8u> m_Spec;
        vector<Ipp8u> m_Buffer;

        IppAlgType m_algType;

        int m_upFactor;
        int m_downFactor;

    public:
        FIRMR_Engine() = default;

        FIRMR_Engine(T *taps, int taplen, int upFactor, int downFactor, ppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, upFactor, downFactor, algType); }

        void initialise(T *taps, int taplen, int upFactor, int downFactor, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            m_algType = algType;

            int specSize, bufSize;
            ippsFIRMRGetSize(taplen, upFactor, downFactor, GetIppDataType<T>(), &specSize, &bufSize)

                m_Spec.resize(specSize);
            m_Buffer.resize(bufSize);

            FIRMRInit<T>(m_taps.data(), taplen, m_algType, m_Spec.data());

            m_taps.resize(taplen);
            Copy(taps, m_taps, taplen);

            m_dlyLen = taplen - 1;
            m_DlySrc.resize(m_dlyLen);
            m_DlyDst.resize(m_dlyLen);
            m_upFactor = upFactor;
            m_downFactor = downFactor;
        }

        void assertIsInitialised()
        {
            if (m_Spec.empty())
                throw std::runtime_error("FIRMR not initialized");
        }

        void filter(const T *pSrc, T *pDst, int len)
        {
            assertIsInitialised();
            FIRMR(pSrc, pDst, len, m_Spec.data(), m_DlySrc.data(), m_DlyDst.data(), m_Buffer.data());
            swap(m_DlySrc, m_DlyDst);
        }
    };

    class FIRGen_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        int m_tapsLen;
        IppWinType m_winType; // ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
        IppBool m_doNormal;

    public:
        FIRGen_Engine() = default;
        FIRGen_Engine(int tapsLen, IppWinType winType, IppBool doNormal)
        {
            initialise(tapsLen, winType, doNormal);
        }

        void initialise(int tapsLen, IppWinType winType, IppBool doNormal)
        {
            m_tapsLen = tapsLen;
            m_winType = winType;
            m_doNormal = doNormal;

            int bufSize;
            OptionalAssertNoError(ippsFIRGenGetBufferSize(tapsLen, &bufSize));
            m_Buffer.resize(bufSize);
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("FIRGen not initialized");
        }

        IppStatus highpass(Ipp64f rFreq, Ipp64f *pTaps)
        {
            assertIsInitialised();
            return OptionalAssertNoError(
                ippsFIRGenHighpass_64f(rFreq, pTaps, m_tapsLen, m_winType, m_doNormal, m_Buffer.data()));
        }

        IppStatus lowpass(Ipp64f rFreq, Ipp64f *pTaps)
        {
            assertIsInitialised();
            return OptionalAssertNoError(
                ippsFIRGenLowpass_64f(rFreq, pTaps, m_tapsLen, m_winType, m_doNormal, m_Buffer.data()));
        }

        IppStatus bandpass(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps)
        {
            assertIsInitialised();
            return OptionalAssertNoError(
                ippsFIRGenBandpass_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, m_winType, m_doNormal, m_Buffer.data()));
        }

        IppStatus bandstop(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps)
        {
            assertIsInitialised();
            return OptionalAssertNoError(
                ippsFIRGenBandstop_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, m_winType, m_doNormal, m_Buffer.data()));
        }

        vector<Ipp64f> highpass_V(Ipp64f rFreq)
        {
            assertIsInitialised();
            vector<Ipp64f> out(m_tapsLen);
            ippsFIRGenHighpass_64f(rFreq, out.data(), m_tapsLen, m_winType, m_doNormal, m_Buffer.data());
            return out;
        }

        vector<Ipp64f> lowpass_V(Ipp64f rFreq)
        {
            assertIsInitialised();
            vector<Ipp64f> out(m_tapsLen);
            ippsFIRGenLowpass_64f(rFreq, out.data(), m_tapsLen, m_winType, m_doNormal, m_Buffer.data());
            return out;
        }

        vector<Ipp64f> bandpass_V(Ipp64f rLowFreq, Ipp64f rHighFreq)
        {
            assertIsInitialised();
            vector<Ipp64f> out(m_tapsLen);
            ippsFIRGenBandpass_64f(rLowFreq, rHighFreq, out.data(), m_tapsLen, m_winType, m_doNormal, m_Buffer.data());
            return out;
        }

        vector<Ipp64f> bandstop_V(Ipp64f rLowFreq, Ipp64f rHighFreq)
        {
            assertIsInitialised();
            vector<Ipp64f> out(m_tapsLen);
            ippsFIRGenBandstop_64f(rLowFreq, rHighFreq, out.data(), m_tapsLen, m_winType, m_doNormal, m_Buffer.data());
            return out;
        }
    };

    class FIRLMS_Engine
    {
    protected:
        float m_mu = 0.001f;
        vector<Ipp8u> m_Buffer;
        IppsFIRLMSState_32f *pState = nullptr; // pointer to state structure (taps and delay line) probably within buffer

    public:
        FIRLMS_Engine() = default;

        FIRLMS_Engine(int tapsLen, float mu)
        {
            initialise(tapsLen, mu);
        }
        void initialise(int tapsLen, float mu)
        {
            int BufferSize;
            OptionalAssertNoError(ippsFIRLMSGetStateSize_32f(tapsLen, 0, &BufferSize));
            m_Buffer.resize(BufferSize);
            // zero initialise taps and delay line
            OptionalAssertNoError(ippsFIRLMSInit_32f(&pState, nullptr, tapsLen, nullptr, 0, m_Buffer.data()));
        }

        IppStatus filter(const Ipp32f *pSrc, const Ipp32f *pRef, Ipp32f *pDst, int len)
        {
            return OptionalAssertNoError(ippsFIRLMS_32f(pSrc, pRef, pDst, len, m_mu, pState));
        }

        // Retrieves the tap values from the FIR LMS filter.
        void getTaps(Ipp32f *pOutTaps) { ippsFIRLMSGetTaps_32f(pState, pOutTaps); }

        IppStatus getDlyLine(Ipp32f *pDlyLine, int *pDlyLineIndex)
        {
            return OptionalAssertNoError(ippsFIRLMSGetDlyLine_32f(pState, pDlyLine, pDlyLineIndex));
        }

        IppStatus setDlyLine(const Ipp32f *pDlyLine, int dlyLineIndex)
        {
            // This function copies the delay line values from pDlyLine,
            // and the current delay line index from dlyLineIndex,
            // and stores them into the state structure pState.
            return OptionalAssertNoError(ippsFIRLMSSetDlyLine_32f(pState, pDlyLine, dlyLineIndex));
        }
    };

    template <typename T>
    class CrossCorrNorm_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        int m_src1Len, m_src2Len, m_dstLen, m_lowLag;
        int m_algType;

    public:
        CrossCorrNorm_Engine() = default;

        explicit CrossCorrNorm_Engine(int len) { initialise(len); }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("CrossCorrNorm not initialized");
        }

        void initialise(int src1Len, int src2Len, int dstLen, int lowLag, int algType)
        {
            // algoType : Bit-field mask for the algorithm type definition. Possible values are the results of composition of the IppAlgType and IppsNormOp values.
            // IppAlgType : ippAlgAuto, ippAlgDirect, ippAlgFFT, ippAlgMask
            // IppsNormOp : ippsNormNone, ippsNormA, ippsNormB, ippsNormMask

            int BufferSize;
            ippsCrossCorrNormGetBufferSize(src1Len, src2Len, dstLen, lowLag, GetIppDataType<T>(), algType, &BufferSize);
            m_Buffer.resize(BufferSize);
            m_src1Len = src1Len;
            m_src2Len = src2Len;
            m_dstLen = dstLen;
            m_lowLag = lowLag;
            m_algType = algType;
        }

        void filter(const Ipp64fc *pSrc1, int src1Len, const Ipp64fc *pSrc2, int src2Len, Ipp64fc *pDst, int dstLen, int lowLag)
        {
            assertIsInitialised();
            CrossCorrNorm(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, m_algType, m_Buffer.data());
        }
    };

    template <typename T>
    class FilterMedian_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        vector<T> m_DlySrc;
        vector<T> m_DlyDst;
        int m_maskSize;

    public:
        FilterMedian_Engine() = default;

        explicit FilterMedian_Engine(int maskSize)
        {
            initialise(maskSize);
        }

        void initialise(int maskSize)
        {
            // Median mask size, must be a positive integer. If an even value is specified, the function subtracts 1 and uses the odd value of the filter mask for median filtering

            m_maskSize = maskSize;
            int bufferSize;
            OptionalAssertNoError(ippsFilterMedianGetBufferSize(maskSize, GetIppDataType<T>(), &bufferSize));
            m_Buffer.resize(bufferSize);

            int dlyLen = maskSize - 1;
            m_DlySrc.resize(dlyLen);
            m_DlyDst.resize(dlyLen);
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("FilterMedian not initialized");
        }

        IppStatus filter(const T *pSrc, T *pDst, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(ippsFilterMedian(pSrc, pDst, len, m_maskSize, m_DlySrc.data(), m_DlyDst.data(), m_Buffer.data()));
        }

        IppStatus filter_I(const T *pSrcDst, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(ippsFilterMedian_I(pSrcDst, len, m_maskSize, m_DlySrc.data(), m_DlyDst.data(), m_Buffer.data()));
        }

        void getSrcDlyLine(T *pDlyLine)
        {
            Copy(m_DlySrc.data(), pDlyLine, m_DlySrc.size());
        }

        void setSrcDlyLine(const T *pDlyLine)
        {
            Copy(pDlyLine, m_DlySrc.data(), m_DlySrc.size());
        }

        void getDstDlyLine(T *pDlyLine)
        {
            Copy(m_DlyDst.data(), pDlyLine, m_DlyDst.size());
        }

        void setDstDlyLine(const T *pDlyLine)
        {
            Copy(pDlyLine, m_DlyDst.data(), m_DlyDst.size());
        }
    };

    template <typename internalType, typename externalType>
    class IIR_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        void *m_State = nullptr; // will this leak memory?
        vector<internalType> m_DlyLine;
        int m_order;

    public:
        IIR_Engine() = default;

        explicit IIR_Engine(int order, internalType *pTaps)
        {
            initialise(order);
        }

        void initialise(int order, internalType *pTaps)
        {
            // pTaps is of length 2*( order + 1)
            m_order = order;
            int bufferSize;
            OptionalAssertNoError(IIRGetStateSize<internalType, externalType>(order, &bufferSize));
            m_Buffer.resize(bufferSize);
            m_DlyLine.resize(order);
            IIRInit<internalType, externalType>(&m_State, pTaps, order, m_DlyLine.data(), m_Buffer.data());
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("Buffer not initialized");
        }

        IppStatus apply(const externalType *pSrc, externalType *pDst, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(IIR(pSrc, pDst, len, m_State));
        }

        IppStatus apply_I(const externalType *pSrcDst, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(IIR_I(pSrcDst, len, m_State));
        }

        IppStatus apply_Sfs(const externalType *pSrc, externalType *pDst, int len, int scaleFactor)
        {
            assertIsInitialised();
            return OptionalAssertNoError(IIR_Sfs(pSrc, pDst, len, m_State, scaleFactor));
        }

        IppStatus apply_ISfs(const externalType *pSrcDst, externalType *pDst, int len, int scaleFactor)
        {
            assertIsInitialised();
            return OptionalAssertNoError(IIR_Sfs(pSrcDst, len, m_State, scaleFactor));
        }

        void getDlyLine(internalType *pDlyLine)
        {
            IIRGetDlyLine(m_State.data(), pDlyLine);
        }

        void setDlyLine(const internalType *pDlyLine)
        {
            IIRSetDlyLine(m_State.data(), pDlyLine);
        }
    };

    template <typename T>
    class AutoCorrNorm_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        int m_srcLen, m_dstLen;
        IppEnum m_algType;

    public:
        AutoCorrNorm_Engine() = default;

        AutoCorrNorm_Engine(int srcLen, int dstLen = 0, IppEnum algType = (IppEnum)(ippAlgAuto | ippsNormB))
        {
            initialise(srcLen, dstLen, algType);
        }

        void initialise(int srcLen, int dstLen = 0, IppEnum algType = (IppEnum)(ippAlgAuto | ippsNormB))
        {

            // algoType : Bit-field mask for the algorithm type definition. Possible values are the results of composition of the IppAlgType and IppsNormOp values.
            // IppAlgType : ippAlgAuto, ippAlgDirect, ippAlgFFT, ippAlgMask
            // IppsNormOp : ippsNormNone, ippsNormA, ippsNormB, ippsNormMask

            if (dstLen == 0)
            {
                dstLen = srcLen;
            }

            int BufferSize;
            ippsAutoCorrNormGetBufferSize(srcLen, dstLen, GetIppDataType<T>(), algType, &BufferSize);
            m_Buffer.resize(BufferSize);
            m_srcLen = srcLen;
            m_dstLen = dstLen;
            m_algType = algType;
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("AutoCorrNorm_Engine not initialized");
        }

        IppStatus filter(const T *pSrc, T *pDst)
        {
            assertIsInitialised();
            return OptionalAssertNoError(AutoCorrNorm(pSrc, m_srcLen, pDst, m_dstLen, m_algType, m_Buffer.data()));
        }

        vector<T> filter_V(vector<T> Src)
        {
            if (Src.size() != m_srcLen)
                throw std::invalid_argument("Input vector size does not match the initialized source length");
            vector<T> output(m_dstLen);
            filter(Src.data(), output.data());
            return output;
        }
    };

    template <typename T>
    class ResamplePolyphase_Engine
    {
    protected:
        vector<T> m_State;
        T m_window;
        T m_nStep;

    public:
        ResamplePolyphase_Engine() = default;

        ResamplePolyphase_Engine(Ipp32f window, int nStep, Ipp32f rollf, Ipp32f alpha, IppHintAlgorithm hint) { initialise(window, nStep, rollf, alpha, hint); }

        void initialise(Ipp32f window, int nStep, Ipp32f rollf, Ipp32f alpha, IppHintAlgorithm hint)
        {
            int specSize;
            OptionalAssertNoError(ResamplePolyphaseGetSize<T>(window, nStep, &specSize, hint));
            m_State.resize(specSize);
            OptionalAssertNoError(ResamplePolyphaseInit<T>(window, nStep, rollf, alpha, m_State.data(), hint));
        }

        void assertIsInitialised()
        {
            if (m_State.empty())
                throw std::runtime_error("Buffer not initalized");
        }

        IppStatus apply(const T *pSrc, int len, T *pDst, Ipp64f factor, Ipp32f norm, Ipp64f *pTime, int *pOutlen)
        {
            assertIsInitialised();
            return OptionalAssertNoError(ResamplePolyphase(pSrc, len, pDst, factor, norm, *pTime, pOutlen, m_State.data()));
        }
    };

    template <typename T>
    class ResamplePolyphaseFixed_Engine
    {
    protected:
        vector<T> m_State;
        int m_inRate;
        int m_outRate;
        int m_filterLength, m_numFilters;
        Ipp32f m_rollf, m_alpha;

    public:
        ResamplePolyphaseFixed_Engine() = default;

        ResamplePolyphaseFixed_Engine(int inRate, int outRate, int len, Ipp32f rollf, Ipp32f alpha, IppHintAlgorithm hint) { initialise(inRate, outRate, len, rollf, alpha, hint); }

        void initialise(int inRate, int outRate, int len, Ipp32f rollf, Ipp32f alpha, IppHintAlgorithm hint)
        {
            int specSize;
            OptionalAssertNoError(ResamplePolyphaseFixedGetSize<T>(inRate, outRate, len, &specSize, &m_filterLength, &m_numFilters, hint));
            m_State.resize(specSize);
            OptionalAssertNoError(ResamplePolyphaseFixedInit<T>(inRate, outRate, m_filterLength, rollf, alpha, m_State.data(), hint));
            m_inRate = inRate;
            m_outRate = outRate;
            m_rollf = rollf;
            m_alpha = alpha;
        }

        void assertIsInitialised()
        {
            if (m_State.empty())
                throw std::runtime_error("Buffer not initalized");
        }

        IppStatus apply(const T *pSrc, int len, T *pDst, Ipp32f norm, Ipp64f *pTime, int *pOutlen)
        {
            assertIsInitialised();
            return OptionalAssertNoError(ResamplePolyphaseFixed(pSrc, len, pDst, norm, pTime, pOutlen, m_State.data()));
        }
    };

    // TODO: Create Engine for FIRSparse
    // TODO: Create Engine for PatternMatch

}
