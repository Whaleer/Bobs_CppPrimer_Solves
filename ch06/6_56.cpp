#include <iostream>
#include <vector>
using namespace std;

int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);


int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }



int main(){

    vector<pFunc1> vec1;
    vector<pFunc2> vec2;
    vector<pFunc3> vec3;
    vector<pFunc4*> vec4;
    vector<pFunc5> vec5;
    vector<pFunc6*> vec6;


    vec1.push_back(add);
    vec1.push_back(subtract);
    vec1.push_back(multiply);
    vec1.push_back(divide);

    std::vector<decltype(func) *> vec{ add, subtract, multiply, divide };
    for (auto f : vec)
        std::cout << f(2, 2) << std::endl;
    return 0;
}