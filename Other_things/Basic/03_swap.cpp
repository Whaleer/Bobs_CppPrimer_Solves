//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>

using namespace std;

void swap(int *p1, int *p2) {
    int p;
    p = *p1;
    *p1 = *p2;
    *p2 = p;
}

int main() {
    int a = 5;
    int b = 7;
    int *ptr1 = &a;
    int *ptr2 = &b;

    swap(ptr1, ptr2);
    printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}