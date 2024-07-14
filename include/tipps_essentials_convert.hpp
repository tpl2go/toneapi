#include <ipps.h>
#include <ipps_l.h>
#include <complex>
#include "tipp_error.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <vector>

namespace tipp
{

    static inline void SortAscend_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSortAscend_8u_I(pSrcDst, len)); }
    static inline void SortAscend_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSortAscend_16u_I(pSrcDst, len)); }
    static inline void SortAscend_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsSortAscend_16s_I(pSrcDst, len)); }
    static inline void SortAscend_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsSortAscend_32s_I(pSrcDst, len)); }
    static inline void SortAscend_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSortAscend_32f_I(pSrcDst, len)); }
    static inline void SortAscend_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSortAscend_64f_I(pSrcDst, len)); }

    static inline void SortDescend_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSortDescend_8u_I(pSrcDst, len)); }
    static inline void SortDescend_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSortDescend_16u_I(pSrcDst, len)); }
    static inline void SortDescend_I(Ipp16s *pSrcDst, int len) { AssertNoError(ippsSortDescend_16s_I(pSrcDst, len)); }
    static inline void SortDescend_I(Ipp32s *pSrcDst, int len) { AssertNoError(ippsSortDescend_32s_I(pSrcDst, len)); }
    static inline void SortDescend_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsSortDescend_32f_I(pSrcDst, len)); }
    static inline void SortDescend_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsSortDescend_64f_I(pSrcDst, len)); }

    static inline void SortIndexAscend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_8u_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexAscend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_16u_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexAscend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_16s_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexAscend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_32s_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexAscend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_32f_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexAscend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexAscend_64f_I(pSrcDst, pDstIdx, len)); }

    static inline void SortIndexDescend_I(Ipp8u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_8u_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexDescend_I(Ipp16u *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_16u_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexDescend_I(Ipp16s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_16s_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexDescend_I(Ipp32s *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_32s_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexDescend_I(Ipp32f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_32f_I(pSrcDst, pDstIdx, len)); }
    static inline void SortIndexDescend_I(Ipp64f *pSrcDst, int *pDstIdx, int len) { AssertNoError(ippsSortIndexDescend_64f_I(pSrcDst, pDstIdx, len)); }

    template <typename T>
    static inline void SortRadixGetBufferSize<T>(int len, int *pBuffferSize);
    template <>
    SortRadixGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp8u, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp16u, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp32u, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp64u, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp16s, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp32s, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp64s, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp32f, pBuffferSize); }
    template <>
    SortRadixGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize(len, IppDataType::ipp64f, pBuffferSize); }

    static inline void SortRadixAscend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64f_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_32f_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_32u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_32s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_16u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_16s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_8u_I(pSrcDst, len, pBuffer)); }

    static inline void SortRadixDescend_I(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64f_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_32f_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp32u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_32u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_32s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp16u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_16u_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp16s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_16s_I(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I(Ipp8u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_8u_I(pSrcDst, len, pBuffer)); }

    template <typename T>
    class SortRadix
    {
    private:
        vector<T> m_buffer;
        int m_len;

    public:
        explicit SortRadix(int len) { initialise(len); }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixGetBufferSize<T>(len, &BufferSize);
            m_buffer.resize(BufferSize);
            m_len = len;
        }

        void sortAscend_I(T *pSrcDst) { SortRadixAscend_I(pSrcDst, m_len, m_buffer.data()); }
        void sortDescend_I(T *pSrcDst) { SortRadixDescend_I(pSrcDst, m_len, m_buffer.data()); }
    };

    template <typename T>
    static inline void SortRadixGetBufferSize_L<T>(int len, int *pBuffferSize);

    template <>
    SortRadixGetBufferSize_L<Ipp64u>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64u, pBuffferSize); }
    template <>
    SortRadixGetBufferSize_L<Ipp32s>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32s, pBuffferSize); }
    template <>
    SortRadixGetBufferSize_L<Ipp64s>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64s, pBuffferSize); }
    template <>
    SortRadixGetBufferSize_L<Ipp32f>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp32f, pBuffferSize); }
    template <>
    SortRadixGetBufferSize_L<Ipp64f>(int len, int *pBuffferSize) { ippsSortRadixGetBufferSize_L(len, IppDataType::ipp64f, pBuffferSize); }

    static inline void SortRadixAscend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64f_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64s_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_64u_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_32f_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixAscend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixAscend_32s_I_L(pSrcDst, len, pBuffer)); }

    static inline void SortRadixDescend_I_L(Ipp64f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64f_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I_L(Ipp64s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64s_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I_L(Ipp64u *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_64u_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I_L(Ipp32f *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_32f_I_L(pSrcDst, len, pBuffer)); }
    static inline void SortRadixDescend_I_L(Ipp32s *pSrcDst, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixDescend_32s_I_L(pSrcDst, len, pBuffer)); }

    template <typename T>
    class SortRadix_L
    {
    private:
        vector<T> m_buffer;
        int m_len;

    public:
        explicit SortRadix_L(int len) { initialise(len); }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixGetBufferSize_L<T>(len, &BufferSize);
            m_buffer.resize(BufferSize);
            m_len = len;
        }

        void sortAscend_I(T *pSrcDst) { SortRadixAscend_I_L(pSrcDst, m_len, m_buffer.data()); }
        void sortDescend_I(T *pSrcDst) { SortRadixDescend_I_L(pSrcDst, m_len, m_buffer.data()); }
    };

    template <typename T>
    static inline void SortRadixIndexGetBufferSize<T>(int len, int *pBuffferSize);
    template <>
    SortRadixIndexGetBufferSize<Ipp8u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp8u, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp16u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16u, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp32u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32u, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp64u>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64u, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp16s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp16s, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp32s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32s, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp64s>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64s, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp32f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp32f, pBuffferSize); }
    template <>
    SortRadixIndexGetBufferSize<Ipp64f>(int len, int *pBuffferSize) { ippsSortRadixIndexGetBufferSize(len, IppDataType::ipp64f, pBuffferSize); }

    static inline void SortRadixIndexAscend_I(Ipp64f *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_64f_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp64s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_64s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp64u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_64u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp32f *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_32f_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp32u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_32u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp32s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_32s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp16u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_16u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp16s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_16s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexAscend_I(Ipp8u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexAscend_8u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }

    static inline void SortRadixIndexDescend_I(Ipp64f *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_64f_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp64s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_64s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp64u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_64u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp32f *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_32f_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp32u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_32u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp32s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_32s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp16u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_16u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp16s *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_16s_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }
    static inline void SortRadixIndexDescend_I(Ipp8u *pSrcDst, Ipp32s srcStrideBytes, Ipp32s *pDstIndx, int len, Ipp8u *pBuffer) { AssertNoError(ippsSortRadixIndexDescend_8u_I(pSrcDst, srcStrideBytes, pDstIndx, len, pBuffer)); }

    template <typename T>
    class SortRadixIndex
    {
    private:
        vector<T> m_buffer;
        int m_len;

    public:
        explicit SortRadix(int len) { initialise(len); }

        void initialise(int len)
        {
            int BufferSize;
            SortRadixGetBufferSize<T>(len, &BufferSize);
            m_buffer.resize(BufferSize);
            m_len = len;
        }

        void sortAscend_I(T *pSrcDst) { SortRadixAscend_I(pSrcDst, m_len, m_buffer.data()); }
        void sortDescend_I(T *pSrcDst) { SortRadixDescend_I(pSrcDst, m_len, m_buffer.data()); }
    };

    //   ippsTopKGetBufferSize
    //   ippsTopKInit_32f
    //   ippsTopKInit_32s
    //   ippsTopK_32f
    //   ippsTopK_32s

    static inline void Conj(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsConj_16sc(pSrc, pDst, len)); }
    static inline void Conj(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsConj_32fc(pSrc, pDst, len)); }
    static inline void Conj(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsConj_64fc(pSrc, pDst, len)); }

    static inline void Conj_I(Ipp16sc *pSrcDst, int len) { AssertNoError(ippsConj_16sc_I(pSrcDst, len)); }
    static inline void Conj_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsConj_32fc_I(pSrcDst, len)); }
    static inline void Conj_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsConj_64fc_I(pSrcDst, len)); }

    static inline void ConjFlip(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsConjFlip_16sc(pSrc, pDst, len)); }
    static inline void ConjFlip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsConjFlip_32fc(pSrc, pDst, len)); }
    static inline void ConjFlip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsConjFlip_64fc(pSrc, pDst, len)); }

    static inline void Magnitude(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void Magnitude(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsMagnitude_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void Magnitude(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_32fc(pSrc, pDst, len)); }
    static inline void Magnitude(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsMagnitude_64fc(pSrc, pDst, len)); }
    static inline void Magnitude(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_16s32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void Magnitude(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsMagnitude_16sc32f(pSrc, pDst, len)); }

    static inline void Phase(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsPhase_64fc(pSrc, pDst, len)); }
    static inline void Phase(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_32fc(pSrc, pDst, len)); }
    static inline void Phase(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_16sc32f(pSrc, pDst, len)); }
    static inline void Phase(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsPhase_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void Phase(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void Phase(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPhase_16s32f(pSrcRe, pSrcIm, pDst, len)); }

    static inline void PowerSpectr(const Ipp64fc *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsPowerSpectr_64fc(pSrc, pDst, len)); }
    static inline void PowerSpectr(const Ipp32fc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_32fc(pSrc, pDst, len)); }
    static inline void PowerSpectr(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDst, int len) { AssertNoError(ippsPowerSpectr_64f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void PowerSpectr(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void PowerSpectr(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_16s32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void PowerSpectr(const Ipp16sc *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsPowerSpectr_16sc32f(pSrc, pDst, len)); }

    static inline void RealToCplx(const Ipp16s *pSrcRe, const Ipp16s *pSrcIm, Ipp16sc *pDst, int len) { AssertNoError(ippsRealToCplx_16s(pSrcRe, pSrcIm, pDst, len)); }
    static inline void RealToCplx(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32fc *pDst, int len) { AssertNoError(ippsRealToCplx_32f(pSrcRe, pSrcIm, pDst, len)); }
    static inline void RealToCplx(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64fc *pDst, int len) { AssertNoError(ippsRealToCplx_64f(pSrcRe, pSrcIm, pDst, len)); }

    static inline void Real(const Ipp16sc *pSrc, Ipp16s *pDstRe, int len) { AssertNoError(ippsReal_16sc(pSrc, pDstRe, len)); }
    static inline void Real(const Ipp32fc *pSrc, Ipp32f *pDstRe, int len) { AssertNoError(ippsReal_32fc(pSrc, pDstRe, len)); }
    static inline void Real(const Ipp64fc *pSrc, Ipp64f *pDstRe, int len) { AssertNoError(ippsReal_64fc(pSrc, pDstRe, len)); }

    static inline void Imag(const Ipp16sc *pSrc, Ipp16s *pDstIm, int len) { AssertNoError(ippsImag_16sc(pSrc, pDstIm, len)); }
    static inline void Imag(const Ipp32fc *pSrc, Ipp32f *pDstIm, int len) { AssertNoError(ippsImag_32fc(pSrc, pDstIm, len)); }
    static inline void Imag(const Ipp64fc *pSrc, Ipp64f *pDstIm, int len) { AssertNoError(ippsImag_64fc(pSrc, pDstIm, len)); }

    static inline void Threshold_LTAbsVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTAbsVal_32f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTAbsVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTAbsVal_64f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTAbsVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTAbsVal_16s(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTAbsVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s level, Ipp32s value) { AssertNoError(ippsThreshold_LTAbsVal_32s(pSrc, pDst, len, level, value)); }

    static inline void Threshold_LTAbsVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTAbsVal_32f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTAbsVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTAbsVal_64f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTAbsVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTAbsVal_16s_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTAbsVal_I(Ipp32s *pSrcDst, int len, Ipp32s level, Ipp32s value) { AssertNoError(ippsThreshold_LTAbsVal_32s_I(pSrcDst, len, level, value)); }

    static inline void Threshold_LTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTVal_16s(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTVal_32f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTVal_64f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_LTVal_16sc(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_LTVal_32fc(pSrc, pDst, len, level, value)); }
    static inline void Threshold_LTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_LTVal_64fc(pSrc, pDst, len, level, value)); }

    static inline void Threshold_GTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_GTVal_16s(pSrc, pDst, len, level, value)); }
    static inline void Threshold_GTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_GTVal_32f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_GTVal(const Ipp64f *pSrc, Ipp64f *pDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_GTVal_64f(pSrc, pDst, len, level, value)); }
    static inline void Threshold_GTVal(const Ipp16sc *pSrc, Ipp16sc *pDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_GTVal_16sc(pSrc, pDst, len, level, value)); }
    static inline void Threshold_GTVal(const Ipp32fc *pSrc, Ipp32fc *pDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_GTVal_32fc(pSrc, pDst, len, level, value)); }
    static inline void Threshold_GTVal(const Ipp64fc *pSrc, Ipp64fc *pDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_GTVal_64fc(pSrc, pDst, len, level, value)); }

    static inline void Threshold_LTValGTVal(const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_16s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline void Threshold_LTValGTVal(const Ipp32s *pSrc, Ipp32s *pDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32s(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline void Threshold_LTValGTVal(const Ipp32f *pSrc, Ipp32f *pDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32f(pSrc, pDst, len, levelLT, valueLT, levelGT, valueGT)); }

    static inline void Threshold_LTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_LTVal_16s_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_LTVal_32f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_LTVal_64f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_LTVal_16sc_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_LTVal_32fc_I(pSrcDst, len, level, value)); }
    static inline void Threshold_LTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_LTVal_64fc_I(pSrcDst, len, level, value)); }

    static inline void Threshold_GTVal_I(Ipp16s *pSrcDst, int len, Ipp16s level, Ipp16s value) { AssertNoError(ippsThreshold_GTVal_16s_I(pSrcDst, len, level, value)); }
    static inline void Threshold_GTVal_I(Ipp32f *pSrcDst, int len, Ipp32f level, Ipp32f value) { AssertNoError(ippsThreshold_GTVal_32f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_GTVal_I(Ipp64f *pSrcDst, int len, Ipp64f level, Ipp64f value) { AssertNoError(ippsThreshold_GTVal_64f_I(pSrcDst, len, level, value)); }
    static inline void Threshold_GTVal_I(Ipp16sc *pSrcDst, int len, Ipp16s level, Ipp16sc value) { AssertNoError(ippsThreshold_GTVal_16sc_I(pSrcDst, len, level, value)); }
    static inline void Threshold_GTVal_I(Ipp32fc *pSrcDst, int len, Ipp32f level, Ipp32fc value) { AssertNoError(ippsThreshold_GTVal_32fc_I(pSrcDst, len, level, value)); }
    static inline void Threshold_GTVal_I(Ipp64fc *pSrcDst, int len, Ipp64f level, Ipp64fc value) { AssertNoError(ippsThreshold_GTVal_64fc_I(pSrcDst, len, level, value)); }

    static inline void Threshold_LTValGTVal_I(Ipp16s *pSrcDst, int len, Ipp16s levelLT, Ipp16s valueLT, Ipp16s levelGT, Ipp16s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_16s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline void Threshold_LTValGTVal_I(Ipp32s *pSrcDst, int len, Ipp32s levelLT, Ipp32s valueLT, Ipp32s levelGT, Ipp32s valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32s_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline void Threshold_LTValGTVal_I(Ipp32f *pSrcDst, int len, Ipp32f levelLT, Ipp32f valueLT, Ipp32f levelGT, Ipp32f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_32f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }
    static inline void Threshold_LTValGTVal_I(Ipp64f *pSrcDst, int len, Ipp64f levelLT, Ipp64f valueLT, Ipp64f levelGT, Ipp64f valueGT) { AssertNoError(ippsThreshold_LTValGTVal_64f_I(pSrcDst, len, levelLT, valueLT, levelGT, valueGT)); }

    static inline void CartToPolar(const Ipp32f *pSrcRe, const Ipp32f *pSrcIm, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_32f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }
    static inline void CartToPolar(const Ipp64f *pSrcRe, const Ipp64f *pSrcIm, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_64f(pSrcRe, pSrcIm, pDstMagn, pDstPhase, len)); }

    static inline void CartToPolar(const Ipp32fc *pSrc, Ipp32f *pDstMagn, Ipp32f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_32fc(pSrc, pDstMagn, pDstPhase, len)); }
    static inline void CartToPolar(const Ipp64fc *pSrc, Ipp64f *pDstMagn, Ipp64f *pDstPhase, int len) { AssertNoError(ippsCartToPolar_64fc(pSrc, pDstMagn, pDstPhase, len)); }

    static inline void PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32f *pDstRe, Ipp32f *pDstIm, int len) { AssertNoError(ippsPolarToCart_32f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
    static inline void PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64f *pDstRe, Ipp64f *pDstIm, int len) { AssertNoError(ippsPolarToCart_64f(pSrcMagn, pSrcPhase, pDstRe, pDstIm, len)); }
    static inline void PolarToCart(const Ipp32f *pSrcMagn, const Ipp32f *pSrcPhase, Ipp32fc *pDst, int len) { AssertNoError(ippsPolarToCart_32fc(pSrcMagn, pSrcPhase, pDst, len)); }
    static inline void PolarToCart(const Ipp64f *pSrcMagn, const Ipp64f *pSrcPhase, Ipp64fc *pDst, int len) { AssertNoError(ippsPolarToCart_64fc(pSrcMagn, pSrcPhase, pDst, len)); }

    static inline void MaxOrder(const Ipp16s *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_16s(pSrc, len, pOrder)); }
    static inline void MaxOrder(const Ipp32s *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_32s(pSrc, len, pOrder)); }
    static inline void MaxOrder(const Ipp32f *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_32f(pSrc, len, pOrder)); }
    static inline void MaxOrder(const Ipp64f *pSrc, int len, int *pOrder) { AssertNoError(ippsMaxOrder_64f(pSrc, len, pOrder)); }

    static inline void Flip(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsFlip_8u(pSrc, pDst, len)); }
    static inline void Flip(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsFlip_16u(pSrc, pDst, len)); }
    static inline void Flip(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsFlip_32f(pSrc, pDst, len)); }
    static inline void Flip(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsFlip_64f(pSrc, pDst, len)); }
    static inline void Flip(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsFlip_32fc(pSrc, pDst, len)); }
    static inline void Flip(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsFlip_64fc(pSrc, pDst, len)); }

    static inline void Flip_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsFlip_16u_I(pSrcDst, len)); }
    static inline void Flip_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsFlip_8u_I(pSrcDst, len)); }
    static inline void Flip_I(Ipp32f *pSrcDst, int len) { AssertNoError(ippsFlip_32f_I(pSrcDst, len)); }
    static inline void Flip_I(Ipp64f *pSrcDst, int len) { AssertNoError(ippsFlip_64f_I(pSrcDst, len)); }
    static inline void Flip_I(Ipp32fc *pSrcDst, int len) { AssertNoError(ippsFlip_32fc_I(pSrcDst, len)); }
    static inline void Flip_I(Ipp64fc *pSrcDst, int len) { AssertNoError(ippsFlip_64fc_I(pSrcDst, len)); }

    static inline void SwapBytes(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsSwapBytes_16u(pSrc, pDst, len)); }
    static inline void SwapBytes(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsSwapBytes_24u(pSrc, pDst, len)); }
    static inline void SwapBytes(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsSwapBytes_32u(pSrc, pDst, len)); }
    static inline void SwapBytes(const Ipp64u *pSrc, Ipp64u *pDst, int len) { AssertNoError(ippsSwapBytes_64u(pSrc, pDst, len)); }
    static inline void SwapBytes_I(Ipp16u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_16u_I(pSrcDst, len)); }
    static inline void SwapBytes_I(Ipp8u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_24u_I(pSrcDst, len)); }
    static inline void SwapBytes_I(Ipp32u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_32u_I(pSrcDst, len)); }
    static inline void SwapBytes_I(Ipp64u *pSrcDst, int len) { AssertNoError(ippsSwapBytes_64u_I(pSrcDst, len)); }

}
