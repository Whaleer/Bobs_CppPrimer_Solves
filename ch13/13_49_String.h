//
// Created by Bingxi L on 2024/4/22.
//

#ifndef CPPPRIMER_13_49_STRING_H
#define CPPPRIMER_13_49_STRING_H

#include <memory>

class String{
public:
    String() : String(""){}
    String(const char *);
    String(const String&);
    String& operator=(const String&);
    String(String &&) noexcept;
    String& operator=(String &&) noexcept;
    ~String();

private:


private:
    char * elements;
    char * end;
    std::allocator<char> alloc;
};

#endif //CPPPRIMER_13_49_STRING_H
