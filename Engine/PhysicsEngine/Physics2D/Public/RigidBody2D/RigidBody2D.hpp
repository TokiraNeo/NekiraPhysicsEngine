/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <Physics2D.hpp>
#include <RigidBodyType.hpp>
#include <memory>
#include <vector>



NAMESPACE_BEGIN(PHYE::Physics2D)

// Forward Declarations
class CCollider2D;

/**
 * @brief RigidBody2D
 * @details holds rigid body type, mass, velocity, collider2D and other physical properties.
 */
class PHYSICS2D_API CRigidBody2D final
{
private:
    // Rigid Body Type
    PHYE::PhysicsBase::ERigidBodyType Type = PHYE::PhysicsBase::ERigidBodyType::Static;

    // Colliders attached to this rigid body
    std::vector<std::unique_ptr<CCollider2D>> Colliders;

public:
    CRigidBody2D() = default;
    ~CRigidBody2D() = default;

    CRigidBody2D(const CRigidBody2D&) = delete;
    CRigidBody2D(CRigidBody2D&&) noexcept = default;

    CRigidBody2D& operator=(const CRigidBody2D&) = delete;
    CRigidBody2D& operator=(CRigidBody2D&&) noexcept = default;

    constexpr explicit CRigidBody2D(PHYE::PhysicsBase::ERigidBodyType type) : Type(type)
    {}

    // Getters
    [[nodiscard]] constexpr PHYE::PhysicsBase::ERigidBodyType GetRigidType() const
    {
        return Type;
    }
};

NAMESPACE_END() // namespace PHYE::Physics2D