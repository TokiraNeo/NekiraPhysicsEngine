/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Vectors/Vector2.hpp>
#include <Vectors/Vector3.hpp>
#include <Vectors/Vector4.hpp>


/// ====-------------------------------------====
/// TVector Type Aliases
/// ====-------------------------------------====

using SVector = BE::Math::TVector3<float>;

using SVector2F = BE::Math::TVector2<float>;

using SVector2D = BE::Math::TVector2<double>;

using SVector3F = BE::Math::TVector3<float>;

using SVector3D = BE::Math::TVector3<double>;

using SVector4F = BE::Math::TVector4<float>;

using SVector4D = BE::Math::TVector4<double>;



/// ====-------------------------------------====
/// Zero Vectors
/// ====-------------------------------------====

constexpr SVector ZERO_VECTOR = SVector(0.0F);

constexpr SVector2F ZERO_VECTOR2F = SVector2F(0.0F);

constexpr SVector2D ZERO_VECTOR2D = SVector2D(0.0);

constexpr SVector3F ZERO_VECTOR3F = SVector3F(0.0F);

constexpr SVector3D ZERO_VECTOR3D = SVector3D(0.0);

constexpr SVector4F ZERO_VECTOR4F = SVector4F(0.0F);

constexpr SVector4D ZERO_VECTOR4D = SVector4D(0.0);



/// ====-------------------------------------====
/// One Vectors (X: 1.0, Y: 1.0, Z: 1.0)
/// ====-------------------------------------====

constexpr SVector ONE_VECTOR = SVector(1.0F);

constexpr SVector2F ONE_VECTOR2F = SVector2F(1.0F);

constexpr SVector2D ONE_VECTOR2D = SVector2D(1.0);

constexpr SVector3F ONE_VECTOR3F = SVector3F(1.0F);

constexpr SVector3D ONE_VECTOR3D = SVector3D(1.0);

constexpr SVector4F ONE_VECTOR4F = SVector4F(1.0F);

constexpr SVector4D ONE_VECTOR4D = SVector4D(1.0);



/// ====-------------------------------------====
/// Forward Vectors (X: 1.0, Y: 0.0, Z: 0.0)
/// ====-------------------------------------====

constexpr SVector FORWARD_VECTOR = SVector(1.0F, 0.0F, 0.0F);

constexpr SVector2F FORWARD_VECTOR2F = SVector2F(1.0F, 0.0F);

constexpr SVector2D FORWARD_VECTOR2D = SVector2D(1.0, 0.0);

constexpr SVector3F FORWARD_VECTOR3F = SVector3F(1.0F, 0.0F, 0.0F);

constexpr SVector3D FORWARD_VECTOR3D = SVector3D(1.0, 0.0, 0.0);



/// ====-------------------------------------====
/// Backward Vectors (X: -1.0, Y: 0.0, Z: 0.0)
/// ====-------------------------------------====

constexpr SVector BACKWARD_VECTOR = SVector(-1.0F, 0.0F, 0.0F);

constexpr SVector2F BACKWARD_VECTOR2F = SVector2F(-1.0F, 0.0F);

constexpr SVector2D BACKWARD_VECTOR2D = SVector2D(-1.0, 0.0);

constexpr SVector3F BACKWARD_VECTOR3F = SVector3F(-1.0F, 0.0F, 0.0F);

constexpr SVector3D BACKWARD_VECTOR3D = SVector3D(-1.0, 0.0, 0.0);



/// ====-------------------------------------====
/// Right Vectors (X: 0.0, Y: 1.0, Z: 0.0)
/// ====-------------------------------------====

constexpr SVector RIGHT_VECTOR = SVector(0.0F, 1.0F, 0.0F);

constexpr SVector2F RIGHT_VECTOR2F = SVector2F(0.0F, 1.0F);

constexpr SVector2D RIGHT_VECTOR2D = SVector2D(0.0, 1.0);

constexpr SVector3F RIGHT_VECTOR3F = SVector3F(0.0F, 1.0F, 0.0F);

constexpr SVector3D RIGHT_VECTOR3D = SVector3D(0.0, 1.0, 0.0);



/// ====-------------------------------------====
/// Left Vectors (X: 0.0, Y: -1.0, Z: 0.0)
/// ====-------------------------------------====

constexpr SVector LEFT_VECTOR = SVector(0.0F, -1.0F, 0.0F);

constexpr SVector2F LEFT_VECTOR2F = SVector2F(0.0F, -1.0F);

constexpr SVector2D LEFT_VECTOR2D = SVector2D(0.0, -1.0);

constexpr SVector3F LEFT_VECTOR3F = SVector3F(0.0F, -1.0F, 0.0F);

constexpr SVector3D LEFT_VECTOR3D = SVector3D(0.0, -1.0, 0.0);



/// ====-------------------------------------====
/// Up Vectors (X: 0.0, Y: 0.0, Z: 1.0)
/// ====-------------------------------------====

constexpr SVector UP_VECTOR = SVector(0.0F, 0.0F, 1.0F);

constexpr SVector3F UP_VECTOR3F = SVector3F(0.0F, 0.0F, 1.0F);

constexpr SVector3D UP_VECTOR3D = SVector3D(0.0, 0.0, 1.0);



/// ====-------------------------------------====
/// Down Vectors (X: 0.0, Y: 0.0, Z: -1.0)
/// ====-------------------------------------====

constexpr SVector DOWN_VECTOR = SVector(0.0F, 0.0F, -1.0F);

constexpr SVector3F DOWN_VECTOR3F = SVector3F(0.0F, 0.0F, -1.0F);

constexpr SVector3D DOWN_VECTOR3D = SVector3D(0.0, 0.0, -1.0);



/// ====-------------------------------------====
/// Dot Product
/// ====-------------------------------------====

template <typename T>
static T DotProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a | b;
}

template <typename T>
static T DotProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a | b;
}



/// ====-------------------------------------====
/// Cross Product
/// ====-------------------------------------====

template <typename T>
static BE::Math::TVector2<T> CrossProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a ^ b;
}

template <typename T>
static BE::Math::TVector3<T> CrossProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a ^ b;
}



/// ====-------------------------------------====
/// Component-wise Product
/// ====-------------------------------------====

template <typename T>
static BE::Math::TVector2<T> ComponentWiseProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a * b;
}

template <typename T>
static BE::Math::TVector3<T> ComponentWiseProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a * b;
}