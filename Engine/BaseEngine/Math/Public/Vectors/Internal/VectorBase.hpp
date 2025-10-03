/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <EASTL/type_traits.h>

NAMESPACE_BEGIN(BE::Math)

NAMESPACE_BEGIN(TVectorInternal)

/// TVectorConcept
template <typename T>
concept TVectorConcept = eastl::is_floating_point_v<T>;

NAMESPACE_END() // namespace BE::Math::TVectorInternal

NAMESPACE_END() // namespace BE::Math