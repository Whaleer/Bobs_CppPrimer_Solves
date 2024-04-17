//
// Created by Bingxi L on 2024/4/16.
//

#ifndef CPPPRIMER_13_18_H
#define CPPPRIMER_13_18_H

#include <string>

using namespace std;

class Employee {
public:
    Employee();

    Employee(const string &name);

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

int main() {

}


#endif //CPPPRIMER_13_18_H
