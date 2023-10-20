#include <iostream>

void calcNextRow(int* prevRow, int* nextRow, int rowNo) {
    std::cout << "Row " << rowNo << ": 1 ";
    for (int i=1; i<rowNo-1; i++) {
        nextRow[i] = prevRow[i] + prevRow[i-1];
        std::cout << nextRow[i] << " ";
    }
    nextRow[rowNo-1] = 1;
    std::cout << "1" << std::endl;
}

int main() {
    int N;
    std::cout << "Enter max row number: ";
    std::cin >> N;
    int* prevRow = new int[5];
    int* nextRow = new int[5];
    prevRow[0] = 1;
    nextRow[0] = 1;
    for (int n=2; n<=N; n++){
        calcNextRow(prevRow, nextRow, n);
        int* tmpRow = prevRow;
        prevRow = nextRow;
        nextRow = tmpRow;
    }
    return 0;
}