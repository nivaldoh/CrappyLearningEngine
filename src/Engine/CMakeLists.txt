add_executable(EngineMain Launch.cpp)
target_sources(EngineMain PRIVATE
    Engine.cpp
    Engine.h
 "PlatformLayer/PlatformLayer.h" "PlatformLayer/GLFWWrapper.cpp" "PlatformLayer/GLFWWrapper.h")
 target_include_directories(EngineMain PUBLIC
    PlatformLayer
)

find_package(Vulkan 1.3.261 REQUIRED)
target_link_libraries(EngineMain PRIVATE Vulkan::Vulkan)
# TODO: enable static vs dynamic linking in the build system
set(GLFW_VULKAN_STATIC ON)

find_package(glfw3 3.3 CONFIG REQUIRED)
target_link_libraries(EngineMain PRIVATE glfw)

# TODO: set GLM version here to match the version used by Vulkan?
find_package(glm CONFIG REQUIRED)
target_link_libraries(EngineMain PRIVATE glm::glm)