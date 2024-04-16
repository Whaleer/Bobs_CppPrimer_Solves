//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>

using namespace std;


int main() {
    char k = 'L';
    int num = (int)k;
    cout << num << endl;
    cout << "=====" << endl;
    while (k > 3) {
        printf("%d\n", k);
        k = k / 2;

    }
    return 0;
}