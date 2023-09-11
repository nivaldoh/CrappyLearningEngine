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

find_package(Vulkan REQUIRED)
target_link_libraries(EngineLib PRIVATE Vulkan::Vulkan)