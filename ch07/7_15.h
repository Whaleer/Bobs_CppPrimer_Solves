#ifndef CP5_ex7_15_h
#define CP5_ex7_15_h

#include <string>
#include <iostream>

using namespace std;

struct Person;

istream &read(istream &, Person &);

struct Person {
    Person() = default;

    Person(const string sname, const string saddr) : name(sname), address(saddr) {}

    Person(istream &is) {
        read(is, *this);
    }

    string getName() const { return name; }

    string getAddress() const { return address; }

    string name;
    string address;
};

istream &read(istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person) {
    os << person.name << " " << person.address;
    return os;
}


#endif