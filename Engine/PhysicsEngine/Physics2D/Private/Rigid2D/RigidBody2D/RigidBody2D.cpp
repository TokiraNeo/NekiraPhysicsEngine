/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Rigid2D/RigidBody2D/RigidBody2D.hpp>
#include <NekiraECS/Core/Coordinator/Coordinator.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

CRigidBody2D::CRigidBody2D() : RigidBodyEntity(NekiraECS::Coordinator::CreateEntity())
{
}

CRigidBody2D::~CRigidBody2D()
{
    NekiraECS::Coordinator::DestroyEntity(RigidBodyEntity);
}

NAMESPACE_END() // namespace PHYE::Physics2D