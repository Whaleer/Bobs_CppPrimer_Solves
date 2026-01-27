//
// Created by Bingxi L on 2024/3/7.
//
// example
#include "iostream"

using namespace std;
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

size_t count_calls(){
    static size_t cnt = 0;
    cnt++;
    return cnt;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
        cout << count_add(i) << endl;

    cout << "======" << endl;

    for (int i = 0; i < 10; ++i) {
        cout << count_calls() << endl;
    }

    return 0;
}