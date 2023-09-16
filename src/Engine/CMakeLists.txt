add_executable(EngineMain Launch.cpp)

set(ENGINE_CORE_SOURCES
    Engine.cpp
    #Engine.h
)

target_sources(EngineMain PRIVATE
    ${ENGINE_CORE_SOURCES}
 #"PlatformLayer/PlatformLayer.h" "PlatformLayer/GLFWWrapper.cpp" "PlatformLayer/GLFWWrapper.h"
)

target_link_libraries(EngineMain PRIVATE PlatformLayer)


 target_include_directories(EngineMain PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    PlatformLayer
)

add_subdirectory(PlatformLayer)

target_link_libraries(EngineMain PRIVATE Vulkan::Vulkan)
# TODO: enable static vs dynamic linking in the build system
set(GLFW_VULKAN_STATIC ON)

#find_package(glfw3 3.3 CONFIG REQUIRED)
target_link_libraries(EngineMain PRIVATE glfw)

target_link_libraries(EngineMain PRIVATE glm::glm)