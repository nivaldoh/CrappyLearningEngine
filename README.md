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
  - [X] Setup Vulkan
    - [X] Create Instance
    - [X] Setup Validation Layer
    - [X] Select Physical Device and Queue Family
    - [X] Create Logical Device
    - [X] Create Swap Chain
    - [X] Create Image Views
    - [X] Create Shader Modules
    - [X] Setup Graphics Pipeline
    - [X] Create Render Passes
    - [X] Create Graphics Pipeline
    - [X] Create Framebuffers
    - [X] Create Command Pool
    - [X] Create Command Buffer
  - [] Basic Render Loop
  - [] Draw a Triangle

### Phase 3: Debugging and Profiling
  - [] Basic Unit Testing
  - [] Simple Logging Mechanism
  - [] Basic Performance Profiling?
  - [] Static Analysis

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
- DLSS
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

### Optimization

#### General
- [MIT OCW 6.172 - Performance Engineering Of Software Systems](https://ocw.mit.edu/courses/6-172-performance-engineering-of-software-systems-fall-2018/resources/lecture-1-intro-and-matrix-multiplication/)

#### Data-oriented Design
- [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc&ab_channel=CppCon)
- [CppCon 2018: Stoyan Nikolov “OOP Is Dead, Long Live Data-oriented Design”](https://www.youtube.com/watch?v=yy8jQgmhbAU&ab_channel=CppCon)

#### Algorithms
- "Introduction to Algorithms, 3rd Edition" by Thomas H. Cormen et al.
- [MIT OCW 6.042J - Mathematics For Computer Science](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-spring-2015/pages/syllabus/)
- [MIT OCW 6.006 - Introduction To Algorithms](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/)
- [MIT OCW 6.046J - Design And Analysis Of Algorithms](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/)

### Graphics
- "Real-Time Rendering, Fourth Edition" by Tomas Akenine-Möller et al.
    -  [Book website with extra resources, including chapters 25 (Collision Detection) and 26 (Real-Time Ray-Tracing)](https://www.realtimerendering.com/)
- [MIT OCW - Computer Graphics](https://ocw.mit.edu/courses/6-837-computer-graphics-fall-2012/)
- [NVIDIA - Ray Tracing Essentials](https://www.youtube.com/playlist?list=PL5B692fm6--sgm8Uiava0IIvUojjFOCSR)
- [CppCon 2017: Nicolas Guillemot “Design Patterns for Low-Level Real-Time Rendering”](https://www.youtube.com/watch?v=mdPeXJ0eiGc&ab_channel=CppCon)

### Linear Algebra
- "Essential Mathematics for Games and Interactive Applications, Third Edition" by James M. Van Verth et al.
- [MIT OCW - Gilbert Strang lectures on Linear Algebra](https://www.youtube.com/playlist?list=PL49CF3715CB9EF31D)

### Low-level programming
- [MIT OCW 6.004 - Computation Structures](https://ocw.mit.edu/courses/6-004-computation-structures-spring-2017/)
- [MIT OCW 6.823 - Computer System Architecture](https://ocw.mit.edu/courses/6-823-computer-system-architecture-fall-2005/)

### Software Design
[MIT OCW 6.005 - Software Construction](https://ocw.mit.edu/courses/6-005-software-construction-spring-2016/)

### Multithreading
- [MIT OCW 6.189 - Multicore Programming Primer](https://ocw.mit.edu/courses/6-189-multicore-programming-primer-january-iap-2007/pages/syllabus/)

## Useful Links/References

### General
- [Amit’s Game Programming Information](http://www-cs-students.stanford.edu/~amitp/gameprog.html)

### Reference repositories
- [OpenUSD](https://github.com/PixarAnimationStudios/OpenUSD)
- [OGRE Rendering Engine](https://github.com/OGRECave/ogre)
- [C++ 20 fully lock-free game engine](https://github.com/eduard-permyakov/peredvizhnikov-engine)

### Game Engine Architecture
- [The anatomy of a Godot API call](https://sampruden.github.io/posts/godot-is-not-the-new-unity/)
- [MMO Architecture: Source of truth, Dataflows, I/O bottlenecks and how to solve them](https://prdeving.wordpress.com/2023/09/29/mmo-architecture-source-of-truth-dataflows-i-o-bottlenecks-and-how-to-solve-them/)

### GLFW
- [Docs](https://www.glfw.org/docs/latest/)

### Graphics
- [Direct3D 12 programming guide](https://learn.microsoft.com/en-us/windows/win32/direct3d12/direct3d-12-graphics)
- [Microsoft DirectX 12 playlist](https://www.youtube.com/watch?v=dcDDvoauaz0&list=PLeHvwXyqearWT_NT7CiGm_kEiKabWNPKw&ab_channel=MicrosoftDirectX12andGraphicsEducation)
- [Oregon State University - Mike Bailey's Vulkan Page](https://web.engr.oregonstate.edu/~mjb/vulkan/)
    - [Mike Bailey - Where to Find More Information about
Computer Graphics, Parallel Programming, and Related Topics](https://web.engr.oregonstate.edu/~mjb/vulkan/moreinfo.pdf)
- [DLSS repository + programming guide](https://github.com/NVIDIA/DLSS/tree/main)
- [NVIDIA Ada Science - How Ada advances the science of graphics with DLSS 3](https://images.nvidia.com/aem-dam/Solutions/geforce/ada/ada-lovelace-architecture/nvidia-ada-gpu-science.pdf)
- [Ray tracing in one weekend](https://github.com/RayTracing/raytracing.github.io)
- [NVIDIA Keynote at SIGGRAPH 2023](https://www.youtube.com/watch?v=Z2VBKerS63A&ab_channel=NVIDIA)
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

## Brief Theory Overview

### Graphics Pipeline
- Consists of the following stages:
    - Application (CPU): feeds geometry to next step, and takes care of everything else that wouldn't fit the rest of the pipeline. Can offload extra work to the GPU through compute shaders.
    - Geometry processing (GPU from this point on): performs transformations, projections and other types of geometry handling. Steps:
        - Vertex shading: takes vertex data and outputs transformed vertices (object space -> projection -> clip space). The resulting unit cube is called canonical view volume. Can also perform additional vertex calculations for lighting, animations, etc. Additional optional stages, in order: 
            - Tessellation: hull shader, tesselation, domain shader. Generates curved surfaces with an appropriate number of triangles (objects closer to the camera have more triangles, etc)
            - Geometry shading: takes a primitive and outputs a potentially different number of primitives. Used for things like particle generation.
            - Stream output: allows the GPU to be used as a geometry engine for further processing. Typically used for particle simulations.
        - Clipping: clips primitives that are partially inside the view volume to ensure that only visible vertices get rendered.
        - Screen mapping: takes the coordinates for the clipped primitives (still in 3D) and maps them to 2D screen coordinates. Screen coordinates together with z-coordinates are also called window coordinates. 
    - Rasterization (also known as scan conversion): converts 2D vertices (generally of triangles) in screen space into pixels on the screen. Substages:triangle setup (also called primitive assembly) and triangle traversal
    - Pixel processing: determines pixel color. Might also do depth testing. Stages:
        - Pixel shading: performs all per-pixel shading computations and outputs colors. Runs the pixel/fragment shader. Performs texturing.
        - Merging/ROP: combines fragment color produced by pixel shading with color stored in color buffer. Resolves visibility via z-buffer. Performs raster/blend operations
            - Stencil buffer: offscreen buffer that stores the locations of the rendered primitive.
            - Framebuffer: generally consists of all buffers on the system.
            - Double buffering: is used to avoid displaying primitives as they are being rasterized and sent to the screen. That is, the rendering of a scene takes place in a back buffer. Once complete, the back buffer is swapped with the front buffer during vertical retrace as it is safe to do so there.