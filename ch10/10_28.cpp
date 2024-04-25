//
// Created by Bingxi L on 2024/4/25.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template<typename T>
void print(T const &seq) {
    for (const auto &i: seq) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // inserter
    list<int> lst1;
    copy(vec.begin(), vec.end(), inserter(lst1, lst1.begin()));
    print(lst1);

    // back_inserter
    list<int> lst2;
    copy(vec.begin(),vec.end(), back_inserter(lst2));
    print(lst2);

    // front_inserter
    list<int> lst3;
    copy(vec.begin(),vec.end(), front_inserter(lst3));
    print(lst3);



    return 0;
}