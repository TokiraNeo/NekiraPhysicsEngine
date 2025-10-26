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

NAMESPACE_BEGIN(TMatrixInternal)

/// TMatrixConcept
template <typename T, char N>
concept TMatrixConcept = std::is_floating_point_v<T> && (N >= 2);

NAMESPACE_END() // namespace BE::Math::TMatrixInternal

NAMESPACE_END() // namespace BE::Math