//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>

using namespace std;

int main(){

    int arr[3] = {1,2,3};
    int *p = arr;
    for(int i = 0; i < 3; i++){
        *(p + i) = 0;
    }

    for(auto i :arr){
        cout << i << endl;
    }
    return 0;
}