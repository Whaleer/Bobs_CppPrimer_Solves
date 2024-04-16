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

bool isLessThan6(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {


    vector<string> authors{"moophy", "zezy", "qweSSSasda", "asdass", "sda"};
    cout << count_if(authors.cbegin(), authors.cend(), bind(isLessThan6, _1, 6));

}