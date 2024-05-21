//
// Created by Bingxi L on 2024/5/21.
//

#ifndef CPPPRIMER_14_02_H
#define CPPPRIMER_14_02_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data {
    friend istream &operator>>(istream &, Sales_data &); // input
    friend ostream &operator<<(ostream &, const Sales_data &); // output
    friend Sales_data operator+(const Sales_data &, const Sales_data &); // addition

public:
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}

    Sales_data() : Sales_data("", 0, 0.0f) {}

    Sales_data(const string &s) : Sales_data(s, 0, 0.0f) {} // 委托构造函数
    Sales_data(istream &is);

    Sales_data &operator=(const Sales_data &);

    string isbn() const { return bookNo; }

private:
    inline double avg_prive() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

istream &operator>>(istream &, Sales_data &);

ostream &operator<<(std::ostream &, const Sales_data &);

Sales_data operator+(const Sales_data &, const Sales_data &);

#endif //CPPPRIMER_14_02_H
