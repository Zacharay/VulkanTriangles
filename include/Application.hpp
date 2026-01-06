#pragma once

#include <memory>
#include <vector>

#include "Camera.hpp"
#include "Window.hpp"
#include "VulkanRenderer.hpp"

class Application {
public:
    Application(int numberOfTriangles);
    ~Application();

    void run();

private:
    std::vector<Vertex> m_vertices;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<VulkanRenderer> m_renderer;
    std::unique_ptr<Camera> m_camera;

    float lastMouseX = 500.0f;
    float lastMouseY = 400.0f;
    bool firstMouse = true;

    void initTriangles(int numberOfTriangles);
    void handleInput(float deltaTime);
};