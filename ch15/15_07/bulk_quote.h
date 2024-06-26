//
// Created by Bingxi L on 2024/4/17.
//

#ifndef CPPPRIMER_BULK_QUOTE_H
#define CPPPRIMER_BULK_QUOTE_H

#include "quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;

    Bulk_quote(const string &b, double p, size_t q, double disc) : Quote(b, p), min_qty(q), discount(disc) {}

    double net_price(size_t n) const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t n) const {
    return n * price * (n >= min_qty ? 1 - discount : 1);
}

#endif //CPPPRIMER_BULK_QUOTE_H
