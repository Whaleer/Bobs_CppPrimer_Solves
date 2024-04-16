//
// Created by Bingxi L on 2024/4/11.
//
#include <iostream>

typedef union {
    long value;
    struct {
        char a;
        char b;
    } v;
} Type;

int main() {
    Type t;
    t.v.a = 0x5A;
    t.v.b = 0XA5;
    printf("value= %x\n", t.value);
    return 0;
}