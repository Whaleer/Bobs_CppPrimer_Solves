//
// Created by Bingxi L on 2024/5/14.
//
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

struct X {
    X() { cout << "X()" << endl; }

    X(const X &) { cout << "X(const X&)" << endl; }

    X &operator=(const X &rhs) { cout << "X& operator=(const X& rhs)" << endl; }

    ~X() { cout << "~X()" << endl; }
};

void f(const X &rx, X x) { // X x = *px 会调用拷贝构造 X(const X&)
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); // X(const X&)
    vec.push_back(x);  // X(const X&)
}

int main() {
    // 1次 X() 调用
    // 3次 X(const X&) 调用
    // 4次 ~X() 调用

    X *px = new X;  // X()
    f(*px, *px);
    delete px;
    return 0;
}