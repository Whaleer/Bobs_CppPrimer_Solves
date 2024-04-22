//
// Created by Bingxi L on 2024/4/22.
//
#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}

    HasPtr &operator=(const HasPtr &rhs_hp) {
        if (this != &rhs_hp) {
            string *tmp_ps = new string(*rhs_hp.ps);
            delete ps;
            ps = tmp_ps;
            i = rhs_hp.i;
        }
        return *this;
    }

    string getPs() {
        return *ps;
    }

private:
    string *ps;
    int i;
};

int main() {
    /*
     * 声明一个新的对象并且同时用另一个现有对象进行初始化时，会触发拷贝构造函数
     * 拷贝赋值运算符是在两个已经存在的对象之间赋值时使用的
     */
    HasPtr p1("hello");
    HasPtr p2 = p1;             // 调用的是拷贝构造函数
    HasPtr p3("initial");
    p3 = p1;                    // 调用拷贝赋值运算符
    cout << p1.getPs() << endl;
    cout << p2.getPs() << endl;
    cout << p3.getPs() << endl;

    return 0;
}