# glfw-vulkan-boilerplate

This is a minimal boilerplate for a CMake project using GLFW and Vulkan.

## Prerequisites

- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/)
- [Vulkan SDK](https://vulkan.lunarg.com/home/welcome)
- `$VULKAN_SDK` is set properly so that CMake can find the SDK.

## How to use

### 1. Clone this repository

Make sure you install submodules with `--recurse-submodules`.

```
% git clone --recurse-submodules https://github.com/k0michi/glfw-vulkan-boilerplate
% cd glfw-vulkan-boilerplate
```

### 2. Build with CMake

```
% mkdir build
% cd build
% cmake ..
% cmake --build .
```

### 3. Execute the program

The built program location differs depending on the environments.

In case of macOS:

```
% ./main
```

## License

CC0 1.0