# ======================================
# Math 模块
# ======================================

find_package(EASTL CONFIG REQUIRED)

# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE HEADER_FILES "Public/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "Private/*.cpp")

# ======================================
# 生成库
# ======================================
add_library(Math STATIC ${HEADER_FILES} ${SOURCE_FILES})

# ======================================
# 头文件目录
# ======================================
target_include_directories(Math
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

# ======================================
# 构建输出
# ======================================
set_target_properties(Math PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# ======================================
# 依赖模块
# ======================================
target_link_libraries(Math
    PUBLIC
        EASTL
        CoreBase
    PRIVATE

)