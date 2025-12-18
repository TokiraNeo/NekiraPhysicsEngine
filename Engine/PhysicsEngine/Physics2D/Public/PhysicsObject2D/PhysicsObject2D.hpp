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
#include <memory>


NAMESPACE_BEGIN(PHYE::Physics2D)

// Forward Declaration
class CRigidBody2D;

/**
 * @brief 2D Physics Object Class
 * @details This class determines an object in the Physics2D World.
 */
class PHYSICS2D_API CPhysicsObject2D final
{
public:
    ~CPhysicsObject2D() = default;

    CPhysicsObject2D();

    CPhysicsObject2D(const CPhysicsObject2D&) = delete;
    CPhysicsObject2D(CPhysicsObject2D&&) noexcept = default;

    CPhysicsObject2D& operator=(const CPhysicsObject2D&) = delete;
    CPhysicsObject2D& operator=(CPhysicsObject2D&&) noexcept = default;

private:
    std::unique_ptr<CRigidBody2D> RigidBody;
};

NAMESPACE_END() // namespace PHYE::Physics2D