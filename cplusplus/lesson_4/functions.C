#include<iostream>
#include<cmath>

int sum(int a, int b) {
    return a+b;
}

void decrease(int &a, int b) {
    a -= b;
}

int q(double a, double b, double c, double &x1, double &x2) {
    double disc = (b*b) - (4*a*c);
    if (disc > 0){
        x1 = (-b + sqrt(disc)) / (2*a);
        x2 = (-b - sqrt(disc)) / (2*a);
        return 2;
    }
    else {
        if (disc == 0){
            x1 = (-b) / (2*a);
            x2 = (-b) / (2*a);
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main() {
    std::cout << sum(2,3) << std::endl;
    int myNum = 17;
    decrease(myNum, 5);
    std::cout << myNum << std::endl;
    double y1 = 18, y2 = 36;
    std::cout << q(1,0,-4,y1,y2) << "," << y1 << "," << y2 << "," << std::endl;
}