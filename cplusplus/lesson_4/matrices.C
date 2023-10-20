#include <iostream>
#include <array>

void matProp(std::array<std::array<int,3>,3> A) {
    int det1 = A[0][0]*(A[1][1]*A[2][2] - A[2][1]*A[1][2]);
    int det2 = A[0][1]*(A[1][0]*A[2][2] - A[2][0]*A[1][2]);
    int det3 = A[0][2]*(A[1][0]*A[2][1] - A[2][0]*A[1][1]);
    int det = det1 - det2 + det3;
    int trace = A[0][0] + A[1][1] + A[2][2];
    std::cout << "Det: " << det << ". Trace: " << trace << std::endl;
}

int main() {
    std::array<std::array<int,3>,3> X;
    for (int i=0; i<9; i++){
        std::cout << "Enter " << i << "th number: ";
        int input;
        std::cin >> X[i%3][i/3];
    }
    matProp(X);
    return 0;
}