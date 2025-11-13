# ======================================
# Core 模块
# ======================================

find_package(NekiraDelegateLib CONFIG REQUIRED)

# ======================================
# 头文件、源文件
# ======================================
file(GLOB_RECURSE CORE_HEADER_FILES "Public/*.hpp")
file(GLOB_RECURSE CORE_SOURCE_FILES "Private/*.cpp")

# ======================================
# 生成库
# ======================================
add_library(Core SHARED ${CORE_HEADER_FILES} ${CORE_SOURCE_FILES})

# ======================================
# 导出宏
# ======================================
target_compile_definitions(Core PRIVATE CORE_EXPORT)

# ======================================
# 头文件目录
# ======================================
target_include_directories(Core PUBLIC Public)

# ======================================
# 依赖
# ======================================
target_link_libraries(Core
    PUBLIC
        NekiraDelegateLib::DelegateCore
        Math
    PRIVATE
)

