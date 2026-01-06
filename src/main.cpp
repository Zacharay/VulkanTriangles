
#include <iostream>
#include "Application.hpp"


int main() {

    const int numberOfTriangles = 10000;

    try {
        Application app(numberOfTriangles);
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
