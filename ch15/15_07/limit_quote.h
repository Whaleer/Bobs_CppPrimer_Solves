//
// Created by Bingxi L on 2024/4/17.
//

#ifndef CPPPRIMER_LIMIT_QUOTE_H
#define CPPPRIMER_LIMIT_QUOTE_H

#include "quote.h"

using namespace std;

class Limit_quote : public Quote {
public:
    Limit_quote() = default;

    Limit_quote(const string &b, double p, size_t max, double disc) : Quote(b, p), max_qty(max), discount(disc) {}

    double net_price(size_t n) const override;

private:
    size_t max_qty = 0;
    double discount = 0.0;
};

double Limit_quote::net_price(size_t n) const {
    if (n > max_qty)
        return max_qty * price * discount + (n - max_qty) * price;
    else
        return n * discount * price;
}


#endif //CPPPRIMER_LIMIT_QUOTE_H
