//
// Created by Bingxi L on 2024/4/25.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main() {

    vector<int> vec{1, 1, 3, 4, 5, 6, 6, 7, 8};
    list<int> lst;
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for (auto i: lst) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}