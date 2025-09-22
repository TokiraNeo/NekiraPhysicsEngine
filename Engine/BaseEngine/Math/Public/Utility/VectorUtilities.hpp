/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Vectors/Vectors.hpp>


/**
 * @brief Dot Product for Vector2
 */
template <typename T>
static T DotProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a | b;
}

/**
 * @brief Dot Product for Vector3
 */
template <typename T>
static T DotProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a | b;
}



/**
 * @brief Cross Product for Vector2
 */
template <typename T>
static BE::Math::TVector2<T> CrossProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a ^ b;
}

/**
 * @brief Cross Product for Vector3
 */
template <typename T>
static BE::Math::TVector3<T> CrossProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a ^ b;
}



/**
 * @brief Component-wise Product for Vector2
 */
template <typename T>
static BE::Math::TVector2<T> ComponentWiseProduct(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return a * b;
}

/**
 * @brief Component-wise Product for Vector3
 */
template <typename T>
static BE::Math::TVector3<T> ComponentWiseProduct(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return a * b;
}



/**
 * @brief Distance Between Two Vector2 or 2D Points
 */
template <typename T>
static T Distance(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    return (a - b).Magnitude();
}

/**
 * @brief Distance Between Two Vector3 or 3D Points
 */
template <typename T>
static T Distance(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    return (a - b).Magnitude();
}



/**
 * @brief Angle Between Two Vector2 (in Radians)
 */
template <typename T>
static T AngleBetween(const BE::Math::TVector2<T>& a, const BE::Math::TVector2<T>& b)
{
    auto dot = DotProduct(a, b);
    auto mags = Sqrt(a.SquareMagnitude() * b.SquareMagnitude());
    if (mags > 0)
    {
        return ACos(dot / mags);
    }
    return 0.0F;
}

/**
 * @brief Angle Between Two Vector3 (in Radians)
 */
template <typename T>
static T AngleBetween(const BE::Math::TVector3<T>& a, const BE::Math::TVector3<T>& b)
{
    auto dot = DotProduct(a, b);
    auto mags = Sqrt(a.SquareMagnitude() * b.SquareMagnitude());
    if (mags > 0)
    {
        return ACos(dot / mags);
    }
    return 0.0F;
}



/**
 * @brief Projection of Vector2 onto another Vector2
 * @param length Vector2 to be projected
 * @param direction Direction vector2 to project onto
 */
template <typename T>
static BE::Math::TVector2<T> Projection(const BE::Math::TVector2<T>& length, const BE::Math::TVector2<T>& direction)
{
    auto dot = DotProduct(length, direction);
    auto dirMagSq = direction.SquareMagnitude();
    if (dirMagSq > 0)
    {
        return direction * (dot / dirMagSq);
    }
    return BE::Math::TVector2<T>(0.0);
}

/**
 * @brief Projection of Vector3 onto another Vector3
 * @param length Vector3 to be projected
 * @param direction Direction vector3 to project onto
 */
template <typename T>
static BE::Math::TVector3<T> Projection(const BE::Math::TVector3<T>& length, const BE::Math::TVector3<T>& direction)
{
    auto dot = DotProduct(length, direction);
    auto dirMagSq = direction.SquareMagnitude();
    if (dirMagSq > 0)
    {
        return direction * (dot / dirMagSq);
    }
    return BE::Math::TVector3<T>(0.0);
}



/**
 * @brief Perpendicular of Vector2 from another Vector2
 * @param length Vector2 to be projected
 * @param direction Direction vector2 to project onto
 */
template <typename T>
static BE::Math::TVector2<T> Perpendicular(const BE::Math::TVector2<T>& length, const BE::Math::TVector2<T>& direction)
{
    return length - Projection(length, direction);
}

/**
 * @brief Perpendicular of Vector3 from another Vector3
 * @param length Vector3 to be projected
 * @param direction Direction vector3 to project onto
 */
template <typename T>
static BE::Math::TVector3<T> Perpendicular(const BE::Math::TVector3<T>& length, const BE::Math::TVector3<T>& direction)
{
    return length - Projection(length, direction);
}

/**
 * @brief Reflection of a Vector2 with a given normal
 * @param incident The incident vector2, which is to be reflected
 * @param normal The normal vector2
 */
template <typename T>
static BE::Math::TVector2<T> Reflection(const BE::Math::TVector2<T>& incident, const BE::Math::TVector2<T>& normal)
{
    // Make sure normal is normalized
    auto normalized = normal.Normalized();
    auto dot = DotProduct(incident, normalized);
    return incident - (normalized * (2.0F * dot));
}

/**
 * @brief Reflection of a Vector3 with a given normal
 * @param incident The incident vector3, which is to be reflected
 * @param normal The normal vector3
 */
template <typename T>
static BE::Math::TVector3<T> Reflection(const BE::Math::TVector3<T>& incident, const BE::Math::TVector3<T>& normal)
{
    // Make sure normal is normalized
    auto normalized = normal.Normalized();
    auto dot = DotProduct(incident, normalized);
    return incident - (normalized * (2.0F * dot));
}