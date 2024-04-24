//
// Created by Bingxi L on 2024/4/18.
//

#ifndef CPPPRIMER_BULK_QUOTE_H
#define CPPPRIMER_BULK_QUOTE_H

#include "disc_quote.h"
class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
            Disc_quote(b, p, q, disc) {   }

    double net_price(std::size_t n) const override;
    void  debug() const override;
};


#endif //CPPPRIMER_BULK_QUOTE_H
