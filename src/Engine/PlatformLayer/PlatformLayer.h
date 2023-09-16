#pragma once

#include <string>
//#include <memory>

// TODO: modularize this?
enum class WindowState {
    MINIMIZED,
    MAXIMIZED,
    FULLSCREEN,
    WINDOWED
};

// TODO: add separate namespace?

class Event;

class IPlatformLayer {
public:
    virtual ~IPlatformLayer() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;

    virtual void SetWindowTitle(const std::string& title) = 0;
    virtual void SetWindowState(WindowState state) = 0;

    virtual void PollEvents() = 0;
    //virtual void RegisterEventListener(std::shared_ptr<Event> listener) = 0;
};

//std::unique_ptr<IPlatformLayer> CreatePlatformLayer();
