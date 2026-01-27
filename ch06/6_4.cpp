//
// Created by Bingxi L on 2024/3/7.
//
#include<iostream>

using namespace std;

int fact(int n) {
    return n > 0 ? n * fact(n - 1) : 1;
}

int main() {

    int n;
    cin >> n;
    if (n > 0) {
        cout << fact(n) << endl;
    }else{
        cout << "please enter + number!" << endl;
    }

    return 0;
}