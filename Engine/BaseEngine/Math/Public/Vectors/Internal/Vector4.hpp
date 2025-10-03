/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Utility/MathUtilities.hpp>
#include <Vectors/Internal/VectorBase.hpp>



NAMESPACE_BEGIN(BE::Math)

/// TVector4<>
template <typename T>
    requires TVectorInternal::TVectorConcept<T>
struct TVector4 final
{
    T X;
    T Y;
    T Z;
    T W;

    ~TVector4() = default;

    constexpr TVector4();
    explicit constexpr TVector4(T value);
    constexpr TVector4(T x, T y, T z, T w);

    TVector4(const TVector4& other);
    TVector4(TVector4&& other) noexcept;

    TVector4& operator=(const TVector4& other);
    TVector4& operator=(TVector4&& other) noexcept;

    TVector4 operator+(const TVector4& other) const;
    TVector4 operator-(const TVector4& other) const;
    TVector4 operator*(const TVector4& other) const;
    TVector4 operator*(T scalar) const;

    TVector4& operator+=(const TVector4& other);
    TVector4& operator-=(const TVector4& other);
    TVector4& operator*=(const TVector4& other);
    TVector4& operator*=(T scalar);

    bool operator==(const TVector4& other) const;
    bool operator!=(const TVector4& other) const;

    // Dot product
    T operator|(const TVector4& other) const;

    T Magnitude() const;
    T SquareMagnitude() const;

    // Normalize the vector to have a magnitude of 1
    void Normalize();
    // Get a new normalized vector based on this vector, without modifying this vector
    TVector4 Normalized() const;

    void Invert();

    bool Equal(const TVector4& other,
               T               epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;

    bool IsZero(T epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;
};



/* ====-------------------------------------------==== */
// Implementation of TVector4<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector4<T>::TVector4() : X(0), Y(0), Z(0), W(0)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector4<T>::TVector4(T value) : X(value), Y(value), Z(value), W(value)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector4<T>::TVector4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>::TVector4(const TVector4& other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>::TVector4(TVector4&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
    other.W = 0;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator=(const TVector4& other)
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        W = other.W;
    }
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator=(TVector4&& other) noexcept
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        W = other.W;
        other.X = 0;
        other.Y = 0;
        other.Z = 0;
        other.W = 0;
    }
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T> TVector4<T>::operator+(const TVector4& other) const
{
    return TVector4<T>(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T> TVector4<T>::operator-(const TVector4& other) const
{
    return TVector4<T>(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T> TVector4<T>::operator*(const TVector4& other) const
{
    return TVector4<T>(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T> TVector4<T>::operator*(T scalar) const
{
    return TVector4<T>(X * scalar, Y * scalar, Z * scalar, W * scalar);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator+=(const TVector4& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    W += other.W;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator-=(const TVector4& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    W -= other.W;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator*=(const TVector4& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    W *= other.W;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T>& TVector4<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    W *= scalar;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector4<T>::operator==(const TVector4& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z)
           && IsNearlyEqual(W, other.W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector4<T>::operator!=(const TVector4& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector4<T>::operator|(const TVector4& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z) + (W * other.W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector4<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z) + (W * W));
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector4<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z) + (W * W);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
void TVector4<T>::Normalize()
{
    T mag = Magnitude();
    if (mag > 0)
    {
        X *= (1.0F / mag);
        Y *= (1.0F / mag);
        Z *= (1.0F / mag);
        W *= (1.0F / mag);
    }
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector4<T> TVector4<T>::Normalized() const
{
    T mag = Magnitude();
    if (mag > 0)
    {
        return TVector4<T>(X * (1.0F / mag), Y * (1.0F / mag), Z * (1.0F / mag), W * (1.0F / mag));
    }
    // If the magnitude is zero, return a default unit vector (1.0, 1.0, 1.0, 1.0)
    return TVector4<T>(1.0F);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
void TVector4<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
    W = -W;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector4<T>::Equal(const TVector4& other, T epsilon) const
{
    return IsNearlyEqual(X, other.X, epsilon) && IsNearlyEqual(Y, other.Y, epsilon)
           && IsNearlyEqual(Z, other.Z, epsilon) && IsNearlyEqual(W, other.W, epsilon);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector4<T>::IsZero(T epsilon) const
{
    return IsNearlyZero(X, epsilon) && IsNearlyZero(Y, epsilon) && IsNearlyZero(Z, epsilon) && IsNearlyZero(W, epsilon);
}

NAMESPACE_END() // namespace BE::Math