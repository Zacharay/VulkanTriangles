#include "Application.hpp"
#include <iostream>
#include "glm/glm.hpp"
#include <chrono>
#include <glm/gtc/matrix_transform.hpp>
#include <random>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

Application::Application(const int numberOfTriangles) {

    initTriangles(numberOfTriangles);

    m_window = std::make_unique<Window>(1280, 720, "Intel Task Zachariasz Slupski");

    m_renderer = std::make_unique<VulkanRenderer>(*m_window,m_vertices);

    m_camera = std::make_unique<Camera>(
        glm::vec3(0.0f, 2.0f, 5.0f),  //position
        glm::vec3(0.0f, 0.0f, -1.0f), //front
        glm::vec3(0.0f, 1.0f, 0.0f)   //up
    );

    glfwSetInputMode(m_window->getNativeWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Application::~Application() {

}

void Application::initTriangles(const int numberOfTriangles) {

    m_vertices.reserve(numberOfTriangles * 3);

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> posDist(-100.0f, 100.0f);
    std::uniform_real_distribution<float> colDist(0.0f, 1.0f);
    std::uniform_real_distribution<float> sizeDist(0.2f, 0.8f);

    for (int i = 0; i < numberOfTriangles; i++) {

        float x = posDist(rng);
        float y = posDist(rng);
        float z = posDist(rng);

        float s = sizeDist(rng);
        glm::vec3 color = {colDist(rng), colDist(rng), colDist(rng)};

        float zTilt1 = sizeDist(rng) - (s/2.0f);
        float zTilt2 = sizeDist(rng) - (s/2.0f);
        float zTilt3 = sizeDist(rng) - (s/2.0f);

        m_vertices.push_back({ glm::vec3(x,     y - s, z + zTilt1), color });
        m_vertices.push_back({ glm::vec3(x + s, y + s, z + zTilt2), color });
        m_vertices.push_back({ glm::vec3(x - s, y + s, z + zTilt3), color });
    }
}

void Application::run() {
    auto lastTime = std::chrono::high_resolution_clock::now();

    while (!m_window->shouldClose()) {
        m_window->pollEvents();


        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastTime).count();
        lastTime = currentTime;


        handleInput(deltaTime);


        UniformBufferObject ubo{};

        ubo.model = glm::mat4(1.0f);


        ubo.view = m_camera->getViewMatrix();


        float aspectRatio = m_window->getAspectRatio();
        ubo.proj = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 1000.0f);


        ubo.proj[1][1] *= -1;


        m_renderer->drawFrame(ubo);
    }

    m_renderer->waitIdle();
}

void Application::handleInput(float deltaTime) {
    GLFWwindow* window = m_window->getNativeWindow();


    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        m_camera->processKeyboardInput(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        m_camera->processKeyboardInput(BACKWARDS, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        m_camera->processKeyboardInput(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        m_camera->processKeyboardInput(RIGHT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        m_camera->processKeyboardInput(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        m_camera->processKeyboardInput(DOWN, deltaTime);


    double xpos, ypos;
    const float MOUSE_SENSITIVITY = 0.05f;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (firstMouse) {
        lastMouseX = xpos;
        lastMouseY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastMouseX;
    float yoffset = lastMouseY - ypos;

    lastMouseX = xpos ;
    lastMouseY = ypos;

    m_camera->processMouseInput(xoffset * MOUSE_SENSITIVITY, yoffset * MOUSE_SENSITIVITY) ;
}


