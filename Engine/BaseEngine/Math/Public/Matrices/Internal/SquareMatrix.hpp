/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once


#include <EASTL/array.h>
#include <Matrices/Internal/MatrixBase.hpp>
#include <Utility/MathUtilities.hpp>



NAMESPACE_BEGIN(BE::Math)

/// TSquareMatrix<>
template <typename T, char N = 2>
    requires TMatrixInternal::TMatrixConcept<T, N>
struct TSquareMatrix
{
    static_assert((N >= 2), "Square matrix must be at least 2x2.");

private:
    /**
     * @brief In Nekira Physics Engine, we use row-major order to store matrix data.
     */
    eastl::array<T, N * N> Data{0};

public:
    virtual ~TSquareMatrix() = default;

    constexpr TSquareMatrix() = default;

    TSquareMatrix(const TSquareMatrix&);
    TSquareMatrix(TSquareMatrix&&) noexcept;

    TSquareMatrix& operator=(const TSquareMatrix&);
    TSquareMatrix& operator=(TSquareMatrix&&) noexcept;

    constexpr T* operator[](char index);

    TSquareMatrix operator*(T scalar) const;
    // Matrix Multiplication
    TSquareMatrix operator*(const TSquareMatrix& other) const;

    // Get Transpose of the matrix
    TSquareMatrix Transpose() const;
};


/* ====-------------------------------------------==== */
// Implementation of TSquareMatrix<>
/* ====-------------------------------------------==== */

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N>::TSquareMatrix(const TSquareMatrix& other) : Data(other.Data)
{}

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N>::TSquareMatrix(TSquareMatrix&& other) noexcept : Data(eastl::move(other.Data))
{}

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N>& TSquareMatrix<T, N>::operator=(const TSquareMatrix& other)
{
    if (this != &other)
    {
        Data = other.Data;
    }
    return *this;
}

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
TSquareMatrix<T, N>& TSquareMatrix<T, N>::operator=(TSquareMatrix&& other) noexcept
{
    if (this != &other)
    {
        Data = eastl::move(other.Data);
    }
    return *this;
}

template <typename T, char N>
    requires TMatrixInternal::TMatrixConcept<T, N>
constexpr T* TSquareMatrix<T, N>::operator[](char index)
{
    index = Clamp<char>(index, 0, N - 1);
    // @example:
    // For a 3x3 matrix (N=3), [1][1] -> *(Data[1] + 1) -> Data[4]
    return &(Data[index * N]);
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
TSquareMatrix<T, N> TSquareMatrix<T, N>::operator*(const TSquareMatrix& other) const
{
    // Square Matrix Multiplication will always result in a square matrix of the same size
    TSquareMatrix<T, N> result;

    for (char row = 0; row < N; ++row)
    {
        for (char col = 0; col < N; ++col)
        {
            // Calculate：C_{ij} = \sum_{k=1}^{n} A_{ik} B_{kj}
            T sum = static_cast<T>(0);
            for (char k = 0; k < N; ++k)
            {
                sum = sum + (Data[(row * N) + k] * other.Data[(k * N) + col]);
            }
            result.Data[(row * N) + col] = sum;
        }
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