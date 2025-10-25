/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraECS/Core/System/System.hpp>
#include <memory>
#include <typeindex>
#include <vector>



namespace NekiraECS
{

// 系统容器，存储某个分组的所有系统
class SystemContainer final
{
public:
    SystemContainer() = default;

    // 添加系统
    void AddSystem(std::unique_ptr<ISystemBase> system);

    // 移除系统
    void RemoveSystem(std::type_index type);

    [[nodiscard]] ISystemBase* GetSystem(std::type_index type) const;

    // 拓扑排序
    void SortingSystems();

    // 获取所有系统
    [[nodiscard]] const std::vector<std::unique_ptr<ISystemBase>>& GetAllSystems() const;

private:
    bool IsSorted = false;

    std::vector<std::unique_ptr<ISystemBase>> Systems;
};


// 系统容器句柄，提供对系统容器的访问
struct SystemContainerHandle final
{
    SystemContainerHandle() : Container(std::make_unique<SystemContainer>())
    {}

    SystemContainerHandle(const SystemContainerHandle&) = delete;
    SystemContainerHandle& operator=(const SystemContainerHandle&) = delete;

    SystemContainerHandle(SystemContainerHandle&& other) noexcept
    {
        if (this != &other)
        {
            Container = std::move(other.Container);
        }
    }

    SystemContainerHandle& operator=(SystemContainerHandle&& other) noexcept
    {
        if (this != &other)
        {
            Container = std::move(other.Container);
        }
        return *this;
    }

    ~SystemContainerHandle() = default;

    SystemContainer* operator->()
    {
        return Container.get();
    }

private:
    std::unique_ptr<SystemContainer> Container;
};

} // namespace NekiraECS