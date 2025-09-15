# ======================================
# Math 模块
# ======================================


# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE CORE_HEADER_FILES Public/*.hpp)
file(GLOB_RECURSE CORE_SOURCE_FILES Private/*.cpp)

# ======================================
# 生成库
# ======================================
add_library(Math STATIC ${CORE_HEADER_FILES} ${CORE_SOURCE_FILES})

# ======================================
# 头文件目录
# ======================================
target_include_directories(Math PUBLIC Public)

# ======================================
# 构建输出
# ======================================
set_target_properties(Math PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)