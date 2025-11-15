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

// Forward Declaration
class CPhysicsObject2D;


/**
 * @brief 2D Force Generator Base Class.
 * @details This class determines a base force generator in the Physics2D World.
 * Specific force generators will inherit from this class. Such as Gravity, Drag, etc.
 */
class PHYSICS2D_API CForceGenerator2D
{
public:
    virtual ~CForceGenerator2D() = default;

    CForceGenerator2D() = default;

    CForceGenerator2D(const CForceGenerator2D&) = default;
    CForceGenerator2D(CForceGenerator2D&&) noexcept = default;

    CForceGenerator2D& operator=(const CForceGenerator2D&) = default;
    CForceGenerator2D& operator=(CForceGenerator2D&&) noexcept = default;

    // Function to Update Force
    virtual void UpdateForce(CPhysicsObject2D* object, float deltaTime) = 0;
};

NAMESPACE_END() // namespace PHYE::Physics2D