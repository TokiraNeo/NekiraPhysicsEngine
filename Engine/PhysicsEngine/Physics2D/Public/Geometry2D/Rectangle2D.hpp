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
 * @brief Rectangle2D
 * @details A rectangle in 2D space can be defined by its origin point and extend (opposite
 * corner).
 */
class CRectangle2D final : public CPrimitiveShape2D
{
private:
    CPoint2D Origin;
    CPoint2D End;

public:
    ~CRectangle2D() override = default;

     CRectangle2D();
     CRectangle2D(CPoint2D origin, CPoint2D end);
     CRectangle2D(CPoint2D origin, const SVector2F& extend);

    CRectangle2D(const CRectangle2D& other) = default;
    CRectangle2D(CRectangle2D&& other) noexcept = default;

    CRectangle2D& operator=(const CRectangle2D& other) = default;
    CRectangle2D& operator=(CRectangle2D&& other) noexcept = default;

    // Getters
    [[nodiscard]] CPoint2D GetOrigin() const;
    [[nodiscard]] CPoint2D GetEnd() const;
    [[nodiscard]] SVector2F GetExtend() const;

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
class SOrientedRectangle2D final : public CPrimitiveShape2D
{
private:
    CPoint2D Center;
    SVector2F HalfExtents;
    float Angle; // In degrees

public:
    ~SOrientedRectangle2D() override = default;

     SOrientedRectangle2D();
     SOrientedRectangle2D(CPoint2D center, SVector2F halfExtents, float angle = 0.0F);

    SOrientedRectangle2D(const SOrientedRectangle2D& other) = default;
    SOrientedRectangle2D(SOrientedRectangle2D&& other) noexcept = default;

    SOrientedRectangle2D& operator=(const SOrientedRectangle2D& other) = default;
    SOrientedRectangle2D& operator=(SOrientedRectangle2D&& other) noexcept = default;

   // Getters
    [[nodiscard]] CPoint2D GetCenter() const;
    [[nodiscard]] SVector2F GetHalfExtents() const;

    [[nodiscard]] constexpr float GetAngle() const { return Angle; }
};

NAMESPACE_END() // namespace PHYE::Physics2D