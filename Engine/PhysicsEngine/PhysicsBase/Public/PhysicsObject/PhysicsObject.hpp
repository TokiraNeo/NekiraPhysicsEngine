/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreObject/CoreObject.hpp>
#include <NekiraECS/Core/Entity/Entity.hpp>

NAMESPACE_BEGIN(PHYE::PhysicsBase)

class CPhysicsObject final : public BE::Core::CObject
{
public:
    CPhysicsObject() = default;
    ~CPhysicsObject() override = default;

    CPhysicsObject(const CPhysicsObject&) = default;
    CPhysicsObject& operator=(const CPhysicsObject&) = default;

    CPhysicsObject(CPhysicsObject&&) noexcept = default;
    CPhysicsObject& operator=(CPhysicsObject&&) noexcept = default;

protected:
    NekiraECS::Entity ID;

};


NAMESPACE_END() // namespace PHYE::PhysicsBase