/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/SquareMatrix.hpp>
#include <Vectors/Internal/Vector2.hpp>


NAMESPACE_BEGIN(BE::Math)

/// 2x2 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
struct TMatrix2 final : public TSquareMatrix<T, 2>
{
    // Constructor using TVector2
    constexpr TMatrix2(const TVector2<T>& row1, const TVector2<T>& row2);

    // Multiply a TVector2: Matrix2 * TVector2
    constexpr TVector2<T> operator*(const TVector2<T>& vec) const;

    // Identity Matrix2
    constexpr static TMatrix2 Identity();

    // Get Minor of element at (row, col)
    constexpr T Minor(char row, char col) const;

    // Minor Matrix2
    TMatrix2 MinorMatrix() const;

    // Get Cofactor of element at (row, col)
    constexpr T Cofactor(char row, char col) const;

    // Get Cofactor Matrix2
    TMatrix2 CofactorMatrix() const;

    // Get Adjugate Matrix2
    TMatrix2 Adjugate() const;

    // Get Derminant of the matrix
    constexpr T Determinant() const;

    // Get Inverse of the matrix
    TMatrix2 Inverse() const;
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
constexpr TVector2<T> TMatrix2<T>::operator*(const TVector2<T>& vec) const
{
    const TVector2<T> ROW1{(*this)[0][0], (*this)[0][1]};
    const TVector2<T> ROW2{(*this)[1][0], (*this)[1][1]};

    // Dot product of each row with the vector
    const T X = (vec | ROW1);
    const T Y = (vec | ROW2);

    return TVector2<T>{X, Y};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr TMatrix2<T> TMatrix2<T>::Identity()
{
    return TMatrix2<T>{TVector2<T>(1, 0), TVector2<T>(0, 1)};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr T TMatrix2<T>::Minor(char row, char col) const
{
    row = Clamp<char>(row, 0, 1);
    col = Clamp<char>(col, 0, 1);

    // For a 2x2 matrix, the minor is simply the other element
    return (*this)[1 - row][1 - col];
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
TMatrix2<T> TMatrix2<T>::MinorMatrix() const
{
    // For a 2x2 matrix:
    // | a b |
    // | c d |
    // Its Minor Matrix:
    // | d c |
    // | b a |
    return TMatrix2<T>{TVector2<T>((*this)[1][1], (*this)[1][0]), TVector2<T>((*this)[0][1], (*this)[0][0])};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr T TMatrix2<T>::Cofactor(char row, char col) const
{
    row = Clamp<char>(row, 0, 1);
    col = Clamp<char>(col, 0, 1);

    T sign = ((row + col) % 2 == 0) ? 1 : -1;
    return sign * Minor(row, col);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
TMatrix2<T> TMatrix2<T>::CofactorMatrix() const
{
    const TVector2<T> ROW1{Cofactor(0, 0), Cofactor(0, 1)};
    const TVector2<T> ROW2{Cofactor(1, 0), Cofactor(1, 1)};

    return TMatrix2<T>{ROW1, ROW2};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
TMatrix2<T> TMatrix2<T>::Adjugate() const
{
    return CofactorMatrix().Transpose();
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
constexpr T TMatrix2<T>::Determinant() const
{
    // For a 2x2 matrix:
    // | a b |
    // | c d |
    // Determinant = ad - bc
    return ((*this)[0][0] * (*this)[1][1]) - ((*this)[0][1] * (*this)[1][0]);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 2>
TMatrix2<T> TMatrix2<T>::Inverse() const
{
    auto det = Determinant();
    if (IsNearlyZero(det))
    {
        return TMatrix2<T>(0);
    }
    return (1.0 / det) * Adjugate();
}

NAMESPACE_END() // namespace BE::Math