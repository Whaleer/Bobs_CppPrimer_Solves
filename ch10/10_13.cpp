//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool predicate(const string &s) {
    return s.size() >= 5;
}


int main() {

    vector<string> vec = {"asd", " asdqweqwe", "asdfgfdsg", "zvd", "as"};
    auto end = partition(vec.begin(), vec.end(), predicate);

    for (auto iter = vec.cbegin(); iter != end; iter++) {
        cout << *iter << " ";
    }
    cout << endl;


    for (auto iter = vec.cbegin(); iter != vec.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}