//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>

using namespace std;


int main() {
    char k = 'L';
    int count = 0;
    while (k > 3) {
        printf("%d", k);
        k = k / 2;
        count++;
    }
    cout << count << endl;

    return 0;
}