/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <type_traits>

NAMESPACE_BEGIN(BE::Math)

NAMESPACE_BEGIN(TRotationInternal)

/// TRotationConcept
template <typename T = float>
concept TRotationConcept = std::is_floating_point_v<T>;

NAMESPACE_END() // namespace BE::Math::TRotationInternal

NAMESPACE_END() // namespace BE::Math