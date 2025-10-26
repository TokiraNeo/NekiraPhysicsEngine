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

#include <NekiraDelegate/SignalSlot/SignalType.hpp>


namespace NekiraDelegate
{
// 单播委托
template <typename RT, typename... Args>
class Delegate final
{
private:
    // 单播信号实例
    std::unique_ptr<SingleSignal<RT, Args...>> Signal;

public:
    Delegate() : Signal(std::make_unique<SingleSignal<RT, Args...>>())
    {}

    ~Delegate()
    {
        RemoveBinding();
        Signal.reset();
    }

    Delegate(const Delegate&) = delete;
    Delegate(Delegate&& other) noexcept : Signal(std::move(other.Signal))
    {}

    Delegate& operator=(const Delegate&) = delete;
    Delegate& operator=(Delegate&& other) noexcept
    {
        if (this != &other)
        {
            Signal = std::move(other.Signal);
        }
        return *this;
    }

    // 是否有效
    [[nodiscard]] bool IsValid() const
    {
        return Signal && Signal->IsValid();
    }

    // 执行连接的回调
    RT Invoke(Args&&... args)
    {
        return IsValid() ? Signal->Invoke(std::forward<Args>(args)...) : RT{};
    }

    // 断开连接
    void RemoveBinding()
    {
        if (Signal)
        {
            Signal->Disconnect();
        }
    }

    // 绑定普通函数
    void BindFunction(RT (*FuncPtr)(Args...))
    {
        if (Signal)
        {
            Signal->Connect(FuncPtr);
        }
    }

    // 绑定普通成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    void BindMemberFunction(ClassType* Object, RT (ClassType::*FuncPtr)(Args...))
    {
        if (Signal)
        {
            Signal->Connect(Object, FuncPtr);
        }
    }

    // 绑定const成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    void BindMemberFunction(const ClassType* Object, RT (ClassType::*FuncPtr)(Args...) const)
    {
        if (Signal)
        {
            Signal->Connect(Object, FuncPtr);
        }
    }

    // 绑定函数对象，lambda表达式
    template <typename Callable>
        requires std::is_invocable_r_v<RT, Callable, Args...>
    void BindFunctionObject(Callable&& Func)
    {
        if (Signal)
        {
            Signal->Connect(std::forward<Callable>(Func));
        }
    }
};
} // namespace NekiraDelegate



namespace NekiraDelegate
{
// 多播委托
template <typename... Args>
class MultiDelegate final
{
private:
    // 多播信号实例
    std::unique_ptr<MultiSignal<Args...>> Signal;

public:
    MultiDelegate() : Signal(std::make_unique<MultiSignal<Args...>>())
    {}
    ~MultiDelegate()
    {
        RemoveAll();
        Signal.reset();
    }

    MultiDelegate(const MultiDelegate&) = delete;
    MultiDelegate(MultiDelegate&& other) noexcept : Signal(std::move(other.Signal))
    {}

    MultiDelegate& operator=(const MultiDelegate&) = delete;
    MultiDelegate& operator=(MultiDelegate&& other) noexcept
    {
        if(this != &other)
        {
            Signal = std::move(other.Signal);
        }
        return *this;
    }

    // 是否有效
    [[nodiscard]] bool IsValid() const
    {
        return Signal && Signal->IsValid();
    }

    // 执行连接的回调
    void Invoke(Args&&... args)
    {
        if (IsValid())
        {
            Signal->Invoke(std::forward<Args>(args)...);
        }
    }

    // 断开特定连接
    void RemoveSingle(const MultiSignalHandle& Handler)
    {
        if (Signal)
        {
            Signal->DisconnectSingle(Handler);
        }
    }

    // 断开所有连接
    void RemoveAll()
    {
        if (Signal)
        {
            Signal->DisconnectAll();
        }
    }

    // 连接普通函数
    MultiSignalHandle BindFunction(void (*FuncPtr)(Args...))
    {
        return Signal ? Signal->Connect(FuncPtr) : MultiSignalHandle{};
    }

    // 连接普通成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    MultiSignalHandle BindMemberFunction(ClassType* Object, void (ClassType::*FuncPtr)(Args...))
    {
        return Signal ? Signal->Connect(Object, FuncPtr) : MultiSignalHandle{};
    }

    // 连接const成员函数,要求继承 IConnectionInterface接口
    template <typename ClassType>
        requires std::is_base_of_v<IConnectionInterface, ClassType>
    MultiSignalHandle BindMemberFunction(const ClassType* Object, void (ClassType::*FuncPtr)(Args...) const)
    {
        return Signal ? Signal->Connect(Object, FuncPtr) : MultiSignalHandle{};
    }

    // 连接函数对象，lambda表达式
    template <typename Callable>
        requires std::is_invocable_r_v<void, Callable, Args...>
    MultiSignalHandle BindFunctionObject(Callable&& Func)
    {
        return Signal ? Signal->Connect(std::forward<Callable>(Func)) : MultiSignalHandle{};
    }
};
} // namespace NekiraDelegate
