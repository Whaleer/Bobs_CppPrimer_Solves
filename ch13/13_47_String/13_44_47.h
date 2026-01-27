//
// Created by Bingxi L on 2024/5/17.
//

#ifndef CPPPRIMER_13_44_47_H
#define CPPPRIMER_13_44_47_H

#include <memory>
#include <string>

class String {
public:
    String() : String("") {} // ?
    String(const char *);

    String(const String &);

    String &operator=(const String &);

    ~String();

    const char *c_str() const { return elements; }

    size_t size() const { return end - elements; }

    size_t length() const { return end - elements - 1; }

private:
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);

    void range_initialize(const char *, const char *);

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




#endif //CPPPRIMER_13_44_47_H
