//
// Created by Bingxi L on 2024/4/22.
//

#ifndef CPPPRIMER_13_30_H
#define CPPPRIMER_13_30_H

#include <string>
#include <iostream>

class HasPtr {

public:
    friend void swap(HasPtr &, HasPtr &);

    HasPtr(const std::string &s = std::string()) : ps(new std::string()), i(0) {}

    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

    HasPtr &operator=(const HasPtr &&hp) {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }

    void show() { std::cout << *ps << std::endl; }

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    /*
     * 这里使用了 using std::swap;，意味着如果存在更适合的 swap 版本（例如对于成员指针 lhs.ps 类型的自定义 swap 函数），
     * 编译器会优先使用那个版本。
     * 如果没有更具体的版本，编译器将回退到使用 std::swap。
     * 这种方法通常被推荐，因为它可以提供最佳的类型匹配和异常安全性。
     */
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif //CPPPRIMER_13_30_H
