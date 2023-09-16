#pragma once

// TODO: flexibilize these
#include <cstdint>
#include <vector>

class Texture;
class Shader;
class Buffer;

class IGraphicsAPI {
public:
    virtual ~IGraphicsAPI() = default;

    // Initialization and Termination
    virtual bool Initialize() = 0;
    virtual void Terminate() = 0;

    // Rendering Loop
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;

    // Resource Management
    virtual Texture* CreateTexture(const char* filename) = 0;
    virtual Shader* CreateShader(const char* vertexSrc, const char* fragmentSrc) = 0;
    virtual Buffer* CreateBuffer(size_t size, const void* data) = 0;
    virtual void DestroyTexture(Texture* texture) = 0;
    virtual void DestroyShader(Shader* shader) = 0;
    virtual void DestroyBuffer(Buffer* buffer) = 0;

    // State Management
    virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
    virtual void SetClearColor(float r, float g, float b, float a) = 0;
    virtual void Clear() = 0;

    // Drawing
    virtual void DrawIndexed(const Buffer* vertexBuffer, const Buffer* indexBuffer, uint32_t indexCount) = 0;
};
