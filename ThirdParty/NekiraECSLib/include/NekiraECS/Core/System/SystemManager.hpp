/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraECS/Core/System/SystemContainer.hpp>
#include <typeindex>
#include <unordered_map>



namespace NekiraECS
{

// 系统管理器
class SystemManager final
{
public:
    static SystemManager& Get();

private:
    SystemManager() = default;
    ~SystemManager() = default;

    SystemManager(const SystemManager&) = delete;
    SystemManager(SystemManager&&) noexcept = delete;

    SystemManager& operator=(const SystemManager&) = delete;
    SystemManager& operator=(SystemManager&&) noexcept = delete;

    // 系统分组映射
    std::unordered_map<SystemGroup, SystemContainerHandle> SystemGroups;

    // 需要重新排序的分组
    std::vector<SystemGroup> DirtyGroups;

    // 标记分组为脏，需要重新排序
    void MarkGroupDirty(SystemGroup group);

    // 对脏分组进行重新排序
    void SortSystemGroups();

    // 更新所有系统
    void UpdateSystemGroups(float deltaTime);

public:
    // 更新所有系统
    void Update(float deltaTime);

    // 注册系统
    template <typename T, typename... Args>
        requires std::is_base_of_v<System<T>, T>
    T* RegisterSystem(Args&&... args)
    {
        auto system = std::make_unique<T>(std::forward<Args>(args)...);
        T*   systemPtr = system.get();

        // 初始化系统
        system->OnInitialize();

        // 添加到对应分组
        SystemGroup group = system->GetGroup();
        if (!SystemGroups.contains(group))
        {
            SystemGroups[group] = SystemContainerHandle();
        }
        SystemGroups[group]->AddSystem(std::move(system));

        // 标记该分组需要重新排序
        MarkGroupDirty(group);

        return systemPtr;
    }

    // 是否存在某个系统
    template <typename T>
        requires std::is_base_of_v<System<T>, T>
    [[nodiscard]] bool HasSystem()
    {
        SystemGroup group = T().GetGroup();
        auto        type = std::type_index(typeid(T));

        return SystemGroups.contains(group) && SystemGroups[group]->GetSystem(type) != nullptr;
    }

    // 移除某个系统
    template <typename T>
        requires std::is_base_of_v<System<T>, T>
    void RemoveSystem()
    {
        /**
         * @[NOTE] 这里其实有点不是很优雅，既然都创建临时对象了，那其实都能直接通过这个临时对象调用OnDeInitialize()了
         * 这样做导致每次RemoveSystem都会创建一个临时对象，感觉不是很合理
         * 如果有动态反射的话，这里其实可以直接通过反射信息来得到group
         * 虽然我已经有了NekiraReflectionLib这个反射库，但将其引入到NekiraECS中，又只是在这里用一下，感觉也不是很合适
         * 而且即便引入NekiraReflectionLib,又需要规定外部在定义System时，需要按要求对其进行动态反射注册，这又增加了使用成本
         * 更何况。。。为什么外部一定要用我自己的NekiraReflectionLib呢🤣🤣🤣🤣🤣
         */
        SystemGroup group = T().GetGroup();

        auto type = std::type_index(typeid(T));

        if (!SystemGroups.contains(group))
        {
            return;
        }

        if (auto* system = SystemGroups[group]->GetSystem(type))
        {
            // 反初始化系统
            system->OnDeInitialize();

            SystemGroups[group]->RemoveSystem(type);

            // 标记该分组需要重新排序
            MarkGroupDirty(group);
        }
    }
};

} // namespace NekiraECS