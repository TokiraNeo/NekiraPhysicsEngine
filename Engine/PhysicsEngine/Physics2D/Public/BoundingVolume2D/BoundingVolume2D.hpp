/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <Physics2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief Bounding Valume 2D base class for all 2D bounding volumes.
 */
struct PHYSICS2D_API SBoundingVolume2D
{
public:
    SBoundingVolume2D() = default;
    virtual ~SBoundingVolume2D() = default;

    SBoundingVolume2D(const SBoundingVolume2D&) = default;
    SBoundingVolume2D(SBoundingVolume2D&&) noexcept = default;

    SBoundingVolume2D& operator=(const SBoundingVolume2D&) = default;
    SBoundingVolume2D& operator=(SBoundingVolume2D&&) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D