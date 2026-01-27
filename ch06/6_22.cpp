#include "iostream"

using namespace std;

void swap(int *&left, int *&right) {
    auto tmp = left;
    left = right;
    right = tmp;

}

int main() {
    int a = 12;
    int b = 24;
    auto left = &a;
    auto right = &b;
    swap(left, right);
    cout << "left : " << *left << endl
         << "right : " << *right << endl;


    return 0;
}