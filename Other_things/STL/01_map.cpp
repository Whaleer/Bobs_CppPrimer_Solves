//
// Created by Bingxi L on 2024/3/27.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    unordered_map<char, int> map;
    string s = "abcc";
    for (char c: s) {
        map[c]++;
    }

    for(auto & item: map){
        cout << item.first << " " << item.second << endl;
    }

    cout << map.size() << endl;
    return 0;
}