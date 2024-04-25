//
// Created by Bingxi L on 2024/4/25.
//
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 10_34
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << " ";
    cout << endl;

    // 10_35
    for (auto it = prev(vec.cend()); true; it--) {
        cout << *it << " ";
        if (it == vec.cbegin()) break;
    }
    cout << endl;


    // 10_36
    list<int> lst = {1, 2, 3, 0, 3, 2, 1};
    auto fount_0 = find(lst.crbegin(), lst.crend(), 0);
    cout << distance(fount_0, lst.crend()) << endl;


    // 10_37
    std::list<int> ret_lst(8 - 3);
    std::copy(vec.cbegin() + 3, vec.cbegin() + 8, ret_lst.rbegin());
    //     0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //           ^              ^
    //          rend          rbegin
    // @note: std::copy copies the range [first, last) into result.
    //        hence, the arguments here denote:
    //        [7 6 5 4 3 2)
    //                   ^ this one is specified but not included.
    for (auto i: ret_lst) std::cout << i << " ";
    std::cout << std::endl;


    return 0;
}