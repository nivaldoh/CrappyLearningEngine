#pragma once

#include "GraphicsAPI.h"
#include <vulkan/vulkan.h>

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class VulkanWrapper : public IGraphicsAPI {
public:
    VulkanWrapper();
    ~VulkanWrapper();

    // Initialization and Termination
    virtual bool Initialize() override;
    virtual void Terminate() override;

    // Rendering Loop
    virtual void BeginFrame() override;
    virtual void EndFrame() override;

    // Resource Management
    virtual Texture* CreateTexture(const char* filename) override;
    virtual Shader* CreateShader(const char* vertexSrc, const char* fragmentSrc) override;
    virtual Buffer* CreateBuffer(size_t size, const void* data) override;
    virtual void DestroyTexture(Texture* texture) override;
    virtual void DestroyShader(Shader* shader) override;
    virtual void DestroyBuffer(Buffer* buffer) override;

    // State Management
    virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
    virtual void SetClearColor(float r, float g, float b, float a) override;
    virtual void Clear() override;

    // Drawing
    virtual void DrawIndexed(const Buffer* vertexBuffer, const Buffer* indexBuffer, uint32_t indexCount) override;

    // Debug
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);

private:
    VkInstance instance;
    VkDevice device;
    VkPhysicalDevice physicalDevice;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    VkDebugUtilsMessengerEXT debugMessenger;

    bool CreateInstance();
    bool SelectPhysicalDevice();
    bool CheckValidationLayerSupport();
    std::vector<const char*> GetRequiredExtensions();
    void SetupDebugMessenger();
    VkResult CreateDebugUtilsMessengerEXT(
        VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger
    );
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
};
