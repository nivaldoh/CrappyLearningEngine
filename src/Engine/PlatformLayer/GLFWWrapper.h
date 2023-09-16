#pragma once

#include "PlatformLayer.h"
#include <GLFW/glfw3.h>

class GLFWPlatformLayer : public IPlatformLayer {
public:
    static GLFWPlatformLayer& GetInstance();

    virtual bool Initialize() override;
    virtual void Shutdown() override;

    virtual void SetWindowTitle(const std::string& title) override;
    virtual void SetWindowState(WindowState state) override;

    virtual void PollEvents() override;
    //virtual void RegisterEventListener(std::shared_ptr<Event> listener) override;

private:
    GLFWPlatformLayer() = default;
    virtual ~GLFWPlatformLayer() override;
    GLFWPlatformLayer(GLFWPlatformLayer const&) = delete;
    void operator=(GLFWPlatformLayer const&) = delete;

    // std::shared_ptr<Event> eventListener;
    
    GLFWwindow* window;
    std::string windowTitle;
    WindowState windowState;
};
