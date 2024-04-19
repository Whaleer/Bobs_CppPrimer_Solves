//
// Created by Bingxi L on 2024/4/17.
//
#include <iostream>

class Base {
public:
    virtual void show() {  // 声明为虚函数
        std::cout << "Base class show function called." << std::endl;
    }
    virtual ~Base() {}  // 虚析构函数
};

class Derived : public Base {
public:
    void show() override {  // 重写虚函数
        std::cout << "Derived class show function called." << std::endl;
    }
};

void display(Base* b) {
    b->show();  // 动态绑定在此发生
}

int main() {
    Base* b = new Base();

    // Derived *d = new Derived(); 也可以
    Base* d = new Derived();

    display(b);  // 输出: Base class show function called.
    display(d);  // 输出: Derived class show function called.

    delete b;
    delete d;
    return 0;
}
