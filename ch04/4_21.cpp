//
// Created by Bingxi L on 2024/2/18.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    for(int buf; cin >> buf ; v.push_back(buf)){
        if(buf % 2 == 1){
            buf *= 2;
        }
    }

    for(auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}