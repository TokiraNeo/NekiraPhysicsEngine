/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <MathUtility/MathUtilities.hpp>
#include <Vectors/Internal/VectorBase.hpp>



NAMESPACE_BEGIN(BE::Math)

/**
 * @brief TVector3<>
 * @details A generic 3D vector class template supporting various mathematical operations.
 */
template <typename T>
    requires TVectorInternal::TVectorConcept<T>
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

    // Normalize the vector to have a magnitude of 1
    void Normalize();
    // Get a new normalized vector based on this vector, without modifying this vector
    TVector3 Normalized() const;

    void Invert();

    bool Equal(const TVector3& other,
               T               epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;

    bool IsZero(T epsilon = (sizeof(T) == sizeof(float) ? KINDER_SMALL_FLOAT : KINDER_SMALL_DOUBLE)) const;
};



/* ====-------------------------------------------==== */
// Implementation of TVector3<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector3<T>::TVector3() : X(0), Y(0), Z(0)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector3<T>::TVector3(T value) : X(value), Y(value), Z(value)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
constexpr TVector3<T>::TVector3(T x, T y, T z) : X(x), Y(y), Z(z)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>::TVector3(const TVector3& other) : X(other.X), Y(other.Y), Z(other.Z)
{}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>::TVector3(TVector3&& other) noexcept : X(other.X), Y(other.Y), Z(other.Z)
{
    other.X = 0;
    other.Y = 0;
    other.Z = 0;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
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
    requires TVectorInternal::TVectorConcept<T>
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
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::operator+(const TVector3& other) const
{
    return TVector3<T>(X + other.X, Y + other.Y, Z + other.Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::operator-(const TVector3& other) const
{
    return TVector3<T>(X - other.X, Y - other.Y, Z - other.Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::operator*(const TVector3& other) const
{
    return TVector3<T>(X * other.X, Y * other.Y, Z * other.Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::operator*(T scalar) const
{
    return TVector3<T>(X * scalar, Y * scalar, Z * scalar);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>& TVector3<T>::operator+=(const TVector3& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>& TVector3<T>::operator-=(const TVector3& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>& TVector3<T>::operator*=(const TVector3& other)
{
    X *= other.X;
    Y *= other.Y;
    Z *= other.Z;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>& TVector3<T>::operator*=(T scalar)
{
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector3<T>::operator==(const TVector3& other) const
{
    return IsNearlyEqual(X, other.X) && IsNearlyEqual(Y, other.Y) && IsNearlyEqual(Z, other.Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector3<T>::operator!=(const TVector3& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector3<T>::operator|(const TVector3& other) const
{
    return (X * other.X) + (Y * other.Y) + (Z * other.Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::operator^(const TVector3& other) const
{
    // | i   j   k  |
    // | X1  Y1  Z1 |
    // | X2  Y2  Z2 |
    // Cross product: i(Y1*Z2 - Z1*Y2) - j(X1*Z2 - Z1*X2) + k(X1*Y2 - Y1*X2)
    return TVector3<T>((Y * other.Z) - (Z * other.Y), (Z * other.X) - (X * other.Z), (X * other.Y) - (Y * other.X));
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
TVector3<T>& TVector3<T>::operator^=(const TVector3& other)
{
    TVector3 cross = (*this) ^ other;
    *this = cross;
    return *this;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector3<T>::Magnitude() const
{
    return Sqrt((X * X) + (Y * Y) + (Z * Z));
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
T TVector3<T>::SquareMagnitude() const
{
    return (X * X) + (Y * Y) + (Z * Z);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
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
    requires TVectorInternal::TVectorConcept<T>
TVector3<T> TVector3<T>::Normalized() const
{
    T mag = Magnitude();
    if (mag > 0)
    {
        return TVector3<T>(X * (1.0F / mag), Y * (1.0F / mag), Z * (1.0F / mag));
    }
    // If the magnitude is zero, return a default unit vector (1.0, 1.0, 1.0)
    return TVector3<T>(1.0F);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
void TVector3<T>::Invert()
{
    X = -X;
    Y = -Y;
    Z = -Z;
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector3<T>::Equal(const TVector3& other, T epsilon) const
{
    return IsNearlyEqual(X, other.X, epsilon) && IsNearlyEqual(Y, other.Y, epsilon)
           && IsNearlyEqual(Z, other.Z, epsilon);
}

template <typename T>
    requires TVectorInternal::TVectorConcept<T>
bool TVector3<T>::IsZero(T epsilon) const
{
    return IsNearlyZero(X, epsilon) && IsNearlyZero(Y, epsilon) && IsNearlyZero(Z, epsilon);
}

NAMESPACE_END() // namespace BE::Math