/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <Delegate/Delegate.hpp>
#include <stack>
#include <unordered_map>


NAMESPACE_BEGIN(BE::Core)

// Forward declaration
class ITickInterface;
enum class ETickGroup : uint8_t;

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

    std::stack<ITickInterface*> PreRegisteredTickables;

    std::unordered_map<ETickGroup, TTickSignature> TickGroupMap;
};


NAMESPACE_END() // namespace BE::Core