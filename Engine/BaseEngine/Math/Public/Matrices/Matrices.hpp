/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Matrices/Internal/Matrix2.hpp>
#include <Matrices/Internal/Matrix3.hpp>
#include <Matrices/Internal/Matrix4.hpp>

/* ====-------------------------------------------==== */
/// Matrix Types Alias
/* ====-------------------------------------------==== */

using SMatrix2 = BE::Math::TMatrix2<float>;
using SMatrix3 = BE::Math::TMatrix3<float>;
using SMatrix4 = BE::Math::TMatrix4<float>;

using SMatrix2F = BE::Math::TMatrix2<float>;
using SMatrix3F = BE::Math::TMatrix3<float>;
using SMatrix4F = BE::Math::TMatrix4<float>;

using SMatrix2D = BE::Math::TMatrix2<double>;
using SMatrix3D = BE::Math::TMatrix3<double>;
using SMatrix4D = BE::Math::TMatrix4<double>;

/* ====-------------------------------------------==== */
/// Identity Matrices
/* ====-------------------------------------------==== */

constexpr SMatrix2 IDENTITY_MATRIX2 = SMatrix2::Identity();

constexpr SMatrix3 IDENTITY_MATRIX3 = SMatrix3::Identity();

constexpr SMatrix4 IDENTITY_MATRIX4 = SMatrix4::Identity();

constexpr SMatrix2F IDENTITY_MATRIX2F = SMatrix2F::Identity();

constexpr SMatrix3F IDENTITY_MATRIX3F = SMatrix3F::Identity();

constexpr SMatrix4F IDENTITY_MATRIX4F = SMatrix4F::Identity();

constexpr SMatrix2D IDENTITY_MATRIX2D = SMatrix2D::Identity();

constexpr SMatrix3D IDENTITY_MATRIX3D = SMatrix3D::Identity();

constexpr SMatrix4D IDENTITY_MATRIX4D = SMatrix4D::Identity();