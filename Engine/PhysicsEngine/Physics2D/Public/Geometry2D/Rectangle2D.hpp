/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Geometry2D/Point2D.hpp>
#include <Vectors/Vectors.hpp>


NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief Rectangle2D
 * @details A rectangle in 2D space can be defined by its origin point and extend (opposite
 * corner).
 */
struct SRectangle2D final
{
    SPoint2D Origin;
    SPoint2D Extend;

    ~SRectangle2D() = default;
     SRectangle2D();
     SRectangle2D(SPoint2D origin, SPoint2D extend);

    SRectangle2D(const SRectangle2D& other) = default;
    SRectangle2D(SRectangle2D&& other) noexcept = default;

    SRectangle2D& operator=(const SRectangle2D& other) = default;
    SRectangle2D& operator=(SRectangle2D&& other) noexcept = default;

    [[nodiscard]] float Width() const;
    [[nodiscard]] float Height() const;
    [[nodiscard]] float Perimeter() const;
    [[nodiscard]] float Area() const;
    [[nodiscard]] float DiagonalLength() const;
};

/**
 * @brief Oriented Rectangle2D
 * @details An oriented rectangle in 2D space defined by its center point, half extents and rotation angle(In degrees).
 */
struct SOrientedRectangle2D final
{
    SPoint2D Center;
    SVector2F HalfExtents;
    float Angle; // In degrees

    ~SOrientedRectangle2D() = default;
     SOrientedRectangle2D();
     SOrientedRectangle2D(SPoint2D center, SVector2F halfExtents, float angle = 0.0F);

    SOrientedRectangle2D(const SOrientedRectangle2D& other) = default;
    SOrientedRectangle2D(SOrientedRectangle2D&& other) noexcept = default;

    SOrientedRectangle2D& operator=(const SOrientedRectangle2D& other) = default;
    SOrientedRectangle2D& operator=(SOrientedRectangle2D&& other) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D