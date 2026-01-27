//
// Created by Bingxi L on 2024/4/18.
//

#ifndef CPPPRIMER_DISC_QUOTE_H
#define CPPPRIMER_DISC_QUOTE_H


#include "quote.h"

using namespace std;

class Disc_quote : public Quote {

public:
    Disc_quote();

    Disc_quote(const string &b, double p, size_t q, double d) :
            Quote(b, p), quantity(q), discount(d) {}

    virtual double net_price(size_t n) const override = 0;

protected:
    size_t quantity;
    double discount;
};

#endif //CPPPRIMER_DISC_QUOTE_H
