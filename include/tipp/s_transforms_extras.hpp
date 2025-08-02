#pragma once
#include <algorithm>
#include <omp.h>

namespace tipp
{
    namespace s
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
    }

}
