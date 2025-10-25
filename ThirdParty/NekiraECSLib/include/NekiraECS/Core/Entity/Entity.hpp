/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraECS/Core/Primary/PrimaryType.hpp>
#include <functional>
#include <stack>
#include <vector>


namespace NekiraECS
{

// 实体类
struct Entity final
{
    friend class EntityManager;

public:
    // 外部直接构建的为无效实体
    Entity() : ID(INVALID_ENTITYID)
    {}

    Entity(const Entity& other) = default;
    Entity(Entity&& other) noexcept = default;

    Entity& operator=(const Entity& other) = default;
    Entity& operator=(Entity&& other) noexcept = default;

    ~Entity() = default;

private:
    // 私有构造函数，仅允许EntityManager创建实体
    explicit Entity(EntityIDType id) : ID(id)
    {}

    // 实体的唯一标识符
    // 由索引和版本组成 (高16位为索引，低16位为版本)
    // [Index(16 bits) | Version(16 bits)]
    EntityIDType ID;
};

} // namespace NekiraECS



namespace NekiraECS
{

// 实体管理器单例
class EntityManager final
{
public:
    // 获取单例实例
    static EntityManager& Get();

    // 解析实体
    static void DecodeEntity(const Entity& entity, EntityIndexType& outIndex, EntityVersionType& outVersion);

    // 获取实体的索引
    static EntityIndexType GetEntityIndex(const Entity& entity);
    static EntityIndexType GetEntityIndex(EntityIDType entityID);

    // 获取实体的版本
    static EntityVersionType GetEntityVersion(const Entity& entity);
    static EntityVersionType GetEntityVersion(EntityIDType entityID);

    // 实体是否有效
    [[nodiscard]] bool IsValid(const Entity& entity) const;
    [[nodiscard]] bool IsValid(EntityIDType entityID) const;

    // 创建一个新实体
    Entity CreateEntity();

    // 销毁一个实体
    void DestroyEntity(const Entity& entity);

    // 获取所有有效的Entity
    [[nodiscard]] std::vector<Entity> GetAllEntities() const;

    // 回调访问所有有效实体
    void ForEachEntity(const std::function<void(const Entity&)>& callback) const;

private:
    EntityManager() = default;
    ~EntityManager() = default;

    EntityManager(const EntityManager& other) = delete;
    EntityManager(EntityManager&& other) noexcept = delete;

    EntityManager& operator=(const EntityManager& other) = delete;
    EntityManager& operator=(EntityManager&& other) noexcept = delete;

    // 每个实体的版本号 EntityIndex -> EntityVersion
    std::vector<EntityVersionType> EntityVersions;

    // 可复用的实体ID.版本号在回收时已做+1处理，因此可以直接复用
    std::stack<EntityIDType> RecycledIDs;
};

} // namespace NekiraECS