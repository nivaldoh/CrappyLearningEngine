#include "Engine.h"
// TODO: create rendering component and probably move this there
#include <vulkan/vulkan.h>

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
}
