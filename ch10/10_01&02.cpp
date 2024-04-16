//
// Created by Bingxi L on 2024/4/15.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {

    vector<int> vec{12, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int cnt = count(vec.cbegin(), vec.cend(), 4);
    cout << cnt << endl;

    list<string> l = {"aa", "aaa", "aa", "cc"};
    cout << count(l.cbegin(), l.cend(), "aa") << endl;


    return 0;
}