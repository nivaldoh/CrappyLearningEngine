#include "VulkanWrapper.h"

//TODO: get rid of this
#include <iostream>

VulkanWrapper& VulkanWrapper::GetInstance() {
    static VulkanWrapper instance;
    return instance;
}

VulkanWrapper::VulkanWrapper() {
    Initialize();
}

VulkanWrapper::~VulkanWrapper() {
    Terminate();
}

// TODO: make this private?
bool VulkanWrapper::Initialize() {
    if (!CreateInstance()) {
        return false;
    }

    SetupDebugMessenger();

    if (!PickPhysicalDevice()) {
        return false;
    }

    return true;
}

// TODO: make this private?
void VulkanWrapper::Terminate() {
    if (enableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(vkInstance, debugMessenger, nullptr);
    }

    vkDestroyInstance(vkInstance, nullptr);
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

VKAPI_ATTR VkBool32 VKAPI_CALL VulkanWrapper::debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) {

    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}

bool VulkanWrapper::CreateInstance() {
    if (enableValidationLayers && !CheckValidationLayerSupport()) {
        throw std::runtime_error("validation layers requested, but not available!");
    }

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

    if (enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();
    }
    else {
        createInfo.enabledLayerCount = 0;
    }

    std::vector<const char*> extensions = GetRequiredExtensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if (enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();

        PopulateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
    }
    else {
        createInfo.enabledLayerCount = 0;

        createInfo.pNext = nullptr;
    }

    VkResult result = vkCreateInstance(&createInfo, nullptr, &vkInstance);
    return result == VK_SUCCESS;
}

bool VulkanWrapper::CheckValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char* layerName : validationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}

// TODO: abstract GLFW-specific code
std::vector<const char*> VulkanWrapper::GetRequiredExtensions() {
    uint32_t extensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + extensionCount);

    if (enableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}

bool VulkanWrapper::PickPhysicalDevice() {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(vkInstance, &deviceCount, nullptr);

    if (deviceCount == 0) {
		throw std::runtime_error("Failed to find GPUs with Vulkan support");
	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(vkInstance, &deviceCount, devices.data());

    // Would be ideal to add device selection logic here, but for this project it's fine.
    for (const auto& device : devices) {
        if (IsDeviceSuitable(device)) {
			physicalDevice = device;
			break;
		}
	}

    if (physicalDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("Failed to find a suitable GPU");
	}
}

bool VulkanWrapper::IsDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices indices = FindQueueFamilies(device);

    return indices.isComplete();
}

QueueFamilyIndices VulkanWrapper::FindQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }

        if (indices.isComplete()) {
            break;
        }

        i++;
    }

    return indices;
}

void VulkanWrapper::SetupDebugMessenger() {
    if (!enableValidationLayers) return;

    VkDebugUtilsMessengerCreateInfoEXT createInfo;
    PopulateDebugMessengerCreateInfo(createInfo);

    if (CreateDebugUtilsMessengerEXT(vkInstance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }
}

VkResult VulkanWrapper::CreateDebugUtilsMessengerEXT(
    VkInstance vkInstance,
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger
) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vkInstance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(vkInstance, pCreateInfo, pAllocator, pDebugMessenger);
    }
    else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void VulkanWrapper::DestroyDebugUtilsMessengerEXT(VkInstance vkInstance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vkInstance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(vkInstance, debugMessenger, pAllocator);
    }
}

void VulkanWrapper::PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
    createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = debugCallback;
}