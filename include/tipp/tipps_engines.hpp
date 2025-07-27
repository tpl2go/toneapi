#pragma once
#include "tipps.hpp"
#include "tipp_vector.hpp"
#include "tipp_error.hpp"
#include <stdexcept>
#include <utility>

namespace tipp
{
    template <typename T>
    class SortRadix_Engine
    {
    protected:
        vector<T> m_Buffer;
        int m_len;

    public:
        SortRadix_Engine() = default;

        explicit SortRadix_Engine(int len) { initialise(len); }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("SortRadix_Engine not initialized");
        }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixGetBufferSize<T>(len, &BufferSize);
            m_Buffer.resize(BufferSize);
            m_len = len;
        }

        void sortAscend_I(T *pSrcDst)
        {
            assertIsInitialised;
            SortRadixAscend_I(pSrcDst, m_len, m_Buffer.data());
        }
        void sortDescend_I(T *pSrcDst)
        {
            assertIsInitialised;
            SortRadixDescend_I(pSrcDst, m_len, m_Buffer.data());
        }
    };

    template <typename T>
    class SortRadix_L_Engine
    {
    protected:
        vector<T> m_Buffer;
        int m_len;

    public:
        SortRadix_L_Engine() = default;

        explicit SortRadix_L_Engine(int len) { initialise(len); }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("SortRadix_L_Engine not initialized");
        }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixGetBufferSize_L<T>(len, &BufferSize);
            m_Buffer.resize(BufferSize);
            m_len = len;
        }

        void sortAscend_I(T *pSrcDst)
        {
            assertIsInitialised();
            SortRadixAscend_I_L(pSrcDst, m_len, m_Buffer.data());
        }
        void sortDescend_I(T *pSrcDst)
        {
            assertIsInitialised();
            SortRadixDescend_I_L(pSrcDst, m_len, m_Buffer.data());
        }
    };

    template <typename T>
    class SortRadixIndex_Engine
    {
    protected:
        vector<T> m_Buffer;
        int m_len;

    public:
        SortRadixIndex_Engine() = default;

        explicit SortRadixIndex_Engine(int len) { initialise(len); }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixIndexGetBufferSize<T>(len, &BufferSize);
            m_Buffer.resize(BufferSize);
            m_len = len;
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("SortRadixIndex_Engine not initialized");
        }

        IppStatus sortAscend_I(T *pSrcDst)
        {
            assertIsInitialised();
            return OptionalAssertNoError(SortRadixIndexAscend_I(pSrcDst, m_len, m_Buffer.data()));
        }
        IppStatus sortDescend_I(T *pSrcDst)
        {
            assertIsInitialised();
            return OptionalAssertNoError(SortRadixIndexDescend_I(pSrcDst, m_len, m_Buffer.data()));
        }
    };

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

            FIRSRGetSize<T>(taplen, &specSize, &bufSize);

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

    public:
        FIRMR_Engine() = default;

        FIRMR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

        void initialise(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect)
        {
            m_algType = algType;

            int specSize, bufSize;
            FIRMRGetSize<T>(taplen, &specSize, &bufSize);

            m_Spec.resize(specSize);
            m_Buffer.resize(bufSize);

            FIRMRInit<T>(m_taps.data(), taplen, m_algType, m_Spec.data());

            m_taps.resize(taplen);
            Copy(taps, m_taps, taplen);

            int m_dlyLen = taplen - 1;
            m_DlySrc.resize(m_dlyLen);
            m_DlyDst.resize(m_dlyLen);
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

    template <typename T>
    class FIRGen_Engine
    {
    protected:
        vector<T> m_Buffer;
        int m_tapsLen;
        IppWinType m_winType; // ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
        IppBool m_doNormal;

    public:
        FIRGen_Engine() = default;
        FIRGen_Engine(int tapsLen)
        {
            initialise(tapsLen);
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
    };

    template <typename T>
    class FIRLMS_Engine
    {
    protected:
        float mu = 0.001f;
        vector<Ipp8u> m_Buffer;
        IppsFIRLMSState_32f *pState = nullptr; // TODO: change this to vector

    public:
        // TODO: add mu as a parameter to the constructor
        // TODO: check how to use this class

        FIRLMS_Engine() = default;

        explicit FIRLMS_Engine(int tapsLen)
        {
            int BufferSize;
            OptionalAssertNoError(ippsFIRLMSGetStateSize_32f(tapsLen, 0, &BufferSize));
            m_Buffer.resize(BufferSize);
            // zero initialise taps and delay line
            OptionalAssertNoError(ippsFIRLMSInit_32f(&pState, nullptr, tapsLen, nullptr, 0, m_Buffer.data()));
        }

        IppStatus filter(const Ipp32f *pSrc, const Ipp32f *pRef, Ipp32f *pDst, int len)
        {
            return OptionalAssertNoError(ippsFIRLMS_32f(pSrc, pRef, pDst, len, mu, pState));
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

        IppStatus Fwd(const T *pSrc, T *pDst)
        {
            assertIsInitialised();
            return OptionalAssertNoError(Hilbert(pSrc, pDst, (IppsHilbertSpec *)m_Spec.data(), m_Buffer.data()));
        }

        vector<T> Fwd_V(vector<T> Src)
        {
            if (Src.size() != m_length)
                throw std::invalid_argument("Input vector size does not match the initialized length");
            vector<T> output(m_length);
            Fwd(Src.data(), output.data());
            return output;
        }
    };

    template <typename T>
    class TopK_Engine
    {
    protected:
        vector<Ipp8u> m_Buffer;
        int m_srcLen;
        int m_dstLen;
        IppTopKMode m_hint; // ippTopKAuto, ippTopKDirect, ippTopKRadix

    public:
        TopK_Engine() = default;

        TopK_Engine(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto)
        {
            initialise(srcLen, dstLen, hint);
        }

        void initialise(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto)
        {
            // Parameter to choose the optimization that is most suitable for the srcLen+dstlen(K) combination, supported values: ippTopKAuto/ ippTopKDirect/ ippTopKRadix.

            m_srcLen = srcLen;
            m_dstLen = dstLen;
            m_hint = hint;
            int bufferSize;
            OptionalAssertNoError(ippsTopKGetBufferSize(srcLen, dstLen, GetIppDataType<T>(), hint, &bufferSize));
            m_Buffer.resize(bufferSize);
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("TopK_Engine not initialized");
        }

        IppStatus get_topk(const T *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, T *pDstValue, Ipp64s *pDstIndex)
        {
            assertIsInitialised();
            OptionalAssertNoError(TopKInit(pDstValue, pDstIndex, m_dstLen));
            return OptionalAssertNoError(TopK(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, m_dstLen, m_hint, m_Buffer.data()));
        }

        std::pair<vector<T>, vector<Ipp64s>> get_topk_V(vector<T> Src)
        {
            if (Src.size() != m_srcLen)
                throw std::invalid_argument("Input vector size does not match the initialized source length");

            vector<T> DstValue(m_dstLen);
            vector<Ipp64s> DstIndex(m_dstLen);
            get_topk(Src.data(), 0, sizeof(T), Src.size(), DstValue.data(), DstIndex.data());

            return std::make_pair(std::move(DstValue), std::move(DstIndex));
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

    template <typename T>
    class RandGauss_Engine
    {
    protected:
        vector<T> m_RandGaussState;
        T m_mean;
        T m_stdDev;
        unsigned int m_seed;

    public:
        RandGauss_Engine() = default;

        RandGauss_Engine(T mean, T stdDev, unsigned int seed) { initialise(mean, stdDev, seed); }

        void initialise(T mean, T stdDev, unsigned int seed)
        {
            m_mean = mean;
            m_stdDev = stdDev;
            m_seed = seed;

            int size;
            OptionalAssertNoError(RandGaussGetSize<T>(&size));
            m_RandGaussState.resize(size);

            OptionalAssertNoError(RandGaussInit(m_RandGaussState.data(), m_mean, m_stdDev, m_seed));
        }

        void assertIsInitialised()
        {
            if (m_RandGaussState.empty())
                throw std::runtime_error("RandGauss_Engine not initalized");
        }

        IppStatus sample(T *output, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(RandGauss(output, len, m_RandGaussState.data()));
        }

        vector<T> sample_V(int len)
        {
            vector<T> output(len);
            sample(output.data(), len);
            return output;
        }
    };

    template <typename T>
    class RandUniform_Engine
    {
    protected:
        vector<T> m_pRandUniformState;
        T m_low;
        T m_high;
        unsigned int m_seed;

    public:
        RandUniform_Engine() = default;
        RandUniform_Engine(T low, T high, unsigned int seed) { initialise(low, high, seed); }
        void initialise(T low, T high, unsigned int seed)
        {
            m_low = low;
            m_high = high;
            m_seed = seed;

            int size;
            OptionalAssertNoError(RandUniformGetSize<T>(&size));
            m_pRandUniformState.resize(size);

            OptionalAssertNoError(RandUniformInit(m_pRandUniformState.data(), m_low, m_high, m_seed));
        }
        void assertIsInitialised()
        {
            if (m_pRandUniformState.empty())
                throw std::runtime_error("RandUniform_Engine not initalized");
        }
        IppStatus sample(T *output, int len)
        {
            assertIsInitialised();
            return OptionalAssertNoError(RandUniform(output, len, m_pRandUniformState.data()));
        }

        vector<T> sample_V(int len)
        {
            vector<T> output(len);
            sample(output.data(), len);
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
            m_outNFFT = DFT_Get_FwdSize<Trc>(nfft);
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

        IppStatus Fwd(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            return OptionalAssertNoError(DFTFwd(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data()));
        }

        vector<Tc> Fwd_V(vector<Trc> input)
        {
            if (input.size() != m_inNFFT)
                throw std::invalid_argument("Input vector size does not match the initialized input size");
            vector<Tc> output(m_outNFFT);
            Fwd(input.data(), output.data());
            return output;
        }

        IppStatus Inv(const Tc *input, Trc *output)
        {
            assertIsInitialised();
            return OptionalAssertNoError(DFTInv(input, output, m_pDFTSpec.data(), m_pDFTWorkBuf.data()));
        }

        vector<Trc> Inv_V(const Tc *input)
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
            m_outNFFT = DFT_Get_FwdSize<Trc>(m_inNFFT);
            m_flag = flag;
            m_order = order;
        }

        void assertIsInitialised()
        {
            if (m_Buffer.empty())
                throw std::runtime_error("FFT not initalized");
        }

        IppStatus Fwd(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            return OptionalAssertNoError(FFTFwd(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
        }
        IppStatus Fwd_I(const Trc *input, Tc *output)
        {
            assertIsInitialised();
            return OptionalAssertNoError(FFTFwd_I(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
        }
        IppStatus Inv(const Tc *input, Trc *output)
        {
            assertIsInitialised();
            return OptionalAssertNoError(FFTInv(input, output, m_Spec.data(), m_pFFTWorkBuf.data()));
        }
        IppStatus Inv_I(const Tc *input, Trc *output)
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

        WT_Engine(int lenLow, int offsLow, int lenHigh, int offsHigh) { initialise(lenLow, offsLow, lenHigh, offsHigh, ); }

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

        IppStatus Fwd(const T *input, Ipp32f *pDstLow, Ipp32f *pDstHigh, int dstLen)
        {
            if (m_Fwd_State.empty())
                throw std::runtime_error("Buffer not initalized");
            return OptionalAssertNoError(WTFwd(input, pDstLow, pDstHigh, dstLen, m_Fwd_State.data()));
        }

        IppStatus inv(const Ipp32f *input, Ipp32f *pSrcHigh, int srcLen, T *pDst)
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
