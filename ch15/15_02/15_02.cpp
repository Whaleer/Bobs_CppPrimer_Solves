//
// Created by Bingxi L on 2024/4/17.
//
#include <string>
#include <iostream>

using namespace std;

class Quote {

public:
    Quote() = default;

    Quote(const string &b, double p) : bookNo(b), price(p) {}

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn() << "# sold:" << n << " total due: " << ret << endl;
    return ret;
}

int main(){

    // quote 在栈上创建，当它的作用域结束（即函数或代码块结束时），quote 会自动被销毁，不需要手动管理内存
    Quote quote("book1", 5.0);

    // quote2 在堆上创建，使用 new 操作符在堆上动态分配内存
    Quote * quote2 = new Quote("book2", 6.0);

    print_total(cout, quote, 3);
    print_total(cout, *quote2, 3);
    return 0;
}