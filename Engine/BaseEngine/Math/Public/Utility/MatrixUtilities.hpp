/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/Matrix4.hpp>



/**
 * @brief Get Translation Matrix4 from a translation vector
 * @param postion Translation vector
 */
template <typename T>
static BE::Math::TMatrix4<T> Translation(const BE::Math::TVector3<T>& position)
{
    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[3][0] = position.X;
    result[3][1] = position.Y;
    result[3][2] = position.Z;

    return result;
}

/**
 * @brief Get Translation Matrix4 from x, y, z components
 * @param x X component of translation
 * @param y Y component of translation
 * @param z Z component of translation
 */
template <typename T>
static BE::Math::TMatrix4<T> Translation(T x, T y, T z)
{
    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[3][0] = x;
    result[3][1] = y;
    result[3][2] = z;

    return result;
}



/**
 * @brief Get Scaling Matrix4 from a scale vector
 * @param scale Scale vector
 */
template <typename T>
static BE::Math::TMatrix4<T> Scaling(const BE::Math::TVector3<T>& scale)
{
    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][0] = scale.X;
    result[1][1] = scale.Y;
    result[2][2] = scale.Z;

    return result;
}

/**
 * @brief Get Scaling Matrix4 from x, y, z components
 * @param x X component of scale
 * @param y Y component of scale
 * @param z Z component of scale
 */
template <typename T>
static BE::Math::TMatrix4<T> Scaling(T x, T y, T z)
{
    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][0] = x;
    result[1][1] = y;
    result[2][2] = z;

    return result;
}