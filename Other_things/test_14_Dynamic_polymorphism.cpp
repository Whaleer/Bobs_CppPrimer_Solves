//
// Created by Bingxi L on 2024/4/18.
//
#include <iostream>

// 基类
class Base {
public:
    virtual void show() {  // 虚函数
        std::cout << "Base class show function called." << std::endl;
    }
    virtual ~Base() {}  // 虚析构函数
};

// 派生类
class Derived : public Base {
public:
    void show() override {  // 重写虚函数
        std::cout << "Derived class show function called." << std::endl;
    }
};

int main() {
    Base* b;           // 基类指针
    Derived d;         // 派生类对象
    b = &d;

    Base& p = d;
    p.show();
    b->show();         // 调用 Derived 的 show()
    return 0;
}
