//
// Created by Bingxi L on 2024/4/16.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isLessthan6(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {

    vector<string> s = {"aasdz", "xzc", "ss", "sadasdas", "aasdqwe"};
    int re = count_if(s.begin(), s.end(), bind(isLessthan6, _1, 6));
    cout << re << endl;

    return 0;
}