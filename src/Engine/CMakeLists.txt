add_executable(EngineMain Launch.cpp)

set(ENGINE_CORE_SOURCES
    Engine.cpp
)

target_sources(EngineMain PRIVATE
    ${ENGINE_CORE_SOURCES}
)

target_link_libraries(EngineMain PRIVATE PlatformLayer)
target_link_libraries(EngineMain PRIVATE GraphicsAPI)


 target_include_directories(EngineMain PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    PlatformLayer
    GraphicsAPI
)

add_subdirectory(PlatformLayer)
add_subdirectory(GraphicsAPI)

#target_link_libraries(EngineMain PRIVATE Vulkan::Vulkan)
# TODO: enable static vs dynamic linking in the build system
#set(GLFW_VULKAN_STATIC ON)

target_link_libraries(EngineMain PRIVATE glfw)

target_link_libraries(EngineMain PRIVATE glm::glm)