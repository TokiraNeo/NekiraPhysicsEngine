/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/Matrix3.hpp>
#include <Vectors/Internal/Vector4.hpp>



NAMESPACE_BEGIN(BE::Math)

/// 4x4 Matrix
template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
struct TMatrix4 final : public TSquareMatrix<T, 4>
{
    // Constructor using TVector4
    constexpr TMatrix4(const TVector4<T>& row1, const TVector4<T>& row2, const TVector4<T>& row3,
                       const TVector4<T>& row4);

    // Identity Matrix4
    constexpr static TMatrix4 Identity();

    // Get Minor of element at (row, col)
    constexpr T Minor(char row, char col) const;

    // Minor Matrix4
    TMatrix4 MinorMatrix() const;

    // Get Cofactor of element at (row, col)
    constexpr T Cofactor(char row, char col) const;

    // Get Cofactor Matrix4
    TMatrix4 CofactorMatrix() const;

    // Get Adjugate Matrix4
    TMatrix4 Adjugate() const;

    // Get Derminant of the matrix
    constexpr T Determinant() const;

    // Get Inverse of the matrix
    TMatrix4 Inverse() const;

    // Get Translation vector from the matrix
    constexpr TVector3<T> GetTranslation() const;

    // Get Scale vector from the matrix
    constexpr TVector3<T> GetScale() const;

private:
    // Get 3x3 SubMatrix excluding specified row and column
    constexpr TMatrix3<T> GetSubMatrix(char excludedRow, char excludedCol) const;
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

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr T TMatrix4<T>::Minor(char row, char col) const
{
    row = Clamp<char>(row, 0, 3);
    col = Clamp<char>(col, 0, 3);

    // For a 4x4 matrix, the minor is the determinant of the 3x3 matrix
    // example:
    // | a b c d |
    // | e f g h |
    // | i j k l |
    // | m n o p |
    // Minor(0, 1):
    // | e g h |
    // | i k l |
    // | m o p |
    // Determinant = e|k p| - g|i p| + h|i o|

    return GetSubMatrix(row, col).Determinant();
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
TMatrix4<T> TMatrix4<T>::MinorMatrix() const
{
    const TVector4<T> ROW1{Minor(0, 0), Minor(0, 1), Minor(0, 2), Minor(0, 3)};
    const TVector4<T> ROW2{Minor(1, 0), Minor(1, 1), Minor(1, 2), Minor(1, 3)};
    const TVector4<T> ROW3{Minor(2, 0), Minor(2, 1), Minor(2, 2), Minor(2, 3)};
    const TVector4<T> ROW4{Minor(3, 0), Minor(3, 1), Minor(3, 2), Minor(3, 3)};

    return TMatrix4<T>{ROW1, ROW2, ROW3, ROW4};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr T TMatrix4<T>::Cofactor(char row, char col) const
{
    row = Clamp<char>(row, 0, 3);
    col = Clamp<char>(col, 0, 3);

    T sign = ((row + col) % 2 == 0) ? 1 : -1;
    return sign * Minor(row, col);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
TMatrix4<T> TMatrix4<T>::CofactorMatrix() const
{
    const TVector4<T> ROW1{Cofactor(0, 0), Cofactor(0, 1), Cofactor(0, 2), Cofactor(0, 3)};
    const TVector4<T> ROW2{Cofactor(1, 0), Cofactor(1, 1), Cofactor(1, 2), Cofactor(1, 3)};
    const TVector4<T> ROW3{Cofactor(2, 0), Cofactor(2, 1), Cofactor(2, 2), Cofactor(2, 3)};
    const TVector4<T> ROW4{Cofactor(3, 0), Cofactor(3, 1), Cofactor(3, 2), Cofactor(3, 3)};

    return TMatrix4<T>{ROW1, ROW2, ROW3, ROW4};
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
TMatrix4<T> TMatrix4<T>::Adjugate() const
{
    return CofactorMatrix().Transpose();
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr T TMatrix4<T>::Determinant() const
{
    // For a 4x4 matrix:
    // | a b c d |
    // | e f g h |
    // | i j k l |
    // | m n o p |
    // Determinant = a*Cofactor(a) + b*Cofactor(b) + c*Cofactor(c) + d*Cofactor(d)

    const T RESULT1 = (*this)[0][0] * Cofactor(0, 0);
    const T RESULT2 = (*this)[0][1] * Cofactor(0, 1);
    const T RESULT3 = (*this)[0][2] * Cofactor(0, 2);
    const T RESULT4 = (*this)[0][3] * Cofactor(0, 3);

    return RESULT1 + RESULT2 + RESULT3 + RESULT4;
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
TMatrix4<T> TMatrix4<T>::Inverse() const
{
    auto det = Determinant();
    if (IsNearlyZero(det))
    {
        return TMatrix4<T>(0);
    }
    return (1.0 / det) * Adjugate();
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr TVector3<T> TMatrix4<T>::GetTranslation() const
{
    /**
     * @brief
     * 在矩阵的数学表现上，Translation矩阵通常是这样的：
     * | 1 0 0 Tx |
     * | 0 1 0 Ty |
     * | 0 0 1 Tz |
     * | 0 0 0 1  |
     *
     * 但是在Nekira Physics Engine中，我们使用`行主序(row-major)`存储矩阵数据，
     * 因此Translation矩阵在内存中的布局是这样的：
     * | 1  0  0  0 |
     * | 0  1  0  0 |
     * | 0  0  1  0 |
     * | Tx Ty Tz 1 |
     * 即相当于我们把数学形式的Translation矩阵进行了转置。
     * OpenGL和Vulkan是`列主序(column-major)`，DirectX是`行主序(row-major)`，
     * Nekira Physics Engine选择了后者以保持一致性。
     */
    return TVector3<T>((*this)[3][0], (*this)[3][1], (*this)[3][2]);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr TVector3<T> TMatrix4<T>::GetScale() const
{
    /**
     * @brief As we use row-major order, the scale vector is ([0][0], [1][1], [2][2])
     */
    return TVector3<T>((*this)[0][0], (*this)[1][1], (*this)[2][2]);
}

template <typename T>
    requires TMatrixInternal::TMatrixConcept<T, 4>
constexpr TMatrix3<T> TMatrix4<T>::GetSubMatrix(char excludedRow, char excludedCol) const
{
    excludedRow = Clamp<char>(excludedRow, 0, 3);
    excludedCol = Clamp<char>(excludedCol, 0, 3);

    TMatrix3<T> subMatrix;

    for (char i = 0; i < 4; ++i)
    {
        if (i == excludedRow)
        {
            continue;
        }

        for (char j = 0; j < 4; ++j)
        {
            if (j == excludedCol)
            {
                continue;
            }

            auto subI = (i < excludedRow) ? i : i - 1;
            auto subJ = (j < excludedCol) ? j : j - 1;

            subMatrix[subI][subJ] = (*this)[i][j];
        }
    }

    return subMatrix;
}

NAMESPACE_END() // namespace BE::Math