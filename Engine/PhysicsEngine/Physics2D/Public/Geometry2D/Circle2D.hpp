/**
* GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Geometry2D/Point2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief Circle2D
 * @details A circle in 2D space defined by its center point and radius.
 */
struct SCircle2D final
{
    SPoint2D Center;
    float Radius;

    ~SCircle2D() = default;
    SCircle2D();
    SCircle2D(SPoint2D center, float radius);

    SCircle2D(const SCircle2D& other) = default;
    SCircle2D(SCircle2D&& other) noexcept = default;

    SCircle2D& operator=(const SCircle2D& other) = default;
    SCircle2D& operator=(SCircle2D&& other) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D