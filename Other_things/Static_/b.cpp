#include <iostream>
#include "a.cpp"

extern int b;


int main(){
    std::cout << "b = " << b << std::endl;
    return 0;
}

