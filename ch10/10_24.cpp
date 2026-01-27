//
// Created by Bingxi L on 2024/4/25.
//
#include <functional>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


auto check_size(string const &str, size_t sz) {
    return str.size() < sz;
}

int main() {

    string s = "asdas";
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = find_if(vec.begin(), vec.end(), bind(check_size, s, std::placeholders::_1));
    if (result != vec.end())
        cout << *result << endl;
    else
        cout << "not found" << endl;
    return 0;
}