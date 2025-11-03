/**
* GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <cstdint>

NAMESPACE_BEGIN(PHYE::PhysicsBase)

/**
 * @brief Rigid Body Type Enumeration
 * @details Rigid bodies can be classified into three main types:
 * - Static: These bodies do not move and are unaffected by forces or collisions.
 * - Dynamic: These bodies can move and are affected by forces and collisions, responding according to the physics simulation.
 * - Kinematic: These bodies can move but are not affected by forces; their motion is not followed the physics simulation.
 */
enum class ERigidBodyType : uint8_t
{
    Static,
    Dynamic,
    Kinematic
};

NAMESPACE_END() // namespace PHYE::PhysicsBase