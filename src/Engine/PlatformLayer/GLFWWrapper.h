#pragma once

#include "PlatformLayer.h"
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

class GLFWWrapper : public IPlatformLayer {
public:
    static GLFWWrapper& GetInstance();

    virtual bool Initialize() override;
    virtual void Shutdown() override;

    // Vulkan
    // TODO: create macro and maybe set this in the interface
    VkResult CreateWindowSurface(
        VkInstance 	instance,
        const VkAllocationCallbacks* allocator,
        VkSurfaceKHR* surface);
    void GetFramebufferSize(int* width, int* height);

    virtual void SetWindowTitle(const std::string& title) override;
    virtual void SetWindowState(WindowState state) override;

    virtual void PollEvents() override;
    virtual bool ShouldCloseWindow() override;
    //virtual void RegisterEventListener(std::shared_ptr<Event> listener) override;

private:
    GLFWWrapper() = default;
    virtual ~GLFWWrapper() override;
    GLFWWrapper(GLFWWrapper const&) = delete;
    void operator=(GLFWWrapper const&) = delete;

    // std::shared_ptr<Event> eventListener;
    
    GLFWwindow* window;
    std::string windowTitle;
    WindowState windowState;
};
