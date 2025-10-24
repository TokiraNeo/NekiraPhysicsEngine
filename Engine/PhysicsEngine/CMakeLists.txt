# ======================================
# PhysicsEngine/CMakeLists.txt
# ======================================

# 添加PhysicsEngine的子模块列表
set(PhysicsEngine_ModuleList

)

# 依次添加子模块的头文件目录，并添加子模块目标
set(PhysicsEngine_Modules "")
foreach(module ${PhysicsEngine_ModuleList})
    list(APPEND PhysicsEngine_Modules ${module})
    add_subdirectory(${module})
endforeach()

# 定义PhysicsEngine目标
add_custom_target(PhysicsEngine)
add_dependencies(PhysicsEngine ${PhysicsEngine_Modules})