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
struct TQuaternion;

/**
 * @brief Rotator for three-dimensional rotation.
 * @details Represents rotation using Euler angles (Roll, Pitch, Yaw) in degrees.
 *          Roll is rotation around X-axis, Pitch around Y-axis, Yaw around Z-axis.
 */
template <typename T = float>
    requires TRotationInternal::TRotationConcept<T>
struct TRotator final
{
private:
    TVector3<T> Rotation;

public:
    ~TRotator() = default;

    constexpr TRotator();

    // Construct with single angle(in degrees) for all axes.
    explicit constexpr TRotator(T degrees);

    // Construct with Roll(X), Pitch(Y), Yaw(Z) in degrees.
    constexpr TRotator(T roll, T pitch, T yaw);

    // Construct with TVector3(roll, pitch, yaw)
    constexpr TRotator(const TVector3<T>& rotation);

    // Copy and move constructors/assignments
    TRotator(const TRotator& other);
    TRotator(TRotator&& other) noexcept;

    TRotator& operator=(const TRotator& other);
    TRotator& operator=(TRotator&& other) noexcept;

    // Comparison operators
    bool operator==(const TRotator& other) const;
    bool operator!=(const TRotator& other) const;

    // Arithmetic operators
    TRotator operator+(const TRotator& other) const;
    TRotator operator-(const TRotator& other) const;
    TRotator operator*(T scalar) const;

    // Self-assignment operators
    TRotator& operator+=(const TRotator& other);
    TRotator& operator-=(const TRotator& other);
    TRotator& operator*=(T scalar);

    // Negate operator
    constexpr TRotator operator-() const;

    // Getters
    [[nodiscard]] constexpr T           Roll() const;
    [[nodiscard]] constexpr T           Pitch() const;
    [[nodiscard]] constexpr T           Yaw() const;
    [[nodiscard]] constexpr TVector3<T> ToVector() const;
    [[nodiscard]] constexpr TQuaternion<T> ToQuaternion() const;

    // Setters
    void SetRoll(T roll);
    void SetPitch(T pitch);
    void SetYaw(T yaw);
};



/* ====-------------------------------------------==== */
// Implementation of TRotator<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T>::TRotator() : Rotation(0.0)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T>::TRotator(T degrees) : Rotation(degrees)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T>::TRotator(T roll, T pitch, T yaw) : Rotation(roll, pitch, yaw)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T>::TRotator(const TVector3<T>& rotation) : Rotation(rotation)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>::TRotator(const TRotator& other) : Rotation(other.Rotation)
{}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>::TRotator(TRotator&& other) noexcept : Rotation(other.Rotation)
{
    other.Rotation = TVector3<T>(0.0);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>& TRotator<T>::operator=(const TRotator& other)
{
    if (this != &other)
    {
        Rotation = other.Rotation;
    }
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>& TRotator<T>::operator=(TRotator&& other) noexcept
{
    if (this != &other)
    {
        Rotation = other.Rotation;
        other.Rotation = TVector3<T>(0.0);
    }
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
bool TRotator<T>::operator==(const TRotator& other) const
{
    return Rotation == other.Rotation;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
bool TRotator<T>::operator!=(const TRotator& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T> TRotator<T>::operator+(const TRotator& other) const
{
    return TRotator(Rotation + other.Rotation);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T> TRotator<T>::operator-(const TRotator& other) const
{
    return TRotator(Rotation - other.Rotation);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T> TRotator<T>::operator*(T scalar) const
{
    return TRotator(Rotation * scalar);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>& TRotator<T>::operator+=(const TRotator& other)
{
    Rotation += other.Rotation;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>& TRotator<T>::operator-=(const TRotator& other)
{
    Rotation -= other.Rotation;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
TRotator<T>& TRotator<T>::operator*=(T scalar)
{
    Rotation *= scalar;
    return *this;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
constexpr TRotator<T> TRotator<T>::operator-() const
{
    return TRotator(-Rotation);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
[[nodiscard]] constexpr T TRotator<T>::Roll() const
{
    return Rotation.X;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
[[nodiscard]] constexpr T TRotator<T>::Pitch() const
{
    return Rotation.Y;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
[[nodiscard]] constexpr T TRotator<T>::Yaw() const
{
    return Rotation.Z;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
[[nodiscard]] constexpr TVector3<T> TRotator<T>::ToVector() const
{
    return Rotation;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
[[nodiscard]] constexpr TQuaternion<T> TRotator<T>::ToQuaternion() const
{
    return TQuaternion<T>(*this);
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
void TRotator<T>::SetRoll(T roll)
{
    Rotation.X = roll;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
void TRotator<T>::SetPitch(T pitch)
{
    Rotation.Y = pitch;
}

template <typename T>
    requires TRotationInternal::TRotationConcept<T>
void TRotator<T>::SetYaw(T yaw)
{
    Rotation.Z = yaw;
}


NAMESPACE_END() // namespace BE::Math