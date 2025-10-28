/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Geometry2D/Rectangle2D.hpp>
#include <cmath>
#include <utility>

NAMESPACE_BEGIN(PHYE::Physics2D)

SRectangle2D::SRectangle2D() : Origin{0.0F}, Extend{1.0F}
{}

SRectangle2D::SRectangle2D(SPoint2D origin, SPoint2D extend) : Origin(std::move(origin)), Extend(std::move(extend))
{}

float SRectangle2D::Width() const
{
    return std::abs(Extend.X - Origin.X);
}

float SRectangle2D::Height() const
{
    return std::abs(Extend.Y - Origin.Y);
}

float SRectangle2D::Perimeter() const
{
    return 2.0F * (Width() + Height());
}

float SRectangle2D::Area() const
{
    return Width() * Height();
}

float SRectangle2D::DiagonalLength() const
{
    return (Extend - Origin).Magnitude();
}

NAMESPACE_END() // namespace PHYE::Physics2D



NAMESPACE_BEGIN(PHYE::Physics2D)

SOrientedRectangle2D::SOrientedRectangle2D() : Center{0.0F}, HalfExtents{0.5F, 0.5F}, Angle{0.0F}
{}

SOrientedRectangle2D::SOrientedRectangle2D(SPoint2D center, SVector2F halfExtents, float angle)
    : Center(std::move(center)), HalfExtents(std::move(halfExtents)), Angle(angle)
{}

NAMESPACE_END() // namespace PHYE::Physics2D