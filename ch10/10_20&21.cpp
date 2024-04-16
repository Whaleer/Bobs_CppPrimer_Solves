//
// Created by Bingxi L on 2024/4/16.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 10_20
size_t bigerThan6(vector<string> const &v) {
    return count_if(v.cbegin(), v.cend(), [](string const &s) {
        return s.size() > 6;
    });
}


int main() {

    vector<string> v{"alan","moophy","asdqweasdqw","asdbbbbbbasd"};
    cout << bigerThan6(v) << endl;

    // ex10.21
    int i = 7;
    auto check_and_decrement = [&i]() { return i > 0 ? !--i : !i; };
    cout << "ex10.21: ";
    while(!check_and_decrement())
        cout << i << " ";
    cout << i << endl;

    return 0;
}