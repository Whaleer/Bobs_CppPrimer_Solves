//
// Created by Bingxi L on 2024/4/18.
//
#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

void print_deg(const Quote &q);

double print_total(ostream &os, const Quote &item, size_t n);

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << endl;

    return ret;
}

void print_debug(const Quote &q) {
    q.debug();
}

int main() {
    Quote q("aaa", 10.0);
    Bulk_quote bq("bbb", 15.0, 10, 0.3);
    Limit_quote lq("ccc", 20.0, 10, 0.3);


    /*
     * 没有发生动态绑定，原因如下：
     * The compiler has known what the
     * r refering to at compile time. As a result, the virtual function debug of
     * the subobject is called.
     */
    Quote &ref = q;
    ref.debug();
    cout << endl;

    ref = bq; // Clang-Tidy: Slicing object from type 'Bulk_quote' to 'Quote' discards override 'debug'
    ref.debug();
    cout << endl;

    ref = lq;
    ref.debug();
    cout << endl;

    cout << "====================" << endl;
    /*
     * 发生了动态绑定
     */
    Quote &r = q;
    r.debug();
    cout << endl;

    Quote &r2 = bq;
    r2.debug();
    cout << endl;

    Quote &r3 = lq;
    r3.debug();
    cout << endl;

    cout << "====================" << endl;

    /*
     * 发生了动态绑定
     */
    print_debug(q);
    cout << endl;

    print_debug(bq);
    cout << endl;

    print_debug(lq);
    cout << endl;

}