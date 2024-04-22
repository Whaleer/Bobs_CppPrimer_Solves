//
// Created by Bingxi L on 2024/4/16.
//
#include <iostream>

using namespace std;

class numbered {
public:
    numbered() {
        mysn = unique++;
        cout << "constructor is called" << endl;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) {
    cout << s.mysn << endl;
}

int main() {

    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}