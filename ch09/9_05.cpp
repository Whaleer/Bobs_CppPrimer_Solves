//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

auto contains (vector<int>::const_iterator first, vector<int>::const_iterator last, int value){
    for(; first != last; ++first){
        if(*first == value){
            return first;
        }
        return last;
    }
}




