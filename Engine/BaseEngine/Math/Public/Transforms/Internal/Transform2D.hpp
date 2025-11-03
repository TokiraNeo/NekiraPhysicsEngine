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
    TVector2<T> Translation;
    T           Rotation; // in degrees
    TVector2<T> Scale;

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
    [[nodiscard]] constexpr T           GetRotation() const;
    [[nodiscard]] constexpr TVector2<T> GetScale() const;

    // Setters
    void SetTranslation(const TVector2<T>& translation);
    void SetRotation(T rotation);
    void SetScale(const TVector2<T>& scale);

    // Translate the transform
    void Translate(const TVector2<T>& translation);

    // Rotate the transform(in degrees)
    void Rotate(T angle);

    // Scale the transform
    void Scaling(const TVector2<T>& scale);

    // Get the Transform Matrix3x3
    [[nodiscard]] TMatrix3<T> GetMatrix() const;

    // Transform a point
    [[nodiscard]] TVector2<T> TransformPoint(const TVector2<T>& point) const;

    // Transform a vector2
    [[nodiscard]] TVector2<T> TransformVector(const TVector2<T>& vector) const;

    // Combine with another transform
    [[nodiscard]] TTransform2D<T> Combine(const TTransform2D<T>& other) const;

    // Identity transform
    constexpr static TTransform2D<T> Identity();
};



/* ====-------------------------------------------==== */
// Implementation of TTransform2D<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D() : Translation(0.0), Rotation(0.0), Scale(1.0)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TVector2<T>& translation)
    : Translation(translation), Rotation(0.0), Scale(1.0)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TVector2<T>& translation, T rotation, const TVector2<T>& scale)
    : Translation(translation), Rotation(rotation), Scale(scale)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T>::TTransform2D(const TMatrix3<T>& transform)
{
    // Decompose the matrix into translation, rotation, and scale
    // Assuming the matrix is in the form: Scale * Rotation * Translation

    // Extract translation
    Translation.X = transform[0][2];
    Translation.Y = transform[1][2];

    // Extract scale
    T scaleX = BE::Math::Sqrt((transform[0][0] * transform[0][0]) + (transform[0][1] * transform[0][1]));
    T scaleY = BE::Math::Sqrt((transform[1][0] * transform[1][0]) + (transform[1][1] * transform[1][1]));
    Scale = TVector2<T>(scaleX, scaleY);

    // Extract rotation (in degrees)
    T radians = BE::Math::ATan2(transform[1][0] / scaleY, transform[0][0] / scaleX);
    Rotation = RadiansToDegrees(radians);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>::TTransform2D(const TTransform2D& other)
    : Translation(other.Translation), Rotation(other.Rotation), Scale(other.Scale)
{}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>::TTransform2D(TTransform2D&& other) noexcept
    : Translation(other.Translation), Rotation(other.Rotation), Scale(other.Scale)
{
    other.Translation = TVector2<T>(0.0);
    other.Rotation = 0.0;
    other.Scale = TVector2<T>(1.0);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator=(const TTransform2D& other)
{
    if (this != &other)
    {
        Translation = other.Translation;
        Rotation = other.Rotation;
        Scale = other.Scale;
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator=(TTransform2D&& other) noexcept
{
    if (this != &other)
    {
        Translation = other.Translation;
        Rotation = other.Rotation;
        Scale = other.Scale;

        other.Translation = TVector2<T>(0.0);
        other.Rotation = 0.0;
        other.Scale = TVector2<T>(1.0);
    }
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T> TTransform2D<T>::operator*(const TTransform2D& other) const
{
    // Combine this transform with another transform
    return Combine(other);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
TTransform2D<T>& TTransform2D<T>::operator*=(const TTransform2D& other)
{
    *this = Combine(other);
    return *this;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector2<T> TTransform2D<T>::GetTranslation() const
{
    return Translation;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr T TTransform2D<T>::GetRotation() const
{
    return Rotation;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] constexpr TVector2<T> TTransform2D<T>::GetScale() const
{
    return Scale;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetTranslation(const TVector2<T>& translation)
{
    Translation = translation;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetRotation(T rotation)
{
    Rotation = rotation;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::SetScale(const TVector2<T>& scale)
{
    Scale = scale;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Translate(const TVector2<T>& translation)
{
    Translation += translation;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Rotate(T angle)
{
    Rotation += angle;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
void TTransform2D<T>::Scaling(const TVector2<T>& scale)
{
    Scale *= scale;
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TMatrix3<T> TTransform2D<T>::GetMatrix() const
{
    return BE::Math::Transform2D3x3(Scale, Rotation, Translation);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TVector2<T> TTransform2D<T>::TransformPoint(const TVector2<T>& point) const
{
    return BE::Math::TransformPoint2D(point, GetMatrix());
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TVector2<T> TTransform2D<T>::TransformVector(const TVector2<T>& vector) const
{
    return BE::Math::TransformVector2D(vector, GetMatrix());
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
[[nodiscard]] TTransform2D<T> TTransform2D<T>::Combine(const TTransform2D<T>& other) const
{
    /**
     * @brief Combine this transform with another transform
     * @details
     * - 1. Scale: multiply scales
     * - 2. Rotation: add rotations
     * - 3. Translation: transform other's position by this transform, using TransformPoint to apply scale, rotation,
     * and translation
     */

    TVector2<T> combinedScale = Scale * other.Scale;

    T combinedRotation = Rotation + other.Rotation;

    TVector2<T> combinedTranslation = TransformPoint(other.Translation);

    return TTransform2D<T>(combinedTranslation, combinedRotation, combinedScale);
}

template <typename T>
    requires TTransformInternal::TTransformConcept<T>
constexpr TTransform2D<T> TTransform2D<T>::Identity()
{
    return TTransform2D<T>();
}

NAMESPACE_END() // namespace BE::Math