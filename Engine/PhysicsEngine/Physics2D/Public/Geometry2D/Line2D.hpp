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
 * @brief Line2D
 * @details A line in 2D space defined by two endpoints: Start and End.
 */
struct SLine2D final
{
    SPoint2D Start;
    SPoint2D End;

     SLine2D() = default;
    ~SLine2D() = default;

    SLine2D(const SLine2D& other) = default;
    SLine2D(SLine2D&& other) noexcept = default;

    SLine2D& operator=(const SLine2D& other) = default;
    SLine2D& operator=(SLine2D&& other) noexcept = default;

    SLine2D(SPoint2D start, SPoint2D end);

    bool operator==(const SLine2D& other) const;
    bool operator!=(const SLine2D& other) const;

    [[nodiscard]] float Length() const;
    [[nodiscard]] float LengthSquared() const;
};

NAMESPACE_END() // namespace PHYE::Physics2D