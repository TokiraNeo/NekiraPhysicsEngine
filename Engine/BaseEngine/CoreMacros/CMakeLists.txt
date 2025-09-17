# ======================================
# CoreMacros 模块
# ======================================

# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE HEADER_FILES "Public/*.hpp")
#file(GLOB_RECURSE SOURCE_FILES "Private/*.cpp")

# ======================================
# 生成库
# ======================================
add_library(CoreMacros INTERFACE ${HEADER_FILES})

# ======================================
# 头文件目录
# ======================================
target_include_directories(CoreMacros
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

# ======================================
# 构建输出
# ======================================
set_target_properties(CoreMacros PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)