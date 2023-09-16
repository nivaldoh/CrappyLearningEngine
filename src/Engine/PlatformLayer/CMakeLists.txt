add_library(PlatformLayer STATIC 
    GLFWWrapper.cpp
)

target_include_directories(PlatformLayer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PlatformLayer PUBLIC glfw)