/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <Utility/MathUtilities.hpp>

NAMESPACE_BEGIN(BE::Math)

/// TVector3<>
template <typename T>
struct TVector3 final
{
    T X;
    T Y;
    T Z;

    ~TVector3() = default;

    constexpr TVector3();
    explicit constexpr TVector3(T value);
    constexpr TVector3(T x, T y, T z);

    TVector3(const TVector3& other);
    TVector3(TVector3&& other) noexcept;

    TVector3& operator=(const TVector3& other);
    TVector3& operator=(TVector3&& other) noexcept;

    TVector3 operator+(const TVector3& other) const;
    TVector3 operator-(const TVector3& other) const;
    TVector3 operator*(const TVector3& other) const;
    TVector3 operator*(T scalar) const;

    TVector3& operator+=(const TVector3& other);
    TVector3& operator-=(const TVector3& other);
    TVector3& operator*=(const TVector3& other);
    TVector3& operator*=(T scalar);

    bool operator==(const TVector3& other) const;
    bool operator!=(const TVector3& other) const;

    // Dot product
    T operator|(const TVector3& other) const;
    // Cross product
    TVector3  operator^(const TVector3& other) const;
    TVector3& operator^=(const TVector3& other);

    T Magnitude() const;
    T SquareMagnitude() const;

    void Normalize();

    void Invert();
};



/// ====-------------------------------------====
/// Implementation of TVector3<>
/// ====-------------------------------------====

template <typename T>
constexpr TVector3<T>::TVector3() : X(0), Y(0), Z(0)
{}

template <typename T>
constexpr TVector3<T>::TVector3(T value) : X(value), Y(value), Z(value)
{}

template <typename T>
constexpr TVector3<T>::TVector3(T x, T y, T z) : X(x), Y(y), Z(z)
{}

template <typename T>
TVector3<T>::TVector3(const TVector3& other) : X(other.X), Y(other.Y), Z(other.Z)
{}

template <typename T>
TVector3<T>::TVector3(TVector3&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
}

template <typename T>
TVector3<T>& TVector3<T>::operator=(const TVector3& other)
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
    }
    return *this;
}

template <typename T>
TVector3<T>& TVector3<T>::operator=(TVector3&& other) noexcept
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        other.X = 0;
        other.Y = 0;
        other.Z = 0;
    }
    return *this;
}

template <typename T>
TVector3<T> TVector3<T>::operator+(const TVector3& other) const
{
    return TVector3<T>(X + other.X, Y + other.Y, Z + other.Z);
}

template <typename T>
TVector3<T> TVector3<T>::operator-(const TVector3& other) const
{
    return TVector3<T>(X - other.X, Y - other.Y, Z - other.Z);
}

template <typename T>
TVector3<T> TVector3<T>::operator*(const TVector3& other) const
{
    return TVector3<T>(X * other.X, Y * other.Y, Z * other.Z);
}

template <typename T>
TVector3<T> TVector3<T>::operator*(T scalar) const
{
    return TVector3<T>(X * scalar, Y * scalar, Z * scalar);
}

template <typename T>
TVector3<T>& TVector3<T>::operator+=(const TVector3& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    return *this;
}

template <typename T>
TVector3<T>& TVector3<T>::operator-=(const TVector3& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    return *this;
}

template <typename T>
TVector3<T>& TVector3<T>::operator*=(const TVector3& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    return *this;
}

template <typename T>
TVector3<T>& TVector3<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    return *this;
}

template <typename T>
bool TVector3<T>::operator==(const TVector3& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z);
}

template <typename T>
bool TVector3<T>::operator!=(const TVector3& other) const
{
    return !(*this == other);
}

template <typename T>
T TVector3<T>::operator|(const TVector3& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z);
}

template <typename T>
TVector3<T> TVector3<T>::operator^(const TVector3& other) const
{
    // | i   j   k  |
    // | X1  Y1  Z1 |
    // | X2  Y2  Z2 |
    // Cross product: i(Y1*Z2 - Z1*Y2) - j(X1*Z2 - Z1*X2) + k(X1*Y2 - Y1*X2)
    return TVector3<T>((Y * other.Z) - (Z * other.Y), (Z * other.X) - (X * other.Z), (X * other.Y) - (Y * other.X));
}

template <typename T>
TVector3<T>& TVector3<T>::operator^=(const TVector3& other)
{
    TVector3 cross = (*this) ^ other;
    *this = cross;
    return *this;
}

template <typename T>
T TVector3<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z));
}

template <typename T>
T TVector3<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z);
}

template <typename T>
void TVector3<T>::Normalize()
{
    T mag = Magnitude();
    if (mag > 0)
    {
        X *= (1.0F / mag);
        Y *= (1.0F / mag);
        Z *= (1.0F / mag);
    }
}

template <typename T>
void TVector3<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
}

NAMESPACE_END() // namespace BE::Math