#include <iostream>
#define ASSERT(x) if( !(x) )\
{\
    std::cout << "Test " << #x << " failed at line " \
    << __LINE__ \
    << " in " << __FILE__ << std::endl; \
}

int main(){
    int a=5;
    ASSERT(a==5);
    ASSERT(a==6);
    return 0;
}