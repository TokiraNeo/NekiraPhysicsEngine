/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once


#include <Matrices/Internal/MatrixBase.hpp>
#include <Utility/MathUtilities.hpp>


NAMESPACE_BEGIN(BE::Math)

/// TSquareMatrix<>
template <typename T, char N = 2>
    requires TMatrixInternal::TMatrixConcept<T, N>
struct TSquareMatrix final
{
    static_assert((N >= 2), "Square matrix must be at least 2x2.");

private:
    T Data[N * N];

public:
    ~TSquareMatrix() = default;
    TSquareMatrix() = default;

    TSquareMatrix(const TSquareMatrix&) = default;
    TSquareMatrix& operator=(const TSquareMatrix&) = default;

    TSquareMatrix(TSquareMatrix&&) = default;
    TSquareMatrix& operator=(TSquareMatrix&&) = default;

    float* operator[](char index) const;

    TSquareMatrix operator*(T scalar) const;
    // @[TODO] Matrix Multiplication
    // TSquareMatrix operator*(const TSquareMatrix& other) const;

    // Get Transpose of the matrix
    TSquareMatrix Transpose() const;
};


/* ====-------------------------------------------==== */
// Implementation of TSquareMatrix<>
/* ====-------------------------------------------==== */

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
float* TSquareMatrix<T, N>::operator[](char index) const
{
    index = Clamp<char>(index, 0, N - 1);
    // @example:
    // For a 3x3 matrix (N=3), [1][1] -> *(Data[1] + 1) -> Data[4]
    return &Data[index * N];
}

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N> TSquareMatrix<T, N>::operator*(T scalar) const
{
    TSquareMatrix<T, N> result;
    for (char i = 0; i < (N * N); ++i)
    {
        result.Data[i] = Data[i] * scalar;
    }
    return result;
}


template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N> TSquareMatrix<T, N>::Transpose() const
{
    TSquareMatrix<T, N> result;
    for (char i = 0; i < (N * N); ++i)
    {
        const char ROW = i / N;
        const char COL = i % N;
        result.Data[i] = Data[(COL * N) + ROW];
    }
    return result;
}

NAMESPACE_END() // namespace BE::Math