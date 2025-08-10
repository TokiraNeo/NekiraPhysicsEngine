# ======================================
# 主程序入口
# ======================================
add_executable(NekiraPhysics2D NekiraPhysics2D.cpp)

# ======================================
# 依赖
# ======================================
target_link_libraries(NekiraPhysics2D
        PRIVATE
        Core
)

# ======================================
# 构建输出
# ======================================
set_target_properties(NekiraPhysics2D PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)


