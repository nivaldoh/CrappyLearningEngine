# CrappyLearningEngine

## Scope
This project is not intended to be a full-fledged game engine, but rather a playground for me to learn about game engine architecture, graphics programming and a plethora of other things.
I'll keep things simple at first using libraries when applicable, but I intend to eventually replace them with my own implementations.

## Setup
- Run setup-environment.ps1 (if on Windows)

## Roadmap

### Phase 1: Environment Setup
  - [X] Setup Visual Studio 2022
  - [X] Dependency Management with CMake and vcpkg
  - [X] Integrate GLFW and Vulkan SDK
  - [X] Create Setup Script

### Phase 2: Basic Rendering
  - [X] Create Blank Window
  - [X] Initialize Vulkan Context
    - [X] Setup Validation Layer
    - [X] Select Physical Device
  - [] Basic Render Loop
  - [] Draw a Triangle

### Phase 3: Debugging and Profiling
  - [] Basic Unit Testing
  - [] Simple Logging Mechanism
  - [] Basic Performance Profiling?

### Phase 4: Resource Management
  - [] Basic File I/O for Resources
  - [] Load Simple OBJ Models
  - [] Render Loaded OBJ Models
  - [] Implement Simple Asset Caching

### Phase 5: Mathematics and Geometry
  - [X] Integrate GLM
  - [] Basic Camera System
  - [] Implement Simple Transformations

### Phase 6: Shaders and Materials
  - [] Basic Shader Compilation
  - [] Implement Material System
  - [] Basic Texturing
  - [] Hot-reloading for Shaders

### Phase 7: Multithreading
  - [] Task-based Multithreading
  - [] Parallel Render Loop
  - [] Resource Loading Threads

### Phase 8: Animations
  - [] Support for Animated Assets
  - [] Simple Skeletal Animation
  - [] Basic Animation Blending

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
- "Game Engine Architecture, 3rd Edition" by Jason Gregory: Amazing introduction to the world of high-performance game development, covering foundational theory (linear algebra, hardware, operating systems, software engineering best practices, etc) as well as the basic aspects of what makes a production-grade game engine tick.

### C++
- "A Tour of C++ (C++ In-Depth Series), 3rd Edition" by Bjarne Stroustrup: Excellent overview of the C++, updated for C++20. Contains succint "advice" sections that are very convenient for quick reference.
- "Modern C++ Design: Generic Programming and Design Patterns Applied, 1st Edition" by Andrei Alexandrescu

### Data-oriented design
- [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc&ab_channel=CppCon)
- [CppCon 2018: Stoyan Nikolov “OOP Is Dead, Long Live Data-oriented Design”](https://www.youtube.com/watch?v=yy8jQgmhbAU&ab_channel=CppCon)

### Graphics
- "Real-Time Rendering, Fourth Edition" by Tomas Akenine-Möller et al.
- [MIT OCW - Computer Graphics](https://ocw.mit.edu/courses/6-837-computer-graphics-fall-2012/)
- [NVIDIA - Ray Tracing Essentials](https://www.youtube.com/playlist?list=PL5B692fm6--sgm8Uiava0IIvUojjFOCSR)

### Linear Algebra
- "Essential Mathematics for Games and Interactive Applications, Third Edition" by James M. Van Verth et al.
- [MIT OCW - Gilbert Strang lectures on Linear Algebra](https://www.youtube.com/playlist?list=PL49CF3715CB9EF31D)

## Useful links/references

### Game Engines/Rendering Engines
- [OGRE Rendering Engine](https://github.com/OGRECave/ogre)
- [C++ 20 fully lock-free game engine](https://github.com/eduard-permyakov/peredvizhnikov-engine)

### GLFW
- [Docs](https://www.glfw.org/docs/latest/)

### Graphics
- [Ray tracing in one weekend](https://github.com/RayTracing/raytracing.github.io)
- [Analyzing Starfield’s Performance on Nvidia’s 4090 and AMD’s 7900 XTX](https://chipsandcheese.com/2023/09/14/analyzing-starfields-performance-on-nvidias-4090-and-amds-7900-xtx/)

#### Vulkan
- [Oficial guide](https://github.com/KhronosGroup/Vulkan-Guide)
- [Samples](https://github.com/KhronosGroup/Vulkan-Samples)
- [Quickstart](https://vulkan-tutorial.com/)

## Thought process
### Build system
- Using [OGRE](https://github.com/OGRECave/ogre) as a quick reference for CMake best practices.

### General
- Trying to abstract away the usage of libraries such as GLFW in order to make it easier to switch to another library in the future (or use custom code), while trying to avoid unnecessary complexity. Using a singleton to manage library state in the wrapper, but not sure yet if that's a good approach.