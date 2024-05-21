//
// Created by Bingxi L on 2024/4/22.
//
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;


char *strcpy(char *dst, const char *src) {
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    while ((*dst++ = *src++) != '\0');
    return ret;
}

int main() {
    char a[] = "hello";
    char b[] = {};
    strcpy(b, a);
    printf("%s", b);
}
