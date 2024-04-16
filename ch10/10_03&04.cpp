//
// Created by Bingxi L on 2024/4/15.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main(){

    // 10_03
    vector<int> v = {1,2,3,4};
    cout << accumulate(v.cbegin(),v.cend(), 0) << endl;

    // 10_04
    vector<double> vd ={1.1 , 0.5, 3.3};
    cout << accumulate(vd.cbegin(),vd.cend(), 0) << endl;

    // The ouput is 4 rather than 4.9 as expected.
    // The reason is std::accumulate is a template function. The third parameter is _Tp __init
    // When "0" , an integer, had been specified here, the compiler deduced _Tp as
    // interger.As a result , when the following statments were being excuted :
    //  for (; __first != __last; ++__first)
    //	__init = __init + *__first;
    //  return __init;
    // all calculation would be converted to integer.

    return 0;
}