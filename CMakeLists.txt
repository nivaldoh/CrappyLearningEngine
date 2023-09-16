cmake_minimum_required(VERSION 3.7)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
    CACHE STRING "Vcpkg toolchain file")

project(Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: this should be conditional depending on build config
find_package(glfw3 3.3 CONFIG REQUIRED)
find_package(Vulkan 1.3.261 REQUIRED)
# TODO: enable static vs dynamic linking in the build system
set(GLFW_VULKAN_STATIC ON)
# TODO: set GLM version here to match the version used by Vulkan?
find_package(glm CONFIG REQUIRED)

add_subdirectory(src/Engine)