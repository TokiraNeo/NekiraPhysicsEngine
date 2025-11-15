/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once



#include <CoreMacros.hpp>
#include <NekiraECS/Core/Component/Component.hpp>
#include <Physics2D.hpp>
#include <RigidBodyType.hpp>
#include <Transforms/Transforms.hpp>
#include <Vectors/Vectors.hpp>


NAMESPACE_BEGIN(PHYE::Physics2D)

/**
 * @brief 2D Rigid Body Component
 * @details This component holds rigid body properties for 2D physics simulation.
 * These properties include type, mass, velocity, and transform information.
 * Originally, these properties were part of CRigidBody2D class, but here they are refactored into this component for
 * better ECS integration.
 */
struct PHYSICS2D_API SRigidBodyComponent2D final : public NekiraECS::Component<SRigidBodyComponent2D>
{
    // 刚体类型
    PHYE::PhysicsBase::ERigidBodyType Type;

    // 位置和旋转
    STransform2D Transform;

    // 线速度
    SVector2F Velocity;

    // 角速度
    float AngularVelocity;

    // 质量
    float Mass;
    // 质量的倒数，优化计算，0表示无限大质量（static类型刚体）
    float InverseMass;

    // 转动惯量，反映物体抗旋转的能力
    float Inertia;
    // 转动惯量的倒数
    float InverseInertia;

    ~SRigidBodyComponent2D() override = default;

    SRigidBodyComponent2D();
    explicit SRigidBodyComponent2D(PHYE::PhysicsBase::ERigidBodyType rigidBodyType, float mass = 1.0F,
                                   float inertia = 1.0F);

    SRigidBodyComponent2D(const SRigidBodyComponent2D&) = delete;
    SRigidBodyComponent2D(SRigidBodyComponent2D&&) noexcept = default;

    SRigidBodyComponent2D& operator=(const SRigidBodyComponent2D&) = delete;
    SRigidBodyComponent2D& operator=(SRigidBodyComponent2D&&) noexcept = default;
};

NAMESPACE_END() // namespace PHYE::Physics2D