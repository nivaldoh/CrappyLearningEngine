add_library(GraphicsAPI STATIC 
    VulkanWrapper.cpp
)

target_include_directories(GraphicsAPI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(GraphicsAPI PRIVATE Vulkan::Vulkan)