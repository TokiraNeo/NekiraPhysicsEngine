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
class PHYSICS2D_API CBoundingVolume2D
{
public:
    CBoundingVolume2D() = default;
    virtual ~CBoundingVolume2D() = default;

    CBoundingVolume2D(const CBoundingVolume2D&) = default;
    CBoundingVolume2D(CBoundingVolume2D&&) noexcept = default;

    CBoundingVolume2D& operator=(const CBoundingVolume2D&) = default;
    CBoundingVolume2D& operator=(CBoundingVolume2D&&) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D