/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Geometry2D/PrimitiveShape2D.hpp>
#include <Vectors/Vectors.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief Point2D
 * @details Since a point in 2D space can simply be represented by a 2D vector,
 * so we just define Point2D as a type alias of TVector2<float>.
 */
class PHYSICS2D_API CPoint2D final : public CPrimitiveShape2D
{
private:
    SVector2F Position;

public:
    ~CPoint2D() override = default;

    constexpr CPoint2D();
    explicit constexpr CPoint2D(float value) : Position(value)
    {}
    constexpr CPoint2D(float x, float y) : Position(x, y)
    {}
    explicit CPoint2D(SVector2F vector2f);

    CPoint2D(const CPoint2D& other) = default;
    CPoint2D(CPoint2D&& other) noexcept = default;

    CPoint2D& operator=(const CPoint2D& other) = default;
    CPoint2D& operator=(CPoint2D&& other) noexcept = default;

    // Assignment from Vector2F
    CPoint2D& operator=(const SVector2F& vector2f);

    bool operator==(const CPoint2D& other) const;
    bool operator!=(const CPoint2D& other) const;

    // Point2D + Vector2F = Point2D
    CPoint2D operator+(const SVector2F& vector) const;

    // Point2D - Point2D = Vector2F
    SVector2F operator-(const CPoint2D& other) const;

    // +=, -= operators effect the Position itself
    CPoint2D& operator+=(const SVector2F& vector);
    CPoint2D& operator-=(const SVector2F& vector);

    // Getters
    [[nodiscard]] constexpr float X() const
    {
        return Position.X;
    }

    [[nodiscard]] constexpr float Y() const
    {
        return Position.Y;
    }

    [[nodiscard]] SVector2F ToVector2F() const;

    // Setters
    void SetX(float x);
    void SetY(float y);
    void Set(const SVector2F& vector);
};

NAMESPACE_END() // namespace PHYE::Physics2D