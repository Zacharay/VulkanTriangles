#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

int main() {

    glfwInit();


    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << "Vulkan dziala! Dostepne rozszerzenia: " << extensionCount << std::endl;


    glm::mat4 matrix;
    glm::vec4 vector;
    auto test = matrix * vector;

    glfwTerminate();
    return 0;
}