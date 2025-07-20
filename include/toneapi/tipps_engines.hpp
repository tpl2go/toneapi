#pragma once
#include "tipps.hpp"
#include "tipp_error.hpp"
#include <stdexcept>
#include <utility>

namespace tipp
{

    namespace signal
    {

        template <typename T>
        class vector
        {
            typedef T value_type;
            typedef T *pointer;
            typedef const T *const_pointer;
            typedef T &reference;
            typedef const T &const_reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;

            friend void swap(vector &a, vector &b) noexcept
            {
                using std::swap;
                swap(a.m_numel, b.m_numel);
                swap(a.m_data, b.m_data);
                swap(a.m_cap, b.m_cap);
            }

        protected:
            size_type m_numel = 0;
            size_type m_cap = 0;
            pointer m_data = nullptr;

        public:
            // Constructors

            // Default constructor
            vector() = default;

            explicit vector(size_type count)
            {
                reserve(count);
                m_numel = count;
            }

            vector(size_type count, const value_type &value)
            {
                reserve(count);
                m_numel = count;
                set(value);
            }

            // Copy constructor
            // creates a deep copy of the argument
            // invoked in situations like:
            //     vector a;
            //     vector b(a);
            vector(const vector &other)
            {
                reserve(m_numel);
                Copy(other.m_data, m_data, (int)m_numel);
                m_numel = other.m_numel;
            }

            // Move constructor
            // Move constructors typically "steal" the resources held by the argument
            // rather than make copies of them, and leave the argument in some valid
            // but otherwise indeterminate state.
            // invoked in situations like:
            //     vector a;
            //     vector b(std::move(a));
            //
            //     vector c = functionReturningVector();
            vector(vector &&other) noexcept
            {
                // steal other's data
                m_numel = other.m_numel;
                m_cap = other.m_cap;
                m_data = other.m_data;

                // nullify other
                other.m_data = nullptr;
                other.m_cap = 0;
                other.m_numel = 0;
            }

            // Copy Assignment operator
            // invoked in situations like:
            //     vector a;
            //     vector b;
            //     a = b;
            vector &operator=(vector &other)
            {
                if (this != &other)
                {
                    if (other.m_numel > 0)
                    {
                        reserve(other.m_numel);
                        Copy(other.m_data, m_data, (int)m_numel);
                    }
                    m_numel = other.m_numel;
                }
                return *this;
            }

            // Move Assignment operator
            // Move assignment operators typically "steal" the resources held by the argument
            // invoked in situations like:
            //     vector a;
            //     vector b;
            //     a = std::move(b);

            vector &operator=(vector &&other) noexcept
            {
                if (this != &other)
                {
                    // free own data
                    if (m_data != nullptr)
                        ippsFree(m_data);

                    // steal other's data
                    m_numel = other.m_numel;
                    m_cap = other.m_cap;
                    m_data = other.m_data;

                    // nullify other
                    other.m_data = nullptr;
                    other.m_cap = 0;
                    other.m_numel = 0;
                }
                return *this;
            }

            ~vector()
            {
                if (m_data != nullptr)
                    ippsFree(m_data);
            }

            /*
            Resizes the container so that it contains n elements.
            If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
            If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
            If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
            If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
            */
            void resize(size_type new_count)
            {

                reserve(new_count);

                if (new_count > m_numel) // value initialise new elements
                    for (int i = m_numel; i < new_count; i++)
                        new (&m_data[i]) value_type{};
                else if (new_count < m_numel) // destroy excess elements
                    for (int i = new_count; i < m_numel; i++)
                        m_data[i].~value_type();

                m_numel = new_count;
            }

            void resize(size_t new_count, const T &value)
            {

                reserve(new_count);

                if (new_count > m_numel) // copy construct new elements
                    for (int i = m_numel; i < new_count; i++)
                        new (&m_data[i]) value_type(value);
                else if (new_count < m_numel) // destroy excess elements
                    for (int i = new_count; i < m_numel; i++)
                        m_data[i].~value_type();

                m_numel = new_count;
            }

            void reserve(size_type new_cap)
            {
                if (new_cap > m_cap)
                {
                    value_type *new_data = ippsMalloc<value_type>(new_cap);
                    if (m_data != nullptr)
                    {
                        Copy(m_data, new_data, (int)m_numel);
                        ippsFree(m_data);
                    }
                    m_data = new_data;
                    m_cap = new_cap;
                }
            }

            void set(const_reference value)
            {
                for (int i = 0; i < m_numel; i++)
                    new (&m_data[i]) value_type(value);
            }

            // Unsafee method, use with caution
            void set_array(pointer pData)
            {
                for (int i = 0; i < m_numel; i++)
                    m_data[i] = pData[i];
            }

            pointer data() { return m_data; }
            const_pointer data() const { return m_data; }

            reference back() { return m_data[m_numel - 1]; }
            const_reference back() const { return m_data[m_numel - 1]; }

            reference front() { return m_data[0]; }

            const_reference front() const { return m_data[0]; }

            reference at(size_type pos)
            {
                if (pos < m_numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
            }

            const_reference at(size_type pos) const
            {
                if (pos < m_numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
            }

            reference operator[](size_type pos) { return m_data[pos]; }

            const_reference operator[](size_type pos) const { return m_data[pos]; }

            void push_back(const_reference value)
            {
                // check size
                if (m_numel == m_cap)
                {
                    m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
                }

                m_data[m_numel] = value;
                m_numel++;
            }

            void push_back(T &&value)
            {
                // check size
                if (m_numel == m_cap)
                {
                    m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
                }

                m_data[m_numel] = value;
                m_numel++;
            }

            size_type size() const { return m_numel; }

            size_type capacity() const { return m_cap; }

            void clear() { m_numel = 0; }

            bool empty() const noexcept { return m_numel == 0; }

            // Iterators
            pointer begin() { return m_data; }

            const_pointer begin() const { return m_data; }

            pointer end() { return m_data + m_numel; }

            const_pointer end() const { return m_data + m_numel; }

            // Const iterators
            const_pointer cbegin() const { return m_data; }

            const_pointer cend() const { return m_data + m_numel; }
        };

        // Custom Allocator for use with STL vector
        template <class T>
        struct IPPallocator
        {
            typedef T value_type;
            IPPallocator() noexcept {} // default ctor not required by C++ Standard Library

            // A converting copy constructor:
            template <class U>
            IPPallocator(const IPPallocator<U> &) noexcept {}

            template <class U>
            bool operator==(const IPPallocator<U> &) const noexcept { return true; }

            template <class U>
            bool operator!=(const IPPallocator<U> &) const noexcept { return false; }

            T *allocate(const size_t n) const
            {
                return ippsMalloc<T>(n);
            }
            void deallocate(T *const p, size_t) const noexcept
            {
                ippsFree(p);
            }
        };

        template <typename T>
        class SortRadix_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadix_Engine() = default;

            explicit SortRadix_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadix_Engine not initialized");
            }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixGetBufferSize<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised;
                SortRadixAscend_I(pSrcDst, m_len, m_buffer.data());
            }
            void sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised;
                SortRadixDescend_I(pSrcDst, m_len, m_buffer.data());
            }
        };

        template <typename T>
        class SortRadix_L_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadix_L_Engine() = default;

            explicit SortRadix_L_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadix_L_Engine not initialized");
            }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixGetBufferSize_L<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised();
                SortRadixAscend_I_L(pSrcDst, m_len, m_buffer.data());
            }
            void sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised();
                SortRadixDescend_I_L(pSrcDst, m_len, m_buffer.data());
            }
        };

        template <typename T>
        class SortRadixIndex_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_len;

        public:
            SortRadixIndex_Engine() = default;

            explicit SortRadixIndex_Engine(int len) { initialise(len); }

            void initialise(int len)
            {
                int BufferSize;
                SortRadixIndexGetBufferSize<T>(len, &BufferSize);
                m_buffer.resize(BufferSize);
                m_len = len;
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("SortRadixIndex_Engine not initialized");
            }

            IppStatus sortAscend_I(T *pSrcDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(SortRadixIndexAscend_I(pSrcDst, m_len, m_buffer.data()));
            }
            IppStatus sortDescend_I(T *pSrcDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(SortRadixIndexDescend_I(pSrcDst, m_len, m_buffer.data()));
            }
        };

        template <typename T>
        class FIRSR_Engine
        {
        protected:
            vector<T> m_taps;

            vector<T> m_dly;
            vector<T> m_dlyDst;

            vector<Ipp8u> m_spec;
            vector<Ipp8u> m_buf;

            IppAlgType m_algType;

        public:
            FIRSR_Engine() = default;

            FIRSR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

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
                FIRSR(pSrc, pDst, len, m_spec.data(), m_dly.data(), m_dlyDst.data(), m_buf.data());
                swap(m_dly, m_dlyDst);
            }
        };

        template <typename T>
        class FIRMR_Engine
        {
        protected:
            vector<T> m_taps;

            vector<T> m_dly;
            vector<T> m_dlyDst;

            vector<Ipp8u> m_spec;
            vector<Ipp8u> m_buf;

            IppAlgType m_algType;

        public:
            FIRMR_Engine() = default;

            FIRMR_Engine(T *taps, int taplen, IppAlgType algType = IppAlgType::ippAlgDirect) { initialise(taps, taplen, algType); }

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
                FIRMR(pSrc, pDst, len, m_spec, m_dly, m_dlyDst, m_buf);
                swap(m_dly, m_dlyDst);
            }
        };

        template <typename T>
        class FIRGen_Engine
        {
        protected:
            vector<T> m_buffer;
            int m_tapsLen;

        public:
            FIRGen_Engine() = default;
            FIRGen_Engine(int tapsLen)
            {
                initialise(tapsLen);
            }

            void initialise(int tapsLen)
            {
                m_tapsLen = tapsLen;
                int bufSize;
                OptionalAssertNoError(ippsFIRGenGetBufferSize(tapsLen, &bufSize));
                m_buffer.resize(bufSize);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("FIRGen not initialized");
            }

            IppStatus highpass(Ipp64f rFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenHighpass_64f(rFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus lowpass(Ipp64f rFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenLowpass_64f(rFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus bandpass(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenBandpass_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }

            IppStatus bandstop(Ipp64f rLowFreq, Ipp64f rHighFreq, Ipp64f *pTaps, IppWinType winType, IppBool doNormal)
            {
                assertIsInitialised();
                // winType: ippWinBartlett,ippWinBlackman,ippWinHamming,ippWinHann,ippWinRect
                return OptionalAssertNoError(
                    ippsFIRGenBandstop_64f(rLowFreq, rHighFreq, pTaps, m_tapsLen, winType, doNormal, m_buffer.data()));
            }
        };

        template <typename T>
        class FIRLMS_Engine
        {
        protected:
            float mu = 0.001f;
            vector<Ipp8u> m_buffer;
            IppsFIRLMSState_32f *pState = nullptr; // TODO: change this to vector

        public:
            // TODO: add mu as a parameter to the constructor
            // TODO: check how to use this class

            FIRLMS_Engine() = default;

            explicit FIRLMS_Engine(int tapsLen)
            {
                int BufferSize;
                OptionalAssertNoError(ippsFIRLMSGetStateSize_32f(tapsLen, 0, &BufferSize));
                m_buffer.resize(BufferSize);
                // zero initialise taps and delay line
                OptionalAssertNoError(ippsFIRLMSInit_32f(&pState, nullptr, tapsLen, nullptr, 0, m_buffer.data()));
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
            vector<Ipp8u> m_buffer;
            int m_src1Len, m_src2Len, m_dstLen, m_lowLag;
            int m_algType;

        public:
            CrossCorrNorm_Engine() = default;

            explicit CrossCorrNorm_Engine(int len) { initialise(len); }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("CrossCorrNorm not initialized");
            }

            void initialise(int src1Len, int src2Len, int dstLen, int lowLag, int algType)
            {
                // algoType : Bit-field mask for the algorithm type definition. Possible values are the results of composition of the IppAlgType and IppsNormOp values.
                // IppAlgType : ippAlgAuto, ippAlgDirect, ippAlgFFT, ippAlgMask
                // IppsNormOp : ippsNormNone, ippsNormA, ippsNormB, ippsNormMask

                int BufferSize;
                ippsCrossCorrNormGetBufferSize(src1Len, src2Len, dstLen, lowLag, GetIppDataType<T>(), algType, &BufferSize);
                m_buffer.resize(BufferSize);
                m_src1Len = src1Len;
                m_src2Len = src2Len;
                m_dstLen = dstLen;
                m_lowLag = lowLag;
                m_algType = algType;
            }

            void filter(const Ipp64fc *pSrc1, int src1Len, const Ipp64fc *pSrc2, int src2Len, Ipp64fc *pDst, int dstLen, int lowLag)
            {
                assertIsInitialised();
                CrossCorrNorm(pSrc1, src1Len, pSrc2, src2Len, pDst, dstLen, lowLag, m_algType, m_buffer.data());
            }
        };

        template <typename T>
        class FilterMedian_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            vector<T> m_srcDly;
            vector<T> m_dstDly;
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
                m_buffer.resize(bufferSize);

                int dlyLen = maskSize - 1;
                m_srcDly.resize(dlyLen);
                m_dstDly.resize(dlyLen);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("FilterMedian not initialized");
            }

            IppStatus filter(const T *pSrc, T *pDst, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(ippsFilterMedian(pSrc, pDst, len, m_maskSize, m_srcDly.data(), m_dstDly.data(), m_buffer.data()));
            }

            IppStatus filter_I(const T *pSrcDst, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(ippsFilterMedian_I(pSrcDst, len, m_maskSize, m_srcDly.data(), m_dstDly.data(), m_buffer.data()));
            }

            void getSrcDlyLine(T *pDlyLine)
            {
                for (int i = 0; i < m_srcDly.size(); ++i)
                {
                    pDlyLine[i] = m_srcDly[i];
                }
            }

            IppStatus setSrcDlyLine(const T *pDlyLine)
            {
                m_srcDly.set_array(pDlyLine);
            }

            void getDstDlyLine(T *pDlyLine)
            {
                for (int i = 0; i < m_dstDly.size(); ++i)
                {
                    pDlyLine[i] = m_dstDly[i];
                }
            }

            IppStatus setDstDlyLine(const T *pDlyLine)
            {
                m_dstDly.set_array(pDlyLine);
            }
        };

        template <typename T>
        class Hilbert_Engine
        {
        protected:
            vector<Ipp8u> m_buffer;
            vector<Ipp8u> m_spec;
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
                m_buffer.resize(bufferSize);
                m_spec.resize(specSize);

                OptionalAssertNoError(HilbertInit<T>(length, ippAlgHintAccurate, (IppsHilbertSpec *)m_spec.data(), m_buffer.data()));
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("Hilbert_Engine not initialized");
            }

            IppStatus Fwd(const T *pSrc, T *pDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(Hilbert(pSrc, pDst, (IppsHilbertSpec *)m_spec.data(), m_buffer.data()));
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
            vector<Ipp8u> m_buffer;
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
                m_buffer.resize(bufferSize);
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("TopK_Engine not initialized");
            }

            IppStatus get_topk(const T *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, T *pDstValue, Ipp64s *pDstIndex)
            {
                assertIsInitialised();
                OptionalAssertNoError(TopKInit(pDstValue, pDstIndex, m_dstLen));
                return OptionalAssertNoError(TopK(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, m_dstLen, m_hint, m_buffer.data()));
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
            vector<Ipp8u> m_buffer;
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
                m_buffer.resize(BufferSize);
                m_srcLen = srcLen;
                m_dstLen = dstLen;
                m_algType = algType;
            }

            void assertIsInitialised()
            {
                if (m_buffer.empty())
                    throw std::runtime_error("AutoCorrNorm_Engine not initialized");
            }

            IppStatus filter(const T *pSrc, T *pDst)
            {
                assertIsInitialised();
                return OptionalAssertNoError(AutoCorrNorm(pSrc, m_srcLen, pDst, m_dstLen, m_algType, m_buffer.data()));
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

        // TODO: Create Engine for ResamplePolyphase

        // TODO: Create Engine for FIRSparse

        // TODO: Create Engine for WT
        // TODO: Create Engine for IIR
        // TODO: Create Engine for PatternMatch

        template <typename T>
        class RandGauss_Engine
        {
        protected:
            vector<T> m_pRandGaussState;
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
                m_pRandGaussState.resize(size);

                OptionalAssertNoError(RandGaussInit(m_pRandGaussState.data(), m_mean, m_stdDev, m_seed));
            }

            void assertIsInitialised()
            {
                if (m_pRandGaussState.empty())
                    throw std::runtime_error("RandGauss_Engine not initalized");
            }

            IppStatus sample(T *output, int len)
            {
                assertIsInitialised();
                return OptionalAssertNoError(RandGauss(output, len, m_pRandGaussState.data()));
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

    }
}
