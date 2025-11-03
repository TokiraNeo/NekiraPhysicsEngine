/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Transforms/Internal/Transform2D.hpp>
#include <Transforms/Internal/Transform3D.hpp>

/* ====-------------------------------------------==== */
/// Type Aliases for Two-Dimensional Transforms
/* ====-------------------------------------------==== */
using STransform2D = BE::Math::TTransform2D<float>;

using STransform2Df = BE::Math::TTransform2D<float>;

using STransform2Dd = BE::Math::TTransform2D<double>;



/* ====-------------------------------------------==== */
/// Type Aliases for Three-Dimensional Transforms
/* ====-------------------------------------------==== */
using STransform3D = BE::Math::TTransform3D<float>;

using STransform3Df = BE::Math::TTransform3D<float>;

using STransform3Dd = BE::Math::TTransform3D<double>;