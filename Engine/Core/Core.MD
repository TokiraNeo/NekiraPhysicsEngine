# Core 模块

## 摘要
- Core 模块是物理引擎的底层核心，主要是提供数学计算的功能。
- 其他的模块都需要PRIVATE依赖于Core模块以获得反射能力。
- Core 模块PUBLIC依赖NekiraReflection模块，以获得反射能力。

## 目录



- [NekiraReflection] - NekiraReflection库，提供静态反射、动态反射、反射生成等功能。

- [NekiraReflectTool] - 反射生成器，主要负责反射代码生成。PRIVATE依赖于NekiraReflection库。

-  [Core] - 底层模块，PUBLIC依赖于NekiraReflection模块。
-  [其他模块] - 其他模块需要PRIVATE依赖于Core模块以获得反射能力。

- 每个模块通过各自的CMakeLists.txt文件进行配置，告知NekiraReflectTool如何生成反射代码。