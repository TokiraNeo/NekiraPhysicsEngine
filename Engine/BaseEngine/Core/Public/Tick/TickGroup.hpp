/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <cstdint>

NAMESPACE_BEGIN(BE::Core)

// Tick Groups for managing tick order
enum class ETickGroup : uint8_t
{
    BeginFrame = 0,
    PreUpdate,
    Update,
    PostUpdate,
    EndFrame,
};

constexpr ETickGroup TICK_GROUP_DEFAULT = ETickGroup::Update;

NAMESPACE_END() // namespace BE::Core