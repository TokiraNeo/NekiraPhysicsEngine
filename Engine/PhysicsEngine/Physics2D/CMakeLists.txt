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
# 头文件目录
# ======================================
target_include_directories(Physics2D
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

# ======================================
# 构建输出
# ======================================
set_target_properties(Physics2D PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# ======================================
# 依赖模块
# ======================================
target_link_libraries(Physics2D
    PUBLIC

    PRIVATE
        PhysicsBase
)