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

CRectangle2D::CRectangle2D() : Origin(0.0F), End(1.0F)
{}

CRectangle2D::CRectangle2D(CPoint2D origin, CPoint2D end) : Origin(std::move(origin)), End(std::move(end))
{}

CRectangle2D::CRectangle2D(CPoint2D origin, const SVector2F& extend) : Origin(std::move(origin)), End(std::move(origin + extend))
{}

CPoint2D CRectangle2D::GetOrigin() const
{
    return Origin;
}

CPoint2D CRectangle2D::GetEnd() const
{
    return End;
}

SVector2F CRectangle2D::GetExtend() const
{
    return End - Origin;
}

float CRectangle2D::Width() const
{
    return std::abs(End.X() - Origin.X());
}

float CRectangle2D::Height() const
{
    return std::abs(End.Y() - Origin.Y());
}

float CRectangle2D::Perimeter() const
{
    return 2.0F * (Width() + Height());
}

float CRectangle2D::Area() const
{
    return Width() * Height();
}

float CRectangle2D::DiagonalLength() const
{
    return (End - Origin).Magnitude();
}

NAMESPACE_END() // namespace PHYE::Physics2D



NAMESPACE_BEGIN(PHYE::Physics2D)

SOrientedRectangle2D::SOrientedRectangle2D() : Center{0.0F}, HalfExtents{0.5F, 0.5F}, Angle{0.0F}
{}

SOrientedRectangle2D::SOrientedRectangle2D(CPoint2D center, SVector2F halfExtents, float angle)
    : Center(std::move(center)), HalfExtents(std::move(halfExtents)), Angle(angle)
{}

CPoint2D SOrientedRectangle2D::GetCenter() const
{
    return Center;
}

SVector2F SOrientedRectangle2D::GetHalfExtents() const
{
    return HalfExtents;
}

NAMESPACE_END() // namespace PHYE::Physics2D