#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <cstdint>

class Window {
public:
    Window(uint32_t width, uint32_t height, const std::string& title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool shouldClose() const;
    void pollEvents();


    void createSurface(VkInstance instance, VkSurfaceKHR* surface);
    void getFramebufferSize(int* width, int* height) const;

    GLFWwindow* getNativeWindow() const { return m_window; }

private:
    GLFWwindow* m_window;
    uint32_t m_width;
    uint32_t m_height;
    std::string m_title;

    void init();
};