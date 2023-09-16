#include "VulkanWrapper.h"

//TODO: get rid of this
#include <iostream>

VulkanWrapper::VulkanWrapper() {}

VulkanWrapper::~VulkanWrapper() {}

bool VulkanWrapper::Initialize() {
    if (!CreateInstance()) {
        return false;
    }

    if (!SelectPhysicalDevice()) {
        return false;
    }

    return true;
}

void VulkanWrapper::Terminate() {
    vkDestroyInstance(instance, nullptr);
}

void VulkanWrapper::BeginFrame() {
    // ...
}

void VulkanWrapper::EndFrame() {
    // ...
}

Texture* VulkanWrapper::CreateTexture(const char* filename) {
    // ...
    return nullptr;
}

Shader* VulkanWrapper::CreateShader(const char* vertexSrc, const char* fragmentSrc) {
    // ...
    return nullptr;
}

Buffer* VulkanWrapper::CreateBuffer(size_t size, const void* data) {
    // ...
    return nullptr;
}

void VulkanWrapper::DestroyTexture(Texture* texture) {
    // ...
}

void VulkanWrapper::DestroyShader(Shader* shader) {
    // ...
}

void VulkanWrapper::DestroyBuffer(Buffer* buffer) {
    // ...
}

void VulkanWrapper::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    // ...
}

void VulkanWrapper::SetClearColor(float r, float g, float b, float a) {
    // ...
}

void VulkanWrapper::Clear() {
    // ...
}

void VulkanWrapper::DrawIndexed(const Buffer* vertexBuffer, const Buffer* indexBuffer, uint32_t indexCount) {
    // ...
}

bool VulkanWrapper::CreateInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "MyVulkanApp";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    return result == VK_SUCCESS;
}

bool VulkanWrapper::SelectPhysicalDevice() {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        std::cerr << "No Vulkan-compatible physical devices found.\n";
        return false;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    physicalDevice = devices[0];
    return true;
}
