//
// Created by Bingxi L on 2024/5/15.
//
#include <iostream>

using namespace std;


class Employee {
public:
    Employee() {
        ID_ = increment++;
    }

    Employee(const string &name) : name_(name) {
        ID_ = increment++;
    }

private:
    string name_;
    int ID_;
    static int increment;
};

int Employee::increment = 0;

int main() {

}