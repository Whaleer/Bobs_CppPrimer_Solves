//
// Created by Bingxi L on 2024/4/22.
//

#ifndef CPPPRIMER_13_49_STRING_H
#define CPPPRIMER_13_49_STRING_H

#include <memory>
#include <algorithm>

class String {
public:
    String() : String("") {}

    String(const char *);

    String(const String &);

    String &operator=(const String &);

    String(String &&) noexcept;

    String &operator=(String &&) noexcept;

    ~String();

private:
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);

    void range_initializer(const char *, const char *);

    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e) {
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last) {
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s) {
    char *sl = const_cast<char *> (s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

void String::free() {
    if (elements) {
        std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String() {
    free();
}

String &String::operator=(const String &rhs) {
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    return *this;
}

String::String(String &&s) noexcept: elements(s.elements), end(s.end) {
    s.elements = s.end = nullptr;
}

String &String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    return *this;
}

#endif //CPPPRIMER_13_49_STRING_H
