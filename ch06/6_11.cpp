#include "iostream"

using namespace std;


void reset(int &i) {

    i = 0;
}

int main() {
    int a = 2;
    reset(a);
    cout << a << endl;

    return 0;
}