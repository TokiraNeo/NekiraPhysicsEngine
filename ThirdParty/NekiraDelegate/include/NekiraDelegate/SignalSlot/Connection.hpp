/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <functional>
#include <memory>
#include <utility>
#include <vector>


namespace NekiraDelegate
{

// 基础的连接器，只暴露断开连接与检查连接有效性的接口
class ConnectionBase
{
public:
    virtual ~ConnectionBase() = default;

    // 连接是否有效
    virtual bool IsValid() const = 0;

    // 断开连接
    virtual void Disconnect() = 0;
};

} // namespace NekiraDelegate


namespace NekiraDelegate
{

// 模板连接器的默认实现
template <typename RT, typename... Args>
class Connection : public ConnectionBase
{
private:
    // 使用 std::function 来存储连接的回调
    // @[INFO] 当然，也可以使用类型擦除来自定义回调存储方式，这里先使用 std::function 简化实现
    std::function<RT(Args...)> Callback;

    // 是否有效的标志
    bool bIsValidConnected;

public:
    Connection() = default;
    virtual ~Connection() = default;

    Connection(std::function<RT(Args...)> InCallback) : Callback(std::move(InCallback)), bIsValidConnected(true)
    {}

    // 检查连接是否有效
    bool IsValid() const override
    {
        return bIsValidConnected && Callback != nullptr;
    }

    // 断开连接
    void Disconnect() override
    {
        bIsValidConnected = false;
        Callback = nullptr;
    }

    // 调用连接的回调
    RT Invoke(Args&&... args)
    {
        return IsValid() ? Callback(std::forward<Args>(args)...) : RT{};
    }
};

} // namespace NekiraDelegate

namespace NekiraDelegate
{

// 连接器接口，继承此接口以获得对连接器的自动管理
class IConnectionInterface
{
private:
    // 存储连接的容器
    mutable std::vector<std::weak_ptr<ConnectionBase>> Connections;

public:
    IConnectionInterface() = default;

    virtual ~IConnectionInterface()
    {
        // 在析构时清理所有连接
        DisconnectAll();
    }

    // 添加连接.这里使用const是为了确保即便对象是const类型也能正常添加连接，对连接器的自动管理不受影响
    void AddConnection(std::shared_ptr<ConnectionBase> InConnection) const;

    // 断开所有连接.这里的const同上，确保即便对象是const类型也能正常断开连接
    void DisconnectAll() const;
};

} // namespace NekiraDelegate