//
// Created by Bingxi L on 2024/4/18.
//

#ifndef CPPPRIMER_QUOTE_H
#define CPPPRIMER_QUOTE_H

#include <string>
#include <iostream>

using namespace std;

class Quote {
public:
    Quote() = default;

    Quote(const string &b, double p) : bookNo(b), price(p) {}

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual void debug() const;

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price = 0.0;
};

void Quote::debug() const {
    cout << "data members of this class: "
         << "bookNo=" << this->bookNo << " "
         << "price= " << this->price << " ";
}

#endif //CPPPRIMER_QUOTE_H
