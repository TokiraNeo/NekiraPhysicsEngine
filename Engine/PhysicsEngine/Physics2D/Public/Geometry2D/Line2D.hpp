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
class CLine2D final : public CPrimitiveShape2D
{
private:
    CPoint2D Start;
    CPoint2D End;

public:
    ~CLine2D() override = default;

    CLine2D() = default;
    CLine2D(CPoint2D start, CPoint2D end);
    CLine2D(CPoint2D start, const SVector2F& extend);

    CLine2D(const CLine2D& other) = default;
    CLine2D(CLine2D&& other) noexcept = default;

    CLine2D& operator=(const CLine2D& other) = default;
    CLine2D& operator=(CLine2D&& other) noexcept = default;

    bool operator==(const CLine2D& other) const;
    bool operator!=(const CLine2D& other) const;

    // Length
    [[nodiscard]] float Length() const;
    [[nodiscard]] float LengthSquared() const;

    // Getters
    [[nodiscard]] CPoint2D  GetStart() const;
    [[nodiscard]] CPoint2D  GetEnd() const;
    [[nodiscard]] SVector2F GetDiagonal() const;
};

NAMESPACE_END() // namespace PHYE::Physics2D