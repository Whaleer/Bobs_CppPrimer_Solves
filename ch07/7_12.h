#ifndef CP5_ex7_11_h
#define CP5_ex7_11_h

#include <iostream>
#include <string>

using namespace std;
struct Sales_data;

istream &read(istream &is, Sales_data &);

struct Sales_data {
    Sales_data() = default;

    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}

    Sales_data(istream &is) {
        read(is, *this);
    }

    string isbn() const { return bookNo; };

    Sales_data &combine(const Sales_data &);


    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


#endif