# ======================================
# Core 模块
# ======================================


# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE CORE_HEADER_FILES Public/*.hpp)
file(GLOB_RECURSE CORE_SOURCE_FILES Private/*.cpp)

# ======================================
# 生成库
# ======================================
add_library(Core STATIC ${CORE_HEADER_FILES} ${CORE_SOURCE_FILES})

# ======================================
# 头文件目录
# ======================================
target_include_directories(Core
        PUBLIC Public
        PRIVATE Private
)

