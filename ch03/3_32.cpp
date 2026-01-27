//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[10];
    for (auto i = 0; i < 10; ++i) arr[i] = i;
    for (auto i : arr) cout << i << " ";
    cout << endl;

    vector<int> v;
    for(auto i : arr){
        v.push_back(i);
    }

    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}