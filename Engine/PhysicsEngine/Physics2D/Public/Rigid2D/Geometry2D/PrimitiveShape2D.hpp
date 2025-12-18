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
 * @brief PrimitiveShape2D
 * @details Base class for all 2D primitive shapes used in the physics engine.
 */
class PHYSICS2D_API CPrimitiveShape2D
{
public:
    CPrimitiveShape2D() = default;
    virtual ~CPrimitiveShape2D() = default;

    CPrimitiveShape2D(const CPrimitiveShape2D& other) = default;
    CPrimitiveShape2D(CPrimitiveShape2D&& other) noexcept = default;

    CPrimitiveShape2D& operator=(const CPrimitiveShape2D& other) = default;
    CPrimitiveShape2D& operator=(CPrimitiveShape2D&& other) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D