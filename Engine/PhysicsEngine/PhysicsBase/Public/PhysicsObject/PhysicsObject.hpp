/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <PhysicsBase.hpp>


NAMESPACE_BEGIN(PHYE::PhysicsBase)

/**
 * @brief Physics Object Base Class.
 * @details This class determines a base object in the Physics World.
 * 2D or 3D Physics Object classes will inherit from this class.
 */
class PHYSICSBASE_API CPhysicsObject
{
public:
    CPhysicsObject() = default;

    virtual ~CPhysicsObject() = default;

    CPhysicsObject(const CPhysicsObject&) = delete;
    CPhysicsObject(CPhysicsObject&&) noexcept = default;

    CPhysicsObject& operator=(const CPhysicsObject&) = delete;
    CPhysicsObject& operator=(CPhysicsObject&&) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::PhysicsBase