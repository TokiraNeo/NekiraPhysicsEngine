/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <ForceGenerator2D/ForceGenerator2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

class PHYSICS2D_API CGravityGenerator2D final : public CForceGenerator2D
{
public:
    ~CGravityGenerator2D() override = default;

    CGravityGenerator2D() = default;

    CGravityGenerator2D(const CGravityGenerator2D&) = default;
    CGravityGenerator2D(CGravityGenerator2D&&) noexcept = default;

    CGravityGenerator2D& operator=(const CGravityGenerator2D&) = default;
    CGravityGenerator2D& operator=(CGravityGenerator2D&&) noexcept = default;

    // Function to Update Force
    void UpdateForce(CPhysicsObject2D* object, float deltaTime) override;
};

NAMESPACE_END() // namespace PHYE::Physics2D