/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraDelegate/Core/Macro.hpp>

template <typename RT, typename... args>
using TDelegate = NekiraDelegate::Delegate<RT, args...>;

template <typename... args>
using TMultiDelegate = NekiraDelegate::MultiDelegate<args...>;
