#include <iostream>

int** allocateMatrix (int N) {
    int* p = new int[N*N];
    int** q = new int*[N];
    for (int i=0; i<N; i++) {
        q[i] = p + i*N;
    }
    return q;
}

void freeMatrix(int** matrix, int N) {
    delete[] matrix[0];
    delete[] matrix;
}

int main() {
    int** A = allocateMatrix(5);
    A[1][2] = 27;
    std::cout << A[1][2] << std::endl;
    freeMatrix(A, 5);
    std::cout << A[3][4] << std::endl;

}