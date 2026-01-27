//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    for(int buffer; cin >> buffer; v.push_back(buffer));

    if(v.size() < 2){
        cout << "enter at least two intergers" << endl;
    }

    for(auto it = v.cbegin(); it + 1 != v.end(); it++){
        cout << *it + *(it + 1) << " ";
    }
    cout << endl;

    for(auto left = v.cbegin(), right = v.cend()-1; left <= right; left++, right--){
        cout << *left +  *right << " ";
    }
    cout << endl;

    return 0;
}