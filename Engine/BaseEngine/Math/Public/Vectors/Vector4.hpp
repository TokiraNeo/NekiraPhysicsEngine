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

/// TVector4<>
template <typename T>
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

    void Normalize();

    void Invert();
};



/// ====-------------------------------------====
/// Implementation of TVector4<>
/// ====-------------------------------------====

template <typename T>
constexpr TVector4<T>::TVector4() : X(0), Y(0), Z(0), W(0)
{}

template <typename T>
constexpr TVector4<T>::TVector4(T value) : X(value), Y(value), Z(value), W(value)
{}

template <typename T>
constexpr TVector4<T>::TVector4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
{}

template <typename T>
TVector4<T>::TVector4(const TVector4& other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{}

template <typename T>
TVector4<T>::TVector4(TVector4&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
    other.W = 0;
}

template <typename T>
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
TVector4<T> TVector4<T>::operator+(const TVector4& other) const
{
    return TVector4<T>(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
}

template <typename T>
TVector4<T> TVector4<T>::operator-(const TVector4& other) const
{
    return TVector4<T>(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
}

template <typename T>
TVector4<T> TVector4<T>::operator*(const TVector4& other) const
{
    return TVector4<T>(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
}

template <typename T>
TVector4<T> TVector4<T>::operator*(T scalar) const
{
    return TVector4<T>(X * scalar, Y * scalar, Z * scalar, W * scalar);
}

template <typename T>
TVector4<T>& TVector4<T>::operator+=(const TVector4& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    W += other.W;
    return *this;
}

template <typename T>
TVector4<T>& TVector4<T>::operator-=(const TVector4& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    W -= other.W;
    return *this;
}

template <typename T>
TVector4<T>& TVector4<T>::operator*=(const TVector4& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    W *= other.W;
    return *this;
}

template <typename T>
TVector4<T>& TVector4<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    W *= scalar;
    return *this;
}

template <typename T>
bool TVector4<T>::operator==(const TVector4& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z)
           && IsNearlyEqual(W, other.W);
}

template <typename T>
bool TVector4<T>::operator!=(const TVector4& other) const
{
    return !(*this == other);
}

template <typename T>
T TVector4<T>::operator|(const TVector4& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z) + (W * other.W);
}

template <typename T>
T TVector4<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z) + (W * W));
}

template <typename T>
T TVector4<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z) + (W * W);
}

template <typename T>
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
void TVector4<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
    W = -W;
}

NAMESPACE_END() // namespace BE::Math