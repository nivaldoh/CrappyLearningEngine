# Initialize and update git submodules (vcpkg)
git submodule update --init --recursive

# Download and install the Vulkan SDK
Invoke-WebRequest -Uri "https://sdk.lunarg.com/sdk/download/latest/windows/vulkan-sdk.exe" -OutFile "vulkan-sdk.exe"
Start-Process -FilePath "vulkan-sdk.exe" -Wait

# Bootstrap vcpkg
Push-Location -Path ".\vcpkg"
.\bootstrap-vcpkg.bat

# Install dependencies
.\vcpkg install --triplet x64-windows
Pop-Location