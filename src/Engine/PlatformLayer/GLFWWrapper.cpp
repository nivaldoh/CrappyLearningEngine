// #include "PlatformLayer.h"
#include "GLFWWrapper.h"
//#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

// TODO: is a singleton the best way to do this?

GLFWPlatformLayer::~GLFWPlatformLayer() {
    Shutdown();
}

GLFWPlatformLayer& GLFWPlatformLayer::GetInstance() {
    static GLFWPlatformLayer instance;
    return instance;
}

bool GLFWPlatformLayer::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(640, 480, "Placeholder", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return false;
    }

    return true;
}

void GLFWPlatformLayer::Shutdown() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }

    glfwTerminate();
}

void GLFWPlatformLayer::SetWindowTitle(const std::string& title) {
    if (window) {
        glfwSetWindowTitle(window, title.c_str());
    }
}

void GLFWPlatformLayer::SetWindowState(WindowState state) {
    if (window) {
        switch (state) {
        case WindowState::MINIMIZED:
            glfwIconifyWindow(window);
            break;
        case WindowState::MAXIMIZED:
            glfwMaximizeWindow(window);
            break;
        case WindowState::FULLSCREEN:
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 640, 480, 0);
            break;
        case WindowState::WINDOWED:
            glfwSetWindowMonitor(window, nullptr, 0, 0, 640, 480, 0);
            break;
        }
    }
}

void GLFWPlatformLayer::PollEvents() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

//std::unique_ptr<IPlatformLayer> CreatePlatformLayer() {
//    return std::make_unique<GLFWPlatformLayer>();
//}
