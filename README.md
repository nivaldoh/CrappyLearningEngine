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
    - [X] Basic Render Loop
    - [X] Draw a Triangle
    - [X] Draw Frames in Flight
    - [X] Enable Swap Chain Recreation (e.g. for window resizing)

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
    - OpenXR
    - USD (Universal Scene Description)
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
    - "Data Parallel C++: Mastering DPC++ for Programming of Heterogeneous Systems using C++ and SYCL, 1st Edition" by James Reinders et al.

### Optimization

#### General
    - [MIT OCW 6.172 - Performance Engineering Of Software Systems](https://ocw.mit.edu/courses/6-172-performance-engineering-of-software-systems-fall-2018/resources/lecture-1-intro-and-matrix-multiplication/)

#### Data-oriented Design
    - [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc&ab_channel=CppCon)
    - [CppCon 2018: Stoyan Nikolov “OOP Is Dead, Long Live Data-oriented Design”](https://www.youtube.com/watch?v=yy8jQgmhbAU&ab_channel=CppCon)

#### Algorithms
    - "Elements of Programming Interviews: The Insiders' Guide" by Adnan Aziz et al.
    - "Introduction to Algorithms, 3rd Edition" by Thomas H. Cormen et al.
    - [MIT OCW 6.042J - Mathematics For Computer Science](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-spring-2015/pages/syllabus/)
    - [MIT OCW 6.006 - Introduction To Algorithms](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/)
    - [MIT OCW 6.046J - Design And Analysis Of Algorithms](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/)

### Graphics
    - "Fundamentals of Computer Graphics, 3rd Edition" by Peter Shirley et al.
    - "Real-Time Rendering, 4th Edition" by Tomas Akenine-Möller et al.
        -  [Book website with extra resources, including chapters 25 (Collision Detection) and 26 (Real-Time Ray-Tracing)](https://www.realtimerendering.com/)
    - "Mastering Graphics Programming with Vulkan: Develop a modern rendering engine from first principles to state-of-the-art techniques, 1st Edition" by Marco Castorina and Gabriel Sassone
    - [Khronos - Book list](https://www.khronos.org/developers/books/)
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
    - [GLFW Docs](https://www.glfw.org/docs/latest/)

### C++
    - [A Guide to Undefined Behavior in C and C++](https://blog.regehr.org/archives/213)

### Profiling/Debugging
    - [Writing a Linux Debugger](https://blog.tartanllama.xyz/writing-a-linux-debugger-setup/)
    - [How I got robbed of my first kernel contribution](https://ariel-miculas.github.io/How-I-got-robbed-of-my-first-kernel-contribution/)

### Reference repositories
    - [OpenUSD](https://github.com/PixarAnimationStudios/OpenUSD)
    - [OGRE Rendering Engine](https://github.com/OGRECave/ogre)
    - [NVIDIA Falcor](https://developer.nvidia.com/falcor)
    - [The G3D Innovation Engine](https://casual-effects.com/g3d/www/index.html)
    - [Khronos OpenXR](https://www.khronos.org/openxr/)
    - [C++ 20 fully lock-free game engine](https://github.com/eduard-permyakov/peredvizhnikov-engine)

### Game Engine Architecture
    - [The anatomy of a Godot API call](https://sampruden.github.io/posts/godot-is-not-the-new-unity/)
    - [MMO Architecture: Source of truth, Dataflows, I/O bottlenecks and how to solve them](https://prdeving.wordpress.com/2023/09/29/mmo-architecture-source-of-truth-dataflows-i-o-bottlenecks-and-how-to-solve-them/)

### Graphics
    - [Direct3D 12 programming guide](https://learn.microsoft.com/en-us/windows/win32/direct3d12/direct3d-12-graphics)
    - [Microsoft DirectX 12 playlist](https://www.youtube.com/watch?v=dcDDvoauaz0&list=PLeHvwXyqearWT_NT7CiGm_kEiKabWNPKw&ab_channel=MicrosoftDirectX12andGraphicsEducation)
    - [Oregon State University - Mike Bailey's Vulkan Page](https://web.engr.oregonstate.edu/~mjb/vulkan/)
        - [Mike Bailey - Where to Find More Information about
    Computer Graphics, Parallel Programming, and Related Topics](https://web.engr.oregonstate.edu/~mjb/vulkan/moreinfo.pdf)
    - [Ray tracing in one weekend](https://github.com/RayTracing/raytracing.github.io)
    - [NVIDIA Keynote at SIGGRAPH 2023](https://www.youtube.com/watch?v=Z2VBKerS63A&ab_channel=NVIDIA)
    - [Analyzing Starfield’s Performance on Nvidia’s 4090 and AMD’s 7900 XTX](https://chipsandcheese.com/2023/09/14/analyzing-starfields-performance-on-nvidias-4090-and-amds-7900-xtx/)

#### DLSS
    - [DLSS repository + programming guide](https://github.com/NVIDIA/DLSS/tree/main)
    - [NVIDIA Ada Science - How Ada advances the science of graphics with DLSS 3](https://images.nvidia.com/aem-dam/Solutions/geforce/ada/ada-lovelace-architecture/nvidia-ada-gpu-science.pdf)
    - [DLSS 2.0 – Image reconstruction for real-time rendering with Deep learning](http://behindthepixels.io/assets/files/DLSS2.0.pdf)

#### Vulkan
- [Oficial guide](https://github.com/KhronosGroup/Vulkan-Guide)
- [Samples](https://github.com/KhronosGroup/Vulkan-Samples)
-   [Quickstart](https://vulkan-tutorial.com/)

## Thought process
### Build system
    - Using [OGRE](https://github.com/OGRECave/ogre) as a quick reference for CMake best practices.

### General
    - Trying to abstract away the usage of libraries such as GLFW in order to make it easier to switch to another library in the future (or use custom code), while trying to avoid unnecessary complexity. Using a singleton to manage library state in the wrapper, but not sure yet if that's a good approach.

## Brief Theory Overview

### Multithreading/Concurrency
#### Vulkan
    - Semaphores: GPU operation ordering. E.g. swapchain image acquisition and presentation.
    - Fences: CPU-GPU synchronization. E.g. wait for a command buffer to finish executing.

### Data Structures and Algorithms
#### Data Structures
	- Arrays & strings: O(1) lookup/insertion/deletion at the end. O(n) insertion/deletion elsewhere. Good cache locality.
	- Linked lists: O(1) insertion/deletion. O(n) lookup. Dynamic size.
	- Stacks: LIFO. O(1) push/pop/peek. Commonly implemented with arrays or linked lists.
	- Queues: FIFO. O(1) enqueue/dequeue/peek .Commonly implemented with arrays or linked lists.
    - Heaps: O(1) lookup for max/min element, O(log n) insertion/deletion. Node and array representations. Is an implementation of a priority queue.
	- Hash tables: O(1) lookup, insertion and deletion on average. Array of buckets and collision chain implementations. Bad for order-related uses. Worst case O(n) due to hash collisions. If total keys not known in advance, it needs resizing (which can have O(n) complexity depending on implementation). Hash functions for ints, strings, objs. Equals function. Variants such as bloom filters.
    - Binary search trees: O(log n) lookup, insertion, deletion, find-min, find-max, successor and predecessor when tree is balanced. Node and pointer implementations. Operations to maintain balance. Can be augmentated to manipulate more complicated data (e.g. intervals) and to support more complex queries (e.g. the number of elements in a range). Dynamic order statistics, AVL trees, red-black trees, etc.
	- Graphs: directed/undirected. Weighted/unweighted. Cyclic/acyclic. Can be implemented with adjacency lists or matrices. Traversal algorithms: BFS, DFS. Shortest path algorithms: Dijkstra, Bellman-Ford, Floyd-Warshall. Minimum spanning tree algorithms: Prim, Kruskal. Topological sort. Connectivity. Cycle detection.
    - Skip lists
    - Treaps
    - Fibonacci heaps
    - Disjoint sets
    - Tries

#### Algorithm design patterns
    - Sorting
    - Recursion
    - Divide and conquer
    - Dynamic programming: applicable when it is possible to reconstruct a solution to a given instance of a problem from solutions of subinstances of smaller problems of the same kind, which can be cached. Usually easier to use recursion and more efficient to use iteration. Sometimes inneficient paths need to be pruned.
    - Greedy algorithms
    - Incremental improvement
    - Elimination
    - Parallelism
    - Caching
    - Randomization
    - Approximation
    - State


### Graphics
#### Graphics Pipeline
    - Consists of the following stages:
        - Application (CPU): feeds geometry to next step, and takes care of everything else that wouldn't fit the rest of the pipeline. Can offload extra work to the GPU through compute shaders.
        - Geometry processing (GPU from this point on): performs transformations, projections and other types of geometry handling. Steps:
            - Vertex shading: takes vertex data and outputs transformed vertices (object space -> projection -> clip space). The resulting unit cube is called canonical view volume. Can also perform additional vertex calculations for lighting, animations, etc. Additional optional stages, in order: 
                - Tessellation: hull shader, tesselation, domain shader. Generates curved surfaces with an appropriate number of triangles (objects closer to the camera have more triangles, etc).
                - Geometry shading: takes a primitive and outputs a potentially different number of primitives. Used for things like particle generation.
                - Stream output: allows the GPU to be used as a geometry engine for further processing. Typically used for particle simulations.
            - Clipping: clips primitives that are partially inside the view volume to ensure that only visible vertices get rendered.
            - Screen mapping: takes the coordinates for the clipped primitives (still in 3D) and maps them to 2D screen coordinates. Screen coordinates together with z-coordinates are also called window coordinates. 
        - Rasterization (also known as scan conversion): converts 2D vertices (generally of triangles) in screen space into pixels on the screen. Substages:triangle setup (also called primitive assembly) and triangle traversal.
        - Pixel processing: determines pixel color. Might also do depth testing. Stages:
            - Pixel shading: performs all per-pixel shading computations and outputs colors. Runs the pixel/fragment shader. Performs texturing.
            - Merging/ROP: combines fragment color produced by pixel shading with color stored in color buffer. Resolves visibility via z-buffer. Performs raster/blend operations
                - Stencil buffer: offscreen buffer that stores the locations of the rendered primitive.
                - Framebuffer: generally consists of all buffers on the system.
                - Double buffering: is used to avoid displaying primitives as they are being rasterized and sent to the screen. That is, the rendering of a scene takes place in a back buffer. Once complete, the back buffer is swapped with the front buffer during vertical retrace as it is safe to do so there.

#### GPU
    - Highly parallelizable processor for a set of narrow tasks (quiickly access textures, find pixels covered by triangle, etc) as well as tasks programmable by shaders.
    - To parallelize programmable shaders, the GPU uses SIMD shader cores. Cores can context switch to a different warp/wavefront (which happens simultaneously for all threads in it) so they don't idle due to memory access latency.
        - Each pixel shader invocation for a fragment is called a thread. These have low overhead compared to CPU threads. Each thread is mapped to a SIMD lane.
        - Threads using the same shader program are bundled into a warp (NVIDIA) / wavefront (AMD).
        - Inefficient shader programs with more register use mean that fewer threads and thus fewer warps can be resident in the GPU.
        - Thread divergence: if at least one thread evaluates differently than others in a warp, the warp must be inneficient and execute both branches.