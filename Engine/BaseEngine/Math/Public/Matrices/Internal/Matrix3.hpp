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

/// 3x3 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
struct TMatrix3 final : public TSquareMatrix<T, 3>
{
    // Constructor using TVector3
    constexpr TMatrix3(const TVector3<T>& row1, const TVector3<T>& row2, const TVector3<T>& row3);

    // Identity Matrix3
    constexpr static TMatrix3 Identity();
};



/* ====-------------------------------------------==== */
// Implementation of TMatrix3<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr TMatrix3<T>::TMatrix3(const TVector3<T>& row1, const TVector3<T>& row2, const TVector3<T>& row3)
{
    (*this)[0][0] = row1.X;
    (*this)[0][1] = row1.Y;
    (*this)[0][2] = row1.Z;

    (*this)[1][0] = row2.X;
    (*this)[1][1] = row2.Y;
    (*this)[1][2] = row2.Z;

    (*this)[2][0] = row3.X;
    (*this)[2][1] = row3.Y;
    (*this)[2][2] = row3.Z;
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr TMatrix3<T> TMatrix3<T>::Identity()
{
    return TMatrix3<T>{TVector3<T>(1, 0, 0), TVector3<T>(0, 1, 0), TVector3<T>(0, 0, 1)};
}

NAMESPACE_END() // namespace BE::Math