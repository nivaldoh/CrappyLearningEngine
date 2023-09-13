add_library(EngineLib STATIC)
target_sources(EngineLib PRIVATE
    Engine.cpp
    Engine.h
)

target_include_directories(EngineLib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(EngineLauncher Launch.cpp)
target_link_libraries(EngineLauncher PRIVATE EngineLib)

find_package(Vulkan 1.3.261 REQUIRED)
target_link_libraries(EngineLib PRIVATE Vulkan::Vulkan)

find_package(glfw3 3.3 CONFIG REQUIRED)
target_link_libraries(EngineLib PRIVATE glfw)