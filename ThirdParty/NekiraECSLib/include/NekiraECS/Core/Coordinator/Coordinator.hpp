/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once


#include <NekiraECS/Core/Component/ComponentManager.hpp>
#include <NekiraECS/Core/Entity/Entity.hpp>
#include <NekiraECS/Core/System/SystemManager.hpp>



namespace NekiraECS
{

// 协调器，负责协调实体、组件和系统
class Coordinator final
{
public:
    static Coordinator& Get();

    // ===============================
    // Entity Management
    // ===============================

    // 实体是否有效
    static bool CheckEntity(const Entity& entity);

    // 创建实体
    static Entity CreateEntity();

    // 销毁实体
    static void DestroyEntity(const Entity& entity);

    // 回调访问所有实体
    static void ForEachEntity(const std::function<void(const Entity&)>& callback);


    // ===============================
    // Component Management
    // ===============================

    // 添加组件
    template <typename T, typename... Args>
        requires std::is_base_of_v<Component<T>, T>
    static void AddComponent(const Entity& entity, Args&&... args)
    {
        if (CheckEntity(entity))
        {
            auto entityIndex = EntityManager::GetEntityIndex(entity);
            ComponentManager::Get().AddComponent<T>(entityIndex, std::forward<Args>(args)...);
        }
    }

    // 获取组件，如果不存在或实体无效则返回nullptr
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    static T* GetComponent(const Entity& entity)
    {
        if (!CheckEntity(entity))
        {
            return nullptr;
        }

        auto entityIndex = EntityManager::GetEntityIndex(entity);
        return ComponentManager::Get().GetComponent<T>(entityIndex);
    }

    // 是否拥有该组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    static bool HasComponent(const Entity& entity)
    {
        if (!CheckEntity(entity))
        {
            return false;
        }

        auto entityIndex = EntityManager::GetEntityIndex(entity);
        return ComponentManager::Get().HasComponent<T>(entityIndex);
    }

    // 移除Entity的某个组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    static void RemoveComponent(const Entity& entity)
    {
        if (CheckEntity(entity))
        {
            auto entityIndex = EntityManager::GetEntityIndex(entity);
            ComponentManager::Get().RemoveComponent<T>(entityIndex);
        }
    }

    // 移除Entity的所有组件
    static void RemoveEntityAllComponents(const Entity& entity);

    // 回调访问特定类型的所有组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    static void ForEachComponent(const std::function<void(T&)>& callback)
    {
        ComponentManager::Get().ForEachComponent<T>(callback);
    }

    // ===============================
    // System Management
    // ===============================

    // 更新所有系统
    static void UpdateSystems(float deltaTime);

    // 注册系统
    template <typename T, typename... Args>
        requires std::is_base_of_v<System<T>, T>
    static T* RegisterSystem(Args&&... args)
    {
        return SystemManager::Get().RegisterSystem<T>(std::forward<Args>(args)...);
    }

    // 是否存在某个系统
    template <typename T>
        requires std::is_base_of_v<System<T>, T>
    static bool HasSystem()
    {
        return SystemManager::Get().HasSystem<T>();
    }

    // 移除某个系统
    template <typename T>
        requires std::is_base_of_v<System<T>, T>
    static void RemoveSystem()
    {
        SystemManager::Get().RemoveSystem<T>();
    }

private:
    Coordinator() = default;
    ~Coordinator() = default;

    Coordinator(const Coordinator&) = delete;
    Coordinator(Coordinator&&) noexcept = delete;

    Coordinator& operator=(const Coordinator&) = delete;
    Coordinator& operator=(Coordinator&&) noexcept = delete;
};

} // namespace NekiraECS