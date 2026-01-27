//
// Created by Bingxi L on 2024/4/12.
//
#include <iostream>
using namespace std;

char *getmemory(void) {
    char p[] = "hello world";
    return p;
}

void test(void) {
    char *str = NULL;
    str = getmemory();
    cout << *str << endl;
}

int main(){
    test();
    return 0;
}