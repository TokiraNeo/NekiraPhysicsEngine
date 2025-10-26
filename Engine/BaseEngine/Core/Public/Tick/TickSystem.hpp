/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <EASTL/stack.h>
#include <EASTL/unordered_map.h>

// Forward declaration
namespace NekiraDelegate
{
struct MultiSignalHandle;
}

NAMESPACE_BEGIN(BE::Core)

// Forward declaration
class ITickInterface;
enum class ETickGroup : unsigned char;

/**
 * @brief Tick System to manage tick updates.
 */
class CTickSystem final
{
    NEKIRA_MULTI_DELEGATE(TTickSignature, float /* deltaTime */)

public:
    CTickSystem(const CTickSystem&) = delete;
    CTickSystem(CTickSystem&&) noexcept = delete;

    CTickSystem& operator=(const CTickSystem&) = delete;
    CTickSystem& operator=(CTickSystem&&) noexcept = delete;

    ~CTickSystem() = default;

    // Get the singleton instance of Tick System
    static CTickSystem& Get();

    // Initialize the Tick System
    void Initialize();

    // Pre-Register a tick delegate
    void PreRegisterTick(ITickInterface* tickable);

    // Unregister a tick delegate
    void UnregisterTick(ETickGroup tickGroup, const NekiraDelegate::MultiSignalHandle& handle);

private:
     CTickSystem() = default;

    // Register a tick delegate
    void RegisterTick(ETickGroup tickGroup, ITickInterface* tickable, void (ITickInterface::*funcPtr)(float));

    eastl::stack<ITickInterface*> PreRegisteredTickables;

    eastl::unordered_map<ETickGroup, TTickSignature> TickGroupMap;
};


NAMESPACE_END() // namespace BE::Core