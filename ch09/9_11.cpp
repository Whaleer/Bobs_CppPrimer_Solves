//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>

using namespace std;
int main(){

    vector<int> vec1;
    vector<int> vec2(10);
    vector<int> vec3(10,1);
    vector<int> vec4{1,2,3,4,5};
    vector<int> vec5(vec1);
    vector<int> vec6(vec2.begin(), vec2.end());



    return 0;
}