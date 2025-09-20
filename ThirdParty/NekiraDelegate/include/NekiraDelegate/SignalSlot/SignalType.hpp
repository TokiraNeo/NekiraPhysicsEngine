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

#include <NekiraDelegate/SignalSlot/Connection.hpp>
#include <algorithm>
#include <functional>
#include <memory>
#include <type_traits>
#include <vector>



namespace NekiraDelegate
{
// 单播信号类
template <typename RT, typename... Args>
class SingleSignal
{
private:
    // 当前连接器
    std::shared_ptr<Connection<RT, Args...>> ConnectionPtr;

public:
    SingleSignal() = default;

    // 是否有效的连接
    bool IsValid() const
    {
        return ConnectionPtr && ConnectionPtr->IsValid();
    }

    // 执行连接的回调
    RT Invoke(Args&&... args)
    {
        return IsValid() ? ConnectionPtr->Invoke(std::forward<Args>(args)...) : RT{};
    }

    // 断开连接
    void Disconnect()
    {
        if (ConnectionPtr)
        {
            ConnectionPtr->Disconnect();
            ConnectionPtr.reset();
        }
    }

    // 连接普通函数
    void Connect(RT (*FuncPtr)(Args...))
    {
        std::function<RT(Args...)> Func = FuncPtr;
        ConnectionPtr = std::make_shared<Connection<RT, Args...>>(std::move(Func));
    }

    // 连接普通成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    void Connect(ClassType* Object, RT (ClassType::*FuncPtr)(Args...))
    {
        auto Lambda = [Object, FuncPtr](Args&&... args) -> RT
        { return (Object->*FuncPtr)(std::forward<Args>(args)...); };

        std::function<RT(Args...)> Func = Lambda;

        ConnectionPtr = std::make_shared<Connection<RT, Args...>>(std::move(Func));

        // 添加连接到对象的连接接口
        static_cast<IConnectionInterface*>(Object)->AddConnection(ConnectionPtr);
    }

    // 连接const成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    void Connect(const ClassType* Object, RT (ClassType::*FuncPtr)(Args...) const)
    {
        auto Lambda = [Object, FuncPtr](Args&&... args) -> RT
        { return (Object->*FuncPtr)(std::forward<Args>(args)...); };

        std::function<RT(Args...)> Func = Lambda;

        ConnectionPtr = std::make_shared<Connection<RT, Args...>>(std::move(Func));

        // 添加连接到对象的连接接口
        static_cast<const IConnectionInterface*>(Object)->AddConnection(ConnectionPtr);
    }

    // 连接函数对象、lambda表达式
    template <typename Callable>
        requires std::is_invocable_r_v<RT, Callable, Args...>
    void Connect(Callable&& CallableObj)
    {
        std::function<RT(Args...)> Func = std::forward<Callable>(CallableObj);

        ConnectionPtr = std::make_shared<Connection<RT, Args...>>(std::move(Func));
    }
};

} // namespace NekiraDelegate



namespace NekiraDelegate
{
// 用于移除多播信号类中的特定连接
struct MultiSignalHandle
{
    bool operator==(const MultiSignalHandle& Other) const
    {
        return SignalPtr == Other.SignalPtr && Id == Other.Id;
    }

    bool operator!=(const MultiSignalHandle& Other) const
    {
        return !(*this == Other);
    }

    void*       SignalPtr; // 指向多播信号的指针
    std::size_t Id;        // 连接的唯一标识符
};
} // namespace NekiraDelegate


namespace NekiraDelegate
{

// 多播信号类
template <typename... Args>
class MultiSignal
{
private:
    using ConnectionType = Connection<void, Args...>;
    using ConnectionPair = std::pair<MultiSignalHandle, std::shared_ptr<ConnectionType>>;

    // 存储连接器
    std::vector<ConnectionPair> ConnectionMap;

    std::size_t NextId = 0; // 用于生成唯一的连接ID

public:
    MultiSignal() = default;

    // 是否有效
    bool IsValid() const
    {
        return !ConnectionMap.empty();
    }

    // 执行所有连接的回调
    void Invoke(Args&&... args)
    {
        // 清理无效连接
        Cleanup();

        for (auto& Pair : ConnectionMap)
        {
            Pair.second->Invoke(std::forward<Args>(args)...);
        }
    }

    // 断开特定连接
    void DisconnectSingle(const MultiSignalHandle& Handle)
    {
        const auto It = std::remove_if(ConnectionMap.begin(), ConnectionMap.end(),
                                       [&Handle](const ConnectionPair& Pair) { return Pair.first == Handle; });

        if (It != ConnectionMap.end())
        {
            if (It->second)
            {
                It->second->Disconnect();
            }
            ConnectionMap.erase(It, ConnectionMap.end());
        }
    }

    // 断开所有连接
    void DisconnectAll()
    {
        for (auto& Pair : ConnectionMap)
        {
            if (Pair.second)
            {
                Pair.second->Disconnect();
            }
        }

        ConnectionMap.clear();
    }

    // 连接普通函数
    MultiSignalHandle Connect(void (*FuncPtr)(Args...))
    {
        std::function<void(Args...)> Func = FuncPtr;
        auto                         NewConnection = std::make_shared<ConnectionType>(std::move(Func));

        MultiSignalHandle Handler{this, ++NextId};

        ConnectionPair Pair{Handler, std::move(NewConnection)};

        ConnectionMap.push_back(std::move(Pair));

        return Handler;
    }

    // 连接普通成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    MultiSignalHandle Connect(ClassType* Object, void (ClassType::*FuncPtr)(Args...))
    {
        auto Lambda = [Object, FuncPtr](Args&&... args) { (Object->*FuncPtr)(std::forward<Args>(args)...); };

        std::function<void(Args...)> Func = Lambda;

        auto NewConnection = std::make_shared<ConnectionType>(std::move(Func));

        // 添加连接到对象的连接接口
        static_cast<IConnectionInterface*>(Object)->AddConnection(NewConnection);

        MultiSignalHandle Handler{this, ++NextId};

        ConnectionPair Pair{Handler, std::move(NewConnection)};

        ConnectionMap.push_back(std::move(Pair));

        return Handler;
    }

    // 连接const成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    MultiSignalHandle Connect(const ClassType* Object, void (ClassType::*FuncPtr)(Args...) const)
    {
        auto Lambda = [Object, FuncPtr](Args&&... args) { (Object->*FuncPtr)(std::forward<Args>(args)...); };

        std::function<void(Args...)> Func = Lambda;

        auto NewConnection = std::make_shared<ConnectionType>(std::move(Func));

        // 添加连接到对象的连接接口
        static_cast<const IConnectionInterface*>(Object)->AddConnection(NewConnection);

        MultiSignalHandle Handler{this, ++NextId};

        ConnectionPair Pair{Handler, std::move(NewConnection)};

        ConnectionMap.push_back(std::move(Pair));

        return Handler;
    }

    // 连接函数对象、lambda表达式
    template <typename Callable>
        requires std::is_invocable_r_v<void, Callable, Args...>
    MultiSignalHandle Connect(Callable&& CallableObj)
    {
        std::function<void(Args...)> Func = std::forward<Callable>(CallableObj);

        auto NewConnection = std::make_shared<ConnectionType>(std::move(Func));

        MultiSignalHandle Handler{this, ++NextId};

        ConnectionPair Pair{Handler, std::move(NewConnection)};

        ConnectionMap.push_back(std::move(Pair));

        return Handler;
    }

private:
    // 清理无效的连接
    void Cleanup()
    {
        const auto It = std::remove_if(ConnectionMap.begin(), ConnectionMap.end(),
                                       [](const auto& Pair) { return !Pair.second || !Pair.second->IsValid(); });

        ConnectionMap.erase(It, ConnectionMap.end());
    }
};

} // namespace NekiraDelegate