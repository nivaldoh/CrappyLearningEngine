# CrappyLearningEngine

## Scope
This project is not intended to be a full-fledged game engine, but rather a playground for me to learn about game engine architecture, graphics programming and a plethora of other things.
I'll keep things simple at first using libraries when applicable, but I intend to eventually replace them with my own implementations.

## Roadmap

### Phase 1: Environment Setup
  - [X] Setup Visual Studio 2022
  - [X] Dependency Management with CMake and vcpkg
  - [] Integrate GLFW and Vulkan SDK

### Phase 2: Basic Rendering
  - [] Initialize Vulkan Context
  - [] Basic Render Loop
  - [] Draw a Triangle

### Phase 3: Debugging and Profiling
  - [] Basic Unit Testing
  - [] Simple Logging Mechanism
  - [] Basic Performance Profiling

### Phase 4: Resource Management
  - [] Implement Simple Asset Caching
  - [] Basic File I/O for Resources
  - [] Hot-reloading for Shaders

### Phase 5: Mathematics and Geometry
  - [] Use Linear Algebra Library
  - [] Basic Camera System
  - [] Implement Simple Transformations

### Phase 6: Shaders and Materials
  - [] Basic Shader Compilation
  - [] Implement Material System
  - [] Basic Texturing

### Phase 7: Multithreading
  - [] Task-based Multithreading
  - [] Parallel Render Loop
  - [] Resource Loading Threads

### Phase 8: Animations
  - [] Simple Skeletal Animation
  - [] Basic Animation Blending
  - [] Support for Animated Assets

### Phase 9: Basic Lighting and Shadows
  - [] Implement Simple Lighting Models
  - [] Basic Shadows
  - [] Simple Skybox

### Phase 10: Batch Rendering
  - [] Implement Static Batching
  - [] Dynamic Batching Techniques
  - [] Vertex and Index Buffer Management

### Phase 11: Post-processing and Effects
  - [] Simple Post-processing Pipeline
  - [] Basic Screen Effects like Bloom
  - [] Screen Space Reflections

### Phase 12: Ray Tracing
  - [] Basic Ray Tracing Support
  - [] Simple Ray-Traced Shadows
  - [] Basic Ray-Traced Lighting

### Phase 13: User Interface
  - [] Integrate Basic UI Library
  - [] Implement Simple UI Widgets
  - [] In-game Debug Console

### Phase 14: Scripting
  - [] Embed a Scripting Language
  - [] Basic Scripting Support
  - [] Expose Simple API to Scripts

### Add later
- Audio
- Physics

### 2.0 ideas
- Custom memory allocation
- Networking
- Data-oriented design
- Plugin system

## Coding standard
Adhering to [UE standard](https://docs.unrealengine.com/5.3/en-US/epic-cplusplus-coding-standard-for-unreal-engine/).

## Formal learning resources

### General
- "Game Engine Architecture, 3rd Edition" by Jason Gregory

### C++
- "A Tour of C++ (C++ In-Depth Series), 3rd Edition" by Bjarne Stroustrup

### Data-oriented design
- [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc&ab_channel=CppCon)
- [CppCon 2018: Stoyan Nikolov “OOP Is Dead, Long Live Data-oriented Design”](https://www.youtube.com/watch?v=yy8jQgmhbAU&ab_channel=CppCon)

### Graphics
- "Real-Time Rendering, Fourth Edition" by Tomas Akenine-Möller et al.

## Useful links/references

### Game engines
- [C++ 20 fully lock-free game engine](https://github.com/eduard-permyakov/peredvizhnikov-engine)

### GLFW
- [Docs](https://www.glfw.org/docs/latest/)

### Graphics
- [Ray tracing in one weekend](https://github.com/RayTracing/raytracing.github.io)

#### Vulkan
- [Oficial guide](https://github.com/KhronosGroup/Vulkan-Guide)
- [Samples](https://github.com/KhronosGroup/Vulkan-Samples)
- [Quickstart](https://vulkan-tutorial.com/)