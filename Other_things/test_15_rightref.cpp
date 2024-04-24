//
// Created by Bingxi L on 2024/4/21.
//
#include <iostream>

using namespace std;

int main() {

    int a = 5;
    int &&ref = std::move(a);
    cout << ref << endl;


    return 0;
}