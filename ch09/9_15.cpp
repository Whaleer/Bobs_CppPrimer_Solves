//
// Created by Bingxi L on 2024/4/19.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3};
    vector<int> v3 = {1,2,6};

    cout << (v1 > v2 ? "true" : "false") << endl;
    cout << (v1 < v3 ? "true" : "false") << endl;

    return 0;
}