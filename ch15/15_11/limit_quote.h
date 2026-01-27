//
// Created by Bingxi L on 2024/4/18.
//

#ifndef CPPPRIMER_LIMIT_QUOTE_H
#define CPPPRIMER_LIMIT_QUOTE_H

#include "quote.h"
#include <iostream>

using namespace std;

class Limit_quote : public Quote {
public:
    Limit_quote();

    Limit_quote(const string &b, double p, size_t max, double disc) : Quote(b, p), max_qty(max), discount(disc) {}

    double net_price(size_t n) const override {
        return n * price * (n < max_qty ? 1 - discount : 1);
    }

    void debug() const override;

private:
    size_t max_qty = 0;
    double discount = 0.0;
};

void Limit_quote::debug() const {
    Quote::debug();
    cout << "max_qty= " << this->max_qty << " "
         << "discount= " << this->discount << " ";
}

#endif //CPPPRIMER_LIMIT_QUOTE_H
