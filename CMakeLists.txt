cmake_minimum_required(VERSION 3.7)
project(GLFWVulkan CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(third_party/glfw)

# main
add_executable(main src/main.cc)

target_include_directories(main PRIVATE third_party/glfw/include)
target_link_libraries(main glfw)

target_include_directories(main PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(main ${Vulkan_LIBRARIES})