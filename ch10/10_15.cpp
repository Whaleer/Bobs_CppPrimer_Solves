//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>

using namespace std;

int main() {

    int i = 42;
    auto add = [i](int num) { return i + num; };
}