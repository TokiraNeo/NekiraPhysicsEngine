/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Tick/TickGroup.hpp>
#include <Tick/TickInterface.hpp>
#include <Tick/TickSystem.hpp>

NAMESPACE_BEGIN(BE::Core)

ITickInterface::ITickInterface() : TickGroup(TICK_GROUP_DEFAULT)
{
    OnRegisterTick.BindMemberFunction(this, &ITickInterface::OnRegisterTickSuccess);

    CTickSystem::Get().PreRegisterTick(this);
}

ITickInterface::~ITickInterface()
{
    OnRegisterTick.RemoveBinding();

    CTickSystem::Get().UnregisterTick(TickGroup,TickHandle);
}

void ITickInterface::OnRegisterTickSuccess(NekiraDelegate::MultiSignalHandle handle)
{
    TickHandle = handle;
}

ETickGroup ITickInterface::GetTickGroup() const
{
    return TickGroup;
}


NAMESPACE_END() // namespace BE::Core