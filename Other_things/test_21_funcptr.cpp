//
// Created by Bingxi L on 2024/5/16.
//
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*operationPtr)(int, int);
    operationPtr = &add;
    int ans = operationPtr(10, 5);
}