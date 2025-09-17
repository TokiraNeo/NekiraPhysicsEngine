/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Utilities.hpp>

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

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

};

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

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;
};

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

    bool operator==(const Vector4& other) const;
    bool operator!=(const Vector4& other) const;
};




/// ====-------------------------------------====
/// Implementation of Vector2<>
/// ====-------------------------------------====

template <typename T>
Vector2<T>::Vector2() : X(0), Y(0) {}

template <typename T>
Vector2<T>::Vector2(T value) : X(value), Y(value) {}

template <typename T>
Vector2<T>::Vector2(T x, T y) : X(x), Y(y) {}

template <typename T>
Vector2<T>::Vector2(const Vector2& other) : X(other.X), Y(other.Y) {}

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
bool Vector2<T>::operator==(const Vector2& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y);
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2& other) const
{
    return !(*this == other);
}




/// ====-------------------------------------====
/// Implementation of Vector3<>
/// ====-------------------------------------====

template <typename T>
Vector3<T>::Vector3() : X(0), Y(0), Z(0) {}

template <typename T>
Vector3<T>::Vector3(T value) : X(value), Y(value), Z(value) {}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : X(x), Y(y), Z(z) {}

template <typename T>
Vector3<T>::Vector3(const Vector3& other) : X(other.X), Y(other.Y), Z(other.Z) {}

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
bool Vector3<T>::operator==(const Vector3& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z);
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3& other) const
{
    return !(*this == other);
}



/// ====-------------------------------------====
/// Implementation of Vector4<>
/// ====-------------------------------------====

template <typename T>
Vector4<T>::Vector4() : X(0), Y(0), Z(0), W(0) {}

template <typename T>
Vector4<T>::Vector4(T value) : X(value), Y(value), Z(value), W(value) {}

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w) {}

template <typename T>
Vector4<T>::Vector4(const Vector4& other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W) {}

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
bool Vector4<T>::operator==(const Vector4& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y)
    && IsNearlyEqual(Z, other.Z) && IsNearlyEqual(W, other.W);
}

template <typename T>
bool Vector4<T>::operator!=(const Vector4& other) const
{
    return !(*this == other);
}

NAMESPACE_END() // namespace Math