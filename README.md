# Vulkan Triangle Renderer 

A C++ application using the Vulkan API to render randomly distributed triangles in 3D space. 

**Core Requirements:**
* Rendering of triangles with random sizes, randomly distributed in space.
* Generation of a new random data set on every launch (no pre-generated data used).
* Triangle count input as a program parameter (range: 1 – 10,000).

**Optional Features Implemented:**
1. Camera rotation and movement support.
2. Real-time rendering speed information displayed in FPS(on title bar).
3. Frustum culling mechanism implementation with the ability to toggle it ON/OFF.


## Requirements
* **C++ Compiler:** C++17 standard support (GCC, Clang).
* **Build System:** CMake 3.17.
* **Vulkan SDK.**
* **Libraries:** GLFW3, GLM.


## Dependency Installation

### Fedora
```bash
sudo dnf install cmake gcc-c++ vulkan-loader-devel vulkan-validation-layers-devel vulkan-tools glfw-devel glm-devel
```
### Debian/Ubuntu
```bash
sudo apt-get update
sudo apt-get install build-essential cmake libvulkan-dev vulkan-validationlayers vulkan-tools libglfw3-dev libglm-dev
```

*Note: This project has been developed and verified on **Linux Fedora**.*
## Build Instructions

The project uses a standard CMake build workflow.

1. Open a terminal in the project's root directory.
2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```
3. Generate build files:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```
4. Compile the application:
   ```bash
   make
   ```
The executable VulkanTriangles will be created in the build directory. Compiled shaders (.spv) are automatically copied to the executable's location.

## Usage
The application accepts an optional command-line argument to specify the number of triangles (range: 1 - 10,000). The default value is 1000.
```bash
./VulkanTriangles [triangle_count]
```
Examples:
```bash
./VulkanTriangles        # Run with default 1000 triangles
./VulkanTriangles 5000   # Run with 5000 triangles
```

## Controls

| Key | Action |
| :--- | :--- |
| **W / A / S / D** | Move Camera (Forward / Left / Back / Right) |
| **Mouse** | Rotate Camera |
| **SPACE** | Move Up |
| **L. SHIFT** | Move Down |
| **F1** | Toggle **Frustum Culling** (On/Off) |
| **ESC** | Exit Application |

## Resources & Acknowledgments
* **[Vulkan Tutorial](https://vulkan-tutorial.com/):** Used as the primary reference for Vulkan initialization and boilerplate code.
* **[LearnOpenGL](https://learnopengl.com/):** Served as a reference for the camera system implementation and frustum culling concepts.
