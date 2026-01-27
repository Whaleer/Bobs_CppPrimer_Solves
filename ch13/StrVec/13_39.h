//
// Created by Bingxi L on 2024/4/22.
//

#ifndef CPPPRIMER_13_39_H
#define CPPPRIMER_13_39_H

#include <memory>
#include <string>
#include <iostream>

class StrVec {

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &); // 拷贝构造函数
    StrVec &operator=(const StrVec &); // 拷贝赋值运算符
    ~StrVec(); // 析构函数
    void push_back(const std::string &); // 拷贝元素

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }


    void reserve(size_t new_cap);

    void resize(size_t count);

    void resize(size_t count, const std::string &);

private:
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free();

    void reallocate();

    void alloc_n_move(size_t new_cap);

private:
    static std::allocator<std::string> alloc; // 分配元素
    std::string *elements;    // 指向首元素的指针
    std::string *first_free; // 指向最后一个实际元素之后的位置
    std::string *cap;        // 指向内存末尾之后的位置
};

void StrVec::push_back(const std::string &s) {
    chk_n_alloc(); // 确保有足够的元素容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);

}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}


StrVec::~StrVec() {
    free();
}


StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    // 将数据从旧内存移动到新内存
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t new_cap) {
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count) {
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s) {
    if (count > size()) {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    } else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

#endif //CPPPRIMER_13_39_H
