#pragma once

#include "PlatformLayer.h"
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

// TODO: improve
static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto inst = reinterpret_cast<IPlatformLayer*>(glfwGetWindowUserPointer(window));
    inst->framebufferResized = true;
}

class GLFWWrapper : public IPlatformLayer {
public:
    bool framebufferResized = false;

    static GLFWWrapper& GetInstance();

    virtual bool Initialize() override;
    virtual void Shutdown() override;
    
    virtual void WaitEvents() override;
    /*const*/ GLFWwindow* GetWindow();

    virtual void SetWindowTitle(const std::string& title) override;
    virtual void SetWindowState(WindowState state) override;

    virtual void PollEvents() override;
    virtual bool ShouldCloseWindow() override;
    //virtual void RegisterEventListener(std::shared_ptr<Event> listener) override;

    // Vulkan
    // TODO: create macro and maybe set this in the interface
    // TODO: circular dependency
    virtual VkResult CreateWindowSurface(
        VkInstance 	instance,
        const VkAllocationCallbacks* allocator,
        VkSurfaceKHR* surface) override;
    virtual void GetFramebufferSize(int* width, int* height) override;
    virtual void SetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback) override;

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
