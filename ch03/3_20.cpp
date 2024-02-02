//
// Created by Bingxi L on 2024/2/2.
//
#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> vec;
    for (int i; cin >> i; vec.push_back(i));

    if (vec.empty()) {
        cout << "input at least one interger!" << endl;
        return -1;
    }

    if (vec.size() == 1) {
        cout << "only one integer" << endl;
    }

    for (int i = 0; i < vec.size() - 1; ++i) {
        cout << vec[i] + vec[i+1] << " ";
    }
    cout << endl;

    return 0;
}