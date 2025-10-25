/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <PhysicsObject/PhysicsObject.hpp>
#include <NekiraECS/Core/Coordinator/Coordinator.hpp>

NAMESPACE_BEGIN(PHYE::PhysicsBase)

CPhysicsObject::CPhysicsObject(NekiraECS::Entity entityID) : ID(entityID)
{}

CPhysicsObject::~CPhysicsObject()
{
    NekiraECS::Coordinator::DestroyEntity(ID);
}

NAMESPACE_END() // namespace PHYE::PhysicsBase