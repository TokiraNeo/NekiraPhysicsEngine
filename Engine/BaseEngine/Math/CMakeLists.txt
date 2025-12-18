# ======================================
# Math 模块
# ======================================


# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE HEADER_FILES "Public/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "Private/*.cpp")

# ======================================
# 生成库
# ======================================
add_library(Math SHARED ${HEADER_FILES} ${SOURCE_FILES})

# ======================================
# 导出宏
# ======================================
target_compile_definitions(Math PRIVATE MATH_EXPORT)

# ======================================
# 头文件目录
# ======================================
target_include_directories(Math
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

# ======================================
# 依赖模块
# ======================================
target_link_libraries(Math
    PUBLIC
        CoreBase
)