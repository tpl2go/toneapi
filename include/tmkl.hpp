#pragma once
#include <mkl.h>
#include "tmkl/transforms.hpp"

static inline void cblas_axpy(const MKL_INT n, const float a, const float *x, const MKL_INT incx, float *y, const MKL_INT incy) { cblas_saxpy(n, a, x, incx, y, incy); }
static inline void cblas_axpy(const MKL_INT n, const double a, const double *x, const MKL_INT incx, double *y, const MKL_INT incy) { cblas_daxpy(n, a, x, incx, y, incy); }
static inline void cblas_axpy(const MKL_INT n, const void *a, const MKL_Complex8 *x, const MKL_INT incx, MKL_Complex8 *y, const MKL_INT incy) { cblas_caxpy(n, a, x, incx, y, incy); }
static inline void cblas_axpy(const MKL_INT n, const void *a, const MKL_Complex16 *x, const MKL_INT incx, MKL_Complex16 *y, const MKL_INT incy) { cblas_zaxpy(n, a, x, incx, y, incy); }

static inline void cblas_gemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb,
                              const MKL_INT m, const MKL_INT n, const MKL_INT k, const float alpha, const float *a, const MKL_INT lda,
                              const float *b, const MKL_INT ldb, const float beta, float *c, const MKL_INT ldc)
{
    cblas_sgemm(Layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}
static inline void cblas_gemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb,
                              const MKL_INT m, const MKL_INT n, const MKL_INT k, const double alpha, const double *a, const MKL_INT lda,
                              const double *b, const MKL_INT ldb, const double beta, double *c, const MKL_INT ldc)
{
    cblas_dgemm(Layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}
static inline void cblas_gemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb,
                              const MKL_INT m, const MKL_INT n, const MKL_INT k, const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT lda,
                              const MKL_Complex8 *b, const MKL_INT ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT ldc)
{
    cblas_cgemm(Layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}
static inline void cblas_gemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb,
                              const MKL_INT m, const MKL_INT n, const MKL_INT k, const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT lda,
                              const MKL_Complex16 *b, const MKL_INT ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT ldc)
{
    cblas_zgemm(Layout, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}

static inline lapack_int LAPACKE_gesv(int matrix_layout, lapack_int n, lapack_int nrhs, float *a, lapack_int lda, lapack_int *ipiv, float *b, lapack_int ldb)
{
    return LAPACKE_sgesv(matrix_layout, n, nrhs, a, lda, ipiv, b, ldb);
}
static inline lapack_int LAPACKE_gesv(int matrix_layout, lapack_int n, lapack_int nrhs, double *a, lapack_int lda, lapack_int *ipiv, double *b, lapack_int ldb)
{
    return LAPACKE_dgesv(matrix_layout, n, nrhs, a, lda, ipiv, b, ldb);
}
static inline lapack_int LAPACKE_gesv(int matrix_layout, lapack_int n, lapack_int nrhs, lapack_complex_float *a, lapack_int lda, lapack_int *ipiv, lapack_complex_float *b, lapack_int ldb)
{
    return LAPACKE_cgesv(matrix_layout, n, nrhs, a, lda, ipiv, b, ldb);
}
static inline lapack_int LAPACKE_gesv(int matrix_layout, lapack_int n, lapack_int nrhs, lapack_complex_double *a, lapack_int lda, lapack_int *ipiv, lapack_complex_double *b, lapack_int ldb)
{
    return LAPACKE_zgesv(matrix_layout, n, nrhs, a, lda, ipiv, b, ldb);
}

static inline lapack_int LAPACKE_syev(int matrix_layout, char jobz, char uplo, lapack_int n, float *a, lapack_int lda, float *w)
{
    return LAPACKE_ssyev(matrix_layout, jobz, uplo, n, a, lda, w);
}
static inline lapack_int LAPACKE_syev(int matrix_layout, char jobz, char uplo, lapack_int n, double *a, lapack_int lda, double *w)
{
    return LAPACKE_dsyev(matrix_layout, jobz, uplo, n, a, lda, w);
}

static inline void cblas_dotu_sub(const MKL_INT n, const void *x, const MKL_INT incx, MKL_Complex8 *y, const MKL_INT incy, void *dotu)
{
    cblas_cdotu_sub(n, x, incx, y, incy, dotu);
}
static inline void cblas_dotu_sub(const MKL_INT n, const void *x, const MKL_INT incx, MKL_Complex16 *y, const MKL_INT incy, void *dotu)
{
    cblas_zdotu_sub(n, x, incx, y, incy, dotu);
}

static inline void mkl_omatcopy(char ordering, char trans, size_t rows, size_t cols, const float alpha, const float *A, size_t lda, float *B, size_t ldb)
{
    mkl_somatcopy(ordering, trans, rows, cols, alpha, A, lda, B, ldb);
}
static inline void mkl_omatcopy(char ordering, char trans, size_t rows, size_t cols, const double alpha, const double *A, size_t lda, double *B, size_t ldb)
{
    mkl_domatcopy(ordering, trans, rows, cols, alpha, A, lda, B, ldb);
}
static inline void mkl_omatcopy(char ordering, char trans, size_t rows, size_t cols, const MKL_Complex8 alpha, const MKL_Complex8 *A, size_t lda, MKL_Complex8 *B, size_t ldb)
{
    mkl_comatcopy(ordering, trans, rows, cols, alpha, A, lda, B, ldb);
}
static inline void mkl_omatcopy(char ordering, char trans, size_t rows, size_t cols, const MKL_Complex16 alpha, const MKL_Complex16 *A, size_t lda, MKL_Complex16 *B, size_t ldb)
{
    mkl_zomatcopy(ordering, trans, rows, cols, alpha, A, lda, B, ldb);
}

static inline lapack_int LAPACKE_heev(int matrix_layout, char jobz, char uplo, lapack_int n, lapack_complex_float *a, lapack_int lda, float *w)
{
    return LAPACKE_cheev(matrix_layout, jobz, uplo, n, a, lda, w);
}

static inline lapack_int LAPACKE_heev(int matrix_layout, char jobz, char uplo, lapack_int n, lapack_complex_double *a, lapack_int lda, double *w)
{
    return LAPACKE_zheev(matrix_layout, jobz, uplo, n, a, lda, w);
}
