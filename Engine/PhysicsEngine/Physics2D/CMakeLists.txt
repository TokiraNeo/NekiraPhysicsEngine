# ======================================
# Physics2D 模块
# ======================================

# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE HEADER_FILES "Public/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "Private/*.cpp")

# ======================================
# 生成库
# ======================================
add_library(Physics2D SHARED ${HEADER_FILES} ${SOURCE_FILES})

# ======================================
# 导出宏
# ======================================
target_compile_definitions(Physics2D
    PRIVATE
        PHYSICS2D_EXPORT
)

# ======================================
# 头文件目录
# ======================================
target_include_directories(Physics2D
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

# ======================================
# 依赖模块
# ======================================
target_link_libraries(Physics2D
    PUBLIC

    PRIVATE
        PhysicsBase
)