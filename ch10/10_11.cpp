//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &vec) {
    sort(vec.begin(), vec.end());
    auto unique_end = unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.end());
}


int main() {

    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);

    for (auto &i: vec)
        cout << i << " ";
    cout << endl;

    return 0;
}