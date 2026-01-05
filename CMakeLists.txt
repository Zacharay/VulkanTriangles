cmake_minimum_required(VERSION 3.17)
project(VulkanTriangles)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

add_executable(VulkanTriangles main.cpp)


target_include_directories(VulkanTriangles PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)


target_link_libraries(VulkanTriangles PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm
)