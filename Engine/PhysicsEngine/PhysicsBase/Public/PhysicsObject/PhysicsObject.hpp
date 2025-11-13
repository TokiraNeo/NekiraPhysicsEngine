/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <NekiraECS/Core/Entity/Entity.hpp>
#include <PhysicsBase.hpp>


NAMESPACE_BEGIN(PHYE::PhysicsBase)

class PHYSICSBASE_API CPhysicsObject
{
public:
    CPhysicsObject() = default;

    explicit CPhysicsObject(NekiraECS::Entity entityID);

    virtual ~CPhysicsObject();

    CPhysicsObject(const CPhysicsObject&) = delete;
    CPhysicsObject(CPhysicsObject&&) noexcept = default;

    CPhysicsObject& operator=(const CPhysicsObject&) = delete;
    CPhysicsObject& operator=(CPhysicsObject&&) noexcept = default;

protected:
    NekiraECS::Entity ID;
};

NAMESPACE_END() // namespace PHYE::PhysicsBase