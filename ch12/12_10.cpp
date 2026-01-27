//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {
    cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main() {
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));

    cout << p.use_count() << "\n";
    auto q = p;
    cout << p.use_count() << "\n";
    cout << "the int p now points to is :" << *p << "\n";
    return 0;

}