//
// Created by Bingxi L on 2024/4/25.
//
#include <functional>
#include <iostream>

using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() > sz;
}

int main() {
    auto check6 = bind(check_size, std::placeholders::_1, 6);
    cout << check6("asdasdasda") << endl;
    return 0;
}