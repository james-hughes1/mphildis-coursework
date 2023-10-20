#include <iostream>
#include <cmath>
#include <fstream>

int main() {
    // Take inputs
    double T, y, dt;
    std::cout << "Enter max time T: " << std::endl;
    std::cin >> T;
    std::cout << "Enter initial value y0: " << std::endl;
    std::cin >> y;
    std::cout << "Enter time-step dt: " << std::endl;
    std::cin >> dt;
    std::ofstream outFile("/home/jhughes2712/projects/scicomp_course/lesson_3/ode.dat"); // Open file
    double t=0;
    while (t <= T) {
        if ((t + dt > T) && (t != T)) {
            dt = T - t;
        }
        y = y + dt * sqrt(y);
        outFile << t << "   " << y << std::endl;
        t += dt;
    }
    outFile.close(); // Close file
}