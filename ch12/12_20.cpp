//
// Created by Bingxi L on 2024/4/11.
//
#include "12_19.h"
#include <fstream>
#include <iostream>

using namespace std;

// g++ 12_19.cpp 12_20.cpp
// ./a.out

int main()
{
    ifstream ifs("./12_20_test.txt");
    StrBlob blob;
    for (string str; getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
    return 0;
}


