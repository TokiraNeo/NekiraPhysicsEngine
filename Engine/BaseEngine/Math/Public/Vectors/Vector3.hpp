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

/// Vector3<>
template <typename T>
struct Vector3 final
{
    T X;
    T Y;
    T Z;

    ~Vector3() = default;

    Vector3();
    explicit Vector3(T value);
    Vector3(T x, T y, T z);

    Vector3(const Vector3& other);
    Vector3(Vector3&& other) noexcept;

    Vector3& operator=(const Vector3& other);
    Vector3& operator=(Vector3&& other) noexcept;

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(const Vector3& other) const;
    Vector3 operator*(T scalar) const;

    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(const Vector3& other);
    Vector3& operator*=(T scalar);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    // Dot product
    T operator|(const Vector3& other) const;
    // Cross product
    Vector3  operator^(const Vector3& other) const;
    Vector3& operator^=(const Vector3& other);

    T Magnitude() const;
    T SquareMagnitude() const;

    void Normalize();

    void Invert();
};



/// ====-------------------------------------====
/// Implementation of Vector3<>
/// ====-------------------------------------====

template <typename T>
Vector3<T>::Vector3() : X(0), Y(0), Z(0)
{}

template <typename T>
Vector3<T>::Vector3(T value) : X(value), Y(value), Z(value)
{}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : X(x), Y(y), Z(z)
{}

template <typename T>
Vector3<T>::Vector3(const Vector3& other) : X(other.X), Y(other.Y), Z(other.Z)
{}

template <typename T>
Vector3<T>::Vector3(Vector3&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
}

template <typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3& other)
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
Vector3<T>& Vector3<T>::operator=(Vector3&& other) noexcept
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
Vector3<T> Vector3<T>::operator+(const Vector3& other) const
{
    return Vector3<T>(X + other.X, Y + other.Y, Z + other.Z);
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& other) const
{
    return Vector3<T>(X - other.X, Y - other.Y, Z - other.Z);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const Vector3& other) const
{
    return Vector3<T>(X * other.X, Y * other.Y, Z * other.Z);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(T scalar) const
{
    return Vector3<T>(X * scalar, Y * scalar, Z * scalar);
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(const Vector3& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    return *this;
}

template <typename T>
bool Vector3<T>::operator==(const Vector3& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z);
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

template <typename T>
T Vector3<T>::operator|(const Vector3& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z);
}

template <typename T>
Vector3<T> Vector3<T>::operator^(const Vector3& other) const
{
    // | i   j   k  |
    // | X1  Y1  Z1 |
    // | X2  Y2  Z2 |
    // Cross product: i(Y1*Z2 - Z1*Y2) - j(X1*Z2 - Z1*X2) + k(X1*Y2 - Y1*X2)
    return Vector3<T>((Y * other.Z) - (Z * other.Y), (Z * other.X) - (X * other.Z), (X * other.Y) - (Y * other.X));
}

template <typename T>
Vector3<T>& Vector3<T>::operator^=(const Vector3& other)
{
    Vector3 cross = (*this) ^ other;
    *this = cross;
    return *this;
}

template <typename T>
T Vector3<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z));
}

template <typename T>
T Vector3<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z);
}

template <typename T>
void Vector3<T>::Normalize()
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
void Vector3<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
}

NAMESPACE_END() // namespace Math