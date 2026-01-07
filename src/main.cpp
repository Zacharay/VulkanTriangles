
#include <iostream>
#include "Application.hpp"


int main(int argc, char* argv[]) {

    const int MAX_TRIANGLE = 10000;

    int triangleCount = 1000;

    if (argc > 1) {
        try {

            triangleCount = std::stoi(argv[1]);

            if(triangleCount < 1 || triangleCount > MAX_TRIANGLE) {
                triangleCount = 1000;
            }
        } catch (const std::exception& e) {
            std::cerr << "Blad parsowania argumentu! Uzywam domyslnej wartosci: " << triangleCount << std::endl;
        }
    }

    std::cout << "Uruchamianie z liczba trojkatow: " << triangleCount << std::endl;

    try {
        Application app(triangleCount);
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
