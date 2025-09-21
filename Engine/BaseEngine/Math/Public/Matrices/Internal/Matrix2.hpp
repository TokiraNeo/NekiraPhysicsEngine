/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/SquareMatrix.hpp>

#include <Vectors/Vectors.hpp>


NAMESPACE_BEGIN(BE::Math)

/// 2x2 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
struct TMatrix2 : public TSquareMatrix<T, 2>
{
    // Constructor using TVector2
    constexpr TMatrix2(const TVector2<T>& row1, const TVector2<T>& row2);

    // Identity Matrix2
    constexpr static TMatrix2 Identity();
};



/* ====-------------------------------------------==== */
// Implementation of TMatrix2<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr TMatrix2<T>::TMatrix2(const TVector2<T>& row1, const TVector2<T>& row2)
{
    (*this)[0][0] = row1.X;
    (*this)[0][1] = row1.Y;

    (*this)[1][0] = row2.X;
    (*this)[1][1] = row2.Y;
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr TMatrix2<T> TMatrix2<T>::Identity()
{
    return TMatrix2<T>{TVector2<T>(1, 0), TVector2<T>(0, 1)};
}

NAMESPACE_END() // namespace BE::Math