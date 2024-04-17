//
// Created by Bingxi L on 2024/4/17.
//

#ifndef CPPPRIMER_QUOTE_H
#define CPPPRIMER_QUOTE_H

#include <string>

using namespace std;

class Quote {
public:
    Quote() = default;

    Quote(const string &s, double p) : bookNo(s), price(p) {}

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price = 0.0;
};

#endif //CPPPRIMER_QUOTE_H
