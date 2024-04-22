//
// Created by Bingxi L on 2024/4/16.
//

#ifndef CPPPRIMER_13_05_H
#define CPPPRIMER_13_05_H

#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(10) {}

    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}

private:
    string *ps;
    int i;

};


#endif //CPPPRIMER_13_05_H
