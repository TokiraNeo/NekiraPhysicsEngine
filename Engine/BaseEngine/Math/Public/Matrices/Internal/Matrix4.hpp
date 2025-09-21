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
    // Constructor using 4x4 elements
    constexpr TMatrix4(T e11, T e12, T e13, T e14, T e21, T e22, T e23, T e24, T e31, T e32, T e33, T e34, T e41, T e42,
                       T e43, T e44);

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
constexpr TMatrix4<T>::TMatrix4(T e11, T e12, T e13, T e14, T e21, T e22, T e23, T e24, T e31, T e32, T e33, T e34,
                                T e41, T e42, T e43, T e44)
{
    (*this)[0][0] = e11;
    (*this)[0][1] = e12;
    (*this)[0][2] = e13;
    (*this)[0][3] = e14;

    (*this)[1][0] = e21;
    (*this)[1][1] = e22;
    (*this)[1][2] = e23;
    (*this)[1][3] = e24;

    (*this)[2][0] = e31;
    (*this)[2][1] = e32;
    (*this)[2][2] = e33;
    (*this)[2][3] = e34;

    (*this)[3][0] = e41;
    (*this)[3][1] = e42;
    (*this)[3][2] = e43;
    (*this)[3][3] = e44;
}

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