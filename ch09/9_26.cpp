//
// Created by Bingxi L on 2024/4/19.
//
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {

    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(begin(ia), end(ia));
    list<int> li(vec.begin(), vec.end());

    for (auto it = li.begin(); it != li.end();) {
        if (*it & 0x1) it = li.erase(it);
        else ++it;
    }

    for (auto it = vec.begin(); it != vec.end();) {
        if (!(*it & 0x1)) it = vec.erase(it);
        else ++it;
    }

    for (auto i: li) cout << i << " ";
    cout << endl;
    for (auto i: vec) cout << i << " ";
    cout << endl;


    return 0;
}