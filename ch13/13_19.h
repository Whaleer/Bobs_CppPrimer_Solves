//
// Created by Bingxi L on 2024/5/15.
//

#ifndef CPPPRIMER_13_19_H
#define CPPPRIMER_13_19_H

#include <string>

using namespace std;

class Employee {
public:
    Employee();

    Employee(const string &name);

    Employee(const Employee &) = delete;

    Employee &operator=(const Employee &) = delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int increment;
};

#endif //CPPPRIMER_13_19_H
