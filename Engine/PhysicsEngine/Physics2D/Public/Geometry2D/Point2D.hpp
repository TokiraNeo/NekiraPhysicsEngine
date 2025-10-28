/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Vectors/Internal/Vector2.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief Point2D
 * @details Since a point in 2D space can simply be represented by a 2D vector,
 * so we just define Point2D as a type alias of TVector2<float>.
 */
using SPoint2D = BE::Math::TVector2<float>;

NAMESPACE_END() // namespace PHYE::Physics2D