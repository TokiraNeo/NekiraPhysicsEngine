cmake_minimum_required(VERSION 3.29)
project(NekiraPhysics2D LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

# ======================================
# 子目录
# ======================================
add_subdirectory(Main)
add_subdirectory(Engine)
add_subdirectory(ThirdParty)

