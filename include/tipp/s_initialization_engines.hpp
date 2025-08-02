#pragma once
#include "s_initialization.hpp"
#include "tipp_vector.hpp"
#include "tipp_error.hpp"
#include <stdexcept>
#include <utility>

namespace tipp
{
    namespace s
    {
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
    }
}
