//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {

    list<const char *> l{"Mooophy", "pezy", "Queeuqueg"};
    vector<string> v;
    v.assign(l.cbegin(), l.cend());
    for (auto ptr: v) {
        cout << ptr << endl;
    }

    return 0;
}