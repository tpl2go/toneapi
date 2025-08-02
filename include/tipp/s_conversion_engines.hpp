#pragma once
#include "s_conversion.hpp"
#include "tipp_error.hpp"
#include "tipp_vector.hpp"
#include <stdexcept>
#include <utility>

namespace tipp {
  namespace s {
    template <typename T>
    class SortRadix_Engine {
    protected:
      vector<T> m_Buffer;
      int m_len;

    public:
      SortRadix_Engine() = default;

      explicit SortRadix_Engine(int len) { initialise(len); }

      void assertIsInitialised() {
        if (m_Buffer.empty())
          throw std::runtime_error("SortRadix_Engine not initialized");
      }

      void initialise(int len) {
        int BufferSize;
        SortRadixGetBufferSize<T>(len, &BufferSize);
        m_Buffer.resize(BufferSize);
        m_len = len;
      }

      void sortAscend_I(T *pSrcDst) {
        assertIsInitialised;
        SortRadixAscend_I(pSrcDst, m_len, m_Buffer.data());
      }
      void sortDescend_I(T *pSrcDst) {
        assertIsInitialised;
        SortRadixDescend_I(pSrcDst, m_len, m_Buffer.data());
      }
    };

    template <typename T>
    class SortRadix_L_Engine {
    protected:
      vector<T> m_Buffer;
      int m_len;

    public:
      SortRadix_L_Engine() = default;

      explicit SortRadix_L_Engine(int len) { initialise(len); }

      void assertIsInitialised() {
        if (m_Buffer.empty())
          throw std::runtime_error("SortRadix_L_Engine not initialized");
      }

      void initialise(int len) {
        int BufferSize;
        SortRadixGetBufferSize_L<T>(len, &BufferSize);
        m_Buffer.resize(BufferSize);
        m_len = len;
      }

      void sortAscend_I(T *pSrcDst) {
        assertIsInitialised();
        SortRadixAscend_I_L(pSrcDst, m_len, m_Buffer.data());
      }
      void sortDescend_I(T *pSrcDst) {
        assertIsInitialised();
        SortRadixDescend_I_L(pSrcDst, m_len, m_Buffer.data());
      }
    };

    template <typename T>
    class SortRadixIndex_Engine {
    protected:
      vector<T> m_Buffer;
      int m_len;

    public:
      SortRadixIndex_Engine() = default;

      explicit SortRadixIndex_Engine(int len) { initialise(len); }

      void initialise(int len) {
        int BufferSize;
        SortRadixIndexGetBufferSize<T>(len, &BufferSize);
        m_Buffer.resize(BufferSize);
        m_len = len;
      }

      void assertIsInitialised() {
        if (m_Buffer.empty())
          throw std::runtime_error("SortRadixIndex_Engine not initialized");
      }

      IppStatus sortAscend(const T *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len) {
        assertIsInitialised();
        return OptionalAssertNoError(SortRadixIndexAscend(pSrc, srcStrideBytes, pDstIndx, len, m_Buffer.data()));
      }
      IppStatus sortDescend(const T *pSrc, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len) {
        assertIsInitialised();
        return OptionalAssertNoError(SortRadixIndexDescend(pSrc, srcStrideBytes, pDstIndx, len, m_Buffer.data()));
      }
    };

    template <typename T>
    class TopK_Engine {
    protected:
      vector<Ipp8u> m_Buffer;
      int m_srcLen;
      int m_dstLen;
      IppTopKMode m_hint; // ippTopKAuto, ippTopKDirect, ippTopKRadix

    public:
      TopK_Engine() = default;

      TopK_Engine(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto) { initialise(srcLen, dstLen, hint); }

      void initialise(Ipp64s srcLen, Ipp64s dstLen, IppTopKMode hint = ippTopKAuto) {
        // Parameter to choose the optimization that is most suitable for the srcLen+dstlen(K) combination, supported values: ippTopKAuto/ ippTopKDirect/ ippTopKRadix.

        m_srcLen = srcLen;
        m_dstLen = dstLen;
        m_hint = hint;
        int bufferSize;
        OptionalAssertNoError(ippsTopKGetBufferSize(srcLen, dstLen, GetIppDataType<T>(), hint, &bufferSize));
        m_Buffer.resize(bufferSize);
      }

      void assertIsInitialised() {
        if (m_Buffer.empty())
          throw std::runtime_error("TopK_Engine not initialized");
      }

      IppStatus topk(const T *pSrc, Ipp64s srcIndex, Ipp64s srcStride, Ipp64s srcLen, T *pDstValue, Ipp64s *pDstIndex) {
        assertIsInitialised();
        OptionalAssertNoError(TopKInit(pDstValue, pDstIndex, m_dstLen));
        return OptionalAssertNoError(TopK(pSrc, srcIndex, srcStride, srcLen, pDstValue, pDstIndex, m_dstLen, m_hint, m_Buffer.data()));
      }

      std::pair<vector<T>, vector<Ipp64s>> topk_V(vector<T> Src) {
        if (Src.size() != m_srcLen)
          throw std::invalid_argument("Input vector size does not match the initialized source length");

        vector<T> DstValue(m_dstLen);
        vector<Ipp64s> DstIndex(m_dstLen);
        topk(Src.data(), 0, sizeof(T), Src.size(), DstValue.data(), DstIndex.data());

        return std::make_pair(std::move(DstValue), std::move(DstIndex));
      }
    };
  } // namespace s
} // namespace tipp
