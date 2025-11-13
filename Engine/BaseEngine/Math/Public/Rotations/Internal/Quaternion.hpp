/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Rotations/Internal/RotationBase.hpp>
#include <Vectors/Internal/Vector3.hpp>

NAMESPACE_BEGIN(BE::Math)

// Forward declaration
template <typename T>
    requires TRotationInternal::TRotationConcept<T>
struct TRotator;

/**
 * @brief Quaternion for three-dimentional rotation.
 * @details Provides a way to represent rotations without gimbal lock.
 *          Quaternions consist of a vector part (X, Y, Z) and a scalar part (W).
 */
template <typename T = float>
    requires TRotationInternal::TRotationConcept<T>
struct TQuaternion final
{
private:
    T           Scalar;
    TVector3<T> Vector;

public:
    ~TQuaternion() = default;

    constexpr TQuaternion();

    // Construct from axis-angle representation, angle in degrees
    constexpr TQuaternion(const TVector3<T>& axis, T degrees);

    // Construct a pure quaternion from vector
    constexpr explicit TQuaternion(const TVector3<T>& vector);

    // Construct from Rotator
    constexpr explicit TQuaternion(const TRotator<T>& rotator);

    // Copy and move constructors/assignments
    TQuaternion(const TQuaternion& other);
    TQuaternion(TQuaternion&& other) noexcept;

    TQuaternion& operator=(const TQuaternion& other);
    TQuaternion& operator=(TQuaternion&& other) noexcept;

    // Comparison operators
    bool operator==(const TQuaternion& other) const;
    bool operator!=(const TQuaternion& other) const;

    // Mathematical operators
    TQuaternion operator+(const TQuaternion& other) const;
    TQuaternion operator-(const TQuaternion& other) const;
    TQuaternion operator*(const TQuaternion& other) const;
    TQuaternion operator*(T scalar) const;

    // Self-assignment operators
    TQuaternion& operator+=(const TQuaternion& other);
    TQuaternion& operator-=(const TQuaternion& other);
    TQuaternion& operator*=(const TQuaternion& other);
    TQuaternion& operator*=(T scalar);

    // Negate operator
    constexpr TQuaternion operator-() const;

    // Getters
    [[nodiscard]] constexpr TRotator<T> ToRotator() const;


    // --------------------------------------------------
    // Static Methods
    // --------------------------------------------------

    /**
     * @brief Create quaternion from axis-angle representation
     * @param axis Axis of rotation
     * @param degrees Angle in degrees
     */
    static TQuaternion<T> FromAxisAngle(const TVector3<T>& axis, T degrees);
};



/* ====-------------------------------------------==== */
// Implementation of TQuaternion<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TQuaternion<T>::TQuaternion() : Scalar(0.0), Vector(TVector3<T>(0.0))
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TQuaternion<T>::TQuaternion(const TVector3<T>& axis, T degrees)
{
    auto normalizedAxis = axis.Normalized();
    T    halfRadians = BE::Math::DegreesToRadians(degrees) * 0.5;

    auto sinHalf = BE::Math::Sin(halfRadians);

    Scalar = BE::Math::Cos(halfRadians);
    Vector = normalizedAxis * sinHalf;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TQuaternion<T>::TQuaternion(const TVector3<T>& vector) : Scalar(0.0), Vector(vector)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TQuaternion<T>::TQuaternion(const TRotator<T>& rotator)
{
    auto rotation = rotator.ToVector();

    auto xQuaternion = TQuaternion<T>(TVector3<T>(1, 0, 0), rotation.X);
    auto yQuaternion = TQuaternion<T>(TVector3<T>(0, 1, 0), rotation.Y);
    auto zQuaternion = TQuaternion<T>(TVector3<T>(0, 0, 1), rotation.Z);

    auto combinedQuaternion = xQuaternion * yQuaternion * zQuaternion;

    Scalar = combinedQuaternion.Scalar;
    Vector = combinedQuaternion.Vector;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>::TQuaternion(const TQuaternion& other) : Scalar(other.Scalar), Vector(other.Vector)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>::TQuaternion(TQuaternion&& other) noexcept : Scalar(other.Scalar), Vector(other.Vector)
{
    other.Scalar = 0.0;
    other.Vector = TVector3<T>(0.0);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator=(const TQuaternion& other)
{
    if (this != &other)
    {
        Scalar = other.Scalar;
        Vector = other.Vector;
    }
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator=(TQuaternion&& other) noexcept
{
    if (this != &other)
    {
        Scalar = other.Scalar;
        Vector = other.Vector;

        other.Scalar = 0.0;
        other.Vector = TVector3<T>(0.0);
    }
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
bool TQuaternion<T>::operator==(const TQuaternion& other) const
{
    return BE::Math::IsNearlyEqual(Scalar, other.Scalar) && (Vector == other.Vector);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
bool TQuaternion<T>::operator!=(const TQuaternion& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T> TQuaternion<T>::operator+(const TQuaternion& other) const
{
    return TQuaternion(Scalar + other.Scalar, Vector + other.Vector);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T> TQuaternion<T>::operator-(const TQuaternion& other) const
{
    return TQuaternion(Scalar - other.Scalar, Vector - other.Vector);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T> TQuaternion<T>::operator*(const TQuaternion& other) const
{
    T           newScalar = (Scalar * other.Scalar) - (Vector | other.Vector);
    TVector3<T> newVector = (Vector * other.Scalar) + (other.Vector * Scalar) + (Vector ^ other.Vector);

    return TQuaternion(newScalar, newVector);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T> TQuaternion<T>::operator*(T scalar) const
{
    return TQuaternion(Scalar * scalar, Vector * scalar);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator+=(const TQuaternion& other)
{
    Scalar += other.Scalar;
    Vector += other.Vector;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator-=(const TQuaternion& other)
{
    Scalar -= other.Scalar;
    Vector -= other.Vector;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator*=(const TQuaternion& other)
{
    auto oldScalar = Scalar;
    auto oldVector = Vector;

    Scalar = (oldScalar * other.Scalar) - (oldVector | other.Vector);
    Vector = (oldVector * other.Scalar) + (other.Vector * oldScalar) + (oldVector ^ other.Vector);

    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T>& TQuaternion<T>::operator*=(T scalar)
{
    Scalar *= scalar;
    Vector *= scalar;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T> TQuaternion<T>::ToRotator() const
{
    // @TODO: Implement conversion from quaternion to rotator (Euler angles)

    return TRotator<T>();
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TQuaternion<T> TQuaternion<T>::FromAxisAngle(const TVector3<T>& axis, T degrees)
{
    return TQuaternion<T>(axis, degrees);
}

NAMESPACE_END() // namespace BE::Math
