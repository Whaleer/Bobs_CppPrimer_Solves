#include "iostream"

using namespace std;


void change_num(int *p1, int *p2) {

    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main() {

    int a = 2;
    int b = 5;

    change_num(&a, &b);
    cout << "a = " << a << endl
         << "b = " << b << endl;


    return 0;
}