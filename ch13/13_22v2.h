//
// Created by Bingxi L on 2024/5/15.
//

#ifndef CPPPRIMER_13_22V2_H
#define CPPPRIMER_13_22V2_H

#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}

    HasPtr &operator=(const HasPtr &);

    ~HasPtr() { delete ps; }

private:
    string *ps;
    int i;
};

#endif //CPPPRIMER_13_22V2_H
