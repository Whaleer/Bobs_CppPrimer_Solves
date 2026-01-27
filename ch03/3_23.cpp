//
// Created by Bingxi L on 2024/2/11.
//
#include <iostream>
#include <vector>

using namespace std;
int main(){

    vector<int> v;
    for(int it; cin >> it; v.push_back(it));
    for(auto i : v)
        cout << i << " ";
    cout << endl;

    for(auto &it : v){
        it = 2 * it;
        cout << it << " ";
    }

    return 0;
}