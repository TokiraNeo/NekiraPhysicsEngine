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
#include <Physics2D.hpp>
#include <memory>
#include <vector>



NAMESPACE_BEGIN(PHYE::Physics2D)

// Forward Declarations
class CCollider2D;

/**
 * @brief RigidBody2D
 * @details holds Colliders and Entity links to the SRigidBodyComponent2D component.
 * We wanna to use ECS for better performance, so the rigid body properties are moved to SRigidBodyComponent2D
 * component. And we remain a RigidBodyEntity in this class to link the component.
 */
class PHYSICS2D_API CRigidBody2D final
{
private:
    // Rigid Body Entity(Used to link SRigidBodyComponent2D component)
    NekiraECS::Entity RigidBodyEntity;

    // Colliders attached to this rigid body
    std::vector<std::unique_ptr<CCollider2D>> Colliders;

public:
    CRigidBody2D();
    ~CRigidBody2D();

    CRigidBody2D(const CRigidBody2D&) = delete;
    CRigidBody2D(CRigidBody2D&&) noexcept = default;

    CRigidBody2D& operator=(const CRigidBody2D&) = delete;
    CRigidBody2D& operator=(CRigidBody2D&&) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D