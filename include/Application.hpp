#pragma once

#include <memory>
#include <vector>

#include "Camera.hpp"
#include "Window.hpp"
#include "VulkanRenderer.hpp"
#include "Frustum.hpp"


struct TriangleData {
    Vertex v1, v2, v3;
    glm::vec3 center;
    float radius;
};

class Application {
public:
    Application(int numberOfTriangles);
    ~Application();

    void run();

private:
    std::vector<Vertex> m_vertices;

    std::vector<TriangleData> m_allTriangles;
    std::vector<Vertex> m_visibleVertices;
    Frustum m_frustum;

    std::unique_ptr<Window> m_window;
    std::unique_ptr<VulkanRenderer> m_renderer;
    std::unique_ptr<Camera> m_camera;

    float lastMouseX = 500.0f;
    float lastMouseY = 400.0f;
    bool firstMouse = true;

    int m_totalTriangles;
    int m_visibleTriangles;
    bool m_cullingOn ;

    int m_lastFPS = 0;
    double m_lastFrameTime = 0.0;

    bool m_meshNeedsFullRestore;
    bool m_f1Pressed = false;

    void initTriangles();
    void setWindowTitle(int frameCount,double msPerFrame);
    void handleInput(float deltaTime);
};