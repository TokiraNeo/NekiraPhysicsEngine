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

/// 4x4 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
struct TMatrix4 : public TSquareMatrix<T, 4>
{
    // Constructor using TVector4
    constexpr TMatrix4(const TVector4<T>& row1, const TVector4<T>& row2, const TVector4<T>& row3,
                       const TVector4<T>& row4);

    // Identity Matrix4
    constexpr static TMatrix4 Identity();
};



/* ====-------------------------------------------==== */
// Implementation of TMatrix4<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr TMatrix4<T>::TMatrix4(const TVector4<T>& row1, const TVector4<T>& row2, const TVector4<T>& row3,
                                const TVector4<T>& row4)
{
    (*this)[0][0] = row1.X;
    (*this)[0][1] = row1.Y;
    (*this)[0][2] = row1.Z;
    (*this)[0][3] = row1.W;

    (*this)[1][0] = row2.X;
    (*this)[1][1] = row2.Y;
    (*this)[1][2] = row2.Z;
    (*this)[1][3] = row2.W;

    (*this)[2][0] = row3.X;
    (*this)[2][1] = row3.Y;
    (*this)[2][2] = row3.Z;
    (*this)[2][3] = row3.W;

    (*this)[3][0] = row4.X;
    (*this)[3][1] = row4.Y;
    (*this)[3][2] = row4.Z;
    (*this)[3][3] = row4.W;
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr TMatrix4<T> TMatrix4<T>::Identity()
{
    return TMatrix4<T>{TVector4<T>(1, 0, 0, 0), TVector4<T>(0, 1, 0, 0), TVector4<T>(0, 0, 1, 0),
                       TVector4<T>(0, 0, 0, 1)};
}

NAMESPACE_END() // namespace BE::Math