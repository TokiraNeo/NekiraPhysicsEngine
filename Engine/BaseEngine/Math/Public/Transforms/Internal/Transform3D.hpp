/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <MathUtility/MatrixUtilities.hpp>
#include <Transforms/Internal/TransformBase.hpp>
#include <Rotations/Internal/Rotator.hpp>
#include <Rotations/Internal/Quaternion.hpp>


NAMESPACE_BEGIN(BE::Math)

/**
 * @brief Transform3D for three-dimensional space
 * @details This class represents a 3D transformation including translation, rotation, and scaling.
 */
template <typename T = float>
    requires TTransformInternal::TTransformConcept<T>
struct TTransform3D final
{
private:
    TMatrix4<T> Matrix;

public:
    ~TTransform3D() = default;

    constexpr TTransform3D();

    // Construct with translation, rotation, and scale
    constexpr TTransform3D(const TVector3<T>& translation, const TRotator<T>& rotation = TRotator<T>(0.0),
                           const TVector3<T>& scale = TVector3<T>(1.0));

    // Construct with translation only
    explicit constexpr TTransform3D(const TVector3<T>& translation);

    // Construct with Transform Matrix4x4
    explicit constexpr TTransform3D(const TMatrix4<T>& transform);

    // Copy and move constructors/assignments
    TTransform3D(const TTransform3D& other);
    TTransform3D(TTransform3D&& other) noexcept;

    TTransform3D& operator=(const TTransform3D& other);
    TTransform3D& operator=(TTransform3D&& other) noexcept;

    // Combine two transforms
    TTransform3D  operator*(const TTransform3D& other) const;
    TTransform3D& operator*=(const TTransform3D& other);

    // Getters
    [[nodiscard]] constexpr TVector3<T> GetTranslation() const;
    [[nodiscard]] constexpr TRotator<T> GetRotation() const;
    [[nodiscard]] constexpr TVector3<T> GetScale() const;

    // Setters
    void SetTranslation(const TVector3<T>& translation);
    void SetRotation(const TVector3<T>& rotation);
    void SetScale(const TVector3<T>& scale);
};



/* ====-------------------------------------------==== */
// Implementation of TTransform3D<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform3D<T>::TTransform3D() : Matrix(TMatrix4<T>::Identity())
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform3D<T>::TTransform3D(const TVector3<T>& translation, const TRotator<T>& rotation,
                                        const TVector3<T>& scale)
    : Matrix(BE::Math::Transform4x4(scale, rotation.ToVector(), translation))
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform3D<T>::TTransform3D(const TVector3<T>& translation)
    : Matrix(BE::Math::Transform4x4(TVector3<T>(1.0), TVector3<T>(0.0), translation))
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform3D<T>::TTransform3D(const TMatrix4<T>& transform) : Matrix(transform)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T>::TTransform3D(const TTransform3D& other) : Matrix(other.Matrix)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T>::TTransform3D(TTransform3D&& other) noexcept : Matrix(other.Matrix)
{
    other.Matrix = TMatrix4<T>::Identity();
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T>& TTransform3D<T>::operator=(const TTransform3D& other)
{
    if (this != &other)
    {
        Matrix = other.Matrix;
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T>& TTransform3D<T>::operator=(TTransform3D&& other) noexcept
{
    if (this != &other)
    {
        Matrix = other.Matrix;

        other.Matrix = TMatrix4<T>::Identity();
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T> TTransform3D<T>::operator*(const TTransform3D& other) const
{
    // @TODO: Implement Combine logic for 3D transforms
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform3D<T>& TTransform3D<T>::operator*=(const TTransform3D& other)
{
    // @TODO: Implement Combine logic for 3D transforms
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector3<T> TTransform3D<T>::GetTranslation() const
{
    /**
     * @brief
     * 在矩阵的数学表现上，Translation矩阵通常是这样的：
     * | 1 0 0 Tx |
     * | 0 1 0 Ty |
     * | 0 0 1 Tz |
     * | 0 0 0 1  |
     *
     * 在Nekira Physics Engine中，我们使用`行主序(row-major)`存储矩阵数据，
     * 因此Translation矩阵在内存中的布局是这样的：
     * | 1 0 0 Tx |
     * | 0 1 0 Ty |
     * | 0 0 1 Tz |
     * | 0 0 0 1  |
     * 即与数学形式保持一致。
     * DirecX使用的是行主序，而OpenGL、Vulkan使用的是列主序。
     * Nekira Physics Engine选择行主序，保证直观上与数学表现一致。
     */

    return TVector3<T>(Matrix[0][3], Matrix[1][3], Matrix[2][3]);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TRotator<T> TTransform3D<T>::GetRotation() const
{
    // @TODO: Extract rotation from the transformation matrix
    return TRotator<T>();
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector3<T> TTransform3D<T>::GetScale() const
{
    /**
     * @brief
     * 由于我们使用行主序存储矩阵数据，缩放向量位于矩阵的对角线上，即[0][0]、[1][1]、[2][2]位置。
     * 缩放矩阵的定义为:
     * | Sx 0  0  0 |
     * | 0  Sy 0  0 |
     * | 0  0  Sz 0 |
     * | 0  0  0  1 |
     */
    return TVector3<T>(Matrix[0][0], Matrix[1][1], Matrix[2][2]);
}

NAMESPACE_END() // namespace BE::Math