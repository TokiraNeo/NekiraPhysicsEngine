# ======================================
# BaseEngine/CMakeLists.txt
# ======================================

# 添加BaseEngine的子模块列表
set(BaseEngine_ModuleList
    CoreBase
    Core
    Math
)

# 依次添加子模块的头文件目录，并添加子模块目标
set(BaseEngine_Modules "")
foreach(module ${BaseEngine_ModuleList})
    list(APPEND BaseEngine_Modules ${module})
    add_subdirectory(${module})
endforeach()

# 定义BaseEngine目标
add_custom_target(BaseEngine)
add_dependencies(BaseEngine ${BaseEngine_Modules})