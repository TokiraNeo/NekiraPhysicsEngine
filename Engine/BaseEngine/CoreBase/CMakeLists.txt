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
add_library(CoreBase INTERFACE ${HEADER_FILES})

# ======================================
# 头文件目录
# ======================================
target_include_directories(CoreBase
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

target_link_libraries(CoreBase
    INTERFACE
        
)

# ======================================
# 构建输出
# ======================================
set_target_properties(CoreBase PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)