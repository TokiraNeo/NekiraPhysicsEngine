/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <PhysicsObject2D/PhysicsObject2D.hpp>
#include <Rigid2D/RigidBody2D/RigidBody2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

CPhysicsObject2D::CPhysicsObject2D() : RigidBody(std::move(std::make_unique<CRigidBody2D>()))
{}

NAMESPACE_END() // namespace PHYE::Physics2D