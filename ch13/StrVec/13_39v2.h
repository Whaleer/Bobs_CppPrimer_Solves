//
// Created by Bingxi L on 2024/5/17.
//

#ifndef CPPPRIMER_13_39V2_H
#define CPPPRIMER_13_39V2_H

#include <string>
#include <memory>

using namespace std;

/*
 *  1. 构造函数隐式地默认初始化 alloc ， 显式地将指针初始化为 nullptr，表明没有元素
 *  2. size 成员返回当前真正在使用的元素的数目，等于 first_free - elements
 *  3. capacity 成员返回 StrVec 可以保存的元素数量，等价于 cap - elements
 *  4. 当没有空间容纳新元素，即 cap == first_free 时， chk_n_alloc 会为 StrVec 重新分配内存
 *  5. begin 和 end 成员分别返回指向首元素和最后一个构造的元素之后的位置（即 first_free）指针
 * */
class StrVec {

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &); // 拷贝构造函数
    StrVec &operator=(const StrVec &); // 拷贝赋值运算符
    ~StrVec(); // 析构函数

    void push_back(const string &); // 拷贝元素
    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    string *begin() const { return elements; }

    string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);

private:
    static allocator<string> alloc; // 分配元素
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }

    // 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free();

    void reallocate();
    void alloc_n_move(std::size_t new_cap);

    string *elements; // 指向数组首元素的指针
    string *first_free; // 指向数组第一个空闲元素的指针
    string *cap; // 指向数组尾后位置的指针

};

/*
 * push_back 首先调用 chk_n_alloc 确保有空间容纳新元素
 * 如果需要，chk_n_alloc 会调用 reallocate
 *
 * */
void StrVec::push_back(const std::string &s) {
    chk_n_alloc(); // 确保有空间容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}


/*
 * alloc_n_copy成员会分配足够的内存来保存给定范围的元素，
 * 并将这些元素拷贝到新分配的内存中。
 * 次函数返回一个指针的 pair，两个指针分别指向新空间的开始位置和拷贝的尾后的位置
 * */
pair<string *, string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair，该 pair 由 data 和 uninitialized——copy 的返回值构成
    return {data, uninitialized_copy(b, e, data)};
}

/*
 * free 成员的任务
 * 1. destroy 元素
 * 2. 释放 StrVec 自己分配的内存空间
 * */
void StrVec::free() {
    if (elements) {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        // 释放空间
        alloc.deallocate(elements, cap - elements);
    }
}

// 实现拷贝控制成员
StrVec::StrVec(const StrVec &s) {
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 析构函数
StrVec::~StrVec() {
    free();
};

// 拷贝赋值运算符
StrVec &StrVec::operator=(const StrVec &rhs) {
    // 调用alloc_n_copy分配内存，大小与 rhs 中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    return *this;
}

/*
 * reallocate 函数应该做什么？
 * 1. 为一个新的，更大的 string 数组分配内存
 * 2. 在内存空间的前一部分构造对象，保存现有元素
 * 3. 销毁原内存空间中的元素，并释放这块内存
 *
 *
 * */
void StrVec::reallocate() {
    // 分配当前大小2倍的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);
    // 将数据从旧内存移动到新内存
    auto dest = newdata; // 指向新数组中下一个空闲位置
    auto elem = elements; // 指向旧数组中下一个元素
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // 一旦移动完元素就释放旧内存
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}


#endif //CPPPRIMER_13_39V2_H
