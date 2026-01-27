#include "iostream"

using namespace std;


void print(const int *arr) {
    if (arr)
        cout << *arr << " ";
    cout << endl;
}

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << " ";
    }
    cout << endl;
}

int main() {

    int i = 0;
    int j[2] = {0, 1};
    print(j);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));


    return 0;
}