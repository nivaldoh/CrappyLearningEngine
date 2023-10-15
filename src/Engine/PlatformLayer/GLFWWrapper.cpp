#include "GLFWWrapper.h"
// TODO: get rid of error handling here?
#include <stdexcept>
#include <iostream>

// TODO: is a singleton the best way to do this?

GLFWWrapper::~GLFWWrapper() {
    Shutdown();
}

GLFWWrapper& GLFWWrapper::GetInstance() {
    static GLFWWrapper instance;
    return instance;
}

bool GLFWWrapper::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(640, 480, "Placeholder", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return false;
    }

    return true;
}

void GLFWWrapper::Shutdown() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }

    glfwTerminate();
}

VkResult GLFWWrapper::CreateWindowSurface(
    VkInstance 	instance,
    const VkAllocationCallbacks* allocator,
    VkSurfaceKHR* surface) {
    VkResult res = glfwCreateWindowSurface(instance, window, nullptr, surface);
    if (res != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface");
    }

    return res;
}

void GLFWWrapper::GetFramebufferSize(int* width, int* height) {
	glfwGetFramebufferSize(window, width, height);
}

void GLFWWrapper::WaitEvents() {
    glfwWaitEvents();
}

const GLFWwindow* GLFWWrapper::GetWindow() {
	return window;
}
    
void GLFWWrapper::SetWindowTitle(const std::string& title) {
    if (window) {
        glfwSetWindowTitle(window, title.c_str());
    }
}

void GLFWWrapper::SetWindowState(WindowState state) {
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

void GLFWWrapper::PollEvents() {
    glfwPollEvents();
}

bool GLFWWrapper::ShouldCloseWindow() {
	return glfwWindowShouldClose(window);
}

//std::unique_ptr<IPlatformLayer> CreatePlatformLayer() {
//    return std::make_unique<GLFWPlatformLayer>();
//}
