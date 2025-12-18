/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <PhysicsWorld2D/PhysicsWorld2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

CPhysicsWorld2D& CPhysicsWorld2D::Get()
{
    static CPhysicsWorld2D instance;
    return instance;
}

NAMESPACE_END() // namespace PHYE::Physics2D