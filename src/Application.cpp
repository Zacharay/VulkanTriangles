#include "Application.hpp"
#include <iostream>

Application::Application() {

    m_window = std::make_unique<Window>(1000, 800, "Intel Task Zachariasz Slupski");

    m_renderer = std::make_unique<VulkanRenderer>(*m_window);


}

Application::~Application() {

}

void Application::run() {
    while (!m_window->shouldClose()) {
        m_window->pollEvents();

        m_renderer->drawFrame();
    }

    m_renderer->waitIdle();
}

