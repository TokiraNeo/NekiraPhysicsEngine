/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Tick/TickInterface.hpp>
#include <Tick/TickSystem.hpp>

NAMESPACE_BEGIN(BE::Core)

CTickSystem& CTickSystem::Get()
{
    static CTickSystem inst;
    return inst;
}

void CTickSystem::Initialize()
{
    // Process pre-registered tickables
    while (!PreRegisteredTickables.empty())
    {
        auto* tickable = PreRegisteredTickables.top();
        PreRegisteredTickables.pop();

        const ETickGroup TICK_GROUP = tickable->GetTickGroup();

        RegisterTick(TICK_GROUP, tickable, &ITickInterface::Tick);
    }
}

void CTickSystem::PreRegisterTick(ITickInterface* tickable)
{
    PreRegisteredTickables.push(tickable);
}

void CTickSystem::UnregisterTick(ETickGroup tickGroup, const NekiraDelegate::MultiSignalHandle& handle)
{
    if (TickGroupMap.contains(tickGroup))
    {
        TickGroupMap[tickGroup].RemoveSingle(handle);
    }
}

void CTickSystem::RegisterTick(ETickGroup tickGroup, ITickInterface* tickable, void (ITickInterface::*funcPtr)(float))
{
    if (!TickGroupMap.contains(tickGroup))
    {
        TickGroupMap.insert({tickGroup, TTickSignature()});
    }

    auto handle = TickGroupMap[tickGroup].BindMemberFunction(tickable, funcPtr);

    // @todo: Broadcast the registration success
    tickable->OnRegisterTick.Invoke(std::move(handle));
}

NAMESPACE_END() // namespace BE::Core