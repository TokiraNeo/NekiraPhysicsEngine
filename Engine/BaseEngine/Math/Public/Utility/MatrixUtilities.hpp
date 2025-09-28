/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Matrices.hpp>

NAMESPACE_BEGIN(BE::Math)

// =====================================================================
// Translation Matrix
// =====================================================================

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

// =====================================================================
// Scaling Matrix
// =====================================================================

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

// =====================================================================
// Euler-angle Rotations
// =====================================================================

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

// =====================================================================
// Combined Euler-angle Rotations
// =====================================================================

/**
 * @brief Get Rotation Matrix4 from TVector3(X, Y, Z)
 * @param rotation Rotation vector3 in degrees for each axis
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Rotation4x4(const BE::Math::TVector3<T>& rotation)
{
    return XRotation4x4<T>(rotation.X) * YRotation4x4<T>(rotation.Y) * ZRotation4x4<T>(rotation.Z);
}

/**
 * @brief Get Rotation Matrix3 from TVector3(X, Y, Z)
 * @param rotation Rotation vector3 in degrees for each axis
 */
template <typename T = float>
static BE::Math::TMatrix3<T> Rotation3x3(const BE::Math::TVector3<T>& rotation)
{
    return XRotation3x3<T>(rotation.X) * YRotation3x3<T>(rotation.Y) * ZRotation3x3<T>(rotation.Z);
}

// =====================================================================
// Axis-Angle Rotation Matrix (Rodrigues' Rotation Formula)
// =====================================================================

/**
 * @brief Get Rodrigues' Rotation Matrix4 from an axis and an angle in degrees
 * @param axis Axis to rotate around
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix4<T> AxisRotation4x4(const BE::Math::TVector3<T>& axis, T degrees)
{
    const BE::Math::TVector3<T> NORMALIZED_AXIS = axis.Normalized();

    const T X = NORMALIZED_AXIS.X;
    const T Y = NORMALIZED_AXIS.Y;
    const T Z = NORMALIZED_AXIS.Z;

    // Convert angle from degrees to radians
    const T RADIANS = DegreesToRadians(degrees);

    const T COS = Cos(RADIANS);
    const T SIN = Sin(RADIANS);
    const T P = 1.0F - COS;

    /**
     * @brief Rodrigues' rotation matrix(row-major):
     * | cosθ + x²(1-cosθ)    xy(1-cosθ) - zsinθ    xz(1-cosθ) + ysinθ    0 |
     * | yx(1-cosθ) + zsinθ   cosθ + y²(1-cosθ)     yz(1-cosθ) - xsinθ    0 |
     * | zx(1-cosθ) - ysinθ   zy(1-cosθ) + xsinθ    cosθ + z²(1-cosθ)     0 |
     * | 0                    0                     0                     1 |
     */

    const BE::Math::TVector4<T> ROW1{(COS + (X * X * P)), ((Y * X * P) - (Z * SIN)), ((Z * X * P) + (Y * SIN)), 0};
    const BE::Math::TVector4<T> ROW2{((X * Y * P) + (Z * SIN)), (COS + (Y * Y * P)), ((Z * Y * P) - (X * SIN)), 0};
    const BE::Math::TVector4<T> ROW3{((X * Z * P) - (Y * SIN)), ((Y * Z * P) + (X * SIN)), (COS + (Z * Z * P)), 0};
    const BE::Math::TVector4<T> ROW4{0, 0, 0, 1};

    return BE::Math::TMatrix4<T>{ROW1, ROW2, ROW3, ROW4};
}

/**
 * @brief Get Rodrigues' Rotation Matrix3 from an axis and an angle in degrees
 * @param axis Axis to rotate around
 * @param degrees Angle in degrees
 */
template <typename T = float>
static BE::Math::TMatrix3<T> AxisRotation3x3(const BE::Math::TVector3<T>& axis, T degrees)
{
    return AxisRotation4x4<T>(axis, degrees).GetSubMatrix(3, 3);
}

// =====================================================================
// Transform Points and Vectors
// =====================================================================

/**
 * @brief Transform a 2D point using a 3x3 transformation matrix
 * @param point 2D point to be transformed
 * @param transform 3x3 transformation matrix
 */
template <typename T = float>
static BE::Math::TVector2<T> TransformPoint2D(const BE::Math::TVector2<T>& point,
                                              const BE::Math::TMatrix3<T>& transform)
{
    BE::Math::TVector3<T> point3D{point.X, point.Y, 1.0};

    point3D = transform * point3D;

    return BE::Math::TVector2<T>{point3D.X, point3D.Y};
}

/**
 * @brief Transform a 3D point using a 4x4 transformation matrix
 * @param point 3D point to be transformed
 * @param transform 4x4 transformation matrix
 */
template <typename T = float>
static BE::Math::TVector3<T> TransformPoint3D(const BE::Math::TVector3<T>& point,
                                              const BE::Math::TMatrix4<T>& transform)
{
    BE::Math::TVector4<T> point4D{point.X, point.Y, point.Z, 1.0};

    point4D = transform * point4D;

    return BE::Math::TVector3<T>{point4D.X, point4D.Y, point4D.Z};
}

/**
 * @brief Transform a 2D direction vector using a 3x3 transformation matrix
 * @param direction 2D direction vector to be transformed
 * @param transform 3x3 transformation matrix
 */
template <typename T = float>
static BE::Math::TVector2<T> TransformVector2D(const BE::Math::TVector2<T>& direction,
                                               const BE::Math::TMatrix3<T>& transform)
{
    BE::Math::TVector3<T> dir3D{direction.X, direction.Y, 0.0};

    dir3D = transform * dir3D;

    return BE::Math::TVector2<T>{dir3D.X, dir3D.Y};
}

/**
 * @brief Transform a 3D direction vector using a 4x4 transformation matrix
 * @param direction 3D direction vector to be transformed
 * @param transform 4x4 transformation matrix
 */
template <typename T = float>
static BE::Math::TVector3<T> TransformVector3D(const BE::Math::TVector3<T>& direction,
                                               const BE::Math::TMatrix4<T>& transform)
{
    BE::Math::TVector4<T> dir4D{direction.X, direction.Y, direction.Z, 0.0};

    dir4D = transform * dir4D;

    return BE::Math::TVector3<T>{dir4D.X, dir4D.Y, dir4D.Z};
}

// =====================================================================
// Combined Transform Matrix
// =====================================================================

/**
 * @brief Get Transform Matrix4 from translation, rotation and scale
 * @param scale Scale vector
 * @param rotation Rotation vector (in degrees)
 * @param translation Translation vector
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Transform4x4(const BE::Math::TVector3<T>& scale, const BE::Math::TVector3<T>& rotation,
                                          const BE::Math::TVector3<T>& translation)
{

    return Scaling4x4<T>(scale) * Rotation4x4<T>(rotation) * Translation4x4<T>(translation);
}

/**
 * @brief Get Transform Matrix4 from translation, axis-angle rotation and scale
 * @param scale Scale vector
 * @param axis Axis to rotate around
 * @param degrees Angle in degrees
 * @param translation Translation vector
 */
template <typename T = float>
static BE::Math::TMatrix4<T> Transform4x4(const BE::Math::TVector3<T>& scale, const BE::Math::TVector3<T>& axis,
                                          T degrees, const BE::Math::TVector3<T>& translation)
{
    return Scaling4x4<T>(scale) * AxisRotation4x4<T>(axis, degrees) * Translation4x4<T>(translation);
}


NAMESPACE_END() // namespace BE::Math