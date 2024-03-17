//
// Created by Bingxi L on 2024/3/7.
//
#include<iostream>

using namespace std;


int fact(int n) {
    if (n > 0) {
        return n * fact(n - 1);
    }else {
        return 1;
    }
}


int main() {

    int re = fact(5);
    cout << re << endl;
    return 0;
}