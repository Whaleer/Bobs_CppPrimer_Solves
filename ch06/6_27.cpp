#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> il) {
    int sum = 0;
    for (auto i: il) {
        sum += i;
    }
    return sum;
}

int main() {

    auto il = {1, 2, 3, 4, 5};
    cout << sum(il) << endl;

    return 0;
}