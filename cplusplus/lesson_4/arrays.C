#include<iostream>
#include<array>

void partials(std::array<int,20> a, std::array<int,20> &b) {
    b[0] = a[0];
    for (int i=1; i<20; i++){
        b[i] = b[i-1] + a[i];
    }
}

int main() {
    std::array<int,20> x;
    std::array<int,20> y;
    for (int i=0; i<20; i++) {
        x[i] = i;
    }
    partials(x,y);
    for (int i=0; i<20; i++) {
        std::cout << i << "th triangular number: " << y[i] << std::endl;
    }
    return 0;
}