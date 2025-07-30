#pragma once
#include "tipp/tipps.hpp"
#include "tipp/tippvm.hpp"
#include "tipp/tippcv.hpp"
#include "tipp/tippcv.hpp"
#include "tipp/tipp_type.hpp"
#include "tipp/tipp_vector.hpp"
#include <algorithm>
#include <chrono>

namespace tipp
{
    // TPL's own convenience functions
    template <typename T>
    static inline void fftshift(T *data, const size_t nsamples)
    {
        // odd: 012 34 changes to 34 012
        int center = (nsamples + 1) / 2;
        std::rotate(data, data + center, data + nsamples);
    }

    template <typename T>
    static inline void fftshift_Rchannel(T *data, const size_t nrows, const size_t ncols, int nthreads)
    {
        int rid;
        omp_set_num_threads(nthreads);
#pragma omp parallel for
        for (rid = 0; rid < nrows; ++rid)
        {
            fftshift(data + rid * ncols, ncols);
        }
    }

    template <typename T>
    static inline void fftshift_Cchannel(T *data, const size_t nrows, const size_t ncols)
    {
        int center = (nrows + 1) / 2;
        center = center * ncols;
        std::rotate(data, data + center, data + nrows * ncols);
    }

    template <typename T>
    static inline void ifftshift(T *data, const size_t nsamples)
    {
        int center = nsamples / 2;
        std::rotate(data, data + center, data + nsamples);
    }

    template <typename T>
    static inline void ifftshift_Rchannel(T *data, const size_t nrows, const size_t ncols)
    {
        int rid;
#pragma omp parallel for
        for (rid = 0; rid < nrows; ++rid)
        {
            fftshift(data + rid * ncols, ncols);
        }
    }

    template <typename T>
    static inline void ifftshift_Cchannel(T *data, const size_t nrows, const size_t ncols)
    {
        int center = nrows / 2;
        center = center * ncols;
        std::rotate(data, data + center, data + nrows * ncols);
    }

    class HighResolutionTimer
    {
    public:
        HighResolutionTimer()
        {
            auto t = std::chrono::high_resolution_clock::now();
            elapsed_start = t;
            lap_start = t;
        }

        double lap()
        {
            auto t = std::chrono::high_resolution_clock::now();
            auto out = std::chrono::duration_cast<std::chrono::duration<double>>((t - lap_start)).count();
            lap_start = t;
            return out;
        }
        double elapsed()
        {
            auto t = std::chrono::high_resolution_clock::now();
            return std::chrono::duration_cast<std::chrono::duration<double>>((t - elapsed_start)).count();
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> elapsed_start;
        std::chrono::time_point<std::chrono::high_resolution_clock> lap_start;
    };

    // WARNING: This function will perform in-place partial sort
    template <typename T>
    static inline T median(T *x, int winlen)
    {
        std::nth_element(x, x + winlen / 2, x + winlen);
        return x[winlen / 2];
    }
}
