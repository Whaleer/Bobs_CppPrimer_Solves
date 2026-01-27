//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(int a, int b) {
    return a > b;
}

int main() {

    vector<int> v = {3, 4, 1, 7, 9, 5, 0, 2};
    sort(v.begin(), v.end(), cmp);

    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}