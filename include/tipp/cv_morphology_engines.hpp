#pragma once
#include <ipp/ippcv.h>
#include <ipp/ippcv_l.h>
#include "tipp_error.hpp"
#include "tipp_vector.hpp"
#include "cv_morphology.hpp"

namespace tipp
{
    namespace cv
    {
        template <typename T, IppChannels C>
        class DilateErodeBorder_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSize m_roiSize;
            IppiSize m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            vector<T> m_BorderVector = vector<T>(static_cast<int>(C));

        public:
            DilateErodeBorder_Engine() = default;
            DilateErodeBorder_Engine(IppiSize roiSize, IppiSize maskSize, const Ipp8u *pMask) { initialise(roiSize, maskSize, pMask); }
            void initialise(IppiSize roiSize, IppiSize maskSize, const Ipp8u *pMask)
            {
                IppSizeL specSize;
                IppSizeL bufferSize;
                MorphologyBorderGetSize<T, C>(roiSize, maskSize, &specSize, &bufferSize);
                m_Spec.resize(specSize);
                m_Buffer.resize(bufferSize);
                MorphologyBorderInit<T, C>(roiSize, pMask, maskSize, (IppiMorphState *)m_Spec.data(), m_Buffer.data());
                m_roiSize = roiSize;
                m_maskSize = maskSize;
            }
            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }
            void setBorderValue(vector<T> value) { m_BorderVector = value; }
            void setBorderValue(T *value)
            {
                for (int i = 0; i < static_cast<int>(C); ++i)
                {
                    m_BorderVector[i] = value[i];
                }
            }

            void dilate(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    DilateBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], (IppiMorphState *)m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    DilateBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), (IppiMorphState *)m_Spec.data(), m_Buffer.data());
                }
            }

            void erode(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    ErodeBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], (IppiMorphState *)m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    ErodeBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), (IppiMorphState *)m_Spec.data(), m_Buffer.data());
                }
            }
        };

        template <typename T>
        class MorphGray
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSize m_roiSize;
            IppiSize m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            bool m_isIpp8u = false;

        public:
            MorphGray() = default;
            MorphGray(IppiSize roiSize, IppiSize maskSize, Ipp32s *pMask, IppiPoint anchor) { initialise(roiSize, maskSize, pMask, anchor); }
            void initialise(IppiSize roiSize, IppiSize maskSize, Ipp32s *pMask, IppiPoint anchor)
            {
                int bufferSize;
                ippiMorphGrayGetSize_8u_C1R(roiSize, pMask, maskSize, &bufferSize);
                m_Buffer.resize(bufferSize);
                ippiMorphGrayInit_8u_C1R((IppiMorphGrayState_8u *)m_Buffer.data(), roiSize, pMask, maskSize, anchor);
                m_roiSize = roiSize;
                m_maskSize = maskSize;
                m_isIpp8u = true;
            }

            MorphGray(IppiSize roiSize, IppiSize maskSize, Ipp32f *pMask, IppiPoint anchor) { initialise(roiSize, maskSize, pMask, anchor); }
            void initialise(IppiSize roiSize, IppiSize maskSize, Ipp32f *pMask, IppiPoint anchor)
            {
                int bufferSize;
                ippiMorphGrayGetSize_32f_C1R(roiSize, pMask, maskSize, &bufferSize);
                m_Buffer.resize(bufferSize);
                ippiMorphGrayInit_32f_C1R((IppiMorphGrayState_32f *)m_Buffer.data(), roiSize, pMask, maskSize, anchor);
                m_roiSize = roiSize;
                m_maskSize = maskSize;
                m_isIpp8u = false;
            }

            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }

            void erode(const Ipp8u *pSrc, int srcStep, Ipp8u *pDst, int dstStep)
            {
                if (!m_isIpp8u)
                {
                    throw std::runtime_error("Error: MorphGray was initialized for Ipp32f. Not Ipp8u");
                }
                ippiGrayErodeBorder_8u_C1R(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, (IppiMorphGrayState_8u *)m_Buffer.data());
            }

            void erode(const Ipp32f *pSrc, int srcStep, Ipp32f *pDst, int dstStep)
            {
                if (m_isIpp8u)
                {
                    throw std::runtime_error("Error: MorphGray was initialized for Ipp8u. Not Ipp32f");
                }
                ippiGrayErodeBorder_32f_C1R(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, (IppiMorphGrayState_32f *)m_Buffer.data());
            }
        };

        template <typename T, IppChannels C>
        class MorphBorder_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSize m_roiSize;
            IppiSize m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            vector<T> m_BorderVector = vector<T>(static_cast<int>(C));

        public:
            MorphBorder_Engine() = default;
            MorphBorder_Engine(IppiSize roiSize, IppiSize maskSize, Ipp8u *pMask) { initialise(roiSize, maskSize, pMask); }
            void initialise(IppiSize roiSize, IppiSize maskSize, Ipp8u *pMask)
            {
                int specSize, bufferSize;
                MorphAdvGetSize<T, C>(roiSize, maskSize, &specSize, &bufferSize);
                m_Spec.resize(specSize);
                m_Buffer.resize(bufferSize);
                MorphAdvInit<T, C>(roiSize, pMask, maskSize, (IppiMorphAdvState *)m_Spec.data(), m_Buffer.data());
                m_roiSize = roiSize;
                m_maskSize = maskSize;
            }
            // Alternative Mode: IPP_MORPH_MASK_NO_FLIP
            void setMode(int mode = IPP_MORPH_DEFAULT) { ippiMorphSetMode(mode, (IppiMorphAdvState *)m_Spec.data()); }
            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }
            void setBorderValue(T value) { m_BorderVector[0] = value; }
            void setBorderValue(vector<T> value) { m_BorderVector = value; }
            void setBorderValue(T *value)
            {
                for (int i = 0; i < static_cast<int>(C); ++i)
                {
                    m_BorderVector[i] = value[i];
                }
            }

            void open(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    MorphOpenBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    MorphOpenBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), m_Spec.data(), m_Buffer.data());
                }
            }

            void close(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    MorphCloseBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    MorphCloseBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), m_Spec.data(), m_Buffer.data());
                }
            }

            void tophat(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    MorphTophatBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    MorphTophatBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), m_Spec.data(), m_Buffer.data());
                }
            }

            void blackhat(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                if constexpr (C == ippC1)
                {
                    MorphBlackhatBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], m_Spec.data(), m_Buffer.data());
                }
                else
                {
                    MorphBlackhatBorder<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), m_Spec.data(), m_Buffer.data());
                }
            }
        };

        /////////////////
        // _L classes  //
        /////////////////

        template <typename T, IppChannels C>
        class Dilate_L_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSizeL m_roiSize;
            IppiSizeL m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            vector<T> m_BorderVector = vector<T>(static_cast<int>(C));

        public:
            Dilate_L_Engine() = default;
            Dilate_L_Engine(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask) { initialise(roiSize, maskSize, pMask); }
            void initialise(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask)
            {
                IppSizeL specSize;
                IppSizeL bufferSize;
                ippiDilateGetBufferSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &bufferSize);
                DilateGetSpecSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &specSize);
                m_Spec.resize(specSize);
                m_Buffer.resize(bufferSize);
                ippiDilateInit_L(roiSize, pMask, maskSize, (IppiMorphStateL *)m_Spec.data());
                m_roiSize = roiSize;
                m_maskSize = maskSize;
            }

            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }
            void setBorderValue(vector<T> value) { m_BorderVector = value; }
            void setBorderValue(T *value)
            {
                for (int i = 0; i < static_cast<int>(C); ++i)
                {
                    m_BorderVector[i] = value[i];
                }
            }

            void apply(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                Dilate_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], (IppiMorphStateL *)m_Spec.data(), m_Buffer.data());
            }
        };

        template <typename T, IppChannels C>
        class Erode_L_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSizeL m_roiSize;
            IppiSizeL m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            vector<T> m_BorderVector = vector<T>(static_cast<int>(C));

        public:
            Erode_L_Engine() = default;
            Erode_L_Engine(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask) { initialise(roiSize, maskSize, pMask); }
            void initialise(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask)
            {
                IppSizeL specSize;
                IppSizeL bufferSize;
                ippiErodeGetBufferSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &bufferSize);
                ippiErodeGetSpecSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &specSize);
                m_Spec.resize(specSize);
                m_Buffer.resize(bufferSize);
                ippiErodeInit_L(roiSize, pMask, maskSize, (IppiMorphStateL *)m_Spec.data());
                m_roiSize = roiSize;
                m_maskSize = maskSize;
            }

            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }
            void setBorderValue(vector<T> value) { m_BorderVector = value; }
            void setBorderValue(T *value)
            {
                for (int i = 0; i < static_cast<int>(C); ++i)
                {
                    m_BorderVector[i] = value[i];
                }
            }

            void apply(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                Erode_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], (IppiMorphStateL *)m_Spec.data(), m_Buffer.data());
            }
        };

        // Advanced Morphological Operations
        // consists of multiple morphological operation steps
        // This class supports image sizes greater than 2^32
        template <typename T, IppChannels C>
        class Morph_L_Engine
        {
        protected:
            vector<Ipp8u> m_Spec;
            vector<Ipp8u> m_Buffer;
            IppiSizeL m_roiSize;
            IppiSizeL m_maskSize;
            IppiBorderType m_borderType = ippBorderRepl;
            vector<T> m_BorderVector = vector<T>(static_cast<int>(C));

        public:
            Morph_L_Engine() = default;
            Morph_L_Engine(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask) { initialise(roiSize, maskSize, pMask); }
            void initialise(IppiSizeL roiSize, IppiSizeL maskSize, Ipp8u *pMask)
            {
                IppSizeL specSize;
                IppSizeL bufferSize;
                ippiMorphGetBufferSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &bufferSize);
                ippiMorphGetSpecSize_L(roiSize, maskSize, GetIppDataType<T>(), static_cast<int>(C), &specSize);
                m_Spec.resize(specSize);
                m_Buffer.resize(bufferSize);
                ippiMorphInit_L(roiSize, pMask, maskSize, GetIppDataType<T>(), static_cast<int>(C), (IppiMorphAdvStateL *)m_Spec.data());
                m_roiSize = roiSize;
                m_maskSize = maskSize;
            }

            // Alternative Mode: IPP_MORPH_MASK_NO_FLIP
            void setMode(int mode = IPP_MORPH_DEFAULT) { ippiMorphSetMode_L(mode, (IppiMorphAdvStateL *)m_Spec.data()); }
            void setBorderType(IppiBorderType borderType) { m_borderType = borderType; }
            void setBorderValue(vector<T> value) { m_BorderVector = value; }
            void setBorderValue(T *value)
            {
                for (int i = 0; i < static_cast<int>(C); ++i)
                {
                    m_BorderVector[i] = value[i];
                }
            }

            void Open(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                MorphOpen_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector[0], (IppiMorphAdvStateL *)m_Spec.data(), m_Buffer.data());
            }

            void Close(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                MorphClose_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), (IppiMorphAdvStateL *)m_Spec.data(), m_Buffer.data());
            }

            void TopHat(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                MorphTophat_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), (IppiMorphAdvStateL *)m_Spec.data(), m_Buffer.data());
            }

            void BlackHat(const T *pSrc, int srcStep, T *pDst, int dstStep)
            {
                MorphBlackhat_L<T, C>(pSrc, srcStep, pDst, dstStep, m_roiSize, m_borderType, m_BorderVector.data(), (IppiMorphAdvStateL *)m_Spec.data(), m_Buffer.data());
            }
        };

        template <typename T>
        class MorphReconstruct_Engine
        {
        protected:
            vector<Ipp8u> m_Buffer;
            IppiSizeL m_roiSize;

        public:
            MorphReconstruct_Engine() = default;
            MorphReconstruct_Engine(IppiSizeL roiSize) { initialise(roiSize); }
            void initialise(IppiSize roiSize)
            {
                IppSizeL bufferSize;
                ippiMorphReconstructGetBufferSize(roiSize, GetIppDataType<T>(), 1, &bufferSize);
                m_Buffer.resize(bufferSize);
                m_roiSize = roiSize;
            }

            void ReconstructErode(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiNorm norm)
            {
                MorphReconstructErode(pSrc, srcStep, pSrcDst, srcDstStep, m_roiSize, m_Buffer.data(), norm);
            }

            void ReconstructDilate(const T *pSrc, int srcStep, T *pSrcDst, int srcDstStep, IppiNorm norm)
            {
                MorphReconstructDilate(pSrc, srcStep, pSrcDst, srcDstStep, m_roiSize, m_Buffer.data(), norm);
            }
        };
    }
}
