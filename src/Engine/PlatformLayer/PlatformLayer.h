#pragma once

#include <string>
//#include <memory>

// TODO: abstract this
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

// TODO: modularize this?
enum class WindowState {
    MINIMIZED,
    MAXIMIZED,
    FULLSCREEN,
    WINDOWED
};

// TODO: add separate namespace?

class Event;

class IPlatformLayer {
public:
    bool framebufferResized;

    virtual ~IPlatformLayer() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;

    virtual void SetWindowTitle(const std::string& title) = 0;
    virtual void SetWindowState(WindowState state) = 0;

    virtual void WaitEvents() = 0;
    virtual void PollEvents() = 0;
    virtual bool ShouldCloseWindow() = 0;
    //virtual void RegisterEventListener(std::shared_ptr<Event> listener) = 0;

    // TODO: this shouldn't know about Vulkan
    virtual VkResult CreateWindowSurface(
        VkInstance 	instance,
        const VkAllocationCallbacks* allocator,
        VkSurfaceKHR* surface) = 0;
    virtual void GetFramebufferSize(int* width, int* height) = 0;
    // TODO: abstract window
    virtual void SetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback) = 0;
};

//std::unique_ptr<IPlatformLayer> CreatePlatformLayer();
