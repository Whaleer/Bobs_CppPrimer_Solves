//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

bool contains (vector<int>::const_iterator first, vector<int>::const_iterator last, int value){
    for(; first != last; ++first){
        if(*first == value){
            return true;
        }
        return false;
    }
}


