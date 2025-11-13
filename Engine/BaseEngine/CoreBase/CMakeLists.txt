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
# 导出宏
# ======================================
target_compile_definitions(CoreBase INTERFACE COREBASE_EXPORT)

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

