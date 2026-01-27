//
// Created by Bingxi L on 2024/4/25.
//
#include <iostream>
#include <string>
#include <list>

using namespace std;

void elimDups(list<string> &words) {
    words.sort();
    words.unique();
}

int main() {
    list<string> l = {"aa", "aa", "aa", "aa", "aasss", "aa"};
    elimDups(l);

    for (auto &e: l)
        cout << e << " ";
    cout << endl;
    return 0;
}