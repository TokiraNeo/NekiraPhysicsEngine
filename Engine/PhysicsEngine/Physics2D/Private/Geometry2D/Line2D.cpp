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

SLine2D::SLine2D(SPoint2D start, SPoint2D end) : Start(std::move(start)), End(std::move(end))
{}

bool SLine2D::operator==(const SLine2D& other) const
{
    return (other.Start == Start) && (other.End == End);
}

bool SLine2D::operator!=(const SLine2D& other) const
{
    return !(*this == other);
}

float SLine2D::Length() const
{
    const SPoint2D DIFF = End - Start;
    return DIFF.Magnitude();
}

float SLine2D::LengthSquared() const
{
    const SPoint2D DIFF = End - Start;
    return DIFF.SquareMagnitude();
}

NAMESPACE_END() // namespace PHYE::Physics2D