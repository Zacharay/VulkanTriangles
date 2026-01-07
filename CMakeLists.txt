cmake_minimum_required(VERSION 3.17)
project(VulkanTriangles)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Vulkan REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)

add_executable(VulkanTriangles src/main.cpp
        src/Application.cpp
        src/Window.cpp
        include/Window.hpp
        include/Application.hpp
        include/VulkanRenderer.hpp
        src/VulkanRenderer.cpp
        include/Camera.hpp
        src/Camera.cpp
        include/Frustum.hpp)


target_include_directories(VulkanTriangles PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include/
)


target_link_libraries(VulkanTriangles PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm
)