/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Rigid2D/RigidBody2D/RigidBodyComponent2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

SRigidBodyComponent2D::SRigidBodyComponent2D()
    : Type(PHYE::PhysicsBase::ERigidBodyType::Static), Velocity(0.0F), AngularVelocity(0.0F), Mass(1.0F),
      InverseMass(1.0F), Inertia(1.0F), InverseInertia(1.0F)
{
    // Static body has infinite mass and inertia
    if(Type == PHYE::PhysicsBase::ERigidBodyType::Static)
    {
        Mass = 0.0F;
        InverseMass = 0.0F;
        Inertia = 0.0F;
        InverseInertia = 0.0F;
    }
}

SRigidBodyComponent2D::SRigidBodyComponent2D(PHYE::PhysicsBase::ERigidBodyType rigidBodyType, float mass, float inertia)
    : Type(rigidBodyType), Velocity(0.0F), AngularVelocity(0.0F), Mass(mass),
      InverseMass(mass > 0.0F ? 1.0F / mass : 0.0F), Inertia(inertia),
      InverseInertia(inertia > 0.0F ? 1.0F / inertia : 0.0F)
{
    // Static body has infinite mass and inertia
    if(Type == PHYE::PhysicsBase::ERigidBodyType::Static)
    {
        Mass = 0.0F;
        InverseMass = 0.0F;
        Inertia = 0.0F;
        InverseInertia = 0.0F;
    }
}

NAMESPACE_END() // namespace PHYE::Physics2D