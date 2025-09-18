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

/// Vector2<>
template <typename T>
struct Vector2 final
{
    T X;
    T Y;

    ~Vector2() = default;

    Vector2();
    explicit Vector2(T value);
    Vector2(T x, T y);

    Vector2(const Vector2& other);
    Vector2(Vector2&& other) noexcept;

    Vector2& operator=(const Vector2& other);
    Vector2& operator=(Vector2&& other) noexcept;

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(const Vector2& other) const;
    Vector2 operator*(T scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(const Vector2& other);
    Vector2& operator*=(T scalar);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    // Dot product
    T operator|(const Vector2& other) const;
    // Cross product
    T        operator^(const Vector2& other) const;
    Vector2& operator^=(const Vector2& other);

    T Magnitude() const;
    T SquareMagnitude() const;

    void Normalize();

    void Invert();
};



/// ====-------------------------------------====
/// Implementation of Vector2<>
/// ====-------------------------------------====

template <typename T>
Vector2<T>::Vector2() : X(0), Y(0)
{}

template <typename T>
Vector2<T>::Vector2(T value) : X(value), Y(value)
{}

template <typename T>
Vector2<T>::Vector2(T x, T y) : X(x), Y(y)
{}

template <typename T>
Vector2<T>::Vector2(const Vector2& other) : X(other.X), Y(other.Y)
{}

template <typename T>
Vector2<T>::Vector2(Vector2&& other) noexcept : X(other.X), Y(other.Y)
{
    other.X = 0;
    other.Y = 0;
}

template <typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2& other)
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
    }
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator=(Vector2&& other) noexcept
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
        other.X = 0;
        other.Y = 0;
    }
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2& other) const
{
    return Vector2<T>(X + other.X, Y + other.Y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2& other) const
{
    return Vector2<T>(X - other.X, Y - other.Y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2& other) const
{
    return Vector2<T>(X * other.X, Y * other.Y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T scalar) const
{
    return Vector2<T>(X * scalar, Y * scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& other)
{
    X += other.X;
    Y += other.Y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2& other)
{
    X -= other.X;
    Y -= other.Y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2& other)
{
    X *= other.X;
    Y *= other.Y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    return *this;
}

template <typename T>
bool Vector2<T>::operator==(const Vector2& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y);
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2& other) const
{
    return !(*this == other);
}

template <typename T>
T Vector2<T>::operator|(const Vector2& other) const
{
    return (X * other.X) + (Y * other.Y);
}

template <typename T>
T Vector2<T>::operator^(const Vector2& other) const
{
    // |X1 Y1|
    // |X2 Y2|
    // Cross product: X1*Y2 - Y1*X2
    return (X * other.Y) - (Y * other.X);
}

template <typename T>
Vector2<T>& Vector2<T>::operator^=(const Vector2& other)
{
    Vector2 cross = (*this) ^ other;
    *this = cross;
    return *this;
}

template <typename T>
T Vector2<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y));
}

template <typename T>
T Vector2<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y);
}

template <typename T>
void Vector2<T>::Normalize()
{
    T mag = Magnitude();
    if (mag > 0)
    {
        X *= (1.0F / mag);
        Y *= (1.0F / mag);
    }
}

template <typename T>
void Vector2<T>::Invert()
{
    X = -X;
    Y = -Y;
}

NAMESPACE_END() // namespace Math