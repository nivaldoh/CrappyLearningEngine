#pragma once

#include "GraphicsAPI.h"
#include <vulkan/vulkan.h>
// TODO: move this
#include <optional>

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

class VulkanWrapper : public IGraphicsAPI {
public:
    static VulkanWrapper& GetInstance();

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
    VulkanWrapper(VulkanWrapper const&) = delete;
    void operator=(VulkanWrapper const&) = delete;

    VkInstance vkInstance;
    VkDevice device;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    VkDebugUtilsMessengerEXT debugMessenger;

    bool CreateInstance();
    bool CheckValidationLayerSupport();
    std::vector<const char*> GetRequiredExtensions();
    bool PickPhysicalDevice();
    bool IsDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
    void CreateLogicalDevice();

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
