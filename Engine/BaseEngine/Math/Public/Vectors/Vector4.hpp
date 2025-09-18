/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Utility/Utilities.hpp>

NAMESPACE_BEGIN(Math)

/// Vector4<>
template <typename T>
struct Vector4 final
{
    T X;
    T Y;
    T Z;
    T W;

    ~Vector4() = default;

    Vector4();
    explicit Vector4(T value);
    Vector4(T x, T y, T z, T w);

    Vector4(const Vector4& other);
    Vector4(Vector4&& other) noexcept;

    Vector4& operator=(const Vector4& other);
    Vector4& operator=(Vector4&& other) noexcept;

    Vector4 operator+(const Vector4& other) const;
    Vector4 operator-(const Vector4& other) const;
    Vector4 operator*(const Vector4& other) const;
    Vector4 operator*(T scalar) const;

    Vector4& operator+=(const Vector4& other);
    Vector4& operator-=(const Vector4& other);
    Vector4& operator*=(const Vector4& other);
    Vector4& operator*=(T scalar);

    bool operator==(const Vector4& other) const;
    bool operator!=(const Vector4& other) const;

    // Dot product
    T operator|(const Vector4& other) const;

    T Magnitude() const;
    T SquareMagnitude() const;

    void Normalize();

    void Invert();
};



/// ====-------------------------------------====
/// Implementation of Vector4<>
/// ====-------------------------------------====

template <typename T>
Vector4<T>::Vector4() : X(0), Y(0), Z(0), W(0)
{}

template <typename T>
Vector4<T>::Vector4(T value) : X(value), Y(value), Z(value), W(value)
{}

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
{}

template <typename T>
Vector4<T>::Vector4(const Vector4& other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{}

template <typename T>
Vector4<T>::Vector4(Vector4&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
    other.W = 0;
}

template <typename T>
Vector4<T>& Vector4<T>::operator=(const Vector4& other)
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
Vector4<T>& Vector4<T>::operator=(Vector4&& other) noexcept
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
Vector4<T> Vector4<T>::operator+(const Vector4& other) const
{
    return Vector4<T>(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
}

template <typename T>
Vector4<T> Vector4<T>::operator-(const Vector4& other) const
{
    return Vector4<T>(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(const Vector4& other) const
{
    return Vector4<T>(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(T scalar) const
{
    return Vector4<T>(X * scalar, Y * scalar, Z * scalar, W * scalar);
}

template <typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    W += other.W;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator-=(const Vector4& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    W -= other.W;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator*=(const Vector4& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    W *= other.W;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    W *= scalar;
    return *this;
}

template <typename T>
bool Vector4<T>::operator==(const Vector4& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z)
           && IsNearlyEqual(W, other.W);
}

template <typename T>
bool Vector4<T>::operator!=(const Vector4& other) const
{
    return !(*this == other);
}

template <typename T>
T Vector4<T>::operator|(const Vector4& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z) + (W * other.W);
}

template <typename T>
T Vector4<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z) + (W * W));
}

template <typename T>
T Vector4<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z) + (W * W);
}

template <typename T>
void Vector4<T>::Normalize()
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
void Vector4<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
    W = -W;
}

NAMESPACE_END() // namespace Math