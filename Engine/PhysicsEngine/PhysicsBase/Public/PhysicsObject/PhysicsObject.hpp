/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreObject/CoreObject.hpp>

NAMESPACE_BEGIN(PHYE::PhysicsBase)

class CPhysicsObject : public BE::Core::CObject
{
public:
    CPhysicsObject() = default;
    virtual ~CPhysicsObject() = default;

    CPhysicsObject(const CPhysicsObject&) = default;
    CPhysicsObject& operator=(const CPhysicsObject&) = default;

    CPhysicsObject(CPhysicsObject&&) noexcept = default;
    CPhysicsObject& operator=(CPhysicsObject&&) noexcept = default;
};


NAMESPACE_END() // namespace PHYE::PhysicsBase