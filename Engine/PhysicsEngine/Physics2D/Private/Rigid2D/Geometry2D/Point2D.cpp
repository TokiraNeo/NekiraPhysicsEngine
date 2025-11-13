/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Rigid2D/Geometry2D/Point2D.hpp>
#include <utility>

NAMESPACE_BEGIN(PHYE::Physics2D)

constexpr CPoint2D::CPoint2D() : Position(0.0F)
{}

CPoint2D::CPoint2D(SVector2F vector2f) : Position(std::move(vector2f))
{}

CPoint2D& CPoint2D::operator=(const SVector2F& vector2f)
{
    Position = vector2f;
    return *this;
}

bool CPoint2D::operator==(const CPoint2D& other) const
{
    return Position == other.Position;
}

bool CPoint2D::operator!=(const CPoint2D& other) const
{
    return !(*this == other);
}

CPoint2D CPoint2D::operator+(const SVector2F& vector) const
{
    return CPoint2D(Position + vector);
}

SVector2F CPoint2D::operator-(const CPoint2D& other) const
{
    return Position - other.Position;
}

CPoint2D& CPoint2D::operator+=(const SVector2F& vector)
{
    Position += vector;
    return *this;
}

CPoint2D& CPoint2D::operator-=(const SVector2F& vector)
{
    Position -= vector;
    return *this;
}


SVector2F CPoint2D::ToVector2F() const
{
    return Position;
}

void CPoint2D::SetX(float x)
{
    Position.X = x;
}

void CPoint2D::SetY(float y)
{
    Position.Y = y;
}

void CPoint2D::Set(const SVector2F& vector)
{
    Position = vector;
}

NAMESPACE_END() // namespace PHYE::Physics2D