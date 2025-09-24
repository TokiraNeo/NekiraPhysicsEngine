/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/Matrix4.hpp>

NAMESPACE_BEGIN(BE::Math)

/**
 * @brief Get Translation Matrix4 from a translation vector
 * @param postion Translation vector
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Translation4x4(const BE::Math::TVector3<T>& position)
{
    /**
     * @brief
     * row-major order:
     * | 1 0 0 Tx |
     * | 0 1 0 Ty |
     * | 0 0 1 Tz |
     * | 0 0 0 1  |
     */

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][3] = position.X;
    result[1][3] = position.Y;
    result[2][3] = position.Z;

    return result;
}

/**
 * @brief Get Translation Matrix4 from x, y, z components
 * @param x X component of translation
 * @param y Y component of translation
 * @param z Z component of translation
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Translation4x4(T x, T y, T z)
{
    /**
     * @brief
     * row-major order:
     * | 1 0 0 Tx |
     * | 0 1 0 Ty |
     * | 0 0 1 Tz |
     * | 0 0 0 1  |
     */

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][3] = x;
    result[1][3] = y;
    result[2][3] = z;

    return result;
}



/**
 * @brief Get Scaling Matrix4 from a scale vector
 * @param scale Scale vector
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Scaling4x4(const BE::Math::TVector3<T>& scale)
{
    /**
     * @brief
     * As we use row-major order, the scaling matrix is:
     * | Sx 0  0  0 |
     * | 0  Sy 0  0 |
     * | 0  0  Sz 0 |
     * | 0  0  0  1 |
     */

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
template <typename T = float>
static BE::Math::TMatrix4<T> Scaling4x4(T x, T y, T z)
{
    /**
     * @brief
     * As we use row-major order, the scaling matrix is:
     * | Sx 0  0  0 |
     * | 0  Sy 0  0 |
     * | 0  0  Sz 0 |
     * | 0  0  0  1 |
     */

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][0] = x;
    result[1][1] = y;
    result[2][2] = z;

    return result;
}



/**
 * @brief Get X Rotation Matrix4 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix4<T> XRotation4x4(T degrees)
{
    /**
     * @brief
     * The X rotation matrix is(row-major):
     * | 1 0    0     0 |
     * | 0 cosθ -sinθ 0 |
     * | 0 sinθ cosθ  0 |
     * | 0 0    0     1 |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[1][1] = Cos(radians);
    result[1][2] = -Sin(radians);

    result[2][1] = Sin(radians);
    result[2][2] = Cos(radians);

    return result;
}

/**
 * @brief Get X Rotation Matrix3 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix3<T> XRotation3x3(T degrees)
{
    /**
     * @brief
     * The X rotation matrix is(row-major):
     * | 1 0    0     |
     * | 0 cosθ -sinθ |
     * | 0 sinθ cosθ  |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix3<T> result = BE::Math::TMatrix3<T>::Identity();

    result[1][1] = Cos(radians);
    result[1][2] = -Sin(radians);

    result[2][1] = Sin(radians);
    result[2][2] = Cos(radians);

    return result;
}

/**
 * @brief Get Y Rotation Matrix4 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix4<T> YRotation4x4(T degrees)
{
    /**
     * @brief
     * The Y rotation matrix(row-major):
     * | cosθ  0 sinθ 0 |
     * | 0     1 0    0 |
     * | -sinθ 0 cosθ 0 |
     * | 0     0 0    1 |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][0] = Cos(radians);
    result[0][2] = Sin(radians);

    result[2][0] = -Sin(radians);
    result[2][2] = Cos(radians);

    return result;
}

/**
 * @brief Get Y Rotation Matrix3 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix3<T> YRotation3x3(T degrees)
{
    /**
     * @brief
     * The Y rotation matrix(row-major):
     * | cosθ  0 sinθ |
     * | 0     1 0    |
     * | -sinθ 0 cosθ |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix3<T> result = BE::Math::TMatrix3<T>::Identity();

    result[0][0] = Cos(radians);
    result[0][2] = Sin(radians);

    result[2][0] = -Sin(radians);
    result[2][2] = Cos(radians);

    return result;
}

/**
 * @brief Get Z Rotation Matrix4 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix4<T> ZRotation4x4(T degrees)
{
    /**
     * @brief
     * The Z rotation matrix(row-major):
     * | cosθ -sinθ 0 0 |
     * | sinθ cosθ  0 0 |
     * | 0    0     1 0 |
     * | 0    0     0 1 |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix4<T> result = BE::Math::TMatrix4<T>::Identity();

    result[0][0] = Cos(radians);
    result[0][1] = -Sin(radians);

    result[1][0] = Sin(radians);
    result[1][1] = Cos(radians);

    return result;
}

/**
 * @brief Get Z Rotation Matrix3 from an angle in degrees
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix3<T> ZRotation3x3(T degrees)
{
    /**
     * @brief
     * The Z rotation matrix(row-major):
     * | cosθ -sinθ 0 |
     * | sinθ cosθ  0 |
     * | 0    0     1 |
     */

    // Convert angle from degrees to radians
    auto radians = DegreesToRadians(degrees);

    BE::Math::TMatrix3<T> result = BE::Math::TMatrix3<T>::Identity();

    result[0][0] = Cos(radians);
    result[0][1] = -Sin(radians);

    result[1][0] = Sin(radians);
    result[1][1] = Cos(radians);

    return result;
}

NAMESPACE_END() // namespace BE::Math