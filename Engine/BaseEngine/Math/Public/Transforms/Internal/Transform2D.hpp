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



NAMESPACE_BEGIN(BE::Math)

/**
 * @brief Transform2D for two-dimensional space
 * @details This class represents a 2D transformation including translation, rotation, and scaling.
 */
template <typename T = float>
    requires TTransformInternal::TTransformConcept<T>
struct TTransform2D final
{
private:
    TMatrix3<T> Matrix; // 3x3 transformation matrix

public:
    ~TTransform2D() = default;

    constexpr TTransform2D();

    // Construct with translation only
    explicit constexpr TTransform2D(const TVector2<T>& translation);

    // Construct with translation, rotation(in degrees), and scale
    constexpr TTransform2D(const TVector2<T>& translation, T rotation = 0.0,
                           const TVector2<T>& scale = TVector2<T>(1.0));

    // Construct with Transform Matrix3x3
    explicit constexpr TTransform2D(const TMatrix3<T>& transform);

    // Copy and move constructors/assignments
    TTransform2D(const TTransform2D& other);
    TTransform2D(TTransform2D&& other) noexcept;

    TTransform2D& operator=(const TTransform2D& other);
    TTransform2D& operator=(TTransform2D&& other) noexcept;

    // Combine two transforms
    TTransform2D  operator*(const TTransform2D& other) const;
    TTransform2D& operator*=(const TTransform2D& other);

    // Getters
    [[nodiscard]] constexpr TVector2<T> GetTranslation() const;
    [[nodiscard]] constexpr TVector2<T> GetScale() const;
    [[nodiscard]] constexpr T           GetRotation() const;

    // Setters
    void SetTranslation(const TVector2<T>& translation);
    void SetRotation(T rotation);
    void SetScale(const TVector2<T>& scale);

    // Translate the transform
    void Translate(const TVector2<T>& translation);

    // Rotate the transform(in degrees)
    void Rotate(T angle);

    // Scale the transform
    void Scaled(const TVector2<T>& scale);

    // Get the Transform Matrix3x3
    [[nodiscard]] TMatrix3<T> ToMatrix() const;

    // Transform a point
    [[nodiscard]] TVector2<T> TransformPoint(const TVector2<T>& point) const;

    // Transform a vector2
    [[nodiscard]] TVector2<T> TransformVector(const TVector2<T>& vector) const;

    // Combine with another transform
    [[nodiscard]] TTransform2D<T> Combine(const TTransform2D<T>& other) const;

    // ------------------------------------------------------
    // Static Methods
    // ------------------------------------------------------

    // Identity transform
    constexpr static TTransform2D<T> Identity();

    // Translation transform
    constexpr static TTransform2D<T> Translation(const TVector2<T>& translation);

    // Rotation transform(in degrees)
    constexpr static TTransform2D<T> Rotation(T angle);

    // Scaling transform
    constexpr static TTransform2D<T> Scaling(const TVector2<T>& scale);
};



/* ====-------------------------------------------==== */
// Implementation of TTransform2D<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D() : Matrix(BE::Math::Transform2D3x3<T>(TVector2<T>(1.0), 0.0, TVector2<T>(0.0)))
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TVector2<T>& translation)
    : Matrix(BE::Math::Transform2D3x3<T>(TVector2<T>(1.0), 0.0, translation))
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TVector2<T>& translation, T rotation, const TVector2<T>& scale)
    : Matrix(BE::Math::Transform2D3x3<T>(scale, rotation, translation))
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TMatrix3<T>& transform) : Matrix(transform)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>::TTransform2D(const TTransform2D& other) : Matrix(other.Matrix)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>::TTransform2D(TTransform2D&& other) noexcept : Matrix(other.Matrix)
{
    other.Matrix = BE::Math::Transform2D3x3<T>(TVector2<T>(1.0), 0.0, TVector2<T>(0.0));
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator=(const TTransform2D& other)
{
    if (this != &other)
    {
        Matrix = other.Matrix;
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator=(TTransform2D&& other) noexcept
{
    if (this != &other)
    {
        Matrix = other.Matrix;

        other.Matrix = BE::Math::Transform2D3x3<T>(TVector2<T>(1.0), 0.0, TVector2<T>(0.0));
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T> TTransform2D<T>::operator*(const TTransform2D& other) const
{
    // Combine this transform with another transform
    auto combinedMatrix = Matrix * other.Matrix;

    return TTransform2D<T>(combinedMatrix);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator*=(const TTransform2D& other)
{
    // Combine this transform with another transform
    Matrix = Matrix * other.Matrix;

    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector2<T> TTransform2D<T>::GetTranslation() const
{
    return TVector2<T>(Matrix[0][2], Matrix[1][2]);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector2<T> TTransform2D<T>::GetScale() const
{
    /**
     * @brief
     * 对于一个二维的Transform矩阵：
     * | Sx*cosθ   -Sy*sinθ  Tx |
     * | Sx*sinθ    Sy*cosθ  Ty |
     * | 0          0        1  |
     */

    T scaleX = BE::Math::Sqrt((Matrix[0][0] * Matrix[0][0]) + (Matrix[1][0] * Matrix[1][0]));
    T scaleY = BE::Math::Sqrt((Matrix[0][1] * Matrix[0][1]) + (Matrix[1][1] * Matrix[1][1]));

    scaleX = (BE::Math::IsNearlyZero(scaleX)) ? 1.0 : scaleX;
    scaleY = (BE::Math::IsNearlyZero(scaleY)) ? 1.0 : scaleY;

    return TVector2<T>(scaleX, scaleY);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr T TTransform2D<T>::GetRotation() const
{
    /**
     * @brief
     * 对于一个二维的Transform矩阵：
     * | Sx*cosθ   -Sy*sinθ  Tx |
     * | Sx*sinθ    Sy*cosθ  Ty |
     * | 0          0        1  |
     */

    auto scale = GetScale();

    T radians = BE::Math::ATan2(Matrix[1][0] / scale.X, Matrix[0][0] / scale.X);

    return BE::Math::RadiansToDegrees(radians);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetTranslation(const TVector2<T>& translation)
{
    Matrix[0][2] = translation.X;
    Matrix[1][2] = translation.Y;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetRotation(T rotation)
{
    auto scale = GetScale();

    T radians = BE::Math::DegreesToRadians(rotation);

    Matrix[0][0] = scale.X * BE::Math::Cos(radians);
    Matrix[0][1] = -scale.Y * BE::Math::Sin(radians);

    Matrix[1][0] = scale.X * BE::Math::Sin(radians);
    Matrix[1][1] = scale.Y * BE::Math::Cos(radians);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetScale(const TVector2<T>& scale)
{
    // Make sure scale is not zero
    TVector2<T> newScale = scale;
    newScale.X = (BE::Math::IsNearlyZero(newScale.X)) ? 1.0 : newScale.X;
    newScale.Y = (BE::Math::IsNearlyZero(newScale.Y)) ? 1.0 : newScale.Y;

    T degrees = GetRotation();

    T radians = BE::Math::DegreesToRadians(degrees);

    Matrix[0][0] = newScale.X * BE::Math::Cos(radians);
    Matrix[0][1] = -newScale.Y * BE::Math::Sin(radians);

    Matrix[1][0] = newScale.X * BE::Math::Sin(radians);
    Matrix[1][1] = newScale.Y * BE::Math::Cos(radians);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Translate(const TVector2<T>& translation)
{
    auto newTranslation = GetTranslation() + translation;
    SetTranslation(newTranslation);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Rotate(T angle)
{
    T currentRotation = GetRotation();
    SetRotation(currentRotation + angle);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Scaled(const TVector2<T>& scale)
{
    auto newScale = GetScale() * scale;
    SetScale(newScale);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TMatrix3<T> TTransform2D<T>::ToMatrix() const
{
    return Matrix;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TVector2<T> TTransform2D<T>::TransformPoint(const TVector2<T>& point) const
{
    return BE::Math::TransformPoint2D(point, Matrix);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TVector2<T> TTransform2D<T>::TransformVector(const TVector2<T>& vector) const
{
    return BE::Math::TransformVector2D(vector, Matrix);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TTransform2D<T> TTransform2D<T>::Combine(const TTransform2D<T>& other) const
{
    auto combinedMatrix = Matrix * other.Matrix;

    return TTransform2D<T>(combinedMatrix);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T> TTransform2D<T>::Identity()
{
    return TTransform2D<T>();
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T> TTransform2D<T>::Translation(const TVector2<T>& translation)
{
    return TTransform2D<T>(translation);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T> TTransform2D<T>::Rotation(T angle)
{
    return TTransform2D<T>(TVector2<T>(0.0), angle, TVector2<T>(1.0));
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T> TTransform2D<T>::Scaling(const TVector2<T>& scale)
{
    return TTransform2D<T>(TVector2<T>(0.0), 0.0, scale);
}

NAMESPACE_END() // namespace BE::Math