/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraECS/Core/Component/ComponentArray.hpp>
#include <unordered_map>
#include <utility>


namespace NekiraECS
{
// 组件管理器
class ComponentManager final
{
public:
    static ComponentManager& Get();

    // 添加组件
    template <typename T, typename... Args>
        requires std::is_base_of_v<Component<T>, T>
    void AddComponent(EntityIndexType entityIndex, Args&&... args)
    {
        auto compTypeIndex = std::type_index(typeid(T));

        // 如果该类型的组件数组不存在，则创建一个新的
        if (!ComponentArrays.contains(compTypeIndex))
        {
            auto handle = MakeComponentArrayHandle<T>();
            ComponentArrays[compTypeIndex] = std::move(handle);
        }

        auto* compArray = ComponentArrays[compTypeIndex].As<T>();

        compArray->AddComponent(entityIndex, std::forward<Args>(args)...);
    }

    // 获取组件，如果不存在或实体无效则返回nullptr
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    T* GetComponent(EntityIndexType entityIndex)
    {
        auto compTypeIndex = std::type_index(typeid(T));

        if (!ComponentArrays.contains(compTypeIndex))
        {
            return nullptr;
        }

        auto* compArray = ComponentArrays[compTypeIndex].As<T>();

        return compArray->GetComponent(entityIndex);
    }

    // 是否拥有该组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    [[nodiscard]] bool HasComponent(EntityIndexType entityIndex)
    {
        auto compTypeIndex = std::type_index(typeid(T));

        if (!ComponentArrays.contains(compTypeIndex))
        {
            return false;
        }

        return ComponentArrays[compTypeIndex]->HasComponent(entityIndex);
    }

    // 移除Entity的某个组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    void RemoveComponent(EntityIndexType entityIndex)
    {
        auto compTypeIndex = std::type_index(typeid(T));

        if (!ComponentArrays.contains(compTypeIndex))
        {
            return;
        }

        ComponentArrays[compTypeIndex]->RemoveComponent(entityIndex);
    }

    // 移除特定组件的组件数组
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    void RemoveComponentArray()
    {
        auto compTypeIndex = std::type_index(typeid(T));

        if (ComponentArrays.contains(compTypeIndex))
        {
            ComponentArrays.erase(compTypeIndex);
        }
    }

    // 获取特定组件类型的组件数组
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    ComponentArray<T>* GetComponentArray()
    {
        auto compTypeIndex = std::type_index(typeid(T));

        if (!ComponentArrays.contains(compTypeIndex))
        {
            return nullptr;
        }

        return ComponentArrays[compTypeIndex].As<T>();
    }

    // 移除Entity的所有组件
    void RemoveEntityAllComponents(EntityIndexType entityIndex);

    // 回调访问特定类型的所有组件
    template <typename T>
        requires std::is_base_of_v<Component<T>, T>
    void ForEachComponent(const std::function<void(T&)>& callback)
    {
        auto compType = std::type_index(typeid(T));

        if (!ComponentArrays.contains(compType))
        {
            return;
        }

        auto* compArray = ComponentArrays[compType].As<T>();

        compArray->ForEachComponent(callback);
    }

private:
    ComponentManager() = default;
    ~ComponentManager() = default;

    ComponentManager(const ComponentManager&) = delete;
    ComponentManager(ComponentManager&&) noexcept = delete;

    ComponentManager& operator=(const ComponentManager&) = delete;
    ComponentManager& operator=(ComponentManager&&) noexcept = delete;

    // 每种组件类型对应的组件数组
    std::unordered_map<std::type_index, ComponentArrayHandle> ComponentArrays;
};
} // namespace NekiraECS