#pragma once
#include <glm/glm.hpp>
#include <array>

struct Plane {
    glm::vec3 normal;
    float distance;

    void normalize() {
        float length = glm::length(normal);
        normal /= length;
        distance /= length;
    }
};

class Frustum {
public:
    std::array<Plane, 6> planes;

    void update(const glm::mat4& viewProjection) {
        const auto& m = viewProjection;

        // Left
        planes[0].normal.x = m[0][3] + m[0][0];
        planes[0].normal.y = m[1][3] + m[1][0];
        planes[0].normal.z = m[2][3] + m[2][0];
        planes[0].distance = m[3][3] + m[3][0];

        // Right
        planes[1].normal.x = m[0][3] - m[0][0];
        planes[1].normal.y = m[1][3] - m[1][0];
        planes[1].normal.z = m[2][3] - m[2][0];
        planes[1].distance = m[3][3] - m[3][0];

        // Bottom
        planes[2].normal.x = m[0][3] + m[0][1];
        planes[2].normal.y = m[1][3] + m[1][1];
        planes[2].normal.z = m[2][3] + m[2][1];
        planes[2].distance = m[3][3] + m[3][1];

        // Top
        planes[3].normal.x = m[0][3] - m[0][1];
        planes[3].normal.y = m[1][3] - m[1][1];
        planes[3].normal.z = m[2][3] - m[2][1];
        planes[3].distance = m[3][3] - m[3][1];

        // Near
        planes[4].normal.x = m[0][3] + m[0][2];
        planes[4].normal.y = m[1][3] + m[1][2];
        planes[4].normal.z = m[2][3] + m[2][2];
        planes[4].distance = m[3][3] + m[3][2];

        // Far
        planes[5].normal.x = m[0][3] - m[0][2];
        planes[5].normal.y = m[1][3] - m[1][2];
        planes[5].normal.z = m[2][3] - m[2][2];
        planes[5].distance = m[3][3] - m[3][2];

        for (auto& plane : planes) plane.normalize();
    }


    bool checkSphere(const glm::vec3& center, float radius) const {
        for (const auto& plane : planes) {

            if (glm::dot(plane.normal, center) + plane.distance < -radius) {
                return false;
            }
        }
        return true;
    }
};
