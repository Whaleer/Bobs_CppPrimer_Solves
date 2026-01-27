#include <iostream>

#define num 5

void func();

int main() {
    printf("%d ", num);
    func();
    printf("%d", num);
}

void func() {
#undef num
#define num 1
}