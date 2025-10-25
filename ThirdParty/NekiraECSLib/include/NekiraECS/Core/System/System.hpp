/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <cstdint>
#include <string>
#include <typeindex>
#include <vector>


namespace NekiraECS
{

// 系统优先级，数值越小优先级越高
using SystemPriority = int32_t;

// 默认系统优先级
constexpr SystemPriority SYSTEM_PRIORITY_DEFAULT = 0;

/**
 * 系统执行阶段分组
 * - BeginFrame: 帧开始阶段
 * - PreUpdate: 预更新阶段
 * - Update: 更新阶段,是主要的逻辑处理阶段,也是默认的系统分组
 * - PostUpdate: 后更新阶段
 * - Presentation: 呈现阶段
 * - EndFrame: 收尾阶段
 */
enum class SystemGroup : uint8_t
{
    BeginFrame = 0,
    PreUpdate,
    Update,
    PostUpdate,
    Presentation,
    EndFrame
};

// 默认的系统执行阶段
constexpr SystemGroup SYSTEM_GROUP_DEFAULT = SystemGroup::Update;

// 系统执行阶段分组列表，用于后续依次按组执行
const std::vector<SystemGroup> SYSTEM_GROUPS = {SystemGroup::BeginFrame,   SystemGroup::PreUpdate,
                                                SystemGroup::Update,       SystemGroup::PostUpdate,
                                                SystemGroup::Presentation, SystemGroup::EndFrame};

} // namespace NekiraECS


namespace NekiraECS
{
// 系统基础接口
class ISystemBase
{
public:
    ISystemBase() = default;
    ISystemBase(const ISystemBase&) = default;
    ISystemBase(ISystemBase&&) noexcept = default;
    ISystemBase& operator=(const ISystemBase&) = default;
    ISystemBase& operator=(ISystemBase&&) noexcept = default;

    virtual ~ISystemBase() = default;

    // 获取系统类型
    [[nodiscard]] virtual std::type_index GetTypeIndex() const = 0;

    // 获取系统名
    [[nodiscard]] virtual std::string GetName() const = 0;

    // 获取系统分组
    [[nodiscard]] virtual SystemGroup GetGroup() const = 0;

    // 获取系统优先级
    [[nodiscard]] virtual SystemPriority GetPriority() const = 0;

    // 初始化系统,系统注册时调用
    virtual void OnInitialize() = 0;

    // 反初始化系统,系统销毁时调用
    virtual void OnDeInitialize() = 0;

    // 系统更新
    virtual void OnUpdate(float deltaTime) = 0;

    // 系统是否激活
    [[nodiscard]] bool IsSystemActive() const
    {
        return IsActive;
    }

    // 设置系统激活状态
    void SetSystemActive(bool active)
    {
        IsActive = active;
    }

private:
    // 系统是否激活,默认激活
    bool IsActive = true;
};


} // namespace NekiraECS


namespace NekiraECS
{
// CRTP模板系统类，其他系统需要继承此类
template <typename T>
class System : public ISystemBase
{
    friend T;

public:
    // 获取系统类型
    [[nodiscard]] std::type_index GetTypeIndex() const override
    {
        return std::type_index(typeid(T));
    }

    // 获取系统名字
    [[nodiscard]] std::string GetName() const override
    {
        return typeid(T).name();
    }

    // 获取系统分组，默认为Update
    [[nodiscard]] SystemGroup GetGroup() const override
    {
        return SYSTEM_GROUP_DEFAULT;
    }

    // 获取系统优先级，默认为0
    [[nodiscard]] SystemPriority GetPriority() const override
    {
        return SYSTEM_PRIORITY_DEFAULT;
    }

    // 初始化系统,系统注册时调用
    void OnInitialize() override
    {}

    // 反初始化系统,系统销毁时调用
    void OnDeInitialize() override
    {}

    // 系统更新
    void OnUpdate(float deltaTime) override
    {}

private:
    System() = default;
    System(const System&) = default;
    System& operator=(const System&) = default;
    System(System&&) noexcept = default;
    System& operator=(System&&) noexcept = default;

    virtual ~System() = default;
};
} // namespace NekiraECS
