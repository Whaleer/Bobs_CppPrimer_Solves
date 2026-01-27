//
// Created by Bingxi L on 2024/2/2.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    // 1
    vector<int> s1(10,42);

    // 2
    vector<int> s2;


    // 3
    vector<int> s3;
    for(int i = 0; i < 10; i++){
        s3.push_back(42);
    }

    return 0;
}