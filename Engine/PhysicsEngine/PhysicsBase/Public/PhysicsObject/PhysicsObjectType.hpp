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
 * @brief Physics Object Type
 * @details Physics object can be classified into three types:
 * - Static: An object that does not move and is not involved in physics simulations.
 * - Dynamic: An object that moves and is fully simulated by physics.
 * - Kinematic: An object that moves but is not followed by physics simulations.
 */
enum class EPhysicsObjectType : uint8_t
{
    Static,
    Dynamic,
    Kinematic
};

NAMESPACE_END() // namespace PHYE::PhysicsBase