/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For full license information, please view the LICENSE file in the root directory of this project.
 */

#pragma once

#include <NekiraECS/Core/Primary/PrimaryType.hpp>
#include <typeindex>



namespace NekiraECS
{

// 组件接口基类
class IComponentBase
{
public:
    IComponentBase() = default;
    IComponentBase(const IComponentBase&) = default;
    IComponentBase(IComponentBase&&) noexcept = default;
    IComponentBase& operator=(const IComponentBase&) = default;
    IComponentBase& operator=(IComponentBase&&) noexcept = default;

    virtual ~IComponentBase() = default;

    virtual std::type_index GetTypeIndex() = 0;
};


// CRTP模板组件类，其他的组件类通过继承该类来实现
template <typename T>
class Component : public IComponentBase
{
    friend T;

public:
    std::type_index GetTypeIndex() override
    {
        return std::type_index(typeid(T));
    }

private:
    Component() = default;
    Component(const Component&) = default;
    Component& operator=(const Component&) = default;
    Component(Component&&) noexcept = default;
    Component& operator=(Component&&) noexcept = default;

    virtual ~Component() = default;
};

} // namespace NekiraECS
