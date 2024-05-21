//
// Created by Bingxi L on 2024/4/27.
//
#include <map>
#include <iostream>
#include <string>

using namespace std;


void print(map<string, size_t> const &m) {
    for (auto i: m)
        cout << i.first << ": " << i.second << "\n";
}


int main() {

    map<string, size_t> map;
    string word;
    while (cin >> word) {
        ++map[word];
    }
    print(map);

    return 0;
}