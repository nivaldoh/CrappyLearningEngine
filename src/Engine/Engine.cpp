#include "Engine.h"
// TODO: this should depend on build config
#include "GLFWWrapper.h"
#include "VulkanWrapper.h"

// TODO: move this out of here
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

// TODO: get rid of this
#include <iostream>

Engine::Engine() {
}

// TODO: setup logging, tests and profiling
// TODO: prepare custom memory allocation, error handling, scope management, thread management, etc
void Engine::PreInit() {

}

// TODO: initialize components (rendering, input, etc)
void Engine::Init() {

}

// TODO: render simple triangle
void Engine::Tick() {
	std::cout << "Running loop" << std::endl;

    // TODO: move this to PreInit
    GLFWWrapper& GLFWInst = GLFWWrapper::GetInstance();
    GLFWInst.Initialize();
    GLFWInst.SetWindowTitle("VulkanTest");

    VulkanWrapper& VulkanInst = VulkanWrapper::GetInstance();
    VulkanInst.SetGLFWInstance(&GLFWInst);
    VulkanInst.Initialize();

    std::cout << "Polling" << std::endl;
    while (!GLFWInst.ShouldCloseWindow()) {
		GLFWInst.PollEvents();
        VulkanInst.DrawFrame();
	}
}
