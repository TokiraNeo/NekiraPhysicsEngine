# Engine 目录

> [!Note]
> Engine 文件夹是整个引擎的主体部分，划分思想是根据不同引擎进行划分

> [!Important]
>
> #### 命名规范：
>
> - 所有引擎类的文件夹均以`Engine`结尾，例如`BaseEngine`、`PhysicsEngine`
> - 接口类均以`I`开头，例如`ICombatInterface`、`IPhysicsInterface`
> - 模板类均以`T`开头，例如`TBaseTemplate`、`TPhysicsTemplate`
> - 枚举类均以`E`开头，例如`ETriggerType`、`EPhysicsType`
> - 非模板结构体类均以`S`开头，例如`SBaseStruct`、`SPhysicsStruct`
> - 非模板类均以`C`开头，例如`CBaseClass`、`CPhysicsClass`

> [!Important]
>
> #### 命名空间：
>
> - 每个引擎类的命名空间为其缩写，例如`BaseEngine`的命名空间为`BE::`，`PhysicsEngine`的命名空间为`PhyE::`，可适当地自定义命名空间避免冲突。
> - 单个引擎类中的每个模块，其命名空间遵循 **引擎类命名空间+模块名** 的规则。例如`BaseEngine`中的`Math`模块，其命名空间为`BE::Math`
> - 每个模块内需要在外部频繁调用的，可以不使用命名空间，直接定义在全局作用域，但尽可能避免内部细节暴露。

## 摘要

- `BaseEngine`是基础引擎套件
- `PhysicsEngine`是物理引擎套件，主要负责物理相关的逻辑
- `RenderEngine`是渲染引擎套件，主要负责引擎界面的渲染、图形管线的渲染
