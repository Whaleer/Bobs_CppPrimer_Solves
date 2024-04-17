//
// Created by Bingxi L on 2024/4/17.
//
#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main() {

    Quote q("textbook", 10.0);
    Bulk_quote bq("textbook", 10.0, 10, 0.3);
    Limit_quote lq("Bible", 10.0, 10, 0.3);

    print_total(cout, q, 5);
    print_total(cout, bq, 5);
    print_total(cout, lq, 5);


    return 0;
}