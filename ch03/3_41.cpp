//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>
#include <vector>

using namespace std;
int main(){
    const int size = 5;
    int arr[size] = {1,2,3,4,5};
    vector<int> v(begin(arr),end(arr));
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}