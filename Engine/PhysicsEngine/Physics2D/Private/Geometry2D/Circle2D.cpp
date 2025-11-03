/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Geometry2D/Circle2D.hpp>

#include <cassert>
#include <utility>

NAMESPACE_BEGIN(PHYE::Physics2D)

CCircle2D::CCircle2D() : Center(0.0F), Radius(1.0F)
{}

CCircle2D::CCircle2D(CPoint2D center, float radius) : Center(std::move(center)), Radius(radius)
{
    // Make sure radius > 0
    assert(radius > 0.0F);
}

CPoint2D CCircle2D::GetCenter() const
{
    return Center;
}

NAMESPACE_END() // namespace PHYE::Physics2D