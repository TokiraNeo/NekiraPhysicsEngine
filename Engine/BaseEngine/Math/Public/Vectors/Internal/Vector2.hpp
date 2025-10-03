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

/// TVector2<>
template <typename T>
    requires TVectorInternal::TVectorConcept<T>
struct TVector2 final
{
    T X;
    T Y;

    ~TVector2() = default;

    constexpr TVector2();
    explicit constexpr TVector2(T value);
    constexpr TVector2(T x, T y);

    TVector2(const TVector2& other);
    TVector2(TVector2&& other) noexcept;

    TVector2& operator=(const TVector2& other);
    TVector2& operator=(TVector2&& other) noexcept;

    TVector2 operator+(const TVector2& other) const;
    TVector2 operator-(const TVector2& other) const;
    TVector2 operator*(const TVector2& other) const;
    TVector2 operator*(T scalar) const;

    TVector2& operator+=(const TVector2& other);
    TVector2& operator-=(const TVector2& other);
    TVector2& operator*=(const TVector2& other);
    TVector2& operator*=(T scalar);

    bool operator==(const TVector2& other) const;
    bool operator!=(const TVector2& other) const;

    // Dot product
    T operator|(const TVector2& other) const;
    // Cross product
    T         operator^(const TVector2& other) const;
    TVector2& operator^=(const TVector2& other);

    T Magnitude() const;
    T SquareMagnitude() const;

    // Normalize the vector to have a magnitude of 1
    void Normalize();
    // Get a new normalized vector based on this vector, without modifying this vector
    TVector2 Normalized() const;

    void Invert();

    bool Equal(const TVector2& other,
               T               epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;

    bool IsZero(T epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;
};



/* ====-------------------------------------------==== */
// Implementation of TVector2<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector2<T>::TVector2() : X(0), Y(0)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector2<T>::TVector2(T value) : X(value), Y(value)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector2<T>::TVector2(T x, T y) : X(x), Y(y)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>::TVector2(const TVector2& other) : X(other.X), Y(other.Y)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>::TVector2(TVector2&& other) noexcept : X(other.X), Y(other.Y)
{
    other.X = 0;
    other.Y = 0;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator=(const TVector2& other)
{
    if (this != &other)
    {
        X = other.X;
        Y = other.Y;
    }
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator=(TVector2&& other) noexcept
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
    requires TVectorInternal::TVectorConcept<T>
TVector2<T> TVector2<T>::operator+(const TVector2& other) const
{
    return TVector2<T>(X + other.X, Y + other.Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T> TVector2<T>::operator-(const TVector2& other) const
{
    return TVector2<T>(X - other.X, Y - other.Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T> TVector2<T>::operator*(const TVector2& other) const
{
    return TVector2<T>(X * other.X, Y * other.Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T> TVector2<T>::operator*(T scalar) const
{
    return TVector2<T>(X * scalar, Y * scalar);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator+=(const TVector2& other)
{
    X += other.X;
    Y += other.Y;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator-=(const TVector2& other)
{
    X -= other.X;
    Y -= other.Y;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator*=(const TVector2& other)
{
    X *= other.X;
    Y *= other.Y;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector2<T>::operator==(const TVector2& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector2<T>::operator!=(const TVector2& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector2<T>::operator|(const TVector2& other) const
{
    return (X * other.X) + (Y * other.Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector2<T>::operator^(const TVector2& other) const
{
    // |X1 Y1|
    // |X2 Y2|
    // Cross product: X1*Y2 - Y1*X2
    return (X * other.Y) - (Y * other.X);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T>& TVector2<T>::operator^=(const TVector2& other)
{
    TVector2 cross = (*this) ^ other;
    *this = cross;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector2<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y));
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector2<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
void TVector2<T>::Normalize()
{
    T mag = Magnitude();
    if (mag > 0)
    {
        X *= (1.0F / mag);
        Y *= (1.0F / mag);
    }
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector2<T> TVector2<T>::Normalized() const
{
    T mag = Magnitude();
    if (mag > 0)
    {
        return TVector2<T>(X * (1.0F / mag), Y * (1.0F / mag));
    }
    // If the magnitude is zero, return a default unit vector (1.0, 1.0)
    return TVector2<T>(1.0F);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
void TVector2<T>::Invert()
{
    X = -X;
    Y = -Y;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector2<T>::Equal(const TVector2& other, T epsilon) const
{
    return IsNearlyEqual(X, other.X, epsilon) && IsNearlyEqual(Y, other.Y, epsilon);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector2<T>::IsZero(T epsilon) const
{
    return IsNearlyZero(X, epsilon) && IsNearlyZero(Y, epsilon);
}

NAMESPACE_END() // namespace BE::Math