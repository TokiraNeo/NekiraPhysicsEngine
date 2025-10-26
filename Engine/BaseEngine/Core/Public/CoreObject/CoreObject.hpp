/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <Tick/TickInterface.hpp>


NAMESPACE_BEGIN(BE::Core)

/**
 * @brief Base Object class in Nekira Physics Engine.
 * Inherits from IConnectionInterface to manage signal-slot connections automatically, which provides
 * a safe way to use Delegate.
 */
class CObject : public ITickInterface
{
public:
    CObject() = default;
    ~CObject() override = default;

    CObject(const CObject&) = delete;
    CObject& operator=(const CObject&) = delete;

    CObject(CObject&&) noexcept = default;
    CObject& operator=(CObject&&) noexcept = default;
};

NAMESPACE_END() // namespace BE::Core