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
 * @brief Circle2D
 * @details A circle in 2D space defined by its center point and radius.
 */
class CCircle2D final : public CPrimitiveShape2D
{
private:
    CPoint2D Center;
    float    Radius;

public:
    ~CCircle2D() override = default;

    CCircle2D();
    CCircle2D(CPoint2D center, float radius);

    CCircle2D(const CCircle2D& other) = default;
    CCircle2D(CCircle2D&& other) noexcept = default;

    CCircle2D& operator=(const CCircle2D& other) = default;
    CCircle2D& operator=(CCircle2D&& other) noexcept = default;

    // Getters
    [[nodiscard]] CPoint2D        GetCenter() const;
    [[nodiscard]] constexpr float GetRadius() const
    {
        return Radius;
    }
};

NAMESPACE_END() // namespace PHYE::Physics2D