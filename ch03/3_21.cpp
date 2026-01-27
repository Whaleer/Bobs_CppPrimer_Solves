//
// Created by Bingxi L on 2024/2/11.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v3(10,42);
    for(auto it = v3.begin(); it != v3.end(); it++)
        cout << *it << endl;

    return 0;
}