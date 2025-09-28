/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/SquareMatrix.hpp>
#include <Vectors/Internal/Vector3.hpp>

NAMESPACE_BEGIN(BE::Math)

/// 3x3 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
struct TMatrix3 final : public TSquareMatrix<T, 3>
{
    // Constructor using TVector3
    constexpr TMatrix3(const TVector3<T>& row1, const TVector3<T>& row2, const TVector3<T>& row3);

    // Multiply a TVector3: Matrix3 * TVector3
    constexpr TVector3<T> operator*(const TVector3<T>& vec) const;

    // Identity Matrix3
    constexpr static TMatrix3 Identity();

    // Get Minor of element at (row, col)
    constexpr T Minor(char row, char col) const;

    // Minor Matrix3
    TMatrix3 MinorMatrix() const;

    // Get Cofactor of element at (row, col)
    constexpr T Cofactor(char row, char col) const;

    // Get Cofactor Matrix3
    TMatrix3 CofactorMatrix() const;

    // Get Adjugate Matrix3
    TMatrix3 Adjugate() const;

    // Get Derminant of the matrix
    constexpr T Determinant() const;

    // Get Inverse of the matrix
    TMatrix3 Inverse() const;
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
constexpr TVector3<T> TMatrix3<T>::operator*(const TVector3<T>& vec) const
{
    const TVector3<T> ROW1{(*this)[0][0], (*this)[0][1], (*this)[0][2]};
    const TVector3<T> ROW2{(*this)[1][0], (*this)[1][1], (*this)[1][2]};
    const TVector3<T> ROW3{(*this)[2][0], (*this)[2][1], (*this)[2][2]};

    // Dot product of each row with the vector
    const T X = (vec | ROW1);
    const T Y = (vec | ROW2);
    const T Z = (vec | ROW3);

    return TVector3<T>{X, Y, Z};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr TMatrix3<T> TMatrix3<T>::Identity()
{
    return TMatrix3<T>{TVector3<T>(1, 0, 0), TVector3<T>(0, 1, 0), TVector3<T>(0, 0, 1)};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr T TMatrix3<T>::Minor(char row, char col) const
{
    row = Clamp<char>(row, 0, 2);
    col = Clamp<char>(col, 0, 2);

    // For a 3x3 matrix, the minor is the determinant of the 2x2 submatrix
    // example:
    // | a b c |
    // | d e f |
    // | g h i |
    // Minor(0, 1):
    // | d f |
    // | g i |
    // Determinant = di - fg

    T a = (*this)[(row + 1) % 3][(col + 2) % 3];
    T b = (*this)[(row + 1) % 3][(col + 1) % 3];
    T c = (*this)[(row + 2) % 3][(col + 2) % 3];
    T d = (*this)[(row + 2) % 3][(col + 1) % 3];

    return (a * d) - (b * c);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
TMatrix3<T> TMatrix3<T>::MinorMatrix() const
{
    const TVector3<T> ROW1{Minor(0, 0), Minor(0, 1), Minor(0, 2)};
    const TVector3<T> ROW2{Minor(1, 0), Minor(1, 1), Minor(1, 2)};
    const TVector3<T> ROW3{Minor(2, 0), Minor(2, 1), Minor(2, 2)};

    return TMatrix3<T>{ROW1, ROW2, ROW3};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr T TMatrix3<T>::Cofactor(char row, char col) const
{
    row = Clamp<char>(row, 0, 2);
    col = Clamp<char>(col, 0, 2);

    T sign = ((row + col) % 2 == 0) ? 1 : -1;
    return sign * Minor(row, col);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
TMatrix3<T> TMatrix3<T>::CofactorMatrix() const
{
    const TVector3<T> ROW1{Cofactor(0, 0), Cofactor(0, 1), Cofactor(0, 2)};
    const TVector3<T> ROW2{Cofactor(1, 0), Cofactor(1, 1), Cofactor(1, 2)};
    const TVector3<T> ROW3{Cofactor(2, 0), Cofactor(2, 1), Cofactor(2, 2)};

    return TMatrix3<T>{ROW1, ROW2, ROW3};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
TMatrix3<T> TMatrix3<T>::Adjugate() const
{
    return CofactorMatrix().Transpose();
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
constexpr T TMatrix3<T>::Determinant() const
{
    // For a 3x3 matrix:
    // | a b c |
    // | d e f |
    // | g h i |
    // Determinant = a*Cofactor(a) + b*Cofactor(b) + c*Cofactor(c)

    const T RESULT1 = (*this)[0][0] * Cofactor(0, 0);
    const T RESULT2 = (*this)[0][1] * Cofactor(0, 1);
    const T RESULT3 = (*this)[0][2] * Cofactor(0, 2);

    return RESULT1 + RESULT2 + RESULT3;
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 3>
TMatrix3<T> TMatrix3<T>::Inverse() const
{
    auto det = Determinant();
    if (IsNearlyZero(det))
    {
        return TMatrix3<T>(0);
    }
    return (1.0 / det) * Adjugate();
}

NAMESPACE_END() // namespace BE::Math