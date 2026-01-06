#include "Camera.hpp"

#include <glm/ext/matrix_transform.hpp>


Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up) {
    m_position = position;
    m_front = front;
    m_up = up;

    yaw = -90.0f;
    pitch = 0.0f;
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}
void Camera::processKeyboardInput(CameraMovement direction, double deltaTime) {
    const float cameraSpeed = 50.0f * deltaTime;

    glm::vec3 right = glm::normalize(glm::cross(m_front, m_up));

    if(CameraMovement::FORWARD == direction) {
        m_position += m_front * cameraSpeed;
    }
    else if(CameraMovement::BACKWARDS == direction) {
        m_position -= m_front * cameraSpeed;
    }
    else if (CameraMovement::RIGHT == direction) {
        m_position += right * cameraSpeed;
    }
    else if(CameraMovement::LEFT == direction) {
        m_position -= right * cameraSpeed;
    }
    else if(CameraMovement::UP == direction) {
        m_position += m_up * cameraSpeed;
    }
    else if(CameraMovement::DOWN == direction) {
        m_position -= m_up * cameraSpeed;
    }
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::processMouseInput(float xOffset, float yOffset) {

    yaw   += xOffset * 1.5f;
    pitch += yOffset * 1.5f;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    m_front = glm::normalize(direction);

    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

const glm::mat4& Camera::getViewMatrix() const {

    return m_viewMatrix;
}
const glm::vec3& Camera::getFront()const {
    return m_front;
}
const glm::vec3& Camera::getPosition()const {
    return m_position;
}
