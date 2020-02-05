//
// Created by dchansen on 1/31/20.
//

#include "cpp_lapack.h"
#include <vector>

#ifdef USE_MKL
#include "mkl.h"
#else
extern "C" {
#include "lapacke.h"
}
#endif

Gadgetron::Lapack::Int Gadgetron::Lapack::potrf(bool upper, size_t n, float* a, size_t lda) {
    return LAPACKE_spotrf(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potrf(bool upper, size_t n, double* a, size_t lda) {
    return LAPACKE_dpotrf(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potrf(bool upper, size_t n, std::complex<float>* a, size_t lda) {
    return LAPACKE_cpotrf(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_float*>(a),lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potrf(bool upper, size_t n, std::complex<double>* a, size_t lda) {
    return LAPACKE_zpotrf(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_double*>(a),lda);
}

Gadgetron::Lapack::Int Gadgetron::Lapack::heev(
    bool eigenvectors, bool upper, size_t n, std::complex<float>* a, size_t lda, float* w) {
    return LAPACKE_cheev(LAPACK_COL_MAJOR,eigenvectors ? 'V' : 'N',upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_float*>(a),lda, w);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::heev(
    bool eigenvectors, bool upper, size_t n, std::complex<double>* a, size_t lda, double* w) {

    return LAPACKE_zheev(LAPACK_COL_MAJOR,eigenvectors ? 'V' : 'N',upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_double*>(a),lda, w);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::syev(bool eigenvectors, bool upper, size_t n, float* a, size_t lda, float* w) {
    return LAPACKE_ssyev(LAPACK_COL_MAJOR,eigenvectors ? 'V' : 'N',upper ? 'U' : 'L',n, a,lda, w);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::syev(bool eigenvectors, bool upper, size_t n, double* a, size_t lda, double* w) {
    return LAPACKE_dsyev(LAPACK_COL_MAJOR,eigenvectors ? 'V' : 'N',upper ? 'U' : 'L',n, a,lda, w);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potri(bool upper, size_t n, float* a, size_t lda) {
    return LAPACKE_spotri(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potri(bool upper, size_t n, double* a, size_t lda) {
    return LAPACKE_dpotri(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potri(bool upper, size_t n, std::complex<float>* a, size_t lda) {
    return LAPACKE_cpotri(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_float*>(a),lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::potri(bool upper, size_t n, std::complex<double>* a, size_t lda) {
    return LAPACKE_zpotri(LAPACK_COL_MAJOR, upper ? 'U' : 'L',n, reinterpret_cast<lapack_complex_double*>(a),lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::tritri(bool upper, bool unittriangular, size_t n, float* a, size_t lda) {
    return LAPACKE_strtri(LAPACK_COL_MAJOR,upper ? 'U' : 'L', unittriangular ? 'U' : 'N',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::tritri(bool upper, bool unittriangular, size_t n, double* a, size_t lda) {
    return LAPACKE_dtrtri(LAPACK_COL_MAJOR,upper ? 'U' : 'L', unittriangular ? 'U' : 'N',n,a,lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::tritri(bool upper, bool unittriangular, size_t n, std::complex<float>* a, size_t lda) {
    return LAPACKE_ctrtri(LAPACK_COL_MAJOR,upper ? 'U' : 'L', unittriangular ? 'U' : 'N',n, reinterpret_cast<lapack_complex_float*>(a),lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::tritri(bool upper, bool unittriangular, size_t n, std::complex<double>* a, size_t lda) {
    return LAPACKE_ztrtri(LAPACK_COL_MAJOR,upper ? 'U' : 'L', unittriangular ? 'U' : 'N',n, reinterpret_cast<lapack_complex_double*>(a),lda);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::posv(bool upper, size_t n, size_t nrhs, float* a, size_t lda, float* b, size_t ldb) {
    return LAPACKE_sposv(LAPACK_COL_MAJOR,upper ? 'U' : 'L', n, nrhs,a,lda,b,ldb);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::posv(bool upper, size_t n, size_t nrhs, double* a, size_t lda, double* b, size_t ldb) {
    return LAPACKE_dposv(LAPACK_COL_MAJOR,upper ? 'U' : 'L', n, nrhs,a,lda,b,ldb);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::posv(
    bool upper, size_t n, size_t nrhs, std::complex<float>* a, size_t lda, std::complex<float>* b, size_t ldb) {
    return LAPACKE_cposv(LAPACK_COL_MAJOR,upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_float*>(a),lda,
        reinterpret_cast<lapack_complex_float*>(b),ldb);
}
Gadgetron::Lapack::Int Gadgetron::Lapack::posv(
    bool upper, size_t n, size_t nrhs, std::complex<double>* a, size_t lda, std::complex<double>* b, size_t ldb) {
    return LAPACKE_zposv(LAPACK_COL_MAJOR,upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_double*>(a),lda,
                         reinterpret_cast<lapack_complex_double*>(b),ldb);
}


namespace {
    template<class T>
        class int_converter {

        public:
            int_converter(T* outside, size_t n) : internal_storage(n), elements(n),outside_data(outside) {
                data = internal_storage.data();
            }

            ~int_converter(){
                std::copy(internal_storage.begin(),internal_storage.end(),outside_data);
            }
            lapack_int* data;
        private:
            T* outside_data;
            size_t elements;
            std::vector<lapack_int> internal_storage;
        };

    template<>
    class int_converter<lapack_int> {

    public:
        int_converter(lapack_int* outside,size_t n) : data(outside) {};
        lapack_int* data;
    };
}

Gadgetron::Lapack::Int Gadgetron::Lapack::hesv(bool upper, size_t n, size_t nrhs, std::complex<float> *a, size_t lda, Int *ipiv,
                                  std::complex<float> *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_chesv(LAPACK_COL_MAJOR, upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_float*>(a),lda, converter.data,
                         reinterpret_cast<lapack_complex_float*>(b),ldb);


}

Gadgetron::Lapack::Int Gadgetron::Lapack::hesv(bool upper, size_t n, size_t nrhs, std::complex<double> *a, size_t lda, Int *ipiv,
                                  std::complex<double> *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_zhesv(LAPACK_COL_MAJOR, upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_double*>(a),lda, converter.data,
                         reinterpret_cast<lapack_complex_double*>(b),ldb);
}

Gadgetron::Lapack::Int
Gadgetron::Lapack::sysv(bool upper, size_t n, size_t nrhs, float *a, size_t lda, Int *ipiv, float *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_ssysv(LAPACK_COL_MAJOR,upper ? 'U' : 'L',n,nrhs,a,lda,converter.data,b,ldb);
}

Gadgetron::Lapack::Int
Gadgetron::Lapack::sysv(bool upper, size_t n, size_t nrhs, double *a, size_t lda, Int *ipiv, double *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_dsysv(LAPACK_COL_MAJOR,upper ? 'U' : 'L',n,nrhs,a,lda,converter.data,b,ldb);

}

Gadgetron::Lapack::Int Gadgetron::Lapack::syv(bool upper, size_t n, size_t nrhs, std::complex<float> *a, size_t lda, Int *ipiv,
                                 std::complex<float> *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_csysv(LAPACK_COL_MAJOR, upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_float*>(a),lda, converter.data,
        reinterpret_cast<lapack_complex_float*>(b),ldb);
}

Gadgetron::Lapack::Int Gadgetron::Lapack::sysv(bool upper, size_t n, size_t nrhs, std::complex<double> *a, size_t lda, Int *ipiv,
                                  std::complex<double> *b, size_t ldb) {
    auto converter = int_converter<Int>(ipiv,n);
    return LAPACKE_zsysv(LAPACK_COL_MAJOR, upper ? 'U' : 'L', n, nrhs, reinterpret_cast<lapack_complex_double*>(a),lda, converter.data,
                         reinterpret_cast<lapack_complex_double*>(b),ldb);
}
