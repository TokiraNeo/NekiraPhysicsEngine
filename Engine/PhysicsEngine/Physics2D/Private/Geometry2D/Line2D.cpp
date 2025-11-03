/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Geometry2D/Line2D.hpp>
#include <utility>

NAMESPACE_BEGIN(PHYE::Physics2D)

CLine2D::CLine2D(CPoint2D start, CPoint2D end) : Start(std::move(start)), End(std::move(end))
{}

CLine2D::CLine2D(CPoint2D start, const SVector2F& extend) : Start(std::move(start)), End(std::move(start + extend))
{}

bool CLine2D::operator==(const CLine2D& other) const
{
    return (other.Start == Start) && (other.End == End);
}

bool CLine2D::operator!=(const CLine2D& other) const
{
    return !(*this == other);
}

float CLine2D::Length() const
{
    const auto DIFF = End - Start;
    return DIFF.Magnitude();
}

float CLine2D::LengthSquared() const
{
    const auto DIFF = End - Start;
    return DIFF.SquareMagnitude();
}

CPoint2D CLine2D::GetStart() const
{
    return Start;
}

CPoint2D CLine2D::GetEnd() const
{
    return End;
}

SVector2F CLine2D::GetDiagonal() const
{
    return End - Start;
}

NAMESPACE_END() // namespace PHYE::Physics2D