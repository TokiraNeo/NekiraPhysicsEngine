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
 * @brief Physics World 2D
 * @details Manages the 2D physics simulation environment.
 */
class PHYSICS2D_API CPhysicsWorld2D final
{
public:
    CPhysicsWorld2D(const CPhysicsWorld2D&) = delete;
    CPhysicsWorld2D(CPhysicsWorld2D&&) noexcept = delete;

    CPhysicsWorld2D& operator=(const CPhysicsWorld2D&) = delete;
    CPhysicsWorld2D& operator=(CPhysicsWorld2D&&) noexcept = delete;

    ~CPhysicsWorld2D() = default;

    // Get singleton instance
    static CPhysicsWorld2D& Get();

private:
    CPhysicsWorld2D() = default;
};


NAMESPACE_END() // namespace PHYE::Physics2D