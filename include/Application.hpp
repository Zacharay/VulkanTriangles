#pragma once

#include <memory>
#include <vector>
#include "Window.hpp"
#include "VulkanRenderer.hpp"

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<VulkanRenderer> m_renderer;

};