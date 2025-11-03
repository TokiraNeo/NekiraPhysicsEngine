/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <memory>
#include <Vectors/Vectors.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

// Forward Declarations
struct SBoundingVolume2D;
class CPrimitiveShape2D;

/**
 * @brief Collider2D that holds bounding volume information.
 */
class CCollider2D final
{
public:
    CCollider2D() = default;
    ~CCollider2D() = default;

    CCollider2D(const CCollider2D&) = delete;
    CCollider2D(CCollider2D&&) noexcept = default;

    CCollider2D& operator=(const CCollider2D&) = delete;
    CCollider2D& operator=(CCollider2D&&) noexcept = default;

    // @TODO: Broad Phase -> Providing simple BoundingCircle2D to filter potential collisions quickly

    // @TODO: Narrow Phase -> Providing AABB or Other BoundingVolume2D for precise collision detection

private:
    // Primitive Shape
    std::unique_ptr<CPrimitiveShape2D> PrimitiveShape;

    // Local Transform
    SVector2F LocalPosition;
    SVector2F LocalScale;
    float LocalRotation = 0.0F;

    // @TODO: Cache Bounding Volume for two collision detection phases???
};

NAMESPACE_END() // namespace PHYE::Physics2D