#include <iostream>

int main() {
    signed int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    while (x < 0) {
        std::cout << "Please enter a positive integer: ";
        std::cin >> x;
    }
    for (int i=0 ; i<=x ; i++) {
        std::cout << i << " * " << i << " = " << i << "." << std::endl;
    }
    return 0;
}