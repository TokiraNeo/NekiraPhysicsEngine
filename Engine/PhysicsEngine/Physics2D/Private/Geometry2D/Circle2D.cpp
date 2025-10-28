/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Geometry2D/Circle2D.hpp>
#include <utility>
#include <cassert>

NAMESPACE_BEGIN(PHYE::Physics2D)

SCircle2D::SCircle2D() : Center(0.0F), Radius(1.0F)
{}

SCircle2D::SCircle2D(SPoint2D center, float radius) : Center(std::move(center)), Radius(radius)
{
    // Make sure radius > 0
    assert(radius > 0.0F);
}

NAMESPACE_END() // namespace PHYE::Physics2D