# ======================================
# Root
# ======================================
cmake_minimum_required(VERSION 3.20)
project(NekiraPhysicsEngine LANGUAGES CXX VERSION 1.0.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ======================================
# 设置符号可见性为默认隐藏
# ======================================
#set(CMAKE_CXX_VISIBILITY_PRESET hidden)
#set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

# ======================================
# 子目录
# ======================================
add_subdirectory(ThirdParty)
add_subdirectory(Engine)
add_subdirectory(Main)