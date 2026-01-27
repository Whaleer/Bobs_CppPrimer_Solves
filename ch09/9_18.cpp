//
// Created by Bingxi L on 2024/4/19.
//
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {

    deque<string> deq;
    string s;
    while (cin >> s) {
        deq.push_back(s);
    }

    for (auto i: deq) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}