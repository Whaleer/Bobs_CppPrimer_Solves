#include <iostream>
#include <vector>

using namespace std;
using Iter = vector<int>::const_iterator;

void recur_print(Iter first, Iter last) {
    if (first != last) {
        cout << *first << endl;
        recur_print(++first, last);
    }
}

int main() {

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    recur_print(vec.begin(),vec.end());

    return 0;
}