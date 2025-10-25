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

NAMESPACE_BEGIN(BE::Core)

enum class ETickGroup : unsigned char;

/**
 * @brief Interface for tickable objects.
 * Classes that implement this interface can be updated every frame or tick.
 */
class ITickInterface : public NekiraDelegate::IConnectionInterface
{
    NEKIRA_SINGLE_DELEGATE(TOnRegisterTickSignature, void, NekiraDelegate::MultiSignalHandle)

public:
    ITickInterface();
    ~ITickInterface() override;

    ITickInterface(const ITickInterface&) = default;
    ITickInterface(ITickInterface&&) noexcept = default;

    ITickInterface& operator=(const ITickInterface&) = default;
    ITickInterface& operator=(ITickInterface&&) noexcept = default;

    virtual void Tick(float deltaTime) {}

    ETickGroup GetTickGroup() const;

private:
    void OnRegisterTickSuccess(NekiraDelegate::MultiSignalHandle handle);

public:
    // Delegate called when registered tick successfully, this will be invoked by TickSystem
    TOnRegisterTickSignature OnRegisterTick;

protected:
    ETickGroup TickGroup;

private:
    NekiraDelegate::MultiSignalHandle TickHandle {};
};

NAMESPACE_END() // namespace BE::Core