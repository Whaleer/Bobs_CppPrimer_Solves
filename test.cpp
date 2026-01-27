#include <iostream>
using namespace std;

class Base {
public:
    virtual void f() { cout << "Base::f\n"; }
    virtual void g() { cout << "Base::g\n"; }
    virtual void h() { cout << "Base::h\n"; }
};

class Derived : public Base {
public:
    void f() override { cout << "Derived::f\n"; }  // override
    void g() override { cout << "Derived::g\n"; }  // override
    void h2()        { cout << "Derived::h2\n"; }  // not virtual
};

int main() {
    Base* p = new Derived();
    p->f();  // Derived::f
    p->g();  // Derived::g
    p->h();  // Base::h（没有被重写）
    // p->h2();  // ❌ 编译错误！Base 类没有 h2()
}

