#include <iostream>
#define POW2(i) 1 << i
#define MIN(a,b) (((a) < (b)) ? (a) : (b) )
#define DISPLAY(x) std::cout << "At line " << __LINE__ << " " << #x << " = " << x << std::endl;

int main() {
    int i = POW2(3);
    std::cout << POW2(8) << std::endl;
    int a=15, b=7;
    std::cout << a << b << std::endl;
    std::cout << MIN(a++,b++) << std::endl;
    std::cout << a << b << std::endl;
}